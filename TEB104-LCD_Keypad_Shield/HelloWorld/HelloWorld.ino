// LCD.Keypad Shield
#include <LiquidCrystal.h>
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // LCD.Keypad Shield
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Hallo Welt!");
  lcd.setCursor(0, 1);
  lcd.print("LCD Keypadshield");
}

void loop() {
}
