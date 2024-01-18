#include "Stack.h"

Stack::Stack(int capacity) : top(0) {
  this->curCapacity = capacity;
  aStack = new PersonalInfo*[this->curCapacity];

  for (int i = 0; i < this->curCapacity; i++) {
    aStack[i] = nullptr;
  }
}

Stack::Stack(const Stack& aStack) : aStack(nullptr), top(0) {
  *this = aStack;
}

Stack::~Stack() {
  destroy();
}

void Stack::destroy() {
  if (this->aStack) {
    for (int i = 0; i < this->top; i++) {
      if (this->aStack[i]) {
        delete this->aStack[i];
      }
    }

    delete[] this->aStack;
  }
}

const Stack& Stack::operator=(const Stack& stackSrc) {
  if (this != &stackSrc) {
    this->destroy();

    this->top = stackSrc.top;
    this->curCapacity = stackSrc.curCapacity;
    this->aStack = new PersonalInfo*[this->curCapacity];

    for (int i = 0; i < top; i++) {
      this->aStack[i] =
        new PersonalInfo(*(stackSrc.aStack[i]));  // copy the customer
    }
  }

  return *this;
}

ostream& operator<<(ostream& out, const Stack& srcStack) {
  if (srcStack.top != 0) {
    for (int i = 0; i < srcStack.top; i++) {
      out << *(srcStack.aStack[i]) << endl;
    }
  }

  return out;
}

void Stack::push(const PersonalInfo& personalInfo) {
  if (this->curCapacity == top) {
    expand();
  }

  this->aStack[top] = new PersonalInfo(personalInfo);
  this->top++;
}

bool Stack::pop(PersonalInfo& personalInfo) {
  if (this->top == 0) {
    return false;
  }

  personalInfo = *(this->aStack[this->top - 1]);
  delete aStack[top - 1];
  this->top--;

  return true;
}

bool Stack::peek(PersonalInfo& personalInfo) {
  if (this->top == 0) {
    return false;
  }

  personalInfo = *(this->aStack[this->top - 1]);

  return true;
}

int Stack::getSize() const {
  return this->top;
}

bool Stack::isEmpty() const {
  return this->top == 0;
}

int Stack::loadData(const char* fileName) {
  ifstream inFile;
  inFile.open(fileName);

  if (!inFile) {
    return ERROR;
  }

  char customerFullName[STR_SIZE];
  char email[STR_SIZE];

  inFile.ignore(numeric_limits<streamsize>::max(), '\n');

  inFile.getline(customerFullName, STR_SIZE, ';');

  while (!inFile.eof()) {
    inFile.getline(email, STR_SIZE, '\n');

    this->push(PersonalInfo(customerFullName, email));

    inFile.getline(customerFullName, STR_SIZE, ';');
  }

  inFile.close();

  return this->top;
}

bool Stack::writeData(const char* fileName) const {
  ofstream outFile;
  outFile.open(fileName);

  if (!outFile) {
    return false;
  }

  outFile << "Full name; Email" << endl;
  outFile << *this;

  outFile.close();

  return true;
}

void Stack::expand() {
  this->curCapacity *= GROWTH_FACTOR;
  PersonalInfo** tempStack = new PersonalInfo*[this->curCapacity];

  for (int i = 0; i < this->top; i++) {
    tempStack[i] = aStack[i];  // only copy the pointers
  }

  delete[] this->aStack;
  this->aStack = tempStack;
}
