/*
 * File:   calc.c
 * Author: Mateus
 *
 * Created on 12 de Março de 2018, 14:08
 */


#include <xc.h>
#include "lcd.h"
#include "teclado_matricial_4x3.h"
#include <stdio.h>

void sum(){
 
    int n1 = 0, n2 = 0;
    char result[8];
    int op = 0;
    while(1){
        char c = teclado_matricial_read();
        if(c != ' '){
            if((c != '+') && (c != '=')){
                if((op == 0)){
                    n1 = n1 * 10 + (c - '0');
                }
                else{
                    n2 = n2 * 10 + (c - '0');
                }
                send_msg(c);
            }
            else if((c == '+') && (op == 0)){
                send_msg(c);
                op = 1;
            }
            if(c == '='){
                send_msg(c);
                sprintf(result, "%d", n1 + n2);
                write_LCD(result);
                return;
            }
        }
    }
}