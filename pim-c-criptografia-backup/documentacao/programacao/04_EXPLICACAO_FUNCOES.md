# 4. EXPLICAÇÃO DAS FUNÇÕES

## 4.1. Função de Criptografia

### Código da Função

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
        // Outros caracteres permanecem inalterados
    }
}
```

### Análise Detalhada

#### Parâmetros de Entrada

- **`texto[]`**: Array de caracteres (string) que será modificado diretamente. A passagem por referência permite que alterações sejam refletidas na variável original.

- **`chave`**: Número inteiro representando quantas posições no alfabeto cada letra será deslocada. Deve estar entre 0 e 25.

#### Assinatura da Função

```c
void criptografar(char texto[], int chave)
```

- **Tipo de retorno**: `void` - não retorna valor, modifica o array diretamente
- **Parâmetros**: Array de caracteres e chave inteira

#### Estrutura do Loop

```c
for (i = 0; texto[i] != '\0'; i++)
```

O loop itera sobre cada caractere da string até encontrar o terminador nulo `\0`, que indica o fim da string em C.

**Sequência de execução:**
1. Inicialização: `i = 0`
2. Condição: `texto[i] != '\0'` (continua enquanto não encontra fim da string)
3. Incremento: `i++` (avança para próximo caractere)

### Processamento de Maiúsculas

```c
if (texto[i] >= 'A' && texto[i] <= 'Z') {
    texto[i] = ((texto[i] - 'A' + chave) % 26) + 'A';
}
```

#### Passo a Passo da Fórmula

**Exemplo:** Criptografar `'H'` com chave `3`

**Passo 1:** Conversão para posição no alfabeto
```c
'H' - 'A' = 72 - 65 = 7
```
O caractere 'H' está na posição 7 do alfabeto (A=0, B=1, ..., H=7)

**Passo 2:** Aplicar deslocamento
```c
7 + 3 = 10
```
Somar a chave ao valor da posição

**Passo 3:** Aplicar módulo
```c
10 % 26 = 10
```
Garantir que o resultado esteja entre 0 e 25

**Passo 4:** Converter de volta para letra
```c
10 + 'A' = 10 + 65 = 75 ('K')
```
Adicionar o valor ASCII de 'A' para obter o caractere final

**Resultado:** 'H' → 'K'

### Processamento de Minúsculas

```c
else if (texto[i] >= 'a' && texto[i] <= 'z') {
    texto[i] = ((texto[i] - 'a' + chave) % 26) + 'a';
}
```

A lógica é idêntica à de maiúsculas, mas usa 'a' (ASCII 97) como base em vez de 'A' (ASCII 65).

**Exemplo:** 'e' com chave 3
```
'e' - 'a' = 101 - 97 = 4
4 + 3 = 7
7 % 26 = 7
7 + 'a' = 104 ('h')
```

### Caracteres Não-Alfabéticos

Caracteres que não são letras (espaços, números, símbolos) não são processados e permanecem inalterados. Isto ocorre porque não satisfazem nenhuma das condições `if`.

### Exemplo Completo

**Entrada:** `"Hello!"` com chave 3

| i | texto[i] | Condição | Cálculo | Resultado |
|---|----------|----------|---------|-----------|
| 0 | H | >= 'A' && <= 'Z' | (7+3)%26+'A' | K |
| 1 | e | >= 'a' && <= 'z' | (4+3)%26+'a' | h |
| 2 | l | >= 'a' && <= 'z' | (11+3)%26+'a' | o |
| 3 | l | >= 'a' && <= 'z' | (11+3)%26+'a' | o |
| 4 | o | >= 'a' && <= 'z' | (14+3)%26+'a' | r |
| 5 | ! | Nenhuma | - | ! |

**Saída:** `"Khoor!"`

---

## 4.2. Função de Descriptografia

### Código da Função

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
        // Outros caracteres permanecem inalterados
    }
}
```

### Diferenças em Relação à Criptografia

#### Subtração em vez de Soma

```c
// Criptografia: soma
texto[i] = ((texto[i] - 'A' + chave) % 26) + 'A';

// Descriptografia: subtração
texto[i] = ((texto[i] - 'A' - chave + 26) % 26) + 'A';
```

A descriptografia inverte o deslocamento, subtraindo a chave em vez de somar.

#### Por que `+ 26`?

O termo `+26` é essencial para evitar valores negativos.

