/*
 * File:   main.c
 * Author: SERVARIVERA
 *
 * Created on 5 de septiembre de 2018, 05:28 PM
 */


#include <xc.h>
#include "CONFIG.h"
#include <stdio.h>
#define _XTAL_FREQ 32000000
#include "flex_lcd.h"

void main(void) {
    unsigned char i;
    unsigned char buffer1[16];
    
     //configuracion del oscilador a 32MHz OSC = HFINT DIV 1:1
    OSCFRQbits.HFFRQ = 0b110; //HFINT a 32MHz
    
    
    //configuracion de puertos************
    ANSELD=0; //PUERTO D COMO DIGIAL
    ANSELE=0;//PUERTO D COMO DIGIAL
    
    //*********INICIALIZACION DE LA LCD
    Lcd_Init();//INICIALIZA LCD
    Lcd_Cmd(LCD_CLEAR );//LIMPIA LCD
    Lcd_Cmd(LCD_CURSOR_OFF );//APAGA EL CURSOR
    Lcd_Cmd(LCD_BLINK_CURSOR_ON );
        __delay_ms(1000);
    
    while(1){
     for(i=0; i<13; i++){
        Lcd_Out(1,i+1,"   Mecatronica");
            __delay_ms(500);
        sprintf(buffer1,"Cuenta: %03d",i);
        Lcd_Out2(2,3,buffer1);
            __delay_ms(500);
        }    
    }
}
