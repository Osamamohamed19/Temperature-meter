/*
 * ADC_private.h
 *
 * Created: 7/27/2023 4:48:41 PM
 *  Author: Osama
 */ 
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_
/* ***************        Defines for ADCMUX       *************** */
#define		MUX0	 0
#define		MUX1	 1
#define		MUX2	 2
#define		MUX3	 3
#define		MUX4	 4
#define		ADLAR	 5
#define		REFS0	 6
#define		REFS1	 7
/* ***************        Defines for ADCSRA       *************** */
#define		ADPS0	0
#define		ADPS1	1
#define		ADPS2	2
#define		ADIE	3
#define		ADIF	4
#define		ADATE	5
#define		ADSC	6
#define		ADEN	7

/* ****************	     ADC Multiplexing Register      **************** */
#define		 ADMUX		*((volatile unsigned char*)(0x27))
/* ****************   ADC control & status register     **************** */
#define		 ADCSRA		*((volatile unsigned char*)(0x26))
/* ****************      ADC High (DATA) Register       **************** */
#define		 ADCH		*((volatile unsigned char*)(0x25))
/* ****************      ADC Low (DATA) Register        **************** */
#define		 ADCL		*((volatile unsigned char*)(0x24))

#endif /* ADC_PRIVATE_H_ */