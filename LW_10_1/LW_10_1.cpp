#include <iostream>

void Function(double x) {
    const int a = 5;
    if (abs(x) < a) {
        std::cout << "модуль значения х должен быть больше чем" << a << "\n";
    }
    else if (abs(x) == a) {
        std::cout << "деление на ноль" << "\n";
    }
    std::cout << std::log((x + a) / (x - a));
}

int main(){
    setlocale(LC_ALL, "Russian");
    double x;
    std::cin >> x;
    Function(x);
}

