#ifndef RESTAURANT_QUEUE_H
#define RESTAURANT_QUEUE_H

#include "Group.h"
#include "Stack.h"

class RestaurantQueue {
  private:
    struct Node {
        Group data;
        Node* next = nullptr;
    };
    Node* rear;
    int size;

  public:
    RestaurantQueue();

    ~RestaurantQueue();

    // Function to add a group to the waiting list (enqueue)
    void enqueue(const Group& group);

    // Function to remove the front group from the waiting list (dequeue)
    void dequeue();

    // Function to view the front group without removing it
    bool peek(Group& aGroup) const;

    // Function to display the waiting list along with the number in line
    void display() const;

    int loadData(const char fileName[], Stack& stack);

    bool writeData(const char fileName[]);

  private:
    void displayList(Node* node);
};

#endif
