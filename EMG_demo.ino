const int sig = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(sig,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(sig);
  Serial.println(reading);
  
}
