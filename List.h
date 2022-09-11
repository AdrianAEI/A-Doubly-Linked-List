#ifndef _List
#define _List
#include <iostream>
#include "Element.h"
template<class T>
class List
{
private:
	unsigned long int size = 0; //rozmiar listy
	Element<T>* first = NULL; //wskaznik na pierwszy element
	Element<T>* last = NULL; //wskaznik na ostatni element
public:
	List() {} //konstruktor domyslny
	List(List<T>& original_List); //konstruktor kopiujacy 
	~List(); //destruktor
	Element<T>* get_position(unsigned long int pos); //zwraca element na danej pozycji 
	void add(T d, unsigned long int pos); //dodanie elemenetu na dowolnej pozycji
	void push_back(T d); //dodanie elementu na koncu
	void show(); //wyswietlenie listy 
	void remove(unsigned long int pos); //usuniecie elementu z wybranej pozycji
	void remove_all(); //usuniecie wszystkich elementow
	int search(T d); //zwraca pozycje elementu 
	void save_to_file(); //zapis listy do pliku
	void read_from_file(); //odczyt listy z pliku
	T operator[] (unsigned long int pos); //dostep do elementu za pomoca []
};

#endif
