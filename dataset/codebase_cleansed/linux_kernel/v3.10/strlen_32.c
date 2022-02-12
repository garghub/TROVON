size_t strlen(const char *s)
{
const uintptr_t s_int = (uintptr_t) s;
const uint32_t *p = (const uint32_t *)(s_int & -4);
uint32_t v = *p | ((1 << (s_int << 3)) - 1);
uint32_t bits;
while ((bits = __insn_seqb(v, 0)) == 0)
v = *++p;
return ((const char *)p) + (__insn_ctz(bits) >> 3) - s;
}
