#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct No
{
    int valor;
    struct No *next;
    struct No *previous;
} No;

typedef struct ListaCircular
{
    No *start;
    No *end;
} ListaCircular;

void create(ListaCircular *l)
{
    l->start = NULL;
    l->end = NULL;
}

int add(ListaCircular *l, int valor)
{
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL)
    {
        printf("Falha ao adicionar elemento. Memória insuficiente.\n");
        return 0;
    }

    novoNo->valor = valor;

    if (l->start == NULL)
    {
        novoNo->next = novoNo;
        novoNo->previous = novoNo;
        l->start = novoNo;
        l->end = novoNo;
    }
    else
    {
        novoNo->next = l->start;
        novoNo->previous = l->end;
        l->end->next = novoNo;
        l->start->previous = novoNo;
        l->end = novoNo;
    }

    return 1;
}

int removerElemento(ListaCircular *l, int valor)
{
    if (l->start == NULL)
    {
        printf("A lista circular está vazia.\n");
        return 0;
    }

    No *atual = l->start;
    do
    {
        if (atual->valor == valor)
        {
            if (atual == l->start && atual == l->end)
            {
                l->start = NULL;
                l->end = NULL;
            }
            else if (atual == l->start)
            {
                l->start = atual->next;
                l->start->previous = l->end;
                l->end->next = l->start;
            }
            else if (atual == l->end)
            {
                l->end = atual->previous;
                l->end->next = l->start;
                l->start->previous = l->end;
            }
            else
            {
                atual->previous->next = atual->next;
                atual->next->previous = atual->previous;
            }
            free(atual);
            return 1;
        }
        atual = atual->next;
    } while (atual != l->start);

    printf("Elemento não encontrado.\n");
    return 0;
}

int size(ListaCircular *l)
{
    if (l->start == NULL)
    {
        return 0;
    }

    int count = 0;
    No *atual = l->start;
    do
    {
        count++;
        atual = atual->next;
    } while (atual != l->start);

    return count;
}

int find(ListaCircular *l, int valor)
{
    if (l->start == NULL)
    {
        printf("A lista circular está vazia.\n");
        return -1;
    }

    int posicao = 0;
    No *atual = l->start;
    do
    {
        if (atual->valor == valor)
        {
            return posicao;
        }
        posicao++;
        atual = atual->next;
    } while (atual != l->start);

    printf("Elemento não encontrado.\n");
    return -1;
}

int isEmpty(ListaCircular *l)
{
    return (l->start == NULL);
}

void clear(ListaCircular *l)
{
    if (l->start == NULL)
    {
        return;
    }

    No *atual = l->start;
    while (atual != l->end)
    {
        No *proximo = atual->next;
        free(atual);
        atual = proximo;
    }
    free(atual);

    l->start = NULL;
    l->end = NULL;
}

void exibirMenu()
{
    printf("\n--- Menu Lista Circular  ---\n");
    printf("1. Criar\n");
    printf("2. Adicionar\n");
    printf("3. Remover\n");
    printf("4. Tamanho\n");
    printf("5. Buscar\n");
    printf("6. Está vazia\n");
    printf("7. Limpar\n");
    printf("8. Imprimir valores\n");
    printf("0. Sair\n");
    printf("----------\n");
}

void imprimirLista(ListaCircular *l)
{
    if (l->start == NULL)
    {
        printf("A lista circular está vazia.\n");
        return;
    }

    No *atual = l->start;
    do
    {
        printf("%d ", atual->valor);
        atual = atual->next;
    } while (atual != l->start);

    printf("\n");
}

