#pragma once
#include <iostream>
#include <string>
using namespace std;
class LabOrganizer {
public:
	LabOrganizer();
	~LabOrganizer();
	int* copyArray(const int* arr, const int size);
	string* copyArray(const string* arr, const int size);
	int* deleteitem(const int* arr, const int size, const int position);
	string* deleteitem(const string* arr, const int size, const int position);
	char* stringtochar(const string string);
	void addCabinet(int id, int rows, int columns);
	void removeCabinet(int id);
	void listCabinets();
	void cabinetContents(int id);
	void placeChemical(int cabinetId, string location, string chemType, int chemID);
	void findChemical(int id);
	void removeChemical(int id);
private:
	int cabinetAmount;
	int* cabinets;
	int* columnsarr;
	int* rowsarr;
	int* cabinetIDarr;
	int* chemIDarr;
	string* locationarr;
	string* chemTypearr;
	int chemicalamount;
};
