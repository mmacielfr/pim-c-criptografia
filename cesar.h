#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para criptografar texto usando Cifra de César
void criptografar(char texto[], int chave) {
    int i;
    
    for (i = 0; texto[i] != '\0'; i++) {
        // Verifica se é uma letra maiúscula
        if (texto[i] >= 'A' && texto[i] <= 'Z') {
            texto[i] = ((texto[i] - 'A' + chave) % 26) + 'A';
        }
        // Verifica se é uma letra minúscula
        else if (texto[i] >= 'a' && texto[i] <= 'z') {
            texto[i] = ((texto[i] - 'a' + chave) % 26) + 'a';
        }
        // Outros caracteres permanecem inalterados (espaços, números, etc)
    }
}

// Função para descriptografar texto usando Cifra de César
void descriptografar(char texto[], int chave) {
    int i;
    
    for (i = 0; texto[i] != '\0'; i++) {
        // Verifica se é uma letra maiúscula
        if (texto[i] >= 'A' && texto[i] <= 'Z') {
            texto[i] = ((texto[i] - 'A' - chave + 26) % 26) + 'A';
        }
        // Verifica se é uma letra minúscula
        else if (texto[i] >= 'a' && texto[i] <= 'z') {
            texto[i] = ((texto[i] - 'a' - chave + 26) % 26) + 'a';
        }
        // Outros caracteres permanecem inalterados (espaços, números, etc)
    }
}

void principal() {
    char texto[1000];
    int chave, opcao;
    
    printf("=== CIFRA DE CÉSAR - Criptografia e Descriptografia ===\n\n");
    
    // Solicita a chave de deslocamento
    printf("Digite a chave de deslocamento (0-25): ");
    scanf("%d", &chave);
    
    // Valida a chave
    if (chave < 0 || chave > 25) {
        printf("Erro: Chave inválida! Use um valor entre 0 e 25.\n");
        return;
    }
    
    // Solicita a operação
    printf("\nEscolha a operação:\n");
    printf("1 - Criptografar\n");
    printf("2 - Descriptografar\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    
    // Limpa o buffer de entrada
    while (getchar() != '\n');
    
    // Solicita o texto
    printf("\nDigite o texto: ");
    fgets(texto, sizeof(texto), stdin);
    
    // Remove o caractere de nova linha no final
    texto[strcspn(texto, "\n")] = 0;
    
    // Executa a operação solicitada
    if (opcao == 1) {
        criptografar(texto, chave);
        printf("\nTexto criptografado: %s\n", texto);
    }
    else if (opcao == 2) {
        descriptografar(texto, chave);
        printf("\nTexto descriptografado: %s\n", texto);
    }
    else {
        printf("Erro: Opção inválida!\n");
        return;
    }
    
}
