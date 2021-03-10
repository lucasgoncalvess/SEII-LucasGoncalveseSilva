#Python Tutorial for Beginners 2: Strings - Working with Textual Data

# message = 'Hello Word'
# print(message[0:7])

greeting = 'Hello'
name = 'Michael'
                        # name.upper() faz o nome ficar todo em letra maiusucla

# message = greeting + ', ' + name

#Printar com variaveis inseridas
message = '{}, {}. Welcome!'.format(greeting, name)
print(message)

#Para Obter Ajuda sobre a classe str e print


print(help(str.lower))