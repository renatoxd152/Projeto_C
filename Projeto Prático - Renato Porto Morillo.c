#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cont = 0;
int cont1 = 0;
typedef struct
{
	float prova;
	float projeto;
	float lista_exercicios;
	float media;
}notas;

typedef struct
{
	char prontuario[50];
	char nome[50];
	char data_nasc[50];
	char email[100];
	notas n;
}aluno;

aluno cadastrar(char cod[])
{
	aluno a;
	fflush(stdin);
	strcpy(a.prontuario,cod);
	printf("Nome:");
	fflush(stdin);
	scanf("%s",&a.nome);
	printf("Data de nascimento:");
	fflush(stdin);
	scanf("%s",&a.data_nasc);
	printf("Email:");
	fflush(stdin);
	scanf("%s",&a.email);
	printf("Digite a nota da prova pratica:");
	fflush(stdin);
	scanf("%f",&a.n.prova);
	printf("Digite a nota do projeto:");
	fflush(stdin);
	scanf("%f",&a.n.projeto);
	printf("Digite a nota da lista de exercícios:");
	fflush(stdin);
	scanf("%f",&a.n.lista_exercicios);
	a.n.media = ((a.n.prova * 40 ) + (a.n.projeto * 40 )+ (a.n.lista_exercicios * 20 ))/100;
	return a;
}

