//Alp Tuðrul Aðçalý
//218017999

#pragma once
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#include "FlowerLibrary.h"
#include "Flower.h"

FlowerLibrary::FlowerLibrary() {

}

FlowerLibrary::~FlowerLibrary() {

}

void FlowerLibrary::addFlower(string name) {
	for_each(name.begin(), name.end(), [](char& c) {
		c = ::tolower(c);
		});

	bool added = 0;
	if (!flowers.checkExistanceFlower(name)) {
		added = flowers.add(name);
	}
	if (added)
		cout << name << "  has been added into the library." << endl;
	else
		cout << name << " cannot be added into the library because it already exists." << endl;
}

void FlowerLibrary::removeFlower(string name) {
	for_each(name.begin(), name.end(), [](char& c) {
		c = ::tolower(c);
		});
	bool removed = 0;
	if (flowers.checkExistanceFlower(name)) {
		removed = flowers.remove(name);
	}
	if (removed)
		cout << name << "  has been removed from the library." << endl;
	else
		cout << name << " cannot be removed because it's not in the library." << endl;
}

void FlowerLibrary::listFlowers() const {
	if (flowers.getLength() == 0) {
		cout << "Library is empty." << endl;
	}
	else {
		flowers.PrintFlowerList();
	}
}

void FlowerLibrary::addFeature(string name, string feature) {
	for_each(name.begin(), name.end(), [](char& c) {
		c = ::tolower(c);
		});
	for_each(feature.begin(), feature.end(), [](char& c) {
		c = ::tolower(c);
		});

	if (flowers.checkExistanceFlower(name)) {
		if (!flowers.returnFlower(name).checkExistenceFeature(feature)){
			flowers.returnFlower(name).add(feature);
			cout << feature << " is added into  " <<name << endl;
		}			
		else
			cout << feature << " already exists in " << name << endl;
	}
	else
		cout << name << " isn't found in library" << endl;
}

void FlowerLibrary::removeFeature(string name, string feature) {
	for_each(name.begin(), name.end(), [](char& c) {
		c = ::tolower(c);
		});
	for_each(feature.begin(), feature.end(), [](char& c) {
		c = ::tolower(c);
		});
	if (flowers.checkExistanceFlower(name)) {
		if (flowers.returnFlower(name).checkExistenceFeature(feature)) {
			
			flowers.returnFlower(name).remove(feature);

			cout << feature << " is removed from " << name << endl;
		}
		else
			cout << feature << " doesn't exist in " << name <<  endl;
	}
	else
		cout << name << " isn't found in library" << endl;
}

void  FlowerLibrary::listFeatures(string name) const {
	if (flowers.checkExistanceFlower(name)) {
		flowers.PrintFlower(name);
	}
	else
	{
		cout << name << " isn't found in library" << endl;
	}
}

void FlowerLibrary::findFlowers(string feature) const {
	for_each(feature.begin(), feature.end(), [](char& c) {
		c = ::tolower(c);
		});
	cout << feature << " flowers: ";	
	if (flowers.findFlower(feature)==0) {
		cout << "there is no such flower";
	}

	cout << endl;
}