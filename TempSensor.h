#ifndef MBED_TEMPSENSOR_H
#define MBED_TEMPSENSOR_H
#include "mbed.h"

#define ADCRES 65535.0
#define R 100000.0
#define BETA 4250
#define K 273.15
#define T0 298.15

class TempSensor{
    public:
        TempSensor(PinName temp_sensor);
        float readTemperature();
    private:
        AnalogIn _pin;
};

#endif