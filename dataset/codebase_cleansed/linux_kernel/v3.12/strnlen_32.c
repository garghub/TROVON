size_t strnlen(const char *s, size_t count)
{
const uintptr_t s_int = (uintptr_t) s;
const uint32_t *p = (const uint32_t *)(s_int & -4);
size_t bytes_read = sizeof(*p) - (s_int & (sizeof(*p) - 1));
size_t len;
uint32_t v, bits;
if (count == 0)
return 0;
v = *p | ((1 << ((s_int << 3) & 31)) - 1);
while ((bits = __insn_seqb(v, 0)) == 0) {
if (bytes_read >= count) {
return count;
}
v = *++p;
bytes_read += sizeof(v);
}
len = ((const char *) p) + (__insn_ctz(bits) >> 3) - s;
return (len < count ? len : count);
}
