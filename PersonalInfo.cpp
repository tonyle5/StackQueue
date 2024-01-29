#include "PersonalInfo.h"

// Default constructor
PersonalInfo::PersonalInfo() {
  this->init(nullptr, nullptr);
}

// Constructor with arguments.
PersonalInfo::PersonalInfo(const char fullName[], const char email[]) {
  this->init(fullName, email);
}

// Copy constructor.
PersonalInfo::PersonalInfo(const PersonalInfo& personalInfo) {
  *this = personalInfo;
}

// Copy assignment operator.
PersonalInfo& PersonalInfo::operator=(const PersonalInfo& anotherOne) {
  if (this != &anotherOne) {
    this->init(anotherOne.fullName, anotherOne.email);
  }

  return *this;
}

// Overloads the << operator to display PersonalInfo.
ostream& operator<<(ostream& out, const PersonalInfo& personalInfo) {
  out << personalInfo.fullName << ';' << personalInfo.email;
  return out;
}

// Destructor
PersonalInfo::~PersonalInfo() {
  freeDynamicArray<char>(this->fullName);
  freeDynamicArray<char>(this->email);
}

// Getter for fullName
const char* PersonalInfo::getFullName() const {
  return fullName;
}

// Getter for email
const char* PersonalInfo::getEmail() const {
  return email;
}

// Setter for fullName
void PersonalInfo::setFullName(const char fullName[]) {
  setCharArr(fullName, this->fullName);
}

// Setter for email
void PersonalInfo::setEmail(const char email[]) {
  setCharArr(email, this->email);
}

// Initializes the PersonalInfo object.
void PersonalInfo::init(const char fullName[], const char email[]) {
  this->setFullName(fullName);
  this->setEmail(email);
}
