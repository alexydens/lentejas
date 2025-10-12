/* Include guard */
#ifndef UTILS_TYPES_H
#define UTILS_TYPES_H

/* Unsigned integers */
typedef unsigned long long u64_t;
typedef unsigned int u32_t;
typedef unsigned short u16_t;
typedef unsigned char u8_t;
/* Signed integers */
typedef signed long long i64_t;
typedef signed int i32_t;
typedef signed short i16_t;
typedef signed char i8_t;

/* Size checks */
#define SIZE_CHECK(t, s)\
_Static_assert(sizeof(t)==s, "Failed size check: sizeof("#t") == "#s)
SIZE_CHECK(u64_t, 8);
SIZE_CHECK(u32_t, 4);
SIZE_CHECK(u16_t, 2);
SIZE_CHECK(u8_t, 1);
SIZE_CHECK(i64_t, 8);
SIZE_CHECK(i32_t, 4);
SIZE_CHECK(i16_t, 2);
SIZE_CHECK(i8_t, 1);
#undef SIZE_CHECK

/* Booleans */
#define TRUE 1
#define FALSE 0

#endif /* UTILS_H */
