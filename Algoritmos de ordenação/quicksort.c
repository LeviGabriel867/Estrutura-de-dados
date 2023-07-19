#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
    int codigo;
    float valor;
} Produto;

// Função para particionar o array e retornar o índice do pivo
int partition(Produto array[], int inicio, int fim)
{
    int pivo = array[fim].codigo; // Seleciona o último elemento como pivo
    int i = inicio - 1;           // Índice do elemento menor

    for (int j = inicio; j <= fim - 1; j++)
    {
        if (array[j].codigo < pivo)
        {
            i++;
            Produto temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    Produto temp = array[i + 1];
    array[i + 1] = array[fim];
    array[fim] = temp;

    return (i + 1); // Retorna o índice do pivo
}

// Função recursiva para ordenar o array usando o algoritmo Quick Sort
void quickSort(Produto array[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int pivo = partition(array, inicio, fim); // Encontra o pivo

        quickSort(array, inicio, pivo - 1); // Ordena a metade esquerda do pivo
        quickSort(array, pivo + 1, fim);    // Ordena a metade direita do pivo
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

    quickSort(array, 0, size - 1); // Chama a função de ordenação Quick Sort

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
O algoritmo Quick Sort funciona da seguinte forma:

1.Seleciona um elemento do vetor como pivo. Neste caso, usamos o último elemento do vetor.
2.Particiona o vetor em duas subpartes, colocando todos os elementos menores que o pivo à esquerda e todos os elementos maiores à direita.
3.Recursivamente, repete o processo de partição para as duas metades do vetor.
4.A recursão termina quando cada subvetor tiver tamanho 1 ou 0, ou seja, quando o vetor estiver completamente ordenado.
A complexidade computacional do Quick Sort depende da escolha do pivo e do balanceamento das partições. No pior caso, em que o
pivo escolhido é sempre o menor ou o maior elemento do vetor, a complexidade é O(n^2). No entanto, em média, o Quick Sort
possui uma complexidade de tempo esperada de O(n log n), tornando-o um dos algoritmos de ordenação mais eficientes.
O Quick Sort é amplamente utilizado na prática devido à sua eficiência e desempenho geralmente superior a outros algoritmos de
ordenação.
*/