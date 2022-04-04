#include "structs.h"


Str* str_init(char* string, int length, int inicio, int fin){
    Str* str = calloc(1, sizeof(Str));
    str -> len = length;
    str -> key = 0;
    str -> inicio = inicio;
    str -> fin = fin - 1;
    str -> code = calloc(length, sizeof(int));

    int cont = 0;
    int in;
    char* check = calloc(length, sizeof(char));

    for (int c = 0; c < length; c++){
        in = alreadyIn(string[c], check, cont);
        if (in != 0){
            str -> code[c] = str -> code[in-1];
            str -> key += str -> code[c];
            //printf("Num: %i Char: %c, Code: %c\n", c, string[c], cn);
            // printf("key: %i\n", str->key);
        } else {
            cont ++;
            str -> key += cont;
            str -> code[c] = cont;
            //printf("Num: %i Char: %c, Code: %c\n", c, string[c], cn);
            // printf("key: %i\n", str->key);
        }
        check[c] = string[c];
    }
    return str;
}

void str_destroy(Str* str){
    free(str);
}

Hash* hash_init(int len){
    Hash* hash = calloc(1, sizeof(Hash));
    hash -> len = 27*len;
    hash -> table = calloc(hash -> len, sizeof(Str**));
    for (int l = 0; l < hash -> len; l++){
        Str** strs = calloc(1000, sizeof(Str*));
        hash -> table[l] = strs;
    }
    return hash;
}

void hash_destroy(Hash* hash){
    for (int l = 0; l < hash -> len; l++){
        for (int s = 0; 0 < 1000; s++){
            if (hash -> table[l][s]){
                free(hash -> table[l][s]);
            }
        }
        free(hash -> table[l]);
    }
    free(hash);
}

Sample* sample_init(int len){
    Sample* sample = calloc(1, sizeof(Sample));
    sample -> hebras = calloc(len, sizeof(Str*));
    sample -> len = len;
    return sample;
}

void sample_destroy(Sample* sample){
    for (int s = 0; s < sample -> len; s++){
        if (sample -> hebras[s]){
            str_destroy(sample -> hebras[s]);
        }
    }
    free(sample);
}

void tablePoblator(char* hebra, int len, Hash* hash, Sample* sample){
    for (int c = 0; c < len; c++){
        for (int h = 0; h < sample -> len; h++){
            int hebraLen = sample -> hebras[h] -> len;
            char* test = calloc(hebraLen, sizeof(char));
            for (int i = c; i < c + hebraLen; i++){
                if (i < len){
                    test[i-c] = hebra[i];
                }
            }
            Str* str = str_init(test, hebraLen, c, c + hebraLen);
            if (sample -> hebras[h] -> key == str -> key){
                int spot = findSpot(hash, str -> key);
                hash -> table[str -> key][spot] = str;
            }
        }
    }
}

void finder(Hash* hash, Sample* sample, int p, FILE* output){
    for (int s = 0; s < 1000; s++){
        if (hash -> table[sample -> hebras[p] -> key][s]){
            if (sameCode(sample, p, hash -> table[sample -> hebras[p] -> key][s])){
                printf("FOUND\n");
                printf("%i %i\n", hash -> table[sample -> hebras[p] -> key][s] -> inicio, hash -> table[sample -> hebras[p] -> key][s] -> fin);
                fprintf(output, "%i %i\n", hash -> table[sample -> hebras[p] -> key][s] -> inicio, hash -> table[sample -> hebras[p] -> key][s] -> fin);
                break;
            }
        }
    }
}

int sameCode(Sample* sample, int p, Str* str){
    int cont = 0;
    if (sample -> hebras[p] -> len == str -> len){
        for (int c = 0; c < str -> len; c++){
            if (sample -> hebras[p] -> code[c] == str -> code[c]){
                cont++;
            }
        }
    }
    if (cont == str -> len){
        return 1;
    } else {
        return 0;
    }
}

int findSpot(Hash* hash, int key){
    for (int s = 0; s < 1000; s++){
        if (!hash -> table[key][s]){
            return s;
        }
    }
    return -1;
}

int alreadyIn(char let, char* string, int length){
    for (int c=0; c < length; c++){
        if (string[c] && (let == string[c])){
            return c+1;
        }
    }
    return 0;
}