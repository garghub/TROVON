guint16
update_crc10_by_bytes_tvb(guint16 crc10, tvbuff_t *tvb, int offset, int len)
{
const guint8 *buf;
tvb_ensure_bytes_exist(tvb, offset, len);
buf = tvb_get_ptr(tvb, offset, len);
return update_crc10_by_bytes(crc10, buf, len);
}
