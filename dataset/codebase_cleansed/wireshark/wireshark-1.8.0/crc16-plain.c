long crc16_plain_reflect(long data, size_t data_len)
{
unsigned int i;
long ret;
ret = data & 0x01;
for (i = 1; i < data_len; i++)
{
data >>= 1;
ret = (ret << 1) | (data & 0x01);
}
return ret;
}
crc16_plain_t crc16_plain_update(crc16_plain_t crc, const unsigned char *data, size_t data_len)
{
unsigned int tbl_idx;
while (data_len--) {
tbl_idx = (crc ^ *data) & 0xff;
crc = (crc_table[tbl_idx] ^ (crc >> 8)) & 0xffff;
data++;
}
return crc & 0xffff;
}
