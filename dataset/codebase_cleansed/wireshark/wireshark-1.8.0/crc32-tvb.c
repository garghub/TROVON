guint32
crc32_ccitt_tvb(tvbuff_t *tvb, guint len)
{
const guint8* buf;
tvb_ensure_bytes_exist(tvb, 0, len);
buf = tvb_get_ptr(tvb, 0, len);
return ( crc32_ccitt_seed(buf, len, CRC32_CCITT_SEED) );
}
guint32
crc32_ccitt_tvb_offset(tvbuff_t *tvb, guint offset, guint len)
{
const guint8* buf;
tvb_ensure_bytes_exist(tvb, offset, len);
buf = tvb_get_ptr(tvb, offset, len);
return ( crc32_ccitt(buf, len) );
}
guint32
crc32_ccitt_tvb_seed(tvbuff_t *tvb, guint len, guint32 seed)
{
const guint8* buf;
tvb_ensure_bytes_exist(tvb, 0, len);
buf = tvb_get_ptr(tvb, 0, len);
return ( crc32_ccitt_seed(buf, len, seed) );
}
guint32
crc32_ccitt_tvb_offset_seed(tvbuff_t *tvb, guint offset, guint len,
guint32 seed)
{
const guint8* buf;
tvb_ensure_bytes_exist(tvb, offset, len);
buf = tvb_get_ptr(tvb, offset, len);
return ( crc32_ccitt_seed(buf, len, seed) );
}
guint32
crc32_802_tvb(tvbuff_t *tvb, guint len)
{
guint32 c_crc;
c_crc = crc32_ccitt_tvb(tvb, len);
c_crc = ((unsigned char)(c_crc>>0)<<24) |
((unsigned char)(c_crc>>8)<<16) |
((unsigned char)(c_crc>>16)<<8) |
((unsigned char)(c_crc>>24)<<0);
return ( c_crc );
}
guint32
crc32_mpeg2_tvb_offset_seed(tvbuff_t *tvb, guint offset,
guint len, guint32 seed)
{
const guint8* buf;
tvb_ensure_bytes_exist(tvb, offset, len);
buf = tvb_get_ptr(tvb, offset, len);
return ( crc32_mpeg2_seed(buf, len, seed) );
}
guint32
crc32_mpeg2_tvb(tvbuff_t *tvb, guint len)
{
return ( crc32_mpeg2_tvb_offset_seed(tvb, 0, len, CRC32_MPEG2_SEED) );
}
guint32
crc32_mpeg2_tvb_offset(tvbuff_t *tvb, guint offset, guint len)
{
return ( crc32_mpeg2_tvb_offset_seed(tvb, offset, len, CRC32_MPEG2_SEED) );
}
guint32
crc32_mpeg2_tvb_seed(tvbuff_t *tvb, guint len, guint32 seed)
{
return ( crc32_mpeg2_tvb_offset_seed(tvb, 0, len, seed) );
}
