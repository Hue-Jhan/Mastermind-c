
#include "Gestire_Tipi.h"
#include "Globali.h"

void scrivereNumTentativi(Impostazioni *impostazioni, int num_tentativi) {
    impostazioni->num_tentativi = num_tentativi;
    return;
}

int leggereNumTentativi(Impostazioni impostazioni) {
    return impostazioni.num_tentativi;
}

void scrivereLunghezzaCodice(Impostazioni *impostazioni, int lunghezza_codice) {
    impostazioni->lunghezza_codice = lunghezza_codice;
    return;
}

int leggereLunghezzaCodice(Impostazioni impostazioni) {
    return impostazioni.lunghezza_codice;
}

void scrivereNumSimboli(Impostazioni *impostazioni, int num_simboli) {
    impostazioni->num_simboli = num_simboli;
    return;
}

int leggereNumSimboli(Impostazioni impostazioni) {
    return impostazioni.num_simboli;
}

void scrivereDoppi(Impostazioni *impostazioni, int doppi) {
    impostazioni->doppi = doppi;
    return;
}

int leggereDoppi(Impostazioni impostazioni) {
    return impostazioni.doppi;
}

void scrivereTentativo(Tentativo *t, int pos, int value) {
	t->tentativo[pos] = value;
	return;
}

int leggereTentativo(Tentativo t, int pos) {
    return t.tentativo[pos];
}

void scrivereLunTentativo(Tentativo *t, int l) {
	t->dimensione = l;
	return;
}

int leggereLunTentativo(Tentativo t) {
    return t.dimensione;
}

void scrivereRisposta(Risposta *r, int pos, int value) {
    r->risposta[pos] = value;
    return;
}
int leggereRisposta(Risposta r, int pos) {
    return r.risposta[pos];
}

void scrivereLunRisposta(Risposta *r, int l) {
	r->dimensione = l;
	return;
}

int leggereLunRisposta(Risposta r) {
    return r.dimensione;
}

void scrivereCorretto(Corretto*c, int pos, int cifra){
	c->corretto[pos]=cifra;
	return;
}

int leggereCorretto(Corretto c, int pos){
	return c.corretto[pos];
}

void scrivereLunCorretto(Corretto *c, int l) {
	c->dimensione = l;
	return;
}

int leggereLunCorretto(Corretto c) {
    return c.dimensione;
}

void scrivereImpostazioni(Partita*p, Impostazioni impostazioni){
	p->imp=impostazioni;
	return;
}
Impostazioni leggereImpostazioni(Partita p){
	return p.imp;
}

void scrivereTentativi(Partita*p, int pos, Tentativo t){
	p->tentativi[pos]=t;
	return;
}
Tentativo leggereTentativi(Partita p, int pos){
	return p.tentativi[pos];
}

void scrivereRisposte(Partita*p, int pos, Risposta r){
	p->risposte[pos]=r;
	return;
}

Risposta leggereRisposte(Partita p, int pos){
	return p.risposte[pos];
}

void scrivereNumTentativiPart(Partita*p, int num){
	p->numTentativiPart=num;
	return;
}

int leggereNumTentativiPart(Partita p){
	return p.numTentativiPart;
}

void scrivereCorrettoPartita(Partita*p, Corretto corretto){
	p->corretto=corretto;
	return;
}

Corretto leggereCorrettoPartita(Partita p){
	return p.corretto;
}
