
typedef enum{
	MEN_CondRetOK,	// Executou corretamente
	MEN_CondReteERRO // H� erros
}	MEN_tpCondRet;

//Primeiro menu a ser exibido. Retorna 1, quando n�o h� erro. Retorna 0, quando h� erro.
MEN_tpCondRet MenuInicial(void);

//Menu que possui todas as op��es ligada ao modulo professor. Retorna 1, quando n�o h� erro. Retorna 0, quando h� erro.
MEN_tpCondRet MenuProfessor(void);

//Menu que possui todas as op��es ligadas ao modulo aluno. Retorna 1, quando n�o h� erro. Retorna 0, quando h� erro.
MEN_tpCondRet MenuAluno(void);

//Menu que possui todas as op��es administrativas. Retorna 1, quando n�o h� erro. Retorna 0, quando h� erro.
MEN_tpCondRet MenuAdmistrador(void);

//Autentica��o para alunos. Retorna 1, quando n�o h� erro. Retorna 0, quando h� erro.
MEN_tpCondRet LoginAluno(void);

//Autentica��o para professores. Retorna 1, quando n�o h� erro. Retorna 0, quando h� erro.
MEN_tpCondRet LoginProfessor(void);

//Autentica��o para administradores. Retorna 1, quando n�o h� erro. Retorna 0, quando h� erro.
MEN_tpCondRet LoginAdmistrador(void);

//Essa fun��o ser� respons�vel pela funcionalidades administrativas. Retorna 1, quando n�o h� erro. Retorna 0, quando h� erro.
MEN_tpCondRet ProsLoginAdmistrador(void);

//Essa fun��o ser� respons�vel pela funcionalidades dos professores. Retorna 1, quando n�o h� erro. Retorna 0, quando h� erro.
MEN_tpCondRet ProsLoginProfessor(void);

//Essa fun��o ser� respons�vel pela funcionalidades dos alunos. Retorna 1, quando n�o h� erro. Retorna 0, quando h� erro.
MEN_tpCondRet ProsLoginAluno(void);
