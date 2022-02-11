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
V_7 -> V_228 = V_229 ;
V_7 -> V_175 = V_230 ;
F_40 ( & V_7 -> V_211 , V_231 ) ;
return V_185 ;
case V_227 :
case V_232 :
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
F_40 ( & V_7 -> V_211 , V_247 ) ;
return V_185 ;
case V_248 :
F_40 ( & V_7 -> V_211 , V_247 ) ;
F_40 ( & V_7 -> V_211 , V_231 ) ;
return V_185 ;
case V_247 :
case V_231 :
default:
F_47 ( & V_7 -> V_195 -> V_38 -> V_39 ,
L_6
L_5 ,
V_196 ,
V_7 -> V_211 . V_220 ) ;
break;
}
return V_221 ;
}
enum V_175 F_49 ( struct V_6 * V_7 )
{
enum V_1 V_2 ;
struct V_13 * V_14 = V_7 -> V_195 ;
V_2 = V_7 -> V_211 . V_220 ;
if ( F_50 ( V_2 != V_231 ,
L_7 ,
F_1 ( V_2 ) ) )
return V_221 ;
if ( V_7 -> V_249 != V_250 )
F_51 ( V_14 ,
V_7 -> V_249 ) ;
F_40 ( & V_7 -> V_211 , V_251 ) ;
return V_185 ;
}
enum V_175 F_52 ( struct V_6 * V_7 ,
T_2 V_252 )
{
enum V_1 V_2 ;
struct V_13 * V_14 = V_7 -> V_195 ;
V_2 = V_7 -> V_211 . V_220 ;
if ( V_2 != V_241 ) {
F_47 ( & V_14 -> V_38 -> V_39 , L_8 ,
V_196 , V_252 , F_1 ( V_2 ) ) ;
return V_221 ;
}
switch ( F_53 ( V_252 ) ) {
case V_253 << V_254 :
F_40 ( & V_7 -> V_211 , V_240 ) ;
return V_185 ;
default:
F_37 ( & V_14 -> V_38 -> V_39 ,
L_9 ,
V_196 , V_252 ) ;
return V_197 ;
}
}
static void F_54 ( struct V_6 * V_7 )
{
void * V_255 ;
T_2 V_111 ;
struct V_256 * V_257 ;
struct V_59 * V_59 = F_17 ( V_7 ) ;
V_257 = & V_7 -> V_45 . V_105 ;
V_255 = & V_59 -> V_258 . V_259 ;
V_111 = F_55 ( T_2 ,
V_260 ,
F_56 ( V_257 -> V_261 ) ) ;
memcpy ( V_255 , V_257 -> V_262 , V_111 ) ;
}
static enum V_175
F_57 ( struct V_6 * V_7 ,
T_2 V_263 )
{
struct V_256 * V_259 ;
T_3 V_264 ;
switch ( F_58 ( V_263 ) ) {
case F_59 ( V_265 ) :
V_7 -> V_228 = V_265 ;
V_7 -> V_175 = V_185 ;
break;
case F_59 ( V_266 ) : {
struct V_256 * V_258 = & V_7 -> V_45 . V_105 ;
T_5 V_267 = V_260 / sizeof( T_2 ) ;
F_15 ( & V_7 -> V_45 . V_105 ,
& V_7 -> V_45 . V_105 ,
V_267 ) ;
if ( V_258 -> V_180 == 0 ) {
V_7 -> V_228 = V_265 ;
V_7 -> V_175 = V_268 ;
} else {
V_7 -> V_228 = V_269 ;
V_7 -> V_175 = V_270 ;
}
break;
}
case F_59 ( V_269 ) : {
T_5 V_267 = V_260 / sizeof( T_2 ) ;
F_15 ( & V_7 -> V_45 . V_105 ,
& V_7 -> V_45 . V_105 ,
V_267 ) ;
V_7 -> V_228 = V_269 ;
V_7 -> V_175 = V_270 ;
break;
}
case F_59 ( V_271 ) :
V_259 = & V_7 -> V_45 . V_105 ;
V_264 = V_259 -> V_264 ;
if ( V_264 == 1 || V_264 == 2 ) {
V_7 -> V_228 = V_269 ;
V_7 -> V_175 = V_270 ;
} else {
V_7 -> V_228 = V_265 ;
V_7 -> V_175 = V_185 ;
}
break;
case F_59 ( V_272 ) :
case F_59 ( V_273 ) :
case F_59 ( V_274 ) :
case F_59 ( V_275 ) :
case F_59 ( V_276 ) :
case F_59 ( V_277 ) :
case F_59 ( V_278 ) :
case F_59 ( V_279 ) :
case F_59 ( V_280 ) :
case F_59 ( V_281 ) :
case F_59 ( V_282 ) :
if ( V_7 -> V_209 == V_213 ) {
V_7 -> V_228 = F_58 ( V_263 ) >>
V_283 ;
V_7 -> V_175 = V_284 ;
} else {
V_7 -> V_228 = F_58 ( V_263 ) >>
V_283 ;
V_7 -> V_175 = V_285 ;
}
break;
case F_59 ( V_286 ) :
case F_59 ( V_287 ) :
case F_59 ( V_288 ) :
case F_59 ( V_289 ) :
case F_59 ( V_290 ) :
case F_59 ( V_291 ) :
case F_59 ( V_292 ) :
case F_59 ( V_293 ) :
case F_59 ( V_294 ) :
case F_59 ( V_295 ) :
V_7 -> V_228 = F_58 ( V_263 ) >>
V_283 ;
V_7 -> V_175 = V_284 ;
break;
case F_59 ( V_296 ) :
case F_59 ( V_297 ) :
case F_59 ( V_298 ) :
case F_59 ( V_299 ) :
case F_59 ( V_300 ) :
case F_59 ( V_301 ) :
case F_59 ( V_302 ) :
case F_59 ( V_303 ) :
case F_59 ( V_304 ) :
case F_59 ( V_305 ) :
case F_59 ( V_306 ) :
case F_59 ( V_307 ) :
case F_59 ( V_308 ) :
case F_59 ( V_309 ) :
case F_59 ( V_310 ) :
default:
V_7 -> V_228 = F_58 ( V_263 ) >>
V_283 ;
V_7 -> V_175 = V_285 ;
break;
}
F_40 ( & V_7 -> V_211 , V_231 ) ;
return V_185 ;
}
static enum V_175
F_60 ( struct V_6 * V_7 ,
T_2 V_263 )
{
switch ( F_58 ( V_263 ) ) {
case ( V_265 << V_283 ) :
case ( V_229 << V_283 ) :
V_7 -> V_228 = V_229 ;
V_7 -> V_175 = V_230 ;
F_40 ( & V_7 -> V_211 , V_231 ) ;
break;
default:
break;
}
return V_185 ;
}
static enum V_175 F_61 ( struct V_6 * V_7 ,
T_2 V_263 )
{
switch ( F_58 ( V_263 ) ) {
case F_59 ( V_265 ) :
V_7 -> V_228 = V_265 ;
V_7 -> V_175 = V_185 ;
F_40 ( & V_7 -> V_211 , V_248 ) ;
break;
case F_59 ( V_272 ) :
F_47 ( & V_7 -> V_195 -> V_38 -> V_39 ,
L_10
L_11 , V_196 , V_7 ,
V_263 ) ;
F_40 ( & V_7 -> V_211 , V_248 ) ;
break;
default:
V_7 -> V_228 = F_62 ( V_263 ) ;
V_7 -> V_175 = V_285 ;
F_40 ( & V_7 -> V_211 , V_231 ) ;
break;
}
return V_185 ;
}
static enum V_175
F_63 ( struct V_6 * V_7 ,
T_2 V_263 )
{
switch ( F_58 ( V_263 ) ) {
case F_59 ( V_265 ) :
V_7 -> V_228 = V_265 ;
V_7 -> V_175 = V_185 ;
F_40 ( & V_7 -> V_211 , V_231 ) ;
break;
case F_59 ( V_302 ) :
case F_59 ( V_303 ) :
case F_59 ( V_304 ) :
case F_59 ( V_305 ) :
V_7 -> V_228 = V_302 ;
V_7 -> V_175 = V_311 ;
F_40 ( & V_7 -> V_211 , V_231 ) ;
break;
default:
V_7 -> V_228 = F_62 ( V_263 ) ;
V_7 -> V_175 = V_285 ;
F_40 ( & V_7 -> V_211 , V_231 ) ;
break;
}
return V_185 ;
}
static enum V_175
F_64 ( struct V_6 * V_7 ,
T_2 V_263 )
{
switch ( F_58 ( V_263 ) ) {
case F_59 ( V_265 ) :
V_7 -> V_228 = V_265 ;
V_7 -> V_175 = V_185 ;
F_40 ( & V_7 -> V_211 , V_231 ) ;
break;
default:
V_7 -> V_228 = F_62 ( V_263 ) ;
V_7 -> V_175 = V_285 ;
F_40 ( & V_7 -> V_211 , V_231 ) ;
break;
}
return V_185 ;
}
static struct V_18 * F_65 ( struct V_177 * V_178 )
{
struct V_18 * V_181 ;
struct V_5 * V_312 ;
struct V_6 * V_7 = F_66 ( V_178 ) ;
struct V_313 * V_314 = & V_178 -> V_181 ;
V_312 = F_2 ( V_7 , V_314 -> V_184 ) ;
if ( ! V_312 )
V_181 = NULL ;
else if ( V_314 -> V_182 == V_183 ) {
if ( V_312 -> V_35 . V_24 == 0 &&
V_312 -> V_35 . V_23 == 0 ) {
V_181 = NULL ;
} else {
V_314 -> V_182 = V_315 ;
V_181 = & V_312 -> V_35 ;
}
} else {
if ( V_312 -> V_37 == 0 &&
V_312 -> V_36 == 0 ) {
V_181 = NULL ;
} else {
V_314 -> V_184 ++ ;
V_314 -> V_182 = V_183 ;
V_312 = F_2 ( V_7 , V_314 -> V_184 ) ;
V_181 = & V_312 -> V_34 ;
}
}
return V_181 ;
}
static enum V_175
F_67 ( struct V_6 * V_7 ,
T_2 V_263 )
{
switch ( F_58 ( V_263 ) ) {
case F_59 ( V_265 ) :
V_7 -> V_228 = V_265 ;
V_7 -> V_175 = V_185 ;
F_40 ( & V_7 -> V_211 , V_238 ) ;
break;
default:
V_7 -> V_228 = F_62 ( V_263 ) ;
V_7 -> V_175 = V_285 ;
F_40 ( & V_7 -> V_211 , V_231 ) ;
break;
}
return V_185 ;
}
static enum V_175 F_68 (
struct V_6 * V_7 ,
T_2 V_22 )
{
struct V_177 * V_178 = & V_7 -> V_171 . V_179 ;
struct V_68 * V_69 = V_7 -> V_9 ;
struct V_5 * V_312 ;
struct V_18 * V_316 ;
V_312 = F_2 ( V_7 , V_178 -> V_181 . V_184 ) ;
if ( V_178 -> V_181 . V_182 == V_183 )
V_316 = & V_312 -> V_34 ;
else
V_316 = & V_312 -> V_35 ;
V_69 -> V_103 = V_316 -> V_23 ;
V_69 -> V_104 = V_316 -> V_24 ;
V_69 -> V_122 = V_22 ;
V_69 -> type . V_171 . V_173 = V_317 ;
return F_69 ( V_7 ) ;
}
static enum V_175 F_70 ( struct V_6 * V_7 )
{
struct V_177 * V_178 = & V_7 -> V_171 . V_179 ;
struct V_5 * V_312 ;
enum V_175 V_180 = V_185 ;
struct V_18 * V_181 ;
T_2 V_15 ;
T_2 V_111 = 0 ;
V_15 = V_178 -> V_181 . V_15 ;
V_312 = F_2 ( V_7 , V_178 -> V_181 . V_184 ) ;
if ( F_50 ( ! V_312 , L_12 , V_196 ) )
return V_197 ;
if ( V_178 -> V_181 . V_182 == V_183 ) {
V_181 = & V_312 -> V_34 ;
V_111 = V_312 -> V_34 . V_22 - V_15 ;
} else {
V_181 = & V_312 -> V_35 ;
V_111 = V_312 -> V_35 . V_22 - V_15 ;
}
if ( V_178 -> V_318 == 0 )
return V_185 ;
if ( V_178 -> V_318 >= V_111 ) {
V_180 = F_68 ( V_7 , V_111 ) ;
if ( V_180 != V_185 )
return V_180 ;
V_178 -> V_318 -= V_111 ;
V_181 = F_65 ( V_178 ) ;
V_15 = 0 ;
} else if ( V_178 -> V_318 < V_111 ) {
F_68 ( V_7 , V_178 -> V_318 ) ;
V_15 += V_178 -> V_318 ;
V_181 -> V_24 += V_178 -> V_318 ;
V_178 -> V_318 = 0 ;
}
V_178 -> V_181 . V_15 = V_15 ;
return V_180 ;
}
static enum V_175
F_71 ( struct V_177 * V_178 ,
T_3 * V_319 , T_2 V_111 )
{
struct V_6 * V_7 ;
T_3 * V_320 ;
int V_321 ;
struct V_26 * V_27 ;
struct V_20 * V_21 ;
void * V_322 ;
int V_323 = V_111 ;
V_7 = F_66 ( V_178 ) ;
V_27 = F_11 ( V_7 ) ;
V_320 = V_319 ;
if ( V_27 -> V_32 > 0 ) {
V_21 = V_27 -> V_33 ;
while ( V_323 > 0 ) {
struct V_324 * V_324 = F_72 ( V_21 ) ;
V_321 = F_55 ( int , V_323 , F_6 ( V_21 ) ) ;
V_322 = F_73 ( V_324 ) ;
memcpy ( V_322 + V_21 -> V_15 , V_320 , V_321 ) ;
F_74 ( V_322 ) ;
V_323 -= V_321 ;
V_320 += V_321 ;
V_21 = F_12 ( V_21 ) ;
}
} else {
F_75 ( V_27 -> V_40 < V_323 ) ;
memcpy ( V_27 -> V_33 , V_320 , V_323 ) ;
}
return V_185 ;
}
static enum V_175 F_76 (
struct V_177 * V_178 ,
T_3 * V_325 )
{
enum V_175 V_180 ;
if ( V_178 -> V_318 < V_326 ) {
V_180 = F_71 (
V_178 , V_325 , V_178 -> V_318 ) ;
if ( V_180 == V_185 )
V_178 -> V_318 = 0 ;
} else {
V_180 = F_71 (
V_178 , V_325 , V_326 ) ;
if ( V_180 == V_185 )
V_178 -> V_318 -= V_326 ;
}
return V_180 ;
}
static enum V_175
F_77 ( struct V_6 * V_7 ,
T_2 V_263 )
{
enum V_175 V_180 = V_185 ;
switch ( F_58 ( V_263 ) ) {
case F_59 ( V_265 ) :
V_7 -> V_228 = V_265 ;
V_7 -> V_175 = V_185 ;
F_40 ( & V_7 -> V_211 , V_240 ) ;
break;
default:
V_7 -> V_228 = F_62 ( V_263 ) ;
V_7 -> V_175 = V_285 ;
F_40 ( & V_7 -> V_211 , V_231 ) ;
break;
}
return V_180 ;
}
static enum V_175
F_78 ( struct V_6 * V_7 ,
T_2 V_263 )
{
enum V_175 V_180 = V_185 ;
bool V_327 = false ;
struct V_177 * V_178 = & V_7 -> V_171 . V_179 ;
switch ( F_58 ( V_263 ) ) {
case F_59 ( V_265 ) :
if ( V_178 -> V_318 != 0 ) {
V_180 = F_70 ( V_7 ) ;
if ( V_180 == V_185 ) {
if ( V_178 -> V_318 == 0 )
V_327 = true ;
}
} else if ( V_178 -> V_318 == 0 ) {
V_327 = true ;
}
if ( V_327 ) {
F_40 ( & V_7 -> V_211 , V_240 ) ;
}
break;
default:
V_7 -> V_228 = F_62 ( V_263 ) ;
V_7 -> V_175 = V_285 ;
F_40 ( & V_7 -> V_211 , V_231 ) ;
break;
}
return V_180 ;
}
static enum V_175 F_79 ( struct V_6 * V_7 ,
T_2 V_328 )
{
struct V_13 * V_14 = V_7 -> V_195 ;
struct V_329 * V_330 ;
enum V_175 V_180 ;
T_2 * V_331 ;
V_180 = F_80 ( & V_14 -> V_332 ,
V_328 ,
( void * * ) & V_330 ) ;
if ( ( V_180 == V_185 ) &&
( V_330 -> V_173 == V_333 ) ) {
F_81 ( & V_14 -> V_332 ,
V_328 ,
( void * * ) & V_331 ) ;
F_82 ( & V_7 -> V_171 . V_105 ,
V_330 ,
V_331 ) ;
}
F_51 ( V_14 , V_328 ) ;
return V_180 ;
}
static enum V_175 F_83 ( struct V_6 * V_7 ,
T_2 V_328 )
{
struct V_13 * V_14 = V_7 -> V_195 ;
enum V_175 V_180 ;
struct V_329 * V_330 ;
T_2 * V_331 ;
V_180 = F_80 ( & V_14 -> V_332 ,
V_328 ,
( void * * ) & V_330 ) ;
if ( V_180 != V_185 )
return V_180 ;
if ( V_330 -> V_173 != V_333 ) {
F_37 ( & V_7 -> V_13 -> V_38 -> V_39 ,
L_13 ,
V_196 , V_330 -> V_173 ) ;
return V_197 ;
}
F_81 ( & V_14 -> V_332 ,
V_328 ,
( void * * ) & V_331 ) ;
F_82 ( & V_7 -> V_171 . V_105 ,
( T_2 * ) V_330 ,
V_331 ) ;
F_51 ( V_14 , V_328 ) ;
return V_180 ;
}
static enum V_175 F_84 ( struct V_6 * V_7 ,
T_2 V_328 )
{
struct V_26 * V_27 = F_11 ( V_7 ) ;
enum V_175 V_180 ;
V_180 = F_83 ( V_7 , V_328 ) ;
if ( V_180 == V_185 ) {
if ( V_7 -> V_171 . V_105 . V_180 & V_334 )
V_180 = V_335 ;
} else {
V_180 = V_335 ;
}
if ( V_180 != V_185 ) {
V_7 -> V_228 = V_269 ;
V_7 -> V_175 = V_180 ;
} else {
V_7 -> V_228 = V_265 ;
V_7 -> V_175 = V_185 ;
}
if ( V_27 -> V_41 == V_156 )
F_40 ( & V_7 -> V_211 , V_231 ) ;
return V_180 ;
}
static void F_85 ( struct V_6 * V_7 )
{
struct V_336 * V_39 = F_86 ( V_7 -> V_74 -> V_194 ) ;
void * V_337 = V_7 -> V_115 . V_116 -> V_202 . V_338 ;
struct V_68 * V_69 = V_7 -> V_9 ;
memset ( & V_7 -> V_171 . V_46 , 0 , sizeof( struct V_169 ) ) ;
memcpy ( ( ( T_3 * ) & V_7 -> V_171 . V_46 + sizeof( T_2 ) ) , V_337 , V_339 ) ;
memset ( & ( V_69 -> type . V_171 ) , 0 , sizeof( struct V_340 ) ) ;
V_69 -> type . V_171 . V_173 = V_317 ;
V_69 -> V_122 = V_39 -> V_341 ;
}
static void F_87 ( struct V_6 * V_7 )
{
struct V_336 * V_39 = F_86 ( V_7 -> V_74 -> V_194 ) ;
struct V_26 * V_27 = F_11 ( V_7 ) ;
struct V_68 * V_69 = V_7 -> V_9 ;
int V_341 = V_39 -> V_341 ;
if ( V_27 -> V_41 == V_159 ) {
V_69 -> V_157 = V_342 ;
V_69 -> V_343 = 0 ;
} else {
V_69 -> V_157 = V_344 ;
V_69 -> V_343 = 1 ;
}
memset ( & V_69 -> type . V_171 , 0 , sizeof( V_69 -> type . V_171 ) ) ;
V_69 -> type . V_171 . V_173 = V_317 ;
memset ( & V_7 -> V_171 . V_46 , 0 , sizeof( V_7 -> V_171 . V_46 ) ) ;
memcpy ( & V_7 -> V_171 . V_46 . V_345 , V_27 -> V_202 . V_338 , V_341 ) ;
V_69 -> V_152 = V_341 / sizeof( T_2 ) ;
V_69 -> V_98 = 0x1 ;
V_69 -> V_346 = 0 ;
V_69 -> V_122 = V_27 -> V_40 ;
F_10 ( V_7 ) ;
}
enum V_175
F_88 ( struct V_6 * V_7 ,
T_2 V_328 )
{
struct V_13 * V_14 = V_7 -> V_195 ;
struct V_177 * V_178 = & V_7 -> V_171 . V_179 ;
enum V_1 V_2 ;
enum V_175 V_180 ;
T_5 V_267 ;
V_2 = V_7 -> V_211 . V_220 ;
switch ( V_2 ) {
case V_227 : {
struct V_347 V_348 ;
void * V_330 ;
F_80 ( & V_14 -> V_332 ,
V_328 ,
& V_330 ) ;
V_267 = sizeof( struct V_347 ) / sizeof( T_2 ) ;
F_15 ( & V_348 , V_330 , V_267 ) ;
if ( V_348 . V_153 == V_349 ) {
struct V_256 * V_259 ;
T_5 V_267 = V_260 / sizeof( T_2 ) ;
F_81 ( & V_14 -> V_332 ,
V_328 ,
( void * * ) & V_259 ) ;
F_15 ( & V_7 -> V_45 . V_105 , V_259 , V_267 ) ;
V_259 = & V_7 -> V_45 . V_105 ;
if ( V_259 -> V_264 == 0x01 ||
V_259 -> V_264 == 0x02 ) {
V_7 -> V_228 = V_269 ;
V_7 -> V_175 = V_285 ;
} else {
V_7 -> V_228 = V_265 ;
V_7 -> V_175 = V_185 ;
}
} else {
F_37 ( & V_14 -> V_38 -> V_39 ,
L_14
L_15 , V_196 , V_7 ,
V_328 , V_348 . V_153 ) ;
}
F_51 ( V_14 , V_328 ) ;
return V_185 ;
}
case V_248 :
F_54 ( V_7 ) ;
F_40 ( & V_7 -> V_211 , V_231 ) ;
F_51 ( V_14 , V_328 ) ;
return V_185 ;
case V_233 : {
struct V_26 * V_27 = F_11 ( V_7 ) ;
struct V_20 * V_21 = & V_27 -> V_350 . V_351 ;
void * V_330 , * V_322 ;
T_3 * V_105 ;
F_80 ( & V_14 -> V_332 ,
V_328 ,
& V_330 ) ;
V_322 = F_73 ( F_72 ( V_21 ) ) ;
V_105 = V_322 + V_21 -> V_15 ;
F_15 ( V_105 , V_330 , 1 ) ;
if ( V_105 [ 0 ] == V_352 ) {
void * V_351 ;
F_81 ( & V_14 -> V_332 ,
V_328 ,
& V_351 ) ;
V_267 = ( V_21 -> V_22 / 4 ) - 1 ;
if ( V_267 > 0 )
V_267 = F_55 (unsigned int, word_cnt,
SCU_UNSOLICITED_FRAME_BUFFER_SIZE/4 ) ;
F_15 ( V_105 + 4 , V_351 , V_267 ) ;
V_7 -> V_228 = V_265 ;
V_7 -> V_175 = V_185 ;
F_40 ( & V_7 -> V_211 , V_234 ) ;
} else {
F_37 ( & V_14 -> V_38 -> V_39 ,
L_16
L_15 ,
V_196 ,
V_7 ,
V_328 ,
V_105 [ 0 ] ) ;
V_7 -> V_228 = V_304 ;
V_7 -> V_175 = V_285 ;
F_40 ( & V_7 -> V_211 , V_231 ) ;
}
F_74 ( V_322 ) ;
F_51 ( V_14 , V_328 ) ;
return V_185 ;
}
case V_235 :
return F_79 ( V_7 ,
V_328 ) ;
case V_236 :
V_180 = F_79 ( V_7 , V_328 ) ;
if ( V_180 != V_185 )
return V_180 ;
V_7 -> V_228 = V_269 ;
V_7 -> V_175 = V_270 ;
F_40 ( & V_7 -> V_211 , V_231 ) ;
return V_185 ;
case V_238 : {
struct V_329 * V_330 ;
T_2 * V_331 ;
V_180 = F_80 ( & V_14 -> V_332 ,
V_328 ,
( void * * ) & V_330 ) ;
if ( V_180 != V_185 ) {
F_37 ( & V_14 -> V_38 -> V_39 ,
L_17
L_18 ,
V_196 ,
V_178 ,
V_328 ,
V_180 ) ;
return V_180 ;
}
switch ( V_330 -> V_173 ) {
case V_333 :
F_81 ( & V_14 -> V_332 ,
V_328 ,
( void * * ) & V_331 ) ;
F_82 ( & V_7 -> V_171 . V_105 ,
V_330 ,
V_331 ) ;
V_7 -> V_228 = V_269 ;
V_7 -> V_175 = V_270 ;
break;
default:
F_47 ( & V_14 -> V_38 -> V_39 ,
L_19
L_20 , V_196 , V_178 ,
V_328 ) ;
V_7 -> V_228 = V_353 ;
V_7 -> V_175 = V_354 ;
break;
}
F_40 ( & V_7 -> V_211 , V_231 ) ;
F_51 ( V_14 , V_328 ) ;
return V_180 ;
}
case V_240 : {
struct V_26 * V_27 = F_11 ( V_7 ) ;
struct V_329 * V_330 ;
T_2 * V_331 ;
V_180 = F_80 ( & V_14 -> V_332 ,
V_328 ,
( void * * ) & V_330 ) ;
if ( V_180 != V_185 ) {
F_37 ( & V_14 -> V_38 -> V_39 ,
L_17
L_18 ,
V_196 , V_178 , V_328 , V_180 ) ;
return V_180 ;
}
switch ( V_330 -> V_173 ) {
case V_355 :
F_81 ( & V_14 -> V_332 ,
V_328 ,
( void * * ) & V_331 ) ;
V_178 -> V_318 = V_331 [ 3 ] & 0xffff ;
V_178 -> V_180 = ( V_331 [ 2 ] >> 24 ) & 0xff ;
F_82 ( & V_7 -> V_171 . V_105 ,
V_330 ,
V_331 ) ;
V_7 -> V_171 . V_105 . V_180 = V_178 -> V_180 ;
if ( V_27 -> V_41 == V_155 ) {
F_40 ( & V_7 -> V_211 , V_241 ) ;
} else if ( V_27 -> V_41 == V_159 ) {
V_180 = F_70 ( V_7 ) ;
if ( V_180 != V_185 )
break;
F_40 ( & V_7 -> V_211 , V_242 ) ;
}
break;
case V_356 :
F_40 ( & V_7 -> V_211 , V_240 ) ;
break;
case V_333 :
if ( V_330 -> V_180 & V_357 ) {
F_89 ( & V_14 -> V_38 -> V_39 ,
L_21
L_22
L_23 ,
V_196 ,
V_178 ,
V_330 -> V_180 ) ;
break;
}
F_81 ( & V_14 -> V_332 ,
V_328 ,
( void * * ) & V_331 ) ;
F_82 ( & V_7 -> V_171 . V_179 ,
V_330 ,
V_331 ) ;
V_7 -> V_228 = V_269 ;
V_7 -> V_175 = V_270 ;
F_40 ( & V_7 -> V_211 , V_231 ) ;
break;
default:
break;
}
F_51 ( V_14 , V_328 ) ;
return V_180 ;
}
case V_241 : {
struct V_329 * V_330 ;
struct V_358 * V_331 ;
V_180 = F_80 ( & V_14 -> V_332 ,
V_328 ,
( void * * ) & V_330 ) ;
if ( V_180 != V_185 ) {
F_37 ( & V_14 -> V_38 -> V_39 ,
L_17
L_18 ,
V_196 ,
V_178 ,
V_328 ,
V_180 ) ;
return V_180 ;
}
if ( V_330 -> V_173 != V_317 ) {
F_37 ( & V_14 -> V_38 -> V_39 ,
L_24
L_25
L_26 ,
V_196 ,
V_178 ,
V_328 ,
V_330 -> V_173 ) ;
V_7 -> V_228 = V_265 ;
V_7 -> V_175 = V_359 ;
F_40 ( & V_7 -> V_211 , V_231 ) ;
F_51 ( V_14 , V_328 ) ;
return V_180 ;
}
if ( V_178 -> V_181 . V_184 < 0 ) {
V_7 -> V_249 = V_328 ;
V_178 -> V_318 = 0 ;
} else {
F_81 ( & V_14 -> V_332 ,
V_328 ,
( void * * ) & V_331 ) ;
V_180 = F_76 ( V_178 ,
( T_3 * ) V_331 ) ;
F_51 ( V_14 , V_328 ) ;
}
if ( V_180 != V_185 || V_178 -> V_318 != 0 )
return V_180 ;
if ( ( V_178 -> V_180 & V_357 ) == 0 ) {
V_7 -> V_228 = V_269 ;
V_7 -> V_175 = V_270 ;
F_40 ( & V_7 -> V_211 , V_231 ) ;
} else {
F_40 ( & V_7 -> V_211 , V_240 ) ;
}
return V_180 ;
}
case V_244 : {
struct V_26 * V_27 = F_11 ( V_7 ) ;
F_51 ( V_14 , V_328 ) ;
V_7 -> V_74 -> V_360 = V_7 ;
if ( V_27 -> V_41 == V_156 ) {
F_40 ( & V_7 -> V_211 , V_246 ) ;
F_85 ( V_7 ) ;
} else {
F_40 ( & V_7 -> V_211 , V_245 ) ;
F_87 ( V_7 ) ;
}
F_69 ( V_7 ) ;
return V_185 ;
}
case V_245 :
return F_84 ( V_7 , V_328 ) ;
case V_247 :
F_51 ( V_14 , V_328 ) ;
return V_185 ;
default:
F_47 ( & V_14 -> V_38 -> V_39 ,
L_27
L_28 ,
V_196 ,
V_328 ,
V_2 ) ;
F_51 ( V_14 , V_328 ) ;
return V_221 ;
}
}
static enum V_175 F_90 ( struct V_6 * V_7 ,
T_2 V_263 )
{
enum V_175 V_180 = V_185 ;
switch ( F_58 ( V_263 ) ) {
case F_59 ( V_265 ) :
V_7 -> V_228 = V_265 ;
V_7 -> V_175 = V_185 ;
F_40 ( & V_7 -> V_211 , V_231 ) ;
break;
case F_59 ( V_353 ) :
case F_59 ( V_281 ) :
if ( V_7 -> V_171 . V_105 . V_173 == V_333 ) {
F_91 ( V_7 -> V_74 ,
F_92 ( F_62 ( V_263 ) ) ) ;
V_7 -> V_228 = V_269 ;
V_7 -> V_175 = V_270 ;
F_40 ( & V_7 -> V_211 , V_231 ) ;
} else {
F_40 ( & V_7 -> V_211 , V_236 ) ;
}
break;
case F_59 ( V_361 ) :
case F_59 ( V_278 ) :
case F_59 ( V_362 ) :
case F_59 ( V_363 ) :
F_91 ( V_7 -> V_74 ,
F_92 ( F_62 ( V_263 ) ) ) ;
default:
V_7 -> V_228 = F_62 ( V_263 ) ;
V_7 -> V_175 = V_285 ;
F_40 ( & V_7 -> V_211 , V_231 ) ;
break;
}
return V_180 ;
}
static enum V_175 F_93 ( struct V_6 * V_7 , T_2 V_263 ,
enum V_1 V_364 )
{
enum V_175 V_180 = V_185 ;
switch ( F_58 ( V_263 ) ) {
case F_59 ( V_265 ) :
V_7 -> V_228 = V_265 ;
V_7 -> V_175 = V_185 ;
F_40 ( & V_7 -> V_211 , V_364 ) ;
break;
default:
V_7 -> V_228 = F_62 ( V_263 ) ;
V_7 -> V_175 = V_285 ;
F_40 ( & V_7 -> V_211 , V_231 ) ;
break;
}
return V_180 ;
}
static enum V_175 F_94 ( struct V_6 * V_7 ,
T_2 V_263 )
{
struct V_70 * V_71 = V_7 -> V_74 ;
struct V_329 * V_365 = & V_7 -> V_171 . V_105 ;
enum V_175 V_180 = V_185 ;
switch ( F_58 ( V_263 ) ) {
case ( V_265 << V_283 ) :
F_40 ( & V_7 -> V_211 , V_231 ) ;
break;
case ( V_353 << V_283 ) : {
T_6 V_111 = F_43 ( V_7 ) ;
if ( V_365 -> V_173 != V_333 ) {
V_365 -> V_173 = V_333 ;
V_365 -> V_65 = ( 1 << 6 ) ;
V_365 -> V_180 = 0x50 ;
V_365 -> error = 0 ;
V_365 -> V_345 = 0 ;
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
V_7 -> V_228 = V_265 ;
V_7 -> V_175 = V_268 ;
V_180 = V_7 -> V_175 ;
F_40 ( & V_71 -> V_211 , V_374 ) ;
break;
}
case ( V_301 << V_283 ) :
V_7 -> V_228 = V_265 ;
V_7 -> V_175 = V_185 ;
F_40 ( & V_7 -> V_211 , V_231 ) ;
break;
default:
if ( V_365 -> V_173 == V_333 ) {
V_180 = V_7 -> V_175 ;
F_40 ( & V_71 -> V_211 , V_374 ) ;
} else {
V_7 -> V_228 = V_269 ;
V_7 -> V_175 = V_270 ;
F_40 ( & V_7 -> V_211 , V_245 ) ;
}
break;
}
return V_180 ;
}
enum V_175
F_95 ( struct V_6 * V_7 ,
T_2 V_263 )
{
enum V_1 V_2 ;
struct V_13 * V_14 = V_7 -> V_195 ;
V_2 = V_7 -> V_211 . V_220 ;
switch ( V_2 ) {
case V_227 :
return F_57 ( V_7 , V_263 ) ;
case V_232 :
return F_61 ( V_7 ,
V_263 ) ;
case V_233 :
return F_63 ( V_7 ,
V_263 ) ;
case V_234 :
return F_64 ( V_7 , V_263 ) ;
case V_235 :
return F_90 ( V_7 ,
V_263 ) ;
case V_237 :
return F_67 ( V_7 ,
V_263 ) ;
case V_239 :
return F_77 ( V_7 ,
V_263 ) ;
case V_242 :
return F_78 ( V_7 , V_263 ) ;
case V_247 :
return F_60 ( V_7 ,
V_263 ) ;
case V_243 :
return F_93 ( V_7 , V_263 ,
V_244 ) ;
case V_246 :
return F_93 ( V_7 , V_263 ,
V_245 ) ;
case V_245 :
return F_94 ( V_7 , V_263 ) ;
default:
F_47 ( & V_14 -> V_38 -> V_39 , L_29 ,
V_196 , V_263 , F_1 ( V_2 ) ) ;
return V_221 ;
}
}
static void F_96 (
struct V_26 * V_27 ,
struct V_256 * V_259 ,
struct V_119 * V_39 )
{
F_89 ( V_39 ,
L_30
L_31
L_32
L_33 ,
V_196 ,
V_259 ,
V_259 -> V_180 ,
V_259 -> V_264 ,
V_259 -> V_261 ,
V_259 -> V_375 ) ;
V_27 -> V_376 . V_377 = V_259 -> V_180 ;
F_97 ( V_39 , V_27 , V_259 ) ;
}
static void F_98 (
struct V_6 * V_378 ,
struct V_26 * V_27 ,
enum V_379 * V_380 ,
enum V_381 * V_382 ,
enum V_383 * V_384 ,
enum V_385 V_386 )
{
F_99 ( V_387 , & V_378 -> V_65 ) ;
* V_380 = V_388 ;
* V_382 = V_389 ;
* V_384 = V_390 ;
V_27 -> V_376 . V_386 = V_386 ;
}
static void F_100 (
struct V_70 * V_71 ,
struct V_6 * V_378 ,
struct V_26 * V_27 ,
enum V_379 * V_380 ,
enum V_381 * V_382 ,
enum V_383 * V_384 )
{
unsigned int V_391 ;
V_391 = V_378 -> V_228 ;
F_89 ( & V_378 -> V_13 -> V_38 -> V_39 ,
L_34
L_35 ,
V_196 , V_378 , V_391 ) ;
switch ( V_391 ) {
case V_392 :
case V_393 :
if ( V_27 -> V_198 == V_394 ) {
* V_380 = V_395 ;
if ( ! V_71 )
* V_382 = V_396 ;
else
* V_382 = V_397 ;
F_99 ( V_387 , & V_378 -> V_65 ) ;
* V_384 =
V_390 ;
} else {
* V_380 = V_388 ;
if ( ! V_71 )
* V_382 = V_396 ;
else
* V_382 = V_398 ;
F_101 ( V_387 , & V_378 -> V_65 ) ;
* V_384 =
V_399 ;
}
break;
case V_253 :
case V_296 :
case V_301 :
case V_353 :
case V_308 :
case V_309 :
case V_310 :
* V_380 = V_395 ;
if ( ! V_71 )
* V_382 = V_396 ;
else
* V_382 = V_397 ;
F_99 ( V_387 , & V_378 -> V_65 ) ;
* V_384 = V_390 ;
break;
case V_287 :
F_98 (
V_378 , V_27 , V_380 , V_382 ,
V_384 , V_400 ) ;
break;
case V_292 :
F_98 (
V_378 , V_27 , V_380 , V_382 ,
V_384 , V_401 ) ;
break;
case V_288 :
F_98 (
V_378 , V_27 , V_380 , V_382 ,
V_384 , V_402 ) ;
break;
case V_289 :
F_98 (
V_378 , V_27 , V_380 , V_382 ,
V_384 , V_403 ) ;
break;
case V_290 :
F_98 (
V_378 , V_27 , V_380 , V_382 ,
V_384 , V_404 ) ;
break;
case V_291 :
F_98 (
V_378 , V_27 , V_380 , V_382 ,
V_384 , V_405 ) ;
break;
case V_293 :
F_98 (
V_378 , V_27 , V_380 , V_382 ,
V_384 , V_406 ) ;
break;
case V_294 :
F_98 (
V_378 , V_27 , V_380 , V_382 ,
V_384 , V_407 ) ;
break;
case V_295 :
F_98 (
V_378 , V_27 , V_380 , V_382 ,
V_384 , V_408 ) ;
break;
case V_362 :
case V_273 :
case V_409 :
case V_410 :
case V_276 :
case V_411 :
case V_298 :
case V_361 :
case V_299 :
case V_300 :
case V_278 :
case V_286 :
case V_302 :
case V_305 :
case V_306 :
case V_280 :
case V_281 :
case V_282 :
case V_229 :
default:
* V_380 = V_388 ;
* V_382 = V_398 ;
if ( V_27 -> V_198 == V_394 ) {
F_99 ( V_387 , & V_378 -> V_65 ) ;
* V_384 = V_390 ;
} else {
F_101 ( V_387 , & V_378 -> V_65 ) ;
* V_384 = V_399 ;
}
break;
}
}
static void F_102 (
struct V_13 * V_412 ,
struct V_6 * V_378 ,
enum V_379 V_413 ,
enum V_381 V_180 ,
enum V_383 V_414 )
{
struct V_26 * V_27 = F_11 ( V_378 ) ;
V_414
= F_103 ( V_27 , V_413 , V_180 ,
V_414 ) ;
switch ( V_414 ) {
case V_390 :
F_104 ( & V_378 -> V_415 ,
& V_412 -> V_416 ) ;
F_105 ( & V_378 -> V_417 ) ;
break;
case V_418 :
F_106 ( V_378 -> V_419 == NULL ) ;
if ( V_378 -> V_419 != NULL ) {
F_107 ( V_378 -> V_419 ) ;
}
break;
case V_399 :
F_104 ( & V_378 -> V_415 ,
& V_412 -> V_420 ) ;
break;
default:
F_104 ( & V_378 -> V_415 ,
& V_412 -> V_420 ) ;
break;
}
F_89 ( & V_412 -> V_38 -> V_39 ,
L_36 ,
V_196 , V_414 , V_27 ,
( V_27 ) ? V_27 -> V_376 . V_258 : 0 , V_413 ,
( V_27 ) ? V_27 -> V_376 . V_377 : 0 , V_180 ) ;
}
static void F_108 ( struct V_26 * V_27 , struct V_329 * V_203 )
{
struct V_421 * V_422 = & V_27 -> V_376 ;
struct V_423 * V_258 = ( void * ) & V_422 -> V_424 [ 0 ] ;
V_258 -> V_425 = sizeof( * V_203 ) ;
memcpy ( V_258 -> V_426 , V_203 , sizeof( * V_203 ) ) ;
V_422 -> V_427 = sizeof( * V_258 ) ;
if ( V_203 -> V_180 & V_428 )
V_422 -> V_377 = V_429 ;
else if ( V_203 -> V_180 & V_334 )
V_422 -> V_377 = V_430 ;
else
V_422 -> V_377 = V_431 ;
V_422 -> V_258 = V_395 ;
}
static void F_109 ( struct V_13 * V_14 ,
struct V_6 * V_378 ,
enum V_432 V_433 )
{
struct V_26 * V_27 = F_11 ( V_378 ) ;
struct V_256 * V_259 ;
unsigned long V_434 ;
struct V_70 * V_71 = V_378 -> V_74 ;
enum V_379 V_413 = V_388 ;
enum V_381 V_180 = V_397 ;
enum V_435 V_436 ;
enum V_383 V_437
= V_390 ;
F_89 ( & V_14 -> V_38 -> V_39 ,
L_37
L_38 ,
V_196 ,
V_378 ,
V_27 ,
V_27 -> V_41 ,
V_433 ) ;
F_110 ( & V_378 -> V_438 ) ;
V_436 = V_378 -> V_180 ;
switch ( V_436 ) {
case V_439 :
F_99 ( V_387 , & V_378 -> V_65 ) ;
V_413 = V_395 ;
if ( ! V_71 )
V_180 = V_396 ;
else
V_180 = V_397 ;
V_437 = V_418 ;
F_111 ( & V_378 -> V_438 ) ;
break;
case V_440 :
F_99 ( V_387 , & V_378 -> V_65 ) ;
V_413 = V_388 ;
if ( ! V_71 )
V_180 = V_396 ;
else
V_180 = V_441 ;
V_437 = V_418 ;
F_111 ( & V_378 -> V_438 ) ;
break;
case V_442 :
F_99 ( V_387 , & V_378 -> V_65 ) ;
V_413 = V_388 ;
if ( ! V_71 )
V_180 = V_396 ;
else
V_180 = V_397 ;
V_437 = V_418 ;
F_111 ( & V_378 -> V_438 ) ;
break;
case V_443 :
V_437 = V_390 ;
F_111 ( & V_378 -> V_438 ) ;
break;
default:
V_378 -> V_180 = V_444 ;
F_111 ( & V_378 -> V_438 ) ;
switch ( V_433 ) {
case V_335 :
F_89 ( & V_14 -> V_38 -> V_39 ,
L_39 ,
V_196 ,
V_378 ,
V_27 ) ;
if ( F_38 ( V_27 -> V_198 ) ) {
F_108 ( V_27 , & V_378 -> V_171 . V_105 ) ;
} else if ( V_445 == V_27 -> V_198 ) {
V_259 = & V_378 -> V_45 . V_105 ;
F_96 ( V_27 , V_259 ,
& V_14 -> V_38 -> V_39 ) ;
} else if ( V_394 == V_27 -> V_198 ) {
F_37 ( & V_14 -> V_38 -> V_39 ,
L_40
L_41 ,
V_196 ) ;
} else
F_37 ( & V_14 -> V_38 -> V_39 ,
L_42 , V_196 ) ;
F_99 ( V_387 , & V_378 -> V_65 ) ;
V_413 = V_27 -> V_376 . V_258 ;
V_180 = V_27 -> V_376 . V_377 ;
break;
case V_446 :
case V_447 :
V_413 = V_395 ;
V_180 = V_431 ;
F_99 ( V_387 , & V_378 -> V_65 ) ;
if ( V_433 == V_447 ) {
T_2 V_448 = F_43 ( V_378 ) ;
V_27 -> V_376 . V_449
= V_27 -> V_40 - V_448 ;
if ( V_27 -> V_376 . V_449 != 0 )
V_180 = V_450 ;
F_89 ( & V_14 -> V_38 -> V_39 ,
L_43 ,
V_196 ,
V_180 ) ;
} else
F_89 ( & V_14 -> V_38 -> V_39 ,
L_44 ,
V_196 ) ;
break;
case V_451 :
F_89 ( & V_14 -> V_38 -> V_39 ,
L_45 ,
V_196 ,
V_378 ,
V_27 ) ;
F_99 ( V_387 , & V_378 -> V_65 ) ;
V_413 = V_388 ;
if ( ! V_71 )
V_180 = V_396 ;
else
V_180 = V_397 ;
V_437 = V_390 ;
break;
case V_285 :
F_100 (
V_71 , V_378 , V_27 , & V_413 , & V_180 ,
& V_437 ) ;
break;
case V_452 :
F_112 ( & V_27 -> V_453 , V_434 ) ;
V_27 -> V_454 |= V_455 ;
F_113 ( & V_27 -> V_453 , V_434 ) ;
V_413 = V_388 ;
V_180 = V_398 ;
V_437 = V_399 ;
F_101 ( V_387 , & V_378 -> V_65 ) ;
break;
case V_311 :
V_413 = V_388 ;
if ( ! V_71 )
V_180 = V_396 ;
else
V_180 = V_397 ;
V_437 = V_390 ;
F_99 ( V_387 , & V_378 -> V_65 ) ;
break;
default:
F_89 ( & V_14 -> V_38 -> V_39 ,
L_46
L_47 ,
V_196 , V_433 , V_378 ) ;
V_413 = V_388 ;
if ( ! V_71 )
V_180 = V_396 ;
else
V_180 = V_397 ;
if ( V_394 == V_27 -> V_198 ) {
F_99 ( V_387 , & V_378 -> V_65 ) ;
V_437 = V_390 ;
} else {
F_101 ( V_387 , & V_378 -> V_65 ) ;
V_437 = V_399 ;
}
break;
}
break;
}
switch ( V_27 -> V_198 ) {
case V_445 :
if ( V_27 -> V_41 == V_156 )
break;
if ( V_27 -> V_32 == 0 )
F_114 ( & V_14 -> V_38 -> V_39 ,
V_378 -> V_42 ,
V_27 -> V_40 , V_27 -> V_41 ) ;
else
F_115 ( & V_14 -> V_38 -> V_39 , V_27 -> V_33 ,
V_378 -> V_456 , V_27 -> V_41 ) ;
break;
case V_394 : {
struct V_20 * V_21 = & V_27 -> V_350 . V_457 ;
struct V_457 * V_457 ;
void * V_322 ;
F_115 ( & V_14 -> V_38 -> V_39 , V_21 , 1 , V_159 ) ;
V_322 = F_73 ( F_72 ( V_21 ) ) ;
V_457 = V_322 + V_21 -> V_15 ;
F_15 ( V_457 , V_457 , V_21 -> V_22 / sizeof( T_2 ) ) ;
F_74 ( V_322 ) ;
break;
}
default:
break;
}
F_102 ( V_14 , V_378 , V_413 ,
V_180 , V_437
) ;
F_116 ( V_14 , V_378 -> V_74 , V_378 ) ;
F_99 ( V_458 , & V_378 -> V_65 ) ;
}
static void F_117 ( struct V_459 * V_211 )
{
struct V_6 * V_7 = F_118 ( V_211 , F_119 ( * V_7 ) , V_211 ) ;
struct V_193 * V_39 = V_7 -> V_74 -> V_194 ;
enum V_1 V_2 ;
struct V_26 * V_27 ;
V_27 = ( F_18 ( V_64 , & V_7 -> V_65 ) ) ? NULL : F_11 ( V_7 ) ;
if ( ! V_27 && V_39 -> V_460 == V_461 ) {
V_2 = V_232 ;
} else if ( V_27 && V_27 -> V_198 == V_394 ) {
V_2 = V_233 ;
} else if ( V_27 && F_38 ( V_27 -> V_198 ) &&
! V_27 -> V_202 . V_206 ) {
if ( V_39 -> V_199 . V_200 == V_201 &&
V_27 -> V_202 . V_203 . V_204 == V_205 ) {
V_2 = V_243 ;
} else if ( V_27 -> V_41 == V_156 ) {
V_2 = V_237 ;
} else if ( V_27 -> V_202 . V_208 ) {
V_2 = V_235 ;
} else {
V_2 = V_239 ;
}
} else {
return;
}
F_40 ( V_211 , V_2 ) ;
}
static void F_120 ( struct V_459 * V_211 )
{
struct V_6 * V_7 = F_118 ( V_211 , F_119 ( * V_7 ) , V_211 ) ;
struct V_13 * V_14 = V_7 -> V_195 ;
if ( ! F_18 ( V_64 , & V_7 -> V_65 ) )
F_109 ( V_14 , V_7 ,
V_7 -> V_175 ) ;
else
F_121 ( V_14 , V_7 , V_7 -> V_175 ) ;
}
static void F_122 ( struct V_459 * V_211 )
{
struct V_6 * V_7 = F_118 ( V_211 , F_119 ( * V_7 ) , V_211 ) ;
V_7 -> V_9 -> abort = 1 ;
}
static void F_123 ( struct V_459 * V_211 )
{
struct V_6 * V_7 = F_118 ( V_211 , F_119 ( * V_7 ) , V_211 ) ;
V_7 -> V_74 -> V_360 = V_7 ;
}
static void F_124 ( struct V_459 * V_211 )
{
struct V_6 * V_7 = F_118 ( V_211 , F_119 ( * V_7 ) , V_211 ) ;
V_7 -> V_74 -> V_360 = V_7 ;
}
static void
F_125 ( struct V_13 * V_14 ,
struct V_70 * V_71 ,
struct V_6 * V_7 )
{
F_126 ( & V_7 -> V_211 , V_462 , V_463 ) ;
V_7 -> V_74 = V_71 ;
V_7 -> V_209 = V_464 ;
V_7 -> V_249 = V_250 ;
V_7 -> V_175 = V_185 ;
V_7 -> V_228 = 0 ;
V_7 -> V_99 = 0xFFFFFFFF ;
}
static enum V_175
F_127 ( struct V_13 * V_14 ,
struct V_70 * V_71 ,
struct V_6 * V_7 )
{
struct V_193 * V_39 = V_71 -> V_194 ;
enum V_175 V_180 = V_185 ;
F_125 ( V_14 , V_71 , V_7 ) ;
if ( V_71 -> V_90 . V_89 == V_465 )
return V_466 ;
if ( V_39 -> V_460 == V_461 )
;
else if ( V_39 -> V_460 == V_467 || ( V_39 -> V_468 & V_469 ) )
memset ( & V_7 -> V_171 . V_46 , 0 , sizeof( V_7 -> V_171 . V_46 ) ) ;
else if ( F_128 ( V_39 ) )
;
else
return V_470 ;
memset ( V_7 -> V_9 , 0 , F_45 ( struct V_68 , V_10 ) ) ;
return V_180 ;
}
enum V_175 F_129 ( struct V_13 * V_14 ,
struct V_70 * V_71 ,
T_6 V_66 , struct V_6 * V_7 )
{
struct V_193 * V_39 = V_71 -> V_194 ;
enum V_175 V_180 = V_185 ;
F_125 ( V_14 , V_71 , V_7 ) ;
if ( V_39 -> V_460 == V_461 ||
V_39 -> V_460 == V_467 || ( V_39 -> V_468 & V_469 ) ) {
F_99 ( V_64 , & V_7 -> V_65 ) ;
memset ( V_7 -> V_9 , 0 , sizeof( struct V_68 ) ) ;
} else
V_180 = V_470 ;
return V_180 ;
}
static enum V_175 F_130 (
struct V_6 * V_378 )
{
enum V_175 V_180 ;
F_89 ( & V_378 -> V_13 -> V_38 -> V_39 ,
L_48 ,
V_196 ,
V_378 ) ;
V_180 = F_39 ( V_378 ) ;
return V_180 ;
}
static enum V_175 F_131 ( struct V_6 * V_7 )
{
struct V_26 * V_27 = F_11 ( V_7 ) ;
struct V_169 * V_203 = & V_7 -> V_171 . V_46 ;
struct V_471 * V_472 = V_27 -> V_117 ;
enum V_175 V_180 ;
F_89 ( & V_7 -> V_13 -> V_38 -> V_39 ,
L_49 ,
V_196 ,
V_7 ) ;
memcpy ( V_203 , & V_27 -> V_202 . V_203 , sizeof( struct V_169 ) ) ;
if ( ! V_27 -> V_202 . V_473 )
V_203 -> V_65 |= 0x80 ;
V_203 -> V_65 &= 0xF0 ;
V_180 = F_42 ( V_7 ) ;
if ( V_472 && ( V_472 -> V_474 . V_204 == V_475 ||
V_472 -> V_474 . V_204 == V_476 ) ) {
V_203 -> V_371 = V_472 -> V_224 << 3 ;
V_7 -> V_9 -> type . V_171 . V_477 = V_472 -> V_224 ;
}
return V_180 ;
}
static enum V_175
F_132 ( struct V_119 * V_39 ,
struct V_6 * V_7 ,
struct V_26 * V_27 )
{
struct V_20 * V_21 = & V_27 -> V_350 . V_457 ;
struct V_70 * V_71 ;
struct V_68 * V_69 ;
struct V_72 * V_73 ;
struct V_457 * V_457 ;
void * V_322 ;
T_3 V_478 ;
T_2 V_46 ;
V_322 = F_73 ( F_72 ( V_21 ) ) ;
V_457 = V_322 + V_21 -> V_15 ;
if ( V_457 -> V_478 == 0 ) {
switch ( V_457 -> V_479 ) {
case V_480 :
case V_481 :
case V_482 :
case V_483 :
V_457 -> V_478 = 2 ;
break;
case V_484 :
case V_485 :
case V_486 :
V_457 -> V_478 = 9 ;
break;
}
}
V_478 = V_457 -> V_478 ;
F_15 ( V_457 , V_457 , V_21 -> V_22 / sizeof( T_2 ) ) ;
V_46 = * ( T_2 * ) V_457 ;
F_74 ( V_322 ) ;
if ( ! F_133 ( V_39 , V_21 , 1 , V_159 ) )
return V_197 ;
V_7 -> V_209 = V_487 ;
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
V_69 -> V_157 = V_488 ;
V_69 -> V_92 = 0 ;
V_69 -> V_93 = 1 ;
V_69 -> V_94 = 0 ;
V_69 -> V_95 = 1 ;
V_69 -> V_96 = 0 ;
V_69 -> V_97 = 0 ;
V_69 -> V_25 = 0 ;
V_69 -> V_152 = V_478 ;
V_69 -> V_122 = 0 ;
memcpy ( & V_69 -> type . V_489 , & V_46 , sizeof( T_2 ) ) ;
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
static enum V_175 F_134 ( struct V_6 * V_7 )
{
struct V_26 * V_27 = F_11 ( V_7 ) ;
struct V_119 * V_39 = & V_7 -> V_13 -> V_38 -> V_39 ;
enum V_175 V_180 = V_197 ;
V_180 = F_132 ( V_39 , V_7 , V_27 ) ;
if ( V_180 != V_185 )
F_89 ( & V_7 -> V_13 -> V_38 -> V_39 ,
L_50 ,
V_196 ,
V_180 ) ;
return V_180 ;
}
static enum V_175 F_135 ( struct V_13 * V_14 ,
struct V_6 * V_378 ,
struct V_70 * V_71 )
{
enum V_175 V_180 = V_185 ;
struct V_26 * V_27 = F_11 ( V_378 ) ;
F_89 ( & V_14 -> V_38 -> V_39 ,
L_51
L_52 ,
V_196 ,
V_71 ,
V_378 ,
V_27 -> V_32 ) ;
if ( V_27 -> V_32 &&
! F_38 ( V_27 -> V_198 ) &&
! ( V_394 & V_27 -> V_198 ) ) {
V_378 -> V_456 = F_133 (
& V_14 -> V_38 -> V_39 ,
V_27 -> V_33 ,
V_27 -> V_32 ,
V_27 -> V_41
) ;
if ( V_378 -> V_456 == 0 )
return V_490 ;
}
V_180 = F_127 ( V_14 , V_71 , V_378 ) ;
if ( V_180 != V_185 ) {
F_89 ( & V_14 -> V_38 -> V_39 ,
L_53 ,
V_196 ) ;
return V_197 ;
}
switch ( V_27 -> V_198 ) {
case V_394 :
V_180 = F_134 ( V_378 ) ;
break;
case V_445 :
V_180 = F_130 ( V_378 ) ;
break;
case V_491 :
case V_469 :
case V_491 | V_469 :
V_180 = F_131 ( V_378 ) ;
break;
default:
F_89 ( & V_14 -> V_38 -> V_39 ,
L_42 , V_196 ) ;
return V_197 ;
}
return V_185 ;
}
static struct V_6 * F_136 ( struct V_13 * V_14 , T_6 V_224 )
{
struct V_6 * V_7 ;
V_7 = V_14 -> V_492 [ F_20 ( V_224 ) ] ;
V_7 -> V_66 = V_224 ;
V_7 -> V_419 = NULL ;
V_7 -> V_65 = 0 ;
V_7 -> V_456 = 0 ;
F_137 ( & V_7 -> V_415 ) ;
F_137 ( & V_7 -> V_417 ) ;
F_138 ( V_7 , V_493 ) ;
return V_7 ;
}
static struct V_6 * F_139 ( struct V_13 * V_14 ,
struct V_26 * V_27 ,
T_6 V_224 )
{
struct V_6 * V_7 ;
V_7 = F_136 ( V_14 , V_224 ) ;
V_7 -> V_115 . V_116 = V_27 ;
F_101 ( V_64 , & V_7 -> V_65 ) ;
V_27 -> V_494 = V_7 ;
return V_7 ;
}
struct V_6 * F_140 ( struct V_13 * V_14 ,
struct V_59 * V_59 ,
T_6 V_224 )
{
struct V_6 * V_7 ;
V_7 = F_136 ( V_14 , V_224 ) ;
V_7 -> V_115 . V_495 = V_59 ;
F_99 ( V_64 , & V_7 -> V_65 ) ;
return V_7 ;
}
int F_141 ( struct V_13 * V_14 , struct V_70 * V_71 ,
struct V_26 * V_27 , T_6 V_224 )
{
enum V_175 V_180 = V_470 ;
struct V_6 * V_7 ;
unsigned long V_65 ;
int V_496 = 0 ;
V_7 = F_139 ( V_14 , V_27 , V_224 ) ;
V_180 = F_135 ( V_14 , V_7 , V_71 ) ;
if ( V_180 != V_185 ) {
F_89 ( & V_14 -> V_38 -> V_39 ,
L_54 ,
V_196 ,
V_180 ) ;
return V_180 ;
}
F_112 ( & V_14 -> V_497 , V_65 ) ;
if ( F_18 ( V_498 , & V_71 -> V_65 ) ) {
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
V_180 != V_284 ) {
F_89 ( & V_14 -> V_38 -> V_39 ,
L_55 ,
V_196 , V_180 ) ;
F_113 ( & V_14 -> V_497 , V_65 ) ;
return V_180 ;
}
F_104 ( & V_7 -> V_417 , & V_71 -> V_499 ) ;
if ( V_180 == V_185 ) {
F_138 ( V_7 , V_500 ) ;
} else {
F_99 ( V_458 , & V_7 -> V_65 ) ;
F_138 ( V_7 , V_444 ) ;
}
F_113 ( & V_14 -> V_497 , V_65 ) ;
if ( V_180 ==
V_284 ) {
F_112 ( & V_27 -> V_453 , V_65 ) ;
V_27 -> V_454 |= V_455 ;
F_113 ( & V_27 -> V_453 , V_65 ) ;
F_145 ( V_27 ) ;
V_180 = V_185 ;
}
return V_496 ;
}
