/******************************************************************************
 * Module     : Flame Sensor
 * File Name  : flame_sensor.c
 * Description: Source file for the Flame Sensor driver
 * Author	  : Marwan Elsayed
 * DATE		  : 8-10-2024
 ********************************************************************************/

#include "flame_sensor.h"
#include "gpio.h"
#include "adc.h"

void FlameSensor_init(void)
{
	GPIO_setupPinDirection(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID, PIN_INPUT);
}

uint8 FlameSensor_getValue(void)
{
	uint8 temp = 0; /* Variable to store the flame sensor value */

	temp = GPIO_readPin(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID);	/* Read the flame sensor value */

	return temp;
}
