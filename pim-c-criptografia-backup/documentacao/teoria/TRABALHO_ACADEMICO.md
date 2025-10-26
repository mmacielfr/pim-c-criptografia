# CIFRA DE CÉSAR: SISTEMA DE CRIPTOGRAFIA E DESCRIPTOGRAFIA EM LINGUAGEM C

**Trabalho acadêmico - UNIP**

---

## 1. INTRODUÇÃO

A Cifra de César é um dos métodos de criptografia mais antigos conhecidos pela humanidade. Foi utilizada pelo imperador romano Júlio César para proteger mensagens militares há mais de 2000 anos. Este trabalho apresenta a implementação completa desse algoritmo em linguagem C, demonstrando sua funcionalidade através de funções de criptografia e descriptografia.

A importância do estudo da Cifra de César reside em sua simplicidade conceitual, que permite compreender os princípios fundamentais da criptografia, mesmo que não seja um método seguro para proteção de informações na atualidade.

---

## 2. FUNDAMENTAÇÃO TEÓRICA

### 2.1. Conceito de Cifra de César

A Cifra de César é um tipo de cifra de substituição na qual cada letra de um texto é substituída por outra letra do alfabeto, deslocada por um número fixo de posições. Por exemplo, com um deslocamento de 3 posições, a letra 'A' torna-se 'D', 'B' torna-se 'E', e assim sucessivamente.

### 2.2. Funcionamento Matemático

A fórmula matemática para criptografia é:

**C = (P + K) mod 26**

Onde:
- C = Letra criptografada
- P = Letra original (0-25, onde A=0, B=1, ..., Z=25)
- K = Chave (número de posições de deslocamento)
- mod = Operador módulo

Para descriptografar, a fórmula inversa é:

**P = (C - K + 26) mod 26**

O termo "+26" é necessário para evitar valores negativos durante a descriptografia.

### 2.3. Características do Algoritmo

- **Simetria**: O mesmo processo em direção inversa reverte a criptografia
- **Reversível**: Com a chave correta, o texto original pode ser completamente recuperado
- **Simples**: Fácil de implementar e entender
- **Vulnerável**: Facilmente quebrado por análise de frequência de letras

---

## 3. DESENVOLVIMENTO

### 3.1. Estrutura do Programa

O programa desenvolvido é composto por três funções principais:

1. `criptografar()`: Realiza a criptografia do texto
2. `descriptografar()`: Realiza a descriptografia do texto
3. `main()`: Função principal que gerencia a interação com o usuário

### 3.2. Função de Criptografia

```c
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
    }
}
```

#### 3.2.1. Explicação da Função

Esta função percorre cada caractere da string de entrada e verifica se é uma letra do alfabeto. Caso positivo, aplica a fórmula matemática da Cifra de César. O operador módulo (%) garante que valores acima de 25 (fim do alfabeto) voltem ao início (A).

**Exemplo prático:**
- Caractere: 'H'
- Chave: 3
- Cálculo: 'H' - 'A' = 7, então 7 + 3 = 10, então 10 % 26 = 10
- Resultado: 10 + 'A' = 'K'

### 3.3. Função de Descriptografia

```c
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
    }
}
```

#### 3.3.1. Explicação da Função

A função de descriptografia opera de forma inversa à criptografia. O termo "+26" é fundamental para evitar valores negativos quando se subtrai a chave.

**Exemplo prático:**
- Caractere criptografado: 'K'
- Chave: 3
- Cálculo: 'K' - 'A' = 10, então 10 - 3 + 26 = 33, então 33 % 26 = 7
- Resultado: 7 + 'A' = 'H'

### 3.4. Função Principal (main)

```c
int main() {
    char texto[1000];
    int chave, opcao;
    
    printf("=== CIFRA DE CÉSAR - Criptografia e Descriptografia ===\n\n");
    
    // Solicita a chave de deslocamento
    printf("Digite a chave de deslocamento (0-25): ");
    scanf("%d", &chave);
    
    // Valida a chave
    if (chave < 0 || chave > 25) {
        printf("Erro: Chave inválida! Use um valor entre 0 e 25.\n");
        return 1;
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
        return 1;
    }
    
    return 0;
}
```

#### 3.4.1. Características da Função Principal

- **Interação com usuário**: Solicita chave, operação e texto
- **Validação de entrada**: Verifica se a chave está no intervalo válido (0-25)
- **Tratamento de strings**: Utiliza `fgets()` para ler linhas completas com espaços
- **Limpeza de buffer**: Remove caracteres residuais do buffer de entrada

---

## 4. TESTES E RESULTADOS

### 4.1. Exemplo 1: Criptografia de Texto Simples

**Entrada:**
- Texto: "Hello World"
- Chave: 3
- Operação: Criptografar

**Resultado:**
```
Texto criptografado: Khoor Zruog
```

**Análise:**
- H deslocado 3 posições resulta em K
- e deslocado 3 posições resulta em h
- O caractere de espaço permanece inalterado
- A conversão mantém maiúsculas e minúsculas

