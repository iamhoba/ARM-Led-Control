/*********************************************************************************************************************
* FILE DESCRIPTION 
* -------------------------------------------------------------------------------
*						File: Port.c
*					Module: Port Module
*
*	Description: C file for Port Module
*********************************************************************************************************************/

/*********************************************************************************************************************
* INCLUDES
*********************************************************************************************************************/
#include "Incl/Port.h"

/*********************************************************************************************************************
* GLOBAL FUNCTIONS
*********************************************************************************************************************/

/********************************************************************************
* Syntax						: void Port_Init(const Port_ConfigType* ConfigPtr)
* Description				: initialize MCU Ports
*											
*
* Sync\Async				: Synchronous
* Reentrancy				: Non Reentrant 
* Parameters (in)		: None
* Parameters (out)	: None
* Return value			: None
********************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr)
{
	/*Variable to store Port base Address*/
	/*Variable for loop counter*/
	uint8_t u8_PinCounter = 0;
	for (u8_PinCounter = 0; u8_PinCounter < PORT_PINSNUM; u8_PinCounter++){
		Port_Num port_num = ConfigPtr[u8_PinCounter].PortNum;
		Port_PinNum pin_num = ConfigPtr[u8_PinCounter].PortPinNum;
		/*STEP 0: initialize the clock as mentioned in the datasheet*/
		SET_BIT(RCGPIO,ConfigPtr[u8_PinCounter].PortNum); 
		/*STEP 1: Set the direction*/
		if(PORT_PIN_OUTPUT == ConfigPtr[u8_PinCounter].PortPinDirection)
		{
			/*Set output direction*/
			SET_BIT(GPIODIR(port_num), pin_num);
			/*STEP 2: Set the level*/
			/*Configure Pin level*/
			if(PORT_PIN_HIGH == ConfigPtr[u8_PinCounter].PortPinLevelValue)
			{
				/*Set level high*/
				SET_BIT(GPIODATA(port_num), pin_num);
			}
			else if (PORT_PIN_LOW == ConfigPtr[u8_PinCounter].PortPinLevelValue)
			{
				/*Set level low*/
				CLR_BIT(GPIODATA(port_num), pin_num);
			}
			else 
			{
				/*error*/
				break;
			}
			/*STEP 3: Set the Output Current*/
			switch (ConfigPtr[u8_PinCounter].PortPinOutputCurrent)
			{
				case PORT_PIN_CUR_2MA:
					SET_BIT(GPIODR2R(port_num), pin_num);
				break;
				case PORT_PIN_CUR_4MA:
					SET_BIT(GPIODR4R(port_num), pin_num);
				break;
				case PORT_PIN_CUR_8MA:
					SET_BIT(GPIODR8R(port_num), pin_num);
				break;
				default: 
					/*error*/
					u8_PinCounter = PORT_PINS_NUM;
				continue;
			}
			/*STEP 4: Setting digital mode*/
			/*Configure Pin mode*/
			if (PORT_PIN_DEN == ConfigPtr[u8_PinCounter].PortPinMode)
			{
				/*Clear corresponding bit in GPIOAFSEL to disable alternative functionality*/
				CLR_BIT(GPIOAFSEL(port_num), pin_num);
				/*Set the corresponding bit in the GPIODEN register to enable digital functionality*/
				SET_BIT(GPIODEN(port_num), pin_num);
				/*Clear the corresponding bit in GPIOAMSEL to disable analog functionality*/
				CLR_BIT(GPIOAMSEL(port_num), pin_num);
			}
			else
			{
				/*Invalid Configuration*/
				break;
			}
		}
		else if (PORT_PIN_INPUT == ConfigPtr[u8_PinCounter].PortPinDirection)
		{
			/*Set input direction*/
			CLR_BIT(GPIODIR(port_num), pin_num);
		
			/*STEP 3: Set the Output Current*/
			switch (ConfigPtr[u8_PinCounter].PortPinOutputCurrent)
			{
				case PORT_PIN_CUR_2MA:
					SET_BIT(GPIODR2R(port_num), pin_num);
				break;
				case PORT_PIN_CUR_4MA:
					SET_BIT(GPIODR4R(port_num), pin_num);
				break;
				case PORT_PIN_CUR_8MA:
					SET_BIT(GPIODR8R(port_num), pin_num);
				break;
				default: 
					/*error*/
					u8_PinCounter = PORT_PINS_NUM;
				continue;
			}
			/*STEP 4: Setting digital mode*/
			/*Configure Pin mode*/
			if (PORT_PIN_DEN == ConfigPtr[u8_PinCounter].PortPinMode)
			{
				/*Clear corresponding bit in GPIOAFSEL to disable alternative functionality*/
				CLR_BIT(GPIOAFSEL(port_num), pin_num);
				/*Set the corresponding bit in the GPIODEN register to enable digital functionality*/
				SET_BIT(GPIODEN(port_num), pin_num);
				/*Clear the corresponding bit in GPIOAMSEL to disable analog functionality*/
				CLR_BIT(GPIOAMSEL(port_num), pin_num);
			}
			else
			{
				/*Invalid Configuration*/
				break;
			}
		}
		
	}
}


/**************************************************************************	*******************************************
* LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/


/*********************************************************************************************************************
* LOCAL DATA
*********************************************************************************************************************/


/*********************************************************************************************************************
* GLOBAL DATA
*********************************************************************************************************************/



/*********************************************************************************************************************
* End of FILE: Port.c
*********************************************************************************************************************/
