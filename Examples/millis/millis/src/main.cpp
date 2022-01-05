#include <Arduino.h>

static uint16_t counter = 0;
static uint8_t led_state = LOW;
static uint32_t last_millis = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    uint32_t now = millis();
    Serial.printf("now = %d\n", now);
    Serial.printf("last_millis = %d\n", last_millis);
    Serial.printf("counter = %d\n", counter);
    delay(4);
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

    if (counter >= 500u)
    {
        Serial.printf("the counter is bigger than 500u = %d\n\n", counter);
        counter = 0;
        led_state = !led_state;
        digitalWrite(LED_BUILTIN, led_state);
    }
}
