/******************  name : Eman Abd Elhamed  ********************/
/******************  Date :   8 Septamber 2023   ********************/
/******************   SW  :       TWI(I2C)       ********************/
/******************  version :     1.0       ********************/
#include"../../libraries/types.h"
#include"../../libraries/Error_State.h"
#include"../../libraries/math.h"

//MCAL layer
#include "TWI_config.h"
#include "TWI_private.h"

#include "../../MCAL/1-DIO/DIO_interface.h"


#include<util/delay.h>


ES_t  TWI_enum_Master_INIT(void)
{
	ES_t Local_enu_Erorr_State= ES_OK;
    /*set prescaler value */
#if TWI_prescaler_mode == TWI_prescaler_1
	CLR_BIT(TWI_u8_TWSR_REG,TWI_u8_TWPS1_BIT1);
	CLR_BIT(TWI_u8_TWSR_REG,TWI_u8_TWPS0_BIT0);
#elif TWI_prescaler_mode == TWI_prescaler_4
	CLR_BIT(TWI_u8_TWSR_REG,TWI_u8_TWPS1_BIT1);
	SET_BIT(TWI_u8_TWSR_REG,TWI_u8_TWPS0_BIT0);
#elif TWI_prescaler_mode == TWI_prescaler_16
	SET_BIT(TWI_u8_TWSR_REG,TWI_u8_TWPS1_BIT1);
	CLR_BIT(TWI_u8_TWSR_REG,TWI_u8_TWPS0_BIT0);
#elif TWI_prescaler_mode == TWI_prescaler_64
	SET_BIT(TWI_u8_TWSR_REG,TWI_u8_TWPS1_BIT1);
	SET_BIT(TWI_u8_TWSR_REG,TWI_u8_TWPS0_BIT0);
#endif
    /*set TWBR with the value --> 200Hz */
	TWI_u8_TWBR_REG=((F_CPU / I2C_CLOCK_FREQ) - 16) / 2;

    /*enable ACK */
	SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWEA_BIT6);
    /*enable I2C */
	SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWEN_BIT2 );

	return Local_enu_Erorr_State;
}

ES_t  TWI_enum_Slave_INIT(u8 Copy_u8_Address)
{
	ES_t Local_enu_Erorr_State= ES_OK;
	    /*set slave address in TWAR */
	TWI_u8_TWAR_REG= Copy_u8_Address << 1;
	 /*enable ACK */
		SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWEA_BIT6);
	    /*enable I2C */
		SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWEN_BIT2 );

		return Local_enu_Erorr_State;
}

ES_t  TWI_enum_Send_Start_Condition(void)
{
	    ES_t Local_enu_Erorr_State= ES_OK;
	    /*clear flag + start condition */
		SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWSTA_BIT5 );
	    SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT_BIT7 );
	    			    /*wait for the flag to be 1 */
	    			while(!GET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT_BIT7 ));
	        /*check the status code*/
	    	if((TWI_u8_TWSR_REG & 0xF8 ) != TWI_u8_start_condation){
	    		Local_enu_Erorr_State= ES_NOK;
	    	}
	    /*clear start condition bit */
        CLR_BIT (TWI_u8_TWCR_REG,TWI_u8_TWSTA_BIT5);
			return Local_enu_Erorr_State;
}

ES_t  TWI_enum_Send_ReStart_Condition(void)
{
	        ES_t Local_enu_Erorr_State= ES_OK;
			    /*clear flag + start condition */
			SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWSTA_BIT5 );
			SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT_BIT7 );
			    /*wait for the flag to be 1 */
			while(!GET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT_BIT7));
		        /*check the status code = repeated start condition */
			if((TWI_u8_TWSR_REG & 0xF8 ) != TWI_u8_start_condation){
				    		Local_enu_Erorr_State= ES_NOK;
				    	}

		    /*clear start condition bit */
	        CLR_BIT (TWI_u8_TWCR_REG,TWI_u8_TWSTA_BIT5);

				return Local_enu_Erorr_State;
}
//
ES_t  TWI_enum_Send_Stop_Condition(void)
{
	ES_t Local_enu_Erorr_State= ES_OK;
			    /*clear flag + stop condition */
	SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWSTO_BIT4 );
     SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT_BIT7 );
				return Local_enu_Erorr_State;
}

