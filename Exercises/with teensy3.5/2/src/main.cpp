/**
 * @file main.cpp
 * @author Milad Zarour ()
 * @brief exercise two for Teensy 3.5 (Using millis to control the time for a blinking LED)
 * @version 0.1
 * @date 2022/01/04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <Arduino.h>

static uint8_t pinLED = 32;
static uint8_t led_state = LOW;
static uint16_t counter = 0;
static uint32_t last_millis = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(pinLED, OUTPUT); // Set the pin connected to the built in LED as output
}

void loop()
{
    uint32_t now = millis();
    Serial.printf("now = %d\n", now);
    Serial.printf("last_millis = %d\n", last_millis);
    Serial.printf("counter = %d\n", counter);
    if (last_millis > now) // When the timer gets overflowed
    {
        counter += (0xFFFFFFFFu - last_millis) + 1u + now;
        Serial.printf("counter in if = %d\n", counter);
    }
    else
    {
        counter += (now - last_millis);
        Serial.printf("counter in else = %d\n", counter);
    }
    last_millis = now;
    Serial.printf("last_millis = now =  %d\n", last_millis);
    if (counter >= 1000u)
    {
        Serial.printf("the counter is bigger than 500u = %d\n\n", counter);
        counter = 0;
        led_state = !led_state;
        digitalWrite(pinLED, led_state);
    }
}