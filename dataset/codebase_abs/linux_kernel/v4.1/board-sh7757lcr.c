static void F_1 ( void * V_1 )
{
if ( ( ( unsigned long ) V_1 & 0x00000fff ) < 0x0800 )
F_2 ( F_3 ( V_2 ) | V_3 , V_2 ) ;
else
F_2 ( F_3 ( V_2 ) | V_4 , V_2 ) ;
}
static void F_4 ( void * V_1 )
{
if ( ( ( unsigned long ) V_1 & 0x00000fff ) < 0x0800 ) {
F_5 ( V_5 , 1 ) ;
F_2 ( F_3 ( V_2 ) & ~ V_3 , V_2 ) ;
} else {
F_5 ( V_5 , 0 ) ;
F_2 ( F_3 ( V_2 ) & ~ V_4 , V_2 ) ;
}
}
static int F_6 ( struct V_6 * V_7 )
{
return V_8 ;
}
static int T_1 F_7 ( void )
{
F_8 ( 0 , L_1 , V_9 ,
F_9 ( V_9 ) , 3300000 ) ;
F_10 ( V_10 , NULL ) ;
F_10 ( V_11 , NULL ) ;
F_10 ( V_12 , NULL ) ;
F_10 ( V_13 , NULL ) ;
F_10 ( V_14 , NULL ) ;
F_10 ( V_15 , NULL ) ;
F_10 ( V_16 , NULL ) ;
F_10 ( V_17 , NULL ) ;
F_10 ( V_18 , NULL ) ;
F_10 ( V_19 , NULL ) ;
F_10 ( V_20 , NULL ) ;
F_10 ( V_21 , NULL ) ;
F_10 ( V_22 , NULL ) ;
F_10 ( V_23 , NULL ) ;
F_10 ( V_24 , NULL ) ;
F_10 ( V_25 , NULL ) ;
F_10 ( V_26 , NULL ) ;
F_10 ( V_27 , NULL ) ;
F_10 ( V_28 , NULL ) ;
F_10 ( V_29 , NULL ) ;
F_10 ( V_30 , NULL ) ;
F_10 ( V_31 , NULL ) ;
F_10 ( V_32 , NULL ) ;
F_10 ( V_33 , NULL ) ;
F_10 ( V_34 , NULL ) ;
F_10 ( V_35 , NULL ) ;
F_10 ( V_36 , NULL ) ;
F_10 ( V_37 , NULL ) ;
F_10 ( V_38 , NULL ) ;
F_10 ( V_39 , NULL ) ;
F_10 ( V_40 , NULL ) ;
F_10 ( V_41 , NULL ) ;
F_10 ( V_42 , NULL ) ;
F_10 ( V_43 , NULL ) ;
F_10 ( V_44 , NULL ) ;
F_10 ( V_45 , NULL ) ;
F_10 ( V_46 , NULL ) ;
F_10 ( V_47 , NULL ) ;
F_10 ( V_48 , NULL ) ;
F_10 ( V_49 , NULL ) ;
F_10 ( V_50 , NULL ) ;
F_10 ( V_51 , NULL ) ;
F_10 ( V_52 , NULL ) ;
F_10 ( V_53 , NULL ) ;
F_10 ( V_54 , NULL ) ;
F_10 ( V_55 , NULL ) ;
F_10 ( V_56 , NULL ) ;
F_10 ( V_57 , NULL ) ;
F_10 ( V_58 , NULL ) ;
F_10 ( V_59 , NULL ) ;
F_10 ( V_60 , NULL ) ;
F_10 ( V_61 , NULL ) ;
F_10 ( V_62 , NULL ) ;
F_10 ( V_63 , NULL ) ;
F_10 ( V_64 , NULL ) ;
F_10 ( V_65 , NULL ) ;
F_10 ( V_66 , NULL ) ;
F_10 ( V_67 , NULL ) ;
F_10 ( V_68 , NULL ) ;
F_10 ( V_69 , NULL ) ;
F_10 ( V_70 , NULL ) ;
F_10 ( V_71 , NULL ) ;
F_10 ( V_72 , NULL ) ;
F_10 ( V_73 , NULL ) ;
F_10 ( V_74 , NULL ) ;
F_10 ( V_75 , NULL ) ;
F_10 ( V_76 , NULL ) ;
F_10 ( V_77 , NULL ) ;
F_10 ( V_78 , NULL ) ;
F_10 ( V_79 , NULL ) ;
F_10 ( V_80 , NULL ) ;
F_10 ( V_81 , NULL ) ;
F_10 ( V_82 , NULL ) ;
F_10 ( V_83 , NULL ) ;
F_10 ( V_84 , NULL ) ;
F_10 ( V_85 , NULL ) ;
F_10 ( V_86 , NULL ) ;
F_10 ( V_87 , NULL ) ;
F_10 ( V_88 , NULL ) ;
F_10 ( V_89 , NULL ) ;
F_10 ( V_90 , NULL ) ;
F_10 ( V_91 , NULL ) ;
F_10 ( V_92 , NULL ) ;
F_10 ( V_93 , NULL ) ;
F_10 ( V_94 , NULL ) ;
F_10 ( V_95 , NULL ) ;
F_10 ( V_96 , NULL ) ;
F_10 ( V_97 , NULL ) ;
F_10 ( V_98 , NULL ) ;
F_10 ( V_99 , NULL ) ;
F_10 ( V_100 , NULL ) ;
F_10 ( V_101 , NULL ) ;
F_10 ( V_102 , NULL ) ;
F_10 ( V_103 , NULL ) ;
F_10 ( V_104 , NULL ) ;
F_10 ( V_105 , NULL ) ;
F_10 ( V_106 , NULL ) ;
F_10 ( V_107 , NULL ) ;
F_10 ( V_108 , NULL ) ;
F_10 ( V_109 , NULL ) ;
F_10 ( V_110 , NULL ) ;
F_10 ( V_111 , NULL ) ;
F_10 ( V_112 , NULL ) ;
F_10 ( V_113 , NULL ) ;
F_10 ( V_114 , NULL ) ;
F_10 ( V_115 , NULL ) ;
F_10 ( V_116 , NULL ) ;
F_10 ( V_117 , NULL ) ;
F_10 ( V_118 , NULL ) ;
F_10 ( V_119 , NULL ) ;
F_10 ( V_120 , NULL ) ;
F_10 ( V_121 , NULL ) ;
F_10 ( V_122 , NULL ) ;
F_10 ( V_123 , NULL ) ;
F_10 ( V_124 , NULL ) ;
F_10 ( V_125 , NULL ) ;
F_10 ( V_126 , NULL ) ;
F_10 ( V_127 , NULL ) ;
F_10 ( V_128 , NULL ) ;
F_11 ( 0x10 , 0xfe470000 ) ;
F_10 ( V_129 , NULL ) ;
F_10 ( V_130 , NULL ) ;
F_10 ( V_131 , NULL ) ;
F_10 ( V_132 , NULL ) ;
F_10 ( V_133 , NULL ) ;
F_10 ( V_134 , NULL ) ;
F_10 ( V_135 , NULL ) ;
F_10 ( V_136 , NULL ) ;
F_10 ( V_137 , NULL ) ;
F_10 ( V_138 , NULL ) ;
F_10 ( V_139 , NULL ) ;
F_10 ( V_140 , NULL ) ;
F_10 ( V_141 , NULL ) ;
F_10 ( V_142 , NULL ) ;
F_10 ( V_143 , NULL ) ;
F_10 ( V_144 , NULL ) ;
F_10 ( V_145 , NULL ) ;
F_10 ( V_146 , NULL ) ;
F_10 ( V_147 , NULL ) ;
F_10 ( V_148 , NULL ) ;
F_10 ( V_149 , NULL ) ;
F_10 ( V_150 , NULL ) ;
F_10 ( V_151 , NULL ) ;
F_10 ( V_152 , NULL ) ;
F_10 ( V_153 , NULL ) ;
F_10 ( V_154 , NULL ) ;
F_10 ( V_155 , NULL ) ;
F_10 ( V_156 , NULL ) ;
F_10 ( V_157 , NULL ) ;
F_10 ( V_158 , NULL ) ;
F_10 ( V_159 , NULL ) ;
F_10 ( V_160 , NULL ) ;
F_10 ( V_161 , NULL ) ;
F_10 ( V_162 , NULL ) ;
F_10 ( V_163 , NULL ) ;
F_10 ( V_164 , NULL ) ;
F_10 ( V_165 , NULL ) ;
F_10 ( V_166 , NULL ) ;
F_10 ( V_167 , NULL ) ;
F_10 ( V_168 , NULL ) ;
F_10 ( V_169 , NULL ) ;
F_10 ( V_170 , NULL ) ;
F_10 ( V_171 , NULL ) ;
F_10 ( V_172 , NULL ) ;
F_10 ( V_173 , NULL ) ;
F_12 ( V_173 , 1 ) ;
F_10 ( V_174 , NULL ) ;
F_12 ( V_174 , 1 ) ;
F_10 ( V_175 , NULL ) ;
F_12 ( V_175 , 1 ) ;
F_10 ( V_176 , NULL ) ;
F_12 ( V_176 , 1 ) ;
F_10 ( V_5 , NULL ) ;
F_12 ( V_5 , 1 ) ;
F_10 ( V_177 , NULL ) ;
F_12 ( V_177 , 0 ) ;
F_10 ( V_178 , NULL ) ;
F_12 ( V_178 , 0 ) ;
F_10 ( V_179 , NULL ) ;
F_12 ( V_179 , 1 ) ;
F_13 ( V_180 ,
F_9 ( V_180 ) ) ;
return F_14 ( V_181 ,
F_9 ( V_181 ) ) ;
}
void T_1 F_15 ( void )
{
F_16 ( V_182 ) ;
F_16 ( V_183 ) ;
}
static void T_1 F_17 ( char * * V_184 )
{
F_18 ( V_185 L_2 ) ;
}
static int F_19 ( void )
{
int V_186 = 0 ;
V_186 |= V_187 ;
return V_186 ;
}
