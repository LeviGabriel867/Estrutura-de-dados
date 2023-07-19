#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"

int main()
{
    // Exemplo de uso de um vetor de alunos com ponteiros
    int numAlunos = 2; // Número de alunos na turma

    // Alocar memória para o vetor de ponteiros para alunos
    Aluno **turma = (Aluno **)malloc(numAlunos * sizeof(Aluno *));
    if (turma == NULL)
    {
        printf("Erro ao alocar memória para o vetor de alunos.\n");
        return 1;
    }

    // Criar alunos e armazenar os ponteiros no vetor
    turma[0] = criarAluno(1001, "Joao", 20, 7.5, 8.0, 2);
    turma[1] = criarAluno(1002, "Maria", 22, 5.5, 6.0, 3);

    // Imprimir dados dos alunos, com sua situção de média e faltas
    imprimiTodos(turma, numAlunos);

    maisVelho(turma[0], turma[1]);

    free(turma); // Liberar a memória alocada para o vetor de ponteiros para alunos

    return 0;
}
