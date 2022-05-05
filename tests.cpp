//
// Created by - on 05.05.2022.
//

#include "ArraySequenceTest.h"
#include "LinkedListSequenceTest.h"
#include "DynamicArrayTest.h"
#include "LinkedListTest.h"
#include "Exception.h"
using namespace std;

int main() {
    arraySequenceTests();
    cout << endl;
    dynamicArrayTest();
    cout << endl;
    linkedListTest();
    cout << endl;
    listSequenceTest();
}