int\r\nF_1 ( int V_1 )\r\n{\r\nif ( ( V_1 != 1 ) && ( V_1 != 2 ) )\r\nV_2 |= ( 1 << ( 31 - V_1 ) ) ;\r\n#ifdef F_2\r\nF_3 ( L_1 , V_3 , V_1 , V_2 ) ;\r\n#endif\r\nreturn 0 ;\r\n}
