#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "MyClass.h"
#include "httplib.h"

void calculateFunctionAndSort(std::vector<double>& data) {
    MyClass obj;
    for (size_t i = 0; i < data.size(); ++i) {
        data[i] = obj.FuncA(i); // Ваш метод обчислення
    }
    std::sort(data.begin(), data.end());
}

int main() {
    httplib::Server server;

    server.Get("/calculate", [](const httplib::Request&, httplib::Response& res) {
        const int arraySize = 100000; // Налаштуйте для виконання обчислень ~10 секунд
        std::vector<double> data(arraySize);

        auto start = std::chrono::high_resolution_clock::now();
        calculateFunctionAndSort(data);
        auto end = std::chrono::high_resolution_clock::now();

        double elapsed = std::chrono::duration<double>(end - start).count();
        res.set_content("Calculation time: " + std::to_string(elapsed) + " seconds", "text/plain");
    });

    std::cout << "Starting HTTP server on port 8080...\n";
    server.listen("0.0.0.0", 8080);
}
