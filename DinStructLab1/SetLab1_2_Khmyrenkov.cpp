#include "SetHead.h"

Element* createEmptySet() {
	Element* firstElement = NULL;
	return firstElement;
}

bool setIsEmpty(Element* firstElement)
{
	if (firstElement == NULL) {
		return true;
	}
	return false;
}

bool setContains(Element* firstElement, int numToFind) {
	if (setIsEmpty(firstElement)) {
		return false;
	}
	Element* tmp = firstElement;
	while (tmp != NULL)
	{
		if (tmp->Value == numToFind) {
			return true;
		}
		tmp = tmp->Next;
	}
	return false;
}

Element* setAddFirst(Element* firstElement, int num) {
	if (setContains(firstElement, num)) {
		return firstElement;
	}
	Element* newStart = new Element;
	newStart->Value = num;
	newStart->Next = firstElement;
	return newStart;
}

Element* createRandomSet(int length, int min, int max) {
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

	Element* tmp = firstElement;
	int length = 0;
	while (tmp != NULL)
	{
		length++;
		tmp = tmp->Next;
	}
	return length;
}

std::string printSet(Element* firstElement, char separator) {
	std::string rezult = "";
	if (setIsEmpty(firstElement)) {
		return rezult;
	}
	Element* tmp = firstElement;
	while (tmp != NULL) {
		rezult = rezult + std::to_string(tmp->Value);
		if (tmp->Next != NULL) {
			rezult = rezult + separator;
		}
		tmp = tmp->Next;
	}
	return rezult;
}

Element* deleteSet(Element* firstElement) {
	if (setIsEmpty(firstElement)) {
		return firstElement;
	}
	Element* tmp = firstElement;
	Element* tmpLast = firstElement;
	while (tmp != NULL) {
		while (tmp->Next != NULL) {
			tmpLast = tmp;
			tmp = tmp->Next;
		}
		if (tmp != tmpLast) {
			tmpLast->Next = NULL;
		}
		if (tmp == firstElement) {
			firstElement = NULL;
		}
		delete tmp;
		tmp = NULL;
		tmpLast = tmp = firstElement;
	}
	return firstElement;
}