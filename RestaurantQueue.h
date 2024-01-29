#ifndef RESTAURANT_QUEUE_H
#define RESTAURANT_QUEUE_H

#include "Group.h"
#include "Stack.h"

/**
 * This class represents a waiting list for a restaurant. It is a queue and
 * uses a circular linked list.
 */
class RestaurantQueue {
  private:
    /**
     * A node in the queue. It contains a group and a pointer to the next
     * node.
     */
    struct Node {
        Group data;
        Node* next = nullptr;
    };

    /**
     * The rear of the queue. The rear is the last node in the queue.
     */
    Node* rear;

    /**
     * The number of groups in the queue.
     */
    int size;

  public:
    /**
     * Default constructor
     */
    RestaurantQueue();

    /**
     * Destructor
     */
    ~RestaurantQueue();

    /**
     * Adds a group to the waiting list.
     *
     * @param group The group to add.
     * @return void
     */
    void enqueue(const Group& group);

    /**
     * Removes the front group from the waiting list.
     *
     * @return void
     */
    void dequeue();

    /**
     * Views the front group without removing it.
     *
     * @param[out] aGroup The group variable to copy the front group to.
     * @return     Whether the front group exists.
     */
    bool peek(Group& aGroup) const;

    /**
     * Displays the waiting list along with the number in line.
     *
     * @return void
     */
    void display() const;

    /**
     * Loads group data from a file into the queue. If there are any groups
     * would like to receive coupons and other promotional materials, they are
     * added to the stack.
     *
     * @param      fileName The name of the file to load data from.
     * @param[out] stack The stack to add groups that would like to receive
     *             coupons and other promotional materials.
     * @return     The number of groups loaded, returns ERROR in case the data
     *             can not be loaded.
     */
    int loadData(const char fileName[], const Stack& stack);

    /**
     * Writes group data from the queue to a file.
     *
     * @param      fileName The name of the file to write data to.
     * @return     Whether the data is written successfully.
     */
    bool writeData(const char fileName[]);

    // private:
    //   /**
    //    * Displays the list of groups.
    //    *
    //    * @param node The node to start displaying from.
    //    * @return void
    //    */
    //   void displayList(Node* node);
};

#endif
