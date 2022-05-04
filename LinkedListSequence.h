//
// Created by - on 27.04.2022.
//

#ifndef LAB2_2SEM_LINKEDLISTSEQUENCE_H
#define LAB2_2SEM_LINKEDLISTSEQUENCE_H


#include "Sequence.h"
#include "linkedList.h"
#include "Sequence.h"
#include "LinkedList.h"

#pragma once
#include "Sequence.h"
#include "LinkedList.h"

template <class T> class LinkedListSequence : public Sequence<T>
{
private:
    LinkedList<T>* list;
public:
    //Конструкторы
    LinkedListSequence();
    LinkedListSequence(int count);
    LinkedListSequence(T *items,int count);
    LinkedListSequence(const LinkedList<T> &previousList );

    //Операции
    int getLength() override;
    T getFirst() override;
    T getLast() override;
    T get(int index) override;
    Sequence<T>* getSubsequence(int fromIndex,int toIndex ) override;
    void insertAt(T item,int index) override;
    void append(T item) override;
    void prepand(T item) override;
    T& operator[](int index)override;
    Sequence <T> * concat(Sequence <T> * sequence)override;
};

template<class T>
LinkedListSequence<T>::LinkedListSequence() {
    list = new LinkedList<T>(0);
}

template<class T>
LinkedListSequence<T>::LinkedListSequence(int count) {
    list = new LinkedList<T>(count);
}

template<class T>
LinkedListSequence<T>::LinkedListSequence(T *items, int count) {
    list = new LinkedList<T>(items, count);
}

template<class T>
LinkedListSequence<T>::LinkedListSequence(const LinkedList<T> &previousList) {
    list = new LinkedList<T>(previousList);
}

template<class T>
int LinkedListSequence<T>::getLength() {
    return list -> getLength();
}

template<class T>
T LinkedListSequence<T>::getFirst() {
    if (list -> getLength() > 0) { return list -> get(0); }
}

template<class T>
T LinkedListSequence<T>::getLast() {
    if (list -> getLength() > 0) { return list -> get(list -> getLength()); }
}

template<class T>
T LinkedListSequence<T>::get(int index) {
    try {
        T result = list ->get(index);
    } catch (Exception& exception) {
        exception.show();
    }
}

template<class T>
Sequence<T> *LinkedListSequence<T>::getSubsequence(int fromIndex, int toIndex) {
    return new LinkedListSequence<T>(list ->getSubLinkedList(fromIndex, toIndex));
}

template<class T>
void LinkedListSequence<T>::insertAt(T item, int index) {
    try {
        list -> insertAt(index, item);
    } catch (Exception& exception) {
        throw exception;
        //exception.show();
    }
}

template<class T>
void LinkedListSequence<T>::append(T item) {
    try {
        insertAt(item, list -> getLength());
    } catch (Exception& exception) {
        //exception.show();
        throw exception;
    }
}

template<class T>
void LinkedListSequence<T>::prepand(T item) {
    try {
        insertAt(item, 0);
    } catch (Exception& exception) {
        exception.show();
    }
}

template<class T>
T &LinkedListSequence<T>::operator[](int index) {
    if (index < 0 || index > list -> getLength()){
        Exception(1).show();
    } else {
        return (*list)[index];
    }
}

template<class T>
Sequence<T> *LinkedListSequence<T>::concat(Sequence<T> *sequence) {
    if (sequence == NULL) {
        throw Exception(2);
    } else {
        try {
            auto *resultList = new LinkedListSequence<T>;
            *(resultList->list) = *(list);
            for (int i = 0; i < sequence->getLength(); i++) {
                resultList->append(sequence->get(i));
            }
            return resultList;
        } catch (Exception& exception) {
            throw exception;
        }
    }
}

template<typename T>
ostream & operator << (ostream& out, LinkedListSequence<T> linkedListSequence)
{
    for (int i = 0; i < linkedListSequence.getLength(); ++i) {
        out << linkedListSequence.get(i) << " ";
    }
    return out;
}

#endif //LAB2_2SEM_LINKEDLISTSEQUENCE_H
