#define SERVO 4

void setup() {
  pinMode(SERVO, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 100; i++)
  {
    digitalWrite(SERVO, 1);
    delay(1);
    digitalWrite(SERVO, 0);
    delay(19);
    Serial.write("1");
  }

  for (int i = 0; i < 100; i++)
  {
    digitalWrite(SERVO, 1);
    delay(2);
    digitalWrite(SERVO, 0);
    delay(18);
    Serial.write("0");
  }
}
