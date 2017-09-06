#include "Aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct aluno {
	char nome[81];
	int mat;
	long cpf;
	int telefone;
	Data nasc;
	Endereco end;
};

/*Recebe um ponteiro para aluno e desaloca o espaço de memória apontado pelo mesmo*/
ALN_tpCondRet deletaAluno(Aluno* a) {
	if (a == NULL)
		return ALN_CondRetAlunoNaoExiste;
	free(a);
	return ALN_CondRetOK;
}

/*Recebe um ponteiro para aluno e outro para um inteiro e retorna a matrícula do aluno pelo ponteiro para inteiro.*/
ALN_tpCondRet GetMat(Aluno *a, int *mat) {
	if (a == NULL)
		return ALN_CondRetAlunoNaoExiste;
	*mat = a->mat;
	return ALN_CondRetOK;
}
/*Recebe um ponteiro para aluno e outro para um char e retorna o nome do aluno pelo ponteiro para char.*/
ALN_tpCondRet GetNome(Aluno *a, char* nome) {
	if (a == NULL)
		return ALN_CondRetAlunoNaoExiste;
	strcpy(nome, a->nome);
	return ALN_CondRetOK;
}

//Cria um único vazio aluno passado por referencia.
ALN_tpCondRet CriaAluno(Aluno *a, char *nome, int mat, int cpf, int telefone, Data *nasc, Endereco* end) {
	
	a = (Aluno*)malloc(sizeof(Aluno));

	if (a == NULL)
		return ALN_CondRetFaltouMemoria;

	strcpy(a->nome, nome);
	a->mat = mat;
	a->cpf = cpf;
	a->telefone = telefone;
	a->nasc.dia = nasc->dia;
	a->nasc.mes = nasc->mes;
	a->nasc.ano = nasc->ano;
	strcpy(a->end.bairro, end->bairro);
	strcpy(a->end.cidade, end->cidade);
	strcpy(a->end.comp, end->comp);
	strcpy(a->end.estado, end->estado);
	strcpy(a->end.rua, end->rua);

	return ALN_CondRetOK;
}

// Altera os dados de um aluno, caso eles sejam diferente de NULL / 0 (Zero).
ALN_tpCondRet AlteraDados(Aluno *aluno, char *nome, int mat, int cpf, int telefone, Data *nasc, Endereco* end) {

	if (aluno == NULL)
		return ALN_CondRetAlunoNaoExiste;
	
	if (nome)
		strcpy(aluno->nome, nome);
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

	return ALN_CondRetOK;
}

ALN_tpCondRet SolicitaDados(char *nome, int *mat, int *cpf, int *telefone, Data *nasc, Endereco* end) {

	int retNasc;

	printf("Digite os dados do aluno: \n");

	printf("Nome Completo: ");	// Prompt para o nome do aluno.
	scanf(" %s", nome);

	printf("Matrícula (7 dígitos): ");	// Prompt para a matrícula do aluno.
	do {
		scanf(" %d", mat);
	} while (*mat < 1000000 && *mat > 9999999);

	printf("CPF (Sem caracteres especiais): ");	// Prompt para o CPF do aluno.
	do {
		scanf(" %ld", cpf);
	} while (*cpf < 10000000000 && *cpf > 99999999999);

	printf("Telefone: ");	// Prompt para o telefone do aluno.
	scanf(" %d", telefone);

	do {
		printf("Data de Nascimento: \n");	// Prompt para a data de nascimento do aluno.
		printf("Dia: ");
		scanf(" %hd", &nasc->dia);
		printf("\nMes: ");
		scanf(" %hd", &nasc->mes);
		printf("\nAno: ");
		scanf(" %hd", &nasc->ano);
		retNasc = ValidaData(nasc);
		if (!retNasc)
			printf("Data invalida");
	} while (!retNasc);

	printf("Endereco: \n");	// Prompt para o endereço o do aluno.
	printf("Estado: ");
	scanf(" %s", end->estado);
	printf("\nCidade: ");
	scanf(" %s", end->cidade);
	printf("\nBairro: ");
	scanf(" %s", end->bairro);
	printf("\nRua: ");
	scanf(" %s", end->rua);
	printf("\nComplemento: ");
	scanf(" %s", end->comp);

	return ALN_CondRetOK;
}

// Função que copia os dados do aluno
ALN_tpCondRet GetAll(Aluno *a, char *nome, int *mat, int *cpf, int *tel, Data *nasc, Endereco *endereco) {

	if (a == NULL)
		return ALN_CondRetAlunoNaoExiste;
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

	return ALN_CondRetOK;
}

// Função recebe um ponteiro pra aluno e imprime todos os seus dados
ALN_tpCondRet imprimeAluno(Aluno *a) {
	if (a == NULL)
		return ALN_CondRetAlunoNaoExiste;
	printf("Nome: %s \nMatricula: %d \nCPF: %ld \nTelefone: %d \nData de Nascimento: %hd/%hd/%hd \nEndereco: %s, %s, %s, %s, %s\n", a->nome, a->mat, a->cpf, a->telefone, a->nasc.dia, a->nasc.mes, a->nasc.ano, a->end.estado, a->end.cidade, a->end.bairro, a->end.rua, a->end.comp);
	return ALN_CondRetOK;
}

/* Função interna para validar uma data.
Considera a data atual do sistema como data limite.
Retorna 1 se a data for válida e 0 caso contrário.
Valida verificando o número de dias por mês, p. ex. O dia 31 de setembro não é válido. */
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
