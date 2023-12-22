#include "LCD_Interface.h"
#include <util/delay.h>
#include "../../MCAL/DIO/DIO_Interface.h"
void LCD_vInit()
{
	/* Set LCD Pins as output*/
	DIO_vsetPINDir(LCD_PORT,LCD_FIRST_PIN,1);
	DIO_vsetPINDir(LCD_PORT,LCD_SECOND_PIN,1);
	DIO_vsetPINDir(LCD_PORT,LCD_THIRD_PIN,1);
	DIO_vsetPINDir(LCD_PORT,LCD_FOURTH_PIN,1);
	DIO_vsetPINDir(LCD_PORT,LCD_FIFTH_PIN,1);
	DIO_vsetPINDir(LCD_PORT,LCD_SIXTH_PIN,1);
	DIO_vsetPINDir(LCD_PORT,LCD_SEVENTH_PIN,1);
	DIO_vsetPINDir(LCD_PORT,LCD_EIGHTH_PIN,1);
	
	/* Set LCD control pins as output */
	DIO_vsetPINDir(LCD_CONTROL,LCD_EN_PIN,1);
	DIO_vsetPINDir(LCD_CONTROL,LCD_RW_PIN,1);
	DIO_vsetPINDir(LCD_CONTROL,LCD_RS_PIN,1);
	
	DIO_write(LCD_CONTROL,LCD_RW_PIN,0);
	
	LCD_vsend_cmd(EIGHT_BIT_MODE);
	LCD_vsend_cmd(CLR_SCREEN);
	LCD_vsend_cmd(DISPLAY_ON_CURSOR_ON);
	_delay_ms(10);
}
void LCD_vsend_cmd(u8 cmd)
{
	DIO_write_port(LCD_PORT,cmd);
	DIO_write(LCD_CONTROL,LCD_RS_PIN,SEND_COMMAND);
	DIO_write(LCD_CONTROL,LCD_RW_PIN,0);
	LCD_send_falling_edge();
}
void LCD_vsend_char(u8 data)
{
	DIO_write_port(LCD_PORT,data);
	DIO_write(LCD_CONTROL,LCD_RS_PIN,SEND_DATA);
	DIO_write(LCD_CONTROL,LCD_RW_PIN,0);
	LCD_send_falling_edge();
}
void LCD_vsend_string(u8 *data)
{
	while ((*data)!=NULL)
	{
		_delay_ms(20);
		LCD_vsend_char(*data);
		data++;
	}
}
void LCD_clearscreen()
{
	LCD_vsend_cmd(CLR_SCREEN);
}
void LCD_send_falling_edge()
{
	/*Sending falling edge to enable printing character on LCD*/
	DIO_write(LCD_CONTROL,LCD_EN_PIN,1);
	_delay_ms(2);
	DIO_write(LCD_CONTROL,LCD_EN_PIN,0);
	_delay_ms(2);
}
void LCD_movecursor(u8 row,u8 coloumn)
{
	u8 data ; // the command which will set the position of the cursor
	/* in case of wrong input set the cursor to the first position of the LCD*/
	if(row>2||row<1||coloumn>16||coloumn<1)
	{
		data = 0x80;
	}
	/********************************************/
	/*set the postion of cursor depend on the selected row and coloumn*/
	if(row==1)
	{
		data=0x80+coloumn-1;
	}
	else if (row==2)
	{
		data=0xc0+coloumn-1;
	}
	/**************************************/
	
	LCD_vsend_cmd(data); //set the position  of the cursor
}