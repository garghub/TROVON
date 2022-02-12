guint16 crc11_307_noreflect_noxor(const guint8 *data, guint64 data_len)
{
guint16 crc = 0;
guint tbl_idx;
while (data_len--) {
tbl_idx = ((crc >> 3) ^ *data) & 0xff;
crc = (crc11_table_307_noreflect_noxor[tbl_idx] ^ (crc << 8)) & 0x7ff;
data++;
}
return crc & 0x7ff;
}
