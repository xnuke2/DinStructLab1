#include "SetHead.h"
#include <exception>
using std::exception;


//�������� ������� ���������
Element* createEmptySet() {
	Element* firstElement = NULL;
	return firstElement;
}

//�������� ������ �� ���������?
bool setisEmpty(Element* firstElement)

{
	if (set->FirstElement == NULL) {
		return true;
	}
	return false;
}


//�������� �� ������� �������� � ���������
bool setContains(Element* firstElement, int numToFind) {
	if (setisEmpty(firstElement)) {
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


//���������� �������� � ������ ���������
Element* setAddFirst(Element* firstElement, int num) {
	if (setContains(firstElement, num)) {
		return firstElement;
	}
	Element* newStart = new Element;
	newStart->Value = num;
	newStart->Next = set->FirstElement;
	set->FirstElement = newStart;
	return set;
}

//�������� ���������� ���������
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

Element* createRandomSet(int length, int min, int max, string type ) {
	if (type == "a") {
		Element* newSet = createEmptySet();
		if (length <= 0 || max - min < length) {
			return newSet;
		}
		for (int i = 0; i < length; i++) {
			int newNum = rand() % (max - min + 1) + min;
			while (setContains(newSet, newNum) || newNum % 10 >= 8) {
				newNum = rand() % (max - min + 1) + min;
			}
			newSet = setAddFirst(newSet, newNum);
		}
		return newSet;
	}
	if (type == "b") {
		Element* newSet = createEmptySet();
		if (length <= 0 || max - min < length) {
			return newSet;
		}
		for (int i = 0; i < length; i++) {
			int newNum = rand() % (max - min + 1) + min;
			while (setContains(newSet, newNum) || newNum % 10 <=3) {
				newNum = rand() % (max - min + 1) + min;
			}
			newSet = setAddFirst(newSet, newNum);
		}
		return newSet;
	}
}


//�������� ���������
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


//����� ��������� ���������	
string printSet(Element* firstElement, char separator) {
	std::string rezult = "";
	if (setisEmpty(firstElement)) {

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


//�������� ���������
Element* deleteSet(Element* firstElement) {
	if (setisEmpty(firstElement)) {
		return firstElement;
	}
	Element* tmp = firstElement;
	Element* tmpLast;
	while (tmp) {
		tmpLast = tmp;
		tmp = tmp->Next;
		delete tmpLast;
	}
	firstElement = NULL;
	return firstElement;
}

//������������ A-B
bool subSet(Element* a, Element* b) {
	if (setisEmpty(a) || setisEmpty(b)) return false;
	int sizea = powerOfSet(a);
	if ( sizea> powerOfSet(b)) return false;
	int check = 0;
	Element* tmpb = b;
	while (tmpb != NULL) {
		Element* tmpa = a;
		Element* tmp = tmpb;
		check = 0;
		while (tmpb!= NULL&&tmpa!=NULL&&tmpa->Value == tmpb->Value)
		{
			check++;
			tmpb = tmpb->Next;
			tmpa = tmpa->Next;
		}
		if (check == sizea)return true;
		tmpb = tmp->Next;
	}
	return false;
}

//��������� ���� ��������
bool equalitySet(Element* a, Element* b) {
	if (subSet(a, b) && subSet(b, a)) return true;
	return false;
}

//����������� ���� ��������
Element* CombiningSets(Element* a, Element* b) {
	if (setisEmpty(a) || setisEmpty(b)) return NULL;
	Element* tmp = b;
	Element* tmpRezult= createEmptySet();
	while (tmp!=NULL)
	{
		tmpRezult = setAddFirst(tmpRezult, tmp->Value);
		tmp = tmp->Next;
	}
	tmp = a;
	while (tmp!=NULL)
	{
		tmpRezult=setAddFirst(tmpRezult, tmp->Value);
		tmp = tmp->Next;
	}
	Element* rezult = createEmptySet();
	while (tmpRezult!=NULL)
	{
		rezult = setAddFirst(rezult, tmpRezult->Value);
		tmpRezult = tmpRezult->Next;
	}
	return rezult;
}

//����������� ���� ��������
Element* intersectionOfSets(Element* a, Element* b) {
	if (setisEmpty(a) || setisEmpty(b)) return NULL;
	Element* tmpRezult = createEmptySet();
	Element* tmpa = a;
	while (tmpa!=NULL)
	{
		if (setContains(b, tmpa->Value)) tmpRezult = setAddFirst(tmpRezult, tmpa->Value);
		tmpa = tmpa->Next;
	}
	Element* rezult = createEmptySet();
	while (tmpRezult != NULL)
	{
		rezult = setAddFirst(rezult, tmpRezult->Value);
		tmpRezult = tmpRezult->Next;
	}
	return rezult;
}

//�������� ���� �������� a-b
Element* subtractionOfSets(Element* a, Element* b) {
	if (setisEmpty(a) && setisEmpty(b)) return NULL;
	Element* tmpRezult = createEmptySet();
	Element* tmpa = a;
	while (tmpa!=NULL)
	{
		if (!setContains(b, tmpa->Value))tmpRezult = setAddFirst(tmpRezult, tmpa->Value);
		tmpa = tmpa->Next;
	}
	Element* rezult = createEmptySet();
	while (tmpRezult != NULL)
	{
		rezult = setAddFirst(rezult, tmpRezult->Value);
		tmpRezult = tmpRezult->Next;
	}
	return rezult;
	return rezult;
}

//������������ �������� ���� ��������
Element* simmetricSubtrOfSets(Element* a, Element* b) {
	return subtractionOfSets(CombiningSets(a, b), intersectionOfSets(a, b));
}