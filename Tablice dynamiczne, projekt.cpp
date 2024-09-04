//Zadanie 1
/*Napisz program, który wczytuje ze standardowego 
wejścia trzy liczby naturalne n, m i o, a następnie 
alokuje pamięć dla trzywymiarowej tablicy nxmxo. 
Wypełnij tę tablicę dowolnymi wartościami a następnie usuń z pamięci.

#include <iostream> 
#include <cstdlib>

int main()
{
    int n, m, o;
    std::cin >> n >> m >> o;

    srand(time(NULL));

    int*** arr1 = new int**[n];
    for (int i = 0; i < n; i++){
        arr1[i] = new int*[m];
        for (int j = 0; j < m; j++){
            arr1[i][j] = new int[o];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < o; k++){
                arr1[i][j][k] = rand()%101;
            }
        }
    }

    std::cout << "Zawartosc tablicy:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < o; ++k) {
                std::cout << arr1[i][j][k] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            delete[] arr1[i][j];
        }
        delete[] arr1[i];
    }
    delete[] arr1;
}*/

//Zadanie 3
/*Napisz funkcję, która dostaje jako parametr 
dynamiczną dwuwymiarową tablicę liczb całkowitych 
i jej wymiary n, m. Funkcja ma zwrócić 0, jeśli 
na brzegach (tzn. w pierwszym i ostatnim wierszu 
oraz w pierwszej i ostatniej kolumnie) tablicy 
występują wartości tylko zerowe; w przeciwnym 
razie funkcja ma zwrócić 1.

#include <iostream>

bool zeroOrNot(int** arr, int n, int m) {
    int count = 0;

    // Sprawdź pierwszy i ostatni wiersz
    for (int j = 0; j < m; j++) {
        if (arr[0][j] != 0 || arr[n - 1][j] != 0) {
            return 1;
        }
    }

    // Sprawdź pierwszą i ostatnią kolumnę (poza pierwszym i ostatnim elementem)
    for (int i = 0; i < n; i++) {
        if (arr[i][0] != 0 || arr[i][m - 1] != 0) {
            return 1;
        }
    }
    return 0;

}

int main() {
    int n, m;
    std::cin >> n >> m;

    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> arr[i][j];
        }
    }

    bool result = zeroOrNot(arr, n, m);
    std::cout << result;

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}*/

//Zadanie 4
/*Napisz funkcję, wykona transpozycję 
macierzy przekazanej w parametrze. Macierz 
ma być reprezentowana za pomocą dynamicznie 
alokowanej tablicy dwuwymiarowej. 
Jaką sygnaturę zaproponujesz dla implementowanej funkcji?

#include <iostream>

int** Transpose(int** arr, int n, int m)
{
    int** result = new int*[n];
    for(int i = 0; i < n; i++){
        result[i] = new int[m];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            result[j][i] = arr[i][j];
        }
    }

    return result;
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    int** arr = new int*[n];
    for(int i = 0; i < n; i++){
        arr[i] = new int[m];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    int** result = Transpose(arr, n, m);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for(int i = 0; i < n; i++){
        delete[] arr[i];
    }
    delete[] arr;

    for(int i = 0; i < m; i++){
        delete[] result[i];
    }
    delete[] result;
}*/

//Zadanie 5 
/*Napisz funkcję, która dostaje jako argumenty 
dwuwymiarową tablicę tablic o elementach typu 
int oraz jej wymiary, i zmienia kolejność 
wierszy w tablicy w taki sposób, że wiersz 
pierwszy ma się znaleźć na miejscu drugiego, 
wiersz drugi ma się znaleźć na miejscu trzeciego itd., 
natomiast ostatni wiersz ma się znaleźć 
na miejscu pierwszego (przyjmujemy, 
że elementy w wierszu są umieszczone w pamięci obok siebie).


#include <iostream>

int** changingArray(int** arr, int o)
{
    int** result = new int*[o];
    for (int i = 0; i < o; i++) {
        result[i] = new int[o];
    }

    // Copy the last row to the first row
    for (int i = 0; i < o; i++) {
        result[0][i] = arr[o - 1][i];
    }

    // Shift the remaining rows up
    for (int i = 1; i < o; i++) {
        for (int j = 0; j < o; j++) {
            result[i][j] = arr[i - 1][j];
        }
    }

    return result;
}

int main()
{
    int o;
    std::cin >> o;

    int** arr = new int*[o];
    for (int i = 0; i < o; i++) {
        arr[i] = new int[o];
    }

    for (int i = 0; i < o; i++) {
        for (int j = 0; j < o; j++) {
            std::cin >> arr[i][j];
        }
    }

    std::cout << "Array before changes" << std::endl;
    for (int i = 0; i < o; i++) {
        for (int j = 0; j < o; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int** arrAftChanges = changingArray(arr, o);

    std::cout << "Array after changes" << std::endl;
    for (int i = 0; i < o; i++) {
        for (int j = 0; j < o; j++) {
            std::cout << arrAftChanges[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Deallocate memory
    for (int i = 0; i < o; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    for (int i = 0; i < o; i++) {
        delete[] arrAftChanges[i];
    }
    delete[] arrAftChanges;

    return 0;
}*/

