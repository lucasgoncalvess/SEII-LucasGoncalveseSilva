#Threads
#Lucas Gonçalves e Silva

#Bibliotecas
import _thread
import concurrent.futures
import time

start = time.perf_counter() #inicia um contador para medir o tempo do script

#função que printa o tempo que vai ser pausado (sleeping)
def do_something(seconds):
    print(f'Sleeping {seconds} second(s)...')
    time.sleep(seconds)
    return f'Done Sleeping...{seconds}'


with concurrent.futures.ThreadPoolExecutor() as executor:
    secs = [5, 4, 3, 2, 1]
    results = executor.map(do_something, secs)

# fim da verificação de tempo
finish = time.perf_counter()

#impressão do tempo total final que foi necessario para executar o script
print(f'Finished in {round(finish-start, 2)} second(s)')