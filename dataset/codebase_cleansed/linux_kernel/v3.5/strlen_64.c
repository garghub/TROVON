size_t strlen(const char *s)
{
const uintptr_t s_int = (uintptr_t) s;
const uint64_t *p = (const uint64_t *)(s_int & -8);
uint64_t v = *p | MASK(s_int);
uint64_t bits;
while ((bits = __insn_v1cmpeqi(v, 0)) == 0)
v = *++p;
return ((const char *)p) + (CFZ(bits) >> 3) - s;
}
