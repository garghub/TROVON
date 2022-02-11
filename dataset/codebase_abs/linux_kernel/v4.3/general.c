int F_1 ( T_1 V_1 )\r\n{\r\nint V_2 , V_3 = 0 ;\r\nfor ( V_2 = 0 ; V_2 < 32 ; V_2 ++ ) {\r\nif ( V_1 & 0x01 )\r\nV_3 ++ ;\r\nV_1 >>= 1 ;\r\n}\r\nreturn V_3 ;\r\n}
