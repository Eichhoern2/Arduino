// DS18B20
#include <OneWire.h>
/*
  name=OneWire
  version=2.3.5
  author=Jim Studt, Tom Pollard, Robin James, Glenn Trewitt, Jason Dangel, Guillermo Lovato, Paul Stoffregen, Scott Roberts, Bertrik Sikken, Mark Tillotson, Ken Butcher, Roger Clark, Love Nystrom
  maintainer=Paul Stoffregen
  sentence=Access 1-wire temperature sensors, memory and other chips.
  paragraph=
  category=Communication
  url=http://www.pjrc.com/teensy/td_libs_OneWire.html
  architectures=*
*/
#include <DallasTemperature.h>
/*
  name=DallasTemperature
  version=3.8.0
  author=Miles Burton <miles@mnetcs.com>, Tim Newsome <nuisance@casualhacker.net>, Guil Barros <gfbarros@bappos.com>, Rob Tillaart <rob.tillaart@gmail.com>
  maintainer=Miles Burton <miles@mnetcs.com>
  sentence=Arduino Library for Dallas Temperature ICs
  paragraph=Supports DS18B20, DS18S20, DS1822, DS1820
  category=Sensors
  url=https://github.com/milesburton/Arduino-Temperature-Control-Library
  architectures=*
  #define ONE_WIRE_BUS 12
  OneWire oneWire(ONE_WIRE_BUS);
  DallasTemperature sensors(&oneWire);
*/
#define ONE_WIRE_BUS 12
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// LCD.Keypad Shield
#include <LiquidCrystal.h>
/*name=LiquidCrystal
  version=1.0.7
  author=Arduino, Adafruit
  maintainer=Arduino <info@arduino.cc>
  sentence=Allows communication with alphanumerical liquid crystal displays (LCDs).
  paragraph=This library allows an Arduino/Genuino board to control LiquidCrystal displays (LCDs) based on the Hitachi HD44780 (or a compatible) chipset, which is found on most text-based LCDs. The library works with in either 4 or 8 bit mode (i.e. using 4 or 8 data lines in addition to the rs, enable, and, optionally, the rw control lines).
  category=Display
  url=http://www.arduino.cc/en/Reference/LiquidCrystal
  architectures=*
*/
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup(void)
{
  // DS18B20
  sensors.begin();

  // LCD Keypad Shield
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("DS18B20:");
  lcd.setCursor(0, 1);
  // äöüß µΩαεΣπρp∞
  lcd.print("\341\357\365\342 \344\364\340\343\366\367\346p\363");
}

void loop(void)
{
  sensors.requestTemperatures();
  lcd.setCursor(9, 0);
  lcd.print(sensors.getTempCByIndex(0));
  lcd.setCursor(14, 0);
  lcd.print("\337C");
}
