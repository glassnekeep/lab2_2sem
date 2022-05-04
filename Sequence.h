//
// Created by - on 27.04.2022.
//

#ifndef LAB2_2SEM_SEQUENCE_H
#define LAB2_2SEM_SEQUENCE_H


//#include "MyComplex.h"
//Темплейт класс какого-то типа T
using namespace std;

template <class T> class Sequence
{
private:

public:
    // Конструкторы
    Sequence() = default;
    // Декомпозиция
    virtual T getFirst() = 0;	// Возвращает первый элемент
    virtual T getLast() = 0;	// Возвращает последний элемент
    virtual T get(int index) = 0;	// Возвращает элемент по индексу
    //GetSubsequence возвращает указатель на подпоследовательность используя
    // индексы начала и конца подпоследовательности из  Sequence
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
    virtual int getLength() = 0;	// Возвращает длину последовательности
    virtual void set(int index, T data) = 0;	// Меняет значение i-го элемента
    virtual T& operator[](int index) = 0;

    // Операции
    virtual void Append(T item) = 0; // Добавляет элемент в конец списка
    virtual void Prepend(T item) = 0; // Добавляет элемент в начало списка
    virtual void InsertAt(T item, int index) = 0; // Вставляет элемент в заданную позицию
    virtual Sequence <T>* Concat(Sequence <T>* list) = 0; // Сцепляет два списка

    //map, reduce, zip, unzip, where
    void map(T mapFunc(T arg)) {
        for (int i = 0; i < getLength(); i++) {
            Set(i, mapFunc(get(i)));
        }
    }
    T reduce(T reduceFunc(T& arg1, T& arg2), T startVal) {
        T buf = startVal;
        for (int i = 0; i < getLength(); i++) {
            buf = reduceFunc(get(i), buf);
        }
        return buf;
    }
    // TODO: Много тестов SubSequenceSearch
    bool SubSequenceSearch(Sequence<T>* seq) {
        bool result = false;
        for (int i = 0; i < getLength() - seq -> getLength(); i++) {
            result = true;
            for (int j = 0; j < seq -> getLength(); j++) {
                result &= (get(i + j) == (seq -> get(j)));
            };
            if (result)break;
        }
        return result;
    }
};

template <class T>
std::ostream& operator<<(std::ostream& out, Sequence<T>* seq) {
    for (int i = 0; i < seq->Get_Length(); i++) { out << seq->Get(i) << " "; }
    return out;
}

#endif //LAB2_2SEM_SEQUENCE_H
