// Zadanie 1
/*Zaliczenie z pewnego przedmiotu wygląda tak, że studenci piszą dwa
kolokwia, oba za 50 punktów. Ocena dostateczna przyznawana jest w przedziale (50-60] punktów,
i rośnie o połowę oceny co 10 punktów aż do 100. Student, który nie otrzyma zaliczenia,
może poprawić jedno z kolokwiów ale wtedy może otrzymać co najwyżej ocenę dostateczną.
Zakładamy, że student, który nie otrzyma zaliczenia, zawsze będzie poprawiał kolokwium, które gorzej napisał.
Napisz klasę, w której znajduje się: numer indeksu studenta, wynik
pierwszego kolokwium, wynik drugiego kolokwium i wynik poprawy.
Numer indeksu musi być przekazany w konstruktorze klasy.  Wszystkie pola tej klasy mają być prywatne.
Napisz funkcję, która przyjmie tablicę obiektów takich klas a zwróci średnią ocen
(nie punktów) zdobytych z tego przedmiotu. Tablicę w wynikami cząstkowymi zainicjuj pseudolosowo.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Student
{
    int idx;
    int kol_1;
    int kol_2;
    int kol_pop;

public:
    Student(int idx)
    {
        this->idx = idx;
        kol_1 = 0;
        kol_2 = 0;
        kol_pop = 0;
    }
    Student(){}
    void setKol_1(int a) { kol_1 = a; }
    void setKol_2(int a) { kol_2 = a; }
    void setKol_pop(int a) { kol_pop = a; }

    int getKol_1() const { return kol_1; }
    int getKol_2() const { return kol_2; }
    int getKol_pop() const { return kol_pop; }


};

float marks(Student **arr, int count)
{
    int points;
    float marks_sum = 0;
    for (int i = 0; i < count; i++)
    {
        points = arr[i]->getKol_1() + arr[i]->getKol_2() + arr[i]->getKol_pop();
        if (points <= 50)
        {
            if (arr[i]->getKol_1() <= arr[i]->getKol_2())
                points = arr[i]->getKol_2() + arr[i]->getKol_pop();
            else
                points = arr[i]->getKol_1() + arr[i]->getKol_pop();
            if (points > 50)
                marks_sum += 3;
            else
                marks_sum += 2;
        }
        else if (points <= 60)
            marks_sum += 3;
        else if (points <= 70)
            marks_sum += 3.5;
        else if (points <= 80)
            marks_sum += 4;
        else if (points <= 90)
            marks_sum += 4.5;
        else
            marks_sum += 5;
    }
    return marks_sum / count;
}

int main()
{
    srand(time(0));
    int count = 5;
    Student **arr = new Student*[count];
    for (int i = 0; i < count; ++i)
    {
        arr[i] = new Student(i);
        arr[i]->setKol_1(rand() % 51);
        arr[i]->setKol_2(rand() % 51);
        if (arr[i]->getKol_1() + arr[i]->getKol_2() <= 50)
            arr[i]->setKol_pop(rand() % 51);
        cout << arr[i]->getKol_1() << ' ' << arr[i]->getKol_2() << ' ' << arr[i]->getKol_pop() << endl;
    }


    cout << marks(arr, count) << endl;

    for (int i = 0; i < count; ++i)
        delete[] arr[i];
    delete[] arr;

    return 0;
}*/

