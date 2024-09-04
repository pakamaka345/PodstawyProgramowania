//Zadanie 1
/*Napisz program, który wczyta od użytkownika dwie liczby 
zmiennoprzecinkowe x i y, a następnie nieujemną liczbę 
całkowitą z. Program, w zależności od wartości podanej 
liczby z, powinien wyświetlić wynik odpowiedniego działa:
z=0 -> sumę x i y,
z=1 -> różnicę x i y,
z=2 -> iloczyn x i y,
z=3 -> iloraz x i y.
Zadanie wykonaj bez instrukcji i wyrażeń warunkowych.

#include <iostream>

float suma(float x, float y){
    return x + y;
}

float różnica(float x, float y){
    return x - y;
}

float iloczyn(float x, float y){
    return x * y;
}

float iloraz(float x, float y){
    if(y == 0) std::cout << "can`t divide by zero";

    return x / y;
}

int main(){
    int z;
    float x, y;
    float (*operation[])(float, float) = {suma, różnica, iloczyn, iloraz};
    std::cin >> z >> x >> y;

    std::cout << operation[z](x, y);

}*/

//Zadanie 2;
/*Napisz program, który wyświetli wszystkie elementy tablicy za pomocą funkcji std::for_each.

#include <algorithm>
#include <iostream>
#include <cstdlib>

void print(int x){
    std::cout << x << " ";
}

int main(){
    int n;
    std::cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        arr[i] = rand()%101;
    }

    std::for_each(arr, arr+n, print);

    delete[] arr;
}*/

//Zadanie 3
/*Napisz program, który wykona kopię wczytanego z 
klawiatury napisu, w ten sposób, że do napisu 
docelowego (o tej samej wielkości co napis źródłowy) 
zostaną zapisane tylko małe litery, reszta zostanie 
zignorowana. W miejscu pozostałych, niewykorzystanych 
znaków wstaw symbol '-' (minus). Program napisz 
bez używania pętli. (podpowiedź: std::copy_if(), std::fill()).
Przykład:
WE: aBcDeFg
WY: aceg---


#include <iostream>
#include <algorithm>
#include <cstring>

int main(){
    char str1[100], str2[100];
    std::cin.getline(str1, 100);
    auto it = std::copy_if(str1, str1 + 100, str2, [](char x){return x>= 'a' && x <= 'z';});
    int size = strlen(str1);
    std::fill(it, str2 + size, '-');

    std::cout << str2;

}*/
//Zadanie 4
/*Napisz program, który posortuje tablicę dowolnych 
liczb rzeczywistych arr1 malejąco oraz tablicę 
dowolnych liczb całkowitych arr2 rosnąco. 
Do sortowania wykorzystaj algorytm qsort 
z biblioteki standardowej c i algorytm 
std::stort z biblioteki standardowej c++. 

#include <iostream>
#include <cstdlib>
#include <algorithm> 

int compare(const void* a, const void* b){
    return ( *(int*)b - *(int*)a );
}


int main(){
    int n = 10, m = 10;
    int* arr1 = new int[n];
    int* arr2 = new int[m];
    srand(time(NULL));

    for(int i = 0; i < n; i++){
        arr1[i] = rand()%100;
    }
    for(int i = 0; i < m; i++){
        arr2[i] = rand()%100;
    }
    std::cout << "before sort \n";
    for(int i = 0; i < n; i++){
        std::cout << arr1[i] << " ";
    }

    std::cout << "\n";

    for(int i = 0; i < m; i++){
        std::cout << arr2[i] << " ";
    }
    std::cout << "\nafter sort \n";

    qsort(arr1, n, sizeof(int), compare);
    std::sort(arr2, arr2 + m, [](int a, int b) { return a < b; });

    for(int i = 0; i < n; i++){
        std::cout << arr1[i] << " ";
    }

    std::cout << "\n";

    for(int i = 0; i < m; i++){
        std::cout << arr2[i] << " ";
    }
    

    delete[] arr1;
    delete[] arr2;
}*/

//Zadanie 5
/*Napisz właną funkcję, która otrzymuje w 
argumentach dwa napisy i zwraca informacje 
o tym, który z nich jest wcześniejszy 
w porządku alfabetycznym (==0, <0, >0).

#include <iostream>

int compareStrings(const char* str1, const char* str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return(*str1) - (*str2);
        }
        ++str1;
        ++str2;
    }

    return (*str1) - (*str2);
}

int main() {
    const char* str1 = "bananjhhilkk";
    const char* str2 = "cpies";

    int result = compareStrings(str1, str2);

    if (result == 0) {
        std::cout << "Strings are equal." << std::endl;
    } else if (result < 0) {
        std::cout << "String '" << str1 << "' is lexicographically smaller than string '" << str2 << "'." << std::endl;
    } else {
        std::cout << "String '" << str2 << "' is lexicographically smaller than string '" << str1 << "'." << std::endl;
    }

    return 0;
}*/

