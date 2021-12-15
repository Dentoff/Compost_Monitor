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

#include "stm32f2xx_hal.h"
#include "MCP9808_Temp_Driver.h"

I2C_HandleTypeDef i2cHandler;

void I2C_Handler_Set(I2C_HandleTypeDef HandlerSent) {
    i2cHandler = HandlerSent;
}

/*
 * Currenlty works in blocking mode as part of the 
 * The below is used to check that the peripheral is active
 * and communicating correctly.
 * 
 * TO DO
 */
void I2C_Chip_Check(int Address, int Id_Register, int Real_ID, int Size, int Timeout) {

    //HAL_StatusTypeDef HAL_I2C_Master_Transmit(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout)

    HAL_I2C_Master_Transmit(&i2cHandler, Address, &Id_Register, Size, Timeout);

    // HAL_StatusTypeDef HAL_I2C_Master_Receive(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout)

    // HAL_I2C_Master_Receive(&i2cHandler, Address, );

    //Master transmit the chip ID register address 

    //Master recive the return from the chip 

	// Request the chip ID

	// Check that the ID returned matches the ID passed

	//return result.
}



/********** End Of File I2C_Base.c **********/
