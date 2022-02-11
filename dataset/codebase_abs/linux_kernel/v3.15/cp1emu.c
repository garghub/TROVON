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
case V_149 :
case V_150 :
if ( V_3 . V_92 . V_7 == V_145 )
V_7 = V_151 ;
else if ( V_3 . V_92 . V_7 == V_146 )
V_7 = V_152 ;
else if ( V_3 . V_92 . V_7 == V_147 )
V_7 = V_153 ;
else if ( V_3 . V_92 . V_7 == V_148 )
V_7 = V_154 ;
else if ( V_3 . V_92 . V_7 == V_149 )
V_7 = V_155 ;
else
V_7 = V_156 ;
V_4 . V_157 . V_9 = V_24 ;
V_4 . V_157 . V_7 = V_7 ;
V_4 . V_157 . V_12 =
V_3 . V_92 . V_12 ;
V_4 . V_157 . V_52 =
V_3 . V_92 . V_52 ;
V_4 . V_157 . V_53 = 0 ;
V_4 . V_157 . V_5 = 0 ;
break;
default:
return V_28 ;
}
break;
case V_158 :
V_4 . V_73 . V_9 = V_24 ;
V_4 . V_73 . V_6 =
V_74 [ V_3 . V_98 . V_6 ] ;
V_4 . V_73 . V_51 = V_3 . V_98 . V_12 ;
V_4 . V_73 . V_52 = V_3 . V_98 . V_52 ;
V_4 . V_73 . V_53 = V_3 . V_98 . V_75 << 2 ;
V_4 . V_73 . V_5 =
V_3 . V_98 . V_159 | V_160 ;
break;
default:
return V_28 ;
}
break;
default:
return V_28 ;
}
* V_2 = V_4 ;
return 0 ;
}
int F_2 ( struct V_161 * V_162 , struct V_163 V_164 ,
unsigned long * V_165 )
{
union V_1 V_3 = (union V_1 ) V_164 . V_3 ;
int V_166 = 0 ;
unsigned int V_167 ;
unsigned int V_168 ;
if ( ! V_169 )
return 0 ;
switch ( V_3 . V_8 . V_9 ) {
case V_170 :
if ( ( V_3 . V_8 . V_171 & V_172 ) ==
V_173 ) {
switch ( V_3 . V_8 . V_171 >>
V_174 ) {
case V_175 :
case V_176 :
case V_177 :
case V_178 :
if ( V_3 . V_8 . V_12 != 0 )
V_162 -> V_162 [ V_3 . V_8 . V_12 ] =
V_162 -> V_179 +
V_164 . V_180 +
V_164 . V_181 ;
* V_165 = V_162 -> V_162 [ V_3 . V_8 . V_13 ] ;
return 1 ;
}
}
break;
case V_20 :
switch ( V_3 . V_8 . V_12 ) {
case V_182 :
case V_183 :
V_162 -> V_162 [ 31 ] = V_162 -> V_179 +
V_164 . V_180 +
V_164 . V_181 ;
case V_184 :
if ( ( long ) V_162 -> V_162 [ V_3 . V_8 . V_13 ] < 0 )
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
( V_3 . V_8 . V_171 << 1 ) ;
else
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
V_164 . V_181 ;
return 1 ;
case V_185 :
case V_186 :
V_162 -> V_162 [ 31 ] = V_162 -> V_179 +
V_164 . V_180 +
V_164 . V_181 ;
case V_187 :
if ( ( long ) V_162 -> V_162 [ V_3 . V_8 . V_13 ] >= 0 )
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
( V_3 . V_8 . V_171 << 1 ) ;
else
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
V_164 . V_181 ;
return 1 ;
case V_188 :
if ( ( long ) V_162 -> V_162 [ V_3 . V_8 . V_13 ] <= 0 )
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
( V_3 . V_8 . V_171 << 1 ) ;
else
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
V_164 . V_181 ;
return 1 ;
case V_189 :
if ( ( long ) V_162 -> V_162 [ V_3 . V_8 . V_13 ] <= 0 )
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
( V_3 . V_8 . V_171 << 1 ) ;
else
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
V_164 . V_181 ;
return 1 ;
case V_190 :
case V_21 :
V_166 = 1 ;
case V_191 :
case V_22 :
F_3 () ;
if ( F_4 () )
asm volatile("cfc1\t%0,$31" : "=r" (fcr31));
else
V_167 = V_192 -> V_193 . V_194 . V_167 ;
F_5 () ;
if ( V_166 )
V_167 = ~ V_167 ;
V_168 = ( V_3 . V_8 . V_13 >> 2 ) ;
V_168 += ( V_168 != 0 ) ;
V_168 += 23 ;
if ( V_167 & ( 1 << V_168 ) )
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
( V_3 . V_8 . V_171 << 1 ) ;
else
* V_165 = V_162 -> V_179 +
V_164 . V_180 + V_164 . V_181 ;
return 1 ;
}
break;
case V_195 :
switch ( V_3 . V_8 . V_12 ) {
case V_196 :
case V_197 :
V_162 -> V_162 [ 31 ] = V_162 -> V_179 +
V_164 . V_180 + V_164 . V_181 ;
case V_198 :
* V_165 = V_162 -> V_162 [ V_3 . V_8 . V_13 ] ;
return 1 ;
}
break;
case V_199 :
if ( ( long ) V_162 -> V_162 [ V_200 [ V_3 . V_201 . V_13 ] ] == 0 )
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
( V_3 . V_201 . V_171 << 1 ) ;
else
* V_165 = V_162 -> V_179 +
V_164 . V_180 + V_164 . V_181 ;
return 1 ;
case V_202 :
if ( ( long ) V_162 -> V_162 [ V_200 [ V_3 . V_201 . V_13 ] ] != 0 )
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
( V_3 . V_201 . V_171 << 1 ) ;
else
* V_165 = V_162 -> V_179 +
V_164 . V_180 + V_164 . V_181 ;
return 1 ;
case V_203 :
* V_165 = V_162 -> V_179 + V_164 . V_180 +
( V_3 . V_204 . V_171 << 1 ) ;
return 1 ;
case V_205 :
if ( V_162 -> V_162 [ V_3 . V_8 . V_13 ] ==
V_162 -> V_162 [ V_3 . V_8 . V_12 ] )
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
( V_3 . V_8 . V_171 << 1 ) ;
else
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
V_164 . V_181 ;
return 1 ;
case V_206 :
if ( V_162 -> V_162 [ V_3 . V_8 . V_13 ] !=
V_162 -> V_162 [ V_3 . V_8 . V_12 ] )
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
( V_3 . V_8 . V_171 << 1 ) ;
else
* V_165 = V_162 -> V_179 +
V_164 . V_180 + V_164 . V_181 ;
return 1 ;
case V_207 :
V_162 -> V_162 [ 31 ] = V_162 -> V_179 +
V_164 . V_180 + V_164 . V_181 ;
* V_165 = V_162 -> V_179 + V_164 . V_180 ;
* V_165 >>= 28 ;
* V_165 <<= 28 ;
* V_165 |= ( V_3 . V_208 . V_209 << 2 ) ;
return 1 ;
case V_210 :
case V_211 :
V_162 -> V_162 [ 31 ] = V_162 -> V_179 +
V_164 . V_180 + V_164 . V_181 ;
case V_212 :
* V_165 = V_162 -> V_179 + V_164 . V_180 ;
* V_165 >>= 27 ;
* V_165 <<= 27 ;
* V_165 |= ( V_3 . V_208 . V_209 << 1 ) ;
F_6 ( * V_165 ) ;
return 1 ;
}
return 0 ;
}
static int F_7 ( struct V_161 * V_162 , struct V_163 V_164 ,
unsigned long * V_165 )
{
union V_1 V_3 = (union V_1 ) V_164 . V_3 ;
unsigned int V_167 ;
unsigned int V_168 = 0 ;
switch ( V_3 . V_213 . V_9 ) {
case V_97 :
switch ( V_3 . V_64 . V_5 ) {
case V_214 :
V_162 -> V_162 [ V_3 . V_64 . V_67 ] =
V_162 -> V_179 + V_164 . V_180 +
V_164 . V_181 ;
case V_215 :
* V_165 = V_162 -> V_162 [ V_3 . V_64 . V_13 ] ;
return 1 ;
}
break;
case V_216 :
switch ( V_3 . V_213 . V_12 ) {
case V_217 :
case V_218 :
V_162 -> V_162 [ 31 ] = V_162 -> V_179 +
V_164 . V_180 +
V_164 . V_181 ;
case V_219 :
case V_220 :
if ( ( long ) V_162 -> V_162 [ V_3 . V_213 . V_13 ] < 0 )
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
( V_3 . V_213 . V_171 << 2 ) ;
else
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
V_164 . V_181 ;
return 1 ;
case V_221 :
case V_222 :
V_162 -> V_162 [ 31 ] = V_162 -> V_179 +
V_164 . V_180 +
V_164 . V_181 ;
case V_223 :
case V_224 :
if ( ( long ) V_162 -> V_162 [ V_3 . V_213 . V_13 ] >= 0 )
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
( V_3 . V_213 . V_171 << 2 ) ;
else
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
V_164 . V_181 ;
return 1 ;
}
break;
case V_225 :
F_6 ( V_168 ) ;
case V_226 :
V_162 -> V_162 [ 31 ] = V_162 -> V_179 +
V_164 . V_180 +
V_164 . V_181 ;
case V_227 :
* V_165 = V_162 -> V_179 + V_164 . V_180 ;
* V_165 >>= 28 ;
* V_165 <<= 28 ;
* V_165 |= ( V_3 . V_208 . V_209 << 2 ) ;
* V_165 ^= V_168 ;
return 1 ;
case V_228 :
case V_229 :
if ( V_162 -> V_162 [ V_3 . V_213 . V_13 ] ==
V_162 -> V_162 [ V_3 . V_213 . V_12 ] )
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
( V_3 . V_213 . V_171 << 2 ) ;
else
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
V_164 . V_181 ;
return 1 ;
case V_230 :
case V_231 :
if ( V_162 -> V_162 [ V_3 . V_213 . V_13 ] !=
V_162 -> V_162 [ V_3 . V_213 . V_12 ] )
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
( V_3 . V_213 . V_171 << 2 ) ;
else
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
V_164 . V_181 ;
return 1 ;
case V_232 :
case V_233 :
if ( ( long ) V_162 -> V_162 [ V_3 . V_213 . V_13 ] <= 0 )
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
( V_3 . V_213 . V_171 << 2 ) ;
else
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
V_164 . V_181 ;
return 1 ;
case V_234 :
case V_235 :
if ( ( long ) V_162 -> V_162 [ V_3 . V_213 . V_13 ] > 0 )
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
( V_3 . V_213 . V_171 << 2 ) ;
else
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
V_164 . V_181 ;
return 1 ;
#ifdef F_8
case V_236 :
if ( ( V_162 -> V_162 [ V_3 . V_213 . V_13 ] & ( 1ull << V_3 . V_213 . V_12 ) ) == 0 )
* V_165 = V_162 -> V_179 + 4 + ( V_3 . V_213 . V_171 << 2 ) ;
else
* V_165 = V_162 -> V_179 + 8 ;
return 1 ;
case V_237 :
if ( ( V_162 -> V_162 [ V_3 . V_213 . V_13 ] & ( 1ull << ( V_3 . V_213 . V_12 + 32 ) ) ) == 0 )
* V_165 = V_162 -> V_179 + 4 + ( V_3 . V_213 . V_171 << 2 ) ;
else
* V_165 = V_162 -> V_179 + 8 ;
return 1 ;
case V_238 :
if ( V_162 -> V_162 [ V_3 . V_213 . V_13 ] & ( 1ull << V_3 . V_213 . V_12 ) )
* V_165 = V_162 -> V_179 + 4 + ( V_3 . V_213 . V_171 << 2 ) ;
else
* V_165 = V_162 -> V_179 + 8 ;
return 1 ;
case V_239 :
if ( V_162 -> V_162 [ V_3 . V_213 . V_13 ] & ( 1ull << ( V_3 . V_213 . V_12 + 32 ) ) )
* V_165 = V_162 -> V_179 + 4 + ( V_3 . V_213 . V_171 << 2 ) ;
else
* V_165 = V_162 -> V_179 + 8 ;
return 1 ;
#endif
case V_240 :
case V_24 :
case V_241 :
case V_48 :
if ( V_3 . V_213 . V_13 == V_26 ) {
F_3 () ;
if ( F_4 () )
asm volatile("cfc1\t%0,$31" : "=r" (fcr31));
else
V_167 = V_192 -> V_193 . V_194 . V_167 ;
F_5 () ;
V_168 = ( V_3 . V_213 . V_12 >> 2 ) ;
V_168 += ( V_168 != 0 ) ;
V_168 += 23 ;
switch ( V_3 . V_213 . V_12 & 3 ) {
case 0 :
case 2 :
if ( ~ V_167 & ( 1 << V_168 ) )
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
( V_3 . V_213 . V_171 << 2 ) ;
else
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
V_164 . V_181 ;
return 1 ;
case 1 :
case 3 :
if ( V_167 & ( 1 << V_168 ) )
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
( V_3 . V_213 . V_171 << 2 ) ;
else
* V_165 = V_162 -> V_179 +
V_164 . V_180 +
V_164 . V_181 ;
return 1 ;
}
}
break;
}
return 0 ;
}
static inline int F_9 ( struct V_161 * V_242 )
{
#if F_10 ( V_243 ) && ! F_10 ( V_244 )
return 1 ;
#elif F_10 ( V_245 ) && ! F_10 ( V_246 )
return 0 ;
#else
return ! F_11 ( V_247 ) ;
#endif
}
static int F_12 ( struct V_161 * V_242 , struct V_248 * V_249 ,
struct V_163 V_164 , void * T_1 * V_250 )
{
V_1 V_251 ;
unsigned long V_165 = V_242 -> V_179 + V_164 . V_180 ;
unsigned int V_159 ;
int V_180 ;
if ( V_242 -> V_252 & V_253 ) {
if ( V_164 . V_254 ) {
if ( ! F_2 ( V_242 , V_164 , & V_165 ) )
V_242 -> V_252 &= ~ V_253 ;
} else {
if ( ! F_7 ( V_242 , V_164 , & V_165 ) )
V_242 -> V_252 &= ~ V_253 ;
}
}
if ( V_242 -> V_252 & V_253 ) {
V_251 = V_164 . V_255 ;
V_180 = V_164 . V_181 ;
} else {
V_251 = V_164 . V_3 ;
V_180 = V_164 . V_180 ;
}
if ( V_164 . V_254 ) {
if ( ( V_180 == 2 ) ||
( F_1 ( (union V_1 * ) & V_251 )
== V_28 ) )
return V_28 ;
}
V_256:
F_13 ( V_257 , 1 , V_242 , 0 ) ;
F_14 ( V_258 ) ;
switch ( F_15 ( V_251 ) ) {
case V_11 : {
T_2 T_1 * V_259 = ( T_2 T_1 * ) ( V_242 -> V_162 [ F_16 ( V_251 ) ] +
F_17 ( V_251 ) ) ;
T_2 V_260 ;
F_14 ( V_261 ) ;
if ( ! F_18 ( V_262 , V_259 , sizeof( T_2 ) ) ) {
F_14 ( V_263 ) ;
* V_250 = V_259 ;
return V_264 ;
}
if ( F_19 ( V_260 , V_259 ) ) {
F_14 ( V_263 ) ;
* V_250 = V_259 ;
return V_265 ;
}
F_20 ( V_260 , F_21 ( V_251 ) ) ;
break;
}
case V_17 : {
T_2 T_1 * V_259 = ( T_2 T_1 * ) ( V_242 -> V_162 [ F_16 ( V_251 ) ] +
F_17 ( V_251 ) ) ;
T_2 V_260 ;
F_14 ( V_266 ) ;
F_22 ( V_260 , F_21 ( V_251 ) ) ;
if ( ! F_18 ( V_267 , V_259 , sizeof( T_2 ) ) ) {
F_14 ( V_263 ) ;
* V_250 = V_259 ;
return V_264 ;
}
if ( F_23 ( V_260 , V_259 ) ) {
F_14 ( V_263 ) ;
* V_250 = V_259 ;
return V_265 ;
}
break;
}
case V_15 : {
T_3 T_1 * V_259 = ( T_3 T_1 * ) ( V_242 -> V_162 [ F_16 ( V_251 ) ] +
F_17 ( V_251 ) ) ;
T_3 V_260 ;
F_14 ( V_261 ) ;
if ( ! F_18 ( V_262 , V_259 , sizeof( T_3 ) ) ) {
F_14 ( V_263 ) ;
* V_250 = V_259 ;
return V_264 ;
}
if ( F_19 ( V_260 , V_259 ) ) {
F_14 ( V_263 ) ;
* V_250 = V_259 ;
return V_265 ;
}
F_24 ( V_260 , F_21 ( V_251 ) ) ;
break;
}
case V_19 : {
T_3 T_1 * V_259 = ( T_3 T_1 * ) ( V_242 -> V_162 [ F_16 ( V_251 ) ] +
F_17 ( V_251 ) ) ;
T_3 V_260 ;
F_14 ( V_266 ) ;
F_25 ( V_260 , F_21 ( V_251 ) ) ;
if ( ! F_18 ( V_267 , V_259 , sizeof( T_3 ) ) ) {
F_14 ( V_263 ) ;
* V_250 = V_259 ;
return V_264 ;
}
if ( F_23 ( V_260 , V_259 ) ) {
F_14 ( V_263 ) ;
* V_250 = V_259 ;
return V_265 ;
}
break;
}
case V_24 :
switch ( F_16 ( V_251 ) ) {
#if F_10 ( V_268 )
case V_269 :
if ( F_21 ( V_251 ) != 0 ) {
F_22 ( V_242 -> V_162 [ F_21 ( V_251 ) ] ,
F_26 ( V_251 ) ) ;
}
break;
case V_270 :
F_20 ( V_242 -> V_162 [ F_21 ( V_251 ) ] , F_26 ( V_251 ) ) ;
break;
#endif
case V_155 :
if ( ! V_271 )
goto V_272;
if ( F_21 ( V_251 ) != 0 ) {
F_27 ( V_242 -> V_162 [ F_21 ( V_251 ) ] ,
F_26 ( V_251 ) ) ;
}
break;
case V_156 :
if ( ! V_271 )
goto V_272;
F_28 ( V_242 -> V_162 [ F_21 ( V_251 ) ] , F_26 ( V_251 ) ) ;
break;
case V_151 :
if ( F_21 ( V_251 ) != 0 ) {
F_25 ( V_242 -> V_162 [ F_21 ( V_251 ) ] ,
F_26 ( V_251 ) ) ;
}
break;
case V_152 :
F_24 ( V_242 -> V_162 [ F_21 ( V_251 ) ] , F_26 ( V_251 ) ) ;
break;
case V_153 : {
T_3 V_273 ;
if ( F_26 ( V_251 ) == V_274 ) {
V_273 = V_249 -> V_167 ;
V_273 = ( V_273 & ~ V_275 ) |
V_276 [ F_29 ( V_273 ) ] ;
#ifdef F_30
F_31 ( L_1 ,
( void * ) ( V_242 -> V_179 ) ,
F_21 ( V_251 ) , V_273 ) ;
#endif
}
else if ( F_26 ( V_251 ) == V_277 )
V_273 = 0 ;
else
V_273 = 0 ;
if ( F_21 ( V_251 ) )
V_242 -> V_162 [ F_21 ( V_251 ) ] = V_273 ;
break;
}
case V_154 : {
T_3 V_273 ;
if ( F_21 ( V_251 ) == 0 )
V_273 = 0 ;
else
V_273 = V_242 -> V_162 [ F_21 ( V_251 ) ] ;
if ( F_26 ( V_251 ) == V_274 ) {
#ifdef F_30
F_31 ( L_2 ,
( void * ) ( V_242 -> V_179 ) ,
F_21 ( V_251 ) , V_273 ) ;
#endif
V_249 -> V_167 = ( V_273 &
~ ( V_278 | V_275 ) ) |
V_279 [ F_29 ( V_273 ) ] ;
}
if ( ( V_249 -> V_167 >> 5 ) & V_249 -> V_167 & V_280 ) {
return V_281 ;
}
break;
}
case V_26 : {
int V_282 = 0 ;
if ( V_242 -> V_252 & V_253 )
return V_28 ;
#if V_283 >= 4
V_159 = V_249 -> V_167 & V_284 [ F_21 ( V_251 ) >> 2 ] ;
#else
V_159 = V_249 -> V_167 & V_285 ;
#endif
switch ( F_21 ( V_251 ) & 3 ) {
case V_286 :
V_282 = 1 ;
case V_287 :
V_159 = ! V_159 ;
break;
case V_288 :
V_282 = 1 ;
case V_289 :
break;
default:
return V_28 ;
}
V_242 -> V_252 |= V_253 ;
if ( V_159 ) {
V_242 -> V_179 += V_164 . V_180 ;
V_165 = F_17 ( V_251 ) ;
V_251 = V_164 . V_255 ;
if ( V_164 . V_254 ) {
V_165 = ( V_242 -> V_179 + ( V_165 << 1 ) ) ;
if ( ( V_164 . V_181 == 2 ) ||
( F_1 ( (union V_1 * ) & V_251 ) == V_28 ) ) {
if ( V_164 . V_181 == 2 )
V_251 = ( V_251 & ( ~ 0xffff ) ) | V_290 ;
return F_32 ( V_242 , V_251 , V_165 ) ;
}
} else
V_165 = ( V_242 -> V_179 + ( V_165 << 2 ) ) ;
switch ( F_15 ( V_251 ) ) {
case V_15 :
case V_19 :
#if ( V_283 >= 2 || F_10 ( V_268 ) )
case V_11 :
case V_17 :
#endif
case V_24 :
#if V_283 >= 4 && V_283 != 32
case V_48 :
#endif
goto V_256;
#if V_283 >= 4
case V_97 :
if ( F_33 ( V_251 ) == V_99 )
goto V_256;
break;
#endif
}
return F_32 ( V_242 , V_251 , V_165 ) ;
}
else {
if ( V_282 ) {
V_242 -> V_179 += V_164 . V_180 ;
V_165 += V_164 . V_180 ;
}
}
break;
}
default:
if ( ! ( F_16 ( V_251 ) & 0x10 ) )
return V_28 ;
{
int V_291 ;
if ( ( V_291 = F_34 ( V_242 , V_249 , V_251 ) ) )
return V_291 ;
}
}
break;
#if V_283 >= 4 && V_283 != 32
case V_48 : {
int V_291 = F_35 ( V_242 , V_249 , V_251 , V_250 ) ;
if ( V_291 )
return V_291 ;
break;
}
#endif
#if V_283 >= 4
case V_97 :
if ( F_33 ( V_251 ) != V_99 )
return V_28 ;
V_159 = V_284 [ F_21 ( V_251 ) >> 2 ] ;
if ( ( ( V_249 -> V_167 & V_159 ) != 0 ) == ( ( F_21 ( V_251 ) & 1 ) != 0 ) )
V_242 -> V_162 [ F_26 ( V_251 ) ] =
V_242 -> V_162 [ F_16 ( V_251 ) ] ;
break;
#endif
default:
V_272:
return V_28 ;
}
V_242 -> V_179 = V_165 ;
V_242 -> V_252 &= ~ V_253 ;
return 0 ;
}
static T_4 F_36 ( T_4 V_292 )
{
return F_37 ( F_38 ( 0 ) , V_292 ) ;
}
static T_4 F_39 ( T_4 V_292 )
{
return F_37 ( F_38 ( 0 ) , F_40 ( V_292 ) ) ;
}
static T_5 F_41 ( T_5 V_293 )
{
return F_42 ( F_43 ( 0 ) , V_293 ) ;
}
static T_5 F_44 ( T_5 V_293 )
{
return F_42 ( F_43 ( 0 ) , F_45 ( V_293 ) ) ;
}
static int F_35 ( struct V_161 * V_242 , struct V_248 * V_249 ,
V_1 V_251 , void * T_1 * V_250 )
{
unsigned V_294 = 0 ;
F_14 ( V_295 ) ;
switch ( F_46 ( V_251 ) ) {
case V_296 : {
T_5 (* F_47) ( T_5 , T_5 , T_5 );
T_5 V_53 , V_49 , V_52 , V_51 ;
T_3 T_1 * V_259 ;
T_3 V_260 ;
switch ( F_33 ( V_251 ) ) {
case V_61 :
V_259 = ( void T_1 * ) ( V_242 -> V_162 [ F_48 ( V_251 ) ] +
V_242 -> V_162 [ F_49 ( V_251 ) ] ) ;
F_14 ( V_261 ) ;
if ( ! F_18 ( V_262 , V_259 , sizeof( T_3 ) ) ) {
F_14 ( V_263 ) ;
* V_250 = V_259 ;
return V_264 ;
}
if ( F_19 ( V_260 , V_259 ) ) {
F_14 ( V_263 ) ;
* V_250 = V_259 ;
return V_265 ;
}
F_24 ( V_260 , F_50 ( V_251 ) ) ;
break;
case V_63 :
V_259 = ( void T_1 * ) ( V_242 -> V_162 [ F_48 ( V_251 ) ] +
V_242 -> V_162 [ F_49 ( V_251 ) ] ) ;
F_14 ( V_266 ) ;
F_25 ( V_260 , F_51 ( V_251 ) ) ;
if ( ! F_18 ( V_267 , V_259 , sizeof( T_3 ) ) ) {
F_14 ( V_263 ) ;
* V_250 = V_259 ;
return V_264 ;
}
if ( F_52 ( V_260 , V_259 ) ) {
F_14 ( V_263 ) ;
* V_250 = V_259 ;
return V_265 ;
}
break;
case V_39 :
F_47 = V_297 ;
goto V_298;
case V_43 :
F_47 = V_299 ;
goto V_298;
case V_41 :
F_47 = V_300 ;
goto V_298;
case V_45 :
F_47 = V_301 ;
goto V_298;
V_298:
F_53 ( V_49 , F_48 ( V_251 ) ) ;
F_53 ( V_52 , F_51 ( V_251 ) ) ;
F_53 ( V_51 , F_49 ( V_251 ) ) ;
V_53 = (* F_47) ( V_49 , V_52 , V_51 ) ;
F_54 ( V_53 , F_50 ( V_251 ) ) ;
V_302:
if ( F_55 ( V_303 ) )
V_294 |= V_304 | V_305 ;
if ( F_55 ( V_306 ) )
V_294 |= V_307 | V_308 ;
if ( F_55 ( V_309 ) )
V_294 |= V_310 | V_311 ;
if ( F_55 ( V_312 ) )
V_294 |= V_313 | V_314 ;
V_249 -> V_167 = ( V_249 -> V_167 & ~ V_315 ) | V_294 ;
if ( ( V_249 -> V_167 >> 5 ) & V_249 -> V_167 & V_280 ) {
return V_281 ;
}
break;
default:
return V_28 ;
}
break;
}
case V_316 : {
T_4 (* F_47) ( T_4 , T_4 , T_4 );
T_4 V_53 , V_49 , V_52 , V_51 ;
T_2 T_1 * V_259 ;
T_2 V_260 ;
switch ( F_33 ( V_251 ) ) {
case V_57 :
V_259 = ( void T_1 * ) ( V_242 -> V_162 [ F_48 ( V_251 ) ] +
V_242 -> V_162 [ F_49 ( V_251 ) ] ) ;
F_14 ( V_261 ) ;
if ( ! F_18 ( V_262 , V_259 , sizeof( T_2 ) ) ) {
F_14 ( V_263 ) ;
* V_250 = V_259 ;
return V_264 ;
}
if ( F_19 ( V_260 , V_259 ) ) {
F_14 ( V_263 ) ;
* V_250 = V_259 ;
return V_265 ;
}
F_20 ( V_260 , F_50 ( V_251 ) ) ;
break;
case V_59 :
V_259 = ( void T_1 * ) ( V_242 -> V_162 [ F_48 ( V_251 ) ] +
V_242 -> V_162 [ F_49 ( V_251 ) ] ) ;
F_14 ( V_266 ) ;
F_22 ( V_260 , F_51 ( V_251 ) ) ;
if ( ! F_18 ( V_267 , V_259 , sizeof( T_2 ) ) ) {
F_14 ( V_263 ) ;
* V_250 = V_259 ;
return V_264 ;
}
if ( F_23 ( V_260 , V_259 ) ) {
F_14 ( V_263 ) ;
* V_250 = V_259 ;
return V_265 ;
}
break;
case V_40 :
F_47 = V_317 ;
goto V_318;
case V_44 :
F_47 = V_319 ;
goto V_318;
case V_42 :
F_47 = V_320 ;
goto V_318;
case V_46 :
F_47 = V_321 ;
goto V_318;
V_318:
F_56 ( V_49 , F_48 ( V_251 ) ) ;
F_56 ( V_52 , F_51 ( V_251 ) ) ;
F_56 ( V_51 , F_49 ( V_251 ) ) ;
V_53 = (* F_47) ( V_49 , V_52 , V_51 ) ;
F_57 ( V_53 , F_50 ( V_251 ) ) ;
goto V_302;
default:
return V_28 ;
}
break;
}
case 0x3 :
if ( F_33 ( V_251 ) != V_322 )
return V_28 ;
break;
default:
return V_28 ;
}
return 0 ;
}
static int F_34 ( struct V_161 * V_242 , struct V_248 * V_249 ,
V_1 V_251 )
{
int V_323 ;
unsigned V_294 = 0 ;
unsigned V_159 ;
union {
T_4 V_292 ;
T_5 V_293 ;
int V_324 ;
#ifdef V_268
T_6 V_325 ;
#endif
} V_326 ;
F_14 ( V_327 ) ;
switch ( V_323 = ( F_58 ( V_251 ) & 0xf ) ) {
case V_296 : {
union {
T_5 (* F_59) ( T_5 , T_5 );
T_5 (* F_60) ( T_5 );
} F_47 ;
switch ( F_33 ( V_251 ) ) {
case V_79 :
F_47 . F_59 = V_328 ;
goto V_329;
case V_81 :
F_47 . F_59 = V_330 ;
goto V_329;
case V_83 :
F_47 . F_59 = V_331 ;
goto V_329;
case V_85 :
F_47 . F_59 = F_42 ;
goto V_329;
#if V_283 >= 2 || F_10 ( V_268 )
case V_143 :
F_47 . F_60 = F_45 ;
goto V_332;
#endif
#if V_283 >= 4 && V_283 != 32
case V_142 :
F_47 . F_60 = F_44 ;
goto V_332;
case V_144 :
F_47 . F_60 = F_41 ;
goto V_332;
#endif
#if V_283 >= 4
case V_76 :
V_159 = V_284 [ F_49 ( V_251 ) >> 2 ] ;
if ( ( ( V_249 -> V_167 & V_159 ) != 0 ) !=
( ( F_49 ( V_251 ) & 1 ) != 0 ) )
return 0 ;
F_53 ( V_326 . V_293 , F_51 ( V_251 ) ) ;
break;
case V_90 :
if ( V_242 -> V_162 [ F_49 ( V_251 ) ] != 0 )
return 0 ;
F_53 ( V_326 . V_293 , F_51 ( V_251 ) ) ;
break;
case V_88 :
if ( V_242 -> V_162 [ F_49 ( V_251 ) ] == 0 )
return 0 ;
F_53 ( V_326 . V_293 , F_51 ( V_251 ) ) ;
break;
#endif
case V_116 :
F_47 . F_60 = V_333 ;
goto V_332;
case V_117 :
F_47 . F_60 = V_334 ;
goto V_332;
case V_115 :
F_53 ( V_326 . V_293 , F_51 ( V_251 ) ) ;
goto V_302;
V_329:
{
T_5 V_52 , V_51 ;
F_53 ( V_52 , F_51 ( V_251 ) ) ;
F_53 ( V_51 , F_49 ( V_251 ) ) ;
V_326 . V_293 = (* F_47 . F_59 ) ( V_52 , V_51 ) ;
goto V_302;
}
V_332:
{
T_5 V_52 ;
F_53 ( V_52 , F_51 ( V_251 ) ) ;
V_326 . V_293 = (* F_47 . F_60 ) ( V_52 ) ;
goto V_302;
}
V_302:
if ( F_55 ( V_303 ) )
V_294 |= V_304 | V_305 ;
if ( F_55 ( V_306 ) )
V_294 |= V_307 | V_308 ;
if ( F_55 ( V_309 ) )
V_294 |= V_310 | V_311 ;
if ( F_55 ( V_335 ) )
V_294 |= V_336 | V_337 ;
if ( F_55 ( V_312 ) )
V_294 |= V_313 | V_314 ;
break;
case V_107 :
return V_28 ;
case V_104 : {
T_5 V_52 ;
F_53 ( V_52 , F_51 ( V_251 ) ) ;
V_326 . V_292 = F_61 ( V_52 ) ;
V_323 = V_316 ;
goto V_302;
}
case V_137 : {
T_5 V_52 ;
F_53 ( V_52 , F_51 ( V_251 ) ) ;
V_326 . V_324 = F_62 ( V_52 ) ;
V_323 = V_338 ;
goto V_302;
}
#if V_283 >= 2 || F_10 ( V_268 )
case V_135 :
case V_133 :
case V_131 :
case V_129 : {
unsigned int V_339 = V_340 . V_341 ;
T_5 V_52 ;
F_53 ( V_52 , F_51 ( V_251 ) ) ;
V_340 . V_341 = V_279 [ F_29 ( F_33 ( V_251 ) ) ] ;
V_326 . V_324 = F_62 ( V_52 ) ;
V_340 . V_341 = V_339 ;
V_323 = V_338 ;
goto V_302;
}
#endif
#if F_10 ( V_268 )
case V_136 : {
T_5 V_52 ;
F_53 ( V_52 , F_51 ( V_251 ) ) ;
V_326 . V_325 = F_63 ( V_52 ) ;
V_323 = V_342 ;
goto V_302;
}
case V_134 :
case V_132 :
case V_130 :
case V_128 : {
unsigned int V_339 = V_340 . V_341 ;
T_5 V_52 ;
F_53 ( V_52 , F_51 ( V_251 ) ) ;
V_340 . V_341 = V_279 [ F_29 ( F_33 ( V_251 ) ) ] ;
V_326 . V_325 = F_63 ( V_52 ) ;
V_340 . V_341 = V_339 ;
V_323 = V_342 ;
goto V_302;
}
#endif
default:
if ( F_33 ( V_251 ) >= V_343 ) {
unsigned V_344 = F_33 ( V_251 ) - V_343 ;
T_5 V_52 , V_51 ;
F_53 ( V_52 , F_51 ( V_251 ) ) ;
F_53 ( V_51 , F_49 ( V_251 ) ) ;
V_326 . V_324 = F_64 ( V_52 , V_51 ,
V_345 [ V_344 & 0x7 ] , V_344 & 0x8 ) ;
V_323 = - 1 ;
if ( ( V_344 & 0x8 ) && F_55
( V_312 ) )
V_294 = V_313 | V_314 ;
else
goto V_302;
}
else {
return V_28 ;
}
break;
}
break;
}
case V_316 : {
union {
T_4 (* F_59) ( T_4 , T_4 );
T_4 (* F_60) ( T_4 );
} F_47 ;
switch ( F_33 ( V_251 ) ) {
case V_79 :
F_47 . F_59 = V_346 ;
goto V_347;
case V_81 :
F_47 . F_59 = V_348 ;
goto V_347;
case V_83 :
F_47 . F_59 = V_349 ;
goto V_347;
case V_85 :
F_47 . F_59 = F_37 ;
goto V_347;
#if V_283 >= 2 || F_10 ( V_268 )
case V_143 :
F_47 . F_60 = F_40 ;
goto V_350;
#endif
#if V_283 >= 4 && V_283 != 32
case V_142 :
F_47 . F_60 = F_39 ;
goto V_350;
case V_144 :
F_47 . F_60 = F_36 ;
goto V_350;
#endif
#if V_283 >= 4
case V_76 :
V_159 = V_284 [ F_49 ( V_251 ) >> 2 ] ;
if ( ( ( V_249 -> V_167 & V_159 ) != 0 ) !=
( ( F_49 ( V_251 ) & 1 ) != 0 ) )
return 0 ;
F_56 ( V_326 . V_292 , F_51 ( V_251 ) ) ;
break;
case V_90 :
if ( V_242 -> V_162 [ F_49 ( V_251 ) ] != 0 )
return 0 ;
F_56 ( V_326 . V_292 , F_51 ( V_251 ) ) ;
break;
case V_88 :
if ( V_242 -> V_162 [ F_49 ( V_251 ) ] == 0 )
return 0 ;
F_56 ( V_326 . V_292 , F_51 ( V_251 ) ) ;
break;
#endif
case V_116 :
F_47 . F_60 = V_351 ;
goto V_350;
case V_117 :
F_47 . F_60 = V_352 ;
goto V_350;
case V_115 :
F_56 ( V_326 . V_292 , F_51 ( V_251 ) ) ;
goto V_302;
V_347: {
T_4 V_52 , V_51 ;
F_56 ( V_52 , F_51 ( V_251 ) ) ;
F_56 ( V_51 , F_49 ( V_251 ) ) ;
V_326 . V_292 = (* F_47 . F_59 ) ( V_52 , V_51 ) ;
goto V_302;
}
V_350: {
T_4 V_52 ;
F_56 ( V_52 , F_51 ( V_251 ) ) ;
V_326 . V_292 = (* F_47 . F_60 ) ( V_52 ) ;
goto V_302;
}
case V_107 : {
T_4 V_52 ;
F_56 ( V_52 , F_51 ( V_251 ) ) ;
V_326 . V_293 = F_65 ( V_52 ) ;
V_323 = V_296 ;
goto V_302;
}
case V_104 :
return V_28 ;
case V_137 : {
T_4 V_52 ;
F_56 ( V_52 , F_51 ( V_251 ) ) ;
V_326 . V_324 = F_66 ( V_52 ) ;
V_323 = V_338 ;
goto V_302;
}
#if V_283 >= 2 || F_10 ( V_268 )
case V_135 :
case V_133 :
case V_131 :
case V_129 : {
unsigned int V_339 = V_340 . V_341 ;
T_4 V_52 ;
F_56 ( V_52 , F_51 ( V_251 ) ) ;
V_340 . V_341 = V_279 [ F_29 ( F_33 ( V_251 ) ) ] ;
V_326 . V_324 = F_66 ( V_52 ) ;
V_340 . V_341 = V_339 ;
V_323 = V_338 ;
goto V_302;
}
#endif
#if F_10 ( V_268 )
case V_136 : {
T_4 V_52 ;
F_56 ( V_52 , F_51 ( V_251 ) ) ;
V_326 . V_325 = F_67 ( V_52 ) ;
V_323 = V_342 ;
goto V_302;
}
case V_134 :
case V_132 :
case V_130 :
case V_128 : {
unsigned int V_339 = V_340 . V_341 ;
T_4 V_52 ;
F_56 ( V_52 , F_51 ( V_251 ) ) ;
V_340 . V_341 = V_279 [ F_29 ( F_33 ( V_251 ) ) ] ;
V_326 . V_325 = F_67 ( V_52 ) ;
V_340 . V_341 = V_339 ;
V_323 = V_342 ;
goto V_302;
}
#endif
default:
if ( F_33 ( V_251 ) >= V_343 ) {
unsigned V_344 = F_33 ( V_251 ) - V_343 ;
T_4 V_52 , V_51 ;
F_56 ( V_52 , F_51 ( V_251 ) ) ;
F_56 ( V_51 , F_49 ( V_251 ) ) ;
V_326 . V_324 = F_68 ( V_52 , V_51 ,
V_345 [ V_344 & 0x7 ] , V_344 & 0x8 ) ;
V_323 = - 1 ;
if ( ( V_344 & 0x8 )
&&
F_55
( V_312 ) )
V_294 = V_313 | V_314 ;
else
goto V_302;
}
else {
return V_28 ;
}
break;
}
break;
}
case V_338 : {
T_5 V_52 ;
switch ( F_33 ( V_251 ) ) {
case V_107 :
F_53 ( V_52 , F_51 ( V_251 ) ) ;
V_326 . V_293 = F_69 ( V_52 . V_353 ) ;
V_323 = V_296 ;
goto V_302;
case V_104 :
F_53 ( V_52 , F_51 ( V_251 ) ) ;
V_326 . V_292 = F_70 ( V_52 . V_353 ) ;
V_323 = V_316 ;
goto V_302;
default:
return V_28 ;
}
break;
}
#if F_10 ( V_268 )
case V_342 : {
T_2 V_353 ;
F_22 ( V_353 , F_51 ( V_251 ) ) ;
switch ( F_33 ( V_251 ) ) {
case V_107 :
V_326 . V_293 = F_71 ( V_353 ) ;
V_323 = V_296 ;
goto V_302;
case V_104 :
V_326 . V_292 = F_72 ( V_353 ) ;
V_323 = V_316 ;
goto V_302;
default:
return V_28 ;
}
break;
}
#endif
default:
return V_28 ;
}
V_249 -> V_167 = ( V_249 -> V_167 & ~ V_315 ) | V_294 ;
if ( ( V_249 -> V_167 >> 5 ) & V_249 -> V_167 & V_280 ) {
return V_281 ;
}
switch ( V_323 ) {
case - 1 : {
#if V_283 >= 4
V_159 = V_284 [ F_50 ( V_251 ) >> 2 ] ;
#else
V_159 = V_285 ;
#endif
if ( V_326 . V_324 )
V_249 -> V_167 |= V_159 ;
else
V_249 -> V_167 &= ~ V_159 ;
break;
}
case V_316 :
F_57 ( V_326 . V_292 , F_50 ( V_251 ) ) ;
break;
case V_296 :
F_54 ( V_326 . V_293 , F_50 ( V_251 ) ) ;
break;
case V_338 :
F_24 ( V_326 . V_324 , F_50 ( V_251 ) ) ;
break;
#if F_10 ( V_268 )
case V_342 :
F_20 ( V_326 . V_325 , F_50 ( V_251 ) ) ;
break;
#endif
default:
return V_28 ;
}
return 0 ;
}
int F_73 ( struct V_161 * V_242 , struct V_248 * V_249 ,
int V_354 , void * T_1 * V_250 )
{
unsigned long V_355 , V_356 ;
struct V_163 V_164 ;
T_7 V_357 [ 4 ] ;
T_7 * V_358 ;
int V_291 = 0 ;
V_355 = V_242 -> V_179 ;
do {
V_356 = V_242 -> V_179 ;
if ( F_74 ( V_356 ) && V_169 ) {
if ( ( F_75 ( V_357 [ 0 ] , ( T_7 T_1 * ) F_76 ( V_242 -> V_179 ) ) ) ||
( F_75 ( V_357 [ 1 ] , ( T_7 T_1 * ) F_76 ( V_242 -> V_179 + 2 ) ) ) ||
( F_75 ( V_357 [ 2 ] , ( T_7 T_1 * ) F_76 ( V_242 -> V_179 + 4 ) ) ) ||
( F_75 ( V_357 [ 3 ] , ( T_7 T_1 * ) F_76 ( V_242 -> V_179 + 6 ) ) ) ) {
F_14 ( V_263 ) ;
return V_264 ;
}
V_358 = V_357 ;
if ( F_77 ( * V_358 ) ) {
V_164 . V_3 = ( * V_358 << 16 ) |
( * V_358 ) ;
V_164 . V_180 = 2 ;
V_358 += 1 ;
} else {
V_164 . V_3 = ( * V_358 << 16 ) |
* ( V_358 + 1 ) ;
V_164 . V_180 = 4 ;
V_358 += 2 ;
}
if ( F_77 ( * V_358 ) ) {
V_164 . V_255 = ( * V_358 << 16 ) |
( * V_358 ) ;
V_164 . V_181 = 2 ;
} else {
V_164 . V_255 = ( * V_358 << 16 ) |
* ( V_358 + 1 ) ;
V_164 . V_181 = 4 ;
}
V_164 . V_254 = 1 ;
} else {
if ( ( F_75 ( V_164 . V_3 ,
( V_1 T_1 * ) V_242 -> V_179 ) ) ||
( F_75 ( V_164 . V_255 ,
( V_1 T_1 * ) ( V_242 -> V_179 + 4 ) ) ) ) {
F_14 ( V_263 ) ;
return V_264 ;
}
V_164 . V_180 = 4 ;
V_164 . V_181 = 4 ;
V_164 . V_254 = 0 ;
}
if ( ( V_164 . V_3 == 0 ) ||
( ( V_164 . V_180 == 2 ) &&
( ( V_164 . V_3 & 0xffff ) == V_290 ) ) )
V_242 -> V_179 += V_164 . V_180 ;
else {
V_340 . V_341 = V_279 [ V_340 . V_341 ] ;
V_291 = F_12 ( V_242 , V_249 , V_164 , V_250 ) ;
V_340 . V_341 = V_276 [ V_340 . V_341 ] ;
}
if ( V_354 )
break;
if ( V_291 )
break;
F_78 () ;
} while ( V_242 -> V_179 > V_356 );
if ( V_291 == V_28 && V_242 -> V_179 != V_355 )
V_291 = 0 ;
return V_291 ;
}
static int F_79 ( void * V_359 , T_2 * V_260 )
{
int V_360 ;
unsigned long V_361 = 0 ;
F_80 (cpu) {
struct V_362 * V_363 ;
T_8 * V_364 ;
V_363 = & F_81 ( V_365 , V_360 ) ;
V_364 = ( void * ) V_363 + ( unsigned long ) V_359 ;
V_361 += F_82 ( V_364 ) ;
}
* V_260 = V_361 ;
return 0 ;
}
static int T_9 F_83 ( void )
{
struct V_366 * V_292 , * V_367 ;
if ( ! V_368 )
return - V_369 ;
V_367 = F_84 ( L_3 , V_368 ) ;
if ( ! V_367 )
return - V_370 ;
#define F_85 ( T_10 ) \
do { \
d = debugfs_create_file(#M , S_IRUGO, dir, \
(void *)offsetof(struct mips_fpu_emulator_stats, M), \
&fops_fpuemu_stat); \
if (!d) \
return -ENOMEM; \
} while (0)
F_85 ( V_258 ) ;
F_85 ( V_261 ) ;
F_85 ( V_266 ) ;
F_85 ( V_327 ) ;
F_85 ( V_295 ) ;
F_85 ( V_263 ) ;
return 0 ;
}
