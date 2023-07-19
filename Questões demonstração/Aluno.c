#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Aluno.h"
struct aluno
{
    int matricula, idade, faltas;
    float nota1, nota2, nfinal;
    char nome[50];
};
Aluno *novo_aluno(int matricula, int idade, int faltas, float nota1, float nota2, float nfinal, const char nome)
{
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
    if (aluno != NULL)
    {
        aluno->matricula = matricula;
        aluno->idade = idade;
        aluno->faltas = faltas;
        aluno->nota1 = nota1;
        aluno->nota2 = nota2;
        strcpy(aluno->nome, nome);
    }
    return aluno;
}
void faltasnofinal(Aluno *aluno)
{
    if (aluno->faltas > 8)
    {
        printf("Reprovado por falta.\n");
    }
    else
    {
        printf("Aprovado por falta.\n");
    }
}
void notasfinais(Aluno *aluno)
{
    float mediafinal = (aluno->nota1 + aluno->nota2) / 2;
    if (mediafinal < 7 && mediafinal >= 4)
    {
        printf("Aluno fára a AF!\n");
    }
    else if (mediafinal >= 7)
    {
        printf("Aprovado por nota!");
    }
    else
    {
        printf("Reprovado por nota!");
    }
}
void comparar_idade(Aluno *aluno1, Aluno *aluno2)
{
    if (aluno1->idade > aluno2->idade)
    {
        printf("Esse é o aluno mais velho: %s\n", aluno1->nome);
    }
    else
    {
        printf("Esse é o aluno mais velho: %s\n", aluno2->nome);
    }
}
float calcular_media(Aluno *aluno)
{
    float mediafinal = (aluno->nota1 + aluno->nota2) / 2;
    return mediafinal;
}
void dadosAluno(Aluno *aluno)
{
    printf("-----Dados do aluno-----\n");
    printf("Matrícula: %d\n", aluno->matricula);
    printf("Idade: %d\n", aluno->idade);
    printf("Total de faltas: %d\n", aluno->faltas);
    printf("Nota 1: %f\n", aluno->nota1);
    printf("Nota 2: %f\n", aluno->nota2);
    printf("Nome: %s\n", aluno->nome);
    printf("Media Final:");
    mediafinal(aluno);
    printf("Faltas:");
    faltasnofinal(aluno);
}
void imprimir_turma(Aluno *turma[], int total_alunos)
{
    for (int i = 0; i < total_alunos; i++)
    {
        printf("-----Dados do aluno-----\n");
        printf("Matrícula: %d\n", turma[i]->matricula);
        printf("Idade: %d\n", turma[i]->idade);
        printf("Total de faltas: %d\n", turma[i]->faltas);
        printf("Nota 1: %.2f\n", turma[i]->nota1);
        printf("Nota 2: %.2f\n", turma[i]->nota2);
        printf("Nome: %s\n", turma[i]->nome);
        printf("Media final da turma");
        mediafinal(turma[i]);
        printf("Faltas:");
        faltasnofinal(turma[i]);
    }
}
void Turma(Aluno **turma, int quant_alunos)
{
    for (int i = 0; int < quant_alunos; i++)
    {
        free(turma[i]);
    }
    free(turma);
}

int main()
{
    int quant_alunos = 2;
    Aluno **turma = (Aluno **)malloc(quant_alunos * sizeof(Aluno *));
    if turma
        == NULL
        {
            printf("Erro para alocar memória!\n");
            return 1;
        }
    turma[0] = novo_aluno(5376, 15, 8, 7.5, 7.0, "Ana");
    turma[1] = novo_aluno(5377, 17, 20, 8.0, 5.0, "Carolina");
    imprimir_turma(turma, quant_alunos);
    comparar_idade(turma[0], turma[1]);
    free(turma);
    return 0;
}