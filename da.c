/*
 * File: da.c
 * Author: Ragib Asif
 * Email: ragib.asif30@myhunter.cuny.edu
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 *
 * implementation
 *
 */

#include "da.h"

#define BUFFER_SIZE_DEFAULT 0
#define BUFFER_CAPACITY_DEFAULT 1
#define BUFFER_CAPACITY_MULTIPLIER 2

// debugging
static void dbg_output(struct dynamic_array *array) {
    size_t i;

    dbg(array);
    dbg(array->buffer);
    for (i = 0; i < array->size; i++) {
        dbg(array->buffer[i]);
    }
    dbg(array->size);
    dbg(&array->size);
    dbg(array->capacity);
    dbg(&array->capacity);
}

struct dynamic_array *da_create(struct dynamic_array *array) {
    size_t i;
    array = malloc(sizeof(*array));
    array->size = BUFFER_SIZE_DEFAULT;
    array->capacity = BUFFER_CAPACITY_DEFAULT;
    array->buffer = malloc(array->capacity * sizeof(int *));
    for (i = 0; i < BUFFER_CAPACITY_DEFAULT; i++) {
        array->buffer[i] = 0;
    }
    dbg(array);
    return array;
}

void da_destroy(struct dynamic_array *array) {
    free(array->buffer);
    array->buffer = NULL;
    array->size = 0;
    array->capacity = 0;
    free(array);
    array = NULL;
}

void da_pushback(struct dynamic_array *array, int value) {
    if (array->size == array->capacity) {
        size_t i;
        array->capacity *= BUFFER_CAPACITY_MULTIPLIER;
        array->buffer = realloc(array->buffer, array->capacity * sizeof(int *));
        for (i = array->size; i < array->capacity; i++) {
            array->buffer[i] = 0;
        }
    }
    // casting is required if the buffer type is void *
    // *(((int *)array->buffer) + array->size++) = value;
    array->buffer[array->size++] = value;
}

void da_popback(struct dynamic_array *array) {
    if (array->size) {
        array->size--;
    }
}

void da_clear(struct dynamic_array *array) { array->size = 0; }

void da_print(struct dynamic_array *array) {
    size_t i;
    for (i = 0; i < array->size; i++) {
        printf("%d ", array->buffer[i]);
    }
    putchar('\n');
}

void da_memory_dump(struct dynamic_array *array) {
    size_t i;
    for (i = 0; i < array->capacity; i++) {
        printf("%d ", array->buffer[i]);
    }
    putchar('\n');
}

// int main(int argc, char **argv) {
//     (void)argc;
//     (void)argv;
//
//     struct dynamic_array *array;
//     array = da_create(array);
//     dbg(array);
//
//     size_t i;
//     for (i = 0; i < 20; i++) {
//         da_pushback(array, i + 100);
//     }
//     dbg_output(array);
//
//     da_print(array);
//
//     for (i = 0; i < 10; i++) {
//         da_popback(array);
//     }
//     da_print(array);
//
//     dbg_output(array);
//     da_clear(array);
//     dbg_output(array);
//
//     da_memory_dump(array);
//
//     da_destroy(array);
//
//     /* MEMORY DEBUGGING - DO NOT TOUCH */
//     f_debug_memory_init(NULL, NULL, NULL);
//     f_debug_mem_print(0);
//     f_debug_mem_reset();
//
//     return 0;
// }
