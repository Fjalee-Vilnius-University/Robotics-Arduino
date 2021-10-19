#define RED_PIN 11
#define GREEN_PIN 10
#define BLUE_PIN 9

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  rgbOn(255, 51, 255);
}

void rgbOn(int red, int green, int blue){
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}