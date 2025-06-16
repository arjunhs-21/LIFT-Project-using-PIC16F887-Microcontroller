/*
 * File:   LIFT.c
 * Author: arjun
 *
 * Created on 12 March, 2025, 11:26 AM
 */
// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#include <xc.h>
#define RS RE0
#define EN RE1
int a=0;
void delay(unsigned int A)
{
    while(A--);
}
void enable()
{
    EN=1;
    delay(1000);
    EN=0;
    delay(1000);
}
void lcd(char rs,char data)
{
    RS = rs;
    PORTD = data;
    enable();
}
void string(char *ptr)
{
    while(*ptr)
    {
        lcd(1,*ptr++);
    }
}
void main(void) 
{
    PORTA = PORTB = PORTC = PORTD = PORTE = 0X00;
    TRISA = TRISD = TRISE = 0X00; 
    TRISB = TRISC=0X0F;
    ANSEL = ANSELH = 0X00;
    
    lcd(0,0X38);
    lcd(0,0X0E);
    lcd(0,0X80);
    while(1)
    {
        if(RB0==1)
        {
            if(a==2)
            {
                     RC6 = 1;
                     RC7 = 0;
            }
            else if(a==3)
            {
                     RC6 = 1;
                     RC7 = 0;
            }
            else if(a==4)
            {
                     RC6 = 1;
                     RC7 = 0;
            }
//            RC6 = 0;
//            RC7 = 0;
            a = 1;
            while(RB0==1);
        }
        if((RC0==0)&&(a==1))
        {
                RC6=0;
                RC7=0;
                lcd(0,0X80);
                RA0=1;
                RA1=RA2=RA3=0;
                string("GROUND FLOOR");
                 //while(RC0==1);
        }
        //////////////////////////////////////
        if(RB1==1)
        {
            if(a==1)
            {
                     RC6 = 0;
                     RC7 = 1;
            }
            else if(a==3)
            {
                     RC6 = 1;
                     RC7 = 0;
            }
            else if(a==4)
            {
                     RC6 = 1;
                     RC7 = 0;
            }
            a=2;
//            RC6 = 1;
//            RC7 = 0;
            while(RB1==1);
        }
        if((RC1==0)&&(a==2))
        {
                RC6=0;
                RC7=0;
                lcd(0,0X80);
                RA1=1;
                RA0=RA2=RA3=0;
                string("FIRST FLOOR");
                //while(RC1==1);
        }
        //////////////////////////////////////////
        if(RB2==1)
        {
          if(a==1)
            {
                     RC6 = 0;
                     RC7 = 1;
            }
            else if(a==2)
            {
                     RC6 = 0;
                     RC7 = 1;
            }
            else if(a==4)
            {
                     RC6 = 1;
                     RC7 = 0;
            }   
            a=3;
//            RC6 = 1;
//            RC7 = 0;
            while(RB2==1);
        }
        if((RC2==0)&&(a==3))
        {
                RC6=0;
                RC7=0;
                lcd(0,0X80);
                RA2=1;
                RA0=RA1=RA3=0;
                string("SECOND FLOOR");
                //while(RC2==1);
        }
        //////////////////////////////////////
        if(RB3==1)
        {
            if(a==1)
            {
                     RC6 = 0;
                     RC7 = 1;
            }
            else if(a==2)
            {
                     RC6 = 0;
                     RC7 = 1;
            }
            else if(a==3)
            {
                     RC6 = 0;
                     RC7 = 1;
            }
            a=4;
            while(RB3==1);
        }
        if((RC3==0)&&(a==4))
        {
                RC6=0;
                RC7=0;
                lcd(0,0X80);
                RA3=1;
                RA0=RA2=RA0=0;
                string("THIRD FLOOR");
                //while(RC3==1);
        }    
    }
}
