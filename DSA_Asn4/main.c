// Dina Makhdoom
// DSA Asn 4
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

#define M 11
int main(void) {

    int input[] = { 764, 35954, 8683, 41, 11004, 1362, 77, 1, 448, 118, 5507 };
    int R = 7;
    int hashTable[M];

    // Initialize and fill the hash table
    hashInit(hashTable, input, M, R);

    // Print the contents of the hash table
    printf("Contents of the hash table:\n");
    for (int i = 0; i < M; i++) {
        printf("%d: %d\n", i, hashTable[i]);
    }

	return 0;
}