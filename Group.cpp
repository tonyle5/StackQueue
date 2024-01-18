#include "Group.h"

/**
 *  This is the default constructor.
 */
Group::Group() {
  this->init(nullptr, 0, false, nullptr, false, PersonalInfo());
}

// This is the constructor with arguments.
Group::Group(char groupName[], int numPeople, bool isSpecialSeatingNeeded,
             char seatingInfo[], bool isPromoAllowed,
             PersonalInfo personalInfo) {
  this->init(groupName, numPeople, isSpecialSeatingNeeded, seatingInfo,
             isPromoAllowed, personalInfo);
}

// Copy constructor
Group::Group(const Group& group) {
  *this = group;
}

// Copy assignment operator.
Group& Group::operator=(const Group& anotherOne) {
  if (this != &anotherOne) {
    this->init(anotherOne.groupName, anotherOne.numPeople,
               anotherOne.isSpecialSeatingNeeded, anotherOne.seatingInfo,
               anotherOne.isPromoAllowed, anotherOne.personalInfo);
  }

  return *this;
}

// Destructor
Group::~Group() {
  freeDynamicArray<char>(this->groupName);
  freeDynamicArray<char>(this->seatingInfo);
}

// Getter for groupName
const char* Group::getGroupName() const {
  return this->groupName;
}

// Getter for numPeople
int Group::getNumPeople() const {
  return numPeople;
}

// Getter for isSpecialSeatingNeeded
bool Group::getIsSpecialSeatingNeeded() {
  return this->isSpecialSeatingNeeded;
}

// Getter for seatingInfo
const char* Group::getSeatingInfo() const {
  return this->seatingInfo;
}

// Getter for isPromoAllowed
bool Group::getIsPromoAllowed() {
  return this->isPromoAllowed;
}

// Getter for personalInfo
const PersonalInfo Group::getPersonalInfo() const {
  return this->personalInfo;
}

// This function prints the data of the group.
void Group::printInformation(ostream& os) {
  os << this->getGroupName() << ";";
  os << this->getNumPeople() << ";";

  os << this->isSpecialSeatingNeeded << ";";
  const char* seatingInfo = this->getSeatingInfo();
  os << (seatingInfo ? seatingInfo : "") << ";";

  os << this->isPromoAllowed << ";";
  os << (this->isPromoAllowed ? this->personalInfo.getFullName() : "") << ";";
  os << (this->isPromoAllowed ? this->personalInfo.getEmail() : "");
}

// Setter for groupName
void Group::setGroupName(const char groupName[]) {
  setCharArr(groupName, this->groupName);
}

// Setter for numPeople
void Group::setNumPeople(int numPeople) {
  this->numPeople = numPeople;
}

// Setter for isSpecialSeatingNeeded
void Group::setIsSpecialSeatingNeeded(bool isSpecialSeatingNeeded) {
  this->isSpecialSeatingNeeded = isSpecialSeatingNeeded;
}

// Setter for seatingInfo
void Group::setSeatingInfo(const char seatingInfo[]) {
  setCharArr(seatingInfo, this->seatingInfo);
}

// Setter for isPromoAllowed
void Group::setIsPromoAllowed(bool isPromoAllowed) {
  this->isPromoAllowed = isPromoAllowed;
}

// Setter for personalInfo
void Group::setPersonalInfo(PersonalInfo& personalInfo) {
  this->personalInfo = personalInfo;
}

// This function initializes the group's information.
void Group::init(char groupName[], int numPeople, bool isSpecialSeatingNeeded,
                 char seatingInfo[], bool isPromoAllowed,
                 PersonalInfo personalInfo) {
  this->setGroupName(groupName);
  this->setNumPeople(numPeople);

  this->setIsSpecialSeatingNeeded(isSpecialSeatingNeeded);
  this->setSeatingInfo(isSpecialSeatingNeeded ? seatingInfo : nullptr);

  this->setIsPromoAllowed(isPromoAllowed);
  this->setPersonalInfo(personalInfo);
}
