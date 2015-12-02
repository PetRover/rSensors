//
// Created by Bryce Carter on 8/25/15.
//

#ifndef FIRMWARE_SENSORS_H
#define FIRMWARE_SENSORS_H

#include "pins.h"
#include "../rCore/easylogging++.h"

namespace RVR
{
    enum class SwitchType
    {
        ADC_BASED,
        GPIO_BASED
    };

    enum class SwitchState
    {
        HIGH,
        LOW,
        ERROR
    };

class Switch
{
private:
    GpioPin* gpioPin;
    AdcPin* adcPin;
    SwitchType type;
public:
    Switch(int pinNumber, SwitchType type);
    SwitchState getState();
};

}
#endif //FIRMWARE_SENSORS_H
