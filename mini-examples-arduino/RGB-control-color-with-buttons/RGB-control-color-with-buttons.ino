#define RED_PIN 11
#define GREEN_PIN 10
#define BLUE_PIN 9

#define RED_BUTTON 5
#define GREEN_BUTTON 4
#define BLUE_BUTTON 3

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  pinMode(RED_BUTTON, INPUT);
  pinMode(GREEN_BUTTON, INPUT);
  pinMode(BLUE_BUTTON, INPUT);
  Serial.begin(9600);
}

void loop() {
  int red1 = digitalRead(RED_BUTTON);
  int green1 = digitalRead(GREEN_BUTTON);
  int blue1 = digitalRead(BLUE_BUTTON);

  delay(10);
  
  int red2 = digitalRead(RED_BUTTON);
  int green2 = digitalRead(GREEN_BUTTON);
  int blue2 = digitalRead(BLUE_BUTTON);

   if ((red1 || red2) == LOW){
    if (redValue >= 255){
      redValue = 0;
    }
    redValue++;
   }

   if ((green1 || green2) == LOW){
    if (greenValue >= 255){
      greenValue = 0;
    }
    greenValue++;
   }
   
   if ((blue1 || blue2) == LOW){
    if (blueValue >= 255){
      blueValue = 0;
    }
    blueValue++;
   }

  rgbOn(redValue, greenValue, blueValue);
}

void rgbOn(int red1, int green1, int blue1){
  analogWrite(RED_PIN, red1);
  analogWrite(GREEN_PIN, green1);
  analogWrite(BLUE_PIN, blue1);
}