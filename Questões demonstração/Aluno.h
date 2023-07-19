typedef struct aluno Aluno;

Aluno *criarAluno(int matricula, const char *nome, int idade, float nota1, float nota2, int quantFaltas);
void situacaoFaltas(Aluno *aluno);
void imprimirSituacaonota(Aluno *aluno);
void maisVelho(Aluno *aluno1, Aluno *aluno2);
float calcularMedia(Aluno *aluno);
void imprimiAluno(Aluno *aluno);
void liberarTurma(Aluno **turma, int numAlunos);
void imprimiTodos(Aluno *turma[], int quant);
