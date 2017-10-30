#ifndef PWM_H
#define PWM_H

#include "bcm2835.h"
// PWM output on RPi Plug P1 pin 12 (which is GPIO pin 18)
// in alt fun 5.
// Note that this is the _only_ PWM pin available on the RPi IO headers
#define PWMPIN RPI_GPIO_P1_12
// and it is controlled by PWM channel 0
#define PWM_CHANNEL 0

class Pwm
{
    public:
        Pwm(uint32_t frequency, uint32_t fillFactor);
        ~Pwm();
        void setFrequency(uint32_t frequency);
        void setFillFactor(uint32_t frequency);
        uint32_t getFrequency();
        uint32_t getFillFactor();
    private:
        uint32_t frequency;
        uint32_t fillFactor;
};

#endif // PWM_H
