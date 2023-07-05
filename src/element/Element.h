//
// Created by pabiosoft on 05/07/2023.
//

#ifndef PCA_ELEMENT_H
#define PCA_ELEMENT_H

#include <Adafruit_SSD1306.h>

class Element{
private:
    Adafruit_SSD1306 oled;
    uint8_t address;
    uint8_t channel;


public:
    Element(uint8_t addr, uint8_t chan, Adafruit_SSD1306& oled);
    byte selectChannel() const;
    void disableTCA() const;
    void setupOled();
    void send(String message);
};

#endif //PCA_ELEMENT_H
