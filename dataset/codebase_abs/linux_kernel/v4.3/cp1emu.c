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
if ( V_174 && V_3 . V_64 . V_5 == V_173 )
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
if ( ! V_3 . V_168 . V_12 && V_174 )
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
if ( ! V_3 . V_168 . V_12 && V_174 )
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
static inline void F_14 ( struct V_161 * V_218 , struct V_225 * V_226 ,
V_1 V_227 )
{
T_1 V_166 = V_226 -> V_166 ;
T_1 V_228 = 0 ;
switch ( F_15 ( V_227 ) ) {
case V_229 :
V_228 = V_166 ;
F_16 ( L_1 ,
( void * ) V_218 -> V_170 , F_17 ( V_227 ) , V_228 ) ;
break;
case V_230 :
if ( ! V_231 )
break;
V_228 = ( V_166 >> ( V_232 - V_233 ) ) &
V_234 ;
V_228 |= V_166 & ( V_235 | V_236 ) ;
F_16 ( L_2 ,
( void * ) V_218 -> V_170 , F_17 ( V_227 ) , V_228 ) ;
break;
case V_237 :
if ( ! V_231 )
break;
V_228 = V_166 & ( V_238 | V_239 ) ;
F_16 ( L_3 ,
( void * ) V_218 -> V_170 , F_17 ( V_227 ) , V_228 ) ;
break;
case V_240 :
if ( ! V_231 )
break;
V_228 = ( V_166 >> ( V_241 - V_242 ) ) &
V_243 ;
V_228 |= ( V_166 >> ( V_244 - V_245 ) ) &
( V_246 & ~ V_243 ) ;
F_16 ( L_4 ,
( void * ) V_218 -> V_170 , F_17 ( V_227 ) , V_228 ) ;
break;
case V_247 :
V_228 = V_248 . V_249 ;
break;
default:
break;
}
if ( F_17 ( V_227 ) )
V_218 -> V_162 [ F_17 ( V_227 ) ] = V_228 ;
}
static inline void F_18 ( struct V_161 * V_218 , struct V_225 * V_226 ,
V_1 V_227 )
{
T_1 V_166 = V_226 -> V_166 ;
T_1 V_228 ;
T_1 V_250 ;
if ( F_17 ( V_227 ) == 0 )
V_228 = 0 ;
else
V_228 = V_218 -> V_162 [ F_17 ( V_227 ) ] ;
switch ( F_15 ( V_227 ) ) {
case V_229 :
F_16 ( L_5 ,
( void * ) V_218 -> V_170 , F_17 ( V_227 ) , V_228 ) ;
V_250 = V_248 . V_251 ;
V_166 = ( V_228 & ~ V_250 ) | ( V_166 & V_250 ) ;
break;
case V_230 :
if ( ! V_231 )
break;
F_16 ( L_6 ,
( void * ) V_218 -> V_170 , F_17 ( V_227 ) , V_228 ) ;
V_166 &= ~ ( V_252 | V_235 | V_236 ) ;
V_166 |= ( V_228 << ( V_232 - V_233 ) ) &
V_252 ;
V_166 |= V_228 & ( V_235 | V_236 ) ;
break;
case V_237 :
if ( ! V_231 )
break;
F_16 ( L_7 ,
( void * ) V_218 -> V_170 , F_17 ( V_227 ) , V_228 ) ;
V_166 &= ~ ( V_238 | V_239 ) ;
V_166 |= V_228 & ( V_238 | V_239 ) ;
break;
case V_240 :
if ( ! V_231 )
break;
F_16 ( L_8 ,
( void * ) V_218 -> V_170 , F_17 ( V_227 ) , V_228 ) ;
V_166 &= ~ ( V_253 | V_254 ) ;
V_166 |= ( V_228 << ( V_241 - V_242 ) ) &
V_254 ;
V_166 |= ( V_228 << ( V_244 - V_245 ) ) &
V_253 ;
break;
default:
break;
}
V_226 -> V_166 = V_166 ;
}
static int F_19 ( struct V_161 * V_218 , struct V_225 * V_226 ,
struct V_163 V_164 , void * T_2 * V_255 )
{
unsigned long V_165 = V_218 -> V_170 + V_164 . V_171 ;
unsigned int V_159 , V_256 ;
V_1 V_227 ;
int V_257 , V_171 ;
T_1 T_2 * V_258 ;
T_3 T_2 * V_259 ;
T_1 V_260 ;
T_3 V_261 ;
int V_262 ;
if ( ! V_263 && V_164 . V_264 )
F_20 () ;
if ( F_21 ( V_218 ) ) {
if ( V_164 . V_264 ) {
if ( ! F_22 ( V_218 , V_164 , & V_165 ) )
F_23 ( V_218 ) ;
} else {
if ( ! F_2 ( V_218 , V_164 , & V_165 ) )
F_23 ( V_218 ) ;
}
}
if ( F_21 ( V_218 ) ) {
V_227 = V_164 . V_265 ;
V_171 = V_164 . V_172 ;
} else {
V_227 = V_164 . V_3 ;
V_171 = V_164 . V_171 ;
}
if ( V_164 . V_264 ) {
if ( ( V_171 == 2 ) ||
( F_1 ( (union V_1 * ) & V_227 )
== V_28 ) )
return V_28 ;
}
V_266:
F_24 ( V_267 , 1 , V_218 , 0 ) ;
F_25 ( V_268 ) ;
switch ( F_26 ( V_227 ) ) {
case V_11 :
V_259 = ( T_3 T_2 * ) ( V_218 -> V_162 [ F_27 ( V_227 ) ] +
F_28 ( V_227 ) ) ;
F_25 ( V_269 ) ;
if ( ! F_29 ( V_270 , V_259 , sizeof( T_3 ) ) ) {
F_25 ( V_271 ) ;
* V_255 = V_259 ;
return V_272 ;
}
if ( F_30 ( V_261 , V_259 ) ) {
F_25 ( V_271 ) ;
* V_255 = V_259 ;
return V_273 ;
}
F_31 ( V_261 , F_17 ( V_227 ) ) ;
break;
case V_17 :
V_259 = ( T_3 T_2 * ) ( V_218 -> V_162 [ F_27 ( V_227 ) ] +
F_28 ( V_227 ) ) ;
F_25 ( V_274 ) ;
F_32 ( V_261 , F_17 ( V_227 ) ) ;
if ( ! F_29 ( V_275 , V_259 , sizeof( T_3 ) ) ) {
F_25 ( V_271 ) ;
* V_255 = V_259 ;
return V_272 ;
}
if ( F_33 ( V_261 , V_259 ) ) {
F_25 ( V_271 ) ;
* V_255 = V_259 ;
return V_273 ;
}
break;
case V_15 :
V_258 = ( T_1 T_2 * ) ( V_218 -> V_162 [ F_27 ( V_227 ) ] +
F_28 ( V_227 ) ) ;
F_25 ( V_269 ) ;
if ( ! F_29 ( V_270 , V_258 , sizeof( T_1 ) ) ) {
F_25 ( V_271 ) ;
* V_255 = V_258 ;
return V_272 ;
}
if ( F_30 ( V_260 , V_258 ) ) {
F_25 ( V_271 ) ;
* V_255 = V_258 ;
return V_273 ;
}
F_34 ( V_260 , F_17 ( V_227 ) ) ;
break;
case V_19 :
V_258 = ( T_1 T_2 * ) ( V_218 -> V_162 [ F_27 ( V_227 ) ] +
F_28 ( V_227 ) ) ;
F_25 ( V_274 ) ;
F_35 ( V_260 , F_17 ( V_227 ) ) ;
if ( ! F_29 ( V_275 , V_258 , sizeof( T_1 ) ) ) {
F_25 ( V_271 ) ;
* V_255 = V_258 ;
return V_272 ;
}
if ( F_33 ( V_260 , V_258 ) ) {
F_25 ( V_271 ) ;
* V_255 = V_258 ;
return V_273 ;
}
break;
case V_24 :
switch ( F_27 ( V_227 ) ) {
case V_276 :
if ( ! V_277 && ! V_278 )
return V_28 ;
if ( F_17 ( V_227 ) != 0 ) {
F_32 ( V_218 -> V_162 [ F_17 ( V_227 ) ] ,
F_15 ( V_227 ) ) ;
}
break;
case V_279 :
if ( ! V_277 && ! V_278 )
return V_28 ;
F_31 ( V_218 -> V_162 [ F_17 ( V_227 ) ] , F_15 ( V_227 ) ) ;
break;
case V_155 :
if ( ! V_280 )
goto V_281;
if ( F_17 ( V_227 ) != 0 ) {
F_36 ( V_218 -> V_162 [ F_17 ( V_227 ) ] ,
F_15 ( V_227 ) ) ;
}
break;
case V_156 :
if ( ! V_280 )
goto V_281;
F_37 ( V_218 -> V_162 [ F_17 ( V_227 ) ] , F_15 ( V_227 ) ) ;
break;
case V_151 :
if ( F_17 ( V_227 ) != 0 ) {
F_35 ( V_218 -> V_162 [ F_17 ( V_227 ) ] ,
F_15 ( V_227 ) ) ;
}
break;
case V_152 :
F_34 ( V_218 -> V_162 [ F_17 ( V_227 ) ] , F_15 ( V_227 ) ) ;
break;
case V_153 :
F_14 ( V_218 , V_226 , V_227 ) ;
break;
case V_154 :
F_18 ( V_218 , V_226 , V_227 ) ;
if ( ( V_226 -> V_166 >> 5 ) & V_226 -> V_166 & V_235 ) {
return V_282 ;
}
break;
case V_210 :
case V_211 :
if ( ! V_196 || F_21 ( V_218 ) )
return V_28 ;
V_159 = V_257 = 0 ;
switch ( F_27 ( V_227 ) ) {
case V_210 :
if ( F_5 ( & V_212 -> V_213 . V_214 . V_215 [ F_17 ( V_227 ) ] , 0 ) & 0x1 )
V_159 = 1 ;
break;
case V_211 :
if ( ! ( F_5 ( & V_212 -> V_213 . V_214 . V_215 [ F_17 ( V_227 ) ] , 0 ) & 0x1 ) )
V_159 = 1 ;
break;
}
goto V_283;
case V_26 :
if ( F_21 ( V_218 ) )
return V_28 ;
if ( V_284 )
V_256 = V_285 [ F_17 ( V_227 ) >> 2 ] ;
else
V_256 = V_254 ;
V_159 = V_226 -> V_166 & V_256 ;
V_257 = 0 ;
switch ( F_17 ( V_227 ) & 3 ) {
case V_286 :
if ( V_287 )
V_257 = 1 ;
case V_288 :
V_159 = ! V_159 ;
break;
case V_289 :
if ( V_287 )
V_257 = 1 ;
case V_290 :
break;
}
V_283:
F_38 ( V_218 ) ;
if ( V_159 ) {
unsigned long V_291 ;
V_291 = V_218 -> V_170 ;
V_218 -> V_170 += V_164 . V_171 ;
V_165 = F_28 ( V_227 ) ;
V_227 = V_164 . V_265 ;
if ( V_164 . V_264 ) {
V_165 = ( V_218 -> V_170 + ( V_165 << 1 ) ) ;
if ( ( V_164 . V_172 == 2 ) ||
( F_1 ( (union V_1 * ) & V_227 ) == V_28 ) ) {
if ( V_164 . V_172 == 2 )
V_227 = ( V_227 & ( ~ 0xffff ) ) | V_292 ;
V_262 = F_39 ( V_218 , V_227 ,
V_165 ) ;
if ( V_262 )
V_218 -> V_170 = V_291 ;
return V_262 ? V_262 : V_28 ;
}
} else
V_165 = ( V_218 -> V_170 + ( V_165 << 2 ) ) ;
switch ( F_26 ( V_227 ) ) {
case V_15 :
case V_19 :
goto V_266;
case V_11 :
case V_17 :
if ( V_287 )
goto V_266;
goto V_293;
case V_24 :
goto V_266;
case V_48 :
if ( V_294 )
goto V_266;
goto V_293;
case V_97 :
switch ( F_40 ( V_227 ) ) {
case V_99 :
if ( V_284 )
goto V_266;
goto V_293;
}
break;
V_293:
V_218 -> V_170 = V_291 ;
return V_28 ;
}
V_262 = F_39 ( V_218 , V_227 , V_165 ) ;
if ( V_262 )
V_218 -> V_170 = V_291 ;
return V_262 ? V_262 : V_28 ;
} else if ( V_257 ) {
V_218 -> V_170 += V_164 . V_171 ;
V_165 += V_164 . V_171 ;
}
break;
default:
if ( ! ( F_27 ( V_227 ) & 0x10 ) )
return V_28 ;
if ( ( V_262 = F_41 ( V_218 , V_226 , V_227 ) ) )
return V_262 ;
}
break;
case V_48 :
if ( ! V_294 )
return V_28 ;
V_262 = F_42 ( V_218 , V_226 , V_227 , V_255 ) ;
if ( V_262 )
return V_262 ;
break;
case V_97 :
if ( ! V_284 )
return V_28 ;
if ( F_40 ( V_227 ) != V_99 )
return V_28 ;
V_159 = V_285 [ F_17 ( V_227 ) >> 2 ] ;
if ( ( ( V_226 -> V_166 & V_159 ) != 0 ) == ( ( F_17 ( V_227 ) & 1 ) != 0 ) )
V_218 -> V_162 [ F_15 ( V_227 ) ] =
V_218 -> V_162 [ F_27 ( V_227 ) ] ;
break;
default:
V_281:
return V_28 ;
}
V_218 -> V_170 = V_165 ;
F_23 ( V_218 ) ;
return 0 ;
}
static union V_295 F_43 ( union V_295 V_296 )
{
return F_44 ( F_45 ( 0 ) , V_296 ) ;
}
static union V_295 F_46 ( union V_295 V_296 )
{
return F_44 ( F_45 ( 0 ) , F_47 ( V_296 ) ) ;
}
static union V_297 F_48 ( union V_297 V_298 )
{
return F_49 ( F_50 ( 0 ) , V_298 ) ;
}
static union V_297 F_51 ( union V_297 V_298 )
{
return F_49 ( F_50 ( 0 ) , F_52 ( V_298 ) ) ;
}
static int F_42 ( struct V_161 * V_218 , struct V_225 * V_226 ,
V_1 V_227 , void * T_2 * V_255 )
{
unsigned V_299 = 0 ;
F_25 ( V_300 ) ;
switch ( F_53 ( V_227 ) ) {
case V_301 : {
union V_297 ( * V_302 ) ( union V_297 , union V_297 , union V_297 ) ;
union V_297 V_53 , V_49 , V_52 , V_51 ;
T_1 T_2 * V_303 ;
T_1 V_304 ;
switch ( F_40 ( V_227 ) ) {
case V_61 :
V_303 = ( void T_2 * ) ( V_218 -> V_162 [ F_54 ( V_227 ) ] +
V_218 -> V_162 [ F_55 ( V_227 ) ] ) ;
F_25 ( V_269 ) ;
if ( ! F_29 ( V_270 , V_303 , sizeof( T_1 ) ) ) {
F_25 ( V_271 ) ;
* V_255 = V_303 ;
return V_272 ;
}
if ( F_30 ( V_304 , V_303 ) ) {
F_25 ( V_271 ) ;
* V_255 = V_303 ;
return V_273 ;
}
F_34 ( V_304 , F_56 ( V_227 ) ) ;
break;
case V_63 :
V_303 = ( void T_2 * ) ( V_218 -> V_162 [ F_54 ( V_227 ) ] +
V_218 -> V_162 [ F_55 ( V_227 ) ] ) ;
F_25 ( V_274 ) ;
F_35 ( V_304 , F_57 ( V_227 ) ) ;
if ( ! F_29 ( V_275 , V_303 , sizeof( T_1 ) ) ) {
F_25 ( V_271 ) ;
* V_255 = V_303 ;
return V_272 ;
}
if ( F_58 ( V_304 , V_303 ) ) {
F_25 ( V_271 ) ;
* V_255 = V_303 ;
return V_273 ;
}
break;
case V_39 :
V_302 = V_305 ;
goto V_306;
case V_43 :
V_302 = V_307 ;
goto V_306;
case V_41 :
V_302 = V_308 ;
goto V_306;
case V_45 :
V_302 = V_309 ;
goto V_306;
V_306:
F_59 ( V_49 , F_54 ( V_227 ) ) ;
F_59 ( V_52 , F_57 ( V_227 ) ) ;
F_59 ( V_51 , F_55 ( V_227 ) ) ;
V_53 = (* V_302) ( V_49 , V_52 , V_51 ) ;
F_60 ( V_53 , F_56 ( V_227 ) ) ;
V_310:
if ( F_61 ( V_311 ) ) {
F_25 ( V_312 ) ;
V_299 |= V_313 | V_314 ;
}
if ( F_61 ( V_315 ) ) {
F_25 ( V_316 ) ;
V_299 |= V_317 | V_318 ;
}
if ( F_61 ( V_319 ) ) {
F_25 ( V_320 ) ;
V_299 |= V_321 | V_322 ;
}
if ( F_61 ( V_323 ) ) {
F_25 ( V_324 ) ;
V_299 |= V_325 | V_326 ;
}
V_226 -> V_166 = ( V_226 -> V_166 & ~ V_238 ) | V_299 ;
if ( ( V_226 -> V_166 >> 5 ) & V_226 -> V_166 & V_235 ) {
return V_282 ;
}
break;
default:
return V_28 ;
}
break;
}
case V_327 : {
union V_295 ( * V_302 ) ( union V_295 , union V_295 , union V_295 ) ;
union V_295 V_53 , V_49 , V_52 , V_51 ;
T_3 T_2 * V_303 ;
T_3 V_304 ;
switch ( F_40 ( V_227 ) ) {
case V_57 :
V_303 = ( void T_2 * ) ( V_218 -> V_162 [ F_54 ( V_227 ) ] +
V_218 -> V_162 [ F_55 ( V_227 ) ] ) ;
F_25 ( V_269 ) ;
if ( ! F_29 ( V_270 , V_303 , sizeof( T_3 ) ) ) {
F_25 ( V_271 ) ;
* V_255 = V_303 ;
return V_272 ;
}
if ( F_30 ( V_304 , V_303 ) ) {
F_25 ( V_271 ) ;
* V_255 = V_303 ;
return V_273 ;
}
F_31 ( V_304 , F_56 ( V_227 ) ) ;
break;
case V_59 :
V_303 = ( void T_2 * ) ( V_218 -> V_162 [ F_54 ( V_227 ) ] +
V_218 -> V_162 [ F_55 ( V_227 ) ] ) ;
F_25 ( V_274 ) ;
F_32 ( V_304 , F_57 ( V_227 ) ) ;
if ( ! F_29 ( V_275 , V_303 , sizeof( T_3 ) ) ) {
F_25 ( V_271 ) ;
* V_255 = V_303 ;
return V_272 ;
}
if ( F_33 ( V_304 , V_303 ) ) {
F_25 ( V_271 ) ;
* V_255 = V_303 ;
return V_273 ;
}
break;
case V_40 :
V_302 = V_328 ;
goto V_329;
case V_44 :
V_302 = V_330 ;
goto V_329;
case V_42 :
V_302 = V_331 ;
goto V_329;
case V_46 :
V_302 = V_332 ;
goto V_329;
V_329:
F_62 ( V_49 , F_54 ( V_227 ) ) ;
F_62 ( V_52 , F_57 ( V_227 ) ) ;
F_62 ( V_51 , F_55 ( V_227 ) ) ;
V_53 = (* V_302) ( V_49 , V_52 , V_51 ) ;
F_63 ( V_53 , F_56 ( V_227 ) ) ;
goto V_310;
default:
return V_28 ;
}
break;
}
case 0x3 :
if ( F_40 ( V_227 ) != V_333 )
return V_28 ;
break;
default:
return V_28 ;
}
return 0 ;
}
static int F_41 ( struct V_161 * V_218 , struct V_225 * V_226 ,
V_1 V_227 )
{
int V_334 ;
unsigned V_299 = 0 ;
unsigned int V_335 ;
unsigned int V_256 ;
unsigned V_159 ;
union {
union V_295 V_296 ;
union V_297 V_298 ;
int V_336 ;
T_4 V_337 ;
} V_338 ;
T_3 V_339 ;
F_25 ( V_340 ) ;
switch ( V_334 = ( F_64 ( V_227 ) & 0xf ) ) {
case V_301 : {
union {
union V_297 ( * V_341 ) ( union V_297 , union V_297 ) ;
union V_297 ( * V_342 ) ( union V_297 ) ;
} V_302 ;
union V_297 V_52 , V_51 ;
switch ( F_40 ( V_227 ) ) {
case V_79 :
V_302 . V_341 = V_343 ;
goto V_344;
case V_81 :
V_302 . V_341 = V_345 ;
goto V_344;
case V_83 :
V_302 . V_341 = V_346 ;
goto V_344;
case V_85 :
V_302 . V_341 = F_49 ;
goto V_344;
case V_143 :
if ( ! V_287 )
return V_28 ;
V_302 . V_342 = F_52 ;
goto V_347;
case V_142 :
if ( ! V_294 )
return V_28 ;
V_302 . V_342 = F_51 ;
goto V_347;
case V_144 :
if ( ! V_294 )
return V_28 ;
V_302 . V_342 = F_48 ;
goto V_347;
case V_76 :
if ( ! V_284 )
return V_28 ;
V_159 = V_285 [ F_55 ( V_227 ) >> 2 ] ;
if ( ( ( V_226 -> V_166 & V_159 ) != 0 ) !=
( ( F_55 ( V_227 ) & 1 ) != 0 ) )
return 0 ;
F_59 ( V_338 . V_298 , F_57 ( V_227 ) ) ;
break;
case V_90 :
if ( ! V_284 )
return V_28 ;
if ( V_218 -> V_162 [ F_55 ( V_227 ) ] != 0 )
return 0 ;
F_59 ( V_338 . V_298 , F_57 ( V_227 ) ) ;
break;
case V_88 :
if ( ! V_284 )
return V_28 ;
if ( V_218 -> V_162 [ F_55 ( V_227 ) ] == 0 )
return 0 ;
F_59 ( V_338 . V_298 , F_57 ( V_227 ) ) ;
break;
case V_348 :
if ( ! V_196 )
return V_28 ;
F_59 ( V_338 . V_298 , F_55 ( V_227 ) ) ;
if ( V_338 . V_336 & 0x1 )
V_338 . V_336 = 0 ;
else
F_59 ( V_338 . V_298 , F_57 ( V_227 ) ) ;
break;
case V_349 :
if ( ! V_196 )
return V_28 ;
F_59 ( V_338 . V_298 , F_55 ( V_227 ) ) ;
if ( V_338 . V_336 & 0x1 )
F_59 ( V_338 . V_298 , F_57 ( V_227 ) ) ;
else
V_338 . V_336 = 0 ;
break;
case V_350 : {
union V_297 V_51 , V_52 , V_53 ;
if ( ! V_196 )
return V_28 ;
F_59 ( V_51 , F_55 ( V_227 ) ) ;
F_59 ( V_52 , F_57 ( V_227 ) ) ;
F_59 ( V_53 , F_56 ( V_227 ) ) ;
V_338 . V_298 = F_65 ( V_53 , V_52 , V_51 ) ;
break;
}
case V_351 : {
union V_297 V_51 , V_52 , V_53 ;
if ( ! V_196 )
return V_28 ;
F_59 ( V_51 , F_55 ( V_227 ) ) ;
F_59 ( V_52 , F_57 ( V_227 ) ) ;
F_59 ( V_53 , F_56 ( V_227 ) ) ;
V_338 . V_298 = F_66 ( V_53 , V_52 , V_51 ) ;
break;
}
case V_352 : {
union V_297 V_52 ;
if ( ! V_196 )
return V_28 ;
F_59 ( V_52 , F_57 ( V_227 ) ) ;
V_338 . V_337 = F_67 ( V_52 ) ;
V_338 . V_298 = F_68 ( V_338 . V_337 ) ;
goto V_310;
}
case V_353 : {
union V_297 V_52 ;
if ( ! V_196 )
return V_28 ;
F_59 ( V_52 , F_57 ( V_227 ) ) ;
V_338 . V_336 = F_69 ( V_52 ) ;
V_334 = V_354 ;
break;
}
case V_355 : {
union V_297 V_52 , V_51 ;
if ( ! V_196 )
return V_28 ;
F_59 ( V_51 , F_55 ( V_227 ) ) ;
F_59 ( V_52 , F_57 ( V_227 ) ) ;
V_338 . V_298 = F_70 ( V_52 , V_51 ) ;
break;
}
case V_356 : {
union V_297 V_52 , V_51 ;
if ( ! V_196 )
return V_28 ;
F_59 ( V_51 , F_55 ( V_227 ) ) ;
F_59 ( V_52 , F_57 ( V_227 ) ) ;
V_338 . V_298 = F_71 ( V_52 , V_51 ) ;
break;
}
case V_357 : {
union V_297 V_52 , V_51 ;
if ( ! V_196 )
return V_28 ;
F_59 ( V_51 , F_55 ( V_227 ) ) ;
F_59 ( V_52 , F_57 ( V_227 ) ) ;
V_338 . V_298 = F_72 ( V_52 , V_51 ) ;
break;
}
case V_358 : {
union V_297 V_52 , V_51 ;
if ( ! V_196 )
return V_28 ;
F_59 ( V_51 , F_55 ( V_227 ) ) ;
F_59 ( V_52 , F_57 ( V_227 ) ) ;
V_338 . V_298 = F_73 ( V_52 , V_51 ) ;
break;
}
case V_116 :
V_302 . V_342 = V_359 ;
goto V_347;
case V_117 :
V_302 . V_342 = V_360 ;
goto V_347;
case V_115 :
F_59 ( V_338 . V_298 , F_57 ( V_227 ) ) ;
goto V_310;
V_344:
F_59 ( V_52 , F_57 ( V_227 ) ) ;
F_59 ( V_51 , F_55 ( V_227 ) ) ;
V_338 . V_298 = (* V_302 . V_341 ) ( V_52 , V_51 ) ;
goto V_310;
V_347:
F_59 ( V_52 , F_57 ( V_227 ) ) ;
V_338 . V_298 = (* V_302 . V_342 ) ( V_52 ) ;
goto V_310;
V_310:
if ( F_61 ( V_311 ) ) {
F_25 ( V_312 ) ;
V_299 |= V_313 | V_314 ;
}
if ( F_61 ( V_315 ) ) {
F_25 ( V_316 ) ;
V_299 |= V_317 | V_318 ;
}
if ( F_61 ( V_319 ) ) {
F_25 ( V_320 ) ;
V_299 |= V_321 | V_322 ;
}
if ( F_61 ( V_361 ) ) {
F_25 ( V_362 ) ;
V_299 |= V_363 | V_364 ;
}
if ( F_61 ( V_323 ) ) {
F_25 ( V_324 ) ;
V_299 |= V_325 | V_326 ;
}
break;
case V_107 :
return V_28 ;
case V_104 :
F_59 ( V_52 , F_57 ( V_227 ) ) ;
V_338 . V_296 = F_74 ( V_52 ) ;
V_334 = V_327 ;
goto V_310;
case V_137 :
F_59 ( V_52 , F_57 ( V_227 ) ) ;
V_338 . V_336 = F_75 ( V_52 ) ;
V_334 = V_354 ;
goto V_310;
case V_135 :
case V_133 :
case V_131 :
case V_129 :
if ( ! V_287 )
return V_28 ;
V_335 = V_365 . V_366 ;
F_59 ( V_52 , F_57 ( V_227 ) ) ;
V_365 . V_366 = F_40 ( V_227 ) ;
V_338 . V_336 = F_75 ( V_52 ) ;
V_365 . V_366 = V_335 ;
V_334 = V_354 ;
goto V_310;
case V_136 :
if ( ! V_367 )
return V_28 ;
F_59 ( V_52 , F_57 ( V_227 ) ) ;
V_338 . V_337 = F_67 ( V_52 ) ;
V_334 = V_368 ;
goto V_310;
case V_134 :
case V_132 :
case V_130 :
case V_128 :
if ( ! V_367 )
return V_28 ;
V_335 = V_365 . V_366 ;
F_59 ( V_52 , F_57 ( V_227 ) ) ;
V_365 . V_366 = F_40 ( V_227 ) ;
V_338 . V_337 = F_67 ( V_52 ) ;
V_365 . V_366 = V_335 ;
V_334 = V_368 ;
goto V_310;
default:
if ( ! V_174 && F_40 ( V_227 ) >= V_369 ) {
unsigned V_370 = F_40 ( V_227 ) - V_369 ;
union V_297 V_52 , V_51 ;
F_59 ( V_52 , F_57 ( V_227 ) ) ;
F_59 ( V_51 , F_55 ( V_227 ) ) ;
V_338 . V_336 = F_76 ( V_52 , V_51 ,
V_371 [ V_370 & 0x7 ] , V_370 & 0x8 ) ;
V_334 = - 1 ;
if ( ( V_370 & 0x8 ) && F_61
( V_323 ) )
V_299 = V_325 | V_326 ;
else
goto V_310;
} else
return V_28 ;
break;
}
break;
}
case V_327 : {
union V_295 V_52 , V_51 ;
union {
union V_295 ( * V_341 ) ( union V_295 , union V_295 ) ;
union V_295 ( * V_342 ) ( union V_295 ) ;
} V_302 ;
switch ( F_40 ( V_227 ) ) {
case V_79 :
V_302 . V_341 = V_372 ;
goto V_373;
case V_81 :
V_302 . V_341 = V_374 ;
goto V_373;
case V_83 :
V_302 . V_341 = V_375 ;
goto V_373;
case V_85 :
V_302 . V_341 = F_44 ;
goto V_373;
case V_143 :
if ( ! V_287 )
return V_28 ;
V_302 . V_342 = F_47 ;
goto V_376;
case V_142 :
if ( ! V_294 )
return V_28 ;
V_302 . V_342 = F_46 ;
goto V_376;
case V_144 :
if ( ! V_294 )
return V_28 ;
V_302 . V_342 = F_43 ;
goto V_376;
case V_76 :
if ( ! V_284 )
return V_28 ;
V_159 = V_285 [ F_55 ( V_227 ) >> 2 ] ;
if ( ( ( V_226 -> V_166 & V_159 ) != 0 ) !=
( ( F_55 ( V_227 ) & 1 ) != 0 ) )
return 0 ;
F_62 ( V_338 . V_296 , F_57 ( V_227 ) ) ;
break;
case V_90 :
if ( ! V_284 )
return V_28 ;
if ( V_218 -> V_162 [ F_55 ( V_227 ) ] != 0 )
return 0 ;
F_62 ( V_338 . V_296 , F_57 ( V_227 ) ) ;
break;
case V_88 :
if ( ! V_284 )
return V_28 ;
if ( V_218 -> V_162 [ F_55 ( V_227 ) ] == 0 )
return 0 ;
F_62 ( V_338 . V_296 , F_57 ( V_227 ) ) ;
break;
case V_348 :
if ( ! V_196 )
return V_28 ;
F_62 ( V_338 . V_296 , F_55 ( V_227 ) ) ;
if ( V_338 . V_337 & 0x1 )
V_338 . V_337 = 0 ;
else
F_62 ( V_338 . V_296 , F_57 ( V_227 ) ) ;
break;
case V_349 :
if ( ! V_196 )
return V_28 ;
F_62 ( V_338 . V_296 , F_55 ( V_227 ) ) ;
if ( V_338 . V_337 & 0x1 )
F_62 ( V_338 . V_296 , F_57 ( V_227 ) ) ;
else
V_338 . V_337 = 0 ;
break;
case V_350 : {
union V_295 V_51 , V_52 , V_53 ;
if ( ! V_196 )
return V_28 ;
F_62 ( V_51 , F_55 ( V_227 ) ) ;
F_62 ( V_52 , F_57 ( V_227 ) ) ;
F_62 ( V_53 , F_56 ( V_227 ) ) ;
V_338 . V_296 = F_77 ( V_53 , V_52 , V_51 ) ;
break;
}
case V_351 : {
union V_295 V_51 , V_52 , V_53 ;
if ( ! V_196 )
return V_28 ;
F_62 ( V_51 , F_55 ( V_227 ) ) ;
F_62 ( V_52 , F_57 ( V_227 ) ) ;
F_62 ( V_53 , F_56 ( V_227 ) ) ;
V_338 . V_296 = F_78 ( V_53 , V_52 , V_51 ) ;
break;
}
case V_352 : {
union V_295 V_52 ;
if ( ! V_196 )
return V_28 ;
F_62 ( V_52 , F_57 ( V_227 ) ) ;
V_338 . V_337 = F_79 ( V_52 ) ;
V_338 . V_296 = F_80 ( V_338 . V_337 ) ;
goto V_310;
}
case V_353 : {
union V_295 V_52 ;
if ( ! V_196 )
return V_28 ;
F_62 ( V_52 , F_57 ( V_227 ) ) ;
V_338 . V_336 = F_81 ( V_52 ) ;
V_334 = V_354 ;
break;
}
case V_355 : {
union V_295 V_52 , V_51 ;
if ( ! V_196 )
return V_28 ;
F_62 ( V_51 , F_55 ( V_227 ) ) ;
F_62 ( V_52 , F_57 ( V_227 ) ) ;
V_338 . V_296 = F_82 ( V_52 , V_51 ) ;
break;
}
case V_356 : {
union V_295 V_52 , V_51 ;
if ( ! V_196 )
return V_28 ;
F_62 ( V_51 , F_55 ( V_227 ) ) ;
F_62 ( V_52 , F_57 ( V_227 ) ) ;
V_338 . V_296 = F_83 ( V_52 , V_51 ) ;
break;
}
case V_357 : {
union V_295 V_52 , V_51 ;
if ( ! V_196 )
return V_28 ;
F_62 ( V_51 , F_55 ( V_227 ) ) ;
F_62 ( V_52 , F_57 ( V_227 ) ) ;
V_338 . V_296 = F_84 ( V_52 , V_51 ) ;
break;
}
case V_358 : {
union V_295 V_52 , V_51 ;
if ( ! V_196 )
return V_28 ;
F_62 ( V_51 , F_55 ( V_227 ) ) ;
F_62 ( V_52 , F_57 ( V_227 ) ) ;
V_338 . V_296 = F_85 ( V_52 , V_51 ) ;
break;
}
case V_116 :
V_302 . V_342 = V_377 ;
goto V_376;
case V_117 :
V_302 . V_342 = V_378 ;
goto V_376;
case V_115 :
F_62 ( V_338 . V_296 , F_57 ( V_227 ) ) ;
goto V_310;
V_373:
F_62 ( V_52 , F_57 ( V_227 ) ) ;
F_62 ( V_51 , F_55 ( V_227 ) ) ;
V_338 . V_296 = (* V_302 . V_341 ) ( V_52 , V_51 ) ;
goto V_310;
V_376:
F_62 ( V_52 , F_57 ( V_227 ) ) ;
V_338 . V_296 = (* V_302 . V_342 ) ( V_52 ) ;
goto V_310;
case V_107 :
F_62 ( V_52 , F_57 ( V_227 ) ) ;
V_338 . V_298 = F_86 ( V_52 ) ;
V_334 = V_301 ;
goto V_310;
case V_104 :
return V_28 ;
case V_137 :
F_62 ( V_52 , F_57 ( V_227 ) ) ;
V_338 . V_336 = F_87 ( V_52 ) ;
V_334 = V_354 ;
goto V_310;
case V_135 :
case V_133 :
case V_131 :
case V_129 :
if ( ! V_287 )
return V_28 ;
V_335 = V_365 . V_366 ;
F_62 ( V_52 , F_57 ( V_227 ) ) ;
V_365 . V_366 = F_40 ( V_227 ) ;
V_338 . V_336 = F_87 ( V_52 ) ;
V_365 . V_366 = V_335 ;
V_334 = V_354 ;
goto V_310;
case V_136 :
if ( ! V_367 )
return V_28 ;
F_62 ( V_52 , F_57 ( V_227 ) ) ;
V_338 . V_337 = F_79 ( V_52 ) ;
V_334 = V_368 ;
goto V_310;
case V_134 :
case V_132 :
case V_130 :
case V_128 :
if ( ! V_367 )
return V_28 ;
V_335 = V_365 . V_366 ;
F_62 ( V_52 , F_57 ( V_227 ) ) ;
V_365 . V_366 = F_40 ( V_227 ) ;
V_338 . V_337 = F_79 ( V_52 ) ;
V_365 . V_366 = V_335 ;
V_334 = V_368 ;
goto V_310;
default:
if ( ! V_174 && F_40 ( V_227 ) >= V_369 ) {
unsigned V_370 = F_40 ( V_227 ) - V_369 ;
union V_295 V_52 , V_51 ;
F_62 ( V_52 , F_57 ( V_227 ) ) ;
F_62 ( V_51 , F_55 ( V_227 ) ) ;
V_338 . V_336 = F_88 ( V_52 , V_51 ,
V_371 [ V_370 & 0x7 ] , V_370 & 0x8 ) ;
V_334 = - 1 ;
if ( ( V_370 & 0x8 )
&&
F_61
( V_323 ) )
V_299 = V_325 | V_326 ;
else
goto V_310;
}
else {
return V_28 ;
}
break;
}
break;
}
case V_354 : {
union V_295 V_52 ;
switch ( F_40 ( V_227 ) ) {
case V_107 :
F_59 ( V_52 , F_57 ( V_227 ) ) ;
V_338 . V_298 = F_89 ( V_52 . V_339 ) ;
V_334 = V_301 ;
goto V_310;
case V_104 :
F_59 ( V_52 , F_57 ( V_227 ) ) ;
V_338 . V_296 = F_90 ( V_52 . V_339 ) ;
V_334 = V_327 ;
goto V_310;
default: {
#define F_91 0x7
#define F_92 (0x1 << 3)
#define F_93 (0x1 << 4)
int V_370 = F_40 ( V_227 ) & F_91 ;
int V_262 = F_40 ( V_227 ) & F_92 ;
union V_297 V_52 , V_51 ;
if ( ! V_196 ||
( F_40 ( V_227 ) & 0x20 ) )
return V_28 ;
V_334 = V_301 ;
V_338 . V_336 = 0 ;
F_59 ( V_52 , F_57 ( V_227 ) ) ;
F_59 ( V_51 , F_55 ( V_227 ) ) ;
if ( ! ( F_40 ( V_227 ) & F_93 ) ) {
if ( F_76 ( V_52 , V_51 , V_371 [ V_370 ] ,
V_262 ) )
V_338 . V_336 = - 1 ;
if ( ( V_262 ) &&
F_61 ( V_323 ) )
V_299 = V_325 | V_326 ;
else
goto V_310;
} else {
switch ( V_370 ) {
case 1 :
case 2 :
case 3 :
if ( F_76 ( V_52 , V_51 ,
V_379 [ V_370 ] ,
V_262 ) )
V_338 . V_336 = - 1 ;
if ( V_262 &&
F_61 ( V_323 ) )
V_299 = V_325 | V_326 ;
else
goto V_310;
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
case V_368 :
if ( ! V_367 )
return V_28 ;
F_32 ( V_339 , F_57 ( V_227 ) ) ;
switch ( F_40 ( V_227 ) ) {
case V_107 :
V_338 . V_298 = F_68 ( V_339 ) ;
V_334 = V_301 ;
goto V_310;
case V_104 :
V_338 . V_296 = F_80 ( V_339 ) ;
V_334 = V_327 ;
goto V_310;
default: {
int V_370 = F_40 ( V_227 ) & F_91 ;
int V_262 = F_40 ( V_227 ) & F_92 ;
union V_295 V_52 , V_51 ;
if ( ! V_196 ||
( F_40 ( V_227 ) & 0x20 ) )
return V_28 ;
V_334 = V_327 ;
V_338 . V_337 = 0 ;
F_62 ( V_52 , F_57 ( V_227 ) ) ;
F_62 ( V_51 , F_55 ( V_227 ) ) ;
if ( ! ( F_40 ( V_227 ) & F_93 ) ) {
if ( F_88 ( V_52 , V_51 ,
V_371 [ V_370 ] , V_262 ) )
V_338 . V_337 = - 1LL ;
if ( V_262 &&
F_61 ( V_323 ) )
V_299 = V_325 | V_326 ;
else
goto V_310;
} else {
switch ( V_370 ) {
case 1 :
case 2 :
case 3 :
if ( F_88 ( V_52 , V_51 ,
V_379 [ V_370 ] ,
V_262 ) )
V_338 . V_337 = - 1LL ;
if ( V_262 &&
F_61 ( V_323 ) )
V_299 = V_325 | V_326 ;
else
goto V_310;
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
V_226 -> V_166 = ( V_226 -> V_166 & ~ V_238 ) | V_299 ;
if ( ( V_226 -> V_166 >> 5 ) & V_226 -> V_166 & V_235 ) {
return V_282 ;
}
switch ( V_334 ) {
case - 1 :
if ( V_284 )
V_256 = V_285 [ F_56 ( V_227 ) >> 2 ] ;
else
V_256 = V_254 ;
if ( V_338 . V_336 )
V_226 -> V_166 |= V_256 ;
else
V_226 -> V_166 &= ~ V_256 ;
break;
case V_327 :
F_63 ( V_338 . V_296 , F_56 ( V_227 ) ) ;
break;
case V_301 :
F_60 ( V_338 . V_298 , F_56 ( V_227 ) ) ;
break;
case V_354 :
F_34 ( V_338 . V_336 , F_56 ( V_227 ) ) ;
break;
case V_368 :
if ( ! V_367 )
return V_28 ;
F_31 ( V_338 . V_337 , F_56 ( V_227 ) ) ;
break;
default:
return V_28 ;
}
return 0 ;
}
int F_95 ( struct V_161 * V_218 , struct V_225 * V_226 ,
int V_380 , void * T_2 * V_255 )
{
unsigned long V_381 , V_382 ;
struct V_163 V_164 ;
T_5 V_383 [ 4 ] ;
T_5 * V_384 ;
int V_262 = 0 ;
V_381 = V_218 -> V_170 ;
do {
V_382 = V_218 -> V_170 ;
if ( F_96 ( V_382 ) && V_263 ) {
if ( ( F_97 ( V_383 [ 0 ] , ( T_5 T_2 * ) F_98 ( V_218 -> V_170 ) ) ) ||
( F_97 ( V_383 [ 1 ] , ( T_5 T_2 * ) F_98 ( V_218 -> V_170 + 2 ) ) ) ||
( F_97 ( V_383 [ 2 ] , ( T_5 T_2 * ) F_98 ( V_218 -> V_170 + 4 ) ) ) ||
( F_97 ( V_383 [ 3 ] , ( T_5 T_2 * ) F_98 ( V_218 -> V_170 + 6 ) ) ) ) {
F_25 ( V_271 ) ;
return V_272 ;
}
V_384 = V_383 ;
if ( F_99 ( * V_384 ) ) {
V_164 . V_3 = ( * V_384 << 16 ) |
( * V_384 ) ;
V_164 . V_171 = 2 ;
V_384 += 1 ;
} else {
V_164 . V_3 = ( * V_384 << 16 ) |
* ( V_384 + 1 ) ;
V_164 . V_171 = 4 ;
V_384 += 2 ;
}
if ( F_99 ( * V_384 ) ) {
V_164 . V_265 = ( * V_384 << 16 ) |
( * V_384 ) ;
V_164 . V_172 = 2 ;
} else {
V_164 . V_265 = ( * V_384 << 16 ) |
* ( V_384 + 1 ) ;
V_164 . V_172 = 4 ;
}
V_164 . V_264 = 1 ;
} else {
if ( ( F_97 ( V_164 . V_3 ,
( V_1 T_2 * ) V_218 -> V_170 ) ) ||
( F_97 ( V_164 . V_265 ,
( V_1 T_2 * ) ( V_218 -> V_170 + 4 ) ) ) ) {
F_25 ( V_271 ) ;
return V_272 ;
}
V_164 . V_171 = 4 ;
V_164 . V_172 = 4 ;
V_164 . V_264 = 0 ;
}
if ( ( V_164 . V_3 == 0 ) ||
( ( V_164 . V_171 == 2 ) &&
( ( V_164 . V_3 & 0xffff ) == V_292 ) ) )
V_218 -> V_170 += V_164 . V_171 ;
else {
V_262 = F_19 ( V_218 , V_226 , V_164 , V_255 ) ;
}
if ( V_380 )
break;
if ( V_262 )
break;
F_100 () ;
} while ( V_218 -> V_170 > V_382 );
if ( V_262 == V_28 && V_218 -> V_170 != V_381 )
V_262 = 0 ;
return V_262 ;
}
