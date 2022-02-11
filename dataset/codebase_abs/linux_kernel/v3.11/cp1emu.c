static int F_1 ( union V_1 * V_2 )
{
union V_1 V_3 = * V_2 ;
union V_1 V_4 = V_3 ;
int V_5 , V_6 , V_7 ;
switch ( V_3 . V_8 . V_9 ) {
case V_10 :
V_4 . V_8 . V_9 = V_11 ;
V_4 . V_8 . V_12 = V_3 . V_8 . V_13 ;
V_4 . V_8 . V_13 = V_3 . V_8 . V_12 ;
break;
case V_14 :
V_4 . V_8 . V_9 = V_15 ;
V_4 . V_8 . V_12 = V_3 . V_8 . V_13 ;
V_4 . V_8 . V_13 = V_3 . V_8 . V_12 ;
break;
case V_16 :
V_4 . V_8 . V_9 = V_17 ;
V_4 . V_8 . V_12 = V_3 . V_8 . V_13 ;
V_4 . V_8 . V_13 = V_3 . V_8 . V_12 ;
break;
case V_18 :
V_4 . V_8 . V_9 = V_19 ;
V_4 . V_8 . V_12 = V_3 . V_8 . V_13 ;
V_4 . V_8 . V_13 = V_3 . V_8 . V_12 ;
break;
case V_20 :
if ( ( V_3 . V_8 . V_12 == V_21 ) ||
( V_3 . V_8 . V_12 == V_22 ) ) {
V_4 . V_23 . V_9 = V_24 ;
V_4 . V_23 . V_25 = V_26 ;
V_4 . V_23 . V_27 =
( V_3 . V_8 . V_12 == V_22 ) ? 1 : 0 ;
} else
return V_28 ;
break;
case V_29 :
switch ( V_3 . V_30 . V_5 ) {
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
V_7 = V_3 . V_30 . V_5 ;
if ( V_7 == V_31 )
V_5 = V_39 ;
else if ( V_7 == V_32 )
V_5 = V_40 ;
else if ( V_7 == V_33 )
V_5 = V_41 ;
else if ( V_7 == V_34 )
V_5 = V_42 ;
else if ( V_7 == V_35 )
V_5 = V_43 ;
else if ( V_7 == V_36 )
V_5 = V_44 ;
else if ( V_7 == V_37 )
V_5 = V_45 ;
else
V_5 = V_46 ;
V_4 . V_47 . V_9 = V_48 ;
V_4 . V_47 . V_49 = V_3 . V_50 . V_49 ;
V_4 . V_47 . V_51 = V_3 . V_50 . V_51 ;
V_4 . V_47 . V_52 = V_3 . V_50 . V_52 ;
V_4 . V_47 . V_53 = V_3 . V_50 . V_53 ;
V_4 . V_47 . V_5 = V_5 ;
break;
case V_54 :
V_5 = - 1 ;
V_7 = V_3 . V_55 . V_7 & 0x7 ;
if ( V_7 == V_56 )
V_5 = V_57 ;
else if ( V_7 == V_58 )
V_5 = V_59 ;
else if ( V_7 == V_60 )
V_5 = V_61 ;
else if ( V_7 == V_62 )
V_5 = V_63 ;
if ( V_5 != - 1 ) {
V_4 . V_64 . V_9 = V_48 ;
V_4 . V_64 . V_13 =
V_3 . V_55 . V_65 ;
V_4 . V_64 . V_12 =
V_3 . V_55 . V_66 ;
V_4 . V_64 . V_67 = 0 ;
V_4 . V_64 . V_68 = V_3 . V_55 . V_53 ;
V_4 . V_64 . V_5 = V_5 ;
} else
return V_28 ;
break;
case V_69 :
V_7 = - 1 ;
if ( V_3 . V_70 . V_7 == V_71 )
V_7 = 1 ;
else if ( V_3 . V_70 . V_7 == V_72 )
V_7 = 0 ;
if ( V_7 != - 1 ) {
V_4 . V_73 . V_9 = V_24 ;
V_4 . V_73 . V_6 =
V_74 [ V_3 . V_70 . V_6 ] ;
V_4 . V_73 . V_51 =
( V_3 . V_70 . V_75 << 2 ) + V_7 ;
V_4 . V_73 . V_52 =
V_3 . V_70 . V_52 ;
V_4 . V_73 . V_53 =
V_3 . V_70 . V_53 ;
V_4 . V_73 . V_5 = V_76 ;
} else
return V_28 ;
break;
case V_77 :
V_5 = - 1 ;
if ( V_3 . V_30 . V_7 == V_78 )
V_5 = V_79 ;
else if ( V_3 . V_30 . V_7 == V_80 )
V_5 = V_81 ;
else if ( V_3 . V_30 . V_7 == V_82 )
V_5 = V_83 ;
else if ( V_3 . V_30 . V_7 == V_84 )
V_5 = V_85 ;
if ( V_5 != - 1 ) {
V_4 . V_73 . V_9 = V_24 ;
V_4 . V_73 . V_6 =
V_74 [ V_3 . V_30 . V_6 ] ;
V_4 . V_73 . V_51 =
V_3 . V_30 . V_51 ;
V_4 . V_73 . V_52 =
V_3 . V_30 . V_52 ;
V_4 . V_73 . V_53 =
V_3 . V_30 . V_53 ;
V_4 . V_73 . V_5 = V_5 ;
} else
return V_28 ;
break;
case V_86 :
V_5 = - 1 ;
if ( V_3 . V_30 . V_7 == V_87 )
V_5 = V_88 ;
else if ( V_3 . V_30 . V_7 == V_89 )
V_5 = V_90 ;
if ( V_5 != - 1 ) {
V_4 . V_73 . V_9 = V_24 ;
V_4 . V_73 . V_6 =
V_74 [ V_3 . V_30 . V_6 ] ;
V_4 . V_73 . V_51 =
V_3 . V_30 . V_51 ;
V_4 . V_73 . V_52 =
V_3 . V_30 . V_52 ;
V_4 . V_73 . V_53 =
V_3 . V_30 . V_53 ;
V_4 . V_73 . V_5 = V_5 ;
} else
return V_28 ;
break;
case V_91 :
switch ( V_3 . V_92 . V_7 ) {
case V_93 :
case V_94 :
case V_95 :
case V_96 :
if ( ( V_3 . V_92 . V_7 & 0x7f ) ==
V_93 )
V_7 = 0 ;
else
V_7 = 1 ;
V_4 . V_64 . V_9 = V_97 ;
V_4 . V_64 . V_13 = V_3 . V_98 . V_52 ;
V_4 . V_64 . V_12 =
( V_3 . V_98 . V_75 << 2 ) + V_7 ;
V_4 . V_64 . V_67 = V_3 . V_98 . V_12 ;
V_4 . V_64 . V_68 = 0 ;
V_4 . V_64 . V_5 = V_99 ;
break;
case V_100 :
case V_101 :
case V_102 :
case V_103 :
if ( ( V_3 . V_92 . V_7 & 0x7f ) ==
V_100 ) {
V_5 = V_104 ;
V_6 = V_105 [ V_3 . V_106 . V_6 ] ;
} else {
V_5 = V_107 ;
V_6 = V_108 [ V_3 . V_106 . V_6 ] ;
}
V_4 . V_73 . V_9 = V_24 ;
V_4 . V_73 . V_6 = V_6 ;
V_4 . V_73 . V_51 = 0 ;
V_4 . V_73 . V_52 =
V_3 . V_106 . V_52 ;
V_4 . V_73 . V_53 =
V_3 . V_106 . V_12 ;
V_4 . V_73 . V_5 = V_5 ;
break;
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
if ( ( V_3 . V_92 . V_7 & 0x7f ) ==
V_109 )
V_5 = V_115 ;
else if ( ( V_3 . V_92 . V_7 & 0x7f ) ==
V_111 )
V_5 = V_116 ;
else
V_5 = V_117 ;
V_4 . V_73 . V_9 = V_24 ;
V_4 . V_73 . V_6 =
V_74 [ V_3 . V_106 . V_6 ] ;
V_4 . V_73 . V_51 = 0 ;
V_4 . V_73 . V_52 =
V_3 . V_106 . V_52 ;
V_4 . V_73 . V_53 =
V_3 . V_106 . V_12 ;
V_4 . V_73 . V_5 = V_5 ;
break;
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
if ( V_3 . V_92 . V_7 == V_118 )
V_5 = V_128 ;
else if ( V_3 . V_92 . V_7 == V_119 )
V_5 = V_129 ;
else if ( V_3 . V_92 . V_7 == V_120 )
V_5 = V_130 ;
else if ( V_3 . V_92 . V_7 == V_121 )
V_5 = V_131 ;
else if ( V_3 . V_92 . V_7 == V_122 )
V_5 = V_132 ;
else if ( V_3 . V_92 . V_7 == V_123 )
V_5 = V_133 ;
else if ( V_3 . V_92 . V_7 == V_124 )
V_5 = V_134 ;
else if ( V_3 . V_92 . V_7 == V_125 )
V_5 = V_135 ;
else if ( V_3 . V_92 . V_7 == V_126 )
V_5 = V_136 ;
else
V_5 = V_137 ;
V_4 . V_73 . V_9 = V_24 ;
V_4 . V_73 . V_6 =
V_138 [ V_3 . V_92 . V_6 ] ;
V_4 . V_73 . V_51 = 0 ;
V_4 . V_73 . V_52 =
V_3 . V_92 . V_52 ;
V_4 . V_73 . V_53 =
V_3 . V_92 . V_12 ;
V_4 . V_73 . V_5 = V_5 ;
break;
case V_139 :
case V_140 :
case V_141 :
if ( V_3 . V_92 . V_7 == V_139 )
V_5 = V_142 ;
else if ( V_3 . V_92 . V_7 == V_140 )
V_5 = V_143 ;
else
V_5 = V_144 ;
V_4 . V_73 . V_9 = V_24 ;
V_4 . V_73 . V_6 =
V_74 [ V_3 . V_92 . V_6 ] ;
V_4 . V_73 . V_51 = 0 ;
V_4 . V_73 . V_52 =
V_3 . V_92 . V_52 ;
V_4 . V_73 . V_53 =
V_3 . V_92 . V_12 ;
V_4 . V_73 . V_5 = V_5 ;
break;
case V_145 :
case V_146 :
case V_147 :
case V_148 :
if ( V_3 . V_92 . V_7 == V_145 )
V_7 = V_149 ;
else if ( V_3 . V_92 . V_7 == V_146 )
V_7 = V_150 ;
else if ( V_3 . V_92 . V_7 == V_147 )
V_7 = V_151 ;
else
V_7 = V_152 ;
V_4 . V_153 . V_9 = V_24 ;
V_4 . V_153 . V_7 = V_7 ;
V_4 . V_153 . V_12 =
V_3 . V_92 . V_12 ;
V_4 . V_153 . V_52 =
V_3 . V_92 . V_52 ;
V_4 . V_153 . V_53 = 0 ;
V_4 . V_153 . V_5 = 0 ;
break;
default:
return V_28 ;
break;
}
break;
case V_154 :
V_4 . V_73 . V_9 = V_24 ;
V_4 . V_73 . V_6 =
V_74 [ V_3 . V_98 . V_6 ] ;
V_4 . V_73 . V_51 = V_3 . V_98 . V_12 ;
V_4 . V_73 . V_52 = V_3 . V_98 . V_52 ;
V_4 . V_73 . V_53 = V_3 . V_98 . V_75 << 2 ;
V_4 . V_73 . V_5 =
V_3 . V_98 . V_155 | V_156 ;
break;
default:
return V_28 ;
break;
}
break;
default:
return V_28 ;
break;
}
* V_2 = V_4 ;
return 0 ;
}
int F_2 ( struct V_157 * V_158 , struct V_159 V_160 ,
unsigned long * V_161 )
{
union V_1 V_3 = (union V_1 ) V_160 . V_3 ;
int V_162 = 0 ;
unsigned int V_163 ;
unsigned int V_164 ;
if ( ! V_165 )
return 0 ;
switch ( V_3 . V_8 . V_9 ) {
case V_166 :
if ( ( V_3 . V_8 . V_167 & V_168 ) ==
V_169 ) {
switch ( V_3 . V_8 . V_167 >>
V_170 ) {
case V_171 :
case V_172 :
case V_173 :
case V_174 :
if ( V_3 . V_8 . V_12 != 0 )
V_158 -> V_158 [ V_3 . V_8 . V_12 ] =
V_158 -> V_175 +
V_160 . V_176 +
V_160 . V_177 ;
* V_161 = V_158 -> V_158 [ V_3 . V_8 . V_13 ] ;
return 1 ;
break;
}
}
break;
case V_20 :
switch ( V_3 . V_8 . V_12 ) {
case V_178 :
case V_179 :
V_158 -> V_158 [ 31 ] = V_158 -> V_175 +
V_160 . V_176 +
V_160 . V_177 ;
case V_180 :
if ( ( long ) V_158 -> V_158 [ V_3 . V_8 . V_13 ] < 0 )
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
( V_3 . V_8 . V_167 << 1 ) ;
else
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
V_160 . V_177 ;
return 1 ;
break;
case V_181 :
case V_182 :
V_158 -> V_158 [ 31 ] = V_158 -> V_175 +
V_160 . V_176 +
V_160 . V_177 ;
case V_183 :
if ( ( long ) V_158 -> V_158 [ V_3 . V_8 . V_13 ] >= 0 )
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
( V_3 . V_8 . V_167 << 1 ) ;
else
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
V_160 . V_177 ;
return 1 ;
break;
case V_184 :
if ( ( long ) V_158 -> V_158 [ V_3 . V_8 . V_13 ] <= 0 )
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
( V_3 . V_8 . V_167 << 1 ) ;
else
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
V_160 . V_177 ;
return 1 ;
break;
case V_185 :
if ( ( long ) V_158 -> V_158 [ V_3 . V_8 . V_13 ] <= 0 )
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
( V_3 . V_8 . V_167 << 1 ) ;
else
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
V_160 . V_177 ;
return 1 ;
break;
case V_186 :
case V_21 :
V_162 = 1 ;
case V_187 :
case V_22 :
F_3 () ;
if ( F_4 () )
asm volatile("cfc1\t%0,$31" : "=r" (fcr31));
else
V_163 = V_188 -> V_189 . V_190 . V_163 ;
F_5 () ;
if ( V_162 )
V_163 = ~ V_163 ;
V_164 = ( V_3 . V_8 . V_13 >> 2 ) ;
V_164 += ( V_164 != 0 ) ;
V_164 += 23 ;
if ( V_163 & ( 1 << V_164 ) )
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
( V_3 . V_8 . V_167 << 1 ) ;
else
* V_161 = V_158 -> V_175 +
V_160 . V_176 + V_160 . V_177 ;
return 1 ;
break;
}
break;
case V_191 :
switch ( V_3 . V_8 . V_12 ) {
case V_192 :
case V_193 :
V_158 -> V_158 [ 31 ] = V_158 -> V_175 +
V_160 . V_176 + V_160 . V_177 ;
case V_194 :
* V_161 = V_158 -> V_158 [ V_3 . V_8 . V_13 ] ;
return 1 ;
break;
}
break;
case V_195 :
if ( ( long ) V_158 -> V_158 [ V_196 [ V_3 . V_197 . V_13 ] ] == 0 )
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
( V_3 . V_197 . V_167 << 1 ) ;
else
* V_161 = V_158 -> V_175 +
V_160 . V_176 + V_160 . V_177 ;
return 1 ;
break;
case V_198 :
if ( ( long ) V_158 -> V_158 [ V_196 [ V_3 . V_197 . V_13 ] ] != 0 )
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
( V_3 . V_197 . V_167 << 1 ) ;
else
* V_161 = V_158 -> V_175 +
V_160 . V_176 + V_160 . V_177 ;
return 1 ;
break;
case V_199 :
* V_161 = V_158 -> V_175 + V_160 . V_176 +
( V_3 . V_200 . V_167 << 1 ) ;
return 1 ;
break;
case V_201 :
if ( V_158 -> V_158 [ V_3 . V_8 . V_13 ] ==
V_158 -> V_158 [ V_3 . V_8 . V_12 ] )
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
( V_3 . V_8 . V_167 << 1 ) ;
else
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
V_160 . V_177 ;
return 1 ;
break;
case V_202 :
if ( V_158 -> V_158 [ V_3 . V_8 . V_13 ] !=
V_158 -> V_158 [ V_3 . V_8 . V_12 ] )
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
( V_3 . V_8 . V_167 << 1 ) ;
else
* V_161 = V_158 -> V_175 +
V_160 . V_176 + V_160 . V_177 ;
return 1 ;
break;
case V_203 :
V_158 -> V_158 [ 31 ] = V_158 -> V_175 +
V_160 . V_176 + V_160 . V_177 ;
* V_161 = V_158 -> V_175 + V_160 . V_176 ;
* V_161 >>= 28 ;
* V_161 <<= 28 ;
* V_161 |= ( V_3 . V_204 . V_205 << 2 ) ;
return 1 ;
break;
case V_206 :
case V_207 :
V_158 -> V_158 [ 31 ] = V_158 -> V_175 +
V_160 . V_176 + V_160 . V_177 ;
case V_208 :
* V_161 = V_158 -> V_175 + V_160 . V_176 ;
* V_161 >>= 27 ;
* V_161 <<= 27 ;
* V_161 |= ( V_3 . V_204 . V_205 << 1 ) ;
F_6 ( * V_161 ) ;
return 1 ;
break;
}
return 0 ;
}
static int F_7 ( struct V_157 * V_158 , struct V_159 V_160 ,
unsigned long * V_161 )
{
union V_1 V_3 = (union V_1 ) V_160 . V_3 ;
unsigned int V_163 ;
unsigned int V_164 = 0 ;
switch ( V_3 . V_209 . V_9 ) {
case V_97 :
switch ( V_3 . V_64 . V_5 ) {
case V_210 :
V_158 -> V_158 [ V_3 . V_64 . V_67 ] =
V_158 -> V_175 + V_160 . V_176 +
V_160 . V_177 ;
case V_211 :
* V_161 = V_158 -> V_158 [ V_3 . V_64 . V_13 ] ;
return 1 ;
break;
}
break;
case V_212 :
switch ( V_3 . V_209 . V_12 ) {
case V_213 :
case V_214 :
V_158 -> V_158 [ 31 ] = V_158 -> V_175 +
V_160 . V_176 +
V_160 . V_177 ;
case V_215 :
case V_216 :
if ( ( long ) V_158 -> V_158 [ V_3 . V_209 . V_13 ] < 0 )
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
( V_3 . V_209 . V_167 << 2 ) ;
else
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
V_160 . V_177 ;
return 1 ;
break;
case V_217 :
case V_218 :
V_158 -> V_158 [ 31 ] = V_158 -> V_175 +
V_160 . V_176 +
V_160 . V_177 ;
case V_219 :
case V_220 :
if ( ( long ) V_158 -> V_158 [ V_3 . V_209 . V_13 ] >= 0 )
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
( V_3 . V_209 . V_167 << 2 ) ;
else
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
V_160 . V_177 ;
return 1 ;
break;
}
break;
case V_221 :
F_6 ( V_164 ) ;
case V_222 :
V_158 -> V_158 [ 31 ] = V_158 -> V_175 +
V_160 . V_176 +
V_160 . V_177 ;
case V_223 :
* V_161 = V_158 -> V_175 + V_160 . V_176 ;
* V_161 >>= 28 ;
* V_161 <<= 28 ;
* V_161 |= ( V_3 . V_204 . V_205 << 2 ) ;
* V_161 ^= V_164 ;
return 1 ;
break;
case V_224 :
case V_225 :
if ( V_158 -> V_158 [ V_3 . V_209 . V_13 ] ==
V_158 -> V_158 [ V_3 . V_209 . V_12 ] )
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
( V_3 . V_209 . V_167 << 2 ) ;
else
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
V_160 . V_177 ;
return 1 ;
break;
case V_226 :
case V_227 :
if ( V_158 -> V_158 [ V_3 . V_209 . V_13 ] !=
V_158 -> V_158 [ V_3 . V_209 . V_12 ] )
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
( V_3 . V_209 . V_167 << 2 ) ;
else
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
V_160 . V_177 ;
return 1 ;
break;
case V_228 :
case V_229 :
if ( ( long ) V_158 -> V_158 [ V_3 . V_209 . V_13 ] <= 0 )
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
( V_3 . V_209 . V_167 << 2 ) ;
else
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
V_160 . V_177 ;
return 1 ;
break;
case V_230 :
case V_231 :
if ( ( long ) V_158 -> V_158 [ V_3 . V_209 . V_13 ] > 0 )
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
( V_3 . V_209 . V_167 << 2 ) ;
else
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
V_160 . V_177 ;
return 1 ;
break;
#ifdef F_8
case V_232 :
if ( ( V_158 -> V_158 [ V_3 . V_209 . V_13 ] & ( 1ull << V_3 . V_209 . V_12 ) ) == 0 )
* V_161 = V_158 -> V_175 + 4 + ( V_3 . V_209 . V_167 << 2 ) ;
else
* V_161 = V_158 -> V_175 + 8 ;
return 1 ;
case V_233 :
if ( ( V_158 -> V_158 [ V_3 . V_209 . V_13 ] & ( 1ull << ( V_3 . V_209 . V_12 + 32 ) ) ) == 0 )
* V_161 = V_158 -> V_175 + 4 + ( V_3 . V_209 . V_167 << 2 ) ;
else
* V_161 = V_158 -> V_175 + 8 ;
return 1 ;
case V_234 :
if ( V_158 -> V_158 [ V_3 . V_209 . V_13 ] & ( 1ull << V_3 . V_209 . V_12 ) )
* V_161 = V_158 -> V_175 + 4 + ( V_3 . V_209 . V_167 << 2 ) ;
else
* V_161 = V_158 -> V_175 + 8 ;
return 1 ;
case V_235 :
if ( V_158 -> V_158 [ V_3 . V_209 . V_13 ] & ( 1ull << ( V_3 . V_209 . V_12 + 32 ) ) )
* V_161 = V_158 -> V_175 + 4 + ( V_3 . V_209 . V_167 << 2 ) ;
else
* V_161 = V_158 -> V_175 + 8 ;
return 1 ;
#endif
case V_236 :
case V_24 :
case V_237 :
case V_48 :
if ( V_3 . V_209 . V_13 == V_26 ) {
F_3 () ;
if ( F_4 () )
asm volatile("cfc1\t%0,$31" : "=r" (fcr31));
else
V_163 = V_188 -> V_189 . V_190 . V_163 ;
F_5 () ;
V_164 = ( V_3 . V_209 . V_12 >> 2 ) ;
V_164 += ( V_164 != 0 ) ;
V_164 += 23 ;
switch ( V_3 . V_209 . V_12 & 3 ) {
case 0 :
case 2 :
if ( ~ V_163 & ( 1 << V_164 ) )
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
( V_3 . V_209 . V_167 << 2 ) ;
else
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
V_160 . V_177 ;
return 1 ;
break;
case 1 :
case 3 :
if ( V_163 & ( 1 << V_164 ) )
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
( V_3 . V_209 . V_167 << 2 ) ;
else
* V_161 = V_158 -> V_175 +
V_160 . V_176 +
V_160 . V_177 ;
return 1 ;
break;
}
}
break;
}
return 0 ;
}
static inline int F_9 ( struct V_157 * V_238 )
{
#if F_10 ( V_239 ) && ! F_10 ( V_240 )
return 1 ;
#elif F_10 ( V_239 ) && F_10 ( V_240 )
return ! F_11 ( V_241 ) ;
#else
return 0 ;
#endif
}
static int F_12 ( struct V_157 * V_238 , struct V_242 * V_243 ,
struct V_159 V_160 , void * T_1 * V_244 )
{
V_1 V_245 ;
unsigned long V_161 = V_238 -> V_175 + V_160 . V_176 ;
unsigned int V_155 ;
int V_176 ;
if ( V_238 -> V_246 & V_247 ) {
if ( V_160 . V_248 ) {
if ( ! F_2 ( V_238 , V_160 , & V_161 ) )
V_238 -> V_246 &= ~ V_247 ;
} else {
if ( ! F_7 ( V_238 , V_160 , & V_161 ) )
V_238 -> V_246 &= ~ V_247 ;
}
}
if ( V_238 -> V_246 & V_247 ) {
V_245 = V_160 . V_249 ;
V_176 = V_160 . V_177 ;
} else {
V_245 = V_160 . V_3 ;
V_176 = V_160 . V_176 ;
}
if ( V_160 . V_248 ) {
if ( ( V_176 == 2 ) ||
( F_1 ( (union V_1 * ) & V_245 )
== V_28 ) )
return V_28 ;
}
V_250:
F_13 ( V_251 , 1 , V_238 , 0 ) ;
F_14 ( V_252 ) ;
switch ( F_15 ( V_245 ) ) {
case V_11 : {
T_2 T_1 * V_253 = ( T_2 T_1 * ) ( V_238 -> V_158 [ F_16 ( V_245 ) ] +
F_17 ( V_245 ) ) ;
T_2 V_254 ;
F_14 ( V_255 ) ;
if ( ! F_18 ( V_256 , V_253 , sizeof( T_2 ) ) ) {
F_14 ( V_257 ) ;
* V_244 = V_253 ;
return V_258 ;
}
if ( F_19 ( V_254 , V_253 ) ) {
F_14 ( V_257 ) ;
* V_244 = V_253 ;
return V_259 ;
}
F_20 ( V_254 , F_21 ( V_245 ) ) ;
break;
}
case V_17 : {
T_2 T_1 * V_253 = ( T_2 T_1 * ) ( V_238 -> V_158 [ F_16 ( V_245 ) ] +
F_17 ( V_245 ) ) ;
T_2 V_254 ;
F_14 ( V_260 ) ;
F_22 ( V_254 , F_21 ( V_245 ) ) ;
if ( ! F_18 ( V_261 , V_253 , sizeof( T_2 ) ) ) {
F_14 ( V_257 ) ;
* V_244 = V_253 ;
return V_258 ;
}
if ( F_23 ( V_254 , V_253 ) ) {
F_14 ( V_257 ) ;
* V_244 = V_253 ;
return V_259 ;
}
break;
}
case V_15 : {
T_3 T_1 * V_253 = ( T_3 T_1 * ) ( V_238 -> V_158 [ F_16 ( V_245 ) ] +
F_17 ( V_245 ) ) ;
T_3 V_254 ;
F_14 ( V_255 ) ;
if ( ! F_18 ( V_256 , V_253 , sizeof( T_3 ) ) ) {
F_14 ( V_257 ) ;
* V_244 = V_253 ;
return V_258 ;
}
if ( F_19 ( V_254 , V_253 ) ) {
F_14 ( V_257 ) ;
* V_244 = V_253 ;
return V_259 ;
}
F_24 ( V_254 , F_21 ( V_245 ) ) ;
break;
}
case V_19 : {
T_3 T_1 * V_253 = ( T_3 T_1 * ) ( V_238 -> V_158 [ F_16 ( V_245 ) ] +
F_17 ( V_245 ) ) ;
T_3 V_254 ;
F_14 ( V_260 ) ;
F_25 ( V_254 , F_21 ( V_245 ) ) ;
if ( ! F_18 ( V_261 , V_253 , sizeof( T_3 ) ) ) {
F_14 ( V_257 ) ;
* V_244 = V_253 ;
return V_258 ;
}
if ( F_23 ( V_254 , V_253 ) ) {
F_14 ( V_257 ) ;
* V_244 = V_253 ;
return V_259 ;
}
break;
}
case V_24 :
switch ( F_16 ( V_245 ) ) {
#if F_10 ( V_262 )
case V_263 :
if ( F_21 ( V_245 ) != 0 ) {
F_22 ( V_238 -> V_158 [ F_21 ( V_245 ) ] ,
F_26 ( V_245 ) ) ;
}
break;
case V_264 :
F_20 ( V_238 -> V_158 [ F_21 ( V_245 ) ] , F_26 ( V_245 ) ) ;
break;
#endif
case V_149 :
if ( F_21 ( V_245 ) != 0 ) {
F_25 ( V_238 -> V_158 [ F_21 ( V_245 ) ] ,
F_26 ( V_245 ) ) ;
}
break;
case V_150 :
F_24 ( V_238 -> V_158 [ F_21 ( V_245 ) ] , F_26 ( V_245 ) ) ;
break;
case V_151 : {
T_3 V_265 ;
if ( F_26 ( V_245 ) == V_266 ) {
V_265 = V_243 -> V_163 ;
V_265 = ( V_265 & ~ V_267 ) |
V_268 [ F_27 ( V_265 ) ] ;
#ifdef F_28
F_29 ( L_1 ,
( void * ) ( V_238 -> V_175 ) ,
F_21 ( V_245 ) , V_265 ) ;
#endif
}
else if ( F_26 ( V_245 ) == V_269 )
V_265 = 0 ;
else
V_265 = 0 ;
if ( F_21 ( V_245 ) )
V_238 -> V_158 [ F_21 ( V_245 ) ] = V_265 ;
break;
}
case V_152 : {
T_3 V_265 ;
if ( F_21 ( V_245 ) == 0 )
V_265 = 0 ;
else
V_265 = V_238 -> V_158 [ F_21 ( V_245 ) ] ;
if ( F_26 ( V_245 ) == V_266 ) {
#ifdef F_28
F_29 ( L_2 ,
( void * ) ( V_238 -> V_175 ) ,
F_21 ( V_245 ) , V_265 ) ;
#endif
V_243 -> V_163 = ( V_265 &
~ ( V_270 | V_267 ) ) |
V_271 [ F_27 ( V_265 ) ] ;
}
if ( ( V_243 -> V_163 >> 5 ) & V_243 -> V_163 & V_272 ) {
return V_273 ;
}
break;
}
case V_26 : {
int V_274 = 0 ;
if ( V_238 -> V_246 & V_247 )
return V_28 ;
#if V_275 >= 4
V_155 = V_243 -> V_163 & V_276 [ F_21 ( V_245 ) >> 2 ] ;
#else
V_155 = V_243 -> V_163 & V_277 ;
#endif
switch ( F_21 ( V_245 ) & 3 ) {
case V_278 :
V_274 = 1 ;
case V_279 :
V_155 = ! V_155 ;
break;
case V_280 :
V_274 = 1 ;
case V_281 :
break;
default:
return V_28 ;
}
V_238 -> V_246 |= V_247 ;
if ( V_155 ) {
V_238 -> V_175 += V_160 . V_176 ;
V_161 = F_17 ( V_245 ) ;
V_245 = V_160 . V_249 ;
if ( V_160 . V_248 ) {
V_161 = ( V_238 -> V_175 + ( V_161 << 1 ) ) ;
if ( ( V_160 . V_177 == 2 ) ||
( F_1 ( (union V_1 * ) & V_245 ) == V_28 ) ) {
if ( V_160 . V_177 == 2 )
V_245 = ( V_245 & ( ~ 0xffff ) ) | V_282 ;
return F_30 ( V_238 , V_245 , V_161 ) ;
}
} else
V_161 = ( V_238 -> V_175 + ( V_161 << 2 ) ) ;
switch ( F_15 ( V_245 ) ) {
case V_15 :
case V_19 :
#if ( V_275 >= 2 || F_10 ( V_262 ) )
case V_11 :
case V_17 :
#endif
case V_24 :
#if V_275 >= 4 && V_275 != 32
case V_48 :
#endif
goto V_250;
#if V_275 >= 4
case V_97 :
if ( F_31 ( V_245 ) == V_99 )
goto V_250;
break;
#endif
}
return F_30 ( V_238 , V_245 , V_161 ) ;
}
else {
if ( V_274 ) {
V_238 -> V_175 += V_160 . V_176 ;
V_161 += V_160 . V_176 ;
}
}
break;
}
default:
if ( ! ( F_16 ( V_245 ) & 0x10 ) )
return V_28 ;
{
int V_283 ;
if ( ( V_283 = F_32 ( V_238 , V_243 , V_245 ) ) )
return V_283 ;
}
}
break;
#if V_275 >= 4 && V_275 != 32
case V_48 : {
int V_283 = F_33 ( V_238 , V_243 , V_245 , V_244 ) ;
if ( V_283 )
return V_283 ;
break;
}
#endif
#if V_275 >= 4
case V_97 :
if ( F_31 ( V_245 ) != V_99 )
return V_28 ;
V_155 = V_276 [ F_21 ( V_245 ) >> 2 ] ;
if ( ( ( V_243 -> V_163 & V_155 ) != 0 ) == ( ( F_21 ( V_245 ) & 1 ) != 0 ) )
V_238 -> V_158 [ F_26 ( V_245 ) ] =
V_238 -> V_158 [ F_16 ( V_245 ) ] ;
break;
#endif
default:
return V_28 ;
}
V_238 -> V_175 = V_161 ;
V_238 -> V_246 &= ~ V_247 ;
return 0 ;
}
static T_4 F_34 ( T_4 V_284 )
{
return F_35 ( F_36 ( 0 ) , V_284 ) ;
}
static T_4 F_37 ( T_4 V_284 )
{
return F_35 ( F_36 ( 0 ) , F_38 ( V_284 ) ) ;
}
static T_5 F_39 ( T_5 V_285 )
{
return F_40 ( F_41 ( 0 ) , V_285 ) ;
}
static T_5 F_42 ( T_5 V_285 )
{
return F_40 ( F_41 ( 0 ) , F_43 ( V_285 ) ) ;
}
static int F_33 ( struct V_157 * V_238 , struct V_242 * V_243 ,
V_1 V_245 , void * T_1 * V_244 )
{
unsigned V_286 = 0 ;
F_14 ( V_287 ) ;
switch ( F_44 ( V_245 ) ) {
case V_288 : {
T_5 (* F_45) ( T_5 , T_5 , T_5 );
T_5 V_53 , V_49 , V_52 , V_51 ;
T_3 T_1 * V_253 ;
T_3 V_254 ;
switch ( F_31 ( V_245 ) ) {
case V_61 :
V_253 = ( void T_1 * ) ( V_238 -> V_158 [ F_46 ( V_245 ) ] +
V_238 -> V_158 [ F_47 ( V_245 ) ] ) ;
F_14 ( V_255 ) ;
if ( ! F_18 ( V_256 , V_253 , sizeof( T_3 ) ) ) {
F_14 ( V_257 ) ;
* V_244 = V_253 ;
return V_258 ;
}
if ( F_19 ( V_254 , V_253 ) ) {
F_14 ( V_257 ) ;
* V_244 = V_253 ;
return V_259 ;
}
F_24 ( V_254 , F_48 ( V_245 ) ) ;
break;
case V_63 :
V_253 = ( void T_1 * ) ( V_238 -> V_158 [ F_46 ( V_245 ) ] +
V_238 -> V_158 [ F_47 ( V_245 ) ] ) ;
F_14 ( V_260 ) ;
F_25 ( V_254 , F_49 ( V_245 ) ) ;
if ( ! F_18 ( V_261 , V_253 , sizeof( T_3 ) ) ) {
F_14 ( V_257 ) ;
* V_244 = V_253 ;
return V_258 ;
}
if ( F_50 ( V_254 , V_253 ) ) {
F_14 ( V_257 ) ;
* V_244 = V_253 ;
return V_259 ;
}
break;
case V_39 :
F_45 = V_289 ;
goto V_290;
case V_43 :
F_45 = V_291 ;
goto V_290;
case V_41 :
F_45 = V_292 ;
goto V_290;
case V_45 :
F_45 = V_293 ;
goto V_290;
V_290:
F_51 ( V_49 , F_46 ( V_245 ) ) ;
F_51 ( V_52 , F_49 ( V_245 ) ) ;
F_51 ( V_51 , F_47 ( V_245 ) ) ;
V_53 = (* F_45) ( V_49 , V_52 , V_51 ) ;
F_52 ( V_53 , F_48 ( V_245 ) ) ;
V_294:
if ( F_53 ( V_295 ) )
V_286 |= V_296 | V_297 ;
if ( F_53 ( V_298 ) )
V_286 |= V_299 | V_300 ;
if ( F_53 ( V_301 ) )
V_286 |= V_302 | V_303 ;
if ( F_53 ( V_304 ) )
V_286 |= V_305 | V_306 ;
V_243 -> V_163 = ( V_243 -> V_163 & ~ V_307 ) | V_286 ;
if ( ( V_243 -> V_163 >> 5 ) & V_243 -> V_163 & V_272 ) {
return V_273 ;
}
break;
default:
return V_28 ;
}
break;
}
case V_308 : {
T_4 (* F_45) ( T_4 , T_4 , T_4 );
T_4 V_53 , V_49 , V_52 , V_51 ;
T_2 T_1 * V_253 ;
T_2 V_254 ;
switch ( F_31 ( V_245 ) ) {
case V_57 :
V_253 = ( void T_1 * ) ( V_238 -> V_158 [ F_46 ( V_245 ) ] +
V_238 -> V_158 [ F_47 ( V_245 ) ] ) ;
F_14 ( V_255 ) ;
if ( ! F_18 ( V_256 , V_253 , sizeof( T_2 ) ) ) {
F_14 ( V_257 ) ;
* V_244 = V_253 ;
return V_258 ;
}
if ( F_19 ( V_254 , V_253 ) ) {
F_14 ( V_257 ) ;
* V_244 = V_253 ;
return V_259 ;
}
F_20 ( V_254 , F_48 ( V_245 ) ) ;
break;
case V_59 :
V_253 = ( void T_1 * ) ( V_238 -> V_158 [ F_46 ( V_245 ) ] +
V_238 -> V_158 [ F_47 ( V_245 ) ] ) ;
F_14 ( V_260 ) ;
F_22 ( V_254 , F_49 ( V_245 ) ) ;
if ( ! F_18 ( V_261 , V_253 , sizeof( T_2 ) ) ) {
F_14 ( V_257 ) ;
* V_244 = V_253 ;
return V_258 ;
}
if ( F_23 ( V_254 , V_253 ) ) {
F_14 ( V_257 ) ;
* V_244 = V_253 ;
return V_259 ;
}
break;
case V_40 :
F_45 = V_309 ;
goto V_310;
case V_44 :
F_45 = V_311 ;
goto V_310;
case V_42 :
F_45 = V_312 ;
goto V_310;
case V_46 :
F_45 = V_313 ;
goto V_310;
V_310:
F_54 ( V_49 , F_46 ( V_245 ) ) ;
F_54 ( V_52 , F_49 ( V_245 ) ) ;
F_54 ( V_51 , F_47 ( V_245 ) ) ;
V_53 = (* F_45) ( V_49 , V_52 , V_51 ) ;
F_55 ( V_53 , F_48 ( V_245 ) ) ;
goto V_294;
default:
return V_28 ;
}
break;
}
case 0x7 :
if ( F_31 ( V_245 ) != V_314 ) {
return V_28 ;
}
break;
default:
return V_28 ;
}
return 0 ;
}
static int F_32 ( struct V_157 * V_238 , struct V_242 * V_243 ,
V_1 V_245 )
{
int V_315 ;
unsigned V_286 = 0 ;
unsigned V_155 ;
union {
T_4 V_284 ;
T_5 V_285 ;
int V_316 ;
#ifdef V_262
T_6 V_317 ;
#endif
} V_318 ;
F_14 ( V_319 ) ;
switch ( V_315 = ( F_56 ( V_245 ) & 0xf ) ) {
case V_288 : {
union {
T_5 (* F_57) ( T_5 , T_5 );
T_5 (* F_58) ( T_5 );
} F_45 ;
switch ( F_31 ( V_245 ) ) {
case V_79 :
F_45 . F_57 = V_320 ;
goto V_321;
case V_81 :
F_45 . F_57 = V_322 ;
goto V_321;
case V_83 :
F_45 . F_57 = V_323 ;
goto V_321;
case V_85 :
F_45 . F_57 = F_40 ;
goto V_321;
#if V_275 >= 2 || F_10 ( V_262 )
case V_143 :
F_45 . F_58 = F_43 ;
goto V_324;
#endif
#if V_275 >= 4 && V_275 != 32
case V_142 :
F_45 . F_58 = F_42 ;
goto V_324;
case V_144 :
F_45 . F_58 = F_39 ;
goto V_324;
#endif
#if V_275 >= 4
case V_76 :
V_155 = V_276 [ F_47 ( V_245 ) >> 2 ] ;
if ( ( ( V_243 -> V_163 & V_155 ) != 0 ) !=
( ( F_47 ( V_245 ) & 1 ) != 0 ) )
return 0 ;
F_51 ( V_318 . V_285 , F_49 ( V_245 ) ) ;
break;
case V_90 :
if ( V_238 -> V_158 [ F_47 ( V_245 ) ] != 0 )
return 0 ;
F_51 ( V_318 . V_285 , F_49 ( V_245 ) ) ;
break;
case V_88 :
if ( V_238 -> V_158 [ F_47 ( V_245 ) ] == 0 )
return 0 ;
F_51 ( V_318 . V_285 , F_49 ( V_245 ) ) ;
break;
#endif
case V_116 :
F_45 . F_58 = V_325 ;
goto V_324;
case V_117 :
F_45 . F_58 = V_326 ;
goto V_324;
case V_115 :
F_51 ( V_318 . V_285 , F_49 ( V_245 ) ) ;
goto V_294;
V_321:
{
T_5 V_52 , V_51 ;
F_51 ( V_52 , F_49 ( V_245 ) ) ;
F_51 ( V_51 , F_47 ( V_245 ) ) ;
V_318 . V_285 = (* F_45 . F_57 ) ( V_52 , V_51 ) ;
goto V_294;
}
V_324:
{
T_5 V_52 ;
F_51 ( V_52 , F_49 ( V_245 ) ) ;
V_318 . V_285 = (* F_45 . F_58 ) ( V_52 ) ;
goto V_294;
}
V_294:
if ( F_53 ( V_295 ) )
V_286 |= V_296 | V_297 ;
if ( F_53 ( V_298 ) )
V_286 |= V_299 | V_300 ;
if ( F_53 ( V_301 ) )
V_286 |= V_302 | V_303 ;
if ( F_53 ( V_327 ) )
V_286 |= V_328 | V_329 ;
if ( F_53 ( V_304 ) )
V_286 |= V_305 | V_306 ;
break;
case V_107 :
return V_28 ;
case V_104 : {
T_5 V_52 ;
F_51 ( V_52 , F_49 ( V_245 ) ) ;
V_318 . V_284 = F_59 ( V_52 ) ;
V_315 = V_308 ;
goto V_294;
}
case V_137 : {
T_5 V_52 ;
F_51 ( V_52 , F_49 ( V_245 ) ) ;
V_318 . V_316 = F_60 ( V_52 ) ;
V_315 = V_330 ;
goto V_294;
}
#if V_275 >= 2 || F_10 ( V_262 )
case V_135 :
case V_133 :
case V_131 :
case V_129 : {
unsigned int V_331 = V_332 . V_333 ;
T_5 V_52 ;
F_51 ( V_52 , F_49 ( V_245 ) ) ;
V_332 . V_333 = V_271 [ F_27 ( F_31 ( V_245 ) ) ] ;
V_318 . V_316 = F_60 ( V_52 ) ;
V_332 . V_333 = V_331 ;
V_315 = V_330 ;
goto V_294;
}
#endif
#if F_10 ( V_262 )
case V_136 : {
T_5 V_52 ;
F_51 ( V_52 , F_49 ( V_245 ) ) ;
V_318 . V_317 = F_61 ( V_52 ) ;
V_315 = V_334 ;
goto V_294;
}
case V_134 :
case V_132 :
case V_130 :
case V_128 : {
unsigned int V_331 = V_332 . V_333 ;
T_5 V_52 ;
F_51 ( V_52 , F_49 ( V_245 ) ) ;
V_332 . V_333 = V_271 [ F_27 ( F_31 ( V_245 ) ) ] ;
V_318 . V_317 = F_61 ( V_52 ) ;
V_332 . V_333 = V_331 ;
V_315 = V_334 ;
goto V_294;
}
#endif
default:
if ( F_31 ( V_245 ) >= V_335 ) {
unsigned V_336 = F_31 ( V_245 ) - V_335 ;
T_5 V_52 , V_51 ;
F_51 ( V_52 , F_49 ( V_245 ) ) ;
F_51 ( V_51 , F_47 ( V_245 ) ) ;
V_318 . V_316 = F_62 ( V_52 , V_51 ,
V_337 [ V_336 & 0x7 ] , V_336 & 0x8 ) ;
V_315 = - 1 ;
if ( ( V_336 & 0x8 ) && F_53
( V_304 ) )
V_286 = V_305 | V_306 ;
else
goto V_294;
}
else {
return V_28 ;
}
break;
}
break;
}
case V_308 : {
union {
T_4 (* F_57) ( T_4 , T_4 );
T_4 (* F_58) ( T_4 );
} F_45 ;
switch ( F_31 ( V_245 ) ) {
case V_79 :
F_45 . F_57 = V_338 ;
goto V_339;
case V_81 :
F_45 . F_57 = V_340 ;
goto V_339;
case V_83 :
F_45 . F_57 = V_341 ;
goto V_339;
case V_85 :
F_45 . F_57 = F_35 ;
goto V_339;
#if V_275 >= 2 || F_10 ( V_262 )
case V_143 :
F_45 . F_58 = F_38 ;
goto V_342;
#endif
#if V_275 >= 4 && V_275 != 32
case V_142 :
F_45 . F_58 = F_37 ;
goto V_342;
case V_144 :
F_45 . F_58 = F_34 ;
goto V_342;
#endif
#if V_275 >= 4
case V_76 :
V_155 = V_276 [ F_47 ( V_245 ) >> 2 ] ;
if ( ( ( V_243 -> V_163 & V_155 ) != 0 ) !=
( ( F_47 ( V_245 ) & 1 ) != 0 ) )
return 0 ;
F_54 ( V_318 . V_284 , F_49 ( V_245 ) ) ;
break;
case V_90 :
if ( V_238 -> V_158 [ F_47 ( V_245 ) ] != 0 )
return 0 ;
F_54 ( V_318 . V_284 , F_49 ( V_245 ) ) ;
break;
case V_88 :
if ( V_238 -> V_158 [ F_47 ( V_245 ) ] == 0 )
return 0 ;
F_54 ( V_318 . V_284 , F_49 ( V_245 ) ) ;
break;
#endif
case V_116 :
F_45 . F_58 = V_343 ;
goto V_342;
case V_117 :
F_45 . F_58 = V_344 ;
goto V_342;
case V_115 :
F_54 ( V_318 . V_284 , F_49 ( V_245 ) ) ;
goto V_294;
V_339: {
T_4 V_52 , V_51 ;
F_54 ( V_52 , F_49 ( V_245 ) ) ;
F_54 ( V_51 , F_47 ( V_245 ) ) ;
V_318 . V_284 = (* F_45 . F_57 ) ( V_52 , V_51 ) ;
goto V_294;
}
V_342: {
T_4 V_52 ;
F_54 ( V_52 , F_49 ( V_245 ) ) ;
V_318 . V_284 = (* F_45 . F_58 ) ( V_52 ) ;
goto V_294;
}
case V_107 : {
T_4 V_52 ;
F_54 ( V_52 , F_49 ( V_245 ) ) ;
V_318 . V_285 = F_63 ( V_52 ) ;
V_315 = V_288 ;
goto V_294;
}
case V_104 :
return V_28 ;
case V_137 : {
T_4 V_52 ;
F_54 ( V_52 , F_49 ( V_245 ) ) ;
V_318 . V_316 = F_64 ( V_52 ) ;
V_315 = V_330 ;
goto V_294;
}
#if V_275 >= 2 || F_10 ( V_262 )
case V_135 :
case V_133 :
case V_131 :
case V_129 : {
unsigned int V_331 = V_332 . V_333 ;
T_4 V_52 ;
F_54 ( V_52 , F_49 ( V_245 ) ) ;
V_332 . V_333 = V_271 [ F_27 ( F_31 ( V_245 ) ) ] ;
V_318 . V_316 = F_64 ( V_52 ) ;
V_332 . V_333 = V_331 ;
V_315 = V_330 ;
goto V_294;
}
#endif
#if F_10 ( V_262 )
case V_136 : {
T_4 V_52 ;
F_54 ( V_52 , F_49 ( V_245 ) ) ;
V_318 . V_317 = F_65 ( V_52 ) ;
V_315 = V_334 ;
goto V_294;
}
case V_134 :
case V_132 :
case V_130 :
case V_128 : {
unsigned int V_331 = V_332 . V_333 ;
T_4 V_52 ;
F_54 ( V_52 , F_49 ( V_245 ) ) ;
V_332 . V_333 = V_271 [ F_27 ( F_31 ( V_245 ) ) ] ;
V_318 . V_317 = F_65 ( V_52 ) ;
V_332 . V_333 = V_331 ;
V_315 = V_334 ;
goto V_294;
}
#endif
default:
if ( F_31 ( V_245 ) >= V_335 ) {
unsigned V_336 = F_31 ( V_245 ) - V_335 ;
T_4 V_52 , V_51 ;
F_54 ( V_52 , F_49 ( V_245 ) ) ;
F_54 ( V_51 , F_47 ( V_245 ) ) ;
V_318 . V_316 = F_66 ( V_52 , V_51 ,
V_337 [ V_336 & 0x7 ] , V_336 & 0x8 ) ;
V_315 = - 1 ;
if ( ( V_336 & 0x8 )
&&
F_53
( V_304 ) )
V_286 = V_305 | V_306 ;
else
goto V_294;
}
else {
return V_28 ;
}
break;
}
break;
}
case V_330 : {
T_5 V_52 ;
switch ( F_31 ( V_245 ) ) {
case V_107 :
F_51 ( V_52 , F_49 ( V_245 ) ) ;
V_318 . V_285 = F_67 ( V_52 . V_345 ) ;
V_315 = V_288 ;
goto V_294;
case V_104 :
F_51 ( V_52 , F_49 ( V_245 ) ) ;
V_318 . V_284 = F_68 ( V_52 . V_345 ) ;
V_315 = V_308 ;
goto V_294;
default:
return V_28 ;
}
break;
}
#if F_10 ( V_262 )
case V_334 : {
switch ( F_31 ( V_245 ) ) {
case V_107 :
V_318 . V_285 = F_69 ( V_243 -> V_346 [ F_49 ( V_245 ) ] ) ;
V_315 = V_288 ;
goto V_294;
case V_104 :
V_318 . V_284 = F_70 ( V_243 -> V_346 [ F_49 ( V_245 ) ] ) ;
V_315 = V_308 ;
goto V_294;
default:
return V_28 ;
}
break;
}
#endif
default:
return V_28 ;
}
V_243 -> V_163 = ( V_243 -> V_163 & ~ V_307 ) | V_286 ;
if ( ( V_243 -> V_163 >> 5 ) & V_243 -> V_163 & V_272 ) {
return V_273 ;
}
switch ( V_315 ) {
case - 1 : {
#if V_275 >= 4
V_155 = V_276 [ F_48 ( V_245 ) >> 2 ] ;
#else
V_155 = V_277 ;
#endif
if ( V_318 . V_316 )
V_243 -> V_163 |= V_155 ;
else
V_243 -> V_163 &= ~ V_155 ;
break;
}
case V_308 :
F_55 ( V_318 . V_284 , F_48 ( V_245 ) ) ;
break;
case V_288 :
F_52 ( V_318 . V_285 , F_48 ( V_245 ) ) ;
break;
case V_330 :
F_24 ( V_318 . V_316 , F_48 ( V_245 ) ) ;
break;
#if F_10 ( V_262 )
case V_334 :
F_20 ( V_318 . V_317 , F_48 ( V_245 ) ) ;
break;
#endif
default:
return V_28 ;
}
return 0 ;
}
int F_71 ( struct V_157 * V_238 , struct V_242 * V_243 ,
int V_347 , void * T_1 * V_244 )
{
unsigned long V_348 , V_349 ;
struct V_159 V_160 ;
T_7 V_350 [ 4 ] ;
T_7 * V_351 ;
int V_283 = 0 ;
V_348 = V_238 -> V_175 ;
do {
V_349 = V_238 -> V_175 ;
if ( F_72 ( V_349 ) && V_165 ) {
if ( ( F_73 ( V_350 [ 0 ] , ( T_7 T_1 * ) F_74 ( V_238 -> V_175 ) ) ) ||
( F_73 ( V_350 [ 1 ] , ( T_7 T_1 * ) F_74 ( V_238 -> V_175 + 2 ) ) ) ||
( F_73 ( V_350 [ 2 ] , ( T_7 T_1 * ) F_74 ( V_238 -> V_175 + 4 ) ) ) ||
( F_73 ( V_350 [ 3 ] , ( T_7 T_1 * ) F_74 ( V_238 -> V_175 + 6 ) ) ) ) {
F_14 ( V_257 ) ;
return V_258 ;
}
V_351 = V_350 ;
if ( F_75 ( * V_351 ) ) {
V_160 . V_3 = ( * V_351 << 16 ) |
( * V_351 ) ;
V_160 . V_176 = 2 ;
V_351 += 1 ;
} else {
V_160 . V_3 = ( * V_351 << 16 ) |
* ( V_351 + 1 ) ;
V_160 . V_176 = 4 ;
V_351 += 2 ;
}
if ( F_75 ( * V_351 ) ) {
V_160 . V_249 = ( * V_351 << 16 ) |
( * V_351 ) ;
V_160 . V_177 = 2 ;
} else {
V_160 . V_249 = ( * V_351 << 16 ) |
* ( V_351 + 1 ) ;
V_160 . V_177 = 4 ;
}
V_160 . V_248 = 1 ;
} else {
if ( ( F_73 ( V_160 . V_3 ,
( V_1 T_1 * ) V_238 -> V_175 ) ) ||
( F_73 ( V_160 . V_249 ,
( V_1 T_1 * ) ( V_238 -> V_175 + 4 ) ) ) ) {
F_14 ( V_257 ) ;
return V_258 ;
}
V_160 . V_176 = 4 ;
V_160 . V_177 = 4 ;
V_160 . V_248 = 0 ;
}
if ( ( V_160 . V_3 == 0 ) ||
( ( V_160 . V_176 == 2 ) &&
( ( V_160 . V_3 & 0xffff ) == V_282 ) ) )
V_238 -> V_175 += V_160 . V_176 ;
else {
V_332 . V_333 = V_271 [ V_332 . V_333 ] ;
V_283 = F_12 ( V_238 , V_243 , V_160 , V_244 ) ;
V_332 . V_333 = V_268 [ V_332 . V_333 ] ;
}
if ( V_347 )
break;
if ( V_283 )
break;
F_76 () ;
} while ( V_238 -> V_175 > V_349 );
if ( V_283 == V_28 && V_238 -> V_175 != V_348 )
V_283 = 0 ;
return V_283 ;
}
static int F_77 ( void * V_352 , T_2 * V_254 )
{
int V_353 ;
unsigned long V_354 = 0 ;
F_78 (cpu) {
struct V_355 * V_356 ;
T_8 * V_357 ;
V_356 = & F_79 ( V_358 , V_353 ) ;
V_357 = ( void * ) V_356 + ( unsigned long ) V_352 ;
V_354 += F_80 ( V_357 ) ;
}
* V_254 = V_354 ;
return 0 ;
}
static int T_9 F_81 ( void )
{
struct V_359 * V_284 , * V_360 ;
if ( ! V_361 )
return - V_362 ;
V_360 = F_82 ( L_3 , V_361 ) ;
if ( ! V_360 )
return - V_363 ;
#define F_83 ( T_10 ) \
do { \
d = debugfs_create_file(#M , S_IRUGO, dir, \
(void *)offsetof(struct mips_fpu_emulator_stats, M), \
&fops_fpuemu_stat); \
if (!d) \
return -ENOMEM; \
} while (0)
F_83 ( V_252 ) ;
F_83 ( V_255 ) ;
F_83 ( V_260 ) ;
F_83 ( V_319 ) ;
F_83 ( V_287 ) ;
F_83 ( V_257 ) ;
return 0 ;
}
