u16 bitrev16(u16 x)\r\n{\r\nreturn (bitrev8(x & 0xff) << 8) | bitrev8(x >> 8);\r\n}\r\nu32 bitrev32(u32 x)\r\n{\r\nreturn (bitrev16(x & 0xffff) << 16) | bitrev16(x >> 16);\r\n}
