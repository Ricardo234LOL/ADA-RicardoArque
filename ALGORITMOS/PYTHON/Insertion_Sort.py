import time

ruta = 'archivo.txt'

inicio_tiempo = time.time()

with open(ruta, 'r') as archivo:
    datos = archivo.read()

arreglo = list(map(int, datos.split()))

n = len(arreglo)
for i in range(1, n):
    clave = arreglo[i]
    j = i - 1
    while j >= 0 and clave < arreglo[j]:
        arreglo[j + 1] = arreglo[j]
        j -= 1
    arreglo[j + 1] = clave

with open(ruta, 'w') as archivo:
    archivo.write(' '.join(map(str, arreglo)))

fin_tiempo = time.time()
print(f"Tiempo de ejecución: {fin_tiempo - inicio_tiempo} segundos")
