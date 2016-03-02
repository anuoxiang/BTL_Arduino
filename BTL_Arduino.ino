#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>
#include <SoftwareSerial.h>

// Color definitions
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

#define LED 8

/*
  Teensy3.x and Arduino's
  You are using 4 wire SPI here, so:
  MOSI:  11//Teensy3.x/Arduino UNO (for MEGA/DUE refere to arduino site)
  MISO:  12//Teensy3.x/Arduino UNO (for MEGA/DUE refere to arduino site)
  SCK:   13//Teensy3.x/Arduino UNO (for MEGA/DUE refere to arduino site)
  the rest of pin below:
*/

#define __CS 10
#define __DC 9

SoftwareSerial bt(7,6); //rx,tx

TFT_ILI9163C display = TFT_ILI9163C(__CS, __DC);
void setup() {
  //设置屏幕LED
  pinMode(LED,OUTPUT);
  digitalWrite(LED,HIGH);
  // 初始化蓝牙连接
  bt.begin(9600);
  display.begin();
  display.clearScreen();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (bt.available()) {
    uint8_t c = bt.read();
    display.print((char)c);
  }
}
