#include <ss_oled.h>
/*
  name=ss_oled
  version=3.3.0
  author=Larry Bank
  maintainer=Larry Bank
  sentence=Small and simple OLED display library.
  paragraph=Designed to use as little FLASH and RAM as possible to run on constrained devices such as the ATtiny series. Automatically detects the display address (3C or 3D) and the controller type (SSD1306, SH1106 or SH1107). Includes 4 sizes of fixed fonts (6x8, 8x8, 16x16, 16x32). Can use I2C, SPI or bit bang I2C on any 2 GPIO pins with the use of my BitBang_I2C library. Supports display sizes of: 128x128, 128x64, 128x32, 64x32, 96x16, 72x40. Now includes scrolling text/gfx and deferred rendering.
  category=Display
  url=https://github.com/bitbank2/ss_oled
  architectures=*
  includes=ss_oled.h
  depends=BitBang_I2C
*/

static uint8_t *ucBackBuffer = NULL;

void initSSD1306() {
  int rc;
  rc = oledInit(OLED_128x32, 0, 0, -1, -1, -1, 400000L); // use standard I2C bus at 400Khz
}
