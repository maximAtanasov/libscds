#include <stdio.h>

#include "int_vector.h"

int main(void){
	//int Vector example
	int_vector* vector1 = make_int_vector();
	int_vector_push(vector1, 1);
    int_vector_push(vector1, 2);
    int_vector_push(vector1, 3);

	int* vec_int = int_vector_at(vector1, 1);
    if(vec_int != NULL) {
        printf("%d\n", *vec_int);
    }

    free_int_vector(vector1);
    return 0;
}
