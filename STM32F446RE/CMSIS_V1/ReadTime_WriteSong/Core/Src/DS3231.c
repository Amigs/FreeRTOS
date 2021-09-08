/*
 * DS3231.c
 *
 *  Created on: Sep 8, 2021
 *      Author: Miguel Murillo
 */

#include "DS3231.h"

void pushTime (struct TIME *time_ptr){
	uint8_t set_time[7];
	set_time[0] = decToBcd(time_ptr->seconds);
	set_time[1] = decToBcd(time_ptr->minutes);
	set_time[2] = decToBcd(time_ptr->hour);
	set_time[3] = decToBcd(time_ptr->day);
	set_time[4] = decToBcd(time_ptr->numWeek);
	set_time[5] = decToBcd(time_ptr->numMonth);
	set_time[6] = decToBcd(time_ptr->year);
	HAL_I2C_Mem_Write(&hi2c1, DS3231_I2C_ADDR, 0x00, 1, set_time, 7, 1000);
}

void pullTime(void){
	uint8_t get_time[7];
	HAL_I2C_Mem_Read(&hi2c1, DS3231_I2C_ADDR, 0x00, 1, get_time, 7, 1000);
	pull.seconds = bcdToDec(get_time[0]);
	pull.minutes = bcdToDec(get_time[1]);
	pull.hour = bcdToDec(get_time[2]);
	pull.day = bcdToDec(get_time[3]);
	pull.numWeek = bcdToDec(get_time[4]);
	pull.numMonth = bcdToDec(get_time[5]);
	pull.year = bcdToDec(get_time[6]);
}
uint8_t decToBcd(int val){
	return (uint8_t)((val/10*16) + (val%10));
}
int bcdToDec(uint8_t val){
	return (int)((val/16*10) + (val%16));
}
