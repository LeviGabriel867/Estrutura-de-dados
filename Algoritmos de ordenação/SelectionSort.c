#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
    int codigo;
    float valor;
} Produto;

// Função para realizar o Selection Sort
void selectionSort(Produto array[], int size)
{
    int i, j, indice_min;
    Produto temp;

    for (i = 0; i < size - 1; i++)
    {
        indice_min = i;

        // Encontra o índice do menor elemento não ordenado
        for (j = i + 1; j < size; j++)
        {
            if (array[j].codigo < array[indice_min].codigo)
            {
                indice_min = j;
            }
        }

        // Troca o elemento atual com o menor elemento encontrado
        temp = array[i];
        array[i] = array[indice_min];
        array[indice_min] = temp;
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int size;
    printf("Digite o tamanho do vetor de produtos: ");
    scanf("%d", &size);

    Produto *array = (Produto *)malloc(size * sizeof(Produto));

    // Preenche o vetor de produtos com os códigos e valores informados pelo usuário
    for (int i = 0; i < size; i++)
    {
        printf("Digite o código do produto %d: ", i + 1);
        scanf("%d", &(array[i].codigo));
        printf("Digite o valor do produto %d: ", i + 1);
        scanf("%f", &(array[i].valor));
    }

    selectionSort(array, size); // Chama a função de ordenação Selection Sort

    printf("\nVetor ordenado:\n");
    // Exibe os produtos ordenados pelo código
    for (int i = 0; i < size; i++)
    {
        printf("Código: %d, Valor: %.2f\n", array[i].codigo, array[i].valor);
    }

    free(array); // Libera a memória alocada para o vetor de produtos

    return 0;
}
/*
O algoritmo Selection Sort funciona da seguinte forma:

1. O algoritmo percorre o vetor e, em cada iteração, seleciona o menor elemento não ordenado.
2.Ele mantém um índice indice_min que aponta para o elemento mínimo encontrado até o momento.
3.Em cada iteração do loop externo, o algoritmo compara o elemento atual com o elemento mínimo atualizado no loop interno.
4.Se um elemento menor é encontrado, o indice_min é atualizado.
5.No final do loop interno, o elemento mínimo é trocado com o elemento na posição atual.
6.O processo é repetido até que todo o vetor esteja ordenado.

A complexidade computacional do Selection Sort é O(n^2), onde n é o número de elementos no vetor. Isso ocorre porque, no pior
caso, o algoritmo precisa comparar e trocar elementos várias vezes para cada elemento do vetor. Ele possui um loop externo que
percorre n elementos e, para cada elemento, um loop interno que percorre n-1 elementos no pior caso. Assim, a complexidade
uadrática surge. Mesmo que o vetor já esteja parcialmente ou totalmente ordenado, o algoritmo ainda precisa realizar as comparações
e trocas necessárias.
*/