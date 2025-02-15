#include <stdio.h>
#include <math.h>

long double CalcPol(int coef[], long double x, int high){
    long double result = 0;
    for(int i = 0; i <= high; i++){
        result +=  coef[i]*(pow(x, high-i));
    }
    return result;
}
void bissec(long double x1, long double x2, int coef[], int high){
    long double c = (x1+x2)/2;
    long double resC = CalcPol(coef, c, high);
    if(resC > 0){
        x2 = c;
    }else{
        x1 = c;
    }
    if(resC <= 1.0E-10 && resC >= -1.0E-10){
        if(x1 < x2)
            printf("A raiz encontra-se entre %.15Lf e %.15Lf.\n",x1,x2);
        else
            printf("A raiz encontra-se entre %.15Lf e %.15Lf.\n",x2,x1);
        return;
    }
    if(resC > 0){
        bissec(x1, x2, coef, high);
    }else{
        bissec(x1, x2, coef, high);
    }
    return;
}
int main(){
    int size;
    long double x1, x2; //x1 <= x2
    scanf("%d", &size);
    int coef[size+1];
    for(int i = 0; i <= size; i++)
        scanf("%d", &coef[i]);
    scanf("%Lf %Lf", &x1, &x2);
    long double resX1 = CalcPol(coef, x1, size), resX2 = CalcPol(coef, x2,size);
    if(resX1 > resX2){
        long double temp = x1;
        x1 = x2;
        x2 = temp;
    }
    //printf("sss %d\n", size);
    bissec(x1, x2, coef, size);
    return 0;
}
