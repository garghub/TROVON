static int F_1 ( struct V_1 * V_2 )\r\n{\r\nstruct V_3 V_4 = {\r\n. V_5 = V_6 ,\r\n. V_7 = V_8 ,\r\n. V_9 . V_10 . V_11 = V_2 -> V_12 ,\r\n. V_9 . V_10 . type = V_13 ,\r\n} ;\r\nstruct V_14 * V_15 , * V_16 = NULL ;\r\nstruct V_17 * V_18 ;\r\nunsigned int V_19 , V_20 ;\r\nint V_21 = 0 ;\r\nV_16 = F_2 ( V_2 -> V_22 . V_23 ,\r\nsizeof( struct V_14 ) , V_24 ) ;\r\nif ( ! V_16 )\r\nreturn - V_25 ;\r\nfor ( V_20 = 0 , V_19 = 1 ; V_19 <= V_2 -> V_22 . V_23 ; V_19 ++ ) {\r\nV_18 = & V_2 -> V_22 . V_26 [ V_19 ] ;\r\nif ( ! V_18 -> V_27 )\r\ncontinue;\r\nV_15 = & ( V_16 [ V_20 ++ ] ) ;\r\nV_15 -> V_28 . V_29 = V_30 ;\r\nif ( V_18 -> V_31 == V_32 ) {\r\nV_15 -> V_28 . V_33 = 8 ;\r\nV_15 -> V_28 . V_34 = 0 ;\r\nV_15 -> V_28 . V_35 = 1 ;\r\n} else {\r\nV_15 -> V_28 . V_29 = V_36 ;\r\nif ( V_18 -> V_31 == V_37 ) {\r\nV_15 -> V_28 . V_34 = 2 ;\r\nV_15 -> V_28 . V_33 = 1 ;\r\n}\r\nV_15 -> V_28 . V_35 = 0 ;\r\n}\r\nV_15 -> V_28 . V_38 = V_18 -> V_38 ;\r\nV_15 -> type = V_18 -> type ;\r\nV_15 -> V_39 = V_18 -> V_39 ;\r\nV_15 -> V_40 = 0 ;\r\nF_3 ( V_15 -> V_41 , NULL ) ;\r\n}\r\nif ( ! V_20 ) {\r\nF_4 ( L_1 , V_2 -> V_12 ) ;\r\nF_5 ( V_16 ) ;\r\nreturn - V_42 ;\r\n}\r\nV_4 . V_9 . V_10 . V_22 . V_23 = V_20 ;\r\nV_4 . V_9 . V_10 . V_22 . V_43 . V_44 = V_2 -> V_43 . V_44 ;\r\nV_4 . V_9 . V_10 . V_22 . V_43 . V_45 = V_2 -> V_43 . V_45 ;\r\nV_4 . V_9 . V_10 . V_22 . V_43 . V_46 = V_2 -> V_43 . V_46 ;\r\nV_4 . V_9 . V_10 . V_22 . V_43 . V_47 =\r\nV_2 -> V_43 . V_47 ;\r\nF_3 ( V_4 . V_9 . V_10 . V_22 . V_26 , V_16 ) ;\r\nif ( ! V_48 )\r\nV_21 = F_6 ( & V_4 ) ;\r\nif ( ! V_21 ) {\r\nF_4 ( L_2 , V_2 -> V_12 ) ;\r\nfor ( V_19 = 1 ; V_19 <= V_2 -> V_22 . V_23 ; V_19 ++ ) {\r\nV_18 = & V_2 -> V_22 . V_26 [ V_19 ] ;\r\nif ( ! V_18 -> V_27 )\r\ncontinue;\r\nF_4 ( L_3 ,\r\nV_18 -> type , V_18 -> V_49 , ( V_50 ) V_18 -> V_39 ) ;\r\n}\r\n} else if ( ( V_21 != - V_42 ) && ( V_21 != - V_51 ) )\r\nF_7 ( L_4 ,\r\nV_21 , V_2 -> V_12 ) ;\r\nF_5 ( V_16 ) ;\r\nreturn V_21 ;\r\n}\r\nstatic struct V_52 *\r\nF_8 ( struct V_1 * V_2 ,\r\nstruct V_53 * V_54 )\r\n{\r\nstruct V_52 * V_55 = NULL ;\r\nunsigned int V_19 ;\r\nF_9 ( sizeof( struct V_52 ) !=\r\nsizeof( struct V_56 ) ) ;\r\nV_55 = F_2 ( V_2 -> V_57 -> V_58 ,\r\nsizeof( struct V_52 ) , V_24 ) ;\r\nif ( ! V_55 )\r\nreturn F_10 ( - V_25 ) ;\r\nV_54 -> V_58 = V_2 -> V_57 -> V_58 ;\r\nfor ( V_19 = 0 ; V_19 < V_2 -> V_57 -> V_58 ; V_19 ++ ) {\r\nmemcpy ( & ( V_55 [ V_19 ] ) , & ( V_2 -> V_57 -> V_26 [ V_19 ] ) ,\r\nsizeof( struct V_56 ) ) ;\r\n}\r\nreturn V_55 ;\r\n}\r\nstatic int F_11 ( struct V_1 * V_2 ,\r\nstruct V_53 * V_59 )\r\n{\r\nstruct V_60 * V_61 ;\r\nF_9 ( sizeof( struct V_62 ) !=\r\nsizeof( struct V_60 ) ) ;\r\nV_59 -> V_63 = V_2 -> V_57 -> V_63 ;\r\nV_61 = & ( V_2 -> V_57 -> V_64 ) ;\r\nif ( V_61 -> V_65 <= 1 ) {\r\nif ( V_61 -> V_66 == V_67 )\r\nV_59 -> V_63 = V_68 ;\r\nelse if ( V_61 -> V_66 == V_69 )\r\nV_59 -> V_63 = V_70 ;\r\nelse if ( V_61 -> V_66 == V_71 )\r\nV_59 -> V_63 = V_72 ;\r\n}\r\nmemcpy ( & ( V_59 -> V_64 ) , V_61 , sizeof( struct V_60 ) ) ;\r\nreturn 0 ;\r\n}\r\nstatic int F_12 ( struct V_73 * V_74 ,\r\nstruct V_75 * V_76 )\r\n{\r\nV_76 -> V_77 = V_74 -> V_77 ;\r\nV_76 -> V_78 = V_74 -> V_78 ;\r\nV_76 -> V_29 = V_74 -> V_29 ;\r\nV_76 -> V_33 = V_74 -> V_33 ;\r\nV_76 -> V_34 = V_74 -> V_34 ;\r\nV_76 -> V_79 = V_74 -> V_79 ;\r\nV_76 -> V_38 = V_74 -> V_38 ;\r\nreturn 0 ;\r\n}\r\nstatic int F_13 ( struct V_1 * V_2 )\r\n{\r\nint V_21 = 0 ;\r\nstruct V_3 V_4 = {\r\n. V_5 = V_6 ,\r\n. V_7 = V_8 ,\r\n. V_9 . V_10 . V_11 = V_2 -> V_12 ,\r\n. V_9 . V_10 . type = V_80 ,\r\n} ;\r\nstruct V_53 * V_54 ;\r\nstruct V_52 * V_55 = NULL ;\r\nV_54 = & V_4 . V_9 . V_10 . V_81 ;\r\nV_54 -> V_82 = V_2 -> V_83 ;\r\nV_54 -> V_43 |= V_84 ;\r\nF_12 ( & ( V_2 -> V_57 -> V_85 ) ,\r\n& V_54 -> V_85 ) ;\r\nF_12 ( & ( V_2 -> V_57 -> V_86 ) ,\r\n& V_54 -> V_86 ) ;\r\nV_54 -> V_43 |= V_87 ;\r\nV_55 = F_8 ( V_2 , V_54 ) ;\r\nif ( ! F_14 ( V_55 ) ) {\r\nF_3 ( V_54 -> V_26 , V_55 ) ;\r\nV_54 -> V_43 |= V_88 ;\r\n}\r\nif ( ! F_11 ( V_2 , V_54 ) )\r\nV_54 -> V_43 |= V_89 ;\r\nif ( V_54 -> V_43 != ( V_89 | V_88 | V_87 | V_84 ) ) {\r\nF_15 ( L_5 ,\r\nV_2 -> V_12 , V_54 -> V_43 ) ;\r\nV_21 = - V_90 ;\r\ngoto V_91;\r\n}\r\nif ( ! V_48 )\r\nV_21 = F_6 ( & V_4 ) ;\r\nif ( ! V_21 ) {\r\nstruct V_92 * V_81 ;\r\nunsigned int V_19 ;\r\nV_81 = V_2 -> V_57 ;\r\nF_4 ( L_6 , V_2 -> V_12 ) ;\r\nfor ( V_19 = 0 ; V_19 < V_81 -> V_58 ; V_19 ++ ) {\r\nF_4 ( L_7 ,\r\n( V_19 == V_81 -> V_93 ? '*' : ' ' ) , V_19 ,\r\n( V_50 ) V_81 -> V_26 [ V_19 ] . V_94 ,\r\n( V_50 ) V_81 -> V_26 [ V_19 ] . V_22 ,\r\n( V_50 ) V_81 -> V_26 [ V_19 ] . V_95 ) ;\r\n}\r\n} else if ( ( V_21 != - V_42 ) && ( V_21 != - V_51 ) )\r\nF_15 ( L_8 ,\r\nV_21 , V_2 -> V_12 ) ;\r\nV_91:\r\nif ( ! F_14 ( V_55 ) )\r\nF_5 ( V_55 ) ;\r\nreturn V_21 ;\r\n}\r\nstatic int F_16 ( struct V_1 * V_2 )\r\n{\r\nint V_96 = 0 ;\r\nF_17 ( & V_97 ) ;\r\nif ( F_18 ( V_2 -> V_12 , V_98 ) ) {\r\nF_19 ( & V_97 ) ;\r\nreturn - V_99 ;\r\n}\r\nif ( V_2 -> V_43 . V_22 )\r\nV_96 = F_1 ( V_2 ) ;\r\nif ( V_2 -> V_57 && V_2 -> V_57 -> V_26 )\r\nV_96 |= F_13 ( V_2 ) ;\r\nF_19 ( & V_97 ) ;\r\nreturn V_96 ;\r\n}\r\nstatic unsigned int T_1 F_20 ( void )\r\n{\r\nstruct V_100 * V_101 ;\r\nstruct V_3 V_4 = {\r\n. V_5 = V_102 ,\r\n. V_7 = V_8 ,\r\n} ;\r\nint V_21 = 0 ;\r\nunsigned int V_19 , V_103 , V_104 = 0 ;\r\nV_101 = & V_4 . V_9 . V_105 ;\r\nV_101 -> V_106 = 0 ;\r\nV_21 = F_6 ( & V_4 ) ;\r\nif ( V_21 )\r\nreturn V_107 ;\r\nV_103 = V_4 . V_9 . V_105 . V_108 ;\r\nfor ( V_19 = 0 ; V_19 <= V_103 ; V_19 ++ ) {\r\nV_101 -> V_106 = V_19 ;\r\nV_21 = F_6 ( & V_4 ) ;\r\nif ( V_21 )\r\ncontinue;\r\nV_104 = F_21 ( V_101 -> V_12 , V_104 ) ;\r\n}\r\nV_104 *= 2 ;\r\nF_4 ( L_9 , V_104 ) ;\r\nreturn V_104 ;\r\n}\r\nstatic T_2\r\nF_22 ( T_3 V_109 , V_50 V_110 , void * V_111 , void * * V_112 )\r\n{\r\nV_50 V_12 ;\r\nT_2 V_113 ;\r\nT_4 V_114 ;\r\nunsigned long long V_115 ;\r\nunion V_116 V_117 = { 0 } ;\r\nstruct V_118 V_119 = { sizeof( union V_116 ) , & V_117 } ;\r\nT_5 V_120 = 0 ;\r\nV_113 = F_23 ( V_109 , & V_114 ) ;\r\nif ( F_24 ( V_113 ) )\r\nreturn V_121 ;\r\nswitch ( V_114 ) {\r\ncase V_122 :\r\nV_113 = F_25 ( V_109 , NULL , NULL , & V_119 ) ;\r\nif ( F_24 ( V_113 ) )\r\nreturn V_121 ;\r\nV_12 = V_117 . V_123 . V_124 ;\r\nV_120 = V_117 . V_123 . V_125 ;\r\nbreak;\r\ncase V_126 :\r\nV_113 = F_26 ( V_109 , L_10 , NULL , & V_115 ) ;\r\nif ( F_24 ( V_113 ) )\r\nreturn V_121 ;\r\nV_12 = V_115 ;\r\nbreak;\r\ndefault:\r\nreturn V_121 ;\r\n}\r\nif ( V_12 > V_127 ) {\r\nF_4 ( L_11 ,\r\nV_127 , V_12 ) ;\r\nreturn V_121 ;\r\n}\r\nF_27 ( V_12 , V_128 ) ;\r\nF_4 ( L_12 , V_12 , ( unsigned long ) V_120 ) ;\r\nV_113 = F_25 ( V_109 , L_13 , NULL , & V_119 ) ;\r\nif ( F_24 ( V_113 ) ) {\r\nif ( ! V_120 )\r\nreturn V_121 ;\r\n}\r\nF_27 ( V_12 , V_129 ) ;\r\nreturn V_121 ;\r\n}\r\nstatic int F_28 ( struct V_1 * V_130 )\r\n{\r\nif ( ! V_130 )\r\nreturn - V_90 ;\r\nif ( V_128 && V_129 )\r\ngoto V_131;\r\nV_128 = F_2 ( F_29 ( V_127 ) , sizeof( unsigned long ) , V_24 ) ;\r\nif ( ! V_128 )\r\nreturn - V_25 ;\r\nV_129 = F_2 ( F_29 ( V_127 ) , sizeof( unsigned long ) , V_24 ) ;\r\nif ( ! V_129 ) {\r\nF_5 ( V_128 ) ;\r\nreturn - V_25 ;\r\n}\r\nF_30 ( V_122 , V_132 ,\r\nV_133 ,\r\nF_22 , NULL , NULL , NULL ) ;\r\nF_31 ( L_14 , F_22 , NULL , NULL ) ;\r\nV_131:\r\nif ( ! F_32 ( V_128 , V_98 , V_127 ) ) {\r\nunsigned int V_19 ;\r\nF_33 (i, acpi_id_present, nr_acpi_bits) {\r\nV_130 -> V_12 = V_19 ;\r\nV_130 -> V_43 . V_22 = F_34 ( V_19 , V_129 ) ;\r\n( void ) F_16 ( V_130 ) ;\r\n}\r\n}\r\nreturn 0 ;\r\n}\r\nstatic int T_1 F_35 ( void )\r\n{\r\nstruct V_134 * V_135 = & F_36 ( 0 ) ;\r\nif ( ! F_37 () )\r\nreturn - V_90 ;\r\nif ( ! V_136 . V_137 )\r\nreturn - V_90 ;\r\nif ( V_135 -> V_138 == V_139 ) {\r\nif ( ! F_38 ( V_135 , V_140 ) )\r\nreturn - V_90 ;\r\nreturn 0 ;\r\n}\r\nif ( V_135 -> V_138 == V_141 ) {\r\n#define F_39 0x80000007\r\n#define F_40 0x00000080\r\nV_50 V_142 , V_143 , V_144 , V_145 ;\r\nF_41 ( F_39 , & V_142 , & V_143 , & V_144 , & V_145 ) ;\r\nif ( ( V_145 & F_40 ) != F_40 )\r\nreturn - V_90 ;\r\nreturn 0 ;\r\n}\r\nreturn - V_90 ;\r\n}\r\nstatic void F_42 ( void )\r\n{\r\nunsigned int V_19 ;\r\nF_43 (i)\r\nF_44 ( F_45 ( V_146 , V_19 )\r\n-> V_147 ) ;\r\nF_46 ( V_146 ) ;\r\n}\r\nstatic int F_47 ( void )\r\n{\r\nstruct V_1 * V_130 = NULL ;\r\nunsigned int V_19 ;\r\nint V_148 = 0 ;\r\nF_48 ( L_15 ) ;\r\nF_43 (i) {\r\nstruct V_1 * V_2 ;\r\nV_2 = F_49 ( V_149 , V_19 ) ;\r\nif ( ! V_2 )\r\ncontinue;\r\nif ( ! V_130 ) {\r\nV_130 = F_50 ( sizeof( struct V_1 ) , V_24 ) ;\r\nif ( V_130 )\r\nmemcpy ( V_130 , V_2 , sizeof( struct V_1 ) ) ;\r\n}\r\n( void ) F_16 ( V_2 ) ;\r\n}\r\nV_148 = F_28 ( V_130 ) ;\r\nF_5 ( V_130 ) ;\r\nreturn V_148 ;\r\n}\r\nstatic int F_51 ( struct V_150 * V_151 ,\r\nunsigned long V_152 , void * V_153 )\r\n{\r\nF_52 ( V_98 , V_127 ) ;\r\nreturn F_47 () ;\r\n}\r\nstatic int T_1 F_53 ( void )\r\n{\r\nunsigned int V_19 ;\r\nint V_148 = F_35 () ;\r\nif ( V_148 )\r\nreturn V_148 ;\r\nV_127 = F_20 () + 1 ;\r\nV_98 = F_2 ( F_29 ( V_127 ) , sizeof( unsigned long ) , V_24 ) ;\r\nif ( ! V_98 )\r\nreturn - V_25 ;\r\nV_146 = F_54 ( struct V_92 ) ;\r\nif ( ! V_146 ) {\r\nF_4 ( L_16 ) ;\r\nF_5 ( V_98 ) ;\r\nreturn - V_25 ;\r\n}\r\nF_43 (i) {\r\nif ( ! F_55 (\r\n& F_45 ( V_146 , V_19 ) -> V_147 ,\r\nV_24 , F_56 ( V_19 ) ) ) {\r\nV_148 = - V_25 ;\r\ngoto V_154;\r\n}\r\n}\r\n( void ) F_57 ( V_146 ) ;\r\nF_43 (i) {\r\nstruct V_1 * V_155 ;\r\nstruct V_92 * V_81 ;\r\nV_155 = F_49 ( V_149 , V_19 ) ;\r\nV_81 = F_45 ( V_146 , V_19 ) ;\r\nif ( ! V_155 )\r\ncontinue;\r\nV_155 -> V_57 = V_81 ;\r\nV_148 = F_58 ( V_155 ) ;\r\nif ( V_148 )\r\ngoto V_154;\r\n}\r\nV_148 = F_47 () ;\r\nif ( V_148 )\r\ngoto V_156;\r\nF_59 ( & V_157 ) ;\r\nreturn 0 ;\r\nV_156:\r\nF_43 (i) {\r\nstruct V_92 * V_81 ;\r\nV_81 = F_45 ( V_146 , V_19 ) ;\r\nF_60 ( V_81 , V_19 ) ;\r\n}\r\nV_154:\r\nF_42 () ;\r\nF_5 ( V_98 ) ;\r\nreturn V_148 ;\r\n}\r\nstatic void T_6 F_61 ( void )\r\n{\r\nint V_19 ;\r\nF_62 ( & V_157 ) ;\r\nF_5 ( V_98 ) ;\r\nF_5 ( V_128 ) ;\r\nF_5 ( V_129 ) ;\r\nF_43 (i) {\r\nstruct V_92 * V_81 ;\r\nV_81 = F_45 ( V_146 , V_19 ) ;\r\nF_60 ( V_81 , V_19 ) ;\r\n}\r\nF_42 () ;\r\n}
