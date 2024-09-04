//Zadanie 1
/*Napisz program, który wydrukuje wartość oraz 
adres w pamięci zmiennych typu: int, wskaźnika 
na typ int niezainicjalizowanego oraz ustawionego 
na konkretną zmienną. Wykorzystaj do tego celu 
funkcję printf() oraz obiekt std::cout.

#include <iostream> 

using namespace std;

int main()
{
    int a = 5;
    int* b;
    int* c = &a;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "&a = " << &a << endl;
    cout << "&b = " << &b << endl;
    cout << "&c = " << &c << endl;
    return 0;
}*/

//Zadanie 2
/*Napisz program, w którym zdefiniujesz 
bezpośrednio po sobie kilka zmiennych typ: 
(1) int, (2) float, (3) char, (4) char[7], 
(5) double. Sprawdź w jakiej kolejności te 
zmienne będą rzeczywiście zaalokowane w 
pamięci po uruchomieniu programu, czy 
wszystkie zostaną zaalokowane w jednolitym 
bloku pamięci i ile bajtów będą łącznie zajmowały.

#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    float b = 7.5;
    char c = 'a';
    char d[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    double e = 64.9;
    cout << "a = " << &a << endl;
    cout << "b = " << &b << endl;
    cout << "c = " << &c << endl;
    cout << "d = " << &d << endl;
    cout << "d[6] = " << d + 6 << endl; 
    cout << "e = " << &e << endl;
    return 0;
}*/

//Zadanie 3
/*Napisz funkcję, która przyjmuje jako argumenty wskaźniki 
do trzech zmiennych typu int. Funkcja powinna do 
trzeciego argumentu zapisać sumę wartości z 
liczb wskazywanych przez dwa poprzednie argumenty.

#include <iostream>

using namespace std;

int sum(int a, int b, int c){
    c = a + b;
    return c;
}
int main()
{
    int a = 5;
    int b = 7;
    int c = 0;
    cout << sum(a, b, c) << endl;
    return 0;
}*/

//Zadanie 4
/*Zmodyfikuj poprzedni program tak aby korzystał z referencji. 

#include <iostream>

using namespace std;

void sum(int &a, int &b, int &c){
    c = a + b;
}
int main()
{
    int a = 5;
    int b = 7;
    int c = 0;
    sum(a, b, c);
    cout << c << endl;
    return 0;
}*/

//Zadanie 5
/*Napisz funkcję otrzymującą dwa argumenty 
referencję a oraz wskaźnik b do zmiennych typu int, 
która zamienia ze sobą wartości zmiennych, 
do których wskaźnik i referencję dostała w argumentach.

#include <iostream>

using namespace std;

void swap(int &a, int *b){
    int temp = a;
    a = *b;
    *b = temp;
}

int main()
{
    int a = 5;
    int b = 7;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    swap(a, &b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}*/

//Zadanie 6
/*Napisz funkcję, która przyjmuje w argumentach 
liczbę 4-bajtową całkowitą nieujemną word oraz 
cztery wskaźniki na 1-bajtowe liczby całkowitą 
nieujemne b0,b1,b2,b3. Funkcja ma wpisać w argumenty 
wskazywane wskaźnikami b0..b3 wartości kolejnych bajtów 
z liczby word. Zadanie zrealizuj za pomocą arytmetyki 
wskaźnikowej i odpowiedniego ich rzutowania. Przetestuj działanie funkcji.

#include <iostream>

void wordToBytes(unsigned int word, unsigned char* b0, unsigned char* b1, unsigned char* b2, unsigned char* b3){
    *b0 = word & 0xFF;
    *b1 = (word >> 8) & 0xFF;
    *b2 = (word >> 16) & 0xFF;
    *b3 = (word >> 24) & 0xFF;
}

int main()
{
    unsigned int word = 0b10000000010000000010000000010000;
    unsigned char b0, b1, b2, b3;
    wordToBytes(word, &b0, &b1, &b2, &b3);
    std::cout << "b0 = " << (int)b0 << std::endl;
    std::cout << "b1 = " << (int)b1 << std::endl;
    std::cout << "b2 = " << (int)b2 << std::endl;
    std::cout << "b3 = " << (int)b3 << std::endl;
    return 0;
}*/

//Zadanie 7
/*Napisz program, który wyświetli wartość liczby 
typu float ale interpretowanej jak gbyby była 
ona liczbą typu unisigned int. Użyj odpowiednich rzutowań wskaźnikowych.

#include <iostream>

using namespace std;

int main()
{
    float a = 5.5;
    unsigned int* b = (unsigned int*)&a;
    cout << *b << endl;
    return 0;
}*/

//Zadanie 8
/*Napisz funkcję otrzymującą jako argumenty wskaźniki 
do dwóch zmiennych typu int, która zwraca jako 
wartość wskaźnik na zmienną przechowującą 
mniejszą z liczb wskazywanych przez argumenty.

#include <iostream> 

using namespace std;

int* min(int* a, int* b){
    if(*a < *b)
        return a;
    else 
        return b;
}

int main()
{
    int a = 5;
    int b = 7;
    cout << *min(&a, &b) << endl;
}*/

//Zadanie 9
/*Napisz funkcję, która przyjmuje jako argument 
wskaźnik na początek i koniec tablicy liczb całkowitych. 
Funkcja powinna wyświetlić wszystkie elementy tej tablicy. 
Przetestuj działanie tej funkcji. Nie korzystaj z dostępu do elementów tablicy operatorem [ ].

#include <iostream>
using namespace std;

void print(int* begin, int* end){
    for(; begin < end; begin++){
        cout << *begin << endl;
    }
}

int main()
{
    int tab[5] = {1, 2, 3, 4, 5};
    print(tab, tab + 5);
    return 0;
}*/

