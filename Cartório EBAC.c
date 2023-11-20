#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //bilbioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca para cuidar das string

int registro () //fun��o de registro
{
	setlocale(LC_ALL, "Portuguese"); 
	
	char arquivo[40]; //variavel/string
	char nome [40];
	char cpf[40];
	char sobrenome [40];
	char idade [4]; //fim das variaveis
	
	printf("Vamos iniciar o registro!\n");
	system("pause");
	
	system("cls");
	
	printf("Insira CPF: "); //coletando dados
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);
	
	//criando o arquivo
	FILE *file;
	file = fopen(arquivo, "w");
	fprintf(file,cpf);
	fclose(file);
	
	//atualizando o arquivo
	file = fopen(arquivo, "a");
	fprintf(file," - ");
	fclose(file); //fechando o arquivo
	
	printf("Insira seu nome: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a"); // atualizando o arquivo
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file," - ");
	fclose(file);
	
	printf("Insira seu sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");	
	fprintf(file," - ");
	fclose(file);
	
	printf("Insira sua idade: "); //fim da coleta de dados
	scanf("%s", idade);
	
	file = fopen(arquivo, "a");
	fprintf(file,idade);
	fclose(file);
	
	printf("Dados inseridos com sucesso!\n");
	system("pause");
}

int consulta () //fun��o de consulta
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf [40];
	char conteudo[200];
	
	printf("Menu de consulta de dados, insira o CPF do Aluno: \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //lendo o arquivo
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel exibir os dados, CPF n�o localizado\n"); //caso de arquivo n�o cadastrado
		system("pause");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //lendo as informa��es at� concluir todas
	{
		printf("Essas s�o as informa��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");
		system("pause");
	}
}

int deletar () //fun��o de deletar cadastros
{
	char cpf [40];
	
	printf("Para prosseguir, insira o CPF do aluno que deseja deletar: \n"); 
	scanf("%s", cpf);
	
	remove(cpf); //fun�ao para remover os dados
	
	FILE *file/*1*/;
	file/*1*/ = fopen(cpf,"r");
	
	
	
	if(file/*1*/ == NULL)
	{
		printf("Usu�rio deletado. CPF n�o consta no sistema.\n");
		system("pause");
	}
} // fim das fun��es do menu



int main () // menu principal
{
	int opcao=0;  //definindo vari�veis
	
	int laco=1;
	
	for(laco=1;laco=1;)
	
	{
		
		system("cls");
    
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	
		printf("### Centro de registros de alunos ###\n\n"); //inicio do menu
		printf("Escolha a opera��o desejada:\n\n");
		printf("\t1 - Registrar inscri��es\n\n");
		printf("\t2 - Consulta de dados\n\n");
		printf("\t3 - Deletar aluno\n\n\n");
		printf("Digite o numero correspondente: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando resposta do usu�rio
	
		system("cls"); //limpando a tela ap�s � op��o
		
		switch (opcao) //inicio da sele��o do usuario
			{
				case 1:
				registro();
				break;
				
				case 2:
				consulta();
				break;
				
				case 3:
				deletar(); //ultima op��o poss�vel para o usu�rio
				break;
				
				default: //Caso de op��o inv�lida
				printf("OP��O INV�LIDA\n"); 
				system("pause"); //fim da sele��o
				break;
			}
	}
}
	

