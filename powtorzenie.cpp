//Zadanie 1
/*Napisz funkcję, która przyjmie jako argument dwuwymiarową tablicę 
liczb zmiennoprzecinkowych (macierz) oraz jej wymiary. 
Funkcja powinna tak zmodyfikować tą tablicę, aby w każdym 
polu znalazła się średnia arytmetyczna wartości w nim samym 
oraz polach sąsiednich: górnym, dolnym, lewym i prawym. 
Jeżeli pole znajduje się na krawędzi tablicy, należy policzyć 
średnią z istniejących sąsiadów. Napisz program, który przetestuje 
działanie tej funkcji, wypełniając tablicę losowymi wartościami. 
Jak zmodyfikować ten program, żeby posługiwać się tablicą 
jednowymiarową, przy zachowaniu idei, że dane reprezentują macierz?

#include <iostream>
#include <cstdlib>

using namespace std;

void average(double** arr, const int n, const int m)
{
    double tmp[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            double left = 0, right = 0, top = 0, down = 0;
            int count = 1;
            if(j - 1 >= 0){ left = arr[i][j - 1]; count++; }
            if(j + 1 < m){ right = arr[i][j + 1]; count++; }
            if(i - 1 >= 0){ top = arr[i - 1][j]; count++; }
            if(i + 1 < n){ down = arr[i + 1][j]; count++; }

            tmp[i][j] = (double)((arr[i][j] + left + right + top + down) / count);
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            arr[i][j] = tmp[i][j];
}


int main()
{
    int n = 5, m = 4;
    double** mat = new double*[n];
    for(int i = 0; i < n; i++)
    {
        mat[i] = new double[m];
        for(int j = 0; j < m; j++)
        {
            mat[i][j] = (double)(rand()  % 101) / 10.0;
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "-------------------------------------" << endl;
    average(mat, n, m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    for(int i = 0; i < n; i++)
        delete[] mat[i];
    delete[] mat;
}*/

//Zadanie 2
/*Napisz funkcję, która przyjmuje w argumencie 
dodatnią liczbę całkowitą i wyświetla jej binarną reprezentację.

#include <iostream>
using namespace std;

void printBinary(int num)
{
    if (num == 0) return;
    
    printBinary(num / 2);
    std::cout << num % 2;
}

int main()
{
    int num = 128;
    printBinary(num);
    std::cout << endl;
    return 0;
}*/

//Zadanie 3
/*Napisz funkcję, która przyjmuje w argumencie liczbę całkowitą dodatnią 
x i liczbę naturalną n, a następnie zwraca wartość bitu na n-tej pozycji liczby x.

#include <iostream>
using namespace std;

int getbit(int x, int n)
{
    return (x >> n) & 1;
}

int main()
{
    int x = 128, n = 7;
    cout << getbit(x, n) << endl;
}*/

//Zadanie 4
/*Napisz funkcję, która przyjmujew argumencie liczbę 
całkowitą dodatnią x oraz liczbę naturalną n, a następnie 
ustawia n-ty bit liczby x na 1. Napisz drugą podobną funkcję, 
która wyłącza wybrany bit w liczbie x. Napisz trzecią funkcję, 
która ustawia wskazany bit na przeciwny.

#include <iostream>
using namespace std;

int setbit(int x, int n)
{
    return x | (1 << n);
}

int offbit(int x, int n)
{
    return x & ~(1 << n);
}

int togglebit(int x, int n)
{
    return x ^ (1 << n);
}

int main()
{
    int x = 192, n = 5;
    cout << setbit(x, n) << endl;
    cout << offbit(x, n) << endl;
    cout << togglebit(x, n) << endl;

}*/

//Zadanie 5
/*Napisz program, który sprawdzi parzystość liczby 
wczytanej od użytkownika bez użycia operacji 
dzielenia modulo. Program powinien wyświetlić 1, 
jeśli liczba jest parzysta lub 0 w przeciwnym wypadku. 

#include <iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;
    cout << (x & 1 ? 0 : 1) << endl; //sprawdzenie ostatniego bitu (0 - parzysta, 1 - nieparzysta
    return 0;
}*/

//Zadanie 6
/*Napisz program sprawdzający, czy liczba wczytana 
od użytkownika jest potęgą dwójki. Program powinien 
wyświetlić 1, jeśli liczba jest potęgą dwójki lub 0 w przeciwnym wypadku.

#include <iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;
    cout << (x & (x - 1) ? 0 : 1) << endl; //sprawdzenie czy liczba jest potęgą dwójki
    return 0;
}*/

