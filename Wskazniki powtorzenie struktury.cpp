// Zadanie 1
/*Napisz funkcję, która przyjmuje w argumentach:
wskaźnik arr na tablicę liczb całkowitych,
rozmiar tej tablicy n, liczbę całkowitą k
oraz wskaźnik na tablicę liczb całkowitych result.
Funkcja powinna wprowadzić do tablicy result k
największych elementów z tablicy arr
przekazanej w argumencie. Funkcja nie
powinna modyfikować oryginalnej tablicy.

#include <iostream>
#include <cstdlib>

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void fiveGreaterNumbers(const int* arr1, int n, int k, int* result)
{
    int* tmpArr = new int[n];
    for(int i = 0; i < n; i++){
        tmpArr[i] = arr1[i];
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(tmpArr[j] < tmpArr[j + 1]){
                swap(tmpArr[j], tmpArr[j + 1]);
            }
        }
    }

    for(int i = 0; i < k; i++){
        result[i] = tmpArr[i];
    }
    delete[] tmpArr;
}



int main()
{
    int n, k;
    std::cin >> n >> k;
    int* arr1 = new int[n];
    int* result = new int[k];

    srand(time(NULL));
    for(int i = 0; i < n; i++)
        arr1[i] = rand()% 101;
    for(int i = 0; i < n; i++)
        std::cout << arr1[i] << " ";
    std::cout << std::endl;

    fiveGreaterNumbers(arr1, n, k, result);

    for(int i = 0; i < k; i++)
        std::cout << result[i] << " ";

    delete[] arr1;
    delete[] result;
}*/

// Zadanie 2
/*Wykorzystując wskaźniki na funkcje napisz program,
który w zależności od wywołania funkcji
mat_operation() wykona dodawanie lub
odejmowanie dwóch macierzy kwadratowych.
Wynik operacji na macierzach powinien być zapisany
do pierwszej macierzy. Jaką zaproponujesz
sygnaturę dla tej funkcji i jakie funkcje pomocnicze?
Operacje na tablicach powinny być przeprowadzone za pomocą arytmetyki wskaźników.

#include <iostream>
#include <cstdlib>

int suma(int a, int b){
    return a + b;
}
int roznica(int a, int b){
    return a - b;
}

void mat_operation(int** arr1, int** arr2, int n, int(*f)(int, int))
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            *(*(arr1 + i) + j) = f(*(*(arr1 + i) + j), *(*(arr2 + i) + j));
        }
    }
}

void print(int** arr1, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cout << *(*(arr1 + i) + j) << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    srand(time(NULL));
    int n;
    std::cin >> n;
    int** arr1 = new int*[n];
    for(int i = 0; i < n; i++){
        arr1[i] = new int[n];
    }
    int** arr2 = new int*[n];
    for(int i = 0; i < n; i++){
        arr2[i] = new int[n];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr1[i][j] = rand()%11;
            arr2[i][j] = rand()%11;
        }
    }
    print(arr1, n);
    std::cout << std::endl;
    print(arr2, n);
    std::cout << std::endl;

    mat_operation(arr1, arr2, n, roznica);

    print(arr1, n);
    std::cout << std::endl;

    for(int i = 0; i < n; i++){
        delete[] arr1[i];
    }
    delete[] arr1;

    for(int i = 0; i < n; i++){
        delete[] arr2[i];
    }
    delete[] arr2;
}*/

