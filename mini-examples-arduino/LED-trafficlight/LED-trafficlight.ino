#define FADE_LED 3
#define BLINK_LED 2

void setup() {
  pinMode(FADE_LED, OUTPUT);
}

void loop() {

  delay(1000);
  blink();
  delay(1000);
  blink();
  delay(1000);
  blink();

  fade();

  delay(1000);
  blink();
  delay(1000);
  blink();
  delay(1000);
  blink();
}

void fade(){
  for (int brigthness=0; brigthness<=255; brigthness++){
    analogWrite(FADE_LED, brigthness);
    delay(10);
  }
  for (int brigthness=255; brigthness>=0; brigthness--){
    analogWrite(FADE_LED, brigthness);
    delay(10);
  }
}

void blink(){
  digitalWrite(BLINK_LED, HIGH);
  delay(1000);
  digitalWrite(BLINK_LED, LOW);
  delay(1000);
}

