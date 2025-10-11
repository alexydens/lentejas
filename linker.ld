ENTRY(_start)

SECTIONS {
  . = 0x40100000;
  .entry . : { .text.entry }
  .text : { *(.text) }
  .data : { *(.data) }
  .bss : { *(.bss) COMMON }
  . = ALIGN(8);
  __stack_bottom__ = .;
  . += 1024*16;
  __stack_top__ = .;
}
