#ifndef PERSONALINFO_H
#define PERSONALINFO_H

#include "myUtil.h"

/**
 * This class represents the personal information of a customer.
 */
class PersonalInfo {
  private:
    char* fullName = nullptr;
    char* email = nullptr;

  public:
    /**
     * Default constructor
     */
    PersonalInfo();

    /**
     * Constructor with arguments.
     *
     * @param fullName The full name of the customer.
     * @param email The email address of the customer.
     */
    PersonalInfo(const char fullName[], const char email[]);

    /**
     * Copy constructor.
     *
     * @param personalInfo The personal info to copy.
     */
    PersonalInfo(const PersonalInfo&);

    /**
     * Copy assignment operator.
     *
     * @param anotherOne The personal info to copy.
     * @return The copied personal info.
     */
    PersonalInfo& operator=(const PersonalInfo& anotherOne);

    /**
     * Overloads the << operator to display PersonalInfo.
     *
     * @param[in, out] out The output stream to which the PersonalInfo will be
     *                 written.
     * @param          personalInfo The PersonalInfo to display.
     */
    friend ostream& operator<<(ostream& out, const PersonalInfo& personalInfo);

    /**
     * Destructor
     */
    ~PersonalInfo();

    /**
     * Getter for fullName
     *
     * @return The full name of the customer.
     */
    const char* getFullName() const;

    /**
     * Getter for email
     *
     * @return The email address of the customer.
     */
    const char* getEmail() const;

  private:
    /**
     * Setter for fullName
     *
     * @param fullName The full name of the customer.
     * @return void
     */
    void setFullName(const char fullName[]);

    /**
     * Setter for email
     *
     * @param email The email address of the customer.
     * @return void
     */
    void setEmail(const char email[]);

    /**
     * Initializes the PersonalInfo object.
     *
     * @param fullName The full name of the customer.
     * @param email The email address of the customer.
     * @return void
     */
    void init(const char fullName[], const char email[]);
};

#endif
