/*
 * main.c
 *
 * Created: 22/09/2022 7:53:40 PM
 *  Author: SEIF
 */
//#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "../LIB/STD_Types.h"
#include "../HAL/PORT/PORT_int.h"
#include "../HAL/7-Segment/SevSegment_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/Keypad/KEYPAD_int.h"
#include "../MCAL/GPT_TIMERS/GPT_int.h"
volatile u8 Global_u8Counter_Seconds=0;
volatile u8 Global_u8Counter_Minutes=0;
volatile u8 Global_u8Counter_Hours=0;
void CBF1 ()
{
   Global_u8Counter_Seconds++;
 		  
 		  if(Global_u8Counter_Seconds >= 60)
 		  {
	 		  Global_u8Counter_Seconds=0;
	 		  Global_u8Counter_Minutes ++;
 		  }
 		  if(Global_u8Counter_Minutes >= 60)
 		  {
	 		  Global_u8Counter_Minutes=0;
	 		  Global_u8Counter_Hours ++;
 		  }
 		  if(Global_u8Counter_Hours >= 24)
 		  {
	 		  Global_u8Counter_Hours=0;
 		  }
   	   
}
int main(void)
{    
	u8 Loc_u8Value;
	u8 Loc_u8FirstDigit;
	u8 Loc_u8SecondDigit;
	 GPT_tstrOptions object;
	              object.Local_u8Prescaler=GPT_CHANNEL2_PRESCALER_128;
	              object.Local_u8Interrupt=GPT_TIMER2_OVERFLOW_INTERRUPT_ENABLE;
	              object.Local_u8CompareOutputMode=GPT_OC2_NORMAL_PORT_CONNECTION;
	              object.Local_u8Mode=GPT_u8_NORMAL;
	             

				
	  PORT_vidInit();
	  LCD_VidInit();
	  INT_vidEnableGlobalINT();
	  GPT_enuConfigure(GPT_u8_TIMER2,&object);
	  GPT_enuRegisterCBF(GPT_u8_TIMER2,CBF1);
      GPT_enuStartTimer(GPT_u8_TIMER2,1);
     
     LCD_enuSendString("Press 1 to");
     LCD_enuGoTo(1,0);
     LCD_enuSendString("Set clock");
     while(1)
     { 
		 
		 KEYPAD_enuGetPressedKey(&Loc_u8Value);
		 if(Loc_u8Value != KEYPAD_u8_NOTPRESSED)
		 {
			  		 DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN0,0);
			  		 DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN1,0);
			  		 DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN2,0);
			  		 DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN3,0);
			  		 DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN4,0);
			  		 DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN5,0);
			  SevSegment_enuDisplayNumber(DIO_u8_PORTB,0);
			  
			  		 DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN0,1);
			  		 DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN1,1);
			  		 DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN2,1);
			  		 DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN3,1);
			  		 DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN4,1);
			  		 DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN5,1);
			if(Loc_u8Value=='1') 
			{
		   //*********************************** Edit Hours ***************************************/
				LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
				LCD_enuSendString("Hours=--");
				LCD_enuGoTo(0,6);
            	_delay_ms(300);
				do{
					KEYPAD_enuGetPressedKey(&Loc_u8FirstDigit); // First Digit
				}while(Loc_u8FirstDigit == KEYPAD_u8_NOTPRESSED);
				LCD_enuSendCharacter(Loc_u8FirstDigit);
				_delay_ms(250);
			     do{
			 	     KEYPAD_enuGetPressedKey(&Loc_u8SecondDigit); // First Digit
				  }while(Loc_u8SecondDigit == KEYPAD_u8_NOTPRESSED);
				  LCD_enuSendCharacter(Loc_u8SecondDigit);
			     _delay_ms(250);
				 Global_u8Counter_Hours=(Loc_u8FirstDigit-48)*10 + (Loc_u8SecondDigit-48);
				 
			  //*********************************** Edit Minutes ***************************************/
			  LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
			  LCD_enuSendString("Minutes=--");
			  LCD_enuGoTo(0,8);
			  do{
				  KEYPAD_enuGetPressedKey(&Loc_u8FirstDigit); // First Digit
			  }while(Loc_u8FirstDigit == KEYPAD_u8_NOTPRESSED);
			  LCD_enuSendCharacter(Loc_u8FirstDigit);
			    _delay_ms(250);
			  do{
				  KEYPAD_enuGetPressedKey(&Loc_u8SecondDigit); // First Digit
			  }while(Loc_u8SecondDigit == KEYPAD_u8_NOTPRESSED);
			   LCD_enuSendCharacter(Loc_u8SecondDigit);
			     _delay_ms(250);
			  Global_u8Counter_Minutes=(Loc_u8FirstDigit-48)*10 + (Loc_u8SecondDigit-48);	 
				 
				  //*********************************** Edit Seconds ***************************************/
				  LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
				  LCD_enuSendString("Seconds=--");
				  LCD_enuGoTo(0,8);
				  do{
					  KEYPAD_enuGetPressedKey(&Loc_u8FirstDigit); // First Digit
				  }while(Loc_u8FirstDigit == KEYPAD_u8_NOTPRESSED);
				  LCD_enuSendCharacter(Loc_u8FirstDigit);
				    _delay_ms(250);
				  do{
					  KEYPAD_enuGetPressedKey(&Loc_u8SecondDigit); // First Digit
				  }while(Loc_u8SecondDigit == KEYPAD_u8_NOTPRESSED);
				  LCD_enuSendCharacter(Loc_u8SecondDigit);
				   _delay_ms(250);
				  Global_u8Counter_Seconds=(Loc_u8FirstDigit-48)*10 + (Loc_u8SecondDigit-48); 
				  
				 //*********************************** Back to default ***************************************//
				   LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
				   LCD_enuSendString("Press 1 to");
				   LCD_enuGoTo(1,0);
				   LCD_enuSendString("Set clock");

		    	}
				   else
				   {
					   LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
					   LCD_enuSendString("Wrong Choice");
					   _delay_ms(1000);
					   LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
					   LCD_enuSendString("Press 1 to");
					   LCD_enuGoTo(1,0);
			   		   LCD_enuSendString("Set clock");
					  }
		 }
 //***************************************** Display Seconds *******************************************/		 
		 DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN0,0);
		 DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN1,1);
		 DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN2,1);
		 DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN3,1);
		 DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN4,1); 
		 DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN5,1); 
		 SevSegment_enuDisplayNumber(DIO_u8_PORTB,Global_u8Counter_Seconds%10);
		 _delay_ms(3);
		 
		  DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN0,1);
		  DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN1,0);
		  DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN2,1);
		  DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN3,1);
		  DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN4,1);
		  DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN5,1);
		 SevSegment_enuDisplayNumber(DIO_u8_PORTB,Global_u8Counter_Seconds/10);
		  _delay_ms(3); 
