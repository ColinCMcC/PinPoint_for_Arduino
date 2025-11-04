#include "main.h"

void setup() {
  Serial.begin(115200);
  Wire.begin();
}

void loop() {

  float xPos = readFloatRegister(Y_POS);

  Serial.println();
  Serial.print("Interpreted float value: ");
  Serial.println(xPos, 6);  // Print with 6 decimal places

  Serial.print("\n");
  delay(100);  // Adjust delay as necessary
}


