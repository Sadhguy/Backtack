#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashing/structs.h"
#include "backtracking/structs.h"

int main(int argc, char** argv)
{
    char* option;
    // Revisamos los argumentos
    FILE *output_file = fopen(argv[3], "w");
    FILE *input_file = fopen(argv[2], "r");

    if(argc < 4) {
        printf("Modo de uso: %s <A/B> <input.txt> <output.txt>\n", argv[0]);
        return 1;
    }
    option = argv[1];
    if(strcmp(option, "A") == 0){
        // Parte 1 de la Tarea
        char nul;
        int T;
        fscanf(input_file, "%d", &T);
        fscanf(input_file, "%c", &nul);
        char* hebra = calloc(T, sizeof(char));
        for (int c = 0; c < T; c++){
            fscanf(input_file, "%c", &hebra[c]);
        }
        int M;
        fscanf(input_file, "%d", &M);
        Hash* hash = hash_init(T);
        Sample* sample = sample_init(M);
        for (int s = 0; s < M; s++){
            int len;
            fscanf(input_file, "%d", &len);
            fscanf(input_file, "%c", &nul);
            char* samp = calloc(len, sizeof(char));
            for (int c = 0; c < len; c++){
                fscanf(input_file, "%c", &samp[c]);
            }
            sample -> hebras[s] = str_init(samp, len, 0, len - 1);

        }
        tablePoblator(hebra, T, hash, sample);
        for (int s = 0; s < M; s++){
            finder(hash, sample, s, output_file);
        }

        hash_destroy(hash);
        //sample_destroy(sample);
        
    }

    else if(strcmp(option, "B") == 0){
        // Parte 2 de la Tarea
        int* base = calloc(64, sizeof(int));
        int* base2 = calloc(64, sizeof(int));
        int* numbers = calloc(64, sizeof(int));
        int numCont = 1;
        int inicio = 0;
        for (int c = 0; c < 64; c++){
            fscanf(input_file, "%d", &base[c]);
            if (base[c] != 0){
                numbers[numCont] = base[c];
                numCont ++;
            }
            if (base[c] == 1){
                inicio = c;
            }
        }
        for (int c = 0; c < 64; c++){
            base2[c] = base[c];
        }
        numbers[0] = numCont;
        printf("INICIO: %d\n", inicio);
        for (int n = 1; n < numbers[n]; n++){
            printf("%d ", numbers[n]);
        }
        printf("\n");
        Tablero* tablero = tablero_init(base, base2, inicio, numbers);
        move(tablero, 2);
        printTablero(tablero, output_file);

    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}