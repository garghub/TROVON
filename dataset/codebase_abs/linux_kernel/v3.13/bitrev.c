T_1 F_1 ( T_1 V_1 )\r\n{\r\nreturn ( F_2 ( V_1 & 0xff ) << 8 ) | F_2 ( V_1 >> 8 ) ;\r\n}\r\nT_2 F_3 ( T_2 V_1 )\r\n{\r\nreturn ( F_1 ( V_1 & 0xffff ) << 16 ) | F_1 ( V_1 >> 16 ) ;\r\n}
