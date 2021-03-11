#Python Tutorial for Beginners 9: Import Modules and Exploring The Standard Library

import my_module as mm #pega a função e abrevia para mm
from my_module import find_index #fazendo assim não é preciso por o nome da biblioteca antes

courses = ['History', 'Math', 'Physics', 'CompSci']

index = mm.find_index(courses, 'Math')
print(index)

import math
import datetime
import calendar

# today = datetime.date.today()
# print(today)
# print(calendar.isleap(2020))

import os
print(os.getcwd())

