#!/usr/bin/env python
# -*- coding: utf-8 -*-
'''
Semana 05- Sistemas Embarcados 2
Lucas Gonçalves e Silva
'''

#!/usr/bin/env python
# -*- coding: utf-8 -*-

#Bibliotecas
import sys
import socket

door = sys.argv[1]
filename = sys.argv[2]

print(door)

door = int(door)

with open(filename,'r') as file:
    data = file.read()
print(data)

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((socket.gethostname(), door))
s.listen(5)
while True:
    clientsocket, address = s.accept()
    print(f"Conexão de {address} realizada.")
    clientsocket.send(bytes(data,"utf-8"))
    clientsocket.close()