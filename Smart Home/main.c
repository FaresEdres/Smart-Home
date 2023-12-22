#include "MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>
#include "Utils.h"
#include "ECUAL/Keypad/Keypad_Interface.h"
#include "ECUAL/LCD/LCD_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#define F_CPU 8000000UL
/*
#include "interrupt.h" 

#define GIE 7
#define INT2    5
#define ISC2    6

*/
u8 key_pressed;
int main(void)
{
	/* //PA7.5 ARE OUTPUT
	 DDRA=(1<<7);

	 
	 
	 //SET EXTERNAL INTERRUPT FOR INT0, INT1 AND INT1
	 GICR=(1<<5);
	 //SET GLOBLE INTERRUPT
	 sei();
	//
*/

	 

	u16 test=0;
		//DIO_vsetPINDir('B',2,0); //Initializes push button
		//DIO_vsetPINDir('A',1,1); //Initializes LED
		DIO_vsetPINDir('B',4,1);//Initializes FAN
		DIO_vsetPINDir('A',0,0);//Initializes Temp Sensor
	LCD_vInit();//initializes the LCD screen
	Keypad_vInit();//initializes the keypad
	ADC_init();

	
	LCD_vsend_string("Welcome to smart");
	LCD_movecursor(2,1);
	LCD_vsend_string("home system");
	_delay_ms(1000);//Halt the system for the given time in (ms)
	LCD_clearscreen();
	LCD_vsend_cmd(DISPLAY_ON_CURSOR_ON);

	while (1)//loop till the user finish inserting the pass
	{
		
		
				LCD_clearscreen();
				LCD_vsend_cmd(DISPLAY_ON_CURSOR_ON);
		LCD_vsend_string("1:LAMP");
		LCD_vsend_string("  2:Temp");
		//key_pressed = NOT_PRESSED;//return the variable that holds the pressed key from keypad to its initial value
		key_pressed = NOT_PRESSED;//return the variable that holds the pressed key from keypad to its initial value
		while (key_pressed == NOT_PRESSED)//repeat till the user press any key
		{
			
			key_pressed = keypad_u8check_press();//if the user pressed any button in keypad save the value in key_pressed
		}
		

		switch (key_pressed)
		{
		case '1' :
		
		LCD_vsend_cmd(CLR_SCREEN);
		LCD_vsend_cmd(DISPLAY_ON_CURSOR_ON);
		
		LCD_vsend_string("1:ON");
		LCD_movecursor(2,1);
		LCD_vsend_string("2:OFF");
		
		key_pressed = NOT_PRESSED;
		while (key_pressed == NOT_PRESSED)//repeat till the user press any key
		{
			key_pressed = keypad_u8check_press();//if the user pressed any button in keypad save the value in key_pressed
		}
		
		switch(key_pressed){
		case '1':
		DIO_write('B',3,1);
			break;
		case '2':
		DIO_write('B',3,0);
			break;
			default:
			break;
		}
		break;
		case '2' :
		LCD_vsend_cmd(CLR_SCREEN);
		LCD_vsend_cmd(DISPLAY_ON_CURSOR_ON);
		LCD_vsend_string("Temp=");
		while (test==0)
		{
			test=(ADC_Read(CH_0)*0.25);
		}
		
		LCD_vsend_char((test/10)+48);
		LCD_vsend_char((test%10)+48);
		
		
		LCD_vsend_char('C');
		break;
		
		default:
		break;}
		//LCD_vsend_char(key_pressed);//print the entered character
		// to display (Password sign *)
		//_delay_ms(100);//Halt the system for the given time in (ms)
		//LCD_movecursor(2,1);
		//LCD_vsend_char((ADC_Read(CH_0))+48);
		
		//////////////////////////ADC Test/////////////////////////////////

		if (test>=25)
		{
			DIO_write('B',4,1);
		}
		else
		{
			DIO_write('B',4,0);
		}
		
	_delay_ms(5000);
		
	

	}// end of the main while(1)
}//end of main function

/*
ISR(TIMER0_OVF_vect)
{

}
*/
/*
ISR(INT2_vect){
	//Toggle PA7
	TOG_BIT(PORTA,7);
}*/