void *memchr(const void *s, int c, size_t n)
{
const uint32_t *last_word_ptr;
const uint32_t *p;
const char *last_byte_ptr;
uintptr_t s_int;
uint32_t goal, before_mask, v, bits;
char *ret;
if (__builtin_expect(n == 0, 0)) {
return NULL;
}
s_int = (uintptr_t) s;
p = (const uint32_t *)(s_int & -4);
goal = 0x01010101 * (uint8_t) c;
before_mask = (1 << (s_int << 3)) - 1;
v = (*p | before_mask) ^ (goal & before_mask);
last_byte_ptr = (const char *)s + n - 1;
last_word_ptr = (const uint32_t *)((uintptr_t) last_byte_ptr & -4);
while ((bits = __insn_seqb(v, goal)) == 0) {
if (__builtin_expect(p == last_word_ptr, 0)) {
return NULL;
}
v = *++p;
}
ret = ((char *)p) + (__insn_ctz(bits) >> 3);
return (ret <= last_byte_ptr) ? ret : NULL;
}
