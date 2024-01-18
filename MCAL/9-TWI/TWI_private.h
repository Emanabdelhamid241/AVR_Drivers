/******************  name : Eman Abd Elhamed  ********************/
/******************  Date :   8 Septamber 2023   ********************/
/******************   SW  :       TWI(I2C)       ********************/
/******************  version :     1.0       ********************/
#ifndef TWI_PRIVATE_H
#define TWI_PRIVATE_H

/*prescaler macros*/
#define TWI_prescaler_1      0
#define TWI_prescaler_4      1
#define TWI_prescaler_16     2
#define TWI_prescaler_64     3
/*register*/
#define TWI_u8_TWDR_REG      *((volatile u8*)0x23)
#define TWI_u8_TWAR_REG      *((volatile u8*)0x22)
#define TWI_u8_TWSR_REG      *((volatile u8*)0x21)
#define TWI_u8_TWBR_REG      *((volatile u8*)0x20)
#define TWI_u8_TWCR_REG      *((volatile u8*)0x56)

/* TWSR */
#define TWI_u8_TWPS1_BIT1   1
#define TWI_u8_TWPS0_BIT0   0
/* TWCR */
#define TWI_u8_TWEN_BIT2    2
#define TWI_u8_TWSTO_BIT4   4
#define TWI_u8_TWSTA_BIT5   5
#define TWI_u8_TWEA_BIT6    6
#define TWI_u8_TWINT_BIT7   7
/*TWDR*/
#define TWI_u8_TWD0_BIT0 0
//#define TWI_u8_TWD1_BIT1 1
//freqancy mode
#define TWI_u8_freq_Value_8Mhz   1
#define TWI_u8_freq_Value_16Mhz  2

//set value of feqancy 200Khz
#define TWI_u8_TWBR_Value_8Mhz    12
#define TWI_u8_TWBR_Value_16Mhz   32


/*transmitted*/
#define TWI_u8_start_condation                         0x08
//#define TWI_u8_repeated_start_condation                0x10
#define TWI_u8_ACK_write_condation                  0x18
#define TWI_u8_ACK_reed_condation                  0x40
#define TWI_u8_ACK_Master_send_condation                  0x28
#define TWI_u8_ACK_Master_reed_condation   0x50
#endif
