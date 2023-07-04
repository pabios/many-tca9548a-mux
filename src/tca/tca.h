//
// Created by pabiosoft on 05/07/2023.
//

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#ifndef PCA_TCA_H
#define PCA_TCA_H

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C

byte tcaI2CAddress[] = {0x70,0x74}; // 0x72

byte numberOfTCAs = 2;
byte numberOfDevicesPerTCA = 2;
const int numberOfDevices = 2;


void setupTca();
byte setTCAAndChannel(byte i);
void disableTCA(byte tca);
void setupOled(byte i,Adafruit_SSD1306& oled);
void drawrect(int i);

#endif //PCA_TCA_H
