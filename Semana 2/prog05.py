# Python Tutorial for Beginners 5: Dictionaries - Working with Key-Value Pairs
student = {'name': 'John', 'age':25, 'courses':['Math', 'CompSci'] }

#print(student['name'])
student['phone']= '3555555'
student['name'] = 'Jane'
#pegar um valor e se não existir por a mensagem
print(student.get('phone', 'Not Found'))

#atualizar os dados
student.update({'name': 'Jane', 'age': 26, 'phone': 66666})
print(student)

#pegar o valor e por em uma variavel
age = student.pop('age')
print(age)

#informações
print(len(student))
print(student.items())

#listar os dados
for key, value in student.items():
    print(key, value)
