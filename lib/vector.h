/*libscds by Maxim Atanasoff
Free for everyone to use, modify and distrubite
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DECLARE_VECTOR(TYPE)\
\
    typedef struct TYPE##_vector\
    {\
        int position;\
        size_t size;\
        TYPE* vector_arr;\
    } TYPE##_vector;\
\
    TYPE##_vector* make_##TYPE##_vector(){\
        TYPE##_vector* this = malloc(sizeof(TYPE##_vector));\
        this->position = 0;\
        this->size = 10;\
        this->vector_arr = malloc((this->size)*sizeof(TYPE));\
        return this;\
    }\
    TYPE##_vector* make_##TYPE##_vector_size(int size){\
        if(size <= 0) {\
            return NULL;\
        }\
        TYPE##_vector* this = malloc(sizeof(TYPE##_vector));\
        this->position = 0;\
        this->size = size;\
        this->vector_arr = malloc((this->size)*sizeof(TYPE));\
        return this;\
    }\
\
    void TYPE##_vector_push(TYPE##_vector* this, TYPE k){\
        if(this->position > this->size - 1){\
            this->size = ceil(this->size*1.5);\
            this->vector_arr = realloc(this->vector_arr, ((this->size)*sizeof( TYPE )));\
        }\
        this->vector_arr[this->position++] = k;\
    }\
\
    int TYPE##_vector_empty(TYPE##_vector* this){\
        return this->position == 0;\
    }\
    TYPE* TYPE##_vector_pop_back(TYPE##_vector *this){\
        if(!TYPE##_vector_empty(this)){\
            TYPE* data = &this->vector_arr[--this->position];\
            return data;\
        }\
        else\
            return NULL;\
    }\
\
    TYPE* TYPE##_vector_at(TYPE##_vector *this, size_t index){\
        if(!TYPE##_vector_empty(this) && index <= this->position-1){\
            TYPE* data = &this->vector_arr[index];\
            return data;\
        }\
        else\
            return NULL;\
    }\
\
    void free_##TYPE##_vector(TYPE##_vector* this){\
        free(this->vector_arr);\
        free(this);\
    }\
\
    void TYPE##_vector_shrink(TYPE##_vector* this){\
        if(this->position != this->size) {\
            this->size = this->position;\
            this->vector_arr = realloc(this->vector_arr, ((this->size)*sizeof( TYPE )));\
        }\
    }\
\
    int TYPE##_vector_size(TYPE##_vector* this){\
        return this->position;\
    }\
//
