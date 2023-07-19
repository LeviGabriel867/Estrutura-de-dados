#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
    int codigo;
    float valor;
} Produto;

// Função para realizar o Bubble Sort
void bubbleSort(Produto array[], int size)
{
    int i, j;
    Produto temp;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            // Compara os códigos dos produtos adjacentes e realiza a troca, se necessário
            if (array[j].codigo > array[j + 1].codigo)
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL,"Portuguese_Brazil");
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

    bubbleSort(array, size); // Chama a função de ordenação Bubble Sort

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
O algoritmo Bubble Sort funciona da seguinte forma:

1.O algoritmo percorre o vetor várias vezes, comparando elementos adjacentes e trocando-os se estiverem fora de ordem.
2.Ele começa comparando o primeiro e o segundo elemento e, em seguida, o segundo e o terceiro, e assim por diante.
3.Se um elemento maior está à esquerda de um elemento menor, ocorre a troca.
4.O processo continua até o final do vetor.
5.Após uma iteração completa, o maior elemento é movido para a última posição.
6.O algoritmo repete esse processo, percorrendo o vetor novamente, mas dessa vez até a penúltima posição.
7.A cada iteração, o próximo maior elemento é movido para a sua posição correta.
8.O processo continua até que todos os elementos estejam em ordem.

A complexidade computacional do Bubble Sort é O(n^2), onde n é o número de elementos no vetor. Isso ocorre porque, no pior 
caso, o algoritmo precisa realizar comparações e trocas em todas as combinações possíveis de elementos no vetor. Ele possui 
dois loops aninhados, um para percorrer todo o vetor e outro para realizar as comparações e trocas. No entanto, o Bubble Sort 
pode ser eficiente em casos em que o vetor já está parcialmente ordenado, pois ele pode detectar quando nenhum elemento foi t
rocado em uma iteração e, assim, terminar mais cedo.
*/