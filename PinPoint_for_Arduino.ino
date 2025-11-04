#include <Wire.h>

#define PINPOINT_ADDRESS 0x31  // Replace with the actual I2C address
#define POSITION_REGISTER1 8   // Register address for position 1
// Add more registers as needed

void setup() {
  Serial.begin(115200);
  Wire.begin();
}

void loop() {
  uint8_t buffer[4];

  // For reading position registers
  Wire.beginTransmission(PINPOINT_ADDRESS);
  Wire.write(POSITION_REGISTER1);
  Wire.endTransmission(false);

  delay(25);  // Delay for the register to be ready

  Wire.requestFrom(PINPOINT_ADDRESS, 4);
  for (uint8_t i = 0; i < 4; i++) {
    if (Wire.available()) {
      buffer[i] = Wire.read();
    }
  }

  // Convert bytes to a meaningful value (depends on Pinpoint module's data format)
  int32_t value = (buffer[3] << 24) | (buffer[2] << 16) | (buffer[1] << 8) | buffer[0];

  Serial.print("Received 4 bytes: ");
  for (int i = 0; i < 4; i++) {
    Serial.print(buffer[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
  Serial.print("Interpreted value: ");
  Serial.println(value);

  Serial.print("\n");
  delay(100);  // Adjust delay as necessary
}
