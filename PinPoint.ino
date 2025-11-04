#include "PinPoint.h"

float readFloatRegister(enum PinPointRegisterMap reg) {
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
