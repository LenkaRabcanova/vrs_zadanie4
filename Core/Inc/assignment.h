/*
 * assignement.h
 *
 *  Created on: Oct 13, 2020
 *      Author: stancoj
 */

#ifndef ASSIGNMENT_H_
#define ASSIGNMENT_H_

#include "main.h"

#define	GPIOA_BASE_ADDR			(uint32_t)(0x48000000U)
#define	GPIOB_BASE_ADDR			(uint32_t)(0x48000400U)

//MODER register
#define	GPIOA_MODER_REG			*((volatile uint32_t *)(GPIOA_BASE_ADDR + 0x00U))
//OTYPER register
#define	GPIOA_OTYPER_REG		*((volatile uint32_t *)(GPIOA_BASE_ADDR + 0x04U))
//OSPEEDER register
#define GPIOA_OSPEEDER_REG		*((volatile uint32_t *)(GPIOA_BASE_ADDR + 0x08U))
//PUPDR register
#define GPIOA_PUPDR_REG			*((volatile uint32_t *)(GPIOA_BASE_ADDR + 0x0CU))
//IDR register
#define GPIOA_IDR_REG			*((volatile uint32_t *)(GPIOA_BASE_ADDR + 0x10U))
//ODR register
#define GPIOA_ODR_REG			*((volatile uint32_t *)(GPIOA_BASE_ADDR + 0x14U))
//BSRR register
#define GPIOA_BSRR_REG			*((volatile uint32_t *)(GPIOA_BASE_ADDR + 0x18U))
//BRR register
#define GPIOA_BRR_REG			*((volatile uint32_t *)(GPIOA_BASE_ADDR + 0x28U))



#define	GPIOB_MODER_REG			*((volatile uint32_t *)(GPIOB_BASE_ADDR + 0x00U))
//OTYPER register
#define	GPIOB_OTYPER_REG		*((volatile uint32_t *)(GPIOB_BASE_ADDR + 0x04U))
//OSPEEDER register
#define GPIOB_OSPEEDER_REG		*((volatile uint32_t *)(GPIOB_BASE_ADDR + 0x08U))
//PUPDR register
#define GPIOB_PUPDR_REG			*((volatile uint32_t *)(GPIOB_BASE_ADDR + 0x0CU))
//IDR register
#define GPIOB_IDR_REG			*((volatile uint32_t *)(GPIOB_BASE_ADDR + 0x10U))
//ODR register
#define GPIOB_ODR_REG			*((volatile uint32_t *)(GPIOB_BASE_ADDR + 0x14U))
//BSRR register
#define GPIOB_BSRR_REG			*((volatile uint32_t *)(GPIOB_BASE_ADDR + 0x18U))
//BRR register
#define GPIOB_BRR_REG			*((volatile uint32_t *)(GPIOB_BASE_ADDR + 0x28U))



/*Reset clock control register macros */
//RCC base address
#define	RCC_BASE_ADDR			(uint32_t)(0x40021000U)
//AHBEN register
#define	RCC_AHBENR_REG			*((volatile uint32_t *)(RCC_BASE_ADDR + 0x00000014U))

/* LED and button macros */
#define LED_ON					GPIOA_BSRR_REG |= (1 << 4)
#define LED_OFF					GPIOA_BRR_REG |= (1 << 4)

#define BUTTON_GET_STATE		!(GPIOA_IDR_REG & (1 << 4))

/*
#define SYSCFG_BASE_ADDR        (uint32_t)(0x40010000U)
#define SYSCFG_EXTICR2          *((volatile uint32_t *)(SYSCFG_BASE_ADDR + 0x0CU))
#define EXTI_IMR2               *((volatile uint32_t *)((SYSCFG_BASE_ADDR + 0x0CU) + 0x20U))
#define EXTI_RTSR2              *((volatile uint32_t *)((SYSCFG_BASE_ADDR + 0x0CU) + 0x28U))
#define EXTI_FTSR2              *((volatile uint32_t *)((SYSCFG_BASE_ADDR + 0x0CU) + 0x2CU))
#define EXTI_PR2                *((volatile uint32_t *)((SYSCFG_BASE_ADDR + 0x0CU) + 0x34U))
*/

// defines for input port used by button
#define		GPIO_PORT_BUTTON				GPIOB
#define		GPIO_PIN_BUTTON					4

// defines for "checkButtonState"
#define		TRIGGER_RISE					1
#define		TRIGGER_FALL					0

#define		BUTTON_EXTI_TRIGGER				TRIGGER_FALL
#define		BUTTON_EXTI_SAMPLES_WINDOW		30
#define		BUTTON_EXTI_SAMPLES_REQUIRED	20


/**
 *  Function checks if the button was pressed or EXTI detection was false - positive.
 *  @input_param_1 - PORT: GPIO port connected to button.
 *  @input_param_2 - PIN: GPIO pin connected to button.
 *  @input_param_3 - edge: EXTI trigger edge. Defines what is the input GPIO idle state after the button is pressed.
 *  					   TRIGGER_RISE - input is expected to be "1" after EXTI was triggered.
 *  					   TRIGGER_FALL - input is expected to be "0" after EXTI was triggered.
 *  @input_param_4 - samples_window: How many samples are checked (input port is read) after EXTI is triggered.
 *  @input_param_5 - samples_required: How many samples in row are required to be in the idle state.
 */
uint8_t checkButtonState(GPIO_TypeDef* PORT, uint8_t PIN, uint8_t edge, uint8_t samples_window, uint8_t samples_required);

#endif /* ASSIGNMENT_H_ */
