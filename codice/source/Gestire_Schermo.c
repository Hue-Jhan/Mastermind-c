
#include <windows.h>
#include <stdio.h>

#include "Gestire_Schermo.h"

void GotoYX(int y, int x) {
    COORD CursorPos = { y, x };
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, CursorPos);
    return;
}

void pulireSchermata(int rigaInizio, int colonnaInizio, int rigaFine, int colonnaFine) {
    int i = rigaInizio;
    while (i <= rigaFine) {
        int j = colonnaInizio;
        while (j <= colonnaFine) {
            GotoYX(j, i);
            printf(" ");
            j=j+1;
        }
        i=i+1;
    }

    GotoYX(0, 0);
    return;
}

void impostaDimensioneConsole(int colonne, int righe) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD size;
    size.X = colonne;
    size.Y = righe;
    SetConsoleScreenBufferSize(hConsole, size);

    SMALL_RECT rect;
    rect.Left = 0;
    rect.Top = 0;
    rect.Right = colonne - 1;
    rect.Bottom = righe - 1;
    SetConsoleWindowInfo(hConsole, TRUE, &rect);
}

void outputSchermo(const char *c){
    GotoYX(0, 0);
    cambiaColore(BACKGROUND_BLUE | BACKGROUND_RED | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("----------------------------------%s----------------------------------",c);
    return;
}

void setConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    return;
}

void cambiaColore(int colore) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colore);
    return;
}
