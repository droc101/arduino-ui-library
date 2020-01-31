#include "Arduino.h"
#include "UI.h"

void UI::UButton(char* text, int x, int y, int w, int h, uint16_t clr, int idp) {
  //add button to array of points and DRAW IT
  tft.fillRect(x, y, w, h, clr);//fill base rect
  tft.setCursor(x + 6 , y);//set spot for text
  tft.setTextColor(ILI9341_BLACK);//set text color
  tft.setTextSize(1);//set text size
  tft.println(text);//draw text
  UTouchHandler(x, y, w, h, idp);//touch handler
}

void UI::UNumberField(int val, int x, int y, int w, int h, uint16_t clr, int id1, int id2) {
  //add to array of points and DRAW IT
  tft.fillRect(x, y, 60, 20, ILI9341_WHITE);//fill base rect
  tft.setCursor(x + 6 , y);//set spot for text
  tft.setTextColor(ILI9341_BLACK);//set text color
  tft.setTextSize(1);//set text size
  tft.println(val);//draw text
  
  //increment button
  tft.fillRect(x+60, y, 30, 20, ILI9341_LIGHTGREY);//fill base rect
  tft.setCursor(x + 6 , y);//set spot for text
  tft.setTextColor(ILI9341_BLACK);//set text color
  tft.setTextSize(1);//set text size
  tft.println("+");//draw text
  UTouchHandler(x+60, y, 30, 20, id1);
  
  //decrement button
  tft.fillRect(x+90, y, 30, 20, ILI9341_LIGHTGREY);//fill base rect
  tft.setCursor(x + 6 , y);//set spot for text
  tft.setTextColor(ILI9341_BLACK);//set text color
  tft.setTextSize(1);//set text size
  tft.println("-");//draw text
  UTouchHandler(x+90, y, 30, 20, id2);
}

void UI::ULabel(char* text, int x, int y) {
  //Draw label
  int w = tft.width();
  tft.setCursor(x + 6 , y);//set spot for text
  tft.setTextColor(ILI9341_BLACK);//set text color
  tft.setTextSize(1);//set text size
  tft.println(text);//draw text
}

void UI::UPanel(char* title, uint16_t clr) {
  //set bg and title (also draws menu bar)
  int w = tft.width();
  tft.fillScreen(clr);
  tft.fillRect(0, 10, tft.width(), 20, ILI9341_DARKGREY);//fill base rect
  tft.setCursor(0 + 6 , 10);//set spot for text
  tft.setTextColor(ILI9341_BLACK);//set text color
  tft.setTextSize(1);//set text size
  tft.println(title);//draw text
}


void UI::UStatusBar(char* text) {
  //add buttons to array of points and DRAW IT
  int w = tft.width();
  tft.fillRect(0, 0, tft.width(), 10, ILI9341_BLACK);//fill base rect
  tft.setCursor(6 , 0);//set spot for text
  tft.setTextColor(ILI9341_WHITE);//set text color
  tft.setTextSize(1);//set text size
  tft.println(text);//draw text
  
  //home button
  tft.fillRect((tft.width() - 20), 0, 20, 10, ILI9341_BLACK);//fill base rect
  tft.setCursor((tft.width() - 20) , 0);//set spot for text
  tft.setTextColor(ILI9341_WHITE);//set text color
  tft.setTextSize(1);//set text size
  tft.println("X");//draw text
  
  //old implementation of addTouchHandler();
  buttonX[0] = 0;
  buttonY[0] = 0;
  buttonW[0] = 20;
  buttonH[0] = 10;
}

void UI::UTouchHandler(int x, int y, int w, int h, int idp) {
  Serial.print("Adding touch handler../");
  //add a touch handler with an id
  buttonX[idp] = x;
  buttonY[idp] = y;
  buttonW[idp] = w;
  buttonH[idp] = h;
  Serial.println(" Added.");
}

int UI::getTouchId(int x, int y) {
  //good ol' button press calculator!
  int idp = 255;//255 is the "null" id for a touch on nothing
  for (byte i = 0; i < (sizeof(buttonX) / sizeof(buttonX[0])); i++) {
    // check the position and set id if in button
    if ((x > buttonX[i]) && (x > (buttonX[i] + buttonW[i]))) {
      if ((y < buttonY[i]) && (y > (buttonY[i] + buttonY[i]))) {
        Serial.print("Tocuh ID Found: ");
        Serial.println(idp);
      idp = i;
      }
    }
  }
  return idp;
}
