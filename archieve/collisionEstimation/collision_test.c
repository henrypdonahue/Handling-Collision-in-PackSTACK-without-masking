#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HASH_SPACE 64  // 2^16 possible hash values

// Function to check for single hash collision
unsigned int singleHashCollision() {
    char hashTable[HASH_SPACE] = {0};
    unsigned int hash, attempts = 0;

    while (1) {
        hash = rand() % HASH_SPACE;
        if (hashTable[hash]) {
            return attempts;
        }
        hashTable[hash] = 1;
        attempts++;
    }
}

// Function to generate a combined hash key from two 16-bit hashes
unsigned int combineHashes(unsigned int hash1, unsigned int hash2) {
    return (hash1 + hash2 * HASH_SPACE) % HASH_SPACE;
}

// Function to check for double hash collision
unsigned int doubleHashCollision() {
    char hashTable[HASH_SPACE] = {0};
    unsigned int hash1, hash2, combinedHash, attempts = 0;

    while (1) {
        hash1 = rand() % HASH_SPACE;
        hash2 = rand() % HASH_SPACE;
        combinedHash = combineHashes(hash1, hash2);

        if (hashTable[combinedHash]) {
            return attempts;
        }
        hashTable[combinedHash] = 1;
        attempts++;
    }
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    unsigned int singleCollisionAttempts = singleHashCollision();
    unsigned int doubleCollisionAttempts = doubleHashCollision();

    printf("It took %u attempts for a single hash collision.\n", singleCollisionAttempts);
    printf("It took %u attempts for two specific hashes to both collide.\n", doubleCollisionAttempts);

    return 0;
}





// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <time.h>

// #define HASH_SPACE 32  // 2^16 possible hash values

// // Function to check for single hash collision
// unsigned int singleHashCollision() {
//     char hashTable[HASH_SPACE] = {0};
//     unsigned int hash, attempts = 0;

//     while (1) {
//         hash = rand() % HASH_SPACE;
//         if (hashTable[hash]) {
//             return attempts;
//         }
//         hashTable[hash] = 1;
//         attempts++;
//     }
// }

// // Function to check for double hash collision
// unsigned int doubleHashCollision() {
//     char hashTable[HASH_SPACE][HASH_SPACE] = {0};
//     unsigned int hash1, hash2, attempts = 0;

//     while (1) {
//         hash1 = rand() % HASH_SPACE;
//         hash2 = rand() % HASH_SPACE;
//         if (hashTable[hash1][hash2]) {
//             return attempts;
//         }
//         hashTable[hash1][hash2] = 1;
//         attempts++;
//     }
// }

// int main() {
//     srand(time(NULL));  // Seed the random number generator
//     unsigned int singleCollisionAttempts = singleHashCollision();
//     unsigned int doubleCollisionAttempts = doubleHashCollision();

//     printf("It took %u attempts for a single hash collision.\n", singleCollisionAttempts);
//     printf("It took %u attempts for two specific hashes to both collide.\n", doubleCollisionAttempts);

//     return 0;
// }