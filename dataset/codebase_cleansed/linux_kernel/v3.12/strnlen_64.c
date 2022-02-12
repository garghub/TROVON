size_t strnlen(const char *s, size_t count)
{
const uintptr_t s_int = (uintptr_t) s;
const uint64_t *p = (const uint64_t *)(s_int & -8);
size_t bytes_read = sizeof(*p) - (s_int & (sizeof(*p) - 1));
size_t len;
uint64_t v, bits;
if (count == 0)
return 0;
v = *p | MASK(s_int);
while ((bits = __insn_v1cmpeqi(v, 0)) == 0) {
if (bytes_read >= count) {
return count;
}
v = *++p;
bytes_read += sizeof(v);
}
len = ((const char *) p) + (CFZ(bits) >> 3) - s;
return (len < count ? len : count);
}
