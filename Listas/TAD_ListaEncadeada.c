#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct No {
    int valor;
    struct No* next;
} No;

typedef struct ListaEncadeada {
    No* start;
    No* end;
} ListaEncadeada;

void create(ListaEncadeada* l) {
    l->start = NULL;
    l->end = NULL;
}

int add(ListaEncadeada* l, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Falha ao adicionar elemento. Memória insuficiente.\n");
        return 0; // Falha na alocação de memória
    }

    novoNo->valor = valor;
    novoNo->next = NULL;

    if (l->start == NULL) {
        l->start = novoNo;
        l->end = novoNo;
    } else {
        l->end->next = novoNo;
        l->end = novoNo;
    }

    return 1; // Elemento adicionado com sucesso
}

int removeElement(ListaEncadeada* l, int valor) {
    No* current = l->start;
    No* previous = NULL;

    while (current != NULL) {
        if (current->valor == valor) {
            if (previous == NULL) {
                l->start = current->next;
                if (l->start == NULL) {
                    l->end = NULL;
                }
            } else {
                previous->next = current->next;
                if (current->next == NULL) {
                    l->end = previous;
                }
            }

            free(current);
            return 1; // Elemento removido com sucesso
        }

        previous = current;
        current = current->next;
    }

    return 0; // Elemento não encontrado
}

int size(ListaEncadeada* l) {
    int count = 0;
    No* current = l->start;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

int find(ListaEncadeada* l, int valor) {
    int position = 0;
    No* current = l->start;

    while (current != NULL) {
        if (current->valor == valor) {
            return position;
        }

        position++;
        current = current->next;
    }

    return -1; // Elemento não encontrado
}

int isEmpty(ListaEncadeada* l) {
    return l->start == NULL;
}

void clear(ListaEncadeada* l) {
    No* current = l->start;
    No* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    l->start = NULL;
    l->end = NULL;
}

void exibirValores(ListaEncadeada* l) {
    No* current = l->start;

    if (isEmpty(l)) {
        printf("A lista encadeada está vazia.\n");
    } else {
        printf("Valores da lista encadeada:\n");
        while (current != NULL) {
            printf("%d ", current->valor);
            current = current->next;
        }
        printf("\n");
    }
}

void exibirMenu() {
    printf("\n--- Menu Lista Encadeada ---\n");
    printf("1. Criar\n");
    printf("2. Adicionar\n");
    printf("3. Remover\n");
    printf("4. Tamanho\n");
    printf("5. Buscar\n");
    printf("6. Está vazia\n");
    printf("7. Limpar\n");
    printf("8. Exibir valores da lista\n");
    printf("0. Sair\n");
    printf("----------\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    ListaEncadeada l;
    int opcao, valor, resultado;

    create(&l);

    do {
        exibirMenu();
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                create(&l);
                printf("Lista encadeada criada.\n");
                break;
            case 2:
                printf("Digite o valor a adicionar: ");
                scanf("%d", &valor);
                resultado = add(&l, valor);
                if (resultado) {
                    printf("Elemento adicionado com sucesso.\n");
                } else {
                    printf("Falha ao adicionar elemento. Memória insuficiente.\n");
                }
                break;
            case 3:
                printf("Digite o valor a remover: ");
                scanf("%d", &valor);
                resultado = removeElement(&l, valor);
                if (resultado) {
                    printf("Elemento removido com sucesso.\n");
                } else {
                    printf("Elemento não encontrado ou falha ao remover.\n");
                }
                break;
            case 4:
                printf("Tamanho da lista encadeada: %d\n", size(&l));
                break;
            case 5:
                printf("Digite o valor a buscar: ");
                scanf("%d", &valor);
                resultado = find(&l, valor);
                if (resultado != -1) {
                    printf("Elemento encontrado na posição %d.\n", resultado);
                } else {
                    printf("Elemento não encontrado.\n");
                }
                break;
            case 6:
                if (isEmpty(&l)) {
                    printf("A lista encadeada está vazia.\n");
                } else {
                    printf("A lista encadeada não está vazia.\n");
                }
                break;
            case 7:
                clear(&l);
                printf("Lista encadeada limpa.\n");
                break;
            case 8:
                exibirValores(&l);
                break;

            case 0:
                printf("Encerrando o programa.\n");
                clear(&l);
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}

/*
Complexidade das funções:
1. `create(ListaEncadeada* l)`: Essa função tem complexidade de tempo O(1) porque simplesmente atribui `NULL` aos ponteiros `start` e `end` da lista encadeada.

2. `add(ListaEncadeada* l, int valor)`: A complexidade de tempo dessa função é O(1) no caso médio. A função alocará um novo nó, atribuirá o valor a ele e o adicionará ao final da lista encadeada, atualizando os ponteiros `end`. Como a adição ocorre sempre no final da lista, a operação é executada em tempo constante.

3. `removeElement(ListaEncadeada* l, int valor)`: A complexidade de tempo dessa função é O(n), onde n é o número de elementos na lista encadeada. A função precisa percorrer a lista para encontrar o elemento a ser removido. No pior caso, o elemento a ser removido está no final da lista, exigindo uma verificação em todos os nós da lista.

4. `size(ListaEncadeada* l)`: Essa função possui complexidade de tempo O(n), onde n é o número de elementos na lista encadeada. A função percorre toda a lista para contar o número de nós.

5. `find(ListaEncadeada* l, int valor)`: A complexidade de tempo dessa função é O(n), onde n é o número de elementos na lista encadeada. A função percorre toda a lista para encontrar o elemento desejado.

6. `isEmpty(ListaEncadeada* l)`: Essa função tem complexidade de tempo O(1) porque verifica se o ponteiro `start` é `NULL` para determinar se a lista está vazia ou não.

7. `clear(ListaEncadeada* l)`: Essa função tem complexidade de tempo O(n), onde n é o número de elementos na lista encadeada. A função percorre todos os nós da lista e os libera, atualizando os ponteiros `start` e `end` para `NULL`.

8. `exibirValores(ListaEncadeada* l)`: Essa função tem complexidade de tempo O(n), onde n é o número de elementos na lista encadeada. A função percorre todos os nós da lista e imprime seus valores.
*/