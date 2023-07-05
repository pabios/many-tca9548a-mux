//
// Created by pabiosoft on 05/07/2023.
//

#include "Element.h"


Element::Element(uint8_t addr, uint8_t chan, Adafruit_SSD1306& oled){
    this->oled = oled;
    this->address = addr;
    this->channel = chan;
}

byte Element::selectChannel() const {
    Wire.beginTransmission(this->address);
    Wire.write(1 << this->channel);
    Wire.endTransmission();

    return this->channel;
}

void Element::disableTCA() const{
    Wire.beginTransmission(this->address);
    Wire.write(0);
    Wire.endTransmission();
}

void Element::setupOled(){
    //byte tcaAddress = this->selectChannel();
    this->selectChannel();
    this->oled.begin(SSD1306_SWITCHCAPVCC,  0x3C);
    this->oled.display();
    this->disableTCA();
}

void Element::send(String message) {
    this->selectChannel();
    this->oled.clearDisplay();
    this->oled.setTextSize(1);
    this->oled.setTextColor(WHITE);
    this->oled.setCursor(0,20);
    this->oled.println(message);
    Serial.println(message);
    //this->display.println(message[1]);
    this->oled.display();
    this->disableTCA();
}