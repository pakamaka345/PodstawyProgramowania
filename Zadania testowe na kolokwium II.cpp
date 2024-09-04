//Zadanie 1
/*Dane są dwie tablice liczb zmiennoprzecinkowych o długościach: 
(1) 3*N oraz (2) N, gdzie N jest liczbą naturalną. 
Zdefiniuj funkcję fun_arr, która w parametrze przyjmie 
dwie tablice (o podanej wyżej specyfikacji) oraz wskaźnik 
na pewną dodatkową funkcję fun_aux. Funkcja fun_arr z 
każdych trzech sąsiadujących elementów (o indeksach {3i, 3i+1, 3i+2}) 
z pierwszej tablicy ma obliczyć, za pomocą fun_aux, pojedynczą wartość 
i wstawić ją do drugiej tablicy w element o indeksie i. 
Funkcja pomocnicza fun_aux, dla trzech podanych liczb, ma zwracać wartość największą.
W funkcji głównej stwórz przykładowe dynamiczne tablice (1) i (2) 
spełniające warunki z początku zadania i wykorzystując 
funkcje fun_arr i fun_aux, uzupełnij tablicę wyjściową (2). 
Wypisz na ekranie jej wartości. Zadbaj o właściwe zarządzanie pamięcią dynamiczną.
Przykład:
IN:     [1.0,1.0,2.5,   2.0,1.0,-0.5,   -1.5,-3.0,-4.0,   0.0,0.0,0.0,0.0]
OUT: [2.5            2.0             -1.5              0.0]

#include <iostream>
#include <cstdlib>
#include <algorithm>

void fun_arr(float* arr1, float* arr2, int size, float(*f)(float, float, float))
{
    for(int i = 0; i < size; i++)
    {
        arr2[i] = f(arr1[3 * i], arr1[3 * i + 1], arr1[3 * i + 2]);
    }
}

float fun_aux(float a, float b, float c)
{
    if (a > b && a > c)
        return a;
    else if (b > c && b > a)
        return b;
    else if (c > b && c > a)
        return c;
}

int main()
{
    int N;
    std::cin >> N;
    int size2 = N, size1 = N*3;
    srand(time(NULL));

    float* arr1 = new float[size1];
    float* arr2 = new float[size2];

    for(int i = 0; i < size1; i++){
        arr1[i] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX / 10.0f);
        printf ("%f ", arr1[i]);
    }

    fun_arr(arr1, arr2, N, fun_aux);
    std::cout << std::endl;
    for(int i = 0; i < size2; i++)
    {
        printf ("%f ", arr2[i]);
    }

    delete[]arr1;
    delete[]arr2;


}*/

//Zadanie 2
/*Napisz program w języku C++, który stworzy dynamiczną 
tablicę dwuwymiarową trójkątną arr o rozmiarze NxN 
wybranego typu liczbowego i wypełni ją dowolnymi wartościami. 
Zdefiniuj funkcję, która w parametrze przyjmie wskaźnik 
na wskaźnik na typ void (do tablicy trójkątnej arr), rozmiar N, 
wielkość w bajtach pojedynczego elementu sizen tablicy 
przekazanej w pierwszym parametrze oraz dwie współrzędne x, 
y typu całkowitego. Funkcja ma zwrócić wskaźnik typu void 
ustawiony na podany we współrzędnych x, y element tablicy 
lub nullptr jeżeli nie ma takiego elementu. 
Pokaż użycie tej funkcji i wykonaj dealokację tablicy arr.
Przykład:
 0  1  2  3  4
 5  6  7  8
 8  9 10
11 12
13
OUT: 7 (dla x=2, y=1)

#include <iostream>
#include <cstdlib>
#include <ctime>

void* function(void** arr, int size, int sizeOf, int x, int y)
{
    if(x < size && y <= x) {
        return (char*)arr[y] + x * sizeOf;
    }
    return nullptr;
}

int main()
{
    int N;
    std::cin >> N;
    srand(time(NULL));

    double** arr = new double*[N];
    for (int i = 0; i < N; i++) {
        arr[i] = new double[N - i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i; j++) {
            arr[i][j] = (double)(rand()) / (double)(RAND_MAX / 10.0f);
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    void* point = function((void**)arr, N, sizeof(double), 2, 1);
    std::cout << std::endl;
    if (point != nullptr)
    {
        std::cout << "point = " << *((double*)point);
    }
    else    
    {
        std::cout << "There is not element in array";
    }

    for (int i = 0; i < N; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}*/

