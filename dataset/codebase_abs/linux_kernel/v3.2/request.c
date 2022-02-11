static struct V_1 * F_1 ( struct V_2 * V_3 ,
int V_4 )
{
if ( V_4 == 0 )
return & V_3 -> V_5 -> V_6 ;
else if ( V_4 == 1 )
return & V_3 -> V_5 -> V_7 ;
else if ( V_4 < 0 )
return NULL ;
else
return & V_3 -> V_8 [ V_4 - 2 ] ;
}
static T_1 F_2 ( struct V_9 * V_10 ,
struct V_2 * V_3 , T_2 V_4 )
{
T_2 V_11 ;
if ( V_4 == 0 ) {
V_11 = ( void * ) & V_3 -> V_5 -> V_6 -
( void * ) & V_10 -> V_12 [ 0 ] ;
return V_10 -> V_13 + V_11 ;
} else if ( V_4 == 1 ) {
V_11 = ( void * ) & V_3 -> V_5 -> V_7 -
( void * ) & V_10 -> V_12 [ 0 ] ;
return V_10 -> V_13 + V_11 ;
}
return F_3 ( V_3 , & V_3 -> V_8 [ V_4 - 2 ] ) ;
}
static void F_4 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
V_15 -> V_18 = F_5 ( V_17 ) ;
V_15 -> V_19 = F_6 ( F_7 ( V_17 ) ) ;
V_15 -> V_20 = F_8 ( F_7 ( V_17 ) ) ;
V_15 -> V_21 = 0 ;
}
static void F_9 ( struct V_2 * V_3 )
{
struct V_9 * V_10 = V_3 -> V_9 ;
struct V_22 * V_23 = F_10 ( V_3 ) ;
struct V_16 * V_17 = NULL ;
T_1 V_24 ;
T_2 V_25 = 0 ;
struct V_1 * V_26 = NULL ;
struct V_1 * V_27 = NULL ;
if ( V_23 -> V_28 > 0 ) {
V_17 = V_23 -> V_29 ;
while ( V_17 ) {
V_26 = F_1 ( V_3 , V_25 ) ;
F_4 ( & V_26 -> V_30 , V_17 ) ;
V_17 = F_11 ( V_17 ) ;
if ( V_17 ) {
F_4 ( & V_26 -> V_31 , V_17 ) ;
V_17 = F_11 ( V_17 ) ;
} else
memset ( & V_26 -> V_31 , 0 , sizeof( V_26 -> V_31 ) ) ;
if ( V_27 ) {
V_24 = F_2 ( V_10 ,
V_3 ,
V_25 ) ;
V_27 -> V_32 =
F_6 ( V_24 ) ;
V_27 -> V_33 =
F_8 ( V_24 ) ;
}
V_27 = V_26 ;
V_25 ++ ;
}
} else {
V_26 = F_1 ( V_3 , V_25 ) ;
V_24 = F_12 ( & V_10 -> V_34 -> V_35 ,
V_23 -> V_29 ,
V_23 -> V_36 ,
V_23 -> V_37 ) ;
V_3 -> V_38 = V_24 ;
V_26 -> V_30 . V_18 = V_23 -> V_36 ;
V_26 -> V_30 . V_19 = F_6 ( V_24 ) ;
V_26 -> V_30 . V_20 = F_8 ( V_24 ) ;
}
if ( V_26 ) {
V_26 -> V_32 = 0 ;
V_26 -> V_33 = 0 ;
}
}
static void F_13 ( struct V_2 * V_3 )
{
struct V_39 * V_40 ;
struct V_22 * V_23 = F_10 ( V_3 ) ;
V_40 = & V_3 -> V_41 . V_42 ;
memcpy ( V_40 -> V_43 , V_23 -> V_44 . V_43 , 8 ) ;
V_40 -> V_45 = 0 ;
V_40 -> V_46 = 0 ;
V_40 -> V_47 = 0 ;
V_40 -> V_48 = 0 ;
V_40 -> V_49 = V_23 -> V_44 . V_49 ;
V_40 -> V_50 = V_23 -> V_44 . V_50 ;
V_40 -> V_51 = 0 ;
F_14 ( & V_40 -> V_52 , V_23 -> V_44 . V_52 ,
sizeof( V_23 -> V_44 . V_52 ) / sizeof( T_2 ) ) ;
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_53 * V_54 ;
struct V_22 * V_23 = F_10 ( V_3 ) ;
struct V_55 * V_55 = F_16 ( V_3 ) ;
V_54 = & V_3 -> V_41 . V_56 ;
memset ( V_54 , 0 , sizeof( struct V_53 ) ) ;
memcpy ( V_54 -> V_43 , V_23 -> V_44 . V_43 , 8 ) ;
V_54 -> V_57 = V_55 -> V_58 ;
V_54 -> V_59 =
( F_17 ( V_60 , & V_3 -> V_61 ) ) ?
V_55 -> V_62 :
V_63 ;
}
static void F_18 (
struct V_2 * V_3 ,
struct V_64 * V_65 )
{
T_1 V_24 ;
struct V_66 * V_67 ;
struct V_68 * V_69 ;
V_67 = V_3 -> V_70 ;
V_69 = V_67 -> V_71 ;
V_65 -> abort = 0 ;
V_65 -> V_72 = 0 ;
V_65 -> V_73 = 1 ;
V_65 -> V_74 = V_67 -> V_74 ;
V_65 -> V_75 = V_76 ;
V_65 -> V_77 = V_69 -> V_78 ;
V_65 -> V_79 = V_80 ;
V_65 -> V_81 = V_82 ;
V_65 -> V_83 = V_84 ;
V_65 -> V_85 = V_67 -> V_86 . V_85 ;
V_65 -> V_87 = 0 ;
V_65 -> V_88 = 0 ;
V_65 -> V_89 = 1 ;
V_65 -> V_90 = 0 ;
V_65 -> V_91 = 0 ;
V_65 -> V_92 = 0 ;
V_65 -> V_93 = 0 ;
V_65 -> V_21 = 0 ;
V_65 -> V_94 = 0x01 ;
V_3 -> V_95 = ( V_96 |
( V_76 << V_97 ) |
( V_69 -> V_78 <<
V_98 ) |
F_19 ( V_3 -> V_62 ) ) ;
V_24 = F_3 ( V_3 , & V_3 -> V_41 . V_42 ) ;
V_65 -> V_99 = F_6 ( V_24 ) ;
V_65 -> V_100 = F_8 ( V_24 ) ;
V_24 = F_3 ( V_3 , & V_3 -> V_41 . V_101 ) ;
V_65 -> V_102 = F_6 ( V_24 ) ;
V_65 -> V_103 = F_8 ( V_24 ) ;
}
static void F_20 ( struct V_2 * V_3 ,
enum V_104 V_105 ,
T_2 V_106 )
{
struct V_64 * V_65 = V_3 -> V_5 ;
F_18 ( V_3 , V_65 ) ;
V_65 -> V_107 =
sizeof( struct V_39 ) / sizeof( T_2 ) ;
V_65 -> type . V_41 . V_108 = V_109 ;
switch ( V_105 ) {
case V_110 :
case V_111 :
default:
V_65 -> V_112 = V_113 ;
break;
case V_114 :
V_65 -> V_112 = V_115 ;
break;
}
V_65 -> V_116 = V_106 ;
if ( V_65 -> V_116 > 0 )
F_9 ( V_3 ) ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_64 * V_65 = V_3 -> V_5 ;
F_18 ( V_3 , V_65 ) ;
V_65 -> V_91 = 1 ;
V_65 -> V_72 = V_117 ;
V_65 -> V_112 = V_118 ;
V_65 -> V_116 = 0 ;
V_65 -> type . V_41 . V_108 = V_119 ;
V_65 -> V_107 =
sizeof( struct V_53 ) / sizeof( T_2 ) ;
}
static void F_22 (
struct V_2 * V_3 ,
struct V_64 * V_65 )
{
T_1 V_24 ;
struct V_66 * V_67 ;
struct V_68 * V_69 ;
V_67 = V_3 -> V_70 ;
V_69 = V_67 -> V_71 ;
V_65 -> abort = 0 ;
V_65 -> V_72 = V_120 ;
V_65 -> V_73 = 1 ;
V_65 -> V_74 = V_67 -> V_74 ;
V_65 -> V_75 = V_76 ;
V_65 -> V_77 = V_69 -> V_78 ;
V_65 -> V_79 = V_121 ;
V_65 -> V_81 = V_82 ;
V_65 -> V_83 = V_84 ;
V_65 -> V_85 = V_67 -> V_86 . V_85 ;
V_65 -> V_87 = 0 ;
V_65 -> V_88 = 0 ;
V_65 -> V_89 = 1 ;
V_65 -> V_90 = 0 ;
V_65 -> V_91 = 0 ;
V_65 -> V_92 = 0 ;
V_65 -> V_93 = 0 ;
V_65 -> V_21 = 0 ;
V_65 -> V_94 = 0x01 ;
V_65 -> V_107 =
( sizeof( struct V_122 ) - sizeof( T_2 ) ) / sizeof( T_2 ) ;
V_65 -> type . V_123 [ 0 ] = * ( T_2 * ) & V_3 -> V_124 . V_42 ;
V_3 -> V_95 = ( V_96 |
( V_76 << V_97 ) |
( V_69 -> V_78 <<
V_98 ) |
F_19 ( V_3 -> V_62 ) ) ;
V_24 = F_3 ( V_3 ,
( ( char * ) & V_3 -> V_124 . V_42 ) +
sizeof( T_2 ) ) ;
V_65 -> V_99 = F_6 ( V_24 ) ;
V_65 -> V_100 = F_8 ( V_24 ) ;
V_65 -> V_102 = 0 ;
V_65 -> V_103 = 0 ;
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_64 * V_65 = V_3 -> V_5 ;
F_22 ( V_3 , V_65 ) ;
V_65 -> V_91 = 0 ;
V_65 -> V_72 = V_120 ;
V_65 -> V_112 = V_125 ;
V_65 -> type . V_124 . V_126 = V_127 ;
V_65 -> V_116 = sizeof( struct V_122 ) - sizeof( T_2 ) ;
}
static enum V_128 F_24 ( struct V_2 * V_3 ,
bool V_129 )
{
struct V_130 * V_131 = & V_3 -> V_124 . V_132 ;
F_23 ( V_3 ) ;
V_131 -> V_133 = 0 ;
V_131 -> V_134 . V_11 = 0 ;
V_131 -> V_134 . V_135 = V_136 ;
if ( V_129 ) {
F_9 ( V_3 ) ;
V_131 -> V_134 . V_137 = 0 ;
} else {
V_131 -> V_134 . V_137 = - 1 ;
}
return V_138 ;
}
static void F_25 ( struct V_2 * V_3 ,
T_3 V_139 ,
T_2 V_106 ,
enum V_104 V_105 )
{
struct V_64 * V_65 = V_3 -> V_5 ;
F_22 ( V_3 , V_65 ) ;
F_9 ( V_3 ) ;
V_65 -> V_116 = V_106 ;
if ( V_105 == V_114 ) {
V_65 -> V_112 = V_139 + ( V_140
- V_141 ) ;
} else {
V_65 -> V_112 = V_139 ;
}
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_122 * V_142 = & V_3 -> V_124 . V_42 ;
struct V_22 * V_23 ;
V_142 -> V_143 |= V_144 ;
F_23 ( V_3 ) ;
V_23 = F_10 ( V_3 ) ;
if ( V_23 -> V_37 == V_111 )
V_23 -> V_36 = 0 ;
V_3 -> V_124 . V_101 . V_126 = 0 ;
}
static enum V_128
F_27 ( struct V_2 * V_3 ,
T_2 V_106 ,
enum V_104 V_105 ,
bool V_145 )
{
enum V_128 V_133 = V_138 ;
struct V_22 * V_23 = F_10 ( V_3 ) ;
struct V_146 * V_35 = V_3 -> V_70 -> V_147 ;
if ( F_17 ( V_60 , & V_3 -> V_61 ) ) {
struct V_55 * V_56 = F_16 ( V_3 ) ;
if ( V_56 -> V_58 == V_148 ||
V_56 -> V_58 == V_149 ) {
F_23 ( V_3 ) ;
return V_138 ;
} else {
F_28 ( & V_3 -> V_150 -> V_34 -> V_35 ,
L_1
L_2 ,
V_151 , V_3 , V_56 -> V_58 ) ;
return V_152 ;
}
}
if ( ! F_29 ( V_23 -> V_153 ) ) {
F_28 ( & V_3 -> V_150 -> V_34 -> V_35 ,
L_3 ,
V_151 ,
V_23 -> V_153 ) ;
return V_152 ;
}
if ( V_35 -> V_154 . V_155 == V_156 &&
V_23 -> V_157 . V_158 . V_159 == V_160 ) {
F_26 ( V_3 ) ;
return V_138 ;
}
if ( V_23 -> V_37 == V_111 ) {
F_23 ( V_3 ) ;
return V_138 ;
}
if ( V_23 -> V_157 . V_161 ) {
F_25 ( V_3 ,
V_162 ,
V_106 , V_105 ) ;
return V_138 ;
}
if ( V_23 -> V_157 . V_163 ) {
F_25 ( V_3 ,
V_141 ,
V_106 , V_105 ) ;
return V_138 ;
} else
return F_24 ( V_3 , V_145 ) ;
return V_133 ;
}
static enum V_128 F_30 ( struct V_2 * V_3 )
{
struct V_22 * V_23 = F_10 ( V_3 ) ;
V_3 -> V_164 = V_165 ;
F_20 ( V_3 ,
V_23 -> V_37 ,
V_23 -> V_36 ) ;
F_13 ( V_3 ) ;
F_31 ( & V_3 -> V_166 , V_167 ) ;
return V_138 ;
}
enum V_128 F_32 (
struct V_2 * V_3 )
{
F_21 ( V_3 ) ;
F_15 ( V_3 ) ;
F_31 ( & V_3 -> V_166 , V_167 ) ;
return V_138 ;
}
static enum V_128 F_33 ( struct V_2 * V_3 )
{
enum V_128 V_133 ;
bool V_145 = false ;
struct V_22 * V_23 = F_10 ( V_3 ) ;
V_3 -> V_164 = V_168 ;
V_145 = ( V_23 -> V_37 == V_111 ) ? false : true ;
V_133 = F_27 ( V_3 ,
V_23 -> V_36 ,
V_23 -> V_37 ,
V_145 ) ;
if ( V_133 == V_138 )
F_31 ( & V_3 -> V_166 , V_167 ) ;
return V_133 ;
}
enum V_128 F_34 ( struct V_2 * V_3 )
{
enum V_128 V_133 = V_138 ;
if ( F_17 ( V_60 , & V_3 -> V_61 ) ) {
struct V_55 * V_56 = F_16 ( V_3 ) ;
if ( V_56 -> V_58 == V_148 ||
V_56 -> V_58 == V_149 ) {
F_23 ( V_3 ) ;
} else {
F_28 ( & V_3 -> V_150 -> V_34 -> V_35 ,
L_1
L_4 ,
V_151 , V_3 , V_56 -> V_58 ) ;
return V_152 ;
}
}
if ( V_133 != V_138 )
return V_133 ;
F_31 ( & V_3 -> V_166 , V_167 ) ;
return V_133 ;
}
static T_2 F_35 ( struct V_2 * V_3 )
{
struct V_9 * V_10 = V_3 -> V_150 ;
T_2 V_169 = 0 ;
if ( F_36 ( & V_10 -> V_170 -> V_21 ) == 0 ) {
void T_4 * V_171 = V_10 -> V_172 ;
V_169 = F_36 ( V_171 +
( V_173 + F_37 ( struct V_64 , type . V_41 . V_174 ) ) +
( ( sizeof( struct V_64 ) ) * F_19 ( V_3 -> V_62 ) ) ) ;
}
return V_169 ;
}
enum V_128 F_38 ( struct V_2 * V_3 )
{
enum V_175 V_176 ;
struct V_64 * V_5 = V_3 -> V_5 ;
struct V_9 * V_10 = V_3 -> V_150 ;
V_176 = V_3 -> V_166 . V_177 ;
if ( V_176 != V_167 ) {
F_39 ( & V_10 -> V_34 -> V_35 ,
L_5
L_6 , V_151 , V_176 ) ;
return V_178 ;
}
V_5 -> V_179 = F_19 ( V_3 -> V_62 ) ;
switch ( V_5 -> V_79 ) {
case V_180 :
case V_80 :
V_5 -> type . V_41 . V_181 = V_3 -> V_62 ;
V_5 -> type . V_41 . V_182 = 0xFFFF ;
break;
case V_121 :
break;
case V_183 :
break;
default:
break;
}
V_3 -> V_95 |= F_19 ( V_3 -> V_62 ) ;
F_31 ( & V_3 -> V_166 , V_184 ) ;
return V_138 ;
}
enum V_128
F_40 ( struct V_2 * V_3 )
{
enum V_175 V_176 ;
V_176 = V_3 -> V_166 . V_177 ;
switch ( V_176 ) {
case V_167 :
V_3 -> V_185 = V_186 ;
V_3 -> V_128 = V_187 ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
return V_138 ;
case V_184 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
case V_200 :
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
case V_206 :
F_31 ( & V_3 -> V_166 , V_207 ) ;
return V_138 ;
case V_208 :
F_31 ( & V_3 -> V_166 , V_207 ) ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
return V_138 ;
case V_207 :
case V_188 :
default:
F_39 ( & V_3 -> V_150 -> V_34 -> V_35 ,
L_7
L_6 ,
V_151 ,
V_3 -> V_166 . V_177 ) ;
break;
}
return V_178 ;
}
enum V_128 F_41 ( struct V_2 * V_3 )
{
enum V_175 V_176 ;
struct V_9 * V_10 = V_3 -> V_150 ;
V_176 = V_3 -> V_166 . V_177 ;
if ( F_42 ( V_176 != V_188 ,
L_8 , V_176 ) )
return V_178 ;
if ( V_3 -> V_209 != V_210 )
F_43 ( V_10 ,
V_3 -> V_209 ) ;
F_31 ( & V_3 -> V_166 , V_211 ) ;
return V_138 ;
}
enum V_128 F_44 ( struct V_2 * V_3 ,
T_2 V_212 )
{
enum V_175 V_176 ;
struct V_9 * V_10 = V_3 -> V_150 ;
V_176 = V_3 -> V_166 . V_177 ;
if ( V_176 != V_198 ) {
F_39 ( & V_10 -> V_34 -> V_35 , L_9 ,
V_151 , V_212 , V_176 ) ;
return V_178 ;
}
switch ( F_45 ( V_212 ) ) {
case V_213 << V_214 :
F_31 ( & V_3 -> V_166 , V_197 ) ;
return V_138 ;
default:
F_28 ( & V_10 -> V_34 -> V_35 ,
L_10 ,
V_151 , V_212 ) ;
return V_152 ;
}
}
static void F_46 ( struct V_2 * V_3 )
{
void * V_215 ;
T_2 V_106 ;
struct V_216 * V_217 ;
struct V_55 * V_55 = F_16 ( V_3 ) ;
V_217 = & V_3 -> V_41 . V_101 ;
V_215 = & V_55 -> V_218 . V_219 ;
V_106 = F_47 ( T_2 ,
V_220 ,
F_48 ( V_217 -> V_221 ) ) ;
memcpy ( V_215 , V_217 -> V_222 , V_106 ) ;
}
static enum V_128
F_49 ( struct V_2 * V_3 ,
T_2 V_223 )
{
struct V_216 * V_219 ;
T_3 V_224 ;
switch ( F_50 ( V_223 ) ) {
case F_51 ( V_225 ) :
V_3 -> V_185 = V_225 ;
V_3 -> V_128 = V_138 ;
break;
case F_51 ( V_226 ) : {
struct V_216 * V_218 = & V_3 -> V_41 . V_101 ;
T_5 V_227 = V_220 / sizeof( T_2 ) ;
F_14 ( & V_3 -> V_41 . V_101 ,
& V_3 -> V_41 . V_101 ,
V_227 ) ;
if ( V_218 -> V_133 == 0 ) {
V_3 -> V_185 = V_225 ;
V_3 -> V_128 = V_228 ;
} else {
V_3 -> V_185 = V_229 ;
V_3 -> V_128 = V_230 ;
}
break;
}
case F_51 ( V_229 ) : {
T_5 V_227 = V_220 / sizeof( T_2 ) ;
F_14 ( & V_3 -> V_41 . V_101 ,
& V_3 -> V_41 . V_101 ,
V_227 ) ;
V_3 -> V_185 = V_229 ;
V_3 -> V_128 = V_230 ;
break;
}
case F_51 ( V_231 ) :
V_219 = & V_3 -> V_41 . V_101 ;
V_224 = V_219 -> V_224 ;
if ( V_224 == 1 || V_224 == 2 ) {
V_3 -> V_185 = V_229 ;
V_3 -> V_128 = V_230 ;
} else {
V_3 -> V_185 = V_225 ;
V_3 -> V_128 = V_138 ;
}
break;
case F_51 ( V_232 ) :
case F_51 ( V_233 ) :
case F_51 ( V_234 ) :
case F_51 ( V_235 ) :
case F_51 ( V_236 ) :
case F_51 ( V_237 ) :
case F_51 ( V_238 ) :
case F_51 ( V_239 ) :
case F_51 ( V_240 ) :
case F_51 ( V_241 ) :
case F_51 ( V_242 ) :
if ( V_3 -> V_164 == V_168 ) {
V_3 -> V_185 = F_50 ( V_223 ) >>
V_243 ;
V_3 -> V_128 = V_244 ;
} else {
V_3 -> V_185 = F_50 ( V_223 ) >>
V_243 ;
V_3 -> V_128 = V_245 ;
}
break;
case F_51 ( V_246 ) :
case F_51 ( V_247 ) :
case F_51 ( V_248 ) :
case F_51 ( V_249 ) :
case F_51 ( V_250 ) :
case F_51 ( V_251 ) :
case F_51 ( V_252 ) :
case F_51 ( V_253 ) :
case F_51 ( V_254 ) :
case F_51 ( V_255 ) :
V_3 -> V_185 = F_50 ( V_223 ) >>
V_243 ;
V_3 -> V_128 = V_244 ;
break;
case F_51 ( V_256 ) :
case F_51 ( V_257 ) :
case F_51 ( V_258 ) :
case F_51 ( V_259 ) :
case F_51 ( V_260 ) :
case F_51 ( V_261 ) :
case F_51 ( V_262 ) :
case F_51 ( V_263 ) :
case F_51 ( V_264 ) :
case F_51 ( V_265 ) :
case F_51 ( V_266 ) :
case F_51 ( V_267 ) :
case F_51 ( V_268 ) :
case F_51 ( V_269 ) :
case F_51 ( V_270 ) :
default:
V_3 -> V_185 = F_50 ( V_223 ) >>
V_243 ;
V_3 -> V_128 = V_245 ;
break;
}
F_31 ( & V_3 -> V_166 , V_188 ) ;
return V_138 ;
}
static enum V_128
F_52 ( struct V_2 * V_3 ,
T_2 V_223 )
{
switch ( F_50 ( V_223 ) ) {
case ( V_225 << V_243 ) :
case ( V_186 << V_243 ) :
V_3 -> V_185 = V_186 ;
V_3 -> V_128 = V_187 ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
break;
default:
break;
}
return V_138 ;
}
static enum V_128 F_53 ( struct V_2 * V_3 ,
T_2 V_223 )
{
switch ( F_50 ( V_223 ) ) {
case F_51 ( V_225 ) :
V_3 -> V_185 = V_225 ;
V_3 -> V_128 = V_138 ;
F_31 ( & V_3 -> V_166 , V_208 ) ;
break;
case F_51 ( V_232 ) :
F_39 ( & V_3 -> V_150 -> V_34 -> V_35 ,
L_11
L_12 , V_151 , V_3 ,
V_223 ) ;
F_31 ( & V_3 -> V_166 , V_208 ) ;
break;
default:
V_3 -> V_185 = F_54 ( V_223 ) ;
V_3 -> V_128 = V_245 ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
break;
}
return V_138 ;
}
static enum V_128
F_55 ( struct V_2 * V_3 ,
T_2 V_223 )
{
switch ( F_50 ( V_223 ) ) {
case F_51 ( V_225 ) :
V_3 -> V_185 = V_225 ;
V_3 -> V_128 = V_138 ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
break;
case F_51 ( V_262 ) :
case F_51 ( V_263 ) :
case F_51 ( V_264 ) :
case F_51 ( V_265 ) :
V_3 -> V_185 = V_262 ;
V_3 -> V_128 = V_271 ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
break;
default:
V_3 -> V_185 = F_54 ( V_223 ) ;
V_3 -> V_128 = V_245 ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
break;
}
return V_138 ;
}
static enum V_128
F_56 ( struct V_2 * V_3 ,
T_2 V_223 )
{
switch ( F_50 ( V_223 ) ) {
case F_51 ( V_225 ) :
V_3 -> V_185 = V_225 ;
V_3 -> V_128 = V_138 ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
break;
default:
V_3 -> V_185 = F_54 ( V_223 ) ;
V_3 -> V_128 = V_245 ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
break;
}
return V_138 ;
}
static struct V_14 * F_57 ( struct V_130 * V_131 )
{
struct V_14 * V_134 ;
struct V_1 * V_272 ;
struct V_2 * V_3 = F_58 ( V_131 ) ;
struct V_273 * V_274 = & V_131 -> V_134 ;
V_272 = F_1 ( V_3 , V_274 -> V_137 ) ;
if ( ! V_272 )
V_134 = NULL ;
else if ( V_274 -> V_135 == V_136 ) {
if ( V_272 -> V_31 . V_20 == 0 &&
V_272 -> V_31 . V_19 == 0 ) {
V_134 = NULL ;
} else {
V_274 -> V_135 = V_275 ;
V_134 = & V_272 -> V_31 ;
}
} else {
if ( V_272 -> V_33 == 0 &&
V_272 -> V_32 == 0 ) {
V_134 = NULL ;
} else {
V_274 -> V_137 ++ ;
V_274 -> V_135 = V_136 ;
V_272 = F_1 ( V_3 , V_274 -> V_137 ) ;
V_134 = & V_272 -> V_30 ;
}
}
return V_134 ;
}
static enum V_128
F_59 ( struct V_2 * V_3 ,
T_2 V_223 )
{
switch ( F_50 ( V_223 ) ) {
case F_51 ( V_225 ) :
V_3 -> V_185 = V_225 ;
V_3 -> V_128 = V_138 ;
F_31 ( & V_3 -> V_166 , V_195 ) ;
break;
default:
V_3 -> V_185 = F_54 ( V_223 ) ;
V_3 -> V_128 = V_245 ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
break;
}
return V_138 ;
}
static enum V_128 F_60 (
struct V_2 * V_3 ,
T_2 V_18 )
{
struct V_130 * V_131 = & V_3 -> V_124 . V_132 ;
struct V_64 * V_65 = V_3 -> V_5 ;
struct V_1 * V_272 ;
struct V_14 * V_276 ;
V_272 = F_1 ( V_3 , V_131 -> V_134 . V_137 ) ;
if ( V_131 -> V_134 . V_135 == V_136 )
V_276 = & V_272 -> V_30 ;
else
V_276 = & V_272 -> V_31 ;
V_65 -> V_99 = V_276 -> V_19 ;
V_65 -> V_100 = V_276 -> V_20 ;
V_65 -> V_116 = V_18 ;
V_65 -> type . V_124 . V_126 = V_277 ;
return F_61 ( V_3 ) ;
}
static enum V_128 F_62 ( struct V_2 * V_3 )
{
struct V_130 * V_131 = & V_3 -> V_124 . V_132 ;
struct V_1 * V_272 ;
enum V_128 V_133 = V_138 ;
struct V_14 * V_134 ;
T_2 V_11 ;
T_2 V_106 = 0 ;
V_11 = V_131 -> V_134 . V_11 ;
V_272 = F_1 ( V_3 , V_131 -> V_134 . V_137 ) ;
if ( F_42 ( ! V_272 , L_13 , V_151 ) )
return V_152 ;
if ( V_131 -> V_134 . V_135 == V_136 ) {
V_134 = & V_272 -> V_30 ;
V_106 = V_272 -> V_30 . V_18 - V_11 ;
} else {
V_134 = & V_272 -> V_31 ;
V_106 = V_272 -> V_31 . V_18 - V_11 ;
}
if ( V_131 -> V_278 == 0 )
return V_138 ;
if ( V_131 -> V_278 >= V_106 ) {
V_133 = F_60 ( V_3 , V_106 ) ;
if ( V_133 != V_138 )
return V_133 ;
V_131 -> V_278 -= V_106 ;
V_134 = F_57 ( V_131 ) ;
V_11 = 0 ;
} else if ( V_131 -> V_278 < V_106 ) {
F_60 ( V_3 , V_131 -> V_278 ) ;
V_11 += V_131 -> V_278 ;
V_134 -> V_20 += V_131 -> V_278 ;
V_131 -> V_278 = 0 ;
}
V_131 -> V_134 . V_11 = V_11 ;
return V_133 ;
}
static enum V_128
F_63 ( struct V_130 * V_131 ,
T_3 * V_279 , T_2 V_106 )
{
struct V_2 * V_3 ;
T_3 * V_280 ;
int V_281 ;
struct V_22 * V_23 ;
struct V_16 * V_17 ;
void * V_282 ;
int V_283 = V_106 ;
V_3 = F_58 ( V_131 ) ;
V_23 = F_10 ( V_3 ) ;
V_280 = V_279 ;
if ( V_23 -> V_28 > 0 ) {
V_17 = V_23 -> V_29 ;
while ( V_283 > 0 ) {
struct V_284 * V_284 = F_64 ( V_17 ) ;
V_281 = F_47 ( int , V_283 , F_5 ( V_17 ) ) ;
V_282 = F_65 ( V_284 , V_285 ) ;
memcpy ( V_282 + V_17 -> V_11 , V_280 , V_281 ) ;
F_66 ( V_282 , V_285 ) ;
V_283 -= V_281 ;
V_280 += V_281 ;
V_17 = F_11 ( V_17 ) ;
}
} else {
F_67 ( V_23 -> V_36 < V_283 ) ;
memcpy ( V_23 -> V_29 , V_280 , V_283 ) ;
}
return V_138 ;
}
static enum V_128 F_68 (
struct V_130 * V_131 ,
T_3 * V_286 )
{
enum V_128 V_133 ;
if ( V_131 -> V_278 < V_287 ) {
V_133 = F_63 (
V_131 , V_286 , V_131 -> V_278 ) ;
if ( V_133 == V_138 )
V_131 -> V_278 = 0 ;
} else {
V_133 = F_63 (
V_131 , V_286 , V_287 ) ;
if ( V_133 == V_138 )
V_131 -> V_278 -= V_287 ;
}
return V_133 ;
}
static enum V_128
F_69 ( struct V_2 * V_3 ,
T_2 V_223 )
{
enum V_128 V_133 = V_138 ;
switch ( F_50 ( V_223 ) ) {
case F_51 ( V_225 ) :
V_3 -> V_185 = V_225 ;
V_3 -> V_128 = V_138 ;
F_31 ( & V_3 -> V_166 , V_197 ) ;
break;
default:
V_3 -> V_185 = F_54 ( V_223 ) ;
V_3 -> V_128 = V_245 ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
break;
}
return V_133 ;
}
static enum V_128
F_70 ( struct V_2 * V_3 ,
T_2 V_223 )
{
enum V_128 V_133 = V_138 ;
bool V_288 = false ;
struct V_130 * V_131 = & V_3 -> V_124 . V_132 ;
switch ( F_50 ( V_223 ) ) {
case F_51 ( V_225 ) :
if ( V_131 -> V_278 != 0 ) {
V_133 = F_62 ( V_3 ) ;
if ( V_133 == V_138 ) {
if ( V_131 -> V_278 == 0 )
V_288 = true ;
}
} else if ( V_131 -> V_278 == 0 ) {
V_288 = true ;
}
if ( V_288 ) {
F_31 ( & V_3 -> V_166 , V_197 ) ;
}
break;
default:
V_3 -> V_185 = F_54 ( V_223 ) ;
V_3 -> V_128 = V_245 ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
break;
}
return V_133 ;
}
static enum V_128 F_71 ( struct V_2 * V_3 ,
T_2 V_289 )
{
struct V_9 * V_10 = V_3 -> V_150 ;
struct V_290 * V_291 ;
enum V_128 V_133 ;
T_2 * V_292 ;
V_133 = F_72 ( & V_10 -> V_293 ,
V_289 ,
( void * * ) & V_291 ) ;
if ( ( V_133 == V_138 ) &&
( V_291 -> V_126 == V_294 ) ) {
F_73 ( & V_10 -> V_293 ,
V_289 ,
( void * * ) & V_292 ) ;
F_74 ( & V_3 -> V_124 . V_101 ,
V_291 ,
V_292 ) ;
}
F_43 ( V_10 , V_289 ) ;
return V_133 ;
}
static enum V_128 F_75 ( struct V_2 * V_3 ,
T_2 V_289 )
{
struct V_9 * V_10 = V_3 -> V_150 ;
enum V_128 V_133 ;
struct V_290 * V_291 ;
T_2 * V_292 ;
V_133 = F_72 ( & V_10 -> V_293 ,
V_289 ,
( void * * ) & V_291 ) ;
if ( V_133 != V_138 )
return V_133 ;
if ( V_291 -> V_126 != V_294 ) {
F_28 ( & V_3 -> V_9 -> V_34 -> V_35 ,
L_14 ,
V_151 , V_291 -> V_126 ) ;
return V_152 ;
}
F_73 ( & V_10 -> V_293 ,
V_289 ,
( void * * ) & V_292 ) ;
F_74 ( & V_3 -> V_124 . V_101 ,
( T_2 * ) V_291 ,
V_292 ) ;
F_43 ( V_10 , V_289 ) ;
return V_133 ;
}
static enum V_128 F_76 ( struct V_2 * V_3 ,
T_2 V_289 )
{
struct V_22 * V_23 = F_10 ( V_3 ) ;
enum V_128 V_133 ;
V_133 = F_75 ( V_3 , V_289 ) ;
if ( V_133 == V_138 ) {
if ( V_3 -> V_124 . V_101 . V_133 & V_295 )
V_133 = V_296 ;
} else {
V_133 = V_296 ;
}
if ( V_133 != V_138 ) {
V_3 -> V_185 = V_229 ;
V_3 -> V_128 = V_133 ;
} else {
V_3 -> V_185 = V_225 ;
V_3 -> V_128 = V_138 ;
}
if ( V_23 -> V_37 == V_111 )
F_31 ( & V_3 -> V_166 , V_188 ) ;
return V_133 ;
}
static void F_77 ( struct V_2 * V_3 )
{
struct V_297 * V_35 = F_78 ( V_3 -> V_70 -> V_147 ) ;
void * V_298 = V_3 -> V_299 . V_300 -> V_157 . V_301 ;
struct V_64 * V_65 = V_3 -> V_5 ;
memset ( & V_3 -> V_124 . V_42 , 0 , sizeof( struct V_122 ) ) ;
memcpy ( ( ( T_3 * ) & V_3 -> V_124 . V_42 + sizeof( T_2 ) ) , V_298 , V_302 ) ;
memset ( & ( V_65 -> type . V_124 ) , 0 , sizeof( struct V_303 ) ) ;
V_65 -> type . V_124 . V_126 = V_277 ;
V_65 -> V_116 = V_35 -> V_304 ;
}
static void F_79 ( struct V_2 * V_3 )
{
struct V_297 * V_35 = F_78 ( V_3 -> V_70 -> V_147 ) ;
struct V_22 * V_23 = F_10 ( V_3 ) ;
struct V_64 * V_65 = V_3 -> V_5 ;
int V_304 = V_35 -> V_304 ;
if ( V_23 -> V_37 == V_114 ) {
V_65 -> V_112 = V_305 ;
V_65 -> V_306 = 0 ;
} else {
V_65 -> V_112 = V_307 ;
V_65 -> V_306 = 1 ;
}
memset ( & V_65 -> type . V_124 , 0 , sizeof( V_65 -> type . V_124 ) ) ;
V_65 -> type . V_124 . V_126 = V_277 ;
memset ( & V_3 -> V_124 . V_42 , 0 , sizeof( V_3 -> V_124 . V_42 ) ) ;
memcpy ( & V_3 -> V_124 . V_42 . V_308 , V_23 -> V_157 . V_301 , V_304 ) ;
V_65 -> V_107 = V_304 / sizeof( T_2 ) ;
V_65 -> V_94 = 0x1 ;
V_65 -> V_309 = 0 ;
V_65 -> V_116 = V_23 -> V_36 ;
F_9 ( V_3 ) ;
}
enum V_128
F_80 ( struct V_2 * V_3 ,
T_2 V_289 )
{
struct V_9 * V_10 = V_3 -> V_150 ;
struct V_130 * V_131 = & V_3 -> V_124 . V_132 ;
enum V_175 V_176 ;
enum V_128 V_133 ;
T_5 V_227 ;
V_176 = V_3 -> V_166 . V_177 ;
switch ( V_176 ) {
case V_184 : {
struct V_310 V_311 ;
void * V_291 ;
F_72 ( & V_10 -> V_293 ,
V_289 ,
& V_291 ) ;
V_227 = sizeof( struct V_310 ) / sizeof( T_2 ) ;
F_14 ( & V_311 , V_291 , V_227 ) ;
if ( V_311 . V_108 == V_312 ) {
struct V_216 * V_219 ;
T_5 V_227 = V_220 / sizeof( T_2 ) ;
F_73 ( & V_10 -> V_293 ,
V_289 ,
( void * * ) & V_219 ) ;
F_14 ( & V_3 -> V_41 . V_101 , V_219 , V_227 ) ;
V_219 = & V_3 -> V_41 . V_101 ;
if ( V_219 -> V_224 == 0x01 ||
V_219 -> V_224 == 0x02 ) {
V_3 -> V_185 = V_229 ;
V_3 -> V_128 = V_245 ;
} else {
V_3 -> V_185 = V_225 ;
V_3 -> V_128 = V_138 ;
}
} else {
F_28 ( & V_10 -> V_34 -> V_35 ,
L_15
L_16 , V_151 , V_3 ,
V_289 , V_311 . V_108 ) ;
}
F_43 ( V_10 , V_289 ) ;
return V_138 ;
}
case V_208 :
F_46 ( V_3 ) ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
F_43 ( V_10 , V_289 ) ;
return V_138 ;
case V_190 : {
struct V_22 * V_23 = F_10 ( V_3 ) ;
struct V_16 * V_17 = & V_23 -> V_313 . V_314 ;
void * V_291 , * V_282 ;
T_3 * V_101 ;
F_72 ( & V_10 -> V_293 ,
V_289 ,
& V_291 ) ;
V_282 = F_65 ( F_64 ( V_17 ) , V_285 ) ;
V_101 = V_282 + V_17 -> V_11 ;
F_14 ( V_101 , V_291 , 1 ) ;
if ( V_101 [ 0 ] == V_315 ) {
void * V_314 ;
F_73 ( & V_10 -> V_293 ,
V_289 ,
& V_314 ) ;
V_227 = ( V_17 -> V_18 / 4 ) - 1 ;
if ( V_227 > 0 )
V_227 = F_47 (unsigned int, word_cnt,
SCU_UNSOLICITED_FRAME_BUFFER_SIZE/4 ) ;
F_14 ( V_101 + 4 , V_314 , V_227 ) ;
V_3 -> V_185 = V_225 ;
V_3 -> V_128 = V_138 ;
F_31 ( & V_3 -> V_166 , V_191 ) ;
} else {
F_28 ( & V_10 -> V_34 -> V_35 ,
L_17
L_16 ,
V_151 ,
V_3 ,
V_289 ,
V_101 [ 0 ] ) ;
V_3 -> V_185 = V_264 ;
V_3 -> V_128 = V_245 ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
}
F_66 ( V_282 , V_285 ) ;
F_43 ( V_10 , V_289 ) ;
return V_138 ;
}
case V_192 :
return F_71 ( V_3 ,
V_289 ) ;
case V_193 :
V_133 = F_71 ( V_3 , V_289 ) ;
if ( V_133 != V_138 )
return V_133 ;
V_3 -> V_185 = V_229 ;
V_3 -> V_128 = V_230 ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
return V_138 ;
case V_195 : {
struct V_290 * V_291 ;
T_2 * V_292 ;
V_133 = F_72 ( & V_10 -> V_293 ,
V_289 ,
( void * * ) & V_291 ) ;
if ( V_133 != V_138 ) {
F_28 ( & V_10 -> V_34 -> V_35 ,
L_18
L_19 ,
V_151 ,
V_131 ,
V_289 ,
V_133 ) ;
return V_133 ;
}
switch ( V_291 -> V_126 ) {
case V_294 :
F_73 ( & V_10 -> V_293 ,
V_289 ,
( void * * ) & V_292 ) ;
F_74 ( & V_3 -> V_124 . V_101 ,
V_291 ,
V_292 ) ;
V_3 -> V_185 = V_229 ;
V_3 -> V_128 = V_230 ;
break;
default:
F_39 ( & V_10 -> V_34 -> V_35 ,
L_20
L_21 , V_151 , V_131 ,
V_289 ) ;
V_3 -> V_185 = V_316 ;
V_3 -> V_128 = V_317 ;
break;
}
F_31 ( & V_3 -> V_166 , V_188 ) ;
F_43 ( V_10 , V_289 ) ;
return V_133 ;
}
case V_197 : {
struct V_22 * V_23 = F_10 ( V_3 ) ;
struct V_290 * V_291 ;
T_2 * V_292 ;
V_133 = F_72 ( & V_10 -> V_293 ,
V_289 ,
( void * * ) & V_291 ) ;
if ( V_133 != V_138 ) {
F_28 ( & V_10 -> V_34 -> V_35 ,
L_18
L_19 ,
V_151 , V_131 , V_289 , V_133 ) ;
return V_133 ;
}
switch ( V_291 -> V_126 ) {
case V_318 :
F_73 ( & V_10 -> V_293 ,
V_289 ,
( void * * ) & V_292 ) ;
V_131 -> V_278 = V_292 [ 3 ] & 0xffff ;
V_131 -> V_133 = ( V_292 [ 2 ] >> 24 ) & 0xff ;
F_74 ( & V_3 -> V_124 . V_101 ,
V_291 ,
V_292 ) ;
V_3 -> V_124 . V_101 . V_133 = V_131 -> V_133 ;
if ( V_23 -> V_37 == V_110 ) {
F_31 ( & V_3 -> V_166 , V_198 ) ;
} else if ( V_23 -> V_37 == V_114 ) {
V_133 = F_62 ( V_3 ) ;
if ( V_133 != V_138 )
break;
F_31 ( & V_3 -> V_166 , V_199 ) ;
}
break;
case V_319 :
F_31 ( & V_3 -> V_166 , V_197 ) ;
break;
case V_294 :
if ( V_291 -> V_133 & V_320 ) {
F_81 ( & V_10 -> V_34 -> V_35 ,
L_22
L_23
L_24 ,
V_151 ,
V_131 ,
V_291 -> V_133 ) ;
break;
}
F_73 ( & V_10 -> V_293 ,
V_289 ,
( void * * ) & V_292 ) ;
F_74 ( & V_3 -> V_124 . V_132 ,
V_291 ,
V_292 ) ;
V_3 -> V_185 = V_229 ;
V_3 -> V_128 = V_230 ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
break;
default:
break;
}
F_43 ( V_10 , V_289 ) ;
return V_133 ;
}
case V_198 : {
struct V_290 * V_291 ;
struct V_321 * V_292 ;
V_133 = F_72 ( & V_10 -> V_293 ,
V_289 ,
( void * * ) & V_291 ) ;
if ( V_133 != V_138 ) {
F_28 ( & V_10 -> V_34 -> V_35 ,
L_18
L_19 ,
V_151 ,
V_131 ,
V_289 ,
V_133 ) ;
return V_133 ;
}
if ( V_291 -> V_126 != V_277 ) {
F_28 ( & V_10 -> V_34 -> V_35 ,
L_25
L_26
L_27 ,
V_151 ,
V_131 ,
V_289 ,
V_291 -> V_126 ) ;
V_3 -> V_185 = V_225 ;
V_3 -> V_128 = V_322 ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
F_43 ( V_10 , V_289 ) ;
return V_133 ;
}
if ( V_131 -> V_134 . V_137 < 0 ) {
V_3 -> V_209 = V_289 ;
V_131 -> V_278 = 0 ;
} else {
F_73 ( & V_10 -> V_293 ,
V_289 ,
( void * * ) & V_292 ) ;
V_133 = F_68 ( V_131 ,
( T_3 * ) V_292 ) ;
F_43 ( V_10 , V_289 ) ;
}
if ( V_133 != V_138 || V_131 -> V_278 != 0 )
return V_133 ;
if ( ( V_131 -> V_133 & V_320 ) == 0 ) {
V_3 -> V_185 = V_229 ;
V_3 -> V_128 = V_230 ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
} else {
F_31 ( & V_3 -> V_166 , V_197 ) ;
}
return V_133 ;
}
case V_202 : {
struct V_290 * V_291 ;
T_2 * V_292 ;
V_133 = F_72 ( & V_10 -> V_293 ,
V_289 ,
( void * * ) & V_291 ) ;
if ( V_133 != V_138 ) {
F_28 ( & V_10 -> V_34 -> V_35 ,
L_18
L_19 ,
V_151 ,
V_131 ,
V_289 ,
V_133 ) ;
return V_133 ;
}
switch ( V_291 -> V_126 ) {
case V_294 :
F_73 ( & V_10 -> V_293 ,
V_289 ,
( void * * ) & V_292 ) ;
F_74 ( & V_3 -> V_124 . V_101 ,
V_291 ,
V_292 ) ;
V_3 -> V_185 = V_229 ;
V_3 -> V_128 = V_230 ;
break;
default:
F_39 ( & V_10 -> V_34 -> V_35 ,
L_20
L_21 ,
V_151 ,
V_131 ,
V_289 ) ;
V_3 -> V_185 = V_316 ;
V_3 -> V_128 = V_317 ;
break;
}
F_31 ( & V_3 -> V_166 , V_188 ) ;
F_43 ( V_10 , V_289 ) ;
return V_133 ;
}
case V_204 : {
struct V_22 * V_23 = F_10 ( V_3 ) ;
F_43 ( V_10 , V_289 ) ;
V_3 -> V_70 -> V_323 = V_3 ;
if ( V_23 -> V_37 == V_111 ) {
F_31 ( & V_3 -> V_166 , V_206 ) ;
F_77 ( V_3 ) ;
} else {
F_31 ( & V_3 -> V_166 , V_205 ) ;
F_79 ( V_3 ) ;
}
F_61 ( V_3 ) ;
return V_138 ;
}
case V_205 :
return F_76 ( V_3 , V_289 ) ;
case V_207 :
F_43 ( V_10 , V_289 ) ;
return V_138 ;
default:
F_39 ( & V_10 -> V_34 -> V_35 ,
L_28
L_29 ,
V_151 ,
V_289 ,
V_176 ) ;
F_43 ( V_10 , V_289 ) ;
return V_178 ;
}
}
static enum V_128 F_82 ( struct V_2 * V_3 ,
T_2 V_223 )
{
enum V_128 V_133 = V_138 ;
switch ( F_50 ( V_223 ) ) {
case F_51 ( V_225 ) :
V_3 -> V_185 = V_225 ;
V_3 -> V_128 = V_138 ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
break;
case F_51 ( V_316 ) :
case F_51 ( V_241 ) :
if ( V_3 -> V_124 . V_101 . V_126 == V_294 ) {
F_83 ( V_3 -> V_70 ,
F_84 ( F_54 ( V_223 ) ) ) ;
V_3 -> V_185 = V_229 ;
V_3 -> V_128 = V_230 ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
} else {
F_31 ( & V_3 -> V_166 , V_193 ) ;
}
break;
case F_51 ( V_324 ) :
case F_51 ( V_238 ) :
case F_51 ( V_325 ) :
case F_51 ( V_326 ) :
F_83 ( V_3 -> V_70 ,
F_84 ( F_54 ( V_223 ) ) ) ;
default:
V_3 -> V_185 = F_54 ( V_223 ) ;
V_3 -> V_128 = V_245 ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
break;
}
return V_133 ;
}
static enum V_128
F_85 ( struct V_2 * V_3 ,
T_2 V_223 )
{
switch ( F_50 ( V_223 ) ) {
case F_51 ( V_225 ) :
V_3 -> V_185 = V_225 ;
V_3 -> V_128 = V_138 ;
F_31 ( & V_3 -> V_166 , V_201 ) ;
break;
default:
V_3 -> V_185 = F_54 ( V_223 ) ;
V_3 -> V_128 = V_245 ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
break;
}
return V_138 ;
}
static enum V_128
F_86 ( struct V_2 * V_3 ,
T_2 V_223 )
{
switch ( F_50 ( V_223 ) ) {
case F_51 ( V_225 ) :
V_3 -> V_185 = V_225 ;
V_3 -> V_128 = V_138 ;
F_31 ( & V_3 -> V_166 , V_202 ) ;
break;
default:
V_3 -> V_185 = F_54 ( V_223 ) ;
V_3 -> V_128 = V_245 ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
break;
}
return V_138 ;
}
static enum V_128 F_87 ( struct V_2 * V_3 , T_2 V_223 ,
enum V_175 V_327 )
{
enum V_128 V_133 = V_138 ;
switch ( F_50 ( V_223 ) ) {
case F_51 ( V_225 ) :
V_3 -> V_185 = V_225 ;
V_3 -> V_128 = V_138 ;
F_31 ( & V_3 -> V_166 , V_327 ) ;
break;
default:
V_3 -> V_185 = F_54 ( V_223 ) ;
V_3 -> V_128 = V_245 ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
break;
}
return V_133 ;
}
static enum V_128 F_88 ( struct V_2 * V_3 ,
T_2 V_223 )
{
struct V_66 * V_67 = V_3 -> V_70 ;
struct V_290 * V_328 = & V_3 -> V_124 . V_101 ;
enum V_128 V_133 = V_138 ;
switch ( F_50 ( V_223 ) ) {
case ( V_225 << V_243 ) :
F_31 ( & V_3 -> V_166 , V_188 ) ;
break;
case ( V_316 << V_243 ) : {
T_6 V_106 = F_35 ( V_3 ) ;
if ( V_328 -> V_126 != V_294 ) {
V_328 -> V_126 = V_294 ;
V_328 -> V_61 = ( 1 << 6 ) ;
V_328 -> V_133 = 0x50 ;
V_328 -> error = 0 ;
V_328 -> V_308 = 0 ;
V_328 -> V_329 = V_106 & 0xff ;
V_328 -> V_330 = V_106 >> 8 ;
V_328 -> V_331 = 0xa0 ;
V_328 -> V_332 = 0 ;
V_328 -> V_333 = 0 ;
V_328 -> V_334 = 0 ;
V_328 -> V_46 = 0 ;
V_328 -> V_335 = 0x3 ;
V_328 -> V_336 = 0 ;
V_328 -> V_47 = 0 ;
V_328 -> V_51 = 0 ;
V_328 -> V_337 = 0 ;
}
V_3 -> V_185 = V_225 ;
V_3 -> V_128 = V_228 ;
V_133 = V_3 -> V_128 ;
F_31 ( & V_67 -> V_166 , V_338 ) ;
break;
}
case ( V_261 << V_243 ) :
V_3 -> V_185 = V_225 ;
V_3 -> V_128 = V_138 ;
F_31 ( & V_3 -> V_166 , V_188 ) ;
break;
default:
if ( V_328 -> V_126 == V_294 ) {
V_133 = V_3 -> V_128 ;
F_31 ( & V_67 -> V_166 , V_338 ) ;
} else {
V_3 -> V_185 = V_229 ;
V_3 -> V_128 = V_230 ;
F_31 ( & V_3 -> V_166 , V_205 ) ;
}
break;
}
return V_133 ;
}
enum V_128
F_89 ( struct V_2 * V_3 ,
T_2 V_223 )
{
enum V_175 V_176 ;
struct V_9 * V_10 = V_3 -> V_150 ;
V_176 = V_3 -> V_166 . V_177 ;
switch ( V_176 ) {
case V_184 :
return F_49 ( V_3 , V_223 ) ;
case V_189 :
return F_53 ( V_3 ,
V_223 ) ;
case V_190 :
return F_55 ( V_3 ,
V_223 ) ;
case V_191 :
return F_56 ( V_3 , V_223 ) ;
case V_192 :
return F_82 ( V_3 ,
V_223 ) ;
case V_194 :
return F_59 ( V_3 ,
V_223 ) ;
case V_196 :
return F_69 ( V_3 ,
V_223 ) ;
case V_199 :
return F_70 ( V_3 , V_223 ) ;
case V_200 :
return F_85 ( V_3 ,
V_223 ) ;
case V_201 :
return F_86 ( V_3 ,
V_223 ) ;
case V_207 :
return F_52 ( V_3 ,
V_223 ) ;
case V_203 :
return F_87 ( V_3 , V_223 ,
V_204 ) ;
case V_206 :
return F_87 ( V_3 , V_223 ,
V_205 ) ;
case V_205 :
return F_88 ( V_3 , V_223 ) ;
default:
F_39 ( & V_10 -> V_34 -> V_35 ,
L_30
L_31 ,
V_151 ,
V_223 ,
V_176 ) ;
return V_178 ;
}
}
static void F_90 (
struct V_22 * V_23 ,
struct V_216 * V_219 ,
struct V_331 * V_35 )
{
F_81 ( V_35 ,
L_32
L_33
L_34
L_35 ,
V_151 ,
V_219 ,
V_219 -> V_133 ,
V_219 -> V_224 ,
V_219 -> V_221 ,
V_219 -> V_339 ) ;
V_23 -> V_340 . V_341 = V_219 -> V_133 ;
F_91 ( V_35 , V_23 , V_219 ) ;
}
static void F_92 (
struct V_2 * V_342 ,
struct V_22 * V_23 ,
enum V_343 * V_344 ,
enum V_345 * V_346 ,
enum V_347 * V_348 ,
enum V_349 V_350 )
{
F_93 ( V_351 , & V_342 -> V_61 ) ;
* V_344 = V_352 ;
* V_346 = V_353 ;
* V_348 = V_354 ;
V_23 -> V_340 . V_350 = V_350 ;
}
static void F_94 (
struct V_66 * V_67 ,
struct V_2 * V_342 ,
struct V_22 * V_23 ,
enum V_343 * V_344 ,
enum V_345 * V_346 ,
enum V_347 * V_348 )
{
unsigned int V_355 ;
V_355 = V_342 -> V_185 ;
F_81 ( & V_342 -> V_9 -> V_34 -> V_35 ,
L_36
L_37 ,
V_151 , V_342 , V_355 ) ;
switch ( V_355 ) {
case V_356 :
case V_357 :
if ( V_23 -> V_153 == V_358 ) {
* V_344 = V_359 ;
if ( ! V_67 )
* V_346 = V_360 ;
else
* V_346 = V_361 ;
F_93 ( V_351 , & V_342 -> V_61 ) ;
* V_348 =
V_354 ;
} else {
* V_344 = V_352 ;
if ( ! V_67 )
* V_346 = V_360 ;
else
* V_346 = V_362 ;
F_95 ( V_351 , & V_342 -> V_61 ) ;
* V_348 =
V_363 ;
}
break;
case V_213 :
case V_256 :
case V_261 :
case V_316 :
case V_268 :
case V_269 :
case V_270 :
* V_344 = V_359 ;
if ( ! V_67 )
* V_346 = V_360 ;
else
* V_346 = V_361 ;
F_93 ( V_351 , & V_342 -> V_61 ) ;
* V_348 = V_354 ;
break;
case V_247 :
F_92 (
V_342 , V_23 , V_344 , V_346 ,
V_348 , V_364 ) ;
break;
case V_252 :
F_92 (
V_342 , V_23 , V_344 , V_346 ,
V_348 , V_365 ) ;
break;
case V_248 :
F_92 (
V_342 , V_23 , V_344 , V_346 ,
V_348 , V_366 ) ;
break;
case V_249 :
F_92 (
V_342 , V_23 , V_344 , V_346 ,
V_348 , V_367 ) ;
break;
case V_250 :
F_92 (
V_342 , V_23 , V_344 , V_346 ,
V_348 , V_368 ) ;
break;
case V_251 :
F_92 (
V_342 , V_23 , V_344 , V_346 ,
V_348 , V_369 ) ;
break;
case V_253 :
F_92 (
V_342 , V_23 , V_344 , V_346 ,
V_348 , V_370 ) ;
break;
case V_254 :
F_92 (
V_342 , V_23 , V_344 , V_346 ,
V_348 , V_371 ) ;
break;
case V_255 :
F_92 (
V_342 , V_23 , V_344 , V_346 ,
V_348 , V_372 ) ;
break;
case V_325 :
case V_233 :
case V_373 :
case V_374 :
case V_236 :
case V_375 :
case V_258 :
case V_324 :
case V_259 :
case V_260 :
case V_238 :
case V_246 :
case V_262 :
case V_265 :
case V_266 :
case V_240 :
case V_241 :
case V_242 :
case V_186 :
default:
* V_344 = V_352 ;
* V_346 = V_362 ;
if ( V_23 -> V_153 == V_358 ) {
F_93 ( V_351 , & V_342 -> V_61 ) ;
* V_348 = V_354 ;
} else {
F_95 ( V_351 , & V_342 -> V_61 ) ;
* V_348 = V_363 ;
}
break;
}
}
static void F_96 (
struct V_9 * V_376 ,
struct V_2 * V_342 ,
enum V_343 V_377 ,
enum V_345 V_133 ,
enum V_347 V_378 )
{
struct V_22 * V_23 = F_10 ( V_342 ) ;
V_378
= F_97 ( V_23 , V_377 , V_133 ,
V_378 ) ;
switch ( V_378 ) {
case V_354 :
F_98 ( & V_342 -> V_379 ,
& V_376 -> V_380 ) ;
F_99 ( & V_342 -> V_381 ) ;
break;
case V_382 :
F_100 ( V_342 -> V_383 == NULL ) ;
if ( V_342 -> V_383 != NULL ) {
F_101 ( V_342 -> V_383 ) ;
}
break;
case V_363 :
F_98 ( & V_342 -> V_379 ,
& V_376 -> V_384 ) ;
break;
default:
F_98 ( & V_342 -> V_379 ,
& V_376 -> V_384 ) ;
break;
}
F_81 ( & V_376 -> V_34 -> V_35 ,
L_38 ,
V_151 , V_378 , V_23 ,
( V_23 ) ? V_23 -> V_340 . V_218 : 0 , V_377 ,
( V_23 ) ? V_23 -> V_340 . V_341 : 0 , V_133 ) ;
}
static void F_102 ( struct V_22 * V_23 , struct V_290 * V_158 )
{
struct V_385 * V_386 = & V_23 -> V_340 ;
struct V_387 * V_218 = ( void * ) & V_386 -> V_388 [ 0 ] ;
V_218 -> V_389 = sizeof( * V_158 ) ;
memcpy ( V_218 -> V_390 , V_158 , sizeof( * V_158 ) ) ;
V_386 -> V_391 = sizeof( * V_218 ) ;
if ( V_158 -> V_133 & V_392 )
V_386 -> V_341 = V_393 ;
else if ( V_158 -> V_133 & V_295 )
V_386 -> V_341 = V_394 ;
else
V_386 -> V_341 = V_395 ;
V_386 -> V_218 = V_359 ;
}
static void F_103 ( struct V_9 * V_10 ,
struct V_2 * V_342 ,
enum V_396 V_397 )
{
struct V_22 * V_23 = F_10 ( V_342 ) ;
struct V_216 * V_219 ;
unsigned long V_398 ;
struct V_66 * V_67 = V_342 -> V_70 ;
enum V_343 V_377 = V_352 ;
enum V_345 V_133 = V_361 ;
enum V_399 V_400 ;
enum V_347 V_401
= V_354 ;
F_81 ( & V_10 -> V_34 -> V_35 ,
L_39
L_40 ,
V_151 ,
V_342 ,
V_23 ,
V_23 -> V_37 ,
V_397 ) ;
F_104 ( & V_342 -> V_402 ) ;
V_400 = V_342 -> V_133 ;
switch ( V_400 ) {
case V_403 :
F_93 ( V_351 , & V_342 -> V_61 ) ;
V_377 = V_359 ;
if ( ! V_67 )
V_133 = V_360 ;
else
V_133 = V_361 ;
V_401 = V_382 ;
F_105 ( & V_342 -> V_402 ) ;
break;
case V_404 :
F_93 ( V_351 , & V_342 -> V_61 ) ;
V_377 = V_352 ;
if ( ! V_67 )
V_133 = V_360 ;
else
V_133 = V_405 ;
V_401 = V_382 ;
F_105 ( & V_342 -> V_402 ) ;
break;
case V_406 :
F_93 ( V_351 , & V_342 -> V_61 ) ;
V_377 = V_352 ;
if ( ! V_67 )
V_133 = V_360 ;
else
V_133 = V_361 ;
V_401 = V_382 ;
F_105 ( & V_342 -> V_402 ) ;
break;
case V_407 :
V_401 = V_354 ;
F_105 ( & V_342 -> V_402 ) ;
break;
default:
V_342 -> V_133 = V_408 ;
F_105 ( & V_342 -> V_402 ) ;
switch ( V_397 ) {
case V_296 :
F_81 ( & V_10 -> V_34 -> V_35 ,
L_41 ,
V_151 ,
V_342 ,
V_23 ) ;
if ( F_29 ( V_23 -> V_153 ) ) {
F_102 ( V_23 , & V_342 -> V_124 . V_101 ) ;
} else if ( V_409 == V_23 -> V_153 ) {
V_219 = & V_342 -> V_41 . V_101 ;
F_90 ( V_23 , V_219 ,
& V_10 -> V_34 -> V_35 ) ;
} else if ( V_358 == V_23 -> V_153 ) {
F_28 ( & V_10 -> V_34 -> V_35 ,
L_42
L_43 ,
V_151 ) ;
} else
F_28 ( & V_10 -> V_34 -> V_35 ,
L_44 , V_151 ) ;
F_93 ( V_351 , & V_342 -> V_61 ) ;
V_377 = V_23 -> V_340 . V_218 ;
V_133 = V_23 -> V_340 . V_341 ;
break;
case V_410 :
case V_411 :
V_377 = V_359 ;
V_133 = V_395 ;
F_93 ( V_351 , & V_342 -> V_61 ) ;
if ( V_397 == V_411 ) {
T_2 V_412 = F_35 ( V_342 ) ;
V_23 -> V_340 . V_413
= V_23 -> V_36 - V_412 ;
if ( V_23 -> V_340 . V_413 != 0 )
V_133 = V_414 ;
F_81 ( & V_10 -> V_34 -> V_35 ,
L_45 ,
V_151 ,
V_133 ) ;
} else
F_81 ( & V_10 -> V_34 -> V_35 ,
L_46 ,
V_151 ) ;
break;
case V_415 :
F_81 ( & V_10 -> V_34 -> V_35 ,
L_47 ,
V_151 ,
V_342 ,
V_23 ) ;
F_93 ( V_351 , & V_342 -> V_61 ) ;
V_377 = V_352 ;
if ( ! V_67 )
V_133 = V_360 ;
else
V_133 = V_361 ;
V_401 = V_354 ;
break;
case V_245 :
F_94 (
V_67 , V_342 , V_23 , & V_377 , & V_133 ,
& V_401 ) ;
break;
case V_416 :
F_106 ( & V_23 -> V_417 , V_398 ) ;
V_23 -> V_418 |= V_419 ;
F_107 ( & V_23 -> V_417 , V_398 ) ;
V_377 = V_352 ;
V_133 = V_362 ;
V_401 = V_363 ;
F_95 ( V_351 , & V_342 -> V_61 ) ;
break;
case V_271 :
V_377 = V_352 ;
if ( ! V_67 )
V_133 = V_360 ;
else
V_133 = V_361 ;
V_401 = V_354 ;
F_93 ( V_351 , & V_342 -> V_61 ) ;
break;
default:
F_81 ( & V_10 -> V_34 -> V_35 ,
L_48
L_49 ,
V_151 , V_397 , V_342 ) ;
V_377 = V_352 ;
if ( ! V_67 )
V_133 = V_360 ;
else
V_133 = V_361 ;
if ( V_358 == V_23 -> V_153 ) {
F_93 ( V_351 , & V_342 -> V_61 ) ;
V_401 = V_354 ;
} else {
F_95 ( V_351 , & V_342 -> V_61 ) ;
V_401 = V_363 ;
}
break;
}
break;
}
switch ( V_23 -> V_153 ) {
case V_409 :
if ( V_23 -> V_37 == V_111 )
break;
if ( V_23 -> V_28 == 0 )
F_108 ( & V_10 -> V_34 -> V_35 ,
V_342 -> V_38 ,
V_23 -> V_36 , V_23 -> V_37 ) ;
else
F_109 ( & V_10 -> V_34 -> V_35 , V_23 -> V_29 ,
V_342 -> V_420 , V_23 -> V_37 ) ;
break;
case V_358 : {
struct V_16 * V_17 = & V_23 -> V_313 . V_421 ;
struct V_421 * V_421 ;
void * V_282 ;
F_109 ( & V_10 -> V_34 -> V_35 , V_17 , 1 , V_114 ) ;
V_282 = F_65 ( F_64 ( V_17 ) , V_285 ) ;
V_421 = V_282 + V_17 -> V_11 ;
F_14 ( V_421 , V_421 , V_17 -> V_18 / sizeof( T_2 ) ) ;
F_66 ( V_282 , V_285 ) ;
break;
}
default:
break;
}
F_96 ( V_10 , V_342 , V_377 ,
V_133 , V_401
) ;
F_110 ( V_10 , V_342 -> V_70 , V_342 ) ;
F_93 ( V_422 , & V_342 -> V_61 ) ;
}
static void F_111 ( struct V_423 * V_166 )
{
struct V_2 * V_3 = F_112 ( V_166 , F_113 ( * V_3 ) , V_166 ) ;
struct V_146 * V_35 = V_3 -> V_70 -> V_147 ;
enum V_175 V_176 ;
struct V_22 * V_23 ;
V_23 = ( F_17 ( V_60 , & V_3 -> V_61 ) ) ? NULL : F_10 ( V_3 ) ;
if ( ! V_23 && V_35 -> V_424 == V_425 ) {
V_176 = V_189 ;
} else if ( ! V_23 &&
( F_16 ( V_3 ) -> V_58 == V_148 ||
F_16 ( V_3 ) -> V_58 == V_149 ) ) {
V_176 = V_200 ;
} else if ( V_23 && V_23 -> V_153 == V_358 ) {
V_176 = V_190 ;
} else if ( V_23 && F_29 ( V_23 -> V_153 ) &&
! V_23 -> V_157 . V_161 ) {
if ( V_35 -> V_154 . V_155 == V_156 &&
V_23 -> V_157 . V_158 . V_159 == V_160 ) {
V_176 = V_203 ;
} else if ( V_23 -> V_37 == V_111 ) {
V_176 = V_194 ;
} else if ( V_23 -> V_157 . V_163 ) {
V_176 = V_192 ;
} else {
V_176 = V_196 ;
}
} else {
return;
}
F_31 ( V_166 , V_176 ) ;
}
static void F_114 ( struct V_423 * V_166 )
{
struct V_2 * V_3 = F_112 ( V_166 , F_113 ( * V_3 ) , V_166 ) ;
struct V_9 * V_10 = V_3 -> V_150 ;
if ( ! F_17 ( V_60 , & V_3 -> V_61 ) )
F_103 ( V_10 , V_3 ,
V_3 -> V_128 ) ;
else
F_115 ( V_10 , V_3 , V_3 -> V_128 ) ;
}
static void F_116 ( struct V_423 * V_166 )
{
struct V_2 * V_3 = F_112 ( V_166 , F_113 ( * V_3 ) , V_166 ) ;
V_3 -> V_5 -> abort = 1 ;
}
static void F_117 ( struct V_423 * V_166 )
{
struct V_2 * V_3 = F_112 ( V_166 , F_113 ( * V_3 ) , V_166 ) ;
V_3 -> V_70 -> V_323 = V_3 ;
}
static void F_118 ( struct V_423 * V_166 )
{
struct V_2 * V_3 = F_112 ( V_166 , F_113 ( * V_3 ) , V_166 ) ;
V_3 -> V_70 -> V_323 = V_3 ;
}
static void F_119 ( struct V_423 * V_166 )
{
struct V_2 * V_3 = F_112 ( V_166 , F_113 ( * V_3 ) , V_166 ) ;
V_3 -> V_70 -> V_323 = V_3 ;
}
static void F_120 ( struct V_423 * V_166 )
{
struct V_2 * V_3 = F_112 ( V_166 , F_113 ( * V_3 ) , V_166 ) ;
struct V_64 * V_5 = V_3 -> V_5 ;
struct V_122 * V_142 ;
enum V_128 V_133 ;
V_142 = & V_3 -> V_124 . V_42 ;
V_142 -> V_426 = 0 ;
V_5 -> V_91 = 0 ;
V_133 = F_61 ( V_3 ) ;
F_42 ( V_133 != V_138 , L_50 ) ;
}
static void
F_121 ( struct V_9 * V_10 ,
struct V_66 * V_67 ,
struct V_2 * V_3 )
{
F_122 ( & V_3 -> V_166 , V_427 , V_428 ) ;
V_3 -> V_70 = V_67 ;
V_3 -> V_164 = V_429 ;
V_3 -> V_209 = V_210 ;
V_3 -> V_128 = V_138 ;
V_3 -> V_185 = 0 ;
V_3 -> V_95 = 0xFFFFFFFF ;
}
static enum V_128
F_123 ( struct V_9 * V_10 ,
struct V_66 * V_67 ,
struct V_2 * V_3 )
{
struct V_146 * V_35 = V_67 -> V_147 ;
enum V_128 V_133 = V_138 ;
F_121 ( V_10 , V_67 , V_3 ) ;
if ( V_67 -> V_86 . V_85 == V_430 )
return V_431 ;
if ( V_35 -> V_424 == V_425 )
;
else if ( V_35 -> V_424 == V_432 || ( V_35 -> V_433 & V_434 ) )
memset ( & V_3 -> V_124 . V_42 , 0 , sizeof( V_3 -> V_124 . V_42 ) ) ;
else if ( F_124 ( V_35 ) )
;
else
return V_435 ;
memset ( V_3 -> V_5 , 0 , F_37 ( struct V_64 , V_6 ) ) ;
return V_133 ;
}
enum V_128 F_125 ( struct V_9 * V_10 ,
struct V_66 * V_67 ,
T_6 V_62 , struct V_2 * V_3 )
{
struct V_146 * V_35 = V_67 -> V_147 ;
enum V_128 V_133 = V_138 ;
F_121 ( V_10 , V_67 , V_3 ) ;
if ( V_35 -> V_424 == V_425 ||
V_35 -> V_424 == V_432 || ( V_35 -> V_433 & V_434 ) ) {
F_93 ( V_60 , & V_3 -> V_61 ) ;
memset ( V_3 -> V_5 , 0 , sizeof( struct V_64 ) ) ;
} else
V_133 = V_435 ;
return V_133 ;
}
static enum V_128 F_126 (
struct V_2 * V_342 )
{
enum V_128 V_133 ;
F_81 ( & V_342 -> V_9 -> V_34 -> V_35 ,
L_51 ,
V_151 ,
V_342 ) ;
V_133 = F_30 ( V_342 ) ;
return V_133 ;
}
static enum V_128 F_127 ( struct V_2 * V_3 )
{
struct V_22 * V_23 = F_10 ( V_3 ) ;
struct V_122 * V_158 = & V_3 -> V_124 . V_42 ;
struct V_436 * V_437 = V_23 -> V_438 ;
enum V_128 V_133 ;
F_81 ( & V_3 -> V_9 -> V_34 -> V_35 ,
L_52 ,
V_151 ,
V_3 ) ;
memcpy ( V_158 , & V_23 -> V_157 . V_158 , sizeof( struct V_122 ) ) ;
if ( ! V_23 -> V_157 . V_439 )
V_158 -> V_61 |= 0x80 ;
V_158 -> V_61 &= 0xF0 ;
V_133 = F_33 ( V_3 ) ;
if ( V_437 && ( V_437 -> V_440 . V_159 == V_441 ||
V_437 -> V_440 . V_159 == V_442 ) ) {
V_158 -> V_335 = V_437 -> V_181 << 3 ;
V_3 -> V_5 -> type . V_124 . V_443 = V_437 -> V_181 ;
}
return V_133 ;
}
static enum V_128
F_128 ( struct V_331 * V_35 ,
struct V_2 * V_3 ,
struct V_22 * V_23 )
{
struct V_16 * V_17 = & V_23 -> V_313 . V_421 ;
struct V_66 * V_67 ;
struct V_64 * V_65 ;
struct V_68 * V_69 ;
struct V_421 * V_421 ;
void * V_282 ;
T_3 V_444 ;
T_2 V_42 ;
V_282 = F_65 ( F_64 ( V_17 ) , V_285 ) ;
V_421 = V_282 + V_17 -> V_11 ;
if ( V_421 -> V_444 == 0 ) {
switch ( V_421 -> V_445 ) {
case V_446 :
case V_447 :
case V_448 :
case V_449 :
V_421 -> V_444 = 2 ;
break;
case V_450 :
case V_451 :
case V_452 :
V_421 -> V_444 = 9 ;
break;
}
}
V_444 = V_421 -> V_444 ;
F_14 ( V_421 , V_421 , V_17 -> V_18 / sizeof( T_2 ) ) ;
V_42 = * ( T_2 * ) V_421 ;
F_66 ( V_282 , V_285 ) ;
if ( ! F_129 ( V_35 , V_17 , 1 , V_114 ) )
return V_152 ;
V_3 -> V_164 = V_453 ;
V_65 = V_3 -> V_5 ;
V_67 = V_3 -> V_70 ;
V_69 = V_67 -> V_71 ;
V_65 -> V_72 = 0 ;
V_65 -> V_73 = 1 ;
V_65 -> V_74 = V_67 -> V_74 ;
V_65 -> V_75 = V_76 ;
V_65 -> V_77 = V_69 -> V_78 ;
V_65 -> V_79 = V_180 ;
V_65 -> abort = 0 ;
V_65 -> V_81 = V_82 ;
V_65 -> V_83 = V_84 ;
V_65 -> V_85 = V_67 -> V_86 . V_85 ;
V_65 -> V_87 = 0 ;
V_65 -> V_112 = V_454 ;
V_65 -> V_88 = 0 ;
V_65 -> V_89 = 1 ;
V_65 -> V_90 = 0 ;
V_65 -> V_91 = 1 ;
V_65 -> V_92 = 0 ;
V_65 -> V_93 = 0 ;
V_65 -> V_21 = 0 ;
V_65 -> V_107 = V_444 ;
V_65 -> V_116 = 0 ;
memcpy ( & V_65 -> type . V_455 , & V_42 , sizeof( T_2 ) ) ;
V_65 -> V_94 = 0 ;
V_3 -> V_95 = ( V_96 |
( V_76 << V_97 ) |
( V_69 -> V_78 <<
V_98 ) |
F_19 ( V_3 -> V_62 ) ) ;
V_65 -> V_99 = F_6 ( F_7 ( V_17 ) ) ;
V_65 -> V_100 = F_8 ( F_7 ( V_17 ) + sizeof( T_2 ) ) ;
V_65 -> V_102 = 0 ;
V_65 -> V_103 = 0 ;
F_31 ( & V_3 -> V_166 , V_167 ) ;
return V_138 ;
}
static enum V_128 F_130 ( struct V_2 * V_3 )
{
struct V_22 * V_23 = F_10 ( V_3 ) ;
struct V_331 * V_35 = & V_3 -> V_9 -> V_34 -> V_35 ;
enum V_128 V_133 = V_152 ;
V_133 = F_128 ( V_35 , V_3 , V_23 ) ;
if ( V_133 != V_138 )
F_81 ( & V_3 -> V_9 -> V_34 -> V_35 ,
L_53 ,
V_151 ,
V_133 ) ;
return V_133 ;
}
static enum V_128 F_131 ( struct V_9 * V_10 ,
struct V_2 * V_342 ,
struct V_66 * V_67 )
{
enum V_128 V_133 = V_138 ;
struct V_22 * V_23 = F_10 ( V_342 ) ;
F_81 ( & V_10 -> V_34 -> V_35 ,
L_54
L_55 ,
V_151 ,
V_67 ,
V_342 ,
V_23 -> V_28 ) ;
if ( V_23 -> V_28 &&
! F_29 ( V_23 -> V_153 ) &&
! ( V_358 & V_23 -> V_153 ) ) {
V_342 -> V_420 = F_129 (
& V_10 -> V_34 -> V_35 ,
V_23 -> V_29 ,
V_23 -> V_28 ,
V_23 -> V_37
) ;
if ( V_342 -> V_420 == 0 )
return V_456 ;
}
V_133 = F_123 ( V_10 , V_67 , V_342 ) ;
if ( V_133 != V_138 ) {
F_81 ( & V_10 -> V_34 -> V_35 ,
L_56 ,
V_151 ) ;
return V_152 ;
}
switch ( V_23 -> V_153 ) {
case V_358 :
V_133 = F_130 ( V_342 ) ;
break;
case V_409 :
V_133 = F_126 ( V_342 ) ;
break;
case V_457 :
case V_434 :
case V_457 | V_434 :
V_133 = F_127 ( V_342 ) ;
break;
default:
F_81 ( & V_10 -> V_34 -> V_35 ,
L_44 , V_151 ) ;
return V_152 ;
}
return V_138 ;
}
static struct V_2 * F_132 ( struct V_9 * V_10 , T_6 V_181 )
{
struct V_2 * V_3 ;
V_3 = V_10 -> V_458 [ F_19 ( V_181 ) ] ;
V_3 -> V_62 = V_181 ;
V_3 -> V_383 = NULL ;
V_3 -> V_61 = 0 ;
V_3 -> V_420 = 0 ;
F_133 ( & V_3 -> V_379 ) ;
F_133 ( & V_3 -> V_381 ) ;
F_134 ( V_3 , V_459 ) ;
return V_3 ;
}
static struct V_2 * F_135 ( struct V_9 * V_10 ,
struct V_22 * V_23 ,
T_6 V_181 )
{
struct V_2 * V_3 ;
V_3 = F_132 ( V_10 , V_181 ) ;
V_3 -> V_299 . V_300 = V_23 ;
F_95 ( V_60 , & V_3 -> V_61 ) ;
V_23 -> V_460 = V_3 ;
return V_3 ;
}
struct V_2 * F_136 ( struct V_9 * V_10 ,
struct V_55 * V_55 ,
T_6 V_181 )
{
struct V_2 * V_3 ;
V_3 = F_132 ( V_10 , V_181 ) ;
V_3 -> V_299 . V_461 = V_55 ;
F_93 ( V_60 , & V_3 -> V_61 ) ;
return V_3 ;
}
int F_137 ( struct V_9 * V_10 , struct V_66 * V_67 ,
struct V_22 * V_23 , T_6 V_181 )
{
enum V_128 V_133 = V_435 ;
struct V_2 * V_3 ;
unsigned long V_61 ;
int V_462 = 0 ;
V_3 = F_135 ( V_10 , V_23 , V_181 ) ;
V_133 = F_131 ( V_10 , V_3 , V_67 ) ;
if ( V_133 != V_138 ) {
F_81 ( & V_10 -> V_34 -> V_35 ,
L_57 ,
V_151 ,
V_133 ) ;
return V_133 ;
}
F_106 ( & V_10 -> V_463 , V_61 ) ;
if ( F_17 ( V_464 , & V_67 -> V_61 ) ) {
if ( F_138 ( V_23 ) ) {
V_133 = F_139 ( V_10 ,
V_67 ,
V_3 ) ;
} else {
V_133 = V_152 ;
}
} else {
V_133 = F_140 ( V_10 , V_67 ,
V_3 ) ;
}
if ( V_133 != V_138 &&
V_133 != V_244 ) {
F_81 ( & V_10 -> V_34 -> V_35 ,
L_58 ,
V_151 , V_133 ) ;
F_107 ( & V_10 -> V_463 , V_61 ) ;
return V_133 ;
}
F_98 ( & V_3 -> V_381 , & V_67 -> V_465 ) ;
if ( V_133 == V_138 ) {
F_134 ( V_3 , V_466 ) ;
} else {
F_93 ( V_422 , & V_3 -> V_61 ) ;
F_134 ( V_3 , V_408 ) ;
}
F_107 ( & V_10 -> V_463 , V_61 ) ;
if ( V_133 ==
V_244 ) {
F_106 ( & V_23 -> V_417 , V_61 ) ;
V_23 -> V_418 |= V_419 ;
F_107 ( & V_23 -> V_417 , V_61 ) ;
F_141 ( V_10 , V_23 ,
V_467 ) ;
V_133 = V_138 ;
}
return V_462 ;
}
