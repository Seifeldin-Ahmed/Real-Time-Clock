 /*
 * SevSegment_prg.c

 *
 *  Created on: Aug 25, 2022
 *      Author: Seif
 */

#include "../../LIB/STD_Types.h"
#include "SevSegment_int.h"
#include "SevSegment_cfg.h"
#include "SevSegment_prv.h"

/// Needed Functions///

/*
 * Name: SevSegment_enuDisplayNumber
 * Description: Display the desired number on the SevSegment.
 * Arguments:   First Argument : Copy_u8Port         options(DIO_u8_PORTA,DIO_u8_PORTB,DIO_u8_PORTC,DIO_u8_PORTD)
 *              Second Argument: Copy_u8Number                 options(From ONE to NINE)
 * Return: Error Status ->>>>>>>DIO_OK , DIO_NOK
 * */
SevSegment_tenuErrorStatus SevSegment_enuDisplayNumber(u8 Copy_u8Port,u8 Copy_u8Number)
{
	SevSegment_tenuErrorStatus Local_enuErrorStatus=SevSegment_OK;
	if(Copy_u8Port>DIO_u8_PORTD || Copy_u8Number >9)
	{
		Local_enuErrorStatus = SevSegment_NOK;
	}

	else
	{
		switch  (Copy_u8Number)
      	    {
                  case 0 :
                 	               DIO_enuSetPortValue (Copy_u8Port,SevSegment_u8_ZERO);
                 	                        break;
                  case 1 :
                 	               DIO_enuSetPortValue (Copy_u8Port,SevSegment_u8_ONE);
                 	       		            break;
                  case 2 :
                      		   DIO_enuSetPortValue (Copy_u8Port,SevSegment_u8_TWO);
                      		       		   break;
                  case 3 :
                      		   DIO_enuSetPortValue (Copy_u8Port,SevSegment_u8_THREE);
                      		       		   break;
                  case 4 :
                      		   DIO_enuSetPortValue (Copy_u8Port,SevSegment_u8_FOUR);
                      		       		   break;
                  case 5 :
                      		   DIO_enuSetPortValue (Copy_u8Port,SevSegment_u8_FIVE);
                      		       		   break;
                  case 6 :
                      		   DIO_enuSetPortValue (Copy_u8Port,SevSegment_u8_SIX);
                      		       		   break;
                  case 7 :
                      		   DIO_enuSetPortValue (Copy_u8Port,SevSegment_u8_SEVEN);
                      		       		   break;
                  case 8 :
                      		   DIO_enuSetPortValue (Copy_u8Port,SevSegment_u8_EIGHT);
                      		       		   break;
                  case 9 :
                      		   DIO_enuSetPortValue (Copy_u8Port,SevSegment_u8_NINE);
                      		       		   break;

               }

	}
	return Local_enuErrorStatus;
}



SevSegment_tenuErrorStatus SevSegment_enuDisplayNumber_BCD(u8 Copy_u8Number)
{
	SevSegment_tenuErrorStatus Local_enuErrorStatus=SevSegment_OK;
	if(Copy_u8Number >9)
	{
		Local_enuErrorStatus = SevSegment_NOK;
	}

	else
	{
	    DIO_enuSetPinValue(SevSegment_u8_PIN0_PORT,SevSegment_u8_PIN0,((Copy_u8Number>>0 ) & 0x01));
	    DIO_enuSetPinValue(SevSegment_u8_PIN1_PORT,SevSegment_u8_PIN1,((Copy_u8Number>>1 ) & 0x01));
	    DIO_enuSetPinValue(SevSegment_u8_PIN2_PORT,SevSegment_u8_PIN2,((Copy_u8Number>>2 ) & 0x01));
	    DIO_enuSetPinValue(SevSegment_u8_PIN3_PORT,SevSegment_u8_PIN3,((Copy_u8Number>>3 ) & 0x01));
    }
	
	return Local_enuErrorStatus;
}	