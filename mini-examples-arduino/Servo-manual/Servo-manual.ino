#define SERVO 4

void setup() {
  pinMode(SERVO, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  servoRotate(90);
  delay(1000);
  servoRotate(180);
  delay(1000);
}

void servoRotate(int deg){
  if (deg < 0 || deg >180){
    return;
  }

  int totalImpulse = 20000;
  int mcsForOneDeg = totalImpulse / 180;
  int mcsOn = deg * mcsForOneDeg;
  int mcsOff = totalImpulse - mcsOn;

  for (int i = 0; i < 100; i++)
  {
    digitalWrite(SERVO, 1);
    delayMicroseconds(mcsOn);
    digitalWrite(SERVO, 0);
    delayMicroseconds(mcsOff);
    Serial.write("1");
  }
}
