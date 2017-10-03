/***************************************************************************
*  $MCI M�dulo de implementa��o: TUR  Turma
*
*  Arquivo gerado:              TURMA.c
*  Letras identificadoras:      TUR
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: cgln - Cristiane - Guilherme - Leonardo - Nath�lia
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     3       cgln  10/set/2017 manuten��o das fun��es do m�dulo
*     2       cgln  07/set/2017 unifica��o de todos os m�dulos em um s� projeto
*     1       cgln  29/ago/2017 in�cio desenvolvimento
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TURMA.h"

/***********************************************************************
*
*  $TC Tipo de dados: TUR turma
*
*
***********************************************************************/

	struct turma {

		char CodTurma [4] ;
			/* C�digo da turma */

		int HorarioInicio ;
			/* Hor�rio de in�cio da turma */

		int HorarioTermino ;
			/* Hor�rio de t�rmino da turma */

		char DiaSemana[28] ;
			/* Dias da semana da turma */

		int QtdVaga ;
			/* N�mero de vagas da turma */

	};

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
* Fun��o: TUR  &Cria turma
*  ****/

	TUR_tpCondRet TUR_CriaTurma ( Turma ** NovaTurma, char * CodTur,
		int HorIni, int HorTer, char * DiaSem, int QtdVag )
	{

		* NovaTurma = ( Turma * ) malloc( sizeof( Turma )) ;

		if ( * NovaTurma == NULL )
		{
			return TUR_CondRetFaltouMemoria ;
		} /* if */
		
		strcpy( ( *NovaTurma )->CodTurma, CodTur ) ;

		if ( HorIni < 7 || HorIni > 21 )
		{
			return TUR_CondRetFormatoInvalido;
		} /* if */

		( *NovaTurma )->HorarioInicio = HorIni ;

		if ( HorTer < 07 || HorTer > 23) 
		{
			return TUR_CondRetFormatoInvalido ;
		} /* if */

		( *NovaTurma )->HorarioTermino = HorTer ;

		strcpy( ( *NovaTurma )->DiaSemana, DiaSem ) ;

		( *NovaTurma )->QtdVaga = QtdVag ;

		return TUR_CondRetOk ;

	} /* Fim fun��o: TUR  &Cria turma */

/***************************************************************************
*
*  Fun��o: TUR  &Altera horario inicio
*  ****/

	TUR_tpCondRet TUR_AlteraHorarioInicio ( Turma * tur, int hora1 )
	{

		if ( hora1 < 7 || hora1 > 21 )
		{
			return TUR_CondRetFormatoInvalido ;
		} else
		{
			tur->HorarioInicio = hora1 ;
			printf( "Hora alterada" ) ;
			return TUR_CondRetOk ;
		} /* if */
	
	} /* Fim fun��o: TUR  &Altera horario inicio */
  
/***************************************************************************
*
*  Fun��o: TUR  &Altera horario final
*  ****/
   
    TUR_tpCondRet TUR_AlteraHorarioFinal ( Turma * tur, int hora2 )
    {

        if ( hora2 < 9 || hora2 > 23 )
		{
			return TUR_CondRetFormatoInvalido ;
		} else
		{
			tur->HorarioTermino = hora2 ;
			printf( "Hora alterada" ) ;
			return TUR_CondRetOk ;
		} /* if */

	} /* Fim fun��o: TUR  &Altera horario final */

/***************************************************************************
*
*  Fun��o: TUR  &Altera dia
*  ****/

	TUR_tpCondRet TUR_AlteraDia ( Turma * tur, char * dia )
	{

		strcpy( tur->DiaSemana, dia ) ;
		printf( "Dias alterados" ) ;
        return TUR_CondRetOk ;

    } /* Fim fun��o: TUR  &Altera dia */

/***************************************************************************
*
*  Fun��o: TUR  &Altera codigo
*  ****/

	TUR_tpCondRet TUR_AlteraCodigo ( Turma * tur, char * cod )
	{ 

		strcpy( tur->CodTurma, cod ) ;
		printf( "Codigo alterado" ) ;
		return TUR_CondRetOk ;

	} /* Fim fun��o: TUR  &Altera codigo */

