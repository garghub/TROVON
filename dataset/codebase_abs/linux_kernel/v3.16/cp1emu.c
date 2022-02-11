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
asm volatile(
".set push\n"
"\t.set mips1\n"
"\tcfc1\t%0,$31\n"
"\t.set pop" : "=r" (fcr31));
else
V_166 = V_203 -> V_204 . V_205 . V_166 ;
F_7 () ;
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
static inline int F_8 ( struct V_161 * V_206 )
{
if ( F_9 ( V_207 ) && ! F_9 ( V_208 ) )
return 1 ;
else if ( F_9 ( V_209 ) &&
! F_9 ( V_210 ) )
return 0 ;
return ! F_10 ( V_211 ) ;
}
static int F_11 ( struct V_161 * V_206 , struct V_212 * V_213 ,
struct V_163 V_164 , void * T_1 * V_214 )
{
unsigned long V_165 = V_206 -> V_170 + V_164 . V_171 ;
unsigned int V_159 , V_215 ;
V_1 V_216 ;
int V_217 , V_171 ;
T_2 T_1 * V_218 ;
T_3 T_1 * V_219 ;
T_2 V_220 ;
T_2 V_221 ;
T_3 V_222 ;
int V_223 ;
if ( ! V_224 && V_164 . V_225 )
F_12 () ;
if ( F_13 ( V_206 ) ) {
if ( V_164 . V_225 ) {
if ( ! F_14 ( V_206 , V_164 , & V_165 ) )
F_15 ( V_206 ) ;
} else {
if ( ! F_2 ( V_206 , V_164 , & V_165 ) )
F_15 ( V_206 ) ;
}
}
if ( F_13 ( V_206 ) ) {
V_216 = V_164 . V_226 ;
V_171 = V_164 . V_172 ;
} else {
V_216 = V_164 . V_3 ;
V_171 = V_164 . V_171 ;
}
if ( V_164 . V_225 ) {
if ( ( V_171 == 2 ) ||
( F_1 ( (union V_1 * ) & V_216 )
== V_28 ) )
return V_28 ;
}
V_227:
F_16 ( V_228 , 1 , V_206 , 0 ) ;
F_17 ( V_229 ) ;
switch ( F_18 ( V_216 ) ) {
case V_11 :
V_219 = ( T_3 T_1 * ) ( V_206 -> V_162 [ F_19 ( V_216 ) ] +
F_20 ( V_216 ) ) ;
F_17 ( V_230 ) ;
if ( ! F_21 ( V_231 , V_219 , sizeof( T_3 ) ) ) {
F_17 ( V_232 ) ;
* V_214 = V_219 ;
return V_233 ;
}
if ( F_22 ( V_222 , V_219 ) ) {
F_17 ( V_232 ) ;
* V_214 = V_219 ;
return V_234 ;
}
F_23 ( V_222 , F_24 ( V_216 ) ) ;
break;
case V_17 :
V_219 = ( T_3 T_1 * ) ( V_206 -> V_162 [ F_19 ( V_216 ) ] +
F_20 ( V_216 ) ) ;
F_17 ( V_235 ) ;
F_25 ( V_222 , F_24 ( V_216 ) ) ;
if ( ! F_21 ( V_236 , V_219 , sizeof( T_3 ) ) ) {
F_17 ( V_232 ) ;
* V_214 = V_219 ;
return V_233 ;
}
if ( F_26 ( V_222 , V_219 ) ) {
F_17 ( V_232 ) ;
* V_214 = V_219 ;
return V_234 ;
}
break;
case V_15 :
V_218 = ( T_2 T_1 * ) ( V_206 -> V_162 [ F_19 ( V_216 ) ] +
F_20 ( V_216 ) ) ;
F_17 ( V_230 ) ;
if ( ! F_21 ( V_231 , V_218 , sizeof( T_2 ) ) ) {
F_17 ( V_232 ) ;
* V_214 = V_218 ;
return V_233 ;
}
if ( F_22 ( V_221 , V_218 ) ) {
F_17 ( V_232 ) ;
* V_214 = V_218 ;
return V_234 ;
}
F_27 ( V_221 , F_24 ( V_216 ) ) ;
break;
case V_19 :
V_218 = ( T_2 T_1 * ) ( V_206 -> V_162 [ F_19 ( V_216 ) ] +
F_20 ( V_216 ) ) ;
F_17 ( V_235 ) ;
F_28 ( V_221 , F_24 ( V_216 ) ) ;
if ( ! F_21 ( V_236 , V_218 , sizeof( T_2 ) ) ) {
F_17 ( V_232 ) ;
* V_214 = V_218 ;
return V_233 ;
}
if ( F_26 ( V_221 , V_218 ) ) {
F_17 ( V_232 ) ;
* V_214 = V_218 ;
return V_234 ;
}
break;
case V_24 :
switch ( F_19 ( V_216 ) ) {
case V_237 :
if ( ! V_238 && ! V_239 )
return V_28 ;
if ( F_24 ( V_216 ) != 0 ) {
F_25 ( V_206 -> V_162 [ F_24 ( V_216 ) ] ,
F_29 ( V_216 ) ) ;
}
break;
case V_240 :
if ( ! V_238 && ! V_239 )
return V_28 ;
F_23 ( V_206 -> V_162 [ F_24 ( V_216 ) ] , F_29 ( V_216 ) ) ;
break;
case V_155 :
if ( ! V_241 )
goto V_242;
if ( F_24 ( V_216 ) != 0 ) {
F_30 ( V_206 -> V_162 [ F_24 ( V_216 ) ] ,
F_29 ( V_216 ) ) ;
}
break;
case V_156 :
if ( ! V_241 )
goto V_242;
F_31 ( V_206 -> V_162 [ F_24 ( V_216 ) ] , F_29 ( V_216 ) ) ;
break;
case V_151 :
if ( F_24 ( V_216 ) != 0 ) {
F_28 ( V_206 -> V_162 [ F_24 ( V_216 ) ] ,
F_29 ( V_216 ) ) ;
}
break;
case V_152 :
F_27 ( V_206 -> V_162 [ F_24 ( V_216 ) ] , F_29 ( V_216 ) ) ;
break;
case V_153 :
if ( F_29 ( V_216 ) == V_243 ) {
V_220 = V_213 -> V_166 ;
V_220 = ( V_220 & ~ V_244 ) | F_32 ( V_220 ) ;
F_33 ( L_1 ,
( void * ) ( V_206 -> V_170 ) ,
F_24 ( V_216 ) , V_220 ) ;
}
else if ( F_29 ( V_216 ) == V_245 )
V_220 = 0 ;
else
V_220 = 0 ;
if ( F_24 ( V_216 ) )
V_206 -> V_162 [ F_24 ( V_216 ) ] = V_220 ;
break;
case V_154 :
if ( F_24 ( V_216 ) == 0 )
V_220 = 0 ;
else
V_220 = V_206 -> V_162 [ F_24 ( V_216 ) ] ;
if ( F_29 ( V_216 ) == V_243 ) {
F_33 ( L_2 ,
( void * ) ( V_206 -> V_170 ) ,
F_24 ( V_216 ) , V_220 ) ;
V_213 -> V_166 = ( V_220 & ~ ( V_246 | V_244 ) ) |
F_32 ( V_220 ) ;
}
if ( ( V_213 -> V_166 >> 5 ) & V_213 -> V_166 & V_247 ) {
return V_248 ;
}
break;
case V_26 :
if ( F_13 ( V_206 ) )
return V_28 ;
if ( V_249 )
V_215 = V_250 [ F_24 ( V_216 ) >> 2 ] ;
else
V_215 = V_251 ;
V_159 = V_213 -> V_166 & V_215 ;
V_217 = 0 ;
switch ( F_24 ( V_216 ) & 3 ) {
case V_252 :
V_217 = 1 ;
case V_253 :
V_159 = ! V_159 ;
break;
case V_254 :
V_217 = 1 ;
case V_255 :
break;
default:
return V_28 ;
}
F_34 ( V_206 ) ;
if ( V_159 ) {
V_206 -> V_170 += V_164 . V_171 ;
V_165 = F_20 ( V_216 ) ;
V_216 = V_164 . V_226 ;
if ( V_164 . V_225 ) {
V_165 = ( V_206 -> V_170 + ( V_165 << 1 ) ) ;
if ( ( V_164 . V_172 == 2 ) ||
( F_1 ( (union V_1 * ) & V_216 ) == V_28 ) ) {
if ( V_164 . V_172 == 2 )
V_216 = ( V_216 & ( ~ 0xffff ) ) | V_256 ;
return F_35 ( V_206 , V_216 , V_165 ) ;
}
} else
V_165 = ( V_206 -> V_170 + ( V_165 << 2 ) ) ;
switch ( F_18 ( V_216 ) ) {
case V_15 :
goto V_227;
case V_19 :
goto V_227;
case V_11 :
case V_17 :
if ( V_257 ||
V_239 )
goto V_227;
return V_28 ;
goto V_227;
case V_24 :
goto V_227;
case V_48 :
if ( V_258 || V_239 )
goto V_227;
return V_28 ;
case V_97 :
if ( ! V_249 )
return V_28 ;
if ( F_36 ( V_216 ) == V_99 )
goto V_227;
break;
}
return F_35 ( V_206 , V_216 , V_165 ) ;
} else if ( V_217 ) {
V_206 -> V_170 += V_164 . V_171 ;
V_165 += V_164 . V_171 ;
}
break;
default:
if ( ! ( F_19 ( V_216 ) & 0x10 ) )
return V_28 ;
if ( ( V_223 = F_37 ( V_206 , V_213 , V_216 ) ) )
return V_223 ;
}
break;
case V_48 :
if ( ! V_258 && ! V_239 )
return V_28 ;
V_223 = F_38 ( V_206 , V_213 , V_216 , V_214 ) ;
if ( V_223 )
return V_223 ;
break;
case V_97 :
if ( ! V_249 )
return V_28 ;
if ( F_36 ( V_216 ) != V_99 )
return V_28 ;
V_159 = V_250 [ F_24 ( V_216 ) >> 2 ] ;
if ( ( ( V_213 -> V_166 & V_159 ) != 0 ) == ( ( F_24 ( V_216 ) & 1 ) != 0 ) )
V_206 -> V_162 [ F_29 ( V_216 ) ] =
V_206 -> V_162 [ F_19 ( V_216 ) ] ;
break;
default:
V_242:
return V_28 ;
}
V_206 -> V_170 = V_165 ;
F_15 ( V_206 ) ;
return 0 ;
}
static union V_259 F_39 ( union V_259 V_260 )
{
return F_40 ( F_41 ( 0 ) , V_260 ) ;
}
static union V_259 F_42 ( union V_259 V_260 )
{
return F_40 ( F_41 ( 0 ) , F_43 ( V_260 ) ) ;
}
static union V_261 F_44 ( union V_261 V_262 )
{
return F_45 ( F_46 ( 0 ) , V_262 ) ;
}
static union V_261 F_47 ( union V_261 V_262 )
{
return F_45 ( F_46 ( 0 ) , F_48 ( V_262 ) ) ;
}
static int F_38 ( struct V_161 * V_206 , struct V_212 * V_213 ,
V_1 V_216 , void * T_1 * V_214 )
{
unsigned V_263 = 0 ;
F_17 ( V_264 ) ;
switch ( F_49 ( V_216 ) ) {
case V_265 : {
union V_261 ( * V_266 ) ( union V_261 , union V_261 , union V_261 ) ;
union V_261 V_53 , V_49 , V_52 , V_51 ;
T_2 T_1 * V_267 ;
T_2 V_268 ;
switch ( F_36 ( V_216 ) ) {
case V_61 :
V_267 = ( void T_1 * ) ( V_206 -> V_162 [ F_50 ( V_216 ) ] +
V_206 -> V_162 [ F_51 ( V_216 ) ] ) ;
F_17 ( V_230 ) ;
if ( ! F_21 ( V_231 , V_267 , sizeof( T_2 ) ) ) {
F_17 ( V_232 ) ;
* V_214 = V_267 ;
return V_233 ;
}
if ( F_22 ( V_268 , V_267 ) ) {
F_17 ( V_232 ) ;
* V_214 = V_267 ;
return V_234 ;
}
F_27 ( V_268 , F_52 ( V_216 ) ) ;
break;
case V_63 :
V_267 = ( void T_1 * ) ( V_206 -> V_162 [ F_50 ( V_216 ) ] +
V_206 -> V_162 [ F_51 ( V_216 ) ] ) ;
F_17 ( V_235 ) ;
F_28 ( V_268 , F_53 ( V_216 ) ) ;
if ( ! F_21 ( V_236 , V_267 , sizeof( T_2 ) ) ) {
F_17 ( V_232 ) ;
* V_214 = V_267 ;
return V_233 ;
}
if ( F_54 ( V_268 , V_267 ) ) {
F_17 ( V_232 ) ;
* V_214 = V_267 ;
return V_234 ;
}
break;
case V_39 :
V_266 = V_269 ;
goto V_270;
case V_43 :
V_266 = V_271 ;
goto V_270;
case V_41 :
V_266 = V_272 ;
goto V_270;
case V_45 :
V_266 = V_273 ;
goto V_270;
V_270:
F_55 ( V_49 , F_50 ( V_216 ) ) ;
F_55 ( V_52 , F_53 ( V_216 ) ) ;
F_55 ( V_51 , F_51 ( V_216 ) ) ;
V_53 = (* V_266) ( V_49 , V_52 , V_51 ) ;
F_56 ( V_53 , F_52 ( V_216 ) ) ;
V_274:
if ( F_57 ( V_275 ) ) {
F_17 ( V_276 ) ;
V_263 |= V_277 | V_278 ;
}
if ( F_57 ( V_279 ) ) {
F_17 ( V_280 ) ;
V_263 |= V_281 | V_282 ;
}
if ( F_57 ( V_283 ) ) {
F_17 ( V_284 ) ;
V_263 |= V_285 | V_286 ;
}
if ( F_57 ( V_287 ) ) {
F_17 ( V_288 ) ;
V_263 |= V_289 | V_290 ;
}
V_213 -> V_166 = ( V_213 -> V_166 & ~ V_291 ) | V_263 ;
if ( ( V_213 -> V_166 >> 5 ) & V_213 -> V_166 & V_247 ) {
return V_248 ;
}
break;
default:
return V_28 ;
}
break;
}
case V_292 : {
union V_259 ( * V_266 ) ( union V_259 , union V_259 , union V_259 ) ;
union V_259 V_53 , V_49 , V_52 , V_51 ;
T_3 T_1 * V_267 ;
T_3 V_268 ;
switch ( F_36 ( V_216 ) ) {
case V_57 :
V_267 = ( void T_1 * ) ( V_206 -> V_162 [ F_50 ( V_216 ) ] +
V_206 -> V_162 [ F_51 ( V_216 ) ] ) ;
F_17 ( V_230 ) ;
if ( ! F_21 ( V_231 , V_267 , sizeof( T_3 ) ) ) {
F_17 ( V_232 ) ;
* V_214 = V_267 ;
return V_233 ;
}
if ( F_22 ( V_268 , V_267 ) ) {
F_17 ( V_232 ) ;
* V_214 = V_267 ;
return V_234 ;
}
F_23 ( V_268 , F_52 ( V_216 ) ) ;
break;
case V_59 :
V_267 = ( void T_1 * ) ( V_206 -> V_162 [ F_50 ( V_216 ) ] +
V_206 -> V_162 [ F_51 ( V_216 ) ] ) ;
F_17 ( V_235 ) ;
F_25 ( V_268 , F_53 ( V_216 ) ) ;
if ( ! F_21 ( V_236 , V_267 , sizeof( T_3 ) ) ) {
F_17 ( V_232 ) ;
* V_214 = V_267 ;
return V_233 ;
}
if ( F_26 ( V_268 , V_267 ) ) {
F_17 ( V_232 ) ;
* V_214 = V_267 ;
return V_234 ;
}
break;
case V_40 :
V_266 = V_293 ;
goto V_294;
case V_44 :
V_266 = V_295 ;
goto V_294;
case V_42 :
V_266 = V_296 ;
goto V_294;
case V_46 :
V_266 = V_297 ;
goto V_294;
V_294:
F_58 ( V_49 , F_50 ( V_216 ) ) ;
F_58 ( V_52 , F_53 ( V_216 ) ) ;
F_58 ( V_51 , F_51 ( V_216 ) ) ;
V_53 = (* V_266) ( V_49 , V_52 , V_51 ) ;
F_59 ( V_53 , F_52 ( V_216 ) ) ;
goto V_274;
default:
return V_28 ;
}
break;
}
case 0x3 :
if ( F_36 ( V_216 ) != V_298 )
return V_28 ;
break;
default:
return V_28 ;
}
return 0 ;
}
static int F_37 ( struct V_161 * V_206 , struct V_212 * V_213 ,
V_1 V_216 )
{
int V_299 ;
unsigned V_263 = 0 ;
unsigned int V_300 ;
unsigned int V_215 ;
unsigned V_159 ;
union {
union V_259 V_260 ;
union V_261 V_262 ;
int V_301 ;
T_4 V_302 ;
} V_303 ;
T_3 V_304 ;
F_17 ( V_305 ) ;
switch ( V_299 = ( F_60 ( V_216 ) & 0xf ) ) {
case V_265 : {
union {
union V_261 ( * V_306 ) ( union V_261 , union V_261 ) ;
union V_261 ( * V_307 ) ( union V_261 ) ;
} V_266 ;
union V_261 V_52 , V_51 ;
switch ( F_36 ( V_216 ) ) {
case V_79 :
V_266 . V_306 = V_308 ;
goto V_309;
case V_81 :
V_266 . V_306 = V_310 ;
goto V_309;
case V_83 :
V_266 . V_306 = V_311 ;
goto V_309;
case V_85 :
V_266 . V_306 = F_45 ;
goto V_309;
case V_143 :
if ( ! V_249 )
return V_28 ;
V_266 . V_307 = F_48 ;
goto V_312;
case V_142 :
if ( ! V_313 )
return V_28 ;
V_266 . V_307 = F_47 ;
goto V_312;
case V_144 :
if ( ! V_313 )
return V_28 ;
V_266 . V_307 = F_44 ;
goto V_312;
case V_76 :
if ( ! V_249 )
return V_28 ;
V_159 = V_250 [ F_51 ( V_216 ) >> 2 ] ;
if ( ( ( V_213 -> V_166 & V_159 ) != 0 ) !=
( ( F_51 ( V_216 ) & 1 ) != 0 ) )
return 0 ;
F_55 ( V_303 . V_262 , F_53 ( V_216 ) ) ;
break;
case V_90 :
if ( ! V_249 )
return V_28 ;
if ( V_206 -> V_162 [ F_51 ( V_216 ) ] != 0 )
return 0 ;
F_55 ( V_303 . V_262 , F_53 ( V_216 ) ) ;
break;
case V_88 :
if ( ! V_249 )
return V_28 ;
if ( V_206 -> V_162 [ F_51 ( V_216 ) ] == 0 )
return 0 ;
F_55 ( V_303 . V_262 , F_53 ( V_216 ) ) ;
break;
case V_116 :
V_266 . V_307 = V_314 ;
goto V_312;
case V_117 :
V_266 . V_307 = V_315 ;
goto V_312;
case V_115 :
F_55 ( V_303 . V_262 , F_53 ( V_216 ) ) ;
goto V_274;
V_309:
F_55 ( V_52 , F_53 ( V_216 ) ) ;
F_55 ( V_51 , F_51 ( V_216 ) ) ;
V_303 . V_262 = (* V_266 . V_306 ) ( V_52 , V_51 ) ;
goto V_274;
V_312:
F_55 ( V_52 , F_53 ( V_216 ) ) ;
V_303 . V_262 = (* V_266 . V_307 ) ( V_52 ) ;
goto V_274;
V_274:
if ( F_57 ( V_275 ) ) {
F_17 ( V_276 ) ;
V_263 |= V_277 | V_278 ;
}
if ( F_57 ( V_279 ) ) {
F_17 ( V_280 ) ;
V_263 |= V_281 | V_282 ;
}
if ( F_57 ( V_283 ) ) {
F_17 ( V_284 ) ;
V_263 |= V_285 | V_286 ;
}
if ( F_57 ( V_316 ) ) {
F_17 ( V_317 ) ;
V_263 |= V_318 | V_319 ;
}
if ( F_57 ( V_287 ) ) {
F_17 ( V_288 ) ;
V_263 |= V_289 | V_290 ;
}
break;
case V_107 :
return V_28 ;
case V_104 :
F_55 ( V_52 , F_53 ( V_216 ) ) ;
V_303 . V_260 = F_61 ( V_52 ) ;
V_299 = V_292 ;
goto V_274;
case V_137 :
F_55 ( V_52 , F_53 ( V_216 ) ) ;
V_303 . V_301 = F_62 ( V_52 ) ;
V_299 = V_320 ;
goto V_274;
case V_135 :
case V_133 :
case V_131 :
case V_129 :
if ( ! V_257 && ! V_239 )
return V_28 ;
V_300 = V_321 . V_322 ;
F_55 ( V_52 , F_53 ( V_216 ) ) ;
V_321 . V_322 = F_32 ( F_36 ( V_216 ) ) ;
V_303 . V_301 = F_62 ( V_52 ) ;
V_321 . V_322 = V_300 ;
V_299 = V_320 ;
goto V_274;
case V_136 :
if ( ! V_238 && ! V_239 )
return V_28 ;
F_55 ( V_52 , F_53 ( V_216 ) ) ;
V_303 . V_302 = F_63 ( V_52 ) ;
V_299 = V_323 ;
goto V_274;
case V_134 :
case V_132 :
case V_130 :
case V_128 :
if ( ! V_238 && ! V_239 )
return V_28 ;
V_300 = V_321 . V_322 ;
F_55 ( V_52 , F_53 ( V_216 ) ) ;
V_321 . V_322 = F_32 ( F_36 ( V_216 ) ) ;
V_303 . V_302 = F_63 ( V_52 ) ;
V_321 . V_322 = V_300 ;
V_299 = V_323 ;
goto V_274;
default:
if ( F_36 ( V_216 ) >= V_324 ) {
unsigned V_325 = F_36 ( V_216 ) - V_324 ;
union V_261 V_52 , V_51 ;
F_55 ( V_52 , F_53 ( V_216 ) ) ;
F_55 ( V_51 , F_51 ( V_216 ) ) ;
V_303 . V_301 = F_64 ( V_52 , V_51 ,
V_326 [ V_325 & 0x7 ] , V_325 & 0x8 ) ;
V_299 = - 1 ;
if ( ( V_325 & 0x8 ) && F_57
( V_287 ) )
V_263 = V_289 | V_290 ;
else
goto V_274;
} else
return V_28 ;
break;
}
break;
}
case V_292 : {
union V_259 V_52 , V_51 ;
union {
union V_259 ( * V_306 ) ( union V_259 , union V_259 ) ;
union V_259 ( * V_307 ) ( union V_259 ) ;
} V_266 ;
switch ( F_36 ( V_216 ) ) {
case V_79 :
V_266 . V_306 = V_327 ;
goto V_328;
case V_81 :
V_266 . V_306 = V_329 ;
goto V_328;
case V_83 :
V_266 . V_306 = V_330 ;
goto V_328;
case V_85 :
V_266 . V_306 = F_40 ;
goto V_328;
case V_143 :
if ( ! V_331 )
return V_28 ;
V_266 . V_307 = F_43 ;
goto V_332;
case V_142 :
if ( ! V_313 )
return V_28 ;
V_266 . V_307 = F_42 ;
goto V_332;
case V_144 :
if ( ! V_313 )
return V_28 ;
V_266 . V_307 = F_39 ;
goto V_332;
case V_76 :
if ( ! V_249 )
return V_28 ;
V_159 = V_250 [ F_51 ( V_216 ) >> 2 ] ;
if ( ( ( V_213 -> V_166 & V_159 ) != 0 ) !=
( ( F_51 ( V_216 ) & 1 ) != 0 ) )
return 0 ;
F_58 ( V_303 . V_260 , F_53 ( V_216 ) ) ;
break;
case V_90 :
if ( ! V_249 )
return V_28 ;
if ( V_206 -> V_162 [ F_51 ( V_216 ) ] != 0 )
return 0 ;
F_58 ( V_303 . V_260 , F_53 ( V_216 ) ) ;
break;
case V_88 :
if ( ! V_249 )
return V_28 ;
if ( V_206 -> V_162 [ F_51 ( V_216 ) ] == 0 )
return 0 ;
F_58 ( V_303 . V_260 , F_53 ( V_216 ) ) ;
break;
case V_116 :
V_266 . V_307 = V_333 ;
goto V_332;
case V_117 :
V_266 . V_307 = V_334 ;
goto V_332;
case V_115 :
F_58 ( V_303 . V_260 , F_53 ( V_216 ) ) ;
goto V_274;
V_328:
F_58 ( V_52 , F_53 ( V_216 ) ) ;
F_58 ( V_51 , F_51 ( V_216 ) ) ;
V_303 . V_260 = (* V_266 . V_306 ) ( V_52 , V_51 ) ;
goto V_274;
V_332:
F_58 ( V_52 , F_53 ( V_216 ) ) ;
V_303 . V_260 = (* V_266 . V_307 ) ( V_52 ) ;
goto V_274;
case V_107 :
F_58 ( V_52 , F_53 ( V_216 ) ) ;
V_303 . V_262 = F_65 ( V_52 ) ;
V_299 = V_265 ;
goto V_274;
case V_104 :
return V_28 ;
case V_137 :
F_58 ( V_52 , F_53 ( V_216 ) ) ;
V_303 . V_301 = F_66 ( V_52 ) ;
V_299 = V_320 ;
goto V_274;
case V_135 :
case V_133 :
case V_131 :
case V_129 :
if ( ! V_331 )
return V_28 ;
V_300 = V_321 . V_322 ;
F_58 ( V_52 , F_53 ( V_216 ) ) ;
V_321 . V_322 = F_32 ( F_36 ( V_216 ) ) ;
V_303 . V_301 = F_66 ( V_52 ) ;
V_321 . V_322 = V_300 ;
V_299 = V_320 ;
goto V_274;
case V_136 :
if ( ! V_238 && ! V_239 )
return V_28 ;
F_58 ( V_52 , F_53 ( V_216 ) ) ;
V_303 . V_302 = F_67 ( V_52 ) ;
V_299 = V_323 ;
goto V_274;
case V_134 :
case V_132 :
case V_130 :
case V_128 :
if ( ! V_238 && ! V_239 )
return V_28 ;
V_300 = V_321 . V_322 ;
F_58 ( V_52 , F_53 ( V_216 ) ) ;
V_321 . V_322 = F_32 ( F_36 ( V_216 ) ) ;
V_303 . V_302 = F_67 ( V_52 ) ;
V_321 . V_322 = V_300 ;
V_299 = V_323 ;
goto V_274;
default:
if ( F_36 ( V_216 ) >= V_324 ) {
unsigned V_325 = F_36 ( V_216 ) - V_324 ;
union V_259 V_52 , V_51 ;
F_58 ( V_52 , F_53 ( V_216 ) ) ;
F_58 ( V_51 , F_51 ( V_216 ) ) ;
V_303 . V_301 = F_68 ( V_52 , V_51 ,
V_326 [ V_325 & 0x7 ] , V_325 & 0x8 ) ;
V_299 = - 1 ;
if ( ( V_325 & 0x8 )
&&
F_57
( V_287 ) )
V_263 = V_289 | V_290 ;
else
goto V_274;
}
else {
return V_28 ;
}
break;
}
break;
case V_320 :
switch ( F_36 ( V_216 ) ) {
case V_107 :
F_55 ( V_52 , F_53 ( V_216 ) ) ;
V_303 . V_262 = F_69 ( V_52 . V_304 ) ;
V_299 = V_265 ;
goto V_274;
case V_104 :
F_55 ( V_52 , F_53 ( V_216 ) ) ;
V_303 . V_260 = F_70 ( V_52 . V_304 ) ;
V_299 = V_292 ;
goto V_274;
default:
return V_28 ;
}
break;
}
case V_323 :
if ( ! V_238 && ! V_239 )
return V_28 ;
F_25 ( V_304 , F_53 ( V_216 ) ) ;
switch ( F_36 ( V_216 ) ) {
case V_107 :
V_303 . V_262 = F_71 ( V_304 ) ;
V_299 = V_265 ;
goto V_274;
case V_104 :
V_303 . V_260 = F_72 ( V_304 ) ;
V_299 = V_292 ;
goto V_274;
default:
return V_28 ;
}
break;
default:
return V_28 ;
}
V_213 -> V_166 = ( V_213 -> V_166 & ~ V_291 ) | V_263 ;
if ( ( V_213 -> V_166 >> 5 ) & V_213 -> V_166 & V_247 ) {
return V_248 ;
}
switch ( V_299 ) {
case - 1 :
if ( V_249 )
V_215 = V_250 [ F_24 ( V_216 ) >> 2 ] ;
else
V_215 = V_251 ;
if ( V_303 . V_301 )
V_213 -> V_166 |= V_215 ;
else
V_213 -> V_166 &= ~ V_215 ;
break;
case V_292 :
F_59 ( V_303 . V_260 , F_52 ( V_216 ) ) ;
break;
case V_265 :
F_56 ( V_303 . V_262 , F_52 ( V_216 ) ) ;
break;
case V_320 :
F_27 ( V_303 . V_301 , F_52 ( V_216 ) ) ;
break;
case V_323 :
if ( ! V_238 && ! V_239 )
return V_28 ;
F_23 ( V_303 . V_302 , F_52 ( V_216 ) ) ;
break;
default:
return V_28 ;
}
return 0 ;
}
int F_73 ( struct V_161 * V_206 , struct V_212 * V_213 ,
int V_335 , void * T_1 * V_214 )
{
unsigned long V_336 , V_337 ;
struct V_163 V_164 ;
T_5 V_338 [ 4 ] ;
T_5 * V_339 ;
int V_223 = 0 ;
V_336 = V_206 -> V_170 ;
do {
V_337 = V_206 -> V_170 ;
if ( F_74 ( V_337 ) && V_224 ) {
if ( ( F_75 ( V_338 [ 0 ] , ( T_5 T_1 * ) F_76 ( V_206 -> V_170 ) ) ) ||
( F_75 ( V_338 [ 1 ] , ( T_5 T_1 * ) F_76 ( V_206 -> V_170 + 2 ) ) ) ||
( F_75 ( V_338 [ 2 ] , ( T_5 T_1 * ) F_76 ( V_206 -> V_170 + 4 ) ) ) ||
( F_75 ( V_338 [ 3 ] , ( T_5 T_1 * ) F_76 ( V_206 -> V_170 + 6 ) ) ) ) {
F_17 ( V_232 ) ;
return V_233 ;
}
V_339 = V_338 ;
if ( F_77 ( * V_339 ) ) {
V_164 . V_3 = ( * V_339 << 16 ) |
( * V_339 ) ;
V_164 . V_171 = 2 ;
V_339 += 1 ;
} else {
V_164 . V_3 = ( * V_339 << 16 ) |
* ( V_339 + 1 ) ;
V_164 . V_171 = 4 ;
V_339 += 2 ;
}
if ( F_77 ( * V_339 ) ) {
V_164 . V_226 = ( * V_339 << 16 ) |
( * V_339 ) ;
V_164 . V_172 = 2 ;
} else {
V_164 . V_226 = ( * V_339 << 16 ) |
* ( V_339 + 1 ) ;
V_164 . V_172 = 4 ;
}
V_164 . V_225 = 1 ;
} else {
if ( ( F_75 ( V_164 . V_3 ,
( V_1 T_1 * ) V_206 -> V_170 ) ) ||
( F_75 ( V_164 . V_226 ,
( V_1 T_1 * ) ( V_206 -> V_170 + 4 ) ) ) ) {
F_17 ( V_232 ) ;
return V_233 ;
}
V_164 . V_171 = 4 ;
V_164 . V_172 = 4 ;
V_164 . V_225 = 0 ;
}
if ( ( V_164 . V_3 == 0 ) ||
( ( V_164 . V_171 == 2 ) &&
( ( V_164 . V_3 & 0xffff ) == V_256 ) ) )
V_206 -> V_170 += V_164 . V_171 ;
else {
V_223 = F_11 ( V_206 , V_213 , V_164 , V_214 ) ;
}
if ( V_335 )
break;
if ( V_223 )
break;
F_78 () ;
} while ( V_206 -> V_170 > V_337 );
if ( V_223 == V_28 && V_206 -> V_170 != V_336 )
V_223 = 0 ;
return V_223 ;
}
