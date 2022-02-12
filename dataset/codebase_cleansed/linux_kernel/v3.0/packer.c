static u64 value_read(int offset, int size, void *structure)
{
switch (size) {
case 1: return *(u8 *) (structure + offset);
case 2: return be16_to_cpup((__be16 *) (structure + offset));
case 4: return be32_to_cpup((__be32 *) (structure + offset));
case 8: return be64_to_cpup((__be64 *) (structure + offset));
default:
printk(KERN_WARNING "Field size %d bits not handled\n", size * 8);
return 0;
}
}
void ib_pack(const struct ib_field *desc,
int desc_len,
void *structure,
void *buf)
{
int i;
for (i = 0; i < desc_len; ++i) {
if (desc[i].size_bits <= 32) {
int shift;
u32 val;
__be32 mask;
__be32 *addr;
shift = 32 - desc[i].offset_bits - desc[i].size_bits;
if (desc[i].struct_size_bytes)
val = value_read(desc[i].struct_offset_bytes,
desc[i].struct_size_bytes,
structure) << shift;
else
val = 0;
mask = cpu_to_be32(((1ull << desc[i].size_bits) - 1) << shift);
addr = (__be32 *) buf + desc[i].offset_words;
*addr = (*addr & ~mask) | (cpu_to_be32(val) & mask);
} else if (desc[i].size_bits <= 64) {
int shift;
u64 val;
__be64 mask;
__be64 *addr;
shift = 64 - desc[i].offset_bits - desc[i].size_bits;
if (desc[i].struct_size_bytes)
val = value_read(desc[i].struct_offset_bytes,
desc[i].struct_size_bytes,
structure) << shift;
else
val = 0;
mask = cpu_to_be64((~0ull >> (64 - desc[i].size_bits)) << shift);
addr = (__be64 *) ((__be32 *) buf + desc[i].offset_words);
*addr = (*addr & ~mask) | (cpu_to_be64(val) & mask);
} else {
if (desc[i].offset_bits % 8 ||
desc[i].size_bits % 8) {
printk(KERN_WARNING "Structure field %s of size %d "
"bits is not byte-aligned\n",
desc[i].field_name, desc[i].size_bits);
}
if (desc[i].struct_size_bytes)
memcpy(buf + desc[i].offset_words * 4 +
desc[i].offset_bits / 8,
structure + desc[i].struct_offset_bytes,
desc[i].size_bits / 8);
else
memset(buf + desc[i].offset_words * 4 +
desc[i].offset_bits / 8,
0,
desc[i].size_bits / 8);
}
}
}
static void value_write(int offset, int size, u64 val, void *structure)
{
switch (size * 8) {
case 8: *( u8 *) (structure + offset) = val; break;
case 16: *(__be16 *) (structure + offset) = cpu_to_be16(val); break;
case 32: *(__be32 *) (structure + offset) = cpu_to_be32(val); break;
case 64: *(__be64 *) (structure + offset) = cpu_to_be64(val); break;
default:
printk(KERN_WARNING "Field size %d bits not handled\n", size * 8);
}
}
void ib_unpack(const struct ib_field *desc,
int desc_len,
void *buf,
void *structure)
{
int i;
for (i = 0; i < desc_len; ++i) {
if (!desc[i].struct_size_bytes)
continue;
if (desc[i].size_bits <= 32) {
int shift;
u32 val;
u32 mask;
__be32 *addr;
shift = 32 - desc[i].offset_bits - desc[i].size_bits;
mask = ((1ull << desc[i].size_bits) - 1) << shift;
addr = (__be32 *) buf + desc[i].offset_words;
val = (be32_to_cpup(addr) & mask) >> shift;
value_write(desc[i].struct_offset_bytes,
desc[i].struct_size_bytes,
val,
structure);
} else if (desc[i].size_bits <= 64) {
int shift;
u64 val;
u64 mask;
__be64 *addr;
shift = 64 - desc[i].offset_bits - desc[i].size_bits;
mask = (~0ull >> (64 - desc[i].size_bits)) << shift;
addr = (__be64 *) buf + desc[i].offset_words;
val = (be64_to_cpup(addr) & mask) >> shift;
value_write(desc[i].struct_offset_bytes,
desc[i].struct_size_bytes,
val,
structure);
} else {
if (desc[i].offset_bits % 8 ||
desc[i].size_bits % 8) {
printk(KERN_WARNING "Structure field %s of size %d "
"bits is not byte-aligned\n",
desc[i].field_name, desc[i].size_bits);
}
memcpy(structure + desc[i].struct_offset_bytes,
buf + desc[i].offset_words * 4 +
desc[i].offset_bits / 8,
desc[i].size_bits / 8);
}
}
}
