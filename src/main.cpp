#include <Arduino.h>
#include "tca/tca.h"


void setup() {
   setupTca();
}

void loop() {
    drawrect(0);// 0x70
    drawrect(1);// 0x74
}
