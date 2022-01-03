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
  delay(30);

  // increase the red
  redIntensity = redIntensity + 1;

  // since 255 is the maximum, set it back to 0
  // when it increments beyond 255
  if (redIntensity > 255)
  {
    redIntensity = 0;
  }
  // analogWrite(redPin, 200);
  // delay(500);
  // analogWrite(greenPin, 50);
  // delay(500);
  // analogWrite(bluePin, 25);
  // delay(2000);
  // analogWrite(redPin, 0);
  // delay(500);
  // analogWrite(greenPin, 0);
  // delay(500);
  // analogWrite(bluePin, 0);
  // delay(500);
}