**Problema sem `+26`:**
```
Descriptografar 'B' com chave 5:
'B' - 'A' = 1
1 - 5 = -4  ❌ NEGATIVO!
```

**Solução com `+26`:**
```
'B' - 'A' - 5 + 26 = 1 - 5 + 26 = 22
22 % 26 = 22
22 + 'A' = 'W'  ✓ Correto!
```

O `+26` adiciona "uma volta completa" no alfabeto, convertendo valores negativos em valores positivos equivalentes.

### Passo a Passo - Descriptografar 'K' com chave 3

**Passo 1:** Posição no alfabeto
```
'K' - 'A' = 75 - 65 = 10
```

**Passo 2:** Subtrair chave
```
10 - 3 = 7
```

**Passo 3:** Normalizar (não necessário neste caso, mas incluído na fórmula)
```
7 + 26 = 33
```

**Passo 4:** Aplicar módulo
```
33 % 26 = 7
```

**Passo 5:** Converter para letra
```
7 + 'A' = 7 + 65 = 72 ('H')
```

**Resultado:** 'K' → 'H' ✓

### Casos Especiais

#### Caso 1: Letra no início do alfabeto

Descriptografar 'D' com chave 5:
```
'D' - 'A' - 5 + 26 = 3 - 5 + 26 = 24
24 % 26 = 24
24 + 'A' = 'Y'
```

#### Caso 2: Letra após a metade

Descriptografar 'M' com chave 10:
```
'M' - 'A' - 10 + 26 = 12 - 10 + 26 = 28
28 % 26 = 2
2 + 'A' = 'C'
```

#### Caso 3: Chave igual à posição

Descriptografar 'D' com chave 3:
```
'D' - 'A' - 3 + 26 = 3 - 3 + 26 = 26
26 % 26 = 0
0 + 'A' = 'A'
```

### Exemplo Completo - Reversão

**Texto criptografado:** `"Khoor!"` com chave 3

| Posição | Caractere | Processamento | Resultado |
|---------|-----------|---------------|-----------|
| 0 | K | (10-3+26)%26+'A' = 7+'A' | H |
| 1 | h | (7-3+26)%26+'a' = 4+'a' | e |
| 2 | o | (14-3+26)%26+'a' = 11+'a' | l |
| 3 | o | (14-3+26)%26+'a' = 11+'a' | l |
| 4 | r | (17-3+26)%26+'a' = 14+'a' | o |
| 5 | ! | Não alterado | ! |

**Resultado:** `"Hello!"` ✓

---

## 4.3. Comparação entre Criptografia e Descriptografia

### Tabela Comparativa

| Aspecto | Criptografar | Descriptografar |
|---------|--------------|-----------------|
| Operação principal | Soma (`+ chave`) | Subtração (`- chave`) |
| Fórmula base | `(P + K) mod 26` | `(C - K + 26) mod 26` |
| Direção do deslocamento | Para frente | Para trás |
| Valor de ajuste | Não necessário | `+ 26` |
| Resultado | Transforma texto | Reverte transformação |

### Propriedade de Inversão

```
criptografar(descriptografar(texto, K), K) = texto
descriptografar(criptografar(texto, K), K) = texto
```

Ambas as operações são mutuamente inversas quando utilizam a mesma chave.

### Validação da Propriedade

**Teste:** Criptografar "HELLO" com chave 3, depois descriptografar com chave 3

```
Original:  H E L L O
           7 4 11 11 14

Criptografia (+3):
H: (7 + 3) % 26 + 'A' = 10 + 'A' = 'K'
E: (4 + 3) % 26 + 'A' = 7 + 'A' = 'H'
L: (11 + 3) % 26 + 'A' = 14 + 'A' = 'O'
L: (11 + 3) % 26 + 'A' = 14 + 'A' = 'O'
O: (14 + 3) % 26 + 'A' = 17 + 'A' = 'R'

Resultado: KHOOR

Descriptografia (-3):
K: (10 - 3 + 26) % 26 + 'A' = 7 + 'A' = 'H' ✓
H: (7 - 3 + 26) % 26 + 'A' = 4 + 'A' = 'E' ✓
O: (14 - 3 + 26) % 26 + 'A' = 11 + 'A' = 'L' ✓
O: (14 - 3 + 26) % 26 + 'A' = 11 + 'A' = 'L' ✓
R: (17 - 3 + 26) % 26 + 'A' = 14 + 'A' = 'O' ✓

Resultado: HELLO ✓
```

A propriedade é validada: o texto original é recuperado perfeitamente.
