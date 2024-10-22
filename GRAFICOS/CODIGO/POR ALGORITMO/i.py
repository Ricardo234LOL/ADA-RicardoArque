import matplotlib.pyplot as plt

# Tamaños de archivo
file_sizes = [100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 100000]

# Tiempos de ejecución por lenguaje (extraídos del archivo)
insertion_sort_times_python = [1.3818042900740581, 50.37011331569334, 394.2679525870843, 1191.6376643931928, 4482.020941494775, 
                               2190.8634083731404, 8835.05359271998, 10119.603198927063, 16329.765377463647, 22649.180476981626, 
                               28906.158767796154, 44079.153741093105, 196907.05137293276, 620852.5508176095, 945739.7617712, 
                               1713748.4021631416, 1395227.7650682605, 1037995.4323577039, 2441146.447557687]

insertion_sort_times_java = [1.122739650101051, 119.59422713368625, 409.99102140277654, 1242.9446573136222, 3902.7068977619024, 
                             2751.628672798996, 11259.677517757294, 9488.720192693143, 24120.526098363192, 17894.628476727463, 
                             35043.12273846534, 185314.13292135793, 100446.24758588252, 358877.88670343225, 450455.0207418501, 
                             1466510.964739018, 537158.4467752783, 1419233.6425519062, 2534066.591968928]

insertion_sort_times_cpp = [4.405223564964339, 97.14481543207357, 417.4240495022749, 1170.5369498619827, 4215.570959787019, 
                            5315.213372811265, 4851.132530208499, 14458.329753282143, 5477.255482444828, 8166.631992291087, 
                            46989.324857817504, 186507.47785082276, 385505.35076358356, 631418.1232955682, 1184206.5304704483, 
                            1006245.9806178012, 1988075.488530068, 2757901.6769084474, 1448720.317027692]

# Graficar los tiempos de ejecución de Insertion Sort en diferentes lenguajes
plt.figure(figsize=(10, 6))

plt.plot(file_sizes, insertion_sort_times_python, label="Python", marker='o')
plt.plot(file_sizes, insertion_sort_times_java, label="Java", marker='o')
plt.plot(file_sizes, insertion_sort_times_cpp, label="C++", marker='o')

plt.xlabel("Tamaño del archivo")
plt.ylabel("Tiempo de ejecución (segundos)")
plt.title("Comparación de tiempos de Insertion Sort en Python, Java y C++")
plt.legend()
plt.grid(True)
plt.xscale("log")
plt.yscale("log")

plt.tight_layout()
plt.show()
