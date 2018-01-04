#include"interrupts.h"




void enable_interrup(){
    INTCONbits.INT0IE = 1;
    INTCON3bits.INT1IE = 1;
    INTCON3bits.INT2IE = 1;
    INTCONbits.GIEH = 1;
}

void disab_interup(){
    INTCONbits.INT0IE = 0;
    INTCON3bits.INT1IE = 0;
    INTCON3bits.INT2IE = 0;
    INTCONbits.GIEH = 0;

}


void interrupt low_priority i_baixes(void){ // interrupcions baixes
    if (INTCONbits.TMR0IE == 1 && INTCONbits.TMR0IF == 1) {
        ++count;
        INTCONbits.TMR0IF = 0;
        if (count == threshold) manage_lock();
   }
}

void interrupt i_altes(void){ //interrupcions altes. Caldria fer control de rebots
        if (INTCONbits.INT0IE == 1 && INTCONbits.INT0IF == 1) {
        	_delay_ms(10);
        	if(INTCONbits.INT0IE == 1){
		        count = 0;
		        INTCONbits.INT0IF = 0;
       		}
       	}
        if (INTCON3bits.INT1IE == 1 && INTCON3bits.INT1IF == 1) {
        	_delay_ms(10);
        	if(INTCON3bits.INT1IE == 1){
		        count = 0;
		        INTCON3bits.INT1IF = 0;
        	}
    	}
        if (INTCON3bits.INT2IE == 1 && INTCON3bits.INT2IF == 1) {
        	_delay_ms(10);
        	if(INTCON3bits.INT2IE == 1){
		        count = 0;
		        INTCON3bits.INT2IF = 0;
        	}
    	}
}
