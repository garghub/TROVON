guint16 update_crc10_by_bytes(guint16 crc10, const guint8 *data_blk_ptr,
int data_blk_size)
{
register int i;
guint16 crc10_accum = 0;
for (i = 0; i < data_blk_size; i++) {
crc10_accum = ((crc10_accum << 8) & 0x3ff)
^ byte_crc10_table[( crc10_accum >> 2) & 0xff]
^ *data_blk_ptr++;
}
crc10_accum = ((crc10_accum << 8) & 0x3ff)
^ byte_crc10_table[( crc10_accum >> 2) & 0xff]
^ (crc10>>2);
crc10_accum = ((crc10_accum << 8) & 0x3ff)
^ byte_crc10_table[( crc10_accum >> 2) & 0xff]
^ ((crc10<<6) & 0xFF);
return crc10_accum;
}
