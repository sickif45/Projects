/* Sakif Chowdhury
Last Edited 
May 13th 2023
Professor Dakota Hernandez
*/
#include <iostream>
#include <algorithm>

const int MAX_SIZE = 50;

void initializeArray(int arr[], int& size) {
    std::cout << "Please enter up to " << MAX_SIZE << " non-negative whole numbers separated by space.\n";
    std::cout << "Mark the end of the input list with a negative number: ";

    size = 0;
    int num;
    std::cin >> num;

    while (num >= 0 && size < MAX_SIZE) {
        arr[size] = num;
        size++;
        std::cin >> num;
    }
}

void displayArray(const int arr[], int size) {
    std::cout << "The array contains: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

bool containsNumber(const int arr[], int size, int number) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == number) {
            return true;
        }
    }
    return false;
}

int countOccurrences(const int arr[], int size, int number) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == number) {
            count++;
        }
    }
    return count;
}

void calculateStats(const int arr[], int size, int& minimum, int& maximum, int& sum, double& average) {
    if (size == 0) {
        minimum = maximum = sum = 0;
        average = 0.0;
        return;
    }

    minimum = *std::min_element(arr, arr + size);
    maximum = *std::max_element(arr, arr + size);

    sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    average = static_cast<double>(sum) / size;
}

int main() {
    int arr[MAX_SIZE];
    int size;
    initializeArray(arr, size);

    int minimum, maximum, sum;
    double average;
    calculateStats(arr, size, minimum, maximum, sum, average);

    std::cout << "The minimum value in the array is " << minimum << std::endl;
    std::cout << "The maximum value in the array is " << maximum << std::endl;
    std::cout << "The sum of all the elements in the array is " << sum << std::endl;
    std::cout << "The average of all the elements in the array is " << average << std::endl;

    int number;
    std::cout << "Please enter the value you want to search in the array: ";
    std::cin >> number;

    if (containsNumber(arr, size, number)) {
        std::cout << "Find your target " << number << std::endl;
    } else {
        std::cout << "The array does not contain the number " << number << std::endl;
    }

    std::cout << "Please enter the value you want to know the frequency of: ";
    std::cin >> number;

    int occurrences = countOccurrences(arr, size, number);
    std::cout << "The number " << number << " has occurred " << occurrences << " time(s) in the array" << std::endl;

    return 0;
}