//
// Created by - on 27.04.2022.
//

#ifndef LAB2_2SEM_ARRAYSEQUENCE_H
#define LAB2_2SEM_ARRAYSEQUENCE_H


#include "Sequence.h"
#include "DynamicArray.h"
#include "Exception.h"

template <class T> class ArraySequence : public Sequence<T>
{
private:
    DynamicArray<T>* items;
public:
    // Конструкторы:
    ArraySequence() {
        items = new DynamicArray<T>(0);
    } // Создать пустой список
    ArraySequence(T* arr, int count) {
        items = new DynamicArray<T>(0);
        items->Resize(count);
        for (int i = 0; i < count; i++)
        {
            items->Set(i, arr[i]);
        }
    } // Копировать элементы из переданного массива
    ArraySequence(ArraySequence <T>& list) {
        items = new DynamicArray<T>(0);
        items->Resize(list.GetLength());
        for (int i = 0; i < (list.GetLength()); i++)
        {
            items->Set(i, list.Get(i));
        }
    }// Создать на основе другого - Копирующий конструктор

    T& operator[](int index) {
        if (index>GetLength()-1 || index<0)
            throw Exception(1);
        return items[index];
    }
    //Операции из Sequence
    T GetFirst() {
        return this->Get(0);
    }
    T GetLast() {
        return this->Get(items->GetSize()-1);
    }
    T Get(int index) {
        return items->Get(index);
    }
    ArraySequence<T>* GetSubsequence(int startIndex, int endIndex) {
        auto* buf = new ArraySequence<T>;
        int dif = endIndex - startIndex+1;
        buf->Resize(dif);
        for (int i = 0; i< dif;i++)
        {
            buf->Set(i, this->Get(startIndex+i));
        }
        return buf;
    }
    int GetLength() {
        return items->GetSize();
    }
    void Set(int index, T value) {// Задать элемент по индексу. Может выбросить IndexOutOfRange
        items->Set(index, value);
    }

    // Добавляет элемент в конец списка
    // TODO: Сделать реализацию без resize в Append, Prepend, InsertAt
    void Append(T item) {
        items->Resize(items->GetSize() + 1);
        items->Set(items->GetSize()-1, item);
    }
    // Добавляет элемент в начало списка

    // TODO: Подумать над балансировкой массива.
    void Prepend(T item) {
        items->ResizeRight(items->GetSize() + 1);
        items->Set(0, item);
    }
    // Вставляет элемент в заданную позицию
    void InsertAt(T item, int index) {
        int newLength = this->GetLength() + 1;
        this->Resize(newLength);
        T buf;
        int dif = newLength - index -1 ;
        for (int i = 0; i < dif; i++) {
            buf = this->Get(newLength - i - 2);
            this->Set(newLength - i - 1, buf);
        }
        this->Set(index + 1, item);
    }
    Sequence <T>* Concat(Sequence <T>* list) {
        Sequence <T>* buf = NULL;
        int oldLenght = this->GetLength();
        this->Resize(this->GetLength() + ((ArraySequence <T>*)list)->GetLength());
        for (int i = 0 ;i < ((ArraySequence <T>*)list)->GetLength(); i++)
            this->Set(i + oldLenght,((ArraySequence <T>*)list)->Get(i));
        return (Sequence <T>*)buf;
    }
    void Resize(int newSize) {
        items->Resize(newSize);
    }
    void ResizeRight(int newSize) {
        items->ResizeRight(newSize);
    }
};

#endif //LAB2_2SEM_ARRAYSEQUENCE_H