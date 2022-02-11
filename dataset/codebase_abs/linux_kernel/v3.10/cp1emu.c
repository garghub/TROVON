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
switch ( V_3 . V_8 . V_9 ) {
case V_165 :
if ( ( V_3 . V_8 . V_166 & V_167 ) ==
V_168 ) {
switch ( V_3 . V_8 . V_166 >>
V_169 ) {
case V_170 :
case V_171 :
case V_172 :
case V_173 :
if ( V_3 . V_8 . V_12 != 0 )
V_158 -> V_158 [ V_3 . V_8 . V_12 ] =
V_158 -> V_174 +
V_160 . V_175 +
V_160 . V_176 ;
* V_161 = V_158 -> V_158 [ V_3 . V_8 . V_13 ] ;
return 1 ;
break;
}
}
break;
case V_20 :
switch ( V_3 . V_8 . V_12 ) {
case V_177 :
case V_178 :
V_158 -> V_158 [ 31 ] = V_158 -> V_174 +
V_160 . V_175 +
V_160 . V_176 ;
case V_179 :
if ( ( long ) V_158 -> V_158 [ V_3 . V_8 . V_13 ] < 0 )
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
( V_3 . V_8 . V_166 << 1 ) ;
else
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
V_160 . V_176 ;
return 1 ;
break;
case V_180 :
case V_181 :
V_158 -> V_158 [ 31 ] = V_158 -> V_174 +
V_160 . V_175 +
V_160 . V_176 ;
case V_182 :
if ( ( long ) V_158 -> V_158 [ V_3 . V_8 . V_13 ] >= 0 )
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
( V_3 . V_8 . V_166 << 1 ) ;
else
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
V_160 . V_176 ;
return 1 ;
break;
case V_183 :
if ( ( long ) V_158 -> V_158 [ V_3 . V_8 . V_13 ] <= 0 )
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
( V_3 . V_8 . V_166 << 1 ) ;
else
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
V_160 . V_176 ;
return 1 ;
break;
case V_184 :
if ( ( long ) V_158 -> V_158 [ V_3 . V_8 . V_13 ] <= 0 )
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
( V_3 . V_8 . V_166 << 1 ) ;
else
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
V_160 . V_176 ;
return 1 ;
break;
case V_185 :
case V_21 :
V_162 = 1 ;
case V_186 :
case V_22 :
F_3 () ;
if ( F_4 () )
asm volatile("cfc1\t%0,$31" : "=r" (fcr31));
else
V_163 = V_187 -> V_188 . V_189 . V_163 ;
F_5 () ;
if ( V_162 )
V_163 = ~ V_163 ;
V_164 = ( V_3 . V_8 . V_13 >> 2 ) ;
V_164 += ( V_164 != 0 ) ;
V_164 += 23 ;
if ( V_163 & ( 1 << V_164 ) )
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
( V_3 . V_8 . V_166 << 1 ) ;
else
* V_161 = V_158 -> V_174 +
V_160 . V_175 + V_160 . V_176 ;
return 1 ;
break;
}
break;
case V_190 :
switch ( V_3 . V_8 . V_12 ) {
case V_191 :
case V_192 :
V_158 -> V_158 [ 31 ] = V_158 -> V_174 +
V_160 . V_175 + V_160 . V_176 ;
case V_193 :
* V_161 = V_158 -> V_158 [ V_3 . V_8 . V_13 ] ;
return 1 ;
break;
}
break;
case V_194 :
if ( ( long ) V_158 -> V_158 [ V_195 [ V_3 . V_196 . V_13 ] ] == 0 )
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
( V_3 . V_196 . V_166 << 1 ) ;
else
* V_161 = V_158 -> V_174 +
V_160 . V_175 + V_160 . V_176 ;
return 1 ;
break;
case V_197 :
if ( ( long ) V_158 -> V_158 [ V_195 [ V_3 . V_196 . V_13 ] ] != 0 )
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
( V_3 . V_196 . V_166 << 1 ) ;
else
* V_161 = V_158 -> V_174 +
V_160 . V_175 + V_160 . V_176 ;
return 1 ;
break;
case V_198 :
* V_161 = V_158 -> V_174 + V_160 . V_175 +
( V_3 . V_199 . V_166 << 1 ) ;
return 1 ;
break;
case V_200 :
if ( V_158 -> V_158 [ V_3 . V_8 . V_13 ] ==
V_158 -> V_158 [ V_3 . V_8 . V_12 ] )
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
( V_3 . V_8 . V_166 << 1 ) ;
else
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
V_160 . V_176 ;
return 1 ;
break;
case V_201 :
if ( V_158 -> V_158 [ V_3 . V_8 . V_13 ] !=
V_158 -> V_158 [ V_3 . V_8 . V_12 ] )
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
( V_3 . V_8 . V_166 << 1 ) ;
else
* V_161 = V_158 -> V_174 +
V_160 . V_175 + V_160 . V_176 ;
return 1 ;
break;
case V_202 :
V_158 -> V_158 [ 31 ] = V_158 -> V_174 +
V_160 . V_175 + V_160 . V_176 ;
* V_161 = V_158 -> V_174 + V_160 . V_175 ;
* V_161 >>= 28 ;
* V_161 <<= 28 ;
* V_161 |= ( V_3 . V_203 . V_204 << 2 ) ;
return 1 ;
break;
case V_205 :
case V_206 :
V_158 -> V_158 [ 31 ] = V_158 -> V_174 +
V_160 . V_175 + V_160 . V_176 ;
case V_207 :
* V_161 = V_158 -> V_174 + V_160 . V_175 ;
* V_161 >>= 27 ;
* V_161 <<= 27 ;
* V_161 |= ( V_3 . V_203 . V_204 << 1 ) ;
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
switch ( V_3 . V_208 . V_9 ) {
case V_97 :
switch ( V_3 . V_64 . V_5 ) {
case V_209 :
V_158 -> V_158 [ V_3 . V_64 . V_67 ] =
V_158 -> V_174 + V_160 . V_175 +
V_160 . V_176 ;
case V_210 :
* V_161 = V_158 -> V_158 [ V_3 . V_64 . V_13 ] ;
return 1 ;
break;
}
break;
case V_211 :
switch ( V_3 . V_208 . V_12 ) {
case V_212 :
case V_213 :
V_158 -> V_158 [ 31 ] = V_158 -> V_174 +
V_160 . V_175 +
V_160 . V_176 ;
case V_214 :
case V_215 :
if ( ( long ) V_158 -> V_158 [ V_3 . V_208 . V_13 ] < 0 )
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
( V_3 . V_208 . V_166 << 2 ) ;
else
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
V_160 . V_176 ;
return 1 ;
break;
case V_216 :
case V_217 :
V_158 -> V_158 [ 31 ] = V_158 -> V_174 +
V_160 . V_175 +
V_160 . V_176 ;
case V_218 :
case V_219 :
if ( ( long ) V_158 -> V_158 [ V_3 . V_208 . V_13 ] >= 0 )
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
( V_3 . V_208 . V_166 << 2 ) ;
else
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
V_160 . V_176 ;
return 1 ;
break;
}
break;
case V_220 :
F_6 ( V_164 ) ;
case V_221 :
V_158 -> V_158 [ 31 ] = V_158 -> V_174 +
V_160 . V_175 +
V_160 . V_176 ;
case V_222 :
* V_161 = V_158 -> V_174 + V_160 . V_175 ;
* V_161 >>= 28 ;
* V_161 <<= 28 ;
* V_161 |= ( V_3 . V_203 . V_204 << 2 ) ;
* V_161 ^= V_164 ;
return 1 ;
break;
case V_223 :
case V_224 :
if ( V_158 -> V_158 [ V_3 . V_208 . V_13 ] ==
V_158 -> V_158 [ V_3 . V_208 . V_12 ] )
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
( V_3 . V_208 . V_166 << 2 ) ;
else
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
V_160 . V_176 ;
return 1 ;
break;
case V_225 :
case V_226 :
if ( V_158 -> V_158 [ V_3 . V_208 . V_13 ] !=
V_158 -> V_158 [ V_3 . V_208 . V_12 ] )
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
( V_3 . V_208 . V_166 << 2 ) ;
else
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
V_160 . V_176 ;
return 1 ;
break;
case V_227 :
case V_228 :
if ( ( long ) V_158 -> V_158 [ V_3 . V_208 . V_13 ] <= 0 )
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
( V_3 . V_208 . V_166 << 2 ) ;
else
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
V_160 . V_176 ;
return 1 ;
break;
case V_229 :
case V_230 :
if ( ( long ) V_158 -> V_158 [ V_3 . V_208 . V_13 ] > 0 )
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
( V_3 . V_208 . V_166 << 2 ) ;
else
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
V_160 . V_176 ;
return 1 ;
break;
case V_231 :
case V_24 :
case V_232 :
case V_48 :
if ( V_3 . V_208 . V_13 == V_26 ) {
F_3 () ;
if ( F_4 () )
asm volatile("cfc1\t%0,$31" : "=r" (fcr31));
else
V_163 = V_187 -> V_188 . V_189 . V_163 ;
F_5 () ;
V_164 = ( V_3 . V_208 . V_12 >> 2 ) ;
V_164 += ( V_164 != 0 ) ;
V_164 += 23 ;
switch ( V_3 . V_208 . V_12 & 3 ) {
case 0 :
case 2 :
if ( ~ V_163 & ( 1 << V_164 ) )
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
( V_3 . V_208 . V_166 << 2 ) ;
else
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
V_160 . V_176 ;
return 1 ;
break;
case 1 :
case 3 :
if ( V_163 & ( 1 << V_164 ) )
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
( V_3 . V_208 . V_166 << 2 ) ;
else
* V_161 = V_158 -> V_174 +
V_160 . V_175 +
V_160 . V_176 ;
return 1 ;
break;
}
}
break;
}
return 0 ;
}
static inline int F_8 ( struct V_157 * V_233 )
{
#if F_9 ( V_234 ) && ! F_9 ( V_235 )
return 1 ;
#elif F_9 ( V_234 ) && F_9 ( V_235 )
return ! F_10 ( V_236 ) ;
#else
return 0 ;
#endif
}
static int F_11 ( struct V_157 * V_233 , struct V_237 * V_238 ,
struct V_159 V_160 , void * T_1 * V_239 )
{
V_1 V_240 ;
unsigned long V_161 = V_233 -> V_174 + V_160 . V_175 ;
unsigned int V_155 ;
int V_175 ;
if ( V_233 -> V_241 & V_242 ) {
if ( V_160 . V_243 ) {
if ( ! F_2 ( V_233 , V_160 , & V_161 ) )
V_233 -> V_241 &= ~ V_242 ;
} else {
if ( ! F_7 ( V_233 , V_160 , & V_161 ) )
V_233 -> V_241 &= ~ V_242 ;
}
}
if ( V_233 -> V_241 & V_242 ) {
V_240 = V_160 . V_244 ;
V_175 = V_160 . V_176 ;
} else {
V_240 = V_160 . V_3 ;
V_175 = V_160 . V_175 ;
}
if ( V_160 . V_243 ) {
if ( ( V_175 == 2 ) ||
( F_1 ( (union V_1 * ) & V_240 )
== V_28 ) )
return V_28 ;
}
V_245:
F_12 ( V_246 , 1 , V_233 , 0 ) ;
F_13 ( V_247 ) ;
switch ( F_14 ( V_240 ) ) {
case V_11 : {
T_2 T_1 * V_248 = ( T_2 T_1 * ) ( V_233 -> V_158 [ F_15 ( V_240 ) ] +
F_16 ( V_240 ) ) ;
T_2 V_249 ;
F_13 ( V_250 ) ;
if ( ! F_17 ( V_251 , V_248 , sizeof( T_2 ) ) ) {
F_13 ( V_252 ) ;
* V_239 = V_248 ;
return V_253 ;
}
if ( F_18 ( V_249 , V_248 ) ) {
F_13 ( V_252 ) ;
* V_239 = V_248 ;
return V_254 ;
}
F_19 ( V_249 , F_20 ( V_240 ) ) ;
break;
}
case V_17 : {
T_2 T_1 * V_248 = ( T_2 T_1 * ) ( V_233 -> V_158 [ F_15 ( V_240 ) ] +
F_16 ( V_240 ) ) ;
T_2 V_249 ;
F_13 ( V_255 ) ;
F_21 ( V_249 , F_20 ( V_240 ) ) ;
if ( ! F_17 ( V_256 , V_248 , sizeof( T_2 ) ) ) {
F_13 ( V_252 ) ;
* V_239 = V_248 ;
return V_253 ;
}
if ( F_22 ( V_249 , V_248 ) ) {
F_13 ( V_252 ) ;
* V_239 = V_248 ;
return V_254 ;
}
break;
}
case V_15 : {
T_3 T_1 * V_248 = ( T_3 T_1 * ) ( V_233 -> V_158 [ F_15 ( V_240 ) ] +
F_16 ( V_240 ) ) ;
T_3 V_249 ;
F_13 ( V_250 ) ;
if ( ! F_17 ( V_251 , V_248 , sizeof( T_3 ) ) ) {
F_13 ( V_252 ) ;
* V_239 = V_248 ;
return V_253 ;
}
if ( F_18 ( V_249 , V_248 ) ) {
F_13 ( V_252 ) ;
* V_239 = V_248 ;
return V_254 ;
}
F_23 ( V_249 , F_20 ( V_240 ) ) ;
break;
}
case V_19 : {
T_3 T_1 * V_248 = ( T_3 T_1 * ) ( V_233 -> V_158 [ F_15 ( V_240 ) ] +
F_16 ( V_240 ) ) ;
T_3 V_249 ;
F_13 ( V_255 ) ;
F_24 ( V_249 , F_20 ( V_240 ) ) ;
if ( ! F_17 ( V_256 , V_248 , sizeof( T_3 ) ) ) {
F_13 ( V_252 ) ;
* V_239 = V_248 ;
return V_253 ;
}
if ( F_22 ( V_249 , V_248 ) ) {
F_13 ( V_252 ) ;
* V_239 = V_248 ;
return V_254 ;
}
break;
}
case V_24 :
switch ( F_15 ( V_240 ) ) {
#if F_9 ( V_257 )
case V_258 :
if ( F_20 ( V_240 ) != 0 ) {
F_21 ( V_233 -> V_158 [ F_20 ( V_240 ) ] ,
F_25 ( V_240 ) ) ;
}
break;
case V_259 :
F_19 ( V_233 -> V_158 [ F_20 ( V_240 ) ] , F_25 ( V_240 ) ) ;
break;
#endif
case V_149 :
if ( F_20 ( V_240 ) != 0 ) {
F_24 ( V_233 -> V_158 [ F_20 ( V_240 ) ] ,
F_25 ( V_240 ) ) ;
}
break;
case V_150 :
F_23 ( V_233 -> V_158 [ F_20 ( V_240 ) ] , F_25 ( V_240 ) ) ;
break;
case V_151 : {
T_3 V_260 ;
if ( F_25 ( V_240 ) == V_261 ) {
V_260 = V_238 -> V_163 ;
V_260 = ( V_260 & ~ V_262 ) |
V_263 [ F_26 ( V_260 ) ] ;
#ifdef F_27
F_28 ( L_1 ,
( void * ) ( V_233 -> V_174 ) ,
F_20 ( V_240 ) , V_260 ) ;
#endif
}
else if ( F_25 ( V_240 ) == V_264 )
V_260 = 0 ;
else
V_260 = 0 ;
if ( F_20 ( V_240 ) )
V_233 -> V_158 [ F_20 ( V_240 ) ] = V_260 ;
break;
}
case V_152 : {
T_3 V_260 ;
if ( F_20 ( V_240 ) == 0 )
V_260 = 0 ;
else
V_260 = V_233 -> V_158 [ F_20 ( V_240 ) ] ;
if ( F_25 ( V_240 ) == V_261 ) {
#ifdef F_27
F_28 ( L_2 ,
( void * ) ( V_233 -> V_174 ) ,
F_20 ( V_240 ) , V_260 ) ;
#endif
V_238 -> V_163 = ( V_260 &
~ ( V_265 | V_262 ) ) |
V_266 [ F_26 ( V_260 ) ] ;
}
if ( ( V_238 -> V_163 >> 5 ) & V_238 -> V_163 & V_267 ) {
return V_268 ;
}
break;
}
case V_26 : {
int V_269 = 0 ;
if ( V_233 -> V_241 & V_242 )
return V_28 ;
#if V_270 >= 4
V_155 = V_238 -> V_163 & V_271 [ F_20 ( V_240 ) >> 2 ] ;
#else
V_155 = V_238 -> V_163 & V_272 ;
#endif
switch ( F_20 ( V_240 ) & 3 ) {
case V_273 :
V_269 = 1 ;
case V_274 :
V_155 = ! V_155 ;
break;
case V_275 :
V_269 = 1 ;
case V_276 :
break;
default:
return V_28 ;
}
V_233 -> V_241 |= V_242 ;
if ( V_155 ) {
V_233 -> V_174 += V_160 . V_175 ;
V_161 = F_16 ( V_240 ) ;
V_240 = V_160 . V_244 ;
if ( V_160 . V_243 ) {
V_161 = ( V_233 -> V_174 + ( V_161 << 1 ) ) ;
if ( ( V_160 . V_176 == 2 ) ||
( F_1 ( (union V_1 * ) & V_240 ) == V_28 ) ) {
if ( V_160 . V_176 == 2 )
V_240 = ( V_240 & ( ~ 0xffff ) ) | V_277 ;
return F_29 ( V_233 , V_240 , V_161 ) ;
}
} else
V_161 = ( V_233 -> V_174 + ( V_161 << 2 ) ) ;
switch ( F_14 ( V_240 ) ) {
case V_15 :
case V_19 :
#if ( V_270 >= 2 || F_9 ( V_257 ) )
case V_11 :
case V_17 :
#endif
case V_24 :
#if V_270 >= 4 && V_270 != 32
case V_48 :
#endif
goto V_245;
#if V_270 >= 4
case V_97 :
if ( F_30 ( V_240 ) == V_99 )
goto V_245;
break;
#endif
}
return F_29 ( V_233 , V_240 , V_161 ) ;
}
else {
if ( V_269 ) {
V_233 -> V_174 += V_160 . V_175 ;
V_161 += V_160 . V_175 ;
}
}
break;
}
default:
if ( ! ( F_15 ( V_240 ) & 0x10 ) )
return V_28 ;
{
int V_278 ;
if ( ( V_278 = F_31 ( V_233 , V_238 , V_240 ) ) )
return V_278 ;
}
}
break;
#if V_270 >= 4 && V_270 != 32
case V_48 : {
int V_278 = F_32 ( V_233 , V_238 , V_240 , V_239 ) ;
if ( V_278 )
return V_278 ;
break;
}
#endif
#if V_270 >= 4
case V_97 :
if ( F_30 ( V_240 ) != V_99 )
return V_28 ;
V_155 = V_271 [ F_20 ( V_240 ) >> 2 ] ;
if ( ( ( V_238 -> V_163 & V_155 ) != 0 ) == ( ( F_20 ( V_240 ) & 1 ) != 0 ) )
V_233 -> V_158 [ F_25 ( V_240 ) ] =
V_233 -> V_158 [ F_15 ( V_240 ) ] ;
break;
#endif
default:
return V_28 ;
}
V_233 -> V_174 = V_161 ;
V_233 -> V_241 &= ~ V_242 ;
return 0 ;
}
static T_4 F_33 ( T_4 V_279 )
{
return F_34 ( F_35 ( 0 ) , V_279 ) ;
}
static T_4 F_36 ( T_4 V_279 )
{
return F_34 ( F_35 ( 0 ) , F_37 ( V_279 ) ) ;
}
static T_5 F_38 ( T_5 V_280 )
{
return F_39 ( F_40 ( 0 ) , V_280 ) ;
}
static T_5 F_41 ( T_5 V_280 )
{
return F_39 ( F_40 ( 0 ) , F_42 ( V_280 ) ) ;
}
static int F_32 ( struct V_157 * V_233 , struct V_237 * V_238 ,
V_1 V_240 , void * T_1 * V_239 )
{
unsigned V_281 = 0 ;
F_13 ( V_282 ) ;
switch ( F_43 ( V_240 ) ) {
case V_283 : {
T_5 (* F_44) ( T_5 , T_5 , T_5 );
T_5 V_53 , V_49 , V_52 , V_51 ;
T_3 T_1 * V_248 ;
T_3 V_249 ;
switch ( F_30 ( V_240 ) ) {
case V_61 :
V_248 = ( void T_1 * ) ( V_233 -> V_158 [ F_45 ( V_240 ) ] +
V_233 -> V_158 [ F_46 ( V_240 ) ] ) ;
F_13 ( V_250 ) ;
if ( ! F_17 ( V_251 , V_248 , sizeof( T_3 ) ) ) {
F_13 ( V_252 ) ;
* V_239 = V_248 ;
return V_253 ;
}
if ( F_18 ( V_249 , V_248 ) ) {
F_13 ( V_252 ) ;
* V_239 = V_248 ;
return V_254 ;
}
F_23 ( V_249 , F_47 ( V_240 ) ) ;
break;
case V_63 :
V_248 = ( void T_1 * ) ( V_233 -> V_158 [ F_45 ( V_240 ) ] +
V_233 -> V_158 [ F_46 ( V_240 ) ] ) ;
F_13 ( V_255 ) ;
F_24 ( V_249 , F_48 ( V_240 ) ) ;
if ( ! F_17 ( V_256 , V_248 , sizeof( T_3 ) ) ) {
F_13 ( V_252 ) ;
* V_239 = V_248 ;
return V_253 ;
}
if ( F_49 ( V_249 , V_248 ) ) {
F_13 ( V_252 ) ;
* V_239 = V_248 ;
return V_254 ;
}
break;
case V_39 :
F_44 = V_284 ;
goto V_285;
case V_43 :
F_44 = V_286 ;
goto V_285;
case V_41 :
F_44 = V_287 ;
goto V_285;
case V_45 :
F_44 = V_288 ;
goto V_285;
V_285:
F_50 ( V_49 , F_45 ( V_240 ) ) ;
F_50 ( V_52 , F_48 ( V_240 ) ) ;
F_50 ( V_51 , F_46 ( V_240 ) ) ;
V_53 = (* F_44) ( V_49 , V_52 , V_51 ) ;
F_51 ( V_53 , F_47 ( V_240 ) ) ;
V_289:
if ( F_52 ( V_290 ) )
V_281 |= V_291 | V_292 ;
if ( F_52 ( V_293 ) )
V_281 |= V_294 | V_295 ;
if ( F_52 ( V_296 ) )
V_281 |= V_297 | V_298 ;
if ( F_52 ( V_299 ) )
V_281 |= V_300 | V_301 ;
V_238 -> V_163 = ( V_238 -> V_163 & ~ V_302 ) | V_281 ;
if ( ( V_238 -> V_163 >> 5 ) & V_238 -> V_163 & V_267 ) {
return V_268 ;
}
break;
default:
return V_28 ;
}
break;
}
case V_303 : {
T_4 (* F_44) ( T_4 , T_4 , T_4 );
T_4 V_53 , V_49 , V_52 , V_51 ;
T_2 T_1 * V_248 ;
T_2 V_249 ;
switch ( F_30 ( V_240 ) ) {
case V_57 :
V_248 = ( void T_1 * ) ( V_233 -> V_158 [ F_45 ( V_240 ) ] +
V_233 -> V_158 [ F_46 ( V_240 ) ] ) ;
F_13 ( V_250 ) ;
if ( ! F_17 ( V_251 , V_248 , sizeof( T_2 ) ) ) {
F_13 ( V_252 ) ;
* V_239 = V_248 ;
return V_253 ;
}
if ( F_18 ( V_249 , V_248 ) ) {
F_13 ( V_252 ) ;
* V_239 = V_248 ;
return V_254 ;
}
F_19 ( V_249 , F_47 ( V_240 ) ) ;
break;
case V_59 :
V_248 = ( void T_1 * ) ( V_233 -> V_158 [ F_45 ( V_240 ) ] +
V_233 -> V_158 [ F_46 ( V_240 ) ] ) ;
F_13 ( V_255 ) ;
F_21 ( V_249 , F_48 ( V_240 ) ) ;
if ( ! F_17 ( V_256 , V_248 , sizeof( T_2 ) ) ) {
F_13 ( V_252 ) ;
* V_239 = V_248 ;
return V_253 ;
}
if ( F_22 ( V_249 , V_248 ) ) {
F_13 ( V_252 ) ;
* V_239 = V_248 ;
return V_254 ;
}
break;
case V_40 :
F_44 = V_304 ;
goto V_305;
case V_44 :
F_44 = V_306 ;
goto V_305;
case V_42 :
F_44 = V_307 ;
goto V_305;
case V_46 :
F_44 = V_308 ;
goto V_305;
V_305:
F_53 ( V_49 , F_45 ( V_240 ) ) ;
F_53 ( V_52 , F_48 ( V_240 ) ) ;
F_53 ( V_51 , F_46 ( V_240 ) ) ;
V_53 = (* F_44) ( V_49 , V_52 , V_51 ) ;
F_54 ( V_53 , F_47 ( V_240 ) ) ;
goto V_289;
default:
return V_28 ;
}
break;
}
case 0x7 :
if ( F_30 ( V_240 ) != V_309 ) {
return V_28 ;
}
break;
default:
return V_28 ;
}
return 0 ;
}
static int F_31 ( struct V_157 * V_233 , struct V_237 * V_238 ,
V_1 V_240 )
{
int V_310 ;
unsigned V_281 = 0 ;
unsigned V_155 ;
union {
T_4 V_279 ;
T_5 V_280 ;
int V_311 ;
#ifdef V_257
T_6 V_312 ;
#endif
} V_313 ;
F_13 ( V_314 ) ;
switch ( V_310 = ( F_55 ( V_240 ) & 0xf ) ) {
case V_283 : {
union {
T_5 (* F_56) ( T_5 , T_5 );
T_5 (* F_57) ( T_5 );
} F_44 ;
switch ( F_30 ( V_240 ) ) {
case V_79 :
F_44 . F_56 = V_315 ;
goto V_316;
case V_81 :
F_44 . F_56 = V_317 ;
goto V_316;
case V_83 :
F_44 . F_56 = V_318 ;
goto V_316;
case V_85 :
F_44 . F_56 = F_39 ;
goto V_316;
#if V_270 >= 2 || F_9 ( V_257 )
case V_143 :
F_44 . F_57 = F_42 ;
goto V_319;
#endif
#if V_270 >= 4 && V_270 != 32
case V_142 :
F_44 . F_57 = F_41 ;
goto V_319;
case V_144 :
F_44 . F_57 = F_38 ;
goto V_319;
#endif
#if V_270 >= 4
case V_76 :
V_155 = V_271 [ F_46 ( V_240 ) >> 2 ] ;
if ( ( ( V_238 -> V_163 & V_155 ) != 0 ) !=
( ( F_46 ( V_240 ) & 1 ) != 0 ) )
return 0 ;
F_50 ( V_313 . V_280 , F_48 ( V_240 ) ) ;
break;
case V_90 :
if ( V_233 -> V_158 [ F_46 ( V_240 ) ] != 0 )
return 0 ;
F_50 ( V_313 . V_280 , F_48 ( V_240 ) ) ;
break;
case V_88 :
if ( V_233 -> V_158 [ F_46 ( V_240 ) ] == 0 )
return 0 ;
F_50 ( V_313 . V_280 , F_48 ( V_240 ) ) ;
break;
#endif
case V_116 :
F_44 . F_57 = V_320 ;
goto V_319;
case V_117 :
F_44 . F_57 = V_321 ;
goto V_319;
case V_115 :
F_50 ( V_313 . V_280 , F_48 ( V_240 ) ) ;
goto V_289;
V_316:
{
T_5 V_52 , V_51 ;
F_50 ( V_52 , F_48 ( V_240 ) ) ;
F_50 ( V_51 , F_46 ( V_240 ) ) ;
V_313 . V_280 = (* F_44 . F_56 ) ( V_52 , V_51 ) ;
goto V_289;
}
V_319:
{
T_5 V_52 ;
F_50 ( V_52 , F_48 ( V_240 ) ) ;
V_313 . V_280 = (* F_44 . F_57 ) ( V_52 ) ;
goto V_289;
}
V_289:
if ( F_52 ( V_290 ) )
V_281 |= V_291 | V_292 ;
if ( F_52 ( V_293 ) )
V_281 |= V_294 | V_295 ;
if ( F_52 ( V_296 ) )
V_281 |= V_297 | V_298 ;
if ( F_52 ( V_322 ) )
V_281 |= V_323 | V_324 ;
if ( F_52 ( V_299 ) )
V_281 |= V_300 | V_301 ;
break;
case V_107 :
return V_28 ;
case V_104 : {
T_5 V_52 ;
F_50 ( V_52 , F_48 ( V_240 ) ) ;
V_313 . V_279 = F_58 ( V_52 ) ;
V_310 = V_303 ;
goto V_289;
}
case V_137 : {
T_5 V_52 ;
F_50 ( V_52 , F_48 ( V_240 ) ) ;
V_313 . V_311 = F_59 ( V_52 ) ;
V_310 = V_325 ;
goto V_289;
}
#if V_270 >= 2 || F_9 ( V_257 )
case V_135 :
case V_133 :
case V_131 :
case V_129 : {
unsigned int V_326 = V_327 . V_328 ;
T_5 V_52 ;
F_50 ( V_52 , F_48 ( V_240 ) ) ;
V_327 . V_328 = V_266 [ F_26 ( F_30 ( V_240 ) ) ] ;
V_313 . V_311 = F_59 ( V_52 ) ;
V_327 . V_328 = V_326 ;
V_310 = V_325 ;
goto V_289;
}
#endif
#if F_9 ( V_257 )
case V_136 : {
T_5 V_52 ;
F_50 ( V_52 , F_48 ( V_240 ) ) ;
V_313 . V_312 = F_60 ( V_52 ) ;
V_310 = V_329 ;
goto V_289;
}
case V_134 :
case V_132 :
case V_130 :
case V_128 : {
unsigned int V_326 = V_327 . V_328 ;
T_5 V_52 ;
F_50 ( V_52 , F_48 ( V_240 ) ) ;
V_327 . V_328 = V_266 [ F_26 ( F_30 ( V_240 ) ) ] ;
V_313 . V_312 = F_60 ( V_52 ) ;
V_327 . V_328 = V_326 ;
V_310 = V_329 ;
goto V_289;
}
#endif
default:
if ( F_30 ( V_240 ) >= V_330 ) {
unsigned V_331 = F_30 ( V_240 ) - V_330 ;
T_5 V_52 , V_51 ;
F_50 ( V_52 , F_48 ( V_240 ) ) ;
F_50 ( V_51 , F_46 ( V_240 ) ) ;
V_313 . V_311 = F_61 ( V_52 , V_51 ,
V_332 [ V_331 & 0x7 ] , V_331 & 0x8 ) ;
V_310 = - 1 ;
if ( ( V_331 & 0x8 ) && F_52
( V_299 ) )
V_281 = V_300 | V_301 ;
else
goto V_289;
}
else {
return V_28 ;
}
break;
}
break;
}
case V_303 : {
union {
T_4 (* F_56) ( T_4 , T_4 );
T_4 (* F_57) ( T_4 );
} F_44 ;
switch ( F_30 ( V_240 ) ) {
case V_79 :
F_44 . F_56 = V_333 ;
goto V_334;
case V_81 :
F_44 . F_56 = V_335 ;
goto V_334;
case V_83 :
F_44 . F_56 = V_336 ;
goto V_334;
case V_85 :
F_44 . F_56 = F_34 ;
goto V_334;
#if V_270 >= 2 || F_9 ( V_257 )
case V_143 :
F_44 . F_57 = F_37 ;
goto V_337;
#endif
#if V_270 >= 4 && V_270 != 32
case V_142 :
F_44 . F_57 = F_36 ;
goto V_337;
case V_144 :
F_44 . F_57 = F_33 ;
goto V_337;
#endif
#if V_270 >= 4
case V_76 :
V_155 = V_271 [ F_46 ( V_240 ) >> 2 ] ;
if ( ( ( V_238 -> V_163 & V_155 ) != 0 ) !=
( ( F_46 ( V_240 ) & 1 ) != 0 ) )
return 0 ;
F_53 ( V_313 . V_279 , F_48 ( V_240 ) ) ;
break;
case V_90 :
if ( V_233 -> V_158 [ F_46 ( V_240 ) ] != 0 )
return 0 ;
F_53 ( V_313 . V_279 , F_48 ( V_240 ) ) ;
break;
case V_88 :
if ( V_233 -> V_158 [ F_46 ( V_240 ) ] == 0 )
return 0 ;
F_53 ( V_313 . V_279 , F_48 ( V_240 ) ) ;
break;
#endif
case V_116 :
F_44 . F_57 = V_338 ;
goto V_337;
case V_117 :
F_44 . F_57 = V_339 ;
goto V_337;
case V_115 :
F_53 ( V_313 . V_279 , F_48 ( V_240 ) ) ;
goto V_289;
V_334: {
T_4 V_52 , V_51 ;
F_53 ( V_52 , F_48 ( V_240 ) ) ;
F_53 ( V_51 , F_46 ( V_240 ) ) ;
V_313 . V_279 = (* F_44 . F_56 ) ( V_52 , V_51 ) ;
goto V_289;
}
V_337: {
T_4 V_52 ;
F_53 ( V_52 , F_48 ( V_240 ) ) ;
V_313 . V_279 = (* F_44 . F_57 ) ( V_52 ) ;
goto V_289;
}
case V_107 : {
T_4 V_52 ;
F_53 ( V_52 , F_48 ( V_240 ) ) ;
V_313 . V_280 = F_62 ( V_52 ) ;
V_310 = V_283 ;
goto V_289;
}
case V_104 :
return V_28 ;
case V_137 : {
T_4 V_52 ;
F_53 ( V_52 , F_48 ( V_240 ) ) ;
V_313 . V_311 = F_63 ( V_52 ) ;
V_310 = V_325 ;
goto V_289;
}
#if V_270 >= 2 || F_9 ( V_257 )
case V_135 :
case V_133 :
case V_131 :
case V_129 : {
unsigned int V_326 = V_327 . V_328 ;
T_4 V_52 ;
F_53 ( V_52 , F_48 ( V_240 ) ) ;
V_327 . V_328 = V_266 [ F_26 ( F_30 ( V_240 ) ) ] ;
V_313 . V_311 = F_63 ( V_52 ) ;
V_327 . V_328 = V_326 ;
V_310 = V_325 ;
goto V_289;
}
#endif
#if F_9 ( V_257 )
case V_136 : {
T_4 V_52 ;
F_53 ( V_52 , F_48 ( V_240 ) ) ;
V_313 . V_312 = F_64 ( V_52 ) ;
V_310 = V_329 ;
goto V_289;
}
case V_134 :
case V_132 :
case V_130 :
case V_128 : {
unsigned int V_326 = V_327 . V_328 ;
T_4 V_52 ;
F_53 ( V_52 , F_48 ( V_240 ) ) ;
V_327 . V_328 = V_266 [ F_26 ( F_30 ( V_240 ) ) ] ;
V_313 . V_312 = F_64 ( V_52 ) ;
V_327 . V_328 = V_326 ;
V_310 = V_329 ;
goto V_289;
}
#endif
default:
if ( F_30 ( V_240 ) >= V_330 ) {
unsigned V_331 = F_30 ( V_240 ) - V_330 ;
T_4 V_52 , V_51 ;
F_53 ( V_52 , F_48 ( V_240 ) ) ;
F_53 ( V_51 , F_46 ( V_240 ) ) ;
V_313 . V_311 = F_65 ( V_52 , V_51 ,
V_332 [ V_331 & 0x7 ] , V_331 & 0x8 ) ;
V_310 = - 1 ;
if ( ( V_331 & 0x8 )
&&
F_52
( V_299 ) )
V_281 = V_300 | V_301 ;
else
goto V_289;
}
else {
return V_28 ;
}
break;
}
break;
}
case V_325 : {
T_5 V_52 ;
switch ( F_30 ( V_240 ) ) {
case V_107 :
F_50 ( V_52 , F_48 ( V_240 ) ) ;
V_313 . V_280 = F_66 ( V_52 . V_340 ) ;
V_310 = V_283 ;
goto V_289;
case V_104 :
F_50 ( V_52 , F_48 ( V_240 ) ) ;
V_313 . V_279 = F_67 ( V_52 . V_340 ) ;
V_310 = V_303 ;
goto V_289;
default:
return V_28 ;
}
break;
}
#if F_9 ( V_257 )
case V_329 : {
switch ( F_30 ( V_240 ) ) {
case V_107 :
V_313 . V_280 = F_68 ( V_238 -> V_341 [ F_48 ( V_240 ) ] ) ;
V_310 = V_283 ;
goto V_289;
case V_104 :
V_313 . V_279 = F_69 ( V_238 -> V_341 [ F_48 ( V_240 ) ] ) ;
V_310 = V_303 ;
goto V_289;
default:
return V_28 ;
}
break;
}
#endif
default:
return V_28 ;
}
V_238 -> V_163 = ( V_238 -> V_163 & ~ V_302 ) | V_281 ;
if ( ( V_238 -> V_163 >> 5 ) & V_238 -> V_163 & V_267 ) {
return V_268 ;
}
switch ( V_310 ) {
case - 1 : {
#if V_270 >= 4
V_155 = V_271 [ F_47 ( V_240 ) >> 2 ] ;
#else
V_155 = V_272 ;
#endif
if ( V_313 . V_311 )
V_238 -> V_163 |= V_155 ;
else
V_238 -> V_163 &= ~ V_155 ;
break;
}
case V_303 :
F_54 ( V_313 . V_279 , F_47 ( V_240 ) ) ;
break;
case V_283 :
F_51 ( V_313 . V_280 , F_47 ( V_240 ) ) ;
break;
case V_325 :
F_23 ( V_313 . V_311 , F_47 ( V_240 ) ) ;
break;
#if F_9 ( V_257 )
case V_329 :
F_19 ( V_313 . V_312 , F_47 ( V_240 ) ) ;
break;
#endif
default:
return V_28 ;
}
return 0 ;
}
int F_70 ( struct V_157 * V_233 , struct V_237 * V_238 ,
int V_342 , void * T_1 * V_239 )
{
unsigned long V_343 , V_344 ;
struct V_159 V_160 ;
T_7 V_345 [ 4 ] ;
T_7 * V_346 ;
int V_278 = 0 ;
V_343 = V_233 -> V_174 ;
do {
V_344 = V_233 -> V_174 ;
if ( F_71 ( V_344 ) && V_347 ) {
if ( ( F_72 ( V_345 [ 0 ] , ( T_7 T_1 * ) F_73 ( V_233 -> V_174 ) ) ) ||
( F_72 ( V_345 [ 1 ] , ( T_7 T_1 * ) F_73 ( V_233 -> V_174 + 2 ) ) ) ||
( F_72 ( V_345 [ 2 ] , ( T_7 T_1 * ) F_73 ( V_233 -> V_174 + 4 ) ) ) ||
( F_72 ( V_345 [ 3 ] , ( T_7 T_1 * ) F_73 ( V_233 -> V_174 + 6 ) ) ) ) {
F_13 ( V_252 ) ;
return V_253 ;
}
V_346 = V_345 ;
if ( F_74 ( * V_346 ) ) {
V_160 . V_3 = ( * V_346 << 16 ) |
( * V_346 ) ;
V_160 . V_175 = 2 ;
V_346 += 1 ;
} else {
V_160 . V_3 = ( * V_346 << 16 ) |
* ( V_346 + 1 ) ;
V_160 . V_175 = 4 ;
V_346 += 2 ;
}
if ( F_74 ( * V_346 ) ) {
V_160 . V_244 = ( * V_346 << 16 ) |
( * V_346 ) ;
V_160 . V_176 = 2 ;
} else {
V_160 . V_244 = ( * V_346 << 16 ) |
* ( V_346 + 1 ) ;
V_160 . V_176 = 4 ;
}
V_160 . V_243 = 1 ;
} else {
if ( ( F_72 ( V_160 . V_3 ,
( V_1 T_1 * ) V_233 -> V_174 ) ) ||
( F_72 ( V_160 . V_244 ,
( V_1 T_1 * ) ( V_233 -> V_174 + 4 ) ) ) ) {
F_13 ( V_252 ) ;
return V_253 ;
}
V_160 . V_175 = 4 ;
V_160 . V_176 = 4 ;
V_160 . V_243 = 0 ;
}
if ( ( V_160 . V_3 == 0 ) ||
( ( V_160 . V_175 == 2 ) &&
( ( V_160 . V_3 & 0xffff ) == V_277 ) ) )
V_233 -> V_174 += V_160 . V_175 ;
else {
V_327 . V_328 = V_266 [ V_327 . V_328 ] ;
V_278 = F_11 ( V_233 , V_238 , V_160 , V_239 ) ;
V_327 . V_328 = V_263 [ V_327 . V_328 ] ;
}
if ( V_342 )
break;
if ( V_278 )
break;
F_75 () ;
} while ( V_233 -> V_174 > V_344 );
if ( V_278 == V_28 && V_233 -> V_174 != V_343 )
V_278 = 0 ;
return V_278 ;
}
static int F_76 ( void * V_348 , T_2 * V_249 )
{
int V_349 ;
unsigned long V_350 = 0 ;
F_77 (cpu) {
struct V_351 * V_352 ;
T_8 * V_353 ;
V_352 = & F_78 ( V_354 , V_349 ) ;
V_353 = ( void * ) V_352 + ( unsigned long ) V_348 ;
V_350 += F_79 ( V_353 ) ;
}
* V_249 = V_350 ;
return 0 ;
}
static int T_9 F_80 ( void )
{
struct V_355 * V_279 , * V_356 ;
if ( ! V_357 )
return - V_358 ;
V_356 = F_81 ( L_3 , V_357 ) ;
if ( ! V_356 )
return - V_359 ;
#define F_82 ( T_10 ) \
do { \
d = debugfs_create_file(#M , S_IRUGO, dir, \
(void *)offsetof(struct mips_fpu_emulator_stats, M), \
&fops_fpuemu_stat); \
if (!d) \
return -ENOMEM; \
} while (0)
F_82 ( V_247 ) ;
F_82 ( V_250 ) ;
F_82 ( V_255 ) ;
F_82 ( V_314 ) ;
F_82 ( V_282 ) ;
F_82 ( V_252 ) ;
return 0 ;
}
