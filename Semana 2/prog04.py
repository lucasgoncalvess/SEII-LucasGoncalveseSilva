# Python Tutorial for Beginners 4: Lists, Tuples, and Sets

courses = ['History', 'Math', 'Physics', 'CompSci']
# print(courses)
# print(len(courses)) #mostra quantos valores tem no vetor
# print(courses[0]) #mostra o primeiro elemento do vetor, pode mostrar um intervalo: [0:2]

# # adicionar um elemento
# # courses.append('Art') #adiciona na ultima posição
# courses.insert(0,'Art') #adiciona na posição que você desejar

#adicionar um vetor dentro de outro
# courses_2 = ['Art', 'Education']
# courses.extend(courses_2)
#
# print(courses)

# Mutable
list_1 = ['History', 'Math', 'Physics', 'CompSci']
list_2 = list_1

print(list_1)
print(list_2)

# list_1[0] = 'Art'

# print(list_1)
# print(list_2)


# Immutable
# tuple_1 = ('History', 'Math', 'Physics', 'CompSci')
# tuple_2 = tuple_1

# print(tuple_1)
# print(tuple_2)

# tuple_1[0] = 'Art'

# print(tuple_1)
# print(tuple_2)

# Sets
cs_courses = {'History', 'Math', 'Physics', 'CompSci'}

print(cs_courses)


# Empty Lists
empty_list = []
empty_list = list()

# Empty Tuples
empty_tuple = ()
empty_tuple = tuple()

# Empty Sets
empty_set = {} # This isn't right! It's a dict
empty_set = set()