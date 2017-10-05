/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo Corpo Docente
*
*  Arquivo gerado:              corpoDocente.C
*  Letras identificadoras:      CDO
*
*  Nome da base de software:    Fonte do m�dulo Corpo Docente
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Bruce Marcellino, BM  
*			Felipe Alfena, FA
*			Nicolas Paes, NP
*			Mariana Ruddy, MR
*			Rodrigo Pumar, RP.
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor 	Data     	Observa��es
*       0.52   BM/RP	04/10/2017	Revis�o
*       0.51   BM   	04/10/2017	Revis�o
*       0.50   RP   	03/10/2017	Documenta��o
*       0.40   FA  	03/10/2017	Fun��es busca adicionadas
*       0.30   MR   	03/10/2017	Fun��es de consulta/altera adicionadas 
*       0.20   BM   	02/10/2017	Funcoes modelo adicionadas 
*       0.10   BM  	01/10/2017	Inicio do desenvolvimento 
*
*  $ED Descri��o do m�dulo
*     Este m�dulo cont�m as fun��es espec�ficas para manipular os professores na lista de corpo docente.
*     Este m�dulo utiliza func�es de interface do modulo professor.
***************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "corpoDocente.h"
#include "professor.h"
#include "listas.h"

/***********************************************************************
*
*  $TC Tipo de dados: corpoDocente
*
*
*  $ED Descri��o do tipo
*     Estrutura principal que armazena os dados de um corpo docente ao qual este m�dulo se dedica.
*
***********************************************************************/

typedef struct corpoDocente{
	List *professores;
} CorpoDocente;


/*****  Dados encapsulados no m�dulo  *****/
	
static CorpoDocente *doc;
	/* inst�ncia de corpo docente armazenada por este m�dulo */

/***** Prot�tipos das fun��es encapsuladas no m�dulo *****/

CDO_tpCondRet buscaIdentificacao(int rgChave, char *cpfChave, int matriculaChave, char *emailChave);


/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: CDO Criar Lista de Corpo Docente
*  ****/

CDO_tpCondRet CDO_cria(){
	doc = (CorpoDocente*) malloc(sizeof(CorpoDocente));
	createList(&doc->professores);
	return CDO_CondRetOk;
}/* Fim fun��o: CDO Criar Lista de Corpo Docente */

/***************************************************************************
*
*  Fun��o: CDO Cadastrar Professor
*  ****/

CDO_tpCondRet CDO_cadastra(char *nome, int rg, char *cpf, int matricula, char *email, int telefone, int dia, int mes, int ano, char *pais, char *uf, char *cidade, char *bairro, char *rua, int numero, char *complemento){
	PRF_ptProfessor prof = NULL;
	PRF_tpCondRet ret;
	if(buscaIdentificacao(rg, cpf, matricula, email) != CDO_CondRetOk)
		return CDO_CondRetIdJaCriado;
	ret = PRF_cria(&prof, nome, rg, cpf, matricula, email, telefone, dia, mes, ano, pais, uf, cidade, bairro, rua, numero, complemento);
	if(ret == PRF_CondRetNaoHaMemoria) return CDO_CondRetNaoHaMemoria;
	if(ret == PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	push_back(doc->professores, prof);
	return CDO_CondRetOk;
}/* Fim fun��o: CDO Cadastrar Professor */

/***********************************************************************
*
*  $FC Fun��o: CDO Busca Identificacao
*
*  $FV Valor retornado
*     Retorna CDO_CondRetIdJaCriado caso um professor com o mesmo valor de uma das chaves seja encontrado.
*     Retorna PRF_CondRetOk caso contr�rio.
*
***********************************************************************/
CDO_tpCondRet buscaIdentificacao(int rgChave, char *cpfChave, int matriculaChave, char *emailChave){
	PRF_ptProfessor prof = NULL;
	char cpf[PRF_TAM_STRING];
	char email[PRF_TAM_STRING];
	int matricula;
	int rg;
	first(doc->professores);
	do{
		if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetOk;

		PRF_consultaCpf(prof, cpf);
		PRF_consultaRg(prof, &rg);
		PRF_consultaEmail(prof, email);
		PRF_consultaMatricula(prof, &matricula);
		if(strcmp(cpfChave, cpf)==0 || strcmp(emailChave, email)==0 || rgChave == rg || matriculaChave == matricula) return CDO_CondRetIdJaCriado;
	}while(next(doc->professores)==LIS_CondRetOK);

	/* N�o encontrou */
	return CDO_CondRetOk;
}/* Fim fun��o: CDO Busca Atual */

/***************************************************************************
*
*  Fun��o: CDO Mostra Atual
*  ****/

CDO_tpCondRet CDO_mostraAtual(){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof)== LIS_CondRetListaVazia) return CDO_CondRetCorpoDocenteVazio;
	PRF_mostra(prof);
	return CDO_CondRetOk;
}/* Fim fun��o: CDO Mostra Atual */

 /***************************************************************************
 *
 *  Fun��o: CDO Mosta Todos Professores
 *  ****/

