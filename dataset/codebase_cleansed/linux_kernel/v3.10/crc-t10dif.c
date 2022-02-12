__u16 crc_t10dif(const unsigned char *buffer, size_t len)
{
__u16 crc = 0;
unsigned int i;
for (i = 0 ; i < len ; i++)
crc = (crc << 8) ^ t10_dif_crc_table[((crc >> 8) ^ buffer[i]) & 0xff];
return crc;
}
