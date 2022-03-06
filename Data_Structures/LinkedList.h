//
// Created by Mai on 12/19/2021.
//

#ifndef POLLUTIONSIMULATOR_LINKEDLIST_H
#define POLLUTIONSIMULATOR_LINKEDLIST_H
#include <iostream>


using namespace std;
template<class T>
struct Node {
    T * data;
    Node<T>* next;
};
template<class T>
class LinkedList {
public:
    LinkedList();

    /* big three */
    LinkedList(const LinkedList& other);

    LinkedList& operator=(const LinkedList& rhs);

    ~LinkedList();

    /**
     * insert an element to the head of the list
     * @param elem
     */
    void insert(T data);

    /**
     * remove the first occurrence of elem in the list
     * @param elem
     */
    void remove(T data);

    /**
     * remove all elements from the list
     */
    void clear();

    /**
     * return how many elements are in the list
     */
    int size() const;

    /**
     * access an element at a given index
     * @param index
     * @return
     */
    T* operator[](int index);


    /**
     * return an element at a given index
     * @param index
     * @return
     */
    const T*& operator[](int index) const;

    friend ostream& operator<<(ostream& out, const LinkedList<T>& list){
        Node<T>* temp = list.head;
        while (temp) {
            if (temp != list.head) {
                out << ",";
            }
            out << *temp->data;
            temp = temp->next;
        }
        return out;}

private:
    Node<T>* head;
    int count;
};

template<class T>
ostream& operator<<(ostream& out, const LinkedList<T>& list);

#include "LinkedList_imp.h"

#endif //POLLUTIONSIMULATOR_LINKEDLIST_H
