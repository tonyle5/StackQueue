#include "Stack.h"

// Default constructor
Stack::Stack(int capacity) : top(0) {
  this->curCapacity = capacity;
  aStack = new PersonalInfo*[this->curCapacity];

  for (int i = 0; i < this->curCapacity; i++) {
    aStack[i] = nullptr;
  }
}

// Copy constructor
Stack::Stack(const Stack& aStack) : aStack(nullptr), top(0) {
  *this = aStack;
}

// Destructor
Stack::~Stack() {
  destroy();
}

// Destroys the stack.
void Stack::destroy() {
  if (this->aStack) {
    this->deleteR(0);
    delete[] this->aStack;
  }
}

// Delete the stack recursively.
void Stack::deleteR(int index) {
  if (index == this->top) {
    return;
  }

  if (this->aStack[index]) {
    delete this->aStack[index];
  }

  deleteR(index + 1);
}

// Assignment operator
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

// Overloads the << operator to display Stack.
ostream& operator<<(ostream& out, const Stack& srcStack) {
  if (srcStack.top != 0) {
    for (int i = 0; i < srcStack.top; i++) {
      out << *(srcStack.aStack[i]) << endl;
    }
  }

  return out;
}

// Adds a customer to the stack.
void Stack::push(const PersonalInfo& personalInfo) {
  if (this->curCapacity == top) {
    expand();
  }

  this->aStack[top] = new PersonalInfo(personalInfo);
  this->top++;
}

// Removes the top customer from the stack.
bool Stack::pop(PersonalInfo& personalInfo) {
  if (this->top == 0) {
    return false;
  }

  personalInfo = *(this->aStack[this->top - 1]);
  delete aStack[top - 1];
  this->top--;

  return true;
}

// Views the top customer without removing them.
bool Stack::peek(PersonalInfo& personalInfo) {
  if (this->top == 0) {
    return false;
  }

  personalInfo = *(this->aStack[this->top - 1]);

  return true;
}

// Get the number of customers in the stack.
int Stack::getSize() const {
  return this->top;
}

// Checks if the stack is empty.
bool Stack::isEmpty() const {
  return this->top == 0;
}

// Loads customer data from a file into the stack.
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

// Writes customer data from the stack to a file.
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

// Expands the stack.
void Stack::expand() {
  this->curCapacity *= GROWTH_FACTOR;
  PersonalInfo** tempStack = new PersonalInfo*[this->curCapacity];

  for (int i = 0; i < this->top; i++) {
    tempStack[i] = aStack[i];  // only copy the pointers
  }

  delete[] this->aStack;
  this->aStack = tempStack;
}
