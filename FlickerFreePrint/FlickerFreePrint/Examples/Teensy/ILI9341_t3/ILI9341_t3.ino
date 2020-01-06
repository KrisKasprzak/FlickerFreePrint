#include <ILI9341_t3.h>           // fast display driver lib
#include <FlickerFreePrint.h>
#include <font_Arial.h>           // custom fonts for the ILI9341_t3.h
#include <font_LiberationMonoItalic.h>
#include <SPI.h>

#define TFT_CS        A1      //odd I know
#define TFT_DC        9

// setup some colors
#define  C_BLACK      0x0000
#define C_BLUE        0x001F
#define C_RED         0xF800
#define C_GREEN       0x07E0
#define C_CYAN        0x07FF
#define C_MAGENTA     0xF81F
#define C_YELLOW      0xFFE0
#define C_WHITE       0xFFFF

// create the display object
ILI9341_t3 Display(TFT_CS, TFT_DC);

// create a flicker free pnject for each data to be printed with the flicker free option
// the library used template scheme so you need to pass the data type in <>
FlickerFreePrint<ILI9341_t3> Data1(&Display, C_WHITE, C_BLACK);
FlickerFreePrint<ILI9341_t3> Data2(&Display, C_WHITE, C_BLACK);
FlickerFreePrint<ILI9341_t3> Data3(&Display, C_WHITE, C_BLACK);

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

  Display.begin();
  Display.setRotation(1);
  Display.fillScreen(C_BLACK);

  Display.fillRect(0, 0, 319, 35, C_RED);

}

void loop() {

  i++;
  j += 0.0013;
  // get some data

  thetime = millis();
  h = (thetime / 3600000) / 1000;
  m = (thetime / 1000 - (3600 * h)) / 60;
  s = (thetime / 1000 - (3600 * h) - (m * 60));

  sprintf(str, "Time: %02d:%02d:%02d", h, m, s);


  // first example
  Display.setFont(LiberationMono_18_Italic);
  Display.setCursor(10, 10);
  Display.setTextColor(C_WHITE, C_BLACK);
  Display.print("Crude repaint: ");
  Display.fillRect(Display.getCursorX(), 0, 100, 35, C_RED);
  Display.print(i);


  Display.setFont(Arial_24);
  Display.setCursor(10, 50);
  Display.setTextColor(C_WHITE, C_RED);
  Display.print("FlickerFree library: ");

  Display.setFont(Arial_18);

  Display.setCursor(10, 100);
  Data1.setTextColor(C_YELLOW, C_BLACK);
  Data1.print(i);

  Display.setCursor(10, 150);
  Data2.setTextColor(C_BLUE, C_BLACK);
  Data2.print(j, 4);

  Display.setCursor(10, 200);
  Data3.setTextColor(C_GREEN, C_BLACK);
  Data3.print(str);

  delay(100);

}
