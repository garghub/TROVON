static struct V_1 * F_1 ( struct V_2 * V_3 ,\r\nvoid * V_4 , unsigned V_5 , int V_6 )\r\n{\r\nstruct V_1 * V_7 ;\r\nstruct V_8 * V_9 = V_3 -> V_8 ;\r\nV_7 = F_2 ( V_9 , V_6 , V_10 ) ;\r\nif ( F_3 ( V_7 ) ) {\r\nF_4 ( V_11 , V_3 ,\r\nL_1 ) ;\r\nreturn NULL ;\r\n}\r\nF_5 ( V_7 ) ;\r\nif ( V_5 && F_6 ( V_9 , V_7 , V_4 , V_5 , V_10 ) ) {\r\nF_7 ( V_7 ) ;\r\nF_4 ( V_11 , V_3 ,\r\nL_2 ) ;\r\nreturn NULL ;\r\n}\r\nV_7 -> V_12 |= V_13 | V_14 |\r\nV_15 ;\r\nV_7 -> V_16 = V_17 ;\r\nV_7 -> V_18 = V_19 ;\r\nreturn V_7 ;\r\n}\r\nstatic struct V_1 * F_8 ( struct V_2 * V_3 ,\r\nstruct V_20 * V_21 , struct V_22 * V_23 )\r\n{\r\nstruct V_1 * V_7 ;\r\nstruct V_24 * V_25 ;\r\nunsigned V_26 ;\r\nstruct V_27 * V_28 ;\r\nT_1 * V_29 ;\r\nif ( V_21 -> V_30 -> V_31 ) {\r\nstruct V_32 * V_33 ;\r\nV_26 = sizeof( struct V_32 ) ;\r\nV_33 = & V_21 -> V_30 -> V_34 . V_35 ;\r\nmemset ( V_33 , 0 , V_26 ) ;\r\nV_25 = & V_33 -> V_25 ;\r\nV_33 -> V_36 = V_37 + 0x40 ;\r\nV_33 -> V_38 = 0x1 ;\r\nV_33 -> V_39 [ 0 ] = 0x01 ;\r\nV_33 -> V_39 [ 1 ] = 0x28 ;\r\nV_29 = V_33 -> V_29 ;\r\n} else {\r\nstruct V_40 * V_33 ;\r\nV_26 = sizeof( struct V_40 ) ;\r\nV_33 = & V_21 -> V_30 -> V_34 . V_41 ;\r\nmemset ( V_33 , 0 , V_26 ) ;\r\nV_25 = & V_33 -> V_25 ;\r\nV_33 -> V_36 = V_37 ;\r\nV_33 -> V_39 = 0x68 ;\r\nV_29 = V_33 -> V_29 ;\r\n}\r\nV_25 -> V_42 [ 1 ] = V_43 ;\r\nV_25 -> V_44 = V_45 ;\r\nV_25 -> V_46 = V_47 ;\r\nF_9 (qdata, list, entry) {\r\nV_29 [ V_28 -> V_21 -> V_48 ] = 0x81 ;\r\n}\r\nV_7 = F_1 ( V_3 , & V_21 -> V_30 -> V_34 , V_26 , V_49 ) ;\r\nif ( ! V_7 )\r\nreturn NULL ;\r\nif ( V_21 -> V_30 -> V_31 ) {\r\nV_7 -> V_50 [ 0 ] = V_51 ;\r\nV_7 -> V_50 [ 7 ] = V_26 >> 8 ;\r\nV_7 -> V_50 [ 8 ] = V_26 & 0xff ;\r\n} else {\r\nV_7 -> V_50 [ 0 ] = V_52 ;\r\nV_7 -> V_50 [ 4 ] = V_26 ;\r\n}\r\nV_7 -> V_53 = F_10 ( V_7 -> V_50 [ 0 ] ) ;\r\nV_7 -> V_54 = V_21 -> V_54 ;\r\nmemset ( V_7 -> V_54 , 0 , V_55 ) ;\r\nV_7 -> V_56 = 0 ;\r\nreturn V_7 ;\r\n}\r\nstatic void F_11 ( struct V_57 * V_57 )\r\n{\r\nstruct V_58 * V_30 ;\r\nV_30 = F_12 ( V_57 , struct V_58 , V_57 ) ;\r\nF_13 ( & V_30 -> V_59 ) ;\r\nF_14 ( V_30 ) ;\r\n}\r\nstatic struct V_58 * F_15 ( int V_60 , char * V_61 ,\r\nT_1 * V_62 , struct V_2 * V_3 )\r\n{\r\nstruct V_58 * V_30 , * V_63 ;\r\nF_9 (tmp, &ctlr_list, node) {\r\nif ( ( memcmp ( V_63 -> V_62 , V_62 , V_64 ) == 0 ) &&\r\n( V_63 -> V_60 == V_60 ) &&\r\n( V_63 -> V_65 == V_3 -> V_65 ) ) {\r\nF_16 ( & V_63 -> V_57 ) ;\r\nreturn V_63 ;\r\n}\r\n}\r\nV_30 = F_17 ( sizeof( * V_30 ) , V_66 ) ;\r\nif ( ! V_30 )\r\nreturn NULL ;\r\nmemcpy ( V_30 -> V_62 , V_62 , V_64 ) ;\r\nV_30 -> V_60 = V_60 ;\r\nV_30 -> V_65 = V_3 -> V_65 ;\r\nmemcpy ( V_30 -> V_61 , V_61 , V_67 ) ;\r\nF_18 ( & V_30 -> V_57 ) ;\r\nV_30 -> V_31 = - 1 ;\r\nV_30 -> V_68 = 0 ;\r\nV_30 -> V_69 = NULL ;\r\nF_19 ( & V_30 -> V_70 ) ;\r\nF_20 ( & V_30 -> V_71 , V_72 ) ;\r\nF_21 ( & V_30 -> V_73 ) ;\r\nF_22 ( & V_30 -> V_59 , & V_74 ) ;\r\nreturn V_30 ;\r\n}\r\nstatic int F_23 ( struct V_2 * V_3 , int V_36 ,\r\nunsigned int V_75 , struct V_20 * V_21 )\r\n{\r\nstruct V_1 * V_7 ;\r\nstruct V_8 * V_9 = V_3 -> V_8 ;\r\nint V_76 = V_77 ;\r\nV_7 = F_1 ( V_3 , & V_21 -> V_78 , V_75 , V_79 ) ;\r\nif ( ! V_7 )\r\ngoto V_80;\r\nV_7 -> V_50 [ 0 ] = V_81 ;\r\nV_7 -> V_50 [ 1 ] = 1 ;\r\nV_7 -> V_50 [ 2 ] = V_36 ;\r\nV_7 -> V_50 [ 4 ] = V_75 ;\r\nV_7 -> V_53 = F_10 ( V_81 ) ;\r\nV_7 -> V_54 = V_21 -> V_54 ;\r\nmemset ( V_7 -> V_54 , 0 , V_55 ) ;\r\nV_7 -> V_56 = 0 ;\r\nV_76 = F_24 ( V_9 , NULL , V_7 , 1 ) ;\r\nif ( V_76 == - V_82 )\r\nV_76 = V_83 ;\r\nF_7 ( V_7 ) ;\r\nV_80:\r\nreturn V_76 ;\r\n}\r\nstatic int F_25 ( struct V_2 * V_3 , struct V_20 * V_21 ,\r\nchar * V_61 , T_1 * V_62 )\r\n{\r\nint V_76 , V_84 ;\r\nstruct V_85 * V_86 ;\r\nV_76 = F_23 ( V_3 , 0xC8 , sizeof( struct V_85 ) , V_21 ) ;\r\nif ( V_76 == V_87 ) {\r\nV_86 = & V_21 -> V_78 . V_88 ;\r\nif ( V_86 -> V_36 != 0xc8 )\r\nreturn V_89 ;\r\nif ( V_86 -> V_90 [ 0 ] != 'e' || V_86 -> V_90 [ 1 ] != 'd' ||\r\nV_86 -> V_90 [ 2 ] != 'i' || V_86 -> V_90 [ 3 ] != 'd' )\r\nreturn V_89 ;\r\nV_21 -> V_48 = V_86 -> V_48 [ 7 ] ;\r\nfor( V_84 = 0 ; V_84 < V_67 - 1 ; ++ V_84 )\r\n* ( V_61 + V_84 ) = V_86 -> V_91 [ ( 2 * V_84 ) + 1 ] ;\r\n* ( V_61 + V_67 - 1 ) = '\0' ;\r\nmemset ( V_62 , 0 , V_64 ) ;\r\nmemcpy ( V_62 , V_86 -> V_92 , V_86 -> V_93 ) ;\r\n}\r\nreturn V_76 ;\r\n}\r\nstatic int F_26 ( struct V_2 * V_3 , struct V_20 * V_21 )\r\n{\r\nint V_76 ;\r\nstruct V_94 * V_86 ;\r\nV_21 -> V_95 = V_96 ;\r\nV_76 = F_23 ( V_3 , 0xC9 , sizeof( struct V_94 ) , V_21 ) ;\r\nif ( V_76 == V_87 ) {\r\nV_86 = & V_21 -> V_78 . V_97 ;\r\nif ( ( V_86 -> V_98 >> 5 ) & 0x1 )\r\nV_21 -> V_99 = V_100 ;\r\nelse if ( V_86 -> V_98 >> 7 )\r\nV_21 -> V_99 = V_101 ;\r\nelse\r\nV_21 -> V_99 = V_102 ;\r\nif ( V_86 -> V_98 & 0x1 )\r\nV_21 -> V_103 = V_104 ;\r\nelse {\r\nV_21 -> V_103 = V_105 ;\r\nif ( V_21 -> V_99 == V_102 )\r\nV_21 -> V_95 = V_106 ;\r\n}\r\nif ( V_86 -> V_107 & 0x1 )\r\nV_21 -> V_108 = V_109 ;\r\nelse\r\nV_21 -> V_108 = V_110 ;\r\n}\r\nreturn V_76 ;\r\n}\r\nstatic int F_27 ( struct V_2 * V_3 ,\r\nstruct V_20 * V_21 , char * V_61 , T_1 * V_62 )\r\n{\r\nint V_76 , V_60 ;\r\nstruct V_111 * V_86 ;\r\nV_76 = F_23 ( V_3 , 0xC4 , sizeof( struct V_111 ) , V_21 ) ;\r\nif ( V_76 == V_87 ) {\r\nV_86 = & V_21 -> V_78 . V_112 ;\r\nif ( V_86 -> V_113 [ 1 ] == 0x31 )\r\nV_60 = 0 ;\r\nelse\r\nV_60 = 1 ;\r\nF_28 ( & V_114 ) ;\r\nV_21 -> V_30 = F_15 ( V_60 , V_61 , V_62 , V_3 ) ;\r\nif ( ! V_21 -> V_30 )\r\nV_76 = V_77 ;\r\nF_29 ( & V_114 ) ;\r\n}\r\nreturn V_76 ;\r\n}\r\nstatic int F_30 ( struct V_2 * V_3 , struct V_20 * V_21 )\r\n{\r\nint V_76 ;\r\nstruct V_115 * V_86 ;\r\nV_76 = F_23 ( V_3 , 0xC2 , sizeof( struct V_115 ) , V_21 ) ;\r\nif ( V_76 == V_87 ) {\r\nV_86 = & V_21 -> V_78 . V_116 ;\r\nif ( V_86 -> V_117 >= V_118 )\r\nV_21 -> V_30 -> V_31 = 1 ;\r\nelse\r\nV_21 -> V_30 -> V_31 = 0 ;\r\n}\r\nreturn V_76 ;\r\n}\r\nstatic int F_31 ( struct V_2 * V_3 ,\r\nunsigned char * V_119 )\r\n{\r\nstruct V_120 V_121 ;\r\nint V_76 = V_83 , V_122 ;\r\nstruct V_20 * V_21 = V_3 -> V_123 ;\r\nV_122 = F_32 ( V_119 , V_55 , & V_121 ) ;\r\nif ( ! V_122 )\r\ngoto V_80;\r\nswitch ( V_121 . V_124 ) {\r\ncase V_125 :\r\ncase V_126 :\r\ncase V_127 :\r\nV_76 = V_128 ;\r\nbreak;\r\ncase V_129 :\r\nif ( V_121 . V_130 == 0x04 && V_121 . V_131 == 0x01 )\r\nV_76 = V_128 ;\r\nbreak;\r\ncase V_132 :\r\nif ( V_121 . V_130 == 0x91 && V_121 . V_131 == 0x36 )\r\nV_76 = V_128 ;\r\nbreak;\r\ndefault:\r\nbreak;\r\n}\r\nF_33 ( V_133 , V_3 , L_3\r\nL_4 ,\r\n( char * ) V_21 -> V_30 -> V_61 , V_21 -> V_30 -> V_60 ,\r\nV_121 . V_124 , V_121 . V_130 , V_121 . V_131 ) ;\r\nV_80:\r\nreturn V_76 ;\r\n}\r\nstatic void V_72 ( struct V_134 * V_135 )\r\n{\r\nstruct V_58 * V_30 =\r\nF_12 ( V_135 , struct V_58 , V_71 ) ;\r\nstruct V_1 * V_7 ;\r\nstruct V_2 * V_3 = V_30 -> V_69 ;\r\nstruct V_20 * V_21 = V_3 -> V_123 ;\r\nstruct V_8 * V_9 = V_3 -> V_8 ;\r\nint V_76 , V_136 = V_137 ;\r\nstruct V_27 * V_63 , * V_28 ;\r\nF_34 ( V_23 ) ;\r\nF_28 ( & V_30 -> V_70 ) ;\r\nF_35 ( & V_30 -> V_73 , & V_23 ) ;\r\nV_30 -> V_68 = 0 ;\r\nV_30 -> V_69 = NULL ;\r\nF_29 ( & V_30 -> V_70 ) ;\r\nV_138:\r\nV_76 = V_77 ;\r\nV_7 = F_8 ( V_3 , V_21 , & V_23 ) ;\r\nif ( ! V_7 )\r\ngoto V_80;\r\nF_33 ( V_133 , V_3 , L_3\r\nL_5 ,\r\n( char * ) V_21 -> V_30 -> V_61 , V_21 -> V_30 -> V_60 ,\r\n( V_136 == V_137 ) ? L_6 : L_7 ) ;\r\nV_76 = F_24 ( V_9 , NULL , V_7 , 1 ) ;\r\nF_7 ( V_7 ) ;\r\nif ( V_76 != V_87 ) {\r\nV_76 = F_31 ( V_3 , V_21 -> V_54 ) ;\r\nif ( V_76 == V_128 && V_136 -- )\r\ngoto V_138;\r\n}\r\nif ( V_76 == V_87 ) {\r\nV_21 -> V_95 = V_96 ;\r\nF_33 ( V_133 , V_3 , L_3\r\nL_8 ,\r\n( char * ) V_21 -> V_30 -> V_61 , V_21 -> V_30 -> V_60 ) ;\r\n}\r\nV_80:\r\nF_36 (qdata, tmp, &list, entry) {\r\nF_13 ( & V_28 -> V_139 ) ;\r\nif ( V_76 == V_87 )\r\nV_28 -> V_21 -> V_95 = V_96 ;\r\nif ( V_28 -> V_140 )\r\nV_28 -> V_140 ( V_28 -> V_141 , V_76 ) ;\r\nF_14 ( V_28 ) ;\r\n}\r\nreturn;\r\n}\r\nstatic int F_37 ( struct V_2 * V_3 ,\r\nT_2 V_142 , void * V_143 )\r\n{\r\nstruct V_27 * V_28 ;\r\nstruct V_58 * V_30 ;\r\nV_28 = F_38 ( sizeof( * V_28 ) , V_144 ) ;\r\nif ( ! V_28 )\r\nreturn V_128 ;\r\nV_28 -> V_21 = V_3 -> V_123 ;\r\nV_28 -> V_140 = V_142 ;\r\nV_28 -> V_141 = V_143 ;\r\nV_30 = V_28 -> V_21 -> V_30 ;\r\nF_28 ( & V_30 -> V_70 ) ;\r\nF_39 ( & V_28 -> V_139 , & V_30 -> V_73 ) ;\r\nif ( ! V_30 -> V_68 ) {\r\nV_30 -> V_68 = 1 ;\r\nV_30 -> V_69 = V_3 ;\r\nF_40 ( V_145 , & V_30 -> V_71 ) ;\r\n}\r\nF_29 ( & V_30 -> V_70 ) ;\r\nreturn V_87 ;\r\n}\r\nstatic int F_41 ( struct V_2 * V_3 ,\r\nT_2 V_142 , void * V_143 )\r\n{\r\nstruct V_20 * V_21 = V_3 -> V_123 ;\r\nint V_76 = V_87 ;\r\nint V_146 = 0 ;\r\nV_76 = F_26 ( V_3 , V_21 ) ;\r\nif ( V_76 != V_87 )\r\ngoto V_80;\r\nswitch ( V_21 -> V_99 ) {\r\ncase V_102 :\r\nif ( V_21 -> V_103 == V_105 )\r\nV_146 = 1 ;\r\nbreak;\r\ncase V_100 :\r\nif ( ( V_21 -> V_103 == V_105 ) &&\r\n( V_21 -> V_108 == V_109 ) )\r\nV_146 = 1 ;\r\nbreak;\r\ndefault:\r\nbreak;\r\n}\r\nif ( V_146 ) {\r\nV_76 = F_37 ( V_3 , V_142 , V_143 ) ;\r\nif ( V_76 == V_87 )\r\nreturn 0 ;\r\n}\r\nV_80:\r\nif ( V_142 )\r\nV_142 ( V_143 , V_76 ) ;\r\nreturn 0 ;\r\n}\r\nstatic int F_42 ( struct V_2 * V_3 , struct V_1 * V_147 )\r\n{\r\nstruct V_20 * V_21 = V_3 -> V_123 ;\r\nint V_122 = V_148 ;\r\nif ( V_21 -> V_95 != V_96 ) {\r\nV_122 = V_149 ;\r\nV_147 -> V_12 |= V_150 ;\r\n}\r\nreturn V_122 ;\r\n}\r\nstatic int F_43 ( struct V_2 * V_3 ,\r\nstruct V_120 * V_121 )\r\n{\r\nstruct V_20 * V_21 = V_3 -> V_123 ;\r\nF_33 ( V_151 , V_3 , L_3\r\nL_9 ,\r\n( char * ) V_21 -> V_30 -> V_61 , V_21 -> V_30 -> V_60 ,\r\nV_121 -> V_124 , V_121 -> V_130 , V_121 -> V_131 ) ;\r\nswitch ( V_121 -> V_124 ) {\r\ncase V_129 :\r\nif ( V_121 -> V_130 == 0x04 && V_121 -> V_131 == 0x01 )\r\nreturn V_152 ;\r\nif ( V_121 -> V_130 == 0x04 && V_121 -> V_131 == 0x81 )\r\nreturn V_153 ;\r\nif ( V_121 -> V_130 == 0x04 && V_121 -> V_131 == 0xA1 )\r\nreturn V_152 ;\r\nif ( V_121 -> V_130 == 0xA1 && V_121 -> V_131 == 0x02 )\r\nreturn V_152 ;\r\nbreak;\r\ncase V_132 :\r\nif ( V_121 -> V_130 == 0x94 && V_121 -> V_131 == 0x01 ) {\r\nV_21 -> V_95 = V_106 ;\r\nreturn V_153 ;\r\n}\r\nbreak;\r\ncase V_127 :\r\nif ( V_121 -> V_130 == 0x29 && V_121 -> V_131 == 0x00 )\r\nreturn V_152 ;\r\nif ( V_121 -> V_130 == 0x8b && V_121 -> V_131 == 0x02 )\r\nreturn V_152 ;\r\nbreak;\r\n}\r\nreturn V_154 ;\r\n}\r\nstatic int F_44 ( struct V_2 * V_3 )\r\n{\r\nstruct V_20 * V_21 ;\r\nint V_76 ;\r\nchar V_61 [ V_67 ] ;\r\nchar V_62 [ V_64 ] ;\r\nV_21 = F_38 ( sizeof( * V_21 ) , V_144 ) ;\r\nif ( ! V_21 )\r\nreturn - V_155 ;\r\nV_21 -> V_48 = V_156 ;\r\nV_21 -> V_95 = V_96 ;\r\nV_76 = F_25 ( V_3 , V_21 , V_61 , V_62 ) ;\r\nif ( V_76 != V_87 )\r\ngoto V_157;\r\nV_76 = F_27 ( V_3 , V_21 , V_61 , V_62 ) ;\r\nif ( V_76 != V_87 )\r\ngoto V_157;\r\nV_76 = F_26 ( V_3 , V_21 ) ;\r\nif ( V_76 != V_87 )\r\ngoto V_158;\r\nV_76 = F_30 ( V_3 , V_21 ) ;\r\nif ( V_76 != V_87 )\r\ngoto V_158;\r\nF_4 ( V_159 , V_3 ,\r\nL_10 ,\r\nV_160 , V_21 -> V_48 , V_99 [ ( int ) V_21 -> V_99 ] ,\r\nV_103 [ ( int ) V_21 -> V_103 ] ) ;\r\nV_3 -> V_123 = V_21 ;\r\nreturn 0 ;\r\nV_158:\r\nF_28 ( & V_114 ) ;\r\nF_45 ( & V_21 -> V_30 -> V_57 , F_11 ) ;\r\nF_29 ( & V_114 ) ;\r\nV_157:\r\nF_14 ( V_21 ) ;\r\nreturn - V_161 ;\r\n}\r\nstatic void F_46 ( struct V_2 * V_3 )\r\n{\r\nstruct V_20 * V_21 = V_3 -> V_123 ;\r\nif ( V_21 -> V_30 && V_21 -> V_30 -> V_68 )\r\nF_47 ( V_145 ) ;\r\nF_28 ( & V_114 ) ;\r\nif ( V_21 -> V_30 )\r\nF_45 ( & V_21 -> V_30 -> V_57 , F_11 ) ;\r\nF_29 ( & V_114 ) ;\r\nV_3 -> V_123 = NULL ;\r\nF_14 ( V_21 ) ;\r\n}\r\nstatic int T_3 F_48 ( void )\r\n{\r\nint V_162 ;\r\nV_162 = F_49 ( & V_163 ) ;\r\nif ( V_162 != 0 ) {\r\nF_50 ( V_164 L_11 ) ;\r\ngoto V_80;\r\n}\r\nV_145 = F_51 ( L_12 ) ;\r\nif ( ! V_145 ) {\r\nF_52 ( & V_163 ) ;\r\nF_50 ( V_164 L_13 ) ;\r\nV_162 = - V_161 ;\r\n}\r\nV_80:\r\nreturn V_162 ;\r\n}\r\nstatic void T_4 F_53 ( void )\r\n{\r\nF_54 ( V_145 ) ;\r\nF_52 ( & V_163 ) ;\r\n}
