# 2436_Lab_04

lab04 : Stacks

1a. Two stacks of the same type are the same if they have the same number of elements and their elements at the corresponding positions are the same.

1a. Overload the relational operator == for the class linkedStackType that returns true if two stacks of the same type are the same; it returns false otherwise. Write the definition of the function template to overload this operator.

1b. Add the following operation to the class linkedStackType.

void reverseStack(stackType<Type> &otherStack);

This operation copies the elements of a stack in reverse order onto another stack.

Consider the following statements:
stackType<int> stack1;
stackType<int> stack2;

The statement:
stack1.reverseStack(stack2);
copies the elements of stack1 onto stack2 in reverse order. That is, the top element of stack1 is the bottom element of stack2, and so on. The old contents of stack2 are destroyed, and stack1 is unchanged.

1c. Write enough code in linkedStackDriver to test the operation of the overloaded equality operator.

1d. Note: Test code has been included, but commented out, to test the operation of the templated function to reverseStack. Be sure to uncomment this code in your tester application.
