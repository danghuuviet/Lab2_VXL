/*
 * function_configuration.h
 *
 *  Created on: Oct 2, 2021
 *      Author: ADMIN
 */

#ifndef INC_FUNCTION_CONFIGURATION_H_
#define INC_FUNCTION_CONFIGURATION_H_
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim );
void update7SEG ( int index );
void display7SEG1(int num);

#endif /* INC_FUNCTION_CONFIGURATION_H_ */