//Zadanie 3
/*Napisz program, który obliczy i wyświetli długości 
dwuwymiarowych wektorów zapisanych w jednowymiarowej 
tablicy liczb zmiennoprzecinkowych. 
Tablica z wektorami wejściowymi ma być skonstruowana 
w ten sposób, że kolejne współrzędne (x, y) każdego 
wektora zajmują kolejne elementy tablicy, czyli:  
[x1,y1, x2,y2, x3,y3, …, xn,yn]. 

Zdefiniuj funkcję arr_fun, która w parametrach przyjmie: 
(1) wskaźnik na początek tablicy wektorów, 
(2) wskaźnik na za-ostatni element tej tablicy, 
(3) wskaźnik na początek tablicy wynikowej z obliczonymi długościami oraz 
(4) wskaźnik na funkcję pomocniczą, która zwraca wartość zmiennoprzecinkową 
a w parametrach bierze dwie wartości zmiennoprzecinkowe. 
Zdefiniuj funkcję pomocniczą, która zwróci długość 
wektora przy podaniu przez parametry jego dwóch współrzędnych.
W funkcji głównej stwórz przykładową dynamiczną tablicę wektorów, 
wyznacz za pomocą stworzonej funkcji arr_fun ich długości i wyświetl 
powstałą w ten sposób tablicę wynikową. 
W zadaniu nie można używać funkcji z biblioteki <algorithm>.
Przykład:
IN:     [1.0,1.0  2.0,1.0  1.0,3.0  3.0,1.0]
OUT: [1.414214 2.236068 3.162278 3.162278]

#include <iostream>
#include <cmath>

double lenthOfVector(double x, double y)
{
    return sqrt(pow(x, 2) + pow(y, 2));
}

void arr_fun(double* begin, double* end, double* res_begin, double(*f)(double, double))
{
    while (begin < end)
    {
        double x = *begin;
        double y = *(begin + 1);
        *res_begin = f(x, y); 
        res_begin++;
        begin += 2;
    }
}

int main()
{
    int N;
    std::cout << "Input N. N must be even";
    std::cin >> N;

    int size = N / 2;
    double* vectors = new double[N];
    double* result = new double[size];

    for(int i = 0; i < N; i++)
    {
        std::cin >> vectors[i];
    }

    arr_fun(vectors, vectors + N, result, lenthOfVector);

    for(int i = 0; i < size; i++)
    {
        std::cout << result[i] << " ";
    }

    delete[] vectors;
    delete[] result;
}*/


//Zadanie 4
/*Napisz program, który przyjmie od użytkownika liczbę całkowitą n. 
Utwórz dynamiczną tablicę liczb całkowitych arr i wypełnij ją 
wartościami od użytkownika większymi od 0. Liczby te reprezentują 
liczbę elementów dla kolejnych wierszy nieregularnej tablicy 
dwuwymiarowej arr2d. Następnie utwórz dynamiczną n-elementową 
tablicę wskaźników na tablice liczb zmiennoprzecinkowych arr2d. 
Każdemu wskaźnikowi zarezerwuj pamięć zgodnie z korespondującą 
indeksowo wartością tablicy arr. Wypełnij wszystkie tablice liczbami 
zmiennoprzecinkowymi pobranymi od użytkownika. 
Utwórz dynamiczną n-elementową tablicę liczb zmiennoprzecinkowych 
result, której elementami są sumy 
elementów poszczególnych wierszy tablicy arr2d, a następnie wyświetl jej zawartość.
Przykład:
IN:
    n:       4
    arr:     [3 5 4 1]
    arr2d:   [1.3 2.5 7.1]
             [1.1 3.4 2.2 4.7 1.9]
             [0.4 2.1 7.1 3.9]
             [3.5]
OUT:
    result:  [10.9 13.3 13.5 3.5]

#include <iostream>

int main()
{
    int n;
    std::cout << "Podaj liczbe calkowita n: ";
    std::cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    float **arr2d = new float *[n];
    for (int i = 0; i < n; i++)
    {
        arr2d[i] = new float[arr[i]];
        for (int j = 0; j < arr[i]; j++)
        {
            std::cin >> arr2d[i][j];
        }
    }

    float *result = new float[n];
    for (int i = 0; i < n; i++)
    {
        result[i] = 0;
        for (int j = 0; j < arr[i]; j++)
        {
            result[i] += arr2d[i][j];
        }
    }

    std::cout << "result: [";
    for (int i = 0; i < n; i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << "]" << std::endl;

    for (int i = 0; i < n; i++)
    {
        delete[] arr2d[i];
    }
    delete[] arr2d;
    delete[] arr;
    delete[] result;
    return 0;
}*/

