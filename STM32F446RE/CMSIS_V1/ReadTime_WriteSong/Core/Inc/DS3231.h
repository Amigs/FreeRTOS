/*
 * DS3231.h
 *
 *  Created on: Sep 8, 2021
 *      Author: Miguel Murillo
 */

#ifndef INC_DS3231_H_
#define INC_DS3231_H_

#include "stm32f4xx_hal.h"

// I2c address
#ifndef DS3231_I2C_ADDR
#define DS3231_I2C_ADDR        0xD0
#endif // DS3231_I2C_ADDR

struct TIME{
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hour;
	uint8_t day;
	uint8_t numWeek;
	uint8_t numMonth;
	uint8_t year;
}push,pull;

//void pushTime (uint8_t sec, uint8_t min, uint8_t hour, uint8_t dow, uint8_t dom, uint8_t month, uint8_t year);
void pushTime (struct TIME *time_ptr);
void pullTime (void);
uint8_t decToBcd(int val);
int bcdToDec(uint8_t val);

I2C_HandleTypeDef hi2c1;  //I2C Handle

#endif /* INC_DS3231_H_ */
