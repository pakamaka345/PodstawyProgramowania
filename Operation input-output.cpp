//Zadanie 1
/*Stwórz funkcję, która przyjmuje ścieżkę do pliku tekstowego. 
W pliku tekstowym znajdują się posortowane rosnąco liczby całkowite 
oddzielone pojedynczymi spacjami. Funkcja powinna wczytać te liczby 
do tablicy i znaleźć w nich wartość minimalną i maksymalną.


#include <iostream>
#include <fstream>

using namespace std;

void fun(string name)
{
    ifstream file(name);
    int a, min, max;
    file >> a;
    min = a;
    max = a;
    while (file >> a){
        if (a < min){
            min = a;
        }
        if (a > max){
            max = a;
        }
    }
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    file.close();
}

int main()
{
    fun("c:/project/c++/files/test.txt");
    return 0;
}*/

//Zadanie 2
/*Napisz program, który zapisze do pliku 10 dowolnych liczb całkowitych.


#include <iostream>
#include <fstream>

int main()
{
    std::ofstream file ("c:/project/c++/files/test.txt");
    for(int i = 0; i < 10; i++){
        file << (double)(rand() % 101) / 100 << " ";
    }
    file.close();
}*/

//Zadqnie 3
/*Napisz program, który usunie plik stworzony w poprzednim zadaniu.

#include <iostream>
#include <fstream>

int main()
{
    std::remove("c:/project/c++/files/test.txt");
}*/


//Zadanie 4
/*Stwórz funkcję, która przyjmuje ścieżkę do pliku tekstowego. 
W pliku tekstowym znajdują się liczby całkowite oddzielone 
pojedynczymi spacjami. Funkcja powinna wczytać te liczby 
zwiększyć o jeden i ponownie zapisać do pliku. */


/*
#include <iostream>
#include <cstdio>
#include <fstream>

void fun(std::string name){
    std::fstream file(name);
    int a, i;
    for( i = 0; file >> a; i++);
    int* tab = new int[i];
    file.clear();
    file.seekg(0);
    for(i = 0; file >> tab[i]; i++);
    file.clear();
    file.seekg(0);
    for(int j = 0; j < i; j++){
        file << tab[j]+1 << " "; 
    }
    file.close();
    delete[] tab;
}

int main()
{
    fun("c:/project/c++/files/test.txt");
    return 0;
}*/

//Zadanie 5
/*Stwórz funkcję write_array(), która zapisze podaną w 
argumencie tablicę liczb zmiennoprzecinkowych (float) 
do pliku (nazwa podana w argumencie funkcji) w postaci 
binarnej (nieformatowanej), gdzie każdy element tablicy jest kodowany na czterech bajtach.
Stwórz analogiczną funkcję read_array(), 
która wczyta z takiego pliku (nazwa podana w argumencie funkcji) 
dane do przekazanej w argumencie tablicy liczb zmiennoprzecinkowych (float). 
Funkcja powinna wczytać nie więcej elementów niż zadeklarowana wielkość tablicy 
i zwrócić rzeczywistą ilość wczytanych elementów.

#include <iostream>
#include <fstream>

using namespace std;

void write_array(float* arr, int size, string path){
    ofstream file(path, ios::binary);
    if(!file){
        return;
    }
    for(int i = 0; i < size; i++){
        file.write((char*)&arr[i], sizeof(float));
    }
    file.close();
}

int read_array(float* arr, int size, string path){
    ifstream file(path, ios::binary);
    if(!file){
        return 0;
    }
    int i = 0;
    for(; i < size; i++){
        file.read((char*)&arr[i], sizeof(float));
    }
    file.close();
    return i;
}

int main()
{
    float arr[10] = {1.1, 2.2, 3.3, 4.4, 5.5};
    write_array(arr, 10, "c:/project/c++/files/test.txt");
    float arr2[10];
    int size = read_array(arr2, 10, "c:/project/c++/files/test.txt");
    for(int i = 0; i < size; i++){
        cout << arr2[i] << " ";
    }
    cout << endl;

}*/

