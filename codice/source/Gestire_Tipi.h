#ifndef GESTIRE_TIPI_H_
#define GESTIRE_TIPI_H_

#include "Globali.h"

typedef struct {
	int num_tentativi;      //tentativi per indovinare il codice
	int lunghezza_codice;   //lunghezza del codice da indovinare
	int num_simboli;        //numero di cifre da usare nel codice
	int doppi;              //ci possono essere cifre ripetute o meno
} Impostazioni;

typedef struct {
	int tentativo[MAXLUNCODICE];
	int dimensione;
} Tentativo;

typedef struct {
	int risposta[2];
	int dimensione;
} Risposta;

typedef struct {
	int corretto[MAXLUNCODICE];
	int dimensione;
} Corretto;

typedef struct {
    Impostazioni imp;
    Tentativo tentativi[MAXTENTATIVI];
    Risposta risposte[MAXTENTATIVI];
    int numTentativiPart;
    Corretto corretto;
} Partita;

void scrivereNumTentativi(Impostazioni *impostazioni, int num_tentativi);
int leggereNumTentativi(Impostazioni impostazioni);
void scrivereLunghezzaCodice(Impostazioni *impostazioni, int lunghezza_codice);
int leggereLunghezzaCodice(Impostazioni impostazioni);
void scrivereNumSimboli(Impostazioni *impostazioni, int num_simboli);
int leggereNumSimboli(Impostazioni impostazioni);
void scrivereDoppi(Impostazioni *impostazioni, int doppi);
int leggereDoppi(Impostazioni impostazioni);

void scrivereTentativo(Tentativo *t, int pos, int value);
int leggereTentativo(Tentativo t, int pos);
void scrivereLunTentativo(Tentativo *t, int l);
int leggereLunTentativo(Tentativo t);

void scrivereRisposta(Risposta *r, int pos, int value);
int leggereRisposta(Risposta r, int pos);
void scrivereLunRisposta(Risposta *r, int l);
int leggereLunRisposta(Risposta r);

void scrivereCorretto(Corretto*c, int pos, int cifra);
int leggereCorretto(Corretto c, int pos);
void scrivereLunCorretto(Corretto *c, int l);
int leggereLunCorretto(Corretto c);


void scrivereImpostazioni(Partita*p, Impostazioni impostazioni);
Impostazioni leggereImpostazioni(Partita p);
void scrivereTentativi(Partita*p, int pos, Tentativo t);
Tentativo leggereTentativi(Partita p, int pos);
void scrivereRisposte(Partita*p, int pos, Risposta r);
Risposta leggereRisposte(Partita p, int pos);
void scrivereNumTentativiPart(Partita*p, int num);
int leggereNumTentativiPart(Partita p);
void scrivereCorrettoPartita(Partita*p, Corretto corretto);
Corretto leggereCorrettoPartita(Partita p);


#endif
