const char * F_1 ( enum V_1 V_2 )
{
static const char * const V_3 [] = V_4 ;
return V_3 [ V_2 ] ;
}
static struct V_5 * F_2 ( struct V_6 * V_7 ,
int V_8 )
{
if ( V_8 == 0 )
return & V_7 -> V_9 -> V_10 ;
else if ( V_8 == 1 )
return & V_7 -> V_9 -> V_11 ;
else if ( V_8 < 0 )
return NULL ;
else
return & V_7 -> V_12 [ V_8 - 2 ] ;
}
static T_1 F_3 ( struct V_13 * V_14 ,
struct V_6 * V_7 , T_2 V_8 )
{
T_2 V_15 ;
if ( V_8 == 0 ) {
V_15 = ( void * ) & V_7 -> V_9 -> V_10 -
( void * ) & V_14 -> V_16 [ 0 ] ;
return V_14 -> V_17 + V_15 ;
} else if ( V_8 == 1 ) {
V_15 = ( void * ) & V_7 -> V_9 -> V_11 -
( void * ) & V_14 -> V_16 [ 0 ] ;
return V_14 -> V_17 + V_15 ;
}
return F_4 ( V_7 , & V_7 -> V_12 [ V_8 - 2 ] ) ;
}
static void F_5 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
V_19 -> V_22 = F_6 ( V_21 ) ;
V_19 -> V_23 = F_7 ( F_8 ( V_21 ) ) ;
V_19 -> V_24 = F_9 ( F_8 ( V_21 ) ) ;
V_19 -> V_25 = 0 ;
}
static void F_10 ( struct V_6 * V_7 )
{
struct V_13 * V_14 = V_7 -> V_13 ;
struct V_26 * V_27 = F_11 ( V_7 ) ;
struct V_20 * V_21 = NULL ;
T_1 V_28 ;
T_2 V_29 = 0 ;
struct V_5 * V_30 = NULL ;
struct V_5 * V_31 = NULL ;
if ( V_27 -> V_32 > 0 ) {
V_21 = V_27 -> V_33 ;
while ( V_21 ) {
V_30 = F_2 ( V_7 , V_29 ) ;
F_5 ( & V_30 -> V_34 , V_21 ) ;
V_21 = F_12 ( V_21 ) ;
if ( V_21 ) {
F_5 ( & V_30 -> V_35 , V_21 ) ;
V_21 = F_12 ( V_21 ) ;
} else
memset ( & V_30 -> V_35 , 0 , sizeof( V_30 -> V_35 ) ) ;
if ( V_31 ) {
V_28 = F_3 ( V_14 ,
V_7 ,
V_29 ) ;
V_31 -> V_36 =
F_7 ( V_28 ) ;
V_31 -> V_37 =
F_9 ( V_28 ) ;
}
V_31 = V_30 ;
V_29 ++ ;
}
} else {
V_30 = F_2 ( V_7 , V_29 ) ;
V_28 = F_13 ( & V_14 -> V_38 -> V_39 ,
V_27 -> V_33 ,
V_27 -> V_40 ,
V_27 -> V_41 ) ;
V_7 -> V_42 = V_28 ;
V_30 -> V_34 . V_22 = V_27 -> V_40 ;
V_30 -> V_34 . V_23 = F_7 ( V_28 ) ;
V_30 -> V_34 . V_24 = F_9 ( V_28 ) ;
}
if ( V_30 ) {
V_30 -> V_36 = 0 ;
V_30 -> V_37 = 0 ;
}
}
static void F_14 ( struct V_6 * V_7 )
{
struct V_43 * V_44 ;
struct V_26 * V_27 = F_11 ( V_7 ) ;
V_44 = & V_7 -> V_45 . V_46 ;
memcpy ( V_44 -> V_47 , V_27 -> V_48 . V_47 , 8 ) ;
V_44 -> V_49 = 0 ;
V_44 -> V_50 = 0 ;
V_44 -> V_51 = 0 ;
V_44 -> V_52 = 0 ;
V_44 -> V_53 = V_27 -> V_48 . V_53 ;
V_44 -> V_54 = V_27 -> V_48 . V_54 ;
V_44 -> V_55 = 0 ;
F_15 ( & V_44 -> V_56 , V_27 -> V_48 . V_56 ,
sizeof( V_27 -> V_48 . V_56 ) / sizeof( T_2 ) ) ;
}
static void F_16 ( struct V_6 * V_7 )
{
struct V_57 * V_58 ;
struct V_26 * V_27 = F_11 ( V_7 ) ;
struct V_59 * V_59 = F_17 ( V_7 ) ;
V_58 = & V_7 -> V_45 . V_60 ;
memset ( V_58 , 0 , sizeof( struct V_57 ) ) ;
memcpy ( V_58 -> V_47 , V_27 -> V_48 . V_47 , 8 ) ;
V_58 -> V_61 = V_59 -> V_62 ;
V_58 -> V_63 =
( F_18 ( V_64 , & V_7 -> V_65 ) ) ?
V_59 -> V_66 :
V_67 ;
}
static void F_19 (
struct V_6 * V_7 ,
struct V_68 * V_69 )
{
T_1 V_28 ;
struct V_70 * V_71 ;
struct V_72 * V_73 ;
V_71 = V_7 -> V_74 ;
V_73 = V_71 -> V_75 ;
V_69 -> abort = 0 ;
V_69 -> V_76 = 0 ;
V_69 -> V_77 = 1 ;
V_69 -> V_78 = V_71 -> V_78 ;
V_69 -> V_79 = V_80 ;
V_69 -> V_81 = V_73 -> V_82 ;
V_69 -> V_83 = V_84 ;
V_69 -> V_85 = V_86 ;
V_69 -> V_87 = V_88 ;
V_69 -> V_89 = V_71 -> V_90 . V_89 ;
V_69 -> V_91 = 0 ;
V_69 -> V_92 = 0 ;
V_69 -> V_93 = 1 ;
V_69 -> V_94 = 0 ;
V_69 -> V_95 = 0 ;
V_69 -> V_96 = 0 ;
V_69 -> V_97 = 0 ;
V_69 -> V_25 = 0 ;
V_69 -> V_98 = 0x01 ;
V_7 -> V_99 = ( V_100 |
( V_80 << V_101 ) |
( V_73 -> V_82 <<
V_102 ) |
F_20 ( V_7 -> V_66 ) ) ;
V_28 = F_4 ( V_7 , & V_7 -> V_45 . V_46 ) ;
V_69 -> V_103 = F_7 ( V_28 ) ;
V_69 -> V_104 = F_9 ( V_28 ) ;
V_28 = F_4 ( V_7 , & V_7 -> V_45 . V_105 ) ;
V_69 -> V_106 = F_7 ( V_28 ) ;
V_69 -> V_107 = F_9 ( V_28 ) ;
}
static T_3 F_21 ( struct V_108 * V_109 )
{
switch ( V_109 -> V_110 ) {
case 512 :
return 0 ;
case 1024 :
return 1 ;
case 4096 :
return 3 ;
default:
return 0xff ;
}
}
static T_2 F_22 ( T_2 V_111 , T_2 V_110 )
{
return ( V_111 >> F_23 ( V_110 ) ) * 8 ;
}
static void F_24 ( struct V_6 * V_7 , T_3 type , T_3 V_112 )
{
struct V_68 * V_9 = V_7 -> V_9 ;
struct V_113 * V_114 = V_7 -> V_115 . V_116 -> V_117 ;
T_3 V_118 = F_21 ( V_114 -> V_119 ) ;
V_9 -> V_97 = 1 ;
V_9 -> V_120 = 1 ;
V_9 -> V_118 = V_118 ;
V_9 -> V_121 = 0x2 ;
V_9 -> V_122 += F_22 ( V_9 -> V_122 ,
V_114 -> V_119 -> V_110 ) ;
V_9 -> V_123 = 0 ;
V_9 -> V_124 = 0 ;
V_9 -> V_125 = 0 ;
V_9 -> V_126 = 0 ;
V_9 -> V_127 = 0 ;
V_9 -> V_128 = V_114 -> V_119 -> V_110 ;
V_9 -> V_129 = 0 ;
V_9 -> V_130 = 8 ;
V_9 -> V_131 = 0 ;
V_9 -> V_132 = V_114 -> V_119 -> V_110 ;
V_9 -> V_133 = 0 ;
V_9 -> V_134 = 0 ;
V_9 -> V_135 = 0 ;
V_9 -> V_136 . V_112 = 0x2 ;
V_9 -> V_137 = 0 ;
V_9 -> V_138 = 0 ;
V_9 -> V_139 = 0 ;
if ( ( type & V_140 ) || ( type & V_141 ) )
V_9 -> V_142 = F_25 ( V_114 ) & 0xffffffff ;
else if ( type & V_143 )
V_9 -> V_142 = 0 ;
}
static void F_26 ( struct V_6 * V_7 , T_3 type , T_3 V_112 )
{
struct V_68 * V_9 = V_7 -> V_9 ;
struct V_113 * V_114 = V_7 -> V_115 . V_116 -> V_117 ;
T_3 V_118 = F_21 ( V_114 -> V_119 ) ;
V_9 -> V_97 = 1 ;
V_9 -> V_120 = 1 ;
V_9 -> V_118 = V_118 ;
V_9 -> V_121 = 0x1 ;
V_9 -> V_122 += F_22 ( V_9 -> V_122 ,
V_114 -> V_119 -> V_110 ) ;
V_9 -> V_123 = 0 ;
V_9 -> V_124 = 0 ;
V_9 -> V_125 = 0 ;
V_9 -> V_126 = 0 ;
if ( ( type & V_140 ) || ( type & V_141 ) )
V_9 -> V_127 = F_25 ( V_114 ) & 0xffffffff ;
else if ( type & V_143 )
V_9 -> V_127 = 0 ;
V_9 -> V_128 = V_114 -> V_119 -> V_110 ;
V_9 -> V_129 = 0 ;
V_9 -> V_130 = 8 ;
V_9 -> V_131 = 0 ;
V_9 -> V_132 = V_114 -> V_119 -> V_110 ;
V_9 -> V_133 = 0 ;
V_9 -> V_134 = 0 ;
V_9 -> V_135 = 0 ;
V_9 -> V_136 . V_144 = 1 ;
V_9 -> V_136 . V_112 = 0x1 ;
if ( ( type & V_140 ) || ( type & V_141 ) ) {
V_9 -> V_136 . V_145 = 1 ;
V_9 -> V_136 . V_146 = 1 ;
} else if ( type & V_143 )
V_9 -> V_136 . V_147 = 1 ;
V_9 -> V_137 = 0 ;
V_9 -> V_138 = 0 ;
V_9 -> V_139 = 0 ;
V_9 -> V_142 = 0 ;
}
static void F_27 ( struct V_6 * V_7 ,
enum V_148 V_149 ,
T_2 V_111 )
{
struct V_68 * V_69 = V_7 -> V_9 ;
struct V_26 * V_26 = V_7 -> V_115 . V_116 ;
struct V_113 * V_114 = V_26 -> V_117 ;
T_3 V_150 = F_28 ( V_114 ) ;
T_3 V_151 = F_29 ( V_114 ) ;
F_19 ( V_7 , V_69 ) ;
V_69 -> V_152 =
sizeof( struct V_43 ) / sizeof( T_2 ) ;
V_69 -> type . V_45 . V_153 = V_154 ;
switch ( V_149 ) {
case V_155 :
case V_156 :
default:
V_69 -> V_157 = V_158 ;
break;
case V_159 :
V_69 -> V_157 = V_160 ;
break;
}
V_69 -> V_122 = V_111 ;
if ( V_69 -> V_122 > 0 )
F_10 ( V_7 ) ;
if ( V_150 != V_161 ) {
if ( V_151 == V_162 )
F_26 ( V_7 , V_150 , V_151 ) ;
else if ( V_151 == V_163 )
F_24 ( V_7 , V_150 , V_151 ) ;
}
}
static void F_30 ( struct V_6 * V_7 )
{
struct V_68 * V_69 = V_7 -> V_9 ;
F_19 ( V_7 , V_69 ) ;
V_69 -> V_95 = 1 ;
V_69 -> V_76 = V_164 ;
V_69 -> V_157 = V_165 ;
V_69 -> V_122 = 0 ;
V_69 -> type . V_45 . V_153 = V_166 ;
V_69 -> V_152 =
sizeof( struct V_57 ) / sizeof( T_2 ) ;
}
static void F_31 (
struct V_6 * V_7 ,
struct V_68 * V_69 )
{
T_1 V_28 ;
struct V_70 * V_71 ;
struct V_72 * V_73 ;
V_71 = V_7 -> V_74 ;
V_73 = V_71 -> V_75 ;
V_69 -> abort = 0 ;
V_69 -> V_76 = V_167 ;
V_69 -> V_77 = 1 ;
V_69 -> V_78 = V_71 -> V_78 ;
V_69 -> V_79 = V_80 ;
V_69 -> V_81 = V_73 -> V_82 ;
V_69 -> V_83 = V_168 ;
V_69 -> V_85 = V_86 ;
V_69 -> V_87 = V_88 ;
V_69 -> V_89 = V_71 -> V_90 . V_89 ;
V_69 -> V_91 = 0 ;
V_69 -> V_92 = 0 ;
V_69 -> V_93 = 1 ;
V_69 -> V_94 = 0 ;
V_69 -> V_95 = 0 ;
V_69 -> V_96 = 0 ;
V_69 -> V_97 = 0 ;
V_69 -> V_25 = 0 ;
V_69 -> V_98 = 0x01 ;
V_69 -> V_152 =
( sizeof( struct V_169 ) - sizeof( T_2 ) ) / sizeof( T_2 ) ;
V_69 -> type . V_170 [ 0 ] = * ( T_2 * ) & V_7 -> V_171 . V_46 ;
V_7 -> V_99 = ( V_100 |
( V_80 << V_101 ) |
( V_73 -> V_82 <<
V_102 ) |
F_20 ( V_7 -> V_66 ) ) ;
V_28 = F_4 ( V_7 ,
( ( char * ) & V_7 -> V_171 . V_46 ) +
sizeof( T_2 ) ) ;
V_69 -> V_103 = F_7 ( V_28 ) ;
V_69 -> V_104 = F_9 ( V_28 ) ;
V_69 -> V_106 = 0 ;
V_69 -> V_107 = 0 ;
}
static void F_32 ( struct V_6 * V_7 )
{
struct V_68 * V_69 = V_7 -> V_9 ;
F_31 ( V_7 , V_69 ) ;
V_69 -> V_95 = 0 ;
V_69 -> V_76 = V_167 ;
V_69 -> V_157 = V_172 ;
V_69 -> type . V_171 . V_173 = V_174 ;
V_69 -> V_122 = sizeof( struct V_169 ) - sizeof( T_2 ) ;
}
static enum V_175 F_33 ( struct V_6 * V_7 ,
bool V_176 )
{
struct V_177 * V_178 = & V_7 -> V_171 . V_179 ;
F_32 ( V_7 ) ;
V_178 -> V_180 = 0 ;
V_178 -> V_181 . V_15 = 0 ;
V_178 -> V_181 . V_182 = V_183 ;
if ( V_176 ) {
F_10 ( V_7 ) ;
V_178 -> V_181 . V_184 = 0 ;
} else {
V_178 -> V_181 . V_184 = - 1 ;
}
return V_185 ;
}
static void F_34 ( struct V_6 * V_7 ,
T_3 V_186 ,
T_2 V_111 ,
enum V_148 V_149 )
{
struct V_68 * V_69 = V_7 -> V_9 ;
F_31 ( V_7 , V_69 ) ;
F_10 ( V_7 ) ;
V_69 -> V_122 = V_111 ;
if ( V_149 == V_159 ) {
V_69 -> V_157 = V_186 + ( V_187
- V_188 ) ;
} else {
V_69 -> V_157 = V_186 ;
}
}
static void F_35 ( struct V_6 * V_7 )
{
struct V_169 * V_189 = & V_7 -> V_171 . V_46 ;
struct V_26 * V_27 ;
V_189 -> V_190 |= V_191 ;
F_32 ( V_7 ) ;
V_27 = F_11 ( V_7 ) ;
if ( V_27 -> V_41 == V_156 )
V_27 -> V_40 = 0 ;
V_7 -> V_171 . V_105 . V_173 = 0 ;
}
static enum V_175
F_36 ( struct V_6 * V_7 ,
T_2 V_111 ,
enum V_148 V_149 ,
bool V_192 )
{
enum V_175 V_180 = V_185 ;
struct V_26 * V_27 = F_11 ( V_7 ) ;
struct V_193 * V_39 = V_7 -> V_74 -> V_194 ;
if ( F_18 ( V_64 , & V_7 -> V_65 ) ) {
struct V_59 * V_60 = F_17 ( V_7 ) ;
F_37 ( & V_7 -> V_195 -> V_38 -> V_39 ,
L_1
L_2 ,
V_196 , V_7 , V_60 -> V_62 ) ;
return V_197 ;
}
if ( ! F_38 ( V_27 -> V_198 ) ) {
F_37 ( & V_7 -> V_195 -> V_38 -> V_39 ,
L_3 ,
V_196 ,
V_27 -> V_198 ) ;
return V_197 ;
}
if ( V_39 -> V_199 . V_200 == V_201 &&
V_27 -> V_202 . V_203 . V_204 == V_205 ) {
F_35 ( V_7 ) ;
return V_185 ;
}
if ( V_27 -> V_41 == V_156 ) {
F_32 ( V_7 ) ;
return V_185 ;
}
if ( V_27 -> V_202 . V_206 ) {
F_34 ( V_7 ,
V_207 ,
V_111 , V_149 ) ;
return V_185 ;
}
if ( V_27 -> V_202 . V_208 ) {
F_34 ( V_7 ,
V_188 ,
V_111 , V_149 ) ;
return V_185 ;
} else
return F_33 ( V_7 , V_192 ) ;
return V_180 ;
}
static enum V_175 F_39 ( struct V_6 * V_7 )
{
struct V_26 * V_27 = F_11 ( V_7 ) ;
V_7 -> V_209 = V_210 ;
F_27 ( V_7 ,
V_27 -> V_41 ,
V_27 -> V_40 ) ;
F_14 ( V_7 ) ;
F_40 ( & V_7 -> V_211 , V_212 ) ;
return V_185 ;
}
enum V_175 F_41 (
struct V_6 * V_7 )
{
F_30 ( V_7 ) ;
F_16 ( V_7 ) ;
F_40 ( & V_7 -> V_211 , V_212 ) ;
return V_185 ;
}
static enum V_175 F_42 ( struct V_6 * V_7 )
{
enum V_175 V_180 ;
bool V_192 = false ;
struct V_26 * V_27 = F_11 ( V_7 ) ;
V_7 -> V_209 = V_213 ;
V_192 = ( V_27 -> V_41 == V_156 ) ? false : true ;
V_180 = F_36 ( V_7 ,
V_27 -> V_40 ,
V_27 -> V_41 ,
V_192 ) ;
if ( V_180 == V_185 )
F_40 ( & V_7 -> V_211 , V_212 ) ;
return V_180 ;
}
static T_2 F_43 ( struct V_6 * V_7 )
{
struct V_13 * V_14 = V_7 -> V_195 ;
T_2 V_214 = 0 ;
if ( F_44 ( & V_14 -> V_215 -> V_25 ) == 0 ) {
void T_4 * V_216 = V_14 -> V_217 ;
V_214 = F_44 ( V_216 +
( V_218 + F_45 ( struct V_68 , type . V_45 . V_219 ) ) +
( ( sizeof( struct V_68 ) ) * F_20 ( V_7 -> V_66 ) ) ) ;
}
return V_214 ;
}
enum V_175 F_46 ( struct V_6 * V_7 )
{
enum V_1 V_2 ;
struct V_68 * V_9 = V_7 -> V_9 ;
struct V_13 * V_14 = V_7 -> V_195 ;
V_2 = V_7 -> V_211 . V_220 ;
if ( V_2 != V_212 ) {
F_47 ( & V_14 -> V_38 -> V_39 ,
L_4
L_5 , V_196 , V_2 ) ;
return V_221 ;
}
V_9 -> V_222 = F_20 ( V_7 -> V_66 ) ;
switch ( V_9 -> V_83 ) {
case V_223 :
case V_84 :
V_9 -> type . V_45 . V_224 = V_7 -> V_66 ;
V_9 -> type . V_45 . V_225 = 0xFFFF ;
break;
case V_168 :
break;
case V_226 :
break;
default:
break;
}
V_7 -> V_99 |= F_20 ( V_7 -> V_66 ) ;
F_40 ( & V_7 -> V_211 , V_227 ) ;
return V_185 ;
}
enum V_175
F_48 ( struct V_6 * V_7 )
{
enum V_1 V_2 ;
V_2 = V_7 -> V_211 . V_220 ;
switch ( V_2 ) {
case V_212 :
F_49 ( V_228 , & V_7 -> V_65 ) ;
V_7 -> V_229 = V_230 ;
V_7 -> V_175 = V_231 ;
F_40 ( & V_7 -> V_211 , V_232 ) ;
return V_185 ;
case V_227 :
case V_233 :
case V_234 :
case V_235 :
case V_236 :
case V_237 :
case V_238 :
case V_239 :
case V_240 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
F_40 ( & V_7 -> V_211 , V_249 ) ;
case V_249 :
if ( ! F_50 ( V_7 -> V_74 ) )
F_49 ( V_250 , & V_7 -> V_65 ) ;
else
F_51 ( V_250 , & V_7 -> V_65 ) ;
return V_185 ;
case V_232 :
default:
F_47 ( & V_7 -> V_195 -> V_38 -> V_39 ,
L_6
L_5 , V_196 , V_7 -> V_211 . V_220 ) ;
break;
}
return V_221 ;
}
enum V_175 F_52 ( struct V_6 * V_7 )
{
enum V_1 V_2 ;
struct V_13 * V_14 = V_7 -> V_195 ;
V_2 = V_7 -> V_211 . V_220 ;
if ( F_53 ( V_2 != V_232 ,
L_7 ,
F_1 ( V_2 ) ) )
return V_221 ;
if ( V_7 -> V_251 != V_252 )
F_54 ( V_14 ,
V_7 -> V_251 ) ;
F_40 ( & V_7 -> V_211 , V_253 ) ;
return V_185 ;
}
enum V_175 F_55 ( struct V_6 * V_7 ,
T_2 V_254 )
{
enum V_1 V_2 ;
struct V_13 * V_14 = V_7 -> V_195 ;
V_2 = V_7 -> V_211 . V_220 ;
if ( V_2 != V_242 ) {
F_47 ( & V_14 -> V_38 -> V_39 , L_8 ,
V_196 , V_254 , F_1 ( V_2 ) ) ;
return V_221 ;
}
switch ( F_56 ( V_254 ) ) {
case V_255 << V_256 :
F_40 ( & V_7 -> V_211 , V_241 ) ;
return V_185 ;
default:
F_37 ( & V_14 -> V_38 -> V_39 ,
L_9 ,
V_196 , V_254 ) ;
return V_197 ;
}
}
static void F_57 ( struct V_6 * V_7 )
{
void * V_257 ;
T_2 V_111 ;
struct V_258 * V_259 ;
struct V_59 * V_59 = F_17 ( V_7 ) ;
V_259 = & V_7 -> V_45 . V_105 ;
V_257 = & V_59 -> V_260 . V_261 ;
V_111 = F_58 ( T_2 ,
V_262 ,
F_59 ( V_259 -> V_263 ) ) ;
memcpy ( V_257 , V_259 -> V_264 , V_111 ) ;
}
static enum V_175
F_60 ( struct V_6 * V_7 ,
T_2 V_265 )
{
struct V_258 * V_261 ;
T_3 V_266 ;
switch ( F_61 ( V_265 ) ) {
case F_62 ( V_267 ) :
V_7 -> V_229 = V_267 ;
V_7 -> V_175 = V_185 ;
break;
case F_62 ( V_268 ) : {
struct V_258 * V_260 = & V_7 -> V_45 . V_105 ;
T_5 V_269 = V_262 / sizeof( T_2 ) ;
F_15 ( & V_7 -> V_45 . V_105 ,
& V_7 -> V_45 . V_105 ,
V_269 ) ;
if ( V_260 -> V_180 == 0 ) {
V_7 -> V_229 = V_267 ;
V_7 -> V_175 = V_270 ;
} else {
V_7 -> V_229 = V_271 ;
V_7 -> V_175 = V_272 ;
}
break;
}
case F_62 ( V_271 ) : {
T_5 V_269 = V_262 / sizeof( T_2 ) ;
F_15 ( & V_7 -> V_45 . V_105 ,
& V_7 -> V_45 . V_105 ,
V_269 ) ;
V_7 -> V_229 = V_271 ;
V_7 -> V_175 = V_272 ;
break;
}
case F_62 ( V_273 ) :
V_261 = & V_7 -> V_45 . V_105 ;
V_266 = V_261 -> V_266 ;
if ( V_266 == 1 || V_266 == 2 ) {
V_7 -> V_229 = V_271 ;
V_7 -> V_175 = V_272 ;
} else {
V_7 -> V_229 = V_267 ;
V_7 -> V_175 = V_185 ;
}
break;
case F_62 ( V_274 ) :
case F_62 ( V_275 ) :
case F_62 ( V_276 ) :
case F_62 ( V_277 ) :
case F_62 ( V_278 ) :
case F_62 ( V_279 ) :
case F_62 ( V_280 ) :
case F_62 ( V_281 ) :
case F_62 ( V_282 ) :
case F_62 ( V_283 ) :
case F_62 ( V_284 ) :
if ( V_7 -> V_209 == V_213 ) {
V_7 -> V_229 = F_61 ( V_265 ) >>
V_285 ;
V_7 -> V_175 = V_286 ;
} else {
V_7 -> V_229 = F_61 ( V_265 ) >>
V_285 ;
V_7 -> V_175 = V_287 ;
}
break;
case F_62 ( V_288 ) :
case F_62 ( V_289 ) :
case F_62 ( V_290 ) :
case F_62 ( V_291 ) :
case F_62 ( V_292 ) :
case F_62 ( V_293 ) :
case F_62 ( V_294 ) :
case F_62 ( V_295 ) :
case F_62 ( V_296 ) :
case F_62 ( V_297 ) :
V_7 -> V_229 = F_61 ( V_265 ) >>
V_285 ;
V_7 -> V_175 = V_286 ;
break;
case F_62 ( V_298 ) :
case F_62 ( V_299 ) :
case F_62 ( V_300 ) :
case F_62 ( V_301 ) :
case F_62 ( V_302 ) :
case F_62 ( V_303 ) :
case F_62 ( V_304 ) :
case F_62 ( V_305 ) :
case F_62 ( V_306 ) :
case F_62 ( V_307 ) :
case F_62 ( V_308 ) :
case F_62 ( V_309 ) :
case F_62 ( V_310 ) :
case F_62 ( V_311 ) :
case F_62 ( V_312 ) :
default:
V_7 -> V_229 = F_61 ( V_265 ) >>
V_285 ;
V_7 -> V_175 = V_287 ;
break;
}
F_40 ( & V_7 -> V_211 , V_232 ) ;
return V_185 ;
}
static enum V_175
F_63 ( struct V_6 * V_7 ,
T_2 V_265 )
{
switch ( F_61 ( V_265 ) ) {
case ( V_267 << V_285 ) :
case ( V_230 << V_285 ) :
V_7 -> V_229 = V_230 ;
V_7 -> V_175 = V_231 ;
F_40 ( & V_7 -> V_211 , V_232 ) ;
break;
default:
break;
}
return V_185 ;
}
static enum V_175 F_64 ( struct V_6 * V_7 ,
T_2 V_265 )
{
switch ( F_61 ( V_265 ) ) {
case F_62 ( V_267 ) :
V_7 -> V_229 = V_267 ;
V_7 -> V_175 = V_185 ;
F_40 ( & V_7 -> V_211 , V_248 ) ;
break;
case F_62 ( V_274 ) :
F_47 ( & V_7 -> V_195 -> V_38 -> V_39 ,
L_10
L_11 , V_196 , V_7 ,
V_265 ) ;
F_40 ( & V_7 -> V_211 , V_248 ) ;
break;
default:
V_7 -> V_229 = F_65 ( V_265 ) ;
V_7 -> V_175 = V_287 ;
F_40 ( & V_7 -> V_211 , V_232 ) ;
break;
}
return V_185 ;
}
static enum V_175
F_66 ( struct V_6 * V_7 ,
T_2 V_265 )
{
switch ( F_61 ( V_265 ) ) {
case F_62 ( V_267 ) :
V_7 -> V_229 = V_267 ;
V_7 -> V_175 = V_185 ;
F_40 ( & V_7 -> V_211 , V_232 ) ;
break;
case F_62 ( V_304 ) :
case F_62 ( V_305 ) :
case F_62 ( V_306 ) :
case F_62 ( V_307 ) :
V_7 -> V_229 = V_304 ;
V_7 -> V_175 = V_313 ;
F_40 ( & V_7 -> V_211 , V_232 ) ;
break;
default:
V_7 -> V_229 = F_65 ( V_265 ) ;
V_7 -> V_175 = V_287 ;
F_40 ( & V_7 -> V_211 , V_232 ) ;
break;
}
return V_185 ;
}
static enum V_175
F_67 ( struct V_6 * V_7 ,
T_2 V_265 )
{
switch ( F_61 ( V_265 ) ) {
case F_62 ( V_267 ) :
V_7 -> V_229 = V_267 ;
V_7 -> V_175 = V_185 ;
F_40 ( & V_7 -> V_211 , V_232 ) ;
break;
default:
V_7 -> V_229 = F_65 ( V_265 ) ;
V_7 -> V_175 = V_287 ;
F_40 ( & V_7 -> V_211 , V_232 ) ;
break;
}
return V_185 ;
}
static struct V_18 * F_68 ( struct V_177 * V_178 )
{
struct V_18 * V_181 ;
struct V_5 * V_314 ;
struct V_6 * V_7 = F_69 ( V_178 ) ;
struct V_315 * V_316 = & V_178 -> V_181 ;
V_314 = F_2 ( V_7 , V_316 -> V_184 ) ;
if ( ! V_314 )
V_181 = NULL ;
else if ( V_316 -> V_182 == V_183 ) {
if ( V_314 -> V_35 . V_24 == 0 &&
V_314 -> V_35 . V_23 == 0 ) {
V_181 = NULL ;
} else {
V_316 -> V_182 = V_317 ;
V_181 = & V_314 -> V_35 ;
}
} else {
if ( V_314 -> V_37 == 0 &&
V_314 -> V_36 == 0 ) {
V_181 = NULL ;
} else {
V_316 -> V_184 ++ ;
V_316 -> V_182 = V_183 ;
V_314 = F_2 ( V_7 , V_316 -> V_184 ) ;
V_181 = & V_314 -> V_34 ;
}
}
return V_181 ;
}
static enum V_175
F_70 ( struct V_6 * V_7 ,
T_2 V_265 )
{
switch ( F_61 ( V_265 ) ) {
case F_62 ( V_267 ) :
V_7 -> V_229 = V_267 ;
V_7 -> V_175 = V_185 ;
F_40 ( & V_7 -> V_211 , V_239 ) ;
break;
default:
V_7 -> V_229 = F_65 ( V_265 ) ;
V_7 -> V_175 = V_287 ;
F_40 ( & V_7 -> V_211 , V_232 ) ;
break;
}
return V_185 ;
}
static enum V_175 F_71 (
struct V_6 * V_7 ,
T_2 V_22 )
{
struct V_177 * V_178 = & V_7 -> V_171 . V_179 ;
struct V_68 * V_69 = V_7 -> V_9 ;
struct V_5 * V_314 ;
struct V_18 * V_318 ;
V_314 = F_2 ( V_7 , V_178 -> V_181 . V_184 ) ;
if ( V_178 -> V_181 . V_182 == V_183 )
V_318 = & V_314 -> V_34 ;
else
V_318 = & V_314 -> V_35 ;
V_69 -> V_103 = V_318 -> V_23 ;
V_69 -> V_104 = V_318 -> V_24 ;
V_69 -> V_122 = V_22 ;
V_69 -> type . V_171 . V_173 = V_319 ;
return F_72 ( V_7 ) ;
}
static enum V_175 F_73 ( struct V_6 * V_7 )
{
struct V_177 * V_178 = & V_7 -> V_171 . V_179 ;
struct V_5 * V_314 ;
enum V_175 V_180 = V_185 ;
struct V_18 * V_181 ;
T_2 V_15 ;
T_2 V_111 = 0 ;
V_15 = V_178 -> V_181 . V_15 ;
V_314 = F_2 ( V_7 , V_178 -> V_181 . V_184 ) ;
if ( F_53 ( ! V_314 , L_12 , V_196 ) )
return V_197 ;
if ( V_178 -> V_181 . V_182 == V_183 ) {
V_181 = & V_314 -> V_34 ;
V_111 = V_314 -> V_34 . V_22 - V_15 ;
} else {
V_181 = & V_314 -> V_35 ;
V_111 = V_314 -> V_35 . V_22 - V_15 ;
}
if ( V_178 -> V_320 == 0 )
return V_185 ;
if ( V_178 -> V_320 >= V_111 ) {
V_180 = F_71 ( V_7 , V_111 ) ;
if ( V_180 != V_185 )
return V_180 ;
V_178 -> V_320 -= V_111 ;
V_181 = F_68 ( V_178 ) ;
V_15 = 0 ;
} else if ( V_178 -> V_320 < V_111 ) {
F_71 ( V_7 , V_178 -> V_320 ) ;
V_15 += V_178 -> V_320 ;
V_181 -> V_24 += V_178 -> V_320 ;
V_178 -> V_320 = 0 ;
}
V_178 -> V_181 . V_15 = V_15 ;
return V_180 ;
}
static enum V_175
F_74 ( struct V_177 * V_178 ,
T_3 * V_321 , T_2 V_111 )
{
struct V_6 * V_7 ;
T_3 * V_322 ;
int V_323 ;
struct V_26 * V_27 ;
struct V_20 * V_21 ;
void * V_324 ;
int V_325 = V_111 ;
V_7 = F_69 ( V_178 ) ;
V_27 = F_11 ( V_7 ) ;
V_322 = V_321 ;
if ( V_27 -> V_32 > 0 ) {
V_21 = V_27 -> V_33 ;
while ( V_325 > 0 ) {
struct V_326 * V_326 = F_75 ( V_21 ) ;
V_323 = F_58 ( int , V_325 , F_6 ( V_21 ) ) ;
V_324 = F_76 ( V_326 ) ;
memcpy ( V_324 + V_21 -> V_15 , V_322 , V_323 ) ;
F_77 ( V_324 ) ;
V_325 -= V_323 ;
V_322 += V_323 ;
V_21 = F_12 ( V_21 ) ;
}
} else {
F_78 ( V_27 -> V_40 < V_325 ) ;
memcpy ( V_27 -> V_33 , V_322 , V_325 ) ;
}
return V_185 ;
}
static enum V_175 F_79 (
struct V_177 * V_178 ,
T_3 * V_327 )
{
enum V_175 V_180 ;
if ( V_178 -> V_320 < V_328 ) {
V_180 = F_74 (
V_178 , V_327 , V_178 -> V_320 ) ;
if ( V_180 == V_185 )
V_178 -> V_320 = 0 ;
} else {
V_180 = F_74 (
V_178 , V_327 , V_328 ) ;
if ( V_180 == V_185 )
V_178 -> V_320 -= V_328 ;
}
return V_180 ;
}
static enum V_175
F_80 ( struct V_6 * V_7 ,
T_2 V_265 )
{
enum V_175 V_180 = V_185 ;
switch ( F_61 ( V_265 ) ) {
case F_62 ( V_267 ) :
V_7 -> V_229 = V_267 ;
V_7 -> V_175 = V_185 ;
F_40 ( & V_7 -> V_211 , V_241 ) ;
break;
default:
V_7 -> V_229 = F_65 ( V_265 ) ;
V_7 -> V_175 = V_287 ;
F_40 ( & V_7 -> V_211 , V_232 ) ;
break;
}
return V_180 ;
}
static enum V_175
F_81 ( struct V_6 * V_7 ,
T_2 V_265 )
{
enum V_175 V_180 = V_185 ;
bool V_329 = false ;
struct V_177 * V_178 = & V_7 -> V_171 . V_179 ;
switch ( F_61 ( V_265 ) ) {
case F_62 ( V_267 ) :
if ( V_178 -> V_320 != 0 ) {
V_180 = F_73 ( V_7 ) ;
if ( V_180 == V_185 ) {
if ( V_178 -> V_320 == 0 )
V_329 = true ;
}
} else if ( V_178 -> V_320 == 0 ) {
V_329 = true ;
}
if ( V_329 ) {
F_40 ( & V_7 -> V_211 , V_241 ) ;
}
break;
default:
V_7 -> V_229 = F_65 ( V_265 ) ;
V_7 -> V_175 = V_287 ;
F_40 ( & V_7 -> V_211 , V_232 ) ;
break;
}
return V_180 ;
}
static enum V_175 F_82 ( struct V_6 * V_7 ,
T_2 V_330 )
{
struct V_13 * V_14 = V_7 -> V_195 ;
struct V_331 * V_332 ;
enum V_175 V_180 ;
T_2 * V_333 ;
V_180 = F_83 ( & V_14 -> V_334 ,
V_330 ,
( void * * ) & V_332 ) ;
if ( ( V_180 == V_185 ) &&
( V_332 -> V_173 == V_335 ) ) {
F_84 ( & V_14 -> V_334 ,
V_330 ,
( void * * ) & V_333 ) ;
F_85 ( & V_7 -> V_171 . V_105 ,
V_332 ,
V_333 ) ;
}
F_54 ( V_14 , V_330 ) ;
return V_180 ;
}
static enum V_175 F_86 ( struct V_6 * V_7 ,
T_2 V_330 )
{
struct V_13 * V_14 = V_7 -> V_195 ;
enum V_175 V_180 ;
struct V_331 * V_332 ;
T_2 * V_333 ;
V_180 = F_83 ( & V_14 -> V_334 ,
V_330 ,
( void * * ) & V_332 ) ;
if ( V_180 != V_185 )
return V_180 ;
if ( V_332 -> V_173 != V_335 ) {
F_37 ( & V_7 -> V_13 -> V_38 -> V_39 ,
L_13 ,
V_196 , V_332 -> V_173 ) ;
return V_197 ;
}
F_84 ( & V_14 -> V_334 ,
V_330 ,
( void * * ) & V_333 ) ;
F_85 ( & V_7 -> V_171 . V_105 ,
( T_2 * ) V_332 ,
V_333 ) ;
F_54 ( V_14 , V_330 ) ;
return V_180 ;
}
static enum V_175 F_87 ( struct V_6 * V_7 ,
T_2 V_330 )
{
struct V_26 * V_27 = F_11 ( V_7 ) ;
enum V_175 V_180 ;
V_180 = F_86 ( V_7 , V_330 ) ;
if ( V_180 == V_185 ) {
if ( V_7 -> V_171 . V_105 . V_180 & V_336 )
V_180 = V_337 ;
} else {
V_180 = V_337 ;
}
if ( V_180 != V_185 ) {
V_7 -> V_229 = V_271 ;
V_7 -> V_175 = V_180 ;
} else {
V_7 -> V_229 = V_267 ;
V_7 -> V_175 = V_185 ;
}
if ( V_27 -> V_41 == V_156 )
F_40 ( & V_7 -> V_211 , V_232 ) ;
return V_180 ;
}
static void F_88 ( struct V_6 * V_7 )
{
struct V_338 * V_39 = F_89 ( V_7 -> V_74 -> V_194 ) ;
void * V_339 = V_7 -> V_115 . V_116 -> V_202 . V_340 ;
struct V_68 * V_69 = V_7 -> V_9 ;
memset ( & V_7 -> V_171 . V_46 , 0 , sizeof( struct V_169 ) ) ;
memcpy ( ( ( T_3 * ) & V_7 -> V_171 . V_46 + sizeof( T_2 ) ) , V_339 , V_341 ) ;
memset ( & ( V_69 -> type . V_171 ) , 0 , sizeof( struct V_342 ) ) ;
V_69 -> type . V_171 . V_173 = V_319 ;
V_69 -> V_122 = V_39 -> V_343 ;
}
static void F_90 ( struct V_6 * V_7 )
{
struct V_338 * V_39 = F_89 ( V_7 -> V_74 -> V_194 ) ;
struct V_26 * V_27 = F_11 ( V_7 ) ;
struct V_68 * V_69 = V_7 -> V_9 ;
int V_343 = V_39 -> V_343 ;
if ( V_27 -> V_41 == V_159 ) {
V_69 -> V_157 = V_344 ;
V_69 -> V_345 = 0 ;
} else {
V_69 -> V_157 = V_346 ;
V_69 -> V_345 = 1 ;
}
memset ( & V_69 -> type . V_171 , 0 , sizeof( V_69 -> type . V_171 ) ) ;
V_69 -> type . V_171 . V_173 = V_319 ;
memset ( & V_7 -> V_171 . V_46 , 0 , sizeof( V_7 -> V_171 . V_46 ) ) ;
memcpy ( & V_7 -> V_171 . V_46 . V_347 , V_27 -> V_202 . V_340 , V_343 ) ;
V_69 -> V_152 = V_343 / sizeof( T_2 ) ;
V_69 -> V_98 = 0x1 ;
V_69 -> V_348 = 0 ;
V_69 -> V_122 = V_27 -> V_40 ;
F_10 ( V_7 ) ;
}
enum V_175
F_91 ( struct V_6 * V_7 ,
T_2 V_330 )
{
struct V_13 * V_14 = V_7 -> V_195 ;
struct V_177 * V_178 = & V_7 -> V_171 . V_179 ;
enum V_1 V_2 ;
enum V_175 V_180 ;
T_5 V_269 ;
V_2 = V_7 -> V_211 . V_220 ;
switch ( V_2 ) {
case V_227 : {
struct V_349 V_350 ;
void * V_332 ;
F_83 ( & V_14 -> V_334 ,
V_330 ,
& V_332 ) ;
V_269 = sizeof( struct V_349 ) / sizeof( T_2 ) ;
F_15 ( & V_350 , V_332 , V_269 ) ;
if ( V_350 . V_153 == V_351 ) {
struct V_258 * V_261 ;
T_5 V_269 = V_262 / sizeof( T_2 ) ;
F_84 ( & V_14 -> V_334 ,
V_330 ,
( void * * ) & V_261 ) ;
F_15 ( & V_7 -> V_45 . V_105 , V_261 , V_269 ) ;
V_261 = & V_7 -> V_45 . V_105 ;
if ( V_261 -> V_266 == 0x01 ||
V_261 -> V_266 == 0x02 ) {
V_7 -> V_229 = V_271 ;
V_7 -> V_175 = V_287 ;
} else {
V_7 -> V_229 = V_267 ;
V_7 -> V_175 = V_185 ;
}
} else {
F_37 ( & V_14 -> V_38 -> V_39 ,
L_14
L_15 , V_196 , V_7 ,
V_330 , V_350 . V_153 ) ;
}
F_54 ( V_14 , V_330 ) ;
return V_185 ;
}
case V_248 :
F_57 ( V_7 ) ;
F_40 ( & V_7 -> V_211 , V_232 ) ;
F_54 ( V_14 , V_330 ) ;
return V_185 ;
case V_234 : {
struct V_26 * V_27 = F_11 ( V_7 ) ;
struct V_20 * V_21 = & V_27 -> V_352 . V_353 ;
void * V_332 , * V_324 ;
T_3 * V_105 ;
F_83 ( & V_14 -> V_334 ,
V_330 ,
& V_332 ) ;
V_324 = F_76 ( F_75 ( V_21 ) ) ;
V_105 = V_324 + V_21 -> V_15 ;
F_15 ( V_105 , V_332 , 1 ) ;
if ( V_105 [ 0 ] == V_354 ) {
void * V_353 ;
F_84 ( & V_14 -> V_334 ,
V_330 ,
& V_353 ) ;
V_269 = ( V_21 -> V_22 / 4 ) - 1 ;
if ( V_269 > 0 )
V_269 = F_58 (unsigned int, word_cnt,
SCU_UNSOLICITED_FRAME_BUFFER_SIZE/4 ) ;
F_15 ( V_105 + 4 , V_353 , V_269 ) ;
V_7 -> V_229 = V_267 ;
V_7 -> V_175 = V_185 ;
F_40 ( & V_7 -> V_211 , V_235 ) ;
} else {
F_37 ( & V_14 -> V_38 -> V_39 ,
L_16
L_15 ,
V_196 ,
V_7 ,
V_330 ,
V_105 [ 0 ] ) ;
V_7 -> V_229 = V_306 ;
V_7 -> V_175 = V_287 ;
F_40 ( & V_7 -> V_211 , V_232 ) ;
}
F_77 ( V_324 ) ;
F_54 ( V_14 , V_330 ) ;
return V_185 ;
}
case V_236 :
return F_82 ( V_7 ,
V_330 ) ;
case V_237 :
V_180 = F_82 ( V_7 , V_330 ) ;
if ( V_180 != V_185 )
return V_180 ;
V_7 -> V_229 = V_271 ;
V_7 -> V_175 = V_272 ;
F_40 ( & V_7 -> V_211 , V_232 ) ;
return V_185 ;
case V_239 : {
struct V_331 * V_332 ;
T_2 * V_333 ;
V_180 = F_83 ( & V_14 -> V_334 ,
V_330 ,
( void * * ) & V_332 ) ;
if ( V_180 != V_185 ) {
F_37 ( & V_14 -> V_38 -> V_39 ,
L_17
L_18 ,
V_196 ,
V_178 ,
V_330 ,
V_180 ) ;
return V_180 ;
}
switch ( V_332 -> V_173 ) {
case V_335 :
F_84 ( & V_14 -> V_334 ,
V_330 ,
( void * * ) & V_333 ) ;
F_85 ( & V_7 -> V_171 . V_105 ,
V_332 ,
V_333 ) ;
V_7 -> V_229 = V_271 ;
V_7 -> V_175 = V_272 ;
break;
default:
F_47 ( & V_14 -> V_38 -> V_39 ,
L_19
L_20 , V_196 , V_178 ,
V_330 ) ;
V_7 -> V_229 = V_355 ;
V_7 -> V_175 = V_356 ;
break;
}
F_40 ( & V_7 -> V_211 , V_232 ) ;
F_54 ( V_14 , V_330 ) ;
return V_180 ;
}
case V_241 : {
struct V_26 * V_27 = F_11 ( V_7 ) ;
struct V_331 * V_332 ;
T_2 * V_333 ;
V_180 = F_83 ( & V_14 -> V_334 ,
V_330 ,
( void * * ) & V_332 ) ;
if ( V_180 != V_185 ) {
F_37 ( & V_14 -> V_38 -> V_39 ,
L_17
L_18 ,
V_196 , V_178 , V_330 , V_180 ) ;
return V_180 ;
}
switch ( V_332 -> V_173 ) {
case V_357 :
F_84 ( & V_14 -> V_334 ,
V_330 ,
( void * * ) & V_333 ) ;
V_178 -> V_320 = V_333 [ 3 ] & 0xffff ;
V_178 -> V_180 = ( V_333 [ 2 ] >> 24 ) & 0xff ;
F_85 ( & V_7 -> V_171 . V_105 ,
V_332 ,
V_333 ) ;
V_7 -> V_171 . V_105 . V_180 = V_178 -> V_180 ;
if ( V_27 -> V_41 == V_155 ) {
F_40 ( & V_7 -> V_211 , V_242 ) ;
} else if ( V_27 -> V_41 == V_159 ) {
V_180 = F_73 ( V_7 ) ;
if ( V_180 != V_185 )
break;
F_40 ( & V_7 -> V_211 , V_243 ) ;
}
break;
case V_358 :
F_40 ( & V_7 -> V_211 , V_241 ) ;
break;
case V_335 :
if ( V_332 -> V_180 & V_359 ) {
F_92 ( & V_14 -> V_38 -> V_39 ,
L_21
L_22
L_23 ,
V_196 ,
V_178 ,
V_332 -> V_180 ) ;
break;
}
F_84 ( & V_14 -> V_334 ,
V_330 ,
( void * * ) & V_333 ) ;
F_85 ( & V_7 -> V_171 . V_179 ,
V_332 ,
V_333 ) ;
V_7 -> V_229 = V_271 ;
V_7 -> V_175 = V_272 ;
F_40 ( & V_7 -> V_211 , V_232 ) ;
break;
default:
break;
}
F_54 ( V_14 , V_330 ) ;
return V_180 ;
}
case V_242 : {
struct V_331 * V_332 ;
struct V_360 * V_333 ;
V_180 = F_83 ( & V_14 -> V_334 ,
V_330 ,
( void * * ) & V_332 ) ;
if ( V_180 != V_185 ) {
F_37 ( & V_14 -> V_38 -> V_39 ,
L_17
L_18 ,
V_196 ,
V_178 ,
V_330 ,
V_180 ) ;
return V_180 ;
}
if ( V_332 -> V_173 != V_319 ) {
F_37 ( & V_14 -> V_38 -> V_39 ,
L_24
L_25
L_26 ,
V_196 ,
V_178 ,
V_330 ,
V_332 -> V_173 ) ;
V_7 -> V_229 = V_267 ;
V_7 -> V_175 = V_361 ;
F_40 ( & V_7 -> V_211 , V_232 ) ;
F_54 ( V_14 , V_330 ) ;
return V_180 ;
}
if ( V_178 -> V_181 . V_184 < 0 ) {
V_7 -> V_251 = V_330 ;
V_178 -> V_320 = 0 ;
} else {
F_84 ( & V_14 -> V_334 ,
V_330 ,
( void * * ) & V_333 ) ;
V_180 = F_79 ( V_178 ,
( T_3 * ) V_333 ) ;
F_54 ( V_14 , V_330 ) ;
}
if ( V_180 != V_185 || V_178 -> V_320 != 0 )
return V_180 ;
if ( ( V_178 -> V_180 & V_359 ) == 0 ) {
V_7 -> V_229 = V_271 ;
V_7 -> V_175 = V_272 ;
F_40 ( & V_7 -> V_211 , V_232 ) ;
} else {
F_40 ( & V_7 -> V_211 , V_241 ) ;
}
return V_180 ;
}
case V_245 : {
struct V_26 * V_27 = F_11 ( V_7 ) ;
F_54 ( V_14 , V_330 ) ;
V_7 -> V_74 -> V_362 = V_7 ;
if ( V_27 -> V_41 == V_156 ) {
F_40 ( & V_7 -> V_211 , V_247 ) ;
F_88 ( V_7 ) ;
} else {
F_40 ( & V_7 -> V_211 , V_246 ) ;
F_90 ( V_7 ) ;
}
F_72 ( V_7 ) ;
return V_185 ;
}
case V_246 :
return F_87 ( V_7 , V_330 ) ;
case V_249 :
F_54 ( V_14 , V_330 ) ;
return V_185 ;
default:
F_47 ( & V_14 -> V_38 -> V_39 ,
L_27
L_28 ,
V_196 ,
V_330 ,
V_2 ) ;
F_54 ( V_14 , V_330 ) ;
return V_221 ;
}
}
static enum V_175 F_93 ( struct V_6 * V_7 ,
T_2 V_265 )
{
enum V_175 V_180 = V_185 ;
switch ( F_61 ( V_265 ) ) {
case F_62 ( V_267 ) :
V_7 -> V_229 = V_267 ;
V_7 -> V_175 = V_185 ;
F_40 ( & V_7 -> V_211 , V_232 ) ;
break;
case F_62 ( V_355 ) :
case F_62 ( V_283 ) :
if ( V_7 -> V_171 . V_105 . V_173 == V_335 ) {
F_94 ( V_7 -> V_74 ,
V_363 ) ;
V_7 -> V_229 = V_271 ;
V_7 -> V_175 = V_272 ;
F_40 ( & V_7 -> V_211 , V_232 ) ;
} else {
F_40 ( & V_7 -> V_211 , V_237 ) ;
}
break;
default:
V_7 -> V_229 = F_65 ( V_265 ) ;
V_7 -> V_175 = V_287 ;
F_40 ( & V_7 -> V_211 , V_232 ) ;
break;
}
return V_180 ;
}
static enum V_175 F_95 ( struct V_6 * V_7 , T_2 V_265 ,
enum V_1 V_364 )
{
enum V_175 V_180 = V_185 ;
switch ( F_61 ( V_265 ) ) {
case F_62 ( V_267 ) :
V_7 -> V_229 = V_267 ;
V_7 -> V_175 = V_185 ;
F_40 ( & V_7 -> V_211 , V_364 ) ;
break;
default:
V_7 -> V_229 = F_65 ( V_265 ) ;
V_7 -> V_175 = V_287 ;
F_40 ( & V_7 -> V_211 , V_232 ) ;
break;
}
return V_180 ;
}
static enum V_175 F_96 ( struct V_6 * V_7 ,
T_2 V_265 )
{
struct V_70 * V_71 = V_7 -> V_74 ;
struct V_331 * V_365 = & V_7 -> V_171 . V_105 ;
enum V_175 V_180 = V_185 ;
switch ( F_61 ( V_265 ) ) {
case ( V_267 << V_285 ) :
F_40 ( & V_7 -> V_211 , V_232 ) ;
break;
case ( V_355 << V_285 ) : {
T_6 V_111 = F_43 ( V_7 ) ;
if ( V_365 -> V_173 != V_335 ) {
V_365 -> V_173 = V_335 ;
V_365 -> V_65 = ( 1 << 6 ) ;
V_365 -> V_180 = 0x50 ;
V_365 -> error = 0 ;
V_365 -> V_347 = 0 ;
V_365 -> V_366 = V_111 & 0xff ;
V_365 -> V_367 = V_111 >> 8 ;
V_365 -> V_119 = 0xa0 ;
V_365 -> V_368 = 0 ;
V_365 -> V_369 = 0 ;
V_365 -> V_370 = 0 ;
V_365 -> V_50 = 0 ;
V_365 -> V_371 = 0x3 ;
V_365 -> V_372 = 0 ;
V_365 -> V_51 = 0 ;
V_365 -> V_55 = 0 ;
V_365 -> V_373 = 0 ;
}
V_7 -> V_229 = V_267 ;
V_7 -> V_175 = V_270 ;
V_180 = V_7 -> V_175 ;
F_40 ( & V_71 -> V_211 , V_374 ) ;
break;
}
case ( V_303 << V_285 ) :
V_7 -> V_229 = V_267 ;
V_7 -> V_175 = V_185 ;
F_40 ( & V_7 -> V_211 , V_232 ) ;
break;
default:
if ( V_365 -> V_173 == V_335 ) {
V_180 = V_7 -> V_175 ;
F_40 ( & V_71 -> V_211 , V_374 ) ;
} else {
V_7 -> V_229 = V_271 ;
V_7 -> V_175 = V_272 ;
F_40 ( & V_7 -> V_211 , V_246 ) ;
}
break;
}
return V_180 ;
}
static int F_97 (
unsigned int V_375 )
{
switch ( V_375 ) {
case V_289 :
case V_290 :
case V_291 :
case V_292 :
case V_293 :
case V_294 :
return 1 ;
}
return 0 ;
}
static int F_98 (
unsigned int V_375 )
{
return 0 ;
}
static int F_99 (
unsigned int V_375 )
{
switch ( V_375 ) {
case V_376 :
case V_288 :
case V_289 :
case V_290 :
case V_291 :
case V_292 :
case V_293 :
case V_294 :
case V_295 :
case V_296 :
case V_297 :
return 1 ;
}
return 0 ;
}
static int F_100 (
unsigned int V_375 )
{
return 0 ;
}
static int F_101 (
unsigned int V_375 )
{
switch ( V_375 ) {
case V_376 :
case V_377 :
case V_275 :
case V_283 :
case V_284 :
case V_289 :
case V_290 :
case V_291 :
case V_292 :
case V_293 :
case V_294 :
case V_295 :
case V_296 :
case V_297 :
return 1 ;
}
return 0 ;
}
static int F_102 (
unsigned int V_375 )
{
switch ( V_375 ) {
case V_288 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_355 :
case V_282 :
case V_280 :
return 1 ;
}
return 0 ;
}
static void F_103 (
struct V_6 * V_7 ,
T_2 V_265 )
{
int V_382 = 0 ;
int V_383 = 0 ;
switch ( V_7 -> V_209 ) {
case V_384 :
V_382 = F_97 (
V_265 ) ;
V_383 = F_98 (
V_265 ) ;
break;
case V_210 :
V_382 = F_99 (
V_265 ) ;
V_383 = F_100 (
V_265 ) ;
break;
case V_213 :
V_382 = F_101 (
V_265 ) ;
V_383 =
F_102 (
V_265 ) ;
break;
default:
F_47 ( & V_7 -> V_13 -> V_38 -> V_39 ,
L_29 ,
V_196 , V_7 ) ;
break;
}
if ( V_382 || V_383 ) {
F_78 ( V_382 && V_383 ) ;
F_104 (
& V_7 -> V_74 -> V_90 ,
V_385 ,
( V_383 ) ? V_386
: V_387 ) ;
}
}
enum V_175
F_105 ( struct V_6 * V_7 ,
T_2 V_265 )
{
enum V_1 V_2 ;
struct V_13 * V_14 = V_7 -> V_195 ;
V_2 = V_7 -> V_211 . V_220 ;
F_103 (
V_7 , F_61 ( V_265 ) ) ;
switch ( V_2 ) {
case V_227 :
return F_60 ( V_7 , V_265 ) ;
case V_233 :
return F_64 ( V_7 ,
V_265 ) ;
case V_234 :
return F_66 ( V_7 ,
V_265 ) ;
case V_235 :
return F_67 ( V_7 , V_265 ) ;
case V_236 :
return F_93 ( V_7 ,
V_265 ) ;
case V_238 :
return F_70 ( V_7 ,
V_265 ) ;
case V_240 :
return F_80 ( V_7 ,
V_265 ) ;
case V_243 :
return F_81 ( V_7 , V_265 ) ;
case V_249 :
return F_63 ( V_7 ,
V_265 ) ;
case V_244 :
return F_95 ( V_7 , V_265 ,
V_245 ) ;
case V_247 :
return F_95 ( V_7 , V_265 ,
V_246 ) ;
case V_246 :
return F_96 ( V_7 , V_265 ) ;
default:
F_47 ( & V_14 -> V_38 -> V_39 , L_30 ,
V_196 , V_265 , F_1 ( V_2 ) ) ;
return V_221 ;
}
}
static void F_106 (
struct V_26 * V_27 ,
struct V_258 * V_261 ,
struct V_119 * V_39 )
{
F_92 ( V_39 ,
L_31
L_32
L_33
L_34 ,
V_196 ,
V_261 ,
V_261 -> V_180 ,
V_261 -> V_266 ,
V_261 -> V_263 ,
V_261 -> V_388 ) ;
V_27 -> V_389 . V_390 = V_261 -> V_180 ;
F_107 ( V_39 , V_27 , V_261 ) ;
}
static void F_108 (
struct V_6 * V_391 ,
struct V_26 * V_27 ,
enum V_392 * V_393 ,
enum V_394 * V_395 ,
enum V_396 V_397 )
{
F_49 ( V_398 , & V_391 -> V_65 ) ;
* V_393 = V_399 ;
* V_395 = V_400 ;
V_27 -> V_389 . V_397 = V_397 ;
}
static void F_109 (
struct V_70 * V_71 ,
struct V_6 * V_391 ,
struct V_26 * V_27 ,
enum V_392 * V_393 ,
enum V_394 * V_395 )
{
unsigned int V_401 ;
V_401 = V_391 -> V_229 ;
F_92 ( & V_391 -> V_13 -> V_38 -> V_39 ,
L_35
L_36 ,
V_196 , V_391 , V_401 ) ;
switch ( V_401 ) {
case V_402 :
case V_403 :
if ( V_27 -> V_198 == V_384 ) {
* V_393 = V_404 ;
if ( ! V_71 )
* V_395 = V_405 ;
else
* V_395 = V_406 ;
F_49 ( V_398 , & V_391 -> V_65 ) ;
} else {
* V_393 = V_399 ;
if ( ! V_71 )
* V_395 = V_405 ;
else
* V_395 = V_407 ;
F_51 ( V_398 , & V_391 -> V_65 ) ;
}
break;
case V_255 :
case V_298 :
case V_303 :
case V_355 :
case V_310 :
case V_311 :
case V_312 :
* V_393 = V_404 ;
if ( ! V_71 )
* V_395 = V_405 ;
else
* V_395 = V_406 ;
F_49 ( V_398 , & V_391 -> V_65 ) ;
break;
case V_289 :
F_108 (
V_391 , V_27 , V_393 , V_395 ,
V_408 ) ;
break;
case V_294 :
F_108 (
V_391 , V_27 , V_393 , V_395 ,
V_409 ) ;
break;
case V_290 :
F_108 (
V_391 , V_27 , V_393 , V_395 ,
V_410 ) ;
break;
case V_291 :
F_108 (
V_391 , V_27 , V_393 , V_395 ,
V_411 ) ;
break;
case V_292 :
F_108 (
V_391 , V_27 , V_393 , V_395 ,
V_412 ) ;
break;
case V_293 :
F_108 (
V_391 , V_27 , V_393 , V_395 ,
V_413 ) ;
break;
case V_295 :
F_108 (
V_391 , V_27 , V_393 , V_395 ,
V_414 ) ;
break;
case V_296 :
F_108 (
V_391 , V_27 , V_393 , V_395 ,
V_415 ) ;
break;
case V_297 :
F_108 (
V_391 , V_27 , V_393 , V_395 ,
V_416 ) ;
break;
case V_377 :
case V_275 :
case V_378 :
case V_379 :
case V_278 :
case V_417 :
case V_300 :
case V_381 :
case V_301 :
case V_302 :
case V_280 :
case V_288 :
case V_304 :
case V_307 :
case V_308 :
case V_282 :
case V_283 :
case V_284 :
case V_230 :
default:
* V_393 = V_399 ;
* V_395 = V_407 ;
if ( V_27 -> V_198 == V_384 )
F_49 ( V_398 , & V_391 -> V_65 ) ;
else
F_51 ( V_398 , & V_391 -> V_65 ) ;
break;
}
}
static void F_110 ( struct V_26 * V_27 , struct V_331 * V_203 )
{
struct V_418 * V_419 = & V_27 -> V_389 ;
struct V_420 * V_260 = ( void * ) & V_419 -> V_421 [ 0 ] ;
V_260 -> V_422 = sizeof( * V_203 ) ;
memcpy ( V_260 -> V_423 , V_203 , sizeof( * V_203 ) ) ;
V_419 -> V_424 = sizeof( * V_260 ) ;
if ( V_203 -> V_180 & V_425 )
V_419 -> V_390 = V_426 ;
else if ( V_203 -> V_180 & V_336 )
V_419 -> V_390 = V_427 ;
else
V_419 -> V_390 = V_428 ;
V_419 -> V_260 = V_404 ;
}
static void F_111 ( struct V_13 * V_14 ,
struct V_6 * V_391 ,
enum V_429 V_375 )
{
struct V_26 * V_27 = F_11 ( V_391 ) ;
struct V_258 * V_261 ;
unsigned long V_430 ;
struct V_70 * V_71 = V_391 -> V_74 ;
enum V_392 V_431 = V_399 ;
enum V_394 V_180 = V_406 ;
F_92 ( & V_14 -> V_38 -> V_39 ,
L_37
L_38 ,
V_196 , V_391 , V_27 , V_27 -> V_41 , V_375 ) ;
switch ( V_375 ) {
case V_337 :
F_92 ( & V_14 -> V_38 -> V_39 ,
L_39 ,
V_196 , V_391 , V_27 ) ;
if ( F_38 ( V_27 -> V_198 ) ) {
F_110 ( V_27 , & V_391 -> V_171 . V_105 ) ;
} else if ( V_210 == V_27 -> V_198 ) {
V_261 = & V_391 -> V_45 . V_105 ;
F_106 ( V_27 , V_261 ,
& V_14 -> V_38 -> V_39 ) ;
} else if ( V_384 == V_27 -> V_198 ) {
F_37 ( & V_14 -> V_38 -> V_39 ,
L_40
L_41 ,
V_196 ) ;
} else
F_37 ( & V_14 -> V_38 -> V_39 ,
L_42 , V_196 ) ;
F_49 ( V_398 , & V_391 -> V_65 ) ;
V_431 = V_27 -> V_389 . V_260 ;
V_180 = V_27 -> V_389 . V_390 ;
break;
case V_432 :
case V_433 :
V_431 = V_404 ;
V_180 = V_428 ;
F_49 ( V_398 , & V_391 -> V_65 ) ;
if ( V_375 == V_433 ) {
T_2 V_434 = F_43 ( V_391 ) ;
V_27 -> V_389 . V_435
= V_27 -> V_40 - V_434 ;
if ( V_27 -> V_389 . V_435 != 0 )
V_180 = V_436 ;
F_92 ( & V_14 -> V_38 -> V_39 ,
L_43 ,
V_196 , V_180 ) ;
} else
F_92 ( & V_14 -> V_38 -> V_39 , L_44 ,
V_196 ) ;
break;
case V_437 :
F_92 ( & V_14 -> V_38 -> V_39 ,
L_45 ,
V_196 , V_391 , V_27 ) ;
F_49 ( V_398 , & V_391 -> V_65 ) ;
V_431 = V_399 ;
if ( ! V_71 )
V_180 = V_405 ;
else
V_180 = V_406 ;
break;
case V_287 :
F_109 ( V_71 , V_391 ,
V_27 , & V_431 ,
& V_180 ) ;
break;
case V_438 :
F_112 ( & V_27 -> V_439 , V_430 ) ;
V_27 -> V_440 |= V_441 ;
F_113 ( & V_27 -> V_439 , V_430 ) ;
V_431 = V_399 ;
V_180 = V_407 ;
F_51 ( V_398 , & V_391 -> V_65 ) ;
break;
case V_313 :
V_431 = V_399 ;
if ( ! V_71 )
V_180 = V_405 ;
else
V_180 = V_406 ;
F_49 ( V_398 , & V_391 -> V_65 ) ;
break;
default:
F_92 ( & V_14 -> V_38 -> V_39 ,
L_46
L_47 ,
V_196 , V_375 , V_391 ) ;
V_431 = V_399 ;
if ( ! V_71 )
V_180 = V_405 ;
else
V_180 = V_406 ;
if ( V_384 == V_27 -> V_198 )
F_49 ( V_398 , & V_391 -> V_65 ) ;
else
F_51 ( V_398 , & V_391 -> V_65 ) ;
break;
}
switch ( V_27 -> V_198 ) {
case V_210 :
if ( V_27 -> V_41 == V_156 )
break;
if ( V_27 -> V_32 == 0 )
F_114 ( & V_14 -> V_38 -> V_39 ,
V_391 -> V_42 ,
V_27 -> V_40 , V_27 -> V_41 ) ;
else
F_115 ( & V_14 -> V_38 -> V_39 , V_27 -> V_33 ,
V_391 -> V_442 , V_27 -> V_41 ) ;
break;
case V_384 : {
struct V_20 * V_21 = & V_27 -> V_352 . V_443 ;
struct V_443 * V_443 ;
void * V_324 ;
F_115 ( & V_14 -> V_38 -> V_39 , V_21 , 1 , V_159 ) ;
V_324 = F_76 ( F_75 ( V_21 ) ) ;
V_443 = V_324 + V_21 -> V_15 ;
F_15 ( V_443 , V_443 , V_21 -> V_22 / sizeof( T_2 ) ) ;
F_77 ( V_324 ) ;
break;
}
default:
break;
}
F_112 ( & V_27 -> V_439 , V_430 ) ;
V_27 -> V_389 . V_260 = V_431 ;
V_27 -> V_389 . V_390 = V_180 ;
if ( F_18 ( V_398 , & V_391 -> V_65 ) ) {
V_27 -> V_440 |= V_444 ;
V_27 -> V_440 &= ~ ( V_445 |
V_446 ) ;
}
F_113 ( & V_27 -> V_439 , V_430 ) ;
F_116 ( V_14 , V_391 -> V_74 , V_391 ) ;
F_49 ( V_447 , & V_391 -> V_65 ) ;
F_117 ( V_14 , V_391 , V_27 ) ;
}
static void F_118 ( struct V_448 * V_211 )
{
struct V_6 * V_7 = F_119 ( V_211 , F_120 ( * V_7 ) , V_211 ) ;
struct V_193 * V_39 = V_7 -> V_74 -> V_194 ;
enum V_1 V_2 ;
struct V_26 * V_27 ;
V_27 = ( F_18 ( V_64 , & V_7 -> V_65 ) ) ? NULL : F_11 ( V_7 ) ;
if ( ! V_27 && V_39 -> V_449 == V_450 ) {
V_2 = V_233 ;
} else if ( V_27 && V_27 -> V_198 == V_384 ) {
V_2 = V_234 ;
} else if ( V_27 && F_38 ( V_27 -> V_198 ) &&
! V_27 -> V_202 . V_206 ) {
if ( V_39 -> V_199 . V_200 == V_201 &&
V_27 -> V_202 . V_203 . V_204 == V_205 ) {
V_2 = V_244 ;
} else if ( V_27 -> V_41 == V_156 ) {
V_2 = V_238 ;
} else if ( V_27 -> V_202 . V_208 ) {
V_2 = V_236 ;
} else {
V_2 = V_240 ;
}
} else {
return;
}
F_40 ( V_211 , V_2 ) ;
}
static void F_121 ( struct V_448 * V_211 )
{
struct V_6 * V_7 = F_119 ( V_211 , F_120 ( * V_7 ) , V_211 ) ;
struct V_13 * V_14 = V_7 -> V_195 ;
if ( ! F_18 ( V_64 , & V_7 -> V_65 ) )
F_111 ( V_14 , V_7 ,
V_7 -> V_175 ) ;
else
F_122 ( V_14 , V_7 , V_7 -> V_175 ) ;
}
static void F_123 ( struct V_448 * V_211 )
{
struct V_6 * V_7 = F_119 ( V_211 , F_120 ( * V_7 ) , V_211 ) ;
V_7 -> V_9 -> abort = 1 ;
}
static void F_124 ( struct V_448 * V_211 )
{
struct V_6 * V_7 = F_119 ( V_211 , F_120 ( * V_7 ) , V_211 ) ;
V_7 -> V_74 -> V_362 = V_7 ;
}
static void F_125 ( struct V_448 * V_211 )
{
struct V_6 * V_7 = F_119 ( V_211 , F_120 ( * V_7 ) , V_211 ) ;
V_7 -> V_74 -> V_362 = V_7 ;
}
static void
F_126 ( struct V_13 * V_14 ,
struct V_70 * V_71 ,
struct V_6 * V_7 )
{
F_127 ( & V_7 -> V_211 , V_451 , V_452 ) ;
V_7 -> V_74 = V_71 ;
V_7 -> V_209 = V_453 ;
V_7 -> V_251 = V_252 ;
V_7 -> V_175 = V_185 ;
V_7 -> V_229 = 0 ;
V_7 -> V_99 = 0xFFFFFFFF ;
}
static enum V_175
F_128 ( struct V_13 * V_14 ,
struct V_70 * V_71 ,
struct V_6 * V_7 )
{
struct V_193 * V_39 = V_71 -> V_194 ;
enum V_175 V_180 = V_185 ;
F_126 ( V_14 , V_71 , V_7 ) ;
if ( V_71 -> V_90 . V_89 == V_454 )
return V_455 ;
if ( V_39 -> V_449 == V_450 )
;
else if ( F_129 ( V_39 ) )
memset ( & V_7 -> V_171 . V_46 , 0 , sizeof( V_7 -> V_171 . V_46 ) ) ;
else if ( F_130 ( V_39 ) )
;
else
return V_456 ;
memset ( V_7 -> V_9 , 0 , F_45 ( struct V_68 , V_10 ) ) ;
return V_180 ;
}
enum V_175 F_131 ( struct V_13 * V_14 ,
struct V_70 * V_71 ,
T_6 V_66 , struct V_6 * V_7 )
{
struct V_193 * V_39 = V_71 -> V_194 ;
enum V_175 V_180 = V_185 ;
F_126 ( V_14 , V_71 , V_7 ) ;
if ( V_39 -> V_449 == V_450 || F_129 ( V_39 ) ) {
F_49 ( V_64 , & V_7 -> V_65 ) ;
memset ( V_7 -> V_9 , 0 , sizeof( struct V_68 ) ) ;
if ( F_129 ( V_39 ) )
V_7 -> V_209 = V_213 ;
else
V_7 -> V_209 = V_210 ;
} else
V_180 = V_456 ;
return V_180 ;
}
static enum V_175 F_132 (
struct V_6 * V_391 )
{
enum V_175 V_180 ;
F_92 ( & V_391 -> V_13 -> V_38 -> V_39 ,
L_48 ,
V_196 ,
V_391 ) ;
V_180 = F_39 ( V_391 ) ;
return V_180 ;
}
static enum V_175 F_133 ( struct V_6 * V_7 )
{
struct V_26 * V_27 = F_11 ( V_7 ) ;
struct V_169 * V_203 = & V_7 -> V_171 . V_46 ;
struct V_457 * V_458 = V_27 -> V_117 ;
enum V_175 V_180 ;
F_92 ( & V_7 -> V_13 -> V_38 -> V_39 ,
L_49 ,
V_196 ,
V_7 ) ;
memcpy ( V_203 , & V_27 -> V_202 . V_203 , sizeof( struct V_169 ) ) ;
if ( ! V_27 -> V_202 . V_459 )
V_203 -> V_65 |= 0x80 ;
V_203 -> V_65 &= 0xF0 ;
V_180 = F_42 ( V_7 ) ;
if ( V_458 && ( V_458 -> V_460 . V_204 == V_461 ||
V_458 -> V_460 . V_204 == V_462 ) ) {
V_203 -> V_371 = V_458 -> V_224 << 3 ;
V_7 -> V_9 -> type . V_171 . V_463 = V_458 -> V_224 ;
}
return V_180 ;
}
static enum V_175
F_134 ( struct V_119 * V_39 ,
struct V_6 * V_7 ,
struct V_26 * V_27 )
{
struct V_20 * V_21 = & V_27 -> V_352 . V_443 ;
struct V_70 * V_71 ;
struct V_68 * V_69 ;
struct V_72 * V_73 ;
struct V_443 * V_443 ;
void * V_324 ;
T_3 V_464 ;
T_2 V_46 ;
V_324 = F_76 ( F_75 ( V_21 ) ) ;
V_443 = V_324 + V_21 -> V_15 ;
if ( V_443 -> V_464 == 0 ) {
switch ( V_443 -> V_465 ) {
case V_466 :
case V_467 :
case V_468 :
case V_469 :
V_443 -> V_464 = 2 ;
break;
case V_470 :
case V_471 :
case V_472 :
V_443 -> V_464 = 9 ;
break;
}
}
V_464 = V_443 -> V_464 ;
F_15 ( V_443 , V_443 , V_21 -> V_22 / sizeof( T_2 ) ) ;
V_46 = * ( T_2 * ) V_443 ;
F_77 ( V_324 ) ;
if ( ! F_135 ( V_39 , V_21 , 1 , V_159 ) )
return V_197 ;
V_7 -> V_209 = V_384 ;
V_69 = V_7 -> V_9 ;
V_71 = V_7 -> V_74 ;
V_73 = V_71 -> V_75 ;
V_69 -> V_76 = 0 ;
V_69 -> V_77 = 1 ;
V_69 -> V_78 = V_71 -> V_78 ;
V_69 -> V_79 = V_80 ;
V_69 -> V_81 = V_73 -> V_82 ;
V_69 -> V_83 = V_223 ;
V_69 -> abort = 0 ;
V_69 -> V_85 = V_86 ;
V_69 -> V_87 = V_88 ;
V_69 -> V_89 = V_71 -> V_90 . V_89 ;
V_69 -> V_91 = 0 ;
V_69 -> V_157 = V_473 ;
V_69 -> V_92 = 0 ;
V_69 -> V_93 = 1 ;
V_69 -> V_94 = 0 ;
V_69 -> V_95 = 1 ;
V_69 -> V_96 = 0 ;
V_69 -> V_97 = 0 ;
V_69 -> V_25 = 0 ;
V_69 -> V_152 = V_464 ;
V_69 -> V_122 = 0 ;
memcpy ( & V_69 -> type . V_474 , & V_46 , sizeof( T_2 ) ) ;
V_69 -> V_98 = 0 ;
V_7 -> V_99 = ( V_100 |
( V_80 << V_101 ) |
( V_73 -> V_82 <<
V_102 ) |
F_20 ( V_7 -> V_66 ) ) ;
V_69 -> V_103 = F_7 ( F_8 ( V_21 ) ) ;
V_69 -> V_104 = F_9 ( F_8 ( V_21 ) + sizeof( T_2 ) ) ;
V_69 -> V_106 = 0 ;
V_69 -> V_107 = 0 ;
F_40 ( & V_7 -> V_211 , V_212 ) ;
return V_185 ;
}
static enum V_175 F_136 ( struct V_6 * V_7 )
{
struct V_26 * V_27 = F_11 ( V_7 ) ;
struct V_119 * V_39 = & V_7 -> V_13 -> V_38 -> V_39 ;
enum V_175 V_180 = V_197 ;
V_180 = F_134 ( V_39 , V_7 , V_27 ) ;
if ( V_180 != V_185 )
F_92 ( & V_7 -> V_13 -> V_38 -> V_39 ,
L_50 ,
V_196 ,
V_180 ) ;
return V_180 ;
}
static enum V_175 F_137 ( struct V_13 * V_14 ,
struct V_6 * V_391 ,
struct V_70 * V_71 )
{
enum V_175 V_180 = V_185 ;
struct V_26 * V_27 = F_11 ( V_391 ) ;
F_92 ( & V_14 -> V_38 -> V_39 ,
L_51
L_52 ,
V_196 ,
V_71 ,
V_391 ,
V_27 -> V_32 ) ;
if ( V_27 -> V_32 &&
! F_38 ( V_27 -> V_198 ) &&
! ( V_384 & V_27 -> V_198 ) ) {
V_391 -> V_442 = F_135 (
& V_14 -> V_38 -> V_39 ,
V_27 -> V_33 ,
V_27 -> V_32 ,
V_27 -> V_41
) ;
if ( V_391 -> V_442 == 0 )
return V_475 ;
}
V_180 = F_128 ( V_14 , V_71 , V_391 ) ;
if ( V_180 != V_185 ) {
F_92 ( & V_14 -> V_38 -> V_39 ,
L_53 ,
V_196 ) ;
return V_197 ;
}
switch ( V_27 -> V_198 ) {
case V_384 :
V_180 = F_136 ( V_391 ) ;
break;
case V_210 :
V_180 = F_132 ( V_391 ) ;
break;
case V_476 :
case V_213 :
case V_476 | V_213 :
V_180 = F_133 ( V_391 ) ;
break;
default:
F_92 ( & V_14 -> V_38 -> V_39 ,
L_42 , V_196 ) ;
return V_197 ;
}
return V_185 ;
}
static struct V_6 * F_138 ( struct V_13 * V_14 , T_6 V_224 )
{
struct V_6 * V_7 ;
V_7 = V_14 -> V_477 [ F_20 ( V_224 ) ] ;
V_7 -> V_66 = V_224 ;
V_7 -> V_478 = NULL ;
V_7 -> V_65 = 0 ;
V_7 -> V_442 = 0 ;
return V_7 ;
}
static struct V_6 * F_139 ( struct V_13 * V_14 ,
struct V_26 * V_27 ,
T_6 V_224 )
{
struct V_6 * V_7 ;
V_7 = F_138 ( V_14 , V_224 ) ;
V_7 -> V_115 . V_116 = V_27 ;
F_51 ( V_64 , & V_7 -> V_65 ) ;
V_27 -> V_479 = V_7 ;
return V_7 ;
}
struct V_6 * F_140 ( struct V_13 * V_14 ,
struct V_59 * V_59 ,
T_6 V_224 )
{
struct V_6 * V_7 ;
V_7 = F_138 ( V_14 , V_224 ) ;
V_7 -> V_115 . V_480 = V_59 ;
F_49 ( V_64 , & V_7 -> V_65 ) ;
return V_7 ;
}
int F_141 ( struct V_13 * V_14 , struct V_70 * V_71 ,
struct V_26 * V_27 , T_6 V_224 )
{
enum V_175 V_180 = V_456 ;
struct V_6 * V_7 ;
unsigned long V_65 ;
int V_481 = 0 ;
V_7 = F_139 ( V_14 , V_27 , V_224 ) ;
V_180 = F_137 ( V_14 , V_7 , V_71 ) ;
if ( V_180 != V_185 ) {
F_92 ( & V_14 -> V_38 -> V_39 ,
L_54 ,
V_196 ,
V_180 ) ;
return V_180 ;
}
F_112 ( & V_14 -> V_482 , V_65 ) ;
if ( F_18 ( V_483 , & V_71 -> V_65 ) ) {
if ( F_142 ( V_27 ) ) {
V_180 = F_143 ( V_14 ,
V_71 ,
V_7 ) ;
} else {
V_180 = V_197 ;
}
} else {
V_180 = F_144 ( V_14 , V_71 ,
V_7 ) ;
}
if ( V_180 != V_185 &&
V_180 != V_286 ) {
F_92 ( & V_14 -> V_38 -> V_39 ,
L_55 ,
V_196 , V_180 ) ;
F_113 ( & V_14 -> V_482 , V_65 ) ;
return V_180 ;
}
if ( V_180 != V_185 ) {
F_49 ( V_447 , & V_7 -> V_65 ) ;
}
F_113 ( & V_14 -> V_482 , V_65 ) ;
if ( V_180 ==
V_286 ) {
F_112 ( & V_27 -> V_439 , V_65 ) ;
V_27 -> V_440 |= V_441 ;
F_113 ( & V_27 -> V_439 , V_65 ) ;
F_145 ( V_27 ) ;
V_180 = V_185 ;
}
return V_481 ;
}
