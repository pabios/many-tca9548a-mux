//
// Created by pabiosoft on 05/07/2023.
//

#include "tca.h"

Adafruit_SSD1306 display1(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_SSD1306 display2(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Adafruit_SSD1306 display[] = {display1,display2};


byte setTCAAndChannel(byte i){
    byte tca = i/numberOfTCAs;
    byte channel = i%numberOfDevicesPerTCA;

    Wire.beginTransmission(tcaI2CAddress[tca]); // i.e: 0x70
    Wire.write(1 << channel); // i.e: bus 1 . decalage a gauche
    Wire.endTransmission();
    return tca;
}
void disableTCA(byte tca){
    Wire.beginTransmission(tcaI2CAddress[tca]);
    Wire.write(0);
    Wire.endTransmission();
}

void setupOled(byte i,Adafruit_SSD1306& oled){
    byte tca = setTCAAndChannel(i);
    oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
    disableTCA(tca);
}

void setupTca(){
    Wire.begin();
    for(int i=0; i<numberOfDevices; i++){
        setupOled(i,display[i]);
    }
}

void drawrect(int pos) {

    display[pos].clearDisplay();

    for(int16_t i=0; i<display[pos].height()/2; i+=2) {
        display[pos].drawRect(i, i, display[pos].width()-2*i, display[pos].height()-2*i, SSD1306_WHITE);
        display[pos].display();
        delay(1);
    }

    delay(2000);
}