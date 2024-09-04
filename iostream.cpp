//Zadanie1
/*Napisz program, który wypisze na ekranie treść swojego kodu źródłowego.

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    FILE* fp = fopen("../iostream.cpp", "r");
    if(fp == nullptr) cout << "Error " << endl;

    char c;
    while((c = fgetc(fp)) != EOF) 
    {
        putchar(c);
    }
    fclose(fp);
}*/


//Zadanie2
/*Napisz program, który policzy wszystkie słowa w podanym napise

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    string napis = "Napisz program, ktory policzy wszystkie slowa w podanym napise";
    stringstream ss(napis);
    string word;
    int count;
    while(ss>>word){
        cout << word << endl;
        count++;
    }
    cout << "count = " << count;
}*/

//Zadanie 3
/*Wydrukuj na ekranie kilka wylosowanych liczb całkowitych 
z przedziału 0..1000 w taki sposób, aby zawsze cyfra jedności 
danej liczby znajdowała się podcyfrą jednoci poprzedniej liczby. 
Wydrukuj te liczby ponownie w postaci szesnastkowej.

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    srand(time(0));
    int a = rand() % 1001;
    int b = rand() % 1001;
    int c = rand() % 1001;
    cout.fill(' ');
    cout << right << setw(4) << a << endl;
    cout << right << setw(4) << b << endl;
    cout << right << setw(4) << c << endl;
    cout << hex << a << " " << hex << b << " " << hex << c << endl;
}*/


//Zadanie 4
/*Napisz program, który dopisze na końcu 
podanego w linii poleceń pliku aktualną datę i czas w formacie "DD-MM-YYYY hh:mm:ss".

#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>
using namespace std;

int main()
{
    FILE* fp = fopen("C:/project/C++/files/time.txt", "a");
    if(fp == nullptr){
        cout << "Error";
        return 1;
    }
    time_t time_1 = time(0);
    tm* localTime = localtime(&time_1);
    char str[20];
    strftime(str, 20, "%d-%m-%Y %H:%M:%S", localTime);
    fprintf(fp, "\n%s", str);
    fclose(fp);
}

#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

using namespace std;

int main()
{
    ofstream file("C:/project/C++/files/time.txt", ios::app);
    if(file.is_open()){
        auto now = chrono::system_clock::now();
        time_t now_c = chrono::system_clock::to_time_t(now);

        tm *timeinfo;
        char buffer[80];

        timeinfo = localtime(&now_c);
        strftime(buffer, 80, "%d-%m-%Y %H:%M:%S", timeinfo);
        file << buffer << endl;
        file.close();
    }
}*/

//Zadanie 5
/*Napisz program, który wczyta z podanego w linii 
poleceń pliku wszystkie daty i czas (o formacie "DD-MM-YYYY hh:mm:ss"), 
doda do każdej daty 15 dni i 37 godzin i wyświetli nową datę/czas w tym samym formacie. 
Możesz wykorzystać funkcje time(), localtime() i mktime() z biblioteki <ctime>.

#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

#include <sstream>

int main()
{
    ifstream file("C:/project/C++/files/time.txt");
    if(file.is_open()){
        string line;
        while(getline(file, line)){
            tm time = {};
            istringstream ss(line);
            ss >> get_time(&time, "%d-%m-%Y %H:%M:%S");
            time.tm_mday += 15;
            time.tm_hour += 37;
            time_t t = mktime(&time);
            tm* newTime = localtime(&t);
            cout << put_time(newTime, "%d-%m-%Y %H:%M:%S") << endl;
        }
    }
}*/


//Zadanie 6
/*Napisz program, który w pliku tekstowym znajdzie 
wszystkie słowa, które zawierają podciąg liter "any". Wypisz te słowa na ekranie.
#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstring>

int main()
{
    FILE* fp = fopen("C:/project/C++/files/time.txt", "r");
    if(fp == nullptr) return 1;

    char word[101];
    while(fscanf(fp, "%100s", word)==1){
        if(strstr(word, "any") != nullptr)
        printf("%s", word);
    }
    fclose(fp);
}*/

//Zadanie 7
/*Napisz program w języku C++, który będzie w stanie zaszyfrować 
i odszyfrować wiadomość szyfrem AtBash. Szyfr AtBash jest to 
prosty monoalfabetyczny szyfr podstawieniowy pochodzenia hebrajskiego, 
którego działanie polega na zamianie litery leżącej w odległości X od 
początku alfabetu na literę leżącą w odległości X od jego końca. 
Szyfrowanie powinno usuwać wszystkie białe znaki w tekście. 



#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void encryption(string &s)
{
    string result;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            result += 'z' - (s[i] - 'a');
        }
        else if(s[i] >= 'A' && s[i] <= 'Z')
        {
            result += 'Z' - (s[i] - 'A');
        }
    }
    s = result;
}

void decryption(string &s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = 'z' - (s[i] - 'a');
        }
        else if(s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = 'Z' - (s[i] - 'A');
        }
    }
}

int main()
{
    ifstream file1("C:/project/C++/files/encrypt.txt");
    string line, encrypted;
    while(getline(file1, line))
    {
        encryption(line);
        encrypted += line;
    }
    file1.close();

    decryption(encrypted);

    ofstream file2("C:/project/C++/files/decrypt.txt", ios::out);
    if(file2.is_open())
    {
        file2 << encrypted;
        file2.close();
    }
}*/

