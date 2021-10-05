#define GREEN_LED 10
#define BLUE_LED 11
#define RED_LED 12

#define POTENTIOMETER A5

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  pinMode(POTENTIOMETER, INPUT);

  Serial.begin(9600);
}

void loop() {
  int pValue = analogRead(POTENTIOMETER);
  Serial.println(pValue);
}
