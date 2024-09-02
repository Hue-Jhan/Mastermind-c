
#ifndef GESTIRE_PARTITA_H_
#define GESTIRE_PARTITA_H_

#include "Gestire_Tipi.h"

void generareCodice(Partita*p);
int appartenenza(int e, Corretto c);
void visualizzareCodiceNascosto(int lun);
Risposta verificareCodici(Partita p, Tentativo t);
void giocarePartita(Partita*p, int riprendi);

#endif
