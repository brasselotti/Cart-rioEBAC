#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio da cria��o de vari�veis/stings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/stings

	printf("Digite o CPF a ser cadastrado: "); //Coletando inforama��o do usu�rio
	scanf("%s", cpf); //%s refere-se � strings 
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo 
	file = fopen(arquivo, "w"); //Cria o arquivo "w" = write
	fprintf(file,cpf); //Salva o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" = read - para ler o arquivo
	
	if (file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado.\n");
	}
	
	while (fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n");
		printf("%s", conteudo);
		printf("\n\n");
	} 
	
	system("pause");	
}

int deletar()
{
	char cpf[40];

	setlocale(LC_ALL,"portuguese");

	printf("Digite o CPF a ser deletado: ");

	scanf("%s",cpf);

	FILE *file;
  	file = fopen(cpf, "r");

	if (file == NULL) 
  	{
    	printf("O usu�rio n�o existe!\n");
	    system("pause");
	} 
	else 
	{
    	fclose(file);
	    remove(cpf);
	    printf("Usu�rio deletado!\n");
	    system("pause");
	}
}

int main()
{
	int opcao = 0; //Definindo as vari�veis
	int laco = 1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem - para usar acentos
		
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do Sistema\n\n");
		printf("Op��o: "); //Fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
		
		system("cls"); //Respons�vel por limpar a tela
		
		switch(opcao) //In�cio da sele��o do menu
		{
			case 1: 
				registro(); //Chamada de fun��o
				break;			
			case 2:
				consulta(); //Chamada de fun��o
				break;	
			case 3:
				deletar(); //Chamada de fun��o
				break;	
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0; //Quebra a fun��o e sai do sistema
				break;
			default:
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
		} //Fim da sele��o
	}
}
