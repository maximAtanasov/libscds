/*libscds by Maxim Atanasoff
Free for everyone to use, modify and distrubite
*/

#include <stdio.h>
#include <stdlib.h>

#define DECLARE_DOUBLYLINKEDLISTELEMENT(TYPE)\
\
    \
    typedef struct DoublyLinkedListElement_##TYPE DoublyLinkedListElement_##TYPE;\
    struct DoublyLinkedListElement_##TYPE{\
        TYPE *content;\
        DoublyLinkedListElement_##TYPE *prev;\
        DoublyLinkedListElement_##TYPE *next;\
    };\
    \
    DoublyLinkedListElement_##TYPE* new_DoublyLinkedListElement_##TYPE(DoublyLinkedListElement_##TYPE* this, TYPE* t){\
        this = malloc( sizeof( DoublyLinkedListElement_##TYPE) );\
        this->content = malloc(sizeof(TYPE));\
        *this->content = *t;\
        this->prev = NULL;\
        this->next = NULL;\
        return this;\
    }\
    \
\

\
#define DECLARE_DOUBLYLINKEDLIST(TYPE)    \
\
    DECLARE_DOUBLYLINKEDLISTELEMENT(TYPE)            \
    \
    typedef struct DoublyLinkedList_##TYPE DoublyLinkedList_##TYPE; \
    struct DoublyLinkedList_##TYPE              \
    {                                           \
        DoublyLinkedListElement_##TYPE *first;   \
        DoublyLinkedListElement_##TYPE *last;      \
        size_t size;          \
    };                                  \
                                        \
    DoublyLinkedList_##TYPE* new_DoublyLinkedList_##TYPE (DoublyLinkedList_##TYPE *this)\
    {     \
        this = malloc(sizeof(DoublyLinkedList_##TYPE));\
        this->first = NULL;         \
        this->last = NULL;          \
        this->size = 0;             \
        return this;                \
    }                               \
    int DoublyLinkedListIsEmpty_##TYPE (DoublyLinkedList_##TYPE *this)\
    {\
        if(this->first == NULL && this->last == NULL)\
            return 1;\
        else\
            return 0;\
    }\
    \
    void addToDoublyLinkedList_##TYPE (DoublyLinkedList_##TYPE *this, TYPE t){\
        if(DoublyLinkedListIsEmpty_##TYPE (this)){\
            this->first = new_DoublyLinkedListElement_##TYPE(this->first, &t);\
            this->last = this->first;\
            this->size++;\
        }                                                 \
        else{                                           \
            this->last->next = new_DoublyLinkedListElement_##TYPE(this->last->next, &t);\
            this->last = this->last->next;\
            this->size++;\
        }\
    }\
    void addFirstToDoublyLinkedList_##TYPE (TYPE t, DoublyLinkedList_##TYPE *this){\
        if(DoublyLinkedListIsEmpty_##TYPE (this)){\
            this->first = new_DoublyLinkedListElement_##TYPE(this->first, &t);\
            this->last = this->first;\
            this->size++;\
        }                                                 \
        else{                                           \
            this->first->prev = new_DoublyLinkedListElement_##TYPE(this->first->prev, &t);\
            this->first = this->first->prev;\
            this->size++;\
        }\
    }\
    void destroy_DoublyLinkedList_##TYPE(DoublyLinkedList_##TYPE *this){\
        DoublyLinkedListElement_##TYPE* current = this->first;\
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

