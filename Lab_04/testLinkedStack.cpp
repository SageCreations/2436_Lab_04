#include <iostream>
#include "myStack.h"

using namespace std;

int main() {
  stackType<int> stack1;
  stackType<int> stack2;

  stack1.initializeStack();
  stack1.push(23);
  stack1.push(45);
  stack1.push(38);

  // test equivalency operator
  // should be identical
  //if (stack1 == stack1) {
  //  cout << "stack1 and stack1 are identical" << endl;
  //} else {
  //  cout << "stack1 and stack1 are not identical" << endl;
  //}
  if (stack1.operator==(stack1)) {
    cout << "stack1 and stack1 are identical" << endl;
  } else {
    cout << "stack1 and stack1 are not identical" << endl;
  }

  // should not be identical
  // if (stack1 == stack2)
  //   cout << "stack1 and stack2 are identical" << endl;
  // else
  //   cout << "stack1 and stack2 are not identical" << endl;

  if (stack1.operator==(stack2)) {
    cout << "stack1 and stack2 are identical" << endl;
  } else {
    cout << "stack1 and stack2 are not identical" << endl;
  }

  // test assignment operator
  //stack2 = stack1;
  stack2.operator=(stack1);
  // should be identical
  // if (stack1 == stack2)
  //   cout << "after assignment: stack1 and stack2 are identical" << endl;
  // else
  //   cout << "after assignment: stack1 and stack2 are not identical" << endl;
  if (stack1.operator==(stack2)) {
    cout << "after assignment: stack1 and stack2 are identical" << endl;
  } else {
    cout << "after assignment: stack1 and stack2 are not identical" << endl;
  }

  // testing equivalency, after modifying one of the stacks
  // if (stack1 == stack2)
  //   cout << "before modifying stack2 : stack1 and stack2 are identical" << endl;
  // else
  //   cout << "before modifying stack2 : stack1 and stack2 are not identical" << endl;
  if (stack1.operator==(stack2)) {
    cout << "before modifying stack2 : stack1 and stack2 are identical" << endl;
  } else {
    cout << "before modifying stack2 : stack1 and stack2 are not identical" << endl;
  }
  
  // modify stack 2
  stack2.pop();
  stack2.push(32);
  stack2.push(35);

  // should NOT be identical
  // if (stack1 == stack2)
  //   cout << "after modifying stack2 : stack1 and stack2 are identical" << endl;
  // else
  //   cout << "after modifying stack2 : stack1 and stack2 are not identical" << endl;
  if (stack1.operator==(stack2)) {
    cout << "after modifying stack2 : stack1 and stack2 are identical" << endl;
  } else {
    cout << "after modifying stack2 : stack1 and stack2 are not identical" << endl;
  }

  
  cout << "testing reverseStack... " << endl;
  cout << "before reverseStack: stack1:" << endl;
  stack1.print();
  cout << "before reverseStack: stack2:" << endl;
  stack2.print();
  
  /* The statement: stack1.reverseStack(stack2); copies the elements of stack1
    onto stack2 in reverse order. That is, the top element of stack1 is the 
    bottom element of stack2, and so on. The old contents of stack2 are 
    destroyed, and stack1 is unchanged. */
  stack1.reverseStack(stack2);
  
  cout << "after reverseStack: stack1" << endl;
  stack1.print();
  cout << "after reverseStack: stack2" << endl;
  stack2.print();

  return 0;
}
