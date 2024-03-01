#pragma once
#include <iostream>
#include <string>
using std::string;

struct Element
{
	int Value;
	Element* Next;
};

//создание пустого множества
Element* createEmptySet();

//проверка пустое ли множество?
bool setisEmpty(Element* firstElement);

//проверка на наличие элемента в множестве
bool setContains(Element* firstElement, int numToFind);

//добавление элемента в начало множества
Element* setAddFirst(Element* firstElement, int num);

//создание случайного множества
Element* createRandomSet(int length, int min, int max);
Element* createRandomSet(int length, int min, int max, string type);

//мощность множества
int powerOfSet(Element* firstElement);

//вывод элементов множества	
string printSet(Element* firstElement, char separator);

//удаление множества
Element* deleteSet(Element* firstElement);

//подмножество A-B
bool subSet(Element* a, Element* b);

//равенство двух множеств
bool equalitySet(Element* a, Element* b);

//объединение двух множеств
Element* CombiningSets(Element* a, Element* b);

//пересечение двух множеств
Element* intersectionOfSets(Element* a, Element* b);

//разность двух множеств a-b
Element* subtractionOfSets(Element* a, Element* b);

//симметричная разность двух множеств
Element* simmetricSubtrOfSets(Element* a, Element* b);
