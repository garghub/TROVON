void\r\nF_1 ( struct V_1 * V_2 , const T_1 * V_3 )\r\n{\r\nV_2 -> V_4 . V_5 . V_6 = V_7 ;\r\nV_2 -> V_4 . V_5 . type = V_8 ;\r\nV_2 -> V_4 . V_5 . V_9 = V_10 ;\r\nif ( V_2 -> V_4 . V_5 . V_11 == 0 ) {\r\nswitch ( V_2 -> V_4 . V_5 . V_12 ) {\r\ncase 5 :\r\nV_2 -> V_4 . V_5 . V_6 = V_13 ;\r\nreturn;\r\ncase 16 :\r\nV_2 -> V_4 . V_5 . type = V_14 ;\r\nreturn;\r\n}\r\n}\r\nif ( V_2 -> V_15 >= 3 ) {\r\nif ( V_3 [ 0 ] == 0xaa && V_3 [ 1 ] == 0xaa && V_3 [ 2 ] == 0x03 ) {\r\nV_2 -> V_4 . V_5 . type = V_16 ;\r\n} else if ( ( V_2 -> V_4 . V_5 . V_17 && V_2 -> V_4 . V_5 . V_17 < 16 ) ||\r\nV_2 -> V_15 < 16 ) {\r\nV_2 -> V_4 . V_5 . V_6 = V_13 ;\r\n} else if ( V_3 [ 0 ] == 0x83 || V_3 [ 0 ] == 0x81 ) {\r\nV_2 -> V_4 . V_5 . V_6 = V_13 ;\r\n} else {\r\nV_2 -> V_4 . V_5 . type = V_18 ;\r\nF_2 ( V_2 , V_3 ) ;\r\n}\r\n} else {\r\nV_2 -> V_4 . V_5 . V_6 = V_13 ;\r\n}\r\n}\r\nvoid\r\nF_2 ( struct V_1 * V_2 , const T_1 * V_3 )\r\n{\r\nif ( V_2 -> V_15 >= 2 ) {\r\nif ( V_3 [ 0 ] == 0xff && V_3 [ 1 ] == 0x00 ) {\r\nV_2 -> V_4 . V_5 . V_9 = V_19 ;\r\n} else {\r\nV_2 -> V_4 . V_5 . V_9 = V_20 ;\r\n}\r\n}\r\n}
