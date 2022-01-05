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

#define INTERVAL (100)
#define DAC_Resolution (12)
#define VOLTAGE_MIN (1.0f)
#define VOLTAGE_MAX (3.0f)
#define VOLTAGE_RESOLUTION (3.3f / (1 << DAC_Resolution))

static float fading_step = 0.15f;
static float voltage = VOLTAGE_MIN;

void setup()
{
  analogWriteResolution(DAC_Resolution);
}

void loop()
{
  // Convert voltage to a value and write it to the pin using analogWriteDAC0
  analogWriteDAC0((int)(voltage / VOLTAGE_RESOLUTION));

  // Increase/decrease voltage by fading_step

  voltage += fading_step; // voltage = voltage + fading_step

  if (voltage >= VOLTAGE_MAX || voltage < VOLTAGE_MIN)
  {
    fading_step = -fading_step;
  }

  delay(INTERVAL);
}