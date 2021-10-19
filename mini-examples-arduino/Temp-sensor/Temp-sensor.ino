#define TEMP_SENSOR A3

void setup() {
  Serial.begin(9600);
}

void loop() {
  float temp = getVoltage();

  temp = (temp - 0.5) * 100;

  Serial.println(temp);
  delay(1000);
}

float getVoltage(){
  return (analogRead(TEMP_SENSOR) * 0.04882814);
}
