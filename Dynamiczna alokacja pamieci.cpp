// Zadanie 1
/*Napisz funkcję, która przyjmuje jako argumenty wskaźniki do dwóch zmiennych typu int.
Funkcja powinna zwrócić wskaźnik do mniejszej wartości z liczb wskazywanych przez argumenty,
jeśli argumenty mają taką samą wartość funkcja powinna zwracać wskaźnik na pierwszy argument.

#include <iostream>

int* minValue(int* number_1, int* number_2){
    if(*number_1 > *number_2)
        return number_2;
    else if (*number_1 < *number_2)
        return number_1;
    else if (*number_1 == *number_2)
        return number_1;
}

int main(){
    int a, b;
    std::cin >> a >> b;
    std::cout << minValue(&a, &b);
    std::cout << std::endl << *minValue(&a, &b);
}
*/

// Zadanie 2
/*Napisz program, który wczyta od użytkownika liczbę całkowitą n,
a następnie dynamicznie zaalokuje pamięć dla n elementowej
tablicy liczb całkowitych. Program powinien wypełnić tablicę
dowolnymi wartościami, a następnie wyświetlić wszystkie
elementy tej tablicy. Na końcu programu zwolnij zaalokowaną pamięć.


#include <iostream>
#include <algorithm>
#include <numeric>
#include <random>
#include <chrono>

void print(int &x){
    std::cout << x << " ";
}

int main()
{
    int n;
    int init = 0;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    std::cout << std::endl << "init1 = " << std::accumulate(arr, arr+n, init) << std::endl;
    for(int i = 0; i <n ; i++)
        std::cout << arr[i] << " ";
    int sum = std::accumulate(arr, arr+n, init);
    std::cout << std::endl << "init2 = " << sum << std::endl;

    std::shuffle(arr, arr+n, std::default_random_engine(seed));

    for(int i = 0; i <n ; i++)
        std::cout << arr[i] << " ";

    std::cout << std::endl;

    std::for_each(arr, arr+n, print);

    delete[] arr;
}*/

// Zadanie 3
/*Napisz program, który wczyta od użytkownika
nieujemną liczbę całkowitą n,
a następnie dynamicznie zaalokuje
pamięć dla n elementowej tablicy liczb rzeczywistych.
Program powinien wypełnić tablicę zerami i wyświetlić
wszystkie elementy tej tablicy.
Następnie program powinien zmienić
rozmiar tablicy na 10 i wypełnić ją jedynkami.


#include <iostream>
#include <algorithm>

void scanner1(double& x){
    x = 0;
}
void print(double x){
    std::cout << x << " ";
}
void scanner2(double& x){
    x = 1;
}
int main()
{
    unsigned int n;
    std::cin >> n;
    double* arr = new double[n];

    std::for_each(arr, arr+n, scanner1);
    std::for_each(arr, arr+n, print);
    std::cout << std::endl;

    delete[] arr;

    n = 10;
    arr = new double[n];

    std::for_each(arr, arr + n, scanner2);
    std::for_each(arr, arr + n, print);

    delete[] arr;
}*/

// Zadanie 4
/*Napisz funkcję, która przyjmie
jako argumenty tablicę wartości
zmiennoprzecinkowych, jej rozmiar,
dwie wartości zmiennoprzecinkowe - minimum i maksimum,
oraz wskaźnik n_out ustawiony na zmienną typu całkowitego.
Funkcja powinna zaalokować i zwrócić tablicę,
w której znajdą się liczby z lewostronnie domkniętego
przedziału od minimum do maksimum.
Pod wartością wskaźnika n_out z argumentu należy zapisać rozmiar nowoutworzonej tablicy.

#include <iostream>
#include <algorithm>

void print(double x){
    std::cout << x << " ";
}

double* rangeNumbers(double arr[], int n, double minNumber, double maxNumber, int* n_out){
    *n_out = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] >= minNumber && arr[i] < maxNumber){
            (*n_out)++;
        }
    }

    double* arr2 = new double[*n_out];
    int j = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] >= minNumber && arr[i] < maxNumber){
            arr2[j++] = arr[i];
        }
    }

    std::for_each(arr2, arr2 + *n_out, print);
    std::cout << std::endl << "n_out " << *n_out;
    return arr2;

}

int main (){
    int n = 6, n_out;
    double arr[n] = {1.2, 2.4, 3.7, 3.2, 7.5, 8.5};
    double minNumber = 3.2, maxNumber = 6.4;

    double* result_arr = rangeNumbers(arr, n, minNumber, maxNumber, &n_out);
    delete[] result_arr;
}*/