//Zadanie 6
/*Stwórz prostą strukturę do obsługi macierzy. Zdefiniuj funkcje write_mat() i read_mat() 
do zapisu/odczytu macierzy do/z pliku tekstowego (formatowanego). Plik tekstowy ma być 
sformatowany w ten sposób, że w pierwszym wierszu są dwie liczby całkowite: szerokość 
i wysokość macierzy a w następnych liniach są zapisane kolejno elementy macierzy 
rozdzielone spacją w postaci liczb zmiennoprzecinkowych.

Przykładowy plik wejściowy:
5 3
1.0 2.0 3.0 4.0 5.0
6.0 7.0 8.0 9.0 0.0
3.0 5.0 7.0 9.0 1.0

#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>

using namespace std;

struct Matrix{
    int n, m;
    double* arr;

    void init(){
        arr = new double[n * m];
    }
    ~Matrix(){
        delete[] arr;
    }
};

void write_mat(Matrix& mat, std::string path){
    ofstream file(path);
    if(!file){
        return;
    }
    file << mat.n << " " << mat.m << endl;

    for (int i = 0; i < mat.m; i++){
        for (int j = 0; j < mat.n; j++){
            file << mat.arr[i * mat.n + j] << " ";
        }
        file << endl;
    }
    file.close();
}

void read_mat(Matrix& mat, std::string path){
    ifstream file(path);
    if(!file){
        return;
    }
    file >> mat.n >> mat.m;
    mat.init();
    for (int i = 0; i < mat.m * mat.n; i++){
        file >> mat.arr[i];
    }
    file.close();
}

int main()
{
    Matrix mat;
    mat.n = 5;
    mat.m = 3;
    mat.init();
    for (int i = 0; i < mat.n * mat.m; i++){
        mat.arr[i] = i;
    }
    write_mat(mat, "c:/project/c++/files/test.txt");
    read_mat(mat, "c:/project/c++/files/test.txt");
}*/

//Zadanie 7
/*Zdefiniuj funkcje write_bin_mat() i read_bin_mat() 
do zapisu/odczytu macierzy do/z pliku binarnego (nieformatowanego). 
Plik binarny ma być skonstruowany w ten sposób, że pierwsze dwa bajty 
kodują szerokość macierzy a dwa kolejne wysokość macierzy (liczba całkowita) a 
następnie jest sekwencja wszystkich elementów macierzy 
kodowanych na czterech bajtach każdy (liczba typu float).

#include <iostream>
#include <fstream>

using namespace std;

struct Matrix{
    int n, m;
    double* arr;

    void init(){
        arr = new double[n * m];
    }
    ~Matrix(){
        delete[] arr;
    }
};

void write_bin_mat(Matrix& mat, std::string path){
    ofstream file(path, ios::binary);
    if(!file){
        return;
    }
    //file << mat.n << " " << mat.m << endl;

    file.write((char*)&mat.n, sizeof(int));
    file.write((char*)&mat.m, sizeof(int));

    for(int i = 0; i < mat.m; i++){
        for (int j = 0; j < mat.n; j++){
            file.write((char*)&mat.arr[i * mat.n + j], sizeof(double));
        }
    }
    file.close();
}

void read_bin_mat(Matrix& mat, std::string path){
    ifstream file(path, ios::binary);
    if(!file){
        return;
    }
    file.read((char*)&mat.n, sizeof(int));
    file.read((char*)&mat.m, sizeof(int));
    mat.init();
    for (int i = 0; i < mat.m * mat.n; i++){
        file.read((char*)&mat.arr[i], sizeof(double));
    }
    file.close();
}

int main()
{
    Matrix mat;
    mat.n = 5;
    mat.m = 3;
    mat.init();
    for (int i = 0; i < mat.n * mat.m; i++){
        mat.arr[i] = i;
    }
    write_bin_mat(mat, "c:/project/c++/files/test.txt");
    read_bin_mat(mat, "c:/project/c++/files/test.txt");
}*/

