#include "List.h"
#include "Element.h"
#include <fstream>

template<class T>
List<T>::List(List<T>& original_List)
{
	Element<T>* temp = original_List.first;
	while (temp != NULL)
	{
		this->push_back(temp->data); //dodawanie elementu do listy
		temp = temp->next; //przejscie do kolejnego elementu
	}
}
template<class T>
List<T>::~List()
{
	while (size > 0) remove(size); //zwolnienie miejsca zeby nie bylo wyciekow pamieci
	std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
}
template<class T>
Element<T>* List<T>::get_position(unsigned long int pos) //zwraca element
{
	if (pos == 0 || pos > this->size)
	{
		std::cout << "Nie znaleziono elementu na tej pozycji" << std::endl;
		return NULL;
	}
	if (pos < this->size - pos) //szuka od poczatku
	{
		Element<T>* temp = this->first;
		for (int i = 1; i < pos; i++)
		{
			temp = temp->next; //przejscie do nastepnego elementu
		}
		return temp;
	}
	else //szuka od konca
	{
		Element<T>* temp = this->last;
		for (int i = size; i > pos; i--)
		{
			temp = temp->prev; //przejscie do poprzedniego elementu
		}
		return temp;
	}

}
template<class T>
void List<T>::add(T d, unsigned long int pos) //dodaje na dowolne miejsce w liscie
{
	Element<T>* elem = new Element<T>(d);
	if (size == 0) { this->first = this->last = elem; } //pierwszy element
	else if (pos <= 1) //wstawienie na poczatek
	{
		this->first->prev = elem;
		elem->next = this->first;
		this->first = elem;
	}
	else if (pos > size)//wstawienie na koniec
	{
		this->last->next = elem;
		elem->prev = this->last;
		this->last = elem;
	}
	else //wstawienie w srodku
	{
		Element<T>* temp = get_position(pos);
		Element<T>* before = temp->prev;
		temp->prev = elem;
		elem->next = temp;
		before->next = elem;
		elem->prev = before;

	}
	size++; //zwiekszenie rozmiaru po dodaniu elementu
	std::cout << "Dodaje element: " << elem->data << " na pozycje: " << pos << std::endl;
}
template<class T>
void List<T>::push_back(T d) //dodanie na koniec listy
{
	Element<T>* elem = new Element<T>(d);
	if (size == 0) { this->first = this->last = elem; } //dodanie pierwszego elementu do listy
	this->last->next = elem; //dodanie elementu na koniec gdy lista ma juz jakis element
	elem->prev = this->last;
	this->last = elem;
	size++;
	std::cout << "Dodaje element: " << elem->data << " na koniec"<< std::endl;
}
template<class T>
void List<T>::show() //wyswietla wszystkie elementy listy
{
	std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
	Element<T>* temp = this->first;
	while (temp) //wykonuje sie az do konca listy 
	{
		std::cout << temp->data << "  ";
		temp = temp->next;
	}
	std::cout << "Rozmiar: " << size << std::endl;
	if (this->first) //sprawdzenie czy jest jakis element na liscie zeby moc wypisac pierwszy i ostatni element
	{
		std::cout << "Pierwszy element: " << this->first->data << "\t Ostatni element: " << this->last->data << std::endl;
	}
	else
		std::cout << "Lista jest pusta" << std::endl;
std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;

}
template<class T>
void List<T>::remove(unsigned long int pos) //usuniecie elementu z dowolnej pozycji
{
	if (size == 0) { std::cout << "Error - lista jest pusta." << std::endl; } // nie da sie usuwac elementu z pustej listy
	else if (size == 1) //usuniecie jedynego elementu
	{
		delete this->first;
		this->first = this->last = NULL;
	}
	else if (pos <= 1) //usuniecie pierwszego elementu
	{
		Element<T>* temp = this->first;
		this->first = this->first->next;
		this->first->prev = NULL;
		delete temp;
	}
	else if (pos >= size) //usuniecie ostatniego elementu 
	{
		Element<T>* temp = this->last;
		this->last->prev->next = NULL;
		this->last = this->last->prev;
		delete temp;
	}
	else //usuniecie elementu w srodku listy 
	{
		Element<T>* temp = get_position(pos);
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
	}
	size--; //zmniejszenie rozmiaru po usunieciu elementu
	std::cout << "Usuwam element z pozycji: " << pos << std::endl;
}
template<class T>
void List<T>::remove_all() //usuniecie wszystkich elementow listy
{
	while (size > 0) remove(size); //usuwa ostatni element do momentu az size wyniesie 0
} 
template<class T>
int List<T>::search(T d) //znajduje pozycje wybranego elemetnu
{
	Element<T>* temp = this->first;
	for (int i = 1; i <= size; i++)
	{
		if (temp->data == d)
		{
			return i; //jesli dany element istnieje
		}
		temp = temp->next;
	}
	delete temp;
	return 0; //jesli dany element nie znajduje sie w liscie
}
template<class T>
void List<T>::save_to_file() //zapisuje liste do pliku
{
	std::ofstream myfile;
	myfile.open("test.txt");
	if (myfile.good())
	{
		for (int i = 1; i <= this->size; i++)
		{
			myfile << (*this)[i] << '\n'; //zapisuje dana wartosc i przechodzi do nastepnej linijki
		}
	}
	myfile.close();
}
template<class T>
void List<T>::read_from_file() //wczytanie listy z pliku 
{
	std::ifstream my_file;
	my_file.open("test2.txt");
	if (my_file.good())
	{
		T temp;
		while (my_file >> temp) //wczytuje wartosc z pliku i wrzuca ja do zmiennej pomocniczej 
		{
			this->push_back(temp); //dodanie wartosci z pliku na koniec listy
		}
	}
	my_file.close();
}
template<class T>
T List<T>::operator[] (unsigned long int pos)
{
	Element<T>* temp = get_position(pos);
	return temp->data; //zwaraca wartosc elementu z wybranej pozycji
}



