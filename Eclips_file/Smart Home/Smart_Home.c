/*
 * Smart_Home.c
 *
 *  Created on: Oct 8, 2024
 *      Author: Marwan Elsayed
 */

#include "buzzer.h"
#include "flame_sensor.h"
#include "dc_motor.h"
#include "led.h"
#include "ldr_sensor.h"
#include "lm35_sensor.h"
#include "lcd.h"

#include <util/delay.h>

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void showData(uint8 lightIntensity, uint8 temp_value);
void lightContorl(uint8 lightIntensity);
void fanSpeedControl(uint8 temp_value);
void fireDetection(void);

/*******************************************************************************
 *                          Main Function                                      *
 *******************************************************************************/
int main() {
	uint8 lightIntensity = 0;
	uint8 temp_value = 0;
	ADC_init();
	LEDS_init();
	BUZZER_init();
	FlameSensor_init();
	DcMotor_Init();
	LCD_init();

	while (1) {
		temp_value = LM35_getTemperature();
		lightIntensity = LDR_getLightIntensity();
		lightContorl(lightIntensity);
		fanSpeedControl(temp_value);
		fireDetection();

		/* The data of the system is displayed only if the flame sensor is not detecting any flame*/
		if (FlameSensor_getValue() == LOGIC_LOW) {
			showData(lightIntensity, temp_value);
		}

	}
}

/*******************************************************************************
 *                      Functions Definition                                   *
 *******************************************************************************/

/*
 * Description:
 * Function to display real-time data of the system on the LCD
 *
 * First Row: Displays "FAN is ON" or "FAN is OFF" based on the fan's state.
 * Second Row: Displays "Temp= xxC LDR= xxx%" showing temperature and light
 * intensity.
 *
 */
void showData(uint8 lightIntensity, uint8 temp_value) {
	if (temp_value >= 25) {
		LCD_displayStringRowColumn(LCD_FIRST_ROW, 0, "   FAN IS ON    ");
	} else {
		LCD_displayStringRowColumn(LCD_FIRST_ROW, 0, "   FAN IS OFF   ");
	}

	LCD_displayStringRowColumn(LCD_SECOND_ROW, 0, "Temp=");
	if (temp_value >= 100) {
		LCD_moveCursor(LCD_SECOND_ROW, 5);
		LCD_intgerToString(temp_value);
	} else {
		LCD_moveCursor(LCD_SECOND_ROW, 5);
		LCD_intgerToString(temp_value);
		LCD_displayCharacter(' ');
	}

	LCD_displayStringRowColumn(1, 8, "LDR=");
	if (lightIntensity >= 100) {
		LCD_moveCursor(LCD_SECOND_ROW, 12);
		LCD_intgerToString(lightIntensity);
		LCD_displayCharacter('%');
	} else {
		LCD_moveCursor(LCD_SECOND_ROW, 12);
		LCD_intgerToString(lightIntensity);
		LCD_displayCharacter(' ');
		LCD_displayCharacter('%');

	}
}

/*
 * Description:
 * Function to control the LEDs based on the light intensity provided by the LDR sensor
 *
 * Intensity < 15%: All 3 LEDs (Red, Green, and Blue) turn ON.
 * Intensity 16–50%: Red and Green LEDs turn ON.
 * Intensity 51–70%: Only the Red LED turns ON.
 * Intensity > 70%: All LEDs are turned OFF.
 *
 */
void lightContorl(uint8 lightIntensity) {
	if (lightIntensity <= 15) {
		LED_on(RED_LED);
		LED_on(GREEN_LED);
		LED_on(BLUE_LED);
	}

	else if (lightIntensity <= 50) {
		LED_on(RED_LED);
		LED_on(GREEN_LED);
		LED_off(BLUE_LED);
	}

	else if (lightIntensity <= 70) {
		LED_on(RED_LED);
		LED_off(GREEN_LED);
		LED_off(BLUE_LED);
	}

	else if (lightIntensity > 70)

	{
		LED_off(RED_LED);
		LED_off(GREEN_LED);
		LED_off(BLUE_LED);
	}
}

/*
 * Description:
 * Function to adjust fan speed based on room temperature.
 *
 * Temperature ≥ 40°C: Fan ON at 100% speed.
 * Temperature ≥ 35°C and < 40°C: Fan ON at 75% speed.
 * Temperature ≥ 30°C and < 35°C: Fan ON at 50% speed.
 * Temperature ≥ 25°C and < 30°C: Fan ON at 25% speed.
 * Temperature < 25°C: Fan OFF
 *
 */
void fanSpeedControl(uint8 temp_value) {
	if (temp_value >= 40) {
		DcMotor_Rotate(CLOCKWISE, 100);
		_delay_ms(100);
	}

	else if ((temp_value >= 35) && (temp_value < 40)) {
		DcMotor_Rotate(CLOCKWISE, 75);
		_delay_ms(100);
	}

	else if ((temp_value >= 30) && (temp_value < 35)) {
		DcMotor_Rotate(CLOCKWISE, 50);
		_delay_ms(100);
	}

	else if ((temp_value >= 25) && (temp_value < 30)) {
		DcMotor_Rotate(CLOCKWISE, 25);
		_delay_ms(100);
	}

	else if (temp_value < 20) {
		DcMotor_Rotate(STOP, 0);
	}
}

/*
 * Description:
 * Function to raise alarm and display message on the LCD if fire is detected
 */
void fireDetection(void) {
	if (FlameSensor_getValue() == LOGIC_HIGH) {
		BUZZER_on();
		LCD_displayStringRowColumn(LCD_FIRST_ROW, 0, "Critical alert!!");
		LCD_displayStringRowColumn(LCD_SECOND_ROW, 0, "                ");

	}

	else {
		BUZZER_off();
	}
}
