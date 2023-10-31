/*
 * interupt_function.c
 *
 *  Created on: Oct 2, 2021
 *      Author: MSI-
 */
#include "main.h"
#include "interupt_function.h"
#define NUMBER_OF_DECIMAL_DIGITS 		10

static uint8_t sevenSegmentLEDConversion[NUMBER_OF_DECIMAL_DIGITS] = {0x01, 0x4f, 0x12, 0x06, 0x4C, 0x24, 0x20, 0x0f, 0x00, 0x04};

void display7SEG1(int num) {
	uint8_t the_number = sevenSegmentLEDConversion[num];
	if(the_number & 0x01) {
		HAL_GPIO_WritePin(LED1_G_GPIO_Port, LED1_G_Pin, 1);
	} else
		HAL_GPIO_WritePin(LED1_G_GPIO_Port, LED1_G_Pin, 0);

	if(the_number & 0x02) {
			HAL_GPIO_WritePin(LED1_F_GPIO_Port, LED1_F_Pin, 1);
		} else
			HAL_GPIO_WritePin(LED1_F_GPIO_Port, LED1_F_Pin, 0);

	if(the_number & 0x04) {
			HAL_GPIO_WritePin(LED1_E_GPIO_Port, LED1_E_Pin, 1);
		} else
			HAL_GPIO_WritePin(LED1_E_GPIO_Port, LED1_E_Pin, 0);

	if(the_number & 0x08) {
			HAL_GPIO_WritePin(LED1_D_GPIO_Port, LED1_D_Pin, 1);
		} else
			HAL_GPIO_WritePin(LED1_D_GPIO_Port, LED1_D_Pin, 0);

	if(the_number & 0x10) {
			HAL_GPIO_WritePin(LED1_C_GPIO_Port, LED1_C_Pin, 1);
		} else
			HAL_GPIO_WritePin(LED1_C_GPIO_Port, LED1_C_Pin, 0);

	if(the_number & 0x20) {
			HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, 1);
		} else
			HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, 0);

	if(the_number & 0x40) {
			HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, 1);
		} else
			HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, 0);
}

static int count , countled , typeofled = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if(++count == 100) {
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		count = 0;
	}

	if(++countled == 50) {
		if(typeofled == 0) {
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
			HAL_GPIO_TogglePin(EN0_GPIO_Port, EN0_Pin);
			display7SEG1(1);
		}
		if(typeofled == 1) {
					HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
					HAL_GPIO_TogglePin(EN1_GPIO_Port, EN1_Pin);
					display7SEG1(2);
				}
		if(typeofled == 2) {
					HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
					HAL_GPIO_TogglePin(EN2_GPIO_Port, EN2_Pin);
					display7SEG1(3);
				}
		if(typeofled == 3) {
					HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
					HAL_GPIO_TogglePin(EN3_GPIO_Port, EN3_Pin);
					display7SEG1(0);
				}
	countled = 0;
	if(typeofled == 3)
			typeofled = 0;
		else
			typeofled++;
	}
}

