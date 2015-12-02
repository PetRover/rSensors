//
// Created by Bryce Carter on 8/25/15.
//

#include "rSensors.h"

namespace RVR
{
    Switch::Switch(int pinNumber, SwitchType type)
    {
        this->type = type;
        switch (type)
        {
            case SwitchType::ADC_BASED:
                this->adcPin = new AdcPin(pinNumber);
                break;
            case SwitchType::GPIO_BASED:
                this->gpioPin = new GpioPin(pinNumber);
                break;
        }
    }


    SwitchState Switch::getState()
    {
        double adcValue;
        switch (this->type)
        {
            case SwitchType::ADC_BASED:
                adcValue = this->adcPin->getValue();
                VLOG(3) << "Got value of switch from ADC and it was: " << adcValue;
                if (adcValue > 0.9)
                {
                    return SwitchState::HIGH;
                }
                else
                {
                    return SwitchState::LOW;
                }
            case SwitchType::GPIO_BASED:
                switch (this->gpioPin->getValue())
                {
                    case GpioValue::HIGH:
                        VLOG(3) << "Got value of switch from GPIO and it was HIGH";
                        return SwitchState::HIGH;
                    case GpioValue::LOW:
                        VLOG(3) << "Got value of switch from GPIO and it was LOW";
                        return SwitchState::LOW;
                    default:
                        VLOG(3) << "Got value of switch from GPIO and it was ERROR";
                        return SwitchState::ERROR;

                }
        }
    }

}
