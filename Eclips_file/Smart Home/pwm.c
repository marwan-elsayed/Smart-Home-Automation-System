/******************************************************************************
 * Module     : PWM
 * File Name  : pwm.c
 * Description: Source file for the PWM driver
 * Author	  : Marwan Elsayed
 * DATE		  : 8-10-2024
 ********************************************************************************/

#include "pwm.h"
#include <avr/io.h>

void PWM_Timer0_Start(uint8 duty_cycle) {

	TCNT0 = 0;

	OCR0 = duty_cycle;

	DDRB |= (1 << PB3);

	TCCR0 = (1 << WGM00) |
			(1 << WGM01) |
			(1 << COM01) |
			(1 << CS00)  |
			(1 << CS02);

}
