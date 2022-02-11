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
static int F_2 ( struct V_161 * V_162 , struct V_163 V_164 ,
unsigned long * V_165 )
{
union V_1 V_3 = (union V_1 ) V_164 . V_3 ;
unsigned int V_166 ;
unsigned int V_167 = 0 ;
switch ( V_3 . V_168 . V_9 ) {
case V_97 :
switch ( V_3 . V_64 . V_5 ) {
case V_169 :
V_162 -> V_162 [ V_3 . V_64 . V_67 ] =
V_162 -> V_170 + V_164 . V_171 +
V_164 . V_172 ;
case V_173 :
* V_165 = V_162 -> V_162 [ V_3 . V_64 . V_13 ] ;
return 1 ;
}
break;
case V_174 :
switch ( V_3 . V_168 . V_12 ) {
case V_175 :
case V_176 :
V_162 -> V_162 [ 31 ] = V_162 -> V_170 +
V_164 . V_171 +
V_164 . V_172 ;
case V_177 :
case V_178 :
if ( ( long ) V_162 -> V_162 [ V_3 . V_168 . V_13 ] < 0 )
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
( V_3 . V_168 . V_179 << 2 ) ;
else
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
V_164 . V_172 ;
return 1 ;
case V_180 :
case V_181 :
V_162 -> V_162 [ 31 ] = V_162 -> V_170 +
V_164 . V_171 +
V_164 . V_172 ;
case V_182 :
case V_183 :
if ( ( long ) V_162 -> V_162 [ V_3 . V_168 . V_13 ] >= 0 )
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
( V_3 . V_168 . V_179 << 2 ) ;
else
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
V_164 . V_172 ;
return 1 ;
}
break;
case V_184 :
F_3 ( V_167 ) ;
case V_185 :
V_162 -> V_162 [ 31 ] = V_162 -> V_170 +
V_164 . V_171 +
V_164 . V_172 ;
case V_186 :
* V_165 = V_162 -> V_170 + V_164 . V_171 ;
* V_165 >>= 28 ;
* V_165 <<= 28 ;
* V_165 |= ( V_3 . V_187 . V_188 << 2 ) ;
* V_165 ^= V_167 ;
return 1 ;
case V_189 :
case V_190 :
if ( V_162 -> V_162 [ V_3 . V_168 . V_13 ] ==
V_162 -> V_162 [ V_3 . V_168 . V_12 ] )
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
( V_3 . V_168 . V_179 << 2 ) ;
else
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
V_164 . V_172 ;
return 1 ;
case V_191 :
case V_192 :
if ( V_162 -> V_162 [ V_3 . V_168 . V_13 ] !=
V_162 -> V_162 [ V_3 . V_168 . V_12 ] )
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
( V_3 . V_168 . V_179 << 2 ) ;
else
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
V_164 . V_172 ;
return 1 ;
case V_193 :
case V_194 :
if ( ( long ) V_162 -> V_162 [ V_3 . V_168 . V_13 ] <= 0 )
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
( V_3 . V_168 . V_179 << 2 ) ;
else
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
V_164 . V_172 ;
return 1 ;
case V_195 :
case V_196 :
if ( ( long ) V_162 -> V_162 [ V_3 . V_168 . V_13 ] > 0 )
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
( V_3 . V_168 . V_179 << 2 ) ;
else
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
V_164 . V_172 ;
return 1 ;
#ifdef F_4
case V_197 :
if ( ( V_162 -> V_162 [ V_3 . V_168 . V_13 ] & ( 1ull << V_3 . V_168 . V_12 ) ) == 0 )
* V_165 = V_162 -> V_170 + 4 + ( V_3 . V_168 . V_179 << 2 ) ;
else
* V_165 = V_162 -> V_170 + 8 ;
return 1 ;
case V_198 :
if ( ( V_162 -> V_162 [ V_3 . V_168 . V_13 ] & ( 1ull << ( V_3 . V_168 . V_12 + 32 ) ) ) == 0 )
* V_165 = V_162 -> V_170 + 4 + ( V_3 . V_168 . V_179 << 2 ) ;
else
* V_165 = V_162 -> V_170 + 8 ;
return 1 ;
case V_199 :
if ( V_162 -> V_162 [ V_3 . V_168 . V_13 ] & ( 1ull << V_3 . V_168 . V_12 ) )
* V_165 = V_162 -> V_170 + 4 + ( V_3 . V_168 . V_179 << 2 ) ;
else
* V_165 = V_162 -> V_170 + 8 ;
return 1 ;
case V_200 :
if ( V_162 -> V_162 [ V_3 . V_168 . V_13 ] & ( 1ull << ( V_3 . V_168 . V_12 + 32 ) ) )
* V_165 = V_162 -> V_170 + 4 + ( V_3 . V_168 . V_179 << 2 ) ;
else
* V_165 = V_162 -> V_170 + 8 ;
return 1 ;
#endif
case V_201 :
case V_24 :
case V_202 :
case V_48 :
if ( V_3 . V_168 . V_13 == V_26 ) {
F_5 () ;
if ( F_6 () )
V_166 = F_7 ( V_203 ) ;
else
V_166 = V_204 -> V_205 . V_206 . V_166 ;
F_8 () ;
V_167 = ( V_3 . V_168 . V_12 >> 2 ) ;
V_167 += ( V_167 != 0 ) ;
V_167 += 23 ;
switch ( V_3 . V_168 . V_12 & 3 ) {
case 0 :
case 2 :
if ( ~ V_166 & ( 1 << V_167 ) )
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
( V_3 . V_168 . V_179 << 2 ) ;
else
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
V_164 . V_172 ;
return 1 ;
case 1 :
case 3 :
if ( V_166 & ( 1 << V_167 ) )
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
( V_3 . V_168 . V_179 << 2 ) ;
else
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
V_164 . V_172 ;
return 1 ;
}
}
break;
}
return 0 ;
}
static inline int F_9 ( struct V_161 * V_207 )
{
if ( F_10 ( V_208 ) && ! F_10 ( V_209 ) )
return 1 ;
else if ( F_10 ( V_210 ) &&
! F_10 ( V_211 ) )
return 0 ;
return ! F_11 ( V_212 ) ;
}
static int F_12 ( struct V_161 * V_207 , struct V_213 * V_214 ,
struct V_163 V_164 , void * T_1 * V_215 )
{
unsigned long V_165 = V_207 -> V_170 + V_164 . V_171 ;
unsigned int V_159 , V_216 ;
V_1 V_217 ;
int V_218 , V_171 ;
T_2 T_1 * V_219 ;
T_3 T_1 * V_220 ;
T_2 V_221 ;
T_2 V_222 ;
T_3 V_223 ;
int V_224 ;
if ( ! V_225 && V_164 . V_226 )
F_13 () ;
if ( F_14 ( V_207 ) ) {
if ( V_164 . V_226 ) {
if ( ! F_15 ( V_207 , V_164 , & V_165 ) )
F_16 ( V_207 ) ;
} else {
if ( ! F_2 ( V_207 , V_164 , & V_165 ) )
F_16 ( V_207 ) ;
}
}
if ( F_14 ( V_207 ) ) {
V_217 = V_164 . V_227 ;
V_171 = V_164 . V_172 ;
} else {
V_217 = V_164 . V_3 ;
V_171 = V_164 . V_171 ;
}
if ( V_164 . V_226 ) {
if ( ( V_171 == 2 ) ||
( F_1 ( (union V_1 * ) & V_217 )
== V_28 ) )
return V_28 ;
}
V_228:
F_17 ( V_229 , 1 , V_207 , 0 ) ;
F_18 ( V_230 ) ;
switch ( F_19 ( V_217 ) ) {
case V_11 :
V_220 = ( T_3 T_1 * ) ( V_207 -> V_162 [ F_20 ( V_217 ) ] +
F_21 ( V_217 ) ) ;
F_18 ( V_231 ) ;
if ( ! F_22 ( V_232 , V_220 , sizeof( T_3 ) ) ) {
F_18 ( V_233 ) ;
* V_215 = V_220 ;
return V_234 ;
}
if ( F_23 ( V_223 , V_220 ) ) {
F_18 ( V_233 ) ;
* V_215 = V_220 ;
return V_235 ;
}
F_24 ( V_223 , F_25 ( V_217 ) ) ;
break;
case V_17 :
V_220 = ( T_3 T_1 * ) ( V_207 -> V_162 [ F_20 ( V_217 ) ] +
F_21 ( V_217 ) ) ;
F_18 ( V_236 ) ;
F_26 ( V_223 , F_25 ( V_217 ) ) ;
if ( ! F_22 ( V_237 , V_220 , sizeof( T_3 ) ) ) {
F_18 ( V_233 ) ;
* V_215 = V_220 ;
return V_234 ;
}
if ( F_27 ( V_223 , V_220 ) ) {
F_18 ( V_233 ) ;
* V_215 = V_220 ;
return V_235 ;
}
break;
case V_15 :
V_219 = ( T_2 T_1 * ) ( V_207 -> V_162 [ F_20 ( V_217 ) ] +
F_21 ( V_217 ) ) ;
F_18 ( V_231 ) ;
if ( ! F_22 ( V_232 , V_219 , sizeof( T_2 ) ) ) {
F_18 ( V_233 ) ;
* V_215 = V_219 ;
return V_234 ;
}
if ( F_23 ( V_222 , V_219 ) ) {
F_18 ( V_233 ) ;
* V_215 = V_219 ;
return V_235 ;
}
F_28 ( V_222 , F_25 ( V_217 ) ) ;
break;
case V_19 :
V_219 = ( T_2 T_1 * ) ( V_207 -> V_162 [ F_20 ( V_217 ) ] +
F_21 ( V_217 ) ) ;
F_18 ( V_236 ) ;
F_29 ( V_222 , F_25 ( V_217 ) ) ;
if ( ! F_22 ( V_237 , V_219 , sizeof( T_2 ) ) ) {
F_18 ( V_233 ) ;
* V_215 = V_219 ;
return V_234 ;
}
if ( F_27 ( V_222 , V_219 ) ) {
F_18 ( V_233 ) ;
* V_215 = V_219 ;
return V_235 ;
}
break;
case V_24 :
switch ( F_20 ( V_217 ) ) {
case V_238 :
if ( ! V_239 && ! V_240 )
return V_28 ;
if ( F_25 ( V_217 ) != 0 ) {
F_26 ( V_207 -> V_162 [ F_25 ( V_217 ) ] ,
F_30 ( V_217 ) ) ;
}
break;
case V_241 :
if ( ! V_239 && ! V_240 )
return V_28 ;
F_24 ( V_207 -> V_162 [ F_25 ( V_217 ) ] , F_30 ( V_217 ) ) ;
break;
case V_155 :
if ( ! V_242 )
goto V_243;
if ( F_25 ( V_217 ) != 0 ) {
F_31 ( V_207 -> V_162 [ F_25 ( V_217 ) ] ,
F_30 ( V_217 ) ) ;
}
break;
case V_156 :
if ( ! V_242 )
goto V_243;
F_32 ( V_207 -> V_162 [ F_25 ( V_217 ) ] , F_30 ( V_217 ) ) ;
break;
case V_151 :
if ( F_25 ( V_217 ) != 0 ) {
F_29 ( V_207 -> V_162 [ F_25 ( V_217 ) ] ,
F_30 ( V_217 ) ) ;
}
break;
case V_152 :
F_28 ( V_207 -> V_162 [ F_25 ( V_217 ) ] , F_30 ( V_217 ) ) ;
break;
case V_153 :
if ( F_30 ( V_217 ) == V_244 ) {
V_221 = V_214 -> V_166 ;
V_221 = ( V_221 & ~ V_245 ) | F_33 ( V_221 ) ;
F_34 ( L_1 ,
( void * ) ( V_207 -> V_170 ) ,
F_25 ( V_217 ) , V_221 ) ;
}
else if ( F_30 ( V_217 ) == V_246 )
V_221 = 0 ;
else
V_221 = 0 ;
if ( F_25 ( V_217 ) )
V_207 -> V_162 [ F_25 ( V_217 ) ] = V_221 ;
break;
case V_154 :
if ( F_25 ( V_217 ) == 0 )
V_221 = 0 ;
else
V_221 = V_207 -> V_162 [ F_25 ( V_217 ) ] ;
if ( F_30 ( V_217 ) == V_244 ) {
F_34 ( L_2 ,
( void * ) ( V_207 -> V_170 ) ,
F_25 ( V_217 ) , V_221 ) ;
V_214 -> V_166 = ( V_221 & ~ ( V_247 | V_245 ) ) |
F_33 ( V_221 ) ;
}
if ( ( V_214 -> V_166 >> 5 ) & V_214 -> V_166 & V_248 ) {
return V_249 ;
}
break;
case V_26 :
if ( F_14 ( V_207 ) )
return V_28 ;
if ( V_250 )
V_216 = V_251 [ F_25 ( V_217 ) >> 2 ] ;
else
V_216 = V_252 ;
V_159 = V_214 -> V_166 & V_216 ;
V_218 = 0 ;
switch ( F_25 ( V_217 ) & 3 ) {
case V_253 :
V_218 = 1 ;
case V_254 :
V_159 = ! V_159 ;
break;
case V_255 :
V_218 = 1 ;
case V_256 :
break;
default:
return V_28 ;
}
F_35 ( V_207 ) ;
if ( V_159 ) {
V_207 -> V_170 += V_164 . V_171 ;
V_165 = F_21 ( V_217 ) ;
V_217 = V_164 . V_227 ;
if ( V_164 . V_226 ) {
V_165 = ( V_207 -> V_170 + ( V_165 << 1 ) ) ;
if ( ( V_164 . V_172 == 2 ) ||
( F_1 ( (union V_1 * ) & V_217 ) == V_28 ) ) {
if ( V_164 . V_172 == 2 )
V_217 = ( V_217 & ( ~ 0xffff ) ) | V_257 ;
return F_36 ( V_207 , V_217 , V_165 ) ;
}
} else
V_165 = ( V_207 -> V_170 + ( V_165 << 2 ) ) ;
switch ( F_19 ( V_217 ) ) {
case V_15 :
goto V_228;
case V_19 :
goto V_228;
case V_11 :
case V_17 :
if ( V_258 ||
V_240 )
goto V_228;
return V_28 ;
goto V_228;
case V_24 :
goto V_228;
case V_48 :
if ( V_259 || V_240 || V_260 )
goto V_228;
return V_28 ;
case V_97 :
if ( ! V_250 )
return V_28 ;
if ( F_37 ( V_217 ) == V_99 )
goto V_228;
break;
}
return F_36 ( V_207 , V_217 , V_165 ) ;
} else if ( V_218 ) {
V_207 -> V_170 += V_164 . V_171 ;
V_165 += V_164 . V_171 ;
}
break;
default:
if ( ! ( F_20 ( V_217 ) & 0x10 ) )
return V_28 ;
if ( ( V_224 = F_38 ( V_207 , V_214 , V_217 ) ) )
return V_224 ;
}
break;
case V_48 :
if ( ! V_259 && ! V_240 && ! V_260 )
return V_28 ;
V_224 = F_39 ( V_207 , V_214 , V_217 , V_215 ) ;
if ( V_224 )
return V_224 ;
break;
case V_97 :
if ( ! V_250 )
return V_28 ;
if ( F_37 ( V_217 ) != V_99 )
return V_28 ;
V_159 = V_251 [ F_25 ( V_217 ) >> 2 ] ;
if ( ( ( V_214 -> V_166 & V_159 ) != 0 ) == ( ( F_25 ( V_217 ) & 1 ) != 0 ) )
V_207 -> V_162 [ F_30 ( V_217 ) ] =
V_207 -> V_162 [ F_20 ( V_217 ) ] ;
break;
default:
V_243:
return V_28 ;
}
V_207 -> V_170 = V_165 ;
F_16 ( V_207 ) ;
return 0 ;
}
static union V_261 F_40 ( union V_261 V_262 )
{
return F_41 ( F_42 ( 0 ) , V_262 ) ;
}
static union V_261 F_43 ( union V_261 V_262 )
{
return F_41 ( F_42 ( 0 ) , F_44 ( V_262 ) ) ;
}
static union V_263 F_45 ( union V_263 V_264 )
{
return F_46 ( F_47 ( 0 ) , V_264 ) ;
}
static union V_263 F_48 ( union V_263 V_264 )
{
return F_46 ( F_47 ( 0 ) , F_49 ( V_264 ) ) ;
}
static int F_39 ( struct V_161 * V_207 , struct V_213 * V_214 ,
V_1 V_217 , void * T_1 * V_215 )
{
unsigned V_265 = 0 ;
F_18 ( V_266 ) ;
switch ( F_50 ( V_217 ) ) {
case V_267 : {
union V_263 ( * V_268 ) ( union V_263 , union V_263 , union V_263 ) ;
union V_263 V_53 , V_49 , V_52 , V_51 ;
T_2 T_1 * V_269 ;
T_2 V_270 ;
switch ( F_37 ( V_217 ) ) {
case V_61 :
V_269 = ( void T_1 * ) ( V_207 -> V_162 [ F_51 ( V_217 ) ] +
V_207 -> V_162 [ F_52 ( V_217 ) ] ) ;
F_18 ( V_231 ) ;
if ( ! F_22 ( V_232 , V_269 , sizeof( T_2 ) ) ) {
F_18 ( V_233 ) ;
* V_215 = V_269 ;
return V_234 ;
}
if ( F_23 ( V_270 , V_269 ) ) {
F_18 ( V_233 ) ;
* V_215 = V_269 ;
return V_235 ;
}
F_28 ( V_270 , F_53 ( V_217 ) ) ;
break;
case V_63 :
V_269 = ( void T_1 * ) ( V_207 -> V_162 [ F_51 ( V_217 ) ] +
V_207 -> V_162 [ F_52 ( V_217 ) ] ) ;
F_18 ( V_236 ) ;
F_29 ( V_270 , F_54 ( V_217 ) ) ;
if ( ! F_22 ( V_237 , V_269 , sizeof( T_2 ) ) ) {
F_18 ( V_233 ) ;
* V_215 = V_269 ;
return V_234 ;
}
if ( F_55 ( V_270 , V_269 ) ) {
F_18 ( V_233 ) ;
* V_215 = V_269 ;
return V_235 ;
}
break;
case V_39 :
V_268 = V_271 ;
goto V_272;
case V_43 :
V_268 = V_273 ;
goto V_272;
case V_41 :
V_268 = V_274 ;
goto V_272;
case V_45 :
V_268 = V_275 ;
goto V_272;
V_272:
F_56 ( V_49 , F_51 ( V_217 ) ) ;
F_56 ( V_52 , F_54 ( V_217 ) ) ;
F_56 ( V_51 , F_52 ( V_217 ) ) ;
V_53 = (* V_268) ( V_49 , V_52 , V_51 ) ;
F_57 ( V_53 , F_53 ( V_217 ) ) ;
V_276:
if ( F_58 ( V_277 ) ) {
F_18 ( V_278 ) ;
V_265 |= V_279 | V_280 ;
}
if ( F_58 ( V_281 ) ) {
F_18 ( V_282 ) ;
V_265 |= V_283 | V_284 ;
}
if ( F_58 ( V_285 ) ) {
F_18 ( V_286 ) ;
V_265 |= V_287 | V_288 ;
}
if ( F_58 ( V_289 ) ) {
F_18 ( V_290 ) ;
V_265 |= V_291 | V_292 ;
}
V_214 -> V_166 = ( V_214 -> V_166 & ~ V_293 ) | V_265 ;
if ( ( V_214 -> V_166 >> 5 ) & V_214 -> V_166 & V_248 ) {
return V_249 ;
}
break;
default:
return V_28 ;
}
break;
}
case V_294 : {
union V_261 ( * V_268 ) ( union V_261 , union V_261 , union V_261 ) ;
union V_261 V_53 , V_49 , V_52 , V_51 ;
T_3 T_1 * V_269 ;
T_3 V_270 ;
switch ( F_37 ( V_217 ) ) {
case V_57 :
V_269 = ( void T_1 * ) ( V_207 -> V_162 [ F_51 ( V_217 ) ] +
V_207 -> V_162 [ F_52 ( V_217 ) ] ) ;
F_18 ( V_231 ) ;
if ( ! F_22 ( V_232 , V_269 , sizeof( T_3 ) ) ) {
F_18 ( V_233 ) ;
* V_215 = V_269 ;
return V_234 ;
}
if ( F_23 ( V_270 , V_269 ) ) {
F_18 ( V_233 ) ;
* V_215 = V_269 ;
return V_235 ;
}
F_24 ( V_270 , F_53 ( V_217 ) ) ;
break;
case V_59 :
V_269 = ( void T_1 * ) ( V_207 -> V_162 [ F_51 ( V_217 ) ] +
V_207 -> V_162 [ F_52 ( V_217 ) ] ) ;
F_18 ( V_236 ) ;
F_26 ( V_270 , F_54 ( V_217 ) ) ;
if ( ! F_22 ( V_237 , V_269 , sizeof( T_3 ) ) ) {
F_18 ( V_233 ) ;
* V_215 = V_269 ;
return V_234 ;
}
if ( F_27 ( V_270 , V_269 ) ) {
F_18 ( V_233 ) ;
* V_215 = V_269 ;
return V_235 ;
}
break;
case V_40 :
V_268 = V_295 ;
goto V_296;
case V_44 :
V_268 = V_297 ;
goto V_296;
case V_42 :
V_268 = V_298 ;
goto V_296;
case V_46 :
V_268 = V_299 ;
goto V_296;
V_296:
F_59 ( V_49 , F_51 ( V_217 ) ) ;
F_59 ( V_52 , F_54 ( V_217 ) ) ;
F_59 ( V_51 , F_52 ( V_217 ) ) ;
V_53 = (* V_268) ( V_49 , V_52 , V_51 ) ;
F_60 ( V_53 , F_53 ( V_217 ) ) ;
goto V_276;
default:
return V_28 ;
}
break;
}
case 0x3 :
if ( F_37 ( V_217 ) != V_300 )
return V_28 ;
break;
default:
return V_28 ;
}
return 0 ;
}
static int F_38 ( struct V_161 * V_207 , struct V_213 * V_214 ,
V_1 V_217 )
{
int V_301 ;
unsigned V_265 = 0 ;
unsigned int V_302 ;
unsigned int V_216 ;
unsigned V_159 ;
union {
union V_261 V_262 ;
union V_263 V_264 ;
int V_303 ;
T_4 V_304 ;
} V_305 ;
T_3 V_306 ;
F_18 ( V_307 ) ;
switch ( V_301 = ( F_61 ( V_217 ) & 0xf ) ) {
case V_267 : {
union {
union V_263 ( * V_308 ) ( union V_263 , union V_263 ) ;
union V_263 ( * V_309 ) ( union V_263 ) ;
} V_268 ;
union V_263 V_52 , V_51 ;
switch ( F_37 ( V_217 ) ) {
case V_79 :
V_268 . V_308 = V_310 ;
goto V_311;
case V_81 :
V_268 . V_308 = V_312 ;
goto V_311;
case V_83 :
V_268 . V_308 = V_313 ;
goto V_311;
case V_85 :
V_268 . V_308 = F_46 ;
goto V_311;
case V_143 :
if ( ! V_250 )
return V_28 ;
V_268 . V_309 = F_49 ;
goto V_314;
case V_142 :
if ( ! V_315 )
return V_28 ;
V_268 . V_309 = F_48 ;
goto V_314;
case V_144 :
if ( ! V_315 )
return V_28 ;
V_268 . V_309 = F_45 ;
goto V_314;
case V_76 :
if ( ! V_250 )
return V_28 ;
V_159 = V_251 [ F_52 ( V_217 ) >> 2 ] ;
if ( ( ( V_214 -> V_166 & V_159 ) != 0 ) !=
( ( F_52 ( V_217 ) & 1 ) != 0 ) )
return 0 ;
F_56 ( V_305 . V_264 , F_54 ( V_217 ) ) ;
break;
case V_90 :
if ( ! V_250 )
return V_28 ;
if ( V_207 -> V_162 [ F_52 ( V_217 ) ] != 0 )
return 0 ;
F_56 ( V_305 . V_264 , F_54 ( V_217 ) ) ;
break;
case V_88 :
if ( ! V_250 )
return V_28 ;
if ( V_207 -> V_162 [ F_52 ( V_217 ) ] == 0 )
return 0 ;
F_56 ( V_305 . V_264 , F_54 ( V_217 ) ) ;
break;
case V_116 :
V_268 . V_309 = V_316 ;
goto V_314;
case V_117 :
V_268 . V_309 = V_317 ;
goto V_314;
case V_115 :
F_56 ( V_305 . V_264 , F_54 ( V_217 ) ) ;
goto V_276;
V_311:
F_56 ( V_52 , F_54 ( V_217 ) ) ;
F_56 ( V_51 , F_52 ( V_217 ) ) ;
V_305 . V_264 = (* V_268 . V_308 ) ( V_52 , V_51 ) ;
goto V_276;
V_314:
F_56 ( V_52 , F_54 ( V_217 ) ) ;
V_305 . V_264 = (* V_268 . V_309 ) ( V_52 ) ;
goto V_276;
V_276:
if ( F_58 ( V_277 ) ) {
F_18 ( V_278 ) ;
V_265 |= V_279 | V_280 ;
}
if ( F_58 ( V_281 ) ) {
F_18 ( V_282 ) ;
V_265 |= V_283 | V_284 ;
}
if ( F_58 ( V_285 ) ) {
F_18 ( V_286 ) ;
V_265 |= V_287 | V_288 ;
}
if ( F_58 ( V_318 ) ) {
F_18 ( V_319 ) ;
V_265 |= V_320 | V_321 ;
}
if ( F_58 ( V_289 ) ) {
F_18 ( V_290 ) ;
V_265 |= V_291 | V_292 ;
}
break;
case V_107 :
return V_28 ;
case V_104 :
F_56 ( V_52 , F_54 ( V_217 ) ) ;
V_305 . V_262 = F_62 ( V_52 ) ;
V_301 = V_294 ;
goto V_276;
case V_137 :
F_56 ( V_52 , F_54 ( V_217 ) ) ;
V_305 . V_303 = F_63 ( V_52 ) ;
V_301 = V_322 ;
goto V_276;
case V_135 :
case V_133 :
case V_131 :
case V_129 :
if ( ! V_258 && ! V_240 )
return V_28 ;
V_302 = V_323 . V_324 ;
F_56 ( V_52 , F_54 ( V_217 ) ) ;
V_323 . V_324 = F_33 ( F_37 ( V_217 ) ) ;
V_305 . V_303 = F_63 ( V_52 ) ;
V_323 . V_324 = V_302 ;
V_301 = V_322 ;
goto V_276;
case V_136 :
if ( ! V_239 && ! V_240 )
return V_28 ;
F_56 ( V_52 , F_54 ( V_217 ) ) ;
V_305 . V_304 = F_64 ( V_52 ) ;
V_301 = V_325 ;
goto V_276;
case V_134 :
case V_132 :
case V_130 :
case V_128 :
if ( ! V_239 && ! V_240 )
return V_28 ;
V_302 = V_323 . V_324 ;
F_56 ( V_52 , F_54 ( V_217 ) ) ;
V_323 . V_324 = F_33 ( F_37 ( V_217 ) ) ;
V_305 . V_304 = F_64 ( V_52 ) ;
V_323 . V_324 = V_302 ;
V_301 = V_325 ;
goto V_276;
default:
if ( F_37 ( V_217 ) >= V_326 ) {
unsigned V_327 = F_37 ( V_217 ) - V_326 ;
union V_263 V_52 , V_51 ;
F_56 ( V_52 , F_54 ( V_217 ) ) ;
F_56 ( V_51 , F_52 ( V_217 ) ) ;
V_305 . V_303 = F_65 ( V_52 , V_51 ,
V_328 [ V_327 & 0x7 ] , V_327 & 0x8 ) ;
V_301 = - 1 ;
if ( ( V_327 & 0x8 ) && F_58
( V_289 ) )
V_265 = V_291 | V_292 ;
else
goto V_276;
} else
return V_28 ;
break;
}
break;
}
case V_294 : {
union V_261 V_52 , V_51 ;
union {
union V_261 ( * V_308 ) ( union V_261 , union V_261 ) ;
union V_261 ( * V_309 ) ( union V_261 ) ;
} V_268 ;
switch ( F_37 ( V_217 ) ) {
case V_79 :
V_268 . V_308 = V_329 ;
goto V_330;
case V_81 :
V_268 . V_308 = V_331 ;
goto V_330;
case V_83 :
V_268 . V_308 = V_332 ;
goto V_330;
case V_85 :
V_268 . V_308 = F_41 ;
goto V_330;
case V_143 :
if ( ! V_333 )
return V_28 ;
V_268 . V_309 = F_44 ;
goto V_334;
case V_142 :
if ( ! V_315 )
return V_28 ;
V_268 . V_309 = F_43 ;
goto V_334;
case V_144 :
if ( ! V_315 )
return V_28 ;
V_268 . V_309 = F_40 ;
goto V_334;
case V_76 :
if ( ! V_250 )
return V_28 ;
V_159 = V_251 [ F_52 ( V_217 ) >> 2 ] ;
if ( ( ( V_214 -> V_166 & V_159 ) != 0 ) !=
( ( F_52 ( V_217 ) & 1 ) != 0 ) )
return 0 ;
F_59 ( V_305 . V_262 , F_54 ( V_217 ) ) ;
break;
case V_90 :
if ( ! V_250 )
return V_28 ;
if ( V_207 -> V_162 [ F_52 ( V_217 ) ] != 0 )
return 0 ;
F_59 ( V_305 . V_262 , F_54 ( V_217 ) ) ;
break;
case V_88 :
if ( ! V_250 )
return V_28 ;
if ( V_207 -> V_162 [ F_52 ( V_217 ) ] == 0 )
return 0 ;
F_59 ( V_305 . V_262 , F_54 ( V_217 ) ) ;
break;
case V_116 :
V_268 . V_309 = V_335 ;
goto V_334;
case V_117 :
V_268 . V_309 = V_336 ;
goto V_334;
case V_115 :
F_59 ( V_305 . V_262 , F_54 ( V_217 ) ) ;
goto V_276;
V_330:
F_59 ( V_52 , F_54 ( V_217 ) ) ;
F_59 ( V_51 , F_52 ( V_217 ) ) ;
V_305 . V_262 = (* V_268 . V_308 ) ( V_52 , V_51 ) ;
goto V_276;
V_334:
F_59 ( V_52 , F_54 ( V_217 ) ) ;
V_305 . V_262 = (* V_268 . V_309 ) ( V_52 ) ;
goto V_276;
case V_107 :
F_59 ( V_52 , F_54 ( V_217 ) ) ;
V_305 . V_264 = F_66 ( V_52 ) ;
V_301 = V_267 ;
goto V_276;
case V_104 :
return V_28 ;
case V_137 :
F_59 ( V_52 , F_54 ( V_217 ) ) ;
V_305 . V_303 = F_67 ( V_52 ) ;
V_301 = V_322 ;
goto V_276;
case V_135 :
case V_133 :
case V_131 :
case V_129 :
if ( ! V_333 )
return V_28 ;
V_302 = V_323 . V_324 ;
F_59 ( V_52 , F_54 ( V_217 ) ) ;
V_323 . V_324 = F_33 ( F_37 ( V_217 ) ) ;
V_305 . V_303 = F_67 ( V_52 ) ;
V_323 . V_324 = V_302 ;
V_301 = V_322 ;
goto V_276;
case V_136 :
if ( ! V_239 && ! V_240 )
return V_28 ;
F_59 ( V_52 , F_54 ( V_217 ) ) ;
V_305 . V_304 = F_68 ( V_52 ) ;
V_301 = V_325 ;
goto V_276;
case V_134 :
case V_132 :
case V_130 :
case V_128 :
if ( ! V_239 && ! V_240 )
return V_28 ;
V_302 = V_323 . V_324 ;
F_59 ( V_52 , F_54 ( V_217 ) ) ;
V_323 . V_324 = F_33 ( F_37 ( V_217 ) ) ;
V_305 . V_304 = F_68 ( V_52 ) ;
V_323 . V_324 = V_302 ;
V_301 = V_325 ;
goto V_276;
default:
if ( F_37 ( V_217 ) >= V_326 ) {
unsigned V_327 = F_37 ( V_217 ) - V_326 ;
union V_261 V_52 , V_51 ;
F_59 ( V_52 , F_54 ( V_217 ) ) ;
F_59 ( V_51 , F_52 ( V_217 ) ) ;
V_305 . V_303 = F_69 ( V_52 , V_51 ,
V_328 [ V_327 & 0x7 ] , V_327 & 0x8 ) ;
V_301 = - 1 ;
if ( ( V_327 & 0x8 )
&&
F_58
( V_289 ) )
V_265 = V_291 | V_292 ;
else
goto V_276;
}
else {
return V_28 ;
}
break;
}
break;
case V_322 :
switch ( F_37 ( V_217 ) ) {
case V_107 :
F_56 ( V_52 , F_54 ( V_217 ) ) ;
V_305 . V_264 = F_70 ( V_52 . V_306 ) ;
V_301 = V_267 ;
goto V_276;
case V_104 :
F_56 ( V_52 , F_54 ( V_217 ) ) ;
V_305 . V_262 = F_71 ( V_52 . V_306 ) ;
V_301 = V_294 ;
goto V_276;
default:
return V_28 ;
}
break;
}
case V_325 :
if ( ! V_239 && ! V_240 )
return V_28 ;
F_26 ( V_306 , F_54 ( V_217 ) ) ;
switch ( F_37 ( V_217 ) ) {
case V_107 :
V_305 . V_264 = F_72 ( V_306 ) ;
V_301 = V_267 ;
goto V_276;
case V_104 :
V_305 . V_262 = F_73 ( V_306 ) ;
V_301 = V_294 ;
goto V_276;
default:
return V_28 ;
}
break;
default:
return V_28 ;
}
V_214 -> V_166 = ( V_214 -> V_166 & ~ V_293 ) | V_265 ;
if ( ( V_214 -> V_166 >> 5 ) & V_214 -> V_166 & V_248 ) {
return V_249 ;
}
switch ( V_301 ) {
case - 1 :
if ( V_250 )
V_216 = V_251 [ F_53 ( V_217 ) >> 2 ] ;
else
V_216 = V_252 ;
if ( V_305 . V_303 )
V_214 -> V_166 |= V_216 ;
else
V_214 -> V_166 &= ~ V_216 ;
break;
case V_294 :
F_60 ( V_305 . V_262 , F_53 ( V_217 ) ) ;
break;
case V_267 :
F_57 ( V_305 . V_264 , F_53 ( V_217 ) ) ;
break;
case V_322 :
F_28 ( V_305 . V_303 , F_53 ( V_217 ) ) ;
break;
case V_325 :
if ( ! V_239 && ! V_240 )
return V_28 ;
F_24 ( V_305 . V_304 , F_53 ( V_217 ) ) ;
break;
default:
return V_28 ;
}
return 0 ;
}
int F_74 ( struct V_161 * V_207 , struct V_213 * V_214 ,
int V_337 , void * T_1 * V_215 )
{
unsigned long V_338 , V_339 ;
struct V_163 V_164 ;
T_5 V_340 [ 4 ] ;
T_5 * V_341 ;
int V_224 = 0 ;
V_338 = V_207 -> V_170 ;
do {
V_339 = V_207 -> V_170 ;
if ( F_75 ( V_339 ) && V_225 ) {
if ( ( F_76 ( V_340 [ 0 ] , ( T_5 T_1 * ) F_77 ( V_207 -> V_170 ) ) ) ||
( F_76 ( V_340 [ 1 ] , ( T_5 T_1 * ) F_77 ( V_207 -> V_170 + 2 ) ) ) ||
( F_76 ( V_340 [ 2 ] , ( T_5 T_1 * ) F_77 ( V_207 -> V_170 + 4 ) ) ) ||
( F_76 ( V_340 [ 3 ] , ( T_5 T_1 * ) F_77 ( V_207 -> V_170 + 6 ) ) ) ) {
F_18 ( V_233 ) ;
return V_234 ;
}
V_341 = V_340 ;
if ( F_78 ( * V_341 ) ) {
V_164 . V_3 = ( * V_341 << 16 ) |
( * V_341 ) ;
V_164 . V_171 = 2 ;
V_341 += 1 ;
} else {
V_164 . V_3 = ( * V_341 << 16 ) |
* ( V_341 + 1 ) ;
V_164 . V_171 = 4 ;
V_341 += 2 ;
}
if ( F_78 ( * V_341 ) ) {
V_164 . V_227 = ( * V_341 << 16 ) |
( * V_341 ) ;
V_164 . V_172 = 2 ;
} else {
V_164 . V_227 = ( * V_341 << 16 ) |
* ( V_341 + 1 ) ;
V_164 . V_172 = 4 ;
}
V_164 . V_226 = 1 ;
} else {
if ( ( F_76 ( V_164 . V_3 ,
( V_1 T_1 * ) V_207 -> V_170 ) ) ||
( F_76 ( V_164 . V_227 ,
( V_1 T_1 * ) ( V_207 -> V_170 + 4 ) ) ) ) {
F_18 ( V_233 ) ;
return V_234 ;
}
V_164 . V_171 = 4 ;
V_164 . V_172 = 4 ;
V_164 . V_226 = 0 ;
}
if ( ( V_164 . V_3 == 0 ) ||
( ( V_164 . V_171 == 2 ) &&
( ( V_164 . V_3 & 0xffff ) == V_257 ) ) )
V_207 -> V_170 += V_164 . V_171 ;
else {
V_224 = F_12 ( V_207 , V_214 , V_164 , V_215 ) ;
}
if ( V_337 )
break;
if ( V_224 )
break;
F_79 () ;
} while ( V_207 -> V_170 > V_339 );
if ( V_224 == V_28 && V_207 -> V_170 != V_338 )
V_224 = 0 ;
return V_224 ;
}
