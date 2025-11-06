// LED.cpp
#include "PinPoint.h"

// Default PinPoint i2c address is 0x31
PinPointModule::PinPointModule(int address) {
}

float PinPointModule::xPos() {
  data.xPos = PinPointRegisterMap(X_POS);

  return data.xPos;
}

float PinPointModule::yPos() {
  return data.yPos;
}

float PinPointModule::hDir() {
  return data.hDir;
}

void PinPointModule::update() {
}

float PinPointModule::readFloatRegister(int reg) {
  uint8_t buffer[4];

  // Start I2C communication and request specific register
  Wire.beginTransmission(_address);
  Wire.write(static_cast<uint8_t>(reg));  // Send register address
  Wire.endTransmission();

  // Request 4 bytes
  Wire.requestFrom(_address, 4);

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
