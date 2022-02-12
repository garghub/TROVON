void wimax_mac_gen_crc32_table(void)
{
guint32 index, bit;
guint32 crc;
for ( index = 0; index < G_N_ELEMENTS(crc32_table); index++ )
{
crc = ( index << 24 );
for ( bit = 0; bit < 8; bit++ )
{
if ( crc & 0x80000000U )
crc = ( crc << 1 ) ^ WMAX_MAC_CRC32_POLYNOMIAL;
else
crc = ( crc << 1 );
}
crc32_table[index] = crc;
}
}
void wimax_mac_gen_crc8_table(void)
{
guint index, bit;
guint8 crc;
for ( index = 0; index < G_N_ELEMENTS(crc8_table); index++ )
{
crc = index;
for ( bit = 0; bit < 8; bit++ )
{
if ( crc & 0x80 )
crc = ( crc << 1 ) ^ WMAX_MAC_CRC8_POLYNOMIAL;
else
crc = ( crc << 1 );
}
crc8_table[index] = crc;
}
}
guint32 wimax_mac_calc_crc32(const guint8 *data, guint data_len)
{
guint32 crc=CRC32_INITIAL_VALUE;
guint i, j;
for ( j = 0; j < data_len; j++ )
{
i = ( (guint8)(crc>>24) ^ data[j] ) & 0xff;
crc = ( crc<<8 ) ^ crc32_table[i];
}
return ~crc;
}
guint16 wimax_mac_calc_crc16(const guint8 *data, guint data_len)
{
guint32 crc=CRC16_INITIAL_VALUE;
guint j;
for ( j = 0; j < data_len; j++ )
{
crc ^= data[j] << 8;
crc = (crc << 8) ^ crc16_table[(crc & 0xff00) >> 8];
}
crc ^= 0xFFFF;
crc &= 0xFFFF;
return crc;
}
guint8 wimax_mac_calc_crc8(const guint8 *data, guint data_len)
{
guint8 crc=0;
guint i;
for(i = 0; i < data_len; i++)
{
crc = crc8_table[data[i]^crc];
}
return crc;
}
