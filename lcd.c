/*
 * File:   lcd.c
 * Author: Mateus
 *
 * Created on 5 de Março de 2018, 21:11
 */


#include <xc.h>
#define _XTAL_FREQ 16000000

void enable(){
    
    PORTAbits.RA0 = 0;
    __delay_ms(1);
    PORTAbits.RA0 = 1;
    __delay_ms(1);
    PORTAbits.RA0 = 0;
    __delay_ms(1);

}

void send_cmd(char cmd){

    PORTB = cmd;
    PORTCbits.RC7 = 0;
    enable();
    __delay_ms(1);

}

void send_msg(char msg){

    PORTB = msg;
    PORTCbits.RC7 = 1;
    __delay_ms(1);
    enable();
    __delay_ms(1);
    PORTCbits.RC7 = 0;

}

void init_LCD(){

    TRISB = 0x00;
    TRISAbits.TRISA0 = 0;
    TRISCbits.TRISC7 = 0;
    
    send_cmd(0x01); // Clear Display
    send_cmd(0x38); // Configura para operacoes com 8 bits e seleciona o display de duas linhas
    send_cmd(0x80); // Seta o display na posicao (0 ,0)
    send_cmd(0x0C); // Cursor com alterancia

}

void write_LCD(char *c){

    int i = 0;
    for(; c[i] != '\0'; i++)
        send_msg(c[i]);

}

void set_cursor(int line, int pos){
    
    char cursor;    
    if(line == 0)
        cursor = 0x80 + pos;
    else
        cursor = 0xC0 + pos;
    send_cmd(cursor);

}