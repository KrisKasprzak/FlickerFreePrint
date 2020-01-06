#include <ILI9341_t3.h>           // fast display driver lib
#include <ILI9341_t3_Controls.h>
#include <font_Arial.h>           // custom fonts that ships with ILI9341_t3.h
#include <font_LiberationMonoItalic.h>
#include "Colors.h"               // custom utilities definition
#include <SPI.h>
#include <SdFat.h>                // lib to talk to the SD card


// if you are not using custom fonts, you dont need this function. If you are using default fonts make sure you set the background color
// to fully paint old text Display.setTextColor(C_WHITE, C_BLACK);
#define FONT_TITLE Arial_24
#define FONT_DATE LiberationMono_24_Italic

#define TFT_CS        A1
#define TFT_DC        9
#define LED_PIN       A9

ILI9341_t3 Display(TFT_CS, TFT_DC);

FlickerFreePrint Bits(&Display, C_RED);

FlickerFreePrint Volts(&Display);

FlickerFreePrint Date(&Display);

float dVolts;
int dBits, i;
unsigned long curtime, thetime;
byte h, m, s;
char str[30];

void setup() {

  Serial.begin(9600);

  pinMode(TFT_CS,   OUTPUT);
  pinMode(TFT_DC,   OUTPUT);
  pinMode(10,       OUTPUT);
  while (!Serial);     // used for leonardo debugging

  Display.begin();
  Display.setRotation(1);
  Display.fillScreen(ILI9341_BLACK);

  analogWrite(LED_PIN, 255);

  Display.setTextColor(C_WHITE, C_BLACK);

  Date.SetBias(0, 0, 3, 0);

  Display.fillRect(10, 45, 300, 34, C_RED);


}

void loop() {

  i++;
  Display.setFont(FONT_TITLE);
  dBits = analogRead(A0) ;
  dVolts = dBits * 3.3 / 1024;

  Display.setCursor(10, 10);
  Display.print("Crued repaint: ");
  Display.fillRect(Display.getCursorX(), 10, 100, 30, C_BLACK);
  Display.print(i);

  Display.setCursor(10, 50);
  Display.print("FlickerFree: ");
  Bits.print(dBits);

  Display.setCursor(10, 90);
  Display.print("FlickerFree: ");
  Volts.print(dVolts, 4);

  Display.setFont(FONT_DATE);
  thetime = (millis() - curtime) / 1000;
  h = (thetime / 3600);
  m = (thetime - (3600 * h)) / 60;
  s = (thetime - (3600 * h) - (m * 60));
  sprintf(str, "Time: %02d:%02d:%02d", h, m, s);
  Display.setCursor(10, 130);
  Date.print(str);

  delay(100);


}
