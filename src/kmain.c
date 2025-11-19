/* Includes */
#include <utils/types.h>
#include <utils/endian.h>
#include <utils/printf.h>

volatile u8_t *uart = (u8_t *)0x09000000;

void putchar(char c) { *uart = c; }
void print(const char *s) { while (*s) { putchar(*s); s++; } }
void print_u8(u8_t val) {
  char buff[3];
  u8_t n = (val >> 4) & 0xf;
  buff[0] = n < 10 ? '0' + n : 'A' + (n-10);
  n = val & 0xf;
  buff[1] = n < 10 ? '0' + n : 'A' + (n-10);
  buff[2] = 0;
  print(buff);
}
void print_u16(u16_t val) {
  char buff[5];
  buff[4] = 0;
  for (u8_t i = 0; i < 4; i++) {
    u8_t n = (val >> (12-4*i)) & 0xf;
    buff[i] = n < 10 ? '0' + n : 'A' + (n-10);
  }
  print(buff);
}
void print_u32(u32_t val) {
  char buff[9];
  buff[8] = 0;
  for (u8_t i = 0; i < 8; i++) {
    u8_t n = (val >> (28-4*i)) & 0xf;
    buff[i] = n < 10 ? '0' + n : 'A' + (n-10);
  }
  print(buff);
}
void print_u64(u64_t val) {
  char buff[17];
  buff[16] = 0;
  for (u8_t i = 0; i < 16; i++) {
    u8_t n = (val >> (60-4*i)) & 0xf;
    buff[i] = n < 10 ? '0' + n : 'A' + (n-10);
  }
  print(buff);
}

/* Kernel entry point */
void kmain(void *dtb) {
  print("dtb: 0x");print_u64((u64_t)dtb);print("\n");
  printf_custom(putchar, "n = %d\n", 3);
  if (endian_swap_u32(*((u32_t *)dtb)) == 0xd00dfeed)
    print("Correct magic number\n");
  else
    print("Incorrect magic number\n");
  while (1);
}
