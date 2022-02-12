guint16 update_crc6_by_bytes(guint16 crc6, guint8 byte1, guint8 byte2) {
int bit;
guint32 remainder = ( byte1<<8 | byte2 ) << 6;
guint32 polynomial = 0x6F << 15;
for (bit = 15;
bit >= 0;
--bit)
{
if (remainder & (0x40 << bit))
{
remainder ^= polynomial;
}
polynomial >>= 1;
}
return (guint16)(remainder ^ crc6);
}
