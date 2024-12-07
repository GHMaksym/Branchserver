#include <iostream>
#include <chrono>
#include "MyClass.h"

void test_calculation_time() {
    const int arraySize = 100000; // Відповідно до HTTP-сервера
    std::vector<double> data(arraySize);

    auto start = std::chrono::high_resolution_clock::now();
    calculateFunctionAndSort(data);
    auto end = std::chrono::high_resolution_clock::now();

    double elapsed = std::chrono::duration<double>(end - start).count();

    if (elapsed >= 5 && elapsed <= 20) {
        std::cout << "Test passed\n";
    } else {
        std::cout << "Test failed. Elapsed time: " << elapsed << " seconds\n";
    }
}

int main() {
    test_calculation_time();
    return 0;
}