//Zadanie 5
/*Napisz program, który przyjmuje od użytkownika dwie liczby całkowite n i m. 
Utwórz dynamiczną tablicę dwuwymiarową liczb całkowitych nieujemnych arr2d o 
rozmiarze nx2m i wypełnij ją losowymi wartościami z przedziału <0,10). 
Następnie utwórz drugą dynamiczną tablicę dwuwymiarową liczb 
zmiennoprzecinkowych arr2d_2 o n wierszach. Korzystając z kolejnych elementów 
tablicy arr2d wypełnij kolejne wiersze tablicy arr2d_2 w następujący sposób: 
kolejne dwa elementy z każdego wiersza scal w liczbę zmiennoprzecinkową, 
w której mniejsza z tych dwóch liczb będzie częścią całkowitą, a większa - częścią ułamkową. 
Następnie wyświetl zawartość tablicy arr2d_2.
Przykład:
IN:
    n: 3
    m: 4
    arr2d:  
    [3 5 2 3 5 0 3 3]
    [0 4 1 2 0 1 9 1]
    [3 1 6 0 1 2 2 9]
OUT:
    arr2d_2:
    [3.5 2.3 0.5 3.3]
    [0.4 1.2 0.1 1.9]
    [3.1 0.6 1.2 2.9]

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    int n, m;
    std::cout << "Input size of array arr2d Nx2*M\n";
    std::cin >> n >> m;
    srand(time(NULL));

    unsigned int** arr2d = new unsigned int*[n];
    for(int i = 0; i < n; i++){
        arr2d[i] = new unsigned int[2*m];
        for(int j = 0; j < m * 2; j++){
            arr2d[i][j] = rand()%11;
            std::cout << arr2d[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    double** arr2d_2 = new double*[n];
    for(int i = 0; i < n; i++){
        arr2d_2[i] = new double[m];
        for(int j = 0; j < m; j++){
            if(arr2d[i][j*2] <= arr2d[i][j*2 + 1])
            {
                arr2d_2[i][j] = ((double)(arr2d[i][j*2 + 1])/10) + (double)(arr2d[i][j*2]); 
                
            }
            else if(arr2d[i][j*2] > arr2d[i][j*2 + 1])
            {
                arr2d_2[i][j] = (double)(arr2d[i][j*2 + 1]) + ((double)(arr2d[i][j*2]) / 10); 
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cout << arr2d_2[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for(int i = 0; i < n; i++){
        delete[] arr2d[i];
        delete[] arr2d_2[i];
    }
    delete[] arr2d;
    delete[] arr2d_2;

}*/

