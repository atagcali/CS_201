#include <string>
#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack() : topPtr(NULL) {

}


Stack::~Stack() {
	while (!isEmpty())
		pop();
}


Stack::Stack(const Stack& aStack) {

    if (aStack.topPtr == NULL)
        topPtr = NULL;  // original stack is empty

    else {
        // copy first node
        topPtr = new StackNode;
        topPtr->item = aStack.topPtr->item;

        // copy rest of stack
        StackNode* newPtr = topPtr;
        for (StackNode* origPtr = aStack.topPtr->next;
            origPtr != NULL;
            origPtr = origPtr->next) {
            newPtr->next = new StackNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }
        newPtr->next = NULL;
    }
}


bool Stack::isEmpty() const {
    return topPtr == NULL;
}


bool Stack::push(StackItemType newItem) {
    StackNode* newPtr = new StackNode;
    newPtr->item = newItem;
    newPtr->next = topPtr;
    topPtr = newPtr;

    return true;
}


bool Stack::pop() {
    if (isEmpty())
        return false;

    else {
        StackNode* temp = topPtr;
        topPtr = topPtr->next;
        temp->next = NULL;  // safeguard
        delete temp;
        return true;
    }
}


bool Stack::pop(StackItemType& stackTop) {

    if (isEmpty())
        return false;

    // not empty; retrieve and delete top 
    else {
        stackTop = topPtr->item;
        StackNode* temp = topPtr;
        topPtr = topPtr->next;

        // return deleted node to system
        temp->next = NULL;  // safeguard
        delete temp;
        return true;
    }
}


bool Stack::getTop(StackItemType& stackTop) const {

    if (isEmpty())
        return false;

    // stack is not empty; retrieve top
    else {
        stackTop = topPtr->item;
        return true;
    }

}

StackItemType Stack::getTop() {
    if (isEmpty())
        return false;

    // stack is not empty; retrieve top
    else {
        return topPtr->item;
    }
}
Stackint::Stackint() : topPtr(NULL) {

}


Stackint::~Stackint() {
    while (!isEmpty())
        pop();
}


Stackint::Stackint(const Stackint& aStack) {

    if (aStack.topPtr == NULL)
        topPtr = NULL;  // original stack is empty

    else {
        // copy first node
        topPtr = new StackNode;
        topPtr->item = aStack.topPtr->item;

        // copy rest of stack
        StackNode* newPtr = topPtr;
        for (StackNode* origPtr = aStack.topPtr->next;
            origPtr != NULL;
            origPtr = origPtr->next) {
            newPtr->next = new StackNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }
        newPtr->next = NULL;
    }
}


bool Stackint::isEmpty() const {
    return topPtr == NULL;
}


bool Stackint::push(stackItemType newItem) {
    StackNode* newPtr = new StackNode;
    newPtr->item = newItem;
    newPtr->next = topPtr;
    topPtr = newPtr;

    return true;
}


bool Stackint::pop() {
    if (isEmpty())
        return false;

    else {
        StackNode* temp = topPtr;
        topPtr = topPtr->next;
        temp->next = NULL;  // safeguard
        delete temp;
        return true;
    }
}


bool Stackint::pop(stackItemType& stackTop) {

    if (isEmpty())
        return false;

    // not empty; retrieve and delete top 
    else {
        stackTop = topPtr->item;
        StackNode* temp = topPtr;
        topPtr = topPtr->next;

        // return deleted node to system
        temp->next = NULL;  // safeguard
        delete temp;
        return true;
    }
}


bool Stackint::getTop(stackItemType& stackTop) const {

    if (isEmpty())
        return false;

    // stack is not empty; retrieve top
    else {
        stackTop = topPtr->item;
        return true;
    }

}

stackItemType Stackint::getTop() {
    if (isEmpty())
        return false;

    // stack is not empty; retrieve top
    else {
        return topPtr->item;
    }
}
