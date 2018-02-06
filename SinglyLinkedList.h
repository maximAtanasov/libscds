/*libscds by Maxim Atanasoff
Free for everyone to use, modify and distrubite
*/

#include <stdio.h>
#include <stdlib.h>

#define DECLARE_SINGLYLINKEDLISTELEMENT(TYPE)\
\
    \
    typedef struct SinglyLinkedListElement_##TYPE SinglyLinkedListElement_##TYPE;\
    struct SinglyLinkedListElement_##TYPE{\
        TYPE *content;\
        SinglyLinkedListElement_##TYPE *next;\
    };\
    \
    SinglyLinkedListElement_##TYPE* new_SinglyLinkedListElement_##TYPE(SinglyLinkedListElement_##TYPE* this, TYPE* t){\
        this = malloc( sizeof( SinglyLinkedListElement_##TYPE) );\
        this->content = malloc(sizeof(TYPE));\
        *this->content = *t;\
        this->next = NULL;\
        return this;\
    }\
    \
\

#define DECLARE_SINGLYLINKEDLIST(TYPE)    \
\
    DECLARE_SINGLYLINKEDLISTELEMENT(TYPE)            \
    \
    typedef struct SinglyLinkedList_##TYPE SinglyLinkedList_##TYPE; \
    struct SinglyLinkedList_##TYPE              \
    {                                           \
        SinglyLinkedListElement_##TYPE *first;   \
        SinglyLinkedListElement_##TYPE *last;      \
        size_t size;          \
    };                                  \
                                        \
    SinglyLinkedList_##TYPE* new_SinglyLinkedList_##TYPE (SinglyLinkedList_##TYPE *this)\
    {     \
        this = malloc(sizeof(SinglyLinkedList_##TYPE));\
        this->first = NULL;         \
        this->last = NULL;          \
        this->size = 0;             \
        return this;                \
    }                               \
    int SinglyLinkedListIsEmpty_##TYPE (SinglyLinkedList_##TYPE *this)\
    {\
        if(this->first == NULL && this->last == NULL)\
            return 1;\
        else\
            return 0;\
    }\
    \
    void addToSinglyLinkedList_##TYPE (SinglyLinkedList_##TYPE *this, TYPE t){\
        if(SinglyLinkedListIsEmpty_##TYPE (this)){\
            this->first = new_SinglyLinkedListElement_##TYPE(this->first, &t);\
            this->last = this->first;\
            this->size++;\
        }                                                 \
        else{                                           \
            this->last->next = new_SinglyLinkedListElement_##TYPE(this->last->next, &t);\
            this->last = this->last->next;\
            this->size++;\
        }\
    }\
    void destroy_SinglyLinkedList_##TYPE(SinglyLinkedList_##TYPE *this){\
        SinglyLinkedListElement_##TYPE* current = this->first;\
        while(current != NULL){\
            this->first = this->first->next;\
            free(current->content);\
            free(current);\
            current = this->first;\
        }\
        free(this);\
    }\
    \
\

