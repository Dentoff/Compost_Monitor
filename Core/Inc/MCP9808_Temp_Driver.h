/*
 * MCP9808_Temp_Driver.h
 *
 *  Created on: Dec 13, 2021
 *  Author: Euan Denton
 *
 *  Description: This File is used to set up the Driver for the MCP9808
 *  Temperature sensor.
 *
 *  The register and control bits have been defined so they can be used
 *  when communicating with the chip over I2C.
 */

#ifndef INC_MCP9808_TEMP_DRIVER_H_
#define INC_MCP9808_TEMP_DRIVER_H_

/***** ADDRESS *****/
#define MCP9808_ADR 0b0011000 //Seven bit for the R/W bit within coms
/***** ADDRESS *****/

/***** REGISTERS *****/
#define MCP9808_CONFIG 0x01

#define MCP9808_TEMP_UPPER      0x02 //Temp Higher
#define MCP9808_TEMP_LOWER      0x03 //Temp Lower
#define MCP9808_TEMP_CRITICAL   0x04 //Temp Critical

#define MCP9808_AMBIENT_TEMP    0x05 //Ambient Temp

#define MCP9808_MANUFACTURER_ID 0x06 //The ID from the manufacturer should be 0x0054

#define MCP9808_DEVICE_ID       0x07 // Device ID 0x04 Rev TBD

#define MCP9808_RESOLUTION      0x08 // Resolution Registe
/***** REGISTERS *****/

/***** COMMANDS *****/

/***** CONFIGURATION *****/
#define MCP9808_CONFIG_DEFAULT_MSB  0x00
#define MCP9808_CONFIG_DEFAULT_LSB  0x00

// Temp upper and lower Limit Hysteresis bits
// MCP9808_CONFIG_DEFAULT_MSB | MCP9808_THYST
#define MCP9808_THYST_DEFAULT   0x00
#define MCP9808_THYST_LOW       0x01
#define MCP9808_THYST_MID       0x02
#define MCP9808_THYST_HIGH      0x03

// Shutdown Mode
// MCP9808_CONFIG_DEFAULT_MSB | MCP9808_SHUTDOWN_MODE
#define MCP9808_CONTINUOUS      0x00
#define MCP9808_SHUTDOWN        0x01

// Temp Critical Register Lock
// MCP9808_CONFIG_DEFAULT_LSB | MCP9808_LOCKED_STATE
#define MCP9808_TC_UNLOCKED     0x00
#define MCP9808_TC_LOCKED       0x80

// Window Lock Bit
// MCP9808_CONFIG_DEFAULT_LSB | MCP9808_LOCKED_STATE
#define MCP9808_WL_UNLOCKED     0x00
#define MCP9808_WL_LOCKED       0x40

// Interrupt Clear bit
// MCP9808_CONFIG_DEFAULT_LSB | MCP9808_CLEAR_STATE
#define MCP9808_NO_CLEAR        0x00
#define MCP9808_CLEAR           0x20

// Alert Output Status
// MCP9808_CONFIG_DEFAULT_LSB | MCP9808_ALERT_STATE
#define MCP9808_NO_ALERT        0x00
#define MCP9808_ALERT           0x10

// Alert Output Control bit
// MCP9808_CONFIG_DEFAULT_LSB | MCP9808_ALERT_OUTPUT_STATE
#define MCP9808_ALERT_DISABLED   0x00
#define MCP9808_ALERT_ENABLED    0x08

// Alert Output Temp Select
// MCP9808_CONFIG_DEFAULT_LSB | MCP9808_ALERT_OUTPUT_TEMP
#define MCP9808_ALERT_ALL_LIMITS 0x00
#define MCP9808_ALERT_CRITICAL   0x04

// Alert Polarity
// MCP9808_CONFIG_DEFAULT_LSB | MCP9808_ALERT_POLARITY
#define MCP9808_ALERT_LOW        0x00
#define MCP9808_ALERT_HIGH       0x02

// Alert Mode
// MCP9808_CONFIG_DEFAULT_LSB | MCP9808_ALERT_MODE
#define MCP9808_ALERT_COMPARATOR 0x00
#define MCP9808_ALERT_INTERRUPT  0x01
/***** CONFIGURATION *****/

/***** RESOLUTION *****/
#define MCP9808_Resolution_Default 0x03 // Highest Resolution
#define MCP9808_Resolution_High    0x02 // High Resolution
#define MCP9808_Resolution_Mid	   0x01 // Middle Resolution
#define MCP9808_Resolution_Low     0x00 // Low Resolution
/***** RESOLUTION *****/

/***** TEMPERATUER LIMITS *****/
/***** CRITICAL *****/ // 80 degrees
#define MCP9808_CRITICAL_MSB 0x05
#define MCP9808_CRITICAL_LSB 0x00
/***** CRITICAL *****/

/***** UPPER *****/ // 65 degrees
#define MCP9808_UPPER_MSB 0x04
#define MCP9808_UPPER_LSB 0x00
/***** UPPER *****/

/***** LOWER *****/ //10 degrees
#define MCP9808_LOWER_MSB 0x00
#define MCP9808_LOWER_LSB 0xA0
/***** LOWER *****/
/***** TEMPERATUER LIMITS *****/

/***** COMMANDS *****/

#endif /* INC_MCP9808_TEMP_DRIVER_H_ */

/********** End Of File MCP9808_Temp_Driver.h **********/
