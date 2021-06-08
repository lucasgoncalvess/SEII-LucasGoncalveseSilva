# Semana 16-18 - Exercício 1

1. Faça um programa em Python que apresenteas 20 primeiras saídas para assequênciasdadas pelos padrões abaixo, de forma iterativa, a partir dovalorinicial e de uma equação de diferenças:


```python
n_elementos = 20  
```

# Sequência A

![image.png](attachment:image.png)


```python
def seq_a(n_saida):
    sequencia = []
    i = 1
    r = 1 
    while i <= n_saida:
        sequencia.append(r)
        r += 2
        i += 1
    return sequencia

print('Resposta:')
seq_a(n_elementos)

```

    Resposta:
    




    [1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39]



# Sequência B

![image.png](attachment:image.png)


```python
def seq_b(n_saida):
    sequencia = []
    i = 1
    r = 0
    while i <= n_saida:
        r = r + i
        sequencia.append(r)
        i +=1
    return sequencia

print('Resposta:')
seq_b(n_elementos)
```

    Resposta:
    




    [1,
     3,
     6,
     10,
     15,
     21,
     28,
     36,
     45,
     55,
     66,
     78,
     91,
     105,
     120,
     136,
     153,
     171,
     190,
     210]



# Sequência C

![image.png](attachment:image.png)


```python
def seq_c(n_saida):
    sequencia = []
    i = 1
    while i <= n_saida:
        r = i*i
        sequencia.append(r)
        i +=1
    return sequencia 

print('Resposta:')
seq_c(n_elementos)
```

    Resposta:
    




    [1,
     4,
     9,
     16,
     25,
     36,
     49,
     64,
     81,
     100,
     121,
     144,
     169,
     196,
     225,
     256,
     289,
     324,
     361,
     400]


