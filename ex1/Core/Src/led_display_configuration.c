#include "main.h"
#include "led_display_configuration.h"

#define NUMBER_OF_DECIMAL_DIGITS			10

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