// Zadanie 2
/*Napisz klasę Mutex, której obiekty w każdym momencie są w
jednym z dwóch stanów wolny lub zajęty. Bezpośrednio po utworzeniu
obiekt typu Mutex powinien być w stanie wolny. Klasa powinna udostępniać następujące publiczne metody:
- lock(), której wywołanie zmienia stan mutexa z wolny na zajęty
(w przypadku, gdy mutex jest już w stanie zajęty, metoda nie powinna zmieniać jego stanu),
- release(), której wywołanie zmienia stan mutexa z zajęty na wolny
(w przypadku, gdy jest już w stanie wolny, metoda nie powinna zmieniać jego stanu),
- state() zwracającą wartość true gdy mutex jest w stanie wolny i false w przeciwnym wypadku.
Zadbaj o odpowiednią hermetyzację klasy i o prawidłową inicjalizację obiektów.
W programie głównym stwórz dynamiczną tablicę obiektów Mutex,
automatyczną tablicę dynamicznych obiektów Mutex, dynamiczną
tablicę dynamicznych obiektów Mutex oraz dwuwymiarową tablicę
dynamiczną obiektów Mutex. Zadbaj o poprawne zwalnianie pamięci.

#include <iostream>
using namespace std;

class Mutex{
    bool m_state;

    public:
    Mutex(){m_state = true;}
    void lock(){
        m_state = false;
    }
    void release(){
        m_state = true;
    }
    bool state(){
        return m_state;
    }
};


int main()
{
    Mutex obj;
    std::cout << obj.state() << std::endl;
    Mutex* obj1 = new Mutex[3];
    delete[] obj1;
    std::cout << obj1->state() << std::endl;
    Mutex* arr[3];
    for(int i = 0; i < 3; i++){
        arr[i] = new Mutex;
    }
    for(int i = 0; i < 3; i++){
        delete arr[i];
    }

    Mutex** arrM = new Mutex*[3];
    for(int i = 0; i < 3; i++){
        arrM[i] = new Mutex;
    }
    for(int i = 0; i < 3; i++){
        delete arrM[i];
    }
    delete[] arrM;

    Mutex** arrD = new Mutex*[3];
    for(int i = 0; i < 3; i++){
        arrD[i] = new Mutex[10];
    }
    for(int i = 0; i < 3; i++){
        delete[] arrD[i];
    }
    delete[];
}*/

// Zadanie 3
/*Zdefiniuj typ wyliczeniowy AnimalType zawierający kilka typowych nazw zwierząt domowych. 
Zaprojektuj klasę Animal, która posiada dwa pola: zmienną typu wyliczeniowego 
AnimalType oraz tablicę będącą maksymalnie 10 znakową nazwą pupila. 
Dodatkowo klasa powinna zawierać metodę say_something(int n). 
Funkcja say_something() w zależności od typu zwierzęcia powinna 
wyświetlić odpowiedni komunikat np. dla kota "miał" oraz powtórzyć go n razy, 
gdzie n zostało przekazane w argumencie metody. Uzupełnij klasę o odpowiedni 
destruktor oraz konstruktor kopiujący.
Napisz program w języku C++, który przetestuje działanie tej klasy.


#include <iostream>
#include <cstring>

enum AnimalType{
    CAT, DOG, COW, HOURSE
};

class Animal{
    AnimalType type;
    char name[10];

    public:
    Animal(AnimalType type, const char* name){
        this->type = type;
        strcpy(this->name, name);
    }
    Animal(const Animal& obj){
        this->type = obj.type;
        strcpy(this->name, obj.name);
    }
    ~Animal(){}

    void say_something(int n){
        switch(type){
            case CAT:
                for(int i = 0; i < n; i++){
                    std::cout << "Mew" << std::endl;
                }
                break;
            case DOG:
                for(int i = 0; i < n; i++){
                    std::cout << "Hau" << std::endl;
                }
                break;
            case COW:
                for(int i = 0; i < n; i++){
                    std::cout << "Muu" << std::endl;
                }
                break;
            case HOURSE:
                for(int i = 0; i < n; i++){
                    std::cout << "Iha" << std::endl;
                }
                break;
        }
    }
};

int main()
{
    Animal obj(CAT, "Filemon");
    Animal obj1(obj);
    obj.say_something(3);
    obj1.say_something(2);
    Animal obj2(DOG, "Azor");
    obj2.say_something(10);
}*/


