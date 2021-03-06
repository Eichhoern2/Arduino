#include <eHaJo_LM75.h>
/*
  name=eHaJo LM75-Addon-Board
  version=1.0.1
  author=Hannes Jochriem <info@ehajo.de>
  maintainer=Hannes Jochriem <info@ehajo.de>
  sentence=Support for I²C digital temperature sensor addon-board LM75.
  paragraph=More information about the addon-board on the shop: https://www.ehajo.de/bausaetze/bedrahtet/207/temperatur-addon-lm75
  category=Sensors
  url=https://github.com/ehajo/LM75B
  architectures=*
  includes=eHaJo_LM75.h
*/

EHAJO_LM75 sensorUmgebungstemperatur;
float temperaturUmgebungFloat = 0.0;
