#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VAGAS 5

typedef enum { false, true } bool;
struct tdados{
	int hora, minuto;
	int ano, mes, dia;
	char placa[8];
};
FILE* editar(char modo, char caminho[30]);
void menu ();
void entrada(struct tdados *p);
void main () {
	FILE *arq;
	struct tdados dados;
	bool erro = false;
	char saida_menu = 'S';

	while (saida_menu == 'S') {
		menu();
		entrada(&dados);
		do {
			erro = false;
			printf("Deseja continuar? (S/N)\n");
			scanf("%c", &saida_menu);
			fflush(stdin);
			if ((saida_menu != 'S')&&(saida_menu != 'N')) {
				erro = true;
				printf("Entrada inv%clida\n\nPressione qualquer tecla para continuar...", 160);
				getchar();
				system("cls || clear");
			}
		}	while (erro == true);
	}

	/*
	arq = abrir ('l', "registro.txt");
	fread(&ent, sizeof(ent), 1, arq);
	saida = false;
	while (feof(arq)){
		if (strstr(arq, dados.carro)){
			printf("Alguma coisa");
		}
	}
	*/


	printf("\n");
}
void menu () {
	printf("%c%c BEM VINDO AO ESTACIONAMENTO DO TADEU %c%c\n", 205, 185, 204, 205);
	printf("\nPRE%cO POR HORA\n 1%c hora: R$ 11,00\n 2%c %c 4%c hora: +R$ 9,00\n Demais horas: +R$ 6,00\n", 128, 166, 166, 133, 166);
	printf("\nPRE%cO DA DI%cRIA: R$ 31,00\n", 128, 181);
}
void entrada(struct tdados *p){
	printf("\nIDENTIFICA%c%cO\n\n", 128, 199);
	printf("Placa do veiculo (sem hifen): ");
	scanf("%s", &p->placa);
	fflush(stdin);

	printf("ENTRADA/SA%cDA\n\n", 214);
	printf("Hora: ");
	scanf("%d", &p->hora);
	fflush(stdin);
	printf("Minuto: ");
	scanf("%d", &p->minuto);
	fflush(stdin);
	printf("Dia: ");
	scanf("%d", &p->dia);
	fflush(stdin);
	printf("Mes: ");
	scanf("%d", &p->mes);
	fflush(stdin);
	printf("Ano: ");
	scanf("%d", &p->ano);
	fflush(stdin);

	system("clear || cls");
}
FILE* abrir(char modo, char caminho[30]){

	FILE *arquivo;

	if(modo == 'g'){
		arquivo = fopen (caminho, "w+");
	}
	if (modo == 'l'){
		arquivo = fopen (caminho, "r");
	}
	if (modo == 'a'){
		arquivo =  fopen (caminho, "a");
	}
	if (arquivo == NULL){
		printf("NÃO FOI POSSÍVEL ABRIR O ARQUIVO");
	}
	return arquivo;
}
