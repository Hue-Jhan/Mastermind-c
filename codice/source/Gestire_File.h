#ifndef GESTIRE_FILE_H_
#define GESTIRE_FILE_H_

#include <stdio.h>
#include "Gestire_Tipi.h"

void salvarePartita(FILE *file, Partita p);
void leggerePartita(FILE *file, Partita* p);
void visualizzareGuida();

#endif