void imprimirValores(ListaCircular *l)
{
    if (l->start == NULL)
    {
        printf("A lista circular está vazia.\n");
        return;
    }

    No *atual = l->start;
    do
    {
        printf("%d ", atual->valor);
        atual = atual->next;
    } while (atual != l->start);

    printf("\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    ListaCircular l;
    int opcao, valor, resultado;

    create(&l);

    do
    {
        exibirMenu();
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            create(&l);
            printf("Lista circular criada.\n");
            break;
        case 2:
            printf("Digite o valor a adicionar: ");
            scanf("%d", &valor);
            resultado = add(&l, valor);
            if (resultado)
            {
                printf("Elemento adicionado com sucesso.\n");
            }
            else
            {
                printf("Falha ao adicionar elemento. Memória insuficiente.\n");
            }
            imprimirLista(&l);
            break;
        case 3:
            printf("Digite o valor a remover: ");
            scanf("%d", &valor);
            resultado = removerElemento(&l, valor);
            if (resultado)
            {
                printf("Elemento removido com sucesso.\n");
            }
            else
            {
                printf("Elemento não encontrado ou falha ao remover.\n");
            }
            imprimirLista(&l);
            break;
        case 4:
            printf("Tamanho da lista circular: %d\n", size(&l));
            imprimirLista(&l);
            break;
        case 5:
            printf("Digite o valor a buscar: ");
            scanf("%d", &valor);
            resultado = find(&l, valor);
            if (resultado != -1)
            {
                printf("Elemento encontrado na posição %d.\n", resultado);
            }
            imprimirLista(&l);
            break;
        case 6:
            if (isEmpty(&l))
            {
                printf("A lista circular está vazia.\n");
            }
            else
            {
                printf("A lista circular não está vazia.\n");
            }
            imprimirLista(&l);
            break;
        case 7:
            clear(&l);
            printf("Lista circular limpa.\n");
            break;
        case 8:
            imprimirValores(&l);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}

/*Complexidade das funções:

1. `create(ListaOrdenada *l)`: Essa função tem complexidade O(1) porque simplesmente atribui 0 ao campo `size` da lista.

2. `add(ListaOrdenada *l, int valor)`: A complexidade dessa função depende do tamanho atual da lista. No pior caso, quando a lista está cheia, a função percorre todos os elementos da lista para encontrar a posição correta para inserir o novo valor. Portanto, a complexidade no pior caso é O(n), onde n é o tamanho da lista.

3. `remove_element(ListaOrdenada *l, int valor)`: Similar à função `add`, a complexidade de remoção depende do tamanho atual da lista. No pior caso, quando o elemento a ser removido está na primeira posição, a função precisa deslocar todos os elementos subsequentes para preencher o espaço vazio. Assim, a complexidade no pior caso é O(n), onde n é o tamanho da lista.

4. `size(ListaOrdenada *l)`: Essa função tem complexidade O(1) porque retorna simplesmente o valor do campo `size` da lista.

5. `linearSearch(ListaOrdenada *l, int valor)`: Essa função percorre todos os elementos da lista em uma busca linear para encontrar o valor desejado. A complexidade no pior caso é O(n), onde n é o tamanho da lista.

6. `binarySearch(ListaOrdenada *l, int valor)`: Essa função realiza uma busca binária na lista ordenada para encontrar o valor desejado. A complexidade no pior caso é O(log n), onde n é o tamanho da lista.

7. `isFull(ListaOrdenada *l)`: Essa função tem complexidade O(1) porque simplesmente compara o tamanho atual da lista com o tamanho máximo permitido.

8. `isEmpty(ListaOrdenada *l)`: Essa função tem complexidade O(1) porque simplesmente compara o tamanho atual da lista com zero.

9. `clear(ListaOrdenada *l)`: Essa função tem complexidade O(1) porque simplesmente atribui 0 ao campo `size` da lista.

10. `printList(ListaOrdenada *l)`: Essa função percorre todos os elementos da lista para imprimi-los. A complexidade é O(n), onde n é o tamanho da lista.

11. `exibirMenu()`: Essa função tem complexidade O(1) porque simplesmente exibe o menu na tela.

12. `main()`: A complexidade da função principal depende das chamadas das outras funções dentro do loop principal. No pior caso, quando a lista está cheia e é necessário percorrer todos os elementos para adicionar um novo valor, a complexidade total é O(n^2), onde n é o tamanho máximo da lista.*/