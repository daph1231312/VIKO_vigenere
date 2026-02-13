#include <stdio.h>
#include <string.h>

#define MAX_TEXT 1000 //max message length 
#define ASCII_START 32
#define ASCII_END 126
#define ASCII_RANGE (ASCII_END - ASCII_START + 1)

// Alphabet for basic mode
const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // alphabet in array

// Basic mode: encrypt and decrypt only uppercase letters using the key's letter positions as shifts

void encrypt_basic(char *text, char *key) {
    int keyLen = strlen(key);
    int keyIndex = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        if (c >= 'A' && c <= 'Z') {
            int textPos = c - 'A';
            int keyPos = key[keyIndex % keyLen] - 'A'; //If the key is shorter than the message, repeat it.

            text[i] = alphabet[(textPos + keyPos) % 26]; //Converting letters to numbers
            keyIndex++;
        }
        else if (c >= 'a' && c <= 'z') {
            int textPos = c - 'a';
            int keyPos = key[keyIndex % keyLen] - 'A';

            text[i] = (char)((textPos + keyPos) % 26 + 'a');
            keyIndex++;
        }
    }
}

void decrypt_basic(char *text, char *key) {
    int keyLen = strlen(key);
    int keyIndex = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        if (c >= 'A' && c <= 'Z') {
            int textPos = c - 'A';
            int keyPos = key[keyIndex % keyLen] - 'A';

            text[i] = alphabet[(textPos - keyPos + 26) % 26];
            keyIndex++;
        }
        else if (c >= 'a' && c <= 'z') {
            int textPos = c - 'a';
            int keyPos = key[keyIndex % keyLen] - 'A';

            text[i] = (char)((textPos - keyPos + 26) % 26 + 'a');
            keyIndex++;
        }
    }
}

// advanced mode: encrypt and decrypt all ASCII characters (32-126) using the key's ASCII values as shifts

void encrypt_ascii(char *text, char *key) {
    int keyLen = strlen(key);

    for (int i = 0; text[i] != '\0'; i++) {
        int shift = key[i % keyLen];
        text[i] = (char)(((text[i] - ASCII_START + shift) % ASCII_RANGE) + ASCII_START);
    }
}

void decrypt_ascii(char *text, char *key) {
    int keyLen = strlen(key);

    for (int i = 0; text[i] != '\0'; i++) {
        int shift = key[i % keyLen];
        text[i] = (char)(((text[i] - ASCII_START - shift + ASCII_RANGE) % ASCII_RANGE) + ASCII_START);
    }
}

//main function to demonstrate both modes of encryption and decryption

int main() {
    char text[MAX_TEXT];
    char key[MAX_TEXT];
    int mode;

    printf("Enter text: ");
    fgets(text, MAX_TEXT, stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter key (uppercase letters recommended): ");
    fgets(key, MAX_TEXT, stdin);
    key[strcspn(key, "\n")] = '\0';

    printf("\nChoose mode:\n");
    printf("1 - Basic alphabetic mode\n");
    printf("2 - Advanced ASCII mode\n");
    printf("Choice: ");
    scanf("%d", &mode);

    if (mode == 1) {
        encrypt_basic(text, key);
        printf("\nEncrypted: %s\n", text);

        decrypt_basic(text, key);
        printf("Decrypted: %s\n", text);
    }
    else if (mode == 2) {
        encrypt_ascii(text, key);
        printf("\nEncrypted: %s\n", text);

        decrypt_ascii(text, key);
        printf("Decrypted: %s\n", text);
    }
    else {
        printf("Invalid mode.\n");
    }

    return 0;
}
