

#ifndef ROUTINES_H_
#define ROUTINES_H_

#define INT0_vect		__vector_1
#define INT2_vect		__vector_3
#define TIMER2_COMP_vect	__vector_4
#define TIMER2_OVF_vect		__vector_5
#define INT1_vect     __vector_6
#define TIMER1_COMPA_vect	__vector_7
#define TIMER1_COMPB_vect	__vector_8
#define TIMER1_OVF_vect		__vector_9
#define TIMER0_COMP_vect     __vector_10
#define TIMER0_OVF_vect     __vector_11
#define SPI_STC_vect	__vector_12
#define USART_RXC_vect		__vector_13
#define USART_UDRE_vect	     __vector_14
#define USART_TXC_vect		 __vector_15

#define sei() __asm__ __volatile__ ("sei" ::)
#define cli() __asm__ __volatile__ ("cli" ::)
#define reti() __asm__ __volatile__ ("reti" ::)
#define ret() __asm__ __volatile__ ("ret" ::)

#define ISR_NOBLOCK __attribute__ ((interrup))
#define ISR_NAKED __attribute__ ((naked))

#define ISR(vector, ...)            \
void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
void vector (void)

#endif /* ROUTINES_H_ */