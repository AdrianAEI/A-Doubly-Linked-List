#include "Element.h"
template<class T>
Element<T>::Element(T d, Element<T>* n, Element<T>* p) //konstruktor domy�lny
{
	this->data = d;
	this->next = this->prev = NULL;
}