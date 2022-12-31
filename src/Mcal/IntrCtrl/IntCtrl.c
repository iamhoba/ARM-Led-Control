/*********************************************************************************************************************
* FILE DESCRIPTION 
* -------------------------------------------------------------------------------
*						File: IntCtrl.c
*					Module: IntCtrl
*
*	Description: C file for IntCtrl Module
*********************************************************************************************************************/

/*********************************************************************************************************************
* INCLUDES
*********************************************************************************************************************/
#include "Incl/IntCtrl.h"




/*********************************************************************************************************************
* LOCAL DATA
*********************************************************************************************************************/


/*********************************************************************************************************************
* GLOBAL FUNCTIONS
*********************************************************************************************************************/


/********************************************************************************
* Syntax						: void IntCtrl_Init(void)
* Description				: initialize NVIC\SCB Module by parsing the configuration
*											into NVIC\SCB registers
*
* Sync\Async				: Synchronous
* Reentrancy				: Non Reentrant 
* Parameters (in)		: None
* Parameters (out)	: None
* Return value			: None
********************************************************************************/
void IntCtrl_Init(void){
	
	/*Configure Grouping/Subgrouping system in APINT register in SCB*/
	SetPriorityGrouping();
	
	/*Enable/Disable based on user configurations and Assign Group/SubGroup priority in NVIC_ENx and SCB_Sys Registers*/
	IntCtrl_EnableInterrupt();
}


/*********************************************************************************************************************
* LOCAL FUNCTIONS
*********************************************************************************************************************/

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
static void SetPriorityGrouping(void)
{
	uint32_t APINT_Temp = APINT;
	uint32_t u32_PriorityGroupingTemp = ((uint32_t)PRIORITYGROUPING & 7UL);
	
	APINT_Temp &= ~((uint32_t)(VECT_KEY_MSK | APINT_PRIGROUP_MSK));
	
	APINT = (APINT_Temp | VECT_KEY | (u32_PriorityGroupingTemp << APINT_PRIGROUP_POS));
}



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

