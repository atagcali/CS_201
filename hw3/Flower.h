//Alp Tuðrul Aðçalý
//218017999

#pragma once
#include <string>
#include <iostream>
using namespace std;
class Flower {
public:
	Flower();
	Flower(string flowerName);
	Flower(const Flower& aFlower);
	~Flower();
	bool isEmpty() const;
	int getLength() const;
	string getFlowerName() const;
	void setFlowerName(string flowerName);
	bool add(string feature);
	bool remove(string feature);
	bool remove(int index);
	string printFlower() const;
	bool checkExistenceFeature(string featureName) const;
private:
	struct FeatureNode {		
		string feature;
		FeatureNode* next;
	};
	int size;
	string flowerName;
	FeatureNode* head; //the features are stored in a sorted singly linear linked list
	FeatureNode* find(int index) const;

	// ...
	//you may define additional member functions and data members, if necessary
};