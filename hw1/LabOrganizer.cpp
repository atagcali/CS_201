#include <iostream>
using namespace std;

#include "LabOrganizer.h"

LabOrganizer::LabOrganizer() {
		cabinetAmount = 0;
		int a = cabinetAmount + 1;
		cabinets = new int[a];
		columnsarr = new int[a];
		rowsarr = new int[a];
		chemicalamount = 0;
		cabinetIDarr = new int[a];
		chemIDarr = new int[a];
		locationarr = new string[a];
		chemTypearr = new string[a];
		cout << "created" << endl;			

/*	**cabinets = new int[];
	**cabinets = { 0 };
	for (int i = 0; i < cabinetAmount + 1; i++) {
		*cabinets[1] = new int[i+1];
		*cabinets[1][i] = i;
		for (int j = 0; j < cabinetAmount + 1; i++) {
			cabinets[1][i] = new int[j + 1];
			cabinets[1][i][j] = j;
		}
	}*/

}

LabOrganizer::~LabOrganizer() {

}
//copying array checked working
int* LabOrganizer::copyArray(const int* arr, const int size) {
	int* output = new int[size];	
	for (int i = 0; i < size; i++) {
		output[i] = arr[i];
	}
	return output;
}

string* LabOrganizer::copyArray(const string* arr, const int size) {
	string* output = new string[size];
	for (int i = 0; i < size; i++) {
		output[i] = arr[i];
	}
	return output;
}
//deleting item checked working POSITION STARTS FROM 0
int* LabOrganizer::deleteitem(const int* arr, const int size, const int position) {
	int a = size;
	a--;
	int* output = new int[a];
	
	for (int i = 0; i < position; i++) {
		output[i] = arr[i];
	}
	for (int i = position; i < a; i++) {
		output[i] = arr[i+1];
	}	
	return output;
}
string* LabOrganizer::deleteitem(const string* arr, const int size, const int position) {
	int a = size;
	a--;
	string* output = new string[a];

	for (int i = 0; i < position; i++) {
		output[i] = arr[i];
	}
	for (int i = position; i < a; i++) {
		output[i] = arr[i + 1];
	}
	return output;

}

char* LabOrganizer::stringtochar(const string string) {
	int a = string.length() + 1;
	char* output = new char[a];
	for (int x = 0; x < a ; x++) {
		output[x] = string[x];
	}
	return output;
}

void LabOrganizer::addCabinet(int id, int rows, int columns) {
	if (rows > 9 || columns > 9) {
		cout << "Cannot add the cabinet: dimensions are out of bounds. " << endl;
	}
	else {

		if (cabinetAmount == 0) {
			int newAmount = cabinetAmount + 1;
			int* tempid;
			int* temprow;
			int* tempcol;
			
			tempid = new int[newAmount];
			tempcol = new int[newAmount];
			temprow = new int[newAmount];
			
			tempid[newAmount - 1] = id;
			tempcol[newAmount - 1] = columns;
			temprow[newAmount - 1] = rows;
			
			cabinetAmount++;
			
			cabinets = copyArray(tempid, cabinetAmount);
			rowsarr = copyArray(temprow, cabinetAmount);
			columnsarr = copyArray(tempcol, cabinetAmount);
			
			delete[] tempid;
			delete[] tempcol;
			delete[] temprow;
			cout << "Added a cabinet: ID " << cabinets[cabinetAmount - 1] << " and dimensions " << rowsarr[cabinetAmount - 1] << " to " << columnsarr[cabinetAmount - 1] << endl;
		}
		else {
			bool check = 0;
			for (int i = 0; i < cabinetAmount; i++) {
				if (cabinets[i] == id) {
					check = 1;
				}
			}
			if (check) {
				cout << "Cannot add the cabinet: ID " << id << " Already in the system." << endl;
			}
			else {
				int newAmount = cabinetAmount + 1;
				int* tempid;
				int* temprow;
				int* tempcol;
				
				tempid = new int[newAmount];
				tempcol = new int[newAmount];
				temprow = new int[newAmount];
				for (int i = 0; i < cabinetAmount; i++) {
					tempid[i] = cabinets[i];
					tempcol[i] = columnsarr[i];
					temprow[i] = rowsarr[i];
				}
				tempid[cabinetAmount] = id;
				temprow[cabinetAmount] = rows;
				tempcol[cabinetAmount] = columns;
				
				cabinetAmount++;
				
				delete[]  cabinets;
				delete[]  rowsarr;
				delete[]  columnsarr;
				
				cabinets = copyArray(tempid, cabinetAmount);
				rowsarr = copyArray(temprow, cabinetAmount);
				columnsarr = copyArray(tempcol, cabinetAmount);
				
				delete[] tempid;
				delete[] tempcol;
				delete[] temprow;
			
				cout << "Added a cabinet: ID " << cabinets[cabinetAmount - 1] << " and dimensions " << rowsarr[cabinetAmount - 1] << " to " << columnsarr[cabinetAmount - 1] << endl;
			}	
		}
	}
}

