unsigned int __bswapsi2(unsigned int u)\r\n{\r\nreturn (((u) & 0xff000000) >> 24) |\r\n(((u) & 0x00ff0000) >> 8) |\r\n(((u) & 0x0000ff00) << 8) |\r\n(((u) & 0x000000ff) << 24);\r\n}
