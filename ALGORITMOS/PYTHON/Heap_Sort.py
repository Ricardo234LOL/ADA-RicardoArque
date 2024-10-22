import time

ruta = 'archivo.txt'

inicio_tiempo = time.time()

with open(ruta, 'r') as archivo:
    datos = archivo.read()

arreglo = list(map(int, datos.split()))

n = len(arreglo)

for i in range(n // 2 - 1, -1, -1):
    indice = i
    while True:
        hijo_izq = 2 * indice + 1
        hijo_der = 2 * indice + 2
        mayor = indice
        if hijo_izq < n and arreglo[hijo_izq] > arreglo[mayor]:
            mayor = hijo_izq
        if hijo_der < n and arreglo[hijo_der] > arreglo[mayor]:
            mayor = hijo_der
        if mayor == indice:
            break
        arreglo[indice], arreglo[mayor] = arreglo[mayor], arreglo[indice]
        indice = mayor

for i in range(n - 1, 0, -1):
    arreglo[i], arreglo[0] = arreglo[0], arreglo[i]  
    tamaño_heap = i
    indice = 0
    while True:
        hijo_izq = 2 * indice + 1
        hijo_der = 2 * indice + 2
        mayor = indice
        if hijo_izq < tamaño_heap and arreglo[hijo_izq] > arreglo[mayor]:
            mayor = hijo_izq
        if hijo_der < tamaño_heap and arreglo[hijo_der] > arreglo[mayor]:
            mayor = hijo_der
        if mayor == indice:
            break
        arreglo[indice], arreglo[mayor] = arreglo[mayor], arreglo[indice]
        indice = mayor

with open(ruta, 'w') as archivo:
    archivo.write(' '.join(map(str, arreglo)))

fin_tiempo = time.time()
print(f"Tiempo de ejecución: {fin_tiempo - inicio_tiempo} segundos")
