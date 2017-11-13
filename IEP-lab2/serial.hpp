#ifndef SERIAL_HPP
#define SERIAL_HPP

#include "bcm2835.h"

class Serial {
public:
    Serial();
    virtual ~Serial();
    virtual uint8_t transfer(uint8_t data) = 0;
};

#endif // SERIAL_HPP
