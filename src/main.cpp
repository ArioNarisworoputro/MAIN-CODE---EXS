#include <Arduino.h>
#include "controller.h"


void setup() {
  Serial.begin(9600);
  setup_controller_btn();
  setup_controller_joy();
}

void loop() {
  // put your main code here, to run repeatedly:
  loop_controller();
}
