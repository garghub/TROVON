u16 crc16(u16 crc, u8 const *buffer, size_t len)\r\n{\r\nwhile (len--)\r\ncrc = crc16_byte(crc, *buffer++);\r\nreturn crc;\r\n}
