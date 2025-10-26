# 🚀 Guia Rápido - Teste Manual no Terminal

## 📝 COMO USAR: Digite EXATAMENTE assim no terminal

---

## 🎯 EXEMPLO COMPLETO - Passo a Passo

### **1️⃣ Inicie o programa:**
```bash
./cesar
```

### **2️⃣ Você verá isto:**
```
=== CIFRA DE CÉSAR - Criptografia e Descriptografia ===

Digite a chave de deslocamento (0-25): 
```

### **3️⃣ CRIPTOGRAFAR uma senha**

Digite na ordem:

**Passo 1:** Digite a chave (por exemplo: `5`)
```
5
```

**Passo 2:** Escolha a opção (digite `1` para criptografar)
```
1
```

**Passo 3:** Digite sua "senha" ou mensagem
```
minhasenha
```

**Resultado esperado:**
```
Texto criptografado: rnsrxfjslf
```

---

## 🔓 DESCRIPTOGRAFAR

**IMPORTANTE:** Use a MESMA chave!

Execute novamente:
```bash
./cesar
```

Agora digite:

**Passo 1:** Chave `5` (mesma de antes!)
```
5
```

**Passo 2:** Opção `2` (descriptografar)
```
2
```

**Passo 3:** Texto criptografado `rnsrxfjslf`
```
rnsrxfjslf
```

**Resultado esperado:**
```
Texto descriptografado: minhasenha
```

---

## 📊 EXEMPLO PRÁTICO COMPLETO

### **Cenário: Criptografar senha "senha123"**

```
Terminal:
$ ./cesar
=== CIFRA DE CÉSAR - Criptografia e Descriptografia ===

Digite a chave de deslocamento (0-25): 3
Escolha a operação:
1 - Criptografar
2 - Descriptografar
Opção: 1
Digite o texto: senha123
Texto criptografado: vhqkd123
```

### **Descriptografar:**

```
$ ./cesar
=== CIFRA DE CÉSAR - Criptografia e Descriptografia ===

Digite a chave de deslocamento (0-25): 3
Escolha a operação:
1 - Criptografar
2 - Descriptografar
Opção: 2
Digite o texto: vhqkd123
Texto descriptografado: senha123
```

---

## ⚠️ DICAS IMPORTANTES

### ✅ **O QUE FUNCIONA:**
- Letras maiúsculas: `SENHA` → `VHQKD`
- Letras minúsculas: `senha` → `vhqkd`
- Mistura: `SenHa` → `VhqKd`

### ❌ **O QUE NÃO MUDA:**
- Números: `123` continua `123`
- Espaços: `senha123` continua com o espaço
- Símbolos: `!@#` continuam `!@#`

---

## 🎓 TESTES SUGERIDOS

### **Teste 1: Senha Simples**
```
Chave: 3
Texto: admin
Resultado: dgplq
```

### **Teste 2: Senha com Números**
```
Chave: 5
Texto: senha123
Resultado: xjslf123
```

### **Teste 3: Senha Maiúscula**
```
Chave: 7
Texto: ADMIN
Resultado: HKJPUT
```

### **Teste 4: Senha Mista**
```
Chave: 4
Texto: SenHa123!
Resultado: WirLe123!
```

---

## 🔑 LEMBRE-SE

- **Use a MESMA chave** para criptografar e descriptografar
- Números e símbolos **NÃO são alterados**
- Chave deve ser entre **0 e 25**
- Para testar: sempre descriptografe o que criptografou!

---

## 🚨 SE DER ERRO

### Erro: "Opção inválida"
- Você digitou algo diferente de `1` ou `2`
- Solução: Digite apenas o número (sem espaços)

### Erro: "Chave inválida"
- Você digitou número fora de 0-25
- Solução: Use número entre 0 e 25

### Não aparece resultado
- Verifique se não digitou espaço antes do texto
- Solução: Comece a digitar direto (sem pressionar espaço)
