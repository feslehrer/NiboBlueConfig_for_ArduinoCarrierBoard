//*************************************************************************************************************
/*	Programm: NiboBlue Konfigurationsprogramm
Beschreibung:
Rahm, 14.1.18
*/
//*************************************************************************************************************
#include "controller.h"
//#include <stdio.h>

#define Taster _PORTB_
#define OK     5
#define Plus   4
#define Minus  3
#define S1     2

void SendAT_Kommando(uint8_t *pChar);
void get_baudrate(void);

uint8_t pin[] = "1234";
uint8_t name[] = "Robby";

volatile uint16_t time16;
volatile int8_t baud = 3;

volatile uint8_t response[17];
const uint32_t baudrate[] = {1200,2400,4800,9600,19200,38400,57600};

#define ANZ_BAUD 7

uint8_t Zeichen1[] = {0x00,0x04,0x0e,0x15,0x04,0x04,0x04,0x00};
uint8_t Zeichen2[] = {0x00,0x04,0x04,0x04,0x15,0x0e,0x04,0x00};

void setup(void)
{
	rs232_init();
	bit_init(Taster,S1,IN);
	bit_init(Taster,Plus,IN);
	bit_init(Taster,Minus,IN);
	bit_init(Taster,OK,IN);
	timer1ms_init(timer1ms_isr);
	lcd_init();
	delay_ms(2);
	lcd_clear();
  delay_ms(2);
	lcd_defchar(Zeichen1,1);
	lcd_defchar(Zeichen2,2);
	
	lcd_setcursor(1,1);
	lcd_print("NiboBlue Config");		// Anzeige auf LC-Display
	delay_ms(2000);
	lcd_clear();
	strcpy(response,"empty");
}

//*********** Hauptprogramm ********************************************************************************
void main (void)
{
	uint8_t buffer[17];
	volatile uint8_t status;
	volatile int8_t count=0;
	
	setup();

	while(1)
	{
		lcd_clear();
		lcd_setcursor(1,1);
	  lcd_print("Baud? ");
	  get_baudrate();
	  rs232_baud(baudrate[baud]);
		
		//--------------------------------------------------
		lcd_clear();
		lcd_print("->AT");
		SendAT_Kommando("AT");					// AT-Verbindung testen
		lcd_setcursor(2,1);
		lcd_print("> ");
		lcd_print(response);
		delay_ms(2000);
		lcd_clear();

		if (strcmp(response,"OK") == 0)			//OK
		{
			//----------------------------------------------------
      lcd_setcursor(1,1);
			lcd_print("Firmware?");
			SendAT_Kommando("AT+VERSION");	// Abfragen der Firmware-Version
  		lcd_setcursor(2,1);
	  	lcd_char('>');
		  lcd_print(response);
		  
			delay_ms(2000);
			lcd_clear();
			lcd_setcursor(1,1);
			//-----------------------------------------------------
			lcd_print("Nibo-Nr:");
			lcd_setcursor(2,1);
			lcd_print("S2:- S3:+ S4:OK");
      count++;
			while(bit_read(Taster,OK))
			{
				if(!bit_read(Taster,Plus))
				{
					delay_ms(40);
					if(count<100)	count++;
					while(!bit_read(Taster,Plus));
					delay_ms(40);
				}
				else if(!bit_read(Taster,Minus))
				{
					delay_ms(40);
					if(count>1)	  count--;
					while(!bit_read(Taster,Minus));
					delay_ms(40);
				}
				lcd_setcursor(1,12);
				lcd_dd(count);
			}

			sprintf(buffer,"AT+NAME%s%u",name,count);
			lcd_clear();
			lcd_setcursor(1,1);
			lcd_print("->"); lcd_print(buffer);
			
			SendAT_Kommando(buffer);	// Name des Bluetooth-Adapter
			lcd_setcursor(2,1);
			lcd_char('>');
  		lcd_print(response);
	  	delay_ms(2000);

			sprintf(buffer,"AT+PIN%s",pin);
			lcd_clear();
			lcd_setcursor(1,1);
			lcd_print("->"); lcd_print(buffer);

			SendAT_Kommando(buffer);	// Festlegen der Bluetooth-Pin
			lcd_setcursor(2,1);
			lcd_char('>');
  		lcd_print(response);
	  	delay_ms(2000);
			
		  lcd_clear();
			lcd_setcursor(1,1);
		  lcd_print("Baud New? ");
	  	get_baudrate();
			
			sprintf(buffer,"AT+BAUD%u",baud+1);   // 4=9600 ; 5=19200  usw.
		  lcd_clear();
			lcd_setcursor(1,1);
			lcd_print("->"); lcd_print(buffer);
			SendAT_Kommando(buffer);
			
			rs232_baud(baudrate[baud]);
		}
		else
		{
			lcd_setcursor(2,2);
			lcd_print("Error");
			delay_ms(2000);			
		}
	}
}

void SendAT_Kommando(uint8_t *pChar)
{
	uint8_t  c,n;
	
	rs232_print(pChar);

	time16 = 0;
	timer1ms_enable();
	n = 0;
	
	while(1)
	{
		while ((c=rs232_get()) == '\0')
		{
			if (time16 >= 1000)
			{
				timer1ms_disable();
				response[n]='\0';		//Stringende (0) einfügen
				return ;
			}
		}
		response[n++]=c;					//Antwort vom Nibo zeichenweise zusammensetzen
	}
}

void timer1ms_isr(void)
{
	time16++;
}

void get_baudrate(void)
{
  uint8_t buffer[10];
  
	lcd_setcursor(2,1);
	lcd_print("S2:\2 S3:\1 S4:OK");
		
	do
	{
		if(!bit_read(Taster,Plus))
		{
			delay_ms(40);
			if(baud<ANZ_BAUD-1)	baud++;
			while(!bit_read(Taster,Plus));
			delay_ms(40);
		}
		else if(!bit_read(Taster,Minus))
		{
			delay_ms(40);
			if(baud>0)	  baud--;
			while(!bit_read(Taster,Minus));
			delay_ms(40);
		}
		lcd_setcursor(1,11);
		lcd_int(baudrate[baud]);
	}
	while(bit_read(Taster,OK));
}