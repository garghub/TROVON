u8 crc7(u8 crc, const u8 *buffer, size_t len)
{
while (len--)
crc = crc7_byte(crc, *buffer++);
return crc;
}
