/*.section .text.boot
.global _start
_start:
  la gp, __stack_bottom__
  csrw satp, zero
  la sp, __stack_top__
  la t0, kmain
  csrw mepc, t0
  tail kmain
  j .*/

.section .text.boot
.option norvc
.type _start, @function
.global _start
_start:
	.cfi_startproc
.option push
.option norelax
	la gp, __stack_bottom__
.option pop
	csrw satp, zero
	la sp, __stack_top__
	
	la t0, kmain
	csrw mepc, t0
	tail kmain
	.cfi_endproc
.end
