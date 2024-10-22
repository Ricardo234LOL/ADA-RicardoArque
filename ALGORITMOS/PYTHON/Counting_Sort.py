import time
ruta = 'archivo.txt'
inicio_tiempo = time.time()
with open(ruta, 'r') as archivo:
    datos = archivo.read()
arreglo = list(map(int, datos.split()))

max_valor = max(arreglo)

conteo = [0] * (max_valor + 1)

for numero in arreglo:
    conteo[numero] += 1

indice = 0
for i in range(len(conteo)):
    while conteo[i] > 0:
        arreglo[indice] = i
        indice += 1
        conteo[i] -= 1

with open(ruta, 'w') as archivo:
    archivo.write(' '.join(map(str, arreglo)))

fin_tiempo = time.time()
print(f"Tiempo de ejecución: {fin_tiempo - inicio_tiempo} segundos")