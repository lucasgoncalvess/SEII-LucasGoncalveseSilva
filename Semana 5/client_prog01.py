#!/usr/bin/env python
# -*- coding: utf-8 -*-
'''
Semana 05- Sistemas Embarcados 2
Lucas Gonçalves e Silva
'''

#Bibliotecas
import sys
import socket

door = sys.argv[1]
ip = sys.argv[2]
filename = sys.argv[3]


door = int(door)

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((socket.gethostname(), door))
print('Guardando dados')
msg = s.recv(door)
out = msg.decode("utf-8")
file = open(filename,'w')
file.write(out)
file.close()