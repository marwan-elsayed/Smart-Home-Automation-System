/******************************************************************************
 * Module     : LED
 * File Name  : led.c
 * Description: Source file for the LED driver
 * Author	  : Marwan Elsayed
 * DATE		  : 8-10-2024
 ********************************************************************************/

#include "led.h"
#include "gpio.h"

void LEDS_init(void) {
	/* Setup pins direction as output pins for all LEDs */
	GPIO_setupPinDirection(RED_LED_PORT_ID, RED_LED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, PIN_OUTPUT);

	/* Turn off all LEDS */
	LED_off(RED_LED);
	LED_off(GREEN_LED);
	LED_off(BLUE_LED);
	/*
	 #if(LEDS_CONNECTION == POSITIVE_LOGIC)
	 turn off all LEDS positive logic
	 GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_LOW);
	 GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_LOW);
	 GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_LOW);

	 #elif(LEDS_CONNECTION == NEGATIVE_LOGIC)
	 turn off all LEDS negative logic
	 GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_HIGH);
	 GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_HIGH);
	 GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_HIGH);
	 #endif
	 */

}

void LED_on(LED_ID id) {
#if(LEDS_CONNECTION == POSITIVE_LOGIC)
	switch (id) {
	case RED_LED:
		GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_HIGH);
		break;

	case GREEN_LED:
		GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_HIGH);
		break;

	case BLUE_LED:
		GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_HIGH);
		break;
	}

#elif(LEDS_CONNECTION == NEGATIVE_LOGIC)
	switch(id)
	{
	case RED_LED:
		GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_LOW);
		break;

	case GREEN_LED:
		GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_LOW);
		break;

	case BLUE_LED:
		GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_LOW);
		break;
	}

#endif
}

void LED_off(LED_ID id) {
#if(LEDS_CONNECTION == POSITIVE_LOGIC)
	switch (id) {
	case RED_LED:
		GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_LOW);
		break;

	case GREEN_LED:
		GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_LOW);
		break;

	case BLUE_LED:
		GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_LOW);
		break;
	}

#elif(LEDS_CONNECTION == NEGATIVE_LOGIC)
	switch(id)
	{
	case RED_LED:
		GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_HIGH);
		break;

	case GREEN_LED:
		GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_HIGH);
		break;

	case BLUE_LED:
		GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_HIGH);
		break;
	}

#endif
}
