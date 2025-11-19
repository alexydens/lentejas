/* Implements utils/printf.h */
#include <utils/printf.h>
#include <stdarg.h>

/* Implementation of printf (incomplete) */
i32_t printf_custom(void (*putc)(char), const char *format, ...) {
  va_list args;
  va_start(args, format);
  u64_t cur = 0;
  while (format[cur]) {
    if (format[cur] != '%') {
      putc(format[cur]);
      cur++;
      continue;
    }
    if (format[++cur] == '%') {
      putc(format[cur]);
      cur++;
      continue;
    }
    u8_t plus_sign = 0; /* '+' or ' ' */
    u8_t length = 0; /* increments for each 'l' (e.g. %llu) */
    u32_t width = 0;
    i32_t precision = 0;
    if (format[cur] == '+' || format[cur] == ' ') {
      plus_sign = format[cur];
      cur++;
    }
    while (format[cur] >= '0' && format[cur] <= '9') {
      width *= 10;
      width += (u32_t)(format[cur] - '0');
      cur++;
    }
    if (format[cur] == '.') {
      cur++;
      if (format[cur] == '*') precision = va_arg(args, int);
      else {
        while (format[cur] >= '0' && format[cur] <= '9') {
          precision *= 10;
          precision += (i32_t)(format[cur] - '0');
          cur++;
        }
      }
    }
    if (format[cur] == 'l') {
      length++;
      cur++;
      if (format[cur] == 'l') {
        length++;
        cur++;
      }
    }
  }
  va_end(args);
  return 0;
}
