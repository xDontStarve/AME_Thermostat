#include "mbed.h"
#include "Grove_LCD_RGB_Backlight.h"
#include "TempSensor.h"
// main() runs in its own thread in the OS
Grove_LCD_RGB_Backlight lcd(I2C_SDA, I2C_SCL);
TempSensor tempSensor(A0);
AnalogIn potSensor (A1);
DigitalOut led(D4);

void funcionPrincipal()
{
    float desireTemp, currentTemp;
    led = 0;
    desireTemp = potSensor.read();
    currentTemp = tempSensor.readTemperature();
    if (desireTemp < currentTemp)
    {
        led = 1;
    }else if (desireTemp > currentTemp)
    {
        while (desireTemp > currentTemp)
        {
            led = !led;
        }
    }
}

int main()
{
    while (true) {
        funcionPrincipal();
        lcd.setRGB(0, 0, 255);
        lcd.print("HOLANO");
    }
}

