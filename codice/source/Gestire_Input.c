
#include <stdio.h>
#include "Gestire_Input.h"
#include "Gestire_Schermo.h"

int leggereIntero() {
    int n;
    scanf("%d", &n);
    return n;
}

int leggereNumeroVincoli(const char*s, int x, int y, int min, int max){
	int n;
	do{
		GotoYX(y,x);
		printf("%s", s);
		n=leggereIntero();
		pulireSchermata(x, 0, x, 79);
	}while(n<min || n>max);
	return n;
}

