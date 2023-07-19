typedef struct quadrado Quadrado;
typedef struct triangulo Triangulo;

Triangulo *criarTriangulo(float alturaTriangulo, float comprimentoTriangulo, float ladoA, float ladoB);
float calculaArea(Triangulo *triangulo);
float calculaPerimentro(Triangulo *triangulo);
float tipoTriangulo(Triangulo *triangulo);
void exibiDados(Triangulo *triangulo);
Quadrado *criarQuadrado(float ladoQuadrado);
float areaQuadrado(Quadrado *quadrado);
float perimetroQuadrado(Quadrado *quadrado);