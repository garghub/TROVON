static void F_1 ( T_1 * V_1 , T_1 * V_2 )\r\n{\r\nT_1 V_3 ;\r\nint V_4 ;\r\nint V_5 ;\r\nint V_6 ;\r\nV_3 = F_2 ( V_7 ) ;\r\n* V_2 = ( V_3 & 0xFFFF ) * 4 ;\r\n* V_1 = ( ( V_3 >> 16 ) & 0xFFFF ) * 4 ;\r\nV_4 = F_2 ( V_8 ) ;\r\nF_3 ( L_1 , V_9 , V_4 / 10 , V_4 % 10 ) ;\r\nif ( V_4 >= 26 ) {\r\nV_5 = F_4 ( V_10 ) ;\r\nV_5 |= F_4 ( V_11 ) ;\r\nV_6 = F_4 ( V_12 ) ;\r\nV_6 |= F_4 ( V_13 ) ;\r\n* V_2 |= ( V_5 << 1 ) | V_6 ;\r\nV_5 = F_4 ( V_14 ) ;\r\nV_5 |= F_4 ( V_15 ) ;\r\nV_6 = F_4 ( V_16 ) ;\r\nV_6 |= F_4 ( V_17 ) ;\r\n* V_1 |= ( V_5 << 1 ) | V_6 ;\r\n} else {\r\n* V_2 |= 0x3 ;\r\n* V_1 |= 0x3 ;\r\n}\r\n}\r\nstatic void F_5 ( int V_18 , int V_19 )\r\n{\r\nswitch ( V_18 ) {\r\ncase V_20 :\r\nV_21 = 0 ;\r\nV_22 = 0 ;\r\nV_23 = V_24 ;\r\nbreak;\r\ncase V_25 :\r\ncase V_26 :\r\nswitch ( V_19 ) {\r\ncase 0x87 :\r\ncase 0x82 :\r\nV_21 = 1 ;\r\nV_22 = 1 ;\r\nV_23 = V_27 ;\r\nbreak;\r\ncase 0x81 :\r\nswitch ( V_28 ) {\r\ncase 1 :\r\nV_21 = 2 ;\r\nV_22 = 2 ;\r\nV_23 = V_29 ;\r\nbreak;\r\ncase 2 :\r\nV_21 = 4 ;\r\nV_22 = 1 ;\r\nV_23 = V_30 ;\r\nbreak;\r\ndefault:\r\nF_6 ( L_2 , V_28 ) ;\r\nF_7 () ;\r\nbreak;\r\n}\r\nbreak;\r\ncase 0x80 :\r\nswitch ( V_28 ) {\r\ncase 1 :\r\nV_21 = 5 ;\r\nV_22 = 2 ;\r\nV_23 = V_31 ;\r\nbreak;\r\ncase 2 :\r\nV_21 = 6 ;\r\nV_22 = 2 ;\r\nV_23 = V_32 ;\r\nbreak;\r\ndefault:\r\nF_6 ( L_2 , V_28 ) ;\r\nF_7 () ;\r\nbreak;\r\n}\r\nbreak;\r\ncase 0x83 :\r\nswitch ( V_28 ) {\r\ncase 1 :\r\nV_21 = 7 ;\r\nV_22 = 1 ;\r\nV_23 = V_33 ;\r\nbreak;\r\ncase 2 :\r\nV_21 = 3 ;\r\nV_22 = 2 ;\r\nV_23 = V_34 ;\r\nbreak;\r\ndefault:\r\nF_6 ( L_2 , V_28 ) ;\r\nF_7 () ;\r\nbreak;\r\n}\r\nbreak;\r\ncase 0x8F :\r\nV_21 = 8 ;\r\nV_22 = 1 ;\r\nV_23 = V_35 ;\r\nbreak;\r\ncase 0x08 :\r\nV_21 = 1 ;\r\nV_22 = 1 ;\r\nV_23 = V_36 ;\r\nbreak;\r\ncase 0x02 :\r\nV_21 = 2 ;\r\nV_22 = 2 ;\r\nV_23 = V_37 ;\r\nbreak;\r\ncase 0x04 :\r\nV_21 = 3 ;\r\nV_22 = 2 ;\r\nV_23 = V_38 ;\r\nbreak;\r\ncase 0 :\r\nswitch ( V_28 ) {\r\ncase 1 :\r\nV_21 = 2 ;\r\nV_22 = 2 ;\r\nV_23 = V_29 ;\r\nbreak;\r\ncase 2 :\r\nV_21 = 3 ;\r\nV_22 = 2 ;\r\nV_23 = V_34 ;\r\nbreak;\r\ndefault:\r\nF_6 ( L_2 , V_28 ) ;\r\nF_7 () ;\r\nbreak;\r\n}\r\nbreak;\r\ndefault:\r\nF_8 ( L_3 , V_19 ) ;\r\nV_21 = 0 ;\r\nV_22 = 0 ;\r\nV_23 = V_24 ;\r\nbreak;\r\n}\r\nbreak;\r\ndefault:\r\nF_8 ( L_4 , V_18 ) ;\r\nV_21 = 0 ;\r\nV_22 = 0 ;\r\nV_23 = V_24 ;\r\nbreak;\r\n}\r\n}\r\nvoid F_9 ( void )\r\n{\r\nT_1 V_39 ;\r\nT_1 V_40 ;\r\nint V_41 ;\r\nF_10 ( F_11 ( V_42 ) !=\r\nV_43 ) ;\r\nF_10 ( F_11 ( V_44 ) !=\r\nV_43 ) ;\r\nV_28 = F_2 ( V_45 ) & 0x0F ;\r\nF_5 ( V_46 , V_47 ) ;\r\nF_1 ( & V_39 , & V_40 ) ;\r\nF_12 ( L_5 , V_9 , V_39 ) ;\r\nF_12 ( L_6 , V_9 , V_40 ) ;\r\nfor ( V_41 = 0 ; V_41 < V_48 ; V_41 ++ ) {\r\nif ( V_39 < V_42 [ V_23 ] [ V_41 ] )\r\nbreak;\r\n}\r\nV_49 = V_41 - 1 ;\r\nif ( V_49 == - 1 ) {\r\nF_8 ( L_7 ,\r\nV_39 ) ;\r\nV_49 = 0 ;\r\nV_21 = 1 ;\r\n}\r\nfor ( V_41 = 0 ; V_41 < V_50 ; V_41 ++ ) {\r\nif ( V_40 < V_44 [ V_23 ] [ V_41 ] )\r\nbreak;\r\n}\r\nV_51 = V_41 - 1 ;\r\nif ( V_51 == - 1 ) {\r\nF_8 ( L_8 ,\r\nV_40 ) ;\r\nV_51 = 0 ;\r\nV_22 = 1 ;\r\n}\r\nF_3 ( L_9 ,\r\nV_21 , V_22 ) ;\r\n}
