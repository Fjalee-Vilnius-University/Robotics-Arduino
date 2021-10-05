#define GREEN_LED 10
#define BLUE_LED 11
#define RED_LED 12

#define FADE_LED 3
#define BLINK_LED 2

void setup() {
  pinMode(FADE_LED, OUTPUT);
  pinMode(BLINK_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  turn_led_on_for(RED_LED, 3000);
  turn_two_leds_on_for(RED_LED, BLUE_LED, 1000);

  digitalWrite(GREEN_LED, HIGH);

  blink_for(3, 1000);
  fade();
  blink_for(3, 1000);

  digitalWrite(GREEN_LED, LOW);
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

void turn_led_on_for(int led, int milliseconds){
  digitalWrite(led, HIGH);
  delay(milliseconds);
  digitalWrite(led, LOW);
}

void turn_two_leds_on_for(int led1, int led2, int milliseconds){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(milliseconds);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

void blink_for(int times, int delayMs){
  for (int i=0; i<times; i++){
    delay(delayMs);
    blink();
  }
}
