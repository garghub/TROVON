static guint8 crc8_precompiled(guint8 *buf, guint32 len, guint8 seed, const guint8 crc_table[])
{
guint8 crc;
crc = seed;
while(len-- > 0)
crc = crc_table[(guint8)(*buf++) ^ crc];
return crc;
}
guint8 crc8_0x2F(guint8 *buf, guint32 len, guint8 seed)
{
return crc8_precompiled(buf, len, seed, crc8_precompiled_2F);
}
