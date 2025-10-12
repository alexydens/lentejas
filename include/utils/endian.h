/* Include guard */
#ifndef UTILS_ENDIAN_H
#define UTILS_ENDIAN_H

/* Swap endianness */
static inline u16_t endian_swap_u16(u16_t val) {
  return ((val >> 8) & 0x00ff) | ((val << 8) & 0xff00);
}
static inline u32_t endian_swap_u32(u32_t val) {
  return ((val >> 24) & 0x000000ff)
      | ((val >> 8) & 0x0000ff00)
      | ((val << 8) & 0x00ff0000)
      | ((val << 24) & 0xff000000);
}
static inline u64_t endian_swap_u64(u64_t val) {
  return ((val >> 56) & 0x00000000000000ff)
      | ((val >> 40) & 0x000000000000ff00)
      | ((val >> 24) & 0x0000000000ff0000)
      | ((val >> 8) & 0x00000000ff000000)
      | ((val << 8) & 0x000000ff00000000)
      | ((val << 24) & 0x0000ff0000000000)
      | ((val << 40) & 0x00ff000000000000)
      | ((val << 56) & 0xff00000000000000);
}

#endif /* UTILS_ENDIAN_H */
