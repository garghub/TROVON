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
struct V_213 * V_214 , int V_215 )
{
struct V_216 * V_217 = V_212 -> V_217 ;
struct V_218 * V_219 = F_5 ( V_217 ) ;
int div [] = { 2 , 3 , 4 , 6 , 8 , 12 } , V_220 = - V_221 , V_4 ;
int V_222 , V_223 , V_224 , V_225 ;
V_222 = V_219 -> V_226 ;
V_223 = 3000000 * 12 ;
for ( V_4 = 0 ; V_4 < F_2 ( div ) ; V_4 ++ ) {
V_224 = div [ V_4 ] * 3000000 ;
if ( V_222 > V_224 )
continue;
V_225 = V_224 - V_222 ;
if ( V_225 < V_223 ) {
V_223 = V_225 ;
V_220 = V_4 ;
}
}
if ( V_220 < 0 )
F_6 ( V_217 -> V_2 , L_1 ) ;
else
F_7 ( V_219 -> V_227 , V_91 ,
V_228 , V_220 << V_229 ) ;
return V_220 ;
}
static int F_8 ( struct V_211 * V_230 ,
struct V_211 * V_231 )
{
struct V_218 * V_219 = F_5 ( V_230 -> V_217 ) ;
unsigned int V_232 ;
F_9 ( V_219 -> V_227 , V_119 , & V_232 ) ;
V_232 &= V_233 ;
if ( V_232 == V_234 )
return 1 ;
else
return 0 ;
}
static int F_10 ( struct V_211 * V_212 ,
struct V_213 * V_214 , int V_215 )
{
struct V_216 * V_217 = V_212 -> V_217 ;
struct V_218 * V_219 = F_5 ( V_217 ) ;
switch ( V_215 ) {
case V_235 :
F_7 ( V_219 -> V_227 , V_105 ,
V_236 , V_236 ) ;
break;
case V_237 :
F_7 ( V_219 -> V_227 , V_105 ,
V_236 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_11 ( struct V_211 * V_212 ,
struct V_213 * V_214 , int V_215 )
{
struct V_216 * V_217 = V_212 -> V_217 ;
struct V_218 * V_219 = F_5 ( V_217 ) ;
switch ( V_215 ) {
case V_235 :
F_7 ( V_219 -> V_227 , V_105 ,
V_238 , V_238 ) ;
break;
case V_237 :
F_7 ( V_219 -> V_227 , V_105 ,
V_238 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_12 ( struct V_211 * V_212 ,
struct V_213 * V_214 , int V_215 )
{
struct V_216 * V_217 = V_212 -> V_217 ;
struct V_218 * V_219 = F_5 ( V_217 ) ;
switch ( V_215 ) {
case V_235 :
F_7 ( V_219 -> V_227 , V_20 , 0x2 , 0x2 ) ;
F_7 ( V_219 -> V_227 , V_20 , 0x2 , 0x0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_13 ( struct V_211 * V_212 ,
struct V_213 * V_214 , int V_215 )
{
struct V_216 * V_217 = V_212 -> V_217 ;
struct V_218 * V_219 = F_5 ( V_217 ) ;
switch ( V_215 ) {
case V_235 :
F_7 ( V_219 -> V_227 , V_21 , 0x2 , 0x2 ) ;
F_7 ( V_219 -> V_227 , V_21 , 0x2 , 0x0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_14 ( struct V_211 * V_212 ,
struct V_213 * V_214 , int V_215 )
{
struct V_216 * V_217 = V_212 -> V_217 ;
struct V_218 * V_219 = F_5 ( V_217 ) ;
switch ( V_215 ) {
case V_235 :
F_7 ( V_219 -> V_227 , V_105 ,
V_239 | V_240 |
V_241 , V_239 |
V_240 | V_241 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_15 ( int V_242 , int V_222 )
{
int V_4 , V_243 [] = { 1 , 2 , 3 , 4 , 6 , 8 , 12 , 16 } ;
if ( V_242 <= 0 || V_222 <= 0 )
return - V_221 ;
V_222 = V_222 << 8 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_243 ) ; V_4 ++ )
if ( V_242 == V_222 * V_243 [ V_4 ] )
return V_4 ;
return - V_221 ;
}
static int F_16 ( struct V_244 * V_245 ,
struct V_246 * V_247 , struct V_248 * V_249 )
{
struct V_216 * V_217 = V_249 -> V_217 ;
struct V_218 * V_219 = F_5 ( V_217 ) ;
unsigned int V_250 = 0 , V_251 , V_252 ;
int V_253 , V_254 , V_255 ;
V_219 -> V_256 [ V_249 -> V_257 ] = F_17 ( V_247 ) ;
V_253 = F_15 ( V_219 -> V_226 , V_219 -> V_256 [ V_249 -> V_257 ] ) ;
if ( V_253 < 0 ) {
F_6 ( V_217 -> V_2 , L_2 ) ;
return - V_221 ;
}
V_255 = F_18 ( V_247 ) ;
if ( V_255 < 0 ) {
F_6 ( V_217 -> V_2 , L_3 , V_255 ) ;
return - V_221 ;
}
V_254 = V_255 > 32 ;
V_219 -> V_258 [ V_249 -> V_257 ] = V_219 -> V_256 [ V_249 -> V_257 ] * ( 32 << V_254 ) ;
F_19 ( V_249 -> V_2 , L_4 ,
V_219 -> V_258 [ V_249 -> V_257 ] , V_219 -> V_256 [ V_249 -> V_257 ] ) ;
F_19 ( V_249 -> V_2 , L_5 ,
V_254 , V_253 , V_249 -> V_257 ) ;
switch ( F_20 ( V_247 ) ) {
case 16 :
break;
case 20 :
V_250 |= V_259 ;
break;
case 24 :
V_250 |= V_260 ;
break;
case 8 :
V_250 |= V_261 ;
break;
default:
return - V_221 ;
}
switch ( V_249 -> V_257 ) {
case V_262 :
V_252 = V_263 ;
V_251 = V_253 << V_264 ;
F_7 ( V_219 -> V_227 , V_111 ,
V_265 , V_250 ) ;
F_7 ( V_219 -> V_227 , V_114 ,
V_252 , V_251 ) ;
break;
case V_266 :
V_252 = V_267 ;
V_251 = V_253 << V_268 ;
F_7 ( V_219 -> V_227 , V_112 ,
V_265 , V_250 ) ;
F_7 ( V_219 -> V_227 , V_114 ,
V_252 , V_251 ) ;
break;
case V_269 :
V_252 = V_270 | V_271 ;
V_251 = V_254 << V_272 |
V_253 << V_273 ;
F_7 ( V_219 -> V_227 , V_113 ,
V_265 , V_250 ) ;
F_7 ( V_219 -> V_227 , V_114 ,
V_252 , V_251 ) ;
break;
case V_274 :
V_252 = V_275 | V_276 ;
V_251 = V_254 << V_277 |
V_253 << V_278 ;
F_7 ( V_219 -> V_227 , V_110 ,
V_265 , V_250 ) ;
F_7 ( V_219 -> V_227 , V_114 ,
V_252 , V_251 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_21 ( struct V_248 * V_249 , unsigned int V_279 )
{
struct V_216 * V_217 = V_249 -> V_217 ;
struct V_218 * V_219 = F_5 ( V_217 ) ;
unsigned int V_280 = 0 ;
switch ( V_279 & V_281 ) {
case V_282 :
V_219 -> V_283 [ V_249 -> V_257 ] = 1 ;
break;
case V_284 :
V_280 |= V_285 ;
V_219 -> V_283 [ V_249 -> V_257 ] = 0 ;
break;
default:
return - V_221 ;
}
switch ( V_279 & V_286 ) {
case V_287 :
break;
case V_288 :
V_280 |= V_289 ;
break;
default:
return - V_221 ;
}
switch ( V_279 & V_290 ) {
case V_291 :
break;
case V_292 :
V_280 |= V_293 ;
break;
case V_294 :
V_280 |= V_295 ;
break;
case V_296 :
V_280 |= V_297 ;
break;
default:
return - V_221 ;
}
switch ( V_249 -> V_257 ) {
case V_262 :
F_7 ( V_219 -> V_227 , V_111 ,
V_298 | V_299 |
V_300 , V_280 ) ;
break;
case V_266 :
F_7 ( V_219 -> V_227 , V_112 ,
V_298 | V_299 |
V_300 , V_280 ) ;
break;
case V_269 :
F_7 ( V_219 -> V_227 , V_113 ,
V_298 | V_299 |
V_300 , V_280 ) ;
break;
case V_274 :
F_7 ( V_219 -> V_227 , V_110 ,
V_298 | V_299 |
V_300 , V_280 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_22 ( struct V_248 * V_249 ,
int V_301 , unsigned int V_302 , int V_303 )
{
struct V_216 * V_217 = V_249 -> V_217 ;
struct V_218 * V_219 = F_5 ( V_217 ) ;
unsigned int V_280 = 0 ;
if ( V_302 == V_219 -> V_226 && V_301 == V_219 -> V_304 )
return 0 ;
switch ( V_301 ) {
case V_305 :
V_280 |= V_306 ;
break;
case V_307 :
V_280 |= V_234 ;
break;
case V_308 :
V_280 |= V_309 ;
break;
default:
F_6 ( V_217 -> V_2 , L_6 , V_301 ) ;
return - V_221 ;
}
F_7 ( V_219 -> V_227 , V_119 ,
V_233 , V_280 ) ;
V_219 -> V_226 = V_302 ;
V_219 -> V_304 = V_301 ;
F_19 ( V_249 -> V_2 , L_7 , V_302 , V_301 ) ;
return 0 ;
}
static int F_23 ( const unsigned int V_310 ,
const unsigned int V_311 , struct V_312 * V_313 )
{
int V_314 = V_315 , V_316 = V_317 ;
int V_318 , V_223 , V_319 , V_320 , V_321 ;
int V_322 = 0 , V_323 = 0 , V_324 = 0 ;
int V_325 , V_326 = abs ( V_311 - V_310 ) ;
bool V_327 = false , V_328 = false ;
if ( V_329 < V_310 || V_330 > V_310 )
return - V_221 ;
V_318 = 100000000 / V_311 - 2 ;
if ( V_318 > V_331 )
V_318 = V_331 ;
for ( V_319 = 0 ; V_319 <= V_314 ; V_319 ++ ) {
V_321 = V_310 / ( V_318 + 2 ) ;
V_320 = V_311 / ( V_319 + 2 ) ;
if ( V_321 < 0 )
continue;
if ( V_321 == V_320 ) {
V_327 = true ;
V_322 = V_319 ;
goto V_332;
}
V_223 = abs ( V_321 - V_320 ) ;
if ( V_223 < V_326 ) {
V_327 = true ;
V_322 = V_319 ;
V_323 = V_324 ;
if ( V_223 == 0 )
goto V_332;
V_326 = V_223 ;
}
for ( V_324 = 0 ; V_324 <= V_316 ; V_324 ++ ) {
V_325 = V_321 / ( V_324 + 2 ) ;
V_223 = abs ( V_325 - V_320 ) ;
if ( V_223 < V_326 ) {
V_327 = false ;
V_322 = V_319 ;
V_323 = V_324 ;
if ( V_223 == 0 )
goto V_332;
V_326 = V_223 ;
}
}
}
F_24 ( L_8 ) ;
V_332:
V_313 -> V_327 = V_327 ;
V_313 -> V_328 = V_328 ;
V_313 -> V_333 = V_323 ;
V_313 -> V_334 = V_322 ;
V_313 -> V_335 = V_318 ;
return 0 ;
}
static int F_25 ( struct V_248 * V_249 , int V_336 , int V_230 ,
unsigned int V_310 , unsigned int V_311 )
{
struct V_216 * V_217 = V_249 -> V_217 ;
struct V_218 * V_219 = F_5 ( V_217 ) ;
struct V_312 V_313 ;
int V_337 ;
if ( V_230 == V_219 -> V_338 && V_310 == V_219 -> V_339 &&
V_311 == V_219 -> V_320 )
return 0 ;
if ( ! V_310 || ! V_311 ) {
F_19 ( V_217 -> V_2 , L_9 ) ;
V_219 -> V_339 = 0 ;
V_219 -> V_320 = 0 ;
F_7 ( V_219 -> V_227 , V_119 ,
V_233 , V_306 ) ;
return 0 ;
}
switch ( V_230 ) {
case V_340 :
F_7 ( V_219 -> V_227 , V_119 ,
V_341 , V_342 ) ;
break;
case V_343 :
case V_344 :
case V_345 :
case V_346 :
switch ( V_249 -> V_257 ) {
case V_262 :
F_7 ( V_219 -> V_227 , V_119 ,
V_341 , V_347 ) ;
break;
case V_266 :
F_7 ( V_219 -> V_227 , V_119 ,
V_341 , V_348 ) ;
break;
case V_269 :
F_7 ( V_219 -> V_227 , V_119 ,
V_341 , V_349 ) ;
break;
case V_274 :
F_7 ( V_219 -> V_227 , V_119 ,
V_341 , V_350 ) ;
break;
default:
break;
}
break;
default:
F_6 ( V_217 -> V_2 , L_10 , V_230 ) ;
return - V_221 ;
}
V_337 = F_23 ( V_310 , V_311 , & V_313 ) ;
if ( V_337 < 0 ) {
F_6 ( V_217 -> V_2 , L_11 , V_310 ) ;
return V_337 ;
}
F_19 ( V_217 -> V_2 , L_12 ,
V_313 . V_327 , V_313 . V_328 ,
( V_313 . V_327 ? 0 : V_313 . V_333 ) , V_313 . V_334 ,
( V_313 . V_328 ? 0 : V_313 . V_335 ) ) ;
F_26 ( V_219 -> V_227 , V_117 ,
V_313 . V_334 << V_351 |
V_313 . V_328 << V_352 |
( V_313 . V_328 ? 0 : V_313 . V_335 ) ) ;
F_26 ( V_219 -> V_227 , V_20 ,
( V_313 . V_327 ? 0 : V_313 . V_333 ) << V_353 |
V_313 . V_327 << V_354 ) ;
V_219 -> V_339 = V_310 ;
V_219 -> V_320 = V_311 ;
V_219 -> V_338 = V_230 ;
return 0 ;
}
static int F_27 ( struct V_216 * V_217 ,
enum V_355 V_356 )
{
struct V_218 * V_219 = F_5 ( V_217 ) ;
switch ( V_356 ) {
case V_357 :
break;
case V_358 :
if ( V_217 -> V_359 . V_360 == V_361 ) {
F_7 ( V_219 -> V_227 , V_104 ,
V_362 | V_363 ,
0x0055 ) ;
F_7 ( V_219 -> V_227 ,
V_364 + V_365 ,
0x0f00 , 0x0f00 ) ;
F_7 ( V_219 -> V_227 , V_104 ,
V_366 | V_367 |
V_368 | V_369 ,
V_366 | V_367 |
V_368 | V_369 ) ;
F_28 ( 20 ) ;
F_7 ( V_219 -> V_227 , V_104 ,
V_370 | V_371 ,
V_370 | V_371 ) ;
F_7 ( V_219 -> V_227 , V_105 ,
V_372 , V_372 ) ;
F_7 ( V_219 -> V_227 , V_208 ,
0x1 , 0x1 ) ;
}
break;
case V_361 :
break;
case V_373 :
F_7 ( V_219 -> V_227 , V_208 , 0x1 , 0x0 ) ;
F_26 ( V_219 -> V_227 , V_102 , 0x0000 ) ;
F_26 ( V_219 -> V_227 , V_103 , 0x0000 ) ;
F_26 ( V_219 -> V_227 , V_104 , 0x0000 ) ;
F_26 ( V_219 -> V_227 , V_105 , 0x0000 ) ;
F_7 ( V_219 -> V_227 ,
V_364 + V_365 , 0x0f00 , 0x0000 ) ;
break;
default:
break;
}
V_217 -> V_359 . V_360 = V_356 ;
return 0 ;
}
static int F_29 ( struct V_216 * V_217 )
{
struct V_218 * V_219 = F_5 ( V_217 ) ;
V_219 -> V_217 = V_217 ;
F_27 ( V_217 , V_373 ) ;
F_26 ( V_219 -> V_227 , V_208 , 0x0020 ) ;
F_26 ( V_219 -> V_227 , V_107 , 0x0c00 ) ;
return 0 ;
}
static int F_30 ( struct V_216 * V_217 )
{
struct V_218 * V_219 = F_5 ( V_217 ) ;
F_26 ( V_219 -> V_227 , V_8 , 0x10ec ) ;
return 0 ;
}
static int F_31 ( struct V_216 * V_217 )
{
struct V_218 * V_219 = F_5 ( V_217 ) ;
F_32 ( V_219 -> V_227 , true ) ;
F_33 ( V_219 -> V_227 ) ;
return 0 ;
}
static int F_34 ( struct V_216 * V_217 )
{
struct V_218 * V_219 = F_5 ( V_217 ) ;
F_32 ( V_219 -> V_227 , false ) ;
F_35 ( V_219 -> V_227 ) ;
return 0 ;
}
static int F_36 ( struct V_374 * V_375 ,
const struct V_376 * V_257 )
{
struct V_377 * V_378 = F_37 ( & V_375 -> V_2 ) ;
struct V_218 * V_219 ;
int V_337 ;
unsigned int V_232 ;
V_219 = F_38 ( & V_375 -> V_2 , sizeof( struct V_218 ) ,
V_379 ) ;
if ( V_219 == NULL )
return - V_380 ;
F_39 ( V_375 , V_219 ) ;
if ( V_378 )
V_219 -> V_378 = * V_378 ;
V_219 -> V_227 = F_40 ( V_375 , & V_381 ) ;
if ( F_41 ( V_219 -> V_227 ) ) {
V_337 = F_42 ( V_219 -> V_227 ) ;
F_6 ( & V_375 -> V_2 , L_13 ,
V_337 ) ;
return V_337 ;
}
F_9 ( V_219 -> V_227 , V_37 , & V_232 ) ;
if ( V_232 != V_382 ) {
F_6 ( & V_375 -> V_2 ,
L_14 , V_232 ) ;
return - V_383 ;
}
F_26 ( V_219 -> V_227 , V_8 , 0x10ec ) ;
V_337 = F_43 ( V_219 -> V_227 , V_384 ,
F_2 ( V_384 ) ) ;
if ( V_337 != 0 )
F_44 ( & V_375 -> V_2 , L_15 , V_337 ) ;
if ( V_219 -> V_378 . V_385 )
F_7 ( V_219 -> V_227 , V_39 ,
V_386 , V_386 ) ;
if ( V_219 -> V_378 . V_387 )
F_7 ( V_219 -> V_227 , V_39 ,
V_388 , V_388 ) ;
V_337 = F_45 ( & V_375 -> V_2 , & V_389 ,
V_390 , F_2 ( V_390 ) ) ;
if ( V_337 < 0 )
goto V_391;
return 0 ;
V_391:
return V_337 ;
}
static int F_46 ( struct V_374 * V_375 )
{
F_47 ( & V_375 -> V_2 ) ;
return 0 ;
}
static int T_1 F_48 ( void )
{
return F_49 ( & V_392 ) ;
}
static void T_2 F_50 ( void )
{
F_51 ( & V_392 ) ;
}
