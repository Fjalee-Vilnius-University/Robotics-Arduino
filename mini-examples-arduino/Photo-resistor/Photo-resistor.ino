#define RED_LED 10
#define GREEN_LED 11
#define BLUE_LED 12

#define RED_PR A0
#define GREEN_PR A1
#define BLUE_PR A2

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  pinMode(RED_PR, INPUT);
  pinMode(GREEN_PR, INPUT);
  pinMode(BLUE_PR, INPUT);
  Serial.begin(9600);
}

void loop() {
  int redPrValue = analogRead(RED_PR);
  int greenPrValue = analogRead(GREEN_PR);
  int bluePrValue = analogRead(BLUE_PR);

  controlRedLed(redPrValue);
  controlGreenLed(greenPrValue);
  controlBlueLed(bluePrValue);
}

void controlRedLed(int prValue){
  if (prValue > 400){
    digitalWrite(RED_LED, HIGH);
  }
  else{
    digitalWrite(RED_LED, LOW);
  }
}

void controlGreenLed(int prValue){
  if (prValue > 400){
    digitalWrite(GREEN_LED, HIGH);
  }
  else{
    digitalWrite(GREEN_LED, LOW);
  }
}

void controlBlueLed(int prValue){
  if (prValue > 400){
    digitalWrite(BLUE_LED, HIGH);
  }
  else{
    digitalWrite(BLUE_LED, LOW);
  }
}
