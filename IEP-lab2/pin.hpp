#ifndef PIN_H
#define PIN_H

#define INPUT  0x00
#define OUTPUT 0x01

#define PULL_OFF  0x00
#define PULL_DOWN 0x01
#define PULL_UP   0x02

#include "bcm2835.h"

class Pin
{
public:
    Pin(uint8_t pinNumber, uint8_t direction);
    Pin(uint8_t pinNumber, uint8_t direction, uint8_t pull);
    ~Pin();
    uint8_t get();
    void set(uint8_t);
    void changeDirection(uint8_t);
private:
    uint8_t pinNumber;
    uint8_t direction;
    uint8_t pull;
    uint8_t value;
};

#endif // PIN_H
