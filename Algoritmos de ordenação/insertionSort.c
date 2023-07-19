#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
    int codigo;
    float valor;
} Produto;

// Função para realizar o Insertion Sort
void insertionSort(Produto array[], int size)
{

    int i, j;
    Produto chave;

    for (i = 1; i < size; i++)
    {
        chave = array[i]; // Armazena o elemento atual em uma variável temporária

        // Move os elementos maiores que a chave para a direita
        j = i - 1;
        while (j >= 0 && array[j].codigo > chave.codigo)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = chave; // Insere a chave na posição correta
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese_BraziL");
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

    insertionSort(array, size); // Chama a função de ordenação Insertion Sort

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
O algoritmo Insertion Sort é um método simples de ordenação que percorre um vetor e insere cada elemento em sua posição correta, mantendo a parte já ordenada do vetor à esquerda. A lógica do algoritmo pode ser descrita da seguinte maneira:

1. Inicialmente, o algoritmo começa do segundo elemento do vetor, assumindo que o primeiro elemento já está ordenado.
2. Ele guarda o valor desse elemento em uma variável chamada `chave`.
3. Em seguida, compara a `chave` com os elementos anteriores (já ordenados) no vetor.
4. Enquanto houver elementos maiores do que a `chave`, o algoritmo desloca esses elementos uma posição para a direita para abrir espaço para a inserção da `chave`.
5. Quando encontra a posição correta, insere a `chave` nessa posição.
6. Repete o processo para o próximo elemento não ordenado, movendo-se para a direita no vetor.
7. O algoritmo continua até que todos os elementos estejam em suas posições corretas.
8. No final, o vetor estará ordenado.

A complexidade computacional do Insertion Sort é O(n^2), onde n é o número de elementos no vetor. Isso ocorre porque, no pior
caso, o algoritmo precisa comparar e mover cada elemento do vetor várias vezes. Ele possui um loop externo que percorre n
elementos, e um loop interno que pode percorrer até n-1 elementos no pior caso. Assim, a complexidade quadrática surge. No
entanto, em casos médios ou melhores, quando o vetor já está parcialmente ou totalmente ordenado, o algoritmo pode ser mais
eficiente, com uma complexidade próxima a O(n), tornando-se mais rápido em relação a outros algoritmos de ordenação como
Bubble Sort ou Selection Sort.
*/