#define SPEAKER 7

#define RED_LED 5
#define GREEN_LED 13
#define BLUE_LED 3
#define YELLOW_LED 10

#define RED_BUTTON 2
#define GREEN_BUTTON 6
#define BLUE_BUTTON 9
#define YELLOW_BUTTON 12

int delayInMs = 50;

void setup() {
  pinMode(SPEAKER, OUTPUT);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);

  pinMode(RED_BUTTON, INPUT_PULLUP);
  pinMode(GREEN_BUTTON, INPUT_PULLUP);
  pinMode(BLUE_BUTTON, INPUT_PULLUP);
  pinMode(YELLOW_BUTTON, INPUT_PULLUP);
}

void loop() {
  int redLed = RED_LED;
  int greenLed = GREEN_LED;
  int blueLed = BLUE_LED;
  int yellowLed = YELLOW_LED;

  int redButton = RED_BUTTON;
  int greenButton = GREEN_BUTTON;
  int blueButton = BLUE_BUTTON;
  int yellowButton = YELLOW_BUTTON;

  buttonAction(redLed, redButton);
  buttonAction(greenLed, greenButton);
  buttonAction(blueLed, blueButton);
  buttonAction(yellowLed, yellowButton);
}

void blinkLed(int led){
  if (!isLed(led)){
    return;
  }

  digitalWrite(led, HIGH);
  delay(delayInMs);
  digitalWrite(led, LOW);
}

bool buttonAction(int led, int button){
  if (!isButton(button) || !isLed(led)){
    return false;
  }

  int buttonState = digitalRead(button);

  if(buttonState == LOW){
    blinkLed(led);
    return true;
  }
}

bool isLed(int led){
  if (led != RED_LED && led != GREEN_LED && led != BLUE_LED && led != YELLOW_LED){
    return false;
  }
  return true;
}

bool isButton(int button){
  if (button != RED_BUTTON && button != GREEN_BUTTON && button != BLUE_BUTTON && button != YELLOW_BUTTON){
    return false;
  }
  return true;
}