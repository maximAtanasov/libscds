/*libscds by Maxim Atanasoff
Free for everyone to use, modify and distrubite
*/

#include <stdio.h>
#include <stdlib.h>

#define DECLARE_HEAPMIN(TYPE)\
\
    typedef struct HeapMin_##TYPE HeapMin_##TYPE;\
    struct HeapMin_##TYPE\
    {\
        int position;\
        size_t size;\
        TYPE* heapArr;\
    };\
\
    HeapMin_##TYPE* new_HeapMin_##TYPE (HeapMin_##TYPE *this)\
    {\
        this = malloc( sizeof( HeapMin_##TYPE) );\
        this->size = 20;\
        this->position = 1;\
        this->heapArr = malloc((this->size)*sizeof(TYPE));\
        return this;\
    }\
    void addToHeapMin_##TYPE (HeapMin_##TYPE *this, TYPE t){\
        if(this->position + 1 >= this->size){\
            this->heapArr = realloc(this->heapArr, ((this->size + this->size/2)*sizeof( TYPE )));\
            this->size += this->size/2;\
        }\
        this->heapArr[this->position] = t;\
        int temp = this->position;\
        if(this->position == 1){\
            this->position++;\
            return;\
        }else{\
            int temp = this->position;\
            while(compare_##TYPE(&this->heapArr[temp], &this->heapArr[temp/2]) == -1){\
                TYPE temp1 = this->heapArr[temp/2];\
                this->heapArr[temp/2] = this->heapArr[temp];\
                this->heapArr[temp] = temp1;\
                temp = temp/2;\
                if(temp <= 1)\
                    break;\
            }\
        }\
        this->position++;\
    }\
\
    void heapifyDown_HeapMin_##TYPE(HeapMin_##TYPE *this, int start){\
        int finish = this->position-1;\
        int index, lchild, rchild;\
        TYPE max, temp;\
        lchild = 2*start;\
        rchild = lchild + 1;\
        if(lchild<=finish){\
            max = this->heapArr[lchild];\
            index = lchild;\
            if(rchild<=finish)\
                if(compare_##TYPE(&this->heapArr[rchild], &max) == -1){\
                    max = this->heapArr[rchild];\
                    index = rchild;\
                }\
            if(compare_##TYPE(&this->heapArr[start], &this->heapArr[index]) == 1)\
            {\
            temp = this->heapArr[start];\
                this->heapArr[start] = this->heapArr[index];\
                this->heapArr[index] = temp;\
                heapifyDown_HeapMin_##TYPE(this, index);\
            }\
        }\
    }\
    TYPE* removeFromHeapMin_##TYPE(HeapMin_##TYPE *this){\
        TYPE Element = this->heapArr[1];\
        TYPE* pElement = &Element;\
        this->heapArr[1] = this->heapArr[this->position - 1];\
        int i = 1;\
        this->position--;\
        heapifyDown_HeapMin_##TYPE(this, 1);\
        return pElement;\
    }\
    void destroy_HeapMin_##TYPE(HeapMin_##TYPE *this){\
        if(this != NULL){\
            free(this->heapArr);\
            free(this);\
        }\
    }\
\

#define DECLARE_HEAPMAX(TYPE)\
\
    typedef struct HeapMax_##TYPE HeapMax_##TYPE;\
    struct HeapMax_##TYPE\
    {\
        int position;\
        size_t size;\
        TYPE* heapArr;\
    };\
\
    HeapMax_##TYPE* new_HeapMax_##TYPE (HeapMax_##TYPE *this)\
    {\
        this = malloc( sizeof( HeapMax_##TYPE) );\
        this->size = 20;\
        this->position = 1;\
        this->heapArr = malloc((this->size)*sizeof(TYPE));\
        return this;\
    }\
    void addToHeapMax_##TYPE (HeapMax_##TYPE *this, TYPE t){\
        if(this->position + 1 >= this->size){\
            this->heapArr = realloc(this->heapArr, ((this->size + this->size/2)*sizeof( TYPE )));\
            this->size += this->size/2;\
        }\
        this->heapArr[this->position] = t;\
        int temp = this->position;\
        if(this->position == 1){\
            this->position++;\
            return;\
        }else{\
            int temp = this->position;\
            while(compare_##TYPE(&this->heapArr[temp], &this->heapArr[temp/2]) == 1){\
                TYPE temp1 = this->heapArr[temp/2];\
                this->heapArr[temp/2] = this->heapArr[temp];\
                this->heapArr[temp] = temp1;\
                temp = temp/2;\
                if(temp <= 1)\
                    break;\
            }\
        }\
        this->position++;\
    }\
\
    void heapifyDown_HeapMax_##TYPE(HeapMax_##TYPE *this, int start){\
        int finish = this->position-1;\
        int index, lchild, rchild;\
        TYPE max, temp;\
        lchild = 2*start;\
        rchild = lchild + 1;\
        if(lchild<=finish){\
            max = this->heapArr[lchild];\
            index = lchild;\
            if(rchild<=finish)\
                if(compare_##TYPE(&this->heapArr[rchild], &max) == 1){\
                    max = this->heapArr[rchild];\
                    index = rchild;\
                }\
            if(compare_##TYPE(&this->heapArr[start], &this->heapArr[index]) == -1)\
            {\
            temp = this->heapArr[start];\
                this->heapArr[start] = this->heapArr[index];\
                this->heapArr[index] = temp;\
                heapifyDown_HeapMax_##TYPE(this, index);\
            }\
        }\
    }\
    TYPE* removeFromHeapMax_##TYPE(HeapMax_##TYPE *this){\
        TYPE Element = this->heapArr[1];\
        TYPE* pElement = &Element;\
        this->heapArr[1] = this->heapArr[this->position - 1];\
        int i = 1;\
        this->position--;\
        heapifyDown_HeapMax_##TYPE(this, 1);\
        return pElement;\
    }\
    void destroy_HeapMax_##TYPE(HeapMax_##TYPE *this){\
        if(this != NULL){\
            free(this->heapArr);\
            free(this);\
        }\
    }\
\




