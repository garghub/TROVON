static int F_1 ( T_1 V_1 , const char * V_2 , int V_3 )\r\n{\r\nint V_4 ;\r\nfor ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )\r\nF_2 ( V_2 [ V_4 ] ) ;\r\nreturn V_4 ;\r\n}\r\nstatic int F_3 ( T_1 V_1 , char * V_2 , int V_3 )\r\n{\r\nint V_4 , V_5 ;\r\nif ( ! V_6 )\r\nreturn 0 ;\r\nfor ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {\r\nif ( ( V_5 = V_6 () ) == - 1 )\r\nbreak;\r\nV_2 [ V_4 ] = V_5 ;\r\n}\r\nreturn V_4 ;\r\n}\r\nstatic int T_2 F_4 ( void )\r\n{\r\nstruct V_7 * V_8 ;\r\nF_5 ( V_9 ) ;\r\nV_8 = F_6 ( 0 , V_10 , & V_11 , 16 ) ;\r\nif ( F_7 ( V_8 ) )\r\nreturn F_8 ( V_8 ) ;\r\nV_9 = V_8 ;\r\nreturn 0 ;\r\n}\r\nstatic void T_3 F_9 ( void )\r\n{\r\nif ( V_9 )\r\nF_10 ( V_9 ) ;\r\n}\r\nstatic int T_2 F_11 ( void )\r\n{\r\nF_12 ( 0 , 0 , & V_11 ) ;\r\nF_13 ( L_1 , 0 , NULL ) ;\r\nreturn 0 ;\r\n}
