#include <Arduino.h>
#include "Line_Sensor.h"

void setup() {
  // put your setup code here, to run once:
  Line_Sensor_Init();
}

void loop() {
  Line_Sensor_Start();
  Line_Sensor_End();
  delay(5);
}