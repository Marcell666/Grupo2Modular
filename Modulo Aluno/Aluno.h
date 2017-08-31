#ifndef ALUNO_H
#define ALUNO_H

typedef struct {
	short dia;
	short mes;
	short ano;
} Data;

typedef struct {
	char *estado;
	char *cidade;
	char *bairro;
	char *rua;
	char *comp;
} Endereco;

/*Fun��o para deletar um aluno. Recebe o endere�o de mem�ria (ponteiro) de um aluno e o deleta (apaga da mem�ria).*/
int deletaAluno (Aluno *a);

/*Fun��o para pegar a matr�cula de um aluno. Recebe o endere�o de mem�ria (ponteiro) de um aluno e retorna sua matr�cula por refer�ncia (em um ponteiro). */
int GetMat (Aluno *a, int mat);

//Fun��o para criar um �nico aluno. Recebe o endere�o de mem�ria (ponteiro) de um aluno e retorna o aluno criado.
int CriaAluno(Aluno *a);

#endif