
#include <stdio.h>
#include <windows.h>
#include "Gestire_File.h"
#include "Gestire_Schermo.h"

void salvarePartita(FILE *file, Partita p){
	int i;
	int c;
	int exit;

	fprintf(file, "%d\n", leggereNumTentativi(leggereImpostazioni(p)));
	fprintf(file, "%d\n", leggereNumSimboli(leggereImpostazioni(p)));
	fprintf(file, "%d\n", leggereLunghezzaCodice(leggereImpostazioni(p)));
	fprintf(file, "%d\n", leggereDoppi(leggereImpostazioni(p)));

	fprintf(file, "%d\n", leggereNumTentativiPart(p));

	i=0;
	while(i<leggereLunghezzaCodice(leggereImpostazioni(p))){
		fprintf(file, "%d\n", leggereCorretto(leggereCorrettoPartita(p),i));
		i=i+1;
	}

	i=0;
	while(i<leggereNumTentativiPart(p)){
		c=0;
		while(c<leggereLunghezzaCodice(leggereImpostazioni(p))){
			fprintf(file, "%d\n", leggereTentativo(leggereTentativi(p,i),c));
			c=c+1;
		}
		fprintf(file, "%d\n", leggereRisposta(leggereRisposte(p,i),0));
		fprintf(file, "%d\n", leggereRisposta(leggereRisposte(p,i),1));
		i=i+1;
	}

	GotoYX(30,11);
	cambiaColore(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	printf("Salvato!");
	cambiaColore(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	exit=leggereNumeroVincoli("Permere 0 per tornare al menu: ", 23, 1, 0,0);

	return;
}

void leggerePartita(FILE *file, Partita*p){
	int i;
	int c;
	int num;
	Impostazioni imp;
	Corretto cor;
	Tentativo t;
	Risposta r;

	fscanf(file, "%d", &num);
	scrivereNumTentativi(&imp, num);
	fscanf(file, "%d", &num);
	scrivereNumSimboli(&imp, num);
	fscanf(file, "%d", &num);
	scrivereLunghezzaCodice(&imp, num);
	fscanf(file, "%d", &num);
	scrivereDoppi(&imp, num);

	scrivereImpostazioni(p, imp);

	fscanf(file, "%d", &num);
	scrivereNumTentativiPart(p, num);

	i=0;
	while(i<leggereLunghezzaCodice(imp)){
		fscanf(file, "%d", &num);
		scrivereCorretto(&cor, i, num);
		i=i+1;
	}
	scrivereCorrettoPartita(p, cor);

	i=0;
	while(i<leggereNumTentativiPart(*p)){
		c=0;
		while(c<leggereLunghezzaCodice(imp)){
			fscanf(file, "%d", &num);
			scrivereTentativo(&t,c,num);
			c=c+1;
		}
		scrivereTentativi(p, i, t);

		fscanf(file, "%d", &num);
		scrivereRisposta(&r, 0, num);
		fscanf(file, "%d", &num);
		scrivereRisposta(&r, 1, num);
		scrivereRisposte(p, i, r);
		i=i+1;
	}

	fclose(file);
	return;
}

void visualizzareGuida(){
	FILE *file;
	int i;
	char carattere;
	int exit;

	pulireSchermata(0, 0, 24, 79);
	outputSchermo("---Guida----");
	 cambiaColore(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

	file=fopen(dataPathGuida, "r");
	i=0;
	GotoYX(0,2);
	while((carattere=fgetc(file))!= EOF){
		printf("%c", carattere);
		i=i+1;
	}

	exit=leggereNumeroVincoli("Permere un numero per tornare al menu: ", 23, 1, 0,9);
	return;
}

