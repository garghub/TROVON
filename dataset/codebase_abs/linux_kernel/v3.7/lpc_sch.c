static int T_1 F_1 ( struct V_1 * V_2 ,\r\nconst struct V_3 * V_4 )\r\n{\r\nunsigned int V_5 ;\r\nunsigned short V_6 ;\r\nint V_7 ;\r\nint V_8 ;\r\nF_2 ( V_2 , V_9 , & V_5 ) ;\r\nif ( ! ( V_5 & ( 1 << 31 ) ) ) {\r\nF_3 ( & V_2 -> V_2 , L_1 ) ;\r\nreturn - V_10 ;\r\n}\r\nV_6 = ( unsigned short ) V_5 ;\r\nif ( V_6 == 0 ) {\r\nF_3 ( & V_2 -> V_2 , L_2 ) ;\r\nreturn - V_10 ;\r\n}\r\nV_11 . V_12 = V_6 ;\r\nV_11 . V_13 = V_6 + V_14 - 1 ;\r\nF_2 ( V_2 , V_15 , & V_5 ) ;\r\nif ( ! ( V_5 & ( 1 << 31 ) ) ) {\r\nF_3 ( & V_2 -> V_2 , L_3 ) ;\r\nreturn - V_10 ;\r\n}\r\nV_6 = ( unsigned short ) V_5 ;\r\nif ( V_6 == 0 ) {\r\nF_3 ( & V_2 -> V_2 , L_4 ) ;\r\nreturn - V_10 ;\r\n}\r\nV_16 . V_12 = V_6 ;\r\nif ( V_4 -> V_17 == V_18 )\r\nV_16 . V_13 = V_6 + V_19 - 1 ;\r\nelse\r\nV_16 . V_13 = V_6 + V_20 - 1 ;\r\nfor ( V_7 = 0 ; V_7 < F_4 ( V_21 ) ; V_7 ++ )\r\nV_21 [ V_7 ] . V_4 = V_4 -> V_17 ;\r\nV_8 = F_5 ( & V_2 -> V_2 , 0 ,\r\nV_21 , F_4 ( V_21 ) , NULL ,\r\n0 , NULL ) ;\r\nif ( V_8 )\r\ngoto V_22;\r\nif ( V_4 -> V_17 == V_23\r\n|| V_4 -> V_17 == V_18 ) {\r\nF_2 ( V_2 , V_24 , & V_5 ) ;\r\nif ( ! ( V_5 & ( 1 << 31 ) ) ) {\r\nF_3 ( & V_2 -> V_2 , L_5 ) ;\r\nV_8 = - V_10 ;\r\ngoto V_22;\r\n}\r\nV_6 = ( unsigned short ) V_5 ;\r\nif ( V_6 == 0 ) {\r\nF_3 ( & V_2 -> V_2 , L_6 ) ;\r\nV_8 = - V_10 ;\r\ngoto V_22;\r\n}\r\nV_25 . V_12 = V_6 ;\r\nV_25 . V_13 = V_6 + V_26 - 1 ;\r\nfor ( V_7 = 0 ; V_7 < F_4 ( V_27 ) ; V_7 ++ )\r\nV_27 [ V_7 ] . V_4 = V_4 -> V_17 ;\r\nV_8 = F_5 ( & V_2 -> V_2 , 0 , V_27 ,\r\nF_4 ( V_27 ) , NULL ,\r\n0 , NULL ) ;\r\n}\r\nreturn V_8 ;\r\nV_22:\r\nF_6 ( & V_2 -> V_2 ) ;\r\nreturn V_8 ;\r\n}\r\nstatic void T_2 F_7 ( struct V_1 * V_2 )\r\n{\r\nF_6 ( & V_2 -> V_2 ) ;\r\n}
