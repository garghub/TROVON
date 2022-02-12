guint8 crc7update(guint8 crc, const unsigned char *data, int data_len)
{
unsigned int tbl_idx;
while (data_len--) {
tbl_idx = ((crc >> 0) ^ *data) & 0xff;
crc = (crc_table[tbl_idx] ^ (crc << (8 - 1))) & (0x7f << 1);
data++;
}
return crc & (0x7f << 1);
}
