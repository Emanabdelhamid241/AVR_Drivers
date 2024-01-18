/******************  name : Eman Abd Elhamed  ********************/
/******************  Date :   24 november 2023   ********************/
/******************   SW  :       RTO       ********************/
/******************  version :     1.0       ********************/
#include"../../libraries/types.h"
#include"../../libraries/Error_State.h"
#include"../../libraries/math.h"

//MCAL layer
#include "RTO_config.h"
#include "RTO_private.h"

#include "../../MCAL/1-DIO/DIO_interface.h"
#include "../../MCAL/5-TIMERS/TIMERS_interface.h"


#include<util/delay.h>

/* Array of TCBs */
RTO_TCB   RTO_Astr_Tasks[RTO_u8_Max_Number_Tasks];
ES_t  RTO_enum_INIT(void)
{
	ES_t Local_enu_Erorr_State= ES_OK;
	/*set call bake function*/
	TIMERS_enum_TIMER0_CTC_SET_CALL_BACK(&RTO_enum_Scheduler);

	/*Start timer*/
	TIMERS_enum_TIMER0_INIT();

	return Local_enu_Erorr_State;
}


ES_t  RTO_enum_Create_Task(u8 Copy_u8_Perority,u16 Copy_u16_Periodicty,u16 Copy_u16_First_Delay,void(*Copy_pf)(void))
{
	ES_t Local_enu_Erorr_State= ES_OK;
    if((Copy_u8_Perority< RTO_u8_Max_Number_Tasks)&&(Copy_pf !=NULL))
    {
    	RTO_Astr_Tasks[Copy_u8_Perority].first_delay =Copy_u16_First_Delay;
    	RTO_Astr_Tasks[Copy_u8_Perority].periodicity =Copy_u16_Periodicty;
    	RTO_Astr_Tasks[Copy_u8_Perority].pf          =Copy_pf;
    	Local_enu_Erorr_State= ES_NOK;
    }
		return Local_enu_Erorr_State;
}

static ES_t  RTO_enum_Scheduler(void)
{
	ES_t Local_enu_Erorr_State= ES_OK;
u8 local_u8_counter;
/*for loop to loop on the ready tasks*/
for(local_u8_counter=0;local_u8_counter<RTO_u8_Max_Number_Tasks;local_u8_counter++)
{
	if(RTO_Astr_Tasks[local_u8_counter].first_delay==0)
	{
		/*call task*/
		RTO_Astr_Tasks[local_u8_counter].pf();
		/*update for the first delay value by the periodicity*/
		RTO_Astr_Tasks[local_u8_counter].first_delay=RTO_Astr_Tasks[local_u8_counter].periodicity-1 ;
	}
	else
	{
		RTO_Astr_Tasks[local_u8_counter].first_delay--;
	}
}
			return Local_enu_Erorr_State;

}
