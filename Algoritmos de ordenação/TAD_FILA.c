#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

struct T_FILA
{
    int *values; // itens da fila
    int n;       // tamanho da fila
    int qtdElements; // variável para quantidade de elementos
    int end;     // variável que vai apontar para o fim da fila
    int start;   // variável que vai apontar para o início da fila
};

typedef struct T_FILA T_FILA;

T_FILA *create(T_FILA *f, int qtd)
//Função para criação da lista
{
    f = (T_FILA *)malloc(sizeof(T_FILA));  //Alocação de memória para fila
    f->values = (int *)calloc(qtd, sizeof(int)); // calloc usado para instanciar vetor
    f->n = qtd;
    f->qtdElements = 0;
    f->end = -1;
    f->start = -1;

    return f;
}

bool isFull(T_FILA *f)
//Realiza uma comparação para verificar se a fila está cheia
{
    return (f->end == f->n - 1);
}

bool isEmpty(T_FILA *f)
//Realiza uma comparação para verificar se a fila está vazia
{
    return (f->qtdElements == 0);
}

bool add(T_FILA *f, int qtd)
//Adiciona elemento na  fila se a verificação retornar que a fila possui espaço e retorna erro se acontecer caso contrário
{
    // Função para inserir elementos na fila
    for (int i = 0; i < qtd; i++)
    {
        if (isFull(f))
        {
            printf("A fila está totalmente cheia, sem possibilidade de novas inserções!\n");
            return false;
        }

        printf("Digite o valor a ser inserido no fim da fila: ");
        int elemento;
        scanf("%d", &elemento);

        if (isEmpty(f))
        {
            f->start = 0;
        }
        f->end++;
        f->values[f->end] = elemento;
        f->qtdElements++;
        printf("Elemento %d adicionado com sucesso.\n", elemento);
    }
    return true;
}

bool pop(T_FILA *f)
//Remove o elemento na fila se caso a verificação apontar que a fila não está vazia
{
    if (isEmpty(f))
    {
        printf("A fila está vazia. Remoção não realizada.\n");
        return false;
    }

    f->start++;
    f->qtdElements--;

    if (f->start > f->end)
    {
        f->start = -1;
        f->end = -1;
    }
    return true;
}

int size(T_FILA *f)
//Usada para retornar quantidade de elementos na fila
{
    return f->qtdElements;
}

int first(T_FILA *f)
//Retorna o elemento inicial da fila
{
    if (isEmpty(f))
    {
        printf("A fila está totalmente vazia.\n");
        return -1;
    }
    return f->values[f->start];
}

int last(T_FILA *f)
//Retorna o elemento final da fila
{
    if (isEmpty(f))
    {
        printf("A fila está totalmente vazia.\n");
        return -1;
    }
    return f->values[f->end];
}

int find(T_FILA *f, int inteiro)
//Retorna a posição do inteiro escolhido pelo usuario
{
    for (int i = f->start; i <= f->end; i++)
    {
        if (f->values[i] == inteiro)
        {
            return i;
        }
    }
    return -1;
}

void clear(T_FILA *f)
//Reinicia toda a fila
{
    f->start = -1;
    f->end = -1;
    f->qtdElements = 0;
    printf("Fila reiniciada.\n");
}

