#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Stack.h"
#include "BinarySearchTree.h"
#include "DoublyLinkedList.h"
#include "SinglyLinkedList.h"
#include "Queue.h"
#include "Heap.h"
#include "Vector.h"


int compare_int(int* a, int* b){
    if(*a == *b){
		return 0;
	}else if(*a < *b){
		return -1;
	}else if(*a > *b){
		return 1;
	}
}

int compare_float(float* a, float* b){
    if(*a == *b){
		return 0;
	}else if(*a < *b){
		return -1;
	}else if(*a > *b){
		return 1;
	}
}

//Declare datastructures for types you need
DECLARE_BINARYSEARCHTREE(int)
DECLARE_BINARYSEARCHTREE(float)
DECLARE_STACK(float)
DECLARE_STACK(char)
DECLARE_SINGLYLINKEDLIST(char)
DECLARE_DOUBLYLINKEDLIST(double)
DECLARE_QUEUE(char)
DECLARE_HEAPMIN(int)
DECLARE_HEAPMAX(int)
DECLARE_VECTOR(int)

/*NOTE: declaring the containers within a function will only work under gcc on linux, as that is a gnu extension.
	If you want portability, declare your containers once in a header/source file in global scope*/


int main(void){
    int i;

	//Vector example
	Vector_int* vector1 = new_Vector_int(vector1);
	vectorPushBack_int(vector1, 2);
	vectorPushBack_int(vector1, 3);
	vectorPushBack_int(vector1, 4);
	int vec_int = *vectorAt_int(vector1, 2);
	destroy_Vector_int(vector1);

	//BinarySearchTree example
    BinarySearchTree_int* tree1 = new_BinarySearchTree_int(tree1);
    int a = 6;
    int b = 3;
    int c = 1;
    int d = 9;
    addToTree_int(tree1, a);
    addToTree_int(tree1, b);
    addToTree_int(tree1, c);
    addToTree_int(tree1, d);
    destroy_BinarySearchTree_int(tree1);

	//Second tree example
    BinarySearchTree_float* tree2 = new_BinarySearchTree_float(tree2);
    {
    float aa = 4.5;
    float bb = 1.5;
    float cc = 9.9;
    float dd = 12;
    float ee = 15.5;
    addToTree_float(tree2, aa);
    addToTree_float(tree2, bb);
    addToTree_float(tree2, cc);
    addToTree_float(tree2, dd);
    addToTree_float(tree2, ee);
    }
    destroy_BinarySearchTree_float(tree2);

	//Third Tree example
    srand(time(NULL));
    int rand_array[150];
    for(i = 0; i < sizeof(rand_array)/sizeof(int); i++){
    	rand_array[i] = rand();
	}

    BinarySearchTree_int* tree3 = new_BinarySearchTree_int(tree3);
    int temp[sizeof(rand_array)/sizeof(int)];
    for(i = 0; i < sizeof(rand_array)/sizeof(int); i++){
        temp[i] = rand_array[i];
        addToTree_int(tree3, temp[i]);
    }
    destroy_BinarySearchTree_int(tree3);

	//Stack example

	Stack_float* stack0 = new_Stack_float(stack0);
    float floatArray[100];
    for(i = 0; i < 100; i++){
        floatArray[i] = i;
        stackPush_float(stack0, floatArray[i]);
    }
    destroy_Stack_float(stack0);

    char ch = 'g';
    Stack_char* stack1 = new_Stack_char(stack1);
    stackPush_char(stack1, ch);
    destroy_Stack_char(stack1);


	//Doubly Linked List example
    DoublyLinkedList_double* list0 = new_DoublyLinkedList_double(list0);
    {
    double test = 1.5;
    double test2 = 3.5;
    addToDoublyLinkedList_double(list0, test);
    addToDoublyLinkedList_double(list0, test2);
    }
    destroy_DoublyLinkedList_double(list0);


	//Queue example
    char test1 = 'g';
    char test2 = 'a';
    Queue_char* queue1 = new_Queue_char(queue1);
    enqueue_char(queue1, test1);
    enqueue_char(queue1, test2);
    for(i = 0; i < 10000; i++){
	char a = 'i';
        enqueue_char(queue1, a);
    }

    for(i = 0; i < 10000; i++){
       dequeue_char(queue1);
    }
    destroy_Queue_char(queue1);


	//Create a min heap and fill it with values
    int oo = 7;
    int aaa = 2;
    int bbb = 5;
    int ccc = 11;
    int ddd = 8;
    HeapMin_int *heap1 = new_HeapMin_int(heap1);

    addToHeapMin_int(heap1, a);
    addToHeapMin_int(heap1, b);
    addToHeapMin_int(heap1, c);
    addToHeapMin_int(heap1, oo);
    addToHeapMin_int(heap1, aaa);
    addToHeapMin_int(heap1, bbb);
    addToHeapMin_int(heap1, ccc);
    addToHeapMin_int(heap1, ddd);

    int* int1 = removeFromHeapMin_int(heap1);

    destroy_HeapMin_int(heap1);

	//Create a max heap and fill it with values
    HeapMax_int *heap2 = new_HeapMax_int(heap2);

    addToHeapMax_int(heap2, a);
    addToHeapMax_int(heap2, b);
    addToHeapMax_int(heap2, c);
    addToHeapMax_int(heap2, oo);
    addToHeapMax_int(heap2, aaa);
    addToHeapMax_int(heap2, bbb);
    addToHeapMax_int(heap2, ccc);
    addToHeapMax_int(heap2, ddd);
    destroy_HeapMax_int(heap2);
    return 0;
}
