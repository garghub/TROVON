u16 crc_itu_t(u16 crc, const u8 *buffer, size_t len)\r\n{\r\nwhile (len--)\r\ncrc = crc_itu_t_byte(crc, *buffer++);\r\nreturn crc;\r\n}
