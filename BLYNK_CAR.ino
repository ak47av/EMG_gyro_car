#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "KBY2iwG9gFtJea3PAaxPS0Y0fPu5YKmn";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Arun";
char pass[] = "sampath747";

// These are used to set the direction of the bridge driver.
#define ENBLEFT D6
#define ENBRIGHT D1 
#define IN1 D5 //IN3
#define IN2 D4
#define IN3 D3
#define IN4 D2

// SETUP
void setup()
{

  pinMode(ENBLEFT, OUTPUT);
  pinMode(ENBRIGHT, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

 // digitalWrite(ENA,LOW);
  digitalWrite(ENBRIGHT,LOW);
  digitalWrite(ENBLEFT,LOW);
  
  // Start serial communication
  Serial.begin(9600);

  // Connect Blynk
  Blynk.begin(auth, ssid, pass);
}


// FORWARD
BLYNK_WRITE(V0) {
  int button = param.asInt(); // read button
  if (button == 1) {
    Serial.println("Moving forward");

    digitalWrite(ENBRIGHT,HIGH);
    digitalWrite(ENBLEFT,HIGH);

    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);    
  }
  else {
    digitalWrite(ENBRIGHT,LOW);
    digitalWrite(ENBLEFT,LOW);

    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);   
  }
}
// BACKWARD
BLYNK_WRITE(V3) {
  int button = param.asInt(); // read button
  if (button == 1) {
    Serial.println("Moving backward");

    digitalWrite(ENBRIGHT,HIGH);
    digitalWrite(ENBLEFT,HIGH);

    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH); 
  }
  else {
    digitalWrite(ENBRIGHT,LOW);
    digitalWrite(ENBLEFT,LOW);

    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);   
  }
}

//RIGHT
BLYNK_WRITE(V1) {
  int button = param.asInt(); // read button
  if (button == 1) {
    Serial.println("Moving right");

    analogWrite(ENBRIGHT,1023);
    analogWrite(ENBLEFT,600);

    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);    
  }
  else {
    digitalWrite(ENBRIGHT,LOW);
    digitalWrite(ENBLEFT,LOW);

    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);   
  }
}

//LEFT
BLYNK_WRITE(V2) {
  int button = param.asInt(); // read button
  if (button == 1) {
    Serial.println("Moving left");

    analogWrite(ENBRIGHT,600);
    analogWrite(ENBLEFT,1023);

    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);    
  }
  else {
    digitalWrite(ENBRIGHT,LOW);
    digitalWrite(ENBLEFT,LOW);

    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);   
  }
}



// MAIN CODE
void loop()
{
  Blynk.run();
}