// Zadanie 4
/*Zaprojektuj i zaimplementuj klasę String do obsługi napisów. Klasa ta powinna mieć metody:
- konstruktor domyślny, konstruktor inicjujący i konstruktor kopiujący
- destruktor
- length() - zwracającą długość napisu
- cstring() - zwracającą wskaźnik na tablicę znakową w tylu c
- append(...) - dodającą do aktualnego napisu inny napis
- clear() - czyszczącą napis
- empty() - zwracającą informację czy napis jest pusty
- print() - drukującą napis na ekranie
- operator przypisania '=' - zadbaj o głęboką kopię obiektu
Przetestuj tworzoną klasę w programie głównym na obiektach automatycznych i dynamicznych.


#include <iostream> 
#include <cstring>

class String{
    private:
    char* str;

    public:
    String(){
        str = nullptr;
    }
    String(const char* str){
        int size = strlen(str);
        this->str = new char[size];
        strcpy(this->str, str);
    }
    String(String &obj){
        int size = strlen(obj.str);
        this->str = new char[size];
        strcpy(this->str, obj.str);
    }
    ~String(){
        delete[] str;
    }

    void print(){
        if(str != nullptr)
            std::cout << str << std::endl;
    }
    int length(){
        
        if(str == nullptr) return 0;
        return strlen(str);
    }

    char *cstring(){
        return str;
    }

    void append(const char* str){
        if(this->str != nullptr){
            int n = strlen(str) + strlen(this->str) + 1;
            char *arr = new char[n];
            strcpy(arr, this->str);
            strcpy(arr+strlen(this->str), str);
            delete[] this->str;
            this->str = arr;
        }
        else{
            int size = strlen(str);
            this->str = new char[size];
            strcpy(this->str, str);
        }
    }

    void clear(){
        delete[] str;
    }

    bool isEmpty(){
        return this->str == nullptr;
    }

    void operator=(String obj){
        int size = strlen(obj.str);
        this->str = new char[size];
        strcpy(this->str, obj.str);
    }
};

int main()
{
    String* obj = new String;
    obj->append("Ala");
    obj->print();
    delete obj;
}*/

// Zadanie 5
/*Zaprojektuj i zaimplementuj klasę Array realizującą funkcjonalność dynamicznej tablicy (typu int).  
W klasie zdefiniuj metody:
- konstruktory - domyślny, inicjujący, kopiujący
- int& at(int i) - zwracającą referencję na i-ty element tablicy,
- void append(int v) - dodającą element na koniec tablicy,
- void insert(int i, int v) - wstawiającą element v za i-tym elementem,
- void resize(int size) - zmieniającą rozmiar tablicy na nowy, zachowując elementy już dodane do tablicy,
- int size() - zwracającą rozmiar tablicy,
- void clear() - czyszczącą całą zawartość obiektu.
 Napisz program, w którym przetestujesz implementację tej klasy.


#include <iostream>

class Array{
    int* arr;
    int size_arr;

    public:
    Array(){
        arr = nullptr;
        size_arr = 0;
    }
    Array(int size){
        arr = new int[size];
        size_arr = size;
    }
    Array(const Array& obj){
        size_arr = obj.size_arr;
        arr = new int[size_arr];
        for(int i = 0; i < size_arr; i++){
            arr[i] = obj.arr[i];
        }
    }
    ~Array(){
        delete[] arr;
    }

    int& at(int i){
        return arr[i];
    }

    void append(int v){
        int* tmp = new int[size_arr+1];
        for(int i = 0; i < size_arr; i++){
            tmp[i] = arr[i];
        }
        tmp[size_arr] = v;
        delete[] arr;
        arr = tmp;
        size_arr++;
    }

    void insert(int i, int v){
        int* tmp = new int[size_arr+1];
        for(int j = 0; j < i; j++){
            tmp[j] = arr[j];
        }
        tmp[i] = v;
        for(int j = i+1; j < size_arr+1; j++){
            tmp[j] = arr[j-1];
        }
        delete[] arr;
        arr = tmp;
        size_arr++;
    }

    void resize(int size){
        int* tmp = new int[size];
        for(int i = 0; i < size; i++){
            tmp[i] = arr[i];
        }
        delete[] arr;
        arr = tmp;
        size_arr = size;
    }

    int size(){
        return size_arr;
    }

    void clear(){
        delete[] arr;
        arr = nullptr;
        size_arr = 0;
    }

    void operator=(Array obj){
        size_arr = obj.size_arr;
        arr = new int[size_arr];
        for(int i = 0; i < size_arr; i++){
            arr[i] = obj.arr[i];
        }
    }

    bool empty(){
        return arr == nullptr;
    }
};

int main()
{
    Array obj(5);
    obj.append(5);
    obj.append(3);
    std::cout << obj.size() << std::endl;
    for(int i = 0; i < obj.size(); i++){
        std::cout << obj.at(i) << " ";
    }
    std::cout << std::endl;
    obj.insert(1, 10);
    std::cout << obj.size() << std::endl;
    for(int i = 0; i < obj.size(); i++){
        std::cout << obj.at(i) << " ";
    }
    std::cout << std::endl;
    obj.resize(10);
    std::cout << obj.size() << std::endl;
    for(int i = 0; i < obj.size(); i++){
        std::cout << obj.at(i) << " ";
    }
    std::cout << std::endl;
    obj.clear();
    std::cout << obj.size() << std::endl;
    for(int i = 0; i < obj.size(); i++){
        std::cout << obj.at(i) << " ";
    }
    std::cout << std::endl;

}*/

