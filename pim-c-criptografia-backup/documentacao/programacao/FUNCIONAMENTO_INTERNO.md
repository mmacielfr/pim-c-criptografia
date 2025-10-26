# 🔬 Funcionamento Interno - Cifra de César em C

## 📚 Índice
1. [Visão Geral da Arquitetura](#visão-geral)
2. [Análise Detalhada das Funções](#análise-das-funções)
3. [Explicação Matemática](#explicação-matemática)
4. [Fluxo de Execução](#fluxo-de-execução)
5. [Manipulação de Strings](#manipulação-de-strings)

---

## 🎯 Visão Geral da Arquitetura

```c
┌─────────────────────────────────────────────┐
│           PROGRAMA PRINCIPAL                │
│                                             │
│  1. Ler entrada do usuário                 │
│  2. Validar dados                          │
│  3. Chamar função apropriada                │
│  4. Exibir resultado                       │
└──────────────┬──────────────────────────────┘
               │
    ┌──────────┴──────────┐
    │                     │
┌───┴──────┐      ┌──────┴────┐
│criptogra-│      │descripto- │
│    far   │      │   grafar  │
└──────────┘      └───────────┘
```

---

## 🔍 Análise Detalhada das Funções

### 1️⃣ Função: `criptografar()`

#### **Assinatura:**
```c
void criptografar(char texto[], int chave)
```

#### **Parâmetros:**
- `texto[]`: Array de caracteres que será modificado (passagem por referência)
- `chave`: Número inteiro representando quantas posições avançar no alfabeto

#### **Retorno:**
- `void`: Não retorna valor (modifica o array diretamente)

#### **Código:**
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

#### **Funcionamento Passo a Passo:**

**Exemplo:** Criptografar `'H'` com chave `3`

```
1. Loop detecta caractere 'H'
2. Condição: 'H' >= 'A' && 'H' <= 'Z' → TRUE
3. Executa fórmula:
   a) 'H' - 'A' = 7        (posição no alfabeto: 0-25)
   b) 7 + 3 = 10           (desloca 3 posições)
   c) 10 % 26 = 10         (garante que fica entre 0-25)
   d) 10 + 'A' = 75        (volta para letra ASCII)
4. 'H' é substituído por 'K'
```

#### **Tabela de Valores ASCII:**
```c
'A' = 65
'B' = 66
...
'H' = 72  (posição 7 no alfabeto)
...
'K' = 75  (posição 10 no alfabeto)
...
'Z' = 90
```

#### **Diagrama da Transformação:**
```
Entrada: 'H' (ASCII 72)
         ↓
Calcular posição: 72 - 65 = 7
         ↓
Somar chave: 7 + 3 = 10
         ↓
Módulo 26: 10 % 26 = 10
         ↓
Voltar para ASCII: 10 + 65 = 75
         ↓
Saída: 'K' (ASCII 75)
```

---

### 2️⃣ Função: `descriptografar()`

#### **Assinatura:**
```c
void descriptografar(char texto[], int chave)
```

#### **Diferença Principal:**
Desloca para **TRÁS** no alfabeto (subtrai a chave)

#### **Código:**
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

#### **Por que `+ 26`?**

**Cenário problemático sem `+ 26`:**

```
Descriptografar 'B' com chave 5:

1. 'B' - 'A' = 1
2. 1 - 5 = -4  ❌ NEGATIVO!
3. -4 % 26 = -4 (comportamento inesperado)
```

**Com `+ 26` (correto):**

```
1. 'B' - 'A' = 1
2. 1 - 5 = -4
3. -4 + 26 = 22  ✅ Converte para positivo
4. 22 % 26 = 22
5. 22 + 'A' = 87 ('W')
```

#### **Lógica Matemática:**
```
+ 26 é equivalente a "dar uma volta completa no alfabeto"

Posição final = (posição_inicial - chave + 26) % 26
                   ↑           ↑      ↑
                   │           │      └─ Garante positivo
                   │           └─ Desloca para trás
                   └─ Posição atual da letra
```

---

### 3️⃣ Função: `main()`

#### **Estrutura Geral:**

```c
int main() {
    // 1. DECLARAÇÃO DE VARIÁVEIS
    char texto[1000];  // Buffer para o texto
    int chave;         // Chave de criptografia
    int opcao;         // Operação selecionada
    
    // 2. ENTRADA DE DADOS
    // 3. VALIDAÇÃO
    // 4. PROCESSAMENTO
    // 5. SAÍDA
}
```

#### **1. Declaração de Variáveis:**

```c
char texto[1000];  // Array de 1000 caracteres
```

**Como funciona:**
- Aloca espaço para 999 caracteres + 1 terminador `\0`
- Cada `char` ocupa 1 byte (8 bits)
- Total: 1000 bytes de memória

```
Memória:
┌─────┬─────┬─────┬─────┬─────┬─────┬────┬────┬────┬────┐
│ 'H' │ 'e' │ 'l' │ 'l' │ 'o' │'\0' │ ?  │ ?  │ ?  │ ...│
└─────┴─────┴─────┴─────┴─────┴─────┴────┴────┴────┴────┘
  [0]   [1]   [2]   [3]   [4]   [5]   [6]  [7]  [8]  ...
```

#### **2. Leitura da Chave:**

```c
printf("Digite a chave de deslocamento (0-25): ");
scanf("%d", &chave);
```

**`scanf()`:**
- `"%d"`: Lê um inteiro (decimal)
- `&chave`: Passa o endereço da variável (ponteiro)
- Lê até encontrar espaço, Enter ou EOF

#### **3. Validação da Chave:**

```c
if (chave < 0 || chave > 25) {
    printf("Erro: Chave inválida! Use um valor entre 0 e 25.\n");
    return 1;  // Encerra o programa com código de erro
}
```

**Por que validar?**
- Evita overflow no cálculo
- Mantém resultado dentro do alfabeto
- Fornece feedback ao usuário

#### **4. Limpeza do Buffer:**

```c
while (getchar() != '\n');
```

**Problema que resolve:**

```
1. scanf("%d", &chave) lê apenas o número
2. Enter fica no buffer: '\n'
3. fgets() leria apenas '\n' ← PROBLEMA!
4. while (getchar() != '\n') remove tudo até o Enter
```

**Fluxo:**
```
Buffer antes:  [5, '\n', 'H', 'e', 'l', ...]
              ↑
scanf lê até aqui (remove 5)

Buffer depois de scanf: ['\n', 'H', 'e', 'l', ...]
                        ↑
getchar() remove '\n'

Buffer limpo: ['H', 'e', 'l', ...]
```

#### **5. Leitura do Texto:**

```c
printf("\nDigite o texto: ");
fgets(texto, sizeof(texto), stdin);
```

**`fgets()` vs `scanf()`:**

| Função | Comportamento | Exemplo |
|--------|---------------|---------|
| `scanf("%s", texto)` | Lê até espaço | "Hello World" → "Hello" |
| `fgets(texto, size, stdin)` | Lê linha completa | "Hello World" → "Hello World\n" |

**Parâmetros:**
- `texto`: Buffer de destino
- `sizeof(texto)`: Tamanho máximo (1000)
- `stdin`: Stream de entrada padrão (teclado)

#### **6. Remoção do `\n` Final:**

```c
texto[strcspn(texto, "\n")] = 0;
```

**`strcspn()`:**
```c
strcspn(texto, "\n")
```
- Retorna posição do `\n` na string
- Se não encontrar, retorna o tamanho da string

**Exemplo:**
```c
char texto[] = "Hello\n\0";
//            0123456
//            hello\n

strcspn(texto, "\n") retorna 5

texto[5] = 0;  // Substitui '\n' por '\0'

Resultado: "Hello\0\0"
```

#### **7. Execução da Operação:**

```c
if (opcao == 1) {
    criptografar(texto, chave);
    printf("\nTexto criptografado: %s\n", texto);
}
else if (opcao == 2) {
    descriptografar(texto, chave);
    printf("\nTexto descriptografado: %s\n", texto);
}
```

**Por que o array é modificado?**
- Arrays são passados por **referência** em C
- Função recebe o endereço de memória original
- Modificações afetam a variável original

---

## 🧮 Explicação Matemática

### **Operador Módulo (%)**

**Definição:** `a % b` retorna o resto da divisão de `a` por `b`

**Exemplos:**
```c
10 % 26 = 10    // 10 ÷ 26 = 0 com resto 10
26 % 26 = 0     // 26 ÷ 26 = 1 com resto 0
30 % 26 = 4     // 30 ÷ 26 = 1 com resto 4
52 % 26 = 0     // 52 ÷ 26 = 2 com resto 0
```

**Por que usar módulo 26?**
```
Alfabeto: 0-25 (A-Z)

Se chave = 30:
30 % 26 = 4

'Z' + 30 posições = 'A' + 4 posições = 'D'
```

### **Fórmula de Criptografia:**

```
C = (P + K) mod 26

Onde:
C = Letra criptografada
P = Letra original (0-25)
K = Chave
mod = Operador módulo
```

### **Fórmula de Descriptografia:**

```
P = (C - K + 26) mod 26

Onde:
P = Letra original
C = Letra criptografada
K = Chave
+ 26 = Garante positivo
mod = Operador módulo
```

### **Tabela de Deslocamento:**

```
Chave 0: A↔A  B↔B  C↔C  ... Z↔Z  (sem alteração)
Chave 1: A↔B  B↔C  C↔D  ... Z↔A  (desloca 1)
Chave 3: A↔D  B↔E  C↔F  ... Z↔C  (desloca 3)
Chave 13: A↔N B↔O  C↔P  ... Z↔M  (ROT13)
Chave 25: A↔Z B↔A  C↔B  ... Z↔Y  (desloca 25)
```

---

## 🔄 Fluxo de Execução Completo

### **Cenário: Criptografar "Hello" com chave 3**

```
1. main() inicia
   ↓
2. Declara variáveis
   texto[1000], chave, opcao
   ↓
3. printf("Digite a chave...")
   ↓
4. scanf("%d", &chave)
   Usuário digita: 3
   chave = 3
   ↓
5. printf("Escolha operação...")
   ↓
6. scanf("%d", &opcao)
   Usuário digita: 1
   opcao = 1
   ↓
7. while(getchar() != '\n')
   Limpa buffer
   ↓
8. fgets(texto, 1000, stdin)
   Usuário digita: "Hello"
   texto = "Hello\0"
   ↓
9. strcspn(texto, "\n")
   Remove '\n' (não havia)
   ↓
10. if(opcao == 1) → TRUE
    ↓
11. Chama criptografar(texto, 3)
    ↓
    ┌─────────────────────────┐
    │ Função criptografar()   │
    ├─────────────────────────┤
    │ for(i=0; i<5; i++)      │
    │                         │
    │ Iteração 0: 'H'         │
    │   if('H' >= 'A' && ...) │
    │   'H' = (7 + 3) % 26   │
    │   'H' = 10              │
    │   'H' = 10 + 'A'        │
    │   'H' = 'K' ← MODIFICADO│
    │                         │
    │ Iteração 1: 'e'         │
    │   if('e' >= 'a' && ...) │
    │   'e' = (4 + 3) % 26   │
    │   'e' = 'h' ← MODIFICADO│
    │                         │
    │ Iterações 2-4...        │
    └─────────────────────────┘
    ↓
12. texto agora = "Khoor\0"
    ↓
13. printf("Texto criptografado: %s")
    Mostra: "Khoor"
    ↓
14. return 0 (sucesso)
    ↓
15. Programa encerra
```

---

## 🧵 Manipulação de Strings em C

### **Representação Interna:**

```c
char texto[] = "Hello";
```

**Memória:**
```
┌─────┬─────┬─────┬─────┬─────┬─────┐
│ 'H' │ 'e' │ 'l' │ 'l' │ 'o' │'\0' │
│ 72  │ 101 │ 108 │ 108 │ 111 │  0  │
└─────┴─────┴─────┴─────┴─────┴─────┘
  [0]   [1]   [2]   [3]   [4]   [5]
```

### **Iteração sobre String:**

```c
for (i = 0; texto[i] != '\0'; i++) {
    // Processar texto[i]
}
```

**Como funciona:**
```
i=0: texto[0] = 'H'  != '\0' → continua
i=1: texto[1] = 'e'  != '\0' → continua
i=2: texto[2] = 'l'  != '\0' → continua
i=3: texto[3] = 'l'  != '\0' → continua
i=4: texto[4] = 'o'  != '\0' → continua
i=5: texto[5] = '\0' == '\0' → PARA
```

### **Modificação em Lugar:**

```c
texto[i] = novo_valor;
```

**Atenção:**
- Arrays são modificados diretamente
- Não há cópia da string
- Mudanças são permanentes

---

## 📊 Comparação: Criptografar vs Descriptografar

| Aspecto | Criptografar | Descriptografar |
|---------|-------------|-----------------|
| **Operação** | `+ chave` | `- chave` |
| **Fórmula** | `(P + K) mod 26` | `(C - K + 26) mod 26` |
| **Direção** | Frente | Trás |
| **+26** | Não precisa | Precisa |

### **Exemplo Visual:**

```
Criptografar "A" com chave 3:
A → B → C → D
0 → 1 → 2 → 3

Descriptografar "D" com chave 3:
D ← C ← B ← A
3 ← 2 ← 1 ← 0
```

---

## 🎓 Conceitos Avançados

### **Passagem por Referência vs Valor:**

```c
// Passagem por referência (arrays)
void criptografar(char texto[], int chave) {
    texto[0] = 'X';  // Modifica original
}

// Passagem por valor (int)
void exemplo(int chave) {
    chave = 10;  // NÃO modifica original
}
```

### **Por que char texto[] é passado como referência?**

Em C, arrays decaem para ponteiros:
```c
void func(char texto[])  // Equivale a
void func(char *texto)   // Ponteiro
```

### **Segurança e Validação:**

```c
// 1. Validação de entrada
if (chave < 0 || chave > 25) { ... }

// 2. Verificação de limites
fgets(texto, sizeof(texto), stdin);

// 3. Tratamento de caracteres especiais
if (texto[i] >= 'A' && texto[i] <= 'Z') { ... }
```

---

## 🚀 Otimizações Possíveis

### **1. Usar unsigned char:**
```c
unsigned char texto[1000];  // 0-255, mais seguro
```

### **2. Função unificada:**
```c
void cifra(char texto[], int chave, int modo) {
    int deslocamento = (modo == 1) ? chave : -chave + 26;
    // ...
}
```

### **3. Suporte a outros caracteres:**
```c
if (texto[i] >= 'a' && texto[i] <= 'z') { ... }
else if (texto[i] >= 'A' && texto[i] <= 'Z') { ... }
else if (texto[i] >= '0' && texto[i] <= '9') { ... }
```

---

Este documento cobre o funcionamento interno completo do código. Cada função foi explicada em detalhes, incluindo exemplos práticos e visualizações.
