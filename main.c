#include"lock.c"
#include"menu.c"


//Inicialitza els registres de la PIC
void init_PIC();

//Inicialitza els registres referents als timers
void init_timers();

//Inicialitza els registres referents a les interrupcions
void init_interrups();

//Inicialitza els registres referents a l'entrada/sortida de USB
void init_IO();

//Inicialitza els registres referents al GLCD
void init_GLCD();

//Desactiva interrupcions relacionades amb inactivitat.
void disab_interup();


void init_PIC(){

    init_timers();
    init_interrups();
    init_IO();
    init_GLCD();

}



int main(){

    init_PIC();
    manage_lock();
    main_menu();
}
