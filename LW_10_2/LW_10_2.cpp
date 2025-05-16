#include <iostream>
#include <vector>
#include <cmath> // добавил для возведения в степень

bool mean_geor(std::vector<double> arr) {
    double product = 1; // серъёзно произведение это "product" какая досада
    for (double elem : arr) {
        product *= elem;
    }
    if (arr.size() % 2 == 1 && product < 0) {
        std::cout << "ваша комбинация чисел не имеет среднего геометрического среди действительных чисел";
        return 0;
    }
    std::cout << pow(product, double(1.0 / arr.size()));
    return 1;
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
        if (elem == 0) {
            std::cout << "Вы ввели '0' вы осазнаёте это? \n Д/Н \n"; // 1238326
            std::cin >> answer; // пользователь думает, что от его ответа что-то зависит :)
            flag = true;
        }
        arr.push_back(elem);
    }

    if (flag) { std::cout << "0 \nа вы чего ожидали?\n"; }
    else {
        mean_geor(arr);
    }
}
