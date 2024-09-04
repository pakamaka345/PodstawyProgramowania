//Zadanie 1

/*#include <iostream>
#include <cmath>
using namespace std;

void gen_mat(double** arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i*i + 1; j++){
            arr[i][j] = (double)(i + j) / 2;
        }
    }
}

int main()
{
    int n;
    cout << "Input size of array" << endl;
    cin >> n;

    double** arr = new double*[n];
    for(int i = 0; i < n; i++){
        arr[i] = new double[i * i + 1];
    }

    gen_mat(arr, n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i*i + 1; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < n; i++){
        delete[] arr[i];
    }
    delete[] arr;
}*/

//Zadanie 2

#include <iostream>
using namespace std;

void reduce(double* begin, double* end, double* arrRB, double(*f)(double, double))
{
    int size = end - begin;
    for(int i = 0; i < size / 2; i++){
        arrRB[i] = f(*(begin + i), *(end - i - 1));
    }
    
}
double mul(double number1, double number2){
    return number1 * number2;
}
double amin(double number1, double number2){
    if(number1 < number2)
        return number1;
    else 
        return number2;
}

int main()
{
    int n;
    cout << "Input size of array, size must be even";
    cin >> n;

    double* arr1 = new double[n];
    cout << "Input element of array";
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }

    double* arr2 = new double[n / 2];
    double* arr3 = new double[n / 2];

    reduce(arr1, arr1 + n, arr2, mul);
    reduce(arr1, arr1 + n, arr3, amin);
    for(int i = 0; i < n / 2; i++){
        cout << arr2[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n / 2; i++){
        cout << arr3[i] << " ";
    }

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
}

//Zadanie 3

/*#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int compare(const void* a, const void* b){
    return strcmp(*(char**)b, *(char**)a);
}

int main()
{
    unsigned int n, min_len, max_len;
    
    cout << "Input n, min_len, max_len" << endl;

    cin >> n >> min_len >> max_len;

    char** napis = new char*[n];
    for(unsigned int i = 0; i < n; i++){
        int size = min_len + (rand() % (max_len - min_len + 1)) + 1;
        napis[i] = new char[size];
        for(int j = 0; j < size; j++){
            napis[i][j] = 'a' + (rand() % ('z' - 'a' + 1));
        }
        napis[i][size] = '\0';
    }
    qsort(napis, n, sizeof(char*), compare);

    for(unsigned int i = 0; i < n; i++){
        cout << napis[i] << endl;
    }
    for(unsigned int i = 0; i < n; i++){
        delete[] napis[i];
    }
    delete[] napis;
}*/

//Zadanie 4


/*#include <iostream>
#include <cstring>

void null_set(void* arr1, void* arr2, int n, int size){
    for(int i = 0; i < n; i++){
        if(memcmp((char*)arr1 + i * size, (char*)arr2 + i * size, size) == 0){
            memset((char*)arr1 + i * size, 0, size);
            memset((char*)arr2 + i * size, 0, size);
        }
    }
}

int main()
{
    int n;
    std::cout << "Input size of arrays" << std::endl;

    std::cin >> n;
    double* arr1 = new double[n];
    double* arr2 = new double[n];
    for(int i = 0; i < n; i++){
        std::cin >> arr1[i] >> arr2[i];
    }

    null_set(arr1, arr2, n, sizeof(double));

    for (int i = 0; i < n; i++){
        std::cout << "arr1 = " << arr1[i] << " " << "arr2 = " << arr2[i] << std::endl;
    }

    delete[] arr1;
    delete[] arr2;
}*/