//Zadanie 10
/*Napisz funkcję, która dostaje jako argument 
wskaźnik do tablicy typu int oraz rozmiar tablicy 
i odwraca kolejność elementów w tablicy. 
Nie korzystaj z dostępu do elementów tablicy operatorem [ ].

#include <iostream>
using namespace std;

void reverse(int* arr, int size){
    for(int i = 0; i < size / 2; i++){
        int tmp = *(arr + i);
        *(arr + i) = *(arr + size - i - 1);
        *(arr + size - i - 1) = tmp;
    }
}

int main()
{
    int tab[5] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++){
        cout << tab[i] << " ";
    }
    cout << endl;
    reverse(tab, 5);
    for(int i = 0; i < 5; i++){
        cout << tab[i] << " ";
    }
    return 0;
}*/

//Zadanie 11
/*Napisz funkcję iteracyjną i rekurencyjną, która oblicza rozmiar napisu (char str[]). 
#include <iostream>
using namespace std;

int sizeIter(char* str){
    int size = 0;
    while(*str != '\0'){
        size++;
        str++;
    }
    return size;
}

int sizeRec(char* str){
    if(*str == '\0')
        return 0;
    else 
        return 1 + sizeRec(str + 1);
}

int main()
{
    char str[] = "Hello World";
    cout << sizeIter(str) << endl;
    cout << sizeRec(str) << endl;
    return 0;
}*/

//Zadanie 12
/*Napisz funkcję, która dostaje dwa argumenty: 
wskaźnik na stałą typu int i stały wskaźnik 
na zmienną typu int. Funkcja powinna przepisać 
zawartość stałej wskazywanej przez pierwszy 
argument do zmiennej wskazywanej przez drugi argument. 
Napisz program, który przetestuje działanie tej funkcji.

#include <iostream>
using namespace std;

void copy(const int* a, int* const b){
    *b = *a;
}

int main()
{
    int a = 5;
    int b = 7;
    copy(&a, &b);
    cout << b << endl;
    return 0;
}*/

//Zadanie 13
/*Napisz odpowiednie funkcje, które umożliwią 
stworzenie kopii wczytanego od użytkownika napisu. 
Napis nie może być dłuższy niż 100 znaków. 

#include <iostream>

using namespace std;

void copy(char* str, char* copy){
    int i = 0;
    while(str[i] != '\0'){
        copy[i] = str[i];
        i++;
    }
    copy[i] = '\0';
}

int main()
{
    char str[100];
    cin.getline(str, 100);
    char str2[100];
    copy(str, str2);
    cout << str2 << endl;
}*/

//Zadanie 14
/*Napisz funkcję, która przyjmuje jako argumenty 
wskaźnik na pierwszy element tablicy liczb całkowitych, 
wskaźnik na za-ostatni element tej tablicy oraz referencję 
do zmiennej logicznej. Funkcja powinna posortować tablicę 
w taki sposób, że wartości nieparzyste znajdą się w początkowej 
części tablicy, a parzyste w końcowej. Kolejność wartości wewnątrz 
tych grup jest dowolna. Funkcja powinna zwrócić wskaźnik na komórkę 
tablicy, w której pojawi się pierwsza liczba parzysta. Zmiennej 
logicznej przekazanej przez referencję podanej w argumencie, 
należy przypisać prawdę, jeżeli funkcja dokonała w tablicy 
jakąkolwiek zmianę, a fałsz w przeciwnym przypadku. W zadaniu 
wykorzystaj wskaźnikowy sposób indeksowania tablicy. 
Dla ułatwienia załóżmy, że w tablicy jest co najmniej 
jedna wartość parzysta i nieparzysta. 

#include <iostream>
using namespace std;

int* sort(int* begin, int* end, bool& flag){
    int* first_even = end;
    for(int i = 0; i < end - begin; i++){
        for(int j = 1; j < end - begin - 1 - i; j++){
            if(*(begin + j) % 2 == 0 && *(begin + j + 1) % 2 == 1){
                int tmp = *(begin + j);
                *(begin + j) = *(begin + j + 1);
                *(begin + j + 1) = tmp;
                flag = true;
            }
        }
    }
    for(; begin < end; begin++){
        if(*begin % 2 == 0){
            first_even = begin;
            break;
        }
    }
    return first_even;
}

int main()
{
    int tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 10, 9};
    bool flag = false;
    int* first_even = sort(tab, tab + 10, flag);
    cout << (bool)flag << endl;
    for(int i = 0; i < 10; i++){
        cout << tab[i] << " ";
    }
    cout << endl;
    cout << *first_even << endl;
    return 0;
}*/

//Zadanie 15
/*Napisz funkcję, która zrealizuje operację 
mnożenia dwóch macierzy o rozmiarze 3x3 przekazanych w argumencie. 
Macierze mają być reprezentowane przez tablice jednowymiarowe 9-elementowe. 
Wewnątrz funkcji nie korzystaj z dostępu do elementów tablicy operatorem [ ]. 
Jaką deklarację funkcji zaproponujesz żeby zrealizować to zadanie?*/

#include <iostream>
using namespace std;

void matrixMul(int* arr1, int* arr2, int* arr3){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            *(arr3 + i * 3 + j) = 0;
            for(int k = 0; k < 3; k++){
                *(arr3 + i * 3 + j) += *(arr1 + i * 3 + k) * *(arr2 + k * 3 + j);
            }
        }
    }
}

int main()
{
    int arr1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr3[9];

    matrixMul(arr1, arr2, arr3);

    for(int i = 0; i < 9; i++){
        cout << arr3[i] << " ";
    }

}