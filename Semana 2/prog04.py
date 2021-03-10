# Python Tutorial for Beginners 4: Lists, Tuples, and Sets

courses = ['History', 'Math', 'Physics', 'CompSci']
# print(courses)
# print(len(courses)) #mostra quantos valores tem no vetor
# print(courses[0]) #mostra o primeiro elemento do vetor, pode mostrar um intervalo: [0:2]

# # adicionar um elemento
# # courses.append('Art') #adiciona na ultima posição
# courses.insert(0,'Art') #adiciona na posição que você desejar

#adicionar um vetor dentro de outro
courses_2 = ['Art', 'Education']
courses.extend(courses_2)

print(courses)
