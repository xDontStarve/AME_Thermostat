#include "mbed.h"
#include "AnalogIn.h"
#include "TempSensor.h"

AnalogIn rotatoryAngleSensor(A0);
TempSensor tempSensor(A1);
DigitalOut led(D4);


// main() runs in its own thread in the OS
int main()
{
    led=1;
    while (true) {
        led=!led;
        printf("temp: %f\nrotatory:%d\n", tempSensor.readTemperature(), rotatoryAngleSensor.read_u16()/1000);
        ThisThread::sleep_for(500ms);
        
    }
}

