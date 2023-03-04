/*
 * SevSegment_int.h

 *
 *  Created on: Aug 25, 2022
 *      Author: Seif
 */

#ifndef HAL_SEVENSEGMENT_SEVSEGMENT_INT_H_
#define HAL_SEVENSEGMENT_SEVSEGMENT_INT_H_


#include "../../MCAL/DIO/DIO_int.h"


// Check Error Status 
typedef enum 
{
	SevSegment_OK,
	SevSegment_NOK
}SevSegment_tenuErrorStatus;

/// Needed Functions///




/*
 * Name: SevSegment_enuDisplayNumber
 * Description: Display the desired number on the SevSegment.
 * Arguments:   First Argument : Copy_u8Port         options(DIO_u8_PORTA,DIO_u8_PORTB,DIO_u8_PORTC,DIO_u8_PORTD)
 *              Second Argument: Copy_u8Number                 options(From ONE to NINE)
 * Return: Error Status ->>>>>>>DIO_OK , DIO_NOK
 * */
SevSegment_tenuErrorStatus SevSegment_enuDisplayNumber(u8 Copy_u8Port,u8 Copy_u8Number);



//**************** New Function *******************// 
SevSegment_tenuErrorStatus SevSegment_enuDisplayNumber_BCD(u8 Copy_u8Number);




#endif /* HAL_SEVENSEGMENT_SEVSEGMENT_INT_H_ */
