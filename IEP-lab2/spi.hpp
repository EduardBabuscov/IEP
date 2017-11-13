#ifndef SPI_H
#define SPI_H

#include "serial.hpp"
#include "bcm2835.h"

class Spi : public Serial
{
    uint8_t receivedData;
public:
    Spi(uint8_t mode, uint16_t divider, uint8_t cs, uint8_t active);
    ~Spi();
    uint8_t transfer(uint8_t data) override;
};

#endif // SPI_H
