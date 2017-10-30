#include "pwm.hpp"

Pwm::Pwm(uint32_t frequency,uint32_t fillFactor):
    frequency(frequency),fillFactor(fillFactor)
{
    bcm2835_gpio_fsel(PWMPIN, BCM2835_GPIO_FSEL_ALT5);
    bcm2835_pwm_set_clock(BCM2835_PWM_CLOCK_DIVIDER_16);
    bcm2835_pwm_set_mode(PWM_CHANNEL, 1, 1);
}

void Pwm::setFrequency(uint32_t newValue)
{
    frequency=newValue;
    bcm2835_pwm_set_range(PWM_CHANNEL, frequency);
}

void Pwm::setFillFactor(uint32_t newValue)
{
    if(newValue<=100)
    {
        fillFactor=newValue;
        bcm2835_pwm_set_data(PWM_CHANNEL, (newValue*frequency)/100);
    }

}

uint32_t Pwm::getFrequency()
{
    return frequency;// trebuie bcm2835_pwm_set_... facut si la get?
}

uint32_t Pwm::getFillFactor()
{
    return fillFactor;
}

Pwm::~Pwm()
{
    uint32_t *pointFrequency = &frequency;
    delete pointFrequency;
    uint32_t *pointFill = &fillFactor;
    delete pointFill;
}