static void IntCtrl_setPriority(IntCtrl_InterruptType IntrNum, uint8_t u8_IntPriority)
{
	uint8_t n = 0;
	
	/*Saturate priority number between 0 and 7*/
	if (u8_IntPriority > 7)
	{
		u8_IntPriority = 7;
	}
	
	/*NVIC PRIx*/
	if (IntrNum < SP) 
	{ 
		n = IntrNum - (IntrNum/4)*4; 
		PRIX(IntrNum) |= ((uint32_t)(PORTA_IN_PRIO)) << (5 + 8*n);
	/*SCB SYSPRIx*/
	}
	else
	{
		switch(IntrNum)
		{
			case MemoryManagement_IRQ:
				SYSPRI1 |= ((uint32_t)u8_IntPriority << 5);
			break;
			case BusFault_IRQ:
				SYSPRI1 |= ((uint32_t)u8_IntPriority << 13);
			break;
			case UsageFault_IRQ:
				SYSPRI1 |= ((uint32_t)u8_IntPriority << 21);
			break;
			case SVCall_IRQ:
				SYSPRI2 |= ((uint32_t)u8_IntPriority << 29);
			break;
			case DebugMonitor_IRQ:
				SYSPRI3 |= ((uint32_t)u8_IntPriority << 5);
			break;
			case PendSV_IRQ:
				SYSPRI3 |= ((uint32_t)u8_IntPriority << 21);
			break;
			case SysTick_IRQ:
				SYSPRI3 |= ((uint32_t)u8_IntPriority << 29);
			break;
			default:
				break;
		}
	}
}


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
static void IntCtrl_EnableInterrupt(void)
{
	#if PORTA_IN == ENABLE
		EN_IN(GPIO_PORTA);
		IntCtrl_setPriority(GPIO_PORTA,GPIO_PORTA_IN_PRIO);
	#endif
	#if PORTB_IN == ENABLE
		EN_IN(GPIO_PORTB);
		IntCtrl_setPriority(GPIO_PORTB,GPIO_PORTB_IN_PRIO);
	#endif
	#if PORTC_IN == ENABLE
		EN_IN(GPIO_PORTC);
		IntCtrl_setPriority(GPIO_PORTC,GPIO_PORTC_IN_PRIO);
	#endif
	#if PORTD_IN == ENABLE
		EN_IN(GPIO_PORTD);
		IntCtrl_setPriority(GPIO_PORTD,GPIO_PORTD_IN_PRIO);
	#endif
	#if PORTE_IN == ENABLE
		EN_IN(GPIO_PORTE);
		IntCtrl_setPriority(GPIO_PORTE,GPIO_PORTE_IN_PRIO);
	#endif
	#if UART0_IN == ENABLE
		EN_IN(UART0);
		IntCtrl_setPriority(UART0,UART0_IN_PRIO);
	#endif
	#if UART1_IN == ENABLE
		EN_IN(UART1);
		IntCtrl_setPriority(UART1,UART1_IN_PRIO);
	#endif
	#if SSI0_IN == ENABLE
		EN_IN(SSI0);
		IntCtrl_setPriority(SSI0,SSI0_IN_PRIO);
	#endif
	#if I2C0_IN == ENABLE
		EN_IN(I2C0);
		IntCtrl_setPriority(I2C0,I2C0_IN_PRIO);
	#endif
	#if PWM0Fault_IN == ENABLE
		EN_IN(PWM0Fault);
		IntCtrl_setPriority(PWM0Fault,PWM0Fault_IN_PRIO);
	#endif
	#if PWM0G0_IN == ENABLE
		EN_IN(PWM0G0);		
		IntCtrl_setPriority(PWM0G0,PWM0G0_IN_PRIO);
	#endif
	#if PWM0G1_IN == ENABLE
		EN_IN(PWM0G1);
		IntCtrl_setPriority(PWM0G1,PWM0G1_IN_PRIO);
	#endif
	#if PWM0G2_IN == ENABLE
		EN_IN(PWM0G2);
		IntCtrl_setPriority(PWM0G2,PWM0G2_IN_PRIO);
	#endif
	#if PWM0G3_IN == ENABLE
		EN_IN(PWM0G3);
		IntCtrl_setPriority(PWM0G3,PWM0G3_IN_PRIO);
	#endif
	#if QEI0_IN == ENABLE
		EN_IN(QEI0);
		IntCtrl_setPriority(QEI0,QEI0_IN_PRIO);
	#endif
	#if ADC0S0_IN == ENABLE
		EN_IN(ADC0S0);
		IntCtrl_setPriority(ADC0S0,ADC0S0_IN_PRIO);
	#endif
	#if ADC0S1_IN == ENABLE
		EN_IN(ADC0S1);
		IntCtrl_setPriority(ADC0S1,ADC0S1_IN_PRIO);
	#endif
	#if ADC0S2_IN == ENABLE
		EN_IN(ADC0S2);
		IntCtrl_setPriority(ADC0S2,ADC0S2_IN_PRIO);
	#endif
	#if ADC0S3_IN == ENABLE
		EN_IN(ADC0S3);
		IntCtrl_setPriority(ADC0S3,ADC0S3_IN_PRIO);
	#endif
	#if WatchDog0and1_IN == ENABLE
		EN_IN(WatchDog0and1);
		IntCtrl_setPriority(WatchDog0and1,WatchDog0and1_IN_PRIO);
	#endif
	#if TIMER0A16_32_IN == ENABLE
		EN_IN(TIMER0A16_32);
		IntCtrl_setPriority(TIMER0A16_32,TIMER0A16_32_IN_PRIO);
	#endif
	#if TIMER0B16_32_IN == ENABLE
		EN_IN(TIMER0B16_32);
		IntCtrl_setPriority(TIMER0B16_32,TIMER0B16_32_IN_PRIO);
	#endif
	#if TIMER2A16_32_IN == ENABLE
		EN_IN(TIMER2A16_32);
		IntCtrl_setPriority(TIMER2A16_32,TIMER2A16_32_IN_PRIO);
	#endif
	#if TIMER2B16_32_IN == ENABLE
		EN_IN(TIMER2B16_32);
		IntCtrl_setPriority(TIMER2B16_32,TIMER2B16_32_IN_PRIO);
	#endif 
	#if AnaComp0_32_IN == ENABLE
		EN_IN(AnaComp0);
		IntCtrl_setPriority(AnaComp0,AnaComp0_IN_PRIO);
	#endif
	#if AnaComp1_32_IN == ENABLE
		EN_IN(AnaComp1);
		IntCtrl_setPriority(AnaComp1,AnaComp1_IN_PRIO);
	#endif
	#if SysCntrl_IN == ENABLE
		EN_IN(SysCntrl);
		IntCtrl_setPriority(SysCntrl,SysCntrl_IN_PRIO);
	#endif
	#if FMandEEPROM_IN == ENABLE
		EN_IN(FMandEEPROM);
		IntCtrl_setPriority(FMandEEPROM,FMandEEPROM_IN_PRIO);
	#endif
	#if GPIO_PORTF_IN == ENABLE
		EN_IN(GPIO_PORTF);
		IntCtrl_setPriority(GPIO_PORTF,GPIO_PORTF_IN_PRIO);
	#endif
	#if UART2_IN == ENABLE
		EN_IN(UART2);
		IntCtrl_setPriority(UART2,UART2_IN_PRIO);
	#endif
	#if SSI1_IN == ENABLE
		EN_IN(SSI1);
		IntCtrl_setPriority(SSI1,SSI1_IN_PRIO);
	#endif
	#if TIMER3A16_32_IN == ENABLE
		EN_IN(TIMER3A16_32);
		IntCtrl_setPriority(TIMER3A16_32,TIMER3A16_32_IN_PRIO);
	#endif
	#if TIMER3B16_32_IN == ENABLE
		EN_IN(TIMER3B16_32);
		IntCtrl_setPriority(TIMER3B16_32,TIMER3B16_32_IN_PRIO);
	#endif
	#if I2C1_IN == ENABLE
		EN_IN(I2C1);
		IntCtrl_setPriority(I2C1,I2C1_IN_PRIO);
	#endif
	#if QEI1_IN == ENABLE
		EN_IN(QEI1);
		IntCtrl_setPriority(QEI1,QEI1_IN_PRIO);
	#endif
	#if CAN0_IN == ENABLE
		EN_IN(CAN0);
		IntCtrl_setPriority(CAN0,CAN0_IN_PRIO);
	#endif
	#if CAN1_IN == ENABLE
		EN_IN(CAN1);
		IntCtrl_setPriority(CAN1,CAN1_IN_PRIO);
	#endif
	#if HiberMod_IN == ENABLE
		EN_IN(HiberMod);
		IntCtrl_setPriority(HiberMod,HiberMod_IN_PRIO);
	#endif
	#if USB_IN == ENABLE
		EN_IN(USB);
		IntCtrl_setPriority(USB,USB_IN_PRIO);
	#endif
	#if PWMG3_IN == ENABLE
		EN_IN(PWMG3);
		IntCtrl_setPriority(PWMG3,PWMG3_IN_PRIO);
	#endif
	#if DMA_SW_IN == ENABLE
		EN_IN(DMA_SW);
		IntCtrl_setPriority(DMA_SW,DMA_SW_IN_PRIO);
	#endif
	#if ADC1Seq0_IN == ENABLE
		EN_IN(ADC1Seq0);
		IntCtrl_setPriority(ADC1Seq0,ADC1Seq0_IN_PRIO);
	#endif
	#if ADC1Seq1_IN == ENABLE
		EN_IN(ADC1Seq1);
		IntCtrl_setPriority(ADC1Seq1,ADC1Seq1_IN_PRIO);
	#endif
	#if ADC1Seq2_IN == ENABLE
		EN_IN(ADC1Seq2);
		IntCtrl_setPriority(ADC1Seq2,ADC1Seq2_IN_PRIO);
	#endif
	#if ADC1Seq3_IN == ENABLE
		EN_IN(ADC1Seq3);
		IntCtrl_setPriority(ADC1Seq3,ADC1Seq3_IN_PRIO);
	#endif
	#if SSI2_IN == ENABLE
		EN_IN(SSI2);
		IntCtrl_setPriority(SSI2,SSI2_IN_PRIO);
	#endif
	#if SSI3_IN == ENABLE
		EN_IN(SSI3);
		IntCtrl_setPriority(SSI3,SSI3_IN_PRIO);
	#endif
	#if UART3_IN == ENABLE
		EN_IN(UART3);
		IntCtrl_setPriority(UART3,UART3_IN_PRIO);
	#endif
	#if UART4_IN == ENABLE
		EN_IN(UART4);
		IntCtrl_setPriority(UART4,UART4_IN_PRIO);
	#endif
	#if UART5_IN == ENABLE
		EN_IN(UART5);
		IntCtrl_setPriority(UART5,UART5_IN_PRIO);
	#endif
	#if UART6_IN == ENABLE
		EN_IN(UART6);
		IntCtrl_setPriority(UART6,UART6_IN_PRIO);
	#endif
	#if UART7_IN == ENABLE
		EN_IN(UART7);
		IntCtrl_setPriority(UART7,UART7_IN_PRIO);
	#endif
	#if I2C2_IN == ENABLE
		EN_IN(I2C2);
		IntCtrl_setPriority(I2C2,I2C2_IN_PRIO);
	#endif
	#if I2C3_IN == ENABLE
		EN_IN(I2C3);
		IntCtrl_setPriority(I2C3,I2C3_IN_PRIO);
	#endif
	#if TIMER4A16_32_IN == ENABLE
		EN_IN(TIMER4A16_32);
		IntCtrl_setPriority(TIMER4A16_32,TIMER4A16_32_IN_PRIO);
	#endif
	#if TIMER4B16_32_IN == ENABLE
		EN_IN(TIMER4B16_32);
		IntCtrl_setPriority(TIMER4B16_32,TIMER4B16_32_IN_PRIO);
	#endif
	#if TIMER5A16_32_IN == ENABLE
		EN_IN(TIMER5A16_32);
		IntCtrl_setPriority(TIMER5A16_32,TIMER5A16_32_IN_PRIO);
	#endif
	#if TIMER5B16_32_IN == ENABLE
		EN_IN(TIMER5B16_32);
		IntCtrl_setPriority(TIMER5B16_32,TIMER5B16_32_IN_PRIO);
	#endif
	#if TIMER0A32_64_IN == ENABLE
		EN_IN(TIMER0A32_64);
		IntCtrl_setPriority(TIMER0A32_64,TIMER0A32_64_IN_PRIO);
	#endif
	#if TIMER0B32_64_IN == ENABLE
		EN_IN(TIMER0B32_64);
		IntCtrl_setPriority(TIMER0B32_64,TIMER0B32_64_IN_PRIO);
	#endif
	#if TIMER1A32_64_IN == ENABLE
		EN_IN(TIMER1A32_64);
		IntCtrl_setPriority(TIMER1A32_64,TIMER1A32_64_IN_PRIO);
	#endif
	#if TIMER1B32_64_IN == ENABLE
		EN_IN(TIMER1B32_64);
		IntCtrl_setPriority(TIMER1B32_64,TIMER1B32_64_IN_PRIO);
	#endif
	#if TIMER2A32_64_IN == ENABLE
		EN_IN(TIMER2A32_64);
		IntCtrl_setPriority(TIMER2A32_64,TIMER2A32_64_IN_PRIO);
	#endif
	#if TIMER2B32_64_IN == ENABLE
		EN_IN(TIMER2B32_64);
		IntCtrl_setPriority(TIMER2B32_64,TIMER2B32_64_IN_PRIO);
	#endif
	#if TIMER3A32_64_IN == ENABLE
		EN_IN(TIMER3A32_64);
		IntCtrl_setPriority(TIMER3A32_64,TIMER3A32_64_IN_PRIO);
	#endif
	#if TIMER3B32_64_IN == ENABLE
		EN_IN(TIMER3B32_64);
		IntCtrl_setPriority(TIMER3B32_64,TIMER3B32_64_IN_PRIO);
	#endif
	#if TIMER4A32_64_IN == ENABLE
		EN_IN(TIMER4A32_64);
		IntCtrl_setPriority(TIMER4A32_64,TIMER4A32_64_IN_PRIO);
	#endif
	#if TIMER4B32_64_IN == ENABLE
		EN_IN(TIMER4B32_64);
		IntCtrl_setPriority(TIMER4B32_64,TIMER4B32_64_IN_PRIO);
	#endif
	#if TIMER5A32_64_IN == ENABLE
		EN_IN(TIMER5A32_64);
		IntCtrl_setPriority(TIMER5A32_64,TIMER5A32_64_IN_PRIO);
	#endif
	#if TIMER5B32_64_IN == ENABLE
		EN_IN(TIMER5B32_64);
		IntCtrl_setPriority(TIMER5B32_64,TIMER5B32_64_IN_PRIO);
	#endif
	#if SysExcep_IN == ENABLE
		EN_IN(SysExcep);
		IntCtrl_setPriority(SysExcep,SysExcep_IN_PRIO);
	#endif
	#if PWM1G0_IN == ENABLE
		EN_IN(PWM1G0);
		IntCtrl_setPriority(PWM1G0,PWM1G0_IN_PRIO);
	#endif
	#if PWM1G1_IN == ENABLE
		EN_IN(PWM1G1);
		IntCtrl_setPriority(PWM1G1,PWM1G1_IN_PRIO);
	#endif
	#if PWM1G2_IN == ENABLE
		EN_IN(PWM1G2);
		IntCtrl_setPriority(PWM1G2,PWM1G2_IN_PRIO);
	#endif
	#if PWM1G3_IN == ENABLE
		EN_IN(PWM1G3);
		IntCtrl_setPriority(PWM1G3,PWM1G3_IN_PRIO);
	#endif
	#if PWM1Fault_IN == ENABLE
		EN_IN(PWM1Fault);
		IntCtrl_setPriority(PWM1Fault,PWM1Fault_IN_PRIO);
	#endif
}

/*********************************************************************************************************************
* LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/



/*********************************************************************************************************************
* GLOBAL DATA
*********************************************************************************************************************/


/*********************************************************************************************************************
* End of FILE: IntCtrl.c
*********************************************************************************************************************/
