int vphn_unpack_associativity(const long *packed, __be32 *unpacked)
{
__be64 be_packed[VPHN_REGISTER_COUNT];
int i, nr_assoc_doms = 0;
const __be16 *field = (const __be16 *) be_packed;
u16 last = 0;
bool is_32bit = false;
#define VPHN_FIELD_UNUSED (0xffff)
#define VPHN_FIELD_MSB (0x8000)
#define VPHN_FIELD_MASK (~VPHN_FIELD_MSB)
for (i = 0; i < VPHN_REGISTER_COUNT; i++)
be_packed[i] = cpu_to_be64(packed[i]);
for (i = 1; i < VPHN_ASSOC_BUFSIZE; i++) {
u16 new = be16_to_cpup(field++);
if (is_32bit) {
unpacked[++nr_assoc_doms] =
cpu_to_be32(last << 16 | new);
is_32bit = false;
} else if (new == VPHN_FIELD_UNUSED)
break;
else if (new & VPHN_FIELD_MSB) {
unpacked[++nr_assoc_doms] =
cpu_to_be32(new & VPHN_FIELD_MASK);
} else {
last = new;
is_32bit = true;
}
}
unpacked[0] = cpu_to_be32(nr_assoc_doms);
return nr_assoc_doms;
}
