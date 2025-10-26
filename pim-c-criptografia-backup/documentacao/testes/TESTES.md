# 🧪 Como Testar o Programa Cifra de César

## 📝 Formas de Testar

### **Método 1: Teste Interativo (Recomendado para Iniciantes)**

1. **Compile o programa** (se ainda não compilou):
```bash
gcc -o cesar cesar.c
```

2. **Execute o programa**:
```bash
./cesar
```

3. **Siga as instruções na tela**:

```
=== CIFRA DE CÉSAR - Criptografia e Descriptografia ===

Digite a chave de deslocamento (0-25): [Digite um número]
Escolha a operação:
1 - Criptografar
2 - Descriptografar
Opção: [Digite 1 ou 2]
Digite o texto: [Digite seu texto]
```

---

### **Método 2: Teste Automatizado (Com echo)**

Testa rapidamente sem digitar manualmente:

#### **Teste 1: Criptografar "Hello"**

```bash
echo -e "3\n1\nHello" | ./cesar
```

**O que acontece:**
- Chave: `3`
- Opção: `1` (criptografar)
- Texto: `Hello`
- **Resultado esperado:** `Khoor`

#### **Teste 2: Descriptografar "Khoor"**

```bash
echo -e "3\n2\nKhoor" | ./cesar
```

**Resultado esperado:** `Hello`

#### **Teste 3: Texto com espaços**

```bash
echo -e "5\n1\nHello World" | ./cesar
```

**Resultado esperado:** `Mjqqt Btwqi`

#### **Teste 4: Texto maiúsculo e minúsculo**

```bash
echo -e "4\n1\nAbCdEf" | ./cesar
```

**Resultado esperado:** `EfGhIj`

---

### **Método 3: Teste Completo (Criptografar e Descriptografar)**

Execute em sequência para verificar se funciona corretamente:

```bash
# 1. Criptografar
echo -e "7\n1\nSegredo Secreto" | ./cesar

# 2. Usar o resultado acima em descriptografar
echo -e "7\n2\nZlnylkv Zlylyav" | ./cesar
```

**Resultado esperado no passo 2:** `Segredo Secreto`

---

## 🎯 Testes Recomendados para Aprender

### **Teste 1: Chave 0 (não altera nada)**

```bash
echo -e "0\n1\nHello" | ./cesar
```

**Resultado:** `Hello` (mesmo texto!)

---

### **Teste 2: Chave 26 (equivalente a chave 0)**

```bash
echo -e "26\n1\nHello" | ./cesar
```

**Resultado:** Deve mostrar erro! (chave inválida)

---

### **Teste 3: Caracteres especiais (não são alterados)**

```bash
echo -e "3\n1\nHello 123!" | ./cesar
```

**Resultado:** Espaços, números e símbolos não mudam!
```
Khoor 123!
```

---

### **Teste 4: Letra Z (testa wraparound)**

```bash
echo -e "1\n1\nZebra" | ./cesar
```

**Resultado:** Z vai virar A (volta ao início do alfabeto)
```
Afcsb
```

---

## 🚀 Script de Teste Automático

Crie um arquivo `testar.sh` para rodar todos os testes de uma vez:

```bash
#!/bin/bash

echo "=== TESTE 1: Criptografar 'Hello' com chave 3 ==="
echo -e "3\n1\nHello" | ./cesar
echo ""

echo "=== TESTE 2: Descriptografar 'Khoor' com chave 3 ==="
echo -e "3\n2\nKhoor" | ./cesar
echo ""

echo "=== TESTE 3: Texto com espaços ==="
echo -e "5\n1\nHello World" | ./cesar
echo ""

echo "=== TESTE 4: Teste completo (criptografar e descriptografar) ==="
CRIPTOGRAFADO=$(echo -e "7\n1\nTeste" | ./cesar | grep ":" | tail -1 | cut -d' ' -f4-)
echo "Texto criptografado: $CRIPTOGRAFADO"
echo "Descriptografando..."
echo -e "7\n2\n$CRIPTOGRAFADO" | ./cesar | grep "descriptografado"
```

**Como usar:**
```bash
chmod +x testar.sh
./testar.sh
```

---

## 📊 Checklist de Testes

Marque conforme testar:

- [ ] Criptografar texto simples
- [ ] Descriptografar texto criptografado
- [ ] Testar chave 0 (não altera nada)
- [ ] Testar chave 13 (metade do alfabeto)
- [ ] Testar chave 25 (penúltima letra)
- [ ] Testar letra Z (volta para A)
- [ ] Testar com espaços
- [ ] Testar com números (não devem mudar)
- [ ] Testar com símbolos (não devem mudar)
- [ ] Testar com maiúsculas e minúsculas
- [ ] Tentar chave inválida (erro deve aparecer)

---

## 🐛 Solução de Problemas

### **Erro: "bash: ./cesar: Permissão negada"**

```bash
chmod +x cesar
```

### **Erro: "bash: ./cesar: No such file or directory"**

```bash
# Recompilar o programa
gcc -o cesar cesar.c
```

### **O programa roda mas não mostra resultado**

```bash
# Verificar se está realmente compilado
ls -l cesar

# Executar com output completo
./cesar
```

---

## 💡 Dicas

1. **Teste sempre com textos conhecidos** primeiro
2. **Use "Hello World"** como base - é fácil de conferir
3. **Teste descriptografar** para garantir que está funcionando
4. **Experimente chaves diferentes** para ver como muda
5. **Use o script automático** para testar tudo rapidamente

---

## 🎓 Exemplos para Apresentação

### **Demonstração 1: Mensagem Secreta**

```bash
# Criptografar uma mensagem
echo -e "10\n1\nReuniao as 15h" | ./cesar
# Resultado: Bokxsxc qc 15h

# Mostrar como descriptografar
echo -e "10\n2\nBokxsxc qc 15h" | ./cesar
# Resultado: Reuniao as 15h
```

### **Demonstração 2: Cifra Clássica (Chave 3)**

```bash
# Cesar originalmente usava chave 3
echo -e "3\n1\nVENI VIDI VICI" | ./cesar
# Resultado: YHQL YLGL YLFL
```
