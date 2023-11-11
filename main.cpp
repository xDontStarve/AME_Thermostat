#include "mbed.h"
#include "AnalogIn.h"
#include "TempSensor.h"
#include "Grove_LCD_RGB_Backlight.h"
#include "THREAD"

AnalogIn rotatoryAngleSensor(A0);
TempSensor tempSensor(A1);
DigitalOut led(D4);
Grove_LCD_RGB_Backlight LCD(A2);
float offset;

// main() runs in its own thread in the OS
void showMessage(float value, bool currentORdesire)
{
        if (currentORdesire) 
        {
            LCD.locate(0,0);
            LCD.printf("Current Tem:");
            LCD.locate(0,1);
            LCD.printf("%d", value);
        }else{
            LCD.locate(0,0);
            LCD.printf("Desire Tem:");
            LCD.locate(0,1);
            LCD.printf("%d", value);
        }
        ThisThread::sleep_for(2000ms);
}

int main()
{
    led=0;
    float tempDifference, currentTemp, desiredTemp, tempIncrement=0;
    
    while (true) {
        currentTemp= tempSensor.readTemperature();
        //Write message in LCD Screen
        showMessage(currentTemp, true);

        desiredTemp= rotatoryAngleSensor.read_u16()/1000;
        //Write message in LCD Screen
        showMessage(desiredTemp, true);
        if (currentTemp < desiredTemp-1){
            led = !led;
            LCD.locate(0,0);
            LCD.printf("COLD");
        
        } else if (currentTemp > desiredTemp+1){
            led = 1;
            LCD.locate(0,0);
            LCD.printf("HEAT");
        }else {
            LCD.locate(0,0);
            LCD.printf("PERFECT");
            led = 0;
        }
    /*
        //targetMin + (value - sourceMin) * (targetMax - targetMin) / (sourceMax - sourceMin);
        desiredTemp= 5 + (desiredTemp-0) * (35 - 5) / (65 - 0); //Limit the desired temp from 5 to 35 celcius
        printf("currentTemp: %.2fºC\ndesiredTemp:%.2fºC\n", currentTemp, desiredTemp);
        tempDifference=desiredTemp-currentTemp;
        if (tempDifference!=currentTemp){
            led = !led;
            printf("Changing temperature to match desired temperature.\n");
            while (currentTemp < desiredTemp)
            {
                currentTemp+=0.25;
                ThisThread::sleep_for(1500ms);
            }
    */
    }

        ThisThread::sleep_for(1500ms);
        
}

/*
float offset;

while(true)
	curentTemp=read_temp();
	desiredTemp=rotatorySensor();

	currentTemp+=offset;
	if currentTemp!=desiredTemp{

		while (currentTemp!=desiredTemp){
			if (currentTemp<desiredTemp) offset-=0.1;
			else offset+=0.1;
			currentTemp+=offset;
			printf("Current temp: currentTemp");
			thisthread::sleep(500ms);
		}

	}


	printf("Current temp: currentTemp");
}
*/