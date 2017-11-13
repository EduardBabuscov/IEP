#include "spi.hpp"

Spi::Spi(uint8_t mode, uint16_t divider, uint8_t cs, uint8_t active) {
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);
    bcm2835_spi_setDataMode(mode);
    bcm2835_spi_setClockDivider(divider);
    bcm2835_spi_chipSelect(cs);
    bcm2835_spi_setChipSelectPolarity(cs, active);
}

uint8_t Spi::transfer(uint8_t data) {
    return bcm2835_spi_transfer(data);
}

Spi::~Spi() {
    bcm2835_spi_end();
    bcm2835_close();
}
