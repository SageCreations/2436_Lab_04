// Header File: linkedStack.h

#ifndef H_StackType
#define H_StackType

#include <cassert>
#include <iostream>

#include "stackADT.h"

using namespace std;

// Definition of the node
template <class Type>
struct nodeType {
  Type info;
  nodeType<Type>* link;
};

template <class Type>
class linkedStackType : public stackADT<Type> {
 public:
  // Overload the assignment operator.
  const linkedStackType<Type>& operator=(const linkedStackType<Type>&);

  // Function to determine whether the stack is empty.
  // Postcondition: Returns true if the stack is empty;
  //               otherwise returns false.

  bool isEmptyStack() const;

  // Function to determine whether the stack is full.
  // Postcondition: Returns false.
  bool isFullStack() const;

  // Function to initialize the stack to an empty state.
  // Postcondition: The stack elements are removed;
  //               stackTop = nullptr;
  void initializeStack();

  // Function to add newItem to the stack.
  // Precondition: The stack exists and is not full.
  // Postcondition: The stack is changed and newItem
  //               is added to the top of the stack.
  void push(const Type& newItem);

  // Function to return the top element of the stack.
  // Precondition: The stack exists and is not empty.
  // Postcondition: If the stack is empty, the program
  //               terminates; otherwise, the top
  //               element of the stack is returned.
  Type top() const;

  // Function to remove the top element of the stack.
  // Precondition: The stack exists and is not empty.
  // Postcondition: The stack is changed and the top
  //               element is removed from the stack.
  void pop();

  // Default constructor
  // Postcondition: stackTop = nullptr;
  linkedStackType();

  // Copy constructor
  linkedStackType(const linkedStackType<Type>& otherStack);

  // Destructor
  // Postcondition: All the elements of the stack are removed from the stack.
  ~linkedStackType();

  bool operator==(const linkedStackType<Type>& otherStack) const;

  void reverseStack(linkedStackType<Type>& otherStack);

  void print() const;

 private:
  nodeType<Type>* stackTop;  // pointer to the stack

  // Function to make a copy of otherStack.
  // Postcondition: A copy of otherStack is created and assigned to this stack.
  void copyStack(const linkedStackType<Type>& otherStack);
};

// Default constructor
template <class Type>
linkedStackType<Type>::linkedStackType() {
  stackTop = nullptr;
}

template <class Type>
bool linkedStackType<Type>::isEmptyStack() const {
  return (stackTop == nullptr);
}

template <class Type>
bool linkedStackType<Type>::isFullStack() const {
  return false;
}

template <class Type>
void linkedStackType<Type>::initializeStack() {
  nodeType<Type>* temp;  // pointer to delete the node

  while (stackTop != nullptr) {  // while there are elements in the stack
    temp = stackTop;             // set temp to point to the current node
    stackTop = stackTop->link;   // advance stackTop to the next node
    delete temp;                 // deallocate memory occupied by temp
  }
}

template <class Type>
void linkedStackType<Type>::push(const Type& newElement) {
  nodeType<Type>* newNode;  // pointer to create the new node

  newNode = new nodeType<Type>;  // create the node

  newNode->info = newElement;  // store newElement in the node
  newNode->link = stackTop;    // insert newNode before stackTop
  stackTop = newNode;          // set stackTop to point to the top node
}

template <class Type>
Type linkedStackType<Type>::top() const {
  assert(stackTop != nullptr);  // if stack is empty, terminate the program
  return stackTop->info;        // return the top element
}

template <class Type>
void linkedStackType<Type>::pop() {
  nodeType<Type>* temp;  // pointer to deallocate memory

  if (stackTop != nullptr) {
    temp = stackTop;  // set temp to point to the top node

    stackTop = stackTop->link;  // advance stackTop to the
                                // next node
    delete temp;                // delete the top node
  } else {
    cout << "Cannot remove from an empty stack." << endl;
  }
}

template <class Type>
void linkedStackType<Type>::copyStack(const linkedStackType<Type>& otherStack) {
  nodeType<Type>*newNode, *current, *last;

  if (stackTop != nullptr)  // if stack is nonempty, make it empty
    initializeStack();

  if (otherStack.stackTop == nullptr) {
    stackTop = nullptr;
  } else {
    current = otherStack.stackTop;  // set current to point to the stack to be copied

    // copy the stackTop element of the stack
    stackTop = new nodeType<Type>;   // create the node
    stackTop->info = current->info;  // copy the info
    stackTop->link = nullptr;  // set the link field of the node to nullptr
    last = stackTop;           // set last to point to the node
    current = current->link;   // set current to point to the next node

    // copy the remaining stack
    while (current != nullptr) {
      newNode = new nodeType<Type>;   // create new node
      newNode->info = current->info;  // assign the info 
      newNode->link = nullptr;        // set link to nullptr
      last->link = newNode;           // point last nodes link to this new node
      last = newNode;                 // point last to new node
      current = current->link;
    }
  }
}

// copy constructor
template <class Type>
linkedStackType<Type>::linkedStackType(
    const linkedStackType<Type>& otherStack) {
  stackTop = nullptr;
  copyStack(otherStack);
}

// destructor
template <class Type>
linkedStackType<Type>::~linkedStackType() {
  initializeStack();
}

// overloading the assignment operator
template <class Type>
const linkedStackType<Type>& linkedStackType<Type>::operator=(const linkedStackType<Type>& otherStack) {
  if (this != &otherStack)  // avoid self-copy
    copyStack(otherStack);

  return *this;
}


// todo: defintion of equivalance operator overload to go here 
template <class Type>
bool linkedStackType<Type>::operator==(const linkedStackType<Type>& otherStack) const {
  return *this == otherStack;
}

// todo: defintion of reverseStack to go here
template <class Type>
void linkedStackType<Type>::reverseStack(linkedStackType<Type>& otherStack) {

}


template <class Type>
void linkedStackType<Type>::print() const {
  nodeType<Type>* current = stackTop;

  while (current != nullptr) {
    cout << current->info << endl;
    current = current->link;
  }
}

#endif