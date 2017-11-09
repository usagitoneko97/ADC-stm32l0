/*
 * Adc.h
 *
 *  Created on: Nov 8, 2017
 *      Author: DareBacon
 */

#ifndef ADC_H_
#define ADC_H_

#include "stm32l0xx.h"
#include "stm32l053xx.h"

#define ADC_BASE_ADDR		0X40012400
#define Adc					((AdcReg*)(ADC_BASE_ADDR))
#define ADC_CCR_BASE_ADDR	ADC_BASE_ADDR+0x308
#define AdcCcr				((AdcRegCCR*)(ADC_CCR_BASE_ADDR))

typedef struct AdcReg AdcReg;
struct AdcReg
{
  volatile uint32_t ADC_ISR;
  volatile uint32_t ADC_IER;
  volatile uint32_t ADC_CR;
  volatile uint32_t ADC_CFGR1;
  volatile uint32_t ADC_CFGR2;
  volatile uint32_t ADC_SMPR;
  volatile uint32_t RESERVED[2];
  volatile uint32_t ADC_TR;
  volatile uint32_t RESERVED0;
  volatile uint32_t ADC_CHSELR;
  volatile uint32_t RESERVED1[5];
  volatile uint32_t ADC_DR;
  volatile uint32_t RESERVED2[28];
  volatile uint32_t ADC_CALFACT;
};

typedef struct AdcRegCCR AdcRegCCR;
struct AdcRegCCR{
	volatile uint32_t ADC_CCR;
};

#define ADC_ENABLE()                SET_BIT(Adc->ADC_CR, ADC_CR_ADEN)
#define ADC_SELECT_CHANNEL(x)	    Adc->ADC_CHSELR |= (1<<x)
#define ADC_CLEAR_ALL_CHANNEL(x)    CLEAR_REG(Adc->ADC_CHSELR)
#define ADC_START()					SET_BIT(Adc->ADC_CR, ADC_CR_ADSTART)
#define ADC_SAMPLING(x)             WRITE_REG(Adc->ADC_SMPR, x)
#define ADC_GET_DATA()              READ_REG(Adc->ADC_DR)
#define ADC_ENABLE_TMP_SENSOR()     SET_BIT(AdcCcr->ADC_CCR, ADC_CCR_TSEN)
#define ADC_SET_CONT_MODE()			SET_BIT(Adc->ADC_CFGR1, ADC_CFGR1_CONT)
#define ADC_SET_CKMODE(x)			MODIFY_REG(Adc->ADC_CFGR2, ADC_CFGR2_CKMODE_Msk, x << ADC_CFGR2_CKMODE_Pos)

#define ADC_ENABLE_IT_EOC()			SET_BIT(Adc->ADC_IER, ADC_IER_EOCIE)
#define ADC_ENABLE_IT_OVR()			SET_BIT(Adc->ADC_IER, ADC_IER_OVRIE)
#endif /* ADC_H_ */