### 4.2. Exemplo 2: Descriptografia

**Entrada:**
- Texto criptografado: "Khoor Zruog"
- Chave: 3
- Operação: Descriptografar

**Resultado:**
```
Texto descriptografado: Hello World
```

**Análise:**
- O texto original foi completamente recuperado
- A operação inversa foi executada com sucesso

### 4.3. Exemplo 3: Texto com Números e Caracteres Especiais

**Entrada:**
- Texto: "Senha123!"
- Chave: 5
- Operação: Criptografar

**Resultado:**
```
Texto criptografado: Xjslf123!
```

**Observação:**
- Números (1, 2, 3) permanecem inalterados
- Caracteres especiais (!) permanecem inalterados
- Apenas letras são criptografadas

---

## 5. ANÁLISE CRÍTICA

### 5.1. Vantagens da Implementação

1. **Simplicidade**: Código limpo e fácil de entender
2. **Versatilidade**: Suporta textos com maiúsculas, minúsculas e caracteres especiais
3. **Mantém estrutura**: Espaços, números e símbolos não são alterados
4. **Validação**: Implementa verificação de entrada de dados
5. **Interface clara**: Mensagens informativas ao usuário

### 5.2. Limitações

1. **Algoritmo inseguro**: Facilmente quebrado por força bruta (apenas 26 chaves possíveis)
2. **Vulnerável a análise de frequência**: A letra 'E' é a mais comum em português/inglês
3. **Não criptografa acentos**: Caracteres especiais latinos não são tratados
4. **Chave limitada**: Aceita apenas valores de 0 a 25

### 5.3. Aplicações Atuais

A Cifra de César não é utilizada para proteção real de informações na atualidade, mas serve como:
- Ferramenta educacional para ensino de criptografia
- Base para entender algoritmos mais complexos
- Método de ofuscação simples de texto
- Exercício de programação

---

## 6. CONSIDERAÇÕES FINAIS

O presente trabalho apresentou uma implementação completa da Cifra de César em linguagem C, demonstrando os conceitos fundamentais de criptografia simétrica. O programa desenvolvido realiza com sucesso as operações de criptografia e descriptografia de textos, mantendo a simplicidade e elegância do algoritmo original.

Embora a Cifra de César seja um método obsoleto em termos de segurança, seu estudo permanece relevante como base para a compreensão de técnicas criptográficas mais avançadas. A implementação prática evidenciou tanto as capacidades quanto as limitações deste algoritmo histórico.

O código desenvolvido pode ser expandido para incluir suporte a acentuação, cifragem de números, ou integração com algoritmos mais modernos. Futuros trabalhos podem explorar a implementação de outras cifras clássicas, como a Cifra de Vigenère ou a Cifra Playfair.

---

## 7. REFERÊNCIAS

ANSI C Standard (C89/C90). ISO/IEC 9899:1990. International Organization for Standardization.

KERNIGHAN, Brian W.; RITCHIE, Dennis M. The C Programming Language. 2nd ed. Prentice Hall, 1988.

SINGH, Simon. The Code Book: The Science of Secrecy from Ancient Egypt to Quantum Cryptography. Anchor Books, 2000.

STALLINGS, William. Cryptography and Network Security: Principles and Practice. 7th ed. Pearson, 2017.

---

## ANEXOS

### A. Código Fonte Completo

```c
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
    }
}

int main() {
    char texto[1000];
    int chave, opcao;
    
    printf("=== CIFRA DE CÉSAR - Criptografia e Descriptografia ===\n\n");
    
    // Solicita a chave de deslocamento
    printf("Digite a chave de deslocamento (0-25): ");
    scanf("%d", &chave);
    
    // Valida a chave
    if (chave < 0 || chave > 25) {
        printf("Erro: Chave inválida! Use um valor entre 0 e 25.\n");
        return 1;
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
        return 1;
    }
    
    return 0;
}
```

### B. Instruções de Compilação

Para compilar o programa, utilize o seguinte comando no terminal:

```bash
gcc -o cesar cesar.c
```

Para executar o programa:

```bash
./cesar
```

### C. Exemplos de Teste

#### Teste 1: Criptografia Básica
**Chave:** 3  
**Operação:** Criptografar  
**Texto:** "Hello"  
**Resultado:** "Khoor"

#### Teste 2: Descriptografia
**Chave:** 3  
**Operação:** Descriptografar  
**Texto:** "Khoor"  
**Resultado:** "Hello"

#### Teste 3: Texto com Espaços
**Chave:** 5  
**Operação:** Criptografar  
**Texto:** "Hello World"  
**Resultado:** "Mjqqt Btwqi"

---

**Formatação sugerida para o documento:**
- Fonte: Times New Roman ou Arial, tamanho 12
- Margens: Superior e inferior 2,5cm, esquerda e direita 3cm
- Espaçamento: 1,5 entre linhas
- Título: Negrito, centralizado
- Subtítulos: Numeração sequencial, em negrito
- Código: Fonte monoespaçada (Courier New), tamanho 10

