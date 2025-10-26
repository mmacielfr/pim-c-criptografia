# 2. FUNDAMENTAÇÃO TEÓRICA

## 2.1. Conceito de Cifra de César

A Cifra de César é um tipo de cifra de substituição monoalfabética, na qual cada letra de um texto é substituída por outra letra do alfabeto, deslocada por um número fixo de posições. Por exemplo, com um deslocamento de 3 posições, a letra 'A' torna-se 'D', 'B' torna-se 'E', e assim sucessivamente.

O método recebe esse nome em homenagem a Júlio César (100-44 a.C.), imperador romano que, segundo registros históricos, utilizou este método para comunicar-se com seus generais durante campanhas militares. Suetônio, historiador romano, documentou que César "escrevia usando caracteres trocados, de forma que nenhuma palavra pudesse ser entendida".

### Características Principais

**Simplicidade Conceitual**: O algoritmo é extremamente simples de entender e implementar, exigindo apenas conhecimento básico de aritmética modular.

**Facilidade de Implementação**: Pode ser implementado manualmente ou através de programação em praticamente qualquer linguagem de programação.

**Criptografia Simétrica**: Utiliza a mesma chave (número de deslocamento) tanto para criptografar quanto para descriptografar a mensagem.

**Unidirecional de Chave**: A chave funciona de forma bidirecional - se avançar 3 posições criptografa, retroceder 3 posições descriptografa.

### Contexto Histórico

A cifra foi desenvolvida em um contexto onde a comunicação segura era crucial para a vitória em batalhas. Militares romanos precisavam proteger informações estratégicas como:
- Planejamento de ataques
- Posições de tropas
- Identidade de aliados
- Coordenadas geográficas

Mesmo sendo um método primitivo, a Cifra de César representou um avanço significativo na história da criptografia, estabelecendo os fundamentos para técnicas mais sofisticadas que viriam a ser desenvolvidas séculos depois.

## 2.2. Funcionamento Matemático

A base matemática da Cifra de César fundamenta-se em aritmética modular, especificamente operações sobre o conjunto finito de 26 letras do alfabeto (A-Z).

### Fórmula de Criptografia

**C = (P + K) mod 26**

Onde:
- **C** = Letra criptografada (ciphertext)
- **P** = Letra original (plaintext), mapeada como número de 0 a 25 (A=0, B=1, ..., Z=25)
- **K** = Chave (key), representando o número de posições de deslocamento
- **mod** = Operador módulo, que retorna o resto da divisão

### Fórmula de Descriptografia

**P = (C - K + 26) mod 26**

Onde o termo "+26" é fundamental para evitar valores negativos durante a descriptografia, garantindo que o resultado seja sempre um número não-negativo.

### Exemplo Numérico Detalhado

Considere a criptografia da letra 'H' com chave 3:

**Passo 1**: Converter 'H' para posição numérica
```
'A' = 65 (ASCII) → posição 0
'B' = 66 (ASCII) → posição 1
...
'H' = 72 (ASCII) → posição 7
```

**Passo 2**: Aplicar a fórmula de criptografia
```
C = (7 + 3) mod 26
C = 10 mod 26
C = 10
```

**Passo 3**: Converter de volta para letra
```
Posição 10 → 'K'
Resultado: 'H' → 'K'
```

### Comportamento do Operador Módulo

O operador módulo (%) é crucial para manter os valores dentro do intervalo válido do alfabeto (0-25):

```
10 % 26 = 10      // Dentro do intervalo
26 % 26 = 0       // Volta ao início (equivalente a chave 0)
30 % 26 = 4       // Excedeu, volta ao início + 4
52 % 26 = 0       // Duas voltas completas
```

### Propriedade Wraparound

Quando o deslocamento ultrapassa a letra 'Z', o algoritmo "volta" para o início do alfabeto. Esta propriedade é chamada de wraparound (volta ao início):

```
Chave 3 aplicada em 'X':
'X' = 23 (posição)
C = (23 + 3) mod 26
C = 26 mod 26
C = 0
Resultado: 'X' → 'A'
```

## 2.3. Mapeamento de Caracteres

### Alfabeto como Sequência Circular

```
  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25
  A   B   C   D   E   F   G   H   I   J   K   L   M   N   O   P   Q   R   S   T   U   V   W   X   Y   Z
  ↑                                                                                                   ↑
  └─────────────────────────────────────────── Chave 3 ────────────────────────────────────────────┘
  
  A → D  (0 + 3 = 3)
  B → E  (1 + 3 = 4)
  ...
  X → A  (23 + 3 = 26 mod 26 = 0)
  Y → B  (24 + 3 = 27 mod 26 = 1)
  Z → C  (25 + 3 = 28 mod 26 = 2)
```

### Tratamento de Maiúsculas e Minúsculas

O algoritmo trata maiúsculas e minúsculas de forma independente:

- **Maiúsculas**: 'A' a 'Z' (ASCII 65-90)
- **Minúsculas**: 'a' a 'z' (ASCII 97-122)

Cada conjunto possui seu próprio intervalo, mas ambos utilizam a mesma lógica matemática de deslocamento módulo 26.

### Caracteres Não-Alfabéticos

Caracteres que não são letras (espaços, números, símbolos) são preservados sem alteração. Esta característica é importante para manter a legibilidade e estrutura do texto original, permitindo que mensagens com números, pontuação e formatação sejam criptografadas de forma apropriada.
