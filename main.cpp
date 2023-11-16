#include "mbed.h"
#include "Grove_LCD_RGB_Backlight.h"
#include "TempSensor.h"
// main() runs in its own thread in the OS

Grove_LCD_RGB_Backlight lcd(I2C_SDA, I2C_SCL);
int main()
{
    while (true) {
        lcd.setRGB(0, 0, 255);
        lcd.print("HOLANO");
    }
}

