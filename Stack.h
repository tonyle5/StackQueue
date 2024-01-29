#ifndef CUSTOMERSTACK_H
#define CUSTOMERSTACK_H

#include "PersonalInfo.h"

/**
 * This class represents a stack of customers who are interested in receiving
 * coupons and other promotional materials.
 */
class Stack {
  private:
    /**
     * A dynamic array contains customers' information.
     */
    PersonalInfo** aStack;

    /**
     * The current capacity of the stack.
     */
    int curCapacity;

    /**
     * The number of customers in the stack.
     */
    int top;

  public:
    /**
     * Default constructor
     */
    Stack(int capacity = INIT_CAP);

    /**
     * Copy constructor.
     *
     * @param aStack The stack to copy.
     */
    Stack(const Stack& aStack);

    /**
     * Destructor
     */
    ~Stack();

    /**
     * Assignment operator.
     *
     * @param aStack The stack to copy.
     * @return The copied stack.
     */
    const Stack& operator=(const Stack& aStack);

    /**
     * Overloads the << operator to display Stack.
     *
     * @param[in, out] out The output stream.
     * @param          aStack The stack to display.
     * @return         The output stream.
     */
    friend ostream& operator<<(ostream& out, const Stack& aStack);

    /**
     * Adds a customer to the stack.
     *
     * @param personalInfo The customer to add.
     * @return void
     */
    void push(const PersonalInfo& personalInfo);

    /**
     * Removes the top customer from the stack.
     *
     * @param[out] personalInfo The customer variable to copy the top customer
     *             after removing them.
     */
    bool pop(PersonalInfo& personalInfo);

    /**
     * Views the top customer without removing them.
     *
     * @param[out] personalInfo The customer variable to copy the top customer
     *             to.
     * @return     Whether the top customer exists.
     */
    bool peek(PersonalInfo& personalInfo);

    /**
     * Get the number of customers in the stack.
     *
     * @return The number of customers in the stack.
     */
    int getSize() const;

    /**
     * Checks if the stack is empty.
     *
     * @return Whether the stack is empty.
     */
    bool isEmpty() const;

    /**
     * Loads customer data from a file into the stack.
     *
     * @param fileName The name of the file to load data from.
     * @return The number of customers loaded, returns ERROR in case the data
     *         can not be loaded.
     */
    int loadData(const char* fileName);

    /**
     * Writes customer data from the stack to a file.
     *
     * @param fileName The name of the file to write data to.
     * @return Whether the data is written successfully.
     */
    bool writeData(const char* fileName) const;

  private:
    /**
     * Destroys the stack.
     *
     * @return void
     */
    void destroy();

    /**
     * Expands the stack when it reaches its capacity.
     *
     * @return void
     */
    void expand();
};

#endif
