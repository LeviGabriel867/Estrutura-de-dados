#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Triangulo {
    float alturaTriangulo;
    float comprimentoBase;
    float ladoA;
    float ladoB;
};

typedef struct Triangulo Triangulo;

Triangulo* criarTriangulo(float alturaTriangulo, float comprimentoBase, float ladoA, float ladoB) {
    Triangulo* triangulo = (Triangulo*)malloc(sizeof(Triangulo));
    if (triangulo != NULL) {
        triangulo->alturaTriangulo = alturaTriangulo;
        triangulo->comprimentoBase = comprimentoBase;
        triangulo->ladoA = ladoA;
        triangulo->ladoB = ladoB;
    }
    return triangulo;
}

float calculaArea(Triangulo* triangulo) {
    float area = (triangulo->alturaTriangulo * triangulo->comprimentoBase) / 2;
    return area;
}

float calculaPerimetro(Triangulo* triangulo) {
    float perimetro = triangulo->comprimentoBase + triangulo->ladoA + triangulo->ladoB;
    return perimetro;
}

void tipoTriangulo(Triangulo* triangulo) {
    if (triangulo->ladoA != triangulo->ladoB && triangulo->ladoA != triangulo->comprimentoBase) {
        printf("Triangulo do tipo ESCALENO!\n");
    } else if (triangulo->ladoA == triangulo->ladoB && triangulo->ladoA != triangulo->comprimentoBase) {
        printf("Triangulo do tipo ISOSCELES!\n");
    } else if (triangulo->ladoA == triangulo->ladoB && triangulo->ladoA == triangulo->comprimentoBase) {
        printf("Triangulo do tipo EQUILATERO!\n");
    }
}

void exibeDados(Triangulo* triangulo) {
    printf("<--- Dados Triangulo --->\n");
    printf("Area do triangulo: %.2f\n", calculaArea(triangulo));
    printf("Perimetro do triangulo: %.2f\n", calculaPerimetro(triangulo));
    printf("Tipo do triangulo: ");
    tipoTriangulo(triangulo);
    printf("\n");
}

int main() {
    int opcao;
    float altura, base, ladoA, ladoB;
    Triangulo* c = NULL;

    do {
        printf("MENU:\n");
        printf("1. Criar Triangulo\n");
        printf("2. Exibir Dados do Triangulo\n");
        printf("3. Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a altura do triangulo: ");
                scanf("%f", &altura);
                printf("Digite a base do triangulo: ");
                scanf("%f", &base);
                printf("Digite o lado A do triangulo: ");
                scanf("%f", &ladoA);
                printf("Digite o lado B do triangulo: ");
                scanf("%f", &ladoB);

                if (c != NULL) {
                    free(c);
                }

                c = criarTriangulo(altura, base, ladoA, ladoB);
                printf("Triangulo criado com sucesso!\n");
                break;

            case 2:
                if (c != NULL) {
                    exibeDados(c);
                } else {
                    printf("Nenhum triangulo foi criado ainda.\n");
                }
                break;

            case 3:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opcao invalida. Por favor, tente novamente.\n");
        }

        printf("\n");
    } while (opcao != 3);

    if (c != NULL) {
        free(c);
    }

    return 0;
}
