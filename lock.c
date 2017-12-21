#include"main.c" //S'ha de comentar per a compilacio
#include"aux.c"
#include"rutines_GLCD.c"
#include"customGLCD.c"
#include"interrupts.c"

#define amunt RB0
#define avall RB1
#define acceptar RB2


#define NDigitsPIN 4
char PIN[NDigitsPIN+1] = {'1', '2', '3', '4', 0x00};


//Gestiona el lock i les interrupcions relacionades amb el lock
void manage_lock();



void manage_lock(){
    disab_interup();
    lock();
    enable_interrup();
}



void lock(){
    int i = 0;
    char usrPIN[NDigitsPIN+1] = {'0', '0', '0', '0', 0x00};
    int correct_psswd = 0;
    while(correct_psswd == 0){
        mostrar_lock(usrPIN[], i);
        if(amunt){ //Augmentar numero
            __delay_ms(10);
            if(amunt){
                while(amunt);
                no_char_overflo(usrPIN[i]+1);

            }
        }
        if(avall){ //Augmentar numero
            __delay_ms(10);
            if(avall){
                while(avall);
                no_char_overflo(usrPIN[i]-1);
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
            if(PIN != usrPIN){
                i = 0;
                clearGLCD(0, 7, 0, 127);
            }
            else{
                correct_psswd = 1;
                count = 0;
            }
        }
    }
}




