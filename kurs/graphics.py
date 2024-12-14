import csv
import matplotlib.pyplot as plt
import numpy as np

filename = "DATA.csv"
X = 12
Y = 8

def readData(n, h, tree):
     with open(filename, "r") as r_file:
        reader = csv.DictReader(r_file, delimiter=";")  # Чтение данных из DATA
        for row in reader:
            
            if(row["search"] == tree):
                n.append(int(row["n"]))
                h.append(float(row["T(n)"]))
     
def pracGraphics():
    plt.figure(figsize=(X, Y))
    #LS
    # Подпись осей
    plt.xlabel("n")
    plt.ylabel("T(n)")

    
    n, h = [], []
    # Чтение данных из csv файла
    readData(n, h, "LS")
    # Построение точек
    plt.scatter(n, h, label="Linear Search")
    #Построение регрессии
    reg(n, h, "red", 1)
    plt.legend()
    # Сохранение файла
    plt.savefig("PracGraphics\LS.png")
    #BS
    plt.clf()
    plt.xlabel("n")
    plt.ylabel("T(n)")
    n.clear()
    h.clear()
    readData(n, h, "BS")
    plt.scatter(n, h, label="Binary Search")
    reg(n, h, "red", 1)
    plt.legend()
    plt.savefig("PracGraphics\BS.png")
    #TS
    plt.clf()
    plt.xlabel("n")
    plt.ylabel("T(n)")
    n, h = [], []
    readData(n, h, "TS")
    plt.scatter(n, h, label="Ternary Search")
    reg(n, h, "red", 1)
    plt.legend()
    plt.savefig("PracGraphics\TS.png")
    #IS
    plt.clf()
    plt.xlabel("n")
    plt.ylabel("T(n)")
    n, h = [], []
    readData(n, h, "IS")
    plt.scatter(n, h, label="Interpolation Search")
    reg(n, h, "red", 1)
    plt.legend()
    plt.savefig("PracGraphics\IS.png")
    # #ALL
    plt.clf()
    plt.xlabel("n")
    plt.ylabel("T(n)")
    n1, n2, n3, n4, h1, h2, h3, h4 = [], [], [], [], [], [], [], []
    readData(n1, h1, "LS")
    readData(n2, h2, "BS")
    readData(n3, h3, "TS")
    readData(n4, h4, "IS")
    #plt.scatter(n1, h1, label="LS")
    #reg(n1, h1, "blue", 1)
    plt.scatter(n2, h2, label="BS")
    reg(n2, h2, "blue", 2)
    plt.scatter(n3, h3, label="TS")
    reg(n3, h3, "orange", 3)
    plt.scatter(n4, h4, label="IS")
    reg(n4, h4, "green", 3)
    plt.legend()
    plt.savefig("PracGraphics\ALL.png")

def reg(n, h, col, index):
    # Находим коэффициенты регрессии 2-й степени
    coefficients = np.polyfit(n, h, 2)
    polynomial_regression = np.poly1d(coefficients)


    # Генерация значений для кривой регрессии
    x_reg = np.linspace(min(n), max(n), 100)
    y_reg = polynomial_regression(x_reg)

    # Построение кривой регрессии
    plt.plot(x_reg, y_reg, color=col)


    a, b, c = coefficients
    

    # Сдвиг уравнения
    plt.text(0.95,  0.2 - 0.05 * index, f"y = ({a:.2e})n^2 + ({b:.2e})n + ({c:.2e})", transform=plt.gca().transAxes,
             fontsize=10, color=col, ha='right', va='top')

     


pracGraphics()


