# 5. FUNÇÃO PRINCIPAL (main)

## 5.1. Visão Geral

A função `main()` é o ponto de entrada do programa, responsável por coordenar todo o fluxo de execução. Ela gerencia a interação com o usuário, valida entrada de dados, e chama as funções apropriadas de criptografia ou descriptografia.

## 5.2. Código Completo

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

## 5.3. Análise Detalhada por Seção

### 5.3.1. Declaração de Variáveis

```c
char texto[1000];
int chave, opcao;
```

#### Variável `texto`

- **Tipo**: Array de caracteres (`char[1000]`)
- **Tamanho**: 1000 caracteres (999 + terminador `\0`)
- **Uso**: Armazena o texto a ser criptografado ou descriptografado
- **Memória**: 1000 bytes (1 byte por caractere)

**Organização na memória:**
```
┌─────┬─────┬─────┬─────┬─────┬─────┬────┬────┬────┬────┐
│ 'H' │ 'e' │ 'l' │ 'l' │ 'o' │'\0' │ ?  │ ?  │ ?  │ ...│
└─────┴─────┴─────┴─────┴─────┴─────┴────┴────┴────┴────┘
  [0]   [1]   [2]   [3]   [4]   [5]   [6]  [7]  [8]  ...
```

#### Variável `chave`

- **Tipo**: Inteiro (`int`)
- **Faixa válida**: 0 a 25
- **Uso**: Define quantas posições no alfabeto cada letra será deslocada

#### Variável `opcao`

- **Tipo**: Inteiro (`int`)
- **Valores possíveis**: 1 (criptografar) ou 2 (descriptografar)
- **Uso**: Determina qual operação realizar

### 5.3.2. Interface Inicial

```c
printf("=== CIFRA DE CÉSAR - Criptografia e Descriptografia ===\n\n");
```

Esta linha imprime o cabeçalho do programa, identificando o tipo de aplicação. O uso de `\n\n` adiciona uma linha em branco para melhor legibilidade.

### 5.3.3. Leitura e Validação da Chave

```c
printf("Digite a chave de deslocamento (0-25): ");
scanf("%d", &chave);
```

**Função `scanf()`:**
- Formato: `"%d"` indica leitura de um inteiro decimal
- Operador `&`: Passa o endereço de memória da variável (ponteiro)
- Comportamento: Lê até encontrar espaço, nova linha ou fim de arquivo

**Exemplo:**
```c
// Usuário digita: 7
scanf("%d", &chave);
// chave agora contém o valor 7
```

**Validação:**
```c
if (chave < 0 || chave > 25) {
    printf("Erro: Chave inválida! Use um valor entre 0 e 25.\n");
    return 1;
}
```

**Por que validar?**
- Evita comportamentos indefinidos
- Fornece feedback claro ao usuário
- Previne cálculos incorretos

**Operador lógico `||` (OU):**
- Retorna `true` se pelo menos uma condição for verdadeira
- Encerra a avaliação no primeiro `true` (short-circuit)

### 5.3.4. Menu de Operação

```c
printf("\nEscolha a operação:\n");
printf("1 - Criptografar\n");
printf("2 - Descriptografar\n");
printf("Opção: ");
scanf("%d", &opcao);
```

**Fluxo:**
1. Mostra opções disponíveis
2. Solicita escolha do usuário
3. Lê a opção digitada

### 5.3.5. Limpeza do Buffer

```c
while (getchar() != '\n');
```

**Por que esta linha é necessária?**

Após usar `scanf()`, o caractere de nova linha (`\n`) permanece no buffer de entrada. Se não for removido, será lido pelo próximo `fgets()`.

**Exemplo do problema:**

```c
scanf("%d", &opcao);     // Lê o número 1
// Buffer contém: ['\n']

fgets(texto, ...);       // Lê apenas '\n' (string vazia!) ❌
```

**Solução:**

```c
while (getchar() != '\n');  // Remove '\n' do buffer
// Buffer agora: []
```

**Como funciona:**
- `getchar()` lê um caractere de cada vez
- `while` continua até encontrar `\n`
- Após encontrar `\n`, o loop termina

### 5.3.6. Leitura do Texto

```c
printf("\nDigite o texto: ");
fgets(texto, sizeof(texto), stdin);
```

**Função `fgets()`:**
- Parâmetro 1: Buffer de destino (`texto`)
- Parâmetro 2: Tamanho máximo (`sizeof(texto)` = 1000)
- Parâmetro 3: Stream de entrada (`stdin` = teclado)

