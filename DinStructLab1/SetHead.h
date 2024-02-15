#pragma once
#include <iostream>
#include <string>

struct Element
{
	int Value;
	Element* Next;
};

Element* createEmptySet();

bool setIsEmpty(Element* firstElement);

bool setContains(Element* firstElement, int numToFind);

Element* setAddFirst(Element* firstElement, int num);

Element* createRandomSet(int length, int min, int max);

int powerOfSet(Element* firstElement);

std::string printSet(Element* firstElement, char separator);

Element* deleteSet(Element* firstElement);