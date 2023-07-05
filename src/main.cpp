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
Element oled4_70(0x70,4,tca1[4]);
Element oled5_70(0x70,5,tca1[5]);

Element oled4_74(0x74,4,tca2[4]);
//-----------------------------------------------------
void setupScreen(){
    Wire.begin();
    oled4_70.setupOled();
    oled5_70.setupOled();
    //
    oled4_74.setupOled();
}
void loopScreen(){
    oled4_70.send("hello 70-4");
    delay(2000);
    oled5_70.send("70-5 hello");
    delay(2000);
    oled4_74.send("4-74 bonjour");
    delay(2000);
}
//-----------------------------------------------------
void setup() {
   setupScreen();
}

void loop() {
     loopScreen();
}
