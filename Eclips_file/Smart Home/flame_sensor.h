/******************************************************************************
 * Module     : Flame Sensor
 * File Name  : flame_sensor.h
 * Description: Header file for the Flame Sensor driver
 * Author	  : Marwan Elsayed
 * DATE		  : 8-10-2024
 ********************************************************************************/

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_

#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define FLAME_SENSOR_PORT_ID		PORTD_ID
#define FLAME_SENSOR_PIN_ID			PIN2_ID
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Definition:
 * Initializes the flame sensor pin direction.
 */
void FlameSensor_init(void);

/*
 * Definition:
 * Reads the value from the flame sensor and returns it.
 */
uint8 FlameSensor_getValue(void);

#endif /* FLAME_SENSOR_H_ */
