#include "classes.h"
#include <iostream>

int main(){
    std::string x;
    Plant <std::string, int, Data> yellow;
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите польный путь файла \n";
    std::cin >> x; // всё реализована в classes.h проверка на правильность пути в функции "information_to_file"
}