CDO_tpCondRet CDO_mostraTodos(){
	PRF_ptProfessor prof = NULL;
	first(doc->professores);
	do{
		if(get_val_cursor(doc->professores, (void**) &prof)== LIS_CondRetListaVazia) return CDO_CondRetCorpoDocenteVazio;
		PRF_mostra(prof);
	}while(next(doc->professores)==LIS_CondRetOK);
	return CDO_CondRetOk;
}/* Fim fun��o: CDO Mosta Todos Professores */

 /***************************************************************************
 *
 *  Fun��o: CDO Limpa Lista
 *  ****/

CDO_tpCondRet CDO_limpa(){
	clear(doc->professores);
	return CDO_CondRetOk;
}/* Fim fun��o: CDO Limpa Lista */

 /***************************************************************************
 *
 *  Fun��o: CDO Retira da Lista
 *  ****/

CDO_tpCondRet CDO_retira(){
	void *nulo;
	if(pop_cursor(doc->professores, &nulo) == LIS_CondRetListaVazia) return CDO_CondRetCorpoDocenteVazio;
	return CDO_CondRetOk;
}/* Fim fun��o: CDO Retira da Lista */

 /***************************************************************************
 *
 *  Fun��o: CDO Libera
 *  ****/

CDO_tpCondRet CDO_libera(){
	del(doc->professores);
	return CDO_CondRetOk;
}/* Fim fun��o: CDO Libera */

 /***************************************************************************
 *
 *  Fun��o: CDO Busca Por RG
 *  ****/

CDO_tpCondRet CDO_buscaPorRg(int chave){
	PRF_ptProfessor prof = NULL;
	int rg;

	first(doc->professores);
	do{
		if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;

		PRF_consultaRg(prof, &rg);
		if(chave == rg) 
			return CDO_CondRetOk;
	}while(next(doc->professores)==LIS_CondRetOK);

	return CDO_CondRetProfessorNaoEncontrado;
}/* Fim fun��o: CDO Busca Por RG */

 /***************************************************************************
 *
 *  Fun��o: CDO Busca Por CPF
 *  ****/
CDO_tpCondRet CDO_buscaPorCpf(char *chave){
	PRF_ptProfessor prof = NULL;
	char cpf[PRF_TAM_STRING];

	first(doc->professores);
	do{
		if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;

		PRF_consultaCpf(prof, cpf);
		if(strcmp(chave, cpf)==0)
			return CDO_CondRetOk;
	}while(next(doc->professores)==LIS_CondRetOK);

	return CDO_CondRetProfessorNaoEncontrado;
}/* Fim fun��o: CDO Busca Por CPF */

 /***************************************************************************
 *
 *  Fun��o: CDO Busca Por Matricula
 *  ****/

CDO_tpCondRet CDO_buscaPorMatricula(int chave){
	PRF_ptProfessor prof = NULL;
	int matricula;

	first(doc->professores);
	do{
		if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;

		PRF_consultaMatricula(prof, &matricula);
		if(chave == matricula) 
			return CDO_CondRetOk;
	}while(next(doc->professores)==LIS_CondRetOK);

	return CDO_CondRetProfessorNaoEncontrado;
}/* Fim fun��o: CDO Busca Por Matricula */

 /***************************************************************************
 *
 *  Fun��o: CDO Busca Por Email
 *  ****/

