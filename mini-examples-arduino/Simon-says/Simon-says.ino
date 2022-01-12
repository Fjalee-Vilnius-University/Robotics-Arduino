#define SPEAKER 7

#define RED_LED 5
#define GREEN_LED 13
#define BLUE_LED 3
#define YELLOW_LED 10

#define RED_BUTTON 2
#define GREEN_BUTTON 6
#define BLUE_BUTTON 9
#define YELLOW_BUTTON 12

int delayInMs = 1000;
int totalLevels = 20;
int timeBetweenLevels = 2000;
int timeBetweenLeds = 50;

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
  Serial.begin(9600);
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

  char redTone = 'a';
  char blueTone = 'b';
  char greenTone = 'c';
  char yellowTone = 'd';

  int outputLedPath[totalLevels] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};;

  for (int i = 0; i < totalLevels; i++)
  {
    int randLed = genRandomLed();
    outputLedPath[i] = randLed;

    for (int j = 0; j <= i; j++){
      int ledToBlink = outputLedPath[j];
      blinkLedWithNote(ledToBlink, ' ');
      delay(timeBetweenLeds);
    }
    
    delay(2000);
    int userInputPath[totalLevels] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int j = 0; j <= i; j++)
    {
      int userInputLed = waitForButtonPress();
      userInputPath[j] = userInputLed;
    }

    int lost = memcmp(outputLedPath, userInputPath, sizeof(outputLedPath));

    if(!lost == 0){
      digitalWrite(redLed, HIGH);
      digitalWrite(greenLed, HIGH);
      digitalWrite(blueLed, HIGH);
      digitalWrite(yellowLed, HIGH);
      while(1);
    }

    delay(timeBetweenLevels);
  }
}

int waitForButtonPress(){
  int redLed = RED_LED;
  int greenLed = GREEN_LED;
  int blueLed = BLUE_LED;
  int yellowLed = YELLOW_LED;

  int redButton = RED_BUTTON;
  int greenButton = GREEN_BUTTON;
  int blueButton = BLUE_BUTTON;
  int yellowButton = YELLOW_BUTTON;

  char redTone = 'a';
  char blueTone = 'b';
  char greenTone = 'c';
  char yellowTone = 'd';

  bool noResponse = true;
  while(noResponse){
    bool redPressed = buttonAction(redLed, redButton, redTone);
    bool greenPressed = buttonAction(greenLed, greenButton, blueTone);
    bool bluePressed = buttonAction(blueLed, blueButton, greenTone);
    bool yellowPressed = buttonAction(yellowLed, yellowButton, yellowTone);

    if (redPressed) return true;
    if (greenPressed) return true;
    if (bluePressed) return true;
    if (yellowPressed) return true;
  }
}

int genRandomLed(){
  int redLed = RED_LED;
  int greenLed = GREEN_LED;
  int blueLed = BLUE_LED;
  int yellowLed = YELLOW_LED;

  char redTone = 'a';
  char blueTone = 'b';
  char greenTone = 'c';
  char yellowTone = 'd';

  int randNum = random(1,5);
  
  if (randNum == 1){
    blinkLedWithNote(redLed, redTone);
    return redLed;
  }
  if (randNum == 2){
    blinkLedWithNote(blueLed, blueTone);
    return blueLed;
  }
  if (randNum == 3){
    blinkLedWithNote(greenLed, greenTone);
    return greenLed;
  }
  if (randNum == 4){
    blinkLedWithNote(yellowLed, yellowTone);
    return yellowLed;
  }
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

void blinkLedWithNote(int led, char unusedNote){
  char redTone = 'a';
  char blueTone = 'b';
  char greenTone = 'c';
  char yellowTone = 'd';

  if (!isLed(led)){
    return;
  }

  char note = ' ';
  if (led == RED_LED){
    note = redTone;
  }
  if (led == GREEN_LED){
    note = greenTone;
  }
  if (led == BLUE_LED){
    note = blueTone;
  }
  if (led == YELLOW_LED){
    note = yellowTone;
  }

  digitalWrite(led, HIGH);
  playNote(note, delayInMs);
  digitalWrite(led, LOW);
}

bool buttonAction(int led, int button, char note){
  if (!isButton(button) || !isLed(led)){
    return false;
  }

  bool isButtonOn = true;

  while (isButtonOn){
    int buttonState = digitalRead(button);

    if (buttonState == HIGH){
      isButtonOn = false;
    }
    else{
      blinkLedWithNote(led, note);

      while(true){
        buttonState = digitalRead(button);
        if (buttonState == HIGH){
          return true;
        }
      }
    }
  }
  return false;
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
