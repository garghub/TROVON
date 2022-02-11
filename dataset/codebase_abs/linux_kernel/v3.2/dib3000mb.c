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
static int F_7 ( struct V_21 * V_22 ,
struct V_23 * V_24 , int V_25 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
struct V_27 * V_28 = & V_24 -> V_29 . V_28 ;
T_3 V_30 = V_31 ;
int V_32 , V_33 ;
if ( V_25 && V_22 -> V_34 . V_35 . V_36 ) {
V_22 -> V_34 . V_35 . V_36 ( V_22 , V_24 ) ;
if ( V_22 -> V_34 . V_37 ) V_22 -> V_34 . V_37 ( V_22 , 0 ) ;
F_8 ( L_7 ) ;
switch ( V_28 -> V_38 ) {
case V_39 :
F_8 ( L_8 ) ;
F_9 ( V_40 , V_41 [ 2 ] ) ;
F_9 ( V_42 , V_43 ) ;
break;
case V_44 :
F_8 ( L_9 ) ;
F_9 ( V_40 , V_41 [ 1 ] ) ;
F_9 ( V_42 , V_45 ) ;
break;
case V_46 :
F_8 ( L_10 ) ;
F_9 ( V_40 , V_41 [ 0 ] ) ;
F_9 ( V_42 , V_47 ) ;
break;
case V_48 :
return - V_49 ;
default:
F_10 ( L_11 ) ;
return - V_50 ;
}
}
F_11 ( V_51 , V_52 ) ;
F_8 ( L_12 ) ;
switch ( V_28 -> V_53 ) {
case V_54 :
F_8 ( L_13 ) ;
F_11 ( V_55 , V_56 ) ;
break;
case V_57 :
F_8 ( L_14 ) ;
F_11 ( V_55 , V_58 ) ;
break;
case V_59 :
F_8 ( L_15 ) ;
break;
default:
return - V_50 ;
}
F_8 ( L_16 ) ;
switch ( V_28 -> V_60 ) {
case V_61 :
F_8 ( L_17 ) ;
F_11 ( V_62 , V_63 ) ;
break;
case V_64 :
F_8 ( L_18 ) ;
F_11 ( V_62 , V_65 ) ;
break;
case V_66 :
F_8 ( L_19 ) ;
F_11 ( V_62 , V_67 ) ;
break;
case V_68 :
F_8 ( L_20 ) ;
F_11 ( V_62 , V_69 ) ;
break;
case V_70 :
F_8 ( L_15 ) ;
break;
default:
return - V_50 ;
}
F_8 ( L_21 ) ;
switch ( V_24 -> V_71 ) {
case V_72 :
F_8 ( L_22 ) ;
F_11 ( V_73 , V_74 ) ;
break;
case V_75 :
F_8 ( L_23 ) ;
break;
case V_76 :
F_8 ( L_24 ) ;
F_11 ( V_73 , V_77 ) ;
break;
default:
return - V_50 ;
}
F_8 ( L_25 ) ;
switch ( V_28 -> V_78 ) {
case V_79 :
F_8 ( L_26 ) ;
F_11 ( V_80 , V_81 ) ;
break;
case V_82 :
F_8 ( L_27 ) ;
F_11 ( V_80 , V_83 ) ;
break;
case V_84 :
F_8 ( L_28 ) ;
F_11 ( V_80 , V_85 ) ;
break;
case V_86 :
break;
default:
return - V_50 ;
}
F_8 ( L_29 ) ;
switch ( V_28 -> V_87 ) {
case V_88 :
F_8 ( L_30 ) ;
case V_89 :
F_8 ( L_31 ) ;
F_11 ( V_90 , V_91 ) ;
break;
case V_92 :
F_8 ( L_32 ) ;
F_11 ( V_90 , V_93 ) ;
break;
case V_94 :
F_8 ( L_33 ) ;
F_11 ( V_90 , V_95 ) ;
break;
case V_96 :
F_8 ( L_34 ) ;
break;
default:
return - V_50 ;
}
F_8 ( L_29 ) ;
if ( V_28 -> V_87 == V_88 ) {
F_8 ( L_35 ) ;
F_11 ( V_97 , V_98 ) ;
F_11 ( V_99 , V_100 ) ;
V_30 = V_28 -> V_101 ;
} else if ( V_28 -> V_87 != V_96 ) {
F_8 ( L_24 ) ;
F_11 ( V_97 , V_102 ) ;
F_11 ( V_99 , V_103 ) ;
V_30 = V_28 -> V_104 ;
}
F_8 ( L_36 ) ;
switch ( V_30 ) {
case V_105 :
F_8 ( L_37 ) ;
F_11 ( V_106 , V_107 ) ;
break;
case V_108 :
F_8 ( L_38 ) ;
F_11 ( V_106 , V_109 ) ;
break;
case V_110 :
F_8 ( L_39 ) ;
F_11 ( V_106 , V_111 ) ;
break;
case V_112 :
F_8 ( L_40 ) ;
F_11 ( V_106 , V_113 ) ;
break;
case V_114 :
F_8 ( L_41 ) ;
F_11 ( V_106 , V_115 ) ;
break;
case V_31 :
F_8 ( L_30 ) ;
break;
case V_116 :
F_8 ( L_15 ) ;
break;
default:
return - V_50 ;
}
V_33 = V_117
[ V_28 -> V_53 == V_59 ]
[ V_28 -> V_60 == V_70 ]
[ V_24 -> V_71 == V_75 ] ;
F_8 ( L_42 , V_33 ) ;
F_11 ( V_118 , V_33 ) ;
F_11 ( V_119 , V_33 ? V_120 : V_121 ) ;
if ( V_28 -> V_53 == V_54 ) {
if ( V_28 -> V_60 == V_66 ) {
F_11 ( V_122 , V_123 ) ;
} else {
F_11 ( V_122 , V_124 ) ;
}
F_11 ( V_125 , V_126 ) ;
} else {
F_11 ( V_125 , V_127 ) ;
}
F_11 ( V_128 , V_129 ) ;
F_11 ( V_130 , V_131 ) ;
F_11 ( V_132 , V_133 ) ;
F_9 ( V_134 , V_135 ) ;
F_11 ( V_119 , V_121 ) ;
F_11 ( V_136 , V_137 + V_138 ) ;
F_11 ( V_136 , V_139 ) ;
F_12 ( 70 ) ;
F_9 ( V_134 , V_140 ) ;
if ( V_28 -> V_78 == V_86 ||
V_28 -> V_87 == V_96 ||
V_30 == V_116 ||
V_24 -> V_71 == V_75 ) {
int V_141 = 0 ;
F_8 ( L_43 ) ;
F_11 ( V_119 , V_120 ) ;
F_11 ( V_136 , V_142 ) ;
F_11 ( V_136 , V_139 ) ;
while ( ( V_32 =
F_5 (
F_13 ( V_143 ) ,
F_13 ( V_144 ) ) ) < 0 && V_141 ++ < 100 )
F_12 ( 1 ) ;
F_8 ( L_44 , V_32 , V_141 ) ;
if ( V_32 == 1 ) {
struct V_23 V_145 ;
if ( F_14 ( V_22 , & V_145 ) == 0 ) {
F_8 ( L_45 ) ;
return F_7 ( V_22 , & V_145 , 0 ) ;
}
}
} else {
F_11 ( V_136 , V_138 ) ;
F_11 ( V_136 , V_139 ) ;
}
return 0 ;
}
static int F_15 ( struct V_21 * V_22 , int V_146 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
F_16 ( L_46 ) ;
F_11 ( V_147 , V_148 ) ;
F_11 ( V_136 , V_137 ) ;
F_11 ( V_149 , V_150 ) ;
F_11 ( V_149 , V_151 ) ;
F_11 ( V_152 , V_153 ) ;
F_11 ( V_154 , V_155 ) ;
F_11 ( V_156 , V_157 ) ;
F_11 ( V_158 , V_159 ) ;
F_9 ( V_40 , V_41 [ 2 ] ) ;
F_9 ( V_160 ,
V_161 [ V_162 ] ) ;
F_9 ( V_163 , V_164 ) ;
F_11 ( V_165 , V_166 ) ;
F_9 ( V_167 , V_168 ) ;
F_9 ( V_169 , V_170 ) ;
F_9 ( V_134 , V_140 ) ;
F_11 ( V_171 , V_172 ) ;
F_11 ( V_51 , V_52 ) ;
F_11 ( V_173 , V_174 ) ;
F_11 ( V_118 , V_117 [ 1 ] [ 1 ] [ 1 ] ) ;
F_9 ( V_42 , V_43 ) ;
F_11 ( V_175 , V_176 ) ;
F_11 ( V_177 , V_178 ) ;
F_11 ( V_179 , V_180 ) ;
F_11 ( V_181 , V_182 ) ;
F_11 ( V_183 , V_184 ) ;
F_11 ( V_119 , V_120 ) ;
F_11 ( V_185 , V_186 ) ;
F_11 ( V_187 , V_188 ) ;
F_11 ( V_189 , V_190 ) ;
F_11 ( V_191 , V_192 ) ;
F_11 ( V_193 , V_194 ) ;
F_11 ( V_195 , V_196 ) ;
F_11 ( V_197 , V_198 ) ;
F_11 ( V_130 , V_131 ) ;
F_11 ( V_199 , V_200 ) ;
F_9 ( V_201 , V_202 ) ;
F_11 ( V_128 , V_203 ) ;
F_11 ( V_204 , V_205 ) ;
F_11 ( V_206 , V_207 ) ;
F_11 ( V_208 , V_209 ) ;
F_11 ( V_210 , V_211 ) ;
F_11 ( V_212 , V_213 ) ;
F_11 ( V_214 , V_215 ) ;
F_11 ( V_216 , V_217 ) ;
F_11 ( V_218 , V_219 ) ;
F_11 ( V_220 , V_221 ) ;
F_11 ( V_222 , V_223 ) ;
return 0 ;
}
static int F_14 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
struct V_27 * V_28 = & V_24 -> V_29 . V_28 ;
T_3 * V_224 ;
T_1 V_225 ;
int V_226 , V_227 ;
T_4 V_228 , V_229 = 0x800000 ;
if ( ! F_13 ( V_230 ) )
return 0 ;
V_228 = ( ( F_13 ( V_231 ) & 0xff ) << 16 ) + F_13 ( V_232 ) ;
F_17 ( L_47 , V_228 , F_13 ( V_231 ) , F_13 ( V_232 ) ) ;
if ( V_228 < V_229 )
V_226 = 0 ;
else if ( V_228 == V_229 )
V_226 = 1 ;
else
V_226 = 2 ;
V_228 = ( ( F_13 ( V_156 ) & 0xff ) << 16 ) + F_13 ( V_158 ) ;
F_17 ( L_48 , V_228 , F_13 ( V_156 ) , F_13 ( V_158 ) ) ;
if ( V_228 < V_229 )
V_227 = 0 ;
else if ( V_228 == V_229 )
V_227 = 1 ;
else
V_227 = 2 ;
V_24 -> V_71 =
( ( V_227 == 2 ) && ( V_226 == 1 || V_226 == 0 ) ) ||
( ( V_227 == 0 ) && ( V_226 == 1 || V_226 == 2 ) ) ?
V_76 : V_72 ;
F_17 ( L_49 , V_227 , V_226 , V_24 -> V_71 ) ;
switch ( ( V_225 = F_13 ( V_233 ) ) ) {
case V_81 :
F_17 ( L_50 ) ;
V_28 -> V_78 = V_79 ;
break;
case V_83 :
F_17 ( L_51 ) ;
V_28 -> V_78 = V_82 ;
break;
case V_85 :
F_17 ( L_52 ) ;
V_28 -> V_78 = V_84 ;
break;
default:
F_10 ( L_53 , V_225 ) ;
break;
}
F_17 ( L_54 , V_225 ) ;
if ( F_13 ( V_234 ) ) {
F_17 ( L_55 ) ;
V_224 = & V_28 -> V_104 ;
V_28 -> V_101 = V_31 ;
switch ( ( V_225 = F_13 ( V_235 ) ) ) {
case V_236 :
F_17 ( L_56 ) ;
V_28 -> V_87 = V_88 ;
break;
case V_91 :
F_17 ( L_57 ) ;
V_28 -> V_87 = V_89 ;
break;
case V_93 :
F_17 ( L_58 ) ;
V_28 -> V_87 = V_92 ;
break;
case V_95 :
F_17 ( L_59 ) ;
V_28 -> V_87 = V_94 ;
break;
default:
F_10 ( L_60 , V_225 ) ;
break;
}
F_17 ( L_54 , V_225 ) ;
V_225 = F_13 ( V_237 ) ;
} else {
F_17 ( L_61 ) ;
V_224 = & V_28 -> V_101 ;
V_28 -> V_104 = V_31 ;
V_28 -> V_87 = V_88 ;
V_225 = F_13 ( V_238 ) ;
}
switch ( V_225 ) {
case V_107 :
F_17 ( L_62 ) ;
* V_224 = V_105 ;
break;
case V_109 :
F_17 ( L_63 ) ;
* V_224 = V_108 ;
break;
case V_111 :
F_17 ( L_64 ) ;
* V_224 = V_110 ;
break;
case V_113 :
F_17 ( L_65 ) ;
* V_224 = V_239 ;
break;
case V_115 :
F_17 ( L_66 ) ;
* V_224 = V_114 ;
break;
default:
F_10 ( L_67 , V_225 ) ;
break;
}
F_17 ( L_54 , V_225 ) ;
switch ( ( V_225 = F_13 ( V_240 ) ) ) {
case V_63 :
F_17 ( L_68 ) ;
V_28 -> V_60 = V_61 ;
break;
case V_65 :
F_17 ( L_69 ) ;
V_28 -> V_60 = V_64 ;
break;
case V_67 :
F_17 ( L_70 ) ;
V_28 -> V_60 = V_66 ;
break;
case V_69 :
F_17 ( L_71 ) ;
V_28 -> V_60 = V_68 ;
break;
default:
F_10 ( L_72 , V_225 ) ;
break;
}
F_17 ( L_54 , V_225 ) ;
switch ( ( V_225 = F_13 ( V_241 ) ) ) {
case V_56 :
F_17 ( L_73 ) ;
V_28 -> V_53 = V_54 ;
break;
case V_58 :
F_17 ( L_74 ) ;
V_28 -> V_53 = V_57 ;
break;
default:
F_10 ( L_75 , V_225 ) ;
break;
}
F_17 ( L_54 , V_225 ) ;
return 0 ;
}
static int F_18 ( struct V_21 * V_22 , T_5 * V_242 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
* V_242 = 0 ;
if ( F_13 ( V_243 ) )
* V_242 |= V_244 ;
if ( F_13 ( V_245 ) )
* V_242 |= V_246 ;
if ( F_13 ( V_247 ) )
* V_242 |= V_248 ;
if ( F_13 ( V_249 ) )
* V_242 |= ( V_250 | V_251 ) ;
F_17 ( L_76 , * V_242 ) ;
F_17 ( L_77 ,
F_13 ( V_230 ) ,
F_13 ( V_233 ) ,
F_13 ( V_234 ) ,
F_13 ( V_235 ) ,
F_13 ( V_238 ) ,
F_13 ( V_237 ) ,
F_13 ( V_240 ) ,
F_13 ( V_241 ) ,
F_13 ( V_252 ) ) ;
return 0 ;
}
static int F_19 ( struct V_21 * V_22 , T_4 * V_253 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
* V_253 = ( ( F_13 ( V_254 ) << 16 ) | F_13 ( V_255 ) ) ;
return 0 ;
}
static int F_20 ( struct V_21 * V_22 , T_1 * V_256 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
* V_256 = F_13 ( V_257 ) * 0xffff / 0x170 ;
return 0 ;
}
static int F_21 ( struct V_21 * V_22 , T_1 * V_258 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
short V_259 = F_13 ( V_257 ) ;
int V_260 = ( ( F_13 ( V_261 ) & 0xff ) << 16 ) |
F_13 ( V_262 ) ;
* V_258 = ( V_259 << 8 ) / ( ( V_260 > 0 ) ? V_260 : 1 ) ;
return 0 ;
}
static int F_22 ( struct V_21 * V_22 , T_4 * V_263 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
* V_263 = F_13 ( V_264 ) ;
return 0 ;
}
static int F_23 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
F_16 ( L_78 ) ;
F_11 ( V_147 , V_265 ) ;
return 0 ;
}
static int F_24 ( struct V_21 * V_22 , struct V_266 * V_267 )
{
V_267 -> V_268 = 800 ;
return 0 ;
}
static int F_25 ( struct V_21 * V_22 )
{
return F_15 ( V_22 , 0 ) ;
}
static int F_26 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
return F_7 ( V_22 , V_24 , 1 ) ;
}
static void F_27 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
F_28 ( V_2 ) ;
}
static int F_29 ( struct V_21 * V_22 , int V_269 , int V_270 , int V_271 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
V_270 = ( V_271 ? V_270 | V_272 : 0 ) ;
F_11 ( V_269 + V_273 , V_270 ) ;
return 0 ;
}
static int F_30 ( struct V_21 * V_22 , int V_271 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
F_31 ( L_79 , V_271 ? L_80 : L_81 ) ;
if ( V_271 ) {
F_11 ( V_216 , V_274 ) ;
} else {
F_11 ( V_216 , V_217 ) ;
}
return 0 ;
}
static int F_32 ( struct V_21 * V_22 , int V_271 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
F_31 ( L_82 , V_271 ? L_80 : L_81 ) ;
F_11 ( V_214 , V_271 ) ;
return 0 ;
}
static int F_33 ( struct V_21 * V_22 , int V_271 , T_2 V_275 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
if ( V_271 ) {
F_11 ( V_276 , F_34 ( V_275 ) ) ;
} else {
F_11 ( V_276 , F_35 ( V_275 ) ) ;
}
return 0 ;
}
struct V_21 * F_36 ( const struct V_277 * V_9 ,
struct V_278 * V_15 , struct V_279 * V_280 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_37 ( sizeof( struct V_1 ) , V_281 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_15 = V_15 ;
memcpy ( & V_2 -> V_9 , V_9 , sizeof( struct V_277 ) ) ;
if ( F_13 ( V_282 ) != V_283 )
goto error;
if ( F_13 ( V_284 ) != V_285 )
goto error;
memcpy ( & V_2 -> V_286 . V_34 , & V_287 , sizeof( struct V_288 ) ) ;
V_2 -> V_286 . V_26 = V_2 ;
V_280 -> V_289 = F_32 ;
V_280 -> V_290 = F_30 ;
V_280 -> V_291 = F_29 ;
V_280 -> V_292 = F_33 ;
return & V_2 -> V_286 ;
error:
F_28 ( V_2 ) ;
return NULL ;
}
