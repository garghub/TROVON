static void\r\nF_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )\r\n{\r\nstruct V_5 * V_6 = F_2 ( V_2 ) -> V_7 ;\r\nT_2 V_8 [] = { V_3 , V_4 } ;\r\nint V_9 ;\r\nV_9 = F_3 ( V_6 , V_8 , F_4 ( V_8 ) ) ;\r\nif ( V_9 < 0 )\r\nF_5 ( & V_6 -> V_10 , L_1 , V_9 , V_3 ) ;\r\n}\r\nstatic T_2\r\nF_6 ( struct V_1 * V_2 , T_2 V_3 )\r\n{\r\nstruct V_5 * V_6 = F_2 ( V_2 ) -> V_7 ;\r\nT_2 V_4 ;\r\nint V_9 ;\r\nV_9 = F_3 ( V_6 , & V_3 , sizeof( V_3 ) ) ;\r\nif ( V_9 < 0 )\r\ngoto V_11;\r\nV_9 = F_7 ( V_6 , & V_4 , sizeof( V_4 ) ) ;\r\nif ( V_9 < 0 )\r\ngoto V_11;\r\nreturn V_4 ;\r\nV_11:\r\nF_5 ( & V_6 -> V_10 , L_2 , V_9 , V_3 ) ;\r\nreturn 0 ;\r\n}\r\nstatic void\r\nF_8 ( struct V_1 * V_2 , T_1 V_12 )\r\n{\r\nstruct V_13 * V_14 = F_2 ( V_2 ) ;\r\nif ( F_9 ( V_12 ) != V_14 -> V_15 ) {\r\nstruct V_5 * V_6 = F_10 ( V_2 ) ;\r\nT_2 V_8 [] = {\r\nV_16 , F_9 (reg)\r\n} ;\r\nint V_9 = F_3 ( V_6 , V_8 , sizeof( V_8 ) ) ;\r\nif ( V_9 < 0 )\r\nF_5 ( & V_6 -> V_10 , L_3 , V_9 ) ;\r\nV_14 -> V_15 = F_9 ( V_12 ) ;\r\n}\r\n}\r\nstatic int\r\nF_11 ( struct V_1 * V_2 , T_1 V_12 , char * V_8 , int V_17 )\r\n{\r\nstruct V_5 * V_6 = F_10 ( V_2 ) ;\r\nT_2 V_3 = F_12 ( V_12 ) ;\r\nint V_9 ;\r\nF_8 ( V_2 , V_12 ) ;\r\nV_9 = F_3 ( V_6 , & V_3 , sizeof( V_3 ) ) ;\r\nif ( V_9 < 0 )\r\ngoto V_11;\r\nV_9 = F_7 ( V_6 , V_8 , V_17 ) ;\r\nif ( V_9 < 0 )\r\ngoto V_11;\r\nreturn V_9 ;\r\nV_11:\r\nF_5 ( & V_6 -> V_10 , L_4 , V_9 , V_12 ) ;\r\nreturn V_9 ;\r\n}\r\nstatic T_2\r\nF_13 ( struct V_1 * V_2 , T_1 V_12 )\r\n{\r\nT_2 V_4 = 0 ;\r\nF_11 ( V_2 , V_12 , & V_4 , sizeof( V_4 ) ) ;\r\nreturn V_4 ;\r\n}\r\nstatic void\r\nF_14 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_4 )\r\n{\r\nstruct V_5 * V_6 = F_10 ( V_2 ) ;\r\nT_2 V_8 [] = { F_12 ( V_12 ) , V_4 } ;\r\nint V_9 ;\r\nF_8 ( V_2 , V_12 ) ;\r\nV_9 = F_3 ( V_6 , V_8 , F_4 ( V_8 ) ) ;\r\nif ( V_9 < 0 )\r\nF_5 ( & V_6 -> V_10 , L_5 , V_9 , V_12 ) ;\r\n}\r\nstatic void\r\nF_15 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_4 )\r\n{\r\nstruct V_5 * V_6 = F_10 ( V_2 ) ;\r\nT_2 V_8 [] = { F_12 ( V_12 ) , V_4 >> 8 , V_4 } ;\r\nint V_9 ;\r\nF_8 ( V_2 , V_12 ) ;\r\nV_9 = F_3 ( V_6 , V_8 , F_4 ( V_8 ) ) ;\r\nif ( V_9 < 0 )\r\nF_5 ( & V_6 -> V_10 , L_5 , V_9 , V_12 ) ;\r\n}\r\nstatic void\r\nF_16 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_4 )\r\n{\r\nF_14 ( V_2 , V_12 , F_13 ( V_2 , V_12 ) | V_4 ) ;\r\n}\r\nstatic void\r\nF_17 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_4 )\r\n{\r\nF_14 ( V_2 , V_12 , F_13 ( V_2 , V_12 ) & ~ V_4 ) ;\r\n}\r\nstatic void\r\nF_18 ( struct V_1 * V_2 )\r\n{\r\nF_16 ( V_2 , V_18 , V_19 | V_20 ) ;\r\nF_19 ( 50 ) ;\r\nF_17 ( V_2 , V_18 , V_19 | V_20 ) ;\r\nF_19 ( 50 ) ;\r\nF_16 ( V_2 , V_21 , V_22 ) ;\r\nF_17 ( V_2 , V_21 , V_22 ) ;\r\nF_14 ( V_2 , V_23 , 0x00 ) ;\r\nF_14 ( V_2 , V_24 , F_20 ( 1 ) ) ;\r\nF_14 ( V_2 , V_25 , 0x00 ) ;\r\nF_14 ( V_2 , V_26 , 0x00 ) ;\r\nF_14 ( V_2 , V_27 , 0x00 ) ;\r\nF_14 ( V_2 , V_28 , 0x00 ) ;\r\nF_14 ( V_2 , V_29 , 0x03 ) ;\r\nF_14 ( V_2 , V_30 , V_31 | V_32 ) ;\r\nF_14 ( V_2 , V_33 , 0xfa ) ;\r\nF_14 ( V_2 , V_34 , 0x00 ) ;\r\nF_14 ( V_2 , V_35 , 0x5b ) ;\r\nF_14 ( V_2 , V_36 , 0x00 ) ;\r\nF_14 ( V_2 , V_37 , 0x10 ) ;\r\n}\r\nstatic void\r\nF_21 ( struct V_1 * V_2 , void * V_38 )\r\n{\r\n}\r\nstatic void\r\nF_22 ( struct V_1 * V_2 , int V_39 )\r\n{\r\nstruct V_13 * V_14 = F_2 ( V_2 ) ;\r\nif ( V_39 != V_40 )\r\nV_39 = V_41 ;\r\nif ( V_39 == V_14 -> V_42 )\r\nreturn;\r\nswitch ( V_39 ) {\r\ncase V_40 :\r\nF_14 ( V_2 , V_43 , 0xff ) ;\r\nF_14 ( V_2 , V_44 , 0xff ) ;\r\nF_14 ( V_2 , V_45 , 0xff ) ;\r\nF_14 ( V_2 , V_46 , 0xff ) ;\r\nF_14 ( V_2 , V_47 ,\r\nF_23 ( 2 ) | F_24 ( 3 ) ) ;\r\nF_14 ( V_2 , V_48 ,\r\nF_25 ( 0 ) | F_26 ( 1 ) ) ;\r\nF_14 ( V_2 , V_49 ,\r\nF_27 ( 4 ) | F_28 ( 5 ) ) ;\r\nbreak;\r\ncase V_41 :\r\nF_14 ( V_2 , V_43 , 0x00 ) ;\r\nF_14 ( V_2 , V_44 , 0x00 ) ;\r\nF_14 ( V_2 , V_45 , 0x00 ) ;\r\nF_14 ( V_2 , V_46 , 0x00 ) ;\r\nbreak;\r\n}\r\nV_14 -> V_42 = V_39 ;\r\n}\r\nstatic void\r\nF_29 ( struct V_1 * V_2 )\r\n{\r\nF_30 ( L_6 ) ;\r\n}\r\nstatic void\r\nF_31 ( struct V_1 * V_2 )\r\n{\r\nF_30 ( L_6 ) ;\r\n}\r\nstatic bool\r\nF_32 ( struct V_1 * V_2 ,\r\nconst struct V_50 * V_39 ,\r\nstruct V_50 * V_51 )\r\n{\r\nreturn true ;\r\n}\r\nstatic int\r\nF_33 ( struct V_1 * V_2 ,\r\nstruct V_50 * V_39 )\r\n{\r\nreturn V_52 ;\r\n}\r\nstatic void\r\nF_34 ( struct V_1 * V_2 ,\r\nstruct V_50 * V_39 ,\r\nstruct V_50 * V_51 )\r\n{\r\nstruct V_13 * V_14 = F_2 ( V_2 ) ;\r\nT_1 V_53 , V_54 , V_55 , V_56 ;\r\nT_1 V_57 , V_58 , V_59 , V_60 ;\r\nT_1 V_61 , V_62 , V_63 ;\r\nT_2 V_12 , div , V_64 ;\r\nV_53 = V_39 -> V_65 - V_39 -> V_66 ;\r\nV_54 = V_39 -> V_67 - V_39 -> V_66 ;\r\nV_55 = 1 ;\r\nV_56 = 1 + V_39 -> V_68 - V_39 -> V_69 ;\r\nV_57 = V_39 -> V_70 - V_39 -> V_69 ;\r\nV_58 = V_57 + V_39 -> V_71 ;\r\nV_59 = V_39 -> V_72 - V_39 -> V_66 ;\r\nV_60 = V_39 -> V_72 ;\r\nV_63 = 0 ;\r\nif ( V_39 -> V_73 & V_74 )\r\nV_63 = ( V_39 -> V_72 / 2 ) + V_53 ;\r\nV_62 = 2 ;\r\nV_61 = 3 + V_53 ;\r\ndiv = 148500 / V_39 -> clock ;\r\nF_30 ( L_7 , V_39 -> clock , div ) ;\r\nF_30 ( L_8 ,\r\nV_53 , V_54 , V_55 , V_56 ) ;\r\nF_30 ( L_9 ,\r\nV_57 , V_58 , V_59 , V_60 ) ;\r\nF_30 ( L_10 ,\r\nV_62 , V_61 , V_63 ) ;\r\nF_16 ( V_2 , V_75 , V_76 ) ;\r\nF_16 ( V_2 , V_77 , V_78 ) ;\r\nF_17 ( V_2 , V_79 , V_80 ) ;\r\nF_14 ( V_2 , V_81 , F_35 ( 0 ) ) ;\r\nF_14 ( V_2 , V_82 , F_36 ( 0 ) |\r\nF_37 ( 0 ) ) ;\r\nF_14 ( V_2 , V_83 , F_38 ( 0 ) ) ;\r\nF_14 ( V_2 , V_84 , F_39 ( 0 ) |\r\nF_40 ( 0 ) ) ;\r\nF_17 ( V_2 , V_25 , V_85 ) ;\r\nF_17 ( V_2 , V_23 , V_86 ) ;\r\nF_17 ( V_2 , V_25 , V_87 ) ;\r\nF_14 ( V_2 , V_26 , 0 ) ;\r\nF_14 ( V_2 , V_88 , F_41 ( 0 ) ) ;\r\nV_64 = 0 ;\r\nF_14 ( V_2 , V_89 , 0 ) ;\r\nF_14 ( V_2 , V_30 , F_42 ( 0 ) |\r\nV_31 | V_32 ) ;\r\nF_14 ( V_2 , V_24 , F_20 ( div ) |\r\nF_43 ( V_64 ) ) ;\r\nF_15 ( V_2 , V_90 , V_63 ) ;\r\nF_15 ( V_2 , V_91 , V_63 ) ;\r\nF_16 ( V_2 , V_92 , V_93 ) ;\r\nF_14 ( V_2 , V_94 , 0x09 ) ;\r\nF_17 ( V_2 , V_95 , V_96 ) ;\r\nF_14 ( V_2 , V_97 , 0 ) ;\r\nF_16 ( V_2 , V_97 , V_98 ) ;\r\nif ( V_39 -> V_73 & V_99 )\r\nF_16 ( V_2 , V_97 , V_100 ) ;\r\nif ( V_39 -> V_73 & V_101 )\r\nF_16 ( V_2 , V_97 , V_102 ) ;\r\nF_14 ( V_2 , V_103 , 0x00 ) ;\r\nF_15 ( V_2 , V_104 , V_39 -> V_66 - 1 ) ;\r\nF_15 ( V_2 , V_105 , V_39 -> V_71 - 1 ) ;\r\nF_15 ( V_2 , V_106 , V_55 ) ;\r\nF_15 ( V_2 , V_107 , V_56 ) ;\r\nF_15 ( V_2 , V_108 , V_53 ) ;\r\nF_15 ( V_2 , V_109 , V_53 ) ;\r\nF_15 ( V_2 , V_110 , V_53 ) ;\r\nF_15 ( V_2 , V_111 , V_54 ) ;\r\nF_15 ( V_2 , V_112 , V_57 ) ;\r\nF_15 ( V_2 , V_113 , V_58 ) ;\r\nF_15 ( V_2 , V_114 , V_59 ) ;\r\nF_15 ( V_2 , V_115 , V_60 ) ;\r\nif ( V_14 -> V_116 == V_117 ) {\r\nF_14 ( V_2 , V_118 , 0x01 ) ;\r\n}\r\nF_15 ( V_2 , V_119 , V_61 ) ;\r\nF_15 ( V_2 , V_120 , V_62 ) ;\r\nV_12 = V_121 |\r\nV_122 |\r\nV_123 |\r\nV_78 |\r\nV_124 ;\r\nif ( V_39 -> V_73 & ( V_99 | V_101 ) )\r\nV_12 |= V_125 ;\r\nF_16 ( V_2 , V_77 , V_12 ) ;\r\nF_17 ( V_2 , V_95 , V_126 ) ;\r\n}\r\nstatic enum V_127\r\nF_44 ( struct V_1 * V_2 ,\r\nstruct V_128 * V_129 )\r\n{\r\nT_2 V_4 = F_6 ( V_2 , V_130 ) ;\r\nreturn ( V_4 & V_131 ) ? V_132 :\r\nV_133 ;\r\n}\r\nstatic int\r\nF_45 ( struct V_1 * V_2 , T_2 * V_8 , int V_134 )\r\n{\r\nT_2 V_135 , V_136 ;\r\nint V_9 , V_137 ;\r\nF_16 ( V_2 , V_138 , V_139 ) ;\r\nV_135 = ( V_134 & 1 ) ? 128 : 0 ;\r\nV_136 = V_134 / 2 ;\r\nF_14 ( V_2 , V_140 , 0xa0 ) ;\r\nF_14 ( V_2 , V_141 , V_135 ) ;\r\nF_14 ( V_2 , V_142 , 0x60 ) ;\r\nF_14 ( V_2 , V_143 , V_136 ) ;\r\nF_14 ( V_2 , V_144 , 0x1 ) ;\r\nF_14 ( V_2 , V_144 , 0x0 ) ;\r\nfor ( V_137 = 100 ; V_137 > 0 ; V_137 -- ) {\r\nT_2 V_4 = F_13 ( V_2 , V_138 ) ;\r\nif ( V_4 & V_139 )\r\nbreak;\r\nF_19 ( 1 ) ;\r\n}\r\nif ( V_137 == 0 )\r\nreturn - V_145 ;\r\nV_9 = F_11 ( V_2 , V_146 , V_8 , V_147 ) ;\r\nif ( V_9 != V_147 ) {\r\nF_5 ( V_2 -> V_10 -> V_10 , L_11 ,\r\nV_134 , V_9 ) ;\r\nreturn V_9 ;\r\n}\r\nF_17 ( V_2 , V_138 , V_139 ) ;\r\nreturn 0 ;\r\n}\r\nstatic T_2 *\r\nF_46 ( struct V_1 * V_2 )\r\n{\r\nint V_148 = 0 , V_149 = 0 ;\r\nT_2 * V_150 , * V_151 ;\r\nbool V_152 = V_153 & V_154 ;\r\nif ( ( V_150 = F_47 ( V_147 , V_155 ) ) == NULL )\r\nreturn NULL ;\r\nif ( F_45 ( V_2 , V_150 , 0 ) )\r\ngoto V_11;\r\nif ( ! F_48 ( V_150 , 0 , V_152 ) )\r\ngoto V_11;\r\nif ( V_150 [ 0x7e ] == 0 )\r\nreturn V_150 ;\r\nV_151 = F_49 ( V_150 , ( V_150 [ 0x7e ] + 1 ) * V_147 , V_155 ) ;\r\nif ( ! V_151 )\r\ngoto V_11;\r\nV_150 = V_151 ;\r\nfor ( V_148 = 1 ; V_148 <= V_150 [ 0x7e ] ; V_148 ++ ) {\r\nT_2 * V_156 = V_150 + ( V_149 + 1 ) * V_147 ;\r\nif ( F_45 ( V_2 , V_156 , V_148 ) )\r\ngoto V_11;\r\nif ( ! F_48 ( V_156 , V_148 , V_152 ) )\r\ngoto V_11;\r\nV_149 ++ ;\r\n}\r\nif ( V_149 != V_150 [ 0x7e ] ) {\r\nV_150 [ V_147 - 1 ] += V_150 [ 0x7e ] - V_149 ;\r\nV_150 [ 0x7e ] = V_149 ;\r\nV_151 = F_49 ( V_150 , ( V_149 + 1 ) * V_147 , V_155 ) ;\r\nif ( ! V_151 )\r\ngoto V_11;\r\nV_150 = V_151 ;\r\n}\r\nreturn V_150 ;\r\nV_11:\r\nF_50 ( V_2 -> V_10 -> V_10 , L_12 ) ;\r\nF_51 ( V_150 ) ;\r\nreturn NULL ;\r\n}\r\nstatic int\r\nF_52 ( struct V_1 * V_2 ,\r\nstruct V_128 * V_129 )\r\n{\r\nstruct V_157 * V_157 = (struct V_157 * ) F_46 ( V_2 ) ;\r\nint V_158 = 0 ;\r\nif ( V_157 ) {\r\nF_53 ( V_129 , V_157 ) ;\r\nV_158 = F_54 ( V_129 , V_157 ) ;\r\nF_51 ( V_157 ) ;\r\n}\r\nreturn V_158 ;\r\n}\r\nstatic int\r\nF_55 ( struct V_1 * V_2 ,\r\nstruct V_128 * V_129 )\r\n{\r\nF_30 ( L_6 ) ;\r\nreturn 0 ;\r\n}\r\nstatic int\r\nF_56 ( struct V_1 * V_2 ,\r\nstruct V_128 * V_129 ,\r\nstruct V_159 * V_160 ,\r\nT_3 V_4 )\r\n{\r\nF_30 ( L_6 ) ;\r\nreturn 0 ;\r\n}\r\nstatic void\r\nF_57 ( struct V_1 * V_2 )\r\n{\r\nstruct V_13 * V_14 = F_2 ( V_2 ) ;\r\nF_58 ( V_2 ) ;\r\nF_51 ( V_14 ) ;\r\n}\r\nstatic int\r\nF_59 ( struct V_5 * V_6 , const struct V_161 * V_162 )\r\n{\r\nreturn 0 ;\r\n}\r\nstatic int\r\nF_60 ( struct V_5 * V_6 )\r\n{\r\nreturn 0 ;\r\n}\r\nstatic int\r\nF_61 ( struct V_5 * V_6 ,\r\nstruct V_163 * V_10 ,\r\nstruct V_164 * V_165 )\r\n{\r\nstruct V_1 * V_2 = & V_165 -> V_166 ;\r\nstruct V_13 * V_14 ;\r\nV_14 = F_62 ( sizeof( * V_14 ) , V_155 ) ;\r\nif ( ! V_14 )\r\nreturn - V_167 ;\r\nV_14 -> V_15 = 0 ;\r\nV_14 -> V_7 = F_63 ( V_6 -> V_168 , 0x34 ) ;\r\nV_14 -> V_42 = V_41 ;\r\nV_165 -> V_169 = V_14 ;\r\nV_165 -> V_170 = & V_171 ;\r\nF_1 ( V_2 , V_172 ,\r\nV_173 | V_174 ) ;\r\nF_18 ( V_2 ) ;\r\nV_14 -> V_116 = F_13 ( V_2 , V_175 ) |\r\nF_13 ( V_2 , V_176 ) << 8 ;\r\nV_14 -> V_116 &= ~ 0x30 ;\r\nswitch ( V_14 -> V_116 ) {\r\ncase V_177 : F_64 ( V_10 -> V_10 , L_13 ) ; break;\r\ncase V_178 : F_64 ( V_10 -> V_10 , L_14 ) ; break;\r\ncase V_179 : F_64 ( V_10 -> V_10 , L_15 ) ; break;\r\ncase V_117 : F_64 ( V_10 -> V_10 , L_16 ) ; break;\r\ndefault:\r\nF_30 ( L_17 , V_14 -> V_116 ) ;\r\ngoto V_11;\r\n}\r\nF_14 ( V_2 , V_180 , 0x00 ) ;\r\nF_14 ( V_2 , V_181 , 39 ) ;\r\nif ( V_14 -> V_116 == V_178 )\r\nF_16 ( V_2 , V_182 , V_183 ) ;\r\nF_1 ( V_2 , V_184 ,\r\nV_185 | V_186 ) ;\r\nreturn 0 ;\r\nV_11:\r\nif ( V_14 -> V_7 )\r\nF_65 ( V_14 -> V_7 ) ;\r\nF_51 ( V_14 ) ;\r\nV_165 -> V_169 = NULL ;\r\nV_165 -> V_170 = NULL ;\r\nreturn - V_187 ;\r\n}\r\nstatic int T_4\r\nF_66 ( void )\r\n{\r\nF_30 ( L_6 ) ;\r\nreturn F_67 ( V_188 , & V_189 ) ;\r\n}\r\nstatic void T_5\r\nF_68 ( void )\r\n{\r\nF_30 ( L_6 ) ;\r\nF_69 ( & V_189 ) ;\r\n}
