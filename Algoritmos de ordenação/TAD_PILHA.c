#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

typedef struct {
    int* data;    // Array para armazenar os elementos da pilha
    int top;      // Índice do elemento no topo da pilha
    int size;     // Tamanho máximo da pilha
} Stack;

// Função para criar uma nova pilha
Stack* createStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(size * sizeof(int));
    stack->top = -1;
    stack->size = size;
    return stack;
}
// Função para verificar se a pilha está cheia
bool isFull(Stack* stack) {
    return stack->top == stack->size - 1;
}

// Função para empilhar um elemento
bool push(Stack* stack, int item) {
    if (isFull(stack)) {
        return false; // Retorna falso se a pilha estiver cheia
    }
    stack->data[++stack->top] = item;
    return true;
}

// Função para verificar se a pilha está vazia
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Função para desempilhar um elemento
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return stack->data[stack->top--];
}

int size(Stack* stack) {
    return stack->top + 1;
}

// Função para obter o elemento na base da pilha
int bottom(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return stack->data[0];
}

// Função para buscar a posição de um elemento na pilha
int find(Stack* stack, int element) {
    if (isEmpty(stack)) {
        return -1; // Retorna -1 se a pilha estiver vazia
    }
    for (int i = 0; i <= stack->top; i++) {
        if (stack->data[i] == element) {
            return i; // Retorna a posição se o elemento for encontrado
        }
    }
    return -1; // Retorna -1 se o elemento não for encontrado
}

// Função para obter o elemento no topo da pilha
int top(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return stack->data[stack->top];
}

// Função para destruir a pilha e liberar a memória alocada
void destroyStack(Stack* stack) {
    free(stack->data);
    free(stack);
}

int main() {
    setlocale(LC_ALL,"Portuguese_Brazil");
    int stackSize;
    printf("Digite o tamanho da pilha: ");
    scanf("%d", &stackSize);

    // Verificação do tamanho da pilha
    if (stackSize <= 0) {
        printf("Tamanho inválido da pilha!\n");
        return 1;
    }

    // Criando uma nova pilha
    Stack* stack = createStack(stackSize);

    // Recebendo os valores da pilha do usuário
    printf("Digite os valores da pilha:\n");
    for (int i = 0; i < stackSize; i++) {
        int value;
        printf("Valor %d: ", i + 1);
        scanf("%d", &value);
        if (!push(stack, value)) {
            printf("Erro: Pilha cheia!\n");
            break;
        }
    }

    printf("Elemento no topo: %d\n", top(stack));
    printf("Quantidade de elementos na pilha: %d\n", size(stack));
    printf("Elemento na base: %d\n", bottom(stack));

    // Buscando um elemento na pilha
    int element;
    printf("Digite o elemento a ser buscado: ");
    scanf("%d", &element);
    int position = find(stack, element);
    if (position != -1) {
        printf("Elemento encontrado na posicao %d da pilha.\n", position);
    } else {
        printf("Elemento não encontrado na pilha.\n");
    }

    // Destruindo a pilha e liberando a memória alocada
    destroyStack(stack);

    return 0;
}



/*Análise  e descrição de complexidade temporal e espacial das funções:

1. `createStack(int size)`:
   - Esta função cria uma nova pilha alocando memória para a estrutura `Stack` e para o array `data` que armazenará os elementos da pilha.
   - Complexidade Temporal: O(1) - Consiste em operações de alocação de memória que possuem tempo constante.
   - Complexidade Espacial: O(1) - A alocação de memória é realizada apenas uma vez, ocupando um espaço fixo.

2. `isFull(Stack* stack)`:
   - Verifica se a pilha está cheia, comparando o valor do campo `top` com o tamanho máximo da pilha.
   - Complexidade Temporal: O(1) - A comparação é uma operação de tempo constante.
   - Complexidade Espacial: O(1) - Não há alocação adicional de memória.

3. `push(Stack* stack, int item)`:
   - Adiciona um elemento à pilha, verificando antes se a pilha está cheia.
   - Complexidade Temporal: O(1) - A inserção ocorre em tempo constante, após a verificação.
   - Complexidade Espacial: O(1) - Não há alocação adicional de memória.

4. `isEmpty(Stack* stack)`:
   - Verifica se a pilha está vazia, comparando o valor do campo `top` com -1.
   - Complexidade Temporal: O(1) - A comparação é uma operação de tempo constante.
   - Complexidade Espacial: O(1) - Não há alocação adicional de memória.

5. `pop(Stack* stack)`:
   - Remove o elemento do topo da pilha, verificando antes se a pilha está vazia.
   - Complexidade Temporal: O(1) - A remoção ocorre em tempo constante, após a verificação.
   - Complexidade Espacial: O(1) - Não há alocação adicional de memória.

6. `size(Stack* stack)`:
   - Retorna a quantidade de elementos na pilha, que é o valor do campo `top` incrementado em 1.
   - Complexidade Temporal: O(1) - A obtenção do valor do campo `top` é uma operação de tempo constante.
   - Complexidade Espacial: O(1) - Não há alocação adicional de memória.

7. `bottom(Stack* stack)`:
   - Retorna o elemento na base da pilha, que está no índice 0 do array `data`.
   - Complexidade Temporal: O(1) - A obtenção do elemento da base é uma operação de tempo constante.
   - Complexidade Espacial: O(1) - Não há alocação adicional de memória.

8. `find(Stack* stack, int element)`:
   - Busca a posição de um elemento na pilha, percorrendo todos os elementos do array `data` e comparando-os com o elemento desejado.
   - Complexidade Temporal: O(n), onde n é o tamanho da pilha - Em pior caso, a função percorre todos os elementos do array `data`.
   - Complexidade Espacial: O(1) - Não há alocação adicional de memória.

9. `top(Stack* stack)`:
   - Retorna o elemento no topo da pilha, que está no índice `top` do array `data`.
   - Complexidade Temporal: O(1) - A obtenção do elemento no topo é uma operação de tempo constante.
   - Complexidade Espacial: O(1) - Não há alocação adicional de memória.

10. `destroyStack(Stack* stack)`:
    - Libera a memória alocada para a estrutura `Stack` e o array `data`.
    - Complexidade Temporal: O(1) - Consiste em operações de desalocação de memória que possuem tempo constante.
    - Complexidade Espacial: O(1) - Não há alocação adicional de memória.

11. `main()`:
    - A função principal do programa, que interage com o usuário para criar, preencher e manipular a pilha.
    - A complexidade temporal e espacial depende do tamanho da pilha definido pelo usuário.
    - Complexidade Temporal: O(n), onde n é o tamanho da pilha - O loop `for` percorre todos os elementos da pilha.
    - Complexidade Espacial: O(n), onde n é o tamanho da pilha - A memória alocada para a pilha é proporcional ao tamanho definido.
*/