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

 

void loop()
{
    sinvader1a();
    delay(delayTime);
    sinvader1b();
    delay(delayTime);
}
