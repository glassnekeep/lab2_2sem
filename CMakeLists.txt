cmake_minimum_required(VERSION 3.20)
project(lab2_2sem)

set(CMAKE_CXX_STANDARD 20)

#add_executable(lab2_2sem main.cpp DynamicArray.h ArraySequence.h LinkedListSequence.h Sequence.h Exception.h LinkedList.h)

add_executable(lab2_2sem tests.cpp ArraySequenceTest.h DynamicArrayTest.h LinkedListSequenceTest.h LinkedListTest.h ArraySequenceTest.cpp DynamicArrayTest.cpp LinkedListSequenceTest.cpp Exception.h)