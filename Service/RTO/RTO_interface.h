/******************  name : Eman Abd Elhamed  ********************/
/******************  Date :   24 november 2023   ********************/
/******************   SW  :       RTO       ********************/
/******************  version :     1.0       ********************/
#ifndef RTO_INTERFACE_H
#define RTO_INTERFACE_H

ES_t  RTO_enum_INIT(void);

ES_t  RTO_enum_Create_Task(u8 Copy_u8_Perority,u16 Copy_u16_Periodicty,u16 Copy_u16_First_Delay,void(*Copy_pf)(void));

#endif
