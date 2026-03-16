#include "SPI.h"
#include <TFT_eSPI.h>
#include <FlickerFreePrint.h>

// setup some colors
#define C_BLACK       0x0000
#define C_BLUE        0x001F
#define C_RED         0xF800
#define C_GREEN       0x07E0
#define C_CYAN        0x07FF
#define C_MAGENTA     0xF81F
#define C_YELLOW      0xFFE0
#define C_WHITE       0xFFFF

// create the display object
TFT_eSPI tft = TFT_eSPI();

// create a flicker free pnject for each data to be printed with the flicker free option
// the library used template scheme so you need to pass the data type in <>
FlickerFreePrint<TFT_eSPI> Data1(&tft, C_WHITE, C_BLACK);
FlickerFreePrint<TFT_eSPI> Data2(&tft, C_WHITE, C_BLACK);
FlickerFreePrint<TFT_eSPI> Data3(&tft, C_WHITE, C_BLACK);

// setup some variables
int i;
float j;
unsigned long curtime, thetime;
byte h, m, s;
char str[30];

void setup() {

  Serial.begin(9600);

  pinMode(TFT_CS,   OUTPUT);
  pinMode(TFT_DC,   OUTPUT);

  // while (!Serial);     // used for leonardo debugging

  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(C_BLACK);

  tft.fillRect(0, 0, 319, 35, C_RED);

}

void loop() {
  
  // get some data
  i++;
  j += 0.0013;
  thetime = millis();
  h = (thetime / 3600000) / 1000;
  m = (thetime / 1000 - (3600 * h)) / 60;
  s = (thetime / 1000 - (3600 * h) - (m * 60));
  sprintf(str, "Time: %02d:%02d:%02d", h, m, s);


  // first example
  tft.setFreeFont(&FreeSansOblique12pt7b);
  tft.setCursor(10, 30);
  tft.setTextColor(C_WHITE);
  tft.print("Crude repaint: ");
  tft.fillRect(tft.getCursorX(), 0, 100, 35, C_RED);
  tft.print(i);

  // now draw some data using flicker free print
  tft.setCursor(10, 80);
  tft.setTextColor(C_WHITE, C_RED);
  tft.print("FlickerFree library: ");

  tft.setCursor(10, 130);
  Data1.setTextColor(C_YELLOW, C_BLACK);
  Data1.print(i);

  tft.setCursor(10, 180);
  Data2.setTextColor(C_BLUE, C_BLACK);
  Data2.print(j, 4);

  tft.setCursor(10, 230);
  Data3.setTextColor(C_GREEN, C_BLACK);
  Data3.print(str);

  delay(100);

}
