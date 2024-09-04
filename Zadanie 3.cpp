#include <iostream>
#include <cmath>

int binToDec(char str[], int index) {
    if (index == sizeof(str)) {
        return 0;
    }
    
    int result = binToDec(str, index + 1);
    int bitValue = str[index] - '0';
    result += bitValue * pow(2, sizeof(str) - index - 1);
    return result;
}
int main() {
    char str[] = "10001111";
    std::cout<<binToDec(str, 0);
    return 0;
}