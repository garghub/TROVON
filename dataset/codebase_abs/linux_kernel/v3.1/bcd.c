unsigned F_1 ( unsigned char V_1 )\r\n{\r\nreturn ( V_1 & 0x0f ) + ( V_1 >> 4 ) * 10 ;\r\n}\r\nunsigned char F_2 ( unsigned V_1 )\r\n{\r\nreturn ( ( V_1 / 10 ) << 4 ) + V_1 % 10 ;\r\n}