// Zadanie 5
/*Napisz program, który wczytuje od użytkownika liczbę całkowitą
n i dynamicznie alokuje pamięć dla n-elementowej tablicy
liczb zmiennoprzecinkowych. Napisz funkcję rand_gen(),
która uzupełni tą tablicę dowolnymi wartościami oraz funkcję seq(),
która przyjmuje rozmiar tablicy oraz tablicę liczb zmiennoprzecinkowych.
Funkcja seq() ma wyświetlić na standardowym wyjściu kolejne wyrazy ciągu od 1 do n zdefiniowanego wzorem:
F0 = 0
Fn = (-1)^n * arr[n-1]+Fn-1, n>0

#include <iostream>
#include <cstdlib>
#include <cmath>

void rand_gen(double arr[], int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        arr[i] = rand()%100;
    }
}

double seq(double arr[], int n){
    if (n == 0) {
        return 0;
    }

    double Fn_minus_1 = seq(arr, n - 1);
    double Fn = pow(-1, n) * arr[n - 1] + Fn_minus_1;

    std::cout << Fn << " ";
    return Fn;
}

int main()
{
    int n;
    std::cin >> n;
    double* arr = new double[n];
    rand_gen(arr, n);
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    seq(arr, n);


    delete[] arr;
}*/

// Zadanie 6
/*Napisz funkcję, która przyjmuje
w argumentach: tablicę liczb zmiennoprzecinkowych arr1,
rozmiar tablicy arr1, tablicę liczb całkowitych arr2
oraz rozmiar tablicy arr2. Wartości elementów w tablicy
arr2 to indeksy dla tablicy arr1. Niech funkcja wyświetli
wszystkie elementy tablicy arr1 o indeksach, których wartości
znajdują się w tablicy arr2. Jeżeli w arr1 nie ma odpowiedniego
indeksu to wyświetla dla niego wartość NAN. Napisz program,
który dynamicznie zaalokuje pamięć dla obu tablic, a następnie
arr1 wypełni dowolnymi wartościami, zaś wartości tablicy arr2 wczyta od użytkownika.


#include <iostream>
#include <cstdlib>
#include <algorithm>

template <typename T>
void print(T& x){
    std::cout << x << " ";
}

void indexToIndex(double arr1[], int n, int arr2[], int m){
    for (int i = 0; i < m; i++){
        if (arr2[i] <= n){
            std::cout << arr1[arr2[i]] << " ";
        }
        else std::cout << "NAN ";
    }
}

int main(){
    srand(time(NULL));
    int n, m;
    std::cin >> n >> m;

    double* arr1 = new double[n];
    int* arr2 = new int[m];

    for(int i = 0; i < n; i++)
        arr1[i] = (double))(rand()) / RAND_MAX * 100.0;

    for (int i = 0; i < m; i++)
        std::cin >> arr2[i];

    std::for_each(arr1, arr1+n, print<double>);
    std::cout << std::endl;
    std::for_each(arr2, arr2+m, print<int>);
    std::cout << std::endl;
    indexToIndex(arr1, n, arr2, m);

    delete[] arr1;
    delete[] arr2;
}*/

// Zadanie 7
/*Napisz uniwersalną funkcję swap() zamieniającą
wartości dwóch zmiennych dowolnego typu oraz program,
który sprawdzi jej działanie dla różnych typów
zmiennych. Użyj odpowiedniego rzutowania wkaźników i typu (void*).

#include <iostream>

void my_memcpy(void *dst, void *src, size_t n) {
    char *csrc = (char *)src;
    char *cdst = (char *)dst;
    for(size_t i = 0; i < n; ++i)
        cdst[i] = csrc[i];
}

void my_swap(void *a, void *b, size_t size) {
    char *tmp = new char[size];
    my_memcpy(tmp, b, size);
    my_memcpy(b, a, size);
    my_memcpy(a, tmp, size);
    delete[] tmp;
}

int main(){
    int a = 15, b = 2;
    double a_d = 15.00, b_d = 2.00;
    char a_c = 'A', b_c = 'Z';

    my_swap(&a, &b, sizeof(int));
    std::cout << "a = " << a << " b = " << b << std::endl;

    my_swap(&a_d, &b_d, sizeof(double));
    std::cout << "a = " << a_d << " b = " << b_d << std::endl;

    my_swap(&a_c, &b_c, sizeof(char));
    std::cout << "a = " << a_c << " b = " << b_c << std::endl;

}*/

