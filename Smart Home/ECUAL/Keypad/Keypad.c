#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../Utils.h"
#include "../../MemMap.h"
#include "Keypad_Interface.h"

void Keypad_vInit()
{

	 /*Initialize first four bits a output*/
	DIO_vsetPINDir(KEYPAD_PORT,KEYPAD_FIRST_PIN,1);
	DIO_vsetPINDir(KEYPAD_PORT,KEYPAD_SECOND_PIN,1);
    DIO_vsetPINDir(KEYPAD_PORT,KEYPAD_THIRD_PIN,1);
	DIO_vsetPINDir(KEYPAD_PORT,KEYPAD_FOURTH_PIN,1);
	/* Initialize first four bits a input*/
	DIO_vsetPINDir(KEYPAD_PORT,KEYPAD_FIFTH_PIN,0);
	DIO_vsetPINDir(KEYPAD_PORT,KEYPAD_SIXTH_PIN,0);
	DIO_vsetPINDir(KEYPAD_PORT,KEYPAD_SEVENTH_PIN,0);
	DIO_vsetPINDir(KEYPAD_PORT,KEYPAD_EIGHTH_PIN,0);
	
    DIO_vconnectpullup(KEYPAD_PORT,KEYPAD_FIFTH_PIN,1);
    DIO_vconnectpullup(KEYPAD_PORT,KEYPAD_SIXTH_PIN,1);
    DIO_vconnectpullup(KEYPAD_PORT,KEYPAD_SEVENTH_PIN,1);
    DIO_vconnectpullup(KEYPAD_PORT,KEYPAD_EIGHTH_PIN,1);
}

u8 keypad_u8check_press(void)
{
		
	u8 arr [4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	u8 row,column,key_pressed_flag;
    u8 returnval=NOT_PRESSED;
	
	for (row=0;row<4;row++)
	{
		DIO_write(KEYPAD_PORT,KEYPAD_FIRST_PIN,1);
		DIO_write(KEYPAD_PORT,KEYPAD_SECOND_PIN,1);
		DIO_write(KEYPAD_PORT,KEYPAD_THIRD_PIN,1);
		DIO_write(KEYPAD_PORT,KEYPAD_FOURTH_PIN,1);
		
         _delay_ms(20);	
		DIO_write(KEYPAD_PORT,row,0);
		
		for(column=0;column<4;column++)
		{
			key_pressed_flag=DIO_u8read(KEYPAD_PORT,(column+4));
		
		if(key_pressed_flag==0)
		{
			 returnval=arr[row][column];
			break;
		}
		
		}
	}
	return returnval;
	}	
