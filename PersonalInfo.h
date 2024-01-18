#ifndef PERSONALINFO_H
#define PERSONALINFO_H

#include "myUtil.h"

class PersonalInfo {
  private:
    char* fullName = nullptr;
    char* email = nullptr;

  public:
    // Default constructor
    PersonalInfo();

    // Constructor with arguments
    PersonalInfo(char fullName[], char email[]);

    // Copy constructor
    PersonalInfo(const PersonalInfo&);

    // Copy assignment operator
    PersonalInfo& operator=(const PersonalInfo& anotherOne);

    friend ostream& operator<<(ostream& out, const PersonalInfo& personalInfo);

    // Destructor
    ~PersonalInfo();

    // Getter for fullName
    const char* getFullName() const;

    // Getter for email
    const char* getEmail() const;

  private:
    // Setter for fullName
    void setFullName(const char fullName[]);

    // Setter for email
    void setEmail(const char email[]);

    void init(char fullName[], char email[]);
};

#endif
