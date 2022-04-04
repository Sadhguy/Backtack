#include "structs.h"

Tablero* tablero_init(int* base, int* base2, int caballo, int* numbers){
    Tablero* tablero = calloc(1, sizeof(Tablero));
    tablero -> casillas = calloc(64, sizeof(int));
    tablero -> casillas = base;
    tablero -> base = calloc(64, sizeof(int));
    tablero -> base = base2;
    tablero -> numbers = numbers;
    tablero -> caballo = caballo;
    return tablero;
}

// int* searchMove(Tablero* tablero, int paso){
//     int* moves = calloc(8, sizeof(int));
//     int cm = 1;
//     int y = tablero -> caballo/8;
//     int x = tablero -> caballo - y*8;
//     if (numbered(tablero, paso)){
//         if (x - 1 >= 0 && y - 2 >= 0 && sumReview(tablero, x - 1, y - 2, paso) == 1 && 
//         tablero -> casillas[tablero -> caballo - 17] == paso){
//             moves[1] = tablero -> caballo - 17;
//             cm++;
//         } else if (x + 1 < 8 && y - 2 >= 0 && sumReview(tablero, x + 1, y -2, paso) == 1 && 
//         tablero -> casillas[tablero -> caballo - 15] == paso){
//             moves[1] = tablero -> caballo - 15;
//             cm++;
//         } else if ( x - 2 >= 0 && y - 1 >= 0 && sumReview(tablero, x - 2, y - 1, paso) == 1 &&
//         tablero -> casillas[tablero -> caballo - 10] == paso){
//             moves[1] = tablero -> caballo - 10;
//             cm++;
//         } else if (x + 2 < 8 && y - 1 >= 0 && sumReview(tablero, x + 2, y - 1, paso) == 1 &&
//         tablero -> casillas[tablero -> caballo - 6] == paso){
//             moves[1] = tablero -> caballo - 6;
//             cm++;
//         } else if (x - 2 >= 0 && y + 1 < 8 && sumReview(tablero, x - 2, y + 1, paso) == 1 &&
//         tablero -> casillas[tablero -> caballo + 6] == paso){
//             moves[1] = tablero -> caballo + 6;
//             cm++;
//         } else if (x + 2 < 8 && y + 1 < 8 && sumReview(tablero, x + 2, y + 1, paso) == 1 &&
//         tablero -> casillas[tablero -> caballo + 10] == paso){
//             moves[1] = tablero -> caballo + 10;
//             cm++;
//         } else if (x - 1 >= 0 && y + 2 < 8 && sumReview(tablero, x - 1, y + 2, paso) == 1 &&
//         tablero -> casillas[tablero -> caballo + 15] == paso){
//             moves[1] = tablero -> caballo + 15;
//             cm++;
//         } else if (x + 1 < 8 && y + 2 < 8 && sumReview(tablero, x + 1, y + 2, paso) == 1 && 
//         tablero -> casillas[tablero -> caballo + 17] == paso){
//             moves[1] = tablero -> caballo + 17;
//             cm++;
//         }
//     } else {
//         if ( x - 1 >= 0 && y - 2 >= 0 && sumReview(tablero, x - 1, y - 2, paso) == 1 &&
//         (tablero -> casillas[tablero -> caballo -17] == 0)){
//             moves[cm] = tablero -> caballo - 17;
//             cm++;
//         }
//         if ( x + 1 < 8 && y - 2 >= 0 && sumReview(tablero, x + 1, y - 2, paso) == 1 &&
//         (tablero -> casillas[tablero -> caballo -15] == 0)){
//             moves[cm] = tablero -> caballo - 15;
//             cm++;
//         }
//         if ( x - 2 >= 0 && y - 1 >= 0 && sumReview(tablero, x - 2, y - 1, paso) == 1&&
//         (tablero -> casillas[tablero -> caballo -10] == 0)){
//             moves[cm] = tablero -> caballo - 10;
//             cm++;
//         }
//         if ( x + 2 < 8 && y - 1 >= 0 && sumReview(tablero, x + 2, y - 1, paso) == 1 &&
//         (tablero -> casillas[tablero -> caballo - 6] == 0)){
//             moves[cm] = tablero -> caballo - 6;
//             cm++;
//         }
//         if ( x - 2 >= 0 && y + 1 < 8 && sumReview(tablero, x - 2, y + 1, paso) == 1 &&
//         (tablero -> casillas[tablero -> caballo + 6] == 0)){
//             moves[cm] = tablero -> caballo + 6;
//             cm++;
//         }
//         if ( x + 2 < 8 && y + 1 < 8 && sumReview(tablero, x + 2, y + 1, paso) == 1 &&
//         (tablero -> casillas[tablero -> caballo + 10] == 0)){
//             moves[cm] = tablero -> caballo + 10;
//             cm++;
//         }
//         if ( x - 1 >= 0 && y + 2 < 8 && sumReview(tablero, x - 1, y + 2, paso) == 1 &&
//         (tablero -> casillas[tablero -> caballo + 15] == 0)){
//             moves[cm] = tablero -> caballo + 15;
//             cm++;
//         }
//         if ( x + 1 < 8 && y + 2 < 8 && sumReview(tablero, x + 1, y + 2, paso) == 1 && 
//         (tablero -> casillas[tablero -> caballo + 17] == 0)){
//             moves[cm] = tablero -> caballo + 17;
//             cm++;
//         }
//     }
//     moves[0] = cm;
//     return moves;
// }

