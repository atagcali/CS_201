#pragma once
#include <string>
#include <iostream>
using namespace std;

typedef char StackItemType;
class Stack{

public:
   Stack();
   Stack(const Stack& aStack);
   ~Stack();
   bool isEmpty() const;
   bool push(StackItemType newItem);
   bool pop();
   bool pop(StackItemType& stackTop);
   bool getTop(StackItemType& stackTop) const;
   StackItemType getTop();


private:
   struct StackNode {            // a node on the stack
      StackItemType item;        // a data item on the stack
      StackNode    *next;        // pointer to next node
   };

   StackNode *topPtr;     // pointer to first node in the stack
};

typedef int stackItemType;
class Stackint {

public:
    Stackint();
    Stackint(const Stackint& aStack);
    ~Stackint();
    bool isEmpty() const;
    bool push(stackItemType newItem);
    bool pop();
    bool pop(stackItemType& stackTop);
    bool getTop(stackItemType& stackTop) const;
    stackItemType getTop();


private:
    struct StackNode {            // a node on the stack
        stackItemType item;        // a data item on the stack
        StackNode* next;        // pointer to next node
    };

    StackNode* topPtr;     // pointer to first node in the stack
};