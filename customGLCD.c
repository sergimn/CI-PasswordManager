#include"main.c" //S'ha de comentar per a compilacio
#include"lock.c" //S'ha de comentar per a compilacio
#include"aux.c"
#include"GLCD.c"
#include"menu.c" //S'ha de comentar per a compilacio

//Imprimeix per pantalla les etiquetes anterior, actual i posterior a la seleccionada.
void mostrar_menu(char ant[], char act[], char pos[]);

//Imprimeix la i posicio del PIN introduit per l'usuari.
void mostrar_lock(char customPIN[], int i);



void mostrar_menu(char ant[], char act[], char pos[]){
    int i;
    for(i = 0; i < strlen(ant); ++i){ //Mostra la etiqueta anterior
        putch(PGAnt, i, ant[i]);
    }
    for(i = 0; i < strlen(act); ++i){ //Mostra la etiqueta actual
        putch(PGAct, i, act[i]);
    }
    for(i = 0; i < strlen(pos); ++i){ //Mostra la etiqueta posterior
        putch(PGPos, i, pos[i]);
    }

}


void mostrar_lock(char customPIN[], int i){
    //Pagina 2, comença a partir del byte 6
    putch(2, 6+i*2, customPIN[i]);
}
