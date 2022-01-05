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

int pinLED = 30;
IntervalTimer timer;
uint8_t led_state = LOW;

static int8_t step = 1;
static int intensity = 0;

void blink(void)
{
    analogWrite(pinLED, intensity);

    intensity += step;

    if ((intensity > 255) || (intensity < 0))
    {
        step = -step;
    }
}

void setup()
{
    pinMode(pinLED, OUTPUT);
    timer.begin(blink, 50000);
}

void loop()
{
}

// void loop()
// {
//     analogWrite(pinLED, 30);
//     delay(500);
//     analogWrite(pinLED, 100);
//     delay(500);
//     analogWrite(pinLED, 150);
//     delay(500);
//     analogWrite(pinLED, 200);
//     delay(500);
// }

// void loop()
// {
//     analogWrite(pinLED, intensity);
//     delay(10);
//     intensity = intensity + 1;
//     if (intensity > 255)
//     {
//         while (intensity)
//         {
//             analogWrite(pinLED, intensity);
//             delay(10);
//             intensity = intensity - 1;
//         }
//     }
// }

// #include <Metro.h>
// #include <Arduino.h>

// int pinLED = 30;
// Metro metro = Metro(10);

// void setup()
// {
//     pinMode(pinLED, OUTPUT);
// }

// int intensity = 0;

// void loop()
// {
//     if (metro.check())
//     {
//         analogWrite(pinLED, intensity);
//         intensity = intensity + 1;
//         if (intensity > 255)
//         {
//             while (intensity)
//             {
//                 if (metro.check())
//                 {
//                     analogWrite(pinLED, intensity);
//                     intensity = intensity - 1;
//                 }
//             }
//         }
//     }
// }