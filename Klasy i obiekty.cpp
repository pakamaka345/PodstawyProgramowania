//Zadanie 1
/*Napisz program, który zdefiniuje typ złożony Point 
reprezentujący punkt w dwuwymiarowej przestrzeni euklidesowej. 
Punkt powinien być opisany za pomocą dwóch współrzędnych. 
Zadeklaruj wszystkie pola klasy jako prywatne i dodaj odpowiednie akcesory. 
Zdefiniuj funkcję globalną do pobierania od użytkownika 
współrzędnych i wstawiania ich do obiektu klasy Point.
Wczytaj od użytkownika współrzędne dwóch punktów. Oblicz 
i wyświetl odległość pomiędzy tymi punktami - czy lepiej 
to zrobić w funkcji globalnej czy metodzie?



#include <iostream>
#include <cmath>

class point{
    private:
    int x;
    int y;

    public:
    //Aksesory
    void setX(int x){
        this->x = x;
    }
    void setY(int y){
        this->y = y;
    }

    double getX(){
        return x;
    }
    double getY(){
        return y;
    }
};

point getCoordinates(){
    point p; //p: x, y;
    int x, y;
    std::cin >> x;
    std::cin >> y;
    p.setX(x);
    p.setY(y);

    return p;
}

double distance(point p1, point p2){
    double x1 = p1.getX();
    double y1 = p1.getY();
    double x2 = p2.getX();
    double y2 = p2.getY();
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main(){
    point p1;
    point p2;
    p1 = getCoordinates();
    p2 = getCoordinates();
    
    double dist;
    dist = distance(p1, p2);
    std::cout << "Distance between points: " << dist << std::endl;
    
}*/
//Zadanie 2
/*Dla klasy z poprzedniego zadania, w programie głównym utwórz: 
(1) obiekt automatyczny tej klasy, 
(2) obiekt dynamiczny, wskazywany wskaźnikiem, 
(3) tablicę automatyczną obiektów automatycznych, 
(4) tablicę automatyczną wskaźników na obiekty, zainicjuj te wskaźniki w dowolny sposób, 
(5) dynamiczną tablicę obiektów automatycznych, 
(6) dynamiczną tablicę wskaźników, zainicjuj te wskaźniki. 
Na końcu programu zwolnij pamięć dla wszystkich obiektów 
tworzonych dynamicznie. W każdym przypadku skorzystaj z publicznych metod tej klasy.

#include <iostream>
#include <cmath>

class point{
    private:
    int x;
    int y;

    public:
    //Aksesory
    void setX(int x){
        this->x = x;
    }
    void setY(int y){
        this->y = y;
    }

    double getX(){
        return x;
    }
    double getY(){
        return y;
    }
};

point getCoordinates(){
    point p; //p: y; x,
    int x, y;
    std::cin >> x;
    std::cin >> y;
    p.setX(x);
    p.setY(y);

    return p;
}

double distance(point p1, point p2){
    double x1 = p1.getX();
    double y1 = p1.getY();
    double x2 = p2.getX();
    double y2 = p2.getY();
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main(){
    point p1;
    p1 = getCoordinates();

    point* p2 = new point;
    delete p2;

    point arr[10];
    point *arr2[5];
    for (int i = 0; i < 5; i++){
        arr2[i] = new point;
    }
    for (int i = 0; i < 5; i++){
        delete arr2[i];
    }

    point *p3 = new point[5];
    delete[] p3;

    point** p4 = new point*[5];
    for (int i = 0; i < 5; i++){
        p4[i] = new point;
    }
    for(int i = 0; i < 5; i++){
        delete p4[i];
    }
    delete p4;
}*/

