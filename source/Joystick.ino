
#include "Keyboard.h"

#define PortX A0
#define PortY A1

#define YLimitExtremeW 896
#define XLimitExtremeA 896
#define YLimitExtremeS 128
#define XLimitExtremeD 128

#define YLimit2W 768
#define XLimit2A 768
#define YLimit2S 256
#define XLimit2D 256 

#define smallerX >
#define biggerX <
#define smallerY <
#define biggerY >

void joystickMove(int X, int Y);

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  int XValue = analogRead(PortX);
  int YValue = analogRead(PortY);

  joystickMove(XValue, YValue);


  if (0)
  {
    Serial.println(XValue);
    Serial.println(YValue);
    Serial.print('\n'); 

    delay(2000);
  }
}

void joystickMove(int X, int Y)
{
  static bool isWpressed = false;
  static bool isApressed = false;
  static bool isSpressed = false;
  static bool isDpressed = false;

  if (Y biggerY YLimitExtremeW) // W pressed
  {
    if (!isWpressed)
    {
      Keyboard.press('W');
      isWpressed = true;
    }
  }
  else if (Y biggerY YLimit2W)
  {
    if (isWpressed)
    {
      Keyboard.release('W');
      isWpressed = false;
      Keyboard.print('W');
    }
  }
  else if (isWpressed)
  {
    Keyboard.release('W');
    isWpressed = false;
  }

  if (X smallerX XLimitExtremeA) // A pressed
  {
    if (!isApressed)
    {
      Keyboard.press('A');
      isApressed = true;
    }
  }
  else if (X smallerX XLimit2A)
  {
    if (isApressed)
    {
      Keyboard.release('A');
      isApressed = false;
      Keyboard.print('A');
    }
  }
  else if (isApressed)
  {
    Keyboard.release('A');
    isApressed = false;
  }
  
  if (Y smallerY YLimitExtremeS) // S pressed
  {
    if (!isSpressed)
    {
      Keyboard.press('S');
      isSpressed = true;
    }
  }
  else if (Y smallerY YLimit2S)
  {
    if (isSpressed)
    {
      Keyboard.release('S');
      isSpressed = false;
      Keyboard.print('S');
    }
  }
  else if (isSpressed)
  {
    Keyboard.release('S');
    isSpressed = false;
  }
 
  if (X biggerX XLimitExtremeD) // D pressed
  {
    if (!isDpressed)
    {
      Keyboard.press('D');
      isDpressed = true;
    }
  }
  else if (X biggerX XLimit2D)
  {
    if (isDpressed)
    {
      Keyboard.release('D');
      isDpressed = false;
      Keyboard.print('D');
    }
  }
  else if (isDpressed)
  {
    Keyboard.release('D');
    isDpressed = false;
  }
}

