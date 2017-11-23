#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *characterTable = NULL;

void sizeCharacterTableForasciiSymbol(unsigned ash) {    
    int h = (int)ash;
    int thresh = sizeof(characterTable);
    if (h >= thresh) {
        characterTable = realloc(characterTable, sizeof(char) * h);
    }
}

char * exclude(char *exclude, char *fromThese) {
    characterTable = malloc(sizeof(char *));
    
    int indicesCount = 0;
    int i;
    for (i=0; exclude[i]!='\0'; i++) {
        char fromThis = exclude[i];
        if (fromThis == *" ") {
            continue; 
        }
        unsigned asciiValue = (int)fromThis; 
        sizeCharacterTableForasciiSymbol(asciiValue);
        characterTable[asciiValue] = fromThis;
    } 

    char *survived = malloc(i*(sizeof(char)) + 1);
    indicesCount = 0;
    i = 0;
    for (i=0; fromThese[i]!='\0'; i++) {
        char fromTheuse = fromThese[i];
        unsigned asciiValue = (int)fromTheuse;
        char compare = characterTable[asciiValue];        
        if (fromTheuse != compare) { 
            survived[indicesCount] = fromTheuse;
            indicesCount++;
        }
    }
    free(characterTable);
    return realloc(survived, indicesCount*sizeof(char));//survived;
}

int main() {
    char *ex = "aBC d f F G  nmlt q Q R o ST uvz";// = exa;
    char *fr = "abcdefgHIJKLMNOPQRSTUVwxyz";// = fro;
    char *e = exclude(ex, fr);
    printf("exclude: %s\n", ex);
    printf("from: %s\n", fr);
    printf("\n----\n");
    printf("result: %s\n", e);
}