verifica_cod(char cod[],aluno alu[])
{
	int x;
	int encontrado;
	encontrado = 0;
	for(x=0; x < cont; x++)
	{
		if(strcmp(cod, alu[x].prontuario) == 0)
		{
			encontrado = 1;
		}
	}
	if(encontrado == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}
listar(aluno alu[])
{
	int x;
	printf("\n Alunos listados \n");
	for(x=0;x<cont;x++)
	{
		printf("\nProntuário: %s",alu[x].prontuario);
		printf("\nNome: %s",alu[x].nome);
		printf("\nData de nascimento: %s",alu[x].data_nasc);
		printf("\nEmail:%s",alu[x].email);
		printf("\nProva Prática:%.2f",alu[x].n.prova);
		printf("\nProjeto: %.2f",alu[x].n.projeto);
		printf("\nLista de exercícios: %.2f",alu[x].n.lista_exercicios);
		printf("\nMedia: %.2f\n", alu[x].n.media);
	}
}
buscar_aluno(aluno alu[])
{
	int j;
	char prontuario1[50];
	printf("\nDigite um prontuário de um aluno para ser pesquisado:");
	scanf("%s",&prontuario1);
	int encontrar;
	encontrar = 0;
	for(j=0;j < cont;j++)
	{
		if(strcmp(prontuario1, alu[j].prontuario)== 0)
		{
			encontrar = 1;
			printf("\nProntuário:%s\n",alu[j].prontuario);
			printf("Nome:%s\n",alu[j].nome);
			printf("Data de nascimento:%s\n",alu[j].data_nasc);
			printf("Email:%s\n",alu[j].email);
			printf("Prova Prática:%.2f\n",alu[j].n.prova);
			printf("Projeto: %.2f\n",alu[j].n.projeto);
			printf("Lista de exercícios: %.2f\n",alu[j].n.lista_exercicios);
		}
	}
	if(encontrar == 0)
	{
		printf("\nEsse prontuário não foi encontrado!\n");
	}
}
alterar_aluno(aluno alu[])
{
	int j;
	char prontuario1[50];
	
	printf("Digite o prontuário para alterar um aluno:");
	scanf("%s",&prontuario1);
	
	int encontrar;
	encontrar = 0;
	
	for(j=0;j<cont;j++)
	{
		if(strcmp(prontuario1,alu[j].prontuario)==0)
		{
			encontrar = 1;
			printf("\nO aluno foi encontrado com sucesso!\n");
			
			printf("Novo prontuário:");
			fflush(stdin);
			fgets(alu[j].prontuario, 50, stdin);
			alu[j].prontuario[strcspn(alu[j].prontuario, "\n")] = 0;
			
			printf("Novo nome:");
			fflush(stdin);
			fgets(alu[j].nome, 50, stdin);
			alu[j].nome[strcspn(alu[j].nome, "\n")] = 0;
			
			printf("Nova data de nascimento:");
			fflush(stdin);
			fgets(alu[j].data_nasc,50, stdin);
			alu[j].data_nasc[strcspn(alu[j].data_nasc, "\n")] = 0;
			
			printf("Novo email:");
			fflush(stdin);
			fgets(alu[j].email,50, stdin);
			alu[j].email[strcspn(alu[j].email, "\n")] = 0;
		}	
	}
	if(encontrar == 0)
	{
		printf("\nO aluno com esse prontuário não foi encontrado\n");
	}
	
}
excluir_aluno(aluno alu[])
{
	int j;
	char prontuario[50];
	
	printf("Informe o codigo que deseja excluir: ");
	scanf("%s",&prontuario);
	
	int encontrar;
	encontrar = 0;
	
	for(j=0;j<cont;j++)
	{
		if(strcmp(prontuario,alu[j].prontuario)==0)
		{
			cont1++;
			encontrar = 1;
			cont--;
		}
	}
	if(encontrar == 1)
	{
		printf("\nO aluno foi exclúido com sucesso\n");
	}
	else
	{
		printf("\nO aluno com esse prontuário não foi encontrado");
	}
}
submenu_alunos(aluno alu[])
{
	int op1;
	int retorno;
	char prontuario[50];
	do
	{
		printf("\nDigite 1 para Listar todos os alunos\n");
		printf("Digite 2 para listar um aluno\n");
		printf("Digite 3 para Cadastrar aluno\n");
		printf("Digite 4 para alterar aluno\n");
		printf("Digite 5 para excluir aluno(cancelar matrícula)\n");
		printf("Digite 6 para voltar para o menu principal!\n");
		scanf("%d",&op1);
		fflush(stdin);
		
		switch(op1)
		{
			case 1:
				listar(alu);
				break;
			case 2:
				buscar_aluno(alu);
				break;
			case 3:
				
				printf("\nDigite um prontuário para ser cadastrado:\n");
				scanf("%s",&prontuario);
				
				retorno = verifica_cod(prontuario,alu);
				
				if(retorno == 0)
				{
					alu[cont] = cadastrar(prontuario);
					cont++;
				}
				else
				{
					printf("\nProntuário já está cadastrado!\n");
				}
				break;
			case 4:
				alterar_aluno(alu);
				break;
			case 5:
				excluir_aluno(alu);
				break;
			case 6 :
				op1 = '0';
				break;
			default: printf("Opção Inválida!\n");
		}
	}while(op1 >= 1 && op1 <=6);					
}
mostrar_alunos_aprovados(aluno alu[])
{
	int j;
	for(j=0;j<cont;j++)
	{
		if(alu[j].n.media >= 7)
		{
			printf("\nProntuário:%s\n",alu[j].prontuario);
			printf("Nome:%s\n",alu[j].nome);
			printf("Data de nascimento:%s\n",alu[j].data_nasc);
			printf("Email:%s\n",alu[j].email);
			printf("Prova Prática:%.2f\n",alu[j].n.prova);
			printf("Projeto: %.2f\n",alu[j].n.projeto);
			printf("Lista de exercícios: %.2f\n",alu[j].n.lista_exercicios);
			printf("O aluno %s foi Aprovado com %.2f na disciplina\n",alu[j].nome,alu[j].n.media);
		}
	}
}
mostrar_alunos_reprovados(aluno alu[])
{
	int j;
	for(j=0;j<cont;j++)
	{
		if(alu[j].n.media < 7)
		{
			printf("\nProntuário:%s\n",alu[j].prontuario);
			printf("Nome:%s\n",alu[j].nome);
			printf("Data de nascimento:%s\n",alu[j].data_nasc);
			printf("Email:%s\n",alu[j].email);
			printf("Prova Prática:%.2f\n",alu[j].n.prova);
			printf("Projeto: %.2f\n",alu[j].n.projeto);
			printf("Lista de exercícios: %.2f\n",alu[j].n.lista_exercicios);
			printf("O aluno %s foi Reprovado com %.2f na disciplina\n",alu[j].nome,alu[j].n.media);
		}
	}
}
mostrar_alunos_excluidos(aluno alu[])
{
	FILE *pont_arq;
	pont_arq = fopen("arquivo.txt", "a");
	if(pont_arq == NULL)
	{
		printf("\nErro ao tentar abrir o arquivo!\n");
	}
	else
	{
		int j;
		for(j=0;j<cont1;j++)
		{
			printf("\nProntuário:%s\n",alu[j].prontuario);
			printf("Nome:%s\n",alu[j].nome);
			printf("Data de nascimento:%s\n",alu[j].data_nasc);
			printf("Email:%s\n",alu[j].email);
			printf("Prova Prática:%.2f\n",alu[j].n.prova);
			printf("Projeto: %.2f\n",alu[j].n.projeto);
			printf("Lista de exercícios: %.2f\n",alu[j].n.lista_exercicios);
			// Essa seção debaixo escreve no arquivo os alunos excluídos
			fprintf(pont_arq,"\nProntuário:%s\n",alu[j].prontuario);
			fprintf(pont_arq,"Nome:%s\n",alu[j].nome);
			fprintf(pont_arq,"Data de nascimento:%s\n",alu[j].data_nasc);
			fprintf(pont_arq,"Email:%s\n",alu[j].email);
			fprintf(pont_arq,"Prova Prática:%.2f\n",alu[j].n.prova);
			fprintf(pont_arq,"Projeto: %.2f\n",alu[j].n.projeto);
			fprintf(pont_arq,"Lista de exercícios: %.2f\n",alu[j].n.lista_exercicios);
		}
	}
	fclose(pont_arq);
	
}

submenu_relatorios(aluno alu[])
{
	int op;
	do
	{
		printf(" Digite 1 para mostrar todos os alunos aprovados na disciplina\n");
		printf(" Digite 2 para mostrar todos os alunos reprovados\n");
		printf(" Digite 3 para mostrart todos os alunos exclúidos\n");
		printf(" Digite 4 para voltar para o menu principal!\n");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1:
				mostrar_alunos_aprovados(alu);
				break;
			case 2:
				mostrar_alunos_reprovados(alu);
				break;
			case 3:
				mostrar_alunos_excluidos(alu);
				break;
			case 4:
				op = '0';
				break;
			default: printf("Opção Inválida!\n");	
		}
	}while(op >= 1 && op <= 4);
}
main()
{
	int op;
	aluno alu[500];
	do
	{
		printf (" MENU DE OPCOES : \n");
		printf (" Digite 1 para os alunos. \n");
		printf (" Digite 2 para os relatórios . \n");
		printf(" Digite 3 para encerrrar o programa\n");
		scanf ("%d",&op);
		fflush(stdin);
		
		switch(op)
		{
			case 1:
				submenu_alunos(alu);
				break;
			case 2:
				submenu_relatorios(alu);
				break;	
			case 3:
				printf("\nEncerrando o programa...\n"); 
			   	break;
			default: printf("Opção incorreta!\n");
		}
	}while(op >= 1 && op <= 2);
}
