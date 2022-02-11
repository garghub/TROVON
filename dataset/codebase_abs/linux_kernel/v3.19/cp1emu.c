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
static inline bool F_12 ( void )
{
return F_11 ( V_213 ) ;
}
static int F_13 ( struct V_161 * V_207 , struct V_214 * V_215 ,
struct V_163 V_164 , void * T_1 * V_216 )
{
unsigned long V_165 = V_207 -> V_170 + V_164 . V_171 ;
unsigned int V_159 , V_217 ;
V_1 V_218 ;
int V_219 , V_171 ;
T_2 T_1 * V_220 ;
T_3 T_1 * V_221 ;
T_2 V_222 ;
T_2 V_223 ;
T_3 V_224 ;
int V_225 ;
if ( ! V_226 && V_164 . V_227 )
F_14 () ;
if ( F_15 ( V_207 ) ) {
if ( V_164 . V_227 ) {
if ( ! F_16 ( V_207 , V_164 , & V_165 ) )
F_17 ( V_207 ) ;
} else {
if ( ! F_2 ( V_207 , V_164 , & V_165 ) )
F_17 ( V_207 ) ;
}
}
if ( F_15 ( V_207 ) ) {
V_218 = V_164 . V_228 ;
V_171 = V_164 . V_172 ;
} else {
V_218 = V_164 . V_3 ;
V_171 = V_164 . V_171 ;
}
if ( V_164 . V_227 ) {
if ( ( V_171 == 2 ) ||
( F_1 ( (union V_1 * ) & V_218 )
== V_28 ) )
return V_28 ;
}
V_229:
F_18 ( V_230 , 1 , V_207 , 0 ) ;
F_19 ( V_231 ) ;
switch ( F_20 ( V_218 ) ) {
case V_11 :
V_221 = ( T_3 T_1 * ) ( V_207 -> V_162 [ F_21 ( V_218 ) ] +
F_22 ( V_218 ) ) ;
F_19 ( V_232 ) ;
if ( ! F_23 ( V_233 , V_221 , sizeof( T_3 ) ) ) {
F_19 ( V_234 ) ;
* V_216 = V_221 ;
return V_235 ;
}
if ( F_24 ( V_224 , V_221 ) ) {
F_19 ( V_234 ) ;
* V_216 = V_221 ;
return V_236 ;
}
F_25 ( V_224 , F_26 ( V_218 ) ) ;
break;
case V_17 :
V_221 = ( T_3 T_1 * ) ( V_207 -> V_162 [ F_21 ( V_218 ) ] +
F_22 ( V_218 ) ) ;
F_19 ( V_237 ) ;
F_27 ( V_224 , F_26 ( V_218 ) ) ;
if ( ! F_23 ( V_238 , V_221 , sizeof( T_3 ) ) ) {
F_19 ( V_234 ) ;
* V_216 = V_221 ;
return V_235 ;
}
if ( F_28 ( V_224 , V_221 ) ) {
F_19 ( V_234 ) ;
* V_216 = V_221 ;
return V_236 ;
}
break;
case V_15 :
V_220 = ( T_2 T_1 * ) ( V_207 -> V_162 [ F_21 ( V_218 ) ] +
F_22 ( V_218 ) ) ;
F_19 ( V_232 ) ;
if ( ! F_23 ( V_233 , V_220 , sizeof( T_2 ) ) ) {
F_19 ( V_234 ) ;
* V_216 = V_220 ;
return V_235 ;
}
if ( F_24 ( V_223 , V_220 ) ) {
F_19 ( V_234 ) ;
* V_216 = V_220 ;
return V_236 ;
}
F_29 ( V_223 , F_26 ( V_218 ) ) ;
break;
case V_19 :
V_220 = ( T_2 T_1 * ) ( V_207 -> V_162 [ F_21 ( V_218 ) ] +
F_22 ( V_218 ) ) ;
F_19 ( V_237 ) ;
F_30 ( V_223 , F_26 ( V_218 ) ) ;
if ( ! F_23 ( V_238 , V_220 , sizeof( T_2 ) ) ) {
F_19 ( V_234 ) ;
* V_216 = V_220 ;
return V_235 ;
}
if ( F_28 ( V_223 , V_220 ) ) {
F_19 ( V_234 ) ;
* V_216 = V_220 ;
return V_236 ;
}
break;
case V_24 :
switch ( F_21 ( V_218 ) ) {
case V_239 :
if ( ! V_240 && ! V_241 )
return V_28 ;
if ( F_26 ( V_218 ) != 0 ) {
F_27 ( V_207 -> V_162 [ F_26 ( V_218 ) ] ,
F_31 ( V_218 ) ) ;
}
break;
case V_242 :
if ( ! V_240 && ! V_241 )
return V_28 ;
F_25 ( V_207 -> V_162 [ F_26 ( V_218 ) ] , F_31 ( V_218 ) ) ;
break;
case V_155 :
if ( ! V_243 )
goto V_244;
if ( F_26 ( V_218 ) != 0 ) {
F_32 ( V_207 -> V_162 [ F_26 ( V_218 ) ] ,
F_31 ( V_218 ) ) ;
}
break;
case V_156 :
if ( ! V_243 )
goto V_244;
F_33 ( V_207 -> V_162 [ F_26 ( V_218 ) ] , F_31 ( V_218 ) ) ;
break;
case V_151 :
if ( F_26 ( V_218 ) != 0 ) {
F_30 ( V_207 -> V_162 [ F_26 ( V_218 ) ] ,
F_31 ( V_218 ) ) ;
}
break;
case V_152 :
F_29 ( V_207 -> V_162 [ F_26 ( V_218 ) ] , F_31 ( V_218 ) ) ;
break;
case V_153 :
if ( F_31 ( V_218 ) == V_245 ) {
V_222 = V_215 -> V_166 ;
V_222 = ( V_222 & ~ V_246 ) | F_34 ( V_222 ) ;
F_35 ( L_1 ,
( void * ) ( V_207 -> V_170 ) ,
F_26 ( V_218 ) , V_222 ) ;
}
else if ( F_31 ( V_218 ) == V_247 )
V_222 = 0 ;
else
V_222 = 0 ;
if ( F_26 ( V_218 ) )
V_207 -> V_162 [ F_26 ( V_218 ) ] = V_222 ;
break;
case V_154 :
if ( F_26 ( V_218 ) == 0 )
V_222 = 0 ;
else
V_222 = V_207 -> V_162 [ F_26 ( V_218 ) ] ;
if ( F_31 ( V_218 ) == V_245 ) {
F_35 ( L_2 ,
( void * ) ( V_207 -> V_170 ) ,
F_26 ( V_218 ) , V_222 ) ;
V_215 -> V_166 = ( V_222 & ~ ( V_248 | V_246 ) ) |
F_34 ( V_222 ) ;
}
if ( ( V_215 -> V_166 >> 5 ) & V_215 -> V_166 & V_249 ) {
return V_250 ;
}
break;
case V_26 :
if ( F_15 ( V_207 ) )
return V_28 ;
if ( V_251 )
V_217 = V_252 [ F_26 ( V_218 ) >> 2 ] ;
else
V_217 = V_253 ;
V_159 = V_215 -> V_166 & V_217 ;
V_219 = 0 ;
switch ( F_26 ( V_218 ) & 3 ) {
case V_254 :
V_219 = 1 ;
case V_255 :
V_159 = ! V_159 ;
break;
case V_256 :
V_219 = 1 ;
case V_257 :
break;
default:
return V_28 ;
}
F_36 ( V_207 ) ;
if ( V_159 ) {
V_207 -> V_170 += V_164 . V_171 ;
V_165 = F_22 ( V_218 ) ;
V_218 = V_164 . V_228 ;
if ( V_164 . V_227 ) {
V_165 = ( V_207 -> V_170 + ( V_165 << 1 ) ) ;
if ( ( V_164 . V_172 == 2 ) ||
( F_1 ( (union V_1 * ) & V_218 ) == V_28 ) ) {
if ( V_164 . V_172 == 2 )
V_218 = ( V_218 & ( ~ 0xffff ) ) | V_258 ;
return F_37 ( V_207 , V_218 , V_165 ) ;
}
} else
V_165 = ( V_207 -> V_170 + ( V_165 << 2 ) ) ;
switch ( F_20 ( V_218 ) ) {
case V_15 :
goto V_229;
case V_19 :
goto V_229;
case V_11 :
case V_17 :
if ( V_259 ||
V_241 )
goto V_229;
return V_28 ;
goto V_229;
case V_24 :
goto V_229;
case V_48 :
if ( V_260 || V_241 || V_261 )
goto V_229;
return V_28 ;
case V_97 :
if ( ! V_251 )
return V_28 ;
if ( F_38 ( V_218 ) == V_99 )
goto V_229;
break;
}
return F_37 ( V_207 , V_218 , V_165 ) ;
} else if ( V_219 ) {
V_207 -> V_170 += V_164 . V_171 ;
V_165 += V_164 . V_171 ;
}
break;
default:
if ( ! ( F_21 ( V_218 ) & 0x10 ) )
return V_28 ;
if ( ( V_225 = F_39 ( V_207 , V_215 , V_218 ) ) )
return V_225 ;
}
break;
case V_48 :
if ( ! V_260 && ! V_241 && ! V_261 )
return V_28 ;
V_225 = F_40 ( V_207 , V_215 , V_218 , V_216 ) ;
if ( V_225 )
return V_225 ;
break;
case V_97 :
if ( ! V_251 )
return V_28 ;
if ( F_38 ( V_218 ) != V_99 )
return V_28 ;
V_159 = V_252 [ F_26 ( V_218 ) >> 2 ] ;
if ( ( ( V_215 -> V_166 & V_159 ) != 0 ) == ( ( F_26 ( V_218 ) & 1 ) != 0 ) )
V_207 -> V_162 [ F_31 ( V_218 ) ] =
V_207 -> V_162 [ F_21 ( V_218 ) ] ;
break;
default:
V_244:
return V_28 ;
}
V_207 -> V_170 = V_165 ;
F_17 ( V_207 ) ;
return 0 ;
}
static union V_262 F_41 ( union V_262 V_263 )
{
return F_42 ( F_43 ( 0 ) , V_263 ) ;
}
static union V_262 F_44 ( union V_262 V_263 )
{
return F_42 ( F_43 ( 0 ) , F_45 ( V_263 ) ) ;
}
static union V_264 F_46 ( union V_264 V_265 )
{
return F_47 ( F_48 ( 0 ) , V_265 ) ;
}
static union V_264 F_49 ( union V_264 V_265 )
{
return F_47 ( F_48 ( 0 ) , F_50 ( V_265 ) ) ;
}
static int F_40 ( struct V_161 * V_207 , struct V_214 * V_215 ,
V_1 V_218 , void * T_1 * V_216 )
{
unsigned V_266 = 0 ;
F_19 ( V_267 ) ;
switch ( F_51 ( V_218 ) ) {
case V_268 : {
union V_264 ( * V_269 ) ( union V_264 , union V_264 , union V_264 ) ;
union V_264 V_53 , V_49 , V_52 , V_51 ;
T_2 T_1 * V_270 ;
T_2 V_271 ;
switch ( F_38 ( V_218 ) ) {
case V_61 :
V_270 = ( void T_1 * ) ( V_207 -> V_162 [ F_52 ( V_218 ) ] +
V_207 -> V_162 [ F_53 ( V_218 ) ] ) ;
F_19 ( V_232 ) ;
if ( ! F_23 ( V_233 , V_270 , sizeof( T_2 ) ) ) {
F_19 ( V_234 ) ;
* V_216 = V_270 ;
return V_235 ;
}
if ( F_24 ( V_271 , V_270 ) ) {
F_19 ( V_234 ) ;
* V_216 = V_270 ;
return V_236 ;
}
F_29 ( V_271 , F_54 ( V_218 ) ) ;
break;
case V_63 :
V_270 = ( void T_1 * ) ( V_207 -> V_162 [ F_52 ( V_218 ) ] +
V_207 -> V_162 [ F_53 ( V_218 ) ] ) ;
F_19 ( V_237 ) ;
F_30 ( V_271 , F_55 ( V_218 ) ) ;
if ( ! F_23 ( V_238 , V_270 , sizeof( T_2 ) ) ) {
F_19 ( V_234 ) ;
* V_216 = V_270 ;
return V_235 ;
}
if ( F_56 ( V_271 , V_270 ) ) {
F_19 ( V_234 ) ;
* V_216 = V_270 ;
return V_236 ;
}
break;
case V_39 :
V_269 = V_272 ;
goto V_273;
case V_43 :
V_269 = V_274 ;
goto V_273;
case V_41 :
V_269 = V_275 ;
goto V_273;
case V_45 :
V_269 = V_276 ;
goto V_273;
V_273:
F_57 ( V_49 , F_52 ( V_218 ) ) ;
F_57 ( V_52 , F_55 ( V_218 ) ) ;
F_57 ( V_51 , F_53 ( V_218 ) ) ;
V_53 = (* V_269) ( V_49 , V_52 , V_51 ) ;
F_58 ( V_53 , F_54 ( V_218 ) ) ;
V_277:
if ( F_59 ( V_278 ) ) {
F_19 ( V_279 ) ;
V_266 |= V_280 | V_281 ;
}
if ( F_59 ( V_282 ) ) {
F_19 ( V_283 ) ;
V_266 |= V_284 | V_285 ;
}
if ( F_59 ( V_286 ) ) {
F_19 ( V_287 ) ;
V_266 |= V_288 | V_289 ;
}
if ( F_59 ( V_290 ) ) {
F_19 ( V_291 ) ;
V_266 |= V_292 | V_293 ;
}
V_215 -> V_166 = ( V_215 -> V_166 & ~ V_294 ) | V_266 ;
if ( ( V_215 -> V_166 >> 5 ) & V_215 -> V_166 & V_249 ) {
return V_250 ;
}
break;
default:
return V_28 ;
}
break;
}
case V_295 : {
union V_262 ( * V_269 ) ( union V_262 , union V_262 , union V_262 ) ;
union V_262 V_53 , V_49 , V_52 , V_51 ;
T_3 T_1 * V_270 ;
T_3 V_271 ;
switch ( F_38 ( V_218 ) ) {
case V_57 :
V_270 = ( void T_1 * ) ( V_207 -> V_162 [ F_52 ( V_218 ) ] +
V_207 -> V_162 [ F_53 ( V_218 ) ] ) ;
F_19 ( V_232 ) ;
if ( ! F_23 ( V_233 , V_270 , sizeof( T_3 ) ) ) {
F_19 ( V_234 ) ;
* V_216 = V_270 ;
return V_235 ;
}
if ( F_24 ( V_271 , V_270 ) ) {
F_19 ( V_234 ) ;
* V_216 = V_270 ;
return V_236 ;
}
F_25 ( V_271 , F_54 ( V_218 ) ) ;
break;
case V_59 :
V_270 = ( void T_1 * ) ( V_207 -> V_162 [ F_52 ( V_218 ) ] +
V_207 -> V_162 [ F_53 ( V_218 ) ] ) ;
F_19 ( V_237 ) ;
F_27 ( V_271 , F_55 ( V_218 ) ) ;
if ( ! F_23 ( V_238 , V_270 , sizeof( T_3 ) ) ) {
F_19 ( V_234 ) ;
* V_216 = V_270 ;
return V_235 ;
}
if ( F_28 ( V_271 , V_270 ) ) {
F_19 ( V_234 ) ;
* V_216 = V_270 ;
return V_236 ;
}
break;
case V_40 :
V_269 = V_296 ;
goto V_297;
case V_44 :
V_269 = V_298 ;
goto V_297;
case V_42 :
V_269 = V_299 ;
goto V_297;
case V_46 :
V_269 = V_300 ;
goto V_297;
V_297:
F_60 ( V_49 , F_52 ( V_218 ) ) ;
F_60 ( V_52 , F_55 ( V_218 ) ) ;
F_60 ( V_51 , F_53 ( V_218 ) ) ;
V_53 = (* V_269) ( V_49 , V_52 , V_51 ) ;
F_61 ( V_53 , F_54 ( V_218 ) ) ;
goto V_277;
default:
return V_28 ;
}
break;
}
case 0x3 :
if ( F_38 ( V_218 ) != V_301 )
return V_28 ;
break;
default:
return V_28 ;
}
return 0 ;
}
static int F_39 ( struct V_161 * V_207 , struct V_214 * V_215 ,
V_1 V_218 )
{
int V_302 ;
unsigned V_266 = 0 ;
unsigned int V_303 ;
unsigned int V_217 ;
unsigned V_159 ;
union {
union V_262 V_263 ;
union V_264 V_265 ;
int V_304 ;
T_4 V_305 ;
} V_306 ;
T_3 V_307 ;
F_19 ( V_308 ) ;
switch ( V_302 = ( F_62 ( V_218 ) & 0xf ) ) {
case V_268 : {
union {
union V_264 ( * V_309 ) ( union V_264 , union V_264 ) ;
union V_264 ( * V_310 ) ( union V_264 ) ;
} V_269 ;
union V_264 V_52 , V_51 ;
switch ( F_38 ( V_218 ) ) {
case V_79 :
V_269 . V_309 = V_311 ;
goto V_312;
case V_81 :
V_269 . V_309 = V_313 ;
goto V_312;
case V_83 :
V_269 . V_309 = V_314 ;
goto V_312;
case V_85 :
V_269 . V_309 = F_47 ;
goto V_312;
case V_143 :
if ( ! V_251 )
return V_28 ;
V_269 . V_310 = F_50 ;
goto V_315;
case V_142 :
if ( ! V_316 )
return V_28 ;
V_269 . V_310 = F_49 ;
goto V_315;
case V_144 :
if ( ! V_316 )
return V_28 ;
V_269 . V_310 = F_46 ;
goto V_315;
case V_76 :
if ( ! V_251 )
return V_28 ;
V_159 = V_252 [ F_53 ( V_218 ) >> 2 ] ;
if ( ( ( V_215 -> V_166 & V_159 ) != 0 ) !=
( ( F_53 ( V_218 ) & 1 ) != 0 ) )
return 0 ;
F_57 ( V_306 . V_265 , F_55 ( V_218 ) ) ;
break;
case V_90 :
if ( ! V_251 )
return V_28 ;
if ( V_207 -> V_162 [ F_53 ( V_218 ) ] != 0 )
return 0 ;
F_57 ( V_306 . V_265 , F_55 ( V_218 ) ) ;
break;
case V_88 :
if ( ! V_251 )
return V_28 ;
if ( V_207 -> V_162 [ F_53 ( V_218 ) ] == 0 )
return 0 ;
F_57 ( V_306 . V_265 , F_55 ( V_218 ) ) ;
break;
case V_116 :
V_269 . V_310 = V_317 ;
goto V_315;
case V_117 :
V_269 . V_310 = V_318 ;
goto V_315;
case V_115 :
F_57 ( V_306 . V_265 , F_55 ( V_218 ) ) ;
goto V_277;
V_312:
F_57 ( V_52 , F_55 ( V_218 ) ) ;
F_57 ( V_51 , F_53 ( V_218 ) ) ;
V_306 . V_265 = (* V_269 . V_309 ) ( V_52 , V_51 ) ;
goto V_277;
V_315:
F_57 ( V_52 , F_55 ( V_218 ) ) ;
V_306 . V_265 = (* V_269 . V_310 ) ( V_52 ) ;
goto V_277;
V_277:
if ( F_59 ( V_278 ) ) {
F_19 ( V_279 ) ;
V_266 |= V_280 | V_281 ;
}
if ( F_59 ( V_282 ) ) {
F_19 ( V_283 ) ;
V_266 |= V_284 | V_285 ;
}
if ( F_59 ( V_286 ) ) {
F_19 ( V_287 ) ;
V_266 |= V_288 | V_289 ;
}
if ( F_59 ( V_319 ) ) {
F_19 ( V_320 ) ;
V_266 |= V_321 | V_322 ;
}
if ( F_59 ( V_290 ) ) {
F_19 ( V_291 ) ;
V_266 |= V_292 | V_293 ;
}
break;
case V_107 :
return V_28 ;
case V_104 :
F_57 ( V_52 , F_55 ( V_218 ) ) ;
V_306 . V_263 = F_63 ( V_52 ) ;
V_302 = V_295 ;
goto V_277;
case V_137 :
F_57 ( V_52 , F_55 ( V_218 ) ) ;
V_306 . V_304 = F_64 ( V_52 ) ;
V_302 = V_323 ;
goto V_277;
case V_135 :
case V_133 :
case V_131 :
case V_129 :
if ( ! V_259 && ! V_241 )
return V_28 ;
V_303 = V_324 . V_325 ;
F_57 ( V_52 , F_55 ( V_218 ) ) ;
V_324 . V_325 = F_34 ( F_38 ( V_218 ) ) ;
V_306 . V_304 = F_64 ( V_52 ) ;
V_324 . V_325 = V_303 ;
V_302 = V_323 ;
goto V_277;
case V_136 :
if ( ! V_240 && ! V_241 )
return V_28 ;
F_57 ( V_52 , F_55 ( V_218 ) ) ;
V_306 . V_305 = F_65 ( V_52 ) ;
V_302 = V_326 ;
goto V_277;
case V_134 :
case V_132 :
case V_130 :
case V_128 :
if ( ! V_240 && ! V_241 )
return V_28 ;
V_303 = V_324 . V_325 ;
F_57 ( V_52 , F_55 ( V_218 ) ) ;
V_324 . V_325 = F_34 ( F_38 ( V_218 ) ) ;
V_306 . V_305 = F_65 ( V_52 ) ;
V_324 . V_325 = V_303 ;
V_302 = V_326 ;
goto V_277;
default:
if ( F_38 ( V_218 ) >= V_327 ) {
unsigned V_328 = F_38 ( V_218 ) - V_327 ;
union V_264 V_52 , V_51 ;
F_57 ( V_52 , F_55 ( V_218 ) ) ;
F_57 ( V_51 , F_53 ( V_218 ) ) ;
V_306 . V_304 = F_66 ( V_52 , V_51 ,
V_329 [ V_328 & 0x7 ] , V_328 & 0x8 ) ;
V_302 = - 1 ;
if ( ( V_328 & 0x8 ) && F_59
( V_290 ) )
V_266 = V_292 | V_293 ;
else
goto V_277;
} else
return V_28 ;
break;
}
break;
}
case V_295 : {
union V_262 V_52 , V_51 ;
union {
union V_262 ( * V_309 ) ( union V_262 , union V_262 ) ;
union V_262 ( * V_310 ) ( union V_262 ) ;
} V_269 ;
switch ( F_38 ( V_218 ) ) {
case V_79 :
V_269 . V_309 = V_330 ;
goto V_331;
case V_81 :
V_269 . V_309 = V_332 ;
goto V_331;
case V_83 :
V_269 . V_309 = V_333 ;
goto V_331;
case V_85 :
V_269 . V_309 = F_42 ;
goto V_331;
case V_143 :
if ( ! V_334 )
return V_28 ;
V_269 . V_310 = F_45 ;
goto V_335;
case V_142 :
if ( ! V_316 )
return V_28 ;
V_269 . V_310 = F_44 ;
goto V_335;
case V_144 :
if ( ! V_316 )
return V_28 ;
V_269 . V_310 = F_41 ;
goto V_335;
case V_76 :
if ( ! V_251 )
return V_28 ;
V_159 = V_252 [ F_53 ( V_218 ) >> 2 ] ;
if ( ( ( V_215 -> V_166 & V_159 ) != 0 ) !=
( ( F_53 ( V_218 ) & 1 ) != 0 ) )
return 0 ;
F_60 ( V_306 . V_263 , F_55 ( V_218 ) ) ;
break;
case V_90 :
if ( ! V_251 )
return V_28 ;
if ( V_207 -> V_162 [ F_53 ( V_218 ) ] != 0 )
return 0 ;
F_60 ( V_306 . V_263 , F_55 ( V_218 ) ) ;
break;
case V_88 :
if ( ! V_251 )
return V_28 ;
if ( V_207 -> V_162 [ F_53 ( V_218 ) ] == 0 )
return 0 ;
F_60 ( V_306 . V_263 , F_55 ( V_218 ) ) ;
break;
case V_116 :
V_269 . V_310 = V_336 ;
goto V_335;
case V_117 :
V_269 . V_310 = V_337 ;
goto V_335;
case V_115 :
F_60 ( V_306 . V_263 , F_55 ( V_218 ) ) ;
goto V_277;
V_331:
F_60 ( V_52 , F_55 ( V_218 ) ) ;
F_60 ( V_51 , F_53 ( V_218 ) ) ;
V_306 . V_263 = (* V_269 . V_309 ) ( V_52 , V_51 ) ;
goto V_277;
V_335:
F_60 ( V_52 , F_55 ( V_218 ) ) ;
V_306 . V_263 = (* V_269 . V_310 ) ( V_52 ) ;
goto V_277;
case V_107 :
F_60 ( V_52 , F_55 ( V_218 ) ) ;
V_306 . V_265 = F_67 ( V_52 ) ;
V_302 = V_268 ;
goto V_277;
case V_104 :
return V_28 ;
case V_137 :
F_60 ( V_52 , F_55 ( V_218 ) ) ;
V_306 . V_304 = F_68 ( V_52 ) ;
V_302 = V_323 ;
goto V_277;
case V_135 :
case V_133 :
case V_131 :
case V_129 :
if ( ! V_334 )
return V_28 ;
V_303 = V_324 . V_325 ;
F_60 ( V_52 , F_55 ( V_218 ) ) ;
V_324 . V_325 = F_34 ( F_38 ( V_218 ) ) ;
V_306 . V_304 = F_68 ( V_52 ) ;
V_324 . V_325 = V_303 ;
V_302 = V_323 ;
goto V_277;
case V_136 :
if ( ! V_240 && ! V_241 )
return V_28 ;
F_60 ( V_52 , F_55 ( V_218 ) ) ;
V_306 . V_305 = F_69 ( V_52 ) ;
V_302 = V_326 ;
goto V_277;
case V_134 :
case V_132 :
case V_130 :
case V_128 :
if ( ! V_240 && ! V_241 )
return V_28 ;
V_303 = V_324 . V_325 ;
F_60 ( V_52 , F_55 ( V_218 ) ) ;
V_324 . V_325 = F_34 ( F_38 ( V_218 ) ) ;
V_306 . V_305 = F_69 ( V_52 ) ;
V_324 . V_325 = V_303 ;
V_302 = V_326 ;
goto V_277;
default:
if ( F_38 ( V_218 ) >= V_327 ) {
unsigned V_328 = F_38 ( V_218 ) - V_327 ;
union V_262 V_52 , V_51 ;
F_60 ( V_52 , F_55 ( V_218 ) ) ;
F_60 ( V_51 , F_53 ( V_218 ) ) ;
V_306 . V_304 = F_70 ( V_52 , V_51 ,
V_329 [ V_328 & 0x7 ] , V_328 & 0x8 ) ;
V_302 = - 1 ;
if ( ( V_328 & 0x8 )
&&
F_59
( V_290 ) )
V_266 = V_292 | V_293 ;
else
goto V_277;
}
else {
return V_28 ;
}
break;
}
break;
case V_323 :
switch ( F_38 ( V_218 ) ) {
case V_107 :
F_57 ( V_52 , F_55 ( V_218 ) ) ;
V_306 . V_265 = F_71 ( V_52 . V_307 ) ;
V_302 = V_268 ;
goto V_277;
case V_104 :
F_57 ( V_52 , F_55 ( V_218 ) ) ;
V_306 . V_263 = F_72 ( V_52 . V_307 ) ;
V_302 = V_295 ;
goto V_277;
default:
return V_28 ;
}
break;
}
case V_326 :
if ( ! V_240 && ! V_241 )
return V_28 ;
F_27 ( V_307 , F_55 ( V_218 ) ) ;
switch ( F_38 ( V_218 ) ) {
case V_107 :
V_306 . V_265 = F_73 ( V_307 ) ;
V_302 = V_268 ;
goto V_277;
case V_104 :
V_306 . V_263 = F_74 ( V_307 ) ;
V_302 = V_295 ;
goto V_277;
default:
return V_28 ;
}
break;
default:
return V_28 ;
}
V_215 -> V_166 = ( V_215 -> V_166 & ~ V_294 ) | V_266 ;
if ( ( V_215 -> V_166 >> 5 ) & V_215 -> V_166 & V_249 ) {
return V_250 ;
}
switch ( V_302 ) {
case - 1 :
if ( V_251 )
V_217 = V_252 [ F_54 ( V_218 ) >> 2 ] ;
else
V_217 = V_253 ;
if ( V_306 . V_304 )
V_215 -> V_166 |= V_217 ;
else
V_215 -> V_166 &= ~ V_217 ;
break;
case V_295 :
F_61 ( V_306 . V_263 , F_54 ( V_218 ) ) ;
break;
case V_268 :
F_58 ( V_306 . V_265 , F_54 ( V_218 ) ) ;
break;
case V_323 :
F_29 ( V_306 . V_304 , F_54 ( V_218 ) ) ;
break;
case V_326 :
if ( ! V_240 && ! V_241 )
return V_28 ;
F_25 ( V_306 . V_305 , F_54 ( V_218 ) ) ;
break;
default:
return V_28 ;
}
return 0 ;
}
int F_75 ( struct V_161 * V_207 , struct V_214 * V_215 ,
int V_338 , void * T_1 * V_216 )
{
unsigned long V_339 , V_340 ;
struct V_163 V_164 ;
T_5 V_341 [ 4 ] ;
T_5 * V_342 ;
int V_225 = 0 ;
V_339 = V_207 -> V_170 ;
do {
V_340 = V_207 -> V_170 ;
if ( F_76 ( V_340 ) && V_226 ) {
if ( ( F_77 ( V_341 [ 0 ] , ( T_5 T_1 * ) F_78 ( V_207 -> V_170 ) ) ) ||
( F_77 ( V_341 [ 1 ] , ( T_5 T_1 * ) F_78 ( V_207 -> V_170 + 2 ) ) ) ||
( F_77 ( V_341 [ 2 ] , ( T_5 T_1 * ) F_78 ( V_207 -> V_170 + 4 ) ) ) ||
( F_77 ( V_341 [ 3 ] , ( T_5 T_1 * ) F_78 ( V_207 -> V_170 + 6 ) ) ) ) {
F_19 ( V_234 ) ;
return V_235 ;
}
V_342 = V_341 ;
if ( F_79 ( * V_342 ) ) {
V_164 . V_3 = ( * V_342 << 16 ) |
( * V_342 ) ;
V_164 . V_171 = 2 ;
V_342 += 1 ;
} else {
V_164 . V_3 = ( * V_342 << 16 ) |
* ( V_342 + 1 ) ;
V_164 . V_171 = 4 ;
V_342 += 2 ;
}
if ( F_79 ( * V_342 ) ) {
V_164 . V_228 = ( * V_342 << 16 ) |
( * V_342 ) ;
V_164 . V_172 = 2 ;
} else {
V_164 . V_228 = ( * V_342 << 16 ) |
* ( V_342 + 1 ) ;
V_164 . V_172 = 4 ;
}
V_164 . V_227 = 1 ;
} else {
if ( ( F_77 ( V_164 . V_3 ,
( V_1 T_1 * ) V_207 -> V_170 ) ) ||
( F_77 ( V_164 . V_228 ,
( V_1 T_1 * ) ( V_207 -> V_170 + 4 ) ) ) ) {
F_19 ( V_234 ) ;
return V_235 ;
}
V_164 . V_171 = 4 ;
V_164 . V_172 = 4 ;
V_164 . V_227 = 0 ;
}
if ( ( V_164 . V_3 == 0 ) ||
( ( V_164 . V_171 == 2 ) &&
( ( V_164 . V_3 & 0xffff ) == V_258 ) ) )
V_207 -> V_170 += V_164 . V_171 ;
else {
V_225 = F_13 ( V_207 , V_215 , V_164 , V_216 ) ;
}
if ( V_338 )
break;
if ( V_225 )
break;
F_80 () ;
} while ( V_207 -> V_170 > V_340 );
if ( V_225 == V_28 && V_207 -> V_170 != V_339 )
V_225 = 0 ;
return V_225 ;
}
