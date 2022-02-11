static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_4 [] = { ( ( V_3 >> 8 ) | 0x80 ) & 0xff , V_3 & 0xff } ;
T_2 V_5 [ 2 ] ;
struct V_6 V_7 [] = {
{ . V_8 = V_2 -> V_9 . V_10 , . V_11 = 0 , . V_12 = V_4 , . V_13 = 2 } ,
{ . V_8 = V_2 -> V_9 . V_10 , . V_11 = V_14 , . V_12 = V_5 , . V_13 = 2 } ,
} ;
if ( F_2 ( V_2 -> V_15 , V_7 , 2 ) != 2 )
F_3 ( L_1 ) ;
F_3 ( L_2 , V_3 , V_3 ,
( V_5 [ 0 ] << 8 ) | V_5 [ 1 ] , ( V_5 [ 0 ] << 8 ) | V_5 [ 1 ] ) ;
return ( V_5 [ 0 ] << 8 ) | V_5 [ 1 ] ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_16 )
{
T_2 V_17 [] = {
( V_3 >> 8 ) & 0xff , V_3 & 0xff ,
( V_16 >> 8 ) & 0xff , V_16 & 0xff ,
} ;
struct V_6 V_7 [] = {
{ . V_8 = V_2 -> V_9 . V_10 , . V_11 = 0 , . V_12 = V_17 , . V_13 = 4 }
} ;
F_3 ( L_3 , V_3 , V_3 , V_16 , V_16 ) ;
return F_2 ( V_2 -> V_15 , V_7 , 1 ) != 1 ? - V_18 : 0 ;
}
static int F_5 ( T_1 V_19 , T_1 V_20 )
{
if ( V_19 & 0x02 ) {
if ( V_20 & 0x01 ) {
F_6 ( L_4 ) ;
return 1 ;
} else {
F_6 ( L_5 ) ;
return 0 ;
}
} else if ( V_19 & 0x01 ) {
F_6 ( L_6 ) ;
return 0 ;
}
return - 1 ;
}
static int F_7 ( struct V_21 * V_22 , int V_23 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
struct V_25 * V_26 = & V_22 -> V_27 ;
enum V_28 V_29 = V_30 ;
int V_31 , V_32 ;
if ( V_23 && V_22 -> V_33 . V_34 . V_35 ) {
V_22 -> V_33 . V_34 . V_35 ( V_22 ) ;
if ( V_22 -> V_33 . V_36 ) V_22 -> V_33 . V_36 ( V_22 , 0 ) ;
switch ( V_26 -> V_37 ) {
case 8000000 :
F_8 ( V_38 , V_39 [ 2 ] ) ;
F_8 ( V_40 , V_41 ) ;
break;
case 7000000 :
F_8 ( V_38 , V_39 [ 1 ] ) ;
F_8 ( V_40 , V_42 ) ;
break;
case 6000000 :
F_8 ( V_38 , V_39 [ 0 ] ) ;
F_8 ( V_40 , V_43 ) ;
break;
case 0 :
return - V_44 ;
default:
F_9 ( L_7 ) ;
return - V_45 ;
}
F_10 ( L_8 , V_26 -> V_37 / 1000000 ) ;
}
F_11 ( V_46 , V_47 ) ;
switch ( V_26 -> V_48 ) {
case V_49 :
F_10 ( L_9 ) ;
F_11 ( V_50 , V_51 ) ;
break;
case V_52 :
F_10 ( L_10 ) ;
F_11 ( V_50 , V_53 ) ;
break;
case V_54 :
F_10 ( L_11 ) ;
break;
default:
return - V_45 ;
}
switch ( V_26 -> V_55 ) {
case V_56 :
F_10 ( L_12 ) ;
F_11 ( V_57 , V_58 ) ;
break;
case V_59 :
F_10 ( L_13 ) ;
F_11 ( V_57 , V_60 ) ;
break;
case V_61 :
F_10 ( L_14 ) ;
F_11 ( V_57 , V_62 ) ;
break;
case V_63 :
F_10 ( L_15 ) ;
F_11 ( V_57 , V_64 ) ;
break;
case V_65 :
F_10 ( L_16 ) ;
break;
default:
return - V_45 ;
}
switch ( V_26 -> V_66 ) {
case V_67 :
F_10 ( L_17 ) ;
F_11 ( V_68 , V_69 ) ;
break;
case V_70 :
F_10 ( L_18 ) ;
break;
case V_71 :
F_10 ( L_19 ) ;
F_11 ( V_68 , V_72 ) ;
break;
default:
return - V_45 ;
}
switch ( V_26 -> V_73 ) {
case V_74 :
F_10 ( L_20 ) ;
F_11 ( V_75 , V_76 ) ;
break;
case V_77 :
F_10 ( L_21 ) ;
F_11 ( V_75 , V_78 ) ;
break;
case V_79 :
F_10 ( L_22 ) ;
F_11 ( V_75 , V_80 ) ;
break;
case V_81 :
break;
default:
return - V_45 ;
}
switch ( V_26 -> V_82 ) {
case V_83 :
F_10 ( L_23 ) ;
case V_84 :
F_10 ( L_24 ) ;
F_11 ( V_85 , V_86 ) ;
break;
case V_87 :
F_10 ( L_25 ) ;
F_11 ( V_85 , V_88 ) ;
break;
case V_89 :
F_10 ( L_26 ) ;
F_11 ( V_85 , V_90 ) ;
break;
case V_91 :
F_10 ( L_27 ) ;
break;
default:
return - V_45 ;
}
if ( V_26 -> V_82 == V_83 ) {
F_11 ( V_92 , V_93 ) ;
F_11 ( V_94 , V_95 ) ;
V_29 = V_26 -> V_96 ;
} else if ( V_26 -> V_82 != V_91 ) {
F_11 ( V_92 , V_97 ) ;
F_11 ( V_94 , V_98 ) ;
V_29 = V_26 -> V_99 ;
}
switch ( V_29 ) {
case V_100 :
F_10 ( L_28 ) ;
F_11 ( V_101 , V_102 ) ;
break;
case V_103 :
F_10 ( L_29 ) ;
F_11 ( V_101 , V_104 ) ;
break;
case V_105 :
F_10 ( L_30 ) ;
F_11 ( V_101 , V_106 ) ;
break;
case V_107 :
F_10 ( L_31 ) ;
F_11 ( V_101 , V_108 ) ;
break;
case V_109 :
F_10 ( L_32 ) ;
F_11 ( V_101 , V_110 ) ;
break;
case V_30 :
F_10 ( L_33 ) ;
break;
case V_111 :
F_10 ( L_34 ) ;
break;
default:
return - V_45 ;
}
V_32 = V_112
[ V_26 -> V_48 == V_54 ]
[ V_26 -> V_55 == V_65 ]
[ V_26 -> V_66 == V_70 ] ;
F_10 ( L_35 , V_32 ) ;
F_11 ( V_113 , V_32 ) ;
F_11 ( V_114 , V_32 ? V_115 : V_116 ) ;
if ( V_26 -> V_48 == V_49 ) {
if ( V_26 -> V_55 == V_61 ) {
F_11 ( V_117 , V_118 ) ;
} else {
F_11 ( V_117 , V_119 ) ;
}
F_11 ( V_120 , V_121 ) ;
} else {
F_11 ( V_120 , V_122 ) ;
}
F_11 ( V_123 , V_124 ) ;
F_11 ( V_125 , V_126 ) ;
F_11 ( V_127 , V_128 ) ;
F_8 ( V_129 , V_130 ) ;
F_11 ( V_114 , V_116 ) ;
F_11 ( V_131 , V_132 + V_133 ) ;
F_11 ( V_131 , V_134 ) ;
F_12 ( 70 ) ;
F_8 ( V_129 , V_135 ) ;
if ( V_26 -> V_73 == V_81 ||
V_26 -> V_82 == V_91 ||
V_29 == V_111 ||
V_26 -> V_66 == V_70 ) {
int V_136 = 0 ;
F_10 ( L_36 ) ;
F_11 ( V_114 , V_115 ) ;
F_11 ( V_131 , V_137 ) ;
F_11 ( V_131 , V_134 ) ;
while ( ( V_31 =
F_5 (
F_13 ( V_138 ) ,
F_13 ( V_139 ) ) ) < 0 && V_136 ++ < 100 )
F_12 ( 1 ) ;
F_10 ( L_37 ,
V_31 , V_136 ) ;
if ( V_31 == 1 ) {
if ( F_14 ( V_22 , V_26 ) == 0 ) {
F_10 ( L_38 ) ;
return F_7 ( V_22 , 0 ) ;
}
}
} else {
F_11 ( V_131 , V_133 ) ;
F_11 ( V_131 , V_134 ) ;
}
return 0 ;
}
static int F_15 ( struct V_21 * V_22 , int V_140 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
F_16 ( L_39 ) ;
F_11 ( V_141 , V_142 ) ;
F_11 ( V_131 , V_132 ) ;
F_11 ( V_143 , V_144 ) ;
F_11 ( V_143 , V_145 ) ;
F_11 ( V_146 , V_147 ) ;
F_11 ( V_148 , V_149 ) ;
F_11 ( V_150 , V_151 ) ;
F_11 ( V_152 , V_153 ) ;
F_8 ( V_38 , V_39 [ 2 ] ) ;
F_8 ( V_154 ,
V_155 [ V_156 ] ) ;
F_8 ( V_157 , V_158 ) ;
F_11 ( V_159 , V_160 ) ;
F_8 ( V_161 , V_162 ) ;
F_8 ( V_163 , V_164 ) ;
F_8 ( V_129 , V_135 ) ;
F_11 ( V_165 , V_166 ) ;
F_11 ( V_46 , V_47 ) ;
F_11 ( V_167 , V_168 ) ;
F_11 ( V_113 , V_112 [ 1 ] [ 1 ] [ 1 ] ) ;
F_8 ( V_40 , V_41 ) ;
F_11 ( V_169 , V_170 ) ;
F_11 ( V_171 , V_172 ) ;
F_11 ( V_173 , V_174 ) ;
F_11 ( V_175 , V_176 ) ;
F_11 ( V_177 , V_178 ) ;
F_11 ( V_114 , V_115 ) ;
F_11 ( V_179 , V_180 ) ;
F_11 ( V_181 , V_182 ) ;
F_11 ( V_183 , V_184 ) ;
F_11 ( V_185 , V_186 ) ;
F_11 ( V_187 , V_188 ) ;
F_11 ( V_189 , V_190 ) ;
F_11 ( V_191 , V_192 ) ;
F_11 ( V_125 , V_126 ) ;
F_11 ( V_193 , V_194 ) ;
F_8 ( V_195 , V_196 ) ;
F_11 ( V_123 , V_197 ) ;
F_11 ( V_198 , V_199 ) ;
F_11 ( V_200 , V_201 ) ;
F_11 ( V_202 , V_203 ) ;
F_11 ( V_204 , V_205 ) ;
F_11 ( V_206 , V_207 ) ;
F_11 ( V_208 , V_209 ) ;
F_11 ( V_210 , V_211 ) ;
F_11 ( V_212 , V_213 ) ;
F_11 ( V_214 , V_215 ) ;
F_11 ( V_216 , V_217 ) ;
return 0 ;
}
static int F_14 ( struct V_21 * V_22 ,
struct V_25 * V_26 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
enum V_28 * V_218 ;
T_1 V_219 ;
int V_220 , V_221 ;
T_3 V_222 , V_223 = 0x800000 ;
if ( ! F_13 ( V_224 ) )
return 0 ;
V_222 = ( ( F_13 ( V_225 ) & 0xff ) << 16 ) + F_13 ( V_226 ) ;
F_17 ( L_40 , V_222 , F_13 ( V_225 ) , F_13 ( V_226 ) ) ;
if ( V_222 < V_223 )
V_220 = 0 ;
else if ( V_222 == V_223 )
V_220 = 1 ;
else
V_220 = 2 ;
V_222 = ( ( F_13 ( V_150 ) & 0xff ) << 16 ) + F_13 ( V_152 ) ;
F_17 ( L_41 , V_222 , F_13 ( V_150 ) , F_13 ( V_152 ) ) ;
if ( V_222 < V_223 )
V_221 = 0 ;
else if ( V_222 == V_223 )
V_221 = 1 ;
else
V_221 = 2 ;
V_26 -> V_66 =
( ( V_221 == 2 ) && ( V_220 == 1 || V_220 == 0 ) ) ||
( ( V_221 == 0 ) && ( V_220 == 1 || V_220 == 2 ) ) ?
V_71 : V_67 ;
F_17 ( L_42 , V_221 , V_220 , V_26 -> V_66 ) ;
switch ( ( V_219 = F_13 ( V_227 ) ) ) {
case V_76 :
F_17 ( L_43 ) ;
V_26 -> V_73 = V_74 ;
break;
case V_78 :
F_17 ( L_44 ) ;
V_26 -> V_73 = V_77 ;
break;
case V_80 :
F_17 ( L_45 ) ;
V_26 -> V_73 = V_79 ;
break;
default:
F_9 ( L_46 , V_219 ) ;
break;
}
F_17 ( L_47 , V_219 ) ;
if ( F_13 ( V_228 ) ) {
F_17 ( L_48 ) ;
V_218 = & V_26 -> V_99 ;
V_26 -> V_96 = V_30 ;
switch ( ( V_219 = F_13 ( V_229 ) ) ) {
case V_230 :
F_17 ( L_49 ) ;
V_26 -> V_82 = V_83 ;
break;
case V_86 :
F_17 ( L_50 ) ;
V_26 -> V_82 = V_84 ;
break;
case V_88 :
F_17 ( L_51 ) ;
V_26 -> V_82 = V_87 ;
break;
case V_90 :
F_17 ( L_52 ) ;
V_26 -> V_82 = V_89 ;
break;
default:
F_9 ( L_53 , V_219 ) ;
break;
}
F_17 ( L_47 , V_219 ) ;
V_219 = F_13 ( V_231 ) ;
} else {
F_17 ( L_54 ) ;
V_218 = & V_26 -> V_96 ;
V_26 -> V_99 = V_30 ;
V_26 -> V_82 = V_83 ;
V_219 = F_13 ( V_232 ) ;
}
switch ( V_219 ) {
case V_102 :
F_17 ( L_55 ) ;
* V_218 = V_100 ;
break;
case V_104 :
F_17 ( L_56 ) ;
* V_218 = V_103 ;
break;
case V_106 :
F_17 ( L_57 ) ;
* V_218 = V_105 ;
break;
case V_108 :
F_17 ( L_58 ) ;
* V_218 = V_233 ;
break;
case V_110 :
F_17 ( L_59 ) ;
* V_218 = V_109 ;
break;
default:
F_9 ( L_60 , V_219 ) ;
break;
}
F_17 ( L_47 , V_219 ) ;
switch ( ( V_219 = F_13 ( V_234 ) ) ) {
case V_58 :
F_17 ( L_61 ) ;
V_26 -> V_55 = V_56 ;
break;
case V_60 :
F_17 ( L_62 ) ;
V_26 -> V_55 = V_59 ;
break;
case V_62 :
F_17 ( L_63 ) ;
V_26 -> V_55 = V_61 ;
break;
case V_64 :
F_17 ( L_64 ) ;
V_26 -> V_55 = V_63 ;
break;
default:
F_9 ( L_65 , V_219 ) ;
break;
}
F_17 ( L_47 , V_219 ) ;
switch ( ( V_219 = F_13 ( V_235 ) ) ) {
case V_51 :
F_17 ( L_66 ) ;
V_26 -> V_48 = V_49 ;
break;
case V_53 :
F_17 ( L_67 ) ;
V_26 -> V_48 = V_52 ;
break;
default:
F_9 ( L_68 , V_219 ) ;
break;
}
F_17 ( L_47 , V_219 ) ;
return 0 ;
}
static int F_18 ( struct V_21 * V_22 ,
enum V_236 * V_237 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
* V_237 = 0 ;
if ( F_13 ( V_238 ) )
* V_237 |= V_239 ;
if ( F_13 ( V_240 ) )
* V_237 |= V_241 ;
if ( F_13 ( V_242 ) )
* V_237 |= V_243 ;
if ( F_13 ( V_244 ) )
* V_237 |= ( V_245 | V_246 ) ;
F_17 ( L_69 , * V_237 ) ;
F_17 ( L_70 ,
F_13 ( V_224 ) ,
F_13 ( V_227 ) ,
F_13 ( V_228 ) ,
F_13 ( V_229 ) ,
F_13 ( V_232 ) ,
F_13 ( V_231 ) ,
F_13 ( V_234 ) ,
F_13 ( V_235 ) ,
F_13 ( V_247 ) ) ;
return 0 ;
}
static int F_19 ( struct V_21 * V_22 , T_3 * V_248 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
* V_248 = ( ( F_13 ( V_249 ) << 16 ) | F_13 ( V_250 ) ) ;
return 0 ;
}
static int F_20 ( struct V_21 * V_22 , T_1 * V_251 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
* V_251 = F_13 ( V_252 ) * 0xffff / 0x170 ;
return 0 ;
}
static int F_21 ( struct V_21 * V_22 , T_1 * V_253 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
short V_254 = F_13 ( V_252 ) ;
int V_255 = ( ( F_13 ( V_256 ) & 0xff ) << 16 ) |
F_13 ( V_257 ) ;
* V_253 = ( V_254 << 8 ) / ( ( V_255 > 0 ) ? V_255 : 1 ) ;
return 0 ;
}
static int F_22 ( struct V_21 * V_22 , T_3 * V_258 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
* V_258 = F_13 ( V_259 ) ;
return 0 ;
}
static int F_23 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
F_16 ( L_71 ) ;
F_11 ( V_141 , V_260 ) ;
return 0 ;
}
static int F_24 ( struct V_21 * V_22 , struct V_261 * V_262 )
{
V_262 -> V_263 = 800 ;
return 0 ;
}
static int F_25 ( struct V_21 * V_22 )
{
return F_15 ( V_22 , 0 ) ;
}
static int F_26 ( struct V_21 * V_22 )
{
return F_7 ( V_22 , 1 ) ;
}
static void F_27 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
F_28 ( V_2 ) ;
}
static int F_29 ( struct V_21 * V_22 , int V_264 , int V_265 , int V_266 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
V_265 = ( V_266 ? V_265 | V_267 : 0 ) ;
F_11 ( V_264 + V_268 , V_265 ) ;
return 0 ;
}
static int F_30 ( struct V_21 * V_22 , int V_266 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
F_31 ( L_72 , V_266 ? L_73 : L_74 ) ;
if ( V_266 ) {
F_11 ( V_210 , V_269 ) ;
} else {
F_11 ( V_210 , V_211 ) ;
}
return 0 ;
}
static int F_32 ( struct V_21 * V_22 , int V_266 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
F_31 ( L_75 , V_266 ? L_73 : L_74 ) ;
F_11 ( V_208 , V_266 ) ;
return 0 ;
}
static int F_33 ( struct V_21 * V_22 , int V_266 , T_2 V_270 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
if ( V_266 ) {
F_11 ( V_271 , F_34 ( V_270 ) ) ;
} else {
F_11 ( V_271 , F_35 ( V_270 ) ) ;
}
return 0 ;
}
struct V_21 * F_36 ( const struct V_272 * V_9 ,
struct V_273 * V_15 , struct V_274 * V_275 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_37 ( sizeof( struct V_1 ) , V_276 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_15 = V_15 ;
memcpy ( & V_2 -> V_9 , V_9 , sizeof( struct V_272 ) ) ;
if ( F_13 ( V_277 ) != V_278 )
goto error;
if ( F_13 ( V_279 ) != V_280 )
goto error;
memcpy ( & V_2 -> V_281 . V_33 , & V_282 , sizeof( struct V_283 ) ) ;
V_2 -> V_281 . V_24 = V_2 ;
V_275 -> V_284 = F_32 ;
V_275 -> V_285 = F_30 ;
V_275 -> V_286 = F_29 ;
V_275 -> V_287 = F_33 ;
return & V_2 -> V_281 ;
error:
F_28 ( V_2 ) ;
return NULL ;
}
