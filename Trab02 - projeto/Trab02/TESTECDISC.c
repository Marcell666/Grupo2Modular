/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste espec�fico
*
*  Arquivo gerado:              TESTECDISC.C
*  Letras identificadoras:      TCDISC
*
*  Nome da base de software:    Teste Automatizado para o M�dulo Corpo Discente
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Bruno Marinho, BM
*			Matheus Zeitune, MZ
*			Fl�vio Franco, FF
*			Jo�o Cerqueira, JC
*			Vinicius Btechs, VB.
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       1.00   BM   09/09/2017 Desenvolvimento para T2 modificando TESTALN.C
*
*  $ED Descri��o do m�dulo
*     Este modulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo corpo discente. � um interpretador de comandos de teste espec�ficos
*	  utilizando o arcabou�o de teste para C.
*
*		CRIAR_CDISC_CMD		Cria o Corpo Discente				"=criar"
*		INS_CDISC_CMD		Insere um aluno no C. Disc.			"=inserir"
*		IMPINF_CDISC_CMD	Imprime a info de um aluno			"=impinfaluno"
*		ALT_CDISC_CMD		Altera dados de um aluno			"=altaluno"
*		RMV_CDISC_CMD		Remove um aluno do C. Disc.			"=remover"
*		IMP_CDISC_CMD		Imprime o C. Disc.					"=imprimir"
*		DEL_CDISC_CMD		Deleta o C. Disc.					"=deletar"
*		LMP_CDISC_CMD		Limpa o C. Disc.					"=limpar"
*
*		Comandos de teste espec�ficos para o m�dulo Corpo Discente:
*
*		"=criar" <int>CondRet
*
*		"=inserir" <string>nome <int>matricula <int>cpf3primDig <int>cpf3segDig
*		<int>cpf3TercDig <int>cpfcodVerif <int>telefone <int>diaNasc <int>mesNasc <int>anoNasc
*		<string>EndEstado <string>EndCidade <string>EndBairro <string>EndRua <string>EndComplemento
*		<int>CondRet
*
*       "=impinfaluno <int>matbusca <int>CondRet
*
*
*		"altaluno"<int>matbusca <string>nome <int>matricula <int>cpf3primDig <int>cpf3segDig
*		<int>cpf3TercDig <int>cpfcodVerif <int>telefone <int>diaNasc <int>mesNasc <int>anoNasc
*		<string>EndEstado <string>EndCidade <string>EndBairro <string>EndRua <string>EndComplemento
*		<int>CondRet
*
*		"=remover" <int>matbusca <int>CondRet
*
*		"=imprimir" <int>CondRet
*
*		"=deletar"  <int>CondRet
*
*		"=limpar"  <int>CondRet
*
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include	<stdlib.h>
#include    "corpodiscente.h"
#include	"aluno.h"
#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

/* Tabela dos nomes dos comandos de teste espec�ficos */

#define     CRIAR_CDISC_CMD		"=criar"
#define     INS_CDISC_CMD		"=inserir"
#define     IMPINF_CDISC_CMD	"=impinfaluno"
#define     ALT_CDISC_CMD       "=altaluno"
#define     RMV_CDISC_CMD		"=remover"
#define     IMP_CDISC_CMD		"=imprimir"
#define     DEL_CDISC_CMD		"=deletar"
#define     LMP_CDISC_CMD		"=limpar"

