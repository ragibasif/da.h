/*
 * File: bitter.h
 * Author: Ragib Asif
 * Email: ragib.asif30@myhunter.cuny.edu
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 *
 * Dynamic Array in C.
 *
 */

#ifndef __DA_H_
#define __DA_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/******************************************************************************/
/*                                  INCLUDES                                  */
/******************************************************************************/

#include <assert.h> //assert
#include <ctype.h>  //size_t
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h> //true, false, bool
#include <stdint.h>
#include <stdio.h> //Includes the standard I/O library for functions like `printf`.
#include <stdlib.h> //Includes the standard library for functions like `malloc`, `free`, and `realloc`.
#include <string.h> //Includes the string manipulation library for functions like `memcpy`.
#include <time.h> //time

/******************************************************************************/
/*                          DEBUGGING - DO NOT TOUCH                          */
/******************************************************************************/

#define F_MEMORY_DEBUG /* turns on the memory debugging system */
#define F_MEMORY_PRINT /* turns on the memory printing system */
#define F_EXIT_CRASH   /* turns on the crash on exit */
#include "libs/dbg-macro/dbg.h"
#include "libs/forge/forge.h"
#include "libs/munit/munit.h"

/******************************************************************************/
/*                                    API                                     */
/******************************************************************************/

struct dynamic_array {
    int *buffer;
    int size;
    int capacity;
};

struct dynamic_array *da_create(struct dynamic_array *array);

extern void da_destroy(struct dynamic_array *array);

extern void da_pushback(struct dynamic_array *array, int value);

extern void da_popback(struct dynamic_array *array);

extern void da_clear(struct dynamic_array *array);

extern void da_print(struct dynamic_array *array);

extern void da_memory_dump(struct dynamic_array *array);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // __DA_H_
