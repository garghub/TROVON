void bitswap_buf_inplace(guint8 *buf, size_t len)\r\n{\r\nsize_t i;\r\nfor (i = 0; i < len; i++)\r\nbuf[i] = swaptab[buf[i]];\r\n}
