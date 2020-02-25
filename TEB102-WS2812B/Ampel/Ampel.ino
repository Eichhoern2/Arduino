
#include <FastLED.h>
#define NUM_LEDS 9
#define DATA_PIN 2
CRGB leds[NUM_LEDS];

void setup() {
  delay(2000);
  //FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS); // Normale Variante
  FastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS); // Alternative Variante
}

void loop() {
    leds[0] = CRGB::Red;
    leds[1] = CRGB::Red;
    leds[2] = CRGB::Red;
    leds[3] = CRGB::Black;
    leds[4] = CRGB::Black;
    leds[5] = CRGB::Black;
    leds[6] = CRGB::Black;
    leds[7] = CRGB::Black;
    leds[8] = CRGB::Black;
    FastLED.show();
    delay(1000);

    leds[0] = CRGB::Red;
    leds[1] = CRGB::Red;
    leds[2] = CRGB::Red;
    leds[3] = CRGB::Yellow;
    leds[4] = CRGB::Yellow;
    leds[5] = CRGB::Yellow;
    leds[6] = CRGB::Black;
    leds[7] = CRGB::Black;
    leds[8] = CRGB::Black;
    FastLED.show();
    delay(1000);

    leds[0] = CRGB::Black;
    leds[1] = CRGB::Black;
    leds[2] = CRGB::Black;
    leds[3] = CRGB::Black;
    leds[4] = CRGB::Black;
    leds[5] = CRGB::Black;
    leds[6] = CRGB::Green;
    leds[7] = CRGB::Green;
    leds[8] = CRGB::Green;
    FastLED.show();
    delay(1000);

    leds[0] = CRGB::Black;
    leds[1] = CRGB::Black;
    leds[2] = CRGB::Black;
    leds[3] = CRGB::Yellow;
    leds[4] = CRGB::Yellow;
    leds[5] = CRGB::Yellow;
    leds[6] = CRGB::Black;
    leds[7] = CRGB::Black;
    leds[8] = CRGB::Black;
    FastLED.show();
    delay(1000);  
}
