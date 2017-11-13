// blink.c
//
// Example program for bcm2835 library
// Blinks a pin on an off every 0.5 secs
//
// After installing bcm2835, you can build this
// with something like:
// gcc -o blink blink.c -l bcm2835
// sudo ./blink
//
// Or you can test it before installing with:
// gcc -o blink -I ../../src ../../src/bcm2835.c blink.c
// sudo ./blink
//
// Author: Mike McCauley
// Copyright (C) 2011 Mike McCauley
// $Id: RF22.h,v 1.21 2012/05/30 01:51:25 mikem Exp $
#include "bcm2835.h"

#include "pin.hpp"
#include "pwm.hpp"
#include "spi.hpp"

#include <stdio.h>
// Blinks on RPi Plug P1 pin 11 (which is GPIO pin 17)
#define PIN RPI_GPIO_P1_11


int main(int argc, char **argv)
{
    bcm2835_set_debug(1);
    if (!bcm2835_init())
    {
      printf("bcm2835_init failed. Are you running as root??\n");
      return 1;
    }
    if (!bcm2835_spi_begin())
    {
      printf("bcm2835_spi_begin failed. Are you running as root??\n");
      return 1;
    }

    Spi spi(BCM2835_SPI_MODE0
        , BCM2835_SPI_CLOCK_DIVIDER_65536
        , BCM2835_SPI_CS0
        , LOW);
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);
    uint8_t send_data = 0x23;
    uint8_t read_data = spi.transfer(send_data);
    if (send_data != read_data) {
        printf("Do you have the loopback from MOSI to MISO connected?\n");
    }
    return 0;
}
