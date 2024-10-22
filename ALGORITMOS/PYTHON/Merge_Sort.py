import time

ruta = 'archivo.txt'

inicio_tiempo = time.time()

with open(ruta, 'r') as archivo:
    datos = archivo.read()

arreglo = list(map(int, datos.split()))

n = len(arreglo)
sublistas = [[arreglo[i]] for i in range(n)]

while len(sublistas) > 1:
    nuevas_sublistas = []
    for i in range(0, len(sublistas) - 1, 2):
        izquierda = sublistas[i]
        derecha = sublistas[i + 1]
        temp = []
        while izquierda and derecha:
            if izquierda[0] < derecha[0]:
                temp.append(izquierda.pop(0))
            else:
                temp.append(derecha.pop(0))
        temp += izquierda
        temp += derecha
        nuevas_sublistas.append(temp)
    if len(sublistas) % 2 == 1:
        nuevas_sublistas.append(sublistas[-1])
    sublistas = nuevas_sublistas

arreglo = sublistas[0]

with open(ruta, 'w') as archivo:
    archivo.write(' '.join(map(str, arreglo)))

fin_tiempo = time.time()
print(f"Tiempo de ejecución: {fin_tiempo - inicio_tiempo} segundos")
