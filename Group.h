#ifndef GROUP_H
#define GROUP_H

#include "myUtil.h"
#include "PersonalInfo.h"

/**
 * This class represents a group of people who are going to the restaurant.
 */
class Group {
  private:
    char* groupName = nullptr;
    int numPeople = 0;

    bool isSpecialSeatingNeeded = false;
    char* seatingInfo = nullptr;

    bool isPromoAllowed = false;
    PersonalInfo personalInfo;

  public:
    /**
     * Default constructor
     */
    Group();

    /**
     * Constructor with arguments.
     *
     * @param groupName The name of the group.
     * @param numPeople The number of people in the group.
     * @param isSpecialSeatingNeeded Whether anyone in the group needs
     *        special seating, such as a high chair or wheel chair.
     * @param seatingInfo The special seating information.
     * @param isPromoAllowed Whether he group would like to receive
     *        coupons and other promotional materials.
     * @param personalInfo The personal information of the
     *        customer. @see PersonalInfo.h
     * @return None
     */
    Group(char groupName[], int numPeople, bool isSpecialSeatingNeeded,
          char seatingInfo[], bool isPromoAllowed, PersonalInfo personalInfo);

    /**
     * Copy constructor.
     *
     * @param group The group to copy.
     */
    Group(const Group&);

    /**
     * Copy assignment operator.
     *
     * @param anotherOne The group to copy.
     * @return The copied group.
     */
    Group& operator=(const Group& anotherOne);

    /**
     * Destructor
     */
    ~Group();

    /**
     * Getter for groupName
     *
     * @return The name of the group.
     */
    const char* getGroupName() const;

    /**
     * Getter for numPeople
     *
     * @return The number of people in the group.
     */
    int getNumPeople() const;

    /**
     * Getter for isSpecialSeatingNeeded
     *
     * @return Whether anyone in the group needs special seating,
     *         such as a high chair or wheel chair.
     */
    bool getIsSpecialSeatingNeeded();

    /**
     * Getter for seatingInfo
     *
     * @return The special seating information.
     */
    const char* getSeatingInfo() const;

    /**
     * Getter for isPromoAllowed
     *
     * @return Whether he group would like to receive coupons and
     *         other promotional materials.
     */
    bool getIsPromoAllowed();

    /**
     * Getter for personalInfo
     *
     * @return The personal information of the customer.
     */
    const PersonalInfo getPersonalInfo() const;

    /**
     * This function prints the data of the group.
     *
     * @param os The output stream.
     * @return void
     */
    void printInformation(ostream& os);

  private:
    /**
     * Setter for groupName
     *
     * @param groupName The name of the group.
     * @return void
     */
    void setGroupName(const char groupName[]);

    /**
     * Setter for numPeople
     *
     * @param numPeople The number of people in the group.
     * @return void
     */
    void setNumPeople(int numPeople);

    /**
     * Setter for isSpecialSeatingNeeded
     *
     * @param isSpecialSeatingNeeded Whether anyone in the group needs
     *        special seating, such as a high chair or wheel chair.
     * @return void
     */
    void setIsSpecialSeatingNeeded(bool isSpecialSeatingNeeded);

    /**
     * Setter for seatingInfo
     *
     * @param seatingInfo The special seating information.
     * @return void
     */
    void setSeatingInfo(const char seatingInfo[]);

    /**
     * Setter for isPromoAllowed
     *
     * @param isPromoAllowed Whether he group would like to receive
     *        coupons and other promotional materials.
     * @return void
     */
    void setIsPromoAllowed(bool isPromoAllowed);

    /**
     * Setter for personalInfo
     *
     * @param personalInfo The personal information of the customer.
     * @return void
     */
    void setPersonalInfo(PersonalInfo& personalInfo);

    /**
     * This function initializes the group's information.
     *
     * @param groupName The name of the group.
     * @param numPeople The number of people in the group.
     * @param isSpecialSeatingNeeded Whether anyone in the group needs
     *        special seating, such as a high chair or wheel chair.
     * @param seatingInfo The special seating information.
     * @param isPromoAllowed Whether he group would like to receive
     *        coupons and other promotional materials.
     * @param personalInfo The personal information of the customer.
     * @return void
     */
    void init(char groupName[], int numPeople, bool isSpecialSeatingNeeded,
              char seatingInfo[], bool isPromoAllowed,
              PersonalInfo personalInfo);
};

#endif
