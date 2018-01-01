#ifndef LOCK_HH
#define LOCK_HH

#include"auxiliars.h"
#include"menu.h"
#include"interrupts.h"
#include"customGLCD.h"
#include"GLCD.h"


#define amunt PORTBbits.RB0
#define avall PORTBbits.RB1
#define acceptar PORTBbits.RB2
#define NDigitsPIN 4


char PIN[NDigitsPIN+1] = {'0', '0', '0', '0', 0x00};




//Gestiona el lock i les interrupcions relacionades amb el lock
void manage_lock();

//Bloqueja el sistema en espera d'entrada de un pin correcte
void lock();




#endif