// Zadanie 8
/*Napisz funkcję print2d(), która wyświetli wartości
automatycznej tablicy dwuwymiarowej, bez względu
na wielkość tej tablicy. W programie głównym stwórz
przykładowe dwuwymiarowe tablice i wyświetl ich
wartości za pomocą funkcji print2d(). Skorzystaj
z umiejętnego rzutowania wskaźników w celu przekazania
tablicy do funkcji. Jakich jeszcze parametrów będzie ta funkcja potrzebowała?

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// VladickPidarInc....

void print2d(vector<vector<int>>::iterator begin, vector<vector<int>>::iterator end)
{
    for (; begin < end; begin++)
    {
        for (vector<int>::iterator jj = (*begin).begin(); jj < (*begin).end(); jj++)
        {
            cout << *jj << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> VladickPidar = {{1, 2, 3, 4, 5, 6, 7}, {1, 2, 3, 4, 5, 6}};
    vector<vector<int>>::iterator pierwszyPidoras = VladickPidar.begin();
    vector<vector<int>>::iterator ostatniPidor = VladickPidar.end();

    print2d(pierwszyPidoras, ostatniPidor);
    VladickPidar.clear();
}

#include <iostream>

// Функція для виведення двовимірного масиву
void print2d(int** array, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    int** exampleArray = new int*[n];
    for (int i = 0; i < n; ++i)
    {
        exampleArray[i] = new int[m];
        for (int j = 0; j < m; ++j)
        {
            exampleArray[i][j] = i * m + j + 1;
        }
    }
    print2d(exampleArray, n, m);

    for (int i = 0; i < n; ++i)
    {
        delete[] exampleArray[i];
    }
    delete[] exampleArray;

    return 0;
}*/

//Zadanie 9
/*Napisz program, który wczytuje od użytkownika dwie liczby 
całkowite n i m, a następnie dynamicznie alokuje pamięć dla 
n-elementowej tablicy liczb całkowitych. W kolejnym kroku 
program powinien uzupełnić tablicę losowymi wartościami z 
przedziału <-50;50> i je posortować. Na koniec program powinien 
znaleźć wszystkie pary liczb całkowitych, których suma jest 
równa liczbie m, wyświetlić je i podać ich ilość.

#include <iostream>
#include <cstdlib>


void inputRandom(int arr1[], int n)
{
    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        arr1[i] = rand()% 101 - 50;
    }
}

void swap(int &a, int &b)
{
    int tmp = 0;
    tmp = a;
    a = b;
    b = tmp;
}

void sortNumbers(int arr1[], int n)
{
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr1[j] > arr1[j + 1])
                swap(arr1[j], arr1[j + 1]);
        }
    }
}



int main()
{
    int n, m;
    std::cin >> n >> m;

    int* arr1 = new int(n);
    inputRandom(arr1, n);
    sortNumbers(arr1, n);

    int counter = 0;

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++){
            if(arr1[i] + arr1[j] == m){
                counter++;
                std::cout << "(" << arr1[i] << ", " << arr1[j] << ") ";
            }
        }
    }

    std::cout << std::endl;
    std::cout << "Ilość par: " << counter << std::endl;
    
    delete[] arr1;
}*/

//Zadanie 10
/*Napisz program, który wczytuje od użytkownika 
trzy liczby całkowite n, m, o, a następnie 
dynamicznie alokuje pamięć dla n-elementowej, 
m-elementowej i o-elementowej tablicy liczb całkowitych. 
W kolejnym kroku program powinien uzupełnić tablice 
losowymi wartościami z przedziału <0;5> i je posortować. 
Na koniec z tak posotowanych tablic algorytm powinien 
wypisać elementy powtarzające się we wszystkich tablicach.


#include <iostream>

void inputRandom(int arr1[], int n)
{
    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        arr1[i] = rand()% 6;
    }
}
void swap(int &a, int &b)
{
    int tmp = 0;
    tmp = a;
    a = b;
    b = tmp;
}

void sortNumbers(int arr1[], int n)
{
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr1[j] > arr1[j + 1])
                swap(arr1[j], arr1[j + 1]);
        }
    }
}
void printCommonElements(int arr1[], int arr2[], int arr3[], int size1, int size2, int size3) {
    int i = 0, j = 0, k = 0;

    std::cout << "Elements common to all arrays: ";
    while (i < size1 && j < size2 && k < size3) {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            std::cout << arr1[i] << " ";
            i++;
            j++;
            k++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr2[j] < arr3[k]) {
            j++;
        } else {
            k++;
        }
    }
    std::cout << std::endl;
}

int main()
{
    int n , m, o;
    std::cin >> n >> m >> o;

    int* arr_n = new int(n);
    int* arr_m = new int(m);
    int* arr_o = new int(o);

    inputRandom(arr_n, n);
    inputRandom(arr_m, m);
    inputRandom(arr_o, o);

    sortNumbers(arr_n, n);
    sortNumbers(arr_m, m);
    sortNumbers(arr_o, o);

    printCommonElements(arr_n, arr_m, arr_o, n, m, o);

    delete[] arr_n;
    delete[] arr_m;
    delete[] arr_o;
}*/

