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
if ( V_174 && V_3 . V_64 . V_9 == V_173 )
break;
* V_165 = V_162 -> V_162 [ V_3 . V_64 . V_13 ] ;
return 1 ;
}
break;
case V_175 :
switch ( V_3 . V_168 . V_12 ) {
case V_176 :
case V_177 :
if ( V_174 && ( V_3 . V_168 . V_13 ||
V_3 . V_168 . V_12 == V_177 ) )
break;
V_162 -> V_162 [ 31 ] = V_162 -> V_170 +
V_164 . V_171 +
V_164 . V_172 ;
case V_178 :
if ( V_174 )
break;
case V_179 :
if ( ( long ) V_162 -> V_162 [ V_3 . V_168 . V_13 ] < 0 )
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
( V_3 . V_168 . V_180 << 2 ) ;
else
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
V_164 . V_172 ;
return 1 ;
case V_181 :
case V_182 :
if ( V_174 && ( V_3 . V_168 . V_13 ||
V_3 . V_168 . V_12 == V_182 ) )
break;
V_162 -> V_162 [ 31 ] = V_162 -> V_170 +
V_164 . V_171 +
V_164 . V_172 ;
case V_183 :
if ( V_174 )
break;
case V_184 :
if ( ( long ) V_162 -> V_162 [ V_3 . V_168 . V_13 ] >= 0 )
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
( V_3 . V_168 . V_180 << 2 ) ;
else
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
V_164 . V_172 ;
return 1 ;
}
break;
case V_185 :
F_3 ( V_167 ) ;
case V_186 :
V_162 -> V_162 [ 31 ] = V_162 -> V_170 +
V_164 . V_171 +
V_164 . V_172 ;
case V_187 :
* V_165 = V_162 -> V_170 + V_164 . V_171 ;
* V_165 >>= 28 ;
* V_165 <<= 28 ;
* V_165 |= ( V_3 . V_188 . V_189 << 2 ) ;
* V_165 ^= V_167 ;
return 1 ;
case V_190 :
if ( V_174 )
break;
case V_191 :
if ( V_162 -> V_162 [ V_3 . V_168 . V_13 ] ==
V_162 -> V_162 [ V_3 . V_168 . V_12 ] )
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
( V_3 . V_168 . V_180 << 2 ) ;
else
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
V_164 . V_172 ;
return 1 ;
case V_192 :
if ( V_174 )
break;
case V_193 :
if ( V_162 -> V_162 [ V_3 . V_168 . V_13 ] !=
V_162 -> V_162 [ V_3 . V_168 . V_12 ] )
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
( V_3 . V_168 . V_180 << 2 ) ;
else
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
V_164 . V_172 ;
return 1 ;
case V_194 :
if ( V_174 )
break;
case V_195 :
if ( V_196 && V_3 . V_168 . V_12 ) {
if ( ( V_3 . V_168 . V_9 == V_195 ) &&
( ( ! V_3 . V_168 . V_13 && V_3 . V_168 . V_12 ) ||
( V_3 . V_168 . V_13 == V_3 . V_168 . V_12 ) ) )
V_162 -> V_162 [ 31 ] = V_162 -> V_170 +
V_164 . V_171 ;
* V_165 = V_162 -> V_170 + V_164 . V_171 +
V_164 . V_172 ;
return 1 ;
}
if ( ( long ) V_162 -> V_162 [ V_3 . V_168 . V_13 ] <= 0 )
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
( V_3 . V_168 . V_180 << 2 ) ;
else
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
V_164 . V_172 ;
return 1 ;
case V_197 :
if ( V_174 )
break;
case V_198 :
if ( V_196 && V_3 . V_168 . V_12 ) {
if ( ( V_3 . V_168 . V_9 == V_195 ) &&
( ( ! V_3 . V_168 . V_13 && V_3 . V_168 . V_12 ) ||
( V_3 . V_168 . V_13 == V_3 . V_168 . V_12 ) ) )
V_162 -> V_162 [ 31 ] = V_162 -> V_170 +
V_164 . V_171 ;
* V_165 = V_162 -> V_170 + V_164 . V_171 +
V_164 . V_172 ;
return 1 ;
}
if ( ( long ) V_162 -> V_162 [ V_3 . V_168 . V_13 ] > 0 )
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
( V_3 . V_168 . V_180 << 2 ) ;
else
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
V_164 . V_172 ;
return 1 ;
case V_199 :
case V_200 :
if ( ! V_196 )
break;
if ( V_3 . V_168 . V_12 && ! V_3 . V_168 . V_13 )
V_162 -> V_162 [ 31 ] = V_162 -> V_170 + 4 ;
* V_165 = V_162 -> V_170 + V_164 . V_171 +
V_164 . V_172 ;
return 1 ;
#ifdef F_4
case V_201 :
if ( ( V_162 -> V_162 [ V_3 . V_168 . V_13 ] & ( 1ull << V_3 . V_168 . V_12 ) ) == 0 )
* V_165 = V_162 -> V_170 + 4 + ( V_3 . V_168 . V_180 << 2 ) ;
else
* V_165 = V_162 -> V_170 + 8 ;
return 1 ;
case V_202 :
if ( ( V_162 -> V_162 [ V_3 . V_168 . V_13 ] & ( 1ull << ( V_3 . V_168 . V_12 + 32 ) ) ) == 0 )
* V_165 = V_162 -> V_170 + 4 + ( V_3 . V_168 . V_180 << 2 ) ;
else
* V_165 = V_162 -> V_170 + 8 ;
return 1 ;
case V_203 :
if ( V_162 -> V_162 [ V_3 . V_168 . V_13 ] & ( 1ull << V_3 . V_168 . V_12 ) )
* V_165 = V_162 -> V_170 + 4 + ( V_3 . V_168 . V_180 << 2 ) ;
else
* V_165 = V_162 -> V_170 + 8 ;
return 1 ;
case V_204 :
if ( V_162 -> V_162 [ V_3 . V_168 . V_13 ] & ( 1ull << ( V_3 . V_168 . V_12 + 32 ) ) )
* V_165 = V_162 -> V_170 + 4 + ( V_3 . V_168 . V_180 << 2 ) ;
else
* V_165 = V_162 -> V_170 + 8 ;
return 1 ;
#else
case V_205 :
if ( ! V_196 )
break;
* V_165 = V_162 -> V_170 + V_164 . V_171 +
V_164 . V_172 ;
return 1 ;
case V_206 :
if ( ! V_196 )
break;
V_162 -> V_162 [ 31 ] = V_162 -> V_170 + 4 ;
* V_165 = V_162 -> V_170 + V_164 . V_171 +
V_164 . V_172 ;
return 1 ;
case V_207 :
if ( ! V_196 )
break;
* V_165 = V_162 -> V_170 + V_164 . V_171 +
V_164 . V_172 ;
return 1 ;
case V_208 :
if ( ! V_196 )
break;
if ( ! V_3 . V_168 . V_13 )
V_162 -> V_162 [ 31 ] = V_162 -> V_170 + 4 ;
* V_165 = V_162 -> V_170 + V_164 . V_171 +
V_164 . V_172 ;
return 1 ;
#endif
case V_209 :
case V_24 :
if ( V_196 &&
( ( V_3 . V_168 . V_13 == V_210 ) ||
( V_3 . V_168 . V_13 == V_211 ) ) ) {
V_167 = 0 ;
switch ( V_3 . V_168 . V_13 ) {
case V_210 :
if ( F_5 ( & V_212 -> V_213 . V_214 . V_215 [ V_3 . V_168 . V_12 ] , 0 ) & 0x1 )
V_167 = 1 ;
break;
case V_211 :
if ( ! ( F_5 ( & V_212 -> V_213 . V_214 . V_215 [ V_3 . V_168 . V_12 ] , 0 ) & 0x1 ) )
V_167 = 1 ;
break;
}
if ( V_167 )
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
( V_3 . V_168 . V_180 << 2 ) ;
else
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
V_164 . V_172 ;
return 1 ;
}
case V_216 :
case V_48 :
if ( V_3 . V_168 . V_13 == V_26 ) {
F_6 () ;
if ( F_7 () )
V_166 = F_8 ( V_217 ) ;
else
V_166 = V_212 -> V_213 . V_214 . V_166 ;
F_9 () ;
V_167 = ( V_3 . V_168 . V_12 >> 2 ) ;
V_167 += ( V_167 != 0 ) ;
V_167 += 23 ;
switch ( V_3 . V_168 . V_12 & 3 ) {
case 0 :
case 2 :
if ( ~ V_166 & ( 1 << V_167 ) )
* V_165 = V_162 -> V_170 +
V_164 . V_171 +
( V_3 . V_168 . V_180 << 2 ) ;
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
( V_3 . V_168 . V_180 << 2 ) ;
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
static inline int F_10 ( struct V_161 * V_218 )
{
if ( F_11 ( V_219 ) && ! F_11 ( V_220 ) )
return 1 ;
else if ( F_11 ( V_221 ) &&
! F_11 ( V_222 ) )
return 0 ;
return ! F_12 ( V_223 ) ;
}
static inline bool F_13 ( void )
{
return F_12 ( V_224 ) ;
}
static int F_14 ( struct V_161 * V_218 , struct V_225 * V_226 ,
struct V_163 V_164 , void * T_1 * V_227 )
{
unsigned long V_165 = V_218 -> V_170 + V_164 . V_171 ;
unsigned int V_159 , V_228 ;
V_1 V_229 ;
int V_230 , V_171 ;
T_2 T_1 * V_231 ;
T_3 T_1 * V_232 ;
T_2 V_233 ;
T_2 V_234 ;
T_3 V_235 ;
int V_236 ;
if ( ! V_237 && V_164 . V_238 )
F_15 () ;
if ( F_16 ( V_218 ) ) {
if ( V_164 . V_238 ) {
if ( ! F_17 ( V_218 , V_164 , & V_165 ) )
F_18 ( V_218 ) ;
} else {
if ( ! F_2 ( V_218 , V_164 , & V_165 ) )
F_18 ( V_218 ) ;
}
}
if ( F_16 ( V_218 ) ) {
V_229 = V_164 . V_239 ;
V_171 = V_164 . V_172 ;
} else {
V_229 = V_164 . V_3 ;
V_171 = V_164 . V_171 ;
}
if ( V_164 . V_238 ) {
if ( ( V_171 == 2 ) ||
( F_1 ( (union V_1 * ) & V_229 )
== V_28 ) )
return V_28 ;
}
V_240:
F_19 ( V_241 , 1 , V_218 , 0 ) ;
F_20 ( V_242 ) ;
switch ( F_21 ( V_229 ) ) {
case V_11 :
V_232 = ( T_3 T_1 * ) ( V_218 -> V_162 [ F_22 ( V_229 ) ] +
F_23 ( V_229 ) ) ;
F_20 ( V_243 ) ;
if ( ! F_24 ( V_244 , V_232 , sizeof( T_3 ) ) ) {
F_20 ( V_245 ) ;
* V_227 = V_232 ;
return V_246 ;
}
if ( F_25 ( V_235 , V_232 ) ) {
F_20 ( V_245 ) ;
* V_227 = V_232 ;
return V_247 ;
}
F_26 ( V_235 , F_27 ( V_229 ) ) ;
break;
case V_17 :
V_232 = ( T_3 T_1 * ) ( V_218 -> V_162 [ F_22 ( V_229 ) ] +
F_23 ( V_229 ) ) ;
F_20 ( V_248 ) ;
F_28 ( V_235 , F_27 ( V_229 ) ) ;
if ( ! F_24 ( V_249 , V_232 , sizeof( T_3 ) ) ) {
F_20 ( V_245 ) ;
* V_227 = V_232 ;
return V_246 ;
}
if ( F_29 ( V_235 , V_232 ) ) {
F_20 ( V_245 ) ;
* V_227 = V_232 ;
return V_247 ;
}
break;
case V_15 :
V_231 = ( T_2 T_1 * ) ( V_218 -> V_162 [ F_22 ( V_229 ) ] +
F_23 ( V_229 ) ) ;
F_20 ( V_243 ) ;
if ( ! F_24 ( V_244 , V_231 , sizeof( T_2 ) ) ) {
F_20 ( V_245 ) ;
* V_227 = V_231 ;
return V_246 ;
}
if ( F_25 ( V_234 , V_231 ) ) {
F_20 ( V_245 ) ;
* V_227 = V_231 ;
return V_247 ;
}
F_30 ( V_234 , F_27 ( V_229 ) ) ;
break;
case V_19 :
V_231 = ( T_2 T_1 * ) ( V_218 -> V_162 [ F_22 ( V_229 ) ] +
F_23 ( V_229 ) ) ;
F_20 ( V_248 ) ;
F_31 ( V_234 , F_27 ( V_229 ) ) ;
if ( ! F_24 ( V_249 , V_231 , sizeof( T_2 ) ) ) {
F_20 ( V_245 ) ;
* V_227 = V_231 ;
return V_246 ;
}
if ( F_29 ( V_234 , V_231 ) ) {
F_20 ( V_245 ) ;
* V_227 = V_231 ;
return V_247 ;
}
break;
case V_24 :
switch ( F_22 ( V_229 ) ) {
case V_250 :
if ( ! V_251 && ! V_252 )
return V_28 ;
if ( F_27 ( V_229 ) != 0 ) {
F_28 ( V_218 -> V_162 [ F_27 ( V_229 ) ] ,
F_32 ( V_229 ) ) ;
}
break;
case V_253 :
if ( ! V_251 && ! V_252 )
return V_28 ;
F_26 ( V_218 -> V_162 [ F_27 ( V_229 ) ] , F_32 ( V_229 ) ) ;
break;
case V_155 :
if ( ! V_254 )
goto V_255;
if ( F_27 ( V_229 ) != 0 ) {
F_33 ( V_218 -> V_162 [ F_27 ( V_229 ) ] ,
F_32 ( V_229 ) ) ;
}
break;
case V_156 :
if ( ! V_254 )
goto V_255;
F_34 ( V_218 -> V_162 [ F_27 ( V_229 ) ] , F_32 ( V_229 ) ) ;
break;
case V_151 :
if ( F_27 ( V_229 ) != 0 ) {
F_31 ( V_218 -> V_162 [ F_27 ( V_229 ) ] ,
F_32 ( V_229 ) ) ;
}
break;
case V_152 :
F_30 ( V_218 -> V_162 [ F_27 ( V_229 ) ] , F_32 ( V_229 ) ) ;
break;
case V_153 :
if ( F_32 ( V_229 ) == V_256 ) {
V_233 = V_226 -> V_166 ;
V_233 = ( V_233 & ~ V_257 ) | F_35 ( V_233 ) ;
F_36 ( L_1 ,
( void * ) ( V_218 -> V_170 ) ,
F_27 ( V_229 ) , V_233 ) ;
}
else if ( F_32 ( V_229 ) == V_258 )
V_233 = 0 ;
else
V_233 = 0 ;
if ( F_27 ( V_229 ) )
V_218 -> V_162 [ F_27 ( V_229 ) ] = V_233 ;
break;
case V_154 :
if ( F_27 ( V_229 ) == 0 )
V_233 = 0 ;
else
V_233 = V_218 -> V_162 [ F_27 ( V_229 ) ] ;
if ( F_32 ( V_229 ) == V_256 ) {
F_36 ( L_2 ,
( void * ) ( V_218 -> V_170 ) ,
F_27 ( V_229 ) , V_233 ) ;
V_226 -> V_166 = ( V_233 & ~ ( V_259 | V_257 ) ) |
F_35 ( V_233 ) ;
}
if ( ( V_226 -> V_166 >> 5 ) & V_226 -> V_166 & V_260 ) {
return V_261 ;
}
break;
case V_26 :
if ( F_16 ( V_218 ) )
return V_28 ;
if ( V_262 )
V_228 = V_263 [ F_27 ( V_229 ) >> 2 ] ;
else
V_228 = V_264 ;
V_159 = V_226 -> V_166 & V_228 ;
V_230 = 0 ;
switch ( F_27 ( V_229 ) & 3 ) {
case V_265 :
V_230 = 1 ;
case V_266 :
V_159 = ! V_159 ;
break;
case V_267 :
V_230 = 1 ;
case V_268 :
break;
default:
return V_28 ;
}
F_37 ( V_218 ) ;
if ( V_159 ) {
V_218 -> V_170 += V_164 . V_171 ;
V_165 = F_23 ( V_229 ) ;
V_229 = V_164 . V_239 ;
if ( V_164 . V_238 ) {
V_165 = ( V_218 -> V_170 + ( V_165 << 1 ) ) ;
if ( ( V_164 . V_172 == 2 ) ||
( F_1 ( (union V_1 * ) & V_229 ) == V_28 ) ) {
if ( V_164 . V_172 == 2 )
V_229 = ( V_229 & ( ~ 0xffff ) ) | V_269 ;
return F_38 ( V_218 , V_229 , V_165 ) ;
}
} else
V_165 = ( V_218 -> V_170 + ( V_165 << 2 ) ) ;
switch ( F_21 ( V_229 ) ) {
case V_15 :
goto V_240;
case V_19 :
goto V_240;
case V_11 :
case V_17 :
if ( V_270 ||
V_252 )
goto V_240;
return V_28 ;
goto V_240;
case V_24 :
goto V_240;
case V_48 :
if ( V_271 || V_252 || V_272 )
goto V_240;
return V_28 ;
case V_97 :
if ( ! V_262 )
return V_28 ;
if ( F_39 ( V_229 ) == V_99 )
goto V_240;
break;
}
return F_38 ( V_218 , V_229 , V_165 ) ;
} else if ( V_230 ) {
V_218 -> V_170 += V_164 . V_171 ;
V_165 += V_164 . V_171 ;
}
break;
default:
if ( ! ( F_22 ( V_229 ) & 0x10 ) )
return V_28 ;
if ( ( V_236 = F_40 ( V_218 , V_226 , V_229 ) ) )
return V_236 ;
}
break;
case V_48 :
if ( ! V_271 && ! V_252 && ! V_272 )
return V_28 ;
V_236 = F_41 ( V_218 , V_226 , V_229 , V_227 ) ;
if ( V_236 )
return V_236 ;
break;
case V_97 :
if ( ! V_262 )
return V_28 ;
if ( F_39 ( V_229 ) != V_99 )
return V_28 ;
V_159 = V_263 [ F_27 ( V_229 ) >> 2 ] ;
if ( ( ( V_226 -> V_166 & V_159 ) != 0 ) == ( ( F_27 ( V_229 ) & 1 ) != 0 ) )
V_218 -> V_162 [ F_32 ( V_229 ) ] =
V_218 -> V_162 [ F_22 ( V_229 ) ] ;
break;
default:
V_255:
return V_28 ;
}
V_218 -> V_170 = V_165 ;
F_18 ( V_218 ) ;
return 0 ;
}
static union V_273 F_42 ( union V_273 V_274 )
{
return F_43 ( F_44 ( 0 ) , V_274 ) ;
}
static union V_273 F_45 ( union V_273 V_274 )
{
return F_43 ( F_44 ( 0 ) , F_46 ( V_274 ) ) ;
}
static union V_275 F_47 ( union V_275 V_276 )
{
return F_48 ( F_49 ( 0 ) , V_276 ) ;
}
static union V_275 F_50 ( union V_275 V_276 )
{
return F_48 ( F_49 ( 0 ) , F_51 ( V_276 ) ) ;
}
static int F_41 ( struct V_161 * V_218 , struct V_225 * V_226 ,
V_1 V_229 , void * T_1 * V_227 )
{
unsigned V_277 = 0 ;
F_20 ( V_278 ) ;
switch ( F_52 ( V_229 ) ) {
case V_279 : {
union V_275 ( * V_280 ) ( union V_275 , union V_275 , union V_275 ) ;
union V_275 V_53 , V_49 , V_52 , V_51 ;
T_2 T_1 * V_281 ;
T_2 V_282 ;
switch ( F_39 ( V_229 ) ) {
case V_61 :
V_281 = ( void T_1 * ) ( V_218 -> V_162 [ F_53 ( V_229 ) ] +
V_218 -> V_162 [ F_54 ( V_229 ) ] ) ;
F_20 ( V_243 ) ;
if ( ! F_24 ( V_244 , V_281 , sizeof( T_2 ) ) ) {
F_20 ( V_245 ) ;
* V_227 = V_281 ;
return V_246 ;
}
if ( F_25 ( V_282 , V_281 ) ) {
F_20 ( V_245 ) ;
* V_227 = V_281 ;
return V_247 ;
}
F_30 ( V_282 , F_55 ( V_229 ) ) ;
break;
case V_63 :
V_281 = ( void T_1 * ) ( V_218 -> V_162 [ F_53 ( V_229 ) ] +
V_218 -> V_162 [ F_54 ( V_229 ) ] ) ;
F_20 ( V_248 ) ;
F_31 ( V_282 , F_56 ( V_229 ) ) ;
if ( ! F_24 ( V_249 , V_281 , sizeof( T_2 ) ) ) {
F_20 ( V_245 ) ;
* V_227 = V_281 ;
return V_246 ;
}
if ( F_57 ( V_282 , V_281 ) ) {
F_20 ( V_245 ) ;
* V_227 = V_281 ;
return V_247 ;
}
break;
case V_39 :
V_280 = V_283 ;
goto V_284;
case V_43 :
V_280 = V_285 ;
goto V_284;
case V_41 :
V_280 = V_286 ;
goto V_284;
case V_45 :
V_280 = V_287 ;
goto V_284;
V_284:
F_58 ( V_49 , F_53 ( V_229 ) ) ;
F_58 ( V_52 , F_56 ( V_229 ) ) ;
F_58 ( V_51 , F_54 ( V_229 ) ) ;
V_53 = (* V_280) ( V_49 , V_52 , V_51 ) ;
F_59 ( V_53 , F_55 ( V_229 ) ) ;
V_288:
if ( F_60 ( V_289 ) ) {
F_20 ( V_290 ) ;
V_277 |= V_291 | V_292 ;
}
if ( F_60 ( V_293 ) ) {
F_20 ( V_294 ) ;
V_277 |= V_295 | V_296 ;
}
if ( F_60 ( V_297 ) ) {
F_20 ( V_298 ) ;
V_277 |= V_299 | V_300 ;
}
if ( F_60 ( V_301 ) ) {
F_20 ( V_302 ) ;
V_277 |= V_303 | V_304 ;
}
V_226 -> V_166 = ( V_226 -> V_166 & ~ V_305 ) | V_277 ;
if ( ( V_226 -> V_166 >> 5 ) & V_226 -> V_166 & V_260 ) {
return V_261 ;
}
break;
default:
return V_28 ;
}
break;
}
case V_306 : {
union V_273 ( * V_280 ) ( union V_273 , union V_273 , union V_273 ) ;
union V_273 V_53 , V_49 , V_52 , V_51 ;
T_3 T_1 * V_281 ;
T_3 V_282 ;
switch ( F_39 ( V_229 ) ) {
case V_57 :
V_281 = ( void T_1 * ) ( V_218 -> V_162 [ F_53 ( V_229 ) ] +
V_218 -> V_162 [ F_54 ( V_229 ) ] ) ;
F_20 ( V_243 ) ;
if ( ! F_24 ( V_244 , V_281 , sizeof( T_3 ) ) ) {
F_20 ( V_245 ) ;
* V_227 = V_281 ;
return V_246 ;
}
if ( F_25 ( V_282 , V_281 ) ) {
F_20 ( V_245 ) ;
* V_227 = V_281 ;
return V_247 ;
}
F_26 ( V_282 , F_55 ( V_229 ) ) ;
break;
case V_59 :
V_281 = ( void T_1 * ) ( V_218 -> V_162 [ F_53 ( V_229 ) ] +
V_218 -> V_162 [ F_54 ( V_229 ) ] ) ;
F_20 ( V_248 ) ;
F_28 ( V_282 , F_56 ( V_229 ) ) ;
if ( ! F_24 ( V_249 , V_281 , sizeof( T_3 ) ) ) {
F_20 ( V_245 ) ;
* V_227 = V_281 ;
return V_246 ;
}
if ( F_29 ( V_282 , V_281 ) ) {
F_20 ( V_245 ) ;
* V_227 = V_281 ;
return V_247 ;
}
break;
case V_40 :
V_280 = V_307 ;
goto V_308;
case V_44 :
V_280 = V_309 ;
goto V_308;
case V_42 :
V_280 = V_310 ;
goto V_308;
case V_46 :
V_280 = V_311 ;
goto V_308;
V_308:
F_61 ( V_49 , F_53 ( V_229 ) ) ;
F_61 ( V_52 , F_56 ( V_229 ) ) ;
F_61 ( V_51 , F_54 ( V_229 ) ) ;
V_53 = (* V_280) ( V_49 , V_52 , V_51 ) ;
F_62 ( V_53 , F_55 ( V_229 ) ) ;
goto V_288;
default:
return V_28 ;
}
break;
}
case 0x3 :
if ( F_39 ( V_229 ) != V_312 )
return V_28 ;
break;
default:
return V_28 ;
}
return 0 ;
}
static int F_40 ( struct V_161 * V_218 , struct V_225 * V_226 ,
V_1 V_229 )
{
int V_313 ;
unsigned V_277 = 0 ;
unsigned int V_314 ;
unsigned int V_228 ;
unsigned V_159 ;
union {
union V_273 V_274 ;
union V_275 V_276 ;
int V_315 ;
T_4 V_316 ;
} V_317 ;
T_3 V_318 ;
F_20 ( V_319 ) ;
switch ( V_313 = ( F_63 ( V_229 ) & 0xf ) ) {
case V_279 : {
union {
union V_275 ( * V_320 ) ( union V_275 , union V_275 ) ;
union V_275 ( * V_321 ) ( union V_275 ) ;
} V_280 ;
union V_275 V_52 , V_51 ;
switch ( F_39 ( V_229 ) ) {
case V_79 :
V_280 . V_320 = V_322 ;
goto V_323;
case V_81 :
V_280 . V_320 = V_324 ;
goto V_323;
case V_83 :
V_280 . V_320 = V_325 ;
goto V_323;
case V_85 :
V_280 . V_320 = F_48 ;
goto V_323;
case V_143 :
if ( ! V_262 )
return V_28 ;
V_280 . V_321 = F_51 ;
goto V_326;
case V_142 :
if ( ! V_327 )
return V_28 ;
V_280 . V_321 = F_50 ;
goto V_326;
case V_144 :
if ( ! V_327 )
return V_28 ;
V_280 . V_321 = F_47 ;
goto V_326;
case V_76 :
if ( ! V_262 )
return V_28 ;
V_159 = V_263 [ F_54 ( V_229 ) >> 2 ] ;
if ( ( ( V_226 -> V_166 & V_159 ) != 0 ) !=
( ( F_54 ( V_229 ) & 1 ) != 0 ) )
return 0 ;
F_58 ( V_317 . V_276 , F_56 ( V_229 ) ) ;
break;
case V_90 :
if ( ! V_262 )
return V_28 ;
if ( V_218 -> V_162 [ F_54 ( V_229 ) ] != 0 )
return 0 ;
F_58 ( V_317 . V_276 , F_56 ( V_229 ) ) ;
break;
case V_88 :
if ( ! V_262 )
return V_28 ;
if ( V_218 -> V_162 [ F_54 ( V_229 ) ] == 0 )
return 0 ;
F_58 ( V_317 . V_276 , F_56 ( V_229 ) ) ;
break;
case V_116 :
V_280 . V_321 = V_328 ;
goto V_326;
case V_117 :
V_280 . V_321 = V_329 ;
goto V_326;
case V_115 :
F_58 ( V_317 . V_276 , F_56 ( V_229 ) ) ;
goto V_288;
V_323:
F_58 ( V_52 , F_56 ( V_229 ) ) ;
F_58 ( V_51 , F_54 ( V_229 ) ) ;
V_317 . V_276 = (* V_280 . V_320 ) ( V_52 , V_51 ) ;
goto V_288;
V_326:
F_58 ( V_52 , F_56 ( V_229 ) ) ;
V_317 . V_276 = (* V_280 . V_321 ) ( V_52 ) ;
goto V_288;
V_288:
if ( F_60 ( V_289 ) ) {
F_20 ( V_290 ) ;
V_277 |= V_291 | V_292 ;
}
if ( F_60 ( V_293 ) ) {
F_20 ( V_294 ) ;
V_277 |= V_295 | V_296 ;
}
if ( F_60 ( V_297 ) ) {
F_20 ( V_298 ) ;
V_277 |= V_299 | V_300 ;
}
if ( F_60 ( V_330 ) ) {
F_20 ( V_331 ) ;
V_277 |= V_332 | V_333 ;
}
if ( F_60 ( V_301 ) ) {
F_20 ( V_302 ) ;
V_277 |= V_303 | V_304 ;
}
break;
case V_107 :
return V_28 ;
case V_104 :
F_58 ( V_52 , F_56 ( V_229 ) ) ;
V_317 . V_274 = F_64 ( V_52 ) ;
V_313 = V_306 ;
goto V_288;
case V_137 :
F_58 ( V_52 , F_56 ( V_229 ) ) ;
V_317 . V_315 = F_65 ( V_52 ) ;
V_313 = V_334 ;
goto V_288;
case V_135 :
case V_133 :
case V_131 :
case V_129 :
if ( ! V_270 && ! V_252 )
return V_28 ;
V_314 = V_335 . V_336 ;
F_58 ( V_52 , F_56 ( V_229 ) ) ;
V_335 . V_336 = F_35 ( F_39 ( V_229 ) ) ;
V_317 . V_315 = F_65 ( V_52 ) ;
V_335 . V_336 = V_314 ;
V_313 = V_334 ;
goto V_288;
case V_136 :
if ( ! V_251 && ! V_252 )
return V_28 ;
F_58 ( V_52 , F_56 ( V_229 ) ) ;
V_317 . V_316 = F_66 ( V_52 ) ;
V_313 = V_337 ;
goto V_288;
case V_134 :
case V_132 :
case V_130 :
case V_128 :
if ( ! V_251 && ! V_252 )
return V_28 ;
V_314 = V_335 . V_336 ;
F_58 ( V_52 , F_56 ( V_229 ) ) ;
V_335 . V_336 = F_35 ( F_39 ( V_229 ) ) ;
V_317 . V_316 = F_66 ( V_52 ) ;
V_335 . V_336 = V_314 ;
V_313 = V_337 ;
goto V_288;
default:
if ( F_39 ( V_229 ) >= V_338 ) {
unsigned V_339 = F_39 ( V_229 ) - V_338 ;
union V_275 V_52 , V_51 ;
F_58 ( V_52 , F_56 ( V_229 ) ) ;
F_58 ( V_51 , F_54 ( V_229 ) ) ;
V_317 . V_315 = F_67 ( V_52 , V_51 ,
V_340 [ V_339 & 0x7 ] , V_339 & 0x8 ) ;
V_313 = - 1 ;
if ( ( V_339 & 0x8 ) && F_60
( V_301 ) )
V_277 = V_303 | V_304 ;
else
goto V_288;
} else
return V_28 ;
break;
}
break;
}
case V_306 : {
union V_273 V_52 , V_51 ;
union {
union V_273 ( * V_320 ) ( union V_273 , union V_273 ) ;
union V_273 ( * V_321 ) ( union V_273 ) ;
} V_280 ;
switch ( F_39 ( V_229 ) ) {
case V_79 :
V_280 . V_320 = V_341 ;
goto V_342;
case V_81 :
V_280 . V_320 = V_343 ;
goto V_342;
case V_83 :
V_280 . V_320 = V_344 ;
goto V_342;
case V_85 :
V_280 . V_320 = F_43 ;
goto V_342;
case V_143 :
if ( ! V_345 )
return V_28 ;
V_280 . V_321 = F_46 ;
goto V_346;
case V_142 :
if ( ! V_327 )
return V_28 ;
V_280 . V_321 = F_45 ;
goto V_346;
case V_144 :
if ( ! V_327 )
return V_28 ;
V_280 . V_321 = F_42 ;
goto V_346;
case V_76 :
if ( ! V_262 )
return V_28 ;
V_159 = V_263 [ F_54 ( V_229 ) >> 2 ] ;
if ( ( ( V_226 -> V_166 & V_159 ) != 0 ) !=
( ( F_54 ( V_229 ) & 1 ) != 0 ) )
return 0 ;
F_61 ( V_317 . V_274 , F_56 ( V_229 ) ) ;
break;
case V_90 :
if ( ! V_262 )
return V_28 ;
if ( V_218 -> V_162 [ F_54 ( V_229 ) ] != 0 )
return 0 ;
F_61 ( V_317 . V_274 , F_56 ( V_229 ) ) ;
break;
case V_88 :
if ( ! V_262 )
return V_28 ;
if ( V_218 -> V_162 [ F_54 ( V_229 ) ] == 0 )
return 0 ;
F_61 ( V_317 . V_274 , F_56 ( V_229 ) ) ;
break;
case V_116 :
V_280 . V_321 = V_347 ;
goto V_346;
case V_117 :
V_280 . V_321 = V_348 ;
goto V_346;
case V_115 :
F_61 ( V_317 . V_274 , F_56 ( V_229 ) ) ;
goto V_288;
V_342:
F_61 ( V_52 , F_56 ( V_229 ) ) ;
F_61 ( V_51 , F_54 ( V_229 ) ) ;
V_317 . V_274 = (* V_280 . V_320 ) ( V_52 , V_51 ) ;
goto V_288;
V_346:
F_61 ( V_52 , F_56 ( V_229 ) ) ;
V_317 . V_274 = (* V_280 . V_321 ) ( V_52 ) ;
goto V_288;
case V_107 :
F_61 ( V_52 , F_56 ( V_229 ) ) ;
V_317 . V_276 = F_68 ( V_52 ) ;
V_313 = V_279 ;
goto V_288;
case V_104 :
return V_28 ;
case V_137 :
F_61 ( V_52 , F_56 ( V_229 ) ) ;
V_317 . V_315 = F_69 ( V_52 ) ;
V_313 = V_334 ;
goto V_288;
case V_135 :
case V_133 :
case V_131 :
case V_129 :
if ( ! V_345 )
return V_28 ;
V_314 = V_335 . V_336 ;
F_61 ( V_52 , F_56 ( V_229 ) ) ;
V_335 . V_336 = F_35 ( F_39 ( V_229 ) ) ;
V_317 . V_315 = F_69 ( V_52 ) ;
V_335 . V_336 = V_314 ;
V_313 = V_334 ;
goto V_288;
case V_136 :
if ( ! V_251 && ! V_252 )
return V_28 ;
F_61 ( V_52 , F_56 ( V_229 ) ) ;
V_317 . V_316 = F_70 ( V_52 ) ;
V_313 = V_337 ;
goto V_288;
case V_134 :
case V_132 :
case V_130 :
case V_128 :
if ( ! V_251 && ! V_252 )
return V_28 ;
V_314 = V_335 . V_336 ;
F_61 ( V_52 , F_56 ( V_229 ) ) ;
V_335 . V_336 = F_35 ( F_39 ( V_229 ) ) ;
V_317 . V_316 = F_70 ( V_52 ) ;
V_335 . V_336 = V_314 ;
V_313 = V_337 ;
goto V_288;
default:
if ( F_39 ( V_229 ) >= V_338 ) {
unsigned V_339 = F_39 ( V_229 ) - V_338 ;
union V_273 V_52 , V_51 ;
F_61 ( V_52 , F_56 ( V_229 ) ) ;
F_61 ( V_51 , F_54 ( V_229 ) ) ;
V_317 . V_315 = F_71 ( V_52 , V_51 ,
V_340 [ V_339 & 0x7 ] , V_339 & 0x8 ) ;
V_313 = - 1 ;
if ( ( V_339 & 0x8 )
&&
F_60
( V_301 ) )
V_277 = V_303 | V_304 ;
else
goto V_288;
}
else {
return V_28 ;
}
break;
}
break;
case V_334 :
switch ( F_39 ( V_229 ) ) {
case V_107 :
F_58 ( V_52 , F_56 ( V_229 ) ) ;
V_317 . V_276 = F_72 ( V_52 . V_318 ) ;
V_313 = V_279 ;
goto V_288;
case V_104 :
F_58 ( V_52 , F_56 ( V_229 ) ) ;
V_317 . V_274 = F_73 ( V_52 . V_318 ) ;
V_313 = V_306 ;
goto V_288;
default:
return V_28 ;
}
break;
}
case V_337 :
if ( ! V_251 && ! V_252 )
return V_28 ;
F_28 ( V_318 , F_56 ( V_229 ) ) ;
switch ( F_39 ( V_229 ) ) {
case V_107 :
V_317 . V_276 = F_74 ( V_318 ) ;
V_313 = V_279 ;
goto V_288;
case V_104 :
V_317 . V_274 = F_75 ( V_318 ) ;
V_313 = V_306 ;
goto V_288;
default:
return V_28 ;
}
break;
default:
return V_28 ;
}
V_226 -> V_166 = ( V_226 -> V_166 & ~ V_305 ) | V_277 ;
if ( ( V_226 -> V_166 >> 5 ) & V_226 -> V_166 & V_260 ) {
return V_261 ;
}
switch ( V_313 ) {
case - 1 :
if ( V_262 )
V_228 = V_263 [ F_55 ( V_229 ) >> 2 ] ;
else
V_228 = V_264 ;
if ( V_317 . V_315 )
V_226 -> V_166 |= V_228 ;
else
V_226 -> V_166 &= ~ V_228 ;
break;
case V_306 :
F_62 ( V_317 . V_274 , F_55 ( V_229 ) ) ;
break;
case V_279 :
F_59 ( V_317 . V_276 , F_55 ( V_229 ) ) ;
break;
case V_334 :
F_30 ( V_317 . V_315 , F_55 ( V_229 ) ) ;
break;
case V_337 :
if ( ! V_251 && ! V_252 )
return V_28 ;
F_26 ( V_317 . V_316 , F_55 ( V_229 ) ) ;
break;
default:
return V_28 ;
}
return 0 ;
}
int F_76 ( struct V_161 * V_218 , struct V_225 * V_226 ,
int V_349 , void * T_1 * V_227 )
{
unsigned long V_350 , V_351 ;
struct V_163 V_164 ;
T_5 V_352 [ 4 ] ;
T_5 * V_353 ;
int V_236 = 0 ;
V_350 = V_218 -> V_170 ;
do {
V_351 = V_218 -> V_170 ;
if ( F_77 ( V_351 ) && V_237 ) {
if ( ( F_78 ( V_352 [ 0 ] , ( T_5 T_1 * ) F_79 ( V_218 -> V_170 ) ) ) ||
( F_78 ( V_352 [ 1 ] , ( T_5 T_1 * ) F_79 ( V_218 -> V_170 + 2 ) ) ) ||
( F_78 ( V_352 [ 2 ] , ( T_5 T_1 * ) F_79 ( V_218 -> V_170 + 4 ) ) ) ||
( F_78 ( V_352 [ 3 ] , ( T_5 T_1 * ) F_79 ( V_218 -> V_170 + 6 ) ) ) ) {
F_20 ( V_245 ) ;
return V_246 ;
}
V_353 = V_352 ;
if ( F_80 ( * V_353 ) ) {
V_164 . V_3 = ( * V_353 << 16 ) |
( * V_353 ) ;
V_164 . V_171 = 2 ;
V_353 += 1 ;
} else {
V_164 . V_3 = ( * V_353 << 16 ) |
* ( V_353 + 1 ) ;
V_164 . V_171 = 4 ;
V_353 += 2 ;
}
if ( F_80 ( * V_353 ) ) {
V_164 . V_239 = ( * V_353 << 16 ) |
( * V_353 ) ;
V_164 . V_172 = 2 ;
} else {
V_164 . V_239 = ( * V_353 << 16 ) |
* ( V_353 + 1 ) ;
V_164 . V_172 = 4 ;
}
V_164 . V_238 = 1 ;
} else {
if ( ( F_78 ( V_164 . V_3 ,
( V_1 T_1 * ) V_218 -> V_170 ) ) ||
( F_78 ( V_164 . V_239 ,
( V_1 T_1 * ) ( V_218 -> V_170 + 4 ) ) ) ) {
F_20 ( V_245 ) ;
return V_246 ;
}
V_164 . V_171 = 4 ;
V_164 . V_172 = 4 ;
V_164 . V_238 = 0 ;
}
if ( ( V_164 . V_3 == 0 ) ||
( ( V_164 . V_171 == 2 ) &&
( ( V_164 . V_3 & 0xffff ) == V_269 ) ) )
V_218 -> V_170 += V_164 . V_171 ;
else {
V_236 = F_14 ( V_218 , V_226 , V_164 , V_227 ) ;
}
if ( V_349 )
break;
if ( V_236 )
break;
F_81 () ;
} while ( V_218 -> V_170 > V_351 );
if ( V_236 == V_28 && V_218 -> V_170 != V_350 )
V_236 = 0 ;
return V_236 ;
}