//Zadanie 7
/*Napisz funkcję, która przyjmuje w 
argumencie napis będący liczbą binarną 
i wyświetla jej wartość dziesiętną. 

#include <iostream>
#include <cmath>

using namespace std;

int binToDec(string num)
{
    int tmp = 0;
    for(int i = 0; i < num.length(); i++)
    {
        tmp += (num[i] == '1') ? pow(2, num.length() - i - 1) : 0;
    }
    return tmp;
}

int main()
{
    string num_bin = "10000000";

    int number = binToDec(num_bin);
    cout << number << endl;

}*/

//Zadanie 8
/*Napisz program, który wczytuje od użytkownika 
dwie liczby całkowite a i b w formacie 'A=a B=b'. 
Program powinien wypisać wartość liczby 'a' po 
przesunięciu bitowym w lewo i w prawo o 'b' w dwóch 
oddzielnych liniach. Użyj tylko jednego wywołania funkcji printf. 

#include <iostream>

using namespace std;

int main()
{
    int a, b;
    scanf("A=%d B=%d", &a, &b);
    printf("After left shift: %d\n After right shift: %d\n", a << b, a >> b);
}*/

//Zadanie 9
/*Napisz program, który zamienia wartościami 
dwie zmienne całkowite i nie używa do tego 
dodatkowej zmiennej. Wykorzystaj do tego operacje bitowe. 

#include <iostream>
using namespace std;

int main()
{
    int a = 5, b = 10;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << "a = " << a << " b = " << b;
}*/

//Zadanie 10
/*Napisz program, który wczyta dwie całkowite wartości 
określające początek i koniec obustronnie domkniętego 
przedziału , a następnie wyświetli wszystkie liczby pierwsze w tym przedziale. 

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num)
{
    if (num <= 1) return false;
    for(int i = 2; i <= sqrt(num);i++)
    {
        if (num % i == 0) return false;
    }
    return true;
}

int main()
{
    int a = 3, b = 63;
    for(int i = a; i <= b; i++)
    {
        if(isPrime(i))
            cout << "i = " << i << endl;
    }
}*/

//Zadanie 11
/*Napisz funkcję, która przyjmuje jako 
argumenty dziesięcio-elementową automatyczną 
tablicę liczb rzeczywistych oraz jej rozmiar. 
Funkcja powinna zwrócić true, jeśli tablica 
czytana od końca wygląda tak samo, ta tablica 
czytana od początku, bądź false w przeciwnym wypadku. 
Napisz program, który przetestuje działanie tej funkcji, 
wczytując od użytkownika 10 wartości wprowadzonych do tablicy.

#include <iostream>
using namespace std;

bool isIden(double* arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] != arr[size - i - 1]) return false;
    }
    return true;
}

int main()
{
    double arr[10];
    cout << "Enter 10 numbers: ";
    for(int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    if(isIden(arr, 10))
        cout << "true";
    else
        cout << "false";

} */

//Zadanie 12
/*Napisz funkcję, która dla otrzymanej w argumencie nieujemnej liczby 
całkowitej n zwróci kolejne wyrazy ciągu zdefiniowanego w następujący sposób: 
a0 = a1 = 1
an = a(n−1) + 2 * a(n−2) + 3 dla n > 1. 

#include <iostream>
using namespace std;

int sequence(unsigned int n)
{
    if(n == 0 || n == 1) return 1;
    return sequence(n - 1) + 2 * sequence(n - 2) + 3;
}

int main()
{
    unsigned int n = 10;
    cout << sequence(n) << endl;
}
*/

//Zadanie 13
/*Napisz program, który stworzy 15 elementową tablicę 
dowolnych wartości rzeczywistych. Następnie program, 
który wczyta od użytkownika 5 liczb całkowitych, będących 
indeksami wcześniej stworzonej tablicy. Program powinien 
wyświetlić elementy tablicy o wskazanych przez użytkownika 
indeksach i zapewnić odpowiedni komunikat, jeśli indeks wykracza 
poza rozmiar tablicy. Zastanów się nad bardziej uniwersalnym rozwiązaniem takiego zadania. 

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(NULL));
    double arr[15];
    for(int i = 0; i < 15; i++)
        arr[i] = ((double)(rand()%101) / 100);

    int arr1[5];
    for(int i = 0; i < 5; i++)
        cin >> arr1[i];

    for(int i = 0; i < 5; i++)
    {
        if(arr1[i] < 0 || arr1[i] >= 15){
            
            cout << "Error index of array";
            continue;
        }
        cout << fixed << setprecision(2) << arr[arr1[i]] << " ";
    }
}*/

