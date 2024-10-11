/******************************************************************************
 * Module     : LDR Sensor
 * File Name  : ldr_sensor.h
 * Description: Header file for the LDR driver
 * Author	  : Marwan Elsayed
 * DATE		  : 8-10-2024
 ********************************************************************************/

#ifndef LDR_SENSOR_H_
#define LDR_SENSOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define LDR_SENSOR_CHANNEL_ID				0
#define LDR_SENSOR_MAX_VOLT_VALUE			2.56
#define LDR_SENSOR_MAX_LIGHT_INTENSITY		100

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Reads the LDR sensor value and returns the light intensity.
 * Function responsible for calculate the light intensity from the ADC digital value.
 */
uint8 LDR_getLightIntensity(void);

#endif /* LDR_SENSOR_H_ */
