guint16
crc6_compute_tvb(tvbuff_t *tvb, int len)
{
const guint8 *buf;
tvb_ensure_bytes_exist(tvb, 0, len);
buf = tvb_get_ptr(tvb, 0, len);
return crc6_compute(buf, len);
}
