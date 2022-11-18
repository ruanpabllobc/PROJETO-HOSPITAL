#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "paciente.h"

int main(){
	
	Hospital *H = hospital_sistema();
	
	int op = 0;
	int exe = 1;

    while(exe==1){
    	system("cls || clear");
		printf("MERIDA GREY GENERAL HOSPITAL\n");
		printf("--------------MENU--------------\n");
	   	printf("0. INICIAR SISTEMA\n");
	   	printf("1. CADASTRAR PACIENTE\n");
	   	printf("2. PACIENTE PRIORITARIO\n");
	   	printf("3. EXCLUIR PACIENTE\n");
	   	printf("4. LISTAR PACIENTES\n");
	   	printf("5. BUSCAR PACIENTE\n");
	   	printf("6. EDITAR CADASTRO DE PACIENTE\n");
	   	printf("7. CONSULTAR VAGAS DISPONIVEIS DE LEITO NO HOSPITAL\n");
	   	printf("8. CONSULTAR QUANTITATIVO DE PACIENTES NO HOSPITAL\n");
	   	printf("9. GERAR RELATORIO ORDENADO\n");
	   	printf("10. DADOS HOSPITAL\n");
	   	printf("11. SAIR\n");
	   	printf("---------------------------------\n");
	   	printf("Seleciona uma opcao: ");
	   	scanf("%d", &op);
	   	
        switch(op){
            case 0:
                Beep(1000,500);
				Fila *f = fila_cria();
				printf("Bem-vindo, o sistema iniciado com sucesso!\n");
				system("pause");
                break;

            case 1:
                cadastra_pacientes(f);
                system("pause");
                break;

            case 2:
                paciente_prioritario(f);
                system("pause");
                break;

            case 3:
            	Beep(1000,500);
                exclui_pacientes(f);
                break;

       	   case 4:
                imprime_pacientes(f);
                system("pause");
                break;
            
       	   case 5:	
                busca_pacientes(f);
                system("pause");
                break;

       	   case 6:	
                edita_pacientes(f);
                system("pause");
                break;
			            
		   case 7:	
                vagas_leitos(f,H);
                system("pause");
                break;
            
           case 8:
				quantidade_pacientes(f);
                system("pause");
                break;
            
            case 9:
            	hospital_sistema();
                system("pause");
                break;
            
            case 10:
            	ordena(f);
                system("pause");
                break;
            
            case 11:
                Beep(1000,500);
                fila_libera(f); 
                free(H);
                return 0;
                break;

            default:
                printf("Nenhuma opcao foi selecionada!\n");
                system("pause");
        }
	}
    return 0;
}