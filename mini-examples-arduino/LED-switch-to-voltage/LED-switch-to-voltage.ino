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

  int stThird = 1023 / 3;
  int ndThird = 1023 / 3 * 2;
  int rdThird = 1023;

  if(pValue >= 0 && pValue <= stThird){
    onOnlyGreenLed();
  }
  else if(pValue > stThird && pValue <= ndThird){
    onOnlyBlueLed();
  }
  else if(pValue > ndThird && pValue <= rdThird){
    onOnlyRedLed();
  }
}

void onOnlyGreenLed(){
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(RED_LED, LOW);
}

void onOnlyBlueLed(){
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, HIGH);
  digitalWrite(RED_LED, LOW);
}

void onOnlyRedLed(){
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(RED_LED, HIGH);
}
