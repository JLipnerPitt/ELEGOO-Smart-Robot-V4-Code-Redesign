#include <Arduino.h>
#include <stdint.h>
#include "Line_Sensor.h"

void Line_Sensor_Init(void) {
  DDRC &= ~(0x03); // makes PC2-PC0 inputs
}

void Line_Sensor_Start(void) {
  DDRC |= 0x03; // makes PC2-PC0 outputs
  PORTC |= 0x03; // starts charging capacitors
  delayMicroseconds(10); // waits 10 us
  DDRC &= ~(0x03); // makes PC2-PC0 inputs
  delayMicroseconds(250); // waits 250 us
}

uint8_t Line_Sensor_End(void) {
  uint8_t input = PINC;
  PORTC &= ~(0x03); // turns off sensors
  return input;
}
