#include <SoftwareSerial.h>
SoftwareSerial BTserial(14,15);
char c;

#define ENBLEFT D6
#define ENBRIGHT D1 
#define IN1 D7 //IN3
#define IN2 D4
#define IN3 D3
#define IN4 D2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTserial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(BTserial.available()){
     c = BTserial.read();
    }
    Serial.println(c);

    if(c == '/') FORWARD();
    else if (c == '1') BACKWARD();
    else if (c == '3')RIGHT();
    else if (c == '5') LEFT();
    else if (c == '7') STOP();
    else STOP();

  if(Serial.available())
    BTserial.write(Serial.read());
}

void FORWARD(){
     digitalWrite(ENBRIGHT,HIGH);
    digitalWrite(ENBLEFT,HIGH);

    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
  }

void BACKWARD(){
  digitalWrite(ENBRIGHT,HIGH);
    digitalWrite(ENBLEFT,HIGH);

    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
  }

void RIGHT(){
  analogWrite(ENBRIGHT,600);
    analogWrite(ENBLEFT,1023);

    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW); 
  }

void LEFT(){
  analogWrite(ENBRIGHT,1023);
    analogWrite(ENBLEFT,600);

    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW); 
  }

void STOP(){
  digitalWrite(ENBRIGHT,LOW);
    digitalWrite(ENBLEFT,LOW);

    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
  }
