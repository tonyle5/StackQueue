#ifndef CUSTOMERSTACK_H
#define CUSTOMERSTACK_H

#include "PersonalInfo.h"

class Stack {
  private:
    PersonalInfo** aStack;
    int curCapacity;
    int top;

  public:
    Stack(int capacity = INIT_CAP);
    Stack(const Stack& aStack);
    ~Stack();

    const Stack& operator=(const Stack& aStack);
    friend ostream& operator<<(ostream& out, const Stack& aStack);

    void push(const PersonalInfo& personalInfo);
    bool pop(PersonalInfo& personalInfo);
    bool peek(PersonalInfo& personalInfo);
    int getSize() const;
    bool isEmpty() const;

    int loadData(const char* fileName);
    bool writeData(const char* fileName) const;

  private:
    void destroy();
    void expand();
};

#endif
