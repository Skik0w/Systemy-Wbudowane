/* 
 * File:   main.c
 * Author: local
 *
 * Created on March 24, 2025, 11:07 AM
 */

#include "p24FJ128GA010.h"

/*
 * 
 */
int main(int argc, char** argv) {

    LATA = 0;
    TRISA = 0;
    while(1){
        LATA = 0xFFFF;
    }
    return (0);
}

