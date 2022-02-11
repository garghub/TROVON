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
return V_24 ;
}
int F_35 ( struct V_21 * V_22 , T_1 V_143 ,
int V_144 , struct V_145 * V_146 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
int V_15 = 0 ;
T_4 V_147 = 0 ;
if ( ! V_146 )
return - V_52 ;
switch ( V_143 ) {
case V_35 :
if ( V_12 -> V_148 ) {
F_5 ( V_12 , V_29 ,
L_18
L_19 ) ;
V_15 = - 1 ;
break;
}
if ( V_146 -> V_149 ) {
if ( V_146 -> V_150 == V_151 ) {
if ( ! V_12 -> V_152 )
break;
V_147 = F_36 ( V_12 -> V_146
. V_150 ) ;
V_12 -> V_146 . V_150 =
F_37 ( V_146 -> V_150 ) ;
} else if ( V_146 -> V_150 ) {
V_12 -> V_146 . V_150 =
F_37 ( V_146 -> V_150 ) ;
V_12 -> V_146 . V_153 = ( T_2 ) V_146 -> V_153 ;
if ( V_146 -> V_154 )
V_12 -> V_146 . V_154 = ( T_2 ) V_146 -> V_154 ;
} else if ( V_12 -> V_146 . V_150 ==
F_37 ( V_151 ) ) {
V_15 = - 1 ;
break;
}
V_15 = F_8 ( V_22 ,
V_155 ,
V_35 , 0 ,
& V_12 -> V_146 ,
V_144 == V_156 ) ;
if ( V_146 -> V_150 == V_151 )
V_12 -> V_146 . V_150 =
F_37 ( V_147 ) ;
} else {
V_12 -> V_146 . V_150 =
F_37 ( V_146 -> V_150 ) ;
V_12 -> V_146 . V_153 = ( T_2 ) V_146 -> V_153 ;
V_12 -> V_146 . V_154 = ( T_2 ) V_146 -> V_154 ;
}
break;
case V_157 :
V_146 -> V_150 = F_36 ( V_12 -> V_146 . V_150 ) ;
V_146 -> V_153 = V_12 -> V_146 . V_153 ;
V_146 -> V_154 = V_12 -> V_146 . V_154 ;
break;
default:
V_15 = - 1 ;
break;
}
return V_15 ;
}
int F_38 ( struct V_21 * V_22 , int V_144 )
{
struct V_145 V_158 ;
V_158 . V_150 = V_151 ;
V_158 . V_149 = true ;
return F_35 ( V_22 , V_35 ,
V_144 , & V_158 ) ;
}
int F_39 ( struct V_11 * V_12 )
{
struct V_145 V_158 ;
struct V_21 * V_22 ;
int V_5 ;
if ( V_159 ) {
for ( V_5 = 0 ; V_5 < V_12 -> V_160 ; V_5 ++ ) {
V_22 = V_12 -> V_22 [ V_5 ] ;
if ( V_22 )
F_40 ( V_22 , NULL ) ;
}
}
V_22 = F_41 ( V_12 , V_161 ) ;
if ( V_22 && V_22 -> V_162 ) {
#ifdef F_42
if ( V_22 -> V_82 . V_83 -> V_163 &&
! V_22 -> V_82 . V_83 -> V_163 -> V_164 ) {
#endif
F_5 ( V_12 , V_165 , L_20 ) ;
F_43 ( V_22 ) ;
F_44 ( V_22 -> V_82 . V_83 ) ;
#ifdef F_42
}
#endif
}
if ( V_12 -> V_166 ) {
F_5 ( V_12 , V_165 ,
L_21 ) ;
return true ;
}
V_12 -> V_167 = false ;
memset ( & V_158 , 0 , sizeof( struct V_145 ) ) ;
V_158 . V_149 = true ;
V_12 -> V_168 = true ;
F_6 ( V_12 ) ;
if ( F_35 ( F_41 ( V_12 ,
V_161 ) ,
V_35 , V_156 ,
& V_158 ) ) {
F_5 ( V_12 , ERROR ,
L_22 ) ;
return false ;
}
if ( F_4 ( V_12 -> V_169 ,
V_12 -> V_167 ,
( 10 * V_19 ) ) <= 0 ) {
F_5 ( V_12 , ERROR ,
L_23 ) ;
return false ;
}
return true ;
}
int F_45 ( struct V_21 * V_22 ,
struct V_170 * V_171 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
struct V_39 * V_40 ;
if ( ! V_171 )
return - 1 ;
V_40 = & V_22 -> V_140 . V_141 ;
V_171 -> V_70 = V_22 -> V_70 ;
memcpy ( & V_171 -> V_138 , & V_40 -> V_138 , sizeof( struct V_114 ) ) ;
memcpy ( & V_171 -> V_54 , & V_40 -> V_53 , V_10 ) ;
V_171 -> V_172 = V_40 -> V_86 ;
memcpy ( V_171 -> V_101 , V_12 -> V_101 ,
V_109 ) ;
V_171 -> V_173 = V_22 -> V_173 ;
V_171 -> V_174 = V_22 -> V_175 ;
V_171 -> V_176 = V_22 -> V_177 ;
V_171 -> V_178 = V_22 -> V_178 ;
V_171 -> V_179 = V_22 -> V_179 ;
if ( V_22 -> V_133 . V_135 )
V_171 -> V_180 = true ;
else
V_171 -> V_180 = false ;
V_171 -> V_152 = V_12 -> V_152 ;
V_171 -> V_181 = V_12 -> V_181 ;
return 0 ;
}
int F_46 ( struct V_21 * V_22 )
{
struct V_182 V_183 ;
V_183 . V_183 = V_184 ;
return F_8 ( V_22 , V_185 ,
V_186 , V_187 , & V_183 , true ) ;
}
int F_47 ( struct V_21 * V_22 , T_4 * V_188 )
{
int V_24 ;
V_24 = F_8 ( V_22 , V_189 ,
V_157 , 0 , NULL , true ) ;
if ( ! V_24 ) {
if ( V_22 -> V_190 )
* V_188 = F_48 ( V_22 , V_22 -> V_191 ,
V_22 -> V_192 ) ;
else
* V_188 = V_22 -> V_193 ;
}
return V_24 ;
}
int F_49 ( struct V_21 * V_22 ,
struct V_194 * V_195 )
{
int V_24 ;
struct V_196 * V_197 ;
struct V_198 * V_199 ;
struct V_200 * V_201 ;
T_2 * V_202 ;
T_1 V_203 = 0 ;
if ( ! V_195 -> V_204 ) {
V_203 = ( T_1 ) V_195 -> V_205 ;
if ( ( V_203 < V_22 -> V_177 ) ||
( V_203 > V_22 -> V_175 ) ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_24
L_25 ,
V_203 , V_22 -> V_177 ,
V_22 -> V_175 ) ;
return - 1 ;
}
}
V_202 = F_23 ( V_206 , V_118 ) ;
if ( ! V_202 )
return - V_52 ;
V_197 = (struct V_196 * ) V_202 ;
V_197 -> V_143 = F_50 ( V_35 ) ;
if ( ! V_195 -> V_204 ) {
V_197 -> V_27 = F_37 ( 1 ) ;
V_199 = (struct V_198 * )
( V_202 + sizeof( struct V_196 ) ) ;
V_199 -> type = F_50 ( V_207 ) ;
V_199 -> V_208 =
F_50 ( 4 * sizeof( struct V_200 ) ) ;
V_201 = (struct V_200 * )
( V_202 + sizeof( struct V_196 )
+ sizeof( struct V_198 ) ) ;
V_201 -> V_209 = 0x00 ;
V_201 -> V_210 = 0x03 ;
V_201 -> V_211 = V_212 ;
V_201 -> V_213 = 0 ;
V_201 -> V_214 = ( V_215 ) V_203 ;
V_201 -> V_216 = ( V_215 ) V_203 ;
V_201 ++ ;
V_201 -> V_209 = 0x00 ;
V_201 -> V_210 = 0x07 ;
V_201 -> V_211 = V_217 ;
V_201 -> V_213 = 0 ;
V_201 -> V_214 = ( V_215 ) V_203 ;
V_201 -> V_216 = ( V_215 ) V_203 ;
V_201 ++ ;
V_201 -> V_209 = 0x00 ;
V_201 -> V_210 = 0x20 ;
V_201 -> V_211 = V_218 ;
V_201 -> V_213 = 0 ;
V_201 -> V_214 = ( V_215 ) V_203 ;
V_201 -> V_216 = ( V_215 ) V_203 ;
V_201 -> V_219 = V_220 ;
V_201 ++ ;
V_201 -> V_209 = 0x00 ;
V_201 -> V_210 = 0x20 ;
V_201 -> V_211 = V_218 ;
V_201 -> V_213 = 0 ;
V_201 -> V_214 = ( V_215 ) V_203 ;
V_201 -> V_216 = ( V_215 ) V_203 ;
V_201 -> V_219 = V_221 ;
}
V_24 = F_8 ( V_22 , V_222 ,
V_35 , 0 , V_202 , true ) ;
F_34 ( V_202 ) ;
return V_24 ;
}
int F_51 ( struct V_21 * V_22 , T_4 * V_223 )
{
int V_24 ;
struct V_11 * V_12 = V_22 -> V_12 ;
T_1 V_224 ;
if ( * V_223 )
V_12 -> V_223 = V_225 ;
else
V_12 -> V_223 = V_226 ;
V_224 = ( * V_223 ) ? V_227 : V_186 ;
V_24 = F_8 ( V_22 , V_185 ,
V_224 , V_228 , NULL , true ) ;
if ( ( ! V_24 ) && ( V_224 == V_186 ) )
V_24 = F_8 ( V_22 , V_185 ,
V_229 , 0 , NULL , false ) ;
return V_24 ;
}
static int F_52 ( struct V_21 * V_22 ,
T_2 * V_230 , T_1 V_231 )
{
if ( V_231 ) {
if ( V_231 > sizeof( V_22 -> V_232 ) ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_26 ) ;
return - 1 ;
}
memcpy ( V_22 -> V_232 , V_230 , V_231 ) ;
V_22 -> V_233 = V_231 ;
F_5 ( V_22 -> V_12 , V_165 ,
L_27 ,
V_22 -> V_233 , V_22 -> V_232 [ 0 ] ) ;
if ( V_22 -> V_232 [ 0 ] == V_234 ) {
V_22 -> V_133 . V_235 = true ;
} else if ( V_22 -> V_232 [ 0 ] == V_236 ) {
V_22 -> V_133 . V_237 = true ;
} else {
V_22 -> V_133 . V_235 = false ;
V_22 -> V_133 . V_237 = false ;
}
} else {
memset ( V_22 -> V_232 , 0 , sizeof( V_22 -> V_232 ) ) ;
V_22 -> V_233 = 0 ;
F_5 ( V_22 -> V_12 , V_29 ,
L_28 ,
V_22 -> V_233 , V_22 -> V_232 [ 0 ] ) ;
V_22 -> V_133 . V_235 = false ;
V_22 -> V_133 . V_237 = false ;
}
return 0 ;
}
static int F_53 ( struct V_21 * V_22 ,
T_2 * V_230 , T_1 V_231 )
{
if ( V_231 ) {
if ( V_231 > sizeof( V_22 -> V_238 ) ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_29 ) ;
return - 1 ;
}
memcpy ( V_22 -> V_238 , V_230 , V_231 ) ;
V_22 -> V_239 = V_231 ;
F_5 ( V_22 -> V_12 , V_165 ,
L_30 ,
V_22 -> V_239 , V_22 -> V_238 [ 0 ] ) ;
if ( V_22 -> V_238 [ 0 ] == V_240 )
V_22 -> V_133 . V_241 = true ;
} else {
memset ( V_22 -> V_238 , 0 , sizeof( V_22 -> V_238 ) ) ;
V_22 -> V_239 = V_231 ;
F_5 ( V_22 -> V_12 , V_29 ,
L_31 ,
V_22 -> V_239 , V_22 -> V_238 [ 0 ] ) ;
V_22 -> V_133 . V_241 = false ;
}
return 0 ;
}
static int F_54 ( struct V_21 * V_22 ,
T_2 * V_230 , T_1 V_231 )
{
if ( V_231 ) {
if ( V_231 > V_242 ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_32 ) ;
return - 1 ;
}
V_22 -> V_243 = F_23 ( V_242 , V_118 ) ;
if ( ! V_22 -> V_243 )
return - V_52 ;
memcpy ( V_22 -> V_243 , V_230 , V_231 ) ;
V_22 -> V_244 = V_231 ;
F_5 ( V_22 -> V_12 , V_165 ,
L_33 ,
V_22 -> V_244 , V_22 -> V_243 [ 0 ] ) ;
} else {
F_34 ( V_22 -> V_243 ) ;
V_22 -> V_244 = V_231 ;
F_5 ( V_22 -> V_12 , V_29 ,
L_34 , V_22 -> V_244 ) ;
}
return 0 ;
}
static int F_55 ( struct V_21 * V_22 ,
struct V_245 * V_246 )
{
return F_8 ( V_22 , V_247 ,
V_35 , V_248 ,
V_246 , true ) ;
}
static int F_56 ( struct V_21 * V_22 ,
struct V_245 * V_246 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
int V_24 ;
struct V_249 * V_250 ;
int V_251 ;
if ( V_22 -> V_252 >= V_253 )
V_22 -> V_252 = 0 ;
V_250 = & V_22 -> V_250 [ V_22 -> V_252 ] ;
V_251 = V_246 -> V_254 ;
if ( V_246 -> V_255 ) {
V_22 -> V_133 . V_135 = 0 ;
} else if ( ! V_246 -> V_256 ) {
V_250 = & V_22 -> V_250 [ V_251 ] ;
if ( ! V_250 -> V_257 ) {
F_5 ( V_12 , ERROR ,
L_35 ) ;
return - 1 ;
}
if ( V_12 -> V_258 == V_259 ) {
memcpy ( V_246 -> V_260 ,
V_250 -> V_260 , V_250 -> V_257 ) ;
V_246 -> V_256 = V_250 -> V_257 ;
}
V_22 -> V_252 = ( T_1 ) V_251 ;
V_22 -> V_133 . V_135 = 1 ;
} else {
V_250 = & V_22 -> V_250 [ V_251 ] ;
memset ( V_250 , 0 , sizeof( struct V_249 ) ) ;
memcpy ( V_250 -> V_260 ,
V_246 -> V_260 ,
V_246 -> V_256 ) ;
V_250 -> V_254 = V_251 ;
V_250 -> V_257 = V_246 -> V_256 ;
V_22 -> V_133 . V_135 = 1 ;
}
if ( V_250 -> V_257 ) {
void * V_261 ;
if ( V_246 -> V_255 ) {
memset ( & V_22 -> V_250 [ V_251 ] , 0 ,
sizeof( struct V_249 ) ) ;
goto V_119;
}
if ( V_12 -> V_258 == V_259 )
V_261 = V_246 ;
else
V_261 = NULL ;
V_24 = F_8 ( V_22 , V_247 ,
V_35 , 0 , V_261 , false ) ;
if ( V_24 )
return V_24 ;
}
V_119:
if ( V_22 -> V_133 . V_135 )
V_22 -> V_26 |= V_262 ;
else
V_22 -> V_26 &= ~ V_262 ;
V_24 = F_8 ( V_22 , V_36 ,
V_35 , 0 ,
& V_22 -> V_26 , true ) ;
return V_24 ;
}
static int F_57 ( struct V_21 * V_22 ,
struct V_245 * V_246 )
{
int V_24 ;
T_2 V_263 = false ;
struct V_264 * V_265 ;
if ( V_246 -> V_256 > V_266 ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_36 ) ;
return - 1 ;
}
if ( V_22 -> V_70 == V_71 ) {
V_246 -> V_254 = V_267 ;
V_24 = F_8 ( V_22 , V_247 ,
V_35 ,
V_248 , V_246 , false ) ;
if ( V_24 )
return V_24 ;
V_265 = & V_22 -> V_268 ;
memset ( V_265 , 0 ,
sizeof( struct V_264 ) ) ;
memcpy ( V_265 -> V_269 . V_270 , V_246 -> V_260 ,
V_246 -> V_256 ) ;
memcpy ( & V_265 -> V_269 . V_256 , & V_246 -> V_256 ,
sizeof( V_265 -> V_269 . V_256 ) ) ;
V_265 -> V_269 . V_271
= F_50 ( V_272 ) ;
V_265 -> V_269 . V_273 = F_50 ( V_274 ) ;
V_246 -> V_254 = ~ V_267 ;
}
if ( ! V_246 -> V_254 )
V_246 -> V_254 = V_267 ;
if ( V_263 )
V_24 = F_8 ( V_22 , V_247 ,
V_35 ,
! V_248 , V_246 , true ) ;
else
V_24 = F_8 ( V_22 , V_247 ,
V_35 ,
V_248 , V_246 , true ) ;
return V_24 ;
}
static int
F_58 ( struct V_21 * V_22 ,
struct V_245 * V_246 )
{
int V_15 ;
if ( V_246 -> V_275 )
V_15 = F_55 ( V_22 , V_246 ) ;
else if ( V_246 -> V_256 > V_276 )
V_15 = F_57 ( V_22 , V_246 ) ;
else
V_15 = F_56 ( V_22 , V_246 ) ;
return V_15 ;
}
int
F_59 ( struct V_11 * V_12 , char * V_277 ,
int V_278 )
{
union {
T_5 V_279 ;
T_2 V_280 [ 4 ] ;
} V_281 ;
char V_282 [ 32 ] ;
V_281 . V_279 = F_37 ( V_12 -> V_283 ) ;
sprintf ( V_282 , L_37 , V_281 . V_280 [ 2 ] , V_281 . V_280 [ 1 ] , V_281 . V_280 [ 0 ] , V_281 . V_280 [ 3 ] ) ;
snprintf ( V_277 , V_278 , V_284 , V_282 ) ;
F_5 ( V_12 , V_285 , L_38 , V_277 ) ;
return 0 ;
}
int F_60 ( struct V_21 * V_22 , struct V_286 * V_287 ,
const T_2 * V_270 , int V_256 , T_2 V_254 ,
const T_2 * V_288 , int V_289 )
{
struct V_245 V_246 ;
memset ( & V_246 , 0 , sizeof( struct V_245 ) ) ;
V_246 . V_256 = V_256 ;
V_246 . V_254 = V_254 ;
if ( V_287 && V_287 -> V_290 == V_291 )
V_246 . V_292 = true ;
if ( ! V_289 ) {
if ( V_256 )
memcpy ( V_246 . V_260 , V_270 , V_256 ) ;
else
V_246 . V_293 = true ;
if ( V_288 )
memcpy ( V_246 . V_288 , V_288 , V_10 ) ;
if ( V_287 && V_287 -> V_294 && V_287 -> V_295 ) {
memcpy ( V_246 . V_296 , V_287 -> V_294 , V_287 -> V_295 ) ;
V_246 . V_297 = V_287 -> V_295 ;
V_246 . V_298 = true ;
}
} else {
if ( F_61 ( V_22 ) == V_299 )
return 0 ;
V_246 . V_255 = true ;
if ( V_288 )
memcpy ( V_246 . V_288 , V_288 , V_10 ) ;
}
return F_58 ( V_22 , & V_246 ) ;
}
int
F_62 ( struct V_21 * V_22 , T_4 V_300 )
{
struct V_301 V_302 ;
memset ( & V_302 , 0 , sizeof( struct V_303 ) ) ;
V_302 . V_300 = V_300 ;
if ( F_8 ( V_22 , V_304 ,
V_157 , 0 , & V_302 , true ) )
return - 1 ;
return 0 ;
}
int
F_63 ( struct V_21 * V_22 , T_1 V_143 ,
struct V_87 * V_88 ,
unsigned int V_305 )
{
struct V_306 V_307 ;
T_2 V_308 ;
memset ( & V_307 , 0 , sizeof( V_307 ) ) ;
V_307 . V_143 = F_50 ( V_143 ) ;
if ( V_143 == V_35 ) {
V_307 . V_309 = V_88 -> V_63 ;
V_308 = F_64 ( V_310 ) ;
V_307 . V_309 |= ( V_308 << 2 ) ;
V_307 . V_86 =
F_65 ( V_88 -> V_311 ) ;
V_307 . V_305 = F_37 ( V_305 ) ;
}
if ( F_8 ( V_22 , V_312 ,
V_143 , 0 , & V_307 , true ) ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_39 ) ;
return - 1 ;
}
return V_307 . V_15 ;
}
int
F_66 ( struct V_21 * V_22 ,
struct V_313 * log )
{
return F_8 ( V_22 , V_314 ,
V_157 , 0 , log , true ) ;
}
static int F_67 ( struct V_21 * V_22 ,
struct V_315 * V_316 ,
T_1 V_143 )
{
T_1 V_317 ;
switch ( F_36 ( V_316 -> type ) ) {
case V_318 :
V_317 = V_319 ;
break;
case V_320 :
V_317 = V_321 ;
break;
case V_322 :
V_317 = V_323 ;
break;
case V_324 :
V_317 = V_325 ;
break;
case V_326 :
V_317 = V_327 ;
break;
default:
return - 1 ;
}
return F_8 ( V_22 , V_317 , V_143 , 0 , V_316 , true ) ;
}
int
F_68 ( struct V_21 * V_22 , T_4 V_328 ,
T_4 V_329 , T_4 V_330 )
{
struct V_315 V_316 ;
V_316 . type = F_37 ( V_328 ) ;
V_316 . V_331 = F_37 ( V_329 ) ;
V_316 . V_332 = F_37 ( V_330 ) ;
return F_67 ( V_22 , & V_316 , V_35 ) ;
}
int
F_69 ( struct V_21 * V_22 , T_4 V_328 ,
T_4 V_329 , T_4 * V_332 )
{
int V_24 ;
struct V_315 V_316 ;
V_316 . type = F_37 ( V_328 ) ;
V_316 . V_331 = F_37 ( V_329 ) ;
V_24 = F_67 ( V_22 , & V_316 , V_157 ) ;
if ( V_24 )
goto V_119;
* V_332 = F_36 ( V_316 . V_332 ) ;
V_119:
return V_24 ;
}
int
F_70 ( struct V_21 * V_22 , T_1 V_331 , T_1 V_333 ,
T_2 * V_332 )
{
int V_24 ;
struct V_334 V_335 ;
V_335 . V_331 = F_50 ( ( T_1 ) V_331 ) ;
V_335 . V_336 = F_50 ( ( T_1 ) V_333 ) ;
V_24 = F_8 ( V_22 , V_337 ,
V_157 , 0 , & V_335 , true ) ;
if ( ! V_24 )
memcpy ( V_332 , V_335 . V_332 , V_338 ) ;
return V_24 ;
}
static int
F_71 ( struct V_21 * V_22 , T_2 * V_230 ,
T_1 V_231 )
{
int V_24 = 0 ;
struct V_339 * V_340 ;
const T_2 V_341 [] = { 0x00 , 0x50 , 0xf2 , 0x01 } ;
const T_2 V_342 [] = { 0x00 , 0x50 , 0xf2 , 0x04 } ;
T_1 V_343 = V_231 ;
int V_344 = 0 ;
if ( ! V_231 ) {
V_22 -> V_345 = 0 ;
V_22 -> V_346 . V_347 = false ;
return 0 ;
} else if ( ! V_230 ) {
return - 1 ;
}
V_340 = (struct V_339 * ) V_230 ;
while ( V_340 ) {
if ( V_340 -> V_348 == V_234 ) {
if ( ! memcmp ( V_340 -> V_349 , V_341 ,
sizeof( V_341 ) ) ) {
V_344 = 1 ;
break;
}
if ( ! memcmp ( V_340 -> V_349 , V_342 ,
sizeof( V_342 ) ) ) {
V_22 -> V_346 . V_347 = true ;
F_5 ( V_22 -> V_12 , V_285 ,
L_40 ) ;
V_24 = F_54 ( V_22 ,
( T_2 * ) V_340 ,
V_343 ) ;
}
}
if ( V_340 -> V_348 == V_236 ) {
V_344 = 1 ;
break;
}
if ( V_340 -> V_348 == V_240 ) {
V_24 = F_53 ( V_22 , ( T_2 * ) V_340 ,
V_343 ) ;
return V_24 ;
}
V_343 -= ( V_340 -> V_48 +
sizeof( struct V_350 ) ) ;
if ( V_343 <= sizeof( struct V_350 ) )
V_340 = NULL ;
else
V_340 = (struct V_339 * )
( ( ( T_2 * ) V_340 ) + V_340 -> V_48 +
sizeof( struct V_350 ) ) ;
}
if ( V_344 ) {
V_24 = F_52 ( V_22 , ( T_2 * ) V_340 ,
V_343 ) ;
V_22 -> V_346 . V_347 = false ;
return V_24 ;
}
if ( V_231 < ( sizeof( V_22 -> V_351 ) - V_22 -> V_345 ) ) {
memcpy ( V_22 -> V_351 + V_22 -> V_345 , V_230 ,
V_231 ) ;
V_22 -> V_345 += V_231 ;
} else {
V_24 = - 1 ;
}
return V_24 ;
}
static int F_72 ( struct V_21 * V_22 ,
struct V_352 * V_353 ,
T_1 V_143 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
switch ( V_353 -> type ) {
case V_354 :
if ( V_143 == V_157 ) {
V_353 -> V_48 = V_22 -> V_233 ;
memcpy ( V_353 -> V_355 , V_22 -> V_232 , V_353 -> V_48 ) ;
} else {
F_71 ( V_22 , V_353 -> V_355 ,
( T_1 ) V_353 -> V_48 ) ;
}
break;
case V_356 :
memset ( V_12 -> V_357 , 0 , sizeof( V_12 -> V_357 ) ) ;
if ( V_353 -> V_48 > V_358 ) {
V_12 -> V_359 = 0 ;
F_5 ( V_12 , ERROR ,
L_41 ) ;
return - 1 ;
} else {
memcpy ( V_12 -> V_357 , V_353 -> V_355 ,
V_353 -> V_48 ) ;
V_12 -> V_359 = V_353 -> V_48 ;
}
break;
default:
F_5 ( V_12 , ERROR , L_42 ) ;
return - 1 ;
}
return 0 ;
}
int
F_73 ( struct V_21 * V_22 , const T_2 * V_360 , int V_231 )
{
struct V_352 V_353 ;
if ( V_231 > V_361 )
return - V_362 ;
V_353 . type = V_354 ;
V_353 . V_48 = V_231 ;
memcpy ( V_353 . V_355 , V_360 , V_231 ) ;
if ( F_72 ( V_22 , & V_353 , V_35 ) )
return - V_362 ;
return 0 ;
}
int F_74 ( struct V_21 * V_22 , T_1 V_143 ,
int V_144 ,
struct V_363 * V_364 )
{
int V_15 = 0 ;
V_15 = F_8 ( V_22 , V_365 ,
V_157 , 0 , V_364 ,
V_144 == V_156 ) ;
return V_15 ;
}
