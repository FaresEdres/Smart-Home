#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

typedef enum
{
	Normal_mode,
	PWM_mode,
	CTC_mode,
	Fast_PWM_mode
}Timer0_modes;

typedef enum
{
	No_Clk,
	PRS_0,
	PRS_8,
	PRS_64,
	PRS_256,
	PRS_1024,
	PRS_FallingEdge,
	PRS_RisingEdge
	}Timer0_Prescalers;

void Timer0_init(void);
void Timer0_start(void);
void Timer0_stop(void);

void Timer0_set_int_value(u8 value);
void Timer0_set_cmp_value(u8 value);

void Timer0_PWM_set_cmp(u8 duty);
void Timer0_PWM_set_cmp_PC(u8 duty);

void Timer0_OV_InterruptEnable(void);
void Timer0_OV_InterruptDisable(void);
void Timer0_OC_InterruptEnable(void);
void Timer0_OC_InterruptDisable(void);

void Timer0_OV_set_callback(void (*p2f_var) (void) );
void Timer0_OC_set_callback(void (*p2f_var) (void) );


#endif /* TIMER0_INTERFACE_H_ */