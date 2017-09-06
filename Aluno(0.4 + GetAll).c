#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct aluno {
	char nome[81];
	int mat;
	int cpf;
	int telefone;
	Data nasc;
	Endereco end;
};

/*Recebe um ponteiro para aluno e desaloca o espa�o de mem�ria apontado pelo mesmo*/
int deletaAluno(Aluno* a) {
	free(a);
	return 0;
}

/*Recebe um ponteiro para aluno e outro para um inteiro e retorna a matr�cula do aluno pelo ponteiro para inteiro.*/
int GetMat(Aluno *a, int *mat) {
	*mat = a->mat;
	return 0;
}
/*Recebe um ponteiro para aluno e outro para um char e retorna o nome do aluno pelo ponteiro para char.*/
int GetNome(Aluno *a, char* nome) {
	strcpy(nome, a->nome);
	return 0;
}

//Cria um �nico vazio aluno passado por referencia.
int CriaAluno(Aluno *a, char *nome, int mat, int cpf, int telefone, Data *nasc, Endereco* end ) {
	a = (Aluno*)malloc(sizeof(Aluno));

	if (a == NULL) {
		printf("\nError na cria��o do Aluno\n");
		exit(1);
	}

	strcpy(a->nome, nome);
	a->mat = mat;
	a->cpf = cpf;
	a->telefone = telefone;
	a->nasc.dia = nasc->dia;
	a->nasc.mes = nasc->mes;
	a->nasc.ano = nasc->ano;
	strcpy(a->end.bairro,end->bairro);
	strcpy(a->end.cidade,end->cidade);
	strcpy(a->end.comp,end->comp);
	strcpy(a->end.estado,end->estado);
	strcpy(a->end.rua,end->rua);

	return 0;
}

// Altera os dados de um aluno, caso eles sejam diferente de NULL / 0 (Zero).
int AlteraDados(Aluno *aluno, char *nome, int mat, int cpf, int telefone, Data *nasc, Endereco* end) {

	if (nome)
		strcpy(aluno->nome,nome);
	if (mat)
		aluno->mat = mat;
	if (cpf)
		aluno->cpf = cpf;
	if (telefone)
		aluno->telefone = telefone;
	if (nasc && ValidaData(nasc)) {
		aluno->nasc.ano = nasc->ano;
		aluno->nasc.mes = nasc->mes;
		aluno->nasc.dia = nasc->dia;
	}
	if (end) {
		strcpy(aluno->end.estado, end->estado);
		strcpy(aluno->end.cidade, end->cidade);
		strcpy(aluno->end.bairro, end->bairro);
		strcpy(aluno->end.rua, end->rua);
		strcpy(aluno->end.comp, end->comp);
	}

	return 0;
}

/* Fun��o interna para validar uma data.
Considera a data atual do sistema como data limite.
Retorna 1 se a data for v�lida e 0 caso contr�rio.
Valida verificando o n�mero de dias por m�s, p. ex. O dia 31 de setembro n�o � v�lido. */
int ValidaData(Data* data) {

	time_t t = time(NULL);
	struct tm *time = localtime(&t);
	char meses31[7] = { 1,3,5,7,8,10,12 };
	char meses30[4] = { 4,6,9,11 };
	int i;

	if ((data->dia < time->tm_mday && data->mes < (time->tm_mon + 1)) && data->ano < (time->tm_year + 1900))
	{
		for (i = 0; i < 7; i++) {
			if (data->mes == meses31[i])
				if (data->dia <= 31)
					return 1;
		}
		for (i = 0; i < 4; i++) {
			if (data->mes == meses30[i])
				if (data->dia <= 30)
					return 1;
		}
		if (data->mes == 2)
			if (data->dia <= 28)
				return 1;
	}
	return 0;
}
/* Funcao que copia os dados do aluno  */
int GetAll(Aluno *a,char *nome,int *mat,int *cpf,int *tel, Data *nasc,Endereco *endereco) {

	if(a == NULL)
		return 0;
	strcpy(nome, a->nome);
	*mat = a->mat;
	*cpf = a->cpf;
	*tel = a->telefone;
	nasc->ano = a->nasc.ano;
	nasc->dia = a->nasc.dia;
	nasc->mes = a->nasc.mes;
	strcpy(endereco->estado, a->end.estado);
	strcpy(endereco->cidade, a->end.cidade);
	strcpy(endereco->bairro, a->end.bairro);
	strcpy(endereco->rua, a->end.rua);
	strcpy(endereco->comp, a->end.comp);

	return 1;
}