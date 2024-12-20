import csv
import matplotlib.pyplot as plt
import numpy as np
import sympy as sp
from sympy import log

filename = "DATA.csv"
X = 12
Y = 8
FROM = 2
TO = 100

def readData(n, T, search):
     with open(filename, "r") as r_file:
        reader = csv.DictReader(r_file, delimiter=";")  # Чтение данных из DATA
        for row in reader:
            
            if(row["search"] == search):
                n.append(int(row["n"]))
                T.append(float(row["T(n)"]))
     
def reg(n, T, col, index):
    # Находим коэффициенты регрессии 2-й степени
    coefficients = np.polyfit(n, T, 2)
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

     




def readData(search, case, n, T):
    with open(filename, "r") as r_file:
        reader = csv.DictReader(r_file, delimiter=";")  # Чтение данных из DATA
        for row in reader:
            if(row["search"] == search and row["case"] == case):
                n.append(int(row["n"]))
                T.append(float(row["T(n)"]))


def plotGraphic(search, case, n, T, filename, index = 1, color = "red"):
    plt.clf()
    plt.figure(figsize=(X, Y))
    plt.xlabel("n")
    plt.ylabel("T(n)")
    n.clear()
    T.clear()
    # Чтение данных из csv файла
    readData(search, case, n, T)
    # Построение точек
    plt.scatter(n, T, label=search)
    #Построение регрессии
    reg(n, T, "red", index)
    plt.legend()
    # Сохранение файла
    plt.savefig(filename)
    plt.close()

def plotAllGraphics(searches, case, n, T, filename, without = None):
    plt.clf()
    plt.figure(figsize=(X, Y))
    plt.xlabel("n")
    plt.ylabel("T(n)")
    n.clear()
    T.clear()
    n1, n2, n3, n4 = [], [], [], []
    T1, T2, T3, T4 = [], [], [], []
    n = [n1, n2, n3, n4]
    T = [T1, T2, T3, T4]
    i = 0
    without_index = -1
    for search in searches:
        if (search == without):
            without_index = i
            i += 1
            continue
        readData(search, case, n[i], T[i])
        i += 1
    colors = ["blue", "orange", "green", "red"]
    for i in range(len(n)):
        if (without_index != -1 and i == without_index):
            continue
        plt.scatter(n[i], T[i], label=searches[i], color = colors[i])
        reg(n[i], T[i], colors[i], i)

    plt.legend()
    # Сохранение файла
    plt.savefig(filename)
    plt.close()

def plotGraphicForAllCases(search, cases, n, T, filename, title):
    plt.clf()
    plt.figure(figsize=(X, Y))
    plt.xlabel("n")
    plt.ylabel("T(n)")
    plt.title(title)
    n.clear()
    T.clear()
    n1, n2, n3, n4, n5 = [], [], [], [], []
    T1, T2, T3, T4, T5 = [], [], [], [], []
    n = [n1, n2, n3, n4, n5]
    T = [T1, T2, T3, T4, T5]
    i = 0
    without_index = -1
    cases_name = ["Worst case", "Search first element", "Search middle element", "Search last element", "Search random element"]
    for case in cases:
        readData(search, case, n[i], T[i])
        i += 1
    colors = ["blue", "orange", "green", "red", "yellow"]
    for i in range(len(n)):
        plt.scatter(n[i], T[i], label=cases_name[i], color = colors[i])
        reg(n[i], T[i], colors[i], i)

    plt.legend()
    # Сохранение файла
    plt.savefig(filename)
    plt.close()



def plotTheorGraphics(n, Tw, Tb, Ta, title, filename):
        p1 = sp.plot(Tw, (n, FROM, TO), title = title, xlabel = "n", ylabel = "T(n)", size = (X, Y), label = 'Worst case', axis_center = "auto", show = False, legend = True)
        p2 = sp.plot(Tb, (n, FROM, TO), title = title, xlabel = "n", ylabel = "T(n)", size = (X, Y), label = 'Best case', axis_center = "auto", show = False, legend = True)
        p3 = sp.plot(Ta, (n, FROM, TO), title = title, xlabel = "n", ylabel = "T(n)", size = (X, Y), label = 'Average case', axis_center = "auto", show = False, legend = True)
        p1.extend(p2)
        p1.extend(p3)
        p1.save(filename)
       

    
        





