#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include<Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_MOSI   11
#define OLED_CLK   13
#define OLED_DC    6
#define OLED_CS    10
#define OLED_RESET 7
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

#define BtnB 2
#define BtnR 3
#define press 0 // pull up : always high; if press 0

int val = 1;
int val_r = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(BtnB, INPUT_PULLUP);
  pinMode(BtnR, INPUT_PULLUP);
  display.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  // If button blue is pressed, blue light on
  display.clearDisplay();
  display.fillRect(0, 0, 128, 16, 1);
  display.setTextSize(2);
  display.setTextColor(0);
  display.setCursor(1,1);
  display.println("PRESS ME!");
  

  val = digitalRead(BtnB);
  if (val == press)
  {
    /* code */
    display.fillCircle(64, 40, 23, 1);
    // eyes
    display.fillRect(52, 30, 5, 5, 0);
    display.fillRect(72, 30, 5, 5, 0);

    // smiling mouth
    int x = 52;
    int y = 40;
    int w = 26;
    int h = 1;
    for (size_t i = 1; i < 17; i++)
    {
      /* code */
      display.fillRect(x, y, w, h, 0);
      if (i % 3 == 0) x = x + 1;
      y = y + h;
      if (i % 3 == 0) w = w - 2;
    }
    
  }

  val_r = digitalRead(BtnR);
  if (val_r == press)
  {
    /* code */
    display.fillCircle(64, 40, 23, 1);
    // eyes
    display.fillRect(52, 30, 5, 5, 0);
    display.fillRect(72, 30, 5, 5, 0);
    //angry mouth
    int x = 57;
    int y = 40;
    int w = 16;
    int h = 1;
    for (size_t i = 1; i < 17; i++)
    {
      /* code */
      display.fillRect(x, y, w, h, 0);
      if (i % 3 == 0) x = x - 1;
      y = y + h;
      if (i % 3 == 0) w = w + 2;
    }
  }
  
  display.display();
}