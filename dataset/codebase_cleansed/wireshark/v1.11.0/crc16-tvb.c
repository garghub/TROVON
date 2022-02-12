guint16 crc16_ccitt_tvb(tvbuff_t *tvb, guint len)
{
const guint8 *buf;
tvb_ensure_bytes_exist(tvb, 0, len);
buf = tvb_get_ptr(tvb, 0, len);
return crc16_ccitt(buf, len);
}
guint16 crc16_x25_ccitt_tvb(tvbuff_t *tvb, guint len)
{
const guint8 *buf;
tvb_ensure_bytes_exist(tvb, 0, len);
buf = tvb_get_ptr(tvb, 0, len);
return crc16_x25_ccitt(buf, len);
}
guint16 crc16_ccitt_tvb_offset(tvbuff_t *tvb, guint offset, guint len)
{
const guint8 *buf;
tvb_ensure_bytes_exist(tvb, offset, len);
buf = tvb_get_ptr(tvb, offset, len);
return crc16_ccitt(buf, len);
}
guint16 crc16_ccitt_tvb_seed(tvbuff_t *tvb, guint len, guint16 seed)
{
const guint8 *buf;
tvb_ensure_bytes_exist(tvb, 0, len);
buf = tvb_get_ptr(tvb, 0, len);
return crc16_ccitt_seed(buf, len, seed);
}
guint16 crc16_ccitt_tvb_offset_seed(tvbuff_t *tvb, guint offset, guint len, guint16 seed)
{
const guint8 *buf;
tvb_ensure_bytes_exist(tvb, offset, len);
buf = tvb_get_ptr(tvb, offset, len);
return crc16_ccitt_seed(buf, len, seed);
}
guint16 crc16_plain_tvb_offset(tvbuff_t *tvb, guint offset, guint len)
{
guint16 crc = crc16_plain_init();
const guint8 *buf;
tvb_ensure_bytes_exist(tvb, offset, len);
buf = tvb_get_ptr(tvb, offset, len);
crc = crc16_plain_update(crc, buf, len);
return crc16_plain_finalize(crc);
}
guint16 crc16_plain_tvb_offset_seed(tvbuff_t *tvb, guint offset, guint len, guint16 crc)
{
const guint8 *buf;
tvb_ensure_bytes_exist(tvb, offset, len);
buf = tvb_get_ptr(tvb, offset, len);
crc = crc16_plain_update(crc, buf, len);
return crc16_plain_finalize(crc);
}