//Zadanie 6
/*Ranking gry NewCSShooter przechowywany jest  na serwerze w następujący sposób:
MystiqueHero;1365;6890;15210
Frizz;5400;6200;11000
Każdy wiersz reprezentuje statystyki rozegranych meczy dla danego użytkownika. 
Pojedynczy wiersz zawiera następujące informacje oddzielone od siebie średnikiem: 
nazwa użytkownika, ilość wygranych meczy, ilość rozegranych meczy, ilość dokonanych likwidacji. 
Przykład 
    MystiqueHero;1365;6890;15210,
można zinterpretować, że gracz MystiqueHero wygrał 1365 meczy na 6890 wszystkich 
rozegranych meczy i dokonał 15210 likwidacji.
Zbuduj ranking graczy obliczając ich wynik rankingowy. 
Napisz funkcję, która przyjmuje dynamiczną tablicę napisów (c-registrations), 
w której w każdym elemencie przechowywany jest zapis statystyki danego 
gracza oraz drugą taką tablicę  wyjściową na wyniki. Funkcja powinna w 
drugą tablicę wyjściową wpisać informacje o graczu oraz jego wynik liczony 
w następujący sposób: wygrane mecze  + wszystkie mecze + ilość likwidacji. 
Możesz założyć że nazwa użytkownika to nie więcej niż 12 znaków oraz całkowity 
wynik to liczba całkowita złożona z maksymalnie 10 cyfr. 
Napisz program testujący zaimplementowaną funkcję.
IN:
[
“MystiqueHero;1365;6890;15210”,
“Frizz;5400;6200;11000”,
“Ziemniak;9965;11000;73000”,
“Evel00na;10;10;90”
]
OUT:
[
“MystiqueHero 23465”, //(bo 1365 + 6890 + 15210 = 23465)
“Frizz 22600”,
“Ziemniak 93965”,
“Evel00na 110”,
]



#include <iostream>
#include <cstring>
#include <cstdlib>

void ratingOfPlayers(char** players, char** result)
{
    char* name = new char[12];
    char* score = new char[10];
    char wins[10], all[10], kills[10];
    int i = 0;
    
    while(players[i] != nullptr){
        int j = 0;
        int rank = 0;
        while(players[i][j] != ';'){
            name[j] = players[i][j];
            j++;
        }
        name[j] = '\0';
        int k = 0;
        while (players[i][j + 1] != ';')
        {
            wins[k] = players[i][j + 1];
            j++;
            k++;
        }
        wins[k] = '\0';
        k = 0;
        while (players[i][j + 2] != ';')
        {
            all[k] = players[i][j + 2];
            j++;
            k++;
        }
        all[k] = '\0';
        k = 0;
        while (players[i][j + 3] != '\0')
        {
            kills[k] = players[i][j + 3];
            j++;
            k++;
        }
        kills[k] = '\0';
        rank = atoi(wins) + atoi(all) + atoi(kills);

        score = itoa(rank, score, 10);

        strcpy(result[i], name);
        strcat(result[i], " ");
        strcat(result[i], score);
        i++;
    }
    delete[] name;
    delete[] score;
}

int main()
{
    int n;

    //std::cin >> n;
    char** players = new char*[5];
    for(int i = 0; i < 4; i++)
    {
        players[i] = new char[100];
    }
    players[0] = "MystiqueHero;1365;6890;15210";
    players[1] = "Frizz;5400;6200;11000";
    players[2] = "Ziemniak;9965;11000;73000";
    players[3] = "Evel00na;10;10;90";
    players[4] = new char[1];
    players[4] = nullptr;

    char** result = new char*[5];
    for(int i = 0; i < 4; i++)
    {
        result[i] = new char[24];
    }
    result[4] = new char[1];
    result[4] = nullptr;

    ratingOfPlayers(players, result);
    for(int i = 0; i < 4; i++)
    {
        std::cout << result[i] << std::endl;
    }


    for(int i = 0; i < 4 + 1; i++)
    {
        delete[]players[i];
        delete[]result[i];
    }
    delete[]players;
    delete[]result;
}*/