//Zadanie 6
/*Napisz program, który uporządkuje alfabetycznie 
tablicę napisów za pomocą funkcji qsort oraz za pomocą funkcji std::sort. 

#include <iostream>
#include <algorithm>
#include <cstring>

int compare(const void* a, const void* b){
    return *(char*)a - *(char*)b;
}

int main(){
    char str1[] = "dsiojsdojdjoskpdjfowskpkspeqwkpjotw";
    char str2[] = "fkfdmflgksewoijifdskods";

    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;

    qsort(str1, strlen(str1), sizeof(char), compare);
    std::sort(str2, str2 + strlen(str2));

    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
}*/

//Zadanie 7
/*Napisz program, który wczyta od użytkownika 
liczbę jako napis. Liczba powinna mieć co 
najwyżej 10 cyfr. Następnie program 
powinien zwiększyć tą liczbę o 10 i ją wyświetlić. 

#include <iostream>

int main(){
    char number[11];
    std::cin.get(number, 11);

    int number1 = atoi(number) + 10;

    std::cout << std::to_string(number1);
}*/

//Zadanie 8
/*Napisz funkcję, która przyjmie dwa parametry liczbę 
całkowitą x oraz liczbę całkowitą d, w której 
zapisana będzie cyfra. Funkcja powinna zwrócić 
liczbę wystąpień cyfry d w liczbie x. 
W implementacji tej funkcji nie używaj pętli.

#include <iostream>

int count_occurrences_of_digit(int x, int d){
    if(!x) return 0;

    int tmp = 0;
    if(x % 10 == d) tmp = 1;
    return count_occurrences_of_digit(x / 10, d) + tmp;
}

int main(){
    int x = 154444324, d = 4;
    std::cout << count_occurrences_of_digit(x, d);
}*/

//Zadanie 9
/*Zaprojektuj funkcję, która zwróci indeks 
szukanej wartości w posortowanej tablicy 
liczb całkowitych. Funkcja powinna 
zwrócić -1, jeśli nie uda się znaleźć 
takiej wartości w tablicy. Rozwiązanie powinno 
być rozwiązaniem optymalnym. 
Napisz program, który przetestuje działanie tej funkcji. 


#include <iostream>
#include <algorithm>
#include <cstdlib>

int binarySearch(int arr[], int n, int x){
    int leftSide = 0;
    int rightSide = n - 1;
    while (leftSide <= rightSide){
        int middle = (leftSide + rightSide) / 2;
        if(arr[middle] == x) return middle;
        else if(arr[middle] < x) leftSide = middle + 1;
        else rightSide = middle - 1;
    }
    return -1;
}

int main(){
    int n, x;
    std::cin >> n >> x;
    int* arr = new int[n];

    srand(time(NULL));

    for(int i = 0; i < n; i++){
        arr[i] = rand()%11;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::sort(arr, arr + n);
    for(int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    int index = binarySearch(arr, n, x);

    std::cout << index;

}*/


//Zadanie 10
/*Napisz program, który wczyta od użytkownika dwie 
liczby całkowite n i x, a następnie stworzy 
dwa n-wymiarowe wektory reprezentowane 
przez n-elementowe tablice liczb zmiennoprzecinkowych. 
Następnie program powinien:
- uzupełnić tablicę kolejnymi wartościami zaczynając od x (std::generate)
- ustawić te wartości w losowej kolejności (wymieszać) (std::shuffle)
- wyświetlić obie tablice (std::for_each)
- wyświetlić sumę wartości w tablicach (std::accumulate)
- wyświetlić wynik iloczynu skalarnego dwóch wektorów (std::inner_product).

#include <iostream>
#include <algorithm>
#include <numeric>
#include <chrono> 
#include <random>

void print (float x){
    std::cout << x << " ";
}

int main()
{
    int n, x;
    std::cin >> n >> x;
    float* arr1 = new float[n];
    float* arr2 = new float[n];

    std::generate(arr1, arr1 + n, [&](){return x++;});
    std::generate(arr2, arr2 + n, [&](){return x++;});

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::shuffle(arr1, arr1 + n, std::default_random_engine(seed));
    std::shuffle(arr2, arr2 + n, std::default_random_engine(seed));

    std::for_each(arr1, arr1 + n, print);
    std::cout << std::endl;
    std::for_each(arr2, arr2 + n, print);

    std::cout << std::endl << std::accumulate(arr1, arr1 + n, 0.0);
    std::cout << std::endl << std::accumulate(arr2, arr2 + n, 0.0);
    std::cout << std::endl << std::inner_product(arr1, arr1 + n, arr2, 0.0);

    delete[]arr1;
    delete[]arr2;
}*/

//Zadanie 11
/*Napisz program, który wczyta od użytkownika 
maksymalnie 100 znakowe słowo. Następnie 
program powinien stworzyć odwrócony 
odpowiednik napisu wprowadzonego przez 
użytkownika za pomocą arytmetyki wskaźników. 

#include <iostream>
#include <cstring>

int main()
{
    char str[101], reverseSTR[101];
    std::cin.getline(str, 101);

    char* s = str;
    char* r = reverseSTR;
    int size = 0;
    while(*(s++)) size++;
    s--;
    while(size != 0){
        *(r++) = *(--s);
        size--;
    }
    *r='\0';
    for(int i = 0; reverseSTR[i] != '\0'; i++){
        std::cout << reverseSTR[i];
    }
}*/