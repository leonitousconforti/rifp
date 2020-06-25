#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define LED_PIN 6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 40

// NeoPixel brightness, 0 (min) to 255 (max)
#define BRIGHTNESS 255

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);

void setup()
{
    strip.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
    strip.show();  // Turn OFF all pixels ASAP
}

void loop() {}
