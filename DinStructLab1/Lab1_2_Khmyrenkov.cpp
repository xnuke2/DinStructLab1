
#include <iostream>
#include "SetHead.h"

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "RUS");
    Set* set = createRandomSet(rand() % (9-6+1)+6, 0, 20);
    std::cout <<"Множество создано: "+ printSet(set, ' ') << std::endl;
    std::cout << "Мощность множество: " + std::to_string(powerOfSet(set)) << std::endl;
    std::cout << "Вывод множества: " + printSet(set, ' ') << std::endl;
    std::cout << "Удаление множества" << std::endl;
    set = deleteSet(set);
    std::cout << "Мощность множество: " + std::to_string(powerOfSet(set)) << std::endl;
    std::cout << "Вывод множества: " + printSet(set, ' ') << std::endl;
    deleteSet(createRandomSet(10, 0, 100));
}
