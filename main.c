#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <avr/io.h>                    
#include <avr/interrupt.h>
#include <util/delay.h>
#include <math.h>
                                                                     
                                   
#include "bmp085.h"   
#include "hd44780.h" 
                                  
int main(void) {                                               
    long l;                                     
    //double d = 0;                                             
    char printbuff[10];       
    
    LCD_Initalize(); 
    LCD_GoTo(10,0);                                                                        
    LCD_WriteText("aaa");

    //init interrupt
    sei();                                                                     
                                                              
    //init bmp085                              
    bmp085_init();                                                  

    //main loop                                       
    while(1)                    
    {           
        LCD_GoTo(4,0);                                                                        
        LCD_WriteText("TEST"); 
        //get temperature        
        //d = bmp085_gettemperature();
        //dtostrf(d, 10, 2, printbuff);             
        //uart_puts("temperature: "); uart_puts(printbuff);  uart_puts(" C deg"); uart_puts("\r\n");
                      
                     
        //get pressure
        l = bmp085_getpressure();      
        dtostrf(l, 10, 2, printbuff); 
        LCD_GoTo(4,1);                                                                        
        LCD_WriteText(printbuff);
        //ltoa(l, printbuff, 10);        
        //uart_puts("pressure: "); uart_puts(printbuff); uart_puts(" Pa"); uart_puts("\r\n");

        //get altitude
        //d = bmp085_getaltitude();
        //dtostrf(d, 10, 2, printbuff);
        //uart_puts("altitude: "); uart_puts(printbuff); uart_puts(" M"); uart_puts("\r\n");

        //uart_puts("\r\n");
        //_delay_ms(1500);
    }
    
    
}                       