#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <stdbool.h>

#define VECTOR_MINIMUM_CAPACITY 2

typedef struct {
    int *data;
    int size;
    int capacity;
} VectorInt1d;

bool vector_int_1d_is_empty(VectorInt1d *v);

void vector_int_1d_init(VectorInt1d *v);

void vector_int_1d_push_back(VectorInt1d *v, int x);
void vector_int_1d_pop_back(VectorInt1d *v);

int vector_int_1d_get(VectorInt1d *v, int index);
void vector_int_1d_insert(VectorInt1d *v, int index, int x);
void vector_int_1d_erase(VectorInt1d *v, int index);
void vector_int_1d_deep_copy(VectorInt1d *v1, VectorInt1d *v2);

void vector_int_1d_reverse(VectorInt1d *v);
void vector_int_1d_find(VectorInt1d *v, int x);
void vector_int_1d_remove(VectorInt1d *v, int x);
void vector_int_1d_swap_elements(VectorInt1d *v, int index1, int index2);
int vector_int_1d_binary_search_lower(VectorInt1d *v, int x);
int vector_int_1d_binary_search_upper(VectorInt1d *v, int x);

// Infomation
int vector_int_1d_size(VectorInt1d *v);
int vector_int_1d_capacity(VectorInt1d *v);

void vector_int_1d_print(VectorInt1d *v);
void vector_int_1d_free(VectorInt1d *v);

/* ------- Private -------*/

bool _vector_int_1d_should_grow(VectorInt1d *v);
bool _vector_int_1d_should_shrink(VectorInt1d *v);

void _vector_int_1d_resize(VectorInt1d *v, int new_capacity);

/* -----------------------*/

#endif 