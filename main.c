/* File: main.c
 * Author: Ragib Asif
 * Email: ragib.asif30@myhunter.cuny.edu
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 */

#include "da.h"

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    struct dynamic_array *array;
    array = da_create(array);
    dbg(array);

    size_t i;
    for (i = 0; i < 20; i++) {
        da_pushback(array, i + 100);
    }
    // dbg_output(array);

    da_print(array);

    for (i = 0; i < 10; i++) {
        da_popback(array);
    }
    da_print(array);

    // dbg_output(array);
    da_clear(array);
    // dbg_output(array);

    da_memory_dump(array);

    da_destroy(array);

    /* MEMORY DEBUGGING - DO NOT TOUCH */
    f_debug_memory_init(NULL, NULL, NULL);
    f_debug_mem_print(0);
    f_debug_mem_reset();

    return 0;
}
