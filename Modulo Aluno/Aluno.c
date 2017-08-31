#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"

typedef struct {
	char *nome;
	int mat;
	int cpf;
	int telefone;
	char *curso;
	Endereco endereco;
	Data data;
}Aluno;

/*Recebe um ponteiro para aluno e desaloca o espaço de memória apontado pelo mesmo*/
int deleta_Aluno (Aluno *a){
	free (a);
	return (0);
}

/*Recebe um ponteiro para aluno e outro para um inteiro e retorna a matrícula do aluno pelo ponteiro para inteiro.*/
int GetMat (Aluno *a, int mat){
	mat = a->mat;
	return (0);
}
/*Recebe um ponteiro para aluno e outro para um char e retorna o nome do aluno pelo ponteiro para char.*/
int GetNome (Aluno *a,char* nome){
   strcpy(nome,a->nome);
   return(0);
}

//Cria um único vazio aluno passado por referencia.
int CriaAlunoVazio(Aluno *a){
	a = (*Aluno) malloc(sizeof(Aluno));

	if(a == NULL){
		printf("\nError na criação do Aluno\n);
		exit(1);
	}

	a->nome = NULL;
	a->mat = NULL;
	a->cfp = NULL;
	a->telefone = NULL;
	a->curso = NULL;
	a->endereco.estado = NULL;
	a->endereco.cidade = NULL;
	a->endereco.bairro = NULL;
	a->endereco.rua = NULL;
	a->endereco.comp = NULL;
	a->data.dia = NULL;
	a->data.mes = NULL;
	a->data.ano = NULL;

	return (0);
}
