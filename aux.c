

int abs(int a){
    if(a < 0) return -a;
    else return a;
}

//Preve un acces fora de rang en un vector. Si i < 0 && i multiple de max no dona el resultat esperat
int no_overflo(int i, int max){
    if(i < 0) return max-abs(i%max);
    else return i%max;
}
