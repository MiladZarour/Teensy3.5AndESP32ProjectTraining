/**
 * @file main.cpp
 * @author Milad Zarour
 * @brief Connect an LED series with a 120𝛀 resistor to a pwm pin on Teensy
 *  ➢ Make the LED fading in/out using PWM signals.
    ➢ For timing use the Metro library
 * @version 0.1
 * @date 2022-01-04
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <Metro.h>
#include <Arduino.h>

static int8_t step = 5;
static int16_t brightness = 0;
static Metro metro = Metro(150);

void setup()
{
}

void loop()
{
  if (metro.check())
  {
    analogWrite(A9, brightness);
    brightness += step;
    if (brightness >= 255 || brightness <= 0)
    {
      step = -step;
    }
  }
}