**Diferenças entre `scanf()` e `fgets()`:**

| Aspecto | scanf("%s", texto) | fgets(texto, size, stdin) |
|---------|-------------------|---------------------------|
| **Espaços** | Para no primeiro espaço | Lê espaços |
| **Linha inteira** | Não | Sim |
| **`\n` final** | Não inclui | Inclui |
| **Exemplo** | "Hello World" → "Hello" | "Hello World" → "Hello World\n" |

### 5.3.7. Remoção do `\n` Final

```c
texto[strcspn(texto, "\n")] = 0;
```

**Função `strcspn()`:**
```c
size_t strcspn(const char *str1, const char *str2);
```

- Retorna a posição do primeiro caractere de `str2` encontrado em `str1`
- Se não encontrar, retorna o tamanho de `str1`

**Exemplo:**
```c
char texto[] = "Hello\n\0";
//             0123456

strcspn(texto, "\n");  // Retorna 5 (posição do '\n')

texto[5] = 0;          // Substitui '\n' por '\0'

// Resultado: "Hello\0"
```

**Por que fazer isso?**
- `fgets()` adiciona `\n` ao final
- Para exibição correta, preferimos remover
- `\0` indica fim da string

### 5.3.8. Execução da Operação

```c
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
```

**Estrutura condicional:**

1. **Se opção == 1**: Criptografa e exibe
2. **Senão se opção == 2**: Descriptografa e exibe
3. **Senão**: Erro (opção inválida)

**Chamada de função:**
```c
criptografar(texto, chave);
```

- Passa o array `texto` (por referência)
- A função modifica `texto` diretamente
- Após a chamada, `texto` contém o resultado

**Especificador de formato `%s`:**
- `%s` em `printf` imprime uma string
- Lê até encontrar `\0`

## 5.4. Fluxo de Execução Completo

### Diagrama de Fluxo

```
Início
  ↓
Declarar variáveis (texto, chave, opcao)
  ↓
Exibir cabeçalho
  ↓
Ler chave do usuário
  ↓
Validar chave
  ↓
Se inválida: Exibir erro e encerrar
  ↓
Exibir menu de opções
  ↓
Ler opção do usuário
  ↓
Limpar buffer (remover '\n')
  ↓
Ler texto do usuário
  ↓
Remover '\n' final do texto
  ↓
Se opção == 1: Criptografar
  ↓
Senão se opção == 2: Descriptografar
  ↓
Senão: Exibir erro e encerrar
  ↓
Exibir resultado
  ↓
Retornar 0 (sucesso)
  ↓
Fim
```

### Exemplo de Execução Interativa

**Entrada do usuário:**
```
Digite a chave de deslocamento (0-25): 3
Escolha a operação:
1 - Criptografar
2 - Descriptografar
Opção: 1
Digite o texto: Hello World
```

**Processamento interno:**
```
Estado das variáveis:

chave = 3
opcao = 1
texto = "Hello World\0"

Aplicação da criptografia:
H → K
e → h
l → o
l → o
o → r
[espaço] → [espaço]
W → Z
o → r
r → u
l → o
d → g

texto = "Khoor Zruog\0"
```

**Saída do programa:**
```
Texto criptografado: Khoor Zruog
```

## 5.5. Tratamento de Erros

### Erro de Chave Inválida

```c
if (chave < 0 || chave > 25) {
    printf("Erro: Chave inválida! Use um valor entre 0 e 25.\n");
    return 1;  // Código de erro
}
```

- Código de retorno 1 indica erro
- Programa encerra imediatamente

### Erro de Opção Inválida

```c
else {
    printf("Erro: Opção inválida!\n");
    return 1;
}
```

- Captura qualquer valor diferente de 1 ou 2

## 5.6. Códigos de Retorno

**Convenção Unix/Linux:**
- `0`: Sucesso
- `1`: Falha geral
- `2`: Uso incorreto

**Motivo:**
- Permite automação de scripts
- Facilita detecção de erros
- Padrão amplamente adotado

## 5.7. Características de Design

### Interatividade
- Programa orientado a diálogo
- Solicita informação quando necessário
- Feedback imediato

### Robustez
- Validação de entrada
- Mensagens de erro claras
- Tratamento de casos inválidos

### Clareza
- Código legível
- Comentários explicativos
- Nomes de variáveis descritivos

### Eficiência
- Processamento em tempo linear O(n)
- Uso eficiente de memória
- Sem overhead desnecessário

---

Esta função principal serve como orquestradora do programa, coordenando todas as operações e garantindo uma experiência de usuário fluida e robusta.