// Zadanie 3
/*Napisz dwie funkcje condition i action.
Funkcja condition powinna przyjąć liczbę
całkowitą i zwrócić wartość logiczną.
Funkcja action powinna przyjmować
referencję na liczbę całkowitą i nic nie zwracać.
Funkcja condition ma sprawdzać, czy w liczbie
powtarza się którakolwiek cyfra.
Funkcja action powinna odwrócić
kolejność cyfr w tej liczbie.
Napisz funkcję modify_array, która przyjmie
tablicę liczb całkowitych, jej rozmiar
oraz dwa wskaźniki na funkcje o nagłówkach
takich jak condition i action.
Dla każdego elementu tablicy spełniającego
warunek condition należy wywołać funkcję action.

#include <iostream>
#include <string>
#include <algorithm>



bool condition(int number)
{
    std::string str = std::to_string(number);
    for(size_t i = 0; i < str.size(); i++){
        char c = str[i];
        if (count_if(str.begin(), str.end(), [c](char x){return c == x;}) > 1){
            return true;
        }
    }
    return false;
}

void action(int& number)
{
    std::string str = std::to_string(number);
    std::string str2;
    int size = str.size();
    for(size_t i = 0; i < size; i++)
    {
        str2[i] = str[size - i - 1];
    }
    number = std::stoi(str2);
}

void modify_array(int arr[], int size, bool (*function1)(int), void (*function2)(int&))
{
    for(int i = 0; i < size; i++)
    {
        if (function1(arr[i])){
            function2(arr[i]);
        }
    }
}

int main()
{
    int arr[] = {53, 7456, 453, 23423, 789698776};

    int size = sizeof(arr)/sizeof(arr[0]);
    modify_array(arr, size, condition, action);
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << "\n";
    }

}*/

//Zadanie 4
/*Napisz funkcję find_substring(), która w stringu 
podanym w pierwszym argumencie wyszukuje wystąpienia 
stringu podanego w drugim argumencie. 
Funkcja powinna zwracać wskaźnik na pierwszy znak 
identycznego podciągu lub nullptr jeżeli takiego podciągu nie ma.

#include <iostream>

char* find_substring(std::string str1, std::string str2)
{
    size_t size1 = str1.size(), size2 = str2.size();

    for (size_t i = 0; i <= size1 - size2; i++) {
        size_t j = 0;
        size_t k = i;
        while (str1[k] == str2[j] && j < size2) {
            j++;
            k++;
        }

        if (j == size2) {
            return &str1[i];
        }
    }
    return nullptr;
}

int main()
{
    std::string str1, str2;
    std::getline(std::cin, str1);
    std::getline(std::cin, str2);

    char* point = find_substring(str1, str2);

    if (point != nullptr) {
        std::cout << "Substring found at index: " << *point << std::endl;
    } else {
        std::cout << "Substring not found." << std::endl;
    }

    return 0;
}
*/
//Zadanie 5
/*Napisz funkcję, do użycia jako komparator w funkcji qsort, 
która pozwoli posortować napisy rosnąco względem ich ostatnich znaków. 
Jeżeli ostatnie znaki są jednakowe, należy porównać przedostatnie itd. 

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

int compare(const void *a, const void *b)
{
    const char *_a = *(const char**)a;
    const char *_b = *(const char**)b;
    
    int LenA = strlen(_a);
    int LenB = strlen(_b);

    int i = 0;
    while (i < LenA && i < LenB){
        if(_a[LenA - i - 1] < _b[LenB - i - 1])
            return 1;
        else if(_a[LenA - i - 1] > _b[LenB - i - 1])
            return -1;

        i++;
    }
    return 0;
}

int main()
{
    const char *string[] = {"abc", "xyz", "def", "yz", "abcde"};
    qsort(string, 5, sizeof(const char *), compare);

    for(int i = 0; i < 5; i++)
        std::cout << string[i] << " ";
}*/


// Zadanie 6
/*Napisz program, który podzieli podany string na tokeny
(fragmenty napisu) rozdzielone podanym znakiem.
Zbierz wszystkie tokeny do tablicy stringów i
następnie wyświetl je na ekranie.
Do wykonania zadania można użyć funkcji strtok() z pliku <cstring>.
PRZYKŁAD:
cstring str = "ala;ma kota;i;dwa psy"
char delimeter = ';'
tokeny: "ala", "ma kota", "i", "dwa psy"

#include <iostream>
#include <cstring>

int main()
{
    const int maxString = 100;
    char input[maxString] = "ALA;ma kota;i;dwa psy";


    std::cout << input << std::endl;
    const char delimiter = ';';

    char* tokens[10];

    char* token = strtok(input, &delimiter);
    int i = 0;
    while (token != nullptr){
        tokens[i] = token;
        i++;
        token = strtok(nullptr, &delimiter);
    }

    for(int j = 0; j < i; j++)
    {
        std::cout << tokens[j] << std::endl;
    }
}*/