int main()
{
    setlocale(LC_ALL,"Portuguese_Brazil");
    
    int tamFila;
    printf("Digite o tamanho da fila: ");
    scanf("%d", &tamFila);

    T_FILA *f = NULL;
    f = create(f, tamFila);

    int opc = 0;
    int posicao = 0;
    int valor = 0;
    int qtd = 0;

    do
    {
        printf("\n");
        printf("=========== Menu ==========\n");
        printf("1. Adicionar elemento na fila\n");
        printf("2. Remover elemento do início da fila\n");
        printf("3. Retornar a quantidade de elementos inseridos na fila\n");
        printf("4. Exibir primeiro elemento da fila\n");
        printf("5. Exibir último elemento da fila\n");
        printf("6. Buscar elemento\n");
        printf("7. Excluir elementos\n");
        printf("0. Sair\n");
        printf("\n");

        printf("Digite sua opção: ");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            printf("Digite a quantidade de elementos a serem adicionados na fila: ");
            scanf("%d", &qtd);
            if (add(f, qtd))
            {
                printf("Elementos adicionados com sucesso.\n");
            }
            else
            {
                printf("Falha ao adicionar elementos.\n");
            }
            break;

        case 2:
            if (pop(f))
            {
                printf("Remoção executada.\n");
            }
            break;

        case 3:
            printf("Quantidade de elementos: %d\n", size(f));
            break;

        case 4:
            valor = first(f);
            if (valor != -1)
            {
                printf("Primeiro elemento na fila: %d\n", valor);
            }
            break;

        case 5:
            valor = last(f);
            if (valor != -1)
            {
                printf("Último elemento na fila: %d\n", valor);
            }
            break;

        case 6:
            printf("Valor que deseja buscar: ");
            scanf("%d", &valor);
            posicao = find(f, valor);
            if (posicao != -1)
            {
                printf("Elemento %d encontrado na posição %d.\n", valor, posicao);
            }
            else
            {
                printf("Elemento %d não foi encontrado na fila.\n", valor);
            }
            break;

        case 7:
            clear(f);
            break;

        case 0:
            printf("Programa encerrado.\n");
            break;

        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opc != 0);

    free(f->values);
    free(f);

    return 0;
}


/*Análise da complexidade temporal e espacial de cada função implementada na TAD para fila:

1. Função `create`:
   - Complexidade temporal: O(1) - A alocação de memória e a inicialização dos campos da struct T_FILA têm complexidade constante.
   - Complexidade espacial: O(1) - A função aloca memória para a struct T_FILA e seu vetor de valores, ocupando um espaço constante.

2. Função `isFull`:
   - Complexidade temporal: O(1) - A verificação simples do valor de `f->end` tem complexidade constante.
   - Complexidade espacial: O(1) - A função não requer memória adicional além dos parâmetros de entrada.

3. Função `isEmpty`:
   - Complexidade temporal: O(1) - A verificação simples do valor de `f->qtdElements` tem complexidade constante.
   - Complexidade espacial: O(1) - A função não requer memória adicional além dos parâmetros de entrada.

4. Função `add`:
   - Complexidade temporal: O(qtd) - A função itera `qtd` vezes para adicionar elementos à fila, onde `qtd` é o número de elementos a serem adicionados.
   - Complexidade espacial: O(1) - A função não requer memória adicional além dos parâmetros de entrada.

5. Função `pop`:
   - Complexidade temporal: O(1) - A função realiza algumas operações simples, como incrementar/decrementar valores e verificar condições, todas com complexidade constante.
   - Complexidade espacial: O(1) - A função não requer memória adicional além dos parâmetros de entrada.

6. Função `size`:
   - Complexidade temporal: O(1) - A função simplesmente retorna o valor de `f->qtdElements`, que é uma operação de complexidade constante.
   - Complexidade espacial: O(1) - A função não requer memória adicional além dos parâmetros de entrada.

7. Função `first`:
   - Complexidade temporal: O(1) - A função retorna o valor `f->values[f->start]`, que é uma operação de complexidade constante.
   - Complexidade espacial: O(1) - A função não requer memória adicional além dos parâmetros de entrada.

8. Função `last`:
   - Complexidade temporal: O(1) - A função retorna o valor `f->values[f->end]`, que é uma operação de complexidade constante.
   - Complexidade espacial: O(1) - A função não requer memória adicional além dos parâmetros de entrada.

9. Função `find`:
   - Complexidade temporal: O(n) - A função itera do índice `f->start` até o índice `f->end`, procurando o elemento `inteiro` na fila. O pior caso ocorre quando o elemento não está presente e a função precisa percorrer toda a fila.
   - Complexidade espacial: O(1) - A função não requer memória adicional além dos parâmetros de entrada.

10. Função `clear`:
    - Complexidade temporal: O(1) - A função simplesmente redefine os campos de `f` para seus valores iniciais, o que tem complexidade constante.
    - Complexidade espacial: O(1) - A função não requer memória adicional
*/