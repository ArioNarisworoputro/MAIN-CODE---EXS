#include <Arduino.h>
#include "controller.h"

CONTROLLER Controller(13, 12, 11, 7, A0, A1);

void setup() {
  Serial.begin(9600);
  Controller.attachMotor(10, 9, 8);
  Controller.attachCommands();
}

void loop() {
  // put your main code here, to run repeatedly:
  //Motor_1.serialTest();
  Controller.controlLoop();
}
