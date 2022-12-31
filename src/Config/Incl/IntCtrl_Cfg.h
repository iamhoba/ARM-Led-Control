/*********************************************************************************************************************
* FILE DESCRIPTION 
* -------------------------------------------------------------------------------
*						File: IntCtrl_Cfg.h
*					Module: Common Files
*
*	Description: header file for IntCtrl Configuration
*********************************************************************************************************************/
#ifndef INTCTRL_Cfg_H
#define INTCTRL_Cfg_H

/*********************************************************************************************************************
* INCLUDES
*********************************************************************************************************************/
#include "../../Common/Incl/Types.h"



/*********************************************************************************************************************
* GLOBAL CONSTANT MACROS 
*********************************************************************************************************************/
#define ENABLE   1
#define DISABLE  0

/*********************************************************************************************************************
* PRIORITY GROUPING 0-7
*********************************************************************************************************************/
#define PRIORITYGROUPING 0

/*********************************************************************************************************************
* INTERRUPTS ACTIVATION 
*********************************************************************************************************************/
#define PORTA_IN 								DISABLE
#define PORTB_IN 								DISABLE
#define PORTC_IN								DISABLE
#define PORTD_IN 								DISABLE
#define PORTE_IN 								DISABLE
#define UART0_IN 								DISABLE
#define UART1_IN 								DISABLE
#define SSI0_IN  								DISABLE
#define I2C0_IN  								DISABLE
#define PWM0Fault_IN 						DISABLE
#define PWM0G0_IN 							DISABLE
#define PWM0G1_IN 							DISABLE
#define PWM0G2_IN 				 			DISABLE
#define PWM0G3_IN 				 			DISABLE
#define QEI0_IN 								DISABLE
#define ADC0S0_IN 							DISABLE
#define ADC0S1_IN 							DISABLE
#define ADC0S2_IN 							DISABLE
#define ADC0S3_IN 							DISABLE
#define WatchDog0and1_IN 				DISABLE	
#define TIMER0A16_32_IN 				DISABLE
#define TIMER0B16_32_IN 				DISABLE
#define TIMER2A16_32_IN 				DISABLE
#define TIMER2B16_32_IN 				DISABLE
#define AnaComp0_32_IN 					DISABLE
#define AnaComp1_32_IN 					DISABLE
#define SysCntrl_IN 						DISABLE
#define FMandEEPROM_IN 					DISABLE
#define GPIO_PORTF_IN 					DISABLE
#define UART2_IN 								DISABLE
#define SSI1_IN 								DISABLE
#define TIMER3A16_32_IN 				DISABLE
#define TIMER3B16_32_IN 				DISABLE
#define I2C1_IN 								DISABLE
#define QEI1_IN 								DISABLE
#define CAN0_IN 								DISABLE
#define CAN1_IN 								DISABLE
#define HiberMod_IN 						DISABLE
#define USB_IN 									DISABLE
#define PWMG3_IN 								DISABLE
#define DMA_SW_IN 							DISABLE
#define ADC1Seq0_IN 						DISABLE
#define ADC1Seq1_IN 						DISABLE
#define ADC1Seq2_IN 						DISABLE
#define ADC1Seq3_IN 						DISABLE
#define SSI2_IN 								DISABLE
#define SSI3_IN 								DISABLE
#define UART3_IN 								DISABLE
#define UART4_IN 								DISABLE
#define UART5_IN 								DISABLE
#define UART6_IN 								DISABLE
#define UART7_IN 								DISABLE
#define I2C2_IN 								DISABLE
#define I2C3_IN 								DISABLE
#define TIMER4A16_32_IN 				DISABLE
#define TIMER4B16_32_IN 				DISABLE
#define TIMER5A16_32_IN 				DISABLE
#define TIMER5B16_32_IN					DISABLE
#define TIMER0A32_64_IN 				DISABLE
#define TIMER0B32_64_IN 				DISABLE
#define TIMER1A32_64_IN 				DISABLE
#define TIMER1B32_64_IN 				DISABLE
#define TIMER2A32_64_IN 				DISABLE
#define TIMER2B32_64_IN 				DISABLE
#define TIMER3A32_64_IN 				DISABLE
#define TIMER3B32_64_IN 				DISABLE
#define TIMER4A32_64_IN 				DISABLE
#define TIMER4B32_64_IN 				DISABLE
#define TIMER5A32_64_IN 				DISABLE
#define TIMER5B32_64_IN 				DISABLE
#define SysExcep_IN 						DISABLE
#define PWM1G0_IN 							DISABLE
#define PWM1G1_IN 							DISABLE
#define PWM1G2_IN 							DISABLE
#define PWM1G3_IN 							DISABLE
#define PWM1Fault_IN  					DISABLE


