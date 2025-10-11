volatile unsigned char *uart = (unsigned char *)0x09000000;

void putchar(char c) { *uart = c; }
void print(const char *s) { while (*s) { putchar(*s); s++; } }
void printptr(void *p) {
  print("0x");
  char buff[17];
  buff[16] = 0;
  for (int i = 0; i < 16; i++) {
    int n = (((unsigned long long)p) >> (124-4*i)) & 0xf;
    buff[i] = n < 10 ? '0' + n : 'A' + (n-10);
  }
  print(buff);
}

void kmain(void *dtb) {
  print("dtb: ");
  printptr(dtb);
  print("\n");
  print("magic number: ");
  printptr(*((void **)dtb));
  print("\n");
  while (1);
}
