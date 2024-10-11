/******************************************************************************
 * Module     : BUZZER
 * File Name  : buzzer.h
 * Description: Header file for the BUZZER driver
 * Author	  : Marwan Elsayed
 * DATE		  : 8-10-2024
 ********************************************************************************/

#ifndef BUZZER_H_
#define BUZZER_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define BUZZER_PORT_ID			PORTD_ID
#define BUZZER_PIN_ID			PIN3_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Initializes the buzzer pin direction and turn off the buzzer.
 */
void BUZZER_init(void);

/*
 * Description:
 * Activates the buzzer.
 */
void BUZZER_on(void);

/*
 * Description:
 * Deactivates the buzzer.
 */
void BUZZER_off(void);


#endif /* BUZZER_H_ */