//********************************************** Display Minutes ********************************************/		 
		 
		 DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN0,1);
		 DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN1,1);
		 DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN2,0);
		 DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN3,1);
		 DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN4,1);
		 DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN5,1);
		 SevSegment_enuDisplayNumber(DIO_u8_PORTB,Global_u8Counter_Minutes%10);
		  _delay_ms(3);
		 
		  DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN0,1);
		  DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN1,1);
		  DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN2,1);
		  DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN3,0);
		  DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN4,1);
		  DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN5,1);
		 SevSegment_enuDisplayNumber(DIO_u8_PORTB,Global_u8Counter_Minutes/10);
		  _delay_ms(3);
//********************************************** Display Hours ********************************************/

           
		  DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN0,1);
		  DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN1,1);
		  DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN2,1);
		  DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN3,1);
		  DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN4,0);
		  DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN5,1);  		 
		 SevSegment_enuDisplayNumber(DIO_u8_PORTB,Global_u8Counter_Hours%10);
		  _delay_ms(3);
		  
		  DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN0,1);
		  DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN1,1);
		  DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN2,1);
		  DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN3,1);
		  DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN4,1);
		  DIO_enuSetPinValue(DIO_u8_PORTC,DIO_u8_PIN5,0);
		 SevSegment_enuDisplayNumber(DIO_u8_PORTB,Global_u8Counter_Hours/10); 
		  _delay_ms(3);  
		  
		  
     }
	
	return 0;
}