#define GREEN_LED 10
#define BLUE_LED 11
#define RED_LED 12

#define POTENTIOMETER A5

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  pinMode(POTENTIOMETER, INPUT);
}

void loop() {
  int pValue = analogRead(POTENTIOMETER);

  int potentiometerRangeTo = 1023;
  int potentiometerRangeHalf = potentiometerRangeTo / 2;

  analogWrite(BLUE_LED, pValue/4);

  if(pValue >= 0 && pValue <= potentiometerRangeHalf){
    onOnlyGreenLed();
  }
  else if(pValue > potentiometerRangeHalf && pValue <= potentiometerRangeTo){
    onOnlyRedLed();
  }
}

void onOnlyGreenLed(){
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);
}

void onOnlyRedLed(){
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, HIGH);
}
