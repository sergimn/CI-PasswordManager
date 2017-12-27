#ifndef INTERRUPTS_HH
#define INTERRUPTS_HH

#include"lock.h"


#define threshold 4 //Threshold perque salti al bloqueig despres de x segons

int count = 0;


//Activa les interrupcions relacionades amb la inactivitat
void enable_interrup();

//Desactiva interrupcions relacionades amb inactivitat.
void disab_interup();




#endif
