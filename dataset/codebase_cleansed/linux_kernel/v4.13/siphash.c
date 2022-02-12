u64 __siphash_aligned(const void *data, size_t len, const siphash_key_t *key)
{
const u8 *end = data + len - (len % sizeof(u64));
const u8 left = len & (sizeof(u64) - 1);
u64 m;
PREAMBLE(len)
for (; data != end; data += sizeof(u64)) {
m = le64_to_cpup(data);
v3 ^= m;
SIPROUND;
SIPROUND;
v0 ^= m;
}
#if defined(CONFIG_DCACHE_WORD_ACCESS) && BITS_PER_LONG == 64
if (left)
b |= le64_to_cpu((__force __le64)(load_unaligned_zeropad(data) &
bytemask_from_count(left)));
#else
switch (left) {
case 7: b |= ((u64)end[6]) << 48;
case 6: b |= ((u64)end[5]) << 40;
case 5: b |= ((u64)end[4]) << 32;
case 4: b |= le32_to_cpup(data); break;
case 3: b |= ((u64)end[2]) << 16;
case 2: b |= le16_to_cpup(data); break;
case 1: b |= end[0];
}
#endif
POSTAMBLE
}
u64 __siphash_unaligned(const void *data, size_t len, const siphash_key_t *key)
{
const u8 *end = data + len - (len % sizeof(u64));
const u8 left = len & (sizeof(u64) - 1);
u64 m;
PREAMBLE(len)
for (; data != end; data += sizeof(u64)) {
m = get_unaligned_le64(data);
v3 ^= m;
SIPROUND;
SIPROUND;
v0 ^= m;
}
#if defined(CONFIG_DCACHE_WORD_ACCESS) && BITS_PER_LONG == 64
if (left)
b |= le64_to_cpu((__force __le64)(load_unaligned_zeropad(data) &
bytemask_from_count(left)));
#else
switch (left) {
case 7: b |= ((u64)end[6]) << 48;
case 6: b |= ((u64)end[5]) << 40;
case 5: b |= ((u64)end[4]) << 32;
case 4: b |= get_unaligned_le32(end); break;
case 3: b |= ((u64)end[2]) << 16;
case 2: b |= get_unaligned_le16(end); break;
case 1: b |= end[0];
}
#endif
POSTAMBLE
}
u64 siphash_1u64(const u64 first, const siphash_key_t *key)
{
PREAMBLE(8)
v3 ^= first;
SIPROUND;
SIPROUND;
v0 ^= first;
POSTAMBLE
}
u64 siphash_2u64(const u64 first, const u64 second, const siphash_key_t *key)
{
PREAMBLE(16)
v3 ^= first;
SIPROUND;
SIPROUND;
v0 ^= first;
v3 ^= second;
SIPROUND;
SIPROUND;
v0 ^= second;
POSTAMBLE
}
u64 siphash_3u64(const u64 first, const u64 second, const u64 third,
const siphash_key_t *key)
{
PREAMBLE(24)
v3 ^= first;
SIPROUND;
SIPROUND;
v0 ^= first;
v3 ^= second;
SIPROUND;
SIPROUND;
v0 ^= second;
v3 ^= third;
SIPROUND;
SIPROUND;
v0 ^= third;
POSTAMBLE
}
u64 siphash_4u64(const u64 first, const u64 second, const u64 third,
const u64 forth, const siphash_key_t *key)
{
PREAMBLE(32)
v3 ^= first;
SIPROUND;
SIPROUND;
v0 ^= first;
v3 ^= second;
SIPROUND;
SIPROUND;
v0 ^= second;
v3 ^= third;
SIPROUND;
SIPROUND;
v0 ^= third;
v3 ^= forth;
SIPROUND;
SIPROUND;
v0 ^= forth;
POSTAMBLE
}
u64 siphash_1u32(const u32 first, const siphash_key_t *key)
{
PREAMBLE(4)
b |= first;
POSTAMBLE
}
u64 siphash_3u32(const u32 first, const u32 second, const u32 third,
const siphash_key_t *key)
{
u64 combined = (u64)second << 32 | first;
PREAMBLE(12)
v3 ^= combined;
SIPROUND;
SIPROUND;
v0 ^= combined;
b |= third;
POSTAMBLE
}
u32 __hsiphash_aligned(const void *data, size_t len, const hsiphash_key_t *key)
{
const u8 *end = data + len - (len % sizeof(u64));
const u8 left = len & (sizeof(u64) - 1);
u64 m;
HPREAMBLE(len)
for (; data != end; data += sizeof(u64)) {
m = le64_to_cpup(data);
v3 ^= m;
HSIPROUND;
v0 ^= m;
}
#if defined(CONFIG_DCACHE_WORD_ACCESS) && BITS_PER_LONG == 64
if (left)
b |= le64_to_cpu((__force __le64)(load_unaligned_zeropad(data) &
bytemask_from_count(left)));
#else
switch (left) {
case 7: b |= ((u64)end[6]) << 48;
case 6: b |= ((u64)end[5]) << 40;
case 5: b |= ((u64)end[4]) << 32;
case 4: b |= le32_to_cpup(data); break;
case 3: b |= ((u64)end[2]) << 16;
case 2: b |= le16_to_cpup(data); break;
case 1: b |= end[0];
}
#endif
HPOSTAMBLE
}
u32 __hsiphash_unaligned(const void *data, size_t len,
const hsiphash_key_t *key)
{
const u8 *end = data + len - (len % sizeof(u64));
const u8 left = len & (sizeof(u64) - 1);
u64 m;
HPREAMBLE(len)
for (; data != end; data += sizeof(u64)) {
m = get_unaligned_le64(data);
v3 ^= m;
HSIPROUND;
v0 ^= m;
}
#if defined(CONFIG_DCACHE_WORD_ACCESS) && BITS_PER_LONG == 64
if (left)
b |= le64_to_cpu((__force __le64)(load_unaligned_zeropad(data) &
bytemask_from_count(left)));
#else
switch (left) {
case 7: b |= ((u64)end[6]) << 48;
case 6: b |= ((u64)end[5]) << 40;
case 5: b |= ((u64)end[4]) << 32;
case 4: b |= get_unaligned_le32(end); break;
case 3: b |= ((u64)end[2]) << 16;
case 2: b |= get_unaligned_le16(end); break;
case 1: b |= end[0];
}
#endif
HPOSTAMBLE
}
u32 hsiphash_1u32(const u32 first, const hsiphash_key_t *key)
{
HPREAMBLE(4)
b |= first;
HPOSTAMBLE
}
u32 hsiphash_2u32(const u32 first, const u32 second, const hsiphash_key_t *key)
{
u64 combined = (u64)second << 32 | first;
HPREAMBLE(8)
v3 ^= combined;
HSIPROUND;
v0 ^= combined;
HPOSTAMBLE
}
u32 hsiphash_3u32(const u32 first, const u32 second, const u32 third,
const hsiphash_key_t *key)
{
u64 combined = (u64)second << 32 | first;
HPREAMBLE(12)
v3 ^= combined;
HSIPROUND;
v0 ^= combined;
b |= third;
HPOSTAMBLE
}
u32 hsiphash_4u32(const u32 first, const u32 second, const u32 third,
const u32 forth, const hsiphash_key_t *key)
{
u64 combined = (u64)second << 32 | first;
HPREAMBLE(16)
v3 ^= combined;
HSIPROUND;
v0 ^= combined;
combined = (u64)forth << 32 | third;
v3 ^= combined;
HSIPROUND;
v0 ^= combined;
HPOSTAMBLE
}
u32 __hsiphash_aligned(const void *data, size_t len, const hsiphash_key_t *key)
{
const u8 *end = data + len - (len % sizeof(u32));
const u8 left = len & (sizeof(u32) - 1);
u32 m;
HPREAMBLE(len)
for (; data != end; data += sizeof(u32)) {
m = le32_to_cpup(data);
v3 ^= m;
HSIPROUND;
v0 ^= m;
}
switch (left) {
case 3: b |= ((u32)end[2]) << 16;
case 2: b |= le16_to_cpup(data); break;
case 1: b |= end[0];
}
HPOSTAMBLE
}
u32 __hsiphash_unaligned(const void *data, size_t len,
const hsiphash_key_t *key)
{
const u8 *end = data + len - (len % sizeof(u32));
const u8 left = len & (sizeof(u32) - 1);
u32 m;
HPREAMBLE(len)
for (; data != end; data += sizeof(u32)) {
m = get_unaligned_le32(data);
v3 ^= m;
HSIPROUND;
v0 ^= m;
}
switch (left) {
case 3: b |= ((u32)end[2]) << 16;
case 2: b |= get_unaligned_le16(end); break;
case 1: b |= end[0];
}
HPOSTAMBLE
}
u32 hsiphash_1u32(const u32 first, const hsiphash_key_t *key)
{
HPREAMBLE(4)
v3 ^= first;
HSIPROUND;
v0 ^= first;
HPOSTAMBLE
}
u32 hsiphash_2u32(const u32 first, const u32 second, const hsiphash_key_t *key)
{
HPREAMBLE(8)
v3 ^= first;
HSIPROUND;
v0 ^= first;
v3 ^= second;
HSIPROUND;
v0 ^= second;
HPOSTAMBLE
}
u32 hsiphash_3u32(const u32 first, const u32 second, const u32 third,
const hsiphash_key_t *key)
{
HPREAMBLE(12)
v3 ^= first;
HSIPROUND;
v0 ^= first;
v3 ^= second;
HSIPROUND;
v0 ^= second;
v3 ^= third;
HSIPROUND;
v0 ^= third;
HPOSTAMBLE
}
u32 hsiphash_4u32(const u32 first, const u32 second, const u32 third,
const u32 forth, const hsiphash_key_t *key)
{
HPREAMBLE(16)
v3 ^= first;
HSIPROUND;
v0 ^= first;
v3 ^= second;
HSIPROUND;
v0 ^= second;
v3 ^= third;
HSIPROUND;
v0 ^= third;
v3 ^= forth;
HSIPROUND;
v0 ^= forth;
HPOSTAMBLE
}
