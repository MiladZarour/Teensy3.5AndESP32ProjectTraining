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
  // put your main code here, to run repeatedly : digitalWrite(redPin, HIGH);
  delay(500);
  digitalWrite(greenPin, HIGH);
  delay(500);
  digitalWrite(bluePin, HIGH);
  delay(500);
  digitalWrite(redPin, LOW);
  delay(500);
  digitalWrite(greenPin, LOW);
  delay(500);
  digitalWrite(bluePin, LOW);
  delay(500);
}