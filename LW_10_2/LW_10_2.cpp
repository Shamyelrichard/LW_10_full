#include <iostream>
#include <vector>
#include <cmath> // добавил для возведения в степень
#include <algorithm> // find

bool mean_geor(std::vector<double> arr) {
    double product = 1; // серъёзно произведение это "product" какая досада
    for (double elem : arr) {
        product *= elem;
    }
    try
    {
        if (arr.size() % 2 == 1 && product < 0) {
            throw std::exception("ваша комбинация чисел не имеет среднего геометрического среди действительных чисел");
        }
        auto it = std::find(arr.begin(), arr.end(), 0);
        if (it != arr.end()) {
            throw std::exception("ваш массив содержит ноль следовательно ответ 0");
        }
        std::cout << pow(product, (1.0 / arr.size()));
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what();
    }
    /*if (arr.size() % 2 == 1 && product < 0) {
        std::cout << "ваша комбинация чисел не имеет среднего геометрического среди действительных чисел";
        return 0;
    }
    std::cout << pow(product, double(1.0 / arr.size()));
    return 1;*/
}

int main(){
    int counter;
    char answer;
    setlocale(LC_ALL, "Russian");
    std::cout << "ВВедите число элемектов\n";
    std::cin >> counter;
    std::cout << "ВВедите элементы массива\n";
    double elem;
    bool flag = false;
    std::vector <double> arr;
    for (int i = 0; i < counter; i++) {
        std::cin >> elem;
        arr.push_back(elem);
    }
    mean_geor(arr);
}
