#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
float calcula(int num)
{
    if (num == 1)
    {
        return 1;
    }
    else
    {
        return 1.0 / num + calcula(num - 1);
    }
}

int main()
{
    int  d;
    float x;
    setlocale(LC_ALL, "Portuguese_Brazil");
    printf("Insira o valor de N: \n");
    scanf("%d", &d);
    x = calcula(d);
    printf("Valor de H em n= %d equivale a: %f\n ",d, x);
    return 0;           
}