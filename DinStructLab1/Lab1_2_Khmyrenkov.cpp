#include <iostream>
#include "SetHead.h"

using std::cout;
using std::endl;
using std::to_string;

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "RUS");

    cout << "Хмыренков 19 вариант" << endl;

    Element* A = createRandomSet(rand() % (9 - 6 + 1) + 6, 10, 25, "a");
    Element* B = createRandomSet(rand() % (9 - 6 + 1) + 6, 10, 26, "b");
    cout << "Множества A и B созданы" << endl;
    cout << "Вывод множества A: " + printSet(A, ',') << endl;
    cout << "Мощность множество A: " + std::to_string(powerOfSet(A)) << std::endl;
    cout << "Вывод множества B: " + printSet(B, ',') << endl;
    cout << "Мощность множество B: " + std::to_string(powerOfSet(B)) << std::endl;
    cout << "Множество A является подмножеством B: " + to_string(subSet(A, B)) << endl;
    cout << "Множество A является подмножеством A: " + to_string(subSet(A, A)) << endl;
    cout << "Множество A равно подмножеству B: " + to_string(equalitySet(A, B)) << endl;
    cout << "Множество A равно подмножеству A: " + to_string(equalitySet(A, A)) << endl;
    Element* C = CombiningSets(A, B);
    cout << "Объединение двух множеств: " + printSet(C, ',') << endl;
    cout << "Мощность объединения множеств: " + std::to_string(powerOfSet(C)) << std::endl;
    Element* D = intersectionOfSets(A, B);
    cout << "Пересечение двух множеств: " + printSet(D, ',') << endl;
    cout << "Мощность пересечения множеств: " + std::to_string(powerOfSet(D)) << std::endl;
    Element* E = subtraction(A, B);
    Element* F = subtraction(B, A);
    cout << "Разность A-B: " + printSet(E, ',') << endl;
    cout << "Мощность разности A-B: " + std::to_string(powerOfSet(E)) << std::endl;
    cout << "Разность B-A: " + printSet(F, ',') << endl;
    cout << "Мощность разности B-A: " + std::to_string(powerOfSet(F)) << std::endl;
    Element* G = simmetricSubtraction(A, B);
    cout << "Симметричная разность множеств: " + printSet(G, ',') << endl;
    cout << "Мощность cимметричная разности: " + std::to_string(powerOfSet(G)) << std::endl;
}
