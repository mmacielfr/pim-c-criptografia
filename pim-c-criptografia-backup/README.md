# pim-c-criptografia
Trabalho de faculdade UNIP

## Cifra de César - Sistema de Criptografia

Este projeto implementa a Cifra de César em linguagem C para criptografar e descriptografar textos.

### ⚠️ IMPORTANTE: Por que não é possível descriptografar hashes?

**Cifra de César ≠ Hash** - São conceitos completamente diferentes:

#### Cifra de César (o que este programa faz):
- ✅ **Reversível**: Com a chave, você pode descriptografar
- ✅ **Bidirecional**: Criptografar ↔ Descriptografar
- ✅ **Simples**: Desloca letras por um número fixo
- ❌ **Não é seguro** para senhas reais

#### Hash (usado para senhas):
- ❌ **Irreversível**: Matematicamente impossível de reverter
- ❌ **Unidirecional**: Só consegue verificar, nunca recuperar
- ✅ **Seguro**: Protege senhas em sistemas reais
- ✅ **Uso correto**: Sistema armazena hash e verifica comparando

### Exemplo:

```
Senha: "minhasenha123"
Hash MD5: "a8f5f167f44f4964e6c998dee827110c"

Não existe forma de transformar "a8f5f167f44f4964e6c998dee827110c" 
de volta em "minhasenha123"
```

### Como funciona a verificação de senha com hash:

```
1. Usuário digita senha: "minhasenha123"
2. Sistema calcula hash: "a8f5f167f44f4964e6c998dee827110c"
3. Sistema compara com hash armazenado
4. Se forem iguais → Login permitido
```

### Por que Cifra de César NÃO funciona para senhas?

Se usar Cifra de César para senhas:
```c
Senha: "admin"
Chave: 3
Criptografado: "dgplq"  ← Com a chave, QUALQUER UM descriptografa!
```

**Qualquer pessoa com a chave recupera a senha original!**

## Compilação e Execução

```bash
gcc -o cesar cesar.c
./cesar
```

## Funcionalidades

- Criptografar texto com chave de 0-25
- Descriptografar texto criptografado
- Suporta letras maiúsculas e minúsculas
- Preserva espaços e caracteres especiais

## Exemplo de Uso

```
Texto original: "Hello World"
Chave: 3
Criptografado: "Khoor Zruog"
Descriptografado: "Hello World" (usando a mesma chave)
```
