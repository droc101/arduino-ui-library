#ifndef UI_h
#define UI_h

#include "Arduino.h"
#include <Adafruit_GFX.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_STMPE610.h>

class UI
{
  public:
    void UButton(char* text, int x, int y, int w, int h, uint16_t clr, int idp);
    void ULabel(char* text, int x, int y);
    void UPanel(char* title, uint16_t clr);
    void UNumberField(int val, int x, int y, int w, int h, uint16_t clr, int id1, int id2);
    void UStatusBar(char* text);
    void UTouchHandler(int x, int y, int w, int h, int idp);
    int touchId;
    int getTouchId(int x, int y);
  private:
    int buttonX[20];
    int buttonY[20];
    int buttonW[20];
    int buttonH[20];
    Adafruit_ILI9341 tft;
};

#endif
