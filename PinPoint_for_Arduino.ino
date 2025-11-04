#include <Wire.h>

#define PINPOINT_ADDRESS 0x31  // Replace with the actual I2C address
// Add more registers as needed

void setup() {
  Serial.begin(115200);
  Wire.begin();
}

void loop() {
  uint8_t buffer[4];

  // For reading position registers
  Wire.beginTransmission(PINPOINT_ADDRESS);
  Wire.write(8);
  Wire.endTransmission(false);

  delay(25);  // Delay for the register to be ready

  Wire.requestFrom(PINPOINT_ADDRESS, 4);
  for (uint8_t i = 0; i < 4; i++) {
    if (Wire.available()) {
      buffer[i] = Wire.read();
    }
  }

  // Convert 4 bytes to float
  float value;
  memcpy(&value, buffer, 4);

  Serial.print("Received 4 bytes: ");
  for (int i = 0; i < 4; i++) {
    Serial.print(buffer[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
  Serial.print("Interpreted float value: ");
  Serial.println(value, 6);  // Print with 6 decimal places

  Serial.print("\n");
  delay(100);  // Adjust delay as necessary
}