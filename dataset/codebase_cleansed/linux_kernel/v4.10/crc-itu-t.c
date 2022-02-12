u16 crc_itu_t(u16 crc, const u8 *buffer, size_t len)
{
while (len--)
crc = crc_itu_t_byte(crc, *buffer++);
return crc;
}
