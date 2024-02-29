#include "SetHead.h"
#include <exception>
using std::exception;

Set* createEmptySet() {
	Set* newSet = new Set;
	newSet->FirstElement = NULL;
	return newSet;
}

bool setIsEmpty(Set* set)
{
	if (set->FirstElement == NULL) {
		return true;
	}
	return false;
}

bool setContains(Set* set, int numToFind) {
	if (setIsEmpty(set)) {
		return false;
	}
	Element* tmp = set->FirstElement;
	while (tmp != NULL)
	{
		if (tmp->Value == numToFind) {
			return true;
		}
		tmp = tmp->Next;
	}
	return false;
}

Set* setAddFirst(Set* set, int num) {
	if (setContains(set, num)) {
		return set;
	}
	Element* newStart = new Element;
	newStart->Value = num;
	newStart->Next = set->FirstElement;
	set->FirstElement = newStart;
	return set;
}

Element* createRandomSet(int length, int min, int max) {
	srand(time(0)); 
	Element* newSet = createEmptySet();
	if (length <= 0 || max - min < length) {
		return newSet;
	}
	for (int i = 0; i < length; i++) {
		int newNum = rand() % (max - min + 1) + min;
		while (setContains(newSet, newNum)) {
			newNum = rand() % (max - min + 1) + min;
		}
		newSet = setAddFirst(newSet, newNum);
	}

	return newSet;
}

int powerOfSet(Element* firstElement) {
	if (setIsEmpty(firstElement)) {
		return 0;
	}
	Element* tmp = firstElement;
	int length = 0;
	while (tmp != NULL)
	{
		length++;
		tmp = tmp->Next;
	}
	return length;
}

std::string printSet(Set* set, char separator) {
	std::string rezult = "";
	if (setIsEmpty(set)) {
		return rezult;
	}
	Element* tmp = set->FirstElement;
	while (tmp != NULL) {
		rezult = rezult + std::to_string(tmp->Value);
		rezult = rezult + separator;
		tmp = tmp->Next;
	}
	rezult.pop_back();
	return rezult;
}

Set* deleteSet(Set* set) {
	if (setIsEmpty(set)) {
		return set;
	}
	Element* tmp = firstElement->Next;
	delete firstElement;
	firstElement = NULL;
	while (tmp != NULL) {
		Element* next = tmp->Next;
		delete tmp;
		tmp = next;
	}
	return set;
}