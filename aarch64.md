# AArch64 Notes
## Registers
- `x0`-`x30`: general purpose
- `x31`: stack pointer/zero (`sp`/`xzr`)
- `x0`-`x7`: arguments
- `x0`(+`x1`): return vals
- `x19`-`x29`: calee-saved
- `x0`-`x18`: caller-saved
- `x29`: frame pointer (optional)
- `x30`: return address
## Stack
- Grows down
- 16-byte aligned (for function calls)
- No push/pop pneumonic
## Addressing Modes
- Offset: `[base, #imm]` -> `dest = *(base + imm)`
- Pre: `[base, #imm]!` -> `base += imm`, `dest = *base`
- Post: `[base], #imm` -> `dest = *base; base += imm`
