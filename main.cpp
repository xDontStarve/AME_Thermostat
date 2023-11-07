#include "mbed.h"
#include "AnalogIn.h"
#include "TempSensor.h"
#include "Grove_LCD_RGB_Backlight.h"

AnalogIn rotatoryAngleSensor(A0);
TempSensor tempSensor(A1);
DigitalOut led(D4);

// main() runs in its own thread in the OS
int main()
{
    led=0;
    float tempDifference, currentTemp, desiredTemp, tempIncrement=0;
    
    while (true) {
        currentTemp= tempSensor.readTemperature();
        desiredTemp= rotatoryAngleSensor.read_u16()/1000;

        if(currentTemp < desiredTemp)
        {
            led = !led;
        }else {
            led = 1;
        }
        //Funcion para escribir en el LCD

        ThisThread::sleep_for(1500ms);
        
    }
}