//Zadanie 6
/*Napisz funkcję, która obliczy (zwróci) 
iloczyn diadyczny dwóch wektorów o dowolnej 
ilości współrzędnych (https://pl.wikipedia.org/wiki/Iloczyn_diadyczny). 
Wektory mają być reprezentowane za pomocą jednowymiarowych dynamicznie 
alokowanych tablic a macierz przez dynamicznie alokowaną tablicę 
dwuwymiarową. Jaką sygnaturę funkcji zaproponujesz?

#include <iostream>

int** productOfVectors(int* firstV, int n, int* secondV, int m)
{
    int** result = new int*[n];
    for(int i = 0; i < n; i++){
        result[i] = new int[m];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            result[i][j] = firstV[i] * secondV[j];
        }
    }
    return result;
}

int main()
{
     int n, m;
     std::cout << "Input size of the first vector\n";
     std::cin >> n;

     int*  first_vector = new int[n];
     std::cout << "Input elements of the first vector\n";
     for(int i = 0; i < n; i++){
        std::cin >> first_vector[i];
     }

     std::cout << "Input size of the second vector\n";
     std::cin >> m;

     int* second_vector = new int[m];
     std::cout << "Input elements of the second vector\n";
     for(int i = 0; i < m; i++){
        std::cin >> second_vector[i];
     }

     int** matrix = productOfVectors(first_vector, n, second_vector, m);

     for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
     }

     for(int i = 0; i < n; i++){
        delete[] matrix[i];
     }
     delete[] matrix;

     delete[] first_vector;
     delete[] second_vector;
}*/

//Zadanie 7
/*Napisz funkcję mul(), która mnoży dwie macierze 
reprezentowane przez dynamicznie alokowane tablice 
dwuwymiarowe oraz funkcję print_matrix(), która 
wyświetla tak zdefiniowaną macierz. Napisz program, 
który przetestuje działanie tych funkcji dla macierzy o dowolnym rozmiarze.

#include <iostream>
#include <algorithm>

int** productOfMatrix(int** arr1, int n1, int m1,
                      int** arr2, int n2, int m2)
{
    int**result = new int*[n1];
    for(int i = 0; i < n1; i++){
        result[i] = new int[m2];
    }

    for(int i = 0; i < n1; i++){
        for(int j = 0; j < m2; j++){
            int temp = 0;
            for(int k = 0; k < m1; k++){
                temp += arr1[i][k] * arr2[k][j];
            }
            result[i][j] = temp;
        }
    }
    return result;
}

void printOfMatrix(int** matrix, int n, int m)
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int rows1, column1, rows2, column2;
    std::cin >> rows1 >> column1;
    int** matrix_1 = new int*[rows1];
    for(int i = 0; i < rows1; i++)
    {
        matrix_1[i] = new int[column1];
        for(int j = 0; j < column1; j++)
        {
            std::cin >> matrix_1[i][j];
        }
    }
    std::cout << "\n -------------------------------------------------------------------------------\n";

    std::cin >> rows2 >> column2;
    int**matrix_2 = new int*[rows2];
    for(int i = 0; i < rows2; i++)
    {
        matrix_2[i] = new int[column2];
        for(int j = 0; j < column2; j++)
        {
            std::cin >> matrix_2[i][j];
        }
    }

    std::cout << "\n -------------------------------------------------------------------------------\n";

    for(int i = 0; i < rows1; i++)
    {
        for(int j = 0; j < column1; j++)
        {
            std::cout << matrix_1[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n -------------------------------------------------------------------------------\n";

    for(int i = 0; i < rows2; i++)
    {
        for(int j = 0; j < column2; j++)
        {
            std::cout << matrix_2[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n -------------------------------------------------------------------------------\n";

        if(rows1 != column2){
        std::cout << "\n Matrix cant be producted \n";
        return 0;
    }

    int** resultMatrix = productOfMatrix(matrix_1, rows1, column1, matrix_2, rows2, column2);
    printOfMatrix(resultMatrix, rows1, column2);

    for(int i = 0; i < rows1; i++)
    {
        delete[] matrix_1[i];
    }
    delete[] matrix_1;
    for(int i = 0; i < rows2; i++)
    {
        delete[] matrix_2[i];
    }
    delete[] matrix_2;
}*/

//Zadanie 8
/*Napisz funkcję, która przyjmie jako argumenty 
dwa napisy - przeszukiwany i poszukiwany. 
Jeżeli w napisie przeszukiwanym znajduje się 
napis będący zgodny z napisem poszukiwanym, 
funkcja powinna zwrócić wskaźnik na indeks 
pierwszego znaku odnalezionego podnapisu. 
W przeciwnym razie funkcja powinna zwrócić NULL.

#include <iostream>

const char* findSubstring(const char* haystack, const char* needle) {
    if (*needle == '\0') {
        return nullptr;
    }

    while (*haystack != '\0') {
        const char* h = haystack;
        const char* n = needle;

        while (*h == *n && *h != '\0' && *n != '\0') {
            h++;
            n++;
        }

        if (*n == '\0') {
            return haystack;
        }

        haystack++;
    }

    return nullptr;
}

int main() {
    const char* haystack = "To be or not to be, that is the question.";
    const char* needle = "not";

    const char* result = findSubstring(haystack, needle);

    if (result != nullptr) {
        std::cout << "Substring found at index: " << result - haystack << std::endl;
    } else {
        std::cout << "Substring not found." << std::endl;
    }

    return 0;
}*/

