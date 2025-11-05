// main code: ArduinoGetStarted.com.ino
#include "main.h"


void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("LED 1 state: ");
  Serial.println(led1.xPos());

  delay(2000);

  Serial.print("LED 1 state: ");
  Serial.println(led1.xPos());

  delay(2000);
}