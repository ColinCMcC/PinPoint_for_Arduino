// main code: ArduinoGetStarted.com.ino
#include "main.h"


void setup() {
  Serial.begin(115200);
}

void loop() {
  pinPoint.update();

  Serial.print("X Pos: ");
  Serial.println(pinPoint.readFloatRegister(8));

  delay(250);
}