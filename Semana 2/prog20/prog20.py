# Python Tutorial: Using Try/Except Blocks for Error Handling

try:
    f = open('curruptfile.txt')
    # if f.name == 'currupt_file.txt':
except IOError as e:
    print('First!')
except Exception as e:
    print('Second')
else:
    print(f.read())
    f.close()
finally:
    print("Executing Finally...")

print('End of program')