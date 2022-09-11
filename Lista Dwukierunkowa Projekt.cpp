#include <iostream>
#include "List.h"
#include "List.cpp"
#include "Element.cpp"

using namespace std;

int main()
{
	List<int> list1;
	list1.show();
	list1.push_back(5);
	list1.push_back(10);
	list1.push_back(20);
	list1.show();
	list1.remove_all();
	list1.show();
	list1.add(5, 1);
	list1.add(7, 2);
	list1.add(10, 3);
	list1.add(3, 1);
	list1.add(30, 5);
	list1.show();
	list1.remove(4);
	list1.show();
	cout <<"Element na trzeciej pozycji: "<< list1[3] << endl;
	list1.save_to_file();
	cout << "Lista wczytana z pliku:" << endl;
	List<string> list2;
	list2.read_from_file();
	list2.show();
	list2.add("Weronika", 100);
	list2.push_back("Kasia");
	list2.show();
	cout << "Lista skopiowana:" << endl;
	List<string> list3(list2);
	list3.show();
	list3.add("Filip", 2);
	list3.show();
	list3.remove(100);
	list3.remove(1);
	list3.show();
	List<double> list4;
	list4.push_back(20.5);
	list4.push_back(25.5);
	list4.push_back(30.5);
	list4.show();
	list4.remove(0);
	list4.show();
	cout << "Szukanie pozycji elementu 30.5, jesli nie znaleziono zwroci 0: " << list4.search(30.5) << endl;
	cout << "Szukanie pozycji elementu 40.25, jesli nie znaleziono zwroci 0: " << list4.search(40.25) << endl;
	cout << "----------------------------------------------------------------------------------------------------" <<endl;
	//_CrtDumpMemoryLeaks(); // destruktor aktywuje sie po wywolaniu tej funkcji, a to on odpowiada za to zeby nie bylo wyciekow pamieci
	return 0;
}
