#include "pin.hpp"

Pin::Pin(uint8_t pinNumber, uint8_t direction)
    : pinNumber(pinNumber)
    , direction(direction)
{
    if (direction == INPUT)
    {
        pull = PULL_OFF;
        bcm2835_gpio_fsel(pinNumber, direction);
    }
    else
    {
        pull = PULL_DOWN;
        bcm2835_gpio_fsel(pinNumber, direction);
        bcm2835_gpio_set_pud(pinNumber, pull);
    }
}

Pin::Pin(uint8_t pinNumber, uint8_t direction, uint8_t pull)
    : pinNumber(pinNumber)
    , direction(direction)
    , pull(pull)
{
    if (direction == INPUT)
    {
        pull = PULL_OFF;
        bcm2835_gpio_fsel(pinNumber, direction);
    }
    else
    {
        bcm2835_gpio_fsel(pinNumber, direction);
        bcm2835_gpio_set_pud(pinNumber, pull);
    }
}

uint8_t Pin::get()
{
    return bcm2835_gpio_lev(pinNumber);
}

void Pin::set(uint8_t newValue)
{
    if (direction == OUTPUT)
    {
        if ((newValue == LOW) || (newValue == HIGH))
        {
            bcm2835_gpio_write(pinNumber, newValue);
        }
    }
}

void Pin::changeDirection(uint8_t newDir)
{
    if ((newDir == INPUT) || (newDir == OUTPUT))
    {
        bcm2835_gpio_fsel(pinNumber, newDir);
    }
}

Pin::~Pin()
{
    uint8_t * pointer = & pinNumber;
    delete pointer;
    pointer = &direction;
    delete pointer;
    pointer = &pull;
    delete pointer;
}
