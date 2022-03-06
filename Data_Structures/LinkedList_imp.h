#ifndef POLLUTIONSIMULATOR_LINKEDLIST_IMP_H
#define POLLUTIONSIMULATOR_LINKEDLIST_IMP_H
#include "LinkedList.h"
#include <cstdlib>

// c'tor
template<class T>
LinkedList<T>::LinkedList() : head(NULL), count(0) {}
// default c'tor
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) : head(NULL), count(0) {
    Node<T>* temp = other.head;
    while (temp) {
        insert(temp->data);
        temp = temp->next;
    }
}

// d'tor
template<class T>
LinkedList<T>::~LinkedList() {
    clear();
}

// operator =
template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& rhs) {
    if (this != &rhs) {
        clear();
        Node<T>* temp = rhs.head;
        while (temp) {
            insert(temp->data);
            temp = temp->next;
        }
    }
    return *this;
}
// operator []
template<class T>
T* LinkedList<T>::operator[](int index) {
    if (index < 0 || index > count) {
        cerr << "whoa there buddy!" << endl;
        exit(1);
    }
    Node<T>* temp = head;
    for (int i = 1; i < index; i++) {
        temp = temp->next;
    }
    return temp->data;
}
// operator [] const
template<class T>
const T*& LinkedList<T>::operator[](int index) const {
    if (index < 0 || index >= count) {
        cerr << "whoa there buddy" << endl;
        exit(1);
    }
    Node<T>* temp = head;
    for (int i = 1; i < index; i++) {
        temp = temp->next;
    }
    return temp->data;
}

// operator <<
// class methods
template<class T>
void LinkedList<T>::insert(T data)
{
    if(!head) { // the list is empty
        head = new Node<T>;
        head->data = new T(data); // assuming T copy c'tor well-definedS
        head->next = NULL;
        count++;
        return;
    }

    Node<T>* temp = head;
    while(temp->next )
    {
            temp = temp->next;
    }
    temp->next = new Node<T>;
    temp->next->data = new T(data);
    temp->next->next = NULL;
    count++;
}

template<class T>
void LinkedList<T>::clear() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete[] temp;
    }
    count = 0;
    head = NULL;
}

template<class T>
void LinkedList<T>::remove(T elem) {
    if (!head) { return; }
    Node<T>* temp = head;
    if (temp->data == elem) {
        head = head->next;
        delete temp;
        count--;
        return;
    }
    while (temp->next && temp->next->data != elem) {
        temp = temp->next;
    }
    if (temp->next) {
        Node<T>* victim = temp->next;
        temp->next = victim->next;
        delete victim;
        count--;
    }
}

template<class T>
int LinkedList<T>::size() const {
    return count;
}
#endif //POLLUTIONSIMULATOR_LINKEDLIST_IMP_H
