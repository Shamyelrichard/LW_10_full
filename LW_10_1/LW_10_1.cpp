#include <iostream>
void Function(int x) {
    const int a = 5;
    if (x == a) {
        throw std::exception("Деление на 0");
    }
    if (((x + a) / (x - a)) <= 0) {
        throw std::exception("Данный логарифм не существует");
    }
    std::cout << std::log((x + a) / (x - a));
}

int main(){
    setlocale(LC_ALL, "Russian");
    int x;
    std::cin >> x;
    try {
        Function(x);
    }
    catch (std::exception& ex) {
        std::cout << ex.what();
    }
    
}

