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


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disciplina.h"
#include "listas.h"
#include "professor.h"
#include "sala.h"
#include "turma.h"
#include "menu.h"
#include "corpodiscente.h"
#include "corpoDocente.h"
#include "aluno.h"

/***************************************************************************
*
*  Fun��o: MEN_menuInicial
*  ****/

int main(void)
{
	MEN_menuInicial();
	return 0;
}