void LabOrganizer::listCabinets() {
	if (cabinetAmount == 0) {

	}
	else {
		cout << "List of all cabinets:" << endl;
	}
	for (int i = 0; i < cabinetAmount; i++) {
		if (chemicalamount == 0) {
			cout << "ID: " << cabinets[i] << ", dim: " << rowsarr[i] << "x" << columnsarr[i] << ", Number of empty slots: " << rowsarr[i] * columnsarr[i] << endl;
		}
		else {
			int reserved = 0;
			int a=0;
			int b=0;
			for (int j = 0; j < chemicalamount; j++) {
				if (cabinetIDarr[j] == cabinets[i]) {
					reserved++;
					a = i;
					b = j;
				}				
			}
			cout << "ID: " << cabinets[a] << ", dim: " << rowsarr[a] << "x" << columnsarr[a] << ", Number of empty slots: " << (rowsarr[a] * columnsarr[a]) - reserved << endl;
		}
	}

}

void LabOrganizer::cabinetContents(int id) {
	int position = 0;
	string* chemicals = new string[1];
	for (int i = 0; i < cabinetAmount; i++) {
		if (cabinets[i] == id) {
			position = i;			
		}
	}
	int reserved = 0;
	for (int i = 0; i < cabinetAmount; i++) {
		for (int j = 0; j < chemicalamount; j++) {
			if (cabinetIDarr[j] == cabinets[i]) {
				reserved++;
			}
		}
	}
	cout << "ID: " << cabinets[position] << ", " << rowsarr[position] << "x" << columnsarr[position] << ", empty: " << (rowsarr[position] * columnsarr[position])-reserved << endl;
	cout << "  ";
	for (int i = 0; i < rowsarr[position]; i++) {
		cout << i + 1 << " ";
	}
	cout << endl;
	for (int i = 0; i < rowsarr[position]; i++) {
		for (int j = 0; j < columnsarr[position]+1; j++) {
			char columnname = (char)i + 65;
			if (j == 0) {
				cout << columnname << " ";
			}	
			else {
				bool find = 0;
				int findedloc = 0;
				for (int k = 0; k < cabinetAmount; k++) {
					char* locchar;
					for (int l = 0; l < chemicalamount; l++) {
						locchar = stringtochar(locationarr[l]);
						int loccol = (int)locchar[0] - 64;
						int locrow = (int)locchar[1] - 48;
						if (i == locrow && j == loccol) {
							find = true;
							findedloc = l;
						}
					}

				}
				if (find) {
					if (chemTypearr[findedloc] == "combustive") {
						cout << "c ";
					}
					else {
						cout << "r ";
					}
				}
				else {
					cout << "+ ";
				}
			}
		}
		cout << endl;
	}
}

