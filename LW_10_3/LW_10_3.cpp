#include "classes.h"
#include <iostream>

int main(){
    setlocale(LC_ALL, "Russian");
    std::string x;
    Plant yellow;
    yellow.set_name(9);
    std::cout << "Введите полный путь файла \n";
    std::cin >> x;
    yellow.infromation_to_file(x);
}
