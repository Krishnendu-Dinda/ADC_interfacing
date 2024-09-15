
/////////////////// ADC INTERFACING ///////////////////

#include<reg51.h>					//include 8051 header file.
#define DATA P2						//Select port2 as a data output pin.
#define adcval P3					//Select port2 for get data from ADC.
unsigned int i,j,k,l,m,n;

sbit rs=P0^0;         //select the pin P0.0 for register select.
sbit rw=P0^1;					//select the pin P0.1 for read/write.
sbit en=P0^2;					//select the pin P0.2 for Enable.
sbit rd=P1^0;					//select the pin P1.0 for send read signal to ADC0804. 
sbit wrt=P1^1;				//select the pin P1.1 for send write signal to ADC0804. 
sbit intr=P1^2;				//select the pin P1.2 for send INTR signal to ADC0804. 

unsigned int cmd[]={0x38,0x0E,0x01,0x06};
unsigned char asc[] ={"0123456789"};
unsigned char title2[]={"ADC value= "};

void delay_ms(){         //  Create a delay of 50mS.
  TMOD=0X01;            // Declear TMOD Resister as Timer 0 Mode 1.
	TH0=0x4B;		         // Load 4B to the TH0 resister.
	TL0=0xFD;	         	// Load FD to the TL0 resister.
	TR0=1;			       //Start Timer 0 resister.
	 while(TF0==0);   // Check if timer 0 is overflow or not.
	 TR0=0;					 //Stop Timer 0 resister.
	 TF0=0;					//Reset Timer 0 Overflow flag.
 }

void lcddata(unsigned char dat)			// Function for LCD data.
{
	DATA=dat;
	rs=1;
	rw=0;
	en=1;
	delay_ms();
	en=0;	
}

void lcdcmd(unsigned char comnd)		// Function for LCD Command.
{
DATA=comnd;
	rs=0;
	rw=0;
	en=1;
	delay_ms();
	en=0;	
}

void show_reading()				// Function for send ADC Value to the LCD display.
{
 unsigned int digit;
digit=0;
lcdcmd(0x8d);
lcddata(asc[digit]);
digit=((adcval*2)%10);
lcdcmd(0x8c);
lcddata(asc[digit]);
digit=((adcval*2)/10)%10;
lcdcmd(0x8b);
lcddata(asc[digit]);
digit=((adcval*2)/100)%10;
lcdcmd(0x8a);
lcddata(asc[digit]);
}

void main(){
	P1=0xff;							//select Port1 to get input from ADC0804.(Configure as an input port)
	for(n=0;n<4;n++){
		lcdcmd(cmd[n]);
	
	}
	lcdcmd(0x80);					  //Command for : Force Cursor to 1st matrix of 1st row.
	delay_ms();

	for(m=0;title2[m]!=(0);m++){
	
	lcddata(title2[m]);
	
		}
	
		lcdcmd(0x8e);					//Command for : Force Cursor to 15th matrix of 1st row.
lcddata('m');
		lcdcmd(0x8f);					//Command for : Force Cursor to 16th matrix of 1st row.
lcddata('V');
	wrt=1;								
while(1){
				
			rd=1;
			wrt=0;
			delay_ms();
			wrt=1;
			while(intr==1);				//wait until  intr is not high.
			rd=0;
			show_reading();
	7	delay_ms();

		
	}
}
