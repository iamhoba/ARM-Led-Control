/*********************************************************************************************************************
* FILE DESCRIPTION 
* -------------------------------------------------------------------------------
*						File: Mcu_HW.h
*					Module: Common Files
*
*	Description: header file for Mcu_HW
*********************************************************************************************************************/
#ifndef MCU_HW
#define MCU_HW

/*********************************************************************************************************************
* INCLUDES
*********************************************************************************************************************/
#include "Types.h"



/*********************************************************************************************************************
* GLOBAL DATA TYPES AND STRUCTURES
*********************************************************************************************************************/
typedef struct 
{
	uint32_t VECACT 		:8;
	uint32_t						:3;
	uint32_t RETBASE		:1;
	uint32_t VECPEND		:8;
	uint32_t 						:2;
	uint32_t ISRPEND		:1;
	uint32_t ISRPRE			:1;
	uint32_t 						:1;
	uint32_t PENDSTCLR	:1;
	uint32_t PENDSTSET	:1;
	uint32_t UNPENDSV		:1;
	uint32_t PENDSV			:2;
	uint32_t 						:2;
	uint32_t NMISET			:1;

}INTCTRL_BF;

typedef union 
{
	uint32_t 	 R;
	INTCTRL_BF B;

}INTCTRL_Tag;




/*********************************************************************************************************************
* GLOBAL CONSTANT MACROS 
*********************************************************************************************************************/
#define APINT_PRIGROUP_POS							8
#define	VECT_KEY												0x05FA
#define VECT_KEY_MSK										0x0000FFFF
#define APINT_PRIGROUP_MSK							0xFFFFF8FF

/*********************************************************************************************************************
* NVIC AND SCB REGISTERS 
*********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS 			0xE000E000
#define CLOCK_BASE_ADDRESS
#define APINT														*((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS + 0xD0C))
#define INTCTRL													*((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS + 0xD04))
#define	SYSPRI1													*((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS + 0xD18))
#define	SYSPRI2													*((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS + 0xD1C))
#define	SYSPRI3													*((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS + 0xD20))
#define RCGPIO													*((volatile uint32_t*)(CLOCK_BASE_ADDRESS + 0xD20))	



/*********************************************************************************************************************
* GPIO REGISTERS 
*********************************************************************************************************************/
#define GPIO_APB
#ifdef 	GPIO_APB	
#define GPIO_OFFSET(x)		(x<4?((0x40004000)+((x)*0x1000)):((0x40024000)+((x-4)*0x1000)))
/*
#define GPIO_PORTA_OFFSET 0x40004000
#define GPIO_PORTB_OFFSET	0x40005000
#define GPIO_PORTC_OFFSET 0x40006000
#define GPIO_PORTD_OFFSET	0x40007000
#define GPIO_PORTE_OFFSET	0x40024000
#define GPIO_PORTF_OFFSET	0x40025000
*/
#elif GPIO_AHB
#error "Not Supported Yet"
#else
#error "Please define a bus for GPIO"
#endif


#define GPIODATA(x) 	*((volatile uint32_t*)(GPIO_OFFSET(x) + 0x3FC))
#define GPIODIR(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x) + 0x400))
#define GPIOIS(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x) + 0x404))
#define GPIOIBE(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x) + 0x408))
#define GPIOIEV(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x) + 0x40C))
#define GPIOIM(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x) + 0x410))
#define GPIORIS(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x) + 0x414))
#define GPIOMIS(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x) + 0x418))
#define GPIOICR(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x) + 0x41C))
#define GPIOAFSEL(x)	*((volatile uint32_t*)(GPIO_OFFSET(x) + 0x420))
#define GPIODR2R(x) 	*((volatile uint32_t*)(GPIO_OFFSET(x) + 0x500))
#define GPIODR4R(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x) + 0x504))
#define GPIODR8R(x) 	*((volatile uint32_t*)(GPIO_OFFSET(x) + 0x508))
#define GPIOODR(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x) + 0x50C))
#define GPIOPUR(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x) + 0x510))
#define GPIOPDR(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x) + 0x514))
#define GPIOSLR(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x) + 0x518))
#define GPIODEN(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x) + 0x51C))
#define GPIOLOCK(x) 	*((volatile uint32_t*)(GPIO_OFFSET(x) + 0x520))
#define GPIOCR(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x) + 0x524))
#define GPIOAMSEL(x) 	*((volatile uint32_t*)(GPIO_OFFSET(x) + 0x528))


/*********************************************************************************************************************
* GLOBAL FUNCTION MACROS
*********************************************************************************************************************/




/*********************************************************************************************************************
* GLOBAL FUNCTIONS PROTOTYPES
*********************************************************************************************************************/




#endif /*MCU_HW*/
/*********************************************************************************************************************
* End of FILE: Mcu_HW.h
*********************************************************************************************************************/
