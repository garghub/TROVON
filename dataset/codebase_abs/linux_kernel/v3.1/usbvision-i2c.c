static inline int F_1 ( struct V_1 * V_2 ,\r\nunsigned char V_3 , int V_4 )\r\n{\r\nstruct V_5 * V_6 ;\r\nint V_7 , V_8 = - 1 ;\r\nchar V_9 [ 4 ] ;\r\nV_6 = (struct V_5 * ) F_2 ( V_2 ) ;\r\nV_9 [ 0 ] = 0x00 ;\r\nfor ( V_7 = 0 ; V_7 <= V_4 ; V_7 ++ ) {\r\nV_8 = ( F_3 ( V_6 , V_3 , V_9 , 1 ) ) ;\r\nif ( V_8 == 1 )\r\nbreak;\r\nF_4 ( 5 ) ;\r\nif ( V_7 == V_4 )\r\nbreak;\r\nF_4 ( 10 ) ;\r\n}\r\nif ( V_7 ) {\r\nF_5 ( V_10 , L_1 , V_7 , V_3 ) ;\r\nF_5 ( V_10 , L_2 ) ;\r\n}\r\nreturn V_8 ;\r\n}\r\nstatic inline int F_6 ( struct V_1 * V_2 ,\r\nunsigned char V_3 , int V_4 )\r\n{\r\nstruct V_5 * V_6 ;\r\nint V_7 , V_8 = - 1 ;\r\nchar V_9 [ 4 ] ;\r\nV_6 = (struct V_5 * ) F_2 ( V_2 ) ;\r\nfor ( V_7 = 0 ; V_7 <= V_4 ; V_7 ++ ) {\r\nV_8 = ( F_7 ( V_6 , V_3 , V_9 , 1 ) ) ;\r\nif ( V_8 == 1 )\r\nbreak;\r\nF_4 ( 5 ) ;\r\nif ( V_7 == V_4 )\r\nbreak;\r\nF_4 ( 10 ) ;\r\n}\r\nif ( V_7 ) {\r\nF_5 ( V_10 , L_1 , V_7 , V_3 ) ;\r\nF_5 ( V_10 , L_2 ) ;\r\n}\r\nreturn V_8 ;\r\n}\r\nstatic inline int F_8 ( struct V_1 * V_2 ,\r\nstruct V_11 * V_12 , int V_4 ,\r\nunsigned char * V_13 )\r\n{\r\nunsigned short V_14 = V_12 -> V_14 ;\r\nunsigned char V_3 ;\r\nint V_8 ;\r\nif ( ( V_14 & V_15 ) ) {\r\nV_3 = 0xf0 | ( ( V_12 -> V_3 >> 7 ) & 0x03 ) ;\r\nV_8 = F_1 ( V_2 , V_3 , V_4 ) ;\r\nif ( V_8 != 1 ) {\r\nF_9 ( & V_2 -> V_16 ,\r\nL_3 ) ;\r\nreturn - V_17 ;\r\n}\r\nV_13 [ 0 ] = V_3 ;\r\nif ( V_14 & V_18 ) {\r\nV_3 |= 0x01 ;\r\nV_8 = F_6 ( V_2 , V_3 , V_4 ) ;\r\nif ( V_8 != 1 ) {\r\nF_9 ( & V_2 -> V_16 ,\r\nL_4 ) ;\r\nreturn - V_17 ;\r\n}\r\n}\r\n} else {\r\nV_3 = ( V_12 -> V_3 << 1 ) ;\r\nif ( V_14 & V_18 )\r\nV_3 |= 1 ;\r\nV_13 [ 0 ] = V_3 ;\r\nif ( V_14 & V_18 )\r\nV_8 = F_6 ( V_2 , V_3 , V_4 ) ;\r\nelse\r\nV_8 = F_1 ( V_2 , V_3 , V_4 ) ;\r\nif ( V_8 != 1 )\r\nreturn - V_17 ;\r\n}\r\nreturn 0 ;\r\n}\r\nstatic int\r\nF_10 ( struct V_1 * V_2 , struct V_11 V_19 [] , int V_20 )\r\n{\r\nstruct V_11 * V_21 ;\r\nstruct V_5 * V_6 ;\r\nint V_7 , V_8 ;\r\nunsigned char V_3 = 0 ;\r\nV_6 = (struct V_5 * ) F_2 ( V_2 ) ;\r\nfor ( V_7 = 0 ; V_7 < V_20 ; V_7 ++ ) {\r\nV_21 = & V_19 [ V_7 ] ;\r\nV_8 = F_8 ( V_2 , V_21 , V_2 -> V_4 , & V_3 ) ;\r\nif ( V_8 != 0 ) {\r\nF_5 ( V_10 , L_5 , V_7 ) ;\r\nreturn ( V_8 < 0 ) ? V_8 : - V_17 ;\r\n}\r\nif ( V_21 -> V_14 & V_18 ) {\r\nV_8 = ( F_7 ( V_6 , V_3 , V_21 -> V_9 , V_21 -> V_22 ) ) ;\r\nif ( V_8 < V_21 -> V_22 )\r\nreturn ( V_8 < 0 ) ? V_8 : - V_17 ;\r\n} else {\r\nV_8 = ( F_3 ( V_6 , V_3 , V_21 -> V_9 , V_21 -> V_22 ) ) ;\r\nif ( V_8 < V_21 -> V_22 )\r\nreturn ( V_8 < 0 ) ? V_8 : - V_17 ;\r\n}\r\n}\r\nreturn V_20 ;\r\n}\r\nstatic T_1 F_11 ( struct V_1 * V_23 )\r\n{\r\nreturn V_24 | V_25 ;\r\n}\r\nint F_12 ( struct V_5 * V_6 )\r\n{\r\nstatic unsigned short V_26 [] = {\r\n0x4a >> 1 , 0x48 >> 1 ,\r\n0x42 >> 1 , 0x40 >> 1 ,\r\nV_27 } ;\r\nif ( V_6 -> V_28 )\r\nreturn 0 ;\r\nmemcpy ( & V_6 -> V_2 , & V_29 ,\r\nsizeof( struct V_1 ) ) ;\r\nsprintf ( V_6 -> V_2 . V_30 , L_6 , V_29 . V_30 ,\r\nV_6 -> V_16 -> V_31 -> V_32 , V_6 -> V_16 -> V_33 ) ;\r\nF_5 ( V_10 , L_7 , V_6 -> V_2 . V_30 ) ;\r\nV_6 -> V_2 . V_16 . V_34 = & V_6 -> V_16 -> V_16 ;\r\nF_13 ( & V_6 -> V_2 , & V_6 -> V_35 ) ;\r\nif ( F_14 ( V_6 , V_36 , V_37 ) < 0 ) {\r\nF_15 ( V_38 L_8 ) ;\r\nreturn - V_39 ;\r\n}\r\nF_5 ( V_10 , L_9 ) ;\r\nF_5 ( V_10 , L_10 ) ;\r\nV_6 -> V_2 . V_40 = & V_41 ;\r\nV_6 -> V_2 . V_42 = 100 ;\r\nV_6 -> V_2 . V_4 = 3 ;\r\nF_16 ( & V_6 -> V_2 ) ;\r\nF_5 ( V_10 , L_11 , V_6 -> V_2 . V_30 ) ;\r\nswitch ( V_43 [ V_6 -> V_44 ] . V_45 ) {\r\ncase V_46 :\r\ncase V_47 :\r\nF_17 ( 10 ) ;\r\nF_18 ( & V_6 -> V_35 ,\r\n& V_6 -> V_2 ,\r\nL_12 , 0 , V_26 ) ;\r\nbreak;\r\n}\r\nif ( V_43 [ V_6 -> V_44 ] . V_48 == 1 ) {\r\nstruct V_49 * V_50 ;\r\nenum V_51 type ;\r\nstruct V_52 V_53 ;\r\nV_50 = F_18 ( & V_6 -> V_35 ,\r\n& V_6 -> V_2 ,\r\nL_13 , 0 , F_19 ( V_54 ) ) ;\r\ntype = V_50 ? V_55 : V_56 ;\r\nV_50 = F_18 ( & V_6 -> V_35 ,\r\n& V_6 -> V_2 ,\r\nL_13 , 0 , F_19 ( type ) ) ;\r\nif ( V_50 == NULL )\r\nreturn - V_57 ;\r\nif ( V_6 -> V_58 != - 1 ) {\r\nV_53 . V_59 = V_60 | V_61 ;\r\nV_53 . type = V_6 -> V_58 ;\r\nV_53 . V_3 = F_20 ( V_50 ) ;\r\nF_21 ( V_6 , V_48 , V_62 , & V_53 ) ;\r\n}\r\n}\r\nV_6 -> V_28 = 1 ;\r\nreturn 0 ;\r\n}\r\nint F_22 ( struct V_5 * V_6 )\r\n{\r\nif ( ! V_6 -> V_28 )\r\nreturn 0 ;\r\nF_23 ( & ( V_6 -> V_2 ) ) ;\r\nV_6 -> V_28 = 0 ;\r\nF_5 ( V_10 , L_14 , V_6 -> V_2 . V_30 ) ;\r\nreturn 0 ;\r\n}\r\nstatic int\r\nF_24 ( struct V_5 * V_6 , unsigned char V_3 ,\r\nchar * V_9 , short V_22 )\r\n{\r\nint V_63 , V_4 ;\r\nfor ( V_4 = 5 ; ; ) {\r\nV_63 = F_14 ( V_6 , V_64 , V_3 ) ;\r\nif ( V_63 < 0 )\r\nreturn V_63 ;\r\nV_63 = F_14 ( V_6 , V_65 ,\r\n( V_22 & 0x07 ) | 0x18 ) ;\r\nif ( V_63 < 0 )\r\nreturn V_63 ;\r\ndo {\r\nV_63 = F_25 ( V_6 , V_65 ) ;\r\n} while ( V_63 > 0 && ( ( V_63 & 0x10 ) != 0 ) );\r\nif ( V_63 < 0 )\r\nreturn V_63 ;\r\nif ( ( V_63 & 0x20 ) == 0 )\r\nbreak;\r\nV_63 = F_14 ( V_6 , V_65 , 0x00 ) ;\r\nif ( V_63 < 0 )\r\nreturn V_63 ;\r\nif ( -- V_4 < 0 )\r\nreturn - 1 ;\r\n}\r\nswitch ( V_22 ) {\r\ncase 4 :\r\nV_9 [ 3 ] = F_25 ( V_6 , V_66 ) ;\r\ncase 3 :\r\nV_9 [ 2 ] = F_25 ( V_6 , V_67 ) ;\r\ncase 2 :\r\nV_9 [ 1 ] = F_25 ( V_6 , V_68 ) ;\r\ncase 1 :\r\nV_9 [ 0 ] = F_25 ( V_6 , V_69 ) ;\r\nbreak;\r\ndefault:\r\nF_15 ( V_38\r\nL_15 ) ;\r\n}\r\nif ( V_70 & V_10 ) {\r\nint V_71 ;\r\nfor ( V_71 = 0 ; V_71 < V_22 ; V_71 ++ )\r\nF_5 ( V_10 , L_16 , ( unsigned char ) V_9 [ V_71 ] , V_3 ) ;\r\n}\r\nreturn V_22 ;\r\n}\r\nstatic int F_26 ( struct V_5 * V_6 ,\r\nunsigned char V_3 , const char * V_9 ,\r\nshort V_22 )\r\n{\r\nint V_63 , V_4 ;\r\nint V_7 ;\r\nunsigned char V_72 [ 6 ] ;\r\nunsigned char V_73 ;\r\nV_73 = ( V_22 & 0x07 ) | 0x10 ;\r\nV_72 [ 0 ] = V_3 ;\r\nV_72 [ 1 ] = V_73 ;\r\nfor ( V_7 = 0 ; V_7 < V_22 ; V_7 ++ )\r\nV_72 [ V_7 + 2 ] = V_9 [ V_7 ] ;\r\nfor ( V_4 = 5 ; ; ) {\r\nV_63 = F_27 ( V_6 -> V_16 ,\r\nF_28 ( V_6 -> V_16 , 1 ) ,\r\nV_74 ,\r\nV_75 | V_76 |\r\nV_77 , 0 ,\r\n( V_78 ) V_64 , V_72 ,\r\nV_22 + 2 , V_79 ) ;\r\nif ( V_63 < 0 )\r\nreturn V_63 ;\r\nV_63 = F_14 ( V_6 , V_65 ,\r\n( V_22 & 0x07 ) | 0x10 ) ;\r\nif ( V_63 < 0 )\r\nreturn V_63 ;\r\ndo {\r\nV_63 = F_25 ( V_6 , V_65 ) ;\r\n} while ( V_63 > 0 && ( ( V_63 & 0x10 ) != 0 ) );\r\nif ( V_63 < 0 )\r\nreturn V_63 ;\r\nif ( ( V_63 & 0x20 ) == 0 )\r\nbreak;\r\nF_14 ( V_6 , V_65 , 0x00 ) ;\r\nif ( -- V_4 < 0 )\r\nreturn - 1 ;\r\n}\r\nif ( V_70 & V_10 ) {\r\nint V_71 ;\r\nfor ( V_71 = 0 ; V_71 < V_22 ; V_71 ++ )\r\nF_5 ( V_10 , L_17 , ( unsigned char ) V_9 [ V_71 ] , V_3 ) ;\r\n}\r\nreturn V_22 ;\r\n}\r\nstatic int F_3 ( struct V_5 * V_6 , unsigned char V_3 , char * V_9 ,\r\nshort V_22 )\r\n{\r\nchar * V_80 = V_9 ;\r\nint V_81 ;\r\nint V_82 = 0 ;\r\nint V_83 ;\r\nint V_84 = 4 ;\r\nwhile ( V_22 > 0 ) {\r\nV_83 = ( V_22 > V_84 ) ? V_84 : V_22 ;\r\nV_81 = F_26 ( V_6 , V_3 , V_80 , V_83 ) ;\r\nif ( V_81 > 0 ) {\r\nV_22 -= V_83 ;\r\nV_80 += V_83 ;\r\nV_82 += V_83 ;\r\n} else\r\nreturn ( V_81 < 0 ) ? V_81 : - V_85 ;\r\n}\r\nreturn V_82 ;\r\n}\r\nstatic int F_7 ( struct V_5 * V_6 , unsigned char V_3 , char * V_9 ,\r\nshort V_22 )\r\n{\r\nchar V_86 [ 4 ] ;\r\nint V_81 , V_7 ;\r\nint V_87 = 0 ;\r\nint V_83 ;\r\nwhile ( V_22 > 0 ) {\r\nV_83 = ( V_22 > 3 ) ? 4 : V_22 ;\r\nV_81 = F_24 ( V_6 , V_3 , V_86 , V_83 ) ;\r\nif ( V_81 > 0 ) {\r\nfor ( V_7 = 0 ; V_7 < V_22 ; V_7 ++ )\r\nV_9 [ V_87 + V_7 ] = V_86 [ V_7 ] ;\r\nV_22 -= V_83 ;\r\nV_87 += V_83 ;\r\n} else\r\nreturn ( V_81 < 0 ) ? V_81 : - V_85 ;\r\n}\r\nreturn V_87 ;\r\n}
