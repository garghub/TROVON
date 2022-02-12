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
guint16 crc6_compute(const guint8 *data_blk_ptr, int data_blk_size)
{
guint16 h;
int byteIndex;
h = 0;
byteIndex = 0;
if(data_blk_size == 0)
{
return 0;
}
do
{
h = (h << 8) | data_blk_ptr[byteIndex];
h = crc6_table[h];
byteIndex++;
}
while(byteIndex < data_blk_size);
return h;
}
