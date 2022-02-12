static guint16 crc16_unreflected(const guint8 *buf, guint len,
guint16 crc_in, const guint table[])
{
guint crc16 = (guint)crc_in;
while( len-- != 0 )
crc16 = table[((crc16 >> 8) ^ *buf++) & 0xff] ^ (crc16 << 8);
return (guint16)crc16;
}
static guint16 crc16_reflected(const guint8 *buf, guint len,
guint16 crc_in, const guint table[])
{
guint crc16 = (guint)crc_in;
while( len-- != 0 )
crc16 = table[(crc16 ^ *buf++) & 0xff] ^ (crc16 >> 8);
return (guint16)crc16;
}
guint16 crc16_ccitt(const guint8 *buf, guint len)
{
return crc16_reflected(buf,len,crc16_ccitt_start,crc16_ccitt_table_reverse)
^ crc16_ccitt_xorout;
}
guint16 crc16_x25_ccitt_seed(const guint8 *buf, guint len, guint16 seed)
{
return crc16_unreflected(buf,len,seed,crc16_ccitt_table);
}
guint16 crc16_ccitt_seed(const guint8 *buf, guint len, guint16 seed)
{
return crc16_reflected(buf,len,seed,crc16_ccitt_table_reverse)
^ crc16_ccitt_xorout;
}
guint16 crc16_iso14443a(const guint8 *buf, guint len)
{
return crc16_reflected(buf,len, 0x6363 ,crc16_ccitt_table_reverse);
}
guint16 crc16_0x5935(const guint8 *buf, guint32 len, guint16 seed)
{
return crc16_unreflected(buf, len, seed, crc16_precompiled_5935);
}
guint16 crc16_0x755B(const guint8 *buf, guint32 len, guint16 seed)
{
return crc16_unreflected(buf, len, seed, crc16_precompiled_755B);
}
guint16 crc16_0x9949_seed(const guint8 *buf, guint len, guint16 seed)
{
return crc16_reflected(buf, len, seed, crc16_precompiled_9949_reverse);
}
guint16 crc16_0x3D65_seed(const guint8 *buf, guint len, guint16 seed)
{
return crc16_reflected(buf, len, seed, crc16_precompiled_3D65_reverse);
}
guint16 crc16_0x080F_seed(const guint8 *buf, guint len, guint16 seed)
{
guint16 crc = seed;
if (len > 0)
{
while (len-- > 0)
{
guint8 data = *buf++;
crc = crc16_precompiled_080F[((crc >> 8) ^ data)] ^ (crc << 8);
}
}
return crc;
}
