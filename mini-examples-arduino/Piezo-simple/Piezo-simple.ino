#define PIEZO 9 

void setup() {
  pinMode(PIEZO, OUTPUT);
}

int length = 25;
char notes[] = "ggecggecfaCaggfaafeggedfedcc ";
float beats[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
2.75, 2.75, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2.75, 2.75};
int tempo = 300;

void loop() {
  for (int i = 0; i < length; i++)
  {
    if (notes[i] == ' '){
      delay(beats[i] * tempo);
    }
    else{
      playNote(notes[i], beats[i] * tempo);
    }
    delay(tempo/2);
  }
}

void playTone(int tone, int duration){
  for (long i = 0; i < duration * 1000L; i+= tone*2)
  {
    digitalWrite(PIEZO, HIGH);
    delayMicroseconds(tone);
    digitalWrite(PIEZO, LOW);
    delayMicroseconds(tone);
  }
}
  
void playNote(char note, int duration){
  char names[] = {'c', 'd', 'e', 'f', 'g', 'a', 'c', 'C'};
  int tones[] = {1915, 1700, 1519, 1432, 1275, 1136, 1014, 956};

  for (int i = 0; i < 8; i++)
  {
    if (names[i] == note){
      playTone(tones[i], duration);
    }
  }
}
