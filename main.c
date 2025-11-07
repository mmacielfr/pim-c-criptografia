#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "./codigo_inteiro.h"

long long cifrada[100];
char cifra[200], descriptografada[200];

char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char chave[] = "QWERTYUIOPASDFGHJKLZXCVBNM";

void criptografarCesar(char texto[], int chave) {
    int i;
    
    for (i = 0; texto[i] != '\0'; i++) {
        if (texto[i] >= 'A' && texto[i] <= 'Z') {
            texto[i] = ((texto[i] - 'A' + chave) % 26) + 'A';
        }
        else if (texto[i] >= 'a' && texto[i] <= 'z') {
            texto[i] = ((texto[i] - 'a' + chave) % 26) + 'a';
        }
    }
    printf("\nTexto criptografado: %s\n", texto);
}

void descriptografarCesar(char texto[], int chave) {
    int i;
    
    for (i = 0; texto[i] != '\0'; i++) {
        if (texto[i] >= 'A' && texto[i] <= 'Z') {
            texto[i] = ((texto[i] - 'A' - chave + 26) % 26) + 'A';
        }
        else if (texto[i] >= 'a' && texto[i] <= 'z') {
            texto[i] = ((texto[i] - 'a' - chave + 26) % 26) + 'a';
        }
    }
    printf("\nTexto descriptografado: %s\n", texto);
}

void criptografarTransposicao(const char *mensagem, char *cifrada) {
    int tam = strlen(mensagem);
    int linhas = (tam + 4 - 1) / 4;
    char matriz[100][4];
    int idx = 0;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < 4; j++) {
            matriz[i][j] = (idx < tam) ? mensagem[idx++] : 'X';
        }
    }
    int pos = 0;
    for (int ordem = 1; ordem <= 4; ordem++) {
        for (int j = 0; j < 4; j++) {
            if ("4312"[j] - '0' == ordem) {
                for (int i = 0; i < linhas; i++) {
                    cifrada[pos++] = matriz[i][j];
                }
            }
        }
    }
    cifrada[pos] = '\0';
    printf("\nTexto criptografado: %s\n", cifrada);
}

void descriptografarTransposicao(const char *cifrada, char *mensagem) {
    int tam = strlen(cifrada);
    int linhas = tam / 4;
    char matriz[100][4];
    
    int pos = 0;
    for (int ordem = 1; ordem <= 4; ordem++) {
        for (int j = 0; j < 4; j++) {
            if ("4312"[j] - '0' == ordem) {
                for (int i = 0; i < linhas; i++) {
                    matriz[i][j] = cifrada[pos++];
                }
            }
        }
    }
    
    int idx = 0;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < 4; j++) {
            mensagem[idx++] = matriz[i][j];
        }
    }
    mensagem[idx] = '\0';
    printf("\nTexto descriptografado: %s\n", cifrada);
}

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
    printf("\nTexto criptografado: %s\n", texto);
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
    printf("\nTexto descriptografado: %s\n", texto);
}

long long exp_modular(long long base, long long exp, long long mod) {
    long long resultado = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            resultado = (resultado * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return resultado;
}

void criptografarRsa(const char *mensagem, long long *cifrada) {
    int tam = strlen(mensagem);
    for (int i = 0; i < tam; i++) {
        long long m = (long long)mensagem[i];
        cifrada[i] = exp_modular(m, 17, 3233);
    }
    printf("\nMensagem cifrada: [");
    for (int i = 0; i < tam; i++) {
        printf("%lld%s", cifrada[i], i < tam-1 ? ", " : "");
    }
    printf("]\n");
}

int main()
{
    printf("Bem vindo ao programa!\n");

    int option = 0;
    int encrypt = 0;
    int decrypt = 0;

    while(option != 3) {
        printf("\nDigite uma opção de 1 a 3\n");
        printf("1 - Criptografar\n");
        printf("2 - Descriptografar\n");
        printf("3 - Sair do programa\n");
        scanf("%d", &option);

        if(option == 1){
            printf("\nEscolha um método de criptografia:\n");
            printf("1 - Cifra de Cesar\n");
            printf("2 - Transposição\n");
            printf("3 - Substituição\n");
            printf("4 - RSA\n");
            scanf("%d", &encrypt);

            while (getchar() != '\n');
            printf("Digite a mensagem: ");
            char text[100];
            fgets(text, 100, stdin);
            text[strcspn(text, "\n")] = '\0';

            if(encrypt == 1) {
                criptografarCesar(text, 3);
            }
            if(encrypt == 2) {
                criptografarTransposicao(text, cifra);
            }
            if(encrypt == 3) {
                criptografarSubstituicao(text, alfabeto, chave);
            }
            if(encrypt == 4) {
                criptografarRsa(text, cifrada);
            }
        }
        if(option == 2){
            printf("\nEscolha um método de descriptografia:\n");
            printf("1 - Cifra de Cesar\n");
            printf("2 - Transposição\n");
            printf("3 - Substituição\n");
            scanf("%d", &decrypt);

            while (getchar() != '\n');
            printf("Digite a mensagem criptografada: ");
            char text[100];
            fgets(text, 100, stdin);
            text[strcspn(text, "\n")] = '\0';

            if(decrypt == 1) {
                descriptografarCesar(text, 3);
            }
            if(decrypt == 2) {
                descriptografarTransposicao(text, descriptografada);
            }
            if(decrypt == 3) {
                descriptografarSubstituicao(text, alfabeto, chave);
            }
        }
    }

    return 0;
}