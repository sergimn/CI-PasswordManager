#include"lock.h"


void manage_lock(){
    clearGLCD(0, 7, 0, 127); //Bora la pantalla
    disab_interup();
    lock();
    T0CONbits.TMR0ON = 1; //Activa el compte enrere
    enable_interrup();
}



void lock(){
    int i = 0;
    char usrPIN[NDigitsPIN+1] = {'0', '0', '0', '0', 0x00};
    int correct_psswd = 0;
    while(correct_psswd == 0){
        mostrar_lock(usrPIN, i);
        if(amunt){ //Augmentar numero
            __delay_ms(10);
            if(amunt){
                while(amunt);
                usrPIN[i] = no_char_overflo(usrPIN[i]+1);

            }
        }
        if(avall){ //Augmentar numero
            __delay_ms(10);
            if(avall){
                while(avall);
                usrPIN[i] = no_char_overflo(usrPIN[i]-1);
            }
        }
        if(acceptar){
            __delay_ms(10);
            if(acceptar){
                while(acceptar);
                ++i;
            }
        }
        if(i == NDigitsPIN){
            if(strcmp(usrPIN, PIN) != 0){
                i = 0; //Es torna a començar des del primer digit
                clearGLCD(0, 7, 0, 127); //Es borra la pantalla

                int k; //Es restableix el pin a 0000
                for(k = 0; k < NDigitsPIN; ++k){
                    usrPIN[k] = '0';
                }
                usrPIN[NDigitsPIN] = 0x00;


            }
            else{
                correct_psswd = 1;
                count = 0;
            }
        }
    }
    clearGLCD(0, 7, 0, 127);
}