ES_t  TWI_enum_Send_Slave_Address_With_Write(u8 Copy_u8_Slave_Address)
{
	ES_t Local_enu_Erorr_State= ES_OK;
	/*write slave address + 0 in TWDR */
	TWI_u8_TWDR_REG= Copy_u8_Slave_Address<<1 ;
	CLR_BIT(TWI_u8_TWDR_REG,TWI_u8_TWD0_BIT0);
	/*Clear Start Condition Bit*/
	CLR_BIT(TWI_u8_TWCR_REG,TWI_u8_TWSTA_BIT5);
	/*clear flag */
    SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT_BIT7 );

	 /*wait for the flag to be 1 */
	while(!GET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT_BIT7 ));

	/*check the status code = SLA+W */
	if((TWI_u8_TWSR_REG & 0xF8 ) != TWI_u8_ACK_write_condation){
	    Local_enu_Erorr_State= ES_NOK;
	    	    	}

	return Local_enu_Erorr_State;

}

ES_t  TWI_enum_Send_Slave_Address_With_Read(u8 Copy_u8_Slave_Address)
{
	ES_t Local_enu_Erorr_State= ES_OK;
		/*write slave address + 0 in TWDR */
	TWI_u8_TWDR_REG=Copy_u8_Slave_Address<<1;
	SET_BIT(TWI_u8_TWDR_REG,TWI_u8_TWD0_BIT0);
	/*Clear Start Condition Bit*/
		CLR_BIT(TWI_u8_TWCR_REG,TWI_u8_TWSTA_BIT5);
	/*clear flag */
	    SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT_BIT7 );

		 /*wait for the flag to be 1 */
		while(!GET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT_BIT7 ));

		/*check the status code = SLA+W */
		if((TWI_u8_TWSR_REG & 0xF8 ) != TWI_u8_ACK_reed_condation){
		    Local_enu_Erorr_State= ES_NOK;
		    	    	}

		return Local_enu_Erorr_State;
}

ES_t  TWI_enum_Send_Data_Byte(u8 Copy_u8_Date_Byte)
{
	ES_t Local_enu_Erorr_State= ES_OK;

	/*write data in TWDR */
	TWI_u8_TWDR_REG=Copy_u8_Date_Byte;
	/*clear flag */
		    SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT_BIT7 );

			 /*wait for the flag to be 1 */
			while(!GET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT_BIT7 ));

			/* check the status code = master send data*/
			if((TWI_u8_TWSR_REG & 0xF8 ) != TWI_u8_ACK_Master_send_condation){
			    Local_enu_Erorr_State= ES_NOK;
			    	    	}

	return Local_enu_Erorr_State;

}

ES_t  TWI_enum_Read_Data_Byte(u8 * Copy_pu8_Returned_Date_Byte)
{
	ES_t Local_enu_Erorr_State= ES_OK;

	/*check pointer*/
	if(Copy_pu8_Returned_Date_Byte!= NULL){
	/*clear flag*/
	    SET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT_BIT7 );

		/*wait for flag to be 1 */
		while(!GET_BIT(TWI_u8_TWCR_REG,TWI_u8_TWINT_BIT7 ));

		/* check the status code = master receive data*/
		if((TWI_u8_TWSR_REG & 0xF8 ) != TWI_u8_ACK_Master_reed_condation){
					    Local_enu_Erorr_State= ES_NOK;
					    	    	}
		/*read data in the pointer*/
		else
		{
			*Copy_pu8_Returned_Date_Byte= TWI_u8_TWDR_REG;
		}


	}
	else
	{
		Local_enu_Erorr_State= ES_NOK;

	}
	return Local_enu_Erorr_State;

}
