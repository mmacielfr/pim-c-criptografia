#include <stdio.h>
#include <string.h>

int main() {
    char texto[100], chave[20];
    int i, j, opcao, tamTexto, tamChave;

    printf("=== Cifra de Transposicao Colunar ===\n");
    printf("1 - Criptografar\n");
    printf("2 - Descriptografar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    printf("Digite a chave: ");
    scanf("%s", chave);
    tamChave = strlen(chave);

    if (opcao == 1) {
        // --- CRIPTOGRAFAR ---
        printf("Digite o texto (sem espacos): ");
        scanf("%s", texto);

        tamTexto = strlen(texto);
        char matriz[20][20];

        // Preenche a matriz linha por linha
        for (i = 0; i < tamTexto; i++) {
            matriz[i / tamChave][i % tamChave] = texto[i];
        }

        // Completa com 'X' se necessário
        while (tamTexto % tamChave != 0) {
            matriz[tamTexto / tamChave][tamTexto % tamChave] = 'X';
            tamTexto++;
        }

        printf("\nMatriz formada:\n");
        for (i = 0; i < tamTexto / tamChave; i++) {
            for (j = 0; j < tamChave; j++) {
                printf("%c ", matriz[i][j]);
            }
            printf("\n");
        }

        printf("\nTexto criptografado: ");
        for (j = 0; j < tamChave; j++) {
            for (i = 0; i < tamTexto / tamChave; i++) {
                printf("%c", matriz[i][j]);
            }
        }
        printf("\n");
    }

    else if (opcao == 2) {
        // --- DESCRIPTOGRAFAR ---
        printf("Digite o texto criptografado: ");
        scanf("%s", texto);

        tamTexto = strlen(texto);
        char matriz[20][20];
        int linhas = tamTexto / tamChave;
        int pos = 0;

        // Preenche a matriz coluna por coluna
        for (j = 0; j < tamChave; j++) {
            for (i = 0; i < linhas; i++) {
                matriz[i][j] = texto[pos];
                pos++;
            }
        }

        printf("\nMatriz reconstruida:\n");
        for (i = 0; i < linhas; i++) {
            for (j = 0; j < tamChave; j++) {
                printf("%c ", matriz[i][j]);
            }
            printf("\n");
        }

        printf("\nTexto descriptografado: ");
        for (i = 0; i < linhas; i++) {
            for (j = 0; j < tamChave; j++) {
                if (matriz[i][j] != 'X')  // remove o padding
                    printf("%c", matriz[i][j]);
            }
        }
        printf("\n");
    }

    else {
        printf("Opcao invalida!\n");
    }

    return 0;
}
