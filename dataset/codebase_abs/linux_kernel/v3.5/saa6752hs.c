static inline struct V_1 * F_1 ( struct V_2 * V_3 )\r\n{\r\nreturn F_2 ( V_3 , struct V_1 , V_3 ) ;\r\n}\r\nstatic int F_3 ( struct V_4 * V_5 ,\r\nenum V_6 V_7 )\r\n{\r\nunsigned char V_8 [ 3 ] ;\r\nunsigned long V_9 ;\r\nint V_10 = 0 ;\r\nswitch( V_7 ) {\r\ncase V_11 :\r\nV_8 [ 0 ] = 0x00 ;\r\nbreak;\r\ncase V_12 :\r\nV_8 [ 0 ] = 0x03 ;\r\nbreak;\r\ncase V_13 :\r\nV_8 [ 0 ] = 0x02 ;\r\nbreak;\r\ncase V_14 :\r\nV_8 [ 0 ] = 0x04 ;\r\nbreak;\r\ncase V_15 :\r\nV_8 [ 0 ] = 0x05 ;\r\nbreak;\r\ncase V_16 :\r\nV_8 [ 0 ] = 0x06 ;\r\nbreak;\r\ncase V_17 :\r\nV_8 [ 0 ] = 0x07 ;\r\nbreak;\r\ndefault:\r\nreturn - V_18 ;\r\n}\r\nF_4 ( V_5 , V_8 , 1 ) ;\r\nV_9 = V_19 + V_20 * 3 ;\r\nfor (; ; ) {\r\nV_8 [ 0 ] = 0x10 ;\r\nF_4 ( V_5 , V_8 , 1 ) ;\r\nF_5 ( V_5 , V_8 , 1 ) ;\r\nif ( ! ( V_8 [ 0 ] & 0x20 ) )\r\nbreak;\r\nif ( F_6 ( V_19 , V_9 ) ) {\r\nV_10 = - V_21 ;\r\nbreak;\r\n}\r\nF_7 ( 10 ) ;\r\n}\r\nF_7 ( 50 ) ;\r\nreturn V_10 ;\r\n}\r\nstatic inline void F_8 ( struct V_4 * V_5 , T_1 V_22 , T_1 V_23 )\r\n{\r\nT_2 V_8 [ 2 ] ;\r\nV_8 [ 0 ] = V_22 ;\r\nV_8 [ 1 ] = V_23 ;\r\nF_4 ( V_5 , V_8 , 2 ) ;\r\n}\r\nstatic inline void F_9 ( struct V_4 * V_5 , T_1 V_22 , T_3 V_23 )\r\n{\r\nT_2 V_8 [ 3 ] ;\r\nV_8 [ 0 ] = V_22 ;\r\nV_8 [ 1 ] = V_23 >> 8 ;\r\nV_8 [ 2 ] = V_23 & 0xff ;\r\nF_4 ( V_5 , V_8 , 3 ) ;\r\n}\r\nstatic int F_10 ( struct V_4 * V_5 ,\r\nstruct V_1 * V_24 )\r\n{\r\nstruct V_25 * V_26 = & V_24 -> V_26 ;\r\nint V_27 ;\r\nint V_28 ;\r\nF_8 ( V_5 , 0x71 ,\r\nV_26 -> V_29 != V_30 ) ;\r\nif ( V_26 -> V_29 == V_30 ) {\r\nF_9 ( V_5 , 0x80 , V_26 -> V_31 ) ;\r\nF_9 ( V_5 , 0x81 , V_26 -> V_32 ) ;\r\nV_27 = V_26 -> V_32 ;\r\n} else {\r\nF_9 ( V_5 , 0x81 , V_26 -> V_31 ) ;\r\nV_27 = V_26 -> V_31 ;\r\n}\r\nF_8 ( V_5 , 0x93 ,\r\nV_26 -> V_33 == V_34 ) ;\r\nif ( V_26 -> V_33 == V_34 )\r\nV_28 = V_35 == V_26 -> V_36 ;\r\nelse\r\nV_28 = V_37 == V_26 -> V_38 ;\r\nF_8 ( V_5 , 0x94 , V_28 ) ;\r\nV_27 += V_28 ? 384 : 256 ;\r\nV_27 += 768 ;\r\nif ( V_27 > V_39 )\r\nV_27 = V_39 ;\r\nF_9 ( V_5 , 0xb1 , V_27 ) ;\r\nreturn 0 ;\r\n}\r\nstatic int F_11 ( int V_40 , struct V_25 * V_26 ,\r\nstruct V_41 * V_42 )\r\n{\r\nswitch ( V_42 -> V_43 ) {\r\ncase V_44 :\r\nV_42 -> V_45 = V_46 ;\r\nbreak;\r\ncase V_47 :\r\nV_42 -> V_45 = V_26 -> V_48 ;\r\nbreak;\r\ncase V_49 :\r\nV_42 -> V_45 = V_26 -> V_50 ;\r\nbreak;\r\ncase V_51 :\r\nV_42 -> V_45 = V_26 -> V_52 ;\r\nbreak;\r\ncase V_53 :\r\nV_42 -> V_45 = V_26 -> V_54 ;\r\nbreak;\r\ncase V_55 :\r\nV_42 -> V_45 = V_26 -> V_33 ;\r\nbreak;\r\ncase V_56 :\r\nV_42 -> V_45 = V_26 -> V_38 ;\r\nbreak;\r\ncase V_57 :\r\nif ( ! V_40 )\r\nreturn - V_18 ;\r\nV_42 -> V_45 = V_26 -> V_36 ;\r\nbreak;\r\ncase V_58 :\r\nV_42 -> V_45 = V_59 ;\r\nbreak;\r\ncase V_60 :\r\nV_42 -> V_45 = V_61 ;\r\nbreak;\r\ncase V_62 :\r\nV_42 -> V_45 = V_26 -> V_63 ;\r\nbreak;\r\ncase V_64 :\r\nV_42 -> V_45 = V_26 -> V_31 * 1000 ;\r\nbreak;\r\ncase V_65 :\r\nV_42 -> V_45 = V_26 -> V_32 * 1000 ;\r\nbreak;\r\ncase V_66 :\r\nV_42 -> V_45 = V_26 -> V_29 ;\r\nbreak;\r\ndefault:\r\nreturn - V_18 ;\r\n}\r\nreturn 0 ;\r\n}\r\nstatic int F_12 ( int V_40 , struct V_25 * V_26 ,\r\nstruct V_41 * V_42 , int V_67 )\r\n{\r\nint V_68 = 0 , V_69 ;\r\nV_69 = V_42 -> V_45 ;\r\nswitch ( V_42 -> V_43 ) {\r\ncase V_44 :\r\nV_68 = V_46 ;\r\nif ( V_67 && V_69 != V_68 )\r\nreturn - V_70 ;\r\nV_69 = V_68 ;\r\nbreak;\r\ncase V_47 :\r\nV_68 = V_26 -> V_48 ;\r\nif ( V_67 && V_69 > V_71 )\r\nreturn - V_70 ;\r\nif ( V_69 > V_71 )\r\nV_69 = V_71 ;\r\nV_26 -> V_48 = V_69 ;\r\nbreak;\r\ncase V_49 :\r\nV_68 = V_26 -> V_50 ;\r\nif ( V_67 && V_69 > V_71 )\r\nreturn - V_70 ;\r\nif ( V_69 > V_71 )\r\nV_69 = V_71 ;\r\nV_26 -> V_50 = V_69 ;\r\nbreak;\r\ncase V_51 :\r\nV_68 = V_26 -> V_52 ;\r\nif ( V_67 && V_69 > V_71 )\r\nreturn - V_70 ;\r\nif ( V_69 > V_71 )\r\nV_69 = V_71 ;\r\nV_26 -> V_52 = V_69 ;\r\nbreak;\r\ncase V_53 :\r\nV_68 = V_26 -> V_54 ;\r\nif ( V_67 && V_69 > V_71 )\r\nreturn - V_70 ;\r\nif ( V_69 > V_71 )\r\nV_69 = V_71 ;\r\nV_26 -> V_54 = V_69 ;\r\nbreak;\r\ncase V_55 :\r\nV_68 = V_26 -> V_33 ;\r\nif ( V_67 && V_69 != V_72 &&\r\n( ! V_40 || V_69 != V_34 ) )\r\nreturn - V_70 ;\r\nV_26 -> V_33 = V_69 ;\r\nbreak;\r\ncase V_56 :\r\nV_68 = V_26 -> V_38 ;\r\nif ( V_67 && V_69 != V_73 &&\r\nV_69 != V_37 )\r\nreturn - V_70 ;\r\nif ( V_69 <= V_73 )\r\nV_69 = V_73 ;\r\nelse\r\nV_69 = V_37 ;\r\nV_26 -> V_38 = V_69 ;\r\nbreak;\r\ncase V_57 :\r\nif ( ! V_40 )\r\nreturn - V_18 ;\r\nV_68 = V_26 -> V_36 ;\r\nif ( V_67 && V_69 != V_74 &&\r\nV_69 != V_35 )\r\nreturn - V_70 ;\r\nif ( V_69 <= V_74 )\r\nV_69 = V_74 ;\r\nelse\r\nV_69 = V_35 ;\r\nV_26 -> V_36 = V_69 ;\r\nbreak;\r\ncase V_58 :\r\nV_68 = V_59 ;\r\nif ( V_67 && V_69 != V_68 )\r\nreturn - V_70 ;\r\nV_69 = V_68 ;\r\nbreak;\r\ncase V_60 :\r\nV_68 = V_61 ;\r\nif ( V_67 && V_69 != V_68 )\r\nreturn - V_70 ;\r\nV_69 = V_68 ;\r\nbreak;\r\ncase V_62 :\r\nV_68 = V_26 -> V_63 ;\r\nif ( V_67 && V_69 != V_75 &&\r\nV_69 != V_76 )\r\nreturn - V_70 ;\r\nif ( V_69 != V_75 )\r\nV_69 = V_76 ;\r\nV_26 -> V_63 = V_69 ;\r\nbreak;\r\ncase V_64 :\r\nV_68 = V_26 -> V_31 * 1000 ;\r\nV_69 = 1000 * ( V_69 / 1000 ) ;\r\nif ( V_67 && V_69 > V_77 * 1000 )\r\nreturn - V_70 ;\r\nif ( V_69 > V_77 * 1000 )\r\nV_69 = V_77 * 1000 ;\r\nV_26 -> V_31 = V_69 / 1000 ;\r\nbreak;\r\ncase V_65 :\r\nV_68 = V_26 -> V_32 * 1000 ;\r\nV_69 = 1000 * ( V_69 / 1000 ) ;\r\nif ( V_67 && V_69 > V_77 * 1000 )\r\nreturn - V_70 ;\r\nif ( V_69 > V_77 * 1000 )\r\nV_69 = V_77 * 1000 ;\r\nV_26 -> V_32 = V_69 / 1000 ;\r\nbreak;\r\ncase V_66 :\r\nV_68 = V_26 -> V_29 ;\r\nV_26 -> V_29 = V_69 ;\r\nbreak;\r\ndefault:\r\nreturn - V_18 ;\r\n}\r\nV_42 -> V_45 = V_69 ;\r\nreturn 0 ;\r\n}\r\nstatic int F_13 ( struct V_2 * V_3 , struct V_78 * V_79 )\r\n{\r\nstruct V_1 * V_24 = F_1 ( V_3 ) ;\r\nstruct V_25 * V_26 = & V_24 -> V_26 ;\r\nint V_80 ;\r\nswitch ( V_79 -> V_43 ) {\r\ncase V_55 :\r\nreturn F_14 ( V_79 ,\r\nV_72 ,\r\nV_24 -> V_40 ? V_34 :\r\nV_72 ,\r\n1 , V_72 ) ;\r\ncase V_56 :\r\nreturn F_14 ( V_79 ,\r\nV_73 ,\r\nV_37 , 1 ,\r\nV_73 ) ;\r\ncase V_57 :\r\nif ( ! V_24 -> V_40 )\r\nreturn - V_18 ;\r\nreturn F_14 ( V_79 ,\r\nV_74 ,\r\nV_35 , 1 ,\r\nV_74 ) ;\r\ncase V_58 :\r\nreturn F_14 ( V_79 ,\r\nV_59 ,\r\nV_59 , 1 ,\r\nV_59 ) ;\r\ncase V_60 :\r\nreturn F_14 ( V_79 ,\r\nV_61 ,\r\nV_61 , 1 ,\r\nV_61 ) ;\r\ncase V_62 :\r\nreturn F_14 ( V_79 ,\r\nV_76 ,\r\nV_75 , 1 ,\r\nV_76 ) ;\r\ncase V_65 :\r\nV_80 = F_14 ( V_79 , 0 , 27000000 , 1 , 8000000 ) ;\r\nif ( V_80 == 0 &&\r\nV_26 -> V_29 ==\r\nV_81 )\r\nV_79 -> V_82 |= V_83 ;\r\nreturn V_80 ;\r\ncase V_44 :\r\nreturn F_14 ( V_79 ,\r\nV_46 ,\r\nV_46 , 1 ,\r\nV_46 ) ;\r\ncase V_66 :\r\nreturn F_14 ( V_79 ,\r\nV_30 ,\r\nV_81 , 1 ,\r\nV_30 ) ;\r\ncase V_64 :\r\nreturn F_14 ( V_79 , 0 , 27000000 , 1 , 6000000 ) ;\r\ncase V_47 :\r\nreturn F_14 ( V_79 , 0 , ( 1 << 14 ) - 1 , 1 , 16 ) ;\r\ncase V_49 :\r\nreturn F_14 ( V_79 , 0 , ( 1 << 14 ) - 1 , 1 , 260 ) ;\r\ncase V_51 :\r\nreturn F_14 ( V_79 , 0 , ( 1 << 14 ) - 1 , 1 , 256 ) ;\r\ncase V_53 :\r\nreturn F_14 ( V_79 , 0 , ( 1 << 14 ) - 1 , 1 , 259 ) ;\r\ndefault:\r\nbreak;\r\n}\r\nreturn - V_18 ;\r\n}\r\nstatic int F_15 ( struct V_2 * V_3 , struct V_84 * V_85 )\r\n{\r\nstatic const T_4 V_86 [] = {\r\nV_72 ,\r\nV_87\r\n} ;\r\nstatic const T_4 V_88 [] = {\r\nV_72 ,\r\nV_34 ,\r\nV_87\r\n} ;\r\nstatic T_4 V_89 [] = {\r\nV_73 ,\r\nV_37 ,\r\nV_87\r\n} ;\r\nstatic T_4 V_90 [] = {\r\nV_74 ,\r\nV_35 ,\r\nV_87\r\n} ;\r\nstruct V_1 * V_24 = F_1 ( V_3 ) ;\r\nstruct V_78 V_79 ;\r\nint V_80 ;\r\nV_79 . V_43 = V_85 -> V_43 ;\r\nV_80 = F_13 ( V_3 , & V_79 ) ;\r\nif ( V_80 )\r\nreturn V_80 ;\r\nswitch ( V_85 -> V_43 ) {\r\ncase V_56 :\r\nreturn F_16 ( V_85 ,\r\nV_89 ) ;\r\ncase V_57 :\r\nif ( ! V_24 -> V_40 )\r\nreturn - V_18 ;\r\nreturn F_16 ( V_85 ,\r\nV_90 ) ;\r\ncase V_55 :\r\nreturn F_16 ( V_85 ,\r\nV_24 -> V_40 ? V_88 :\r\nV_86 ) ;\r\n}\r\nreturn F_17 ( V_85 , & V_79 , NULL ) ;\r\n}\r\nstatic int F_18 ( struct V_2 * V_3 , T_4 V_91 )\r\n{\r\nunsigned char V_8 [ 9 ] , V_92 [ 4 ] ;\r\nstruct V_1 * V_24 = F_1 ( V_3 ) ;\r\nstruct V_4 * V_5 = F_19 ( V_3 ) ;\r\nunsigned V_93 ;\r\nT_4 V_94 ;\r\nunsigned char V_95 [ 256 ] ;\r\nunsigned char V_96 [ 256 ] ;\r\nF_8 ( V_5 , 0x41 , V_24 -> V_97 ) ;\r\nF_8 ( V_5 , 0x40 , ( V_24 -> V_98 & V_99 ) ? 1 : 0 ) ;\r\nF_10 ( V_5 , V_24 ) ;\r\nF_9 ( V_5 , 0x72 , 0x030d ) ;\r\nF_8 ( V_5 , 0x82 , 0x04 ) ;\r\nF_8 ( V_5 , 0x83 , 0x0c ) ;\r\nF_8 ( V_5 , 0xd0 , 0x81 ) ;\r\nF_8 ( V_5 , 0xb0 , 0x05 ) ;\r\nF_9 ( V_5 , 0xf6 , V_91 ) ;\r\nmemcpy ( V_95 , V_100 , sizeof( V_100 ) ) ;\r\nV_95 [ 17 ] = 0xe0 | ( ( V_24 -> V_26 . V_48 >> 8 ) & 0x0f ) ;\r\nV_95 [ 18 ] = V_24 -> V_26 . V_48 & 0xff ;\r\nV_94 = F_20 ( ~ 0 , & V_95 [ 7 ] , sizeof( V_100 ) - 7 - 4 ) ;\r\nV_95 [ sizeof( V_100 ) - 4 ] = ( V_94 >> 24 ) & 0xFF ;\r\nV_95 [ sizeof( V_100 ) - 3 ] = ( V_94 >> 16 ) & 0xFF ;\r\nV_95 [ sizeof( V_100 ) - 2 ] = ( V_94 >> 8 ) & 0xFF ;\r\nV_95 [ sizeof( V_100 ) - 1 ] = V_94 & 0xFF ;\r\nif ( V_24 -> V_26 . V_33 == V_34 ) {\r\nV_93 = sizeof( V_101 ) ;\r\nmemcpy ( V_96 , V_101 , V_93 ) ;\r\n} else {\r\nV_93 = sizeof( V_102 ) ;\r\nmemcpy ( V_96 , V_102 , V_93 ) ;\r\n}\r\nV_96 [ 3 ] = 0x40 | ( ( V_24 -> V_26 . V_48 >> 8 ) & 0x0f ) ;\r\nV_96 [ 4 ] = V_24 -> V_26 . V_48 & 0xff ;\r\nV_96 [ 15 ] = 0xE0 | ( ( V_24 -> V_26 . V_54 >> 8 ) & 0x0F ) ;\r\nV_96 [ 16 ] = V_24 -> V_26 . V_54 & 0xFF ;\r\nV_96 [ 20 ] = 0xE0 | ( ( V_24 -> V_26 . V_52 >> 8 ) & 0x0F ) ;\r\nV_96 [ 21 ] = V_24 -> V_26 . V_52 & 0xFF ;\r\nV_96 [ 25 ] = 0xE0 | ( ( V_24 -> V_26 . V_50 >> 8 ) & 0x0F ) ;\r\nV_96 [ 26 ] = V_24 -> V_26 . V_50 & 0xFF ;\r\nV_94 = F_20 ( ~ 0 , & V_96 [ 7 ] , V_93 - 7 - 4 ) ;\r\nV_96 [ V_93 - 4 ] = ( V_94 >> 24 ) & 0xFF ;\r\nV_96 [ V_93 - 3 ] = ( V_94 >> 16 ) & 0xFF ;\r\nV_96 [ V_93 - 2 ] = ( V_94 >> 8 ) & 0xFF ;\r\nV_96 [ V_93 - 1 ] = V_94 & 0xFF ;\r\nF_9 ( V_5 , 0xc1 , V_24 -> V_26 . V_50 ) ;\r\nF_9 ( V_5 , 0xc0 , V_24 -> V_26 . V_52 ) ;\r\nF_9 ( V_5 , 0xc4 , V_24 -> V_26 . V_54 ) ;\r\nF_4 ( V_5 , V_95 , sizeof( V_100 ) ) ;\r\nF_4 ( V_5 , V_96 , V_93 ) ;\r\nF_8 ( V_5 , 0xa4 , 1 ) ;\r\nF_8 ( V_5 , 0xa4 , 0 ) ;\r\nF_3 ( V_5 , V_13 ) ;\r\nV_8 [ 0 ] = 0xE1 ;\r\nV_8 [ 1 ] = 0xA7 ;\r\nV_8 [ 2 ] = 0xFE ;\r\nV_8 [ 3 ] = 0x82 ;\r\nV_8 [ 4 ] = 0xB0 ;\r\nF_4 ( V_5 , V_8 , 5 ) ;\r\nF_5 ( V_5 , V_92 , 4 ) ;\r\nV_8 [ 0 ] = 0xE0 ;\r\nV_8 [ 1 ] = 0xA7 ;\r\nV_8 [ 2 ] = 0xFE ;\r\nV_8 [ 3 ] = 0x82 ;\r\nV_8 [ 4 ] = 0xB0 ;\r\nV_8 [ 5 ] = V_92 [ 0 ] ;\r\nswitch ( V_24 -> V_26 . V_63 ) {\r\ncase V_75 :\r\nV_8 [ 6 ] = V_92 [ 1 ] | 0x40 ;\r\nbreak;\r\ncase V_76 :\r\ndefault:\r\nV_8 [ 6 ] = V_92 [ 1 ] & 0xBF ;\r\nbreak;\r\n}\r\nV_8 [ 7 ] = V_92 [ 2 ] ;\r\nV_8 [ 8 ] = V_92 [ 3 ] ;\r\nF_4 ( V_5 , V_8 , 9 ) ;\r\nreturn 0 ;\r\n}\r\nstatic int F_21 ( struct V_2 * V_3 , struct V_103 * V_104 , int V_67 )\r\n{\r\nstruct V_1 * V_24 = F_1 ( V_3 ) ;\r\nstruct V_25 V_26 ;\r\nint V_105 ;\r\nif ( V_104 -> V_106 != V_107 )\r\nreturn - V_18 ;\r\nV_26 = V_24 -> V_26 ;\r\nfor ( V_105 = 0 ; V_105 < V_104 -> V_108 ; V_105 ++ ) {\r\nint V_80 = F_12 ( V_24 -> V_40 , & V_26 , V_104 -> V_109 + V_105 , V_67 ) ;\r\nif ( V_80 ) {\r\nV_104 -> V_110 = V_105 ;\r\nreturn V_80 ;\r\n}\r\n}\r\nif ( V_67 )\r\nV_24 -> V_26 = V_26 ;\r\nreturn 0 ;\r\n}\r\nstatic int F_22 ( struct V_2 * V_3 , struct V_103 * V_104 )\r\n{\r\nreturn F_21 ( V_3 , V_104 , 1 ) ;\r\n}\r\nstatic int F_23 ( struct V_2 * V_3 , struct V_103 * V_104 )\r\n{\r\nreturn F_21 ( V_3 , V_104 , 0 ) ;\r\n}\r\nstatic int F_24 ( struct V_2 * V_3 , struct V_103 * V_104 )\r\n{\r\nstruct V_1 * V_24 = F_1 ( V_3 ) ;\r\nint V_105 ;\r\nif ( V_104 -> V_106 != V_107 )\r\nreturn - V_18 ;\r\nfor ( V_105 = 0 ; V_105 < V_104 -> V_108 ; V_105 ++ ) {\r\nint V_80 = F_11 ( V_24 -> V_40 , & V_24 -> V_26 , V_104 -> V_109 + V_105 ) ;\r\nif ( V_80 ) {\r\nV_104 -> V_110 = V_105 ;\r\nreturn V_80 ;\r\n}\r\n}\r\nreturn 0 ;\r\n}\r\nstatic int F_25 ( struct V_2 * V_3 , struct V_111 * V_112 )\r\n{\r\nstruct V_1 * V_24 = F_1 ( V_3 ) ;\r\nif ( V_24 -> V_97 == V_113 )\r\nV_24 -> V_97 = V_114 ;\r\nV_112 -> V_115 = V_116 [ V_24 -> V_97 ] . V_117 . V_118 . V_115 ;\r\nV_112 -> V_119 = V_116 [ V_24 -> V_97 ] . V_117 . V_118 . V_119 ;\r\nV_112 -> V_120 = V_121 ;\r\nV_112 -> V_122 = V_123 ;\r\nV_112 -> V_124 = V_125 ;\r\nreturn 0 ;\r\n}\r\nstatic int F_26 ( struct V_2 * V_3 , struct V_111 * V_112 )\r\n{\r\nstruct V_1 * V_24 = F_1 ( V_3 ) ;\r\nint V_126 , V_127 , V_128 ;\r\nif ( V_112 -> V_120 != V_121 )\r\nreturn - V_18 ;\r\nV_126 = abs ( V_112 -> V_115 - 352 ) ;\r\nV_127 = abs ( V_112 -> V_115 - 480 ) ;\r\nV_128 = abs ( V_112 -> V_115 - 720 ) ;\r\nif ( V_128 < V_127 ) {\r\nV_112 -> V_115 = 720 ;\r\nV_112 -> V_119 = 576 ;\r\nV_24 -> V_97 = V_114 ;\r\n} else if ( V_127 < V_126 ) {\r\nV_112 -> V_115 = 480 ;\r\nV_112 -> V_119 = 576 ;\r\nV_24 -> V_97 = V_129 ;\r\n} else {\r\nV_112 -> V_115 = 352 ;\r\nif ( abs ( V_112 -> V_119 - 576 ) <\r\nabs ( V_112 -> V_119 - 288 ) ) {\r\nV_112 -> V_119 = 576 ;\r\nV_24 -> V_97 = V_130 ;\r\n} else {\r\nV_112 -> V_119 = 288 ;\r\nV_24 -> V_97 = V_131 ;\r\n}\r\n}\r\nV_112 -> V_122 = V_123 ;\r\nV_112 -> V_124 = V_125 ;\r\nreturn 0 ;\r\n}\r\nstatic int F_27 ( struct V_2 * V_3 , T_5 V_132 )\r\n{\r\nstruct V_1 * V_24 = F_1 ( V_3 ) ;\r\nV_24 -> V_98 = V_132 ;\r\nreturn 0 ;\r\n}\r\nstatic int F_28 ( struct V_2 * V_3 , struct V_133 * V_134 )\r\n{\r\nstruct V_4 * V_5 = F_19 ( V_3 ) ;\r\nstruct V_1 * V_24 = F_1 ( V_3 ) ;\r\nreturn F_29 ( V_5 ,\r\nV_134 , V_24 -> V_134 , V_24 -> V_135 ) ;\r\n}\r\nstatic int F_30 ( struct V_4 * V_5 ,\r\nconst struct V_136 * V_43 )\r\n{\r\nstruct V_1 * V_24 = F_31 ( sizeof( * V_24 ) , V_137 ) ;\r\nstruct V_2 * V_3 ;\r\nT_2 V_138 = 0x13 ;\r\nT_2 V_139 [ 12 ] ;\r\nF_32 ( V_5 , L_1 ,\r\nV_5 -> V_138 << 1 , V_5 -> V_140 -> V_141 ) ;\r\nif ( V_24 == NULL )\r\nreturn - V_142 ;\r\nV_3 = & V_24 -> V_3 ;\r\nF_33 ( V_3 , V_5 , & V_143 ) ;\r\nF_4 ( V_5 , & V_138 , 1 ) ;\r\nF_5 ( V_5 , V_139 , sizeof( V_139 ) ) ;\r\nV_24 -> V_134 = V_144 ;\r\nV_24 -> V_135 = ( V_139 [ 8 ] << 8 ) | V_139 [ 9 ] ;\r\nV_24 -> V_40 = 0 ;\r\nif ( V_24 -> V_135 == 0x0206 ) {\r\nV_24 -> V_134 = V_145 ;\r\nV_24 -> V_40 = 1 ;\r\nF_32 ( V_5 , L_2 ) ;\r\n}\r\nV_24 -> V_26 = V_146 ;\r\nV_24 -> V_98 = 0 ;\r\nreturn 0 ;\r\n}\r\nstatic int F_34 ( struct V_4 * V_5 )\r\n{\r\nstruct V_2 * V_3 = F_35 ( V_5 ) ;\r\nF_36 ( V_3 ) ;\r\nF_37 ( F_1 ( V_3 ) ) ;\r\nreturn 0 ;\r\n}
