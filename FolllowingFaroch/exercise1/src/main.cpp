#include <Arduino.h>

#define tempPin A14
#define ADC_Resolution (10)
#define VOLTAGE_OFFEST (500)
#define MILLIVOLTS_PER_CELSIUS (10)
#define VOLTAGE_RESOLUTION ((3.3f * 1000) / (1 << ADC_Resolution))

void setup()
{
  // put your setup code here, to run once:
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);
  delay(2000);
  // Set the ADC resolution
  analogReadResolution(ADC_Resolution);
}

void loop()
{
  // value : Read the pin (A14) using analogRead
  uint16_t value = analogRead(tempPin);
  Serial.printf("value : %d\n", value);

  // voltage: Convert the read value to a voltage in millivolts
  float voltage = value * VOLTAGE_RESOLUTION;
  Serial.printf("voltage : %f\n", voltage);

  // tempreature : ((voltage - 500) / 10)
  float current_temp = (voltage - VOLTAGE_OFFEST) / MILLIVOLTS_PER_CELSIUS;

  // Print tempreature to the terminal
  Serial.printf("Temperature: %.2f\n", current_temp);

  delay(1000);

  // put your main code here, to run repeatedly:
}