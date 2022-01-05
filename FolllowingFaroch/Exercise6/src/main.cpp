/**
 * @file main.cpp
 * @author Milad Zarour
 * @brief Fading using IntervalTimer
 * @version 0.1
 * @date 2022-01-05
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <Arduino.h>
#include <Metro.h>

#define RED_PIN (2)
#define GREEN_PIN (3)
#define BLUE_PIN (4)
static Metro metro = Metro(150);

void setup()
{
  Serial.begin(9600);
  delay(2000);
}

void loop()
{
  if (metro.check())
  {
    uint8_t red = random(255);
    uint8_t green = random(255);
    uint8_t blue = random(255);

    analogWrite(RED_PIN, red);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, blue);
    // Generate random red, green and blue numbers in the range of 0 to 255

    //
  }
}