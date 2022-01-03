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

void loop()
{
  // put your main code here, to run repeatedly :
  analogWrite(redPin, 100);
  delay(500);
  analogWrite(greenPin, 25);
  delay(500);
  analogWrite(bluePin, 10);
  delay(500);
  analogWrite(redPin, 0);
  delay(500);
  analogWrite(greenPin, 0);
  delay(500);
  analogWrite(bluePin, 0);
  delay(500);
}