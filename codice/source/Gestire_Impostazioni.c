
#include <windows.h>
#include <stdio.h>
#include "Gestire_Impostazioni.h"
#include "Globali.h"
#include "Gestire_Tipi.h"
#include "Gestire_Schermo.h"
#include "Gestire_Input.h"

void impostazioniDefault(Impostazioni*imp, int t, int l, int s, int d){
	scrivereNumTentativi(imp, t);
	scrivereLunghezzaCodice(imp, l);
	scrivereNumSimboli(imp, s);
	scrivereDoppi(imp, d);
	return;
}

void visualizzareImpostazioni(Impostazioni*imp){
	int scelta;

	do{
		pulireSchermata(0, 0, 24, 79);

		outputSchermo("Impostazioni");

		GotoYX(27, 2);
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_RED);
		printf("Numero tentativi: ");
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		printf("%d", leggereNumTentativi(*imp));

		GotoYX(27, 3);
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_RED);
		printf("Numero simboli: ");
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		printf("%d",leggereNumSimboli(*imp));

		GotoYX(27, 4);
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_RED);
		printf("Lunghezza codice: ");
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		printf("%d",leggereLunghezzaCodice(*imp));

		GotoYX(27, 5);
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_RED);
		printf("Cifre ripetute: ");
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		if(leggereDoppi(*imp)==1){
			printf("Si");
		}else{
			printf("No");
		}

		scelta = leggereNumeroVincoli("Premere 1 per modificare le impostazioni o 0 per tornare al menu: ", 8, 7, 0,1);

		if(scelta==1){
			modificareImpostazioni(imp);
		}
	}while(scelta!=0);

	return;
}

void modificareImpostazioni(Impostazioni*imp){
	int scelta;
	do{
		pulireSchermata(0, 0, 24, 79);

		outputSchermo("Impostazioni");

		GotoYX(27, 2);
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_RED);
		printf("1 --> ");
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		printf("Modifica numero tentativi");

		GotoYX(27, 3);
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_RED);
		printf("2 --> ");
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		printf("Modifica numero simboli");

		GotoYX(27, 4);
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_RED);
		printf("3 --> ");
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		printf("Modifica lunghezza codice");

		GotoYX(27, 5);
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_RED);
		printf("4 --> ");
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		printf("Modifica cifre ripetute");

		GotoYX(27, 9);
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_GREEN);
		printf("0 --> Torna alla visualizzazione delle impostazioni");
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

		scelta = leggereNumeroVincoli("Inserire valore corrispondente: ", 12, 27, 0,4);

		pulireSchermata(0, 0, 24, 79);
		outputSchermo("Impostazioni");
		cambiaColore(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		GotoYX(20, 2);
		if(scelta==1){
			scrivereNumTentativi(imp, leggereNumeroVincoli("Numero tentativi compreso tra 3 e 8: ",2,20,3,MAXTENTATIVI));
		}else if(scelta==2){
			scrivereNumSimboli(imp, leggereNumeroVincoli("Numero simboli compreso tra 3 e 10: ",2,20,3,MAXSIMBOLI));
		}else if(scelta==3){
			scrivereLunghezzaCodice(imp, leggereNumeroVincoli("Lunghezza codice compreso tra 3 e 8: ",2,20,3,MAXLUNCODICE));
		}else if(scelta==4){
			scrivereDoppi(imp, leggereNumeroVincoli("Cifre ripetute 0=no o 1=si: ",2,20,0,1));
		}
	}while(scelta!=0);
	return;
}
