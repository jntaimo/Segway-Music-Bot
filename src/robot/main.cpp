#include <Arduino.h>
#include "pid.h"
#include "imu.h"
#include "pins.h"
#include "audio.h"
#include "imu.h"
#include "wireless.h"
#include "display.h"
#include "inputs.h"
#include "drive.h"


void setup() {
  // put your setup code here, to run once:
  audioSetup();
  displaySetup();
  inputsSetup();
  imuSetup();
  wirelessSetup();
  
}


void loop() {
  // put your main code here, to run repeatedly:
}