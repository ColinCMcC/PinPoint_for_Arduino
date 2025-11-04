#ifndef main
#define main

int enum PinPointRegisterMap {
  unused,
  ID,
  VERSION,
  STATUS,
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

#endif