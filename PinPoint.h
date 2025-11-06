// LED.h
#ifndef PinPoint_h
#define PinPoint_h

#include <Arduino.h>
#include <Wire.h>

class PinPointModule {
private:
  struct PinPointData {
    float
      xPos = 0,
      yPos = 0,
      hDir = 0,
      xVel = 0,
      yVel = 0,
      hVel = 0,
      ticksPerMM = 0,
      xPodOffset = 0,
      yPodOffset = 0,
      yawOffset = 0;
  };




  int _address;
  PinPointData data;



public:
  enum PinPointRegisterMap {
    unused,
    ID,
    VERSION,
    DEVICE_STATUS,
    CONTROL,
    LOOP_TIME,
    RAW_X_ENCODER_VAL,
    RAW_Y_ENCODER_VAL,
    X_POS,
    Y_POS,
    H_ORIENTATION,
    X_VELOCITY,
    Y_VELOCITY,
    H_VELOCITY,
    TICKS_PER_MM,
    X_POD_OFFSET,
    Y_POD_OFFSET,
    YAW_OFFSET,
    BULK_READ,
  };

  PinPointModule(int address);

  float xPos();
  float yPos();
  float hDir();
  void update();
  float readFloatRegister(int reg);
};

#endif