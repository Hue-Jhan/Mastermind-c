
#ifndef GESTIRE_SCHERMO_H_
#define GESTIRE_SCHERMO_H_

void GotoYX(int y, int x);
void pulireSchermata(int rigaInizio, int colonnaInizio, int rigaFine, int colonnaFine);
void impostaDimensioneConsole(int colonne, int righe);
void outputSchermo(const char *c);
void setConsoleColor(int color);
void cambiaColore(int colore);

#endif
