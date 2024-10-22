import time

ruta = 'archivo.txt'

inicio_tiempo = time.time()

with open(ruta, 'r') as archivo:
    datos = archivo.read()

arreglo = list(map(int, datos.split()))

pila = [(0, len(arreglo) - 1)]

while pila:
    inicio, fin = pila.pop()
    if inicio >= fin:
        continue

    pivote = arreglo[fin]
    i = inicio - 1

    for j in range(inicio, fin):
        if arreglo[j] <= pivote:
            i += 1
            arreglo[i], arreglo[j] = arreglo[j], arreglo[i]

    arreglo[i + 1], arreglo[fin] = arreglo[fin], arreglo[i + 1]
    pivote_index = i + 1

    pila.append((inicio, pivote_index - 1))
    pila.append((pivote_index + 1, fin))

with open(ruta, 'w') as archivo:
    archivo.write(' '.join(map(str, arreglo)))

fin_tiempo = time.time()
print(f"Tiempo de ejecución: {fin_tiempo - inicio_tiempo} segundos")
