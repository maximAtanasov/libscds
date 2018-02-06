/*libscds by Maxim Atanasoff
Free for everyone to use, modify and distrubite
*/

#include <stdio.h>
#include <stdlib.h>

#define DECLARE_BINARYSEARCHTREE(TYPE)\
\
    typedef struct BinarySearchTree_##TYPE BinarySearchTree_##TYPE;\
    struct BinarySearchTree_##TYPE\
    {\
        BinarySearchTree_##TYPE *leftChild;\
        BinarySearchTree_##TYPE *rightChild;\
        TYPE *content;\
        unsigned int quantity;\
    };\
\
    BinarySearchTree_##TYPE* new_BinarySearchTree_##TYPE (BinarySearchTree_##TYPE *this)\
    {\
        this = malloc( sizeof( BinarySearchTree_##TYPE) );\
        this->content = NULL;\
        this->leftChild = NULL;\
        this->rightChild = NULL;\
        this->quantity = 0;\
        return this;\
    }\
    int treeNodeIsEmpty_##TYPE (BinarySearchTree_##TYPE *this)\
    {\
        if(this->content == NULL)\
            return 1;\
        else\
            return 0;\
    }\
    int treeNodeIsLeaf_##TYPE (BinarySearchTree_##TYPE *this)\
    {\
        if(!treeNodeIsEmpty_##TYPE(this) && treeNodeIsEmpty_##TYPE(this->leftChild)\
        && treeNodeIsEmpty_##TYPE(this->rightChild))\
            return 1;\
        else\
            return 0;\
    }\
    int treeHeight_##TYPE(BinarySearchTree_##TYPE *this){\
        if(treeNodeIsEmpty_##TYPE(this))\
            return 0;\
        else{\
            int leftH = treeHeight_##TYPE(this->leftChild);\
            int rightH = treeHeight_##TYPE(this->rightChild);\
            if(leftH > rightH)\
                return leftH + 1;\
            else\
                return rightH + 1;\
        }\
    }\
    void addToTree_##TYPE (BinarySearchTree_##TYPE *this, TYPE t){\
        if(treeNodeIsEmpty_##TYPE (this)){\
            this->content = malloc(sizeof(TYPE));\
            *this->content = t;\
            this->leftChild = new_BinarySearchTree_##TYPE(this->leftChild);\
            this->rightChild = new_BinarySearchTree_##TYPE(this->rightChild);\
        }\
        else{\
            if(compare_##TYPE(&t, this->content) == -1)\
                addToTree_##TYPE (this->leftChild, t);\
            else if(compare_##TYPE(&t, this->content) == 1)\
                addToTree_##TYPE (this->rightChild, t);\
            else\
                this->quantity++;\
        }\
    }\
    BinarySearchTree_##TYPE* getTreeLeftChild_##TYPE(BinarySearchTree_##TYPE *this){\
        return this->leftChild;\
    }\
	BinarySearchTree_##TYPE* getTreeRightChild_##TYPE(BinarySearchTree_##TYPE *this){\
        return this->rightChild;\
    }\
    void destroy_BinarySearchTree_##TYPE(BinarySearchTree_##TYPE *this){\
        if(this != NULL){\
            destroy_BinarySearchTree_##TYPE(this->rightChild);\
            destroy_BinarySearchTree_##TYPE(this->leftChild);\
            free(this->content);\
            free(this);\
        }\
    }\
\
