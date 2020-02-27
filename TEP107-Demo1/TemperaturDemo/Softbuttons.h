int sensorButton[5] = {0,4,5,6,7};

void initSoftbuttons() {
  pinMode(sensorButton[1], INPUT_PULLUP);
  pinMode(sensorButton[2], INPUT_PULLUP);
  pinMode(sensorButton[3], INPUT_PULLUP);
  pinMode(sensorButton[4], INPUT_PULLUP);
}