//Zadanie 7
/*Napisz funkcję, która przyjmuje dwie równoliczne dynamiczne tablice wskaźników na napisy (c-registrations). 
W pierwszej tablicy, w każdym napisie zapisana jest tablica rejestracyjna, która została przechwycona 
przez fotoradar. Zakładamy że każda tablica rejestracyjna rozpoczyna się od dwóch lub trzech liter 
wskazujących miejscowość rejestracji, a następnie biały znak oraz ciąg cyfr (długość ciągu to 4 lub 5 cyfr). 
Należy pomóc jednostce policji w pogrupowaniu rejestracji według miejscowości, aby odpowiednio rozesłać 
poszczególnym jednostkom numery rejestracji wskazane do wystawienia mandatu. 
Funkcja powinna zapisać do drugiej tablicy napisy, które są połączeniem tablic rejestracyjnych dla 
konkretnego województwa (zobacz przykład). Funkcja ma zwrócić liczbę napisów w wyjściowej tablicy. 
Kolejność województw i rejestracji pojazdów w tablicy wynikowej nie ma znaczenia. 
Napisz program testujący zaimplementowaną funkcję.
IN:
[
“LRY 1234”,
“LU 87654”,
“WA 1234”,
“LRY 888”,
“LU 999”
]
OUT:
[
“LRY 1234 888”,
“LU 87654 999”,
“WA 1234”
]

#include <iostream>
#include <cstring>
#include <vector>

int Fun(char** str, char** result, const int size)
{
	char** strings = new char* [size]; //таблиця букв(ВОЄВУДСТВ)
	char** values = new char* [size];  //таблиця цифр(ВОЄВУДСТВ)
	char** result_copy = new char* [size]; //таблиця, до якої потім скопіюю таблицю result
	for (int i = 0; i < size; i++) //ініціалізація пам'яті
	{
		strings[i] = new char[4];
		values[i] = new char[6];
		result_copy[i] = new char[255];
	}

	for (int i = 0; i < size; i++) //копіювання букв номерних знаків
	{
		int j = 0;
		for (; str[i][j] != ' '; j++)
		{
			strings[i][j] = str[i][j];
		}
		strings[i][j] = '\0';
	}

	for (int i = 0; i < size; i++) //копіювання цифр номерних знаків
	{
		bool isSpace = false;
		int j = 0, idx = 0;
		for (; str[i][j] != '\0'; j++)
		{
			if (str[i][j - 1] == ' ') isSpace = true;
			if (isSpace)
				values[i][idx++] = str[i][j];
		}
		if (isSpace) values[i][idx] = '\0';
	}

	int idx = 0; //індекс кількісті унікальних воєвудств(а ще за умовою функція має його повернути)

	for (int i = 0; i < size; i++) //логіка, яка записує до таблиці result унікальні воєвудства(ТОБТО БУКВИ)
	{
		int different_province = 0;
		for (int j = 0; j < size; j++)
		{
			if (i == j) continue;
			if (strcmp(strings[i], result[j]) != 0) different_province++;
		}
		if (different_province == size-1)
			strcpy(result[idx++], strings[i]);
	}

	for (int i = 0; i < idx; i++) //копіювання таблиці result з унікальними воєвудствами(ТОБТО БУКВАМИ)
		strcpy(result_copy[i], result[i]);

	for (int i = 0; i < idx; i++) //порівняння елементів таблиці result з елементами таблиці strings і присвоєння до таблиці result цифр з таблиці values
	{
		for (int j = 0; j < size; j++)
		{
			if (strcmp(result_copy[i], strings[j]) == 0)
			{
				strcat(result[i], " ");
				strcat(result[i], values[j]);
			}
		}
	}

	for (int i = 0; i < idx; i++) //вивід таблиці написів result
		std::cout << result[i] << std::endl;

	for (int i = 0; i < size; i++) //очищення пам'яті
	{
		delete[] strings[i];
		delete[] values[i];
		delete[] result_copy[i];
	}
	delete[] strings;
	delete[] values;
	delete[] result_copy;

	return idx;
}

int main()
{
    const int size = 8, buf = 255;
    char** str = new char* [size];
    char** result = new char* [size];
    for (int i = 0; i < size; i++)
    {
        str[i] = new char[10];
        result[i] = new char[buf];
        strcpy(result[i], ""); // Ініціалізація кожного елемента result пустим рядком
    }

    strcpy(str[0], "LRY 1234");
    strcpy(str[1], "LU 87654");
    strcpy(str[2], "WA 1234");
    strcpy(str[3], "LRY 888");
    strcpy(str[4], "LU 999");
    strcpy(str[5], "WA 111");
    strcpy(str[6], "BR 555");
    strcpy(str[7], "LRY 786");

    Fun(str, result, size);
    
    for (int i = 0; i < size; i++)
    {
        delete[] str[i];
        delete[] result[i];
    }
    delete[] str;
    delete[] result;
}
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

int registerFunction(string *registrations, string *result, int n)
{
    unordered_map<string, string> m;
    for(int i = 0; i < n; i++)
    {
        stringstream ss(registrations[i]);
        string key, value;
        ss >> key >> value;
        m[key] += " " + value;
    }
    int i = 0;
    for(auto it = m.begin(); it != m.end(); it++)
        result[i++] = it->first + it->second;
    
    return i; 
}

int main()
{
    int n = 10;
    string* registrations = new string[n];
    
    string* result = new string[n];
    registrations[0] = "WA 1234";
    registrations[1] = "LRY 1234";
    registrations[2] = "LU 87654";
    registrations[3] = "LRY 888";
    registrations[4] = "LU 999";
    registrations[5] = "WA 111";
    registrations[6] = "BR 555";
    registrations[7] = "WA 1234";
    registrations[8] = "LRY 1234";
    registrations[9] = "LU 87654";
    int size = registerFunction(registrations, result, n);
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << endl;
    }

    delete[] registrations;
    delete[] result;
}*/

