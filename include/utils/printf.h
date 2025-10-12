/* Include guard */
#ifndef UTILS_PRINTF_H
#define UTILS_PRINTF_H

/* Includes */
#include <utils/types.h>

/* Implementation of printf */
extern i32_t printf_custom(void (*putc)(char), const char *format, ...)
    __attribute__((format(printf, 2, 3)));

#endif /* PRINTF_H */