int* searchMove(Tablero* tablero, int paso){
    int* moves = calloc(8, sizeof(int));
    int cm = 1;
    int y = tablero -> caballo/8;
    int x = tablero -> caballo - y*8;
    if (numbered(tablero, paso)){
        if (x - 1 >= 0 && y - 2 >= 0 && 
        tablero -> casillas[tablero -> caballo - 17] == paso){
            moves[1] = tablero -> caballo - 17;
            cm++;
        } else if (x + 1 < 8 && y - 2 >= 0 &&  
        tablero -> casillas[tablero -> caballo - 15] == paso){
            moves[1] = tablero -> caballo - 15;
            cm++;
        } else if ( x - 2 >= 0 && y - 1 >= 0 && 
        tablero -> casillas[tablero -> caballo - 10] == paso){
            moves[1] = tablero -> caballo - 10;
            cm++;
        } else if (x + 2 < 8 && y - 1 >= 0 && 
        tablero -> casillas[tablero -> caballo - 6] == paso){
            moves[1] = tablero -> caballo - 6;
            cm++;
        } else if (x - 2 >= 0 && y + 1 < 8 && 
        tablero -> casillas[tablero -> caballo + 6] == paso){
            moves[1] = tablero -> caballo + 6;
            cm++;
        } else if (x + 2 < 8 && y + 1 < 8 && 
        tablero -> casillas[tablero -> caballo + 10] == paso){
            moves[1] = tablero -> caballo + 10;
            cm++;
        } else if (x - 1 >= 0 && y + 2 < 8 &&
        tablero -> casillas[tablero -> caballo + 15] == paso){
            moves[1] = tablero -> caballo + 15;
            cm++;
        } else if (x + 1 < 8 && y + 2 < 8 && 
        tablero -> casillas[tablero -> caballo + 17] == paso){
            moves[1] = tablero -> caballo + 17;
            cm++;
        }
    } else {
        if ( x - 1 >= 0 && y - 2 >= 0 && 
        (tablero -> casillas[tablero -> caballo -17] == 0)){
            moves[cm] = tablero -> caballo - 17;
            cm++;
        }
        if ( x + 1 < 8 && y - 2 >= 0 && 
        (tablero -> casillas[tablero -> caballo -15] == 0)){
            moves[cm] = tablero -> caballo - 15;
            cm++;
        }
        if ( x - 2 >= 0 && y - 1 >= 0 && 
        (tablero -> casillas[tablero -> caballo -10] == 0)){
            moves[cm] = tablero -> caballo - 10;
            cm++;
        }
        if ( x + 2 < 8 && y - 1 >= 0 && 
        (tablero -> casillas[tablero -> caballo - 6] == 0)){
            moves[cm] = tablero -> caballo - 6;
            cm++;
        }
        if ( x - 2 >= 0 && y + 1 < 8 && 
        (tablero -> casillas[tablero -> caballo + 6] == 0)){
            moves[cm] = tablero -> caballo + 6;
            cm++;
        }
        if ( x + 2 < 8 && y + 1 < 8 && 
        (tablero -> casillas[tablero -> caballo + 10] == 0)){
            moves[cm] = tablero -> caballo + 10;
            cm++;
        }
        if ( x - 1 >= 0 && y + 2 < 8 && 
        (tablero -> casillas[tablero -> caballo + 15] == 0)){
            moves[cm] = tablero -> caballo + 15;
            cm++;
        }
        if ( x + 1 < 8 && y + 2 < 8 && 
        (tablero -> casillas[tablero -> caballo + 17] == 0)){
            moves[cm] = tablero -> caballo + 17;
            cm++;
        }
    }
    moves[0] = cm;
    return moves;
}

int move(Tablero* tablero, int paso){
    if (paso == 65){
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
                if (!sumReview(tablero, i, j, 0)){
                    return 0;
                }
            }
        }
        return 1;
    } else { 
        int inicial = tablero -> caballo;
        int* moves = calloc(8, sizeof(int));
        moves = searchMove(tablero, paso);
        for (int m = 1; m < moves[0]; m++){
            tablero -> caballo = moves[m];
            tablero -> casillas[tablero -> caballo] = paso;
            if (move(tablero, paso + 1)){
                return 1;
            } else {
                tablero -> casillas[tablero -> caballo] = tablero -> base[tablero -> caballo];
                tablero -> caballo = inicial;
            }
        }
        return 0;
    }
}

void printTablero(Tablero* tablero, FILE* output){
    for (int c = 1; c < 65; c++){
        printf(" %d ", tablero -> casillas[c-1]);
        fprintf(output, "%d ", tablero -> casillas[c-1]);
        if (c%8 == 0){
            printf("\n");
            fprintf(output, "\n");
        }
    }
}

int numbered(Tablero* tablero, int paso){
    for (int n = 1; n < tablero -> numbers[0]; n++){
        if (tablero -> numbers[n] == paso){
            return 1;
        }
    }
    return 0;
}

int sumReview(Tablero* tablero, int x, int y, int paso){
    int sumFila = paso;
    int sumCol = paso;
    for (int c = 0; c < 8; c++){
        sumCol += tablero -> casillas[x + 8*c];
        sumFila += tablero -> casillas[y*8 + c];
    }
    if (sumCol > 260 || sumFila > 260){
        return 0;
    } else {
        return 1;
    }
}