//Zadanie 7
/*Napisz funkcję search_string(), która przyjmie tablicę napisów, 
jej rozmiar oraz wskaźnik na funkcję pf odpowiedniej postaci. 
Funkcja search_string() powinna zwrócić wskaźnik na napis, 
dla którego funkcja pf zwróci największą wartość. 
Zdefiniuj funkcję search_string() tak, aby jako funkcja pf 
mogła być wywołana funkcja biblioteczna strpbrk z <cstring>, 
której jako drugi argument zostanie przekazany napis złożony z samogłosek.

#include <iostream>
#include <cstring>
unsigned int f(const char *str, char *(*pf)(const char *, const char *)) {
    unsigned int result = 0;
    const char *tmp = str;
    
    while(tmp) {
        tmp = pf(tmp, "aeiouy");
        if(tmp) ++result;
        else return result;
        tmp += 1;
    }
    return result;
}
const char *search_string(const char *arr[], int n, char *(*pf)(const char *, const char *)) {
    unsigned int tmp = 0, max = f(arr[0], pf);
    const char *result = arr[0];
    for(int i = 1; i < n; ++i) {
        tmp = f(arr[i], pf);
        if(tmp > max) {
            max = tmp;
            result = arr[i];
        }
    }
    return result;
}
int main() {
    const char *arr[5] = {
        "iwi",
        "alaeeeeeeeeee",
        "maciek",
        "bogdan",
        "test"
    };
    std::cout << search_string(arr, 5, strpbrk) << std::endl;
    return 0;
}*/

//Zadanie 8
/*Zdefiniuj strukturę Rect, reprezentującą prostokąt. 
Struktura ta ma składać się z dwóch elementów - długości boków a i b.
Stwórz funkcję print_rect(..), 
która wyświetla na ekranie długości boków podanego w parametrze prostokąta. 
Stwórz funkcję area(...), 
która zwróci wielkość pola podanego w parametrze prostokąta.
W programie stwórz obiekt automatyczny 
i dynamiczny typu Rect i przetestuj działanie zdefiniowanych funkcji.

#include <iostream>

struct Rect {
    double x;
    double y;
};

void print_rect(Rect square)
{
    std::cout << "side of square: " << square.x << ", " << square.y << std::endl;
}

double area(Rect square)
{
    return square.x * square.y;
}

int main()
{
    Rect square = {7.5, 8.7};
    print_rect(square);
    std::cout << area(square);

    Rect* square2 = new Rect{4.5, 6.5};
    print_rect(*square2);
    std::cout << area(*square2);
    delete square2;

}*/

//Zadanie 9
/*Zdefiniuj strukturę reprezentującą macierz 
o rozmiarze 3x3 liczba zmiennoprzecinkowych. 
Zdefiniuj funkcję print_mat() wypisującą na 
ekranie elementy tej macierzy.
Zdefiniuj funkcję add_mat() dodawania liczby 
do takiej macierzy; funkcja ma zwracać nowo obliczoną macierz. 
Napisz program testujący.

#include <iostream>

struct matrix {
    double arr[3][3];
};

void print_matrix(matrix arr){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << arr.arr[i][j] << " ";
        }
        std::cout << "\n";
    }
}

matrix add_mat(matrix arr, double n){
    matrix arr2;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arr2.arr[i][j] = arr.arr[i][j] + n;
        }
    }
    return arr2;
}

int main(){
    matrix arr = {{{3, 4, 5}, {1, 2, 3}, {7, 8, 9}}};
    print_matrix(arr);
    matrix arr2;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cin >> arr2.arr[i][j];
        }
    }
    print_matrix(arr2);
    std::cout << std::endl;
    arr = add_mat(arr2, 7);
    print_matrix(arr);
                  
}*/

