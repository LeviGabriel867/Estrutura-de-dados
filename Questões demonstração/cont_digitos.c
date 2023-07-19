#include <stdio.h>
int main()
{
    int num=0;
    int contador=0;
    printf("Insira um numero inteiro: ");
    scanf("%d", &num);
    if (num == 0)
    {
        contador = 1;
    }
    else
        while (num != 0)
        {
            contador++;
            num = num/10;
        }
    printf("O numero %d possui %d digitos: ", num, contador);
    return 0;
}