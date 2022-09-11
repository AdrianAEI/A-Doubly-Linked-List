#ifndef _Element
#define _Element
#include <iostream>
template<class T>
class Element
{
	public:
		T data; //dane
		Element<T>* next; //wskaznik na nastepny element
		Element<T>* prev; //wskaznik na poprzedni element
		Element(T d = 0, Element<T>* n = NULL, Element<T>* p = NULL);
};

#endif
