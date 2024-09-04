#include <iostream>

int main() {
    int height;

    // Get the height of the triangle from the user
    std::cout << "Enter the height of the triangle: ";
    std::cin >> height;

    // Draw the triangle
    for (int i = 1; i <= height; ++i) {
        // Draw spaces before the stars
        for (int j = 1; j <= height - i; ++j) {
            std::cout << " ";
        }

        // Draw stars
        for (int k = 1; k <= 2 * i - 1; ++k) {
            std::cout << "*";
        }

        // Move to the next line
        std::cout << std::endl;
    }

    return 0;
}
