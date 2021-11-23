#define SPEAKER 7
#define RED 5
#define GREEN 13
#define BLUE 3
#define YELLOW 10

int delayInMs = 50;

void setup() {
  pinMode(SPEAKER, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(YELLOW, OUTPUT);
}

void loop() {
  int redLed = RED;
  int greenLed = GREEN;
  int blueLed = BLUE;
  int yellowLed = YELLOW;

  blinkLed(redLed);
  blinkLed(greenLed);
  blinkLed(blueLed);
  blinkLed(yellowLed);
}

void blinkLed(int led){
  if (led != RED && led != GREEN && led != BLUE && led != YELLOW){
    return;
  }

  digitalWrite(led, HIGH);
  delay(delayInMs);
  digitalWrite(led, LOW);
}
