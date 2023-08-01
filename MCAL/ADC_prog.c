/*
 * ADC_prog.c
 *
 * Created: 7/27/2023 4:48:25 PM
 *  Author: Osama
 */ 
#include "BIT_MATH.h"
#include "ADC_private.h"

void ADC_init(void)
{
	/* configure VREF */
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	
	/* Differential mode */
	SET_BIT(ADMUX,MUX4);
	
	/*  enable ADC   */
	SET_BIT(ADCSRA,ADEN);
	
	/* adjust ADC Clock */
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
}


unsigned short ADC_read(void)
{
	unsigned short read_value;
	
	SET_BIT(ADCSRA,ADSC);
	while(GET_BIT(ADCSRA,ADIF)==1);
	SET_BIT(ADCSRA,ADIF);
	
	read_value = ADCL;
	read_value |= (ADCH << 8);
	
	return read_value;
}

