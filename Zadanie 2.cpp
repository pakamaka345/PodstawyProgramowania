#include <iostream>
#include <ctime>

const int MAX_SIZE = 16;

// Функція для занегування біту на позиції 'column' та встановлення біту на позиції 'row' в 0
void transform_mat(unsigned short matrix[MAX_SIZE][MAX_SIZE], int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] ^= (1 << j);   // Занегувати біт на позиції 'column'
            matrix[i][j] &= ~(1 << i);  // Встановити біт на позиції 'row' в 0
            
        }
    }
}

// Функція для виведення матриці на екран
void print_matrix(unsigned short matrix[MAX_SIZE][MAX_SIZE], int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int rows, columns;
    
    

    // Отримати від користувача кількість рядків та стовпців матриці
    std::cout << "Enter the number of rows in the matrix (max 16): ";
    std::cin >> rows;

    std::cout << "Enter the number of columns in the matrix (max 16): ";
    std::cin >> columns;

    // Перевірити, чи кількість рядків та стовпців не перевищує 16
    if (rows > MAX_SIZE || columns > MAX_SIZE) {
        std::cout << "Too many rows or columns. Maximum is 16." << std::endl;
        return 1;
    }

    // Ініціалізувати та отримати елементи матриці від користувача
    unsigned short matrix[MAX_SIZE][MAX_SIZE];
    std::cout << "Enter matrix elements row-wise:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << "Element[" << i << "][" << j << "]: ";
             matrix[i][j] = rand()%100;
        }
    }

    // Вивести оригінальну матрицю
    std::cout << "Original matrix:" << std::endl;
    print_matrix(matrix, rows, columns);

    // Виконати трансформацію матриці
    transform_mat(matrix, rows, columns);

    // Вивести трансформовану матрицю
    std::cout << "\nTransformed matrix:" << std::endl;
    print_matrix(matrix, rows, columns);

    return 0;
}
