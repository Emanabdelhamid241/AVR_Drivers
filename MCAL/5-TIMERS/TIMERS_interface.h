/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   7 August 2023     ********************/
/******************   SW :         TIMERS        ********************/
/******************  version :     1.0       ********************/
#include "TIMERS_config.h"
#include "TIMERS_private.h"

#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

ES_t TIMERS_enum_TIMER0_INIT(u8 copy_TIMER_mode ,Timer0_Scaler_type copy_TIMER_scaler);
ES_t TIMERS_enum_TIMER1_INIT(Timer1_Mode_type copy_TIMER1_mode,
		                     OC1A_Mode_type copy_OC1A_mode ,
		                     Timer1_Scaler_type copy_TIMER1_scaler);

ES_t TIMERS_enum_TIMER0_SET_CALL_BACK(void(*Copy_pf)(void));
ES_t TIMERS_enum_TIMER0_CTC_SET_CALL_BACK(void(*Copy_pf)(void));
ES_t TIMERS_enum_TIMER0_SET_COMPARE_MATCH_VALUE(u8 Copy_u8_OCRO_Value);

ES_t TIMERS_enum_TIMER1_SET_COMPARE_MATCH_VALUE_A(u8 Copy_u16_OCR_Value);
ES_t TIMERS_enum_TIMER1_SET_Servo_Motor_Angle(u8 Copy_u8_Servo_Motor_Angle);


#endif
