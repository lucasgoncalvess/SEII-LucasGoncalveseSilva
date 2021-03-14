import matplotlib.pyplot as plt
import numpy as np

x = [0,1,2,3,4]
y = [0,2,4,6,8]
plt.figure(figsize=(8,5), dpi=100)
plt.plot(x,y, 'b^--', label='2x') #azul, pontinhada, com marcadores

#primeira parte linha dois, cor vermelha, largura 2
x2 = np.arange(0,4.5,0.5)
plt.plot(x2[:6], x2[:6]**2, 'r', label='X^2', linewidth =2)

#segunda parte linha dois, vermelha pontilhada
plt.plot(x2[5:], x2[5:]**2, 'r--')

#titulo do graifco
plt.title('Teste de Gráfico', fontdict={'fontname': 'Comic Sans MS', 'fontsize': 20})

#titulo eixos
plt.xlabel('X')
plt.ylabel('Y')

#marcas da escala do grafico
plt.xticks([0,1,2,3,4,])
plt.yticks([0,2,4,6,8,10])
#legenda
plt.legend()

#salvando grafico
plt.savefig('grafico1.png', dpi=100)

plt.show()