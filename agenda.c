#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct agenda{
	char nome[50];
	char telefone[15];
	char celular[15];
	char email[40];
	struct agenda *prox;
};


typedef struct agenda contato;

contato *listaContato;


void add(char nome[], char telefone[], char celular[], char email[]){

	contato *p = (contato*) malloc(sizeof(contato));
	strcpy(p->nome, nome);
	strcpy(p->telefone, telefone);
	strcpy(p->celular, celular);
	strcpy(p->email, email);

	p->prox = listaContato;
	listaContato = p;
}

void addQtd(){

	char continuar;
	char nome[50], telefone[15], celular[15], email[40];

	do{

		printf("INFORME O NOME DO CONTATO: "); scanf("%s", nome);
		printf("INFORME O NUMERO DE TELEFONE: "); scanf("%s", telefone);
		printf("INFORME O NUMERO DE CELULAR: "); scanf("%s", celular);
		printf("INFORME O EMAIL: "); scanf("%s", email);
		add(nome, telefone, celular, email);
		printf("\nCONTATO ADCIONADO COM SUCESSO\n");
        
		printf("\nDESEJA ADCIONAR MAIS CONTATO? [S/N] "); scanf(" %c", &continuar);
		printf("\n");

	}while(continuar == 'S' || continuar == 's');
}

void listar (contato *listaContato){

	contato *p;
	int i = 1;

	for (p=listaContato; p !=NULL; p = p->prox){

		printf("--- CONTATO #%d ---\n", i);
		printf("NOME: %s\n", p->nome);
		printf("TELEFONE: %s\n", p->telefone);
		printf("CELULAR: %s\n", p->celular);
		printf("EMAIL: %s\n", p->email);
		printf("\n");
		i++;
	}
}

void remover(char valorRemovido[]){
	
	contato *atual = listaContato;
	contato *anterior = NULL;
	
	while(atual!=NULL && strcmp(atual->nome, valorRemovido)!=0){
		anterior = atual;
		atual = atual->prox;
	}
	
	if(atual == NULL){
		printf("VALOR INFORMADO NAO EXISTE\n");
		printf("VOCE SERA DIRECIONADO PARA O MENU PRINCIPAL\n");
		printf("\n");
		return;
	}
	
	if(anterior == NULL){
		listaContato = atual->prox;
	}
	else{
		anterior->prox = atual->prox;
	}
	free(atual);
	printf("CONTATO REMOVIDO COM SUCESSO! \n");	
}

void procurar(char nomeProc[]){

    contato *p;

    for (p=listaContato; p !=NULL; p = p->prox){
        if(strcmp(p->nome, nomeProc) == 0){
            printf("\n");
            printf("NOME: %s\n", p->nome);
            printf("TELEFONE: %s\n", p->telefone);
            printf("CELULAR: %s\n", p->celular);
            printf("EMAIL: %s\n", p->email);
            printf("\n");

        }
	}
}

void editar(char nomeProc[],int opcao){
	
	contato *p;
	
	char nomeEdit[50], telEdit[15], celEdit[15], emailEdit[40];
	
	for (p=listaContato; p !=NULL; p = p->prox){
	    if(strcmp(p->nome, nomeProc) == 0){
	        switch(opcao){
	            case 1: //editar nome
	            	printf("NOME ATUAL: %s\n", p->nome);
	            	printf("INFORME O NOVO NOME: "); scanf("%s", nomeEdit);
	            	strcpy(p->nome, nomeEdit);
	            	printf("NOME EDITADO COM SUCESSO!\n");
	            	printf("\n");
	            	break;
	            case 2: //editar telefone
	            	printf("TELEFONE ATUAL: %s\n", p->telefone);
	            	printf("INFORME O NOVO NUMERO DE TELEFONE: "); scanf("%s", telEdit);
	            	strcpy(p->telefone, telEdit);
	            	printf("TELEFONE EDITADO COM SUCESSO!\n");
	            	printf("\n");
	            	break;
	            case 3: //editar celular
	            	printf("CELULAR ATUAL: %s\n", p->celular);
	            	printf("INFORME O NOVO NUMERO DE CELULAR: "); scanf("%s", celEdit);
	            	strcpy(p->celular, celEdit);
	            	printf("CELULAR EDITADO COM SUCESSO!\n");
	            	printf("\n");
					break;
	            case 4: //editar e-mail
	            	printf("EMAIL ATUAL: %s\n", p->email);
	            	printf("INFORME O NOVO EMAIL: "); scanf("%s", emailEdit);
	            	strcpy(p->email, emailEdit);
	            	printf("EMAIL EDITADO COM SUCESSO!\n");
	            	printf("\n");
					break;
	            case 5:
	            	return;
	            	break;				
			}
	    }
	}	
}

int main(){

	int escolha, opcao;
	char continuar;

	char nome[50], telefone[15], celular[15], email[40], nomeRemocao[50], nomeProcurado[50];



	do{
        printf("--------- MENU ---------\n");
		printf("ESCOLHA UMA DAS OPCOES:\n");
		printf("1 - INSERIR CONTATO\n");
		printf("2 - LISTAR CONTATO\n");
		printf("3 - REMOVER CONTATO\n");
		printf("4 - PROCURAR CONTATO\n");
        printf("5 - EDITAR CONTATO\n");
		printf("6 - SAIR\n");

		printf("DIGITE A OPCAO DESEJADA: "); scanf("%d", &escolha);
		printf("\n");


		switch(escolha){
			case 1:
				printf("VOCE SELECIONOU A OPCAO ADCIONAR CONTATO\n\n");
				addQtd();
				break;
			case 2:
				printf("VOCE SELECIONOU A OPCAO LISTAR CONTATO\n\n");
				listar(listaContato);
				break;
			case 3:
				printf("VOCE SELECIONOU A OPCAO REMOVER CONTATO\n\n");
				printf("QUAL NOME VOCE DESEJA REMOVER: "); scanf("%s", nomeRemocao);
				remover(nomeRemocao);
				
				break;
            case 4:
                printf("VOCE SELECIONOU A OPCAO PROCURAR CONTATO\n\n");
                printf("INFORME O NOME PROCURADO: "); scanf("%s", nomeProcurado);
                procurar(nomeProcurado);
                break;
            case 5:
                printf("VOCE SELECIONOU A OPCAO EDITAR CONTATO\n\n");
                printf("INFORME O NOME DO CONTATO A SER EDITADO: "), scanf("%s", nomeProcurado);
                printf("----- MENU DE EDICAO -----\n");
                printf("ESCOLHA UMA DAS OPCOES:\n");
                printf("1 - ALTERAR NOME\n");
                printf("2 - ALTERAR TELEFONE\n");
                printf("3 - ALTERAR CELULAR\n");
                printf("4 - ALTERAR E-MAIL\n");
                printf("5 - VOLTAR AO MENU PRINCIPAL \n");
                printf("\n");
                printf("DIGITE A OPCAO DESEJADA: "); scanf("%d", &opcao);
                printf("\n");

                editar(nomeProcurado, opcao);

		}

	}while(escolha != 6);

	printf("ESPERO TER AJUDADO :)\nATE BREVE!");

}
