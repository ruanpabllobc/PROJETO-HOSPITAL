#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"

struct hospital{
	char numero[20];
	int leitos;
	char localizacao[100];
	char nome[100];
};

Hospital* hospital_sistema(void){
	Hospital * H = (Hospital*) malloc(sizeof(Hospital));
	strcpy(H->numero,"19.629.480/0001-82"); 
	H->leitos = 50;
	strcpy(H->localizacao,"Avenida Getulio Vargas, 1453"); 
	strcpy(H->nome,"Merida Grey General Hospital");
	 
	printf("%s\n", H->numero);
	printf("%d\n", H->leitos);
	printf("%s\n", H->localizacao);
	printf("%s\n", H->nome);
	return H;
	system("pause");
}

struct lista{
    char nome[30];
    long long int cpf;
    char enfermidade[30];
    int internado;
    char receita[100];
    struct lista *prox;
};

struct fila{
    Lista *ini;
    Lista *fim;
};

Fila* fila_cria(void){
    Fila * f = (Fila*) malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

void cadastra_pacientes(Fila * f){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    
    printf("Nome do paciente: ");
    scanf(" %[^\n]",novo->nome);
	printf("CPF paciente: ");
    scanf("%lld",&novo->cpf);
    printf("Enfermidade: ");
    scanf(" %[^\n]",novo->enfermidade);
	printf("Paciente para internacao? 1 para SIM e 0 para NAO: ");
    scanf("%d",&novo->internado);
    printf("Receita Medica: ");
    scanf(" %[^\n]",novo->receita);
    
    novo->prox = NULL;
    if(f->fim!=NULL)
        f->fim->prox = novo;
    else{
       	f->ini= novo;
    }
    f->fim = novo;

}

void paciente_prioritario(Fila * f){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
	printf("Nome do paciente: ");
    scanf(" %[^\n]",novo->nome);
	printf("CPF paciente: ");
    scanf("%lld",&novo->cpf);
    printf("Enfermidade: ");
    scanf(" %[^\n]",novo->enfermidade);
	printf("Paciente para internacao? 1 para SIM e 0 para NAO: ");
    scanf("%d",&novo->internado);
    printf("Receita Medica: ");
    scanf(" %[^\n]",novo->receita);
    
    novo->prox = f->ini;
    f->ini = novo;
}

void exclui_pacientes(Fila* f){
	if(f->ini == NULL){
		printf("Nao e possivel deletar uma lista vazia, por favor preencha!\n");
		exit(1);
	}
	else{
		struct lista *fi = f->ini;
		f->ini = fi->prox;
		free(fi);
	}
}

void imprime_pacientes(Fila *f){
	Lista *p;
	
	FILE* arquivo = fopen("Relatorio.txt", "w");
	if(arquivo == NULL){
		printf("Arquivo nao existente!\n");
		exit(1);
	}
	
	for(p=f->ini; p!=NULL; p=p->prox){
		fprintf(arquivo, "Nome = %s\nCPF = %lld\nEnfermidade = %s\nInternado = %d\nReceita = %s\n", p->nome, p->cpf, p->enfermidade, p->internado, p->receita);
		
	}
	fclose(arquivo);
	
	for(p=f->ini; p!=NULL; p=p->prox){
		printf("Nome = %s\nCPF = %lld\nEnfermidade = %s\nInternado = %d\nReceita = %s\n", p->nome, p->cpf, p->enfermidade, p->internado, p->receita);
		printf("\n");
	}
}

void busca_pacientes(Fila *f){
	long long int elemento = 0;
	printf("Digite o CPF para busca: ");
	scanf("%lld", &elemento);
	
	Lista *p;
	for(p=f->ini; p!=NULL; p=p->prox){
		if(p->cpf == elemento){
			printf("Paciente encontrado!\n");
		}
	}
}

void edita_pacientes(Fila *f){
	long long int elemento = 0;
	printf("Digite o CPF para busca: ");
	scanf("%lld", &elemento);
	
	Lista *p;
	for(p=f->ini; p!=NULL; p=p->prox){
		if(p->cpf == elemento){
			printf("Paciente encontrado!\n");
			printf("Nome do paciente: ");
    		scanf(" %[^\n]",p->nome);
		   	printf("CPF paciente: ");
    	   	scanf("%lld",&p->cpf);
    	   	printf("Enfermidade: ");
    	   	scanf(" %[^\n]",p->enfermidade);
		   	printf("Paciente para internacao? 1 para SIM e 0 para NAO: ");
    	   	scanf("%d",&p->internado);
    	   	printf("Receita Medica: ");
    		scanf(" %[^\n]",p->receita);
		}
	}
}

void vagas_leitos(Fila *f, Hospital *H){
	Lista *p;
	for(p=f->ini; p!=NULL; p=p->prox){
		if(p->internado == 1){
			H->leitos--;
		}
	}
	printf("Total de leitos: %d\n", H->leitos);
	H->leitos = 50;
}

void quantidade_pacientes(Fila *f){	
	Lista *p;
	int i = 0;
	for(p=f->ini; p!=NULL; p=p->prox){
		i++;
	}
	printf("Pacientes para atendimento: %d\n", i);
}

void fila_libera(Fila *f){
	Lista *p = f->ini;
	while(p!=NULL){
		Lista* t = p->prox;
		free(p);
		p = t;
	}
	free(f);
}

int fila_vazia(Fila *f){
	return (f->ini==NULL);
}

void ordena(Fila* f){
	Lista* p;
	Lista* aux;
	FILE* arquivo_ordenado = fopen("Ordenacao.txt", "w");
	if(arquivo_ordenado == NULL){
		printf("Arquivo nao existente!\n");
		exit(1);
	}
	int r;
		
	for(p=f->ini; p!=NULL; p=p->prox){
		r = strcmp(p->nome, p=p->prox->nome);
		if(r > 0){
			strcpy(aux->nome, p->nome);
			strcpy(p->nome, p=p->prox->nome);
			strcpy(p=p->prox->nome, aux->nome);
		}	
	}
	
	for(p=f->ini; p!=NULL; p=p->prox){
		fprintf(arquivo_ordenado, "Nome = %s\nCPF = %lld\nEnfermidade = %s\nInternado = %d\nReceita = %s\n", p->nome, p->cpf, p->enfermidade, p->internado, p->receita);
		
	}
	
	fclose(arquivo_ordenado);
}