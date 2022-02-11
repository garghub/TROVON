static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
if ( V_3 >= V_5 [ V_4 ] . V_6 &&
V_3 <= V_5 [ V_4 ] . V_7 ) {
return true ;
}
}
switch ( V_3 ) {
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
return true ;
default:
return false ;
}
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
if ( V_3 >= V_5 [ V_4 ] . V_6 &&
V_3 <= V_5 [ V_4 ] . V_7 ) {
return true ;
}
}
switch ( V_3 ) {
case V_8 :
case V_38 :
case V_39 :
case V_40 :
case V_9 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_10 :
case V_11 :
case V_72 :
case V_73 :
case V_12 :
case V_74 :
case V_75 :
case V_13 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_14 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_15 :
case V_16 :
case V_91 :
case V_92 :
case V_93 :
case V_17 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_18 :
case V_107 :
case V_108 :
case V_109 :
case V_19 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_20 :
case V_118 :
case V_21 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_22 :
case V_23 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_24 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_25 :
case V_153 :
case V_26 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_27 :
case V_28 :
case V_29 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
case V_30 :
case V_193 :
case V_194 :
case V_195 :
case V_31 :
case V_196 :
case V_197 :
case V_198 :
case V_32 :
case V_199 :
case V_200 :
case V_201 :
case V_33 :
case V_202 :
case V_203 :
case V_204 :
case V_34 :
case V_205 :
case V_206 :
case V_207 :
case V_208 :
case V_209 :
case V_210 :
case V_35 :
case V_36 :
case V_37 :
return true ;
default:
return false ;
}
}
static int F_4 ( struct V_211 * V_212 ,
unsigned int V_213 , unsigned int V_214 , unsigned int V_215 )
{
struct V_216 * V_217 = V_212 -> V_217 ;
int V_218 ;
F_5 ( & V_212 -> V_219 ) ;
V_218 = F_6 ( V_212 -> V_220 , V_221 ,
V_213 >> 16 ) ;
if ( V_218 < 0 ) {
F_7 ( V_217 -> V_2 , L_1 , V_218 ) ;
goto V_222;
}
V_218 = F_6 ( V_212 -> V_220 , V_223 ,
V_213 & 0xffff ) ;
if ( V_218 < 0 ) {
F_7 ( V_217 -> V_2 , L_2 , V_218 ) ;
goto V_222;
}
V_218 = F_6 ( V_212 -> V_220 , V_224 ,
V_214 >> 16 ) ;
if ( V_218 < 0 ) {
F_7 ( V_217 -> V_2 , L_3 , V_218 ) ;
goto V_222;
}
V_218 = F_6 ( V_212 -> V_220 , V_225 ,
V_214 & 0xffff ) ;
if ( V_218 < 0 ) {
F_7 ( V_217 -> V_2 , L_4 , V_218 ) ;
goto V_222;
}
V_218 = F_6 ( V_212 -> V_220 , V_226 ,
V_215 ) ;
if ( V_218 < 0 ) {
F_7 ( V_217 -> V_2 , L_5 , V_218 ) ;
goto V_222;
}
V_222:
F_8 ( & V_212 -> V_219 ) ;
return V_218 ;
}
static int F_9 (
struct V_211 * V_212 , unsigned int V_213 , unsigned int * V_214 )
{
struct V_216 * V_217 = V_212 -> V_217 ;
int V_218 ;
unsigned int V_227 , V_228 ;
F_5 ( & V_212 -> V_219 ) ;
V_218 = F_6 ( V_212 -> V_220 , V_221 ,
V_213 >> 16 ) ;
if ( V_218 < 0 ) {
F_7 ( V_217 -> V_2 , L_1 , V_218 ) ;
goto V_222;
}
V_218 = F_6 ( V_212 -> V_220 , V_223 ,
V_213 & 0xffff ) ;
if ( V_218 < 0 ) {
F_7 ( V_217 -> V_2 , L_2 , V_218 ) ;
goto V_222;
}
V_218 = F_6 ( V_212 -> V_220 , V_226 ,
0x0002 ) ;
if ( V_218 < 0 ) {
F_7 ( V_217 -> V_2 , L_5 , V_218 ) ;
goto V_222;
}
F_10 ( V_212 -> V_220 , V_224 , & V_227 ) ;
F_10 ( V_212 -> V_220 , V_225 , & V_228 ) ;
* V_214 = ( V_227 << 16 ) | V_228 ;
V_222:
F_8 ( & V_212 -> V_219 ) ;
return V_218 ;
}
static int F_11 ( struct V_211 * V_212 ,
unsigned int V_3 , unsigned int V_214 )
{
return F_4 ( V_212 , 0x18020000 + V_3 * 2 ,
V_214 , 0x0001 ) ;
}
static int F_12 (
struct V_211 * V_212 , unsigned int V_3 , unsigned int * V_214 )
{
int V_218 = F_9 ( V_212 , 0x18020000 + V_3 * 2 ,
V_214 ) ;
* V_214 &= 0xffff ;
return V_218 ;
}
static void F_13 ( struct V_216 * V_217 , bool V_229 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
if ( V_229 ) {
F_15 ( V_212 -> V_230 , V_106 , 0x2 , 0x2 ) ;
V_212 -> V_231 = true ;
} else {
F_15 ( V_212 -> V_230 , V_106 , 0x2 , 0x0 ) ;
V_212 -> V_231 = false ;
}
}
static int F_16 ( struct V_216 * V_217 , bool V_229 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
static bool V_232 ;
int V_218 ;
if ( ! F_17 ( V_233 ) )
return - V_234 ;
if ( V_229 && ! V_232 ) {
V_232 = true ;
F_18 ( V_212 -> V_230 , false ) ;
F_19 ( V_212 -> V_230 , true ) ;
F_15 ( V_212 -> V_230 , V_208 , 0x1 , 0x1 ) ;
F_15 ( V_212 -> V_230 ,
V_235 + V_236 , 0x0f00 , 0x0f00 ) ;
F_15 ( V_212 -> V_230 , V_104 ,
V_237 , 0x0 ) ;
F_15 ( V_212 -> V_230 , V_105 ,
V_238 , V_238 ) ;
F_15 ( V_212 -> V_230 , V_119 ,
V_239 , V_240 ) ;
F_15 ( V_212 -> V_230 , V_120 ,
V_241 | V_242 ,
V_243 | V_244 ) ;
F_6 ( V_212 -> V_230 , V_107 , 0x07ff ) ;
F_6 ( V_212 -> V_230 , V_106 , 0x07fd ) ;
F_13 ( V_217 , true ) ;
V_218 = F_20 ( & V_212 -> V_245 , V_246 ,
V_217 -> V_2 ) ;
if ( V_218 == 0 ) {
F_21 ( 0x50000000 , V_212 -> V_245 ) ;
F_22 ( V_212 -> V_245 ) ;
}
V_218 = F_20 ( & V_212 -> V_247 , V_248 ,
V_217 -> V_2 ) ;
if ( V_218 == 0 ) {
F_21 ( 0x60000000 , V_212 -> V_247 ) ;
F_22 ( V_212 -> V_247 ) ;
}
F_15 ( V_212 -> V_230 , V_106 , 0x1 , 0x0 ) ;
F_19 ( V_212 -> V_230 , false ) ;
F_18 ( V_212 -> V_230 , true ) ;
} else if ( ! V_229 && V_232 ) {
V_232 = false ;
F_18 ( V_212 -> V_230 , false ) ;
F_19 ( V_212 -> V_230 , true ) ;
F_15 ( V_212 -> V_230 , V_106 , 0x1 , 0x1 ) ;
F_13 ( V_217 , false ) ;
F_6 ( V_212 -> V_230 , V_106 , 0x0001 ) ;
F_6 ( V_212 -> V_230 , V_8 , 0x10ec ) ;
F_19 ( V_212 -> V_230 , false ) ;
F_23 ( V_212 -> V_230 ) ;
F_24 ( V_212 -> V_230 ) ;
}
return 0 ;
}
static int F_25 ( struct V_249 * V_250 ,
struct V_251 * V_252 )
{
struct V_253 * V_254 = F_26 ( V_250 ) ;
struct V_211 * V_212 = F_27 ( V_254 ) ;
V_252 -> V_214 . integer . V_214 [ 0 ] = V_212 -> V_255 ;
return 0 ;
}
static int F_28 ( struct V_249 * V_250 ,
struct V_251 * V_252 )
{
struct V_253 * V_254 = F_26 ( V_250 ) ;
struct V_211 * V_212 = F_27 ( V_254 ) ;
struct V_216 * V_217 = F_29 ( V_254 ) ;
V_212 -> V_255 = ! ! V_252 -> V_214 . integer . V_214 [ 0 ] ;
if ( V_217 -> V_256 . V_257 == V_258 )
F_16 ( V_217 , V_212 -> V_255 ) ;
return 0 ;
}
static int F_30 ( struct V_259 * V_260 ,
struct V_249 * V_250 , int V_261 )
{
struct V_216 * V_217 = F_31 ( V_260 -> V_256 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
int V_262 = F_32 ( V_212 -> V_263 ) ;
if ( V_262 < 0 )
F_7 ( V_217 -> V_2 , L_6 ) ;
else
F_15 ( V_212 -> V_230 , V_91 ,
V_264 , V_262 << V_265 ) ;
return V_262 ;
}
static int F_33 ( struct V_259 * V_266 ,
struct V_259 * V_267 )
{
struct V_216 * V_217 = F_31 ( V_266 -> V_256 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_268 ;
F_10 ( V_212 -> V_230 , V_119 , & V_268 ) ;
V_268 &= V_269 ;
if ( V_268 == V_270 )
return 1 ;
else
return 0 ;
}
static int F_34 ( struct V_259 * V_266 ,
struct V_259 * V_267 )
{
struct V_216 * V_217 = F_31 ( V_266 -> V_256 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_3 , V_271 , V_268 ;
if ( V_266 -> V_3 == V_121 ) {
switch ( V_266 -> V_271 ) {
case 12 :
V_3 = V_124 ;
V_271 = 0 ;
break;
case 13 :
V_3 = V_124 ;
V_271 = 4 ;
break;
case 14 :
V_3 = V_124 ;
V_271 = 8 ;
break;
case 15 :
V_3 = V_124 ;
V_271 = 12 ;
break;
default:
return 0 ;
}
} else {
switch ( V_266 -> V_271 ) {
case 0 :
V_3 = V_126 ;
V_271 = 8 ;
break;
case 1 :
V_3 = V_126 ;
V_271 = 12 ;
break;
case 2 :
V_3 = V_125 ;
V_271 = 0 ;
break;
case 3 :
V_3 = V_125 ;
V_271 = 4 ;
break;
case 4 :
V_3 = V_125 ;
V_271 = 8 ;
break;
case 5 :
V_3 = V_125 ;
V_271 = 12 ;
break;
case 12 :
V_3 = V_123 ;
V_271 = 0 ;
break;
case 13 :
V_3 = V_123 ;
V_271 = 4 ;
break;
case 14 :
V_3 = V_123 ;
V_271 = 12 ;
break;
default:
return 0 ;
}
}
F_10 ( V_212 -> V_230 , V_3 , & V_268 ) ;
V_268 = ( V_268 >> V_271 ) & 0xf ;
switch ( V_268 ) {
case 1 ... 6 :
return 1 ;
default:
return 0 ;
}
}
static int F_35 ( struct V_259 * V_266 ,
struct V_259 * V_267 )
{
struct V_216 * V_217 = F_31 ( V_266 -> V_256 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
if ( V_212 -> V_263 > V_212 -> V_272 [ V_273 ] * 384 )
return 1 ;
return 0 ;
}
static int F_36 ( struct V_259 * V_260 ,
struct V_249 * V_250 , int V_261 )
{
struct V_216 * V_217 = F_31 ( V_260 -> V_256 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_261 ) {
case V_274 :
F_15 ( V_212 -> V_230 , V_105 ,
V_275 , V_275 ) ;
break;
case V_276 :
F_15 ( V_212 -> V_230 , V_105 ,
V_275 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_37 ( struct V_259 * V_260 ,
struct V_249 * V_250 , int V_261 )
{
struct V_216 * V_217 = F_31 ( V_260 -> V_256 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_261 ) {
case V_274 :
F_15 ( V_212 -> V_230 , V_105 ,
V_277 , V_277 ) ;
break;
case V_276 :
F_15 ( V_212 -> V_230 , V_105 ,
V_277 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_38 ( struct V_259 * V_260 ,
struct V_249 * V_250 , int V_261 )
{
struct V_216 * V_217 = F_31 ( V_260 -> V_256 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_261 ) {
case V_278 :
F_15 ( V_212 -> V_230 , V_20 , 0x2 , 0x2 ) ;
break;
case V_274 :
F_15 ( V_212 -> V_230 , V_20 , 0x2 , 0x0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_39 ( struct V_259 * V_260 ,
struct V_249 * V_250 , int V_261 )
{
struct V_216 * V_217 = F_31 ( V_260 -> V_256 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_261 ) {
case V_278 :
F_15 ( V_212 -> V_230 , V_21 , 0x2 , 0x2 ) ;
break;
case V_274 :
F_15 ( V_212 -> V_230 , V_21 , 0x2 , 0x0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_40 ( struct V_259 * V_260 ,
struct V_249 * V_250 , int V_261 )
{
struct V_216 * V_217 = F_31 ( V_260 -> V_256 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_261 ) {
case V_274 :
F_15 ( V_212 -> V_230 , V_105 ,
V_279 | V_280 |
V_281 , V_279 |
V_280 | V_281 ) ;
break;
case V_276 :
F_15 ( V_212 -> V_230 , V_105 ,
V_279 | V_280 |
V_281 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_41 ( struct V_259 * V_260 ,
struct V_249 * V_250 , int V_261 )
{
struct V_216 * V_217 = F_31 ( V_260 -> V_256 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_214 ;
switch ( V_261 ) {
case V_278 :
F_10 ( V_212 -> V_230 , V_77 , & V_214 ) ;
if ( V_214 & V_282 )
F_15 ( V_212 -> V_230 , V_76 ,
V_283 ,
V_284 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_42 ( struct V_259 * V_260 ,
struct V_249 * V_250 , int V_261 )
{
struct V_216 * V_217 = F_31 ( V_260 -> V_256 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_214 ;
switch ( V_261 ) {
case V_278 :
F_10 ( V_212 -> V_230 , V_82 , & V_214 ) ;
if ( V_214 & V_285 )
F_15 ( V_212 -> V_230 , V_81 ,
V_286 ,
V_287 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_43 ( struct V_259 * V_260 ,
struct V_249 * V_250 , int V_261 )
{
struct V_216 * V_217 = F_31 ( V_260 -> V_256 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_261 ) {
case V_274 :
if ( V_217 -> V_256 . V_257 != V_288 &&
! V_212 -> V_289 ) {
F_44 ( 20 ) ;
F_15 ( V_212 -> V_230 , V_104 ,
V_290 | V_291 ,
V_290 | V_291 ) ;
V_212 -> V_289 = true ;
}
break;
default:
return 0 ;
}
return 0 ;
}
static int F_45 ( struct V_292 * V_293 ,
struct V_294 * V_295 , struct V_296 * V_297 )
{
struct V_216 * V_217 = V_297 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_298 = 0 , V_299 , V_300 ;
int V_301 , V_302 , V_303 ;
V_212 -> V_272 [ V_297 -> V_304 ] = F_46 ( V_295 ) ;
V_301 = F_47 ( V_212 -> V_263 , V_212 -> V_272 [ V_297 -> V_304 ] ) ;
if ( V_301 < 0 ) {
F_7 ( V_217 -> V_2 , L_7 ,
V_212 -> V_263 , V_212 -> V_272 [ V_297 -> V_304 ] ) ;
return - V_305 ;
}
V_303 = F_48 ( V_295 ) ;
if ( V_303 < 0 ) {
F_7 ( V_217 -> V_2 , L_8 , V_303 ) ;
return - V_305 ;
}
V_302 = V_303 > 32 ;
V_212 -> V_306 [ V_297 -> V_304 ] = V_212 -> V_272 [ V_297 -> V_304 ] * ( 32 << V_302 ) ;
F_49 ( V_297 -> V_2 , L_9 ,
V_212 -> V_306 [ V_297 -> V_304 ] , V_212 -> V_272 [ V_297 -> V_304 ] ) ;
F_49 ( V_297 -> V_2 , L_10 ,
V_302 , V_301 , V_297 -> V_304 ) ;
switch ( F_50 ( V_295 ) ) {
case 16 :
break;
case 20 :
V_298 |= V_307 ;
break;
case 24 :
V_298 |= V_308 ;
break;
case 8 :
V_298 |= V_309 ;
break;
default:
return - V_305 ;
}
switch ( V_297 -> V_304 ) {
case V_273 :
V_300 = V_310 ;
V_299 = V_301 << V_311 ;
F_15 ( V_212 -> V_230 , V_111 ,
V_312 , V_298 ) ;
F_15 ( V_212 -> V_230 , V_114 ,
V_300 , V_299 ) ;
break;
case V_313 :
V_300 = V_314 ;
V_299 = V_301 << V_315 ;
F_15 ( V_212 -> V_230 , V_112 ,
V_312 , V_298 ) ;
F_15 ( V_212 -> V_230 , V_114 ,
V_300 , V_299 ) ;
break;
case V_316 :
V_300 = V_317 | V_318 ;
V_299 = V_302 << V_319 |
V_301 << V_320 ;
F_15 ( V_212 -> V_230 , V_113 ,
V_312 , V_298 ) ;
F_15 ( V_212 -> V_230 , V_114 ,
V_300 , V_299 ) ;
break;
case V_321 :
V_300 = V_322 | V_323 ;
V_299 = V_302 << V_324 |
V_301 << V_325 ;
F_15 ( V_212 -> V_230 , V_110 ,
V_312 , V_298 ) ;
F_15 ( V_212 -> V_230 , V_114 ,
V_300 , V_299 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_51 ( struct V_296 * V_297 , unsigned int V_326 )
{
struct V_216 * V_217 = V_297 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_327 = 0 ;
switch ( V_326 & V_328 ) {
case V_329 :
V_212 -> V_330 [ V_297 -> V_304 ] = 1 ;
break;
case V_331 :
V_327 |= V_332 ;
V_212 -> V_330 [ V_297 -> V_304 ] = 0 ;
break;
default:
return - V_305 ;
}
switch ( V_326 & V_333 ) {
case V_334 :
break;
case V_335 :
V_327 |= V_336 ;
break;
default:
return - V_305 ;
}
switch ( V_326 & V_337 ) {
case V_338 :
break;
case V_339 :
V_327 |= V_340 ;
break;
case V_341 :
V_327 |= V_342 ;
break;
case V_343 :
V_327 |= V_344 ;
break;
default:
return - V_305 ;
}
switch ( V_297 -> V_304 ) {
case V_273 :
F_15 ( V_212 -> V_230 , V_111 ,
V_345 | V_346 |
V_347 , V_327 ) ;
break;
case V_313 :
F_15 ( V_212 -> V_230 , V_112 ,
V_345 | V_346 |
V_347 , V_327 ) ;
break;
case V_316 :
F_15 ( V_212 -> V_230 , V_113 ,
V_345 | V_346 |
V_347 , V_327 ) ;
break;
case V_321 :
F_15 ( V_212 -> V_230 , V_110 ,
V_345 | V_346 |
V_347 , V_327 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_52 ( struct V_296 * V_297 ,
int V_348 , unsigned int V_349 , int V_350 )
{
struct V_216 * V_217 = V_297 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_327 = 0 ;
if ( V_349 == V_212 -> V_263 && V_348 == V_212 -> V_351 )
return 0 ;
switch ( V_348 ) {
case V_352 :
V_327 |= V_353 ;
break;
case V_354 :
V_327 |= V_270 ;
break;
case V_355 :
V_327 |= V_356 ;
break;
default:
F_7 ( V_217 -> V_2 , L_11 , V_348 ) ;
return - V_305 ;
}
F_15 ( V_212 -> V_230 , V_119 ,
V_269 , V_327 ) ;
V_212 -> V_263 = V_349 ;
V_212 -> V_351 = V_348 ;
F_49 ( V_297 -> V_2 , L_12 , V_349 , V_348 ) ;
return 0 ;
}
static int F_53 ( const unsigned int V_357 ,
const unsigned int V_358 , struct V_359 * V_360 )
{
if ( V_361 > V_357 )
return - V_305 ;
return F_54 ( V_357 , V_358 , V_360 ) ;
}
static int F_55 ( struct V_296 * V_297 , int V_362 , int V_266 ,
unsigned int V_357 , unsigned int V_358 )
{
struct V_216 * V_217 = V_297 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
struct V_359 V_360 ;
int V_218 ;
if ( V_266 == V_212 -> V_363 && V_357 == V_212 -> V_364 &&
V_358 == V_212 -> V_365 )
return 0 ;
if ( ! V_357 || ! V_358 ) {
F_49 ( V_217 -> V_2 , L_13 ) ;
V_212 -> V_364 = 0 ;
V_212 -> V_365 = 0 ;
F_15 ( V_212 -> V_230 , V_119 ,
V_269 , V_353 ) ;
return 0 ;
}
switch ( V_266 ) {
case V_366 :
F_15 ( V_212 -> V_230 , V_119 ,
V_367 , V_368 ) ;
break;
case V_369 :
case V_370 :
case V_371 :
case V_372 :
switch ( V_297 -> V_304 ) {
case V_273 :
F_15 ( V_212 -> V_230 , V_119 ,
V_367 , V_373 ) ;
break;
case V_313 :
F_15 ( V_212 -> V_230 , V_119 ,
V_367 , V_374 ) ;
break;
case V_316 :
F_15 ( V_212 -> V_230 , V_119 ,
V_367 , V_375 ) ;
break;
case V_321 :
F_15 ( V_212 -> V_230 , V_119 ,
V_367 , V_376 ) ;
break;
default:
break;
}
break;
default:
F_7 ( V_217 -> V_2 , L_14 , V_266 ) ;
return - V_305 ;
}
V_218 = F_53 ( V_357 , V_358 , & V_360 ) ;
if ( V_218 < 0 ) {
F_7 ( V_217 -> V_2 , L_15 , V_357 ) ;
return V_218 ;
}
F_49 ( V_217 -> V_2 , L_16 ,
V_360 . V_377 , ( V_360 . V_377 ? 0 : V_360 . V_378 ) ,
V_360 . V_379 , V_360 . V_380 ) ;
F_6 ( V_212 -> V_230 , V_117 ,
V_360 . V_379 << V_381 | V_360 . V_380 ) ;
F_6 ( V_212 -> V_230 , V_20 ,
( V_360 . V_377 ? 0 : V_360 . V_378 ) << V_382 |
V_360 . V_377 << V_383 ) ;
V_212 -> V_364 = V_357 ;
V_212 -> V_365 = V_358 ;
V_212 -> V_363 = V_266 ;
return 0 ;
}
static int F_56 ( struct V_296 * V_297 , unsigned int V_384 ,
unsigned int V_385 , int V_386 , int V_387 )
{
struct V_216 * V_217 = V_297 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_268 = 0 , V_388 = 0 ;
if ( V_385 || V_384 )
V_268 |= ( 1 << 12 ) ;
switch ( V_386 ) {
case 4 :
V_268 |= ( 1 << 10 ) ;
break;
case 6 :
V_268 |= ( 2 << 10 ) ;
break;
case 8 :
V_268 |= ( 3 << 10 ) ;
break;
case 2 :
default:
break;
}
switch ( V_387 ) {
case 20 :
V_268 |= ( 1 << 8 ) ;
break;
case 25 :
V_388 = 0x8080 ;
case 24 :
V_268 |= ( 2 << 8 ) ;
break;
case 32 :
V_268 |= ( 3 << 8 ) ;
break;
case 16 :
default:
break;
}
switch ( V_297 -> V_304 ) {
case V_273 :
F_15 ( V_212 -> V_230 , V_76 , 0x1f00 ,
V_268 ) ;
F_15 ( V_212 -> V_230 , V_208 , 0x8000 ,
V_388 ) ;
break;
case V_313 :
F_15 ( V_212 -> V_230 , V_81 , 0x1f00 ,
V_268 ) ;
F_15 ( V_212 -> V_230 , V_208 , 0x80 ,
V_388 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_57 ( struct V_216 * V_217 ,
enum V_389 V_390 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_390 ) {
case V_288 :
break;
case V_391 :
if ( V_217 -> V_256 . V_257 == V_392 ) {
F_16 ( V_217 , false ) ;
F_15 ( V_212 -> V_230 , V_104 ,
V_237 | V_393 ,
0x0055 ) ;
F_15 ( V_212 -> V_230 ,
V_235 + V_236 ,
0x0f00 , 0x0f00 ) ;
F_15 ( V_212 -> V_230 , V_104 ,
V_290 | V_291 |
V_394 | V_395 |
V_396 | V_397 ,
V_394 | V_395 |
V_396 | V_397 ) ;
V_212 -> V_289 = false ;
F_15 ( V_212 -> V_230 , V_105 ,
V_398 , V_398 ) ;
F_15 ( V_212 -> V_230 , V_208 ,
0x1 , 0x1 ) ;
}
break;
case V_392 :
break;
case V_258 :
F_15 ( V_212 -> V_230 , V_208 , 0x1 , 0x0 ) ;
F_6 ( V_212 -> V_230 , V_102 , 0x0000 ) ;
F_6 ( V_212 -> V_230 , V_103 , 0x0000 ) ;
F_6 ( V_212 -> V_230 , V_104 , 0x0022 ) ;
F_6 ( V_212 -> V_230 , V_105 , 0x0000 ) ;
F_15 ( V_212 -> V_230 ,
V_235 + V_236 , 0x0f00 , 0x0000 ) ;
if ( V_212 -> V_255 )
F_16 ( V_217 , true ) ;
break;
default:
break;
}
V_217 -> V_256 . V_257 = V_390 ;
return 0 ;
}
static inline struct V_211 * F_58 ( struct V_399 * V_400 )
{
return F_59 ( V_400 , struct V_211 , V_399 ) ;
}
static void F_60 ( struct V_399 * V_400 , unsigned V_401 , int V_214 )
{
struct V_211 * V_212 = F_58 ( V_400 ) ;
switch ( V_401 ) {
case V_402 ... V_403 :
F_15 ( V_212 -> V_230 , V_161 ,
0x1 << ( V_401 * 3 + 1 ) , ! ! V_214 << ( V_401 * 3 + 1 ) ) ;
break;
case V_404 :
F_15 ( V_212 -> V_230 , V_162 ,
V_405 , ! ! V_214 << V_406 ) ;
break;
default:
break;
}
}
static int F_61 ( struct V_399 * V_400 ,
unsigned V_401 , int V_214 )
{
struct V_211 * V_212 = F_58 ( V_400 ) ;
switch ( V_401 ) {
case V_402 ... V_403 :
F_15 ( V_212 -> V_230 , V_161 ,
0x3 << ( V_401 * 3 + 1 ) ,
( 0x2 | ! ! V_214 ) << ( V_401 * 3 + 1 ) ) ;
break;
case V_404 :
F_15 ( V_212 -> V_230 , V_162 ,
V_407 | V_405 ,
V_408 | ! ! V_214 << V_406 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_62 ( struct V_399 * V_400 , unsigned V_401 )
{
struct V_211 * V_212 = F_58 ( V_400 ) ;
int V_214 , V_218 ;
V_218 = F_10 ( V_212 -> V_230 , V_29 , & V_214 ) ;
if ( V_218 < 0 )
return V_218 ;
return ( V_214 & ( 0x1 << V_401 ) ) >> V_401 ;
}
static int F_63 ( struct V_399 * V_400 , unsigned V_401 )
{
struct V_211 * V_212 = F_58 ( V_400 ) ;
switch ( V_401 ) {
case V_402 ... V_403 :
F_15 ( V_212 -> V_230 , V_161 ,
0x1 << ( V_401 * 3 + 2 ) , 0x0 ) ;
break;
case V_404 :
F_15 ( V_212 -> V_230 , V_162 ,
V_407 , V_409 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_64 ( struct V_211 * V_212 , unsigned V_401 ,
int V_214 )
{
int V_271 ;
switch ( V_401 ) {
case V_402 ... V_410 :
V_271 = 2 * ( 1 - V_401 ) ;
F_15 ( V_212 -> V_230 ,
V_235 + V_411 ,
0x3 << V_271 ,
( V_214 & 0x3 ) << V_271 ) ;
break;
case V_412 ... V_404 :
V_271 = 2 * ( 9 - V_401 ) ;
F_15 ( V_212 -> V_230 ,
V_235 + V_413 ,
0x3 << V_271 ,
( V_214 & 0x3 ) << V_271 ) ;
break;
default:
break;
}
}
static int F_65 ( struct V_399 * V_400 , unsigned V_401 )
{
struct V_211 * V_212 = F_58 ( V_400 ) ;
struct V_414 * V_415 = V_212 -> V_416 ;
int V_417 ;
if ( V_401 >= V_402 && V_401 <= V_412 ) {
if ( ( V_212 -> V_418 . V_419 == 1 && V_401 == V_402 ) ||
( V_212 -> V_418 . V_419 == 2 &&
V_401 == V_410 ) ||
( V_212 -> V_418 . V_419 == 3 &&
V_401 == V_412 ) ) {
V_417 = V_420 ;
} else {
return - V_234 ;
}
}
if ( V_401 >= V_421 && V_401 <= V_404 ) {
if ( ( V_212 -> V_418 . V_422 == 1 && V_401 == V_421 ) ||
( V_212 -> V_418 . V_422 == 2 &&
V_401 == V_403 ) ||
( V_212 -> V_418 . V_422 == 3 &&
V_401 == V_404 ) ) {
V_417 = V_423 ;
} else if ( ( V_212 -> V_418 . V_424 == 1 &&
V_401 == V_421 ) ||
( V_212 -> V_418 . V_424 == 2 &&
V_401 == V_403 ) ||
( V_212 -> V_418 . V_424 == 3 &&
V_401 == V_404 ) ) {
V_417 = V_425 ;
} else {
return - V_234 ;
}
}
return F_66 ( V_415 , V_417 ) ;
}
static void F_67 ( struct V_426 * V_427 )
{
struct V_211 * V_212 = F_68 ( V_427 ) ;
int V_218 ;
V_212 -> V_399 = V_428 ;
V_212 -> V_399 . V_429 = V_430 ;
V_212 -> V_399 . V_2 = & V_427 -> V_2 ;
V_212 -> V_399 . V_431 = - 1 ;
V_218 = F_69 ( & V_212 -> V_399 ) ;
if ( V_218 != 0 )
F_7 ( & V_427 -> V_2 , L_17 , V_218 ) ;
}
static void F_70 ( struct V_426 * V_427 )
{
struct V_211 * V_212 = F_68 ( V_427 ) ;
F_71 ( & V_212 -> V_399 ) ;
}
static void F_64 ( struct V_211 * V_212 , unsigned V_401 ,
int V_214 )
{
}
static void F_67 ( struct V_426 * V_427 )
{
}
static void F_70 ( struct V_426 * V_427 )
{
}
static int F_72 ( struct V_216 * V_217 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
int V_4 ;
V_212 -> V_217 = V_217 ;
if ( V_212 -> V_418 . V_432 == V_433 ) {
F_73 ( & V_217 -> V_256 ,
V_434 ,
F_2 ( V_434 ) ) ;
} else {
F_73 ( & V_217 -> V_256 ,
V_435 ,
F_2 ( V_435 ) ) ;
}
F_57 ( V_217 , V_258 ) ;
F_6 ( V_212 -> V_230 , V_208 , 0x0020 ) ;
F_6 ( V_212 -> V_230 , V_107 , 0x0c00 ) ;
for ( V_4 = 0 ; V_4 < V_430 ; V_4 ++ )
F_64 ( V_212 , V_4 , V_212 -> V_418 . V_436 [ V_4 ] ) ;
if ( V_212 -> V_416 ) {
F_15 ( V_212 -> V_230 , V_160 , 0x8000 ,
0x8000 ) ;
F_15 ( V_212 -> V_230 , V_208 , 0x0018 ,
0x0008 ) ;
if ( V_212 -> V_418 . V_419 )
F_15 ( V_212 -> V_230 , V_157 ,
V_437 ,
V_212 -> V_418 . V_419 <<
V_438 ) ;
if ( V_212 -> V_418 . V_422 )
F_15 ( V_212 -> V_230 , V_157 ,
V_439 ,
V_212 -> V_418 . V_422 <<
V_440 ) ;
if ( V_212 -> V_418 . V_424 )
F_15 ( V_212 -> V_230 , V_157 ,
V_441 ,
V_212 -> V_418 . V_424 <<
V_442 ) ;
}
F_74 ( & V_212 -> V_219 ) ;
F_74 ( & V_212 -> V_443 ) ;
return 0 ;
}
static int F_75 ( struct V_216 * V_217 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
F_6 ( V_212 -> V_230 , V_8 , 0x10ec ) ;
if ( F_76 ( V_212 -> V_444 ) )
F_77 ( V_212 -> V_444 , 0 ) ;
return 0 ;
}
static int F_78 ( struct V_216 * V_217 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
if ( ! V_212 -> V_255 ) {
F_18 ( V_212 -> V_230 , true ) ;
F_23 ( V_212 -> V_230 ) ;
}
if ( F_76 ( V_212 -> V_444 ) )
F_77 ( V_212 -> V_444 , 0 ) ;
return 0 ;
}
static int F_79 ( struct V_216 * V_217 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
if ( F_76 ( V_212 -> V_444 ) ) {
F_77 ( V_212 -> V_444 , 1 ) ;
F_80 ( 10 ) ;
}
if ( ! V_212 -> V_255 ) {
F_18 ( V_212 -> V_230 , false ) ;
F_24 ( V_212 -> V_230 ) ;
}
return 0 ;
}
static int F_81 ( void * V_445 , unsigned int V_3 , unsigned int * V_268 )
{
struct V_426 * V_446 = V_445 ;
struct V_211 * V_212 = F_68 ( V_446 ) ;
if ( V_212 -> V_231 ) {
if ( V_3 > 0xff ) {
F_5 ( & V_212 -> V_443 ) ;
F_11 ( V_212 , V_109 ,
V_3 & 0xff ) ;
F_12 ( V_212 , V_19 , V_268 ) ;
F_8 ( & V_212 -> V_443 ) ;
} else {
F_12 ( V_212 , V_3 , V_268 ) ;
}
} else {
F_10 ( V_212 -> V_220 , V_3 , V_268 ) ;
}
return 0 ;
}
static int F_82 ( void * V_445 , unsigned int V_3 , unsigned int V_268 )
{
struct V_426 * V_446 = V_445 ;
struct V_211 * V_212 = F_68 ( V_446 ) ;
if ( V_212 -> V_231 ) {
if ( V_3 > 0xff ) {
F_5 ( & V_212 -> V_443 ) ;
F_11 ( V_212 , V_109 ,
V_3 & 0xff ) ;
F_11 ( V_212 , V_19 ,
V_268 ) ;
F_8 ( & V_212 -> V_443 ) ;
} else {
F_11 ( V_212 , V_3 , V_268 ) ;
}
} else {
F_6 ( V_212 -> V_220 , V_3 , V_268 ) ;
}
return 0 ;
}
static int F_83 ( struct V_211 * V_212 , struct V_447 * V_448 )
{
V_212 -> V_418 . V_449 = F_84 ( V_448 ,
L_18 ) ;
V_212 -> V_418 . V_450 = F_84 ( V_448 ,
L_19 ) ;
V_212 -> V_418 . V_451 = F_84 ( V_448 ,
L_20 ) ;
V_212 -> V_418 . V_452 = F_84 ( V_448 ,
L_21 ) ;
V_212 -> V_418 . V_453 = F_84 ( V_448 ,
L_22 ) ;
V_212 -> V_444 = F_85 ( V_448 ,
L_23 , 0 ) ;
if ( ! F_76 ( V_212 -> V_444 ) &&
( V_212 -> V_444 != - V_454 ) )
return V_212 -> V_444 ;
F_86 ( V_448 , L_24 ,
V_212 -> V_418 . V_436 , V_430 ) ;
F_87 ( V_448 , L_25 , & V_212 -> V_418 . V_419 ) ;
F_87 ( V_448 , L_26 , & V_212 -> V_418 . V_422 ) ;
F_87 ( V_448 , L_27 , & V_212 -> V_418 . V_424 ) ;
return 0 ;
}
static int F_88 ( struct V_426 * V_427 )
{
int V_218 ;
struct V_211 * V_212 = F_68 ( V_427 ) ;
if ( ! V_212 -> V_418 . V_419 &&
! V_212 -> V_418 . V_422 &&
! V_212 -> V_418 . V_424 )
return 0 ;
if ( ! V_427 -> V_417 ) {
F_7 ( & V_427 -> V_2 , L_28 ) ;
return - V_305 ;
}
V_218 = F_89 ( V_212 -> V_230 , V_427 -> V_417 ,
V_455 | V_456 | V_457 , 0 ,
& V_458 , & V_212 -> V_416 ) ;
if ( V_218 != 0 ) {
F_7 ( & V_427 -> V_2 , L_29 , V_218 ) ;
return V_218 ;
}
return 0 ;
}
static void F_90 ( struct V_426 * V_427 )
{
struct V_211 * V_212 = F_68 ( V_427 ) ;
if ( V_212 -> V_416 )
F_91 ( V_427 -> V_417 , V_212 -> V_416 ) ;
}
static int F_92 ( struct V_426 * V_427 ,
const struct V_459 * V_304 )
{
struct V_460 * V_418 = F_93 ( & V_427 -> V_2 ) ;
struct V_211 * V_212 ;
int V_218 ;
unsigned int V_268 ;
V_212 = F_94 ( & V_427 -> V_2 , sizeof( struct V_211 ) ,
V_461 ) ;
if ( V_212 == NULL )
return - V_462 ;
F_95 ( V_427 , V_212 ) ;
if ( V_418 )
V_212 -> V_418 = * V_418 ;
if ( V_427 -> V_2 . V_463 ) {
V_218 = F_83 ( V_212 , V_427 -> V_2 . V_463 ) ;
if ( V_218 ) {
F_7 ( & V_427 -> V_2 , L_30 ,
V_218 ) ;
return V_218 ;
}
} else {
V_212 -> V_444 = - V_305 ;
}
if ( F_76 ( V_212 -> V_444 ) ) {
V_218 = F_96 ( & V_427 -> V_2 , V_212 -> V_444 ,
V_464 ,
L_31 ) ;
if ( V_218 < 0 ) {
F_7 ( & V_427 -> V_2 , L_32 ,
V_212 -> V_444 , V_218 ) ;
return V_218 ;
}
F_80 ( 10 ) ;
}
V_212 -> V_220 = F_97 ( V_427 ,
& V_465 ) ;
if ( F_98 ( V_212 -> V_220 ) ) {
V_218 = F_99 ( V_212 -> V_220 ) ;
F_7 ( & V_427 -> V_2 , L_33 ,
V_218 ) ;
return V_218 ;
}
V_212 -> V_230 = F_100 ( & V_427 -> V_2 , NULL , V_427 , & V_466 ) ;
if ( F_98 ( V_212 -> V_230 ) ) {
V_218 = F_99 ( V_212 -> V_230 ) ;
F_7 ( & V_427 -> V_2 , L_33 ,
V_218 ) ;
return V_218 ;
}
F_10 ( V_212 -> V_230 , V_37 , & V_268 ) ;
if ( V_268 != V_467 ) {
F_7 ( & V_427 -> V_2 ,
L_34 , V_268 ) ;
return - V_468 ;
}
F_6 ( V_212 -> V_230 , V_8 , 0x10ec ) ;
V_218 = F_101 ( V_212 -> V_230 , V_469 ,
F_2 ( V_469 ) ) ;
if ( V_218 != 0 )
F_102 ( & V_427 -> V_2 , L_35 , V_218 ) ;
if ( V_212 -> V_418 . V_449 )
F_15 ( V_212 -> V_230 , V_39 ,
V_470 , V_470 ) ;
if ( V_212 -> V_418 . V_450 )
F_15 ( V_212 -> V_230 , V_39 ,
V_471 , V_471 ) ;
if ( V_212 -> V_418 . V_451 )
F_15 ( V_212 -> V_230 , V_38 ,
V_472 , V_472 ) ;
if ( V_212 -> V_418 . V_452 )
F_15 ( V_212 -> V_230 , V_38 ,
V_473 , V_473 ) ;
if ( V_212 -> V_418 . V_453 )
F_15 ( V_212 -> V_230 , V_38 ,
V_474 , V_474 ) ;
if ( V_212 -> V_418 . V_432 == V_433 ) {
F_15 ( V_212 -> V_230 , V_210 ,
V_475 ,
V_476 ) ;
F_15 ( V_212 -> V_230 , V_161 ,
V_477 ,
V_478 ) ;
}
if ( V_212 -> V_418 . V_479 )
F_15 ( V_212 -> V_230 , V_40 ,
V_480 ,
V_481 ) ;
F_67 ( V_427 ) ;
F_88 ( V_427 ) ;
return F_103 ( & V_427 -> V_2 , & V_482 ,
V_483 , F_2 ( V_483 ) ) ;
}
static int F_104 ( struct V_426 * V_427 )
{
F_105 ( & V_427 -> V_2 ) ;
F_90 ( V_427 ) ;
F_70 ( V_427 ) ;
return 0 ;
}