CDO_tpCondRet CDO_buscaPorEmail(char *chave){
	PRF_ptProfessor prof = NULL;
	char email[PRF_TAM_STRING];

	first(doc->professores);
	do{
		if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;

		PRF_consultaEmail(prof, email);
		if(strcmp(chave, email)==0)
			return CDO_CondRetOk;
	}while(next(doc->professores)==LIS_CondRetOK);

	return CDO_CondRetProfessorNaoEncontrado;
}/* Fim fun��o: CDO Busca Por Email */

 /***************************************************************************
 *
 *  Fun��o: CDO Consulta Nome
 *  ****/
CDO_tpCondRet CDO_consultaNome(char *nome){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	PRF_consultaNome(prof, nome);
	return CDO_CondRetOk;
}/* Fim fun��o: CDO Consulta Nome*/

 /***************************************************************************
 *
 *  Fun��o: CDO Consulta RG
 *  ****/
CDO_tpCondRet CDO_consultaRg(int *rg){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	PRF_consultaRg(prof,rg);
	return CDO_CondRetOk;
}/* Fim fun��o: CDO Consulta RG */

 /***************************************************************************
 *
 *  Fun��o: CDO Consulta CPF
 *  ****/
CDO_tpCondRet CDO_consultaCpf(char *cpf){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	PRF_consultaCpf(prof, cpf);
	return CDO_CondRetOk;
}/* Fim fun��o: CDO Consulta CPF*/

 /***************************************************************************
 *
 *  Fun��o: CDO Consulta Matricula
 *  ****/
CDO_tpCondRet CDO_consultaMatricula(int *matricula){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	PRF_consultaMatricula(prof,matricula);
	return CDO_CondRetOk;
}/* Fim fun��o: CDO Consulta Matricula*/

 /***************************************************************************
 *
 *  Fun��o: CDO Consulta Email
 *  ****/
CDO_tpCondRet CDO_consultaEmail(char *email){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	PRF_consultaEmail(prof, email);
	return CDO_CondRetOk;
}/* Fim fun��o: CDO Consulta Email*/

 /***************************************************************************
 *
 *  Fun��o: CDO Consulta Telefone
 *  ****/
CDO_tpCondRet CDO_consultaTelefone(int *tel){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	PRF_consultaTelefone(prof, tel);
	return CDO_CondRetOk;
}/* Fim fun��o: CDO Consulta Telefone*/

 /***************************************************************************
 *
 *  Fun��o: CDO Consulta Data de Nascimento
 *  ****/
CDO_tpCondRet CDO_consultaDataNascimento(int *dia, int *mes, int *ano){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	PRF_consultaDiaNascimento(prof, dia);
	PRF_consultaMesNascimento(prof, mes);
	PRF_consultaAnoNascimento(prof, ano);
	return CDO_CondRetOk;
}/* Fim fun��o: CDO Consulta Data de Nascimento*/

 /***************************************************************************
 *
 *  Fun��o: CDO Consulta Endere�o
 *  ****/
CDO_tpCondRet CDO_consultaEndereco(char *pais, char *uf, char *cidade, char *bairro, char *rua, int *numero, char *complemento){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	PRF_consultaPais(prof,pais);
	PRF_consultaUf(prof,uf);
	PRF_consultaCidade(prof,cidade);
	PRF_consultaBairro(prof,bairro);
	PRF_consultaRua(prof,rua);
	PRF_consultaNumero(prof,numero);
	PRF_consultaComplemento(prof,complemento);
	return CDO_CondRetOk;
}/* Fim fun��o: CDO Consulta Endere�o*/

 /***************************************************************************
 *
 *  Fun��o: CDO Altera Nome
 *  ****/
