/*
 * Global_Interrupt_prg.c
 *
 *  Created on: Sep 2, 2022
 *      Author: Dell
 */

#include "../../LIB/STD_Types.h"
#include "Global_Interrupt_int.h"
#include "Global_Interrupt_prv.h"

void INT_vidEnableGlobalINT()
{
	EXT_INT_u8_SREG_REG  |=0x80;

}

void INT_vidDisableGlobalINT()
{
	EXT_INT_u8_SREG_REG  =0x00;
}

