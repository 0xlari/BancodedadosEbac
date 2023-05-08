#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocaçãode espaço de memória
#include <locale.h> // biblioteca de alocaçõs de texto por região
#include <string.h> //biblioteca responsável pelas strings.

int registro() //função responsavél por cadastrar os usuarios que pode ser chamada a qualquer momento
{  
 //inicio da criação de variaveis/string
    char arquivo [40]; 
    char cpf [40];
    char nome [40];
    char sobrenome [40];
    char cargo [40];
// final da criação de variaveis
    
    printf ("Digite o CPF a ser cadastrado:"); // coletando infos do usuarios
    scanf ("%s",cpf); // %s salva na string
    
    strcpy (arquivo,cpf); //Responsável por copiar os valores das string
    
    FILE *file; // Cria o arquivo
    file = fopen (arquivo,"w"); //cria o arquivo "w" escreve
    fprintf (file,"CPF:");
    fprintf(file,cpf); // salva o valor da variavel
    fclose(file); // fecha o arquivo
    
    
    printf ("Digite o nome a ser cadastrado:");
    scanf("%s",nome);
    
    file = fopen (arquivo, "a"); // abre o arquivo e o "a" edita o  nome
    fprintf (file,"\nNome:");
    fprintf(file,nome);
    fclose (file); // fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado:");
    scanf("%s",sobrenome);
    
    file = fopen (arquivo,"a");
    fprintf (file,"\nSobrenome:");
    fprintf(file,sobrenome);
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado:");
    scanf("%s",cargo);
    
    file = fopen (arquivo,"a");
    fprintf (file,"\nCargo:");
    fprintf(file,cargo);
    fclose(file);
    
}

int consultar() //função que pode ser chamada a qualquer momento
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
    char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // abrimos o arquivo e o "r" serve para ler o arquivo
	
	
	if(file == NULL)
	{
		printf("Esse usuario não existe./n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as insformações do usuário:"); // quero saber como faço para essa mensagem não se repetir em todas as linhas
		printf ("%s", conteudo);
		printf ("\n\n");		
	}	
	
	system("pause");
}

int deletar() //função que pode ser chamada a qualquer momento
{
	
	char cpf[40]; // abrindo os caracteres da string
    
    printf("Digite o CPF a ser deletado:");
    scanf("%s",cpf); // gravando na string
    
     remove(cpf); // remover u arcpf
    
	FILE *file; //abrimos o arquivo e o "r" leu o arquivo
	file = fopen(cpf,"r"); 
	
	if(file == NULL) //aqui a gente esta falando que se for = a nulo mostrar o comentario a baixo.
	{
	  printf("O usúario não se encontra no sistema!\n");
	  system("pause"); 	
	}
}


int main()
   {
     int opcao=0; //Definindo variavies
	 int laco=1;
	
	     for (laco=1;laco=1;)
	 {
	       system("cls");
	
	       setlocale(LC_ALL,"Portuguese"); //lingua que será utilizada
	
         //Titulo Geral
	     printf("### cartório da EBAC ###\n\n");
         //Menu com as opções
	     printf("Escolha a opção desejada do menu:\n\n");
	
	     printf("\t1 - Registrar nomes\n");
	     printf("\t3 - Deletar nomes\n\n"); 
	     printf("\t2 - Consultar nomes\n");
	     printf("\t4 - Sair do sistema!\n");
	     printf("opção:"); //Fim do menu
	
	     scanf("%d", &opcao); //armazenamento do usuario
	
	     system("cls"); //apagar o que estava escrito antes
	
	         switch(opcao) //opções que vão aparecer para o usuario
	       {
	       	 case 1: 
	       	  registro();
		     break;
		     
		     case 2:
			  consultar();
	         break;
	         
	         case 3:
	          deletar();
			 break;
			 
			 case 4;
			  printf("Obrigado po utilizar nosso sistema!\n");
			  return
			 break;
			 
			 
			 
			 
			 

			 
			 default: // aparecerra quando não for nenhuma das anteriores
			 printf("Essa opção não esta disponivél!\n");
		     system("pause");
			 break; 	// fim das escolhas
	       }
	   }     
   }   

