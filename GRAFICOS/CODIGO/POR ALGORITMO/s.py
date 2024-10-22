import matplotlib.pyplot as plt

# Tamaños de archivo
file_sizes = [100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 100000]

# Tiempos de ejecución por lenguaje (extraídos del archivo)
selection_sort_times_python = [0.004154703544769866, 0.020389791747567707, 0.0211579151644527, 0.09265518370432886, 0.051851296933313216, 
                               0.09725873659750436, 0.218187937912507, 0.1977410430914507, 0.27851699005558106, 0.37744834905577085, 
                               0.42160542605182705, 0.6297350996312623, 0.4182212868414985, 0.9379711811592266, 1.3660372921300752, 
                               2.503449951506297, 1.7542917333299926, 3.805224534453365, 2.0215379576474897]

selection_sort_times_java = [0.0015031354737464185, 0.018310099889936635, 0.015712701842515702, 0.053118708039181936, 0.13365291713832383, 
                             0.10979799588023133, 0.12938359669909236, 0.10968894015841822, 0.10338051988680645, 0.21615887038409157, 
                             0.16614568320610934, 0.8358819292777016, 1.114190553633691, 1.7163886074477646, 1.9492819764622817, 
                             1.4997802089509285, 3.4302805640717886, 1.2088759077927167, 3.5235292994628318]

selection_sort_times_cpp = [0.0033517346623367565, 0.01300341430729247, 0.014174536099933289, 0.020677553600508734, 0.09174908809075444, 
                            0.08004974873010678, 0.1556546719270847, 0.21367597963187834, 0.13563658920660915, 0.18541879974920036, 
                            0.39235114586899456, 0.5718887922434764, 1.465221499009761, 0.4979856501024266, 2.2064751252825827, 
                            1.525156432114706, 1.5815248150023686, 2.8770139593611184, 3.2666098691224215]

# Graficar los tiempos de ejecución de Selection Sort en diferentes lenguajes
plt.figure(figsize=(10, 6))

plt.plot(file_sizes, selection_sort_times_python, label="Python", marker='o')
plt.plot(file_sizes, selection_sort_times_java, label="Java", marker='o')
plt.plot(file_sizes, selection_sort_times_cpp, label="C++", marker='o')

plt.xlabel("Tamaño del archivo")
plt.ylabel("Tiempo de ejecución (segundos)")
plt.title("Comparación de tiempos de Selection Sort en Python, Java y C++")
plt.legend()
plt.grid(True)
plt.xscale("log")
plt.yscale("log")

plt.tight_layout()
plt.show()
