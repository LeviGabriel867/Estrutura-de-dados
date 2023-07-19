#include <stdio.h>
#include <stdlib.h>   
#include <locale.h>
int fatorial(int n) {
  if (n == 0) { 
    return 1;
  } else { 
    return n * fatorial(n-1);
  }
}

int main(){
setlocale(LC_ALL, "Portuguese_Brazil");

int num, Fat;
printf("Número que deseja calcular o fatorial: \n");
scanf("%d", &num);
Fat = fatorial(num);
printf("O fatorial de %d é %d: ", num, Fat);

system ("pause");
return 0;

}