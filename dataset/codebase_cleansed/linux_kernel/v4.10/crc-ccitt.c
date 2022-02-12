u16 crc_ccitt(u16 crc, u8 const *buffer, size_t len)
{
while (len--)
crc = crc_ccitt_byte(crc, *buffer++);
return crc;
}
