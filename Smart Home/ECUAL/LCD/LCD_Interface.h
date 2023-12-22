


#ifndef LCD_H_
#define LCD_H_


#include "../../MCAL/DIO/DIO_Interface.h"
#include "LCD_Interface.h"
#include "../../MemMap.h"

#define CLR_SCREEN           0X01
#define DISPLAY_ON_CURSOR_ON 0X0E
#define EIGHT_BIT_MODE       0X38
#define FOUR_BIT_MODE_I      0X02
#define FOUR_BIT_MODE_II     0X28

#define SEND_COMMAND        0
#define SEND_DATA           1

#define LCD_PORT         'C'
#define LCD_FIRST_PIN    0
#define LCD_SECOND_PIN   1
#define LCD_THIRD_PIN    2
#define LCD_FOURTH_PIN   3
#define LCD_FIFTH_PIN    4 
#define LCD_SIXTH_PIN    5
#define LCD_SEVENTH_PIN  6
#define LCD_EIGHTH_PIN   7

#define LCD_CONTROL 'B'
#define LCD_EN_PIN  0
#define LCD_RS_PIN  1
#define LCD_RW_PIN  3


void LCD_vInit();
void LCD_vsend_cmd(u8 cmd);
void LCD_vsend_char(u8 data);
void LCD_vsend_string(u8 *data);
void LCD_clearscreen();
void LCD_send_falling_edge();



#endif /* LCD_H_ */