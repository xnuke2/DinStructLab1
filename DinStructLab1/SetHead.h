#pragma once
#include <iostream>
#include <string>


struct Element
{
	int Value;
	Element* Next;
};

struct Set {
	Element* FirstElement;
};
Set* createEmptySet();

bool setIsEmpty(Set* set);

bool setContains(Set* set, int numToFind);

Set* setAddFirst(Set* set, int num);

Set* createRandomSet(int length, int min, int max);

int powerOfSet(Set* set);

std::string printSet(Set* set, char separator);

Set* deleteSet(Set* set);
