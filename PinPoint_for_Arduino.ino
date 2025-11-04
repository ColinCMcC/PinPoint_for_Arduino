#include <Wire.h>
#include "main.h"

#define PINPOINT_ADDRESS 0x31  // Replace with the actual I2C address
// Add more registers as needed

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


float readFloatRegister(PinPointRegisterMap reg) {
  uint8_t buffer[4];

  // Start I2C communication and request specific register
  Wire.beginTransmission(PINPOINT_ADDRESS);
  Wire.write(static_cast<uint8_t>(reg));  // Send register address
  Wire.endTransmission();

  // Request 4 bytes
  Wire.requestFrom(PINPOINT_ADDRESS, 4);

  // Read 4 bytes
  for (int i = 0; i < 4; i++) {
    if (Wire.available()) {
      buffer[i] = Wire.read();
    }
  }

  // Convert to float
  float value;
  memcpy(&value, buffer, 4);

  return value;
}
