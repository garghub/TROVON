void F_1 ( void )\r\n{\r\nstatic int V_1 = 1 ;\r\nif ( V_1 )\r\n{\r\nV_1 = 0 ;\r\n#ifndef F_2\r\nF_3 ( V_2 , V_3 ) ;\r\nF_3 ( V_2 , V_4 ) ;\r\n#endif\r\n}\r\n}
