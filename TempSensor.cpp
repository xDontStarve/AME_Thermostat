#include "TempSensor.h"
#include "mbed.h"

TempSensor::TempSensor(PinName temp_sensor) : _pin(temp_sensor){
}

float TempSensor::readTemperature(){
    float thermR=NULL;
    float rawTemp=NULL;
    float tempK=NULL;

    rawTemp = _pin.read_u16();
    thermR = R*((ADCRES/rawTemp)-1);
    tempK = 1/(log(thermR/R)/BETA+(1.0/T0));

    return(tempK - K);
}