//Zadanie 3
/*Napisz funkcję, która otrzymuje jako argumenty tablice 
points1 i points2 o argumentach typu Point  
i przepisuje zwartość tablicy points1 do tablicy points2. 

#include <iostream>
#include <cmath>

class point{
    private:
    int x;
    int y;

    public:
    //Aksesory
    void setX(int x1){
        x = x1;
    }
    void setY(int y1){
        y = y1;
    }

    double getX(){
        return x;
    }
    double getY(){
        return y;
    }
};

point getCoordinates(){
    point p; //p: x, y;
    int x, y;
    std::cin >> x;
    std::cin >> y;
    p.setX(x);
    p.setY(y);

    return p;
}

void copy(point arr1[], point arr2[])
{
    for (int i = 0; i < 5; i++){
        arr2[i] = arr1[i];
    }

}
int main(){
    point arr1[5];
    point arr2[5];
    for (int i = 0; i < 5; i++){
        arr1[i] = getCoordinates();
    }
    
    copy(arr1, arr2);
    for(int i = 0; i < 5; i++){
        std::cout << arr2[i].getX() << " " << arr2[i].getY() << std::endl;
    
    }
}*/

//Zadanie 4
/*Napisz funkcję, która otrzymuje jako argumenty 
tablicę typu Point i zwraca jako wartość najmniejszą 
spośród odległości pomiędzy punktami przechowywanymi 
w tablicy points. Zakładamy, że otrzymana w 
argumencie tablica ma co najmniej dwa argumenty. 

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

class point{
    private:
    int x;
    int y;

    public:
    //Aksesory
    void setX(int x){
        this->x = x;
    }
    void setY(int y){
        this->y = y;
    }

    double getX(){
        return x;
    }
    double getY(){
        return y;
    }
};

double distance(point p1, point p2){
    double x1 = p1.getX();
    double y1 = p1.getY();
    double x2 = p2.getX();
    double y2 = p2.getY();
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}


float shorter_dist(point arr[], int size){
    float min_dist = distance(arr[0], arr[1]);
    float current;
    for (int i = 0; i < size; i++){
        for(int j = 0; j < i; j++){
            current = distance(arr[i], arr[j]);
            if(current < min_dist) min_dist = current;
        }
    }
    return min_dist;
}

int main()
{
    point arr[5];
    srand(time(NULL));
    for (int i = 0; i < 5; i++){
        arr[i].setX(rand()%10);
        arr[i].setY(rand()%10);
        std::cout << arr[i].getX() << " " << arr[i].getY();
        std::cout << std::endl;
    }

    std::cout << shorter_dist(arr, 5);
}*/

//Zadanie 5
/*Napisz funkcję pointsInCircle() , która przyjmuje tablicę typu 
Point oraz trzy liczby rzeczywiste a, b i r, będące parametrami  
równania okręgu (x - a)^2 + (y - b)^2 = r^2. Funkcja powinna zwrócić, 
za pomocą argumentu, wskaźnik na tablicę wskaźników na punkty położone 
w zdefiniowanym kole. W funkcji głównej stwórz testową tablicę punktów 
wygenerowaną pseudolosowo i przetestuj funkcję pointsInCircle(). 

#include <iostream>
#include <cmath>

class point{
    private:
    int x;
    int y;
    public:
    void setX(int x){
        this->x = x;
    }
    void setY(int y){
        this->y = y;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }

};

point** pointsInCircle(point* arr, int n, int a, int b, int r, int& current){
    point** result = new point*[n];
    current = 0;
    for (int i = 0; i < n; i++){
        int dx = arr[i].getX();
        int dy = arr[i].getY();
        if (pow(dx - a, 2) + pow(dy - b, 2) <= pow(r, 2))
        {
            result[current++] = &arr[i];
        }
    }
    return result;
}

int main()
{
    srand(time(NULL));
    int n;
    std::cin >> n;
    point *arr = new point[n];
    for (int i = 0; i < n; i++){
        arr[i].setX(rand()%10);
        arr[i].setY(rand()%10);
    }
    int current;
    point** result = pointsInCircle(arr, n, 3, 2, 5, current);
    for (int i = 0; i < current; i++){
        std::cout << result[i]->getX() << " " << result[i]->getY() << std::endl;
    }
    delete[] arr;
    delete[] result;
}*/

