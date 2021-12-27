/*
 * I2C_Base.c
 *
 *  Created on: 15 Dec 2021
 *  Author: Euan Denton
 *
 *  Description: Used as a base for the I2C communications.
 *  Each peripheral chip using I2C will use this file for
 *  it's basic communications.
 */

#include "main.h" // The include for stm32f2xx_hal.h is part of main.h

#include "MCP9808_Temp_Driver.h" // Inlcude for the temp chip/ might not be needed

I2C_HandleTypeDef* i2cHandler;

void I2C_Handler_Set(I2C_HandleTypeDef HandlerSent) {
    i2cHandler = &HandlerSent;
}

//#IF I2C_BLOCKING

/*
 * Setting up I2C to work in blocking
 * will set up a non blocking version as well
 * currenlty only used for the temp sensor
 * but will also be tested with the Accel.
 */

int I2C_Chip_Check(int Address, uint8_t* Id_Register, int Size, int Timeout) {

	uint8_t* Chip_Return = 0;

    //HAL_StatusTypeDef HAL_I2C_Master_Transmit(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout)

    if (HAL_I2C_Master_Transmit(i2cHandler, Address, Id_Register, Size, Timeout) != HAL_OK) {
    	return ERROR_U;
    }

    // HAL_StatusTypeDef HAL_I2C_Master_Receive(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout)

    if (HAL_I2C_Master_Receive(i2cHandler, Address, Chip_Return, Size, Timeout) != HAL_OK) {
    	return ERROR_U;
    }

    //Master transmit the chip ID register address 

    //Master recive the return from the chip 

	// Request the chip ID

	// Check that the ID returned matches the ID passed

	return ERROR_U;
}


uint8_t I2C_Read_8Bit(int Address, uint8_t* Id_Register, int Size, int Timeout){

	uint8_t Chip_Return = ERROR_U;

	uint8_t* Chip_Data = 0;

    if (HAL_I2C_Master_Transmit(i2cHandler, Address, Id_Register, Size, Timeout) != HAL_OK) {
    	return Chip_Return;
    }

    if (HAL_I2C_Master_Receive(i2cHandler, Address, Chip_Data, Size, Timeout) != HAL_OK) {
    	return Chip_Return;
    }

    Chip_Return = *Chip_Data;

	return Chip_Return;
}

//#ENDIF


/********** End Of File I2C_Base.c **********/
