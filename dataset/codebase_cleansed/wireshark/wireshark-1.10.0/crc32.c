guint32
crc32c_table_lookup (guchar pos)
{
return crc32c_table[pos];
}
guint32
crc32_ccitt_table_lookup (guchar pos)
{
return crc32_ccitt_table[pos];
}
guint32
crc32c_calculate(const void *buf, int len, guint32 crc)
{
const guint8 *p = (const guint8 *)buf;
crc = CRC32C_SWAP(crc);
while (len-- > 0) {
CRC32C(crc, *p++);
}
return CRC32C_SWAP(crc);
}
guint32
crc32c_calculate_no_swap(const void *buf, int len, guint32 crc)
{
const guint8 *p = (const guint8 *)buf;
while (len-- > 0) {
CRC32C(crc, *p++);
}
return crc;
}
guint32
crc32_ccitt(const guint8 *buf, guint len)
{
return (crc32_ccitt_seed(buf, len, CRC32_CCITT_SEED));
}
guint32
crc32_ccitt_seed(const guint8 *buf, guint len, guint32 seed)
{
guint i;
guint32 crc32 = seed;
for (i = 0; i < len; i++)
crc32 = crc32_ccitt_table[(crc32 ^ buf[i]) & 0xff] ^ (crc32 >> 8);
return ( ~crc32 );
}
guint32
crc32_mpeg2_seed(const guint8 *buf, guint len, guint32 seed)
{
guint i;
guint32 crc32;
crc32 = seed;
for (i = 0; i < len; i++)
crc32 = (crc32 << 8) ^ crc32_mpeg2_table[((crc32 >> 24) ^ buf[i]) & 0xff];
return ( crc32 );
}
