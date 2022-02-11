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
T_3 V_28 = V_29 ;
int V_30 , V_31 ;
if ( V_23 && V_22 -> V_32 . V_33 . V_34 ) {
V_22 -> V_32 . V_33 . V_34 ( V_22 ) ;
if ( V_22 -> V_32 . V_35 ) V_22 -> V_32 . V_35 ( V_22 , 0 ) ;
F_8 ( L_7 ) ;
switch ( V_26 -> V_36 ) {
case 8000000 :
F_8 ( L_8 ) ;
F_9 ( V_37 , V_38 [ 2 ] ) ;
F_9 ( V_39 , V_40 ) ;
break;
case 7000000 :
F_8 ( L_9 ) ;
F_9 ( V_37 , V_38 [ 1 ] ) ;
F_9 ( V_39 , V_41 ) ;
break;
case 6000000 :
F_8 ( L_10 ) ;
F_9 ( V_37 , V_38 [ 0 ] ) ;
F_9 ( V_39 , V_42 ) ;
break;
case 0 :
return - V_43 ;
default:
F_10 ( L_11 ) ;
return - V_44 ;
}
}
F_11 ( V_45 , V_46 ) ;
F_8 ( L_12 ) ;
switch ( V_26 -> V_47 ) {
case V_48 :
F_8 ( L_13 ) ;
F_11 ( V_49 , V_50 ) ;
break;
case V_51 :
F_8 ( L_14 ) ;
F_11 ( V_49 , V_52 ) ;
break;
case V_53 :
F_8 ( L_15 ) ;
break;
default:
return - V_44 ;
}
F_8 ( L_16 ) ;
switch ( V_26 -> V_54 ) {
case V_55 :
F_8 ( L_17 ) ;
F_11 ( V_56 , V_57 ) ;
break;
case V_58 :
F_8 ( L_18 ) ;
F_11 ( V_56 , V_59 ) ;
break;
case V_60 :
F_8 ( L_19 ) ;
F_11 ( V_56 , V_61 ) ;
break;
case V_62 :
F_8 ( L_20 ) ;
F_11 ( V_56 , V_63 ) ;
break;
case V_64 :
F_8 ( L_15 ) ;
break;
default:
return - V_44 ;
}
F_8 ( L_21 ) ;
switch ( V_26 -> V_65 ) {
case V_66 :
F_8 ( L_22 ) ;
F_11 ( V_67 , V_68 ) ;
break;
case V_69 :
F_8 ( L_23 ) ;
break;
case V_70 :
F_8 ( L_24 ) ;
F_11 ( V_67 , V_71 ) ;
break;
default:
return - V_44 ;
}
F_8 ( L_25 ) ;
switch ( V_26 -> V_72 ) {
case V_73 :
F_8 ( L_26 ) ;
F_11 ( V_74 , V_75 ) ;
break;
case V_76 :
F_8 ( L_27 ) ;
F_11 ( V_74 , V_77 ) ;
break;
case V_78 :
F_8 ( L_28 ) ;
F_11 ( V_74 , V_79 ) ;
break;
case V_80 :
break;
default:
return - V_44 ;
}
F_8 ( L_29 ) ;
switch ( V_26 -> V_81 ) {
case V_82 :
F_8 ( L_30 ) ;
case V_83 :
F_8 ( L_31 ) ;
F_11 ( V_84 , V_85 ) ;
break;
case V_86 :
F_8 ( L_32 ) ;
F_11 ( V_84 , V_87 ) ;
break;
case V_88 :
F_8 ( L_33 ) ;
F_11 ( V_84 , V_89 ) ;
break;
case V_90 :
F_8 ( L_34 ) ;
break;
default:
return - V_44 ;
}
F_8 ( L_29 ) ;
if ( V_26 -> V_81 == V_82 ) {
F_8 ( L_35 ) ;
F_11 ( V_91 , V_92 ) ;
F_11 ( V_93 , V_94 ) ;
V_28 = V_26 -> V_95 ;
} else if ( V_26 -> V_81 != V_90 ) {
F_8 ( L_24 ) ;
F_11 ( V_91 , V_96 ) ;
F_11 ( V_93 , V_97 ) ;
V_28 = V_26 -> V_98 ;
}
F_8 ( L_36 ) ;
switch ( V_28 ) {
case V_99 :
F_8 ( L_37 ) ;
F_11 ( V_100 , V_101 ) ;
break;
case V_102 :
F_8 ( L_38 ) ;
F_11 ( V_100 , V_103 ) ;
break;
case V_104 :
F_8 ( L_39 ) ;
F_11 ( V_100 , V_105 ) ;
break;
case V_106 :
F_8 ( L_40 ) ;
F_11 ( V_100 , V_107 ) ;
break;
case V_108 :
F_8 ( L_41 ) ;
F_11 ( V_100 , V_109 ) ;
break;
case V_29 :
F_8 ( L_30 ) ;
break;
case V_110 :
F_8 ( L_15 ) ;
break;
default:
return - V_44 ;
}
V_31 = V_111
[ V_26 -> V_47 == V_53 ]
[ V_26 -> V_54 == V_64 ]
[ V_26 -> V_65 == V_69 ] ;
F_8 ( L_42 , V_31 ) ;
F_11 ( V_112 , V_31 ) ;
F_11 ( V_113 , V_31 ? V_114 : V_115 ) ;
if ( V_26 -> V_47 == V_48 ) {
if ( V_26 -> V_54 == V_60 ) {
F_11 ( V_116 , V_117 ) ;
} else {
F_11 ( V_116 , V_118 ) ;
}
F_11 ( V_119 , V_120 ) ;
} else {
F_11 ( V_119 , V_121 ) ;
}
F_11 ( V_122 , V_123 ) ;
F_11 ( V_124 , V_125 ) ;
F_11 ( V_126 , V_127 ) ;
F_9 ( V_128 , V_129 ) ;
F_11 ( V_113 , V_115 ) ;
F_11 ( V_130 , V_131 + V_132 ) ;
F_11 ( V_130 , V_133 ) ;
F_12 ( 70 ) ;
F_9 ( V_128 , V_134 ) ;
if ( V_26 -> V_72 == V_80 ||
V_26 -> V_81 == V_90 ||
V_28 == V_110 ||
V_26 -> V_65 == V_69 ) {
int V_135 = 0 ;
F_8 ( L_43 ) ;
F_11 ( V_113 , V_114 ) ;
F_11 ( V_130 , V_136 ) ;
F_11 ( V_130 , V_133 ) ;
while ( ( V_30 =
F_5 (
F_13 ( V_137 ) ,
F_13 ( V_138 ) ) ) < 0 && V_135 ++ < 100 )
F_12 ( 1 ) ;
F_8 ( L_44 , V_30 , V_135 ) ;
if ( V_30 == 1 ) {
if ( F_14 ( V_22 ) == 0 ) {
F_8 ( L_45 ) ;
return F_7 ( V_22 , 0 ) ;
}
}
} else {
F_11 ( V_130 , V_132 ) ;
F_11 ( V_130 , V_133 ) ;
}
return 0 ;
}
static int F_15 ( struct V_21 * V_22 , int V_139 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
F_16 ( L_46 ) ;
F_11 ( V_140 , V_141 ) ;
F_11 ( V_130 , V_131 ) ;
F_11 ( V_142 , V_143 ) ;
F_11 ( V_142 , V_144 ) ;
F_11 ( V_145 , V_146 ) ;
F_11 ( V_147 , V_148 ) ;
F_11 ( V_149 , V_150 ) ;
F_11 ( V_151 , V_152 ) ;
F_9 ( V_37 , V_38 [ 2 ] ) ;
F_9 ( V_153 ,
V_154 [ V_155 ] ) ;
F_9 ( V_156 , V_157 ) ;
F_11 ( V_158 , V_159 ) ;
F_9 ( V_160 , V_161 ) ;
F_9 ( V_162 , V_163 ) ;
F_9 ( V_128 , V_134 ) ;
F_11 ( V_164 , V_165 ) ;
F_11 ( V_45 , V_46 ) ;
F_11 ( V_166 , V_167 ) ;
F_11 ( V_112 , V_111 [ 1 ] [ 1 ] [ 1 ] ) ;
F_9 ( V_39 , V_40 ) ;
F_11 ( V_168 , V_169 ) ;
F_11 ( V_170 , V_171 ) ;
F_11 ( V_172 , V_173 ) ;
F_11 ( V_174 , V_175 ) ;
F_11 ( V_176 , V_177 ) ;
F_11 ( V_113 , V_114 ) ;
F_11 ( V_178 , V_179 ) ;
F_11 ( V_180 , V_181 ) ;
F_11 ( V_182 , V_183 ) ;
F_11 ( V_184 , V_185 ) ;
F_11 ( V_186 , V_187 ) ;
F_11 ( V_188 , V_189 ) ;
F_11 ( V_190 , V_191 ) ;
F_11 ( V_124 , V_125 ) ;
F_11 ( V_192 , V_193 ) ;
F_9 ( V_194 , V_195 ) ;
F_11 ( V_122 , V_196 ) ;
F_11 ( V_197 , V_198 ) ;
F_11 ( V_199 , V_200 ) ;
F_11 ( V_201 , V_202 ) ;
F_11 ( V_203 , V_204 ) ;
F_11 ( V_205 , V_206 ) ;
F_11 ( V_207 , V_208 ) ;
F_11 ( V_209 , V_210 ) ;
F_11 ( V_211 , V_212 ) ;
F_11 ( V_213 , V_214 ) ;
F_11 ( V_215 , V_216 ) ;
return 0 ;
}
static int F_14 ( struct V_21 * V_22 )
{
struct V_25 * V_26 = & V_22 -> V_27 ;
struct V_1 * V_2 = V_22 -> V_24 ;
T_3 * V_217 ;
T_1 V_218 ;
int V_219 , V_220 ;
T_4 V_221 , V_222 = 0x800000 ;
if ( ! F_13 ( V_223 ) )
return 0 ;
V_221 = ( ( F_13 ( V_224 ) & 0xff ) << 16 ) + F_13 ( V_225 ) ;
F_17 ( L_47 , V_221 , F_13 ( V_224 ) , F_13 ( V_225 ) ) ;
if ( V_221 < V_222 )
V_219 = 0 ;
else if ( V_221 == V_222 )
V_219 = 1 ;
else
V_219 = 2 ;
V_221 = ( ( F_13 ( V_149 ) & 0xff ) << 16 ) + F_13 ( V_151 ) ;
F_17 ( L_48 , V_221 , F_13 ( V_149 ) , F_13 ( V_151 ) ) ;
if ( V_221 < V_222 )
V_220 = 0 ;
else if ( V_221 == V_222 )
V_220 = 1 ;
else
V_220 = 2 ;
V_26 -> V_65 =
( ( V_220 == 2 ) && ( V_219 == 1 || V_219 == 0 ) ) ||
( ( V_220 == 0 ) && ( V_219 == 1 || V_219 == 2 ) ) ?
V_70 : V_66 ;
F_17 ( L_49 , V_220 , V_219 , V_26 -> V_65 ) ;
switch ( ( V_218 = F_13 ( V_226 ) ) ) {
case V_75 :
F_17 ( L_50 ) ;
V_26 -> V_72 = V_73 ;
break;
case V_77 :
F_17 ( L_51 ) ;
V_26 -> V_72 = V_76 ;
break;
case V_79 :
F_17 ( L_52 ) ;
V_26 -> V_72 = V_78 ;
break;
default:
F_10 ( L_53 , V_218 ) ;
break;
}
F_17 ( L_54 , V_218 ) ;
if ( F_13 ( V_227 ) ) {
F_17 ( L_55 ) ;
V_217 = & V_26 -> V_98 ;
V_26 -> V_95 = V_29 ;
switch ( ( V_218 = F_13 ( V_228 ) ) ) {
case V_229 :
F_17 ( L_56 ) ;
V_26 -> V_81 = V_82 ;
break;
case V_85 :
F_17 ( L_57 ) ;
V_26 -> V_81 = V_83 ;
break;
case V_87 :
F_17 ( L_58 ) ;
V_26 -> V_81 = V_86 ;
break;
case V_89 :
F_17 ( L_59 ) ;
V_26 -> V_81 = V_88 ;
break;
default:
F_10 ( L_60 , V_218 ) ;
break;
}
F_17 ( L_54 , V_218 ) ;
V_218 = F_13 ( V_230 ) ;
} else {
F_17 ( L_61 ) ;
V_217 = & V_26 -> V_95 ;
V_26 -> V_98 = V_29 ;
V_26 -> V_81 = V_82 ;
V_218 = F_13 ( V_231 ) ;
}
switch ( V_218 ) {
case V_101 :
F_17 ( L_62 ) ;
* V_217 = V_99 ;
break;
case V_103 :
F_17 ( L_63 ) ;
* V_217 = V_102 ;
break;
case V_105 :
F_17 ( L_64 ) ;
* V_217 = V_104 ;
break;
case V_107 :
F_17 ( L_65 ) ;
* V_217 = V_232 ;
break;
case V_109 :
F_17 ( L_66 ) ;
* V_217 = V_108 ;
break;
default:
F_10 ( L_67 , V_218 ) ;
break;
}
F_17 ( L_54 , V_218 ) ;
switch ( ( V_218 = F_13 ( V_233 ) ) ) {
case V_57 :
F_17 ( L_68 ) ;
V_26 -> V_54 = V_55 ;
break;
case V_59 :
F_17 ( L_69 ) ;
V_26 -> V_54 = V_58 ;
break;
case V_61 :
F_17 ( L_70 ) ;
V_26 -> V_54 = V_60 ;
break;
case V_63 :
F_17 ( L_71 ) ;
V_26 -> V_54 = V_62 ;
break;
default:
F_10 ( L_72 , V_218 ) ;
break;
}
F_17 ( L_54 , V_218 ) ;
switch ( ( V_218 = F_13 ( V_234 ) ) ) {
case V_50 :
F_17 ( L_73 ) ;
V_26 -> V_47 = V_48 ;
break;
case V_52 :
F_17 ( L_74 ) ;
V_26 -> V_47 = V_51 ;
break;
default:
F_10 ( L_75 , V_218 ) ;
break;
}
F_17 ( L_54 , V_218 ) ;
return 0 ;
}
static int F_18 ( struct V_21 * V_22 , T_5 * V_235 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
* V_235 = 0 ;
if ( F_13 ( V_236 ) )
* V_235 |= V_237 ;
if ( F_13 ( V_238 ) )
* V_235 |= V_239 ;
if ( F_13 ( V_240 ) )
* V_235 |= V_241 ;
if ( F_13 ( V_242 ) )
* V_235 |= ( V_243 | V_244 ) ;
F_17 ( L_76 , * V_235 ) ;
F_17 ( L_77 ,
F_13 ( V_223 ) ,
F_13 ( V_226 ) ,
F_13 ( V_227 ) ,
F_13 ( V_228 ) ,
F_13 ( V_231 ) ,
F_13 ( V_230 ) ,
F_13 ( V_233 ) ,
F_13 ( V_234 ) ,
F_13 ( V_245 ) ) ;
return 0 ;
}
static int F_19 ( struct V_21 * V_22 , T_4 * V_246 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
* V_246 = ( ( F_13 ( V_247 ) << 16 ) | F_13 ( V_248 ) ) ;
return 0 ;
}
static int F_20 ( struct V_21 * V_22 , T_1 * V_249 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
* V_249 = F_13 ( V_250 ) * 0xffff / 0x170 ;
return 0 ;
}
static int F_21 ( struct V_21 * V_22 , T_1 * V_251 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
short V_252 = F_13 ( V_250 ) ;
int V_253 = ( ( F_13 ( V_254 ) & 0xff ) << 16 ) |
F_13 ( V_255 ) ;
* V_251 = ( V_252 << 8 ) / ( ( V_253 > 0 ) ? V_253 : 1 ) ;
return 0 ;
}
static int F_22 ( struct V_21 * V_22 , T_4 * V_256 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
* V_256 = F_13 ( V_257 ) ;
return 0 ;
}
static int F_23 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
F_16 ( L_78 ) ;
F_11 ( V_140 , V_258 ) ;
return 0 ;
}
static int F_24 ( struct V_21 * V_22 , struct V_259 * V_260 )
{
V_260 -> V_261 = 800 ;
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
static int F_29 ( struct V_21 * V_22 , int V_262 , int V_263 , int V_264 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
V_263 = ( V_264 ? V_263 | V_265 : 0 ) ;
F_11 ( V_262 + V_266 , V_263 ) ;
return 0 ;
}
static int F_30 ( struct V_21 * V_22 , int V_264 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
F_31 ( L_79 , V_264 ? L_80 : L_81 ) ;
if ( V_264 ) {
F_11 ( V_209 , V_267 ) ;
} else {
F_11 ( V_209 , V_210 ) ;
}
return 0 ;
}
static int F_32 ( struct V_21 * V_22 , int V_264 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
F_31 ( L_82 , V_264 ? L_80 : L_81 ) ;
F_11 ( V_207 , V_264 ) ;
return 0 ;
}
static int F_33 ( struct V_21 * V_22 , int V_264 , T_2 V_268 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
if ( V_264 ) {
F_11 ( V_269 , F_34 ( V_268 ) ) ;
} else {
F_11 ( V_269 , F_35 ( V_268 ) ) ;
}
return 0 ;
}
struct V_21 * F_36 ( const struct V_270 * V_9 ,
struct V_271 * V_15 , struct V_272 * V_273 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_37 ( sizeof( struct V_1 ) , V_274 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_15 = V_15 ;
memcpy ( & V_2 -> V_9 , V_9 , sizeof( struct V_270 ) ) ;
if ( F_13 ( V_275 ) != V_276 )
goto error;
if ( F_13 ( V_277 ) != V_278 )
goto error;
memcpy ( & V_2 -> V_279 . V_32 , & V_280 , sizeof( struct V_281 ) ) ;
V_2 -> V_279 . V_24 = V_2 ;
V_273 -> V_282 = F_32 ;
V_273 -> V_283 = F_30 ;
V_273 -> V_284 = F_29 ;
V_273 -> V_285 = F_33 ;
return & V_2 -> V_279 ;
error:
F_28 ( V_2 ) ;
return NULL ;
}
