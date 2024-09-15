#include <stdio.h>

#include "vector.h"

int main(void){
    //     SimpleVector v;
    // simple_vector_init(&v);

    // for(int i = 0; i < 10; i++){
    //     simple_vector_push_back(&v, i);
    // }

    // simple_vector_print(&v);

    // simple_vector_pop_back(&v);

    // simple_vector_print(&v);

    // simple_vector_insert(&v, 3, 100);

    // simple_vector_print(&v);

    // simple_vector_erase(&v, 3);

    // simple_vector_print(&v);

    // printf("%d\n", simple_vector_find(&v, 4));

    // simple_vector_remove(&v, 3);

    // simple_vector_print(&v);

    // printf("%d\n", simple_vector_get(&v, 3));

    // printf("%d\n", simple_vector_size(&v));

    // simple_vector_reverse(&v);

    // simple_vector_print(&v);


    VectorInt1d v;
    vector_int_1d_init(&v);

    for(int i = 0; i < 10; i++){
        vector_int_1d_push_back(&v, i);
    }

    vector_int_1d_print(&v);

    vector_int_1d_pop_back(&v);

    vector_int_1d_print(&v);

    vector_int_1d_insert(&v, 3, 100);

    vector_int_1d_print(&v);

    vector_int_1d_erase(&v, 3);

    vector_int_1d_print(&v);

    printf("%d\n", vector_int_1d_get(&v, 3));

    printf("%d\n", vector_int_1d_size(&v));

    vector_int_1d_reverse(&v);

    vector_int_1d_print(&v);

    vector_int_1d_find(&v, 4);

    vector_int_1d_remove(&v, 3);

    vector_int_1d_print(&v);

    vector_int_1d_swap_elements(&v, 0, 1);

    vector_int_1d_print(&v);

    vector_int_1d_free(&v);

    return 0;
}