static int F_1 ( struct V_1 * V_2 ,\r\nunsigned long V_3 , void * V_4 )\r\n{\r\nF_2 ( 1 , V_5 + 0xb0 ) ;\r\nF_2 ( 1 , V_6 + 0x34 ) ;\r\nF_3 ( 50 ) ;\r\nF_4 ( L_1 ) ;\r\nreturn V_7 ;\r\n}\r\nstatic int F_5 ( struct V_8 * V_9 )\r\n{\r\nstruct V_10 * V_11 = V_9 -> V_12 . V_13 ;\r\nint V_14 ;\r\nV_5 = F_6 ( V_11 , 0 ) ;\r\nif ( ! V_5 ) {\r\nF_7 ( 1 , L_2 ) ;\r\nreturn - V_15 ;\r\n}\r\nV_11 = F_8 ( NULL , NULL , L_3 ) ;\r\nV_6 = F_6 ( V_11 , 0 ) ;\r\nif ( ! V_6 ) {\r\nF_9 ( V_5 ) ;\r\nF_7 ( 1 , L_4 ) ;\r\nreturn - V_15 ;\r\n}\r\nV_14 = F_10 ( & V_16 ) ;\r\nif ( V_14 )\r\nF_11 ( & V_9 -> V_12 , L_5 ,\r\nV_14 ) ;\r\nreturn V_14 ;\r\n}
