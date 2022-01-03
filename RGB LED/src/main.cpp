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
  analogWrite(redPin, 200);
  delay(500);
  analogWrite(greenPin, 50);
  delay(500);
  analogWrite(bluePin, 25);
  delay(2000);
  analogWrite(redPin, 0);
  delay(500);
  analogWrite(greenPin, 0);
  delay(500);
  analogWrite(bluePin, 0);
  delay(500);
}