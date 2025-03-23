/*
 * File:   main.c
 * Author: Bartek
 *
 * Created on March 23, 2025, 9:10 PM
 */

// PIC24FJ128GA010 Configuration Bit Settings

// 'C' source line config statements


// PIC24FJ128GA010 Configuration Bit Settings

// 'C' source line config statements

// CONFIG2
#pragma config POSCMOD = HS             // Primary Oscillator Select (HS Oscillator mode selected)
#pragma config OSCIOFNC = OFF           // Primary Oscillator Output Function (OSC2/CLKO/RC15 functions as CLKO (FOSC/2))
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor (Clock switching and Fail-Safe Clock Monitor are disabled)
#pragma config FNOSC = PRI              // Oscillator Select (Primary Oscillator (XT, HS, EC))
#pragma config IESO = ON                // Internal External Switch Over Mode (IESO mode (Two-Speed Start-up) enabled)

// CONFIG1
#pragma config WDTPS = PS32768          // Watchdog Timer Postscaler (1:32,768)
#pragma config FWPSA = PR128            // WDT Prescaler (Prescaler ratio of 1:128)
#pragma config WINDIS = ON              // Watchdog Timer Window (Standard Watchdog Timer enabled,(Windowed-mode is disabled))
#pragma config FWDTEN = ON              // Watchdog Timer Enable (Watchdog Timer is enabled)
#pragma config ICS = PGx2               // Comm Channel Select (Emulator/debugger uses EMUC2/EMUD2)
#pragma config GWRP = OFF               // General Code Segment Write Protect (Writes to program memory are allowed)
#pragma config GCP = OFF                // General Code Segment Code Protect (Code protection is disabled)
#pragma config JTAGEN = OFF             // JTAG Port Enable (JTAG port is disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#include "p24FJ128GA010.h"


#define Fos 8000000
#define PreScalar 256
#define TperS Fos / 2 /PreScalar

void setTimer(){
    TMR1 = 0;
    PR1 = 0xFFFF;
    T1CON = 0x8030; // 0b 1000 0000 0011 0000
}

int main(void) {
    LATA = 0;
    TRISA = 0;
    
    while(1)
    {
        LATA = ~LATA; // 0b 1111 1111 1111 1111
        while(TMR1 < TperS * 0.5) {
            
        }
        TMR1 = 0;
    }
    
    
    return (0);
}
