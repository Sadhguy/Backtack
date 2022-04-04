#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//######## STRINGS ########//
typedef struct str{
    int* code;
    int len;
    int key;
    int inicio;
    int fin;
} Str;

Str* str_init(char* string, int length, int inicio, int fin);
void str_destroy(Str* str);

//######## SAMPLES ########//
typedef struct sample{
    Str** hebras;
    int len;
} Sample;

Sample* sample_init(int len);
void sample_destroy(Sample* sample);

//######## HASH ########//
typedef struct hash{
    Str*** table;
    int len;
} Hash;

Hash* hash_init(int len);
void hash_destroy(Hash* hash);
void tablePoblator(char* hebra, int len, Hash* hash, Sample* sample);

int alreadyIn(char let, char* string, int length);
int findSpot(Hash* hash, int key);
int sameCode(Sample* sample, int p, Str* str);

void finder(Hash* hash, Sample* sample, int p, FILE* output);