CDO_tpCondRet CDO_alteraNome(char *nome){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	if(PRF_alteraNome(prof, nome)==PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	return CDO_CondRetOk;
}/* Fim fun��o: CDO Altera Nome*/

 /***************************************************************************
 *
 *  Fun��o: CDO Altera RG
 *  ****/
CDO_tpCondRet CDO_alteraRg(int rg){
	PRF_ptProfessor prof = NULL;
	int id;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	PRF_consultaMatricula(prof, &id);
	if(CDO_buscaPorRg(rg) == CDO_CondRetOk) return CDO_CondRetIdJaCriado;
	/* Retornando cursor para posicao original */
	CDO_buscaPorMatricula(id);
	if(PRF_alteraRg(prof,rg)==PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	return CDO_CondRetOk;
}/* Fim fun��o: CDO Altera RG*/

 /***************************************************************************
 *
 *  Fun��o: CDO Altera CPF
 *  ****/
CDO_tpCondRet CDO_alteraCpf(char *cpf){
	PRF_ptProfessor prof = NULL;
	int id;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	PRF_consultaMatricula(prof, &id);
	if(CDO_buscaPorCpf(cpf) == CDO_CondRetOk) return CDO_CondRetIdJaCriado;
	/* Retornando cursor para posicao original */
	CDO_buscaPorMatricula(id);
	if(PRF_alteraCpf(prof, cpf)==PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	return CDO_CondRetOk;
}/* Fim fun��o: CDO Altera CPF*/

 /***************************************************************************
 *
 *  Fun��o: CDO Altera Matricula
 *  ****/
CDO_tpCondRet CDO_alteraMatricula(int matricula){
	PRF_ptProfessor prof = NULL;
	int id;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	PRF_consultaMatricula(prof, &id);
	if(CDO_buscaPorMatricula(matricula) == CDO_CondRetOk) return CDO_CondRetIdJaCriado;
	/* Retornando cursor para posicao original */
	CDO_buscaPorMatricula(id);
	if(PRF_alteraMatricula(prof, matricula)==PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	return CDO_CondRetOk;
}/* Fim fun��o: CDO Altera Matricula*/

 /***************************************************************************
 *
 *  Fun��o: CDO Altera Email
 *  ****/
CDO_tpCondRet CDO_alteraEmail(char* email){
	PRF_ptProfessor prof = NULL;
	int id;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	PRF_consultaMatricula(prof, &id);
	if(CDO_buscaPorEmail(email) == CDO_CondRetOk) return CDO_CondRetIdJaCriado;
	/* Retornando cursor para posicao original */
	CDO_buscaPorMatricula(id);
	if(PRF_alteraEmail(prof, email)==PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	return CDO_CondRetOk;
}/* Fim fun��o: CDO Altera Email*/

 /***************************************************************************
 *
 *  Fun��o: CDO Altera Telefone
 *  ****/
CDO_tpCondRet CDO_alteraTelefone(int tel){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	if(PRF_alteraTelefone(prof, tel)==PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	return CDO_CondRetOk;
}/* Fim fun��o: CDO Altera Telefone*/

 /***************************************************************************
 *
 *  Fun��o: CDO Altera Data de Nascimento
 *  ****/
CDO_tpCondRet CDO_alteraDataNascimento(int dia, int mes, int ano){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	if(PRF_alteraDataNascimento(prof, dia, mes, ano)==PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	return CDO_CondRetOk;
}/* Fim fun��o: CDO Altera Data de Nascimento*/

 /***************************************************************************
 *
 *  Fun��o: CDO Altera Endereco
 *  ****/
CDO_tpCondRet CDO_alteraEndereco(char *pais, char *uf, char *cidade, char *bairro, char *rua, int numero, char *complemento){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	if(PRF_alteraPais(prof,pais)==PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	if(PRF_alteraUf(prof,uf)==PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	if(PRF_alteraCidade(prof,cidade)==PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	if(PRF_alteraBairro(prof,bairro)==PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	if(PRF_alteraRua(prof,rua)==PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	if(PRF_alteraNumero(prof,numero)==PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	if(PRF_alteraComplemento(prof,complemento)==PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	return CDO_CondRetOk;
}/* Fim fun��o: CDO Altera Endereco*/
