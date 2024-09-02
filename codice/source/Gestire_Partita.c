

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>

#include "Gestire_Partita.h"
#include "Gestire_Schermo.h"
#include "Globali.h"
#include "Gestire_File.h"
#include "Gestire_Input.h"

int appartenenza(int e, Corretto c){

	int posI = 0;
	int appartiene=0;

	posI = 0;
	while (posI < leggereLunCorretto(c) && appartiene == 0) {
		if (e == leggereCorretto(c,posI)) {
			appartiene = 1;
		} else {
			posI++;
		}
	}

	return appartiene;
}


void generareCodice(Partita*p){
	int i;
	int num;
	Corretto c;
	i=0;
	srand(time(NULL));
	scrivereLunCorretto(&c,leggereLunghezzaCodice(leggereImpostazioni(*p)));
	while(i<leggereLunCorretto(c)){
		if (leggereDoppi(leggereImpostazioni(*p))==1) {
			   num= rand() % (leggereNumSimboli(leggereImpostazioni(*p))-1);
		}else{
			do{
				num=rand() % (leggereNumSimboli(leggereImpostazioni(*p))-1);
			}while(appartenenza(num, c)==1);
	    }
		scrivereCorretto(&c,i,num);
		i=i+1;
	}
	scrivereCorrettoPartita(p,c);

	return;
}

void visualizzareCodiceNascosto(int lun){
	int i;
	i=0;
	GotoYX(25,2);
	printf("Il codice segreto: ");
	while(i<lun){
		printf("x");
		i=i+1;
	}
	return;
}

Risposta verificareCodici(Partita p, Tentativo temp){
	Risposta r;
	Corretto c;
	Tentativo t;
	bool trovata;
	int i;
	int a;
	int numOK;
	int numNok;

	c=leggereCorrettoPartita(p);
	t=temp;

	i=0;
	numOK=0;
	while(i<leggereLunTentativo(temp)){
		if(leggereTentativo(t,i)==leggereCorretto(c,i)){
			numOK=numOK+1;
			scrivereCorretto(&c,i,-1);
			scrivereTentativo(&t,i,-2);
		}
		i=i+1;
	}
	i=0;
	numNok=0;
	trovata=false;
	while(i<leggereLunTentativo(temp)){
		a=0;
		trovata=false;
		while(a<leggereLunTentativo(temp) && trovata==false){
			if(leggereTentativo(t,i)==leggereCorretto(c,a)){
				numNok=numNok+1;
				trovata=true;
				scrivereCorretto(&c,a,-1);
			}
			a=a+1;
		}
		i=i+1;
	}
	scrivereLunRisposta(&r, 2);
	scrivereRisposta(&r,0,numOK);
	scrivereRisposta(&r,1,numNok);

	return r;
}

void giocarePartita(Partita*p, int riprendi){
	int exit;
	int tentativi;
	int i;
	int a;
	int giusto;
	int num;
	Tentativo t;
	Risposta r;
	FILE *fileL;

	pulireSchermata(0, 0, 24, 79);
	outputSchermo("---Gioca!---");
	cambiaColore(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

	if(riprendi==1){
		fileL=fopen(datapath, "r");
		if(fileL!=NULL){
			leggerePartita(fileL, p);
			tentativi=leggereNumTentativiPart(*p);
			i=0;
			while(i<tentativi){
				GotoYX(25,9+i);
				printf("\nTentativo %d --> ", i+1);
				a=0;
				while(a<leggereLunghezzaCodice(leggereImpostazioni(*p))){
					printf("%d", leggereTentativo(leggereTentativi(*p,i),a));
					a=a+1;
				}
				printf("| Risultato --> %d posizione giusta - ", leggereRisposta(leggereRisposte(*p,i),0));
				printf("%d posizione errata",leggereRisposta(leggereRisposte(*p,i),1));
				i=i+1;
			}
			exit=1;
		}else{
			printf("Nessuna partita salvata. Gioca!");
			tentativi=0;
			generareCodice(p);
			exit = leggereNumeroVincoli("Permere 0 per tornare al menu': ", 4, 1, 0,0);
		}
	}else{
		tentativi=0;
		generareCodice(p);
		exit = leggereNumeroVincoli("Permere 0 se vuoi tornare al menu', altrimenti premi un altro numero: ", 4, 1, 0,9);
	}
	scrivereLunTentativo(&t,leggereLunghezzaCodice(leggereImpostazioni(*p)));
	scrivereLunRisposta(&r, 2);

	while(exit!=0){
		visualizzareCodiceNascosto(leggereLunghezzaCodice(leggereImpostazioni(*p)));
	    //printf("CORRETTO--> %d %d %d %d %d %d", leggereCorretto(leggereCorrettoPartita(*p),0),leggereCorretto(leggereCorrettoPartita(*p),1),leggereCorretto(leggereCorrettoPartita(*p),2),leggereCorretto(leggereCorrettoPartita(*p),3),leggereCorretto(leggereCorrettoPartita(*p),4),leggereCorretto(leggereCorrettoPartita(*p),5));
		GotoYX(25, 2);
		giusto=0;
		if(exit!=0){
			while(tentativi<leggereNumTentativi(leggereImpostazioni(*p)) && exit!=0){
				i=0;
				pulireSchermata(4,0,3+leggereLunghezzaCodice(leggereImpostazioni(*p)),79);
				while(i<leggereLunTentativo(t)){
					do{
						pulireSchermata(4+i,0,4+i,79);
						GotoYX(21,4+i);
						printf("Inserire cifra tra 0 e %d: ",(leggereNumSimboli(leggereImpostazioni(*p))-1));
						scanf("%d", &num);
					}while(num<0 || num>leggereNumSimboli(leggereImpostazioni(*p))-1);
					scrivereTentativo(&t,i,num);
					i=i+1;
				}
				tentativi=tentativi+1;
				GotoYX(25,9+tentativi-1);

				r=verificareCodici(*p,t);
				scrivereNumTentativiPart(p,tentativi);
				scrivereTentativi(p,tentativi-1, t);
				scrivereRisposte(p,tentativi-1, r);

				printf("\nTentativo %d --> ", tentativi);
				a=0;
				while(a<leggereLunTentativo(t)){
					printf("%d", leggereTentativo(t,a));
					a=a+1;
				}
				printf("| Risultato --> %d posizione giusta - ", leggereRisposta(r,0));
				printf("%d posizione errata",leggereRisposta(r,1));

				if(leggereRisposta(r,0)==leggereLunTentativo(t)){
					exit=0;
					giusto=1;
				}
				else if(tentativi==leggereNumTentativi(leggereImpostazioni(*p))){
					exit=0;
					giusto=-1;
				}else{
					exit=leggereNumeroVincoli("Permere 0 se vuoi tornare al menu', altrimenti premi un altro numero: ", 22, 1, 0,9);
				}

			}
		}
	}

	if(giusto==1){
		GotoYX(25,20);
		cambiaColore(FOREGROUND_GREEN);
		printf("Hai indovinato!");
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	}else if(giusto==-1){
		GotoYX(25,20);
		cambiaColore(FOREGROUND_RED);
		printf("Hai perso...");
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	}

	if(giusto==1 || giusto==-1){
		GotoYX(25,21);
		printf("Il codice corretto era: ");
		int i=0;
		while(i<leggereLunghezzaCodice(leggereImpostazioni(*p))){
			printf("%d",leggereCorretto(leggereCorrettoPartita(*p),i));
			i=i+1;
		}
		exit=leggereNumeroVincoli("Permere un numero per tornare al menu: ", 23, 1, 0,9);
	}
	return;
}
