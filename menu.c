#include"menu.h"



void main_menu(){

    char etiquetes[Ncontes][16] = {"Facebook", "Google", "Hotmail", "Github"} ;  //Com ens referirem a la conta per pantalla
    char usuari[Ncontes][32];     //Nom d'usuari
    char psswds[Ncontes][32];     //Contrassenya

    int i = 0;
    while(1){
        writeNum(0, 15, count); //Mostra el valor del compte enrere en pantalla
        if(amunt == 1){ //RB0 fa baixar en el menu
            __delay_ms(10);
            if(amunt == 1){
                while(amunt);
                i = no_overflo(i-1, Ncontes-1);
                clearGLCD(PGAnt, PGPos, 0, 127); //Borrar la part de les etiquetes en el menu principal
            }
        }
        if(avall == 1){ //RB1 fa pujar en el menu
            __delay_ms(10);
            if(avall == 1){
                while(avall);
                i = no_overflo(i+1, Ncontes-1);
                clearGLCD(PGAnt, PGPos, 0, 127); //Borrar la part de les etiquetes en el menu principal
            }
        }
        if(acceptar == 1){ //RB2 accepta l'etiqueta actual
            __delay_ms(10);
            if(acceptar == 1){
                //KeyboardOUT(usuari[i], psswds[i]); //Treu els caracters pel teclat
            }
        }
        mostrar_menu(etiquetes[no_overflo(i-1, Ncontes-1)], etiquetes[i], etiquetes[no_overflo(i+1, Ncontes-1)]);

    }

}
