#include <stdio.h>

typedef struct {
	int dia;
	int mes;
	int ano;
} Data;

int bissexto (int ano);
unsigned long dist_dias (Data inicio, Data fim);

int dias_mes[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int main(void) {
	Data dia1, dia2;

	printf("Coloque data incial no formato: dia/mes/ano\n");
	scanf("%d/%d/%d", &dia1.dia, &dia1.mes, &dia1.ano);
	printf("Coloque data final no formato: dia/mes/ano\n");
	scanf("%d/%d/%d", &dia2.dia, &dia2.mes, &dia2.ano);

	printf("A distancia em dias: %lu\n", dist_dias (dia1, dia2));

	return 0;
}

/*
 * Retorna 1 caso 'ano' seja bissexto, 0 caso contrário
 */
int bissexto (int ano) {
	return (ano % 4 == 0) && ((ano % 100 != 0) || (ano % 400 == 0));
}

/*
 * Retorna a distancia entre inicio e fim em dias.
 * Assume que inicio nao vem depois de fim.
 */
unsigned long dist_dias (Data inicio, Data fim) {
	unsigned long idias, fdias;	/* guarda qtos dias tem da data */
					/* ate o comeco do ano */
	unsigned long def_anos = 0;	/* guarda diferenca entre anos das */
					/* datas inicio e fim medida em dias */
	int i;
	int dbissexto;

	idias = inicio.dia;
	dbissexto = bissexto (inicio.ano);
	for (i = inicio.mes - 1; i > 0; --i)
		idias += dias_mes[dbissexto][i];

	fdias = fim.dia;
	dbissexto = bissexto (fim.ano);
	for (i = fim.mes - 1; i > 0; --i)
		fdias += dias_mes[dbissexto][i];

	while (inicio.ano < fim.ano)
		def_anos += 365 + bissexto(inicio.ano++);

	return def_anos - idias + fdias;
}
