int F_1 ( T_1 * V_1 , unsigned char * * V_2 )\r\n{\r\nint V_3 , V_4 = 0 ;\r\nF_2 ( V_1 ) ;\r\nV_3 = F_3 ( V_1 -> type ) ;\r\nF_4 ( V_1 -> type , V_5 ) ;\r\nswitch ( V_3 ) {\r\ncase V_6 :\r\nF_5 ( V_1 -> V_7 . V_8 ,\r\nV_9 , 0 , V_4 ) ;\r\nbreak;\r\ncase V_10 :\r\nF_5 ( V_1 -> V_7 . V_11 ,\r\nV_9 , 0 , V_4 ) ;\r\nbreak;\r\ncase V_12 :\r\nF_5 ( V_1 -> V_7 . V_13 ,\r\nV_14 , 0 , V_4 ) ;\r\nbreak;\r\ndefault:\r\nF_5 ( V_1 -> V_7 . V_15 ,\r\nV_16 , 0 , V_4 ) ;\r\nbreak;\r\n}\r\nF_6 () ;\r\nF_7 ( V_1 -> type , V_5 ) ;\r\nswitch ( V_3 ) {\r\ncase V_6 :\r\nF_8 ( V_1 -> V_7 . V_8 ,\r\nV_9 , 0 , V_4 ) ;\r\nbreak;\r\ncase V_10 :\r\nF_8 ( V_1 -> V_7 . V_11 ,\r\nV_9 , 0 , V_4 ) ;\r\nbreak;\r\ncase V_12 :\r\nF_8 ( V_1 -> V_7 . V_13 ,\r\nV_14 , 0 , V_4 ) ;\r\nbreak;\r\ndefault:\r\nF_8 ( V_1 -> V_7 . V_15 , V_16 , 0 , V_4 ) ;\r\nbreak;\r\n}\r\nF_9 () ;\r\n}\r\nT_1 * F_10 ( void )\r\n{\r\nT_1 * V_17 = NULL ;\r\nT_2 V_18 ;\r\nF_11 ( V_17 , T_1 ) ;\r\nV_17 -> type = NULL ;\r\nV_17 -> V_7 . V_15 = NULL ;\r\nreturn ( V_17 ) ;\r\nF_12 ( V_19 ) ;\r\n}\r\nT_1 * F_13 ( T_1 * * V_1 , unsigned char * * V_2 ,\r\nlong V_20 )\r\n{\r\nint V_3 ;\r\nF_14 ( V_1 , T_1 * , F_10 ) ;\r\nF_15 () ;\r\nF_16 () ;\r\nF_17 ( V_17 -> type , V_21 ) ;\r\nV_3 = F_3 ( V_17 -> type ) ;\r\nswitch ( V_3 ) {\r\ncase V_6 :\r\nF_18 ( V_17 -> V_7 . V_8 ,\r\nV_22 , 0 ) ;\r\nbreak;\r\ncase V_10 :\r\nF_18 ( V_17 -> V_7 . V_11 ,\r\nV_22 , 0 ) ;\r\nbreak;\r\ncase V_12 :\r\nF_18 ( V_17 -> V_7 . V_13 ,\r\nV_23 , 0 ) ;\r\nbreak;\r\ndefault:\r\nF_18 ( V_17 -> V_7 . V_15 ,\r\nV_24 , 0 ) ;\r\nbreak;\r\n}\r\nF_19 ( V_1 , V_25 , V_26 ) ;\r\n}\r\nvoid V_25 ( T_1 * V_1 )\r\n{\r\nif ( V_1 == NULL ) return;\r\nswitch ( F_3 ( V_1 -> type ) ) {\r\ncase V_6 :\r\nF_20 ( V_1 -> V_7 . V_8 ) ;\r\nbreak;\r\ncase V_10 :\r\nF_20 ( V_1 -> V_7 . V_11 ) ;\r\nbreak;\r\ncase V_12 :\r\nF_21 ( V_1 -> V_7 . V_13 ) ;\r\nbreak;\r\ndefault:\r\nF_22 ( V_1 -> V_7 . V_15 ) ;\r\nbreak;\r\n}\r\nF_23 ( V_1 -> type ) ;\r\nFree ( ( char * ) V_1 ) ;\r\n}
