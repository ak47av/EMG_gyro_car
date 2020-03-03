#include <SoftwareSerial.h>
SoftwareSerial BTSerial(3,5); 

//const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A1; // analog pin connected to X output
const int Y_pin = A2; // analog pin connected to Y output

char controller;

int X;
int Y;

void setup() {
  //pinMode(SW_pin, INPUT);
  //digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  //Serial.print("Switch:  ");
  //Serial.print(digitalRead(SW_pin));
  //Serial.print("\n");

  //if(BTserial.available())
    //Serial.write(BTserial.read())

  X = analogRead(X_pin);
  Y = analogRead(Y_pin);
  
if((X>1000 && Y>900)){
  controller = "f";
    Serial.println("f");
  }
 else if((X<50 && Y<100)){
  controller = "b";
    Serial.println("b");
  }
 else if((X>500 && Y>550)){
  controller = "r"; 
    Serial.println("r");
  }
 else if((X>500 && Y<500)){
    controller = "l";
    Serial.println("l");
  }
 else {
    controller = "s";
    Serial.println("s");
  }

  if(Serial.available())
    BTSerial.write(controller);
  /**
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("      ");
  Serial.print("Y-axis: ");
  Serial.print(analogRead(Y_pin));
  Serial.print("\n");
  **/
  delay(10);
}
