/*
 * LED_UI.c
 *
 *  Created on: 13 Dec 2021
 *  Author: Euan Denton
 *  Description: This file has been prodcued to hold the UI outputs for
 *  the LEDs available.
 */

// HAL Includes
#include "stm32f2xx_hal.h"

// Driver include
#include "LED_UI_F207ZGT6.h"

void LED_GPIO_SETUP() {
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB, LD1_Pin|LD3_Pin|LD2_Pin, GPIO_PIN_RESET);
}

void LED_Flash(GPIO_TypeDef* Port, uint16_t Pin) {
	for(int i=2; i>0; i--){
		HAL_GPIO_TogglePin(Port, Pin);
		HAL_Delay(250);
	}
}

void Red_LED_Flash() {
	LED_Flash(LD3_GPIO_Port, LD3_Pin);
}

void Blue_LED_Flash() {
	LED_Flash(LD2_GPIO_Port, LD2_Pin);
}

void Green_LED_Flash() {
	LED_Flash(LD1_GPIO_Port, LD1_Pin);
}

void LED_Standby() {
	//Green
	HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
	HAL_Delay(250);

	//Blue
	HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
	HAL_Delay(250);

	//Red
	HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
	HAL_Delay(250);

	return;
}

/********** End Of File LED_UI.c **********/