Endereco Endteste;
Data Datateste;
TST_tpCondRet TST_EfetuarComando(char * ComandoTeste)
{

	ALN_tpCondRet CondRetObtido = ALN_CondRetOK;
	ALN_tpCondRet CondRetEsperada = ALN_CondRetFaltouMemoria;
	/* inicializa para qualquer coisa,� s� para inicializar as vari�veis */
	unsigned int matbusca = -1;
	char StringEsperada[81];
	unsigned int MatEsperada = -1;
	CPF cpfEsperado;
	unsigned int telefoneEsperado;
	int dia;
	int mes;
	int ano;
	char estado[81];
	char cidade[81];
	char bairro[81];
	char rua[81];
	char complemento[81];
	int  NumLidos = -1;

	/* Testar criar lista de alunos*/

	if (strcmp(ComandoTeste, CRIAR_CDISC_CMD) == 0)
	{

		NumLidos = LER_LerParametros("i", &CondRetEsperada);
		if (NumLidos != 1)
		{
			return TST_CondRetParm;
		}
		CondRetObtido = CDI_cria();
		return TST_CompararInt(CondRetEsperada, CondRetObtido,
			"Retorno errado ao criar lista.");

	}

	/* Testar CDISC Insere aluno na lista do corpo discente*/

	if (strcmp(ComandoTeste, INS_CDISC_CMD) == 0)
	{

		NumLidos = LER_LerParametros("siiiiiiiiisssssi", StringEsperada, &MatEsperada, &cpfEsperado.dig1, &cpfEsperado.dig2, &cpfEsperado.dig3, &cpfEsperado.cod, &telefoneEsperado, &dia, &mes, &ano, estado, cidade, bairro, rua, complemento,
			&CondRetEsperada);
		if (NumLidos != 16)
		{
			return TST_CondRetParm;
		}
		/* testando se a matricula � valida, isto �, tem 7 n�meros */
		if (MatEsperada<1000000 || MatEsperada>9999999) {
			return TST_CondRetErro;
		}
		Datateste.dia = dia;
		Datateste.mes = mes;
		Datateste.ano = ano;
		strcpy(Endteste.estado, estado);
		strcpy(Endteste.cidade, cidade);
		strcpy(Endteste.bairro, bairro);
		strcpy(Endteste.rua, rua);
		strcpy(Endteste.comp, complemento);
		CondRetObtido = CDI_insere(StringEsperada, MatEsperada, &cpfEsperado, telefoneEsperado, &Datateste, &Endteste);
		return TST_CompararInt(CondRetEsperada, CondRetObtido,
			"Retorno errado ao inserir aluno na lista.");
	}


	/* Testar CDISC Altera dados de um aluno do corpo discente*/

	if (strcmp(ComandoTeste, ALT_CDISC_CMD) == 0)
	{

		NumLidos = LER_LerParametros("isiiiiiiiiisssssi", &matbusca, StringEsperada, &MatEsperada, &cpfEsperado.dig1, &cpfEsperado.dig2, &cpfEsperado.dig3, &cpfEsperado.cod, &telefoneEsperado, &dia, &mes, &ano, estado, cidade, bairro, rua, complemento,
			&CondRetEsperada);
		if (NumLidos != 17)
		{
			return TST_CondRetParm;
		}
		/* testando se a matricula � valida, isto �, tem 7 n�meros */
		if (MatEsperada<1000000 || MatEsperada>9999999) {
			return TST_CondRetErro;
		}
		Datateste.dia = dia;
		Datateste.mes = mes;
		Datateste.ano = ano;
		strcpy(Endteste.estado, estado);
		strcpy(Endteste.cidade, cidade);
		strcpy(Endteste.bairro, bairro);
		strcpy(Endteste.rua, rua);
		strcpy(Endteste.comp, complemento);
		CondRetObtido = CDI_altera(matbusca, StringEsperada, MatEsperada, &cpfEsperado, telefoneEsperado, &Datateste, &Endteste);
		return TST_CompararInt(CondRetEsperada, CondRetObtido,
			"Retorno errado ao alterar dados do Aluno.");
	}

	/* Testar remove aluno da lista */

	else if (strcmp(ComandoTeste, RMV_CDISC_CMD) == 0)
	{
		NumLidos = LER_LerParametros("ii", &matbusca, &CondRetEsperada);
		if (NumLidos != 2)
		{
			return TST_CondRetParm;
		}
		CondRetObtido = CDI_remove(matbusca);
		return TST_CompararInt(CondRetEsperada, CondRetObtido, "Retorno errado");
	}

	/* Testar imprimir todos os alunos da lista corpo discente */

	else if (strcmp(ComandoTeste, IMP_CDISC_CMD) == 0)
	{
		NumLidos = LER_LerParametros("i", &CondRetEsperada);
		if (NumLidos != 1)
		{
			return TST_CondRetParm;
		}
		CondRetObtido = CDI_imprime();
		return TST_CompararInt(CondRetEsperada, CondRetObtido, "Retorno Errado");
	}

	/* Testar imprimir info de um aluno da lista corpo discente */

	else if (strcmp(ComandoTeste, IMPINF_CDISC_CMD) == 0)
	{
		NumLidos = LER_LerParametros("ii", &matbusca, &CondRetEsperada);
		if (NumLidos != 2)
		{
			return TST_CondRetParm;
		}
		CondRetObtido = CDI_imprimeInfo(matbusca);
		return TST_CompararInt(CondRetEsperada, CondRetObtido, "Retorno Errado");
	}

	/* Testar deletar o corpo discente */

	else if (strcmp(ComandoTeste, DEL_CDISC_CMD) == 0)
	{
		NumLidos = LER_LerParametros("i", &CondRetEsperada);
		if (NumLidos != 1)
		{
			return TST_CondRetParm;
		}
		CondRetObtido = CDI_deleta();
		return TST_CompararInt(CondRetEsperada, CondRetObtido, "Retorno Errado");
	}

	/* Testar limpar todos os alunos do corpo discente */

	else if (strcmp(ComandoTeste, LMP_CDISC_CMD) == 0)
	{
		NumLidos = LER_LerParametros("i", &CondRetEsperada);
		if (NumLidos != 1)
		{
			return TST_CondRetParm;
		}
		CondRetObtido = CDI_limpa();
		return TST_CompararInt(CondRetEsperada, CondRetObtido, "Retorno Errado");
	}
	return TST_CondRetNaoConhec;
}