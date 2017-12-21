#include"lock.c" //S'ha de comentar per a compilacio
#include"aux.c"
#include"GLCD.c"
#include"rutines_GLCD.c"
#include"interrupts.c"



//Inicialitza els registres referents a l'entrada/sortida de USB
void init_IO();

//Inicialitza els registres referents als timers
void init_timers();

//Inicialitza els registres referents a les interrupcions
void init_interrupts();

//Inicialitza els registres referents al GLCD
void init_GLCD();

//Inicialitza els registres de la PIC
void init_PIC();



void init_IO(){
    PORTB = 0;
    TRISB = 0x07; //habilitem els pins de les 3 interrupcions
    PORTD = 0;
    TRISD = 0x00; // GLCD
    ADCON1 = 0X0F; // Digitalitzar registres
}

void init_timers(){
    T0CONbits.TMR0ON = 0; // enable timer 0
    T0CONbits.T08BIT = 0; // timer de 16 bits
    T0CONbits.T0CS = 0; // clock del PIC (8MHz/4)
    T0CONbits.T0SE = 1; // increment on rising edge del clock
    T0CONbits.PSA = 0; //prescaler assignat
    T0CONbits.T0PS2 = 1; // bit 2 prescaler
    T0CONbits.T0PS1 = 1; // bit 1 prescaler  Prescaler = 128
    T0CONbits.T0PS0 = 0; // bit 0 prescaler

    INTCONbits.TMR0IF = 0; // Flag del timer a 0
    INTCONbits.TMR0IE = 1; // Enable bit de la interrupci� del timer0
    INTCON2bits.TMR0IP = 0; //Low priority interrupt

    TMR0 = 0xC2F7; // 49511 en decimal, configuracio perque salti la interrupt cada 1 segon
}


void init_interrupts(){
//INT0 -> BOT� ACCEPT, INT1 -> BOT� 1, INT2 -> BOT� 2	
    RCONbits.IPEN = 1; // Enable priority
    INTCONbits.GIE = 1; // Enable high priority interrupts
    INTCONbits.PEIE = 1; // Enable low priority peripheral interrupts

    //BOT� ACCEPT (int0)
    INTCONbits.INT0IE = 1; // interrupcio activada
    INTCONbits.INT0IF = 0; //flag a 0
    //BOT� 1 (int1)
    INTCON3bits.INT1IE = 1; // interrupcio activada
    INTCON3bits.INT1IF = 0; //flag a 0
    INTCON3bits.INT1IP = 1; //prioritat alta
    //BOT� 2 (int2)
    INTCON3bits.INT2IE = 1; // interrupcio activada
    INTCON3bits.INT2IF = 0; //flag a 0
    INTCON3bits.INT2IP = 1; //prioritat alta
}

void init_GLCD(){
	GLCDinit(); //incloure GLCD.h
	clearGLCD(0, 7, 0, 127);
}


void init_PIC(){
	
    init_IO();
    init_timers();
    init_interrupts();
    init_GLCD();

}


int main(){
    init_PIC();
    manage_lock();
    main_menu();
}
