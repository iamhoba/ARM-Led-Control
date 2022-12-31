/*********************************************************************************************************************
* FILE DESCRIPTION 
* -------------------------------------------------------------------------------
*						File: IntCtrl.c
*					Module: IntCtrl
*
*	Description: header file for IntCtrl Module
*********************************************************************************************************************/
#ifndef INTCTRL_H
#define INTCTRL_H

/*********************************************************************************************************************
* INCLUDES
*********************************************************************************************************************/
#include "IntCtrl_Types.h"
#include "../../../Common/Incl/Mcu_HW.h"
#include "../../../Config/Incl/IntCtrl_Cfg.h"


/*********************************************************************************************************************
* GLOBAL CONSTANT MACROS 
*********************************************************************************************************************/
#if PRIORITYGROUPING > 7
 PRIORITYGROUPING = 7;
#elseif PRIORITYGROUPING < 0
 PRIORITYGROUPING = 0;
#endif

/*********************************************************************************************************************
* GLOBAL FUNCTION MACROS
*********************************************************************************************************************/
#define PRIX(i)						(*((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS + ((0x0400+((i/4)*4))))))
#define ENX(i)						(*((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS + 0x0100 + ((i/32)*32))))
#define DISX(i)						(*((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS + 0x0180 + ((i/32)*32))))
#define EN_IN(i)					SET_BIT(ENX(i),(i-((i/32)*32)))
#define DIS_IN(i)					CLR_BIT(DISX(i),(i-((i/32)*32)))
#define PRI_IN(i,prio)		PRIX(i) |= (prio << ((i/32)/4) 


/*********************************************************************************************************************
* GLOBAL DATA TYPES AND STRUCTURES
*********************************************************************************************************************/
extern g_user_data;

/*********************************************************************************************************************
* GLOBAL FUNCTIONS PROTOTYPES
*********************************************************************************************************************/


/********************************************************************************
* Syntax						: void IntCtrl_Init(void)
* Description				: initialize NVIC\SCB Module by parsing the configuration
*										into NVIC\SCB registers
*
* Sync\Async				: Synchronous
* Reentrancy				: Non Reentrant 
* Parameters (in)		: None
* Parameters (out)	: None
* Return value			: None
********************************************************************************/
void IntCtrl_Init(void);


/********************************************************************************
* Syntax						: static void SetPriorityGrouping(void)
* Description				: Sets the priority (group and SubGroup numbers) of the NVIC exceptions
*										
*
* Sync\Async				: Synchronous
* Reentrancy				: Non Reentrant 
* Parameters (in)		: PriorityGrouping
* Parameters (out)	: None
* Return value			: None
********************************************************************************/
static void SetPriorityGrouping(void);


/********************************************************************************
* Syntax						: static void IntCtrl_setPriority(IntCtrl_InterruptType IntrNum, uint8_t u8_IntPriority)
* Description				: Sets the priority (group and SubGroup) of the interrupt
*											
*
* Sync\Async				: Synchronous
* Reentrancy				: Non Reentrant 
* Parameters (in)		: IntrNum, u8_IntPriority
* Parameters (out)	: None
* Return value			: None
********************************************************************************/
static void IntCtrl_setPriority(IntCtrl_InterruptType IntrNum, uint8_t u8_IntPriority);


/********************************************************************************
* Syntax						: static void IntCtrl_EnableInterrupt(void)
* Description				: Enable Interrupt
*											
*
* Sync\Async				: Synchronous
* Reentrancy				: Non Reentrant 
* Parameters (in)		: IntrNum, u8_IntPriority
* Parameters (out)	: None
* Return value			: None
********************************************************************************/
static void IntCtrl_EnableInterrupt(void);


static void IntCtrl_DisableInterrupt(IntCtrl_InterruptType IntrNum);



#endif /*INTCTRL_H*/
/*********************************************************************************************************************
* End of FILE: IntCtrl.h
*********************************************************************************************************************/
