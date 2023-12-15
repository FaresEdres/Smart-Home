#include "../../../StdTypes.h"
#include "../../../MemMap.h"
#include "../../../Utils.h"
#include "../../../Routines.h"
#include "Timer0_Cfg.h"
#include "Timer0_Interface.h"

static void (*p2f_ov)  (void) = NULL_PTR;
static void (*p2f_cmp) (void) = NULL_PTR;

void Timer0_init(void)
{
	//Timer Mode
	#if Timer0_mode==Normal_mode
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
	
	#elif Timer0_mode==PWM_mode
	SET_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
	
	#elif Timer0_mode==CTC_mode
	SET_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
	
	#elif Timer0_mode==Fast_PWM_mode
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	#endif
	
	
}

void Timer0_start(void)
{
	TCCR0&= 0XF8;
	TCCR0|=Timer0_Prescaler;
	
}
void Timer0_stop(void)
{
	TCCR0&=0XF8;
}

void Timer0_set_int_value(u8 value)
{
	TCNT0 = value;
}
void Timer0_set_cmp_value(u8 value)
{
	OCR0=value;
}

void Timer0_PWM_set_cmp(u8 duty)
{
	#if Timer0_modeofcmp==Inverting
	duty= 100 - duty;
	#endif
	OCR0=(duty * resolution/100)-1;
}
void Timer0_PWM_set_cmp_PC(u8 duty)
{
	#if Timer0_modeofcmp==Inverting
	duty= 100 - duty;
	#endif
	OCR0= (duty*resolution/50)-1;
}

void Timer0_OV_InterruptEnable(void)
{
	SET_BIT(TIMSK,0);
}
void Timer0_OV_InterruptDisable(void)
{
	CLR_BIT(TIMSK,0);
}
void Timer0_OC_InterruptEnable(void)
{
	SET_BIT(TIMSK,1);
}
void Timer0_OC_InterruptDisable(void)
{
	CLR_BIT(TIMSK,1);
}

void Timer0_OV_set_callback(void (*p2f_var) (void) )
{
	if (p2f_var != NULL_PTR)
	{
		p2f_ov = p2f_var;
	}
}
void Timer0_OC_set_callback(void (*p2f_var) (void) )
{
	if (p2f_var != NULL_PTR)
	{
		p2f_cmp = p2f_var;
	}
}

ISR(Timer0_OVF_vect)
{
	p2f_ov();
}

ISR(TIMER0_COMP_vect)
{
	p2f_cmp();
}