/*********************************************************************************************************************
* INTERRUPTS PRIORTY 
*********************************************************************************************************************/
#define PORTA_IN_PRIO 							0
#define PORTB_IN_PRIO 							0
#define PORTC_IN_PRIO 							0
#define PORTD_IN_PRIO 							0
#define PORTE_IN_PRIO 							0
#define UART0_IN_PRIO 							0
#define UART1_IN_PRIO 							0
#define SSI0_IN_PRIO 								0
#define I2C0_IN_PRIO 								0
#define PWM0Fault_IN_PRIO 					0
#define PWM0G0_IN_PRIO 							0
#define PWM0G1_IN_PRIO 							0
#define PWM0G2_IN_PRIO 							0
#define PWM0G3_IN_PRIO 							0
#define QEI0_IN_PRIO 								0
#define ADC0S0_IN_PRIO 							0
#define ADC0S1_IN_PRIO 							0
#define ADC0S2_IN_PRIO 							0
#define ADC0S3_IN_PRIO 							0
#define WatchDog0and1_IN_PRIO 			0	
#define TIMER0A16_32_IN_PRIO 				0
#define TIMER0B16_32_IN_PRIO 				0
#define TIMER2A16_32_IN_PRIO 				0
#define TIMER2B16_32_IN_PRIO 				0
#define AnaComp0_32_IN_PRIO 				0
#define AnaComp1_32_IN_PRIO 				0
#define SysCntrl_IN_PRIO 						0
#define FMandEEPROM_IN_PRIO 				0
#define GPIO_PORTF_IN_PRIO 					0
#define UART2_IN_PRIO 							0
#define SSI1_IN_PRIO 								0
#define TIMER3A16_32_IN_PRIO 				0
#define TIMER3B16_32_IN_PRIO 				0
#define I2C1_IN_PRIO 								0
#define QEI1_IN_PRIO 								0
#define CAN0_IN_PRIO 								0
#define CAN1_IN_PRIO 								0
#define HiberMod_IN_PRIO 						0
#define USB_IN_PRIO 								0
#define PWMG3_IN_PRIO 							0
#define DMA_SW_IN_PRIO 							0
#define ADC1Seq0_IN_PRIO 						0
#define ADC1Seq1_IN_PRIO 						0
#define ADC1Seq2_IN_PRIO 						0
#define ADC1Seq3_IN_PRIO 						0
#define SSI2_IN_PRIO 								0
#define SSI3_IN_PRIO 								0
#define UART3_IN_PRIO 							0
#define UART4_IN_PRIO 							0
#define UART5_IN_PRIO 							0
#define UART6_IN_PRIO 							0
#define UART7_IN_PRIO 							0
#define I2C2_IN_PRIO 								0
#define I2C3_IN_PRIO 								0
#define TIMER4A16_32_IN_PRIO 				0
#define TIMER4B16_32_IN_PRIO 				0
#define TIMER5A16_32_IN_PRIO 				0
#define TIMER5B16_32_IN_PRIO				0
#define TIMER0A32_64_IN_PRIO 				0
#define TIMER0B32_64_IN_PRIO 				0
#define TIMER1A32_64_IN_PRIO 				0
#define TIMER1B32_64_IN_PRIO 				0
#define TIMER2A32_64_IN_PRIO 				0
#define TIMER2B32_64_IN_PRIO 				0
#define TIMER3A32_64_IN_PRIO 				0
#define TIMER3B32_64_IN_PRIO 				0
#define TIMER4A32_64_IN_PRIO 				0
#define TIMER4B32_64_IN_PRIO 				0
#define TIMER5A32_64_IN_PRIO 				0
#define TIMER5B32_64_IN_PRIO 				0
#define SysExcep_IN_PRIO 						0
#define PWM1G0_IN_PRIO 							0
#define PWM1G1_IN_PRIO 							0
#define PWM1G2_IN_PRIO 							0
#define PWM1G3_IN_PRIO 							0
#define PWM1Fault_IN_PRIO  					0

/*********************************************************************************************************************
* GLOBAL FUNCTION MACROS
*********************************************************************************************************************/


/*********************************************************************************************************************
* GLOBAL DATA TYPES AND STRUCTURES
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
