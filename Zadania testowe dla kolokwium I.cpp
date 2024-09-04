//Zadanie 1
/*Napisz program, który wczytuje od użytkownika 2 
liczby całkowite r oraz h, które są odpowiednio 
promieniem koła oraz wysokością stożka zbudowanego na tym kole. 
Program ma wypisać na standardowym wyjściu objętość bryły. 
Jeżeli r lub h są mniejsze lub równe 0 wyświetl na standardowym 
wyjściu komunikat “Bledne dane”. (objętość stożka V=PI r^2 h / 3)


#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int r, h;
    cin >> r >> h;
    if(r <= 0 && h <= 0) cout << "Error";
    else cout << (3.14 * pow(r, 2) * h) / 3;
}*/

//Zadanie 2
/*Napisz funkcję, która przyjmuje w argumentach: 
(1) tablicę liczb zmiennoprzecinkowych arr1, 
(2) liczbę całkowitą n - rozmiar tablicy arr1, 
(3) tablicę liczb całkowitych arr2 oraz 
(4) liczbę całkowitą m - rozmiar tablicy arr2. 
Wartości elementów w tablicy arr2 to indeksy dla tablicy arr1. 
Niech funkcja wyświetli wszystkie elementy tablicy arr1 o indeksach, 
których wartości znajdują się w tablicy arr2. Jeżeli w arr1 nie ma 
odpowiedniego indeksu to wyświetla dla niego wartość NAN. 
Zademonstruj użycie tej funkcji w funkcji głównej.
PRZYKŁAD:
IN arr1: 2.3, 3.1, 0.5, 3.4, 5.2
IN arr2: 4, 1, 3, 9, 1
OUT: [4]=5.2, [1]=3.1, [3]=3.4, [9]=NAN, [1]=3.1

#include <iostream>
using namespace std;

void printArr(float arr1[], int n, int arr2[], int m)
{
    for(int i = 0; i < m; i++)
    {
        if(arr2[i] > 0 && arr2[i] < n) cout << arr1[arr2[i]] << " ";
        else cout << "NAN ";
    }
}

int main()
{
    float arr1[] = {2.3, 3.1, 0.5, 3.4, 5.2};
    int arr2[] = {4, 1, 3, 9, 1};
    printArr(arr1, 5, arr2, 5);
    return 0;
}*/

//Zadanie 3
/*Napisz funkcję, która przyjmuje w argumencie liczbę całkowitą 
(bez znaku, mniejszą niż 65536) w postaci napisu. 
Funkcja ma dokonać konwersji tego napisu do liczby całkowitej 
i zwrócić jej wartość. Zademonstruj użycie tej funkcji w funkcji głównej.
PRZYKŁAD:
IN: "1234"
OUT: 1234

#include <iostream>
using namespace std;

unsigned short convertToShort(string str)
{
    unsigned short result = 0;
    for(int i = 0; i < str.length(); i++)
    {
        result = (result + (str[i] - '0')) * 10;
    }
    return result / 10;
}

int main()
{
    cout << convertToShort("2234");
    return 0;
}*/

//Zadanie 4
/*Napisz funkcję rekurencyjną, która zamienia liczbę binarną, 
reprezentowaną za pomocą napisu, na liczbę całkowitą. Zademonstruj jej użycie.
PRZYKŁAD:
IN: "10010011"
OUT: 147

#include <iostream>
#include <cmath>
using namespace std;

int convertToInt(string str)
{
    if(str.length() == 0) return 0;
    return (str[0] - '0') * pow(2, str.length() - 1) + convertToInt(str.substr(1));
}

int main()
{
    cout << convertToInt("10010011");
    return 0;
}*/

//Zadanie 5
/*Napisz program, który wczytuje od użytkownika liczbę całkowitą n 
(zakładamy, że n<20). Utwórz tablicę liczb zmiennoprzecinkowych arr, 
która będzie w stanie pomieścić n liczb, a następnie wczytaj do niej 
n wartości ze standardowego wejścia. Napisz funkcję, która przyjmuje 
taką tablicę w argumencie. Funkcja ma wyświetlić na standardowym 
wyjściu kolejne wyrazy ciągu od 1 do n zdefiniowanego wzorem:
F(0) = 0
F(n) = (-1)^n * arr_{n-1} + F_{n-1}
gdzie: ^ - operacja potęgowania
PRZYKŁAD:
IN n: 3
IN a: 0.4, 0.2, 1.4
OUT: -0.4, -0.2, -1.6



#include <iostream>
#include <cmath>
using namespace std;

float F(int n, float arr[])
{
    if(n == 0) return 0;
    return pow(-1, n) * arr[n - 1] + F(n - 1, arr);
}

void printArr(float arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << F(i + 1, arr) << " ";
    }
}


int main()
{
    int n = 3;
    float arr[] = {0.4, 0.2, 1.4};
    printArr(arr, n);
}*/

//Zadanie 6
/*Zaprojektuj i zdefiniuj funkcję dyadic(), która oblicza 
i zwraca iloczyn diadyczny dwóch wektorów 3-elementowych 
przekazanych w argumentach. Do reprezentacji wektorów i 
macierzy użyj tablic automatycznych. W funkcji głównej 
pokaż użycie tej funkcji. Iloczyn diadyczny dwóch wektorów 
n-wymiarowych daje w wyniku macierz nxn-wymiarową 
(zob. https://pl.wikipedia.org/wiki/Iloczyn_diadyczny)

#include <iostream>

using namespace std;

void dydiac(int a[], int b[], int** result)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            result[i][j] = a[i] * b[j];
        }
    }
}

int main()
{
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int** result = new int*[3];
    for(int i = 0; i < 3; i++)
    {
        result[i] = new int[3];
    }
    dydiac(a, b, result);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < 3; i++)
    {
        delete[] result[i];
    }
    delete[] result;
    return 0;
}*/

//Zadanie 7
/*Zdefiniuj funkcję seq(), która w argumencie otrzymuje 
nieujemną liczbę całkowitą n. Funkcja powinna zwracać, jako 
liczbę rzeczywistą, wartość elementu o indeksie n ciągu zdefiniowanego w następujący sposób:
a_{0}=0, a_{1}=1
a_{n} = a_{n-1} * pierwiastek(a_{n-2})
Napisz program, który sprawdzi działanie tej funkcji. 
Program powinien wylosować liczbę n z przedziału obustronnie 
domkniętego <0;100>, a następnie wyświetlić wynik funkcji seq() dla wylosowanej liczby.

typedef unsigned int pidar;
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using  namespace std;

double seq(pidar n)
{
    if(n == 0 ) return 0;
    if(n == 1) return 1;
    return seq(n - 1) * sqrt(seq(n - 2));
}

int main()
{
    srand(time(NULL));
    pidar n;
    n = rand()%11;
    cout << seq(n) << endl;
}*/