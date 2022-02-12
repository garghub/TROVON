unsigned _bcd2bin(unsigned char val)\r\n{\r\nreturn (val & 0x0f) + (val >> 4) * 10;\r\n}\r\nunsigned char _bin2bcd(unsigned val)\r\n{\r\nreturn ((val / 10) << 4) + val % 10;\r\n}
