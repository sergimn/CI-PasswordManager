#ifndef CUSTOM_ROM_HH
#define CUSTOM_ROM_HH

#include"interrupts.h"

//Escriu a en l'adreça de memoria EEPROM addr
void escriure_byte(char a, byte addr);

//Escriu str a partir de l'adreça addr. str ha d'acabar amb 0x00.
void escriure_string(char *str, byte addr);

//Retorna el byte que hi ha a la adreça addr.
char llegir_byte(int addr);

//Posa la string que hi ha a partir de addr a str, acaba amb 0x00
//S'ha de reservar memoria a str ABANS de cridar a la funció (fent servir un buffer, vaja)
void llegir_string(char *str, int addr);

#endif
