#ifndef MENU_HH
#define MENU_HH




#include"auxiliars.h"
#include"customGLCD.h"
#include"GLCD.h"
#include"interrupts.h"

//Falta el USB.h


#define Ncontes 4 //Nombre de contes que contindra el dispositiu


#define PGAnt 2         //Pagina del GLCD en el que l'etiqueta previa s'imprimira
#define PGAct PGAnt+1   //Pagina del GLCD en el que l'etiqueta actual s'imprimira
#define PGPos PGAct+1   //Pagina del GLCD en el que l'etiqueta posterior s'imprimira


//Mostra el menu i permet navegar entre les etiquetes
void main_menu();


#endif
