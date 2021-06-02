cmake_minimum_required(VERSION 3.19)
project(libscds C)

set(CMAKE_C_STANDARD 11)

include_directories(lib)

add_executable(libscds
        BinarySearchTree.h
        DoublyLinkedList.h
        example/examples.c
        Heap.h
        Queue.h
        SinglyLinkedList.h
        Stack.h
        lib/vector.h
        example/int_vector.h)
