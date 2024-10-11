/******************************************************************************
 * Module     : DC Motor
 * File Name  : dc_motor.c
 * Description: Source file for the Motor driver
 * Author	  : Marwan Elsayed
 * DATE		  : 8-10-2024
 ********************************************************************************/

#include "dc_motor.h"
#include "gpio.h"
#include "pwm.h"

void DcMotor_Init(void) {

	GPIO_setupPinDirection(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID,
			PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID,
			PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_EN1_PORT_ID, DC_MOTOR_EN1_PIN_ID,
			PIN_OUTPUT);
	DcMotor_Rotate(STOP,0);
}

void DcMotor_Rotate(DcMotor_State state, uint8 speed) {
	uint8 temp;
	if (speed >= 0 && speed <= 100) {
		temp = (uint8) ((uint16) (speed * 255) / 100);
		PWM_Timer0_Start(temp);

	} else {
	}

	switch (state) {
	case STOP:
		GPIO_writePin(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_LOW);
		break;
	case CLOCKWISE:
		GPIO_writePin(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_LOW);
		break;
	case ANTI_CLOCKWISE:
		GPIO_writePin(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_HIGH);
		break;
	}

}
