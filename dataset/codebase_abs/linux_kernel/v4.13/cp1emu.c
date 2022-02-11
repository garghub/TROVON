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
unsigned int V_166 ;
unsigned int V_167 = 0 ;
unsigned int V_168 ;
union V_169 * V_170 ;
switch ( V_3 . V_171 . V_9 ) {
case V_97 :
switch ( V_3 . V_64 . V_5 ) {
case V_172 :
if ( V_3 . V_64 . V_67 != 0 ) {
V_162 -> V_162 [ V_3 . V_64 . V_67 ] =
V_162 -> V_173 + V_164 . V_174 +
V_164 . V_175 ;
}
case V_176 :
if ( V_177 && V_3 . V_64 . V_5 == V_176 )
break;
* V_165 = V_162 -> V_162 [ V_3 . V_64 . V_13 ] ;
return 1 ;
}
break;
case V_178 :
switch ( V_3 . V_171 . V_12 ) {
case V_179 :
case V_180 :
if ( V_177 && ( V_3 . V_171 . V_13 ||
V_3 . V_171 . V_12 == V_180 ) )
break;
V_162 -> V_162 [ 31 ] = V_162 -> V_173 +
V_164 . V_174 +
V_164 . V_175 ;
case V_181 :
if ( V_177 )
break;
case V_182 :
if ( ( long ) V_162 -> V_162 [ V_3 . V_171 . V_13 ] < 0 )
* V_165 = V_162 -> V_173 +
V_164 . V_174 +
( V_3 . V_171 . V_183 << 2 ) ;
else
* V_165 = V_162 -> V_173 +
V_164 . V_174 +
V_164 . V_175 ;
return 1 ;
case V_184 :
case V_185 :
if ( V_177 && ( V_3 . V_171 . V_13 ||
V_3 . V_171 . V_12 == V_185 ) )
break;
V_162 -> V_162 [ 31 ] = V_162 -> V_173 +
V_164 . V_174 +
V_164 . V_175 ;
case V_186 :
if ( V_177 )
break;
case V_187 :
if ( ( long ) V_162 -> V_162 [ V_3 . V_171 . V_13 ] >= 0 )
* V_165 = V_162 -> V_173 +
V_164 . V_174 +
( V_3 . V_171 . V_183 << 2 ) ;
else
* V_165 = V_162 -> V_173 +
V_164 . V_174 +
V_164 . V_175 ;
return 1 ;
}
break;
case V_188 :
F_3 ( V_167 ) ;
case V_189 :
V_162 -> V_162 [ 31 ] = V_162 -> V_173 +
V_164 . V_174 +
V_164 . V_175 ;
case V_190 :
* V_165 = V_162 -> V_173 + V_164 . V_174 ;
* V_165 >>= 28 ;
* V_165 <<= 28 ;
* V_165 |= ( V_3 . V_191 . V_192 << 2 ) ;
* V_165 ^= V_167 ;
return 1 ;
case V_193 :
if ( V_177 )
break;
case V_194 :
if ( V_162 -> V_162 [ V_3 . V_171 . V_13 ] ==
V_162 -> V_162 [ V_3 . V_171 . V_12 ] )
* V_165 = V_162 -> V_173 +
V_164 . V_174 +
( V_3 . V_171 . V_183 << 2 ) ;
else
* V_165 = V_162 -> V_173 +
V_164 . V_174 +
V_164 . V_175 ;
return 1 ;
case V_195 :
if ( V_177 )
break;
case V_196 :
if ( V_162 -> V_162 [ V_3 . V_171 . V_13 ] !=
V_162 -> V_162 [ V_3 . V_171 . V_12 ] )
* V_165 = V_162 -> V_173 +
V_164 . V_174 +
( V_3 . V_171 . V_183 << 2 ) ;
else
* V_165 = V_162 -> V_173 +
V_164 . V_174 +
V_164 . V_175 ;
return 1 ;
case V_197 :
if ( ! V_3 . V_171 . V_12 && V_177 )
break;
case V_198 :
if ( V_199 && V_3 . V_171 . V_12 ) {
if ( ( V_3 . V_171 . V_9 == V_198 ) &&
( ( ! V_3 . V_171 . V_13 && V_3 . V_171 . V_12 ) ||
( V_3 . V_171 . V_13 == V_3 . V_171 . V_12 ) ) )
V_162 -> V_162 [ 31 ] = V_162 -> V_173 +
V_164 . V_174 ;
* V_165 = V_162 -> V_173 + V_164 . V_174 +
V_164 . V_175 ;
return 1 ;
}
if ( ( long ) V_162 -> V_162 [ V_3 . V_171 . V_13 ] <= 0 )
* V_165 = V_162 -> V_173 +
V_164 . V_174 +
( V_3 . V_171 . V_183 << 2 ) ;
else
* V_165 = V_162 -> V_173 +
V_164 . V_174 +
V_164 . V_175 ;
return 1 ;
case V_200 :
if ( ! V_3 . V_171 . V_12 && V_177 )
break;
case V_201 :
if ( V_199 && V_3 . V_171 . V_12 ) {
if ( ( V_3 . V_171 . V_9 == V_198 ) &&
( ( ! V_3 . V_171 . V_13 && V_3 . V_171 . V_12 ) ||
( V_3 . V_171 . V_13 == V_3 . V_171 . V_12 ) ) )
V_162 -> V_162 [ 31 ] = V_162 -> V_173 +
V_164 . V_174 ;
* V_165 = V_162 -> V_173 + V_164 . V_174 +
V_164 . V_175 ;
return 1 ;
}
if ( ( long ) V_162 -> V_162 [ V_3 . V_171 . V_13 ] > 0 )
* V_165 = V_162 -> V_173 +
V_164 . V_174 +
( V_3 . V_171 . V_183 << 2 ) ;
else
* V_165 = V_162 -> V_173 +
V_164 . V_174 +
V_164 . V_175 ;
return 1 ;
case V_202 :
case V_203 :
if ( ! V_199 )
break;
if ( V_3 . V_171 . V_12 && ! V_3 . V_171 . V_13 )
V_162 -> V_162 [ 31 ] = V_162 -> V_173 + 4 ;
* V_165 = V_162 -> V_173 + V_164 . V_174 +
V_164 . V_175 ;
return 1 ;
#ifdef F_4
case V_204 :
if ( ( V_162 -> V_162 [ V_3 . V_171 . V_13 ] & ( 1ull << V_3 . V_171 . V_12 ) ) == 0 )
* V_165 = V_162 -> V_173 + 4 + ( V_3 . V_171 . V_183 << 2 ) ;
else
* V_165 = V_162 -> V_173 + 8 ;
return 1 ;
case V_205 :
if ( ( V_162 -> V_162 [ V_3 . V_171 . V_13 ] & ( 1ull << ( V_3 . V_171 . V_12 + 32 ) ) ) == 0 )
* V_165 = V_162 -> V_173 + 4 + ( V_3 . V_171 . V_183 << 2 ) ;
else
* V_165 = V_162 -> V_173 + 8 ;
return 1 ;
case V_206 :
if ( V_162 -> V_162 [ V_3 . V_171 . V_13 ] & ( 1ull << V_3 . V_171 . V_12 ) )
* V_165 = V_162 -> V_173 + 4 + ( V_3 . V_171 . V_183 << 2 ) ;
else
* V_165 = V_162 -> V_173 + 8 ;
return 1 ;
case V_207 :
if ( V_162 -> V_162 [ V_3 . V_171 . V_13 ] & ( 1ull << ( V_3 . V_171 . V_12 + 32 ) ) )
* V_165 = V_162 -> V_173 + 4 + ( V_3 . V_171 . V_183 << 2 ) ;
else
* V_165 = V_162 -> V_173 + 8 ;
return 1 ;
#else
case V_208 :
if ( ! V_199 )
break;
* V_165 = V_162 -> V_173 + V_164 . V_174 +
V_164 . V_175 ;
return 1 ;
case V_209 :
if ( ! V_199 )
break;
V_162 -> V_162 [ 31 ] = V_162 -> V_173 + 4 ;
* V_165 = V_162 -> V_173 + V_164 . V_174 +
V_164 . V_175 ;
return 1 ;
case V_210 :
if ( ! V_199 )
break;
* V_165 = V_162 -> V_173 + V_164 . V_174 +
V_164 . V_175 ;
return 1 ;
case V_211 :
if ( ! V_199 )
break;
if ( ! V_3 . V_171 . V_13 )
V_162 -> V_162 [ 31 ] = V_162 -> V_173 + 4 ;
* V_165 = V_162 -> V_173 + V_164 . V_174 +
V_164 . V_175 ;
return 1 ;
#endif
case V_212 :
case V_24 :
if ( V_199 &&
( ( V_3 . V_171 . V_13 == V_213 ) ||
( V_3 . V_171 . V_13 == V_214 ) ) ) {
V_167 = 0 ;
V_170 = & V_215 -> V_216 . V_217 . V_170 [ V_3 . V_171 . V_12 ] ;
V_168 = F_5 ( V_170 , 0 ) & 0x1 ;
switch ( V_3 . V_171 . V_13 ) {
case V_213 :
V_167 = V_168 == 0 ;
break;
case V_214 :
V_167 = V_168 != 0 ;
break;
}
if ( V_167 )
* V_165 = V_162 -> V_173 +
V_164 . V_174 +
( V_3 . V_171 . V_183 << 2 ) ;
else
* V_165 = V_162 -> V_173 +
V_164 . V_174 +
V_164 . V_175 ;
return 1 ;
}
case V_218 :
case V_48 :
if ( V_3 . V_171 . V_13 == V_26 ) {
F_6 () ;
if ( F_7 () )
V_166 = F_8 ( V_219 ) ;
else
V_166 = V_215 -> V_216 . V_217 . V_166 ;
F_9 () ;
V_167 = ( V_3 . V_171 . V_12 >> 2 ) ;
V_167 += ( V_167 != 0 ) ;
V_167 += 23 ;
switch ( V_3 . V_171 . V_12 & 3 ) {
case 0 :
case 2 :
if ( ~ V_166 & ( 1 << V_167 ) )
* V_165 = V_162 -> V_173 +
V_164 . V_174 +
( V_3 . V_171 . V_183 << 2 ) ;
else
* V_165 = V_162 -> V_173 +
V_164 . V_174 +
V_164 . V_175 ;
return 1 ;
case 1 :
case 3 :
if ( V_166 & ( 1 << V_167 ) )
* V_165 = V_162 -> V_173 +
V_164 . V_174 +
( V_3 . V_171 . V_183 << 2 ) ;
else
* V_165 = V_162 -> V_173 +
V_164 . V_174 +
V_164 . V_175 ;
return 1 ;
}
}
break;
}
return 0 ;
}
static inline int F_10 ( struct V_161 * V_220 )
{
if ( F_11 ( V_221 ) && ! F_11 ( V_222 ) )
return 1 ;
else if ( F_11 ( V_223 ) &&
! F_11 ( V_224 ) )
return 0 ;
return ! F_12 ( V_225 ) ;
}
static inline bool F_13 ( void )
{
return F_12 ( V_226 ) ;
}
static inline void F_14 ( struct V_161 * V_220 , struct V_227 * V_228 ,
V_1 V_229 )
{
T_1 V_166 = V_228 -> V_166 ;
T_1 V_230 = 0 ;
switch ( F_15 ( V_229 ) ) {
case V_231 :
V_230 = V_166 ;
F_16 ( L_1 ,
( void * ) V_220 -> V_173 , F_17 ( V_229 ) , V_230 ) ;
break;
case V_232 :
if ( ! V_233 )
break;
V_230 = ( V_166 >> ( V_234 - V_235 ) ) &
V_236 ;
V_230 |= V_166 & ( V_237 | V_238 ) ;
F_16 ( L_2 ,
( void * ) V_220 -> V_173 , F_17 ( V_229 ) , V_230 ) ;
break;
case V_239 :
if ( ! V_233 )
break;
V_230 = V_166 & ( V_240 | V_241 ) ;
F_16 ( L_3 ,
( void * ) V_220 -> V_173 , F_17 ( V_229 ) , V_230 ) ;
break;
case V_242 :
if ( ! V_233 )
break;
V_230 = ( V_166 >> ( V_243 - V_244 ) ) &
V_245 ;
V_230 |= ( V_166 >> ( V_246 - V_247 ) ) &
( V_248 & ~ V_245 ) ;
F_16 ( L_4 ,
( void * ) V_220 -> V_173 , F_17 ( V_229 ) , V_230 ) ;
break;
case V_249 :
V_230 = V_250 . V_251 ;
break;
default:
break;
}
if ( F_17 ( V_229 ) )
V_220 -> V_162 [ F_17 ( V_229 ) ] = V_230 ;
}
static inline void F_18 ( struct V_161 * V_220 , struct V_227 * V_228 ,
V_1 V_229 )
{
T_1 V_166 = V_228 -> V_166 ;
T_1 V_230 ;
T_1 V_252 ;
if ( F_17 ( V_229 ) == 0 )
V_230 = 0 ;
else
V_230 = V_220 -> V_162 [ F_17 ( V_229 ) ] ;
switch ( F_15 ( V_229 ) ) {
case V_231 :
F_16 ( L_5 ,
( void * ) V_220 -> V_173 , F_17 ( V_229 ) , V_230 ) ;
V_252 = V_250 . V_253 ;
V_166 = ( V_230 & ~ V_252 ) | ( V_166 & V_252 ) ;
break;
case V_232 :
if ( ! V_233 )
break;
F_16 ( L_6 ,
( void * ) V_220 -> V_173 , F_17 ( V_229 ) , V_230 ) ;
V_166 &= ~ ( V_254 | V_237 | V_238 ) ;
V_166 |= ( V_230 << ( V_234 - V_235 ) ) &
V_254 ;
V_166 |= V_230 & ( V_237 | V_238 ) ;
break;
case V_239 :
if ( ! V_233 )
break;
F_16 ( L_7 ,
( void * ) V_220 -> V_173 , F_17 ( V_229 ) , V_230 ) ;
V_166 &= ~ ( V_240 | V_241 ) ;
V_166 |= V_230 & ( V_240 | V_241 ) ;
break;
case V_242 :
if ( ! V_233 )
break;
F_16 ( L_8 ,
( void * ) V_220 -> V_173 , F_17 ( V_229 ) , V_230 ) ;
V_166 &= ~ ( V_255 | V_256 ) ;
V_166 |= ( V_230 << ( V_243 - V_244 ) ) &
V_256 ;
V_166 |= ( V_230 << ( V_246 - V_247 ) ) &
V_255 ;
break;
default:
break;
}
V_228 -> V_166 = V_166 ;
}
static int F_19 ( struct V_161 * V_220 , struct V_227 * V_228 ,
struct V_163 V_164 , void * T_2 * V_257 )
{
unsigned long V_165 = V_220 -> V_173 + V_164 . V_174 ;
unsigned int V_159 , V_258 , V_168 ;
V_1 V_229 ;
int V_259 , V_174 ;
union V_169 * V_170 ;
T_1 T_2 * V_260 ;
T_3 T_2 * V_261 ;
T_1 V_262 ;
T_3 V_263 ;
int V_264 ;
if ( ! V_265 && V_164 . V_266 )
F_20 () ;
if ( F_21 ( V_220 ) ) {
if ( V_164 . V_266 ) {
if ( ! F_22 ( V_220 , V_164 , & V_165 ) )
F_23 ( V_220 ) ;
} else {
if ( ! F_2 ( V_220 , V_164 , & V_165 ) )
F_23 ( V_220 ) ;
}
}
if ( F_21 ( V_220 ) ) {
V_229 = V_164 . V_267 ;
V_174 = V_164 . V_175 ;
} else {
V_229 = V_164 . V_3 ;
V_174 = V_164 . V_174 ;
}
if ( V_164 . V_266 ) {
if ( ( V_174 == 2 ) ||
( F_1 ( (union V_1 * ) & V_229 )
== V_28 ) )
return V_28 ;
}
V_268:
F_24 ( V_269 , 1 , V_220 , 0 ) ;
F_25 ( V_270 ) ;
switch ( F_26 ( V_229 ) ) {
case V_11 :
V_261 = ( T_3 T_2 * ) ( V_220 -> V_162 [ F_27 ( V_229 ) ] +
F_28 ( V_229 ) ) ;
F_25 ( V_271 ) ;
if ( ! F_29 ( V_272 , V_261 , sizeof( T_3 ) ) ) {
F_25 ( V_273 ) ;
* V_257 = V_261 ;
return V_274 ;
}
if ( F_30 ( V_263 , V_261 ) ) {
F_25 ( V_273 ) ;
* V_257 = V_261 ;
return V_275 ;
}
F_31 ( V_263 , F_17 ( V_229 ) ) ;
break;
case V_17 :
V_261 = ( T_3 T_2 * ) ( V_220 -> V_162 [ F_27 ( V_229 ) ] +
F_28 ( V_229 ) ) ;
F_25 ( V_276 ) ;
F_32 ( V_263 , F_17 ( V_229 ) ) ;
if ( ! F_29 ( V_277 , V_261 , sizeof( T_3 ) ) ) {
F_25 ( V_273 ) ;
* V_257 = V_261 ;
return V_274 ;
}
if ( F_33 ( V_263 , V_261 ) ) {
F_25 ( V_273 ) ;
* V_257 = V_261 ;
return V_275 ;
}
break;
case V_15 :
V_260 = ( T_1 T_2 * ) ( V_220 -> V_162 [ F_27 ( V_229 ) ] +
F_28 ( V_229 ) ) ;
F_25 ( V_271 ) ;
if ( ! F_29 ( V_272 , V_260 , sizeof( T_1 ) ) ) {
F_25 ( V_273 ) ;
* V_257 = V_260 ;
return V_274 ;
}
if ( F_30 ( V_262 , V_260 ) ) {
F_25 ( V_273 ) ;
* V_257 = V_260 ;
return V_275 ;
}
F_34 ( V_262 , F_17 ( V_229 ) ) ;
break;
case V_19 :
V_260 = ( T_1 T_2 * ) ( V_220 -> V_162 [ F_27 ( V_229 ) ] +
F_28 ( V_229 ) ) ;
F_25 ( V_276 ) ;
F_35 ( V_262 , F_17 ( V_229 ) ) ;
if ( ! F_29 ( V_277 , V_260 , sizeof( T_1 ) ) ) {
F_25 ( V_273 ) ;
* V_257 = V_260 ;
return V_274 ;
}
if ( F_33 ( V_262 , V_260 ) ) {
F_25 ( V_273 ) ;
* V_257 = V_260 ;
return V_275 ;
}
break;
case V_24 :
switch ( F_27 ( V_229 ) ) {
case V_278 :
if ( ! V_279 && ! V_280 )
return V_28 ;
if ( F_17 ( V_229 ) != 0 ) {
F_32 ( V_220 -> V_162 [ F_17 ( V_229 ) ] ,
F_15 ( V_229 ) ) ;
}
break;
case V_281 :
if ( ! V_279 && ! V_280 )
return V_28 ;
F_31 ( V_220 -> V_162 [ F_17 ( V_229 ) ] , F_15 ( V_229 ) ) ;
break;
case V_155 :
if ( ! V_282 )
return V_28 ;
if ( F_17 ( V_229 ) != 0 ) {
F_36 ( V_220 -> V_162 [ F_17 ( V_229 ) ] ,
F_15 ( V_229 ) ) ;
}
break;
case V_156 :
if ( ! V_282 )
return V_28 ;
F_37 ( V_220 -> V_162 [ F_17 ( V_229 ) ] , F_15 ( V_229 ) ) ;
break;
case V_151 :
if ( F_17 ( V_229 ) != 0 ) {
F_35 ( V_220 -> V_162 [ F_17 ( V_229 ) ] ,
F_15 ( V_229 ) ) ;
}
break;
case V_152 :
F_34 ( V_220 -> V_162 [ F_17 ( V_229 ) ] , F_15 ( V_229 ) ) ;
break;
case V_153 :
F_14 ( V_220 , V_228 , V_229 ) ;
break;
case V_154 :
F_18 ( V_220 , V_228 , V_229 ) ;
if ( ( V_228 -> V_166 >> 5 ) & V_228 -> V_166 & V_237 ) {
return V_283 ;
}
break;
case V_213 :
case V_214 :
if ( ! V_199 || F_21 ( V_220 ) )
return V_28 ;
V_159 = V_259 = 0 ;
V_170 = & V_215 -> V_216 . V_217 . V_170 [ F_17 ( V_229 ) ] ;
V_168 = F_5 ( V_170 , 0 ) & 0x1 ;
switch ( F_27 ( V_229 ) ) {
case V_213 :
V_159 = V_168 == 0 ;
break;
case V_214 :
V_159 = V_168 != 0 ;
break;
}
goto V_284;
case V_26 :
if ( F_21 ( V_220 ) )
return V_28 ;
if ( V_285 )
V_258 = V_286 [ F_17 ( V_229 ) >> 2 ] ;
else
V_258 = V_256 ;
V_159 = V_228 -> V_166 & V_258 ;
V_259 = 0 ;
switch ( F_17 ( V_229 ) & 3 ) {
case V_287 :
if ( V_288 )
V_259 = 1 ;
case V_289 :
V_159 = ! V_159 ;
break;
case V_290 :
if ( V_288 )
V_259 = 1 ;
case V_291 :
break;
}
V_284:
F_38 ( V_220 ) ;
if ( V_159 ) {
unsigned long V_292 ;
V_292 = V_220 -> V_173 ;
V_220 -> V_173 += V_164 . V_174 ;
V_165 = F_28 ( V_229 ) ;
V_229 = V_164 . V_267 ;
if ( V_164 . V_266 ) {
V_165 = ( V_220 -> V_173 + ( V_165 << 1 ) ) ;
if ( ( V_164 . V_175 == 2 ) ||
( F_1 ( (union V_1 * ) & V_229 ) == V_28 ) ) {
if ( V_164 . V_175 == 2 )
V_229 = ( V_229 & ( ~ 0xffff ) ) | V_293 ;
V_264 = F_39 ( V_220 , V_229 ,
V_292 , V_165 ) ;
if ( V_264 < 0 )
break;
if ( V_264 )
V_220 -> V_173 = V_292 ;
return V_264 ? V_264 : V_28 ;
}
} else
V_165 = ( V_220 -> V_173 + ( V_165 << 2 ) ) ;
switch ( F_26 ( V_229 ) ) {
case V_15 :
case V_19 :
goto V_268;
case V_11 :
case V_17 :
if ( V_288 )
goto V_268;
goto V_294;
case V_24 :
goto V_268;
case V_48 :
if ( V_295 )
goto V_268;
goto V_294;
case V_97 :
switch ( F_40 ( V_229 ) ) {
case V_99 :
if ( V_285 )
goto V_268;
goto V_294;
}
break;
V_294:
V_220 -> V_173 = V_292 ;
return V_28 ;
}
V_264 = F_39 ( V_220 , V_229 , V_292 , V_165 ) ;
if ( V_264 < 0 )
break;
if ( V_264 )
V_220 -> V_173 = V_292 ;
return V_264 ? V_264 : V_28 ;
} else if ( V_259 ) {
V_220 -> V_173 += V_164 . V_174 ;
V_165 += V_164 . V_174 ;
}
break;
default:
if ( ! ( F_27 ( V_229 ) & 0x10 ) )
return V_28 ;
if ( ( V_264 = F_41 ( V_220 , V_228 , V_229 ) ) )
return V_264 ;
}
break;
case V_48 :
if ( ! V_295 )
return V_28 ;
V_264 = F_42 ( V_220 , V_228 , V_229 , V_257 ) ;
if ( V_264 )
return V_264 ;
break;
case V_97 :
if ( ! V_285 )
return V_28 ;
if ( F_40 ( V_229 ) != V_99 )
return V_28 ;
V_159 = V_286 [ F_17 ( V_229 ) >> 2 ] ;
if ( ( ( V_228 -> V_166 & V_159 ) != 0 ) == ( ( F_17 ( V_229 ) & 1 ) != 0 ) )
V_220 -> V_162 [ F_15 ( V_229 ) ] =
V_220 -> V_162 [ F_27 ( V_229 ) ] ;
break;
default:
return V_28 ;
}
V_220 -> V_173 = V_165 ;
F_23 ( V_220 ) ;
return 0 ;
}
static union V_296 F_43 ( union V_296 V_297 )
{
return F_44 ( F_45 ( 0 ) , V_297 ) ;
}
static union V_296 F_46 ( union V_296 V_297 )
{
return F_44 ( F_45 ( 0 ) , F_47 ( V_297 ) ) ;
}
static union V_298 F_48 ( union V_298 V_299 )
{
return F_49 ( F_50 ( 0 ) , V_299 ) ;
}
static union V_298 F_51 ( union V_298 V_299 )
{
return F_49 ( F_50 ( 0 ) , F_52 ( V_299 ) ) ;
}
static int F_42 ( struct V_161 * V_220 , struct V_227 * V_228 ,
V_1 V_229 , void * T_2 * V_257 )
{
unsigned V_300 = 0 ;
F_25 ( V_301 ) ;
switch ( F_53 ( V_229 ) ) {
case V_302 : {
union V_298 ( * V_303 ) ( union V_298 , union V_298 , union V_298 ) ;
union V_298 V_53 , V_49 , V_52 , V_51 ;
T_1 T_2 * V_304 ;
T_1 V_305 ;
switch ( F_40 ( V_229 ) ) {
case V_61 :
V_304 = ( void T_2 * ) ( V_220 -> V_162 [ F_54 ( V_229 ) ] +
V_220 -> V_162 [ F_55 ( V_229 ) ] ) ;
F_25 ( V_271 ) ;
if ( ! F_29 ( V_272 , V_304 , sizeof( T_1 ) ) ) {
F_25 ( V_273 ) ;
* V_257 = V_304 ;
return V_274 ;
}
if ( F_30 ( V_305 , V_304 ) ) {
F_25 ( V_273 ) ;
* V_257 = V_304 ;
return V_275 ;
}
F_34 ( V_305 , F_56 ( V_229 ) ) ;
break;
case V_63 :
V_304 = ( void T_2 * ) ( V_220 -> V_162 [ F_54 ( V_229 ) ] +
V_220 -> V_162 [ F_55 ( V_229 ) ] ) ;
F_25 ( V_276 ) ;
F_35 ( V_305 , F_57 ( V_229 ) ) ;
if ( ! F_29 ( V_277 , V_304 , sizeof( T_1 ) ) ) {
F_25 ( V_273 ) ;
* V_257 = V_304 ;
return V_274 ;
}
if ( F_58 ( V_305 , V_304 ) ) {
F_25 ( V_273 ) ;
* V_257 = V_304 ;
return V_275 ;
}
break;
case V_39 :
V_303 = V_306 ;
goto V_307;
case V_43 :
V_303 = V_308 ;
goto V_307;
case V_41 :
V_303 = V_309 ;
goto V_307;
case V_45 :
V_303 = V_310 ;
goto V_307;
V_307:
F_59 ( V_49 , F_54 ( V_229 ) ) ;
F_59 ( V_52 , F_57 ( V_229 ) ) ;
F_59 ( V_51 , F_55 ( V_229 ) ) ;
V_53 = (* V_303) ( V_49 , V_52 , V_51 ) ;
F_60 ( V_53 , F_56 ( V_229 ) ) ;
V_311:
if ( F_61 ( V_312 ) ) {
F_25 ( V_313 ) ;
V_300 |= V_314 | V_315 ;
}
if ( F_61 ( V_316 ) ) {
F_25 ( V_317 ) ;
V_300 |= V_318 | V_319 ;
}
if ( F_61 ( V_320 ) ) {
F_25 ( V_321 ) ;
V_300 |= V_322 | V_323 ;
}
if ( F_61 ( V_324 ) ) {
F_25 ( V_325 ) ;
V_300 |= V_326 | V_327 ;
}
V_228 -> V_166 = ( V_228 -> V_166 & ~ V_240 ) | V_300 ;
if ( ( V_228 -> V_166 >> 5 ) & V_228 -> V_166 & V_237 ) {
return V_283 ;
}
break;
default:
return V_28 ;
}
break;
}
case V_328 : {
union V_296 ( * V_303 ) ( union V_296 , union V_296 , union V_296 ) ;
union V_296 V_53 , V_49 , V_52 , V_51 ;
T_3 T_2 * V_304 ;
T_3 V_305 ;
switch ( F_40 ( V_229 ) ) {
case V_57 :
V_304 = ( void T_2 * ) ( V_220 -> V_162 [ F_54 ( V_229 ) ] +
V_220 -> V_162 [ F_55 ( V_229 ) ] ) ;
F_25 ( V_271 ) ;
if ( ! F_29 ( V_272 , V_304 , sizeof( T_3 ) ) ) {
F_25 ( V_273 ) ;
* V_257 = V_304 ;
return V_274 ;
}
if ( F_30 ( V_305 , V_304 ) ) {
F_25 ( V_273 ) ;
* V_257 = V_304 ;
return V_275 ;
}
F_31 ( V_305 , F_56 ( V_229 ) ) ;
break;
case V_59 :
V_304 = ( void T_2 * ) ( V_220 -> V_162 [ F_54 ( V_229 ) ] +
V_220 -> V_162 [ F_55 ( V_229 ) ] ) ;
F_25 ( V_276 ) ;
F_32 ( V_305 , F_57 ( V_229 ) ) ;
if ( ! F_29 ( V_277 , V_304 , sizeof( T_3 ) ) ) {
F_25 ( V_273 ) ;
* V_257 = V_304 ;
return V_274 ;
}
if ( F_33 ( V_305 , V_304 ) ) {
F_25 ( V_273 ) ;
* V_257 = V_304 ;
return V_275 ;
}
break;
case V_40 :
V_303 = V_329 ;
goto V_330;
case V_44 :
V_303 = V_331 ;
goto V_330;
case V_42 :
V_303 = V_332 ;
goto V_330;
case V_46 :
V_303 = V_333 ;
goto V_330;
V_330:
F_62 ( V_49 , F_54 ( V_229 ) ) ;
F_62 ( V_52 , F_57 ( V_229 ) ) ;
F_62 ( V_51 , F_55 ( V_229 ) ) ;
V_53 = (* V_303) ( V_49 , V_52 , V_51 ) ;
F_63 ( V_53 , F_56 ( V_229 ) ) ;
goto V_311;
default:
return V_28 ;
}
break;
}
case 0x3 :
if ( F_40 ( V_229 ) != V_334 )
return V_28 ;
break;
default:
return V_28 ;
}
return 0 ;
}
static int F_41 ( struct V_161 * V_220 , struct V_227 * V_228 ,
V_1 V_229 )
{
int V_335 ;
unsigned V_300 = 0 ;
unsigned int V_336 ;
unsigned int V_258 ;
unsigned V_159 ;
union {
union V_296 V_297 ;
union V_298 V_299 ;
int V_337 ;
T_4 V_338 ;
} V_339 ;
T_3 V_340 ;
F_25 ( V_341 ) ;
switch ( V_335 = ( F_64 ( V_229 ) & 0xf ) ) {
case V_302 : {
union {
union V_298 ( * V_342 ) ( union V_298 , union V_298 ) ;
union V_298 ( * V_343 ) ( union V_298 ) ;
} V_303 ;
union V_298 V_53 , V_52 , V_51 ;
switch ( F_40 ( V_229 ) ) {
case V_79 :
V_303 . V_342 = V_344 ;
goto V_345;
case V_81 :
V_303 . V_342 = V_346 ;
goto V_345;
case V_83 :
V_303 . V_342 = V_347 ;
goto V_345;
case V_85 :
V_303 . V_342 = F_49 ;
goto V_345;
case V_143 :
if ( ! V_288 )
return V_28 ;
V_303 . V_343 = F_52 ;
goto V_348;
case V_142 :
if ( ! V_295 )
return V_28 ;
V_303 . V_343 = F_51 ;
goto V_348;
case V_144 :
if ( ! V_295 )
return V_28 ;
V_303 . V_343 = F_48 ;
goto V_348;
case V_76 :
if ( ! V_285 )
return V_28 ;
V_159 = V_286 [ F_55 ( V_229 ) >> 2 ] ;
if ( ( ( V_228 -> V_166 & V_159 ) != 0 ) !=
( ( F_55 ( V_229 ) & 1 ) != 0 ) )
return 0 ;
F_59 ( V_339 . V_299 , F_57 ( V_229 ) ) ;
break;
case V_90 :
if ( ! V_285 )
return V_28 ;
if ( V_220 -> V_162 [ F_55 ( V_229 ) ] != 0 )
return 0 ;
F_59 ( V_339 . V_299 , F_57 ( V_229 ) ) ;
break;
case V_88 :
if ( ! V_285 )
return V_28 ;
if ( V_220 -> V_162 [ F_55 ( V_229 ) ] == 0 )
return 0 ;
F_59 ( V_339 . V_299 , F_57 ( V_229 ) ) ;
break;
case V_349 :
if ( ! V_199 )
return V_28 ;
F_59 ( V_339 . V_299 , F_55 ( V_229 ) ) ;
if ( V_339 . V_337 & 0x1 )
V_339 . V_337 = 0 ;
else
F_59 ( V_339 . V_299 , F_57 ( V_229 ) ) ;
break;
case V_350 :
if ( ! V_199 )
return V_28 ;
F_59 ( V_339 . V_299 , F_55 ( V_229 ) ) ;
if ( V_339 . V_337 & 0x1 )
F_59 ( V_339 . V_299 , F_57 ( V_229 ) ) ;
else
V_339 . V_337 = 0 ;
break;
case V_351 : {
union V_298 V_51 , V_52 , V_53 ;
if ( ! V_199 )
return V_28 ;
F_59 ( V_51 , F_55 ( V_229 ) ) ;
F_59 ( V_52 , F_57 ( V_229 ) ) ;
F_59 ( V_53 , F_56 ( V_229 ) ) ;
V_339 . V_299 = F_65 ( V_53 , V_52 , V_51 ) ;
break;
}
case V_352 : {
union V_298 V_51 , V_52 , V_53 ;
if ( ! V_199 )
return V_28 ;
F_59 ( V_51 , F_55 ( V_229 ) ) ;
F_59 ( V_52 , F_57 ( V_229 ) ) ;
F_59 ( V_53 , F_56 ( V_229 ) ) ;
V_339 . V_299 = F_66 ( V_53 , V_52 , V_51 ) ;
break;
}
case V_353 : {
union V_298 V_52 ;
if ( ! V_199 )
return V_28 ;
F_59 ( V_52 , F_57 ( V_229 ) ) ;
V_339 . V_338 = F_67 ( V_52 ) ;
V_339 . V_299 = F_68 ( V_339 . V_338 ) ;
goto V_311;
}
case V_354 : {
union V_298 V_52 ;
if ( ! V_199 )
return V_28 ;
F_59 ( V_52 , F_57 ( V_229 ) ) ;
V_339 . V_337 = F_69 ( V_52 ) ;
V_335 = V_355 ;
break;
}
case V_356 : {
union V_298 V_52 , V_51 ;
if ( ! V_199 )
return V_28 ;
F_59 ( V_51 , F_55 ( V_229 ) ) ;
F_59 ( V_52 , F_57 ( V_229 ) ) ;
V_339 . V_299 = F_70 ( V_52 , V_51 ) ;
break;
}
case V_357 : {
union V_298 V_52 , V_51 ;
if ( ! V_199 )
return V_28 ;
F_59 ( V_51 , F_55 ( V_229 ) ) ;
F_59 ( V_52 , F_57 ( V_229 ) ) ;
V_339 . V_299 = F_71 ( V_52 , V_51 ) ;
break;
}
case V_358 : {
union V_298 V_52 , V_51 ;
if ( ! V_199 )
return V_28 ;
F_59 ( V_51 , F_55 ( V_229 ) ) ;
F_59 ( V_52 , F_57 ( V_229 ) ) ;
V_339 . V_299 = F_72 ( V_52 , V_51 ) ;
break;
}
case V_359 : {
union V_298 V_52 , V_51 ;
if ( ! V_199 )
return V_28 ;
F_59 ( V_51 , F_55 ( V_229 ) ) ;
F_59 ( V_52 , F_57 ( V_229 ) ) ;
V_339 . V_299 = F_73 ( V_52 , V_51 ) ;
break;
}
case V_116 :
V_303 . V_343 = V_360 ;
goto V_348;
case V_117 :
V_303 . V_343 = V_361 ;
goto V_348;
case V_115 :
F_59 ( V_339 . V_299 , F_57 ( V_229 ) ) ;
goto V_311;
V_345:
F_59 ( V_52 , F_57 ( V_229 ) ) ;
F_59 ( V_51 , F_55 ( V_229 ) ) ;
V_339 . V_299 = (* V_303 . V_342 ) ( V_52 , V_51 ) ;
goto V_311;
V_348:
F_59 ( V_52 , F_57 ( V_229 ) ) ;
V_339 . V_299 = (* V_303 . V_343 ) ( V_52 ) ;
goto V_311;
V_311:
if ( F_61 ( V_312 ) ) {
F_25 ( V_313 ) ;
V_300 |= V_314 | V_315 ;
}
if ( F_61 ( V_316 ) ) {
F_25 ( V_317 ) ;
V_300 |= V_318 | V_319 ;
}
if ( F_61 ( V_320 ) ) {
F_25 ( V_321 ) ;
V_300 |= V_322 | V_323 ;
}
if ( F_61 ( V_362 ) ) {
F_25 ( V_363 ) ;
V_300 |= V_364 | V_365 ;
}
if ( F_61 ( V_324 ) ) {
F_25 ( V_325 ) ;
V_300 |= V_326 | V_327 ;
}
break;
case V_107 :
return V_28 ;
case V_104 :
F_59 ( V_52 , F_57 ( V_229 ) ) ;
V_339 . V_297 = F_74 ( V_52 ) ;
V_335 = V_328 ;
goto V_311;
case V_137 :
F_59 ( V_52 , F_57 ( V_229 ) ) ;
V_339 . V_337 = F_75 ( V_52 ) ;
V_335 = V_355 ;
goto V_311;
case V_135 :
case V_133 :
case V_131 :
case V_129 :
if ( ! V_288 )
return V_28 ;
V_336 = V_366 . V_367 ;
F_59 ( V_52 , F_57 ( V_229 ) ) ;
V_366 . V_367 = F_40 ( V_229 ) ;
V_339 . V_337 = F_75 ( V_52 ) ;
V_366 . V_367 = V_336 ;
V_335 = V_355 ;
goto V_311;
case V_368 :
if ( ! V_199 )
return V_28 ;
F_59 ( V_53 , F_56 ( V_229 ) ) ;
if ( V_53 . V_340 & 0x1 )
F_59 ( V_339 . V_299 , F_55 ( V_229 ) ) ;
else
F_59 ( V_339 . V_299 , F_57 ( V_229 ) ) ;
break;
case V_136 :
if ( ! V_369 )
return V_28 ;
F_59 ( V_52 , F_57 ( V_229 ) ) ;
V_339 . V_338 = F_67 ( V_52 ) ;
V_335 = V_370 ;
goto V_311;
case V_134 :
case V_132 :
case V_130 :
case V_128 :
if ( ! V_369 )
return V_28 ;
V_336 = V_366 . V_367 ;
F_59 ( V_52 , F_57 ( V_229 ) ) ;
V_366 . V_367 = F_40 ( V_229 ) ;
V_339 . V_338 = F_67 ( V_52 ) ;
V_366 . V_367 = V_336 ;
V_335 = V_370 ;
goto V_311;
default:
if ( ! V_177 && F_40 ( V_229 ) >= V_371 ) {
unsigned V_372 = F_40 ( V_229 ) - V_371 ;
union V_298 V_52 , V_51 ;
F_59 ( V_52 , F_57 ( V_229 ) ) ;
F_59 ( V_51 , F_55 ( V_229 ) ) ;
V_339 . V_337 = F_76 ( V_52 , V_51 ,
V_373 [ V_372 & 0x7 ] , V_372 & 0x8 ) ;
V_335 = - 1 ;
if ( ( V_372 & 0x8 ) && F_61
( V_324 ) )
V_300 = V_326 | V_327 ;
else
goto V_311;
} else
return V_28 ;
break;
}
break;
}
case V_328 : {
union V_296 V_53 , V_52 , V_51 ;
union {
union V_296 ( * V_342 ) ( union V_296 , union V_296 ) ;
union V_296 ( * V_343 ) ( union V_296 ) ;
} V_303 ;
switch ( F_40 ( V_229 ) ) {
case V_79 :
V_303 . V_342 = V_374 ;
goto V_375;
case V_81 :
V_303 . V_342 = V_376 ;
goto V_375;
case V_83 :
V_303 . V_342 = V_377 ;
goto V_375;
case V_85 :
V_303 . V_342 = F_44 ;
goto V_375;
case V_143 :
if ( ! V_288 )
return V_28 ;
V_303 . V_343 = F_47 ;
goto V_378;
case V_142 :
if ( ! V_295 )
return V_28 ;
V_303 . V_343 = F_46 ;
goto V_378;
case V_144 :
if ( ! V_295 )
return V_28 ;
V_303 . V_343 = F_43 ;
goto V_378;
case V_76 :
if ( ! V_285 )
return V_28 ;
V_159 = V_286 [ F_55 ( V_229 ) >> 2 ] ;
if ( ( ( V_228 -> V_166 & V_159 ) != 0 ) !=
( ( F_55 ( V_229 ) & 1 ) != 0 ) )
return 0 ;
F_62 ( V_339 . V_297 , F_57 ( V_229 ) ) ;
break;
case V_90 :
if ( ! V_285 )
return V_28 ;
if ( V_220 -> V_162 [ F_55 ( V_229 ) ] != 0 )
return 0 ;
F_62 ( V_339 . V_297 , F_57 ( V_229 ) ) ;
break;
case V_88 :
if ( ! V_285 )
return V_28 ;
if ( V_220 -> V_162 [ F_55 ( V_229 ) ] == 0 )
return 0 ;
F_62 ( V_339 . V_297 , F_57 ( V_229 ) ) ;
break;
case V_349 :
if ( ! V_199 )
return V_28 ;
F_62 ( V_339 . V_297 , F_55 ( V_229 ) ) ;
if ( V_339 . V_338 & 0x1 )
V_339 . V_338 = 0 ;
else
F_62 ( V_339 . V_297 , F_57 ( V_229 ) ) ;
break;
case V_350 :
if ( ! V_199 )
return V_28 ;
F_62 ( V_339 . V_297 , F_55 ( V_229 ) ) ;
if ( V_339 . V_338 & 0x1 )
F_62 ( V_339 . V_297 , F_57 ( V_229 ) ) ;
else
V_339 . V_338 = 0 ;
break;
case V_351 : {
union V_296 V_51 , V_52 , V_53 ;
if ( ! V_199 )
return V_28 ;
F_62 ( V_51 , F_55 ( V_229 ) ) ;
F_62 ( V_52 , F_57 ( V_229 ) ) ;
F_62 ( V_53 , F_56 ( V_229 ) ) ;
V_339 . V_297 = F_77 ( V_53 , V_52 , V_51 ) ;
break;
}
case V_352 : {
union V_296 V_51 , V_52 , V_53 ;
if ( ! V_199 )
return V_28 ;
F_62 ( V_51 , F_55 ( V_229 ) ) ;
F_62 ( V_52 , F_57 ( V_229 ) ) ;
F_62 ( V_53 , F_56 ( V_229 ) ) ;
V_339 . V_297 = F_78 ( V_53 , V_52 , V_51 ) ;
break;
}
case V_353 : {
union V_296 V_52 ;
if ( ! V_199 )
return V_28 ;
F_62 ( V_52 , F_57 ( V_229 ) ) ;
V_339 . V_338 = F_79 ( V_52 ) ;
V_339 . V_297 = F_80 ( V_339 . V_338 ) ;
goto V_311;
}
case V_354 : {
union V_296 V_52 ;
if ( ! V_199 )
return V_28 ;
F_62 ( V_52 , F_57 ( V_229 ) ) ;
V_339 . V_337 = F_81 ( V_52 ) ;
V_335 = V_355 ;
break;
}
case V_356 : {
union V_296 V_52 , V_51 ;
if ( ! V_199 )
return V_28 ;
F_62 ( V_51 , F_55 ( V_229 ) ) ;
F_62 ( V_52 , F_57 ( V_229 ) ) ;
V_339 . V_297 = F_82 ( V_52 , V_51 ) ;
break;
}
case V_357 : {
union V_296 V_52 , V_51 ;
if ( ! V_199 )
return V_28 ;
F_62 ( V_51 , F_55 ( V_229 ) ) ;
F_62 ( V_52 , F_57 ( V_229 ) ) ;
V_339 . V_297 = F_83 ( V_52 , V_51 ) ;
break;
}
case V_358 : {
union V_296 V_52 , V_51 ;
if ( ! V_199 )
return V_28 ;
F_62 ( V_51 , F_55 ( V_229 ) ) ;
F_62 ( V_52 , F_57 ( V_229 ) ) ;
V_339 . V_297 = F_84 ( V_52 , V_51 ) ;
break;
}
case V_359 : {
union V_296 V_52 , V_51 ;
if ( ! V_199 )
return V_28 ;
F_62 ( V_51 , F_55 ( V_229 ) ) ;
F_62 ( V_52 , F_57 ( V_229 ) ) ;
V_339 . V_297 = F_85 ( V_52 , V_51 ) ;
break;
}
case V_116 :
V_303 . V_343 = V_379 ;
goto V_378;
case V_117 :
V_303 . V_343 = V_380 ;
goto V_378;
case V_115 :
F_62 ( V_339 . V_297 , F_57 ( V_229 ) ) ;
goto V_311;
V_375:
F_62 ( V_52 , F_57 ( V_229 ) ) ;
F_62 ( V_51 , F_55 ( V_229 ) ) ;
V_339 . V_297 = (* V_303 . V_342 ) ( V_52 , V_51 ) ;
goto V_311;
V_378:
F_62 ( V_52 , F_57 ( V_229 ) ) ;
V_339 . V_297 = (* V_303 . V_343 ) ( V_52 ) ;
goto V_311;
case V_107 :
F_62 ( V_52 , F_57 ( V_229 ) ) ;
V_339 . V_299 = F_86 ( V_52 ) ;
V_335 = V_302 ;
goto V_311;
case V_104 :
return V_28 ;
case V_137 :
F_62 ( V_52 , F_57 ( V_229 ) ) ;
V_339 . V_337 = F_87 ( V_52 ) ;
V_335 = V_355 ;
goto V_311;
case V_135 :
case V_133 :
case V_131 :
case V_129 :
if ( ! V_288 )
return V_28 ;
V_336 = V_366 . V_367 ;
F_62 ( V_52 , F_57 ( V_229 ) ) ;
V_366 . V_367 = F_40 ( V_229 ) ;
V_339 . V_337 = F_87 ( V_52 ) ;
V_366 . V_367 = V_336 ;
V_335 = V_355 ;
goto V_311;
case V_368 :
if ( ! V_199 )
return V_28 ;
F_62 ( V_53 , F_56 ( V_229 ) ) ;
if ( V_53 . V_340 & 0x1 )
F_62 ( V_339 . V_297 , F_55 ( V_229 ) ) ;
else
F_62 ( V_339 . V_297 , F_57 ( V_229 ) ) ;
break;
case V_136 :
if ( ! V_369 )
return V_28 ;
F_62 ( V_52 , F_57 ( V_229 ) ) ;
V_339 . V_338 = F_79 ( V_52 ) ;
V_335 = V_370 ;
goto V_311;
case V_134 :
case V_132 :
case V_130 :
case V_128 :
if ( ! V_369 )
return V_28 ;
V_336 = V_366 . V_367 ;
F_62 ( V_52 , F_57 ( V_229 ) ) ;
V_366 . V_367 = F_40 ( V_229 ) ;
V_339 . V_338 = F_79 ( V_52 ) ;
V_366 . V_367 = V_336 ;
V_335 = V_370 ;
goto V_311;
default:
if ( ! V_177 && F_40 ( V_229 ) >= V_371 ) {
unsigned V_372 = F_40 ( V_229 ) - V_371 ;
union V_296 V_52 , V_51 ;
F_62 ( V_52 , F_57 ( V_229 ) ) ;
F_62 ( V_51 , F_55 ( V_229 ) ) ;
V_339 . V_337 = F_88 ( V_52 , V_51 ,
V_373 [ V_372 & 0x7 ] , V_372 & 0x8 ) ;
V_335 = - 1 ;
if ( ( V_372 & 0x8 )
&&
F_61
( V_324 ) )
V_300 = V_326 | V_327 ;
else
goto V_311;
}
else {
return V_28 ;
}
break;
}
break;
}
case V_355 : {
union V_296 V_52 ;
switch ( F_40 ( V_229 ) ) {
case V_107 :
F_59 ( V_52 , F_57 ( V_229 ) ) ;
V_339 . V_299 = F_89 ( V_52 . V_340 ) ;
V_335 = V_302 ;
goto V_311;
case V_104 :
F_59 ( V_52 , F_57 ( V_229 ) ) ;
V_339 . V_297 = F_90 ( V_52 . V_340 ) ;
V_335 = V_328 ;
goto V_311;
default: {
#define F_91 0x7
#define F_92 (0x1 << 3)
#define F_93 (0x1 << 4)
int V_372 = F_40 ( V_229 ) & F_91 ;
int V_264 = F_40 ( V_229 ) & F_92 ;
union V_298 V_52 , V_51 ;
if ( ! V_199 ||
( F_40 ( V_229 ) & 0x20 ) )
return V_28 ;
V_335 = V_302 ;
V_339 . V_337 = 0 ;
F_59 ( V_52 , F_57 ( V_229 ) ) ;
F_59 ( V_51 , F_55 ( V_229 ) ) ;
if ( ! ( F_40 ( V_229 ) & F_93 ) ) {
if ( F_76 ( V_52 , V_51 , V_373 [ V_372 ] ,
V_264 ) )
V_339 . V_337 = - 1 ;
if ( ( V_264 ) &&
F_61 ( V_324 ) )
V_300 = V_326 | V_327 ;
else
goto V_311;
} else {
switch ( V_372 ) {
case 1 :
case 2 :
case 3 :
if ( F_76 ( V_52 , V_51 ,
V_381 [ V_372 ] ,
V_264 ) )
V_339 . V_337 = - 1 ;
if ( V_264 &&
F_61 ( V_324 ) )
V_300 = V_326 | V_327 ;
else
goto V_311;
break;
default:
F_94 ( L_9 ) ;
return V_28 ;
}
}
break;
}
}
}
case V_370 :
if ( ! V_369 )
return V_28 ;
F_32 ( V_340 , F_57 ( V_229 ) ) ;
switch ( F_40 ( V_229 ) ) {
case V_107 :
V_339 . V_299 = F_68 ( V_340 ) ;
V_335 = V_302 ;
goto V_311;
case V_104 :
V_339 . V_297 = F_80 ( V_340 ) ;
V_335 = V_328 ;
goto V_311;
default: {
int V_372 = F_40 ( V_229 ) & F_91 ;
int V_264 = F_40 ( V_229 ) & F_92 ;
union V_296 V_52 , V_51 ;
if ( ! V_199 ||
( F_40 ( V_229 ) & 0x20 ) )
return V_28 ;
V_335 = V_328 ;
V_339 . V_338 = 0 ;
F_62 ( V_52 , F_57 ( V_229 ) ) ;
F_62 ( V_51 , F_55 ( V_229 ) ) ;
if ( ! ( F_40 ( V_229 ) & F_93 ) ) {
if ( F_88 ( V_52 , V_51 ,
V_373 [ V_372 ] , V_264 ) )
V_339 . V_338 = - 1LL ;
if ( V_264 &&
F_61 ( V_324 ) )
V_300 = V_326 | V_327 ;
else
goto V_311;
} else {
switch ( V_372 ) {
case 1 :
case 2 :
case 3 :
if ( F_88 ( V_52 , V_51 ,
V_381 [ V_372 ] ,
V_264 ) )
V_339 . V_338 = - 1LL ;
if ( V_264 &&
F_61 ( V_324 ) )
V_300 = V_326 | V_327 ;
else
goto V_311;
break;
default:
F_94 ( L_10 ) ;
return V_28 ;
}
}
break;
}
}
default:
return V_28 ;
}
V_228 -> V_166 = ( V_228 -> V_166 & ~ V_240 ) | V_300 ;
if ( ( V_228 -> V_166 >> 5 ) & V_228 -> V_166 & V_237 ) {
return V_283 ;
}
switch ( V_335 ) {
case - 1 :
if ( V_285 )
V_258 = V_286 [ F_56 ( V_229 ) >> 2 ] ;
else
V_258 = V_256 ;
if ( V_339 . V_337 )
V_228 -> V_166 |= V_258 ;
else
V_228 -> V_166 &= ~ V_258 ;
break;
case V_328 :
F_63 ( V_339 . V_297 , F_56 ( V_229 ) ) ;
break;
case V_302 :
F_60 ( V_339 . V_299 , F_56 ( V_229 ) ) ;
break;
case V_355 :
F_34 ( V_339 . V_337 , F_56 ( V_229 ) ) ;
break;
case V_370 :
if ( ! V_369 )
return V_28 ;
F_31 ( V_339 . V_338 , F_56 ( V_229 ) ) ;
break;
default:
return V_28 ;
}
return 0 ;
}
int F_95 ( struct V_161 * V_220 , struct V_227 * V_228 ,
int V_382 , void * T_2 * V_257 )
{
unsigned long V_383 , V_384 ;
struct V_163 V_164 ;
T_5 V_385 [ 4 ] ;
T_5 * V_386 ;
int V_264 = 0 ;
V_383 = V_220 -> V_173 ;
do {
V_384 = V_220 -> V_173 ;
if ( F_96 ( V_384 ) && V_265 ) {
if ( ( F_97 ( V_385 [ 0 ] , ( T_5 T_2 * ) F_98 ( V_220 -> V_173 ) ) ) ||
( F_97 ( V_385 [ 1 ] , ( T_5 T_2 * ) F_98 ( V_220 -> V_173 + 2 ) ) ) ||
( F_97 ( V_385 [ 2 ] , ( T_5 T_2 * ) F_98 ( V_220 -> V_173 + 4 ) ) ) ||
( F_97 ( V_385 [ 3 ] , ( T_5 T_2 * ) F_98 ( V_220 -> V_173 + 6 ) ) ) ) {
F_25 ( V_273 ) ;
return V_274 ;
}
V_386 = V_385 ;
if ( F_99 ( * V_386 ) ) {
V_164 . V_3 = ( * V_386 << 16 ) |
( * V_386 ) ;
V_164 . V_174 = 2 ;
V_386 += 1 ;
} else {
V_164 . V_3 = ( * V_386 << 16 ) |
* ( V_386 + 1 ) ;
V_164 . V_174 = 4 ;
V_386 += 2 ;
}
if ( F_99 ( * V_386 ) ) {
V_164 . V_267 = ( * V_386 << 16 ) |
( * V_386 ) ;
V_164 . V_175 = 2 ;
} else {
V_164 . V_267 = ( * V_386 << 16 ) |
* ( V_386 + 1 ) ;
V_164 . V_175 = 4 ;
}
V_164 . V_266 = 1 ;
} else {
if ( ( F_97 ( V_164 . V_3 ,
( V_1 T_2 * ) V_220 -> V_173 ) ) ||
( F_97 ( V_164 . V_267 ,
( V_1 T_2 * ) ( V_220 -> V_173 + 4 ) ) ) ) {
F_25 ( V_273 ) ;
return V_274 ;
}
V_164 . V_174 = 4 ;
V_164 . V_175 = 4 ;
V_164 . V_266 = 0 ;
}
if ( ( V_164 . V_3 == 0 ) ||
( ( V_164 . V_174 == 2 ) &&
( ( V_164 . V_3 & 0xffff ) == V_293 ) ) )
V_220 -> V_173 += V_164 . V_174 ;
else {
V_264 = F_19 ( V_220 , V_228 , V_164 , V_257 ) ;
}
if ( V_382 )
break;
if ( V_264 )
break;
if ( ( V_220 -> V_173 ^ V_384 ) & 0x1 )
break;
F_100 () ;
} while ( V_220 -> V_173 > V_384 );
if ( V_264 == V_28 && V_220 -> V_173 != V_383 )
V_264 = 0 ;
return V_264 ;
}
