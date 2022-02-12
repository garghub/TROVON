u16 crc_ccitt(u16 crc, u8 const *buffer, size_t len)\r\n{\r\nwhile (len--)\r\ncrc = crc_ccitt_byte(crc, *buffer++);\r\nreturn crc;\r\n}
