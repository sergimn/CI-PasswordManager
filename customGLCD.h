#ifndef CUSTOMGLCD_HH
#define CUSTOMGLCD_HH

#include"GLCD.h"
#include"menu.h"
#include<string.h>

//Imprimeix per pantalla les etiquetes anterior, actual i posterior a la seleccionada.
void mostrar_menu(char ant[], char act[], char pos[]);

//Imprimeix la i posicio del PIN introduit per l'usuari.
void mostrar_lock(char customPIN[], int i);

//Activa la GLCD permetent que els pixels siguin modificats
void enable_GLCD();

//Desactiva la GLCD prohibint que els pixels siguin modificats
void disable_GLCD();


#endif
