#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MEN_menuInicial(void);
void MEN_menuAluno(void);
int MEN_loginAluno(void);
int MEN_loginProfessor(void);
void MEN_menuProfessor(void);
void MEN_menuPAdministrativo(void);
int MEN_loginAdministrativo(void);

void MEN_menuInicial(void)
{
	int opcao = 0;

	while(opcao != 4)
	{
		printf("\nMenu SAU\n");
		printf("\nDigite 1: ir menu Aluno");
		printf("\nDigite 2: ir menu Professor");
		printf("\nDigite 3: ir menu Administrativo");
		printf("\nDigite 4: para sair\n");
		scanf("%d", &opcao);

		switch(opcao)
		{
			case 1:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				MEN_menuAluno();
				break;
			case 2:
				system("cls");
				 MEN_menuProfessor();
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 3:
				system("cls");
				MEN_menuPAdministrativo();
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			default:
				if(opcao != 4)
				{
					system("cls");
					printf("\n\nOPCAO INVALIDA!!!!!\n\n");
				}
				break;
		}
	}
}

void MEN_menuAluno(void)
{
	int opcao = 0;

	if(MEN_loginAluno() == 1) // Se volta 1, ok.

	while(opcao != 8)
	{
		printf("\nMenu Aluno\n");
		printf("\nDigite 1: ver disciplinas");
		printf("\nDigite 2: ver horarios");
		printf("\nDigite 3: ver nota");
		printf("\nDigite 4: ver historico");
		printf("\nDigite 5: modificar dados pessoais");
		printf("\nDigite 6: cancelar disciplina");
		printf("\nDigite 7: trancar a faculdade");
		printf("\nDigite 8: sair\n");
		scanf("%d", &opcao);

		switch(opcao)
		{
			case 1:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 2:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 3:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 4:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 5:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 6:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 7:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 8:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			default:
				if(opcao != 8)
				{
					system("cls");
					printf("\n\nOPCAO INVALIDA!!!!!\n\n");
				}
				break;
		}
	}
}

int MEN_loginAluno(void)
{
	char mat[81];

	printf("\nLogin Aluno\n");

	printf("\nDigite a matricula: ");
	scanf("%s", mat);

	//Quando o modulo aluno estive funcionado ir� ser feita
	system("cls");
	return 1;
}

int MEN_loginProfessor(void)
{
	char mat[81];

	printf("\nLogin Professor\n");

	printf("\nDigite a matricula: ");
	scanf(" %s", mat);

	//Quando o modulo aluno estive funcionado ir� ser feita
	system("cls");
	return 1;
}

void MEN_menuProfessor(void)
{
	int opcao = 0;

	if(MEN_loginProfessor() == 1) // Se volta 1, ok.

	while(opcao != 6)
	{
		printf("\nMenu Aluno\n");
		printf("\nDigite 1: ver disciplinas");
		printf("\nDigite 2: ver horarios");
		printf("\nDigite 3: ver nota");
		printf("\nDigite 4: ver turmas");
		printf("\nDigite 5: modificar dados pessoais");
		printf("\nDigite 6: sair\n");
		scanf("%d", &opcao);

		switch(opcao)
		{
			case 1:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 2:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 3:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 4:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 5:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			default:
				if(opcao != 6)
				{
					system("cls");
					printf("\n\nOPCAO INVALIDA!!!!!\n\n");
				}
				break;
		}
	}

}

void MEN_menuPAdministrativo(void)
{
	int opcao = 0;

	if(MEN_loginAdministrativo() == 1) // Se volta 1, ok.

	while(opcao != 16)
	{
		printf("\nMenu Aluno\n");
		printf("\nDigite 1: ver alunos");
		printf("\nDigite 2: ver professores");
		printf("\nDigite 3: ver disciplina");
		printf("\nDigite 4: ver criterio de aprova��o");
		printf("\nDigite 5: adicionar aluno");
		printf("\nDigite 6: deletar aluno");
		printf("\nDigite 7: adicionar professor");
		printf("\nDigite 8: deletar professor");
		printf("\nDigite 9: deletar sala");
		printf("\nDigite 10: adicionar sala");
		printf("\nDigite 11: deletar turma");
		printf("\nDigite 12: adicionar turma");
		printf("\nDigite 13: modificar grade");
		printf("\nDigite 14: modificar dados pessoais de um aluno");
		printf("\nDigite 15: modificar dados pessoais de um professor");
		printf("\nDigite 16: sair\n");
		scanf("%d", &opcao);

		switch(opcao)
		{
			case 1:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 2:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 3:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 4:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 5:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 6:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 7:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 8:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 9:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 10:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 11:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 12:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 13:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 14:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 15:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			default:
				if(opcao != 16)
				{
					system("cls");
					printf("\n\nOPCAO INVALIDA!!!!!\n\n");
				}
				break;
		}
	}
}

int MEN_loginAdministrativo(void)
{
	char mat[81];
	char senha[81];
	printf("\nLogin Administrador\n");

	printf("\nDigite a matricula: ");
	scanf(" %s", mat);

	printf("\nDigite a senha: ");
	scanf(" %s", senha);

	if(strcomp("admin", mat) == 0 && strcomp("admin", senha) == 0 )
	{
		system("cls");
		return 1;
	}

	system("cls");
	return 0;
}