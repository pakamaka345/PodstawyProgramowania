#include <vector> 
#include <iostream>


class BestTravel {
public:
    static void generateCombinations(const std::vector<int>& distances, int k, 
          std::vector<int>::size_type index, int currentSum, int& maxSum, std::vector<int>& currentCombination) {
        if (k == 0) {
            // Calculate the sum of the current combination
            maxSum = std::max(maxSum, currentSum);
            return;
        }
        std::cout << "Max sum = " << maxSum << std::endl;

        for (std::vector<int>::size_type i = index; i < distances.size(); ++i) {
            currentCombination.push_back(distances[i]);
            generateCombinations(distances, k - 1, i + 1, currentSum + distances[i], maxSum, currentCombination);
            currentCombination.pop_back();
        }
    }

    static int chooseBestSum(int t, int k, std::vector<int> ls) {
        int maxSum = -1;
        std::vector<int> currentCombination;

        // Generate all combinations of distances
        generateCombinations(ls, k, 0, 0, maxSum, currentCombination);

        if (maxSum <= t) {
            return maxSum;
        } else {
            return -1; // No valid combination found
        }
    }
};

int main() {
    // Example usage
    std::vector<int> distances = {50, 55, 57, 58, 60};
    
    // Test case 1
    int maxSum1 = BestTravel::chooseBestSum(174, 3, distances);
    std::cout << "Test case 1: The biggest possible sum is: " << maxSum1 << std::endl;

    // Test case 2
    int maxSum2 = BestTravel::chooseBestSum(163, 3, distances);
    std::cout << "Test case 2: The biggest possible sum is: " << maxSum2 << std::endl;

    // Test case 3
    std::vector<int> distances2 = {91, 74, 73, 85, 73, 81, 87};
    int maxSum3 = BestTravel::chooseBestSum(230, 3, distances2);
    std::cout << "Test case 3: The biggest possible sum is: " << maxSum3 << std::endl;

    // ... add more test cases as needed

    return 0;
}