//Zadanie 6
/*Zaimplementuj klasę List realizującą funkcjonalność jednokierunkowej listy wskaźnikowej. W klasie zdefiniuj metody:
- konstruktory - domyślny, (konstruktor kopiujący uczyń prywatnym)
- int size() - zwracającą rozmiar tablicy,
- int& at(int i) - zwracającą referencję na i-ty element tablicy,
- int* find(int v) - zwracającą wskaźnik na znaleziony element v lub nullptr jeżeli takiego elementu nie ma na liście
- void append(int v) - dodającą element na koniec listy,
- void insert(int i, int v) - wstawiającą element v za i-tym elementem,
- void remove(int i) - usuwającą i-ty element z listy
- void clear() - czyszczącą całą zawartość obiektu.
Napisz program, w którym przetestujesz implementację tej klasy.

#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
};

class LinkedList{
    Node* head;
    LinkedList(const LinkedList* obj){
        Node* tmp = obj->head;
        for(; tmp!=nullptr; tmp = tmp->next){
            append(tmp->value);
        }
    }

    public:
    LinkedList(){
        head = nullptr;
    }
    int size(){
        Node* tmp = head;
        int count = 0;
        for(; tmp!=nullptr; tmp = tmp->next)
        {
            count++;
        }
        return count;
    }

    int& at(int n){
        Node* tmp = head;
        for(int i = 0; i < n; i++){
            tmp = tmp->next;
        }
        return tmp->value;
    }

    int* find(int v){
        Node* tmp = head;
        for(; tmp != nullptr; tmp = tmp->next)
        {
            if(tmp->value == v){
                return &tmp->value;
            }
        }
        return nullptr;
    }

    void append(int v){
        Node* new_node = new Node;
        new_node -> value = v;
        new_node -> next = nullptr;
        if(head==nullptr){
            head = new_node;
        }
        else{
            Node* tmp = head;
            for(; tmp->next!=nullptr; tmp=tmp->next);
            tmp->next = new_node;
        }
    }

    void insert(int i, int v){
        Node* new_node = new Node;
        new_node -> value = v;
        if(i==-1){
            new_node->next=head;
            head=new_node;
        }
        else{
            Node* tmp = head;
            for(int j = 0; j < i; j++){
                if(tmp == nullptr){
                    delete new_node;
                    return;
                }
                tmp = tmp->next;
            }
            new_node->next=tmp->next;
            tmp->next=new_node;
        }
    }

    void remove(int i){
        if(i==-1){
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
        else{
            Node* tmp = head;
            for(int j = 0; j < i; j++){
                if(tmp == nullptr) return;
                tmp = tmp->next;
            }
            Node* tmp2 = tmp->next;
            tmp->next = tmp2->next;
            delete tmp2;
        }
    }

    void clear(){
        Node* tmp = head;
        for(; tmp!=nullptr;){
            tmp = tmp->next;
            delete head;
            head=tmp;
        }
        head = nullptr;
    }
};

int main()
{
    LinkedList obj;
    std::cout << obj.size() << std::endl;
    obj.append(5);
    obj.append(3);
    std::cout << obj.size() << std::endl;
    for(int i = 0; i < obj.size(); i++){
        std::cout << obj.at(i) << " ";
    }
    std::cout << std::endl;
    obj.insert(-1, 10);
    std::cout << obj.size() << std::endl;
    for(int i = 0; i < obj.size(); i++){
        std::cout << obj.at(i) << " ";
    }
    std::cout << std::endl;
    obj.remove(1);
    for(int i = 0; i < obj.size(); i++){
        std::cout << obj.at(i) << " ";
    }

    LinkedList obj1(obj);

    for(int i = 0; i < obj1.size(); i++){
        std::cout << "i = " << i << " " << obj1.at(i) << " ";
    }
    

    obj.clear();
}*/