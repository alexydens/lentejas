.section .text.entry
.global _start
_start:
  ldr x1, =__stack_top__
  mov sp, x1
  ldr x0, =0x40000000
  bl kmain
  b .
