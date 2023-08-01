/*
 * Temperature meter.c
 *
 * Created: 7/28/2023 12:09:28 AM
 * Author : Osama
 */ 
#define  F_CPU 8000000ul
#include <util/delay.h>
#include "LCD.h"
#include "ADC_interface.h"
unsigned char read_value ;
unsigned short temperature , volt;
int main(void)
{
	LCD_init();
    ADC_init();
	LCD_sendstring("Temp=");
    while (1) 
    {
		volt = (ADC_read()*2.5);
		if(volt >= 1000)
		{
		temperature = (volt-1000)/10;	
		if(temperature < 10)
		{
			LCD_movecursor(1,6);
			LCD_send_char(' ');
			LCD_send_char(temperature+48);
			LCD_send_char(0xDF);
			LCD_send_char('c');
			LCD_send_char(0x20);
		}
		else if(temperature < 100)
		{
			LCD_movecursor(1,6);
			LCD_send_char(' ');
			LCD_send_char((temperature / 10)+48);
			LCD_send_char((temperature % 10)+48);
			LCD_send_char(0xDF);
			LCD_send_char('c');
		}
		}
		else
		{
			temperature = (1000 - volt)/10;
			if(temperature < 10)
			{
				LCD_movecursor(1,6);
				LCD_send_char(' ');
				LCD_send_char('-');
				LCD_send_char(temperature + 48);
				LCD_send_char(0xDF);
				LCD_send_char('c');
			}
			else
			{
				LCD_movecursor(1,6);
				LCD_send_char('-');
				LCD_send_char((temperature / 10)+ 48);
				LCD_send_char((temperature % 10)+ 48);
				LCD_send_char(0xDF);
				LCD_send_char('c');
			}
		}
    }
}

