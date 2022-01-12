#define LED 3

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  for (int brigthness=0; brigthness<=255; brigthness++){
    analogWrite(LED, brigthness);
    delay(10);
  }
  for (int brigthness=255; brigthness>=0; brigthness--){
    analogWrite(LED, brigthness);
    delay(10);
  }
}
