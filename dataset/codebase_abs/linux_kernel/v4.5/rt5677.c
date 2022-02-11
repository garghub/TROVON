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
case V_36 :
case V_37 :
case V_38 :
case V_9 :
case V_39 :
case V_40 :
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
case V_10 :
case V_11 :
case V_70 :
case V_71 :
case V_12 :
case V_72 :
case V_73 :
case V_13 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_14 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_15 :
case V_16 :
case V_89 :
case V_90 :
case V_91 :
case V_17 :
case V_92 :
case V_93 :
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
case V_18 :
case V_105 :
case V_106 :
case V_107 :
case V_19 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
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
case V_20 :
case V_21 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_22 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_23 :
case V_153 :
case V_24 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_25 :
case V_26 :
case V_27 :
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
case V_28 :
case V_193 :
case V_194 :
case V_195 :
case V_29 :
case V_196 :
case V_197 :
case V_198 :
case V_30 :
case V_199 :
case V_200 :
case V_201 :
case V_31 :
case V_202 :
case V_203 :
case V_204 :
case V_32 :
case V_205 :
case V_206 :
case V_207 :
case V_208 :
case V_209 :
case V_210 :
case V_33 :
case V_34 :
case V_35 :
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
F_15 ( V_212 -> V_230 , V_104 , 0x2 , 0x2 ) ;
V_212 -> V_231 = true ;
} else {
F_15 ( V_212 -> V_230 , V_104 , 0x2 , 0x0 ) ;
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
F_15 ( V_212 -> V_230 , V_102 ,
V_237 , 0x0 ) ;
F_15 ( V_212 -> V_230 , V_103 ,
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
F_6 ( V_212 -> V_230 , V_105 , 0x07ff ) ;
F_6 ( V_212 -> V_230 , V_104 , 0x07fd ) ;
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
F_15 ( V_212 -> V_230 , V_104 , 0x1 , 0x0 ) ;
F_19 ( V_212 -> V_230 , false ) ;
F_18 ( V_212 -> V_230 , true ) ;
} else if ( ! V_229 && V_232 ) {
V_232 = false ;
F_18 ( V_212 -> V_230 , false ) ;
F_19 ( V_212 -> V_230 , true ) ;
F_15 ( V_212 -> V_230 , V_104 , 0x1 , 0x1 ) ;
F_13 ( V_217 , false ) ;
F_6 ( V_212 -> V_230 , V_104 , 0x0001 ) ;
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
if ( F_30 ( V_217 ) == V_258 )
F_16 ( V_217 , V_212 -> V_257 ) ;
return 0 ;
}
static int F_31 ( struct V_259 * V_260 ,
struct V_251 * V_252 , int V_261 )
{
struct V_216 * V_217 = F_32 ( V_260 -> V_262 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
int V_263 , V_264 ;
V_264 = V_212 -> V_265 / F_33 ( V_212 -> V_230 ,
V_112 , V_266 ) ;
V_263 = F_34 ( V_264 ) ;
if ( V_263 < 0 )
F_7 ( V_217 -> V_2 , L_6 ) ;
else
F_15 ( V_212 -> V_230 , V_89 ,
V_267 , V_263 << V_268 ) ;
return V_263 ;
}
static int F_35 ( struct V_259 * V_269 ,
struct V_259 * V_270 )
{
struct V_216 * V_217 = F_32 ( V_269 -> V_262 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_271 ;
F_10 ( V_212 -> V_230 , V_119 , & V_271 ) ;
V_271 &= V_272 ;
if ( V_271 == V_273 )
return 1 ;
else
return 0 ;
}
static int F_36 ( struct V_259 * V_269 ,
struct V_259 * V_270 )
{
struct V_216 * V_217 = F_32 ( V_269 -> V_262 ) ;
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
static int F_37 ( struct V_259 * V_269 ,
struct V_259 * V_270 )
{
struct V_216 * V_217 = F_32 ( V_269 -> V_262 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
if ( V_212 -> V_265 > V_212 -> V_275 [ V_276 ] * 384 )
return 1 ;
return 0 ;
}
int F_38 ( struct V_216 * V_217 ,
unsigned int V_277 , unsigned int V_278 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_279 = 0 , V_280 = 0 ;
unsigned int V_281 = 0 , V_282 = 0 ;
unsigned int V_283 = 0 , V_284 = 0 ;
unsigned int V_285 = 0 , V_286 = 0 ;
unsigned int V_287 = 0 , V_288 = 0 ;
unsigned int V_289 = 0 , V_290 = 0 ;
switch ( V_278 ) {
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
case V_301 :
case V_302 :
case V_303 :
break;
default:
return - V_304 ;
}
if ( V_277 & V_305 ) {
V_279 |= V_306 ;
V_280 = ( V_280 & ~ V_306 )
| ( V_278 << V_307 ) ;
}
if ( V_277 & V_308 ) {
V_279 |= V_309 ;
V_280 = ( V_280 & ~ V_309 )
| ( V_278 << V_310 ) ;
}
if ( V_277 & V_311 ) {
V_279 |= V_312 ;
V_280 = ( V_280 & ~ V_312 )
| ( V_278 << V_313 ) ;
}
if ( V_279 )
F_15 ( V_212 -> V_230 , V_123 , V_279 ,
V_280 ) ;
if ( V_277 & V_314 ) {
V_281 |= V_315 ;
V_282 = ( V_282 & ~ V_315 )
| ( V_278 << V_316 ) ;
}
if ( V_277 & V_317 ) {
V_281 |= V_318 ;
V_282 = ( V_282 & ~ V_318 )
| ( V_278 << V_319 ) ;
}
if ( V_277 & V_320 ) {
V_281 |= V_321 ;
V_282 = ( V_282 & ~ V_321 )
| ( V_278 << V_322 ) ;
}
if ( V_277 & V_323 ) {
V_281 |= V_324 ;
V_282 = ( V_282 & ~ V_324 )
| ( V_278 << V_325 ) ;
}
if ( V_281 )
F_15 ( V_212 -> V_230 , V_124 , V_281 ,
V_282 ) ;
if ( V_277 & V_326 ) {
V_283 |= V_327 ;
V_284 = ( V_284 & ~ V_327 )
| ( V_278 << V_328 ) ;
}
if ( V_277 & V_329 ) {
V_283 |= V_330 ;
V_284 = ( V_284 & ~ V_330 )
| ( V_278 << V_331 ) ;
}
if ( V_277 & V_332 ) {
V_283 |= V_333 ;
V_284 = ( V_284 & ~ V_333 )
| ( V_278 << V_334 ) ;
}
if ( V_277 & V_335 ) {
V_283 |= V_336 ;
V_284 = ( V_284 & ~ V_336 )
| ( V_278 << V_337 ) ;
}
if ( V_283 )
F_15 ( V_212 -> V_230 , V_125 , V_283 ,
V_284 ) ;
if ( V_277 & V_338 ) {
V_285 |= V_339 ;
V_286 = ( V_286 & ~ V_339 )
| ( V_278 << V_340 ) ;
}
if ( V_277 & V_341 ) {
V_285 |= V_342 ;
V_286 = ( V_286 & ~ V_342 )
| ( V_278 << V_343 ) ;
}
if ( V_285 )
F_15 ( V_212 -> V_230 , V_126 , V_285 ,
V_286 ) ;
if ( V_277 & V_344 ) {
V_287 |= V_345 ;
V_288 = ( V_288 & ~ V_345 )
| ( V_278 << V_346 ) ;
}
if ( V_277 & V_347 ) {
V_287 |= V_348 ;
V_288 = ( V_288 & ~ V_348 )
| ( V_278 << V_349 ) ;
}
if ( V_287 )
F_15 ( V_212 -> V_230 , V_127 , V_287 ,
V_288 ) ;
if ( V_277 & V_350 ) {
V_289 |= V_351 ;
V_290 = ( V_290 & ~ V_351 )
| ( ( V_278 - 1 ) << V_352 ) ;
}
if ( V_277 & V_353 ) {
V_289 |= V_354 ;
V_290 = ( V_290 & ~ V_354 )
| ( ( V_278 - 1 ) << V_355 ) ;
}
if ( V_277 & V_356 ) {
V_289 |= V_357 ;
V_290 = ( V_290 & ~ V_357 )
| ( ( V_278 - 1 ) << V_358 ) ;
}
if ( V_277 & V_359 ) {
V_289 |= V_360 ;
V_290 = ( V_290 & ~ V_360 )
| ( ( V_278 - 1 ) << V_361 ) ;
}
if ( V_289 )
F_15 ( V_212 -> V_230 , V_128 , V_289 ,
V_290 ) ;
return 0 ;
}
static int F_39 ( struct V_259 * V_269 ,
struct V_259 * V_270 )
{
struct V_216 * V_217 = F_32 ( V_269 -> V_262 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_362 ;
switch ( V_269 -> V_274 ) {
case 11 :
F_10 ( V_212 -> V_230 , V_125 , & V_362 ) ;
V_362 = ( V_362 & V_327 ) >>
V_328 ;
if ( V_362 >= V_292 &&
V_362 <= V_297 )
return 1 ;
break;
case 10 :
F_10 ( V_212 -> V_230 , V_125 , & V_362 ) ;
V_362 = ( V_362 & V_330 ) >>
V_331 ;
if ( V_362 >= V_292 &&
V_362 <= V_297 )
return 1 ;
break;
case 9 :
F_10 ( V_212 -> V_230 , V_125 , & V_362 ) ;
V_362 = ( V_362 & V_333 ) >>
V_334 ;
if ( V_362 >= V_292 &&
V_362 <= V_297 )
return 1 ;
break;
case 8 :
F_10 ( V_212 -> V_230 , V_125 , & V_362 ) ;
V_362 = ( V_362 & V_336 ) >>
V_337 ;
if ( V_362 >= V_292 &&
V_362 <= V_297 )
return 1 ;
break;
case 7 :
F_10 ( V_212 -> V_230 , V_126 , & V_362 ) ;
V_362 = ( V_362 & V_339 ) >>
V_340 ;
if ( V_362 >= V_292 &&
V_362 <= V_297 )
return 1 ;
break;
case 6 :
F_10 ( V_212 -> V_230 , V_126 , & V_362 ) ;
V_362 = ( V_362 & V_342 ) >>
V_343 ;
if ( V_362 >= V_292 &&
V_362 <= V_297 )
return 1 ;
break;
default:
break;
}
return 0 ;
}
static int F_40 ( struct V_259 * V_260 ,
struct V_251 * V_252 , int V_261 )
{
struct V_216 * V_217 = F_32 ( V_260 -> V_262 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_261 ) {
case V_363 :
F_15 ( V_212 -> V_230 , V_103 ,
V_364 , V_364 ) ;
break;
case V_365 :
F_15 ( V_212 -> V_230 , V_103 ,
V_364 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_41 ( struct V_259 * V_260 ,
struct V_251 * V_252 , int V_261 )
{
struct V_216 * V_217 = F_32 ( V_260 -> V_262 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_261 ) {
case V_363 :
F_15 ( V_212 -> V_230 , V_103 ,
V_366 , V_366 ) ;
break;
case V_365 :
F_15 ( V_212 -> V_230 , V_103 ,
V_366 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_42 ( struct V_259 * V_260 ,
struct V_251 * V_252 , int V_261 )
{
struct V_216 * V_217 = F_32 ( V_260 -> V_262 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_261 ) {
case V_367 :
F_15 ( V_212 -> V_230 , V_116 , 0x2 , 0x2 ) ;
break;
case V_363 :
F_15 ( V_212 -> V_230 , V_116 , 0x2 , 0x0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_43 ( struct V_259 * V_260 ,
struct V_251 * V_252 , int V_261 )
{
struct V_216 * V_217 = F_32 ( V_260 -> V_262 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_261 ) {
case V_367 :
F_15 ( V_212 -> V_230 , V_118 , 0x2 , 0x2 ) ;
break;
case V_363 :
F_15 ( V_212 -> V_230 , V_118 , 0x2 , 0x0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_44 ( struct V_259 * V_260 ,
struct V_251 * V_252 , int V_261 )
{
struct V_216 * V_217 = F_32 ( V_260 -> V_262 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_261 ) {
case V_363 :
F_15 ( V_212 -> V_230 , V_103 ,
V_368 | V_369 |
V_370 , V_368 |
V_369 | V_370 ) ;
break;
case V_365 :
F_15 ( V_212 -> V_230 , V_103 ,
V_368 | V_369 |
V_370 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_45 ( struct V_259 * V_260 ,
struct V_251 * V_252 , int V_261 )
{
struct V_216 * V_217 = F_32 ( V_260 -> V_262 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_214 ;
switch ( V_261 ) {
case V_367 :
F_10 ( V_212 -> V_230 , V_75 , & V_214 ) ;
if ( V_214 & V_371 )
F_15 ( V_212 -> V_230 , V_74 ,
V_372 ,
V_373 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_46 ( struct V_259 * V_260 ,
struct V_251 * V_252 , int V_261 )
{
struct V_216 * V_217 = F_32 ( V_260 -> V_262 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_214 ;
switch ( V_261 ) {
case V_367 :
F_10 ( V_212 -> V_230 , V_80 , & V_214 ) ;
if ( V_214 & V_374 )
F_15 ( V_212 -> V_230 , V_79 ,
V_375 ,
V_376 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_47 ( struct V_259 * V_260 ,
struct V_251 * V_252 , int V_261 )
{
struct V_216 * V_217 = F_32 ( V_260 -> V_262 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_261 ) {
case V_363 :
if ( F_30 ( V_217 ) != V_377 &&
! V_212 -> V_378 ) {
F_48 ( 20 ) ;
F_15 ( V_212 -> V_230 , V_102 ,
V_379 | V_380 ,
V_379 | V_380 ) ;
V_212 -> V_378 = true ;
}
break;
default:
return 0 ;
}
return 0 ;
}
static int F_49 ( struct V_259 * V_260 ,
struct V_251 * V_252 , int V_261 )
{
switch ( V_261 ) {
case V_363 :
F_50 ( 50 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_51 ( struct V_381 * V_382 ,
struct V_383 * V_384 , struct V_385 * V_386 )
{
struct V_216 * V_217 = V_386 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_387 = 0 , V_388 , V_389 ;
int V_390 , V_391 , V_392 ;
V_212 -> V_275 [ V_386 -> V_393 ] = F_52 ( V_384 ) ;
V_390 = F_53 ( V_212 -> V_265 , V_212 -> V_275 [ V_386 -> V_393 ] ) ;
if ( V_390 < 0 ) {
F_7 ( V_217 -> V_2 , L_7 ,
V_212 -> V_265 , V_212 -> V_275 [ V_386 -> V_393 ] ) ;
return - V_304 ;
}
V_392 = F_54 ( V_384 ) ;
if ( V_392 < 0 ) {
F_7 ( V_217 -> V_2 , L_8 , V_392 ) ;
return - V_304 ;
}
V_391 = V_392 > 32 ;
V_212 -> V_394 [ V_386 -> V_393 ] = V_212 -> V_275 [ V_386 -> V_393 ] * ( 32 << V_391 ) ;
F_55 ( V_386 -> V_2 , L_9 ,
V_212 -> V_394 [ V_386 -> V_393 ] , V_212 -> V_275 [ V_386 -> V_393 ] ) ;
F_55 ( V_386 -> V_2 , L_10 ,
V_391 , V_390 , V_386 -> V_393 ) ;
switch ( F_56 ( V_384 ) ) {
case 16 :
break;
case 20 :
V_387 |= V_395 ;
break;
case 24 :
V_387 |= V_396 ;
break;
case 8 :
V_387 |= V_397 ;
break;
default:
return - V_304 ;
}
switch ( V_386 -> V_393 ) {
case V_276 :
V_389 = V_398 ;
V_388 = V_390 << V_266 ;
F_15 ( V_212 -> V_230 , V_109 ,
V_399 , V_387 ) ;
F_15 ( V_212 -> V_230 , V_112 ,
V_389 , V_388 ) ;
break;
case V_400 :
V_389 = V_401 ;
V_388 = V_390 << V_402 ;
F_15 ( V_212 -> V_230 , V_110 ,
V_399 , V_387 ) ;
F_15 ( V_212 -> V_230 , V_112 ,
V_389 , V_388 ) ;
break;
case V_403 :
V_389 = V_404 | V_405 ;
V_388 = V_391 << V_406 |
V_390 << V_407 ;
F_15 ( V_212 -> V_230 , V_111 ,
V_399 , V_387 ) ;
F_15 ( V_212 -> V_230 , V_112 ,
V_389 , V_388 ) ;
break;
case V_408 :
V_389 = V_409 | V_410 ;
V_388 = V_391 << V_411 |
V_390 << V_412 ;
F_15 ( V_212 -> V_230 , V_108 ,
V_399 , V_387 ) ;
F_15 ( V_212 -> V_230 , V_112 ,
V_389 , V_388 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_57 ( struct V_385 * V_386 , unsigned int V_413 )
{
struct V_216 * V_217 = V_386 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_414 = 0 ;
switch ( V_413 & V_415 ) {
case V_416 :
V_212 -> V_417 [ V_386 -> V_393 ] = 1 ;
break;
case V_418 :
V_414 |= V_419 ;
V_212 -> V_417 [ V_386 -> V_393 ] = 0 ;
break;
default:
return - V_304 ;
}
switch ( V_413 & V_420 ) {
case V_421 :
break;
case V_422 :
V_414 |= V_423 ;
break;
default:
return - V_304 ;
}
switch ( V_413 & V_424 ) {
case V_425 :
break;
case V_426 :
V_414 |= V_427 ;
break;
case V_428 :
V_414 |= V_429 ;
break;
case V_430 :
V_414 |= V_431 ;
break;
default:
return - V_304 ;
}
switch ( V_386 -> V_393 ) {
case V_276 :
F_15 ( V_212 -> V_230 , V_109 ,
V_432 | V_433 |
V_434 , V_414 ) ;
break;
case V_400 :
F_15 ( V_212 -> V_230 , V_110 ,
V_432 | V_433 |
V_434 , V_414 ) ;
break;
case V_403 :
F_15 ( V_212 -> V_230 , V_111 ,
V_432 | V_433 |
V_434 , V_414 ) ;
break;
case V_408 :
F_15 ( V_212 -> V_230 , V_108 ,
V_432 | V_433 |
V_434 , V_414 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_58 ( struct V_385 * V_386 ,
int V_435 , unsigned int V_436 , int V_437 )
{
struct V_216 * V_217 = V_386 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_414 = 0 ;
if ( V_436 == V_212 -> V_265 && V_435 == V_212 -> V_438 )
return 0 ;
switch ( V_435 ) {
case V_439 :
V_414 |= V_440 ;
break;
case V_441 :
V_414 |= V_273 ;
break;
case V_442 :
V_414 |= V_443 ;
break;
default:
F_7 ( V_217 -> V_2 , L_11 , V_435 ) ;
return - V_304 ;
}
F_15 ( V_212 -> V_230 , V_119 ,
V_272 , V_414 ) ;
V_212 -> V_265 = V_436 ;
V_212 -> V_438 = V_435 ;
F_55 ( V_386 -> V_2 , L_12 , V_436 , V_435 ) ;
return 0 ;
}
static int F_59 ( const unsigned int V_444 ,
const unsigned int V_445 , struct V_446 * V_447 )
{
if ( V_448 > V_444 )
return - V_304 ;
return F_60 ( V_444 , V_445 , V_447 ) ;
}
static int F_61 ( struct V_385 * V_386 , int V_449 , int V_269 ,
unsigned int V_444 , unsigned int V_445 )
{
struct V_216 * V_217 = V_386 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
struct V_446 V_447 ;
int V_218 ;
if ( V_269 == V_212 -> V_450 && V_444 == V_212 -> V_451 &&
V_445 == V_212 -> V_452 )
return 0 ;
if ( ! V_444 || ! V_445 ) {
F_55 ( V_217 -> V_2 , L_13 ) ;
V_212 -> V_451 = 0 ;
V_212 -> V_452 = 0 ;
F_15 ( V_212 -> V_230 , V_119 ,
V_272 , V_440 ) ;
return 0 ;
}
switch ( V_269 ) {
case V_453 :
F_15 ( V_212 -> V_230 , V_119 ,
V_454 , V_455 ) ;
break;
case V_456 :
case V_457 :
case V_458 :
case V_459 :
switch ( V_386 -> V_393 ) {
case V_276 :
F_15 ( V_212 -> V_230 , V_119 ,
V_454 , V_460 ) ;
break;
case V_400 :
F_15 ( V_212 -> V_230 , V_119 ,
V_454 , V_461 ) ;
break;
case V_403 :
F_15 ( V_212 -> V_230 , V_119 ,
V_454 , V_462 ) ;
break;
case V_408 :
F_15 ( V_212 -> V_230 , V_119 ,
V_454 , V_463 ) ;
break;
default:
break;
}
break;
default:
F_7 ( V_217 -> V_2 , L_14 , V_269 ) ;
return - V_304 ;
}
V_218 = F_59 ( V_444 , V_445 , & V_447 ) ;
if ( V_218 < 0 ) {
F_7 ( V_217 -> V_2 , L_15 , V_444 ) ;
return V_218 ;
}
F_55 ( V_217 -> V_2 , L_16 ,
V_447 . V_464 , ( V_447 . V_464 ? 0 : V_447 . V_465 ) ,
V_447 . V_466 , V_447 . V_467 ) ;
F_6 ( V_212 -> V_230 , V_115 ,
V_447 . V_466 << V_468 | V_447 . V_467 ) ;
F_6 ( V_212 -> V_230 , V_116 ,
( V_447 . V_464 ? 0 : V_447 . V_465 ) << V_469 |
V_447 . V_464 << V_470 ) ;
V_212 -> V_451 = V_444 ;
V_212 -> V_452 = V_445 ;
V_212 -> V_450 = V_269 ;
return 0 ;
}
static int F_62 ( struct V_385 * V_386 , unsigned int V_471 ,
unsigned int V_472 , int V_473 , int V_474 )
{
struct V_216 * V_217 = V_386 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_271 = 0 , V_475 = 0 ;
if ( V_472 || V_471 )
V_271 |= ( 1 << 12 ) ;
switch ( V_473 ) {
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
switch ( V_474 ) {
case 20 :
V_271 |= ( 1 << 8 ) ;
break;
case 25 :
V_475 = 0x8080 ;
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
switch ( V_386 -> V_393 ) {
case V_276 :
F_15 ( V_212 -> V_230 , V_74 , 0x1f00 ,
V_271 ) ;
F_15 ( V_212 -> V_230 , V_208 , 0x8000 ,
V_475 ) ;
break;
case V_400 :
F_15 ( V_212 -> V_230 , V_79 , 0x1f00 ,
V_271 ) ;
F_15 ( V_212 -> V_230 , V_208 , 0x80 ,
V_475 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_63 ( struct V_216 * V_217 ,
enum V_476 V_477 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_477 ) {
case V_377 :
break;
case V_478 :
if ( F_30 ( V_217 ) == V_479 ) {
F_16 ( V_217 , false ) ;
F_15 ( V_212 -> V_230 , V_102 ,
V_237 | V_480 ,
0x0055 ) ;
F_15 ( V_212 -> V_230 ,
V_235 + V_236 ,
0x0f00 , 0x0f00 ) ;
F_15 ( V_212 -> V_230 , V_102 ,
V_379 | V_380 |
V_481 | V_482 |
V_483 | V_484 ,
V_481 | V_482 |
V_483 | V_484 ) ;
V_212 -> V_378 = false ;
F_15 ( V_212 -> V_230 , V_103 ,
V_485 , V_485 ) ;
F_15 ( V_212 -> V_230 , V_208 ,
0x1 , 0x1 ) ;
}
break;
case V_479 :
break;
case V_258 :
F_15 ( V_212 -> V_230 , V_208 , 0x1 , 0x0 ) ;
F_6 ( V_212 -> V_230 , V_100 , 0x0000 ) ;
F_6 ( V_212 -> V_230 , V_101 , 0x0000 ) ;
F_6 ( V_212 -> V_230 , V_102 , 0x0022 ) ;
F_6 ( V_212 -> V_230 , V_103 , 0x0000 ) ;
F_15 ( V_212 -> V_230 ,
V_235 + V_236 , 0x0f00 , 0x0000 ) ;
if ( V_212 -> V_257 )
F_16 ( V_217 , true ) ;
break;
default:
break;
}
return 0 ;
}
static inline struct V_211 * F_64 ( struct V_486 * V_487 )
{
return F_65 ( V_487 , struct V_211 , V_486 ) ;
}
static void F_66 ( struct V_486 * V_487 , unsigned V_488 , int V_214 )
{
struct V_211 * V_212 = F_64 ( V_487 ) ;
switch ( V_488 ) {
case V_489 ... V_490 :
F_15 ( V_212 -> V_230 , V_161 ,
0x1 << ( V_488 * 3 + 1 ) , ! ! V_214 << ( V_488 * 3 + 1 ) ) ;
break;
case V_491 :
F_15 ( V_212 -> V_230 , V_162 ,
V_492 , ! ! V_214 << V_493 ) ;
break;
default:
break;
}
}
static int F_67 ( struct V_486 * V_487 ,
unsigned V_488 , int V_214 )
{
struct V_211 * V_212 = F_64 ( V_487 ) ;
switch ( V_488 ) {
case V_489 ... V_490 :
F_15 ( V_212 -> V_230 , V_161 ,
0x3 << ( V_488 * 3 + 1 ) ,
( 0x2 | ! ! V_214 ) << ( V_488 * 3 + 1 ) ) ;
break;
case V_491 :
F_15 ( V_212 -> V_230 , V_162 ,
V_494 | V_492 ,
V_495 | ! ! V_214 << V_493 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_68 ( struct V_486 * V_487 , unsigned V_488 )
{
struct V_211 * V_212 = F_64 ( V_487 ) ;
int V_214 , V_218 ;
V_218 = F_10 ( V_212 -> V_230 , V_27 , & V_214 ) ;
if ( V_218 < 0 )
return V_218 ;
return ( V_214 & ( 0x1 << V_488 ) ) >> V_488 ;
}
static int F_69 ( struct V_486 * V_487 , unsigned V_488 )
{
struct V_211 * V_212 = F_64 ( V_487 ) ;
switch ( V_488 ) {
case V_489 ... V_490 :
F_15 ( V_212 -> V_230 , V_161 ,
0x1 << ( V_488 * 3 + 2 ) , 0x0 ) ;
break;
case V_491 :
F_15 ( V_212 -> V_230 , V_162 ,
V_494 , V_496 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_70 ( struct V_211 * V_212 , unsigned V_488 ,
int V_214 )
{
int V_274 ;
switch ( V_488 ) {
case V_489 ... V_497 :
V_274 = 2 * ( 1 - V_488 ) ;
F_15 ( V_212 -> V_230 ,
V_235 + V_498 ,
0x3 << V_274 ,
( V_214 & 0x3 ) << V_274 ) ;
break;
case V_499 ... V_491 :
V_274 = 2 * ( 9 - V_488 ) ;
F_15 ( V_212 -> V_230 ,
V_235 + V_500 ,
0x3 << V_274 ,
( V_214 & 0x3 ) << V_274 ) ;
break;
default:
break;
}
}
static int F_71 ( struct V_486 * V_487 , unsigned V_488 )
{
struct V_211 * V_212 = F_64 ( V_487 ) ;
struct V_501 * V_502 = V_212 -> V_503 ;
int V_504 ;
if ( V_488 >= V_489 && V_488 <= V_499 ) {
if ( ( V_212 -> V_505 . V_506 == 1 && V_488 == V_489 ) ||
( V_212 -> V_505 . V_506 == 2 &&
V_488 == V_497 ) ||
( V_212 -> V_505 . V_506 == 3 &&
V_488 == V_499 ) ) {
V_504 = V_507 ;
} else {
return - V_234 ;
}
}
if ( V_488 >= V_508 && V_488 <= V_491 ) {
if ( ( V_212 -> V_505 . V_509 == 1 && V_488 == V_508 ) ||
( V_212 -> V_505 . V_509 == 2 &&
V_488 == V_490 ) ||
( V_212 -> V_505 . V_509 == 3 &&
V_488 == V_491 ) ) {
V_504 = V_510 ;
} else if ( ( V_212 -> V_505 . V_511 == 1 &&
V_488 == V_508 ) ||
( V_212 -> V_505 . V_511 == 2 &&
V_488 == V_490 ) ||
( V_212 -> V_505 . V_511 == 3 &&
V_488 == V_491 ) ) {
V_504 = V_512 ;
} else {
return - V_234 ;
}
}
return F_72 ( V_502 , V_504 ) ;
}
static void F_73 ( struct V_513 * V_514 )
{
struct V_211 * V_212 = F_74 ( V_514 ) ;
int V_218 ;
V_212 -> V_486 = V_515 ;
V_212 -> V_486 . V_516 = V_517 ;
V_212 -> V_486 . V_518 = & V_514 -> V_2 ;
V_212 -> V_486 . V_519 = - 1 ;
V_218 = F_75 ( & V_212 -> V_486 ) ;
if ( V_218 != 0 )
F_7 ( & V_514 -> V_2 , L_17 , V_218 ) ;
}
static void F_76 ( struct V_513 * V_514 )
{
struct V_211 * V_212 = F_74 ( V_514 ) ;
F_77 ( & V_212 -> V_486 ) ;
}
static void F_70 ( struct V_211 * V_212 , unsigned V_488 ,
int V_214 )
{
}
static void F_73 ( struct V_513 * V_514 )
{
}
static void F_76 ( struct V_513 * V_514 )
{
}
static int F_78 ( struct V_216 * V_217 )
{
struct V_520 * V_262 = F_79 ( V_217 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
int V_4 ;
V_212 -> V_217 = V_217 ;
if ( V_212 -> V_505 . V_521 == V_522 ) {
F_80 ( V_262 ,
V_523 ,
F_2 ( V_523 ) ) ;
} else {
F_80 ( V_262 ,
V_524 ,
F_2 ( V_524 ) ) ;
}
F_81 ( V_217 , V_258 ) ;
F_6 ( V_212 -> V_230 , V_208 , 0x0020 ) ;
F_6 ( V_212 -> V_230 , V_105 , 0x0c00 ) ;
for ( V_4 = 0 ; V_4 < V_517 ; V_4 ++ )
F_70 ( V_212 , V_4 , V_212 -> V_505 . V_525 [ V_4 ] ) ;
if ( V_212 -> V_503 ) {
F_15 ( V_212 -> V_230 , V_160 , 0x8000 ,
0x8000 ) ;
F_15 ( V_212 -> V_230 , V_208 , 0x0018 ,
0x0008 ) ;
if ( V_212 -> V_505 . V_506 )
F_15 ( V_212 -> V_230 , V_157 ,
V_526 ,
V_212 -> V_505 . V_506 <<
V_527 ) ;
if ( V_212 -> V_505 . V_509 )
F_15 ( V_212 -> V_230 , V_157 ,
V_528 ,
V_212 -> V_505 . V_509 <<
V_529 ) ;
if ( V_212 -> V_505 . V_511 )
F_15 ( V_212 -> V_230 , V_157 ,
V_530 ,
V_212 -> V_505 . V_511 <<
V_531 ) ;
}
F_82 ( & V_212 -> V_219 ) ;
F_82 ( & V_212 -> V_532 ) ;
return 0 ;
}
static int F_83 ( struct V_216 * V_217 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
F_6 ( V_212 -> V_230 , V_8 , 0x10ec ) ;
F_84 ( V_212 -> V_533 , 0 ) ;
F_84 ( V_212 -> V_534 , 1 ) ;
return 0 ;
}
static int F_85 ( struct V_216 * V_217 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
if ( ! V_212 -> V_257 ) {
F_18 ( V_212 -> V_230 , true ) ;
F_23 ( V_212 -> V_230 ) ;
F_84 ( V_212 -> V_533 , 0 ) ;
F_84 ( V_212 -> V_534 , 1 ) ;
}
return 0 ;
}
static int F_86 ( struct V_216 * V_217 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
if ( ! V_212 -> V_257 ) {
V_212 -> V_450 = 0 ;
V_212 -> V_451 = 0 ;
V_212 -> V_452 = 0 ;
F_84 ( V_212 -> V_533 , 1 ) ;
F_84 ( V_212 -> V_534 , 0 ) ;
if ( V_212 -> V_533 || V_212 -> V_534 )
F_50 ( 10 ) ;
F_18 ( V_212 -> V_230 , false ) ;
F_24 ( V_212 -> V_230 ) ;
}
return 0 ;
}
static int F_87 ( void * V_535 , unsigned int V_3 , unsigned int * V_271 )
{
struct V_513 * V_536 = V_535 ;
struct V_211 * V_212 = F_74 ( V_536 ) ;
if ( V_212 -> V_231 ) {
if ( V_3 > 0xff ) {
F_5 ( & V_212 -> V_532 ) ;
F_11 ( V_212 , V_107 ,
V_3 & 0xff ) ;
F_12 ( V_212 , V_19 , V_271 ) ;
F_8 ( & V_212 -> V_532 ) ;
} else {
F_12 ( V_212 , V_3 , V_271 ) ;
}
} else {
F_10 ( V_212 -> V_220 , V_3 , V_271 ) ;
}
return 0 ;
}
static int F_88 ( void * V_535 , unsigned int V_3 , unsigned int V_271 )
{
struct V_513 * V_536 = V_535 ;
struct V_211 * V_212 = F_74 ( V_536 ) ;
if ( V_212 -> V_231 ) {
if ( V_3 > 0xff ) {
F_5 ( & V_212 -> V_532 ) ;
F_11 ( V_212 , V_107 ,
V_3 & 0xff ) ;
F_11 ( V_212 , V_19 ,
V_271 ) ;
F_8 ( & V_212 -> V_532 ) ;
} else {
F_11 ( V_212 , V_3 , V_271 ) ;
}
} else {
F_6 ( V_212 -> V_220 , V_3 , V_271 ) ;
}
return 0 ;
}
static void F_89 ( struct V_211 * V_212 ,
struct V_1 * V_2 )
{
V_212 -> V_505 . V_537 = F_90 ( V_2 ,
L_18 ) ;
V_212 -> V_505 . V_538 = F_90 ( V_2 ,
L_19 ) ;
V_212 -> V_505 . V_539 = F_90 ( V_2 ,
L_20 ) ;
V_212 -> V_505 . V_540 = F_90 ( V_2 ,
L_21 ) ;
V_212 -> V_505 . V_541 = F_90 ( V_2 ,
L_22 ) ;
F_91 ( V_2 , L_23 ,
V_212 -> V_505 . V_525 , V_517 ) ;
F_92 ( V_2 , L_24 ,
& V_212 -> V_505 . V_506 ) ;
F_92 ( V_2 , L_25 ,
& V_212 -> V_505 . V_509 ) ;
F_92 ( V_2 , L_26 ,
& V_212 -> V_505 . V_511 ) ;
}
static int F_93 ( struct V_513 * V_514 )
{
int V_218 ;
struct V_211 * V_212 = F_74 ( V_514 ) ;
if ( ! V_212 -> V_505 . V_506 &&
! V_212 -> V_505 . V_509 &&
! V_212 -> V_505 . V_511 )
return 0 ;
if ( ! V_514 -> V_504 ) {
F_7 ( & V_514 -> V_2 , L_27 ) ;
return - V_304 ;
}
V_218 = F_94 ( V_212 -> V_230 , V_514 -> V_504 ,
V_542 | V_543 | V_544 , 0 ,
& V_545 , & V_212 -> V_503 ) ;
if ( V_218 != 0 ) {
F_7 ( & V_514 -> V_2 , L_28 , V_218 ) ;
return V_218 ;
}
return 0 ;
}
static void F_95 ( struct V_513 * V_514 )
{
struct V_211 * V_212 = F_74 ( V_514 ) ;
if ( V_212 -> V_503 )
F_96 ( V_514 -> V_504 , V_212 -> V_503 ) ;
}
static int F_97 ( struct V_513 * V_514 ,
const struct V_546 * V_393 )
{
struct V_547 * V_505 = F_98 ( & V_514 -> V_2 ) ;
struct V_211 * V_212 ;
int V_218 ;
unsigned int V_271 ;
V_212 = F_99 ( & V_514 -> V_2 , sizeof( struct V_211 ) ,
V_548 ) ;
if ( V_212 == NULL )
return - V_549 ;
F_100 ( V_514 , V_212 ) ;
V_212 -> type = V_393 -> V_550 ;
if ( V_505 )
V_212 -> V_505 = * V_505 ;
else
F_89 ( V_212 , & V_514 -> V_2 ) ;
V_212 -> V_533 = F_101 ( & V_514 -> V_2 ,
L_29 , V_551 ) ;
if ( F_102 ( V_212 -> V_533 ) ) {
V_218 = F_103 ( V_212 -> V_533 ) ;
F_7 ( & V_514 -> V_2 , L_30 , V_218 ) ;
return V_218 ;
}
V_212 -> V_534 = F_101 ( & V_514 -> V_2 ,
L_31 , V_552 ) ;
if ( F_102 ( V_212 -> V_534 ) ) {
V_218 = F_103 ( V_212 -> V_534 ) ;
F_7 ( & V_514 -> V_2 , L_32 , V_218 ) ;
return V_218 ;
}
if ( V_212 -> V_533 || V_212 -> V_534 ) {
F_50 ( 10 ) ;
}
V_212 -> V_220 = F_104 ( V_514 ,
& V_553 ) ;
if ( F_102 ( V_212 -> V_220 ) ) {
V_218 = F_103 ( V_212 -> V_220 ) ;
F_7 ( & V_514 -> V_2 , L_33 ,
V_218 ) ;
return V_218 ;
}
V_212 -> V_230 = F_105 ( & V_514 -> V_2 , NULL , V_514 , & V_554 ) ;
if ( F_102 ( V_212 -> V_230 ) ) {
V_218 = F_103 ( V_212 -> V_230 ) ;
F_7 ( & V_514 -> V_2 , L_33 ,
V_218 ) ;
return V_218 ;
}
F_10 ( V_212 -> V_230 , V_35 , & V_271 ) ;
if ( V_271 != V_555 ) {
F_7 ( & V_514 -> V_2 ,
L_34 , V_271 ) ;
return - V_556 ;
}
F_6 ( V_212 -> V_230 , V_8 , 0x10ec ) ;
V_218 = F_106 ( V_212 -> V_230 , V_557 ,
F_2 ( V_557 ) ) ;
if ( V_218 != 0 )
F_107 ( & V_514 -> V_2 , L_35 , V_218 ) ;
if ( V_212 -> V_505 . V_537 )
F_15 ( V_212 -> V_230 , V_37 ,
V_558 , V_558 ) ;
if ( V_212 -> V_505 . V_538 )
F_15 ( V_212 -> V_230 , V_37 ,
V_559 , V_559 ) ;
if ( V_212 -> V_505 . V_539 )
F_15 ( V_212 -> V_230 , V_36 ,
V_560 , V_560 ) ;
if ( V_212 -> V_505 . V_540 )
F_15 ( V_212 -> V_230 , V_36 ,
V_561 , V_561 ) ;
if ( V_212 -> V_505 . V_541 )
F_15 ( V_212 -> V_230 , V_36 ,
V_562 , V_562 ) ;
if ( V_212 -> V_505 . V_521 == V_522 ) {
F_15 ( V_212 -> V_230 , V_210 ,
V_563 ,
V_564 ) ;
F_15 ( V_212 -> V_230 , V_161 ,
V_565 ,
V_566 ) ;
}
if ( V_212 -> V_505 . V_567 )
F_15 ( V_212 -> V_230 , V_38 ,
V_568 ,
V_569 ) ;
F_73 ( V_514 ) ;
F_93 ( V_514 ) ;
return F_108 ( & V_514 -> V_2 , & V_570 ,
V_571 , F_2 ( V_571 ) ) ;
}
static int F_109 ( struct V_513 * V_514 )
{
F_110 ( & V_514 -> V_2 ) ;
F_95 ( V_514 ) ;
F_76 ( V_514 ) ;
return 0 ;
}
