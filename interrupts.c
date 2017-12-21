#include"main.c" //S'ha de comentar per a compilacio
#include"lock.c" //S'ha de comentar per a compilacio
#include"aux.c"
#include"rutines_GLCD.c"
#include"menu.c" //S'ha de comentar per a compilacio
#include"customGLCD.c"

#define threshold //Threshold perque salti al bloqueig despres de x segons

int count = 0;

void enable_interrup();

//Desactiva interrupcions relacionades amb inactivitat.
void disab_interup();



void enable_interrup(){
    INTCONbits.INT0IE = 1;
    INTCON3bits.INT1IE = 1;
    INTCON3bits.INT2IE = 1;
    INTCONbits.GIEH = 1
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

void interrupt i_altes(void){ //interrupcions altes // caldria fer control de rebots 
	if (INTCONbits.INT0IE == 1 && INTCONbits.INT0IF == 1) {
		count = 0;
		INTCONbits.INT0IF = 0;
	}
	if (INTCON3bits.INT1IE == 1 && INTCON3bits.INT1IF == 1) {
		count = 0;
		INTCON3bits.INT1IF = 0;
	}
	if (INTCON3bits.INT2IE == 1 && INTCON3bits.INT2IF == 1) {
		count = 0;
		INTCON3bits.INT2IF = 0;
	}
}
