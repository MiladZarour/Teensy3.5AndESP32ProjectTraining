#include <Arduino.h>

int redPin = 23;
int greenPin = 22;
int bluePin = 21;

void setup()
{ // put your setup code here, to run once:

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

int redIntensity = 0;

void loop()
{
  // put your main code here, to run repeatedly :

  // set all 3 pins to the desired intensity
  analogWrite(redPin, redIntensity);
  analogWrite(greenPin, 255 - redIntensity);
  analogWrite(bluePin, 0);

  // remain at this color, but not for very long
  delay(10);

  // increase the red
  redIntensity = redIntensity + 1;

  // since 255 is the maximum, set it back to 0
  // when it increments beyond 255
  if (redIntensity > 255)
  {
    while (redIntensity > 1)
    {
      analogWrite(redPin, redIntensity);
      analogWrite(greenPin, 255 - redIntensity);
      analogWrite(bluePin, 0);
      delay(10);
      redIntensity = redIntensity - 1;
    }
  }
}