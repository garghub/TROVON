u8 crc7_be(u8 crc, const u8 *buffer, size_t len)\r\n{\r\nwhile (len--)\r\ncrc = crc7_be_byte(crc, *buffer++);\r\nreturn crc;\r\n}
