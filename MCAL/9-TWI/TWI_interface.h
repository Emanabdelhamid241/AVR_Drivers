/******************  name : Eman Abd Elhamed  ********************/
/******************  Date :   8 Septamber 2023   ********************/
/******************   SW  :       TWI(I2C)       ********************/
/******************  version :     1.0       ********************/
#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H

ES_t  TWI_enum_Master_INIT(void);

ES_t  TWI_enum_Slave_INIT(u8 Copy_u8_Address);

ES_t  TWI_enum_Send_Start_Condition(void);

ES_t  TWI_enum_Send_ReStart_Condition(void);

ES_t  TWI_enum_Send_Stop_Condition(void);

ES_t  TWI_enum_Send_Slave_Address_With_Write(u8 Copy_u8_Slave_Address);

ES_t  TWI_enum_Send_Slave_Address_With_Read(u8 Copy_u8_Slave_Address);

ES_t  TWI_enum_Send_Data_Byte(u8 Copy_u8_Date_Byte);

ES_t  TWI_enum_Read_Data_Byte(u8 * Copy_pu8_Returned_Date_Byte);

#endif
