guint16\r\ncrc6_compute_tvb(tvbuff_t *tvb, int len)\r\n{\r\nconst guint8 *buf;\r\ntvb_ensure_bytes_exist(tvb, 0, len);\r\nbuf = tvb_get_ptr(tvb, 0, len);\r\nreturn crc6_compute(buf, len);\r\n}
