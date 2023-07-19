#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    int *values;  // itens da lista
    int size;     // quantidade de elementos na lista
    int n; // capacidade máxima da lista || dimensão da lista
} ListaEstatica;

ListaEstatica *create(ListaEstatica *l, int n) {
    //
    l = (ListaEstatica*)malloc(sizeof(ListaEstatica));
    l->size = 0;
    l->n = n;
    l->values = (int*)malloc(n * sizeof(int));

    return l;
}

bool add(ListaEstatica *l, int elemento) {
    if (l->size == l->n) {
        return false; // ListaEstatica cheia, não é possível adicionar mais elementos
    }

    l->values[l->size] = elemento;
    l->size++;
    return true;
}

bool removeElement(ListaEstatica *l, int elemento) {
    int posicao = -1;

    // Encontra a posição do elemento na ListaEstatica
    for (int i = 0; i < l->size; i++) {
        if (l->values[i] == elemento) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        return false; // Elemento não encontrado na ListaEstatica
    }

    // Remove o elemento e remaneja os elementos seguintes
    for (int i = posicao; i < l->size - 1; i++) {
        l->values[i] = l->values[i + 1];
    }

    l->size--;
    return true;
}

int size(const ListaEstatica *l) {
    //Retorna a quantidade de elementos inseridos na lista
    return l->size;
}

int find(const ListaEstatica *l, int elemento) {
    //Função para retornar a posição do inteiro recebido fodo usuario e retorna erro se não for encontrado
    for (int i = 0; i < l->size; i++) {
        if (l->values[i] == elemento) {
            return i; // Elemento encontrado, retorna a posição
        }
    }
    return -1; // Elemento não encontrado
}

bool isFull(const ListaEstatica *l) {
    //Realiza comparação para saber se a lista já está totalmente preenchida
    return (l->size == l->n);
}

bool isEmpty(const ListaEstatica *l) {
    //Verifica se a fila está vazia
    return (l->size == 0);
}

void clear(ListaEstatica *l) {
    //Realiza a remoção de todos os elementos da fila
    l->size = 0;
}

void destroy(ListaEstatica *l) {
    //Libera espaço de memória
    free(l->values);
    l->values = NULL;
    l->size = 0;
    l->n = 0;
}

int main() {
    setlocale(LC_ALL,"Portuguese_Brazil");
    
    ListaEstatica *l = NULL;

    l = create(l, 100);
    
    add(l, 3);
    add(l, 7);
    add(l, 13);

    printf("Tamanho da lista: %d\n", size(l));
    printf("Posição do elemento 7: %d\n", find(l, 7));

    removeElement(l,7);

    printf("Tamanho da lista após a remoção: %d\n", size(l));
    printf("Posição do elemento 7 após a remoção: %d\n", find(l, 7));

    clear(l);

    printf("Tamanho da lista após a limpeza: %d\n", size(l));
    printf("Lista está vazia: %s\n", isEmpty(l) ? "Sim" : "Não");

    destroy(l);
    free(l);

    return 0;
}
/*
Análise de complexidade temporal e espacial de cada função no código:

1. `create(ListaEstatica *lista, int capacity)`:
   - Essa função cria uma nova lista estática com capacidade definida pelo parâmetro `capacity`.
   - Complexidade Temporal: O(1) - A alocação de memória é uma operação de tempo constante.
   - Complexidade Espacial: O(1) - A memória alocada é proporcional à capacidade definida.

2. `add(ListaEstatica *lista, int elemento)`:
   - Essa função adiciona um elemento à lista estática.
   - Complexidade Temporal: O(1) - A inserção ocorre em tempo constante.
   - Complexidade Espacial: O(1) - Não há alocação adicional de memória.

3. `removeElement(ListaEstatica *lista, int elemento)`:
   - Essa função remove um elemento específico da lista estática.
   - Complexidade Temporal: O(n) - Em pior caso, a função precisa percorrer todos os elementos da lista para encontrar o elemento a ser removido.
   - Complexidade Espacial: O(1) - Não há alocação adicional de memória.

4. `size(const ListaEstatica *lista)`:
   - Essa função retorna o número de elementos presentes na lista estática.
   - Complexidade Temporal: O(1) - A obtenção do tamanho é uma operação de tempo constante.
   - Complexidade Espacial: O(1) - Não há alocação adicional de memória.

5. `find(const ListaEstatica *lista, int elemento)`:
   - Essa função busca a posição de um elemento na lista estática.
   - Complexidade Temporal: O(n) - Em pior caso, a função precisa percorrer todos os elementos da lista para encontrar o elemento desejado.
   - Complexidade Espacial: O(1) - Não há alocação adicional de memória.

6. `isFull(const ListaEstatica *lista)`:
   - Essa função verifica se a lista estática está cheia.
   - Complexidade Temporal: O(1) - A verificação é uma operação de tempo constante.
   - Complexidade Espacial: O(1) - Não há alocação adicional de memória.

7. `isEmpty(const ListaEstatica *lista)`:
   - Essa função verifica se a lista estática está vazia.
   - Complexidade Temporal: O(1) - A verificação é uma operação de tempo constante.
   - Complexidade Espacial: O(1) - Não há alocação adicional de memória.

8. `clear(ListaEstatica *lista)`:
   - Essa função limpa a lista estática, removendo todos os elementos.
   - Complexidade Temporal: O(1) - A limpeza é uma operação de tempo constante.
   - Complexidade Espacial: O(1) - Não há alocação adicional de memória.

9. `destroy(ListaEstatica *lista)`:
   - Essa função destrói a lista estática, liberando a memória alocada.
   - Complexidade Temporal: O(1) - As operações de desalocação de memória possuem tempo constante.
   - Complexidade Espacial: O(1) - Não há alocação adicional de memória.

10. `main()`:
    - A função principal do programa que interage com o usuário para criar, preencher e manipular a lista estática.
    - A complexidade temporal e espacial depende do número de operações realizadas e do tamanho da lista definido.
    - Complexidade Temporal: O(n) - As operações de inserção, remoção e busca podem ser executadas em tempo linear, dependendo do tamanho da lista.
    - Complexidade Espacial: O(1) - A memória alocada é liberada no final do programa e não há alocação adicional de memória.
*/