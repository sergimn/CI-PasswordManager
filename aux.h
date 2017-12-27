#ifndef AUX_HH
#define AUX_HH


//Retorna el valor absolut de a
int abs(int a);

//Preve un acces fora de rang en un vector. Si i < 0 && i multiple de max no dona el resultat esperat
int no_overflo(int i, int max);

//Preve sortir-se de la taula de caracters enters.
char no_char_overflo(char c);





#endif
