int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
struct V_6 * V_7 ;
F_2 (ha, dev)
memcpy ( & V_2 -> V_8 [ V_5 ++ ] , V_7 -> V_9 , V_10 ) ;
return V_5 ;
}
int F_3 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
int V_15 ;
V_15 = F_4 ( V_12 -> V_16 . V_17 ,
* ( V_14 -> V_18 ) ,
( 12 * V_19 ) ) ;
if ( V_15 <= 0 ) {
if ( V_15 == 0 )
V_15 = - V_20 ;
F_5 ( V_12 , ERROR , L_1 ,
V_15 ) ;
F_6 ( V_12 ) ;
return V_15 ;
}
V_15 = V_12 -> V_16 . V_15 ;
V_12 -> V_16 . V_15 = 0 ;
return V_15 ;
}
int F_7 ( struct V_21 * V_22 ,
struct V_1 * V_23 )
{
int V_24 = 0 ;
T_1 V_25 ;
V_25 = V_22 -> V_26 ;
if ( V_23 -> V_27 == V_28 ) {
F_5 ( V_22 -> V_12 , V_29 ,
L_2 ) ;
V_22 -> V_26 |= V_30 ;
V_22 -> V_26 &=
~ V_31 ;
} else {
V_22 -> V_26 &= ~ V_30 ;
if ( V_23 -> V_27 == V_32 ) {
F_5 ( V_22 -> V_12 , V_29 ,
L_3 ) ;
V_22 -> V_26 |=
V_31 ;
} else {
V_22 -> V_26 &=
~ V_31 ;
F_5 ( V_22 -> V_12 , V_29 ,
L_4 ,
V_23 -> V_33 ) ;
V_24 = F_8 ( V_22 ,
V_34 ,
V_35 , 0 ,
V_23 , false ) ;
}
}
F_5 ( V_22 -> V_12 , V_29 ,
L_5 ,
V_25 , V_22 -> V_26 ) ;
if ( V_25 != V_22 -> V_26 ) {
V_24 = F_8 ( V_22 , V_36 ,
V_35 ,
0 , & V_22 -> V_26 , false ) ;
}
return V_24 ;
}
int F_9 ( struct V_21 * V_22 ,
struct V_37 * V_38 ,
struct V_39 * V_40 )
{
T_2 * V_41 ;
T_3 V_42 ;
struct V_43 * V_44 = ( void * ) V_38 -> V_22 ;
const struct V_45 * V_46 ;
int V_24 ;
F_10 () ;
V_46 = F_11 ( V_38 -> V_46 ) ;
V_41 = F_12 ( V_46 -> V_47 , V_46 -> V_48 , V_49 ) ;
V_42 = V_46 -> V_48 ;
V_40 -> V_50 = V_46 -> V_51 ;
F_13 () ;
if ( ! V_41 ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_6 ) ;
return - V_52 ;
}
memcpy ( V_40 -> V_53 , V_38 -> V_54 , V_10 ) ;
V_40 -> V_55 = V_38 -> signal ;
V_40 -> V_56 = V_41 ;
V_40 -> V_57 = V_42 ;
V_40 -> V_58 = V_38 -> V_59 ;
V_40 -> V_60 = V_38 -> V_61 ;
V_40 -> V_62 = V_44 -> V_63 ;
V_40 -> V_64 = V_44 -> V_64 ;
if ( V_40 -> V_60 & V_65 ) {
F_5 ( V_22 -> V_12 , V_29 ,
L_7 ) ;
V_40 -> V_66 = V_67 ;
} else {
V_40 -> V_66 = V_68 ;
}
if ( V_40 -> V_60 & V_69 )
V_40 -> V_70 = V_71 ;
else
V_40 -> V_70 = V_72 ;
V_40 -> V_73 = true ;
if ( V_40 -> V_60 & V_74 )
V_40 -> V_75 = true ;
V_24 = F_14 ( V_22 -> V_12 , V_40 ) ;
if ( V_24 )
return V_24 ;
if ( V_40 -> V_76 && V_40 -> V_77 ) {
T_2 V_78 = V_40 -> V_76 -> V_78 ;
T_2 V_79 = F_15 ( V_40 -> V_62 ) ;
struct V_80 * V_81 =
V_22 -> V_82 . V_83 -> V_84 [ V_79 ] ;
int V_85 = F_16 ( V_40 -> V_86 ,
V_79 ) ;
struct V_87 * V_88 =
F_17 ( V_22 -> V_12 -> V_83 , V_85 ) ;
switch ( V_78 & V_89 ) {
case V_90 :
if ( V_88 -> V_91 & V_92 ) {
V_81 -> V_93 . V_94 &=
~ V_95 ;
V_81 -> V_93 . V_94 &= ~ V_96 ;
} else {
V_81 -> V_93 . V_94 |=
V_95 |
V_96 ;
}
break;
case V_97 :
if ( V_88 -> V_91 & V_98 ) {
V_81 -> V_93 . V_94 &=
~ V_95 ;
V_81 -> V_93 . V_94 &= ~ V_96 ;
} else {
V_81 -> V_93 . V_94 |=
V_95 |
V_96 ;
}
break;
}
}
return 0 ;
}
void F_18 ( struct V_21 * V_22 )
{
if ( V_22 -> V_12 -> V_99 ) {
char V_100 [] = { L_8 } ;
memcpy ( & V_100 [ 8 ] , V_22 -> V_12 -> V_101 , 2 ) ;
F_19 ( V_22 , V_22 -> V_12 -> V_99 , V_100 ) ;
}
}
static int F_20 ( struct V_21 * V_22 ,
struct V_37 * V_38 )
{
const T_2 * V_102 ;
T_2 V_103 ;
struct V_104 * V_105 =
& V_22 -> V_12 -> V_106 ;
F_10 () ;
V_102 = F_21 ( V_38 , V_107 ) ;
if ( ! V_102 ) {
F_13 () ;
return 0 ;
}
V_103 = V_102 [ 1 ] ;
if ( V_103 < V_108 ) {
F_13 () ;
return 0 ;
}
if ( ! strncmp ( V_22 -> V_12 -> V_101 , & V_102 [ 2 ] , 2 ) ) {
F_13 () ;
F_5 ( V_22 -> V_12 , V_29 ,
L_9 ) ;
return 0 ;
}
memcpy ( V_22 -> V_12 -> V_101 , & V_102 [ 2 ] , 2 ) ;
V_105 -> V_101 [ 0 ] = V_102 [ 2 ] ;
V_105 -> V_101 [ 1 ] = V_102 [ 3 ] ;
V_105 -> V_101 [ 2 ] = ' ' ;
V_103 -= V_109 ;
V_105 -> V_110 =
V_103 / sizeof( struct V_111 ) ;
memcpy ( ( T_2 * ) V_105 -> V_112 ,
& V_102 [ 2 ] + V_109 , V_103 ) ;
F_13 () ;
if ( F_8 ( V_22 , V_113 ,
V_35 , 0 , NULL , false ) ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_10 ) ;
return - 1 ;
}
F_18 ( V_22 ) ;
return 0 ;
}
int F_22 ( struct V_21 * V_22 , struct V_37 * V_38 ,
struct V_114 * V_115 )
{
int V_24 ;
struct V_11 * V_12 = V_22 -> V_12 ;
struct V_39 * V_40 = NULL ;
V_22 -> V_116 = false ;
if ( V_38 ) {
if ( V_12 -> V_117 == 0x00 )
F_20 ( V_22 , V_38 ) ;
V_40 = F_23 ( sizeof( struct V_39 ) ,
V_118 ) ;
if ( ! V_40 )
return - V_52 ;
V_24 = F_9 ( V_22 , V_38 , V_40 ) ;
if ( V_24 )
goto V_119;
}
if ( V_22 -> V_70 == V_72 ||
V_22 -> V_70 == V_120 ) {
T_2 V_121 ;
if ( ! V_40 )
return - 1 ;
if ( F_15 ( V_40 -> V_62 ) ==
V_122 ) {
V_121 = V_123 | V_124 | V_125 ;
} else {
V_121 = V_126 | V_127 ;
if ( V_12 -> V_128 & V_129 )
V_121 |= V_129 ;
}
if ( ! ( ( V_121 | V_12 -> V_128 ) & ~ V_12 -> V_128 ) )
V_12 -> V_121 = V_121 ;
V_24 = F_24 ( V_22 , V_40 ) ;
if ( V_24 )
goto V_119;
if ( F_25 ( V_22 ) ==
( T_2 ) V_40 -> V_86 ) {
F_5 ( V_12 , ERROR ,
L_11 ,
V_40 -> V_86 ) ;
V_24 = - 1 ;
goto V_119;
}
F_5 ( V_12 , V_29 ,
L_12
L_13 ) ;
F_26 ( V_22 -> V_130 , V_12 ) ;
if ( F_27 ( V_22 -> V_130 ) )
F_28 ( V_22 -> V_130 ) ;
V_22 -> V_131 = 0 ;
V_24 = F_29 ( V_22 , V_40 ) ;
if ( V_24 == V_132 &&
V_22 -> V_133 . V_134 &&
V_22 -> V_133 . V_135 ) {
V_22 -> V_133 . V_136 =
V_137 ;
V_24 = F_29 ( V_22 , V_40 ) ;
}
if ( V_38 )
F_30 ( V_22 -> V_12 -> V_83 , V_38 ) ;
} else {
if ( V_40 && V_40 -> V_138 . V_139 &&
( ! F_31 ( & V_22 -> V_140 . V_141 .
V_138 , & V_40 -> V_138 ) ) ) {
V_24 = 0 ;
goto V_119;
}
V_22 -> V_142 = false ;
V_24 = F_24 ( V_22 , V_40 ) ;
F_26 ( V_22 -> V_130 , V_12 ) ;
if ( F_27 ( V_22 -> V_130 ) )
F_28 ( V_22 -> V_130 ) ;
if ( ! V_24 ) {
F_5 ( V_12 , V_29 ,
L_14
L_15 ) ;
V_24 = F_32 ( V_22 , V_40 ) ;
if ( V_38 )
F_30 ( V_22 -> V_12 -> V_83 , V_38 ) ;
} else {
F_5 ( V_12 , V_29 ,
L_16
L_17 ,
V_115 -> V_138 ) ;
V_24 = F_33 ( V_22 , V_115 ) ;
}
}
V_119:
if ( V_40 )
F_34 ( V_40 -> V_56 ) ;
F_34 ( V_40 ) ;
if ( V_24 < 0 )
V_22 -> V_143 = NULL ;
return V_24 ;
}
int F_35 ( struct V_21 * V_22 , T_1 V_144 ,
int V_145 , struct V_146 * V_147 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
int V_15 = 0 ;
T_4 V_148 = 0 ;
if ( ! V_147 )
return - V_52 ;
switch ( V_144 ) {
case V_35 :
if ( V_12 -> V_149 ) {
F_5 ( V_12 , V_29 ,
L_18
L_19 ) ;
V_15 = - 1 ;
break;
}
if ( V_147 -> V_150 ) {
if ( V_147 -> V_151 == V_152 ) {
if ( ! V_12 -> V_153 )
break;
V_148 = F_36 ( V_12 -> V_147
. V_151 ) ;
V_12 -> V_147 . V_151 =
F_37 ( V_147 -> V_151 ) ;
} else if ( V_147 -> V_151 ) {
V_12 -> V_147 . V_151 =
F_37 ( V_147 -> V_151 ) ;
V_12 -> V_147 . V_154 = ( T_2 ) V_147 -> V_154 ;
if ( V_147 -> V_155 )
V_12 -> V_147 . V_155 = ( T_2 ) V_147 -> V_155 ;
} else if ( V_12 -> V_147 . V_151 ==
F_37 ( V_152 ) ) {
V_15 = - 1 ;
break;
}
V_15 = F_8 ( V_22 ,
V_156 ,
V_35 , 0 ,
& V_12 -> V_147 ,
V_145 == V_157 ) ;
if ( V_147 -> V_151 == V_152 )
V_12 -> V_147 . V_151 =
F_37 ( V_148 ) ;
} else {
V_12 -> V_147 . V_151 =
F_37 ( V_147 -> V_151 ) ;
V_12 -> V_147 . V_154 = ( T_2 ) V_147 -> V_154 ;
V_12 -> V_147 . V_155 = ( T_2 ) V_147 -> V_155 ;
}
break;
case V_158 :
V_147 -> V_151 = F_36 ( V_12 -> V_147 . V_151 ) ;
V_147 -> V_154 = V_12 -> V_147 . V_154 ;
V_147 -> V_155 = V_12 -> V_147 . V_155 ;
break;
default:
V_15 = - 1 ;
break;
}
return V_15 ;
}
int F_38 ( struct V_21 * V_22 , int V_145 )
{
struct V_146 V_159 ;
V_159 . V_151 = V_152 ;
V_159 . V_150 = true ;
return F_35 ( V_22 , V_35 ,
V_145 , & V_159 ) ;
}
int F_39 ( struct V_11 * V_12 )
{
struct V_146 V_159 ;
struct V_21 * V_22 ;
int V_5 ;
if ( V_160 ) {
for ( V_5 = 0 ; V_5 < V_12 -> V_161 ; V_5 ++ ) {
V_22 = V_12 -> V_22 [ V_5 ] ;
if ( V_22 )
F_40 ( V_22 , NULL ) ;
}
}
V_22 = F_41 ( V_12 , V_162 ) ;
if ( V_22 && V_22 -> V_163 ) {
#ifdef F_42
if ( V_22 -> V_82 . V_83 -> V_164 &&
! V_22 -> V_82 . V_83 -> V_164 -> V_165 ) {
#endif
F_5 ( V_12 , V_166 , L_20 ) ;
F_43 ( V_22 ) ;
F_44 ( V_22 -> V_82 . V_83 ) ;
#ifdef F_42
}
#endif
}
if ( V_12 -> V_167 ) {
F_5 ( V_12 , V_166 ,
L_21 ) ;
return true ;
}
V_12 -> V_168 = false ;
memset ( & V_159 , 0 , sizeof( struct V_146 ) ) ;
V_159 . V_150 = true ;
V_12 -> V_169 = true ;
F_6 ( V_12 ) ;
if ( F_35 ( F_41 ( V_12 ,
V_162 ) ,
V_35 , V_157 ,
& V_159 ) ) {
F_5 ( V_12 , ERROR ,
L_22 ) ;
return false ;
}
if ( F_4 ( V_12 -> V_170 ,
V_12 -> V_168 ,
( 10 * V_19 ) ) <= 0 ) {
F_5 ( V_12 , ERROR ,
L_23 ) ;
return false ;
}
return true ;
}
int F_45 ( struct V_21 * V_22 ,
struct V_171 * V_172 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
struct V_39 * V_40 ;
if ( ! V_172 )
return - 1 ;
V_40 = & V_22 -> V_140 . V_141 ;
V_172 -> V_70 = V_22 -> V_70 ;
memcpy ( & V_172 -> V_138 , & V_40 -> V_138 , sizeof( struct V_114 ) ) ;
memcpy ( & V_172 -> V_54 , & V_40 -> V_53 , V_10 ) ;
V_172 -> V_173 = V_40 -> V_86 ;
memcpy ( V_172 -> V_101 , V_12 -> V_101 ,
V_109 ) ;
V_172 -> V_174 = V_22 -> V_174 ;
V_172 -> V_175 = V_22 -> V_176 ;
V_172 -> V_177 = V_22 -> V_178 ;
V_172 -> V_179 = V_22 -> V_179 ;
V_172 -> V_180 = V_22 -> V_180 ;
if ( V_22 -> V_133 . V_135 )
V_172 -> V_181 = true ;
else
V_172 -> V_181 = false ;
V_172 -> V_153 = V_12 -> V_153 ;
V_172 -> V_182 = V_12 -> V_182 ;
return 0 ;
}
int F_46 ( struct V_21 * V_22 )
{
struct V_183 V_184 ;
V_184 . V_184 = V_185 ;
return F_8 ( V_22 , V_186 ,
V_187 , V_188 , & V_184 , true ) ;
}
int F_47 ( struct V_21 * V_22 , T_4 * V_189 )
{
int V_24 ;
V_24 = F_8 ( V_22 , V_190 ,
V_158 , 0 , NULL , true ) ;
if ( ! V_24 ) {
if ( V_22 -> V_191 )
* V_189 = F_48 ( V_22 , V_22 -> V_192 ,
V_22 -> V_193 ) ;
else
* V_189 = V_22 -> V_194 ;
}
return V_24 ;
}
int F_49 ( struct V_21 * V_22 ,
struct V_195 * V_196 )
{
int V_24 ;
struct V_197 * V_198 ;
struct V_199 * V_200 ;
struct V_201 * V_202 ;
T_2 * V_203 ;
T_1 V_204 = 0 ;
if ( ! V_196 -> V_205 ) {
V_204 = ( T_1 ) V_196 -> V_206 ;
if ( ( V_204 < V_22 -> V_178 ) ||
( V_204 > V_22 -> V_176 ) ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_24
L_25 ,
V_204 , V_22 -> V_178 ,
V_22 -> V_176 ) ;
return - 1 ;
}
}
V_203 = F_23 ( V_207 , V_118 ) ;
if ( ! V_203 )
return - V_52 ;
V_198 = (struct V_197 * ) V_203 ;
V_198 -> V_144 = F_50 ( V_35 ) ;
if ( ! V_196 -> V_205 ) {
V_198 -> V_27 = F_37 ( 1 ) ;
V_200 = (struct V_199 * )
( V_203 + sizeof( struct V_197 ) ) ;
V_200 -> type = F_50 ( V_208 ) ;
V_200 -> V_209 =
F_50 ( 4 * sizeof( struct V_201 ) ) ;
V_202 = (struct V_201 * )
( V_203 + sizeof( struct V_197 )
+ sizeof( struct V_199 ) ) ;
V_202 -> V_210 = 0x00 ;
V_202 -> V_211 = 0x03 ;
V_202 -> V_212 = V_213 ;
V_202 -> V_214 = 0 ;
V_202 -> V_215 = ( V_216 ) V_204 ;
V_202 -> V_217 = ( V_216 ) V_204 ;
V_202 ++ ;
V_202 -> V_210 = 0x00 ;
V_202 -> V_211 = 0x07 ;
V_202 -> V_212 = V_218 ;
V_202 -> V_214 = 0 ;
V_202 -> V_215 = ( V_216 ) V_204 ;
V_202 -> V_217 = ( V_216 ) V_204 ;
V_202 ++ ;
V_202 -> V_210 = 0x00 ;
V_202 -> V_211 = 0x20 ;
V_202 -> V_212 = V_219 ;
V_202 -> V_214 = 0 ;
V_202 -> V_215 = ( V_216 ) V_204 ;
V_202 -> V_217 = ( V_216 ) V_204 ;
V_202 -> V_220 = V_221 ;
V_202 ++ ;
V_202 -> V_210 = 0x00 ;
V_202 -> V_211 = 0x20 ;
V_202 -> V_212 = V_219 ;
V_202 -> V_214 = 0 ;
V_202 -> V_215 = ( V_216 ) V_204 ;
V_202 -> V_217 = ( V_216 ) V_204 ;
V_202 -> V_220 = V_222 ;
}
V_24 = F_8 ( V_22 , V_223 ,
V_35 , 0 , V_203 , true ) ;
F_34 ( V_203 ) ;
return V_24 ;
}
int F_51 ( struct V_21 * V_22 , T_4 * V_224 )
{
int V_24 ;
struct V_11 * V_12 = V_22 -> V_12 ;
T_1 V_225 ;
if ( * V_224 )
V_12 -> V_224 = V_226 ;
else
V_12 -> V_224 = V_227 ;
V_225 = ( * V_224 ) ? V_228 : V_187 ;
V_24 = F_8 ( V_22 , V_186 ,
V_225 , V_229 , NULL , true ) ;
if ( ( ! V_24 ) && ( V_225 == V_187 ) )
V_24 = F_8 ( V_22 , V_186 ,
V_230 , 0 , NULL , false ) ;
return V_24 ;
}
static int F_52 ( struct V_21 * V_22 ,
T_2 * V_231 , T_1 V_232 )
{
if ( V_232 ) {
if ( V_232 > sizeof( V_22 -> V_233 ) ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_26 ) ;
return - 1 ;
}
memcpy ( V_22 -> V_233 , V_231 , V_232 ) ;
V_22 -> V_234 = V_232 ;
F_5 ( V_22 -> V_12 , V_166 ,
L_27 ,
V_22 -> V_234 , V_22 -> V_233 [ 0 ] ) ;
if ( V_22 -> V_233 [ 0 ] == V_235 ) {
V_22 -> V_133 . V_236 = true ;
} else if ( V_22 -> V_233 [ 0 ] == V_237 ) {
V_22 -> V_133 . V_238 = true ;
} else {
V_22 -> V_133 . V_236 = false ;
V_22 -> V_133 . V_238 = false ;
}
} else {
memset ( V_22 -> V_233 , 0 , sizeof( V_22 -> V_233 ) ) ;
V_22 -> V_234 = 0 ;
F_5 ( V_22 -> V_12 , V_29 ,
L_28 ,
V_22 -> V_234 , V_22 -> V_233 [ 0 ] ) ;
V_22 -> V_133 . V_236 = false ;
V_22 -> V_133 . V_238 = false ;
}
return 0 ;
}
static int F_53 ( struct V_21 * V_22 ,
T_2 * V_231 , T_1 V_232 )
{
if ( V_232 ) {
if ( V_232 > sizeof( V_22 -> V_239 ) ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_29 ) ;
return - 1 ;
}
memcpy ( V_22 -> V_239 , V_231 , V_232 ) ;
V_22 -> V_240 = V_232 ;
F_5 ( V_22 -> V_12 , V_166 ,
L_30 ,
V_22 -> V_240 , V_22 -> V_239 [ 0 ] ) ;
if ( V_22 -> V_239 [ 0 ] == V_241 )
V_22 -> V_133 . V_242 = true ;
} else {
memset ( V_22 -> V_239 , 0 , sizeof( V_22 -> V_239 ) ) ;
V_22 -> V_240 = V_232 ;
F_5 ( V_22 -> V_12 , V_29 ,
L_31 ,
V_22 -> V_240 , V_22 -> V_239 [ 0 ] ) ;
V_22 -> V_133 . V_242 = false ;
}
return 0 ;
}
static int F_54 ( struct V_21 * V_22 ,
T_2 * V_231 , T_1 V_232 )
{
if ( V_232 ) {
if ( V_232 > V_243 ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_32 ) ;
return - 1 ;
}
V_22 -> V_244 = F_23 ( V_243 , V_118 ) ;
if ( ! V_22 -> V_244 )
return - V_52 ;
memcpy ( V_22 -> V_244 , V_231 , V_232 ) ;
V_22 -> V_245 = V_232 ;
F_5 ( V_22 -> V_12 , V_166 ,
L_33 ,
V_22 -> V_245 , V_22 -> V_244 [ 0 ] ) ;
} else {
F_34 ( V_22 -> V_244 ) ;
V_22 -> V_245 = V_232 ;
F_5 ( V_22 -> V_12 , V_29 ,
L_34 , V_22 -> V_245 ) ;
}
return 0 ;
}
static int F_55 ( struct V_21 * V_22 ,
struct V_246 * V_247 )
{
return F_8 ( V_22 , V_248 ,
V_35 , V_249 ,
V_247 , true ) ;
}
static int F_56 ( struct V_21 * V_22 ,
struct V_246 * V_247 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
int V_24 ;
struct V_250 * V_251 ;
int V_252 ;
if ( V_22 -> V_253 >= V_254 )
V_22 -> V_253 = 0 ;
V_251 = & V_22 -> V_251 [ V_22 -> V_253 ] ;
V_252 = V_247 -> V_255 ;
if ( V_247 -> V_256 ) {
V_22 -> V_133 . V_135 = 0 ;
} else if ( ! V_247 -> V_257 ) {
V_251 = & V_22 -> V_251 [ V_252 ] ;
if ( ! V_251 -> V_258 ) {
F_5 ( V_12 , ERROR ,
L_35 ) ;
return - 1 ;
}
if ( V_12 -> V_259 == V_260 ) {
memcpy ( V_247 -> V_261 ,
V_251 -> V_261 , V_251 -> V_258 ) ;
V_247 -> V_257 = V_251 -> V_258 ;
}
V_22 -> V_253 = ( T_1 ) V_252 ;
V_22 -> V_133 . V_135 = 1 ;
} else {
V_251 = & V_22 -> V_251 [ V_252 ] ;
memset ( V_251 , 0 , sizeof( struct V_250 ) ) ;
memcpy ( V_251 -> V_261 ,
V_247 -> V_261 ,
V_247 -> V_257 ) ;
V_251 -> V_255 = V_252 ;
V_251 -> V_258 = V_247 -> V_257 ;
V_22 -> V_133 . V_135 = 1 ;
}
if ( V_251 -> V_258 ) {
void * V_262 ;
if ( V_247 -> V_256 ) {
memset ( & V_22 -> V_251 [ V_252 ] , 0 ,
sizeof( struct V_250 ) ) ;
goto V_119;
}
if ( V_12 -> V_259 == V_260 )
V_262 = V_247 ;
else
V_262 = NULL ;
V_24 = F_8 ( V_22 , V_248 ,
V_35 , 0 , V_262 , false ) ;
if ( V_24 )
return V_24 ;
}
V_119:
if ( V_22 -> V_133 . V_135 )
V_22 -> V_26 |= V_263 ;
else
V_22 -> V_26 &= ~ V_263 ;
V_24 = F_8 ( V_22 , V_36 ,
V_35 , 0 ,
& V_22 -> V_26 , true ) ;
return V_24 ;
}
static int F_57 ( struct V_21 * V_22 ,
struct V_246 * V_247 )
{
int V_24 ;
T_2 V_264 = false ;
struct V_265 * V_266 ;
if ( V_247 -> V_257 > V_267 ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_36 ) ;
return - 1 ;
}
if ( V_22 -> V_70 == V_71 ) {
V_247 -> V_255 = V_268 ;
V_24 = F_8 ( V_22 , V_248 ,
V_35 ,
V_249 , V_247 , false ) ;
if ( V_24 )
return V_24 ;
V_266 = & V_22 -> V_269 ;
memset ( V_266 , 0 ,
sizeof( struct V_265 ) ) ;
memcpy ( V_266 -> V_270 . V_271 , V_247 -> V_261 ,
V_247 -> V_257 ) ;
memcpy ( & V_266 -> V_270 . V_257 , & V_247 -> V_257 ,
sizeof( V_266 -> V_270 . V_257 ) ) ;
V_266 -> V_270 . V_272
= F_50 ( V_273 ) ;
V_266 -> V_270 . V_274 = F_50 ( V_275 ) ;
V_247 -> V_255 = ~ V_268 ;
}
if ( ! V_247 -> V_255 )
V_247 -> V_255 = V_268 ;
if ( V_264 )
V_24 = F_8 ( V_22 , V_248 ,
V_35 ,
! V_249 , V_247 , true ) ;
else
V_24 = F_8 ( V_22 , V_248 ,
V_35 ,
V_249 , V_247 , true ) ;
return V_24 ;
}
static int
F_58 ( struct V_21 * V_22 ,
struct V_246 * V_247 )
{
int V_15 ;
if ( V_247 -> V_276 )
V_15 = F_55 ( V_22 , V_247 ) ;
else if ( V_247 -> V_257 > V_277 )
V_15 = F_57 ( V_22 , V_247 ) ;
else
V_15 = F_56 ( V_22 , V_247 ) ;
return V_15 ;
}
int
F_59 ( struct V_11 * V_12 , char * V_278 ,
int V_279 )
{
union {
T_5 V_280 ;
T_2 V_281 [ 4 ] ;
} V_282 ;
char V_283 [ 32 ] ;
V_282 . V_280 = F_37 ( V_12 -> V_284 ) ;
sprintf ( V_283 , L_37 , V_282 . V_281 [ 2 ] , V_282 . V_281 [ 1 ] , V_282 . V_281 [ 0 ] , V_282 . V_281 [ 3 ] ) ;
snprintf ( V_278 , V_279 , V_285 , V_283 ) ;
F_5 ( V_12 , V_286 , L_38 , V_278 ) ;
return 0 ;
}
int F_60 ( struct V_21 * V_22 , struct V_287 * V_288 ,
const T_2 * V_271 , int V_257 , T_2 V_255 ,
const T_2 * V_289 , int V_290 )
{
struct V_246 V_247 ;
memset ( & V_247 , 0 , sizeof( struct V_246 ) ) ;
V_247 . V_257 = V_257 ;
V_247 . V_255 = V_255 ;
if ( V_288 && V_288 -> V_291 == V_292 )
V_247 . V_293 = true ;
if ( ! V_290 ) {
if ( V_257 )
memcpy ( V_247 . V_261 , V_271 , V_257 ) ;
else
V_247 . V_294 = true ;
if ( V_289 )
memcpy ( V_247 . V_289 , V_289 , V_10 ) ;
if ( V_288 && V_288 -> V_295 && V_288 -> V_296 ) {
memcpy ( V_247 . V_297 , V_288 -> V_295 , V_288 -> V_296 ) ;
V_247 . V_298 = V_288 -> V_296 ;
V_247 . V_299 = true ;
}
} else {
if ( F_61 ( V_22 ) == V_300 )
return 0 ;
V_247 . V_256 = true ;
if ( V_289 )
memcpy ( V_247 . V_289 , V_289 , V_10 ) ;
}
return F_58 ( V_22 , & V_247 ) ;
}
int
F_62 ( struct V_21 * V_22 , T_4 V_301 )
{
struct V_302 V_303 ;
memset ( & V_303 , 0 , sizeof( struct V_304 ) ) ;
V_303 . V_301 = V_301 ;
if ( F_8 ( V_22 , V_305 ,
V_158 , 0 , & V_303 , true ) )
return - 1 ;
return 0 ;
}
int
F_63 ( struct V_21 * V_22 , T_1 V_144 ,
struct V_87 * V_88 ,
unsigned int V_306 )
{
struct V_307 V_308 ;
T_2 V_309 ;
memset ( & V_308 , 0 , sizeof( V_308 ) ) ;
V_308 . V_144 = F_50 ( V_144 ) ;
if ( V_144 == V_35 ) {
V_308 . V_310 = V_88 -> V_63 ;
V_309 = F_64 ( V_311 ) ;
V_308 . V_310 |= ( V_309 << 2 ) ;
V_308 . V_86 =
F_65 ( V_88 -> V_312 ) ;
V_308 . V_306 = F_37 ( V_306 ) ;
}
if ( F_8 ( V_22 , V_313 ,
V_144 , 0 , & V_308 , true ) ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_39 ) ;
return - 1 ;
}
return V_308 . V_15 ;
}
int
F_66 ( struct V_21 * V_22 ,
struct V_314 * log )
{
return F_8 ( V_22 , V_315 ,
V_158 , 0 , log , true ) ;
}
static int F_67 ( struct V_21 * V_22 ,
struct V_316 * V_317 ,
T_1 V_144 )
{
T_1 V_318 ;
switch ( V_317 -> type ) {
case V_319 :
V_318 = V_320 ;
break;
case V_321 :
V_318 = V_322 ;
break;
case V_323 :
V_318 = V_324 ;
break;
case V_325 :
V_318 = V_326 ;
break;
case V_327 :
V_318 = V_328 ;
break;
default:
return - 1 ;
}
return F_8 ( V_22 , V_318 , V_144 , 0 , V_317 , true ) ;
}
int
F_68 ( struct V_21 * V_22 , T_4 V_329 ,
T_4 V_330 , T_4 V_331 )
{
struct V_316 V_317 ;
V_317 . type = V_329 ;
V_317 . V_332 = V_330 ;
V_317 . V_333 = V_331 ;
return F_67 ( V_22 , & V_317 , V_35 ) ;
}
int
F_69 ( struct V_21 * V_22 , T_4 V_329 ,
T_4 V_330 , T_4 * V_333 )
{
int V_24 ;
struct V_316 V_317 ;
V_317 . type = V_329 ;
V_317 . V_332 = V_330 ;
V_24 = F_67 ( V_22 , & V_317 , V_158 ) ;
if ( V_24 )
goto V_119;
* V_333 = V_317 . V_333 ;
V_119:
return V_24 ;
}
int
F_70 ( struct V_21 * V_22 , T_1 V_332 , T_1 V_334 ,
T_2 * V_333 )
{
int V_24 ;
struct V_335 V_336 ;
V_336 . V_332 = V_332 ;
V_336 . V_337 = V_334 ;
V_24 = F_8 ( V_22 , V_338 ,
V_158 , 0 , & V_336 , true ) ;
if ( ! V_24 )
memcpy ( V_333 , V_336 . V_333 , F_71 ( ( T_1 ) V_339 ,
V_336 . V_337 ) ) ;
return V_24 ;
}
static int
F_72 ( struct V_21 * V_22 , T_2 * V_231 ,
T_1 V_232 )
{
int V_24 = 0 ;
struct V_340 * V_341 ;
const T_2 V_342 [] = { 0x00 , 0x50 , 0xf2 , 0x01 } ;
const T_2 V_343 [] = { 0x00 , 0x50 , 0xf2 , 0x04 } ;
T_1 V_344 = V_232 ;
int V_345 = 0 ;
if ( ! V_232 ) {
V_22 -> V_346 = 0 ;
V_22 -> V_347 . V_348 = false ;
return 0 ;
} else if ( ! V_231 ) {
return - 1 ;
}
V_341 = (struct V_340 * ) V_231 ;
while ( V_341 ) {
if ( V_341 -> V_349 == V_235 ) {
if ( ! memcmp ( V_341 -> V_350 , V_342 ,
sizeof( V_342 ) ) ) {
V_345 = 1 ;
break;
}
if ( ! memcmp ( V_341 -> V_350 , V_343 ,
sizeof( V_343 ) ) ) {
V_22 -> V_347 . V_348 = true ;
F_5 ( V_22 -> V_12 , V_286 ,
L_40 ) ;
V_24 = F_54 ( V_22 ,
( T_2 * ) V_341 ,
V_344 ) ;
}
}
if ( V_341 -> V_349 == V_237 ) {
V_345 = 1 ;
break;
}
if ( V_341 -> V_349 == V_241 ) {
V_24 = F_53 ( V_22 , ( T_2 * ) V_341 ,
V_344 ) ;
return V_24 ;
}
V_344 -= ( V_341 -> V_48 +
sizeof( struct V_351 ) ) ;
if ( V_344 <= sizeof( struct V_351 ) )
V_341 = NULL ;
else
V_341 = (struct V_340 * )
( ( ( T_2 * ) V_341 ) + V_341 -> V_48 +
sizeof( struct V_351 ) ) ;
}
if ( V_345 ) {
V_24 = F_52 ( V_22 , ( T_2 * ) V_341 ,
V_344 ) ;
V_22 -> V_347 . V_348 = false ;
return V_24 ;
}
if ( V_232 < ( sizeof( V_22 -> V_352 ) - V_22 -> V_346 ) ) {
memcpy ( V_22 -> V_352 + V_22 -> V_346 , V_231 ,
V_232 ) ;
V_22 -> V_346 += V_232 ;
} else {
V_24 = - 1 ;
}
return V_24 ;
}
static int F_73 ( struct V_21 * V_22 ,
struct V_353 * V_354 ,
T_1 V_144 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
switch ( V_354 -> type ) {
case V_355 :
if ( V_144 == V_158 ) {
V_354 -> V_48 = V_22 -> V_234 ;
memcpy ( V_354 -> V_356 , V_22 -> V_233 , V_354 -> V_48 ) ;
} else {
F_72 ( V_22 , V_354 -> V_356 ,
( T_1 ) V_354 -> V_48 ) ;
}
break;
case V_357 :
memset ( V_12 -> V_358 , 0 , sizeof( V_12 -> V_358 ) ) ;
if ( V_354 -> V_48 > V_359 ) {
V_12 -> V_360 = 0 ;
F_5 ( V_12 , ERROR ,
L_41 ) ;
return - 1 ;
} else {
memcpy ( V_12 -> V_358 , V_354 -> V_356 ,
V_354 -> V_48 ) ;
V_12 -> V_360 = V_354 -> V_48 ;
}
break;
default:
F_5 ( V_12 , ERROR , L_42 ) ;
return - 1 ;
}
return 0 ;
}
int
F_74 ( struct V_21 * V_22 , const T_2 * V_361 , int V_232 )
{
struct V_353 V_354 ;
if ( V_232 > V_362 )
return - V_363 ;
V_354 . type = V_355 ;
V_354 . V_48 = V_232 ;
memcpy ( V_354 . V_356 , V_361 , V_232 ) ;
if ( F_73 ( V_22 , & V_354 , V_35 ) )
return - V_363 ;
return 0 ;
}
int F_75 ( struct V_21 * V_22 , T_1 V_144 ,
int V_145 ,
struct V_364 * V_365 )
{
int V_15 = 0 ;
V_15 = F_8 ( V_22 , V_366 ,
V_158 , 0 , V_365 ,
V_145 == V_157 ) ;
return V_15 ;
}
