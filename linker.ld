ENTRY(_start)

SECTIONS {
  . = 0x40100000;
  .entry . : { .text.entry }
  .text : { *(.text*) }
  .data : { *(.data*) }
  .rodata : { *(.rodata*) }
  .bss : { *(.bss*) COMMON }
  . = ALIGN(16);
  __stack_bottom__ = .;
  . += 1024*32;
  __stack_top__ = .;
}
