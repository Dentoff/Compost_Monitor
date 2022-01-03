/*
 * I2C_Base.h
 *
 *  Created on: 15 Dec 2021
 *  Author: Euan Denton
 *
 *  Description:
 */

#ifndef INC_I2C_BASE_H_
#define INC_I2C_BASE_H_

#include "main.h" // The include for stm32f2xx_hal.h is part of main.h
#include "MCP9808_Temp_Driver.h" // Inlcude for the temp chip/ might not be needed

void I2C_Handler_Set( HandlerSent);

uint8_t I2C_Read_8Bit(int Address, uint8_t* Id_Register, int Size, int Timeout);

uint16_t I2C_Read_16Bit(uint8_t Address, uint8_t Register_Address, int Timeout);


#endif /* INC_I2C_BASE_H_ */

/********** End Of File I2C_Base.h **********/
