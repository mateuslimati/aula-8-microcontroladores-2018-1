/*
 * File:   main.c
 * Author: Mateus
 *
 * Created on 26 de Fevereiro de 2018, 22:19
 */

#include "config_bits.h"
#include "lcd.h"
#include "calc.h"

void main(){
 
    init_LCD();
    set_cursor(0,0);
    write_LCD("Calculadora PET");
    set_cursor(1,0);
    sum();
    while(1);
    
}