/***************************************************************************
*
*  Fun��o: TUR  &Altera qtd vaga
*  ****/

	TUR_tpCondRet TUR_AlteraQtdVaga ( Turma * tur, int qtd )
	{

		tur->QtdVaga = qtd ;
		printf( "Quantidade alterada" ) ;
		return TUR_CondRetOk ;

	} /* Fim fun��o: TUR  &Altera qtd vaga */

/***************************************************************************
*
*  Fun��o: TUR  &Get codigo
*  ****/

	TUR_tpCondRet TUR_GetCodigo ( Turma * tur, char * CodTur)
	{

		strcpy( CodTur, tur->CodTurma ) ;
		return TUR_CondRetOk ;
		
	} /* Fim fun��o: TUR  &Get codigo */

/***************************************************************************
*
*  Fun��o: TUR  &Get hor�rio inicio
*  ****/

	TUR_tpCondRet TUR_GetHorIni ( Turma * tur, int * HorIni)
	{

		*HorIni = tur->HorarioInicio ;
		return TUR_CondRetOk ;

	} /* Fim fun��o: TUR  &hor�rio inicio */

/***************************************************************************
*
*  Fun��o: TUR  &Get hor�rio final
*  ****/

	TUR_tpCondRet TUR_GetHorFin ( Turma * tur, int * HorTer )
	{

		*HorTer = tur->HorarioTermino ;
		return TUR_CondRetOk ;

	}  /* Fim fun��o: TUR  &hor�rio final */

/***************************************************************************
*
*  Fun��o: TUR  &Get dia
*  ****/

	TUR_tpCondRet TUR_GetDiaSem ( Turma * tur, char * DiaSem ) 
	{

		strcpy( DiaSem, tur->DiaSemana ) ;
		return TUR_CondRetOk ;

	}  /* Fim fun��o: TUR  &Get dia */

/***************************************************************************
*
*  Fun��o: TUR  &Get qtd vaga
*  ****/
	
	TUR_tpCondRet TUR_GetQtdVaga ( Turma * tur, int * QtdVag )
	{

		*QtdVag = tur->QtdVaga ;
		return TUR_CondRetOk ;

	} /* Fim fun��o: TUR  &Get qtd vaga */

/***************************************************************************
*
*  Fun��o: TUR  &Get turma
*  ****/

	TUR_tpCondRet TUR_GetTurma ( Turma * tur, char * CodTur, int * HorIni, int * HorTer,
		char * DiaSem, int * QtdVag )
	{

		strcpy( CodTur, tur->CodTurma ) ;
		*HorIni = tur->HorarioInicio ;
		*HorTer = tur->HorarioTermino ;
		strcpy( DiaSem, tur->DiaSemana ) ;
		*QtdVag = tur->QtdVaga ;

		return TUR_CondRetOk ;

	}  /* Fim fun��o: TUR  &Get turma */

/***************************************************************************
*
*  Fun��o: TUR &Exibe turma
*  ****/
	
	TUR_tpCondRet TUR_ExibeTurma ( Turma * tur )
	{

		puts( "\n\n****** TURMA SELECIONADA ******" ) ;
		printf( "\nCodigo: %s",tur->CodTurma ) ;
		printf( "\nHorario de inicio: %d:00",tur->HorarioInicio ) ;
		printf( "\nHorario de termino: %d:00",tur->HorarioTermino ) ;
		printf( "\nDias da semana: %s",tur->DiaSemana ) ;
		printf( "\nQuantidade de vagas: %d\n\n",tur->QtdVaga ) ;

		return TUR_CondRetOk ;

	} /* Fim fun��o: TUR  &Exibe turma */

/***************************************************************************
*
*  Fun��o: TUR  &Exclui turma
*  ****/

	TUR_tpCondRet TUR_ExcluiTurma ( Turma * turma )
	{

		free( turma ) ;
		
		return TUR_CondRetOk ;

	} /* Fim fun��o: TUR  &Exclui turma */

/********** Fim do m�dulo de implementa��o: TUR  Turma **********/