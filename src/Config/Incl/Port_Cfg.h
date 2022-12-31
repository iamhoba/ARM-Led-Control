/*********************************************************************************************************************
* FILE DESCRIPTION 
* -------------------------------------------------------------------------------
*						File: Port_Cfg.h
*					Module: Common Files
*
*	Description: header file for Port Configuration
*********************************************************************************************************************/
#ifndef PORT_Cfg_H
#define PORT_Cfg_H

/*********************************************************************************************************************
* INCLUDES
*********************************************************************************************************************/
#include "../../Common/Incl/Types.h"



/*********************************************************************************************************************
* GLOBAL CONSTANT MACROS 
*********************************************************************************************************************/
#define PORT_PINS_NUM 			(uint8_t)(2U)

/*Port_PinLevel CONFIGURATION OPTIONS*/
#define PORT_PIN_HIGH				HIGH
#define PORT_PIN_LOW				LOW

/*PortPinDirection CONFIGURATION OPTIONS*/
#define PORT_PIN_INPUT			IN
#define	PORT_PIN_OUTPUT			OUT

/*PortNum CONFIGURATION OPTIONS*/
#define PORT_A							'A'
#define PORT_B							'B'
#define PORT_C							'C'
#define PORT_D							'D'
#define PORT_E							'E'
#define PORT_F							'F'
#define A										0
#define B										1
#define C										2
#define D										3
#define E										4
#define F										5

/*PortPinNum CONFIGURATION OPTIONS*/
#define PORT_PIN_0					0
#define PORT_PIN_1					1
#define PORT_PIN_2					2
#define PORT_PIN_3					3
#define PORT_PIN_4					4
#define PORT_PIN_5					5
#define PORT_PIN_6					6
#define PORT_PIN_7	  			7

/*PortPinOutputCurrent CONFIGURATION OPTIONS*/
#define PORT_PIN_CUR_2MA		2
#define PORT_PIN_CUR_4MA		4
#define PORT_PIN_CUR_8MA		8

/*PortPinMode CONFIGURATION OPTIONS*/
#define PORT_PIN_DEN				0

/*PortPinInternalAttach CONFIGURATION OPTIONS*/
#define PORT_PIN_PUR				0
#define PORT_PIN_PDR				1
#define PORT_PIN_ODR				2


/*********************************************************************************************************************
* GLOBAL CONSTANT CONFIGURATIONS 
*********************************************************************************************************************/
#define PORT_PINSNUM				0




/*********************************************************************************************************************
* GLOBAL DATA TYPES AND STRUCTURES
*********************************************************************************************************************/
typedef uint8_t Port_PinModeType;
typedef uint8_t Port_PinLevel;
typedef uint8_t Port_PinDirectionType;
typedef uint8_t Port_PinInternalAttachType;
typedef uint8_t Port_PinOutputCurrentType;
typedef uint8_t Port_Num;
typedef uint8_t Port_PinNum;

/*********************************************************************************************************************
* STRUCTS AND UNIONS
*********************************************************************************************************************/
typedef struct
{
	Port_PinModeType						PortPinMode;
	Port_PinLevel			     			PortPinLevelValue;
	Port_PinDirectionType   		PortPinDirection;
	Port_PinInternalAttachType	PortPinInternalAttach;
	Port_PinOutputCurrentType		PortPinOutputCurrent;
	Port_Num										PortNum;
	Port_PinNum									PortPinNum;
}Port_ConfigType;

/*********************************************************************************************************************
* INTERRUPTS ACTIVATION 
*********************************************************************************************************************/


/*********************************************************************************************************************
* INTERRUPTS PRIORTY 
*********************************************************************************************************************/


/*********************************************************************************************************************
* GLOBAL FUNCTION MACROS
*********************************************************************************************************************/



/*********************************************************************************************************************
* GLOBAL FUNCTIONS PROTOTYPES
*********************************************************************************************************************/


/********************************************************************************
* Syntax						: 
* Description				: 
*
*
* Sync\Async				: Synchronous
* Reentrancy				: Non Reentrant 
* Parameters (in)		: None
* Parameters (out)	: None
* Return value			: None
********************************************************************************/



#endif /*INTCTRL_CFG_H*/
/*********************************************************************************************************************
* End of FILE: IntCtrl_Cfg.h
*********************************************************************************************************************/
