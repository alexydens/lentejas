OUTPUT_ARCH("riscv")
ENTRY(_start)

. = 0x80000000;

SECTIONS
{
  .text : ALIGN(4K) {
    $(.text.boot)
    *(.text .text.*)
  }

  .rodata : ALIGN(4K) {
    *(.srodata .srodata.*)
    . = ALIGN(16);
    *(.rodata .rodata.*)
  }

  .data : ALIGN(4K) {
    *(.sdata .sdata.*)
    . = ALIGN(16);
    *(.data .data.*)
  }

  .bss : ALIGN(4K) {
    *(.sbss .sbss.*)
    . = ALIGN(16);
    *(.bss .bss.*)
    . = ALIGN(4096);
    __stack_top__ = .;
    . += 4096;
    __stack_bottom__ = .;
  }
}