//Zadanie 8
/*Napisz program, który wczyta z pliku tekstowego wszystkie napisy do tablicy napisów.

#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int main()
{
    ifstream file("c:/project/c++/files/test.txt");
    int i = 0;
    string a;

    for(; file >> a; i++);
    string *text = new string[i];

    file.clear();
    file.seekg(0);

    for(int j = 0; j < i; j++)
    {
        file >> text[j];
        cout << text[j] << " ";
    }
    file.close();
    delete[] text;
}*/

//Zadanie 9
/*Napisz funkcje, która przyjmuje ścieżkę do pliku tekstowego oraz 5-cio 
literowe słowo wczytane od użytkownika. Funkcja powinna znaleźć w pliku 
ciąg znaków "*****"  i zamienić ten ciąg gwiazdek na słowo wczytane od 
użytkownika. Np. Ala ma *****. -> Ala ma rybke.

#include <iostream>
#include <fstream>

using namespace std;

void fun(string name, string word)
{
    fstream file(name);
    string a;
    while (file >> a){
        if(a.compare("*****") == 0){
            file.seekg(-5, ios::cur);
            file << word;
        }
    }
    file.close();
}

int main()
{
    fun("c:/project/c++/files/exercise8.txt", "test");
    return 0;
}*/

//Zadanie 10
/*Zmodyfikuj poprzednią funkcję tak aby 
możliwe było wprowadzenie dowolnie długiego 
napisu w miejsce gwiazdek. Gwiazdki mogą wystąpić więcej niż jeden raz.

#include <iostream>
#include <fstream>

using namespace std;

void fun(string name, string word)
{
    ifstream file(name);
    string a, result;
    while (file >> a){
        if(a.compare("*****") == 0){
            result += word;
        }
        else{
            result += a;
        }
        result += " ";
    }
    file.close();
    ofstream file2(name, ios::trunc);
    file2 << result;
    file2.close();
}

int main()
{
    fun("c:/project/c++/files/exercise8.txt", "test");
    return 0;
}*/

//Zadanie 11
/*Zdefiniuj strukturę City opisującą miasto i zawierającą składowe: nazwa miasta (string), 
ilość mieszkańców (uint), dwie współrzędne geograficzne (2x double).
Zdefiniowany jest plik tekstowy typu csv (coma-separated values, 
https://pl.wikipedia.org/wiki/CSV_(format_pliku)) zawierający listę takich miast. 
W programie głównym wczytaj z tego pliku dane i stwórz na ich podstawie tablicę obiektów typu City.

Przykładowy plik cities.csv:
------------------------------------------------------------------------------------------------
nazwa_miasta,ilosc_mieszkancow,dlugosc_geogr,szerokosc_geogr
Lublin,340000,51.253305,22.559572
Warszawa,1790658,52.250691,21.016754
Stalowa_Wola,60179,50.581978,22.054380
------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct City{
    string name;
    unsigned int population;
    double x, y;
};


int main()
{
    ifstream file("c:/project/c++/files/cities.csv");
    if(!file){
        return 1;
    }
    string line;
    int size = 0;
    while(getline(file, line)){
        size++;
    }
    size--;
    City* arr = new City[size];
    file.clear();
    file.seekg(0);
    getline(file, line);
    int i = 0;
    while(getline(file, line)){
        stringstream ss(line);
        string token;
        getline(ss, token, ',');
        arr[i].name = token;
        getline(ss, token, ',');
        arr[i].population = stoi(token);
        getline(ss, token, ',');
        arr[i].x = stod(token);
        getline(ss, token, ',');
        arr[i].y = stod(token);
        cout << arr[i].name << " " << arr[i].population << " " << arr[i].x << " " << arr[i].y << endl;
        i++;
    }
    
    delete[] arr;
    file.close();
}*/