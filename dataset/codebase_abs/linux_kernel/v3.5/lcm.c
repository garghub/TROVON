unsigned long F_1 ( unsigned long V_1 , unsigned long V_2 )\r\n{\r\nif ( V_1 && V_2 )\r\nreturn ( V_1 * V_2 ) / F_2 ( V_1 , V_2 ) ;\r\nelse if ( V_2 )\r\nreturn V_2 ;\r\nreturn V_1 ;\r\n}
