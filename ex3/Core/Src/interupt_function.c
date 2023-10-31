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

const int MAX_LED = 4;
int index_led = 0;
int led_buffer [4] = {1 , 2 , 3 , 4};

void update7SEG ( int index ) {
	 index = index % MAX_LED;
	 switch ( index ) {
	 case 0:
		 // Display the first 7 SEG with led_buffer [0]
		 HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
		 HAL_GPIO_TogglePin(EN0_GPIO_Port, EN0_Pin);
		 display7SEG1(0);
		 break ;
	 case 1:
		 // Display the second 7 SEG with led_buffer [1]
		 HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		 HAL_GPIO_TogglePin(EN1_GPIO_Port, EN1_Pin);
		 display7SEG1(1);
		 break ;
	 case 2:
		 // Display the third 7 SEG with led_buffer [2]
		 HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		 HAL_GPIO_TogglePin(EN2_GPIO_Port, EN2_Pin);
		 display7SEG1(2);
		 break ;
	 case 3:
	 // Display the forth 7 SEG with led_buffer [3]
		 HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		 HAL_GPIO_TogglePin(EN3_GPIO_Port, EN3_Pin);
		 display7SEG1(3);
		 break ;
	 default :
		 break ;
	 }
 }
static int count = 0;
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim ) {
	if(++count == 50) {
		update7SEG(index_led++);
		count = 0;
	}
}
