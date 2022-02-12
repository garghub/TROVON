u8 crc7(u8 crc, const u8 *buffer, size_t len)\r\n{\r\nwhile (len--)\r\ncrc = crc7_byte(crc, *buffer++);\r\nreturn crc;\r\n}