void LabOrganizer::removeCabinet(int id) {
	if (cabinetAmount == 0) {

	}
	else {
		bool check = 0;
		int position = 0;
		for (int i = 0; i < cabinetAmount; i++) {
			if (cabinets[i] == id) {
				check = 1;
				position = i;
			}
		}
		if (check) {
			int* tempid;
			int* temprow;
			int* tempcol;
			
			tempid = deleteitem(cabinets, cabinetAmount, position);
			temprow = deleteitem(rowsarr, cabinetAmount, position);
			tempcol = deleteitem(columnsarr, cabinetAmount, position);
			
			cabinetAmount--;
			
			delete[] cabinets;
			delete[] columnsarr;
			delete[] rowsarr;
			
			cabinets = copyArray(tempid, cabinetAmount);
			rowsarr = copyArray(temprow, cabinetAmount);
			columnsarr = copyArray(temprow, cabinetAmount);
			
			delete[] tempid;
			delete[] temprow;
			delete[] tempcol;
			
			cout << "Cabinet " << id << " has been removed" << endl;
  		}
		else {
			cout << "Cabinet " << id << " does not exist in the system" << endl;
		}
	}

}

void LabOrganizer::placeChemical(int cabinetId, string location, string chemType, int chemID) {
	if (chemicalamount == 0) {
		int newamount = chemicalamount + 1;
		
		int* tempcabinetid = new int[newamount];
		int* tempchemid = new int[newamount];
		string* templocation = new string[newamount];
		string* tempchemType = new string[newamount];
		
		tempcabinetid[chemicalamount] = cabinetId;
		tempchemid[chemicalamount] = chemID;
		templocation[chemicalamount] = location;
		tempchemType[chemicalamount] = chemType;
		
		chemicalamount++;

		delete[] cabinetIDarr;
		delete[] chemIDarr;
		delete[] chemTypearr;
		delete[] locationarr;
		
		cabinetIDarr = copyArray(tempcabinetid, chemicalamount);
		chemIDarr = copyArray(tempchemid, chemicalamount);
		locationarr = copyArray(templocation, chemicalamount);
		chemTypearr = copyArray(tempchemType, chemicalamount);

		delete[] tempcabinetid;
		delete[] tempchemid;
		delete[] templocation;
		delete[] tempchemType;

		cout << chemType << " chemical with ID: " << chemID << " has been placed at location: " << location << " in cabinet " << cabinetId << endl;
	}
	else {
		bool check1 = 0;
		bool check2 = 0;
		int check1id = 0;
		string check1loc = "";
		for (int i = 0; i < chemicalamount; i++) {
			if (cabinetIDarr[i] == cabinetId && locationarr[i] == location) {
				check1 = 1;
				check1id = cabinetIDarr[i];
				check1loc = locationarr[i];
			}
		}
		for (int i = 0; i < chemicalamount; i++) {
			char* temp;
			char* temp1;
			temp = stringtochar(location);
			temp1 = stringtochar(locationarr[i]);
			int loccol1 = (int)temp1[0] - 64;
			int locrow1 = (int)temp1[1] - 48;
			int loccol = (int)temp[0] - 64;
			int locrow = (int)temp[1] - 48;
			if (loccol1 == loccol + 1 || loccol1 == loccol - 1 || locrow1 == locrow + 1 || locrow1 == loccol - 1 && chemTypearr[i] == "combustive") {
				check2 = 1;
			}
		}
		if (check1) {
			char* string = stringtochar(check1loc);
			int temp1 = (int)string[0];
			int temp2 = temp1 - 64;
			int temp3 = (int)string[1] - 48;
			if (temp2 == 1) {
				char posloc1 = (char)temp2 + 65;
				cout << "Location " << check1loc << " in cabinet " << "is already occupied. Nearest possible " << posloc1 << string[1] <<", "  << posloc1 << temp3 + 1 << ", " << string[0] << temp3 + 1 << endl;
			}
			else {
				char posloc1 = (char)temp2 + 65;
				char posloc2 = (char)temp2 + 63;
				cout << "Location " << check1loc << " in cabinet " << "is already occupied. Nearest possible " << posloc1 << string[1] << ", " << posloc1 << temp3 + 1 << ", " << string[0] << temp3 + 1 << ", " << posloc2 << string[1] << ", " << posloc2 << temp3 + 1 << endl;
			}
		}
		else if(check2) {
			cout << "Location " << location << " is not suitable for combustive chemical" << endl;
		}
		else {
			int newamount = chemicalamount + 1;
			
			int* tempcabinetid = new int[newamount];
			int* tempchemid = new int[newamount];
			string* templocation = new string[newamount];
			string* tempchemType = new string[newamount];

			for (int i = 0; i < chemicalamount; i++) {
				tempcabinetid[i] = cabinetIDarr[i];
				tempchemid[i] = chemIDarr[i];
				templocation[i] = locationarr[i];
				tempchemType[i] = chemTypearr[i];
			}

			tempcabinetid[chemicalamount] = cabinetId;
			tempchemid[chemicalamount] = chemID;
			templocation[chemicalamount] = location;
			tempchemType[chemicalamount] = chemType;

			chemicalamount++;

			delete[] cabinetIDarr;
			delete[] chemIDarr;
			delete[] chemTypearr;
			delete[] locationarr;

			cabinetIDarr = copyArray(tempcabinetid, chemicalamount);
			chemIDarr = copyArray(tempchemid, chemicalamount);
			locationarr = copyArray(templocation, chemicalamount);
			chemTypearr = copyArray(tempchemType, chemicalamount);

			delete[] tempcabinetid;
			delete[] tempchemid;
			delete[] templocation;
			delete[] tempchemType;

			cout << chemType << " chemical with ID: " << chemID << " has been placed at location: " << location << " in cabinet " << cabinetId << endl;
		}
	}
}


