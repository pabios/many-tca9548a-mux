#include <Arduino.h>
#include "element/Element.h"

// Tca 1: a0=a1=a2=0  ==> 0x70
Adafruit_SSD1306 display0_70(128, 64, &Wire, -1);
Adafruit_SSD1306 display1_70(128, 64, &Wire, -1);
Adafruit_SSD1306 display2_70(128, 64, &Wire, -1);
Adafruit_SSD1306 display3_70(128, 64, &Wire, -1);
Adafruit_SSD1306 display4_70(128, 64, &Wire, -1);
Adafruit_SSD1306 display5_70(128, 64, &Wire, -1);
Adafruit_SSD1306 display6_70(128, 64, &Wire, -1);
Adafruit_SSD1306 display7_70(128, 64, &Wire, -1);


// Tca 2: a0=a1=0 et a2 = 1 ===> 0x74
Adafruit_SSD1306 display0_74(128, 64, &Wire, -1);
Adafruit_SSD1306 display1_74(128, 64, &Wire, -1);
Adafruit_SSD1306 display2_74(128, 64, &Wire, -1);
Adafruit_SSD1306 display3_74(128, 64, &Wire, -1);
Adafruit_SSD1306 display4_74(128, 64, &Wire, -1);
Adafruit_SSD1306 display5_74(128, 64, &Wire, -1);
Adafruit_SSD1306 display6_74(128, 64, &Wire, -1);
Adafruit_SSD1306 display7_74(128, 64, &Wire, -1);
//
Adafruit_SSD1306 tca1[] = {display0_70,display1_70,display2_70,display3_70,display4_70,display5_70,display6_70,display7_70};
Adafruit_SSD1306 tca2[] = {display0_74,display1_74,display2_74,display3_74,display4_74,display5_74,display6_74,display7_74};
//
Element oled2_70(0x70,4,tca1[2]);
Element oled7_70(0x70,4,tca1[7]);
Element oled4_70(0x70,4,tca1[4]);
Element oled5_70(0x70,5,tca1[5]);

Element oled2_74(0x74,4,tca2[2]);
Element oled7_74(0x74,4,tca2[7]);
//-----------------------------------------------------
void setupScreen(){
    Wire.begin();
    oled2_70.setupOled();
    oled7_70.setupOled();
    //
    oled2_74.setupOled();
    oled7_74.setupOled();
}
void loopScreen(){
    oled2_70.send("Screen 2 tca 1 - 0x70");
    delay(2000);
    oled7_70.send("Screen 7 tca 1 - 0x70");
    delay(2000);
    //
    oled2_74.send("Screen 2 tca 2 - 0x74");
    delay(2000);
    oled7_74.send("Screen 7 tca 2 - 0x74");
    delay(2000);
}
//-----------------------------------------------------
void setup() {
   setupScreen();
}

void loop() {
     loopScreen();
}
