#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//######## TABLERO #########
typedef struct tablero{
    int* casillas;
    int* base;
    int* numbers;
    int caballo;
} Tablero;

Tablero* tablero_init(int* base, int* base2, int caballo, int* numbers);


int move(Tablero* tablero, int paso);
int* searchMove(Tablero* tablero, int paso);
void printTablero(Tablero* tablero, FILE* output);
int numbered(Tablero* tablero, int paso);
int sumReview(Tablero* tablero, int x, int y, int paso);