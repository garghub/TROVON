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
switch ( V_212 -> type ) {
case V_239 :
F_15 ( V_212 -> V_230 , V_119 ,
V_240 , V_241 ) ;
F_15 ( V_212 -> V_230 , V_120 ,
V_242 |
V_243 ,
V_244 |
V_245 ) ;
break;
case V_246 :
F_15 ( V_212 -> V_230 , V_120 ,
V_243 ,
V_245 ) ;
break;
default:
break;
}
F_6 ( V_212 -> V_230 , V_107 , 0x07ff ) ;
F_6 ( V_212 -> V_230 , V_106 , 0x07fd ) ;
F_13 ( V_217 , true ) ;
V_218 = F_20 ( & V_212 -> V_247 , V_248 ,
V_217 -> V_2 ) ;
if ( V_218 == 0 ) {
F_21 ( 0x50000000 , V_212 -> V_247 ) ;
F_22 ( V_212 -> V_247 ) ;
}
V_218 = F_20 ( & V_212 -> V_249 , V_250 ,
V_217 -> V_2 ) ;
if ( V_218 == 0 ) {
F_21 ( 0x60000000 , V_212 -> V_249 ) ;
F_22 ( V_212 -> V_249 ) ;
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
static int F_25 ( struct V_251 * V_252 ,
struct V_253 * V_254 )
{
struct V_255 * V_256 = F_26 ( V_252 ) ;
struct V_211 * V_212 = F_27 ( V_256 ) ;
V_254 -> V_214 . integer . V_214 [ 0 ] = V_212 -> V_257 ;
return 0 ;
}
static int F_28 ( struct V_251 * V_252 ,
struct V_253 * V_254 )
{
struct V_255 * V_256 = F_26 ( V_252 ) ;
struct V_211 * V_212 = F_27 ( V_256 ) ;
struct V_216 * V_217 = F_29 ( V_256 ) ;
V_212 -> V_257 = ! ! V_254 -> V_214 . integer . V_214 [ 0 ] ;
if ( V_217 -> V_258 . V_259 == V_260 )
F_16 ( V_217 , V_212 -> V_257 ) ;
return 0 ;
}
static int F_30 ( struct V_261 * V_262 ,
struct V_251 * V_252 , int V_263 )
{
struct V_216 * V_217 = F_31 ( V_262 -> V_258 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
int V_264 = F_32 ( V_212 -> V_265 [ V_266 ] << 8 ) ;
if ( V_264 < 0 )
F_7 ( V_217 -> V_2 , L_6 ) ;
else
F_15 ( V_212 -> V_230 , V_91 ,
V_267 , V_264 << V_268 ) ;
return V_264 ;
}
static int F_33 ( struct V_261 * V_269 ,
struct V_261 * V_270 )
{
struct V_216 * V_217 = F_31 ( V_269 -> V_258 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_271 ;
F_10 ( V_212 -> V_230 , V_119 , & V_271 ) ;
V_271 &= V_272 ;
if ( V_271 == V_273 )
return 1 ;
else
return 0 ;
}
static int F_34 ( struct V_261 * V_269 ,
struct V_261 * V_270 )
{
struct V_216 * V_217 = F_31 ( V_269 -> V_258 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_3 , V_274 , V_271 ;
if ( V_269 -> V_3 == V_121 ) {
switch ( V_269 -> V_274 ) {
case 12 :
V_3 = V_124 ;
V_274 = 0 ;
break;
case 13 :
V_3 = V_124 ;
V_274 = 4 ;
break;
case 14 :
V_3 = V_124 ;
V_274 = 8 ;
break;
case 15 :
V_3 = V_124 ;
V_274 = 12 ;
break;
default:
return 0 ;
}
} else {
switch ( V_269 -> V_274 ) {
case 0 :
V_3 = V_126 ;
V_274 = 8 ;
break;
case 1 :
V_3 = V_126 ;
V_274 = 12 ;
break;
case 2 :
V_3 = V_125 ;
V_274 = 0 ;
break;
case 3 :
V_3 = V_125 ;
V_274 = 4 ;
break;
case 4 :
V_3 = V_125 ;
V_274 = 8 ;
break;
case 5 :
V_3 = V_125 ;
V_274 = 12 ;
break;
case 12 :
V_3 = V_123 ;
V_274 = 0 ;
break;
case 13 :
V_3 = V_123 ;
V_274 = 4 ;
break;
case 14 :
V_3 = V_123 ;
V_274 = 12 ;
break;
default:
return 0 ;
}
}
F_10 ( V_212 -> V_230 , V_3 , & V_271 ) ;
V_271 = ( V_271 >> V_274 ) & 0xf ;
switch ( V_271 ) {
case 1 ... 6 :
return 1 ;
default:
return 0 ;
}
}
static int F_35 ( struct V_261 * V_269 ,
struct V_261 * V_270 )
{
struct V_216 * V_217 = F_31 ( V_269 -> V_258 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
if ( V_212 -> V_275 > V_212 -> V_265 [ V_266 ] * 384 )
return 1 ;
return 0 ;
}
int F_36 ( struct V_216 * V_217 ,
unsigned int V_276 , unsigned int V_277 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_278 = 0 , V_279 = 0 ;
unsigned int V_280 = 0 , V_281 = 0 ;
unsigned int V_282 = 0 , V_283 = 0 ;
unsigned int V_284 = 0 , V_285 = 0 ;
unsigned int V_286 = 0 , V_287 = 0 ;
switch ( V_277 ) {
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
case V_298 :
case V_299 :
case V_300 :
break;
default:
return - V_301 ;
}
if ( V_276 & V_302 ) {
V_278 |= V_303 ;
V_279 = ( V_279 & ~ V_303 )
| ( V_277 << V_304 ) ;
}
if ( V_276 & V_305 ) {
V_278 |= V_306 ;
V_279 = ( V_279 & ~ V_306 )
| ( V_277 << V_307 ) ;
}
if ( V_276 & V_308 ) {
V_278 |= V_309 ;
V_279 = ( V_279 & ~ V_309 )
| ( V_277 << V_310 ) ;
}
if ( V_278 )
F_15 ( V_212 -> V_230 , V_123 , V_278 ,
V_279 ) ;
if ( V_276 & V_311 ) {
V_280 |= V_312 ;
V_281 = ( V_281 & ~ V_312 )
| ( V_277 << V_313 ) ;
}
if ( V_276 & V_314 ) {
V_280 |= V_315 ;
V_281 = ( V_281 & ~ V_315 )
| ( V_277 << V_316 ) ;
}
if ( V_276 & V_317 ) {
V_280 |= V_318 ;
V_281 = ( V_281 & ~ V_318 )
| ( V_277 << V_319 ) ;
}
if ( V_276 & V_320 ) {
V_280 |= V_321 ;
V_281 = ( V_281 & ~ V_321 )
| ( V_277 << V_322 ) ;
}
if ( V_280 )
F_15 ( V_212 -> V_230 , V_124 , V_280 ,
V_281 ) ;
if ( V_276 & V_323 ) {
V_282 |= V_324 ;
V_283 = ( V_283 & ~ V_324 )
| ( V_277 << V_325 ) ;
}
if ( V_276 & V_326 ) {
V_282 |= V_327 ;
V_283 = ( V_283 & ~ V_327 )
| ( V_277 << V_328 ) ;
}
if ( V_276 & V_329 ) {
V_282 |= V_330 ;
V_283 = ( V_283 & ~ V_330 )
| ( V_277 << V_331 ) ;
}
if ( V_276 & V_332 ) {
V_282 |= V_333 ;
V_283 = ( V_283 & ~ V_333 )
| ( V_277 << V_334 ) ;
}
if ( V_282 )
F_15 ( V_212 -> V_230 , V_125 , V_282 ,
V_283 ) ;
if ( V_276 & V_335 ) {
V_284 |= V_336 ;
V_285 = ( V_285 & ~ V_336 )
| ( V_277 << V_337 ) ;
}
if ( V_276 & V_338 ) {
V_284 |= V_339 ;
V_285 = ( V_285 & ~ V_339 )
| ( V_277 << V_340 ) ;
}
if ( V_284 )
F_15 ( V_212 -> V_230 , V_126 , V_284 ,
V_285 ) ;
if ( V_276 & V_341 ) {
V_286 |= V_342 ;
V_287 = ( V_287 & ~ V_342 )
| ( V_277 << V_343 ) ;
}
if ( V_276 & V_344 ) {
V_286 |= V_345 ;
V_287 = ( V_287 & ~ V_345 )
| ( V_277 << V_346 ) ;
}
if ( V_286 )
F_15 ( V_212 -> V_230 , V_127 , V_286 ,
V_287 ) ;
return 0 ;
}
static int F_37 ( struct V_261 * V_262 ,
struct V_251 * V_252 , int V_263 )
{
struct V_216 * V_217 = F_31 ( V_262 -> V_258 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_263 ) {
case V_347 :
F_15 ( V_212 -> V_230 , V_105 ,
V_348 , V_348 ) ;
break;
case V_349 :
F_15 ( V_212 -> V_230 , V_105 ,
V_348 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_38 ( struct V_261 * V_262 ,
struct V_251 * V_252 , int V_263 )
{
struct V_216 * V_217 = F_31 ( V_262 -> V_258 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_263 ) {
case V_347 :
F_15 ( V_212 -> V_230 , V_105 ,
V_350 , V_350 ) ;
break;
case V_349 :
F_15 ( V_212 -> V_230 , V_105 ,
V_350 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_39 ( struct V_261 * V_262 ,
struct V_251 * V_252 , int V_263 )
{
struct V_216 * V_217 = F_31 ( V_262 -> V_258 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_263 ) {
case V_351 :
F_15 ( V_212 -> V_230 , V_20 , 0x2 , 0x2 ) ;
break;
case V_347 :
F_15 ( V_212 -> V_230 , V_20 , 0x2 , 0x0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_40 ( struct V_261 * V_262 ,
struct V_251 * V_252 , int V_263 )
{
struct V_216 * V_217 = F_31 ( V_262 -> V_258 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_263 ) {
case V_351 :
F_15 ( V_212 -> V_230 , V_21 , 0x2 , 0x2 ) ;
break;
case V_347 :
F_15 ( V_212 -> V_230 , V_21 , 0x2 , 0x0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_41 ( struct V_261 * V_262 ,
struct V_251 * V_252 , int V_263 )
{
struct V_216 * V_217 = F_31 ( V_262 -> V_258 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_263 ) {
case V_347 :
F_15 ( V_212 -> V_230 , V_105 ,
V_352 | V_353 |
V_354 , V_352 |
V_353 | V_354 ) ;
break;
case V_349 :
F_15 ( V_212 -> V_230 , V_105 ,
V_352 | V_353 |
V_354 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_42 ( struct V_261 * V_262 ,
struct V_251 * V_252 , int V_263 )
{
struct V_216 * V_217 = F_31 ( V_262 -> V_258 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_214 ;
switch ( V_263 ) {
case V_351 :
F_10 ( V_212 -> V_230 , V_77 , & V_214 ) ;
if ( V_214 & V_355 )
F_15 ( V_212 -> V_230 , V_76 ,
V_356 ,
V_357 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_43 ( struct V_261 * V_262 ,
struct V_251 * V_252 , int V_263 )
{
struct V_216 * V_217 = F_31 ( V_262 -> V_258 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_214 ;
switch ( V_263 ) {
case V_351 :
F_10 ( V_212 -> V_230 , V_82 , & V_214 ) ;
if ( V_214 & V_358 )
F_15 ( V_212 -> V_230 , V_81 ,
V_359 ,
V_360 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_44 ( struct V_261 * V_262 ,
struct V_251 * V_252 , int V_263 )
{
struct V_216 * V_217 = F_31 ( V_262 -> V_258 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_263 ) {
case V_347 :
if ( V_217 -> V_258 . V_259 != V_361 &&
! V_212 -> V_362 ) {
F_45 ( 20 ) ;
F_15 ( V_212 -> V_230 , V_104 ,
V_363 | V_364 ,
V_363 | V_364 ) ;
V_212 -> V_362 = true ;
}
break;
default:
return 0 ;
}
return 0 ;
}
static int F_46 ( struct V_365 * V_366 ,
struct V_367 * V_368 , struct V_369 * V_370 )
{
struct V_216 * V_217 = V_370 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_371 = 0 , V_372 , V_373 ;
int V_374 , V_375 , V_376 ;
V_212 -> V_265 [ V_370 -> V_377 ] = F_47 ( V_368 ) ;
V_374 = F_48 ( V_212 -> V_275 , V_212 -> V_265 [ V_370 -> V_377 ] ) ;
if ( V_374 < 0 ) {
F_7 ( V_217 -> V_2 , L_7 ,
V_212 -> V_275 , V_212 -> V_265 [ V_370 -> V_377 ] ) ;
return - V_301 ;
}
V_376 = F_49 ( V_368 ) ;
if ( V_376 < 0 ) {
F_7 ( V_217 -> V_2 , L_8 , V_376 ) ;
return - V_301 ;
}
V_375 = V_376 > 32 ;
V_212 -> V_378 [ V_370 -> V_377 ] = V_212 -> V_265 [ V_370 -> V_377 ] * ( 32 << V_375 ) ;
F_50 ( V_370 -> V_2 , L_9 ,
V_212 -> V_378 [ V_370 -> V_377 ] , V_212 -> V_265 [ V_370 -> V_377 ] ) ;
F_50 ( V_370 -> V_2 , L_10 ,
V_375 , V_374 , V_370 -> V_377 ) ;
switch ( F_51 ( V_368 ) ) {
case 16 :
break;
case 20 :
V_371 |= V_379 ;
break;
case 24 :
V_371 |= V_380 ;
break;
case 8 :
V_371 |= V_381 ;
break;
default:
return - V_301 ;
}
switch ( V_370 -> V_377 ) {
case V_266 :
V_373 = V_382 ;
V_372 = V_374 << V_383 ;
F_15 ( V_212 -> V_230 , V_111 ,
V_384 , V_371 ) ;
F_15 ( V_212 -> V_230 , V_114 ,
V_373 , V_372 ) ;
break;
case V_385 :
V_373 = V_386 ;
V_372 = V_374 << V_387 ;
F_15 ( V_212 -> V_230 , V_112 ,
V_384 , V_371 ) ;
F_15 ( V_212 -> V_230 , V_114 ,
V_373 , V_372 ) ;
break;
case V_388 :
V_373 = V_389 | V_390 ;
V_372 = V_375 << V_391 |
V_374 << V_392 ;
F_15 ( V_212 -> V_230 , V_113 ,
V_384 , V_371 ) ;
F_15 ( V_212 -> V_230 , V_114 ,
V_373 , V_372 ) ;
break;
case V_393 :
V_373 = V_394 | V_395 ;
V_372 = V_375 << V_396 |
V_374 << V_397 ;
F_15 ( V_212 -> V_230 , V_110 ,
V_384 , V_371 ) ;
F_15 ( V_212 -> V_230 , V_114 ,
V_373 , V_372 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_52 ( struct V_369 * V_370 , unsigned int V_398 )
{
struct V_216 * V_217 = V_370 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_399 = 0 ;
switch ( V_398 & V_400 ) {
case V_401 :
V_212 -> V_402 [ V_370 -> V_377 ] = 1 ;
break;
case V_403 :
V_399 |= V_404 ;
V_212 -> V_402 [ V_370 -> V_377 ] = 0 ;
break;
default:
return - V_301 ;
}
switch ( V_398 & V_405 ) {
case V_406 :
break;
case V_407 :
V_399 |= V_408 ;
break;
default:
return - V_301 ;
}
switch ( V_398 & V_409 ) {
case V_410 :
break;
case V_411 :
V_399 |= V_412 ;
break;
case V_413 :
V_399 |= V_414 ;
break;
case V_415 :
V_399 |= V_416 ;
break;
default:
return - V_301 ;
}
switch ( V_370 -> V_377 ) {
case V_266 :
F_15 ( V_212 -> V_230 , V_111 ,
V_417 | V_418 |
V_419 , V_399 ) ;
break;
case V_385 :
F_15 ( V_212 -> V_230 , V_112 ,
V_417 | V_418 |
V_419 , V_399 ) ;
break;
case V_388 :
F_15 ( V_212 -> V_230 , V_113 ,
V_417 | V_418 |
V_419 , V_399 ) ;
break;
case V_393 :
F_15 ( V_212 -> V_230 , V_110 ,
V_417 | V_418 |
V_419 , V_399 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_53 ( struct V_369 * V_370 ,
int V_420 , unsigned int V_421 , int V_422 )
{
struct V_216 * V_217 = V_370 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_399 = 0 ;
if ( V_421 == V_212 -> V_275 && V_420 == V_212 -> V_423 )
return 0 ;
switch ( V_420 ) {
case V_424 :
V_399 |= V_425 ;
break;
case V_426 :
V_399 |= V_273 ;
break;
case V_427 :
V_399 |= V_428 ;
break;
default:
F_7 ( V_217 -> V_2 , L_11 , V_420 ) ;
return - V_301 ;
}
F_15 ( V_212 -> V_230 , V_119 ,
V_272 , V_399 ) ;
V_212 -> V_275 = V_421 ;
V_212 -> V_423 = V_420 ;
F_50 ( V_370 -> V_2 , L_12 , V_421 , V_420 ) ;
return 0 ;
}
static int F_54 ( const unsigned int V_429 ,
const unsigned int V_430 , struct V_431 * V_432 )
{
if ( V_433 > V_429 )
return - V_301 ;
return F_55 ( V_429 , V_430 , V_432 ) ;
}
static int F_56 ( struct V_369 * V_370 , int V_434 , int V_269 ,
unsigned int V_429 , unsigned int V_430 )
{
struct V_216 * V_217 = V_370 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
struct V_431 V_432 ;
int V_218 ;
if ( V_269 == V_212 -> V_435 && V_429 == V_212 -> V_436 &&
V_430 == V_212 -> V_437 )
return 0 ;
if ( ! V_429 || ! V_430 ) {
F_50 ( V_217 -> V_2 , L_13 ) ;
V_212 -> V_436 = 0 ;
V_212 -> V_437 = 0 ;
F_15 ( V_212 -> V_230 , V_119 ,
V_272 , V_425 ) ;
return 0 ;
}
switch ( V_269 ) {
case V_438 :
F_15 ( V_212 -> V_230 , V_119 ,
V_439 , V_440 ) ;
break;
case V_441 :
case V_442 :
case V_443 :
case V_444 :
switch ( V_370 -> V_377 ) {
case V_266 :
F_15 ( V_212 -> V_230 , V_119 ,
V_439 , V_445 ) ;
break;
case V_385 :
F_15 ( V_212 -> V_230 , V_119 ,
V_439 , V_446 ) ;
break;
case V_388 :
F_15 ( V_212 -> V_230 , V_119 ,
V_439 , V_447 ) ;
break;
case V_393 :
F_15 ( V_212 -> V_230 , V_119 ,
V_439 , V_448 ) ;
break;
default:
break;
}
break;
default:
F_7 ( V_217 -> V_2 , L_14 , V_269 ) ;
return - V_301 ;
}
V_218 = F_54 ( V_429 , V_430 , & V_432 ) ;
if ( V_218 < 0 ) {
F_7 ( V_217 -> V_2 , L_15 , V_429 ) ;
return V_218 ;
}
F_50 ( V_217 -> V_2 , L_16 ,
V_432 . V_449 , ( V_432 . V_449 ? 0 : V_432 . V_450 ) ,
V_432 . V_451 , V_432 . V_452 ) ;
F_6 ( V_212 -> V_230 , V_117 ,
V_432 . V_451 << V_453 | V_432 . V_452 ) ;
F_6 ( V_212 -> V_230 , V_20 ,
( V_432 . V_449 ? 0 : V_432 . V_450 ) << V_454 |
V_432 . V_449 << V_455 ) ;
V_212 -> V_436 = V_429 ;
V_212 -> V_437 = V_430 ;
V_212 -> V_435 = V_269 ;
return 0 ;
}
static int F_57 ( struct V_369 * V_370 , unsigned int V_456 ,
unsigned int V_457 , int V_458 , int V_459 )
{
struct V_216 * V_217 = V_370 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_271 = 0 , V_460 = 0 ;
if ( V_457 || V_456 )
V_271 |= ( 1 << 12 ) ;
switch ( V_458 ) {
case 4 :
V_271 |= ( 1 << 10 ) ;
break;
case 6 :
V_271 |= ( 2 << 10 ) ;
break;
case 8 :
V_271 |= ( 3 << 10 ) ;
break;
case 2 :
default:
break;
}
switch ( V_459 ) {
case 20 :
V_271 |= ( 1 << 8 ) ;
break;
case 25 :
V_460 = 0x8080 ;
case 24 :
V_271 |= ( 2 << 8 ) ;
break;
case 32 :
V_271 |= ( 3 << 8 ) ;
break;
case 16 :
default:
break;
}
switch ( V_370 -> V_377 ) {
case V_266 :
F_15 ( V_212 -> V_230 , V_76 , 0x1f00 ,
V_271 ) ;
F_15 ( V_212 -> V_230 , V_208 , 0x8000 ,
V_460 ) ;
break;
case V_385 :
F_15 ( V_212 -> V_230 , V_81 , 0x1f00 ,
V_271 ) ;
F_15 ( V_212 -> V_230 , V_208 , 0x80 ,
V_460 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_58 ( struct V_216 * V_217 ,
enum V_461 V_462 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_462 ) {
case V_361 :
break;
case V_463 :
if ( V_217 -> V_258 . V_259 == V_464 ) {
F_16 ( V_217 , false ) ;
F_15 ( V_212 -> V_230 , V_104 ,
V_237 | V_465 ,
0x0055 ) ;
F_15 ( V_212 -> V_230 ,
V_235 + V_236 ,
0x0f00 , 0x0f00 ) ;
F_15 ( V_212 -> V_230 , V_104 ,
V_363 | V_364 |
V_466 | V_467 |
V_468 | V_469 ,
V_466 | V_467 |
V_468 | V_469 ) ;
V_212 -> V_362 = false ;
F_15 ( V_212 -> V_230 , V_105 ,
V_470 , V_470 ) ;
F_15 ( V_212 -> V_230 , V_208 ,
0x1 , 0x1 ) ;
}
break;
case V_464 :
break;
case V_260 :
F_15 ( V_212 -> V_230 , V_208 , 0x1 , 0x0 ) ;
F_6 ( V_212 -> V_230 , V_102 , 0x0000 ) ;
F_6 ( V_212 -> V_230 , V_103 , 0x0000 ) ;
F_6 ( V_212 -> V_230 , V_104 , 0x0022 ) ;
F_6 ( V_212 -> V_230 , V_105 , 0x0000 ) ;
F_15 ( V_212 -> V_230 ,
V_235 + V_236 , 0x0f00 , 0x0000 ) ;
if ( V_212 -> V_257 )
F_16 ( V_217 , true ) ;
break;
default:
break;
}
V_217 -> V_258 . V_259 = V_462 ;
return 0 ;
}
static inline struct V_211 * F_59 ( struct V_471 * V_472 )
{
return F_60 ( V_472 , struct V_211 , V_471 ) ;
}
static void F_61 ( struct V_471 * V_472 , unsigned V_473 , int V_214 )
{
struct V_211 * V_212 = F_59 ( V_472 ) ;
switch ( V_473 ) {
case V_474 ... V_475 :
F_15 ( V_212 -> V_230 , V_161 ,
0x1 << ( V_473 * 3 + 1 ) , ! ! V_214 << ( V_473 * 3 + 1 ) ) ;
break;
case V_476 :
F_15 ( V_212 -> V_230 , V_162 ,
V_477 , ! ! V_214 << V_478 ) ;
break;
default:
break;
}
}
static int F_62 ( struct V_471 * V_472 ,
unsigned V_473 , int V_214 )
{
struct V_211 * V_212 = F_59 ( V_472 ) ;
switch ( V_473 ) {
case V_474 ... V_475 :
F_15 ( V_212 -> V_230 , V_161 ,
0x3 << ( V_473 * 3 + 1 ) ,
( 0x2 | ! ! V_214 ) << ( V_473 * 3 + 1 ) ) ;
break;
case V_476 :
F_15 ( V_212 -> V_230 , V_162 ,
V_479 | V_477 ,
V_480 | ! ! V_214 << V_478 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_63 ( struct V_471 * V_472 , unsigned V_473 )
{
struct V_211 * V_212 = F_59 ( V_472 ) ;
int V_214 , V_218 ;
V_218 = F_10 ( V_212 -> V_230 , V_29 , & V_214 ) ;
if ( V_218 < 0 )
return V_218 ;
return ( V_214 & ( 0x1 << V_473 ) ) >> V_473 ;
}
static int F_64 ( struct V_471 * V_472 , unsigned V_473 )
{
struct V_211 * V_212 = F_59 ( V_472 ) ;
switch ( V_473 ) {
case V_474 ... V_475 :
F_15 ( V_212 -> V_230 , V_161 ,
0x1 << ( V_473 * 3 + 2 ) , 0x0 ) ;
break;
case V_476 :
F_15 ( V_212 -> V_230 , V_162 ,
V_479 , V_481 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_65 ( struct V_211 * V_212 , unsigned V_473 ,
int V_214 )
{
int V_274 ;
switch ( V_473 ) {
case V_474 ... V_482 :
V_274 = 2 * ( 1 - V_473 ) ;
F_15 ( V_212 -> V_230 ,
V_235 + V_483 ,
0x3 << V_274 ,
( V_214 & 0x3 ) << V_274 ) ;
break;
case V_484 ... V_476 :
V_274 = 2 * ( 9 - V_473 ) ;
F_15 ( V_212 -> V_230 ,
V_235 + V_485 ,
0x3 << V_274 ,
( V_214 & 0x3 ) << V_274 ) ;
break;
default:
break;
}
}
static int F_66 ( struct V_471 * V_472 , unsigned V_473 )
{
struct V_211 * V_212 = F_59 ( V_472 ) ;
struct V_486 * V_487 = V_212 -> V_488 ;
int V_489 ;
if ( V_473 >= V_474 && V_473 <= V_484 ) {
if ( ( V_212 -> V_490 . V_491 == 1 && V_473 == V_474 ) ||
( V_212 -> V_490 . V_491 == 2 &&
V_473 == V_482 ) ||
( V_212 -> V_490 . V_491 == 3 &&
V_473 == V_484 ) ) {
V_489 = V_492 ;
} else {
return - V_234 ;
}
}
if ( V_473 >= V_493 && V_473 <= V_476 ) {
if ( ( V_212 -> V_490 . V_494 == 1 && V_473 == V_493 ) ||
( V_212 -> V_490 . V_494 == 2 &&
V_473 == V_475 ) ||
( V_212 -> V_490 . V_494 == 3 &&
V_473 == V_476 ) ) {
V_489 = V_495 ;
} else if ( ( V_212 -> V_490 . V_496 == 1 &&
V_473 == V_493 ) ||
( V_212 -> V_490 . V_496 == 2 &&
V_473 == V_475 ) ||
( V_212 -> V_490 . V_496 == 3 &&
V_473 == V_476 ) ) {
V_489 = V_497 ;
} else {
return - V_234 ;
}
}
return F_67 ( V_487 , V_489 ) ;
}
static void F_68 ( struct V_498 * V_499 )
{
struct V_211 * V_212 = F_69 ( V_499 ) ;
int V_218 ;
V_212 -> V_471 = V_500 ;
V_212 -> V_471 . V_501 = V_502 ;
V_212 -> V_471 . V_2 = & V_499 -> V_2 ;
V_212 -> V_471 . V_503 = - 1 ;
V_218 = F_70 ( & V_212 -> V_471 ) ;
if ( V_218 != 0 )
F_7 ( & V_499 -> V_2 , L_17 , V_218 ) ;
}
static void F_71 ( struct V_498 * V_499 )
{
struct V_211 * V_212 = F_69 ( V_499 ) ;
F_72 ( & V_212 -> V_471 ) ;
}
static void F_65 ( struct V_211 * V_212 , unsigned V_473 ,
int V_214 )
{
}
static void F_68 ( struct V_498 * V_499 )
{
}
static void F_71 ( struct V_498 * V_499 )
{
}
static int F_73 ( struct V_216 * V_217 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
int V_4 ;
V_212 -> V_217 = V_217 ;
if ( V_212 -> V_490 . V_504 == V_505 ) {
F_74 ( & V_217 -> V_258 ,
V_506 ,
F_2 ( V_506 ) ) ;
} else {
F_74 ( & V_217 -> V_258 ,
V_507 ,
F_2 ( V_507 ) ) ;
}
F_58 ( V_217 , V_260 ) ;
F_6 ( V_212 -> V_230 , V_208 , 0x0020 ) ;
F_6 ( V_212 -> V_230 , V_107 , 0x0c00 ) ;
for ( V_4 = 0 ; V_4 < V_502 ; V_4 ++ )
F_65 ( V_212 , V_4 , V_212 -> V_490 . V_508 [ V_4 ] ) ;
if ( V_212 -> V_488 ) {
F_15 ( V_212 -> V_230 , V_160 , 0x8000 ,
0x8000 ) ;
F_15 ( V_212 -> V_230 , V_208 , 0x0018 ,
0x0008 ) ;
if ( V_212 -> V_490 . V_491 )
F_15 ( V_212 -> V_230 , V_157 ,
V_509 ,
V_212 -> V_490 . V_491 <<
V_510 ) ;
if ( V_212 -> V_490 . V_494 )
F_15 ( V_212 -> V_230 , V_157 ,
V_511 ,
V_212 -> V_490 . V_494 <<
V_512 ) ;
if ( V_212 -> V_490 . V_496 )
F_15 ( V_212 -> V_230 , V_157 ,
V_513 ,
V_212 -> V_490 . V_496 <<
V_514 ) ;
}
F_75 ( & V_212 -> V_219 ) ;
F_75 ( & V_212 -> V_515 ) ;
return 0 ;
}
static int F_76 ( struct V_216 * V_217 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
F_6 ( V_212 -> V_230 , V_8 , 0x10ec ) ;
if ( F_77 ( V_212 -> V_516 ) )
F_78 ( V_212 -> V_516 , 0 ) ;
return 0 ;
}
static int F_79 ( struct V_216 * V_217 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
if ( ! V_212 -> V_257 ) {
F_18 ( V_212 -> V_230 , true ) ;
F_23 ( V_212 -> V_230 ) ;
if ( F_77 ( V_212 -> V_516 ) )
F_78 ( V_212 -> V_516 , 0 ) ;
}
return 0 ;
}
static int F_80 ( struct V_216 * V_217 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
if ( ! V_212 -> V_257 ) {
if ( F_77 ( V_212 -> V_516 ) ) {
F_78 ( V_212 -> V_516 , 1 ) ;
F_81 ( 10 ) ;
}
F_18 ( V_212 -> V_230 , false ) ;
F_24 ( V_212 -> V_230 ) ;
}
return 0 ;
}
static int F_82 ( void * V_517 , unsigned int V_3 , unsigned int * V_271 )
{
struct V_498 * V_518 = V_517 ;
struct V_211 * V_212 = F_69 ( V_518 ) ;
if ( V_212 -> V_231 ) {
if ( V_3 > 0xff ) {
F_5 ( & V_212 -> V_515 ) ;
F_11 ( V_212 , V_109 ,
V_3 & 0xff ) ;
F_12 ( V_212 , V_19 , V_271 ) ;
F_8 ( & V_212 -> V_515 ) ;
} else {
F_12 ( V_212 , V_3 , V_271 ) ;
}
} else {
F_10 ( V_212 -> V_220 , V_3 , V_271 ) ;
}
return 0 ;
}
static int F_83 ( void * V_517 , unsigned int V_3 , unsigned int V_271 )
{
struct V_498 * V_518 = V_517 ;
struct V_211 * V_212 = F_69 ( V_518 ) ;
if ( V_212 -> V_231 ) {
if ( V_3 > 0xff ) {
F_5 ( & V_212 -> V_515 ) ;
F_11 ( V_212 , V_109 ,
V_3 & 0xff ) ;
F_11 ( V_212 , V_19 ,
V_271 ) ;
F_8 ( & V_212 -> V_515 ) ;
} else {
F_11 ( V_212 , V_3 , V_271 ) ;
}
} else {
F_6 ( V_212 -> V_220 , V_3 , V_271 ) ;
}
return 0 ;
}
static int F_84 ( struct V_211 * V_212 , struct V_519 * V_520 )
{
V_212 -> V_490 . V_521 = F_85 ( V_520 ,
L_18 ) ;
V_212 -> V_490 . V_522 = F_85 ( V_520 ,
L_19 ) ;
V_212 -> V_490 . V_523 = F_85 ( V_520 ,
L_20 ) ;
V_212 -> V_490 . V_524 = F_85 ( V_520 ,
L_21 ) ;
V_212 -> V_490 . V_525 = F_85 ( V_520 ,
L_22 ) ;
V_212 -> V_516 = F_86 ( V_520 ,
L_23 , 0 ) ;
if ( ! F_77 ( V_212 -> V_516 ) &&
( V_212 -> V_516 != - V_526 ) )
return V_212 -> V_516 ;
F_87 ( V_520 , L_24 ,
V_212 -> V_490 . V_508 , V_502 ) ;
F_88 ( V_520 , L_25 , & V_212 -> V_490 . V_491 ) ;
F_88 ( V_520 , L_26 , & V_212 -> V_490 . V_494 ) ;
F_88 ( V_520 , L_27 , & V_212 -> V_490 . V_496 ) ;
return 0 ;
}
static int F_89 ( struct V_498 * V_499 )
{
int V_218 ;
struct V_211 * V_212 = F_69 ( V_499 ) ;
if ( ! V_212 -> V_490 . V_491 &&
! V_212 -> V_490 . V_494 &&
! V_212 -> V_490 . V_496 )
return 0 ;
if ( ! V_499 -> V_489 ) {
F_7 ( & V_499 -> V_2 , L_28 ) ;
return - V_301 ;
}
V_218 = F_90 ( V_212 -> V_230 , V_499 -> V_489 ,
V_527 | V_528 | V_529 , 0 ,
& V_530 , & V_212 -> V_488 ) ;
if ( V_218 != 0 ) {
F_7 ( & V_499 -> V_2 , L_29 , V_218 ) ;
return V_218 ;
}
return 0 ;
}
static void F_91 ( struct V_498 * V_499 )
{
struct V_211 * V_212 = F_69 ( V_499 ) ;
if ( V_212 -> V_488 )
F_92 ( V_499 -> V_489 , V_212 -> V_488 ) ;
}
static int F_93 ( struct V_498 * V_499 ,
const struct V_531 * V_377 )
{
struct V_532 * V_490 = F_94 ( & V_499 -> V_2 ) ;
struct V_211 * V_212 ;
int V_218 ;
unsigned int V_271 ;
V_212 = F_95 ( & V_499 -> V_2 , sizeof( struct V_211 ) ,
V_533 ) ;
if ( V_212 == NULL )
return - V_534 ;
F_96 ( V_499 , V_212 ) ;
V_212 -> type = V_377 -> V_535 ;
if ( V_490 )
V_212 -> V_490 = * V_490 ;
if ( V_499 -> V_2 . V_536 ) {
V_218 = F_84 ( V_212 , V_499 -> V_2 . V_536 ) ;
if ( V_218 ) {
F_7 ( & V_499 -> V_2 , L_30 ,
V_218 ) ;
return V_218 ;
}
} else {
V_212 -> V_516 = - V_301 ;
}
if ( F_77 ( V_212 -> V_516 ) ) {
V_218 = F_97 ( & V_499 -> V_2 , V_212 -> V_516 ,
V_537 ,
L_31 ) ;
if ( V_218 < 0 ) {
F_7 ( & V_499 -> V_2 , L_32 ,
V_212 -> V_516 , V_218 ) ;
return V_218 ;
}
F_81 ( 10 ) ;
}
V_212 -> V_220 = F_98 ( V_499 ,
& V_538 ) ;
if ( F_99 ( V_212 -> V_220 ) ) {
V_218 = F_100 ( V_212 -> V_220 ) ;
F_7 ( & V_499 -> V_2 , L_33 ,
V_218 ) ;
return V_218 ;
}
V_212 -> V_230 = F_101 ( & V_499 -> V_2 , NULL , V_499 , & V_539 ) ;
if ( F_99 ( V_212 -> V_230 ) ) {
V_218 = F_100 ( V_212 -> V_230 ) ;
F_7 ( & V_499 -> V_2 , L_33 ,
V_218 ) ;
return V_218 ;
}
F_10 ( V_212 -> V_230 , V_37 , & V_271 ) ;
if ( V_271 != V_540 ) {
F_7 ( & V_499 -> V_2 ,
L_34 , V_271 ) ;
return - V_541 ;
}
F_6 ( V_212 -> V_230 , V_8 , 0x10ec ) ;
V_218 = F_102 ( V_212 -> V_230 , V_542 ,
F_2 ( V_542 ) ) ;
if ( V_218 != 0 )
F_103 ( & V_499 -> V_2 , L_35 , V_218 ) ;
if ( V_212 -> V_490 . V_521 )
F_15 ( V_212 -> V_230 , V_39 ,
V_543 , V_543 ) ;
if ( V_212 -> V_490 . V_522 )
F_15 ( V_212 -> V_230 , V_39 ,
V_544 , V_544 ) ;
if ( V_212 -> V_490 . V_523 )
F_15 ( V_212 -> V_230 , V_38 ,
V_545 , V_545 ) ;
if ( V_212 -> V_490 . V_524 )
F_15 ( V_212 -> V_230 , V_38 ,
V_546 , V_546 ) ;
if ( V_212 -> V_490 . V_525 )
F_15 ( V_212 -> V_230 , V_38 ,
V_547 , V_547 ) ;
if ( V_212 -> V_490 . V_504 == V_505 ) {
F_15 ( V_212 -> V_230 , V_210 ,
V_548 ,
V_549 ) ;
F_15 ( V_212 -> V_230 , V_161 ,
V_550 ,
V_551 ) ;
}
if ( V_212 -> V_490 . V_552 )
F_15 ( V_212 -> V_230 , V_40 ,
V_553 ,
V_554 ) ;
F_68 ( V_499 ) ;
F_89 ( V_499 ) ;
return F_104 ( & V_499 -> V_2 , & V_555 ,
V_556 , F_2 ( V_556 ) ) ;
}
static int F_105 ( struct V_498 * V_499 )
{
F_106 ( & V_499 -> V_2 ) ;
F_91 ( V_499 ) ;
F_71 ( V_499 ) ;
return 0 ;
}