//Zadanie 10
/*Zdefiniuj strukturę vec2d, składającą 
się z dwóch pół x i y typu zmiennoprzecinkowego, 
która będzie reprezentowała wektor dwuwymiarowy. 
Utwórz tablicę automatyczną obiektów tego typu. 
Z pomocą funkcji z biblioteki <algorithm>:
- wypełnij tę tablicę wektorami, których poszczególne współrzędne spełniają zależność: x jest liczbą pseudolosową z zakresu domkniętego <-1, 1> a y jest liczbą przeciwną do x;
- wypisz na ekranie wszystkie elementy tej tablicy;
- posortuj wszystkie wektory w tablicy malejąco względem współrzędnej y;
- znajdź wektor o najmniejszej współrzędnej x.

#include <iostream>
#include <algorithm>
#include <cstdlib>

struct vec2d{
    double x;
    double y;
};
vec2d RandomNumber () { 
    vec2d v;
    v.x = 2 * ((double)std::rand()/RAND_MAX) - 1; 
    v.y =- v.x;
    return v;
}
void print(vec2d v){
    std::cout << v.x << " " << v.y << std::endl;
}

int main(){
    vec2d arr[10];

    std::generate(arr, arr + 10, RandomNumber);
    std::for_each(arr, arr + 10, print);
    std::cout << std::endl;
    std::sort(arr, arr + 10, [](vec2d v, vec2d f){return v.y > f.y;});
    std::for_each(arr, arr + 10, print);
    std::cout << std::endl;
    print(*std::min_element(arr, arr + 10, [](vec2d v, vec2d f){return v.x < f.x;}));
    return 0;
}*/

//Zadanie 11
/*Zdefiniuj strukturę Task, która będzie się składała z pół: 
(1) nazwa zadania (c-string), 
(2) priorytet zadania (int), 
wskaźnik run na funkcję realizującą zadanie - 
funkcja ma przyjmować w parametrze napis 
c-string i liczbę typu int i zwracać void. 
Stwórz pomocniczą funkcję o identycznym 
nagłówku 'void print(const char*, int)', 
która wyświetli na ekranie podany w parametrze napis i liczbę.
Utwórz dynamiczną n-elementową tablicę 
wskaźników do obiektów typu Task. 
Zainicjuj wszystkie elementy tej tablicy, 
a wskaźnik run ustaw na funkcję print().
Z pomocą funkcji z biblioteki <algorithm>:
- posortuj zadania rosnąco względem priorytetu;
- posortuj zadania malejąco względem nazwy zadania;
- dla każdego obiektu z tablicy za pomocą wskaźnika run wywołaj funkcję, na którą wskazuje.

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

struct Task {
    char* name;
    int priority;
    void (*run)(const char*, int);
};

void print(const char* str, int n){
    printf("%s %i\n", str, n);
}

int main()
{
    Task** arr = new Task*[3];
    arr[0] = new Task{"Baaaaad", 3, print};
    arr[1] = new Task{"Baa", 2, print};
    arr[2] = new Task{"Baaaaac", 1, print};

    for(int i = 0; i < 3; i++){
        arr[i] -> run(arr[i] -> name, arr[i] -> priority);
    }
    std::cout << std::endl;
    std::sort(arr, arr + 3, [](Task* p1, Task* p2){return p1->priority - p2->priority;});

    for(int i = 0; i < 3; i++){
        arr[i] -> run(arr[i] -> name, arr[i] -> priority);
    }

    std::sort(arr, arr + 3, [](Task* a, Task* b) {
        return std::lexicographical_compare(
            a->name, a->name + std::strlen(a->name),
            b->name, b->name + std::strlen(b->name),
            [](char c1, char c2) { return std::tolower(c1) < std::tolower(c2); }
        );
    });

    std::cout << std::endl;
    
    for(int i = 0; i < 3; i++){
        arr[i] -> run(arr[i] -> name, arr[i] -> priority);
    }

    for(int i = 0; i < 3; i++){
        delete[] arr[i];
    }
    delete[] arr;
}*/


