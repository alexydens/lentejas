/* Includes */
#include <utils/types.h>
#include <utils/endian.h>

volatile u8_t *uart = (u8_t *)0x09000000;

void putchar(char c) { *uart = c; }
void print(const char *s) { while (*s) { putchar(*s); s++; } }
void printptr(void *p) {
  print("0x");
  char buff[17];
  buff[16] = 0;
  for (u8_t i = 0; i < 16; i++) {
    u8_t n = (((u64_t)p) >> (124-4*i)) & 0xf;
    buff[i] = n < 10 ? '0' + n : 'A' + (n-10);
  }
  print(buff);
}

/* Kernel entry point */
void kmain(void *dtb) {
  print("dtb: ");
  printptr(dtb);
  print("\n");
  if (endian_swap_u32(*((u32_t *)dtb)) == 0xd00dfeed)
    print("Correct magic number\n");
  else
    print("Incorrect magic number\n");
  while (1);
}
