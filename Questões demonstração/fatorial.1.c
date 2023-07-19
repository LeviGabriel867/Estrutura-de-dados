#include <stdio.h>
int fatorial(int num){
    if(num==0){
        return 1;
    }else{
        return num * fatorial(num-1);
    }
}
float logica(int n){
    if(n==1){
        return 1.0;
    }else{
        return logica(n)/n + (float) fatorial(n)/n;
    }
}

int main(){;
    int N;
    printf("Insira o número N: ");
    scanf("%d", &N);
    printf("S = : %f\n", logica(N));
    return 0;
}