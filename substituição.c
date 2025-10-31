#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 100

void criptografarSubstituicao(char texto[], char original[], char substituto[]) {
    for (int i = 0; i < strlen(texto); i++) {
        char c = toupper(texto[i]);
        int encontrado = 0;
        for (int j = 0; j < 26; j++) {
            if (c == original[j]) {
                texto[i] = substituto[j];
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            texto[i] = texto[i];
        }
    }
}

void descriptografarSubstituicao(char texto[], char original[], char substituto[]) {
    for (int i = 0; i < strlen(texto); i++) {
        char c = toupper(texto[i]);
        int encontrado = 0;
        for (int j = 0; j < 26; j++) {
            if (c == substituto[j]) {
                texto[i] = original[j];
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            texto[i] = texto[i];
        }
    }
}

int main() {
    char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char chave[] = "QWERTYUIOPASDFGHJKLZXCVBNM";

    char texto[TAM];

    printf("Digite a mensagem: ");
    fgets(texto, TAM, stdin);
    texto[strcspn(texto, "\n")] = '\0'; // remove o \n

    printf("\nMensagem original: %s", texto);

    criptografarSubstituicao(texto, alfabeto, chave);
    printf("\nMensagem criptografada: %s", texto);

    descriptografarSubstituicao(texto, alfabeto, chave);
    printf("\nMensagem descriptografada: %s\n", texto);

    return 0;
}

