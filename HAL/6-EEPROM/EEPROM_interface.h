/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   14 November 2023    ********************/
/******************   SW :         EEPROM       ********************/
/******************  version :     1.0       ********************/
#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

//ES_t EEPROM_enum_INIT();
ES_t EEPROM_enum_Write_Data_Byte(u16 Copy_u16_Byte_Address,u8 Copy_Data_Byte);
ES_t EEPROM_enum_Reed_Data_Byte(u16 Copy_u16_Byte_Address,u8 *copy_pu8_Returned_Data);

#endif