//Zadanie 6
/*Zdefiniuj klasę Matrix3x3 reprezentującą macierz o 
rozmiarze 3x3 liczb zmiennoprzecinkowych. Zdefiniuj 
metodę print() wypisującą na ekranie elementy tej macierzy.
Zdefiniuj metodę add() dodawania liczby do takiej macierzy; 
funkcja ma zwracać nowo obliczoną macierz. Napisz program testujący.

#include <iostream>

class Matrix3x3{
    private:
    double arr[3][3];
    public:
    void print(){
        for (int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                std::cout << arr[i][j] << " ";
            }
        }
    }
    Matrix3x3 add(double value){
        Matrix3x3 result;
        for (int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                result.arr[i][j] = arr[i][j] + value;
            }
        }
        return result;
    }
    Matrix3x3(){
        for (int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                arr[i][j] = 0;
            }
        }
    }
    
};

int main(){
    Matrix3x3 m1;
    m1 = m1.add(5);
    m1.print();
}*/

//Zadanie 7
/*Napisz klasę Identifier, która udostępnia tylko 
jedną publiczną bezargumentową metodę id. 
Metoda id powinna zwracać, za każdym razem inną, 
nieujemną liczbę całkowitą dla danego obiektu.


#include <iostream>

class Identifier{
    public:
    int id(){
        static int number = 1;
        return number++;
    }
};

int main() 
{
    Identifier one;
    std::cout << one.id() << one.id() << one.id();
}*/

//Zadanie 8
/*Zdefiniuj klasę Complex służącą do przechowywania 
liczb zespolonych. Zdefiniowana klasa powinna zawierać pola im i re 
typu double służące do przechowywania odpowiednio części urojonej 
i rzeczywistej liczby zespolonej. Zdefiniuj metodę abs tej klasy, 
która zwróci moduł liczby zespolonej. Napisz funkcję add, która 
dostaje dwa argumenty typu complex zwraca jako wartość ich sumę. 
W funkcji głównej stwórz dwa dynamiczne obiekty typu 
Complex i przetestuj działanie zdefiniowanych funkcji.

#include <iostream>
#include <cmath>

class Complex{
    double im, re;
    public:
    double abs(){
        return sqrt(pow(im, 2) + pow(re, 2));
    }
    void setIm(double im){
        this->im = im;
    }
    void setRe(double re){
        this->re = re;
    }
    double getIm(){return im;};
    double getRe(){return re;};
};

Complex add(Complex first_value, Complex second_value){
    Complex result;
    result.setIm(first_value.getIm() + second_value.getIm());
    result.setRe(first_value.getRe() + second_value.getRe());
    return result;
}

int main()
{
    Complex *first_value = new Complex;
    Complex *second_value = new Complex;

    first_value->setIm(5);
    first_value->setRe(3);
    second_value->setIm(10);
    second_value->setRe(7);

    Complex result = add(*first_value, *second_value);

    std::cout << result.getRe() << " " << result.getIm();

    delete first_value;
    delete second_value;

}*/

//Zadanie 9
/*Zdefiniuj typ złożony Person mający dwa pola: 
liczbę całkowitą - age, napis - name. W funkcji 
głównej stwórz obiekt tego typu, a następnie stwórz 
jego głęboką kopię. Klasa Person może mieć dowolną 
ilość metod pomocniczych. Następnie stwórz dynamiczny 
obiekt klasy Person oraz jego głęboką kopię. 
Jaki problem występuje podczas kasowania tych obiektów.

#include <iostream>
#include <cstring>

class Person{
    private:
    int age;
    char* name;

    public: 
    Person(){
        age = 0;
        name = new char[1]{};
    }
    void setAge(int age){
        this->age = age;
    }
    void setName(char* name){
        delete[] this->name;
        this->name = name;
    }
    int getAge(){
        return age;
    }
    char* getName(){

        return name;
    }
    Person(const Person& p){
        age = p.age;
        name = new char[strlen(p.name) + 1];
        strcpy(name, p.name);
    }
};

int main()
{
    Person p1;
    p1.setAge(98);
    p1.setName("Jan");
    Person p2 = p1;
    std::cout << p2.getName() << " has " << p2.getAge() << " years old" << std::endl;
    Person* p3 = new Person;
    p3->setAge(12);
    p3->setName("Kamil");
    Person* p4 = new Person(*p3);
    std::cout << p4->getName() << " has " << p4->getAge() << " years old" << std::endl;
    delete p3;
    delete p4;
}*/

