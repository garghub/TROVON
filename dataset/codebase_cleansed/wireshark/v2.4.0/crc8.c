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
guint8 crc8_0x37(guint8 *buf, guint32 len, guint8 seed)
{
guint8 crc = seed;
while (len-- > 0)
{
crc = crc8_precompiled_37[(crc ^ *buf++)];
}
return (crc);
}
guint8 crc8_0x3B(guint8 *buf, guint32 len, guint8 seed)
{
guint8 crc = seed;
while (len-- > 0)
{
crc = crc8_precompiled_3b[(crc ^ *buf++)];
}
return (crc);
}