//Zadanie 8
/*Napisz program, który umożliwi użytkownikowi wprowadzenie wiadomości zawierającej 
informacje o jego imieniu, wieku, wzroście i wadze w następującym formacie np. 
"Ala 12 162.52 52.28". Odczytaj informacje z tak przekazanej wiadomości i zapisz je w odpowiednich zmiennych. 
Następnie program powinien wyświetlić te informację w następujący sposób:
  Imię
     Wiek (w systemie szesnastkowym)
          Wzrost (z dokładnością do 2 miejsc po przecinku)
  Waga (z dokładnością do 3 miejsc po przecinku)


#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    string napis = "Ala 12 162.52 52.28";
    stringstream ss(napis);
    string word;
    ss >> word;
    cout << "name = " << word << endl;
    ss >> word;
    cout << "int = " << hex << stoi(word) << endl;
    ss >> word;
    cout << fixed << setprecision(2) << stof(word) << endl;
    ss >> word;
    cout << fixed << setprecision(3) << stof(word) << endl;
}*/

//Zadanie 9
/*Zdefiniuj strukturę City opisującą miasto i zawierającą składowe: 
nazwa miasta (string), ilość mieszkańców (uint), dwie współrzędne geograficzne (2x double). 
Zdefiniuj operator wstawiania do strumienia wejściowego (operator<<) 
tak aby można było używać klasy City bezpośrediono z std::cout.


#include <iostream>
#include <string>
using namespace std;


struct City{
    string name;
    unsigned int population;
    double x;
    double y;
};

ostream& operator<<(ostream &os, City& miasto)
{
    os << miasto.name << " " << miasto.population << endl << miasto.x << " " << miasto.y;
    return os;
}

int main()
{
    City miasto;
    miasto.name = "Kaminets-Podilskij";
    miasto.population = 98000;
    miasto.x = 51.4444435;
    miasto.y = 46.9949959;

    cout << miasto;

}*/

//Zadanie 10
/*Zdefiniowany jest plik tekstowy typu csv (coma-separated values, 
https://pl.wikipedia.org/wiki/CSV_(format_pliku)) zawierający listę miast, 
ilość mieszkańców i współrzędne geograficzne. W programie głównym wczytaj z 
tego pliku dane i stwórz na ich podstawie tablicę obiektów typu City 
(zdefiniowanych w poprzednim zadaniu).
Przykładowy plik cities.csv:
------------------------------------------------------------------------------------------------
nazwa_miasta,ilosc mieszkancow,dlugosc geogr,szerokosc geogr
Lublin,340000,51.253305,22.559572
Warszawa,1790658,52.250691,21.016754
Stalowa_Wola,60179,50.581978,22.054380
------------------------------------------------------------------------------------------------


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


struct City{
    string name;
    unsigned int population;
    double x;
    double y;
};

ostream& operator<<(ostream &os, City& miasto)
{
    os << miasto.name << " " << miasto.population << endl << miasto.x << " " << miasto.y;
    return os;
}

int main()
{
    ifstream file("C:/project/C++/files/cities.csv");
    if(!file.is_open()) return 1;
    string line;
    int size = 0;
    while(getline(file, line))
    {
        size++;
    }
    City* cities = new City[size];
    file.clear();
    file.seekg(0);
    int i = 0;
    while(getline(file, line))
    {
        stringstream ss(line);
        string token;
        getline(ss, token, ',');
        cities[i].name = token;
        getline(ss, token, ',');
        cities[i].population = stoi(token);
        getline(ss, token, ',');
        cities[i].x = stod(token);
        getline(ss, token, ',');
        cities[i].y = stod(token);
        i++;
    }
    for(int i = 0; i < size; i++)
    {
        cout << cities[i] << endl;
    }
    file.close();
    delete[] cities;
}*/

//Zadanie 11
/*Dla struktury City opracuj binarny format pliku 
do przechowywania danych o miastach. Napisz funkcje 
do zapisu i odczytu tablicy z miastami z tak zdefiniowanego pliku binarnego.*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


struct City{
    string name;
    unsigned int population;
    double x;
    double y;
};

ostream& operator<<(ostream &os, City& miasto)
{
    os << miasto.name << " " << miasto.population << endl << miasto.x << " " << miasto.y;
    return os;
}

void saveToFile(City* cities, int size)
{
    ofstream file("C:/project/C++/files/cities.bin", ios::binary);
    if(file.is_open())
    {
        for (int i = 0; i < size; i++)
        {
            size_t len = cities[i].name.length();
            file.write((char*)&len, sizeof(size_t));
            file.write(cities[i].name.c_str(), len);
            file.write((char*)&cities[i].population, sizeof(unsigned int));
            file.write((char*)&cities[i].x, sizeof(double));
            file.write((char*)&cities[i].y, sizeof(double));
        }
        file.close();
    }
}

void readFromFile(City* cities, int size)
{
    ifstream file("C:/project/C++/files/cities.bin", ios::binary);
    if(file.is_open())
    {
        for (int i = 0; i < size; i++)
        {
            size_t len;
            file.read((char*)&len, sizeof(size_t));
            char* buf = new char[len + 1];
            file.read(buf, len);
            buf[len] = '\0';
            cities[i].name = buf;
            delete[] buf;
            file.read((char*)&cities[i].population, sizeof(unsigned int));
            file.read((char*)&cities[i].x, sizeof(double));
            file.read((char*)&cities[i].y, sizeof(double));
        }
        file.close();
    }
}

int main()
{
    City cities[3] = {
        {"Lublin", 340000, 51.253305, 22.559572},
        {"Warszawa", 1790658, 52.250691, 21.016754},
        {"Stalowa_Wola", 60179, 50.581978, 22.054380}
    };
    saveToFile(cities, 3);
    City cities2[3];
    readFromFile(cities2, 3);
    for(int i = 0; i < 3; i++)
    {
        cout << cities2[i] << endl;
    }
}