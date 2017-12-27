#include"aux.h"

int abs(int a){
    if(a < 0) return -a;
    else return a;
}

int no_overflo(int i, int max){
    if(i < 0) return max-abs(i%max);
    else return i%max;
}


char no_char_overflo(char c){
    return '0'+ no_overflo(c-'0', 10);
}
