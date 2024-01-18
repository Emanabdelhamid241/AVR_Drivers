/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   14 November 2023    ********************/
/******************   SW :         EEPROM       ********************/
/******************  version :     1.0       ********************/
//from libraries layer
#include"../../libraries/types.h"
#include"../../libraries/Error_State.h"
#include"../../libraries/math.h"

//MCAL layer
#include"../../MCAL/1-DIO/DIO_interface.h"
#include"../../MCAL/9-TWI/TWI_interface.h"

//HAL layer
#include "EEPROM_config.h"
#include "EEPROM_private.h"

#include<util/delay.h>



ES_t EEPROM_enum_Write_Data_Byte(u16 Copy_u16_Byte_Address,u8 Copy_u8_Data_Byte)
{
	ES_t Local_enu_Erorr_State=ES_OK ;
	ES_t Local_TWI_enu_Erorr_State=ES_OK;
	/*1-start condition*/
	Local_TWI_enu_Erorr_State=TWI_enum_Send_Start_Condition();
	Local_enu_Erorr_State=Private_enu_Chack_Erorr_State(Local_TWI_enu_Erorr_State );

	/*2-send slave address*/
	Local_TWI_enu_Erorr_State=TWI_enum_Send_Slave_Address_With_Write((EEPROM_Fixed_Address) | (EEPROM_u8_A2_Address<<2) | (Copy_u16_Byte_Address >>8)  );
	Local_enu_Erorr_State=Private_enu_Chack_Erorr_State(Local_TWI_enu_Erorr_State );
	/*3-send the rest of the byte address */
	Local_TWI_enu_Erorr_State=TWI_enum_Send_Data_Byte((u8)Copy_u16_Byte_Address);
	Local_enu_Erorr_State=Private_enu_Chack_Erorr_State(Local_TWI_enu_Erorr_State );
    /*4- send the data*/
	Local_TWI_enu_Erorr_State=TWI_enum_Send_Data_Byte(Copy_u8_Data_Byte);
	Local_enu_Erorr_State = Private_enu_Chack_Erorr_State(Local_TWI_enu_Erorr_State );

	/*5-send stop address*/
	TWI_enum_Send_Stop_Condition();
	/*delay*/
	_delay_ms(10);
return Local_enu_Erorr_State;
}
ES_t EEPROM_enum_Reed_Data_Byte(u16 Copy_u16_Byte_Address,u8 *copy_pu8_Returned_Data)
{
	ES_t Local_enu_Erorr_State=ES_OK ;
		ES_t Local_TWI_enu_Erorr_State=ES_OK;
/*check pointer*/
		if(copy_pu8_Returned_Data!=NULL)
		{
			/*1-start condation*/
				Local_TWI_enu_Erorr_State=TWI_enum_Send_Start_Condition();
				Local_enu_Erorr_State=Private_enu_Chack_Erorr_State(Local_TWI_enu_Erorr_State );
		    /*2-send slave address*/
				Local_TWI_enu_Erorr_State=TWI_enum_Send_Slave_Address_With_Write((EEPROM_Fixed_Address) | (EEPROM_u8_A2_Address<<2) | (Copy_u16_Byte_Address >>8)  );
					Local_enu_Erorr_State=Private_enu_Chack_Erorr_State(Local_TWI_enu_Erorr_State );
		   /*3-send the rest of the byte address */
						Local_TWI_enu_Erorr_State=TWI_enum_Send_Data_Byte((u8)Copy_u16_Byte_Address);
						Local_enu_Erorr_State=Private_enu_Chack_Erorr_State(Local_TWI_enu_Erorr_State );
          /*4-send restert codition*/
						Local_TWI_enu_Erorr_State=TWI_enum_Send_ReStart_Condition();
						Local_enu_Erorr_State=Private_enu_Chack_Erorr_State(Local_TWI_enu_Erorr_State );
		/*2-send slave address*/
						Local_TWI_enu_Erorr_State=TWI_enum_Send_Slave_Address_With_Read((EEPROM_Fixed_Address) | (EEPROM_u8_A2_Address<<2) | (Copy_u16_Byte_Address >>8)  );
							Local_enu_Erorr_State=Private_enu_Chack_Erorr_State(Local_TWI_enu_Erorr_State );
	  /*6-read data recieved from EEPROM*/
							Local_TWI_enu_Erorr_State=TWI_enum_Read_Data_Byte(copy_pu8_Returned_Data);
							Local_enu_Erorr_State=Private_enu_Chack_Erorr_State(Local_TWI_enu_Erorr_State );
			/*5-send stop address*/
				TWI_enum_Send_Stop_Condition();
				/*delay*/
				_delay_ms(10);


		}
		else{
			Local_enu_Erorr_State=ES_NOK;
		}

	return Local_enu_Erorr_State;

}

static ES_t Private_enu_Chack_Erorr_State(ES_t Copy_enu_Error_State )
{
	ES_t Local_enu_Erorr_State=ES_OK ;
  			if(Copy_enu_Error_State !=ES_OK){
			Local_enu_Erorr_State= ES_NOK ;
	}

	return Local_enu_Erorr_State;

}
