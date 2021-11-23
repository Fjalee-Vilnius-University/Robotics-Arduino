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

  buttonAction(redLed, redButton, 'a');
  buttonAction(greenLed, greenButton, 'b');
  buttonAction(blueLed, blueButton, 'c');
  buttonAction(yellowLed, yellowButton, 'd');;
}

void playTone(int tone, int duration){
  for (long i = 0; i < duration * 1000L; i+= tone*2)
  {
    digitalWrite(SPEAKER, HIGH);
    delayMicroseconds(tone);
    digitalWrite(SPEAKER, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration){
  char names[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
  int tones[] = {1915, 1700, 1519, 1432, 1275, 1136, 1014, 956};

  for (int i = 0; i < 8; i++)
  {
    if (names[i] == note){
      playTone(tones[i], duration);
    }
  }
}

void blinkLedWithNote(int led, char note){
  if (!isLed(led)){
    return;
  }

  digitalWrite(led, HIGH);
  playNote(note, delayInMs);
  digitalWrite(led, LOW);
}

void buttonAction(int led, int button, char note){
  if (!isButton(button) || !isLed(led)){
    return;
  }

  bool isButtonOn = true;

  while (isButtonOn){
    int buttonState = digitalRead(button);

    if (buttonState == HIGH){
      isButtonOn = false;
    }
    else{
      // blinkLedWithNote(led);
    }

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