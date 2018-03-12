/*
 * File:   teclado_matricial_4x3.c
 * Author: Mateus
 *
 * Created on 1 de Março de 2018, 00:18
 */


#include <xc.h>
#include <pic16f870.h>

#include "teclado_matricial_4x3.h"
#define _XTAL_FREQ 16000000


unsigned PORTC_read(int i){
    switch(i){
        case 0:
            return PORTCbits.RC0;
        case 1:
            return PORTCbits.RC1;
        case 2:
            return PORTCbits.RC2;
        case 3:
            return PORTCbits.RC3;
        case 4:
            return PORTCbits.RC4;
        case 5:
            return PORTCbits.RC5;
        case 6:
            return PORTCbits.RC6;
        case 7:
            return PORTCbits.RC7;
        default:
            return 0;
    }
}

void PORTC_write(int i, unsigned v){
    if(v > 1)
        return;
    switch(i){
        case 0:
            PORTCbits.RC0 = v;
            break;
        case 1:
            PORTCbits.RC1 = v;
            break;
        case 2:
            PORTCbits.RC2 = v;
            break;
        case 3:
            PORTCbits.RC3 = v;
            break;
        case 4:
            PORTCbits.RC4 = v;
            break;
        case 5:
            PORTCbits.RC5 = v;
            break;
        case 6:
            PORTCbits.RC6 = v;
            break;
        case 7:
            PORTCbits.RC7 = v;
            break;
        default:
            return;
    }
    return;
}

char teclado_matricial_read(){
    
    TRISC = 0x70;
    int i, j;
    for(i = 0; i < 5; i++){
        if(i == 0){            
            __delay_ms(200);
        }
        PORTC_write(i, 1);
        for(j = 0; j < 3; j++){
            if(PORTC_read(j+4)){
                PORTC_write(i, 0);
                return matriz[i][j];
            }
        }
        PORTC_write(i, 0);
    }
    return ' ';
}
