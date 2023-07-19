#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#define MAX_SIZE 5

typedef struct
{
    int data[MAX_SIZE];
    int size;
} ListaOrdenada;

void create(ListaOrdenada *l)
{
    l->size = 0;
}

bool add(ListaOrdenada *l, int valor)
{
    if (l->size == MAX_SIZE)
    {
        return false; // Lista cheia
    }

    int i = l->size - 1;
    while (i >= 0 && l->data[i] > valor)
    {
        l->data[i + 1] = l->data[i];
        i--;
    }

    l->data[i + 1] = valor;
    l->size++;

    return true;
}

bool remove_element(ListaOrdenada *l, int valor)
{
    int i = 0;
    while (i < l->size && l->data[i] != valor)
    {
        i++;
    }

    if (i == l->size)
    {
        return false; // Elemento não encontrado
    }

    for (int j = i; j < l->size - 1; j++)
    {
        l->data[j] = l->data[j + 1];
    }

    l->size--;

    return true;
}

int size(ListaOrdenada *l)
{
    return l->size;
}

int linearSearch(ListaOrdenada *l, int valor)
{
    for (int i = 0; i < l->size; i++)
    {
        if (l->data[i] == valor)
        {
            return i; // Elemento encontrado
        }
    }

    return -1; // Elemento não encontrado
}

int binarySearch(ListaOrdenada *l, int valor)
{
    int start = 0;
    int end = l->size - 1;

    while (start <= end)
    {
        int next = (start + end) / 2;

        if (l->data[next] == valor)
        {
            return next; // Elemento encontrado
        }

        if (l->data[next] < valor)
        {
            start = next + 1;
        }
        else
        {
            end = next - 1;
        }
    }

    return -1; // Elemento não encontrado
}

bool isFull(ListaOrdenada *l)
{
    return l->size == MAX_SIZE;
}

bool isEmpty(ListaOrdenada *l)
{
    return l->size == 0;
}

void clear(ListaOrdenada *l)
{
    l->size = 0;
}

void printList(ListaOrdenada *l)
{
    if (isEmpty(l))
    {
        printf("A lista está vazia.\n");
    }
    else
    {
        printf("Valores da lista: ");

        for (int i = 0; i < l->size; i++)
        {
            printf("%d ", l->data[i]);
        }

        printf("\n");
    }
}

void exibirMenu()
{
    printf("--- Menu Lista Ordenada ---\n");
    printf("1. Adicionar elemento\n");
    printf("2. Remover elemento\n");
    printf("3. Tamanho da lista\n");
    printf("4. Buscar elemento (busca linear)\n");
    printf("5. Buscar elemento (busca binária)\n");
    printf("6. Verificar se a lista está cheia\n");
    printf("7. Verificar se a lista está vazia\n");
    printf("8. Limpar a lista\n");
    printf("0. Sair\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    ListaOrdenada l;
    int opcao, valor;

    create(&l);

    do
    {
        exibirMenu();
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o valor a adicionar: ");
            scanf("%d", &valor);
            if (add(&l, valor))
            {
                printf("Elemento adicionado com sucesso.\n");
            }
            else
            {
                printf("Falha ao adicionar elemento. Lista cheia.\n");
            }
            break;
        case 2:
            printf("Digite o valor a remover: ");
            scanf("%d", &valor);
            if (remove_element(&l, valor))
            {
                printf("Elemento removido com sucesso.\n");
            }
            else
            {
                printf("Elemento não encontrado ou falha ao remover.\n");
            }
            break;
        case 3:
            printf("Tamanho da lista: %d\n", size(&l));
            break;
        case 4:
            printf("Digite o valor a buscar: ");
            scanf("%d", &valor);
            int posicaoLinear = linearSearch(&l, valor);
            if (posicaoLinear != -1)
            {
                printf("Elemento encontrado na posição %d (busca linear).\n", posicaoLinear);
            }
            else
            {
                printf("Elemento não encontrado.\n");
            }
            break;
        case 5:
            printf("Digite o valor a buscar: ");
            scanf("%d", &valor);
            int posicaoBinaria = binarySearch(&l, valor);
            if (posicaoBinaria != -1)
            {
                printf("Elemento encontrado na posição %d (busca binária).\n", posicaoBinaria);
            }
            else
            {
                printf("Elemento não encontrado.\n");
            }
            break;
        case 6:
            if (isFull(&l))
            {
                printf("A lista está cheia.\n");
            }
            else
            {
                printf("A lista não está cheia.\n");
            }
            break;
        case 7:
            if (isEmpty(&l))
            {
                printf("A lista está vazia.\n");
            }
            else
            {
                printf("A lista não está vazia.\n");
            }
            break;
        case 8:
            clear(&l);
            printf("Lista limpa.\n");
            break;
        case 0:
            printf("Encerrando o programa.\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }

        printList(&l);
    } while (opcao != 0);

    return 0;
}
/*Complexidade das funções:

1. Função `create`: Complexidade O(1). Apenas atribui o valor 0 ao campo `size` da estrutura `ListaOrdenada`.

2. Função `add`: Complexidade O(n), onde n é o tamanho atual da lista. No pior caso, quando o elemento a ser adicionado é o menor de todos os elementos na lista, será necessário percorrer a lista inteira para encontrar a posição correta de inserção.

3. Função `remove_element`: Complexidade O(n), onde n é o tamanho atual da lista. No pior caso, quando o elemento a ser removido é o último da lista, será necessário percorrer a lista inteira para encontrar o elemento.

4. Função `size`: Complexidade O(1). Apenas retorna o valor do campo `size` da estrutura `ListaOrdenada`.

5. Função `linearSearch`: Complexidade O(n), onde n é o tamanho atual da lista. No pior caso, quando o elemento não está presente na lista, será necessário percorrer a lista inteira.

6. Função `binarySearch`: Complexidade O(log n), onde n é o tamanho atual da lista. O algoritmo de busca binária divide a lista pela metade a cada iteração, reduzindo o espaço de busca pela metade. Portanto, a complexidade é logarítmica em relação ao tamanho da lista.

7. Função `isFull`: Complexidade O(1). Apenas verifica se o campo `size` da estrutura `ListaOrdenada` é igual a `MAX_SIZE`.

8. Função `isEmpty`: Complexidade O(1). Apenas verifica se o campo `size` da estrutura `ListaOrdenada` é igual a zero.

9. Função `clear`: Complexidade O(1). Apenas atribui o valor 0 ao campo `size` da estrutura `ListaOrdenada`.

10. Função `printList`: Complexidade O(n), onde n é o tamanho atual da lista. Percorre a lista e imprime todos os elementos.

11. Função `exibirMenu`: Complexidade O(1). Apenas imprime um conjunto fixo de mensagens.

12. Função `main`: A complexidade depende das operações escolhidas pelo usuário. Cada operação chama uma das funções mencionadas acima, portanto a complexidade será a complexidade da função chamada.
*/