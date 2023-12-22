

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#define NOT_PRESSED 0XFF
#include "../../MCAL/DIO/DIO_Interface.h"

#define KEYPAD_PORT        'D'
#define KEYPAD_FIRST_PIN   0
#define KEYPAD_SECOND_PIN  1
#define KEYPAD_THIRD_PIN   2
#define KEYPAD_FOURTH_PIN  3
#define KEYPAD_FIFTH_PIN   4
#define KEYPAD_SIXTH_PIN   5
#define KEYPAD_SEVENTH_PIN 6
#define KEYPAD_EIGHTH_PIN  7
void Keypad_vInit(void);
u8 keypad_u8check_press(void);




#endif /* KEYPAD_H_ */