def graphics():
    #Prac Gr
    searches = ["LS", "BS", "TS", "IS"]
    cases = ["W", "F", "M", "L", "R"]
    n = []
    T = []
    all_n = []
    all_T = []

    #Worst case
    plotGraphic(searches[0], cases[0], n, T, "PracGraphics\Worst case\LS.png")
    plotGraphic(searches[1], cases[0], n, T, "PracGraphics\Worst case\BS.png")
    plotGraphic(searches[2], cases[0], n, T, "PracGraphics\Worst case\TS.png")
    plotGraphic(searches[3], cases[0], n, T, "PracGraphics\Worst case\IS.png")
    #for all
    plotAllGraphics(searches, cases[0], all_n, all_T,"PracGraphics\Worst case\ALL.png")
    plotAllGraphics(searches, cases[0], all_n, all_T,"PracGraphics\Worst case\ALLwoLS.png", without="LS")
    #Search first
    plotGraphic(searches[0], cases[1], n, T, "PracGraphics\First\LS.png")
    plotGraphic(searches[1], cases[1], n, T, "PracGraphics\First\BS.png")
    plotGraphic(searches[2], cases[1], n, T, "PracGraphics\First\TS.png")
    plotGraphic(searches[3], cases[1], n, T, "PracGraphics\First\IS.png")
    #for all
    plotAllGraphics(searches, cases[1], all_n, all_T,"PracGraphics\First\ALL.png")
    #Search middle
    plotGraphic(searches[0], cases[2], n, T, "PracGraphics\Mid\LS.png")
    plotGraphic(searches[1], cases[2], n, T, "PracGraphics\Mid\BS.png")
    plotGraphic(searches[2], cases[2], n, T, "PracGraphics\Mid\TS.png")
    plotGraphic(searches[3], cases[2], n, T, "PracGraphics\Mid\IS.png")
    #for all
    plotAllGraphics(searches, cases[2], all_n, all_T,"PracGraphics\Mid\ALL.png")
    plotAllGraphics(searches, cases[2], all_n, all_T,"PracGraphics\Mid\ALLwoLS.png", without="LS")
    #Search last
    plotGraphic(searches[0], cases[3], n, T, "PracGraphics\Last\LS.png")
    plotGraphic(searches[1], cases[3], n, T, "PracGraphics\Last\BS.png")
    plotGraphic(searches[2], cases[3], n, T, "PracGraphics\Last\TS.png")
    plotGraphic(searches[3], cases[3], n, T, "PracGraphics\Last\IS.png")
    #for all
    plotAllGraphics(searches, cases[3], all_n, all_T,"PracGraphics\Last\ALL.png")
    plotAllGraphics(searches, cases[3], all_n, all_T,"PracGraphics\Last\ALLwoLS.png", without="LS")

    #Search random
    plotGraphic(searches[0], cases[4], n, T, "PracGraphics\Random\LS.png")
    plotGraphic(searches[1], cases[4], n, T, "PracGraphics\Random\BS.png")
    plotGraphic(searches[2], cases[4], n, T, "PracGraphics\Random\TS.png")
    plotGraphic(searches[3], cases[4], n, T, "PracGraphics\Random\IS.png")

    #for all
    plotAllGraphics(searches, cases[4], all_n, all_T,"PracGraphics\Random\ALL.png")
    plotAllGraphics(searches, cases[4], all_n, all_T,"PracGraphics\Random\ALLwoLS.png", without="LS")

    #Everyone for all cases
    plotGraphicForAllCases(searches[0], cases, n, T, "PracGraphics\one for all cases\LS.png", "Linear Search")
    plotGraphicForAllCases(searches[1], cases, n, T, "PracGraphics\one for all cases\BS.png", "Binary Search")
    plotGraphicForAllCases(searches[2], cases, n, T, "PracGraphics\one for all cases\TS.png", "Ternary Search")
    plotGraphicForAllCases(searches[3], cases, n, T, "PracGraphics\one for all cases\IS.png", "Interpolation Search")

    #Theor gr
    n = sp.Symbol("n")

    #LS
    Tw = 3 * n + 3
    Tb = 5
    Ta = 3 + 1.5 * n
    plotTheorGraphics(n, Tw, Tb, Ta, "Linear search", "TheorGraphics\LS.png")
    #BS
    Tw = 4 + 4 * log(n, 2)
    Tb = 6
    Ta = (1 / n) * log(n,2)
    plotTheorGraphics(n, Tw, Tb, Ta, "Binary search", "TheorGraphics\BS.png")
    #TS
    Tw = 2 + 9 * log(n,3)
    Tb = 6
    Ta = log(n, 3)
    plotTheorGraphics(n, Tw, Tb, Ta, "Ternary search", "TheorGraphics\TS.png")
    #IS
    Tw = n
    Tb = 10
    Ta = 8* log(log(n,2), 2) + 7
    plotTheorGraphics(n, Tw, Tb, Ta, "Interpolation search", "TheorGraphics\IS.png")

    



graphics()


