int F_1 ( T_1 * V_1 , const char * V_2 , int V_3 )\r\n{\r\nreturn F_2 ( V_1 , V_2 , V_3 , 0 ) ;\r\n}\r\nint F_2 ( T_1 * V_1 , const char * V_2 , int V_3 , int V_4 )\r\n{\r\nint V_5 = 0 ;\r\nchar V_6 [ 288 + 1 ] , V_7 [ 20 ] , V_8 [ 128 + 1 ] ;\r\nint V_9 , V_10 , V_11 , V_12 ;\r\nunsigned char V_13 ;\r\nint V_14 ;\r\nV_12 = 0 ;\r\n#ifdef F_3\r\nfor(; ( V_3 > 0 ) && ( ( V_2 [ V_3 - 1 ] == ' ' ) || ( V_2 [ V_3 - 1 ] == '\0' ) ) ; V_3 -- )\r\nV_12 ++ ;\r\n#endif\r\nif ( V_4 < 0 )\r\nV_4 = 0 ;\r\nif ( V_4 )\r\n{\r\nif ( V_4 > 128 ) V_4 = 128 ;\r\nmemset ( V_8 , ' ' , V_4 ) ;\r\n}\r\nV_8 [ V_4 ] = '\0' ;\r\nV_14 = F_4 ( V_4 ) ;\r\nV_11 = ( V_3 / V_14 ) ;\r\nif ( ( V_11 * V_14 ) < V_3 )\r\nV_11 ++ ;\r\nfor( V_9 = 0 ; V_9 < V_11 ; V_9 ++ )\r\n{\r\nV_6 [ 0 ] = '\0' ;\r\nstrcpy ( V_6 , V_8 ) ;\r\nsprintf ( V_7 , L_1 , V_9 * V_14 ) ;\r\nstrcat ( V_6 , V_7 ) ;\r\nfor( V_10 = 0 ; V_10 < V_14 ; V_10 ++ )\r\n{\r\nif ( ( ( V_9 * V_14 ) + V_10 ) >= V_3 )\r\n{\r\nstrcat ( V_6 , L_2 ) ;\r\n}\r\nelse\r\n{\r\nV_13 = ( ( unsigned char ) * ( V_2 + V_9 * V_14 + V_10 ) ) & 0xff ;\r\nsprintf ( V_7 , L_3 , V_13 , V_10 == 7 ? '-' : ' ' ) ;\r\nstrcat ( V_6 , V_7 ) ;\r\n}\r\n}\r\nstrcat ( V_6 , L_4 ) ;\r\nfor( V_10 = 0 ; V_10 < V_14 ; V_10 ++ )\r\n{\r\nif ( ( ( V_9 * V_14 ) + V_10 ) >= V_3 )\r\nbreak;\r\nV_13 = ( ( unsigned char ) * ( V_2 + V_9 * V_14 + V_10 ) ) & 0xff ;\r\n#ifndef F_5\r\nsprintf ( V_7 , L_5 , ( ( V_13 >= ' ' ) && ( V_13 <= '~' ) ) ? V_13 : '.' ) ;\r\n#else\r\nsprintf ( V_7 , L_5 , ( ( V_13 >= V_15 [ ' ' ] ) && ( V_13 <= V_15 [ '~' ] ) )\r\n? V_16 [ V_13 ]\r\n: '.' ) ;\r\n#endif\r\nstrcat ( V_6 , V_7 ) ;\r\n}\r\nstrcat ( V_6 , L_6 ) ;\r\nV_5 += F_6 ( V_1 , ( char * ) V_6 , strlen ( V_6 ) ) ;\r\n}\r\n#ifdef F_3\r\nif ( V_12 > 0 )\r\n{\r\nsprintf ( V_6 , L_7 , V_8 , V_3 + V_12 ) ;\r\nV_5 += F_6 ( V_1 , ( char * ) V_6 , strlen ( V_6 ) ) ;\r\n}\r\n#endif\r\nreturn ( V_5 ) ;\r\n}
