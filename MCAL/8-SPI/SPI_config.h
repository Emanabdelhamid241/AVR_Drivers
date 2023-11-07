/******************  name : Eman Abd Elhamed  ********************/
/******************  Date :   10 september 2023   ********************/
/******************   SW  :       SPI       ********************/
/******************  version :     1.0       ********************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#include "../1-DIO/DIO_interface.h"
/*option
 * SPI_u8_MASTER_MODE
 * or SPI_u8_SALVE_MODE
 * */

#define SPI_u8_MODE       SPI_u8_SLAVE_MODE
/*option
 * SPI_u8_DATA_MSB
 * SPI_u8_DATA_LSB
 * */
#define SPI_u8_DATA_Order   SPI_u8_DATA_MSB
/*option
 * SPI_u8_Rising_Falling
 * SPI_u8_Falling_Rising
 *  */
#define SPI_u8_CLK_Polarity  SPI_u8_Falling_Rising

/*option
 * SPI_u8_Sample_Setup
 * SPI_u8_Setup_Sample
 *  */
#define SPI_u8_CLK_Phase  SPI_u8_Setup_Sample


/*Options
 * SPI_u8_CLK_fosc_4
 * SPI_u8_CLK_fosc_16
 * SPI_u8_CLK_fosc_64
 * SPI_u8_CLK_fosc_128
 * SPI_u8_CLK_fosc_2
 * SPI_u8_CLK_fosc_8
 * SPI_u8_CLK_fosc_10
 * SPI_u8_CLK_fosc_64_DOUBLE_SPEED

                                */
#define SPI_u8_CLK     SPI_u8_CLK_fosc_64
#endif