//Zadanie 8 
/*Radar morski na statku to prawdopodobnie najczęściej używany 
sprzęt elektroniczny podczas nawigacji. To doskonałe narzędzie 
do wykrywania obiektów wokół nas. Niestety jesteśmy tak bardzo 
uzależnieni od radaru, że czasami używamy go częściej niż własnych 
oczu do obserwacji wokół. Jednakże inna sytuacja miała miejsce, gdy 
pewien marynarz odczytywał dane z notatek pozostawionych na pokładzie 
swojego statku. W notatkach kapitan pokładu zapisał położenia N obiektów 
na morzu za pomocą współrzędnych biegunowych w następujący sposób:
    R1 F1 R2 F2 ... Rn Fn
gdzie R to promień wodzący obiektu (odległość), zaś F to amplituda punktu (wartość kąt skierowanego w radianach).
Zaimplementuj funkcję, która posortuje dane przedstawione w notatce tak, 
aby obiekty były w kolejności od najmniej do najbardziej odległego od 
statku naszego bohatera, który znajduje się w punkcie (0, 0). W sytuacji, 
gdy oba obiekty są tak samo odległe należy wybrać ten o większej amplitudzie.
Napisz program, który przetestuje działanie tej funkcji i wyświetli 
współrzędne w układzie kartezjańskim tych obiektów w odpowiedniej kolejności.
Konwersja ze współrzędnych biegunowych do kartezjańskich:
   x = R * cos(F)
   y = R * sin(F)
Przykład:
IN:   [1.2 6.1 1.2 1.1 5.4 3.1]
OUT:
    1.179 -0.219
    0.544  1.069
   -5.395  0.225


#include <iostream>
#include <cmath>

void sortOfObjects(double* cordinates, int number)
{
    double* result = new double[number * 2];

    for(int i = 0; i < number; i++)
    {
        result[i * 2] = cordinates[i * 2] * cos(cordinates[i * 2 + 1]);
        result[i * 2 + 1] = cordinates[i * 2] * sin(cordinates[i * 2 + 1]);
    }
    for(int i = 0; i < number; i++)
    {
        for(int j = 0; j < number - 1; j++)
        {
            if(sqrt(pow(result[j * 2], 2) + pow(result[j * 2 + 1], 2)) > sqrt(pow(result[(j + 1) * 2], 2) + pow(result[(j + 1) * 2 + 1], 2)))
            {
                double tmp = result[j * 2];
                result[j * 2] = result[(j + 1) * 2];
                result[(j + 1) * 2] = tmp;

                tmp = result[j * 2 + 1];
                result[j * 2 + 1] = result[(j + 1) * 2 + 1];
                result[(j + 1) * 2 + 1] = tmp;
            }
            else if(sqrt(pow(result[j * 2], 2) + pow(result[j * 2 + 1], 2)) == sqrt(pow(result[(j + 1) * 2], 2) + pow(result[(j + 1) * 2 + 1], 2)))
            {
                if(cordinates[j * 2 + 1] < cordinates[(j + 1) * 2 + 1])
                {
                    double tmp = result[j * 2];
                    result[j * 2] = result[(j + 1) * 2];
                    result[(j + 1) * 2] = tmp;

                    tmp = result[j * 2 + 1];
                    result[j * 2 + 1] = result[(j + 1) * 2 + 1];
                    result[(j + 1) * 2 + 1] = tmp;
                }
            }
        }
    }

    for(int i = 0; i < number; i ++){
        std::cout << result[i * 2] << "   " << result[i * 2 + 1] << std::endl;
    }
    delete[] result;
}

int main()
{
    int N;
    std::cin >> N;

    double* cordinates = new double[N * 2]; 
    std::cout << "Input cordinates of objects in polar system\n";
    for(int i = 0; i < N * 2; i++)
    {
        std::cin >> cordinates[i];
    }

    sortOfObjects(cordinates, N);

    delete[] cordinates;
}*/








