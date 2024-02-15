#include <iostream>
#include "SetHead.h"

int main()
{
    
    setlocale(LC_ALL, "RUS");
    Element* set = createRandomSet(rand() % (9 - 6 + 1) + 6, 0, 20);
    std::cout << "Множество создано: " + printSet(set, ' ') << std::endl;
    std::cout << "Мощность множество: " + std::to_string(powerOfSet(set)) << std::endl;
    std::cout << "Вывод множества: " + printSet(set, ' ') << std::endl;
    std::cout << "Удаление множества" << std::endl;
    set = deleteSet(set);
    std::cout << "Мощность множество: " + std::to_string(powerOfSet(set)) << std::endl;
    std::cout << "Вывод множества: " + printSet(set, ' ') << std::endl;
    deleteSet(createRandomSet(10, 0, 100));
}