//Zadanie 10
/*Zdefiniuj strukturę vec2d, składającą się z dwóch pół x i y typu zmiennoprzecinkowego, 
która będzie reprezentowała wektor dwuwymiarowy. Utwórz tablicę automatyczną obiektów tego typu. 
Z pomocą funkcji z biblioteki <algorithm>:
- wypełnij tę tablicę wektorami, których poszczególne współrzędne spełniają zależność: 
x jest liczbą pseudolosową z zakresu domkniętego <-1, 1> a y jest liczbą przeciwną do x (std::generate);
- wypisz na ekranie wszystkie elementy tej tablicy (std::for_each);
- posortuj wszystkie wektory w tablicy malejąco względem współrzędnej y (std::sort);
- znajdź wektor o najmniejszej współrzędnej x (std::min_element).


#include <iostream>
#include <algorithm>

using namespace std;

struct vec2d{
    double x;
    double y;
};

int main()
{
    vec2d first_arr[10];
    std::generate(first_arr, first_arr + 10, [](){
        vec2d v;
        v.x = (double)(rand()%101) / 100;
        v.y = -v.x;
        return v;
    });

    for_each(first_arr, first_arr + 10, [](vec2d v){ cout << v.x << " " << v.y << endl;});
    sort(first_arr, first_arr + 10, [](vec2d v1, vec2d v2){return v1.y > v2.y;});

    cout << "Sorted: " << endl;
    for_each(first_arr, first_arr + 10, [](vec2d v){ cout << v.x << " " << v.y << endl;});
    cout << endl;
    auto min = min_element(first_arr, first_arr + 10, [](vec2d v1, vec2d v2){return v1.x < v2.x;});

    cout << "Min: " << endl;
    cout << min->x << " " << min->y << endl;
}*/


//Zadanie 11
/*Zdefiniuj klasę Vector, która będzie realizowała podstawową funkcjonalność 
dynamicznej tablicy liczb całkowitych typu int. W klasie zdefiniuj metody:
- init() - inicjującą elementy składowe obiektu,
- int& at(int i) - zwracającą referencję na i-ty element tablicy,
- void append(int v) - dodającą element na koniec tablicy,
- void resize(int size) - zmieniającą rozmiar tablicy na nowy, zachowując elementy już dodane do tablicy,
- int size() - zwracającą rozmiar tablicy,
- void clear() - czyszczącą całą zawartość obiektu.
 Napisz program, w którym przetestujesz implementację tej klasy.

#include <iostream>
#include <algorithm>
using namespace std;


class Vector{
    int *arr;
    int size;
    int current;


    public:
    void intit(int size){
        arr = new int[size];
        this->size = size;
        current = 0;
    }

    int& at(int i)
    {
        return arr[i];
    }
    void resize(int size){
        int* arr2 = new int [size];
        int min_size = min(this->size, size);
        for (int i = 0; i < min_size; i++){
            arr2[i] = arr[i];
        }
        delete[] arr;
        arr = arr2;
        this->size = size;
        current = min_size;        
    }
    void append(int v){
        if (current > size){
            resize(size + 10);
        }
        arr[current++] = v;
    }
    int m_size(){
        return current;
    }
    void clear(){
        delete[] arr;
    }
};

int main()
{
    Vector v1;
    v1.intit(10);
    for(int i = 0; i < 10; i++){
        v1.append(i);
    }

    cout << v1.m_size() << endl;
    v1.append(12);
    cout << v1.m_size() << endl;
    v1.clear();
}*/

