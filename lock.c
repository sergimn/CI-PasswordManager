#include"main.c" //S'ha de comentar per a compilacio
#include"aux.c"
#include"rutines_GLCD.c"
#include"customGLCD.c"
#include"interrupts.c"

#define amunt RB0
#define avall RB1
#define acceptar RB2


#define NDigitsPIN 4
char PIN[NDigitsPIN+1] = {1, 2, 3, 4, 0x00};


//Gestiona el lock i les interrupcions relacionades amb el lock
void manage_lock();



void manage_lock(){
    disab_interup();
    lock();
    init_interrupts();
}


void lock(){

    int i = 0;


}


