/*
 * func.c
 *
 *  Created on: Oct 10, 2021
 *      Author: MSI-
 */


#include "main.h"
#include "func.h"

static uint8_t row[8] = {0x00, 0x3f, 0x5f, 0xd0, 0xd0, 0x5f, 0x3f, 0x1f};

void clearcol() {
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, 0);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, 0);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, 0);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, 0);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, 0);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, 0);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, 0);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, 0);
}

void updatecol(int index) {

	if(index == 7)	{
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, 0);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, 1);
	}
	else if(index == 6) {
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, 0);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, 1);
	}
	else if(index == 5) {
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, 0);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, 1);
	}
	else if(index == 4) {
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, 0);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, 1);
	}
	else if(index == 3){
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, 0);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, 1);
	}
	else if(index == 2){
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, 0);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, 1);
	}
	else if(index == 1){
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, 0);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, 1);
	}
	else if(index == 0){
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, 1);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, 0);
	}
}

void updaterow(uint8_t num) {
	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, num & 0x80);
	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, num & 0x40);
	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, num & 0x20);
	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, num & 0x10);
	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, num & 0x08);
	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, num & 0x04);
	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, num & 0x02);
	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, num & 0x01);
}

void updateLEDMatrix (int index ) {
	clearcol();
	switch(index) {
	case 7:
		updatecol(7);
		updaterow(row[0]);
		break;
	case 6:
		updatecol(6);
		updaterow(row[1]);
		break;
	case 5:
		updatecol(5);
		updaterow(row[2]);
		break;
	case 4:
		updatecol(4);
		updaterow(row[3]);
		break;
	case 3:
		updatecol(3);
		updaterow(row[4]);
		break;
	case 2:
		updatecol(2);
		updaterow(row[5]);
		break;
	case 1:
		updatecol(1);
		updaterow(row[6]);
		break;
	case 0:
		updatecol(0);
		updaterow(row[0]);
		break;
	default:
		break;
	}
}