//Zadanie 12
/*Zdefiniuj klasę Vector, która będzie realizowała podstawową funkcjonalność 
dynamicznej tablicy liczb całkowitych typu int. W klasie zdefiniuj metody:
- init() - inicjującą elementy składowe obiektu,
- int& at(int i) - zwracającą referencję na i-ty element tablicy,
- void append(int v) - dodającą element na koniec tablicy,
- void resize(int size) - zmieniającą rozmiar tablicy na nowy, zachowując elementy już dodane do tablicy,
- int size() - zwracającą rozmiar tablicy,
- void clear() - czyszczącą całą zawartość obiektu.
Napisz program, w którym przetestujesz implementację tej klasy.

#include <iostream>
 

class Vector{
    int* arr;
    int size;
    int current;

    public:
    void init(int size){
        arr = new int[size];
        this->size = size;
        current = 0;
    }
    int& at(int i){
        return arr[i];
    }
    void append(int v){
        if (current > size){
            resize(size + 10);
        }
        arr[current++] = v;     
    }
    void resize(int size){
        int* arr2 = new int[size];
        int min_size = std::min(this->size, size);
        for (int i = 0; i < min_size; i++){
            arr2[i] = arr[i];
        }
        delete[] arr;
        arr = arr2;
        this->size = size;
        current = min_size;
        delete[] arr2;
    }
    int m_size(){
        return current;
    }
    void clear(){
        delete[] arr;
    }
};

int main()
{
    Vector v1;
    v1.init(10);
    for(int i = 0; i < 10; i++){
        v1.append(i + 543);
    }
    for(int i = 0; i < 10; i++){
        std::cout << v1.at(i) << " ";
    }
    std::cout << v1.m_size() << std::endl;
    v1.append(12);
    std::cout << v1.m_size() << std::endl;
    v1.clear();
}*/

//Zadanie 13
/*Zdefiniuj typ wyliczeniowy składający się z wartości 
odzwierciedlających typy: CHAR, UCHAR, INT, FLOAT. 
Napisz funkcję, która przyjmie jako argumenty wskaźnik na void, 
pod którym znajduje się tablica, rozmiar tej tablicy oraz zmienną 
uprzednio zdefiniowanego typu wyliczeniowego oznaczającą typ danych 
znajdujących się w tablicy. Funkcja powinna zwrócić średnią arytmetyczną danych w przekazanej tablicy.

#include <iostream>

enum type{CHAR, UCHAR, INT, FLOAT};

double average(void* arr, int size, type t){
    double result = 0;
    switch(t){
        case CHAR: {
            char* arr2 = (char*)arr;
            for (int i = 0; i < size; i++){
                result += arr2[i];
            }
            break;
        }
        case UCHAR: {
            unsigned char* arr2 = (unsigned char*)arr;
            for (int i = 0; i < size; i++){
                result += arr2[i];
            }
            break;
        }
        case INT: {
            int* arr2 = (int*)arr;
            for (int i = 0; i < size; i++){
                result += arr2[i];
            }
            break;
        }
        case FLOAT: {
            float* arr2 = (float*)arr;
            for (int i = 0; i < size; i++){
                result += arr2[i];
            }
            break;
        }
    }
    return result / size;
}

int main()
{
    char arr[5] = {1, 2, 3, 4, 5};
    std::cout << average(arr, 5, CHAR) << std::endl;
    unsigned char arr2[5] = {1, 2, 3, 4, 5};
    std::cout << average(arr2, 5, UCHAR) << std::endl;
    int arr3[5] = {1, 2, 3, 4, 5};
    std::cout << average(arr3, 5, INT) << std::endl;
    float arr4[5] = {1, 2, 3, 4, 5};
    std::cout << average(arr4, 5, FLOAT) << std::endl;

}*/

//Zadanie 14
/*Zdefiniuj typ wyliczeniowy, służący do przechowywania informacji 
o stanie połączenia internetowego, o trzech wartościach odpowiadających 
trzem stanom: połączenie nawiązane (connected), połączenie nienawiązane 
(disconnected) i połączenie w trakcie nawiązywania (connecting). 
Następnie zdefiniuj strukturę komputer przechowującą stan połączenia, 
IP podłączonego komputera (jako napis) oraz nazwę jego właściciela. 
Napisz funkcję, która jako argument otrzymuje strukturę komputer i 
wyświetla na standardowym wyjściu jej zawartość w sposób przyjazny dla użytkownika.

#include <iostream>
#include <string>

using namespace std;

enum conection_state{connected, disconnected, connecting};

struct Computer{
    conection_state cs;
    string ip;
    string name;
};

void print(Computer pc){
    cout << pc.name << endl;
    cout << pc.ip << endl;
    switch(pc.cs){
        case connected: cout << "connected" << endl; break;
        case disconnected: cout << "disconnected" << endl; break;
        case connecting: cout << "connecting" << endl; break;
    }
}

int main() 
{
    Computer pc{connected, "192.168.0.1", "Admin"};
    print(pc);
}*/