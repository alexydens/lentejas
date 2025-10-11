volatile unsigned char *uart = (unsigned char *)0x09000000;

void putchar(char c) { *uart = c; }
void print(const char *s) { while (*s) { putchar(*s); s++; } }

void kmain(void) {
  print("Hello world!\n");
  while (1);
}
