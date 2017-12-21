#include"main.c" //S'ha de comentar per a compilacio
#include"lock.c" //S'ha de comentar per a compilacio
#include"aux.c"
#include"rutines_GLCD.c"
#include"menu.c" //S'ha de comentar per a compilacio
#include"customGLCD.c"



int count = 0;



//Desactiva interrupcions relacionades amb inactivitat.
void disab_interup();


void interrupt low_priority i_baixes(void){ // interrupcions baixes
    if (INTCONbits.TMR0IE == 1 && INTCONbits.TMR0IF == 1) {
        ++count;
        INTCONbits.TMR0IF = 0;
   }
}

void interrupt i_altes(void){ //interrupcions altes

}
