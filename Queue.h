/*libscds by Maxim Atanasoff
Free for everyone to use, modify and distrubite
*/

#include <stdio.h>
#include <stdlib.h>

#define DECLARE_QUEUE(TYPE)\
    typedef struct Queue_##TYPE\
    {\
	unsigned int position, firstPos;\
        TYPE* first, *last;  \
        size_t size;       \
        TYPE* queueArr;    \
    } Queue_##TYPE;             \
                                \
    Queue_##TYPE* new_Queue_##TYPE(Queue_##TYPE* this){\
        this = malloc(sizeof(Queue_##TYPE));\
        this->first = this->queueArr;\
	this->last = this->first;\
        this->size = 20;\
        this->queueArr = malloc((this->size)*sizeof(TYPE));\
	this->position = 0;\
	this->firstPos = 0;\
        return this;\
    }\
\
    void enqueue_##TYPE(Queue_##TYPE* this, TYPE k){\
        if(this->position > this->size - 1){\
            if(this->firstPos > 0){\
                int i;\
                for(i = 0; i > this->position-this->firstPos; i++){\
                    this->queueArr[i] = this->queueArr[i+this->firstPos]; \
                }\
                this->position -= this->firstPos;\
                this->firstPos = 0;\
            }\
            else{\
                this->queueArr = realloc(this->queueArr, ((this->size + this->size/2)*sizeof( TYPE )));\
                this->size += this->size/2;\
            }\
        } \
        this->queueArr[this->position++] = k; \
	this->last = &this->queueArr[this->position];\
    }\
    \
    int queueIsEmpty_##TYPE(Queue_##TYPE* this)\
    {\
        if(this->position == 0)\
            return 1;\
        else \
            return 0;\
    }\
    TYPE* dequeue_##TYPE(Queue_##TYPE *this)\
    {\
        if(!queueIsEmpty_##TYPE(this)){\
            TYPE* data = this->first;\
	        this->first = NULL;\
	        this->first = &this->queueArr[++this->firstPos];\
            return data;\
        }\
        else\
            return NULL;\
    }\
    \
    TYPE* queuePeek_##TYPE(Queue_##TYPE *this)\
    {\
        if(!queueIsEmpty_##TYPE(this)){\
            TYPE* data = &this->queueArr[this->firstPos];\
            return data;\
        }\
        else\
            return NULL;\
    }\
\
    void destroy_Queue_##TYPE(Queue_##TYPE* this){\
        free(this->queueArr);\
        free(this);\
    }\
\

