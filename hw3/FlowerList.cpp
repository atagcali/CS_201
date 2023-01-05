//Alp Tuðrul Aðçalý
//218017999

#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "FlowerList.h"


FlowerList::FlowerList() : size(0), head(NULL) {

}

FlowerList::FlowerList(const FlowerList& aList) : size(aList.size) {
    if (aList.head == NULL)
        head = NULL;  // original list is empty
    else {
        // copy first node
        head = new FlowerNode;
        head->f = aList.head->f;
        // copy rest of list
        FlowerNode* newPtr = head;  // new list ptr

        for (FlowerNode* origPtr = aList.head->next;
            origPtr != NULL;
            origPtr = origPtr->next) {
            newPtr->next = new FlowerNode;
            newPtr = newPtr->next;
            newPtr->f = origPtr->f;
        }
        newPtr->next = NULL;
    }

}

FlowerList::~FlowerList() {
    while (!isEmpty()) {
        remove(1);
    }
}


bool FlowerList::isEmpty() const {
    return size == 0;
}

int FlowerList::getLength() const {
    return size;
}

FlowerList::FlowerNode* FlowerList::find(int index) const {
    if ((index < 1) || (index > getLength()))
        return NULL;

    else { // count from the beginning of the list
        FlowerNode* cur = head;
        for (int skip = 1; skip < index; ++skip)
            cur = cur->next;
        return cur;
    }
}

bool FlowerList::add(string Flowername) {        
    for (int i = 0; i < Flowername.length(); i++) {
        if (Flowername[i] >= 65 && Flowername[i] <= 92)
        {
            Flowername[i] = Flowername[i] + 32;
        }
    }
    int index = 1;
    bool breaked = 0;
    if (size != 0) {
        //indexfinding
        for (FlowerNode* checkNode = head; checkNode != NULL; checkNode = checkNode->next) {
            if (checkNode->f.getFlowerName().at(0) > Flowername.at(0)) {
                break;
            }
            else if (checkNode->f.getFlowerName().at(0) == Flowername.at(0)) {
                int i = 0;
                while (checkNode->f.getFlowerName().at(i) == Flowername.at(i) && i < checkNode->f.getFlowerName().length()) {
                    i++;
                    if (checkNode->f.getFlowerName().at(i) < Flowername.at(i)) {
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
        int newLength = getLength() + 1;
    if ((index < 1) || (index > newLength)) {
        return false;
        cout << "error at index(addfeature)" << endl;
    }
    FlowerNode* newPtr = new FlowerNode;
    size = newLength;
    newPtr->f.setFlowerName(Flowername);
    if (index == 1) {
        newPtr->next = head;
        head = newPtr;
    }
    else {
        FlowerNode* prev = find(index - 1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }
    return true;
    

}


bool FlowerList::remove(string flowerName) {
    //finding index 
    int index = 1;
    bool finded = 0;
    for (FlowerNode* checker = head; checker != NULL; checker = checker->next) {
        if (checker->f.getFlowerName() == flowerName) {
            finded = 1;
            break;
        }
        index++;
    }
    if (finded == 0) {
        return 0;
    }
    //removing
    
    else {
        FlowerNode* cur;
        if ((index < 1) || (index > getLength()))
            return false;

        --size;
        if (index == 1) {
cur = head;
head = head->next;
        }
        else {
        FlowerNode* prev = find(index - 1);
        cur = prev->next;
        prev->next = cur->next;
        }
        cur->next = NULL;
        delete cur;
        cur = NULL;

        return true;
    }
}

bool FlowerList::retrieve(string flowerName, Flower& flower) const {
    //finding index 
    int index = 1;
    bool finded = 0;
    for (FlowerNode* checker = head; checker != NULL; checker = checker->next) {
        if (checker->f.getFlowerName() == flowerName) {
            finded = 1;
            break;
        }
        index++;

    }
    if (!finded)
        return false;
    if ((index < 1) || (index > getLength()))
        return false;

    // get pointer to node, then data in node
    FlowerNode* cur = find(index);
    flower = cur->f;
    return true;

}


bool FlowerList::remove(int index) {
    FlowerNode* cur;

    if ((index < 1) || (index > getLength()))
        return false;

    --size;
    if (index == 1) {
        cur = head;
        head = head->next;
    }
    else {
        FlowerNode* prev = find(index - 1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;

    return true;
}



void FlowerList::PrintFlowerList() const {
    for (FlowerNode* origPtr = head; origPtr != NULL; origPtr = origPtr->next) {
        origPtr->f.printFlower();
    }
}

void FlowerList::PrintFlower(string flowerName) const {
    for (FlowerNode* check = head; check != NULL; check = check->next) {
        if (check->f.getFlowerName() == flowerName)
            check->f.printFlower();
    }
}


bool FlowerList::checkExistanceFlower(string flowerName) const {
    for (FlowerNode* check = head; check != NULL; check = check->next) {
        if (check->f.getFlowerName() == flowerName)
            return 1;
    }
    return 0;
}

Flower& FlowerList::returnFlower(string flowerName) {
    int index = 1;
    for (FlowerNode* checker = head; checker != NULL; checker = checker->next) {
        if (checker->f.getFlowerName() == flowerName) {
            return checker->f;
        }
        index++;
    }
}

bool FlowerList::findFlower(string feature) const {
    int finded = 0;
    for (FlowerNode* check = head; check != NULL; check = check->next){
        if (check->f.checkExistenceFeature(feature) && finded != 0) {
            cout << ", " << check->f.getFlowerName();
            finded++;
        }
        else if (check->f.checkExistenceFeature(feature) && finded == 0) {
            cout << check->f.getFlowerName() ;
            finded++;
        }       
    }
    if (finded == 0) {
        return 0;
    }
    else
        return 1;
    
}