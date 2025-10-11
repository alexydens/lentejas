.section .text.entry
.global _start
_start:
  ldr x30, =__stack_top__
  mov sp, x30
  bl kmain
  b .
