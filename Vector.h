/*libscds by Maxim Atanasoff
Free for everyone to use, modify and distrubite
*/

#include <stdio.h>
#include <stdlib.h>

#define DECLARE_VECTOR(TYPE)\
    typedef struct Vector_##TYPE\
    {                           \
        unsigned int position;  \
        size_t size;       \
        TYPE* vectorArr;    \
    } Vector_##TYPE;             \
                                \
    Vector_##TYPE* new_Vector_##TYPE(Vector_##TYPE* this){\
        this = malloc(sizeof(Vector_##TYPE));\
        this->position = 0;\
        this->size = 20;\
        this->vectorArr = malloc((this->size)*sizeof(TYPE));\
        return this;\
    }\
\
    void vectorPushBack_##TYPE(Vector_##TYPE* this, TYPE k){\
        if(this->position > this->size - 1){\
            this->vectorArr = realloc(this->vectorArr, ((this->size + this->size/2)*sizeof( TYPE )));\
            this->size += this->size/2;\
        } \
        this->vectorArr[this->position++] = k; \
    }\
    \
    int vectorIsEmpty_##TYPE(Vector_##TYPE* this)\
    {\
        if(this->position == 0)\
            return 1;\
        else \
            return 0;\
    }\
    TYPE* vectorPopBack_##TYPE(Vector_##TYPE *this)\
    {\
        if(!vectorIsEmpty_##TYPE(this)){\
            TYPE* data = &this->vectorArr[--this->position];\
            return data;\
        }\
        else\
            return NULL;\
    }\
    \
    TYPE* vectorAt_##TYPE(Vector_##TYPE *this, size_t index)\
    {\
        if(!vectorIsEmpty_##TYPE(this) && index <= this->position-1){\
            TYPE* data = &this->vectorArr[index];\
            return data;\
        }\
        else\
            return NULL;\
    }\
    void destroy_Vector_##TYPE(Vector_##TYPE* this){\
        free(this->vectorArr);\
        free(this);\
    }\
\
//
