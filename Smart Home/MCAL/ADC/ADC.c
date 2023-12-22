#include "../../StdTypes.h"
#include "../../MemMap.h"
#include "../../Utils.h"
#include "ADC_Interface.h"

void ADC_init(void)
{
	/*
 #if VREF == VREF_AREF
CLR_BIT(ADMUX,REFS0);
CLR_BIT(ADMUX,REFS1);
#elif VREF == VREF_AVCC
SET_BIT(ADMUX,REFS0);
CLR_BIT(ADMUX,REFS1);
#elif  VREF == VREF_256V
SET_BIT(ADMUX,REFS0);
SET_BIT(ADMUX,REFS1);
#else
#endif
	*/
	
	SET_BIT(ADMUX,REFS0);
    SET_BIT(ADMUX,REFS1);
	
	/*
	ADCSRA&=0xF8;
	//scaler&=0X07;
	ADCSRA|=SCALER;
	*/
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADEN);	
}
/* Choose channel - Start Conversion - Return ADC */
u16 ADC_Read(ADC_Channel_type ch)
{
	
	u16 read_val;
	/*
	ch=0x07;
	ADMUX&=(0XF8)|ch;
	*/
	SET_BIT(ADCSRA,ADSC);
	/* wait till the end of the conversion */
	while (READ_BIT(ADCSRA,ADIF)==1);
	SET_BIT(ADCSRA,ADIF);
	read_val=(ADCL);
	read_val|=(ADCH<<8);
	
	return read_val;
}
u16 ADC_VoltRead(ADC_Channel_type CH);