//Zadanie 14
/*Zadeklaruj funkcję, która przyjmuje w argumencie automatyczną 
tablicę liczb całkowitych, jej rozmiar jako wartość całkowita 
bez znaku oraz zmienną typu bool. Funkcja powinna zwrócić 
wartość pierwszego powtarzającego się elementu w tablicy, 
tylko wtedy gdy wartość zmiennej typu bool ma wartość logiczną true. 
Jeśli tablica składa się tylko z unikalnych wartości to funkcja powinna zwrócić 0. 

#include <iostream>
#include <set>
using namespace std;

int uniqueElement(int arr[], unsigned int n, bool value)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i != j && value && arr[i] == arr[j])
            {
                return arr[i];
            }

        }
    }
    return 0;
}


int main()
{
    unsigned int n = 10;
    int arr[n];
    for(int i = 0; i < n; i++)
        arr[i] = rand()%10;

    int result = uniqueElement(arr, n, true);
    cout << result;

}*/

//Zadanie 15
/*Napisz funkcję rekurencyjną, która dla otrzymanej w 
argumencie nieujemnej liczby całkowitej n zwraca wartość 
elementu o indeksie n ciągu zdefiniowanego w następujący sposób:
a0 = a1 = 1
an = a(n-1) + n dla n parzystych,
an = a(n-1) * n dla n nieparzystych.

#include <iostream>
using namespace std;

unsigned int funrec(unsigned int n)
{
    if(n == 0 || n == 1) return 1;
    if(n % 2 == 0)
        return funrec(n - 1) + n;
    else   
        return funrec(n - 1) * n;
}

int main()
{
    cout << funrec(86) << endl;
}*/

//Zadanie 16
/*Pewna obojnacza populacja rozwija się w taki sposób, że na wiosnę wszystkie 
osobniki łączą się w pary, a każda para ma jedno młode. W lecie liczebność 
nie zmienia się. Przez jesień populacja pozbywa się dziesięciu najsłabszych osobników. 
Zimę przeżywa 60% populacji. Napisz funkcję rekurencyjną, która przyjmie początkową 
liczebność populacji oraz rok i porę roku (wiosna - 0, ..., zima - 3). Funkcja powinna 
zwrócić liczebność populacji w podanym roku, po zakończeniu podanej pory roku. Zakładamy, 
że początkowa liczebność jest odczytana w roku 0, na początku wiosny. Jeżeli pośrednim lub 
ostatecznym wynikiem będzie liczba niecałkowita, zaokrąglamy wynik na niekorzyść populacji. 
Dodatkowo napisz program, który sprawdzi działanie funkcji. 

#include <iostream>
#include <cmath>
using namespace std;

int population(int n, int year, int season)
{
    if(year == 0 && season == 0) return n;
    if(year == 0) return n;
    if(season == 0) return population(n + n / 2, year, season + 1);
    if(season == 1) return population(n, year, season + 1);
    if(season == 2) return population(n - 10, year, season + 1);
    if(season == 3) return population(n * 0.6, year - 1, 0);
}


int main()
{
    cout << population(100000, 10, 3) << endl;
}*/

//Zadanie 17
/*Napisz program, rysujący trójkąt ze znaków.

#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i; j++)
            cout << " ";
        for(int j = 0; j < 2 * i + 1; j++)
            cout << "*";
        cout << endl;
    }
}*/

//Zadanie 18
/*Napisz funkcję, która generuje szum Gaussowski. 
Funkcja powinna przyjmować dwie liczby rzeczywiste mean 
(średnią) i sigma (wariancję). Użyj metody polarnej Marsaglia. 

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

double gaussNoise(double mean, double sigma)
{
    double u1, u2, w, mult;
    double x, y;
    double result;
    do
    {
        u1 = -1 + ((double)rand() / RAND_MAX) * 2;
        u2 = -1 + ((double)rand() / RAND_MAX) * 2;
        w = pow(u1, 2) + pow(u2, 2);
    } while (w >= 1 || w == 0);
    mult = sqrt((-2 * log(w)) / w);
    x = u1 * mult;
    y = u2 * mult;
    result = x * sigma + mean;
    return result;
}

int main()
{
    srand(time(NULL));
    double mean = 0, sigma = 1;
    cout << gaussNoise(mean, sigma) << endl;
    return 0;
}*/
