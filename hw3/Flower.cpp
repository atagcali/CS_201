//Alp Tuðrul Aðçalý
//218017999

#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Flower.h"

Flower::Flower() : size(0), head(NULL) {
    
}

Flower::Flower(string flowerName) : size(0), head(NULL) {
	this->flowerName = flowerName;
}

Flower::Flower(const Flower& aFlower) : size(aFlower.size) {
    if (aFlower.head == NULL)
        head = NULL;  // original list is empty
    else {
        // copy first node
        head = new FeatureNode;
        head->feature = aFlower.head->feature;
        // copy rest of list
        FeatureNode* newPtr = head;  // new list ptr

        for (FeatureNode* origPtr = aFlower.head->next; origPtr != NULL; origPtr = origPtr->next) {
            newPtr->next = new FeatureNode;
            newPtr = newPtr->next;
            newPtr->feature = origPtr->feature;
        }
        newPtr->next = NULL;
    }

}


Flower::~Flower() {
    while (!isEmpty())
        remove(1);
}


bool Flower::isEmpty() const {
	return size == 0;
}

int Flower::getLength() const {
	return size;
}

string Flower::getFlowerName() const {
    return flowerName;
}

void Flower::setFlowerName(string flowerName) {
    this->flowerName = flowerName;
}

Flower::FeatureNode *Flower::find(int index) const {
    if ((index < 1) || (index > getLength()))
        return NULL;

    else { // count from the beginning of the list
        FeatureNode* cur = head;
        for (int skip = 1; skip < index; ++skip)
            cur = cur->next;
        return cur;
    }

}

bool Flower::add(string feature) {
    int index = 1;
    bool breaked = 0;
    if (size != 0) {
        //indexfinding
        for (FeatureNode* checkNode = head; checkNode != NULL; checkNode = checkNode->next) {
            if (checkNode->feature.at(0) > feature.at(0)) {
                break;
            }
            else if (checkNode->feature.at(0) == feature.at(0)) {
                int i = 0;
                while (checkNode->feature.at(i) == feature.at(i) && i < checkNode->feature.length()) {
                    i++;
                    if (checkNode->feature.at(i) < feature.at(i)) {
                        index++;
                        breaked = 1;
                        break;
                    }
                    else
                    {
                        breaked = 1;
                        break;
                    }
                }
            }                        
            if (breaked)
                break;
            index++;
        }
    }
    //adding

    if ((index < 1) || (index > size+1)) {
        return false;
        cout << "error at index(addfeature)" << endl;
    }
    int newLength = getLength() + 1;
    FeatureNode* newPtr = new FeatureNode;
    size = newLength;
    newPtr->feature = feature;

    if (index == 1) {
        newPtr->next = head;
        head = newPtr;
    }
    else {
        FeatureNode* prev = find(index - 1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }
    return true;

}


bool Flower::remove(string feature) {
    //finding index 
    int index = 0;
    bool finded = 0;
    for (FeatureNode* checker = head; checker != NULL; checker = checker->next) {  
        index++;
        if (checker->feature == feature) {
            break;
            finded = 1;
        }
    }
    //removing
    FeatureNode* cur;

    if ((index < 1) || (index > getLength()))
        return false;

    --size;
    if (index == 1) {
        cur = head;
        head = head->next;
    }
    else {
        FeatureNode* prev = find(index - 1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;

    return true;

}


bool Flower::remove(int index) {
    FeatureNode* cur;

    if ((index < 1) || (index > getLength()))
        return false;

    --size;
    if (index == 1) {
        cur = head;
        head = head->next;
    }
    else {
        FeatureNode* prev = find(index - 1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;

    return true;
}


string Flower::printFlower() const {
    cout << flowerName << ":";
    if (head == NULL) {
        cout << " No feature";
    }
    for (FeatureNode* origPtr = head; origPtr != NULL; origPtr = origPtr->next) {
        if (origPtr != head) {
            cout << ", " << origPtr->feature;
        }
        else
            cout << origPtr->feature;
    }
    cout << endl;
    return flowerName;
}

bool Flower::checkExistenceFeature(string featureName) const {
    for (FeatureNode* check = head; check != NULL; check = check->next) {
        if (check->feature == featureName) {
            return 1;
        }
    }
    return 0;
}