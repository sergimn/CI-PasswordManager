#include"main.c" //S'ha de comentar per a compilacio
#include"lock.c" //S'ha de comentar per a compilacio
#include"aux.c"
#include"rutines_GLCD.c"
#include"customGLCD.c"



#define Ncontes 4 //Nombre de contes que contindra el dispositiu
#define RB0 PORTBbits.RB0
#define RB1 PORTBbits.RB1
#define RB2 PORTBbits.RB2

#define PGAnt 2         //Pagina del GLCD en el que l'etiqueta previa s'imprimira
#define PGAct PGAnt+1   //Pagina del GLCD en el que l'etiqueta actual s'imprimira
#define PGPos PGAct+1   //Pagina del GLCD en el que l'etiqueta posterior s'imprimira




void main_menu(){

    char etiquetes[Ncontes][16] = {"Facebook", "Google", "Hotmail", "Github"} ;  //Com ens referirem a la conta per pantalla
    char usuari[Ncontes][32];     //Nom d'usuari
    char psswds[Ncontes][32];     //Contrassenya

    int i = 0;
    while(1){
        if(RB0 == 1){ //RB0 fa baixar en el menu
            __delay_ms(10);
            if(RB0 == 1){
                while(RB0);
                i = no_overflo(i-1, Ncontes-1);
                clearGLCD(PGAnt, PGPos, 0, 127); //Borrar la part de les etiquetes en el menu principal
            }
        }
        if(RB1 == 1){ //RB1 fa pujar en el menu
            __delay_ms(10);
            if(RB1 == 1){
                while(RB0);
                i = no_overflo(i+1, Ncontes-1);
                clearGLCD(PGAnt, PGPos, 0, 127); //Borrar la part de les etiquetes en el menu principal
            }
        }
        if(RB2 == 1){ //RB2 accepta l'etiqueta actual
            __delay_ms(10);
            if(RB2 == 1){
                KeyboardOUT(usuari[i], psswds[i]); //Treu els caracters pel teclat
            }
        }
        mostrar_menu(etiquetes[no_overflo(i-1, Ncontes-1)], etiquetes[i], etiquetes[no_overflo(i+1, Ncontes-1)]);






        //Mostrar menu, permetre seleccionar...
    }

}
