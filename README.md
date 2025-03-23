# Systemy-Wbudowane
 
/*
 * File:   main.c
 * Author: Bartek
 *
 * Created on March 23, 2025, 9:10 PM
 */

// PIC24FJ128GA010 Configuration Bit Settings

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

#include <xc.h>
#include "p24FJ128GA010.h"

// Constants
#define Fos 8000000
#define PreScalar 256
#define TperS (Fos / 2 / PreScalar)

void setTimer() {
    TMR1 = 0;         // Clear timer register
    PR1 = TperS * 0.1; // Set period for 100 ms delay (0.1 sekundy)
    T1CON = 0x8030;   // Timer1 ON, 256 prescaler
}

void delay() {
    TMR1 = 0;
    while (!IFS0bits.T1IF); // Czekaj na przepełnienie timera
    IFS0bits.T1IF = 0;      // Wyczyść flagę przerwania
}

int main(void) {
    LATA = 0;  // Clear port A
    TRISA = 0; // Set port A as output

    setTimer(); // Initialize timer

    unsigned int mask = 1; // Zaczynamy od pierwszej diody

    while (1) {
        LATA = mask;   // Zapal diodę
        delay();       // Odczekaj chwilę
        mask <<= 1;    // Przesuń bit w lewo

        // Jeśli maska wyjdzie poza 16 bitów (dla 16 diod), wróć do pierwszej
        if (mask == 0) {
            mask = 1;
        }
    }

    return 0;
}
