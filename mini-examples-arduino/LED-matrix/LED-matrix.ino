#include "LedControl.h"

LedControl lc=LedControl(12,11,10,2);

unsigned long delayTime = 200;

byte invader1a[] =
{
  B00011000,
  B00111100,
  B01111110,
  B11011011,
  B11111111,
  B01011010,
  B01011010,
  B10100101
};

byte invader1b[]=
{
  B00011000,
  B00111100,
  B01111110,
  B11011011,
  B11111111,
  B00100100,
  B01011010,
  B01000010
};

byte letterR[]=
{
  B00000000,
  B00110000,
  B01001000,
  B01001000,
  B01110000,
  B01001000,
  B01000100,
  B00000000
};

byte letterY[]=
{
  B00000000,
  B01000100,
  B01000100,
  B00101000,
  B00010000,
  B00010000,
  B00010000,
  B00000000
};

byte letterT[]=
{
  B00000000,
  B01111110,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00000000
};

byte letterI[]=
{
  B00000000,
  B00111000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00111000,
  B00000000
};

byte letterS[]=
{
  B00000000,
  B00111100,
  B01000010,
  B00110000,
  B00001100,
  B01000100,
  B00111000,
  B00000000
};

void setup()
{
  lc.shutdown(0, false);
  lc.setIntensity(0,5);
  lc.clearDisplay(0);
}

void sinvader1a()
{
  for (int i = 0; i<8; i++)
  {
    lc.setRow(0,i,invader1a[i]);
  }
}

void sinvader1b()
{
  for (int i = 0; i<8; i++)
  {
    lc.setRow(0,i,invader1b[i]);
  }
}

void sletterR()
{
  for (int i = 0; i<8; i++)
  {
    lc.setRow(0,i,letterR[i]);
  }
}

void sletterY()
{
  for (int i = 0; i<8; i++)
  {
    lc.setRow(0,i,letterY[i]);
  }
}

void sletterT()
{
  for (int i = 0; i<8; i++)
  {
    lc.setRow(0,i,letterT[i]);
  }
}

void sletterI()
{
  for (int i = 0; i<8; i++)
  {
    lc.setRow(0,i,letterI[i]);
  }
}

void sletterS()
{
  for (int i = 0; i<8; i++)
  {
    lc.setRow(0,i,letterS[i]);
  }
}

void loop()
{
  sletterR();
  delay(delayTime);
  sletterY();
  delay(delayTime);
  sletterT();
  delay(delayTime);
  sletterI();
  delay(delayTime);
  sletterS();
  delay(delayTime);
}
