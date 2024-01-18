#include "PersonalInfo.h"

// PersonalInfo class implementation
PersonalInfo::PersonalInfo() {
  this->init(nullptr, nullptr);
}

PersonalInfo::PersonalInfo(char fullName[], char email[]) {
  this->init(fullName, email);
}

void PersonalInfo::init(char fullName[], char email[]) {
  this->setFullName(fullName);
  this->setEmail(email);
}

PersonalInfo::PersonalInfo(const PersonalInfo& personalInfo) {
  *this = personalInfo;
}

PersonalInfo& PersonalInfo::operator=(const PersonalInfo& anotherOne) {
  if (this != &anotherOne) {
    this->init(anotherOne.fullName, anotherOne.email);
  }

  return *this;
}

ostream& operator<<(ostream& out, const PersonalInfo& personalInfo) {
  out << personalInfo.fullName << ';' << personalInfo.email;
  return out;
}

PersonalInfo::~PersonalInfo() {
  freeDynamicArray<char>(this->fullName);
  freeDynamicArray<char>(this->email);
}

const char* PersonalInfo::getFullName() const {
  return fullName;
}

void PersonalInfo::setFullName(const char fullName[]) {
  setCharArr(fullName, this->fullName);
}

const char* PersonalInfo::getEmail() const {
  return email;
}

void PersonalInfo::setEmail(const char email[]) {
  setCharArr(email, this->email);
}
