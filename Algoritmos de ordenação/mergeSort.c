#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
typedef struct
{
    int codigo;
    float valor;
} Produto;

// Função para combinar duas metades ordenadas do array em uma única metade ordenada
void merge(Produto array[], int inicio, int meio, int fim)
{
    int tamanho_esquerda = meio - inicio + 1;
    int tamanho_direita = fim - meio;

    // Cria arrays auxiliares para armazenar as metades esquerda e direita
    Produto *esquerda = (Produto *)malloc(tamanho_esquerda * sizeof(Produto));
    Produto *direita = (Produto *)malloc(tamanho_direita * sizeof(Produto));

    int i, j, k;

    // Copia os elementos para os arrays auxiliares
    for (i = 0; i < tamanho_esquerda; i++)
    {
        esquerda[i] = array[inicio + i];
    }
    for (j = 0; j < tamanho_direita; j++)
    {
        direita[j] = array[meio + 1 + j];
    }

    // Combina os elementos dos arrays auxiliares de volta ao array original, em ordem crescente
    i = 0;      // Índice para o array da esquerda
    j = 0;      // Índice para o array da direita
    k = inicio; // Índice para o array original

    while (i < tamanho_esquerda && j < tamanho_direita)
    {
        if (esquerda[i].codigo <= direita[j].codigo)
        {
            array[k] = esquerda[i];
            i++;
        }
        else
        {
            array[k] = direita[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes do array esquerdo, se houver
    while (i < tamanho_esquerda)
    {
        array[k] = esquerda[i];
        i++;
        k++;
    }

    // Copia os elementos restantes do array direito, se houver
    while (j < tamanho_direita)
    {
        array[k] = direita[j];
        j++;
        k++;
    }

    // Libera a memória alocada para os arrays auxiliares
    free(esquerda);
    free(direita);
}

// Função recursiva para dividir o array em metades e chamar a função merge para combinar e ordenar
void mergeSort(Produto array[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(array, inicio, meio);  // Ordena a metade esquerda do array
        mergeSort(array, meio + 1, fim); // Ordena a metade direita do array

        merge(array, inicio, meio, fim); // Combina as duas metades ordenadas
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

    mergeSort(array, 0, size - 1); // Chama a função de ordenação Merge Sort

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
O algoritmo Merge Sort funciona da seguinte forma:

1.O vetor é dividido recursivamente pela metade até que cada subvetor tenha apenas um elemento.
2.Em seguida, os subvetores são combinados em ordem crescente.
3.Durante a combinação, os elementos dos subvetores são comparados e colocados em ordem em um novo vetor auxiliar.
4.Esse processo é repetido até que todos os subvetores sejam combinados e o vetor original esteja completamente ordenado.

A complexidade computacional do Merge Sort é O(n log n), onde n é o número de elementos no vetor. Isso ocorre porque o algoritmo
 divide o vetor ao meio a cada recursão, e o número de divisões é logarítmico em relação ao tamanho do vetor. Em seguida, a
 combinação dos subvetores ocorre em tempo linear. Portanto, a combinação de log n camadas, cada uma com tempo linear,
 resulta em uma complexidade total de n log n. O Merge Sort é um algoritmo eficiente para ordenar grandes conjuntos de dados e
 possui uma performance estável em todos os casos.
*/