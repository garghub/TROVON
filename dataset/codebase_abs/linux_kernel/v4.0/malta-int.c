static inline int F_1 ( void )\r\n{\r\nint V_1 ;\r\nswitch ( V_2 ) {\r\ncase V_3 :\r\ncase V_4 :\r\ncase V_5 :\r\ncase V_6 :\r\nF_2 ( V_7 , V_1 ) ;\r\nV_1 &= 0xff ;\r\nbreak;\r\ncase V_8 :\r\nV_1 = F_3 ( V_9 ) ;\r\nV_1 &= 0xff ;\r\nbreak;\r\ncase V_10 :\r\nV_11 = 0x20000 ;\r\n( void ) V_11 ;\r\nF_4 () ;\r\nV_1 = F_5 ( ( V_12 * ) V_13 ) ;\r\nF_4 () ;\r\nV_1 &= 0xff ;\r\nV_11 = 0 ;\r\nbreak;\r\ndefault:\r\nF_6 ( L_1 ) ;\r\nreturn - 1 ;\r\n}\r\nreturn V_1 ;\r\n}\r\nstatic inline int F_7 ( void )\r\n{\r\nunsigned long V_14 ;\r\nint V_1 ;\r\nF_8 ( & V_15 , V_14 ) ;\r\nV_1 = F_1 () ;\r\nF_9 ( & V_15 , V_14 ) ;\r\nreturn V_1 ;\r\n}\r\nstatic void F_10 ( void )\r\n{\r\nint V_1 ;\r\nV_1 = F_7 () ;\r\nif ( V_1 < 0 ) {\r\nreturn;\r\n}\r\nF_11 ( V_16 + V_1 ) ;\r\n#ifdef F_12\r\nif ( V_17 )\r\nV_17 () ;\r\n#endif\r\n}\r\nstatic T_1 F_13 ( int V_1 , void * V_18 )\r\n{\r\nF_10 () ;\r\nreturn V_19 ;\r\n}\r\nstatic void F_14 ( void )\r\n{\r\nunsigned int V_20 , V_21 , V_22 , V_23 ;\r\nunsigned int V_24 , V_25 , V_26 , V_27 ;\r\nunsigned int V_28 , V_29 , V_30 ;\r\nstruct V_31 * V_32 = F_15 () ;\r\nF_6 ( L_2 ) ;\r\nF_6 ( L_3\r\nL_4 ,\r\nV_32 -> V_33 , V_32 -> V_34 ,\r\nV_32 -> V_35 , V_32 -> V_36 ) ;\r\nswitch ( V_2 ) {\r\ncase V_3 :\r\ncase V_4 :\r\ncase V_5 :\r\ncase V_6 :\r\nF_16 () ;\r\nbreak;\r\ncase V_8 :\r\nV_28 = F_3 ( V_37 ) ;\r\nV_29 = F_3 ( V_38 ) ;\r\nV_30 = F_3 ( V_39 ) ;\r\nF_6 ( L_5 , V_28 ) ;\r\nF_6 ( L_6 ,\r\nV_30 , V_29 ) ;\r\nbreak;\r\ncase V_10 :\r\nV_23 = V_40 ;\r\nV_24 = V_41 ;\r\nV_25 = V_42 ;\r\nV_26 = V_43 ;\r\nV_27 = V_44 ;\r\nV_20 = V_45 ;\r\nV_21 = V_46 ;\r\nV_22 = V_47 ;\r\nF_6 ( L_7 , V_25 ) ;\r\nF_6 ( L_8 , V_26 ) ;\r\nF_6 ( L_9 , V_27 ) ;\r\nF_6 ( L_10 , V_20 ) ;\r\nF_6 ( L_11 , V_21 ) ;\r\nF_6 ( L_12 , V_22 ) ;\r\nF_6 ( L_13 , V_23 ) ;\r\nF_6 ( L_14 , V_24 ) ;\r\nbreak;\r\n}\r\nF_17 ( L_15 , V_32 ) ;\r\n}\r\nstatic T_1 F_18 ( int V_1 , void * V_18 )\r\n{\r\nF_14 () ;\r\nreturn V_19 ;\r\n}\r\nstatic void F_19 ( void )\r\n{\r\nF_11 ( V_48 + V_49 ) ;\r\n}\r\nstatic void F_20 ( void )\r\n{\r\nF_11 ( V_48 + V_50 ) ;\r\n}\r\nstatic T_1 F_21 ( int V_1 , void * V_18 )\r\n{\r\n#ifdef F_22\r\nif ( V_17 )\r\nV_17 () ;\r\n#endif\r\nF_23 () ;\r\nreturn V_19 ;\r\n}\r\nstatic T_1 F_24 ( int V_1 , void * V_18 )\r\n{\r\nF_25 () ;\r\nreturn V_19 ;\r\n}\r\nvoid T_2 F_26 ( int V_1 , struct V_51 * V_52 )\r\n{\r\nF_27 ( V_1 , V_52 ) ;\r\nF_28 ( V_1 , V_53 ) ;\r\n}\r\nvoid T_2 F_29 ( void )\r\n{\r\nint V_54 , V_55 ;\r\nF_30 () ;\r\nif ( ! V_56 )\r\nF_31 () ;\r\nif ( F_32 () ) {\r\nF_33 ( V_57 | V_58 ) ;\r\nV_59 = 1 ;\r\n} else {\r\nif ( V_2 == V_4 ) {\r\nV_60 = F_34 ( V_61 ,\r\nV_62 ) ;\r\nV_59 =\r\n( F_5 ( V_60 + V_63 ) &\r\nV_64 ) >>\r\nV_65 ;\r\n}\r\n}\r\nif ( V_59 )\r\nF_35 ( L_16 ) ;\r\nswitch ( V_2 ) {\r\ncase V_3 :\r\ncase V_4 :\r\nif ( V_56 )\r\nF_36 ( V_66 ,\r\nV_67 , V_68 ,\r\nV_69 ) ;\r\nelse\r\nF_36 ( V_66 ,\r\nV_70 , V_71 ,\r\nV_72 ) ;\r\nbreak;\r\ncase V_5 :\r\ncase V_6 :\r\nif ( V_56 )\r\nF_36 ( V_73 ,\r\nV_67 , V_68 ,\r\nV_69 ) ;\r\nelse\r\nF_36 ( V_73 ,\r\nV_70 , V_71 ,\r\nV_72 ) ;\r\n}\r\nif ( V_59 ) {\r\nint V_74 ;\r\nF_37 ( V_57 , V_75 , V_76 ,\r\nV_77 ) ;\r\nif ( ! F_32 () ) {\r\nV_74 = F_5 ( V_60 + V_63 ) ;\r\nF_38 ( V_74 | ( 0x1 << V_78 ) ,\r\nV_60 + V_63 ) ;\r\nF_35 ( L_17 ) ;\r\n}\r\nV_55 = V_77 + V_79 ;\r\nV_54 = V_48 + V_80 ;\r\n} else {\r\n#if F_39 ( V_81 )\r\nif ( V_56 ) {\r\nF_40 ( V_82 , F_19 ) ;\r\nF_40 ( V_83 , F_20 ) ;\r\nV_84 = V_82 ;\r\nV_85 = V_83 ;\r\n} else {\r\nV_84 = V_48 +\r\nV_49 ;\r\nV_85 = V_48 +\r\nV_50 ;\r\n}\r\nF_26 ( V_84 , & V_86 ) ;\r\nF_26 ( V_85 , & V_87 ) ;\r\n#endif\r\nif ( V_56 ) {\r\nF_40 ( V_88 ,\r\nF_10 ) ;\r\nF_40 ( V_89 ,\r\nF_14 ) ;\r\nV_55 = V_67 + V_88 ;\r\nV_54 = V_67 + V_89 ;\r\n} else {\r\nV_55 = V_48 + V_90 ;\r\nV_54 = V_48 + V_80 ;\r\n}\r\n}\r\nF_27 ( V_55 , & V_91 ) ;\r\nF_27 ( V_54 , & V_92 ) ;\r\n}\r\nvoid F_41 ( void )\r\n{\r\n}\r\nint F_42 ( struct V_31 * V_32 , int V_93 )\r\n{\r\nint V_94 = V_93 ? V_95 : V_96 ;\r\nif ( F_32 () ) {\r\nunsigned long V_97 = F_43 () ;\r\nunsigned long V_98 = F_44 () ;\r\nunsigned long V_99 = F_45 () ;\r\nunsigned long V_100 , V_101 ;\r\nchar V_102 [ 256 ] ;\r\nV_100 = V_97 & V_103 ;\r\nif ( V_100 != 0 ) {\r\nV_100 >>= V_104 ;\r\nif ( V_100 < 16 ) {\r\nunsigned long V_105 = ( V_97 >> 15 ) & 7 ;\r\nunsigned long V_106 = ( V_97 >> 12 ) & 7 ;\r\nunsigned long V_107 = ( V_97 >> 7 ) & 0x1f ;\r\nunsigned long V_108 = ( V_97 >> 3 ) & 15 ;\r\nunsigned long V_109 = ( V_97 >> 0 ) & 7 ;\r\nsnprintf ( V_102 , sizeof( V_102 ) ,\r\nL_18\r\nL_19 ,\r\nV_105 , V_110 [ V_106 ] , V_111 [ V_107 ] ,\r\nV_108 , V_109 ) ;\r\n} else {\r\nunsigned long V_112 = ( V_97 >> 18 ) & 7 ;\r\nunsigned long V_113 = ( V_97 >> 15 ) & 7 ;\r\nunsigned long V_114 = ( V_97 >> 12 ) & 7 ;\r\nunsigned long V_115 = ( V_97 >> 9 ) & 7 ;\r\nunsigned long V_116 = ( V_97 >> 8 ) & 1 ;\r\nunsigned long V_107 = ( V_97 >> 3 ) & 0x1f ;\r\nunsigned long V_109 = ( V_97 >> 0 ) & 7 ;\r\nsnprintf ( V_102 , sizeof( V_102 ) ,\r\nL_20\r\nL_21 ,\r\nV_117 [ V_112 ] , V_117 [ V_113 ] ,\r\nV_117 [ V_114 ] , V_117 [ V_115 ] ,\r\nV_116 ? L_22 : L_23 ,\r\nV_111 [ V_107 ] , V_109 ) ;\r\n}\r\nV_101 = ( V_99 & V_118 ) >>\r\nV_119 ;\r\nF_46 ( L_24 , V_97 ,\r\nV_120 [ V_100 ] , V_102 ) ;\r\nF_46 ( L_25 , V_98 ) ;\r\nF_46 ( L_26 , V_99 , V_120 [ V_101 ] ) ;\r\nF_47 ( 0 ) ;\r\n}\r\n}\r\nreturn V_94 ;\r\n}
