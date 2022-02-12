u8 crc7_be(u8 crc, const u8 *buffer, size_t len)
{
while (len--)
crc = crc7_be_byte(crc, *buffer++);
return crc;
}
