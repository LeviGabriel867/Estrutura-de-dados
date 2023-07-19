#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int chave;
    struct No *esquerda;
    struct No *direita;
} No;

No *createNo(int chave)
{
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->chave = chave;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

No *addNo(No *raiz, int chave)
{
    if (raiz == NULL)
    {
        return createNo(chave);
    }

    if (chave < raiz->chave)
    {
        raiz->esquerda = addNo(raiz->esquerda, chave);
    }
    else if (chave > raiz->chave)
    {
        raiz->direita = addNo(raiz->direita, chave);
    }

    return raiz;
}

No *findNo(No *raiz, int chave)
{
    if (raiz == NULL || raiz->chave == chave)
    {
        return raiz;
    }

    if (chave < raiz->chave)
    {
        return findNo(raiz->esquerda, chave);
    }
    else
    {
        return findNo(raiz->direita, chave);
    }
}

void clear(No *raiz)
{
    if (raiz != NULL)
    {
        clear(raiz->esquerda);
        clear(raiz->direita);
        free(raiz);
    }
}

void printAllPre(No *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->chave);
        printAllPre(raiz->esquerda);
        printAllPre(raiz->direita);
    }
}

void printAllLn(No *raiz)
{
    if (raiz != NULL)
    {
        printAllLn(raiz->esquerda);
        printf("%d ", raiz->chave);
        printAllLn(raiz->direita);
    }
}

void printAllPos(No *raiz)
{
    if (raiz != NULL)
    {
        printAllPos(raiz->esquerda);
        printAllPos(raiz->direita);
        printf("%d ", raiz->chave);
    }
}

int main()
{
    No *raiz = NULL;
    int opcao, chave;

    do
    {
        printf("\nOperacoes da Arvore Binaria de Busca\n");
        printf("1. Adicionar Elemento\n");
        printf("2. Encontrar Elemento\n");
        printf("3. Imprimir Traversao Pre-Ordem\n");
        printf("4. Imprimir Traversao Em-Ordem\n");
        printf("5. Imprimir Traversao Pos-Ordem\n");
        printf("6. Limpar Arvore\n");
        printf("7. Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite a chave a ser adicionada: ");
            scanf("%d", &chave);
            raiz = addNo(raiz, chave);
            break;
        case 2:
            printf("Digite a chave a ser encontrada: ");
            scanf("%d", &chave);
            No *noEncontrado = findNo(raiz, chave);
            if (noEncontrado != NULL)
            {
                printf("No com a chave %d encontrado!\n", chave);
            }
            else
            {
                printf("No com a chave %d nao encontrado!\n", chave);
            }
            break;
        case 3:
            printf("Traversao Pre-Ordem: ");
            printAllPre(raiz);
            printf("\n");
            break;
        case 4:
            printf("Traversao Em-Ordem: ");
            printAllLn(raiz);
            printf("\n");
            break;
        case 5:
            printf("Traversao Pos-Ordem: ");
            printAllPos(raiz);
            printf("\n");
            break;
        case 6:
            clear(raiz);
            raiz = NULL;
            printf("Arvore limpa!\n");
            break;
        case 7:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida! Por favor, escolha uma opcao valida.\n");
            break;
        }
    } while (opcao != 7);

    return 0;
}

/*Complexidade das funções: 
- Função de criação ('create'): A complexidade dessa função é constante, ou seja, O(1). A função createNo cria um novo nó e inicializa 
seus atributos chave, esquerda e direita com valores específicos. A função aloca memória para o novo nó usando a função malloc, que 
geralmente possui uma complexidade de O(1) (tempo constante) para a alocação de memória.Não há laços ou estruturas de repetição na 
função, e todas as operações são realizadas em tempo constante. Portanto, a complexidade da função createNo é O(1).

- Função de inserção (`addNo`): A complexidade da inserção em uma Árvore Binária de Busca depende da altura da árvore. No pior 
caso, quando a árvore está perfeitamente desbalanceada e assume uma forma linear, a complexidade é O(n), pois é necessário percorrer 
todos os nós da árvore. No entanto, em média, a complexidade é O(log n), devido à natureza balanceada da árvore, em que cada nível reduz o 
espaço de busca pela metade.

- Função de pesquisa (`findNo`): A complexidade da pesquisa em uma Árvore Binária de Busca também depende da altura da árvore. 
No pior caso, quando a árvore está desbalanceada e assume uma forma linear, a complexidade é O(n), pois é necessário percorrer todos 
os nós da árvore. No entanto, em média, a complexidade é O(log n), devido à natureza balanceada da árvore, em que cada nível reduz o 
espaço de busca pela metade.

- Função de limpar a árvore (`clear`):  A complexidade dessa função é conhecida como O(n), onde "n" representa o número de nós presentes na árvore.
Para realizar a tarefa de liberação de memória de forma adequada, a função clear percorre recursivamente todos os nós da árvore. 
Ela começa verificando se a raiz não é nula. Em caso afirmativo, o processo de limpeza continua com a chamada recursiva da função clear 
para a subárvore esquerda, seguida pela chamada recursiva para a subárvore direita. Por fim, a memória alocada para a raiz é liberada 
por meio do comando free(raiz).

- Funções de impressão (`printAllPre`, `printAllLn`, `printAllPos`): Cada uma dessas funções possui uma complexidade de O(n), onde "n" representa 
o número de nós existentes na árvore. 
A função printAllPre imprime todos os nós em pré-ordem. Isso é realizado seguindo uma abordagem recursiva. A função verifica se a 
raiz não é nula e, em seguida, imprime o valor da raiz. Em seguida, ocorre a chamada recursiva da função printAllPre para a subárvore esquerda e, 
posteriormente, para a subárvore direita.
Da mesma forma, a função printAllLn percorre todos os nós da árvore em ordem. Ela realiza isso de maneira recursiva, primeiro 
percorrendo a subárvore esquerda, imprimindo o valor da raiz e, em seguida, percorrendo a subárvore direita.
Por fim, a função printAllPos percorre todos os nós da árvore em pós-ordem. Novamente, isso é feito de forma recursiva, 
começando pela subárvore esquerda, seguida pela subárvore direita e, por último, imprimindo o valor da raiz.
*/

