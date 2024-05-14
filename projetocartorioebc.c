#include <stdio.h>  //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca responsavel aloca��o de espa�o de memoria
#include <locale.h> // bibliote�a de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel para cuidar das string

int Registrar() //fun��o resposanvel por cadastrar usuarios no sistemas
{		
    //inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es de usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo de danco de dados
	file = fopen(arquivo, "w"); //cria o arquivo no sistema "w" significa escrever
	fprintf(file,cpf); //salva valor da variavel
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s" ,nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s" ,sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s" ,cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}

int Consultar()
{	
	setlocale(LC_ALL, "Portuguese"); //Definindo o indioma
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF n�o localizado! .\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int Deletar()
{
	char cpf[40];
	
	printf("Digite o CPF que deseja excluir: ");
	scanf("%s",cpf);
	
	remove(cpf); //fun��o para deletar 
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o se encontra em nossos Bancos de dados!\n");
		system("pause");	
	}
	
	while(fgets(cpf, 40, file) != NULL) //fun��o para exibir a fun��o deletada ao encontrar algo no banco de dados
	{
		printf("\nEssas s�o as informa��es deletadas em nosso bando de dados: "); //mensagem a exibir para usuario
		printf("%s", cpf); // qual banco pesquisar
		printf("\n\n"); //pular linhas <3
		system("pause"); //pause para usuario conseguir ler
	}
	
}


int main()
    {
	int opcao=0; //Definindo variaveis
	int repeticao=1; //Inicio do Codigo de Repeti��o
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartorio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
		system ("cls");
  		for(repeticao=1;repeticao=1;)
		{
	
	 	   system("cls"); //codigo para limpar a tela
		
		    setlocale(LC_ALL, "Portuguese"); //Definindo o indioma
	
		    printf("### Cart�rio da EBAC ###\n\n"); //Titulo do software e Inicio do menu
		    printf("Escolha a op��o desejada do menu\n\n"); //Op��es de menu
		    printf("\t1 - Registrar nomes\n"); //op��o 1
	  	    printf("\t2 - Consultar nomes\n"); //op��o 2
	  	    printf("\t3 - Deletar nomes\n"); //op��o 3 e Fim do menu
		    printf("\t4 - Sair do sistema\n\n"); //op��o de saida
		    printf("Op��o: ");
	
		    scanf("%d" , &opcao); //Armazenando a escolha do usuario
	
		    system("cls"); //codigo para limpar a tela
	    
	    
			switch(opcao) //mudan�a da forma de op��es e inicio da sele��o de menu
		    {
		    	case 1:
		    	Registrar(); //chamada de fun�oes
			    break;
		    
			    case 2:
			    Consultar();
			    break;
		    
			    case 3:
			    Deletar();
		     	break;
	     	
		     	case 4:
		    	printf("Obrigado por utilizar o sistema!"); //op��o de saida
	    		return 0; //return 0 faz o programa fechar
	    		break;
	     		
	     		default:
	     		printf("Op��o invalida!\n"); //Mensagem se o usuario por informa��es invalidas
    			system("pause");
    			break;
	     	}
	
   		} //Fim do codigo de Repeti��o
    }
    
    else
        printf("Senha incorreta!");
}
