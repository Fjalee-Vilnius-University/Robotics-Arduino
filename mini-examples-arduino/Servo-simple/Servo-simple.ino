#include<Servo.h>
#define SERVO 5

Servo Servo1; 

void setup() {
  pinMode(SERVO, OUTPUT);
  Servo1.attach(SERVO); 
  Serial.begin(9600);
}

void loop() {
  Servo1.write(0);
  delay(1000);
  Servo1.write(90);
  delay(1000);
  Servo1.write(180);
  delay(1000);
}
