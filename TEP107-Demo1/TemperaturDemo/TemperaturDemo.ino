/*
   Variablennamen:
                     temperaturUmgebungFloat
                                       ^^^^^ Typ (int, float, chat, array ...)
                               ^^^^^^^^      Prädikat (Haus, Vorlauf, Waage1, Lichtschalter ...)
                     ^^^^^^^^^^              Subjekt  (Physikalische Größe, ...)
   Funktionsnamen:
                     initSSD1306()
                         ^^^^^^^    Subjekt
                     ^^^^           Operation (init, set, get)
*/

/*
    Liste der Komponenten

    Umgebungstemperatur:              float temperaturUmgebungFloat
    Temperatursensor (LM75):          EHAJO_LM75 sensorUmgebungstemperatur

    Monitor (Schnittstelle zum PC)

    Display (SSD1206)

    LED-Leiste (WS2112B)              CRGB leds

    Softbuttons
*/


/*
   +==============================================================================+
   |   Bibliotheken einbinden, initialisieren, spezifische Variablen definieren   |
   +==============================================================================+
*/
#include "LM75.h" // Temperatursensor
#include "SSD1306.h" // OLED-Display
#include "WS2812B.h" // LED-leiste
#include "Softbuttons.h" // Softbuttons

/*
   +==========================+
   |   Variablen definieren   |
   +==========================+
*/
char str_temp[6]; // Für Umwandlung gebraucht, da %f in Arduino nicht implementiert ist :-(
char temperaturString[10]; // Für Ausgabe
int ledNummer = 0; // Für WS2812B


/*
   +=======================================================+
   |   Temperatur-Schwellwerte und Farben für LED-Leiste   |
   +=======================================================+
*/
// float temperaturSchwelleFloatArray[7] = { -100, 3, 14, 18, 20, 22}; // Typische Werte für Wohnungen
float temperaturSchwelleFloatArray[6] = { -100, 22, 23, 24, 25, 26}; // Werte zum Testen
struct CRGB temperaturFarbeArray[6] = {CRGB::Violet, CRGB::Blue, CRGB::LightBlue, CRGB::Green, CRGB::Yellow, CRGB::Red};


/*
   +===========+
   |   Setup   |
   +===========+
*/

void setup() {
  // Serielle Schnittstelle für Monitor
  Serial.begin(9600);

  // Für alle I²C-Bausteine
  Wire.begin();

  // SSD1306
  initSSD1306();

  // WS2812B
  initWS2812B();

  // Softbuttons
  initSoftbuttons();
}

/*
   +==========+
   |   Loop   |
   +==========+
*/
void loop() {
  /*
    +======================+
    |   Temperatur lesen   |
    +======================+
  */
  temperaturUmgebungFloat = sensorUmgebungstemperatur.getTemp();


  /*
     +==================================================================+
     |   Temperatur verabeiten, wenn realistischer Wert gelesen wurde   |
     +==================================================================+
  */
  if (temperaturUmgebungFloat < 50) {

    // Temperatur in String umwandeln
    dtostrf(temperaturUmgebungFloat, 4, 2, str_temp);     // Für Umwandlung gebraucht, da %f in Arduino nicht implementiert ist :-(
    sprintf(temperaturString, "%s", str_temp);    // Für Umwandlung gebraucht, da %f in Arduino nicht implementiert ist :-(

    // Ausgabe Monitor
    Serial.println(temperaturString);

    /*
       +=============================+
       |   Ausgabe SSD1206-Display   |
       +=============================+
    */
    oledFill(0x0, 1); // Display löschen
    oledWriteString(0, 0, 0, (char *)"Temperatur", FONT_NORMAL, 0, 1);  // Ausgabe "Temperatur"
    oledWriteString(0, 90, 0, temperaturString, FONT_NORMAL, 0, 1);     // Ausgabe der Temperatur

    /*
       +========================+
       |   Ausgabe LED-Leiste   |
       +========================+
    */
    for (int i = 0; i < 6; i++) {
      if (temperaturUmgebungFloat >  temperaturSchwelleFloatArray[i]) {
        leds[8] = temperaturFarbeArray[i];
      }
    }
    FastLED.show();


  } // if (temperaturUmgebungFloat < 50)



  /*
     +=================+
     |   Softbuttons   |
     +=================+
  */
  for (int i = 1; i <= 4; i++) {

    if (digitalRead(sensorButton[i]) == HIGH) {
      leds[i] = CRGB::Red;
      FastLED.show();
    }
    else {
      leds[i] = CRGB::Green;
      FastLED.show();
    }
    FastLED.show();
  }

  /*
     +==========================+
     |   Schleifenverzögerung   |
     +==========================+
  */

  delay(100);
}
