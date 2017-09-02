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

// Estrutura que cont�m dados b�sicos.
typedef struct {
	char* nome;
	int mat;
	int cpf;
	int telefone;
	Data nasc;
	Endereco end;
} Dados;

/*Fun��o para deletar um aluno. Recebe o endere�o de mem�ria (ponteiro) de um aluno e o deleta (apaga da mem�ria).*/
int deletaAluno(Aluno *a);

/*Fun��o para pegar a matr�cula de um aluno. Recebe o endere�o de mem�ria (ponteiro) de um aluno e retorna sua matr�cula por refer�ncia (em um ponteiro). */
int GetMat(Aluno *a, int* mat);

//Fun��o para criar um �nico aluno vazio. Recebe o endere�o de mem�ria (ponteiro) de um aluno e retorna o aluno criado.
int CriaAlunoVazio(Aluno *a);

/*Fun��o para pegar o nome de um aluno. Recebe o endere�o de mem�ria (ponteiro) de um aluno e retorna seu nome por refer�ncia (em um ponteiro)*/
int GetNome(Aluno *a, char* nome);

//Fun��o para pegar os dados digitados e colocar no aluno.
int InsereDadosAluno(Aluno *a);

// Altera os dados de um aluno, caso eles sejam diferente de NULL / 0 (Zero).
int AlteraDados(Aluno* aluno, Dados* dados);

/* Fun��o interna para validar uma data.
Considera a data atual do sistema como data limite.
Retorna 1 se a data for v�lida e 0 caso contr�rio.
Valida verificando o n�mero de dias por m�s, p. ex. O dia 31 de setembro n�o � v�lido. */
int ValidaData(Data* data);

#endif
