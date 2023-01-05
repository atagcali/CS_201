//Alp Tuðrul Aðçalý
//218017999

#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Flower.h"
class FlowerList {
public:
	FlowerList();
	FlowerList(const FlowerList& aList);
	~FlowerList();
	bool isEmpty() const;
	int getLength() const;
	bool retrieve(string flowerName, Flower& flower) const;	
	Flower& returnFlower(string name);
	bool add(string flowerName);
	bool remove(string flowerName);
	bool remove(int index);
	void PrintFlowerList() const;
	void PrintFlower(string FLowername) const;
	bool findFlower(string feature) const;
	bool checkExistanceFlower(string flowerName) const;
private:
	struct FlowerNode {
		Flower f;
		FlowerNode* next;
	};
	int size;
	FlowerNode* head; //the flowers are stored in a sorted singly linear linked list
	FlowerNode* find(int index) const;
	// ...
	//you may define additional member functions and data members, if necessary
};
