int bit1cnt_long(u32 data)\r\n{\r\nint i, cnt = 0;\r\nfor (i = 0; i < 32; i++) {\r\nif (data & 0x01)\r\ncnt++;\r\ndata >>= 1;\r\n}\r\nreturn cnt;\r\n}