void LabOrganizer::findChemical(int id) {
	if (chemicalamount == 0) {

	}
	else {
		bool find = 1;
		for (int i = 0; i < chemicalamount; i++) {
			if (chemIDarr[i]==id) {
				cout << "chemical " << id << " is at location " << locationarr[i] << " in cabinet " << cabinetIDarr[i] << endl;
			}
			else {
				find= 0;
			}
		}
		if (find == 0) {
			cout << "chemical " << id << " is not in the system" << endl;
		}
	}
}

void LabOrganizer::removeChemical(int id) {
	if (chemicalamount == 0) {

	}
	else {
		bool check = 0;
		int position = 0;
		int cabinetofremoved = 0;
		for (int i = 0; i < chemicalamount; i++) {
			if (chemIDarr[i] == id) {
				check = 1;
				position = i;
				cabinetofremoved = cabinetIDarr[i];
			}
		}		
		if (check) {
			int* tempcabinetid;
			int* tempchemid;
			string* templocation;
			string* tempchemType;

			tempcabinetid = deleteitem(cabinetIDarr, chemicalamount, position);
			tempchemid = deleteitem(chemIDarr, chemicalamount, position);
			tempchemType = deleteitem(chemTypearr, chemicalamount, position);
			templocation = deleteitem(locationarr, chemicalamount, position);

			chemicalamount--;

			delete[] cabinetIDarr;
			delete[] chemIDarr;
			delete[] chemTypearr;
			delete[] locationarr;

			cabinetIDarr = copyArray(tempcabinetid, chemicalamount);
			chemIDarr = copyArray(tempchemid, chemicalamount);
			locationarr = copyArray(templocation, chemicalamount);
			chemTypearr = copyArray(tempchemType, chemicalamount);

			delete[] tempcabinetid;
			delete[] tempchemid;
			delete[] templocation;
			delete[] tempchemType;

			cout << "chemical " << id << " removed from cabinet " << cabinetofremoved << endl;
		}
		else {
			cout << "chemical " << id << " is not in the system" << endl;
		}
	}

}






