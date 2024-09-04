//Zadanie 10 
/*Zdefiniuj funkcję, która przyjmuje jako argumenty: 
napis str oraz automatyczną tablicę liczb całkowitych 
bez znaku occ o długości równej ilości znaków w napisie str. 
Funkcja powinna w i-ty element tablicy occ wpisać liczbę wystąpień 
(w całym napisie str) i-tego znaku z tego napisu.Napis str może 
zawierać jedynie małe i wielkie litery oraz spacje. 
Małe i wielkie litery zliczamy łącznie, jako ten sam znak.
PRZYKŁAD:
IN str = “Ala ma kota”
OUT occ = [4, 1, 4, 2, 1, 4, 2, 1, 1, 1, 4]
*/

#include <iostream>

void function(char str[], int occ[], int N) {
    for (int i = 0; i < N; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
    for (int i = 0; i < N; i++) {
        int counter = 0;
        
        for (int j = 0; j < N; j++) {
            
            if (str[i] == str[j] ) {
                counter++;
            }
        }

        occ[i] = counter;
    }
}

int main() {
    char str[] = "dksjfjdoksko skdjg dosjfosj sodfjosd";
    int N = sizeof(str) - 1;
    
    int occ[N];

    function(str, occ, N);

    std::cout << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << occ[i] << " ";

    return 0;
}
