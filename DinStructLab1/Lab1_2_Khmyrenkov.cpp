#include <iostream>
#include "SetHead.h"

using std::cout;
using std::endl;
using std::to_string;

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "RUS");
    //Element* set = createRandomSet(rand() % (9-6+1)+6, 0, 20);
    //std::cout <<"Множество создано: "+ printSet(set, ' ') << std::endl;
    //std::cout << "Мощность множество: " + std::to_string(powerOfSet(set)) << std::endl;
    //std::cout << "Вывод множества: " + printSet(set, ' ') << std::endl;
    //std::cout << "Удаление множества" << std::endl;
    //set = deleteSet(set);
    //std::cout << "Мощность множество: " + std::to_string(powerOfSet(set)) << std::endl;
    //std::cout << "Вывод множества: " + printSet(set, ' ') << std::endl;
    //deleteSet(createRandomSet(10, 0, 100));

    Element* A = createRandomSet(rand() % (9 - 6 + 1) + 6, 10, 99, "a");
    Element* B = createRandomSet(rand() % (9 - 6 + 1) + 6, 10, 99, "b");
    //Element* A = createEmptySet();
    //Element* B = createEmptySet();
    //A = setAddFirst(A, 1);
    //A = setAddFirst(A, 2);
    //A = setAddFirst(A, 3);
    //B = setAddFirst(B, 9);
    //B = setAddFirst(B, 4);
    //B = setAddFirst(B, 1);
    //B = setAddFirst(B, 2);
    //B = setAddFirst(B, 3);
    cout << "Множества A и B созданы" << endl;
    cout << "Вывод множества A: " + printSet(A, ',') << endl;
    cout << "Вывод множества B: " + printSet(B, ',') << endl;
    cout << "Множество A является подмножеством B: " + to_string(subSet(A, B)) << endl;
    cout << "Множество A является подмножеством A: " + to_string(subSet(A, A)) << endl;
    cout << "Множество A равно подмножеству B: " + to_string(equalitySet(A, B)) << endl;
    cout << "Множество A равно подмножеству A: " + to_string(equalitySet(A, A)) << endl;
    Element* C = CombiningSets(A, B);
    cout << "Объединение двух множеств: " + printSet(C, ',') << endl;
    Element* D = intersectionOfSets(A, B);
    cout << "Пересечение двух множеств: " + printSet(D, ',') << endl;
    Element* E = subtractionOfSets(A, B);
    Element* F = subtractionOfSets(B, A);
    cout << "Разность A-B: " + printSet(E, ',') << endl;
    cout << "Разность B-A: " + printSet(F, ',') << endl;
    Element* G = simmetricSubtrOfSets(A, B);
    cout << "Симметричная разность множеств: " + printSet(G, ',') << endl;
}
