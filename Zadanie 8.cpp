#include <iostream>

int* balance(int* arr, int n) {
    for (int* indexPtr = arr; indexPtr < arr + n; indexPtr++) {
        int leftSide = 0, rightSide = 0;

        // Left side sum using pointers
        for (int* leftPtr = arr; leftPtr < arr + *indexPtr; leftPtr++) {
            leftSide += *leftPtr;
        }

        // Right side sum using pointers
        for (int* rightPtr = arr + *indexPtr; rightPtr < arr + n; rightPtr++) {
            rightSide += *rightPtr;
        }

        if (leftSide == rightSide) {
            return indexPtr;
        }
    }
    return nullptr;
}

int main()
{
    int n;
    std::cin >> n;
    int* arr = new int[n];

    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }

    auto index = balance(arr, n);

    std::cout << *index;

    delete[] arr;
}