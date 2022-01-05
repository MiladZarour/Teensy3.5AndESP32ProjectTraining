#include <Arduino.h>
#include <Bounce.h>
#include <Metro.h>

const int buttonPin = 33;

static uint32_t count = 0;
static uint32_t previous_count = 0;
static Metro metro = Metro(100);
Bounce pushbutton = Bounce(buttonPin, 5); // 10 ms debounce

void setup()
{
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  delay(2000);
  Serial.println("Pushbutton Bounce library test:");
}

void loop()
{
  if (pushbutton.update())
  {
    if (pushbutton.fallingEdge())
    {
      count = count + 1;
    }
  }

  else if ((count != previous_count) && metro.check())
  {
    previous_count = count;
    Serial.printf("Count : %d\n", count);
  }
}