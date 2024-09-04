#include <iostream> 


unsigned int convert(char napis[])
{
    int i = 0, p = 1, n = 0;
    int lenght = 0;
    while (napis[i]!= '\0')
    {
        lenght++;
        i++;
    }

    for (i=lenght-1; i>=0;i--)
    {
        if (napis[i] >='0' && napis[i] <='9') n+=( napis[i] - '0')*p;
        p*=10;
    }
    return n;
}


int main ()
{
    char napis[5];
    std::cout << "Podaj liczbe calkowita (mniejsza niz 65536) w postaci napisu: ";
    std::cin >> napis;
    int result = convert(napis);

    if (result > 0 && result <= 65536) std::cout << "Wynik konwersji: " << result << std::endl;
    else std::cout << "Konwersja nieudana." << std::endl;
    

}