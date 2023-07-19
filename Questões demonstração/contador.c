#include <stdio.h>
int contador(float altura1, float altura2)
{
    int contador = 0;   
    while (altura2 <= altura1){
        altura1 += 0.02;
        altura2 += 0.03;
        contador++;
    }
    return contador;
}

int main()
{
    float francisco = 1.6;
    float jose = 1.4;
    int x;
    x = contador(francisco, jose);
    printf("José será maior que Francisco em %d anos\n", x);
    return 0;
}
