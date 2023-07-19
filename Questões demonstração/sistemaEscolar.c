#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TAMANHO_TURMA 4
typedef struct
{
    int matricula;
    char nome[50];
    int idade;
    float nota_01;
    float nota_02;
    float nota_final;
    int faltas;
    float media;

}aluno;

void calcula_media(aluno *a)
{
    a->media = (a->nota_01 + a->nota_02 + a->nota_final) / 3;

    printf("\n");
    if (a->media > 7)
    {
        printf("ALuno  está aprovado por nota.");
    }
    else if (a->media > 4)
    {
        printf("Aluno está de avaliação final.");
    }
    else
    {
        printf("Aluno está reprovado por nota.");
    }
    return 0;
};
int faltas(aluno *a){
    if(a->faltas<=10){
        printf("Não reprovado por faltas.");
    }else{
        printf("Reprovado por falta");
    }
}
int maior_idade(aluno *a, aluno *b){
    if(a->idade > b->idade){
        return 1;
    } else if(a->idade < b->idade){
        return -1;
    } else{
        return 0;
    }
}
aluno* retorna_mais_velho(aluno *a, aluno *b){
    if(a->idade > b->idade){
        return a;
    }else{
        return b;
    }
}
int total_faltas(aluno *turma){
    for(int i = 0; i<TAMANHO_TURMA; i++){
        total_faltas += turma[i].faltas;
    }
    return total_faltas;

}
int main()
{
    int qtd;
    float media;
    float av_Final;
    int maior_idade = 0;
    char nome_mais_velho[50];

    printf("Quantos alunos deseja cadastrar?  ");
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++)
    {
        printf("\nInsira a matricula do aluno ", i + 1, "º:");
        scanf("%d", &Alunos[i].matricula);

        printf("Nome do aluno ", i + 1); // problema no º
        scanf("%s", &Alunos[i].nome);

        printf("Idade do aluno: ");
        scanf("%d", &Alunos[i].idade);

        printf("Nota 01: ");
        scanf("%f", &Alunos[i].nota_01);

        printf("Nota 02: ");
        scanf("%f", &Alunos[i].nota_02);

        printf("Nota final: ");
        scanf("%f", &Alunos[i].nota_final);

        printf("Total de faltas: ");
        scanf("%f", &Alunos[i].faltas);

        media = calcula_media(Alunos[i].nota_01, Alunos[i].nota_02, Alunos[i].nota_final);
            for(int i = 0; i <qtd; i++){
                if(Alunos[i].nome > maior_idade){
                    maior_idade = Alunos[i].nome;
                    strcpy(nome_mais_velho, Alunos[i].nome);
                }
            }
     printf("A pessoa com a maior idade é %s, com %d anos.\n", nome_, maior_idade);
    
    }
}