u16 crc16(u16 crc, u8 const *buffer, size_t len)
{
while (len--)
crc = crc16_byte(crc, *buffer++);
return crc;
}