//Zadanie 11.
/*Napisz funkcję, która wykona operację zmiany rozmiaru (realokacji) 
przekazanej w parametrze tablicy dynamicznej na nowy rozmiar. 
Oprócz tablicy, przekaż do funkcji również stary_rozmiar i nowy_rozmiar.
Taka operacja wymaga utworzenia nowej tablicy, skopiowania 
do niej elementów ze starej tablicy, usunięcia starej tablicy 
i odpowiedniego ustawienia wskaźnika na nową tablicę. W przypadku 
gdy nowy_rozmiar jest mniejszy niż stary_rozmiar funkcja przepisuje 
jedynie nowy_rozmiar elementów,  w przeciwnym razie przepisuje 
wszystkie elementy a nadmiarowe elementy zeruje.
Zrealizuj tę funkcję w dwóch wersjach: (1) nowa tablica 
jest zwracana przez funkcję, (2) nowa tablica jest realokowana za pomocą parametru funkcji.

#include <iostream>

int* resizeArrayV1(int* array, int old_size, int new_size) {
    int* new_array = new int[new_size];

    int smaller_size = (old_size < new_size) ? old_size : new_size;
    for (int i = 0; i < smaller_size; i++) {
        new_array[i] = array[i];
    }

    for (int i = smaller_size; i < new_size; i++) {
        new_array[i] = 0;
    }

    delete[] array;

    return new_array;
}

void resizeArrayV2(int*& array, int old_size, int new_size) {
    int* new_array = new int[new_size];

    int smaller_size = (old_size < new_size) ? old_size : new_size;
    for (int i = 0; i < smaller_size; i++) {
        new_array[i] = array[i];
    }

    for (int i = smaller_size; i < new_size; i++) {
        new_array[i] = 0;
    }

    delete[] array;

    array = new_array;
}

int main() {
    int old_size = 5;
    int new_size = 8;

    int* array = new int[old_size];
    int* new_array = resizeArrayV1(array, old_size, new_size);

    resizeArrayV2(array, old_size, new_size);

    delete[] new_array;
    delete[] array;
    return 0;
}*/

//zadanie 13
/*Niektóre implementacje kompilatorów c++ przechowują 
wielkość dynamicznie zaalokowanej tablicy w postaci 
watości typu long tuż przed tą tablicą. Napisz program, 
który zaalokuje dynamicznie dwie tablice zmiennoprzecinkowe 
o wielkości m i n. Sprawdź jaka jest wartość komórki pamięci 
leżąca o jeden element typu long przed każdą z tych tablic. 
Sprawdź jaka jest różnica adresów obu tablic. Czy możesz na 
tej podstawie wysnuć jakieś wnioski. (Uwaga: wynik zadania 
może być zależny od kompilatora).

#include <iostream>

int main() {
    int m, n;
    std::cout << "Enter the size of the first array (m): ";
    std::cin >> m;
    std::cout << "Enter the size of the second array (n): ";
    std::cin >> n;

    double* array1 = new double[m];
    double* array2 = new double[n];

    long* address_before_array1 = (long*)(array1) - 1;
    long* address_before_array2 = (long*)(array2) - 1;

    ptrdiff_t address_difference = (char*)(array2) - (char*)(array1);

    std::cout << "Value before the first array: " << *address_before_array1 << std::endl;
    std::cout << "Value before the second array: " << *address_before_array2 << std::endl;
    std::cout << "Address difference between arrays: " << address_difference << " bytes" << std::endl;

    delete[] array1;
    delete[] array2;

    return 0;
}*/

