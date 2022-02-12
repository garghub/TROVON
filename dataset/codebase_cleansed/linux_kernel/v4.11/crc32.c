u32 __pure crc32_le(u32 crc, unsigned char const *p, size_t len)
{
return crc32_le_generic(crc, p, len, NULL, CRCPOLY_LE);
}
u32 __pure __crc32c_le(u32 crc, unsigned char const *p, size_t len)
{
return crc32_le_generic(crc, p, len, NULL, CRC32C_POLY_LE);
}
u32 __pure crc32_le(u32 crc, unsigned char const *p, size_t len)
{
return crc32_le_generic(crc, p, len,
(const u32 (*)[256])crc32table_le, CRCPOLY_LE);
}
u32 __pure __crc32c_le(u32 crc, unsigned char const *p, size_t len)
{
return crc32_le_generic(crc, p, len,
(const u32 (*)[256])crc32ctable_le, CRC32C_POLY_LE);
}
static u32 __attribute_const__ gf2_multiply(u32 x, u32 y, u32 modulus)
{
u32 product = x & 1 ? y : 0;
int i;
for (i = 0; i < 31; i++) {
product = (product >> 1) ^ (product & 1 ? modulus : 0);
x >>= 1;
product ^= x & 1 ? y : 0;
}
return product;
}
static u32 __attribute_const__ crc32_generic_shift(u32 crc, size_t len,
u32 polynomial)
{
u32 power = polynomial;
int i;
for (i = 0; i < 8 * (int)(len & 3); i++)
crc = (crc >> 1) ^ (crc & 1 ? polynomial : 0);
len >>= 2;
if (!len)
return crc;
for (;;) {
if (len & 1)
crc = gf2_multiply(crc, power, polynomial);
len >>= 1;
if (!len)
break;
power = gf2_multiply(power, power, polynomial);
}
return crc;
}
u32 __attribute_const__ crc32_le_shift(u32 crc, size_t len)
{
return crc32_generic_shift(crc, len, CRCPOLY_LE);
}
u32 __attribute_const__ __crc32c_le_shift(u32 crc, size_t len)
{
return crc32_generic_shift(crc, len, CRC32C_POLY_LE);
}
u32 __pure crc32_be(u32 crc, unsigned char const *p, size_t len)
{
return crc32_be_generic(crc, p, len, NULL, CRCPOLY_BE);
}
u32 __pure crc32_be(u32 crc, unsigned char const *p, size_t len)
{
return crc32_be_generic(crc, p, len,
(const u32 (*)[256])crc32table_be, CRCPOLY_BE);
}
