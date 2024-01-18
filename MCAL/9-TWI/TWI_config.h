/******************  name : Eman Abd Elhamed  ********************/
/******************  Date :   8 Septamber 2023   ********************/
/******************   SW  :       TWI(I2C)       ********************/
/******************  version :     1.0       ********************/
#ifndef TWI_CONFIG_H
#define TWI_CONFIG_H

/*F_CPU freq*/
#define F_CPU 8000000UL   //8Mhz
/*freqancy*/
#define I2C_CLOCK_FREQ   100000UL //100khz
/*prescaler macros
 * optinos
 * 1- TWI_prescaler_1
 * 2- TWI_prescaler_4
 * 3- TWI_prescaler_16
 * 4- TWI_prescaler_64  */

#define TWI_prescaler_mode TWI_prescaler_16


#endif
