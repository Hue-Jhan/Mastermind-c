#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include "Gestire_Tipi.h"
#include "Globali.h"
#include "Gestire_Schermo.h"
#include "Gestire_Partita.h"
#include "Gestire_impostazioni.h"
#include "Gestire_Input.h"
#include "Gestire_File.h"

void visualizzareMenu(Partita*p);

int main(void) {
   impostaDimensioneConsole(80, 25);

   Partita p;
   visualizzareMenu(&p);

   pulireSchermata(0, 0, 24, 79);

   system("pause");
   return 0;
}

void visualizzareMenu(Partita*p) {
	Impostazioni impostazioni;
	FILE *file;
	int riprendi;

	impostazioniDefault(&impostazioni, MAXTENTATIVI, MAXLUNCODICE, MAXSIMBOLI, 1);
	scrivereImpostazioni(p,impostazioni);
    int scelta;
    do {
        pulireSchermata(0, 0, 24, 79);

        outputSchermo("-MasterMind-");

        GotoYX(27, 2);
        cambiaColore(FOREGROUND_BLUE | FOREGROUND_RED);
        printf("1 --> ");
        cambiaColore(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
        printf("Guida del gioco");

        GotoYX(27, 3);
        cambiaColore(FOREGROUND_BLUE | FOREGROUND_RED);
		printf("2 --> ");
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
        printf("Impostazioni di gioco");

        GotoYX(27, 4);
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_RED);
		printf("3 --> ");
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		printf("Gioca");

		GotoYX(27, 5);
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_RED);
		printf("4 --> ");
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		printf("Salva partita");

        GotoYX(27, 9);
        cambiaColore(FOREGROUND_BLUE | FOREGROUND_GREEN);
       	printf("0 --> Termina gioco");
       	cambiaColore(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

        scelta = leggereNumeroVincoli("Inserire il numero della voce del menu' compreso tra 0 e 4: ", 12, 10, 0,4);

        if(scelta==1){
        	visualizzareGuida();
        }else if(scelta==2){
        	visualizzareImpostazioni(&impostazioni);
        	scrivereImpostazioni(p,impostazioni);
        }else if(scelta==3){
        	riprendi=leggereNumeroVincoli("Inserire 1 per riprendere partita altrimenti premere 0: ", 12, 12, 0,4);
        	giocarePartita(p, riprendi);
        }else if(scelta==4){
        	file=fopen(datapath, "w");
        	salvarePartita(file, *p);
        	fclose(file);
        }
    } while (scelta != 0);

}
