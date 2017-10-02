//Primeiro menu a ser exibido. Retorna 1, quando n�o h� erro. Retorna 0, quando h� erro.
int MenuInicial(void);

//Menu que possui todas as op��es ligada ao modulo professor. Retorna 1, quando n�o h� erro. Retorna 0, quando h� erro.
int MenuProfessor(void);

//Menu que possui todas as op��es ligadas ao modulo aluno. Retorna 1, quando n�o h� erro. Retorna 0, quando h� erro.
int MenuAluno(void);

//Menu que possui todas as op��es administrativas. Retorna 1, quando n�o h� erro. Retorna 0, quando h� erro.
int MenuAdmistrador(void);

//Autentica��o para alunos. Retorna 1, quando n�o h� erro. Retorna 0, quando h� erro.
int LoginAluno(void);

//Autentica��o para professores. Retorna 1, quando n�o h� erro. Retorna 0, quando h� erro.
int LoginProfessor(void);

//Autentica��o para administradores. Retorna 1, quando n�o h� erro. Retorna 0, quando h� erro.
int LoginAdmistrador(void);

//Essa fun��o ser� respons�vel pela funcionalidades administrativas. Retorna 1, quando n�o h� erro. Retorna 0, quando h� erro.
int ProsLoginAdmistrador(void);

//Essa fun��o ser� respons�vel pela funcionalidades dos professores. Retorna 1, quando n�o h� erro. Retorna 0, quando h� erro.
int ProsLoginProfessor(void);

//Essa fun��o ser� respons�vel pela funcionalidades dos alunos. Retorna 1, quando n�o h� erro. Retorna 0, quando h� erro.
int ProsLoginAluno(void);