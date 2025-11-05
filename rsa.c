#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Estrutura para armazenar as chaves
typedef struct {
    long long n;  // Módulo (p * q)
    long long e;  // Expoente público
    long long d;  // Expoente privado
} RSAKeys;

// Função para calcular o MDC (Máximo Divisor Comum)
long long mdc(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Algoritmo de Euclides Estendido para encontrar o inverso modular
long long inverso_modular(long long e, long long phi) {
    long long t = 0, novo_t = 1;
    long long r = phi, novo_r = e;
    
    while (novo_r != 0) {
        long long quociente = r / novo_r;
        
        long long temp_t = t;
        t = novo_t;
        novo_t = temp_t - quociente * novo_t;
        
        long long temp_r = r;
        r = novo_r;
        novo_r = temp_r - quociente * novo_r;
    }
    
    if (t < 0) {
        t += phi;
    }
    
    return t;
}

// Exponenciação modular eficiente (base^exp mod mod)
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

// Teste simples de primalidade
int eh_primo(long long n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

// Função para gerar chaves RSA
RSAKeys gerar_chaves(long long p, long long q) {
    RSAKeys chaves;
    
    // Verifica se p e q são primos
    if (!eh_primo(p) || !eh_primo(q)) {
        printf("Erro: p e q devem ser números primos!\n");
        chaves.n = chaves.e = chaves.d = 0;
        return chaves;
    }
    
    // Calcula n = p * q
    chaves.n = p * q;
    
    // Calcula phi(n) = (p-1) * (q-1)
    long long phi = (p - 1) * (q - 1);
    
    // Escolhe e (geralmente 65537 ou 3, mas aqui usaremos 65537 se possível)
    chaves.e = 65537;
    if (chaves.e >= phi || mdc(chaves.e, phi) != 1) {
        chaves.e = 3;
        while (mdc(chaves.e, phi) != 1) {
            chaves.e += 2;
        }
    }
    
    // Calcula d (inverso modular de e mod phi)
    chaves.d = inverso_modular(chaves.e, phi);
    
    return chaves;
}

// Função para CRIPTOGRAFAR uma mensagem
void criptografar(const char *mensagem, long long *cifrada, RSAKeys chaves) {
    int tam = strlen(mensagem);
    
    printf("\n--- CRIPTOGRAFANDO ---\n");
    for (int i = 0; i < tam; i++) {
        // Converte cada caractere para seu valor ASCII
        long long m = (long long)mensagem[i];
        
        // Aplica a fórmula: c = m^e mod n
        cifrada[i] = exp_modular(m, chaves.e, chaves.n);
        
        printf("'%c' (ASCII %lld) -> %lld\n", mensagem[i], m, cifrada[i]);
    }
}

// Função para DESCRIPTOGRAFAR uma mensagem
void descriptografar(const long long *cifrada, char *mensagem, int tam, RSAKeys chaves) {
    printf("\n--- DESCRIPTOGRAFANDO ---\n");
    for (int i = 0; i < tam; i++) {
        // Aplica a fórmula: m = c^d mod n
        long long m = exp_modular(cifrada[i], chaves.d, chaves.n);
        
        // Converte de volta para caractere
        mensagem[i] = (char)m;
        
        printf("%lld -> '%c' (ASCII %lld)\n", cifrada[i], mensagem[i], m);
    }
    mensagem[tam] = '\0';
}

// Função principal de demonstração
int main() {
    // Escolha números primos pequenos para demonstração
    // IMPORTANTE: Em aplicações reais, use primos MUITO maiores (1024-4096 bits)
    long long p = 61;
    long long q = 53;
    
    printf("=== DEMONSTRAÇÃO DE CRIPTOGRAFIA RSA ===\n\n");
    printf("Números primos escolhidos:\n");
    printf("p = %lld\n", p);
    printf("q = %lld\n\n", q);
    
    // Gera as chaves
    RSAKeys chaves = gerar_chaves(p, q);
    
    printf("Chaves geradas:\n");
    printf("n (módulo) = %lld\n", chaves.n);
    printf("e (chave pública) = %lld\n", chaves.e);
    printf("d (chave privada) = %lld\n", chaves.d);
    
    // Mensagem a ser criptografada
    const char *mensagem_original = "OLA";
    printf("\n=== MENSAGEM ORIGINAL ===\n");
    printf("\"%s\"\n", mensagem_original);
    
    int tam = strlen(mensagem_original);
    
    // Array para armazenar a mensagem cifrada
    long long *mensagem_cifrada = (long long *)malloc(tam * sizeof(long long));
    
    // Criptografa
    criptografar(mensagem_original, mensagem_cifrada, chaves);
    
    printf("\n=== MENSAGEM CIFRADA ===\n");
    printf("[");
    for (int i = 0; i < tam; i++) {
        printf("%lld", mensagem_cifrada[i]);
        if (i < tam - 1) printf(", ");
    }
    printf("]\n");
    
    // Descriptografa
    char *mensagem_descriptografada = (char *)malloc((tam + 1) * sizeof(char));
    descriptografar(mensagem_cifrada, mensagem_descriptografada, tam, chaves);
    
    printf("\n=== MENSAGEM DESCRIPTOGRAFADA ===\n");
    printf("\"%s\"\n", mensagem_descriptografada);
    
    // Libera memória
    free(mensagem_cifrada);
    free(mensagem_descriptografada);
    
    return 0;
}
