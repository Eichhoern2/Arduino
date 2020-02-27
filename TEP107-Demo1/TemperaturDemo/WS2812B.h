#include <FastLED.h>
/*
  name=FastLED
  version=3.3.3
  author=Daniel Garcia
  maintainer=Daniel Garcia <dgarcia@fastled.io>
  sentence=Multi-platform library for controlling dozens of different types of LEDs along with optimized math, effect, and noise functions.
  paragraph=Multi-platform library for controlling dozens of different types of LEDs along with optimized math, effect, and noise functions.
  category=Display
  url=https://github.com/FastLED/FastLED
  architectures=*
  includes=FastLED.h
*/
#define NUM_LEDS 9
#define DATA_PIN 11
CRGB leds[NUM_LEDS];

void initWS2812B() {
  FastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS); // Alternative Variante
  FastLED.setBrightness(10);
}
