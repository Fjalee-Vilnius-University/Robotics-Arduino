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
  int red = digitalRead(RED_BUTTON);
  int green = digitalRead(GREEN_BUTTON);
  int blue = digitalRead(BLUE_BUTTON);
  
   if (red == LOW){
    if (redValue >= 255){
      redValue = 0;
    }
    redValue++;
   }
   if (green == LOW){
    if (greenValue >= 255){
      greenValue = 0;
    }
    greenValue++;
   }
   if (blue == LOW){
    if (blueValue >= 255){
      blueValue = 0;
    }
    blueValue++;
   }

  rgbOn(redValue, greenValue, blueValue);
}

void rgbOn(int red, int green, int blue){
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}