#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //bilbioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca para cuidar das string

int registro () //fun��o de registro
{
	setlocale(LC_ALL, "Portuguese");
	
	system("cls");
	
	int opcao = 0;
	
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
	
	printf("Insira o nome: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a"); // atualizando o arquivo
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file," - ");
	fclose(file);
	
	printf("Insira a idade: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");	
	fprintf(file," - ");
	fclose(file);
	
	printf("Qual o sua posi��o na EBAC: "); //fim da coleta de dados
	scanf("%s", idade);
	
	file = fopen(arquivo, "a");
	fprintf(file,idade);
	fclose(file);
	
	printf("Dados inseridos com sucesso!\n\n");
	printf("\t1 Repetir a opera��o\n\n");
	printf("\t2 Voltar ao menu\n\n");
	
	printf("Digite a op��o que deseja: \n\n");
	
	scanf("%d", &opcao);
	
	switch (opcao)
		{
			case 1:
			registro();
			break;
			
			case 2:
			printf("Voltando ao menu!\n");
			system("pause");
			
			case 3:
			printf("At� um outro dia!!");
			return 0; //Este return n�o esta sendo executado
			break;
		}
}

int consulta () //fun��o de consulta
{
	setlocale(LC_ALL, "Portuguese");
	
	int opcao = 0;
		
	char cpf [40];
	char conteudo[200];
	
	system ("cls");
	
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
		
		printf("Deseja consultar novos dados? :\n\n");
		printf("\t1 Sim");
		printf("\t2 N�o\n\n");
		printf("Digite 1 ou 2: ");
		scanf("%d", &opcao);
		{
		if (opcao == 1)
		{
		 	consulta();
		}
		else
		{
			printf("Voltando ao menu principal\n\n");
			system ("pause");
			return 0; 	
		}
		}
		
			
			
	}
}

int deletar () //fun��o de deletar cadastros
{
	
	system("cls");
	
	int opcao = 0;
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
	
	printf("Deseja repetir a opera��o:\n\n");
	printf("\t1 Sim");
	printf("\t2 N�o\n\n");
	scanf("%d", &opcao);
	
	if (opcao == 1)
	{
		deletar();
	}
	else
	{
		printf("Voltando ao menu\n\n");
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
	
	
		printf("### Centro de registros da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opera��o desejada:\n\n");
		printf("\t1 - Registrar Aluno ou funcion�rio\n\n");
		printf("\t2 - Consulta de dados\n\n");
		printf("\t3 - Deletar dados\n\n");
		printf("\t4 - Deseja fechar o programa\n\n");
		
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
				
				case 4:
				printf ("Obrigado por ultilizar o programa!");
				return 0;
				break;
				
				
				default: //Caso de op��o inv�lida
				printf("OP��O INV�LIDA\n"); 
				system("pause"); //fim da sele��o
				break;
			}
	}
}
	

