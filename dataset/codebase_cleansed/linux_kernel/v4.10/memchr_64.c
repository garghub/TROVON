void *memchr(const void *s, int c, size_t n)
{
const uint64_t *last_word_ptr;
const uint64_t *p;
const char *last_byte_ptr;
uintptr_t s_int;
uint64_t goal, before_mask, v, bits;
char *ret;
if (__builtin_expect(n == 0, 0)) {
return NULL;
}
s_int = (uintptr_t) s;
p = (const uint64_t *)(s_int & -8);
goal = copy_byte(c);
before_mask = MASK(s_int);
v = (*p | before_mask) ^ (goal & before_mask);
last_byte_ptr = (const char *)s + n - 1;
last_word_ptr = (const uint64_t *)((uintptr_t) last_byte_ptr & -8);
while ((bits = __insn_v1cmpeq(v, goal)) == 0) {
if (__builtin_expect(p == last_word_ptr, 0)) {
return NULL;
}
v = *++p;
}
ret = ((char *)p) + (CFZ(bits) >> 3);
return (ret <= last_byte_ptr) ? ret : NULL;
}
