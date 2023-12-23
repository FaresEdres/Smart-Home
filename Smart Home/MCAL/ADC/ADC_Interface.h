

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define VREF   VREF_256V
#define SCALER ADC_SCALER_128

typedef enum {
	VREF_AREF,
	VREF_AVCC,
	VREF_256V
	}ADC_VOLTREF_type;

typedef enum {
	ADC_SCALER_2=1,
	ADC_SCALER_4,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128
	}ADC_Prescaler_type;

typedef enum {
	CH_0=0,
	CH_1,
	CH_2,
    CH_3,
    CH_4,
    CH_5,
	CH_6,
	CH_7
	}ADC_Channel_type;



void ADC_init(void);
u16 ADC_Read(ADC_Channel_type ch);
u16 ADC_VoltRead(ADC_Channel_type CH);

#endif /* ADC_INTERFACE_H_ */