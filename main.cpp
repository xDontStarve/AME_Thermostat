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
    led=1;
    float tempDifference, currentTemp, desiredTemp, tempIncrement=0;
    
    while (true) {
        currentTemp= tempSensor.readTemperature()+tempDifference;
        desiredTemp= rotatoryAngleSensor.read_u16()/1000;

        //targetMin + (value - sourceMin) * (targetMax - targetMin) / (sourceMax - sourceMin);
        desiredTemp= 5 + (desiredTemp-0) * (35 - 5) / (65 - 0); //Limit the desired temp from 5 to 35 celcius
        printf("currentTemp: %.2fºC\ndesiredTemp:%.2fºC\n", currentTemp, desiredTemp);
        tempDifference=desiredTemp-currentTemp;
        if (tempDifference!=currentTemp){
            printf("Changing temperature to match desired temperature.\n");
        }
        ThisThread::sleep_for(1500ms);
        
    }
}

