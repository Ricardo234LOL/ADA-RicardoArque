import time
import os
from functools import partial

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        L = arr[:mid]
        R = arr[mid:]

        merge_sort(L)
        merge_sort(R)

        i = j = k = 0
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1

        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1

def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def heap_sort(arr):
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

def heapify(arr, n, i):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2
    if l < n and arr[l] > arr[largest]:
        largest = l
    if r < n and arr[r] > arr[largest]:
        largest = r
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def counting_sort(arr):
    max_val = max(arr)
    count = [0] * (max_val + 1)
    for num in arr:
        count[num] += 1
    i = 0
    for num in range(max_val + 1):
        while count[num] > 0:
            arr[i] = num
            i += 1
            count[num] -= 1

def leer_archivo(path):
    with open(path, 'r') as archivo:
        datos = archivo.read()
    return list(map(int, datos.split()))

files = [
    "File_100.txt", "File_500.txt", "File_1000.txt", "File_2000.txt",
    "File_3000.txt", "File_4000.txt", "File_5000.txt", "File_6000.txt",
    "File_7000.txt", "File_8000.txt", "File_10000.txt", "File_20000.txt",
    "File_30000.txt", "File_40000.txt", "File_50000.txt", "File_60000.txt",
    "File_70000.txt", "File_80000.txt", "File_100000.txt"
]

algoritmos = [
    (bubble_sort, "Bubble Sort"),
    (selection_sort, "Selection Sort"),
    (insertion_sort, "Insertion Sort"),
    (merge_sort, "Merge Sort"),
    (partial(quick_sort, low=0, high=None), "Quick Sort"),
    (heap_sort, "Heap Sort"),
    (counting_sort, "Counting Sort")
]

for file in files:
    print(f"\n--- Resultados para {file} ---")
    arreglo_original = leer_archivo(file)
    
    for alg, nombre in algoritmos:
        arreglo = arreglo_original.copy()
        print(f"Ejecutando {nombre}...")

        inicio = time.time()

        if nombre == "Quick Sort":
            alg.func(arreglo, 0, len(arreglo) - 1)
        else:
            alg(arreglo)

        fin = time.time()
        print(f"{nombre} completado en {fin - inicio:.6f} segundos")

    print(f"Finalizado el procesamiento para {file}\n")
