#include"customROM.h"


void escriure_byte(char a, byte addr){
    EEADR = addr; //Adreça
    EEDATA = a; //Dades
    EECON2 = 0x55; //Especificació (no tocar)
    EECON2 = 0xAA; //Especificació (no tocar)
    
    EECON1bits.WR = 1; //COMENÇAR ESCRIPTURA
    
    if(EECON1bits.WRERR == 1){ //Error en la escriptura pg93
        //Control d'errors en la escriptura
    }
    if(PIR2bits.EEIF == 1){ //La escriptura s'ha completat
        PIR2bits.EEIF = 0;
    }
    
    
}

void escriure_string(char *str, byte addr){
    disab_interup();
    EECON1bits.EEPGD = 0; //EEPROM memory
    EECON1bits.CFGS =  0; //EEPROM memory
    EECON1bits.FREE = 0; //Fer un write i no un erase
    EECON1bits.WREN = 1; //Habilitar escriptures

    int i = 0;
    while(*(str+i) != 0x00){
        escriure_byte(*(str+i), addr+i);
        ++i;
    }
    
    EECON1bits.WREN = 0; //Deshabilitar escriptures

    enable_interrup();
}


char llegir_byte(int addr){
    EEADR = addr;
    EECON1bits.RD = 1;
    return EEDATA;
}

void llegir_string(char *str, int addr){
    disab_interup();
    EECON1bits.EEPGD = 0; //EEPROM memory
    EECON1bits.EEPGD = 0; //EEPROM memory
    int i = 0;
    char temp = 1;
    while(temp != 0x00){
        temp = llegir_byte(addr+i);
        *(str+i) = temp;
        
        ++i
    }
    
    enable_interrup();
}
