
#ifndef ALUNO_H
#define ALUNO_H

typedef struct data {
	short dia;
	short mes;
	short ano;
} Data;

typedef struct endereco {
	char estado[51];
	char cidade[51];
	char bairro[32];
	char rua[81];
	char comp[32];
} Endereco;

typedef struct aluno Aluno;


// Fun��o para criar um aluno. Recebe um ponteiro para Aluno e retorna o aluno criado com as informa��es passadas por par�metros.
int CriaAluno(Aluno *a, char *nome, int mat, int cpf, int telefone, Data *nasc, Endereco* end);

// Fun��o para deletar um aluno. Recebe o endere�o de mem�ria de um aluno e o deleta (apaga da mem�ria).*/
int deletaAluno(Aluno* a);

// Altera os dados de um aluno, caso eles sejam diferente de NULL / 0 (Zero). Caso um dado n�o necessite ser alterado, passar 0 / NULL como par�metro.
int AlteraDados(Aluno *aluno, char *nome, int mat, int cpf, int telefone, Data *nasc, Endereco* end);

// Fun��o para pegar a matr�cula de um aluno. Recebe o endere�o de mem�ria (ponteiro) de um aluno e devolve sua matr�cula por refer�ncia.
int GetMat(Aluno *a, int *mat);

// Fun��o para pegar o nome de um aluno. Recebe um ponteiro para Aluno e devolve seu nome por refer�ncia.
int GetNome(Aluno *a, char* nome);

// Fun��o interna para validar uma data.
// Considera a data atual do sistema como data limite.
// Retorna 1 se a data for v�lida e 0 caso contr�rio.
// Valida verificando o n�mero de dias por m�s, p. ex. O dia 31 de setembro n�o � v�lido. */
int ValidaData(Data* data);

// Funcao que copia os dados do aluno.
int GetAll(Aluno *a,char *nome,int *mat,int *cpf,int *tel, Data *nasc,Endereco *endereco);

#endif