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
return F_14 ( V_22 -> V_12 , V_40 ) ;
}
void F_15 ( struct V_21 * V_22 )
{
if ( V_22 -> V_12 -> V_76 ) {
char V_77 [] = { L_8 } ;
memcpy ( & V_77 [ 8 ] , V_22 -> V_12 -> V_78 , 2 ) ;
F_16 ( V_22 , V_22 -> V_12 -> V_76 , V_77 ) ;
}
}
static int F_17 ( struct V_21 * V_22 ,
struct V_37 * V_38 )
{
const T_2 * V_79 ;
T_2 V_80 ;
struct V_81 * V_82 =
& V_22 -> V_12 -> V_83 ;
F_10 () ;
V_79 = F_18 ( V_38 , V_84 ) ;
if ( ! V_79 ) {
F_13 () ;
return 0 ;
}
V_80 = V_79 [ 1 ] ;
if ( V_80 < V_85 ) {
F_13 () ;
return 0 ;
}
if ( ! strncmp ( V_22 -> V_12 -> V_78 , & V_79 [ 2 ] , 2 ) ) {
F_13 () ;
F_5 ( V_22 -> V_12 , V_29 ,
L_9 ) ;
return 0 ;
}
memcpy ( V_22 -> V_12 -> V_78 , & V_79 [ 2 ] , 2 ) ;
V_82 -> V_78 [ 0 ] = V_79 [ 2 ] ;
V_82 -> V_78 [ 1 ] = V_79 [ 3 ] ;
V_82 -> V_78 [ 2 ] = ' ' ;
V_80 -= V_86 ;
V_82 -> V_87 =
V_80 / sizeof( struct V_88 ) ;
memcpy ( ( T_2 * ) V_82 -> V_89 ,
& V_79 [ 2 ] + V_86 , V_80 ) ;
F_13 () ;
if ( F_8 ( V_22 , V_90 ,
V_35 , 0 , NULL , false ) ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_10 ) ;
return - 1 ;
}
F_15 ( V_22 ) ;
return 0 ;
}
int F_19 ( struct V_21 * V_22 , struct V_37 * V_38 ,
struct V_91 * V_92 )
{
int V_24 ;
struct V_11 * V_12 = V_22 -> V_12 ;
struct V_39 * V_40 = NULL ;
V_22 -> V_93 = false ;
if ( V_38 ) {
if ( V_12 -> V_94 == 0x00 )
F_17 ( V_22 , V_38 ) ;
V_40 = F_20 ( sizeof( struct V_39 ) ,
V_95 ) ;
if ( ! V_40 )
return - V_52 ;
V_24 = F_9 ( V_22 , V_38 , V_40 ) ;
if ( V_24 )
goto V_96;
}
if ( V_22 -> V_70 == V_72 ||
V_22 -> V_70 == V_97 ) {
T_2 V_98 ;
if ( ! V_40 )
return - 1 ;
if ( F_21 ( V_40 -> V_62 ) ==
V_99 ) {
V_98 = V_100 | V_101 | V_102 ;
} else {
V_98 = V_103 | V_104 ;
if ( V_12 -> V_105 & V_106 )
V_98 |= V_106 ;
}
if ( ! ( ( V_98 | V_12 -> V_105 ) & ~ V_12 -> V_105 ) )
V_12 -> V_98 = V_98 ;
V_24 = F_22 ( V_22 , V_40 ) ;
if ( V_24 )
goto V_96;
if ( F_23 ( V_22 ) ==
( T_2 ) V_40 -> V_107 ) {
F_5 ( V_12 , ERROR ,
L_11 ,
V_40 -> V_107 ) ;
V_24 = - 1 ;
goto V_96;
}
F_5 ( V_12 , V_29 ,
L_12
L_13 ) ;
F_24 ( V_22 -> V_108 , V_12 ) ;
if ( F_25 ( V_22 -> V_108 ) )
F_26 ( V_22 -> V_108 ) ;
V_22 -> V_109 = 0 ;
V_24 = F_27 ( V_22 , V_40 ) ;
if ( V_24 == V_110 &&
V_22 -> V_111 . V_112 &&
V_22 -> V_111 . V_113 ) {
V_22 -> V_111 . V_114 =
V_115 ;
V_24 = F_27 ( V_22 , V_40 ) ;
}
if ( V_38 )
F_28 ( V_22 -> V_12 -> V_116 , V_38 ) ;
} else {
if ( V_40 && V_40 -> V_117 . V_118 &&
( ! F_29 ( & V_22 -> V_119 . V_120 .
V_117 , & V_40 -> V_117 ) ) ) {
V_24 = 0 ;
goto V_96;
}
V_22 -> V_121 = false ;
V_24 = F_22 ( V_22 , V_40 ) ;
F_24 ( V_22 -> V_108 , V_12 ) ;
if ( F_25 ( V_22 -> V_108 ) )
F_26 ( V_22 -> V_108 ) ;
if ( ! V_24 ) {
F_5 ( V_12 , V_29 ,
L_14
L_15 ) ;
V_24 = F_30 ( V_22 , V_40 ) ;
if ( V_38 )
F_28 ( V_22 -> V_12 -> V_116 , V_38 ) ;
} else {
F_5 ( V_12 , V_29 ,
L_16
L_17 ,
V_92 -> V_117 ) ;
V_24 = F_31 ( V_22 , V_92 ) ;
}
}
V_96:
if ( V_40 )
F_32 ( V_40 -> V_56 ) ;
F_32 ( V_40 ) ;
return V_24 ;
}
int F_33 ( struct V_21 * V_22 , T_1 V_122 ,
int V_123 , struct V_124 * V_125 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
int V_15 = 0 ;
T_4 V_126 = 0 ;
if ( ! V_125 )
return - V_52 ;
switch ( V_122 ) {
case V_35 :
if ( V_12 -> V_127 ) {
F_5 ( V_12 , V_29 ,
L_18
L_19 ) ;
V_15 = - 1 ;
break;
}
if ( V_125 -> V_128 ) {
if ( V_125 -> V_129 == V_130 ) {
if ( ! V_12 -> V_131 )
break;
V_126 = F_34 ( V_12 -> V_125
. V_129 ) ;
V_12 -> V_125 . V_129 =
F_35 ( V_125 -> V_129 ) ;
} else if ( V_125 -> V_129 ) {
V_12 -> V_125 . V_129 =
F_35 ( V_125 -> V_129 ) ;
V_12 -> V_125 . V_132 = ( T_2 ) V_125 -> V_132 ;
if ( V_125 -> V_133 )
V_12 -> V_125 . V_133 = ( T_2 ) V_125 -> V_133 ;
} else if ( V_12 -> V_125 . V_129 ==
F_35 ( V_130 ) ) {
V_15 = - 1 ;
break;
}
V_15 = F_8 ( V_22 ,
V_134 ,
V_35 , 0 ,
& V_12 -> V_125 ,
V_123 == V_135 ) ;
if ( V_125 -> V_129 == V_130 )
V_12 -> V_125 . V_129 =
F_35 ( V_126 ) ;
} else {
V_12 -> V_125 . V_129 =
F_35 ( V_125 -> V_129 ) ;
V_12 -> V_125 . V_132 = ( T_2 ) V_125 -> V_132 ;
V_12 -> V_125 . V_133 = ( T_2 ) V_125 -> V_133 ;
}
break;
case V_136 :
V_125 -> V_129 = F_34 ( V_12 -> V_125 . V_129 ) ;
V_125 -> V_132 = V_12 -> V_125 . V_132 ;
V_125 -> V_133 = V_12 -> V_125 . V_133 ;
break;
default:
V_15 = - 1 ;
break;
}
return V_15 ;
}
int F_36 ( struct V_21 * V_22 , int V_123 )
{
struct V_124 V_137 ;
V_137 . V_129 = V_130 ;
V_137 . V_128 = true ;
return F_33 ( V_22 , V_35 ,
V_123 , & V_137 ) ;
}
int F_37 ( struct V_11 * V_12 )
{
struct V_124 V_137 ;
struct V_21 * V_22 ;
int V_5 ;
if ( V_138 ) {
for ( V_5 = 0 ; V_5 < V_12 -> V_139 ; V_5 ++ ) {
V_22 = V_12 -> V_22 [ V_5 ] ;
if ( V_22 )
F_38 ( V_22 , NULL ) ;
}
}
V_22 = F_39 ( V_12 , V_140 ) ;
if ( V_22 && V_22 -> V_141 ) {
#ifdef F_40
if ( ! V_22 -> V_142 . V_116 -> V_143 -> V_144 ) {
#endif
F_5 ( V_12 , V_145 , L_20 ) ;
F_41 ( V_22 ) ;
F_42 ( V_22 -> V_142 . V_116 ) ;
#ifdef F_40
}
#endif
}
if ( V_12 -> V_146 ) {
F_5 ( V_12 , V_145 ,
L_21 ) ;
return true ;
}
V_12 -> V_147 = false ;
memset ( & V_137 , 0 , sizeof( struct V_124 ) ) ;
V_137 . V_128 = true ;
V_12 -> V_148 = true ;
F_6 ( V_12 ) ;
if ( F_33 ( F_39 ( V_12 ,
V_140 ) ,
V_35 , V_135 ,
& V_137 ) ) {
F_5 ( V_12 , ERROR ,
L_22 ) ;
return false ;
}
if ( F_4 ( V_12 -> V_149 ,
V_12 -> V_147 ,
( 10 * V_19 ) ) <= 0 ) {
F_5 ( V_12 , ERROR ,
L_23 ) ;
return false ;
}
return true ;
}
int F_43 ( struct V_21 * V_22 ,
struct V_150 * V_151 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
struct V_39 * V_40 ;
if ( ! V_151 )
return - 1 ;
V_40 = & V_22 -> V_119 . V_120 ;
V_151 -> V_70 = V_22 -> V_70 ;
memcpy ( & V_151 -> V_117 , & V_40 -> V_117 , sizeof( struct V_91 ) ) ;
memcpy ( & V_151 -> V_54 , & V_40 -> V_53 , V_10 ) ;
V_151 -> V_152 = V_40 -> V_107 ;
memcpy ( V_151 -> V_78 , V_12 -> V_78 ,
V_86 ) ;
V_151 -> V_153 = V_22 -> V_153 ;
V_151 -> V_154 = V_22 -> V_155 ;
V_151 -> V_156 = V_22 -> V_157 ;
V_151 -> V_158 = V_22 -> V_158 ;
V_151 -> V_159 = V_22 -> V_159 ;
if ( V_22 -> V_111 . V_113 )
V_151 -> V_160 = true ;
else
V_151 -> V_160 = false ;
V_151 -> V_131 = V_12 -> V_131 ;
V_151 -> V_161 = V_12 -> V_161 ;
return 0 ;
}
int F_44 ( struct V_21 * V_22 )
{
struct V_162 V_163 ;
V_163 . V_163 = V_164 ;
return F_8 ( V_22 , V_165 ,
V_166 , V_167 , & V_163 , true ) ;
}
int F_45 ( struct V_21 * V_22 , T_4 * V_168 )
{
int V_24 ;
V_24 = F_8 ( V_22 , V_169 ,
V_136 , 0 , NULL , true ) ;
if ( ! V_24 ) {
if ( V_22 -> V_170 )
* V_168 = F_46 ( V_22 , V_22 -> V_171 ,
V_22 -> V_172 ) ;
else
* V_168 = V_22 -> V_173 ;
}
return V_24 ;
}
int F_47 ( struct V_21 * V_22 ,
struct V_174 * V_175 )
{
int V_24 ;
struct V_176 * V_177 ;
struct V_178 * V_179 ;
struct V_180 * V_181 ;
T_2 * V_182 ;
T_1 V_183 = 0 ;
if ( ! V_175 -> V_184 ) {
V_183 = ( T_1 ) V_175 -> V_185 ;
if ( ( V_183 < V_22 -> V_157 ) ||
( V_183 > V_22 -> V_155 ) ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_24
L_25 ,
V_183 , V_22 -> V_157 ,
V_22 -> V_155 ) ;
return - 1 ;
}
}
V_182 = F_20 ( V_186 , V_95 ) ;
if ( ! V_182 )
return - V_52 ;
V_177 = (struct V_176 * ) V_182 ;
V_177 -> V_122 = F_48 ( V_35 ) ;
if ( ! V_175 -> V_184 ) {
V_177 -> V_27 = F_35 ( 1 ) ;
V_179 = (struct V_178 * )
( V_182 + sizeof( struct V_176 ) ) ;
V_179 -> type = F_48 ( V_187 ) ;
V_179 -> V_188 =
F_48 ( 4 * sizeof( struct V_180 ) ) ;
V_181 = (struct V_180 * )
( V_182 + sizeof( struct V_176 )
+ sizeof( struct V_178 ) ) ;
V_181 -> V_189 = 0x00 ;
V_181 -> V_190 = 0x03 ;
V_181 -> V_191 = V_192 ;
V_181 -> V_193 = 0 ;
V_181 -> V_194 = ( V_195 ) V_183 ;
V_181 -> V_196 = ( V_195 ) V_183 ;
V_181 ++ ;
V_181 -> V_189 = 0x00 ;
V_181 -> V_190 = 0x07 ;
V_181 -> V_191 = V_197 ;
V_181 -> V_193 = 0 ;
V_181 -> V_194 = ( V_195 ) V_183 ;
V_181 -> V_196 = ( V_195 ) V_183 ;
V_181 ++ ;
V_181 -> V_189 = 0x00 ;
V_181 -> V_190 = 0x20 ;
V_181 -> V_191 = V_198 ;
V_181 -> V_193 = 0 ;
V_181 -> V_194 = ( V_195 ) V_183 ;
V_181 -> V_196 = ( V_195 ) V_183 ;
V_181 -> V_199 = V_200 ;
V_181 ++ ;
V_181 -> V_189 = 0x00 ;
V_181 -> V_190 = 0x20 ;
V_181 -> V_191 = V_198 ;
V_181 -> V_193 = 0 ;
V_181 -> V_194 = ( V_195 ) V_183 ;
V_181 -> V_196 = ( V_195 ) V_183 ;
V_181 -> V_199 = V_201 ;
}
V_24 = F_8 ( V_22 , V_202 ,
V_35 , 0 , V_182 , true ) ;
F_32 ( V_182 ) ;
return V_24 ;
}
int F_49 ( struct V_21 * V_22 , T_4 * V_203 )
{
int V_24 ;
struct V_11 * V_12 = V_22 -> V_12 ;
T_1 V_204 ;
if ( * V_203 )
V_12 -> V_203 = V_205 ;
else
V_12 -> V_203 = V_206 ;
V_204 = ( * V_203 ) ? V_207 : V_166 ;
V_24 = F_8 ( V_22 , V_165 ,
V_204 , V_208 , NULL , true ) ;
if ( ( ! V_24 ) && ( V_204 == V_166 ) )
V_24 = F_8 ( V_22 , V_165 ,
V_209 , 0 , NULL , false ) ;
return V_24 ;
}
static int F_50 ( struct V_21 * V_22 ,
T_2 * V_210 , T_1 V_211 )
{
if ( V_211 ) {
if ( V_211 > sizeof( V_22 -> V_212 ) ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_26 ) ;
return - 1 ;
}
memcpy ( V_22 -> V_212 , V_210 , V_211 ) ;
V_22 -> V_213 = V_211 ;
F_5 ( V_22 -> V_12 , V_145 ,
L_27 ,
V_22 -> V_213 , V_22 -> V_212 [ 0 ] ) ;
if ( V_22 -> V_212 [ 0 ] == V_214 ) {
V_22 -> V_111 . V_215 = true ;
} else if ( V_22 -> V_212 [ 0 ] == V_216 ) {
V_22 -> V_111 . V_217 = true ;
} else {
V_22 -> V_111 . V_215 = false ;
V_22 -> V_111 . V_217 = false ;
}
} else {
memset ( V_22 -> V_212 , 0 , sizeof( V_22 -> V_212 ) ) ;
V_22 -> V_213 = 0 ;
F_5 ( V_22 -> V_12 , V_29 ,
L_28 ,
V_22 -> V_213 , V_22 -> V_212 [ 0 ] ) ;
V_22 -> V_111 . V_215 = false ;
V_22 -> V_111 . V_217 = false ;
}
return 0 ;
}
static int F_51 ( struct V_21 * V_22 ,
T_2 * V_210 , T_1 V_211 )
{
if ( V_211 ) {
if ( V_211 > sizeof( V_22 -> V_218 ) ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_29 ) ;
return - 1 ;
}
memcpy ( V_22 -> V_218 , V_210 , V_211 ) ;
V_22 -> V_219 = V_211 ;
F_5 ( V_22 -> V_12 , V_145 ,
L_30 ,
V_22 -> V_219 , V_22 -> V_218 [ 0 ] ) ;
if ( V_22 -> V_218 [ 0 ] == V_220 )
V_22 -> V_111 . V_221 = true ;
} else {
memset ( V_22 -> V_218 , 0 , sizeof( V_22 -> V_218 ) ) ;
V_22 -> V_219 = V_211 ;
F_5 ( V_22 -> V_12 , V_29 ,
L_31 ,
V_22 -> V_219 , V_22 -> V_218 [ 0 ] ) ;
V_22 -> V_111 . V_221 = false ;
}
return 0 ;
}
static int F_52 ( struct V_21 * V_22 ,
T_2 * V_210 , T_1 V_211 )
{
if ( V_211 ) {
if ( V_211 > V_222 ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_32 ) ;
return - 1 ;
}
V_22 -> V_223 = F_20 ( V_222 , V_95 ) ;
if ( ! V_22 -> V_223 )
return - V_52 ;
memcpy ( V_22 -> V_223 , V_210 , V_211 ) ;
V_22 -> V_224 = V_211 ;
F_5 ( V_22 -> V_12 , V_145 ,
L_33 ,
V_22 -> V_224 , V_22 -> V_223 [ 0 ] ) ;
} else {
F_32 ( V_22 -> V_223 ) ;
V_22 -> V_224 = V_211 ;
F_5 ( V_22 -> V_12 , V_29 ,
L_34 , V_22 -> V_224 ) ;
}
return 0 ;
}
static int F_53 ( struct V_21 * V_22 ,
struct V_225 * V_226 )
{
return F_8 ( V_22 , V_227 ,
V_35 , V_228 ,
V_226 , true ) ;
}
static int F_54 ( struct V_21 * V_22 ,
struct V_225 * V_226 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
int V_24 ;
struct V_229 * V_230 ;
int V_231 ;
if ( V_22 -> V_232 >= V_233 )
V_22 -> V_232 = 0 ;
V_230 = & V_22 -> V_230 [ V_22 -> V_232 ] ;
V_231 = V_226 -> V_234 ;
if ( V_226 -> V_235 ) {
V_22 -> V_111 . V_113 = 0 ;
} else if ( ! V_226 -> V_236 ) {
V_230 = & V_22 -> V_230 [ V_231 ] ;
if ( ! V_230 -> V_237 ) {
F_5 ( V_12 , ERROR ,
L_35 ) ;
return - 1 ;
}
if ( V_12 -> V_238 == V_239 ) {
memcpy ( V_226 -> V_240 ,
V_230 -> V_240 , V_230 -> V_237 ) ;
V_226 -> V_236 = V_230 -> V_237 ;
}
V_22 -> V_232 = ( T_1 ) V_231 ;
V_22 -> V_111 . V_113 = 1 ;
} else {
V_230 = & V_22 -> V_230 [ V_231 ] ;
memset ( V_230 , 0 , sizeof( struct V_229 ) ) ;
memcpy ( V_230 -> V_240 ,
V_226 -> V_240 ,
V_226 -> V_236 ) ;
V_230 -> V_234 = V_231 ;
V_230 -> V_237 = V_226 -> V_236 ;
V_22 -> V_111 . V_113 = 1 ;
}
if ( V_230 -> V_237 ) {
void * V_241 ;
if ( V_226 -> V_235 ) {
memset ( & V_22 -> V_230 [ V_231 ] , 0 ,
sizeof( struct V_229 ) ) ;
goto V_96;
}
if ( V_12 -> V_238 == V_239 )
V_241 = V_226 ;
else
V_241 = NULL ;
V_24 = F_8 ( V_22 , V_227 ,
V_35 , 0 , V_241 , false ) ;
if ( V_24 )
return V_24 ;
}
V_96:
if ( V_22 -> V_111 . V_113 )
V_22 -> V_26 |= V_242 ;
else
V_22 -> V_26 &= ~ V_242 ;
V_24 = F_8 ( V_22 , V_36 ,
V_35 , 0 ,
& V_22 -> V_26 , true ) ;
return V_24 ;
}
static int F_55 ( struct V_21 * V_22 ,
struct V_225 * V_226 )
{
int V_24 ;
T_2 V_243 = false ;
struct V_244 * V_245 ;
if ( V_226 -> V_236 > V_246 ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_36 ) ;
return - 1 ;
}
if ( V_22 -> V_70 == V_71 ) {
V_226 -> V_234 = V_247 ;
V_24 = F_8 ( V_22 , V_227 ,
V_35 ,
V_228 , V_226 , false ) ;
if ( V_24 )
return V_24 ;
V_245 = & V_22 -> V_248 ;
memset ( V_245 , 0 ,
sizeof( struct V_244 ) ) ;
memcpy ( V_245 -> V_249 . V_250 , V_226 -> V_240 ,
V_226 -> V_236 ) ;
memcpy ( & V_245 -> V_249 . V_236 , & V_226 -> V_236 ,
sizeof( V_245 -> V_249 . V_236 ) ) ;
V_245 -> V_249 . V_251
= F_48 ( V_252 ) ;
V_245 -> V_249 . V_253 = F_48 ( V_254 ) ;
V_226 -> V_234 = ~ V_247 ;
}
if ( ! V_226 -> V_234 )
V_226 -> V_234 = V_247 ;
if ( V_243 )
V_24 = F_8 ( V_22 , V_227 ,
V_35 ,
! V_228 , V_226 , true ) ;
else
V_24 = F_8 ( V_22 , V_227 ,
V_35 ,
V_228 , V_226 , true ) ;
return V_24 ;
}
static int
F_56 ( struct V_21 * V_22 ,
struct V_225 * V_226 )
{
int V_15 ;
if ( V_226 -> V_255 )
V_15 = F_53 ( V_22 , V_226 ) ;
else if ( V_226 -> V_236 > V_256 )
V_15 = F_55 ( V_22 , V_226 ) ;
else
V_15 = F_54 ( V_22 , V_226 ) ;
return V_15 ;
}
int
F_57 ( struct V_11 * V_12 , char * V_257 ,
int V_258 )
{
union {
T_5 V_259 ;
T_2 V_260 [ 4 ] ;
} V_261 ;
char V_262 [ 32 ] ;
V_261 . V_259 = F_35 ( V_12 -> V_263 ) ;
sprintf ( V_262 , L_37 , V_261 . V_260 [ 2 ] , V_261 . V_260 [ 1 ] , V_261 . V_260 [ 0 ] , V_261 . V_260 [ 3 ] ) ;
snprintf ( V_257 , V_258 , V_264 , V_262 ) ;
F_5 ( V_12 , V_265 , L_38 , V_257 ) ;
return 0 ;
}
int F_58 ( struct V_21 * V_22 , struct V_266 * V_267 ,
const T_2 * V_250 , int V_236 , T_2 V_234 ,
const T_2 * V_268 , int V_269 )
{
struct V_225 V_226 ;
memset ( & V_226 , 0 , sizeof( struct V_225 ) ) ;
V_226 . V_236 = V_236 ;
V_226 . V_234 = V_234 ;
if ( V_267 && V_267 -> V_270 == V_271 )
V_226 . V_272 = true ;
if ( ! V_269 ) {
if ( V_236 )
memcpy ( V_226 . V_240 , V_250 , V_236 ) ;
else
V_226 . V_273 = true ;
if ( V_268 )
memcpy ( V_226 . V_268 , V_268 , V_10 ) ;
if ( V_267 && V_267 -> V_274 && V_267 -> V_275 ) {
memcpy ( V_226 . V_276 , V_267 -> V_274 , V_267 -> V_275 ) ;
V_226 . V_277 = V_267 -> V_275 ;
V_226 . V_278 = true ;
}
} else {
if ( F_59 ( V_22 ) == V_279 )
return 0 ;
V_226 . V_235 = true ;
if ( V_268 )
memcpy ( V_226 . V_268 , V_268 , V_10 ) ;
}
return F_56 ( V_22 , & V_226 ) ;
}
int
F_60 ( struct V_21 * V_22 , T_4 V_280 )
{
struct V_281 V_282 ;
memset ( & V_282 , 0 , sizeof( struct V_283 ) ) ;
V_282 . V_280 = V_280 ;
if ( F_8 ( V_22 , V_284 ,
V_136 , 0 , & V_282 , true ) )
return - 1 ;
return 0 ;
}
int
F_61 ( struct V_21 * V_22 , T_1 V_122 ,
struct V_285 * V_286 ,
unsigned int V_287 )
{
struct V_288 V_289 ;
T_2 V_290 ;
memset ( & V_289 , 0 , sizeof( V_289 ) ) ;
V_289 . V_122 = F_48 ( V_122 ) ;
if ( V_122 == V_35 ) {
V_289 . V_291 = V_286 -> V_63 ;
V_290 = F_62 ( V_292 ) ;
V_289 . V_291 |= ( V_290 << 2 ) ;
V_289 . V_107 =
F_63 ( V_286 -> V_293 ) ;
V_289 . V_287 = F_35 ( V_287 ) ;
}
if ( F_8 ( V_22 , V_294 ,
V_122 , 0 , & V_289 , true ) ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_39 ) ;
return - 1 ;
}
return V_289 . V_15 ;
}
int
F_64 ( struct V_21 * V_22 ,
struct V_295 * log )
{
return F_8 ( V_22 , V_296 ,
V_136 , 0 , log , true ) ;
}
static int F_65 ( struct V_21 * V_22 ,
struct V_297 * V_298 ,
T_1 V_122 )
{
T_1 V_299 ;
switch ( F_34 ( V_298 -> type ) ) {
case V_300 :
V_299 = V_301 ;
break;
case V_302 :
V_299 = V_303 ;
break;
case V_304 :
V_299 = V_305 ;
break;
case V_306 :
V_299 = V_307 ;
break;
case V_308 :
V_299 = V_309 ;
break;
default:
return - 1 ;
}
return F_8 ( V_22 , V_299 , V_122 , 0 , V_298 , true ) ;
}
int
F_66 ( struct V_21 * V_22 , T_4 V_310 ,
T_4 V_311 , T_4 V_312 )
{
struct V_297 V_298 ;
V_298 . type = F_35 ( V_310 ) ;
V_298 . V_313 = F_35 ( V_311 ) ;
V_298 . V_314 = F_35 ( V_312 ) ;
return F_65 ( V_22 , & V_298 , V_35 ) ;
}
int
F_67 ( struct V_21 * V_22 , T_4 V_310 ,
T_4 V_311 , T_4 * V_314 )
{
int V_24 ;
struct V_297 V_298 ;
V_298 . type = F_35 ( V_310 ) ;
V_298 . V_313 = F_35 ( V_311 ) ;
V_24 = F_65 ( V_22 , & V_298 , V_136 ) ;
if ( V_24 )
goto V_96;
* V_314 = F_34 ( V_298 . V_314 ) ;
V_96:
return V_24 ;
}
int
F_68 ( struct V_21 * V_22 , T_1 V_313 , T_1 V_315 ,
T_2 * V_314 )
{
int V_24 ;
struct V_316 V_317 ;
V_317 . V_313 = F_48 ( ( T_1 ) V_313 ) ;
V_317 . V_318 = F_48 ( ( T_1 ) V_315 ) ;
V_24 = F_8 ( V_22 , V_319 ,
V_136 , 0 , & V_317 , true ) ;
if ( ! V_24 )
memcpy ( V_314 , V_317 . V_314 , V_320 ) ;
return V_24 ;
}
static int
F_69 ( struct V_21 * V_22 , T_2 * V_210 ,
T_1 V_211 )
{
int V_24 = 0 ;
struct V_321 * V_322 ;
const T_2 V_323 [] = { 0x00 , 0x50 , 0xf2 , 0x01 } ;
const T_2 V_324 [] = { 0x00 , 0x50 , 0xf2 , 0x04 } ;
T_1 V_325 = V_211 ;
int V_326 = 0 ;
if ( ! V_211 ) {
V_22 -> V_327 = 0 ;
V_22 -> V_328 . V_329 = false ;
return 0 ;
} else if ( ! V_210 ) {
return - 1 ;
}
V_322 = (struct V_321 * ) V_210 ;
while ( V_322 ) {
if ( V_322 -> V_330 == V_214 ) {
if ( ! memcmp ( V_322 -> V_331 , V_323 ,
sizeof( V_323 ) ) ) {
V_326 = 1 ;
break;
}
if ( ! memcmp ( V_322 -> V_331 , V_324 ,
sizeof( V_324 ) ) ) {
V_22 -> V_328 . V_329 = true ;
F_5 ( V_22 -> V_12 , V_265 ,
L_40 ) ;
V_24 = F_52 ( V_22 ,
( T_2 * ) V_322 ,
V_325 ) ;
}
}
if ( V_322 -> V_330 == V_216 ) {
V_326 = 1 ;
break;
}
if ( V_322 -> V_330 == V_220 ) {
V_24 = F_51 ( V_22 , ( T_2 * ) V_322 ,
V_325 ) ;
return V_24 ;
}
V_325 -= ( V_322 -> V_48 +
sizeof( struct V_332 ) ) ;
if ( V_325 <= sizeof( struct V_332 ) )
V_322 = NULL ;
else
V_322 = (struct V_321 * )
( ( ( T_2 * ) V_322 ) + V_322 -> V_48 +
sizeof( struct V_332 ) ) ;
}
if ( V_326 ) {
V_24 = F_50 ( V_22 , ( T_2 * ) V_322 ,
V_325 ) ;
V_22 -> V_328 . V_329 = false ;
return V_24 ;
}
if ( V_211 < ( sizeof( V_22 -> V_333 ) - V_22 -> V_327 ) ) {
memcpy ( V_22 -> V_333 + V_22 -> V_327 , V_210 ,
V_211 ) ;
V_22 -> V_327 += V_211 ;
} else {
V_24 = - 1 ;
}
return V_24 ;
}
static int F_70 ( struct V_21 * V_22 ,
struct V_334 * V_335 ,
T_1 V_122 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
switch ( V_335 -> type ) {
case V_336 :
if ( V_122 == V_136 ) {
V_335 -> V_48 = V_22 -> V_213 ;
memcpy ( V_335 -> V_337 , V_22 -> V_212 , V_335 -> V_48 ) ;
} else {
F_69 ( V_22 , V_335 -> V_337 ,
( T_1 ) V_335 -> V_48 ) ;
}
break;
case V_338 :
memset ( V_12 -> V_339 , 0 , sizeof( V_12 -> V_339 ) ) ;
if ( V_335 -> V_48 > V_340 ) {
V_12 -> V_341 = 0 ;
F_5 ( V_12 , ERROR ,
L_41 ) ;
return - 1 ;
} else {
memcpy ( V_12 -> V_339 , V_335 -> V_337 ,
V_335 -> V_48 ) ;
V_12 -> V_341 = V_335 -> V_48 ;
}
break;
default:
F_5 ( V_12 , ERROR , L_42 ) ;
return - 1 ;
}
return 0 ;
}
int
F_71 ( struct V_21 * V_22 , const T_2 * V_342 , int V_211 )
{
struct V_334 V_335 ;
if ( V_211 > V_343 )
return - V_344 ;
V_335 . type = V_336 ;
V_335 . V_48 = V_211 ;
memcpy ( V_335 . V_337 , V_342 , V_211 ) ;
if ( F_70 ( V_22 , & V_335 , V_35 ) )
return - V_344 ;
return 0 ;
}
int F_72 ( struct V_21 * V_22 , T_1 V_122 ,
int V_123 ,
struct V_345 * V_346 )
{
int V_15 = 0 ;
V_15 = F_8 ( V_22 , V_347 ,
V_136 , 0 , V_346 ,
V_123 == V_135 ) ;
return V_15 ;
}
