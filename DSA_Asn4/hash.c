// Dina Makhdoom
// Data Structures & Algorithms Assignment #4
// Impl for a hash table function
#include "hash.h"

void hashInit(int* hashTable, int* input, int M, int R) {

    // Initialize hash table with -1 (indicating that the slots are empty)
    for (int i = 0; i < M; i++) {
        hashTable[i] = -1;
    }

    // Iterate over each element in the input array
    for (int j = 0; j < M; j++) {
        int key = input[j];
        // Calculate the first hash value
        int h1 = key % M; // Evenly distributes available slots by taking the remainder of the key / total slots
        // Calculate the second hash value
        int h2 = R - (key % R); // Calculation to ensure that the hash value can "jump" to the next one if the first is taken
        int i = 0;
        // Calculating initial position for the input
        int hashIndex = (h1 + i * h2) % M;

        // Handle collisions with double hashing
        // If the calculated slot is already occupied, the code will increase i and recalculate a new slot using 
        // the double hashing formula ((h1 + i * h2) % M)
        while (hashTable[hashIndex] != -1 && i < M) {
            i++;
            hashIndex = (h1 + i * h2) % M;
        }

        // Insert the key into the hash table
        if (i < M) {
            hashTable[hashIndex] = key;
        }
        // Otherwise, print an error to explain why it couldn't
        else {
            printf("Hash table is full or unable to resolve collision for key %d\n", key);
        }
    }
}