/*
 *  MCP9808_Temp_Driver.c
 *
 *  Created on: 27 Dec 2021
 *  Author: Euan Denton
 *
 *  Description: This file holds the communications and
 *  specific setup for the MCP9808 temperature sensor
 */

#include "main.h"
#include "I2C_Base.h"
#include "MCP9808_Temp_Driver.h"

void MCP9808_Chip_Check() {

	uint16_t returned;

	returned = I2C_Read_16Bit(MCP9808_ADR, MCP9808_MANUFACTURER_ID, 10);

	//Set up as a bool return
}

/********** End Of File MCP9808_Temp_Driver.c **********/
