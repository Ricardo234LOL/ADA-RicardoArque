import time

ruta = 'archivo.txt'

inicio_tiempo = time.time()

with open(ruta, 'r') as archivo:
    datos = archivo.read()

arreglo = list(map(int, datos.split()))

n = len(arreglo)
for i in range(n):
    min_idx = i
    for j in range(i + 1, n):
        if arreglo[j] < arreglo[min_idx]:
            min_idx = j
    arreglo[i], arreglo[min_idx] = arreglo[min_idx], arreglo[i]

with open(ruta, 'w') as archivo:
    archivo.write(' '.join(map(str, arreglo)))

fin_tiempo = time.time()
print(f"Tiempo de ejecución: {fin_tiempo - inicio_tiempo} segundos")
