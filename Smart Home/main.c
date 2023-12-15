


#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/Ext_Int/Ext_Int_Interface.h"
#include "MCAL/GI/GI_Interface.h"

void main(void)
{
    DIO_InitPin(PINA0,OUTPUT);
    while (1) 
    {
		
		DIO_WritePin(PINA0,HIGH);
		
    }
}



