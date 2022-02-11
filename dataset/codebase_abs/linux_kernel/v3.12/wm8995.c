static void F_1 ( struct V_1 * V_2 )
{
int V_3 = 1 ;
int V_4 = 0 ;
int V_5 , V_6 ;
V_5 = F_2 ( V_2 , V_7 ) ;
switch ( V_5 ) {
case V_8 :
F_3 ( V_2 -> V_9 , L_1 ) ;
V_4 = 2 << V_10 ;
break;
case V_11 :
F_3 ( V_2 -> V_9 , L_2 ) ;
V_4 = 1 << V_10 ;
break;
case V_12 :
F_3 ( V_2 -> V_9 , L_3 ) ;
V_4 = 0 << V_10 ;
break;
default:
F_3 ( V_2 -> V_9 , L_4 , V_5 ) ;
V_3 = 0 ;
break;
}
V_6 = F_2 ( V_2 , V_13 ) ;
if ( V_6 != V_5 ) {
F_3 ( V_2 -> V_9 , L_5 ) ;
V_3 = 0 ;
}
if ( V_3 ) {
F_3 ( V_2 -> V_9 , L_6 ) ;
F_4 ( V_2 , V_14 ,
V_15 |
V_16 ,
V_4 | V_17 ) ;
} else {
F_3 ( V_2 -> V_9 , L_7 ) ;
F_4 ( V_2 , V_14 ,
V_15 , 0 ) ;
}
}
static int F_5 ( struct V_18 * V_4 ,
struct V_18 * V_19 )
{
unsigned int V_5 ;
const char * V_20 ;
V_5 = F_2 ( V_4 -> V_2 , V_21 ) ;
if ( V_5 & V_22 )
V_20 = L_8 ;
else
V_20 = L_9 ;
return ! strcmp ( V_4 -> V_23 , V_20 ) ;
}
static int F_6 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_7 ( V_25 ) ;
int V_28 ;
V_28 = F_8 ( V_25 , V_27 ) ;
F_1 ( V_2 ) ;
return V_28 ;
}
static int F_9 ( struct V_18 * V_29 ,
struct V_24 * V_25 , int V_30 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 ;
V_2 = V_29 -> V_2 ;
V_32 = F_10 ( V_2 ) ;
switch ( V_30 ) {
case V_33 :
F_4 ( V_2 , V_34 ,
V_35 |
V_36 ,
V_37 |
V_38 ) ;
F_4 ( V_2 , V_39 ,
V_40 |
V_41 ,
V_42 |
V_43 ) ;
break;
case V_44 :
F_4 ( V_2 , V_45 ,
V_46 , 0 ) ;
break;
}
return 0 ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned int V_5 , unsigned int V_47 , unsigned int V_48 )
{
int V_49 = 10 ;
F_3 ( V_2 -> V_9 , L_10 ,
V_50 , V_5 , V_47 , V_48 ) ;
F_12 ( V_2 , V_5 , V_47 ) ;
while ( V_49 -- ) {
F_13 ( 10 ) ;
V_47 = F_2 ( V_2 , V_51 ) ;
if ( ( V_47 & V_48 ) == V_48 )
return;
}
F_14 ( V_2 -> V_9 , L_11 ) ;
}
static int F_15 ( struct V_18 * V_29 ,
struct V_24 * V_25 , int V_30 )
{
struct V_1 * V_2 ;
unsigned int V_5 ;
V_2 = V_29 -> V_2 ;
V_5 = F_2 ( V_2 , V_39 ) ;
switch ( V_30 ) {
case V_52 :
F_4 ( V_2 , V_45 ,
V_46 , V_53 ) ;
F_13 ( 5 ) ;
F_4 ( V_2 , V_34 ,
V_35 |
V_36 ,
V_37 | V_38 ) ;
F_16 ( 20 ) ;
V_5 |= V_42 | V_43 ;
F_12 ( V_2 , V_39 , V_5 ) ;
F_12 ( V_2 , V_54 , V_55 |
V_56 ) ;
F_11 ( V_2 , V_57 ,
V_58 |
V_59 ,
V_60 |
V_61 ) ;
V_5 |= V_62 | V_63 |
V_64 | V_65 ;
F_12 ( V_2 , V_39 , V_5 ) ;
break;
case V_44 :
F_4 ( V_2 , V_39 ,
V_66 |
V_67 |
V_68 |
V_69 , 0 ) ;
F_4 ( V_2 , V_39 ,
V_40 |
V_41 , 0 ) ;
F_12 ( V_2 , V_54 , 0 ) ;
F_4 ( V_2 , V_34 ,
V_35 |
V_36 ,
0 ) ;
break;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_70 )
{
struct V_31 * V_32 ;
int V_71 ;
int V_72 = 0 ;
int V_73 ;
V_32 = F_10 ( V_2 ) ;
if ( V_70 )
V_73 = 4 ;
else
V_73 = 0 ;
switch ( V_32 -> V_74 [ V_70 ] ) {
case V_75 :
V_71 = V_32 -> V_76 [ 0 ] ;
break;
case V_77 :
V_72 |= 0x8 ;
V_71 = V_32 -> V_76 [ 1 ] ;
break;
case V_78 :
V_72 |= 0x10 ;
V_71 = V_32 -> V_79 [ 0 ] . V_80 ;
break;
case V_81 :
V_72 |= 0x18 ;
V_71 = V_32 -> V_79 [ 1 ] . V_80 ;
break;
default:
return - V_82 ;
}
if ( V_71 >= 13500000 ) {
V_71 /= 2 ;
V_72 |= V_83 ;
F_3 ( V_2 -> V_9 , L_12 ,
V_70 + 1 , V_71 ) ;
}
V_32 -> V_84 [ V_70 ] = V_71 ;
F_4 ( V_2 , V_85 + V_73 ,
V_86 | V_87 ,
V_72 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
int V_88 , V_89 ;
V_32 = F_10 ( V_2 ) ;
F_17 ( V_2 , 0 ) ;
F_17 ( V_2 , 1 ) ;
if ( V_32 -> V_84 [ 0 ] == V_32 -> V_84 [ 1 ] )
return 0 ;
if ( V_32 -> V_84 [ 0 ] < V_32 -> V_84 [ 1 ] )
V_89 = V_22 ;
else
V_89 = 0 ;
V_88 = F_4 ( V_2 , V_21 ,
V_90 , V_89 ) ;
if ( ! V_88 )
return 0 ;
F_19 ( & V_2 -> V_91 ) ;
return 0 ;
}
static int F_20 ( struct V_18 * V_29 ,
struct V_24 * V_25 , int V_30 )
{
struct V_1 * V_2 ;
V_2 = V_29 -> V_2 ;
switch ( V_30 ) {
case V_33 :
return F_18 ( V_2 ) ;
case V_92 :
F_18 ( V_2 ) ;
break;
}
return 0 ;
}
static bool F_21 ( struct V_93 * V_9 , unsigned int V_5 )
{
switch ( V_5 ) {
case V_94 :
case V_34 :
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
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_45 :
case V_14 :
case V_54 :
case V_57 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_51 :
case V_39 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_85 :
case V_127 :
case V_128 :
case V_129 :
case V_21 :
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
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
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
case V_207 :
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
case V_217 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
case V_222 :
case V_223 :
case V_224 :
case V_225 :
case V_226 :
case V_227 :
case V_228 :
case V_229 :
case V_230 :
case V_231 :
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
case V_247 :
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_7 :
case V_13 :
case V_257 :
case V_258 :
case V_259 :
case V_260 :
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
case V_268 :
case V_269 :
case V_270 :
case V_271 :
case V_272 :
case V_273 :
case V_274 :
case V_275 :
case V_276 :
case V_277 :
case V_278 :
case V_279 :
case V_280 :
case V_281 :
case V_282 :
case V_283 :
case V_284 :
case V_285 :
case V_286 :
case V_287 :
case V_288 :
case V_289 :
case V_290 :
case V_291 :
case V_292 :
case V_293 :
case V_294 :
return true ;
default:
return false ;
}
}
static bool F_22 ( struct V_93 * V_9 , unsigned int V_5 )
{
switch ( V_5 ) {
case V_94 :
case V_51 :
case V_283 :
case V_284 :
case V_288 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_133 :
return true ;
default:
return false ;
}
}
static int F_23 ( struct V_295 * V_296 , int V_297 )
{
struct V_1 * V_2 = V_296 -> V_2 ;
int V_298 ;
switch ( V_296 -> V_299 ) {
case 0 :
V_298 = V_170 ;
break;
case 1 :
V_298 = V_229 ;
break;
default:
return - V_82 ;
}
F_4 ( V_2 , V_298 , V_300 ,
! ! V_297 << V_301 ) ;
return 0 ;
}
static int F_24 ( struct V_295 * V_296 , unsigned int V_302 )
{
struct V_1 * V_2 ;
int V_303 ;
int V_70 ;
V_2 = V_296 -> V_2 ;
V_303 = 0 ;
switch ( V_302 & V_304 ) {
case V_305 :
break;
case V_306 :
V_303 = V_307 ;
break;
default:
F_14 ( V_296 -> V_9 , L_13 ) ;
return - V_82 ;
}
V_70 = 0 ;
switch ( V_302 & V_308 ) {
case V_309 :
V_70 |= V_310 ;
case V_311 :
V_70 |= ( 0x3 << V_312 ) ;
break;
case V_313 :
V_70 |= ( 0x2 << V_312 ) ;
break;
case V_314 :
break;
case V_315 :
V_70 |= ( 0x1 << V_312 ) ;
break;
default:
F_14 ( V_296 -> V_9 , L_14 ) ;
return - V_82 ;
}
switch ( V_302 & V_308 ) {
case V_311 :
case V_309 :
switch ( V_302 & V_316 ) {
case V_317 :
break;
case V_318 :
V_70 |= V_319 ;
break;
default:
return - V_82 ;
}
break;
case V_313 :
case V_314 :
case V_315 :
switch ( V_302 & V_316 ) {
case V_317 :
break;
case V_320 :
V_70 |= V_319 | V_310 ;
break;
case V_318 :
V_70 |= V_319 ;
break;
case V_321 :
V_70 |= V_310 ;
break;
default:
return - V_82 ;
}
break;
default:
return - V_82 ;
}
F_4 ( V_2 , V_144 ,
V_322 |
V_323 |
V_324 , V_70 ) ;
F_4 ( V_2 , V_146 ,
V_325 , V_303 ) ;
return 0 ;
}
static int F_25 ( struct V_326 * V_327 ,
struct V_328 * V_329 ,
struct V_295 * V_296 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 ;
int V_330 ;
int V_331 ;
int V_332 ;
int V_333 ;
int V_334 ;
int V_335 ;
int V_336 , V_337 ;
int V_338 , V_339 , V_340 , V_341 , V_342 ;
V_2 = V_296 -> V_2 ;
V_32 = F_10 ( V_2 ) ;
switch ( V_296 -> V_299 ) {
case 0 :
V_330 = V_144 ;
V_331 = V_147 ;
V_333 = V_131 ;
if ( V_327 -> V_343 == V_344 ) {
V_332 = V_149 ;
} else {
V_332 = V_148 ;
F_3 ( V_2 -> V_9 , L_15 ) ;
}
break;
case 1 :
V_330 = V_152 ;
V_331 = V_155 ;
V_333 = V_132 ;
if ( V_327 -> V_343 == V_344 ) {
V_332 = V_157 ;
} else {
V_332 = V_156 ;
F_3 ( V_2 -> V_9 , L_16 ) ;
}
break;
default:
return - V_82 ;
}
V_334 = F_26 ( V_329 ) ;
if ( V_334 < 0 )
return V_334 ;
V_335 = 0 ;
switch ( F_27 ( V_329 ) ) {
case V_345 :
break;
case V_346 :
V_335 |= ( 0x1 << V_347 ) ;
break;
case V_348 :
V_335 |= ( 0x2 << V_347 ) ;
break;
case V_349 :
V_335 |= ( 0x3 << V_347 ) ;
break;
default:
F_14 ( V_296 -> V_9 , L_17 ,
F_27 ( V_329 ) ) ;
return - V_82 ;
}
for ( V_338 = 0 ; V_338 < F_28 ( V_350 ) ; ++ V_338 )
if ( V_350 [ V_338 ] == F_29 ( V_329 ) )
break;
if ( V_338 == F_28 ( V_350 ) ) {
F_14 ( V_296 -> V_9 , L_18 ,
F_29 ( V_329 ) ) ;
return - V_82 ;
}
V_339 = V_338 << V_351 ;
F_3 ( V_296 -> V_9 , L_19 , V_350 [ V_338 ] ) ;
F_3 ( V_296 -> V_9 , L_20 ,
V_296 -> V_299 + 1 , V_32 -> V_84 [ V_296 -> V_299 ] , V_334 ) ;
V_340 = 1 ;
V_341 = abs ( ( V_352 [ 1 ] * F_29 ( V_329 ) )
- V_32 -> V_84 [ V_296 -> V_299 ] ) ;
for ( V_338 = 2 ; V_338 < F_28 ( V_352 ) ; V_338 ++ ) {
V_342 = abs ( ( V_352 [ V_338 ] * F_29 ( V_329 ) )
- V_32 -> V_84 [ V_296 -> V_299 ] ) ;
if ( V_342 >= V_341 )
continue;
V_340 = V_338 ;
V_341 = V_342 ;
}
V_339 |= V_340 ;
F_3 ( V_296 -> V_9 , L_21 ,
V_296 -> V_299 + 1 , V_352 [ V_340 ] ) ;
V_340 = 0 ;
V_337 = 0 ;
for ( V_338 = 0 ; V_338 < F_28 ( V_353 ) ; V_338 ++ ) {
V_342 = ( V_32 -> V_84 [ V_296 -> V_299 ] * 10 / V_353 [ V_338 ] ) - V_334 ;
if ( V_342 < 0 )
break;
V_340 = V_338 ;
}
V_337 |= V_340 << V_354 ;
V_334 = V_32 -> V_84 [ V_296 -> V_299 ] * 10 / V_353 [ V_340 ] ;
F_3 ( V_296 -> V_9 , L_22 ,
V_353 [ V_340 ] , V_334 ) ;
V_336 = V_334 / F_29 ( V_329 ) ;
F_3 ( V_296 -> V_9 , L_23 ,
V_336 , V_334 / V_336 ) ;
F_4 ( V_2 , V_330 ,
V_355 , V_335 ) ;
F_4 ( V_2 , V_331 ,
V_356 , V_337 ) ;
F_4 ( V_2 , V_332 ,
V_357 , V_336 ) ;
F_4 ( V_2 , V_333 ,
V_358 |
V_359 , V_339 ) ;
return 0 ;
}
static int F_30 ( struct V_295 * V_360 , int V_361 )
{
struct V_1 * V_2 = V_360 -> V_2 ;
int V_5 , V_47 , V_48 ;
switch ( V_360 -> V_299 ) {
case 0 :
V_5 = V_146 ;
V_48 = V_362 ;
break;
case 1 :
V_5 = V_154 ;
V_48 = V_363 ;
break;
case 2 :
V_5 = V_98 ;
V_48 = V_364 ;
break;
default:
return - V_82 ;
}
if ( V_361 )
V_47 = V_48 ;
else
V_47 = 0 ;
return F_4 ( V_2 , V_5 , V_48 , V_47 ) ;
}
static int F_31 ( struct V_365 * V_79 ,
int V_366 , int V_367 )
{
T_1 V_368 ;
unsigned int V_369 , V_370 , V_371 ;
F_32 ( L_24 , V_366 , V_367 ) ;
V_79 -> V_372 = 0 ;
while ( V_366 > 13500000 ) {
V_79 -> V_372 ++ ;
V_366 /= 2 ;
if ( V_79 -> V_372 > 3 )
return - V_82 ;
}
F_32 ( L_25 , V_79 -> V_372 , V_366 ) ;
V_79 -> V_373 = 3 ;
while ( V_367 * ( V_79 -> V_373 + 1 ) < 90000000 ) {
V_79 -> V_373 ++ ;
if ( V_79 -> V_373 > 63 )
return - V_82 ;
}
V_367 *= V_79 -> V_373 + 1 ;
F_32 ( L_26 , V_79 -> V_373 , V_367 ) ;
if ( V_366 > 1000000 ) {
V_79 -> V_374 = 0 ;
} else if ( V_366 > 256000 ) {
V_79 -> V_374 = 1 ;
V_366 *= 2 ;
} else if ( V_366 > 128000 ) {
V_79 -> V_374 = 2 ;
V_366 *= 4 ;
} else if ( V_366 > 64000 ) {
V_79 -> V_374 = 3 ;
V_366 *= 8 ;
} else {
V_79 -> V_374 = 4 ;
V_366 *= 16 ;
}
F_32 ( L_27 , V_79 -> V_374 , V_366 ) ;
V_370 = V_367 / V_366 ;
V_79 -> V_375 = V_370 ;
V_371 = V_367 % V_366 ;
F_32 ( L_28 , V_371 ) ;
V_368 = V_376 * ( long long ) V_371 ;
F_33 ( V_368 , V_366 ) ;
V_369 = V_368 & 0xFFFFFFFF ;
if ( ( V_369 % 10 ) >= 5 )
V_369 += 5 ;
V_79 -> V_377 = V_369 / 10 ;
F_32 ( L_29 , V_79 -> V_375 , V_79 -> V_377 ) ;
return 0 ;
}
static int F_34 ( struct V_295 * V_296 , int V_299 ,
int V_378 , unsigned int V_366 ,
unsigned int V_367 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 ;
int V_379 , V_28 ;
struct V_365 V_79 ;
T_2 V_5 , V_335 , V_380 ;
V_2 = V_296 -> V_2 ;
V_32 = F_10 ( V_2 ) ;
V_335 = F_2 ( V_2 , V_85 )
& V_381 ;
V_380 = F_2 ( V_2 , V_128 )
& V_382 ;
switch ( V_299 ) {
case V_383 :
V_379 = 0 ;
V_299 = 0 ;
break;
case V_384 :
V_379 = 0x20 ;
V_299 = 1 ;
break;
default:
return - V_82 ;
}
switch ( V_378 ) {
case 0 :
if ( V_367 )
return - V_82 ;
break;
case V_385 :
case V_386 :
case V_387 :
case V_388 :
break;
default:
return - V_82 ;
}
if ( V_32 -> V_79 [ V_299 ] . V_378 == V_378 &&
V_32 -> V_79 [ V_299 ] . V_389 == V_366 && V_32 -> V_79 [ V_299 ] . V_80 == V_367 )
return 0 ;
if ( V_367 )
V_28 = F_31 ( & V_79 , V_366 , V_367 ) ;
else
V_28 = F_31 ( & V_79 , V_32 -> V_79 [ V_299 ] . V_389 ,
V_32 -> V_79 [ V_299 ] . V_80 ) ;
if ( V_28 < 0 )
return V_28 ;
F_4 ( V_2 , V_85 ,
V_390 , 0 ) ;
F_4 ( V_2 , V_128 ,
V_391 , 0 ) ;
F_4 ( V_2 , V_134 + V_379 ,
V_392 , 0 ) ;
V_5 = ( V_79 . V_373 << V_393 ) |
( V_79 . V_374 << V_394 ) ;
F_4 ( V_2 , V_135 + V_379 ,
V_395 |
V_396 , V_5 ) ;
F_12 ( V_2 , V_136 + V_379 , V_79 . V_377 ) ;
F_4 ( V_2 , V_137 + V_379 ,
V_397 ,
V_79 . V_375 << V_398 ) ;
F_4 ( V_2 , V_138 + V_379 ,
V_399 |
V_400 ,
( V_79 . V_372 << V_401 ) |
( V_378 - 1 ) ) ;
if ( V_367 )
F_4 ( V_2 , V_134 + V_379 ,
V_392 , V_402 ) ;
V_32 -> V_79 [ V_299 ] . V_389 = V_366 ;
V_32 -> V_79 [ V_299 ] . V_80 = V_367 ;
V_32 -> V_79 [ V_299 ] . V_378 = V_378 ;
F_4 ( V_2 , V_85 ,
V_390 , V_335 ) ;
F_4 ( V_2 , V_128 ,
V_391 , V_380 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
static int F_35 ( struct V_295 * V_296 ,
int V_403 , unsigned int V_404 , int V_405 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 ;
V_2 = V_296 -> V_2 ;
V_32 = F_10 ( V_2 ) ;
switch ( V_296 -> V_299 ) {
case 0 :
case 1 :
break;
default:
return - V_82 ;
}
switch ( V_403 ) {
case V_75 :
V_32 -> V_74 [ V_296 -> V_299 ] = V_75 ;
V_32 -> V_76 [ 0 ] = V_404 ;
F_3 ( V_296 -> V_9 , L_30 ,
V_296 -> V_299 + 1 , V_404 ) ;
break;
case V_77 :
V_32 -> V_74 [ V_296 -> V_299 ] = V_75 ;
V_32 -> V_76 [ 1 ] = V_404 ;
F_3 ( V_296 -> V_9 , L_31 ,
V_296 -> V_299 + 1 , V_404 ) ;
break;
case V_78 :
V_32 -> V_74 [ V_296 -> V_299 ] = V_78 ;
F_3 ( V_296 -> V_9 , L_32 , V_296 -> V_299 + 1 ) ;
break;
case V_81 :
V_32 -> V_74 [ V_296 -> V_299 ] = V_81 ;
F_3 ( V_296 -> V_9 , L_33 , V_296 -> V_299 + 1 ) ;
break;
case V_406 :
default:
F_14 ( V_296 -> V_9 , L_34 , V_403 ) ;
return - V_82 ;
}
F_18 ( V_2 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
enum V_407 V_408 )
{
struct V_31 * V_32 ;
int V_28 ;
V_32 = F_10 ( V_2 ) ;
switch ( V_408 ) {
case V_409 :
case V_410 :
break;
case V_411 :
if ( V_2 -> V_91 . V_412 == V_413 ) {
V_28 = F_37 ( F_28 ( V_32 -> V_414 ) ,
V_32 -> V_414 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_38 ( V_32 -> V_415 ) ;
if ( V_28 ) {
F_14 ( V_2 -> V_9 ,
L_35 , V_28 ) ;
return V_28 ;
}
F_4 ( V_2 , V_34 ,
V_416 , V_417 ) ;
}
break;
case V_413 :
F_4 ( V_2 , V_34 ,
V_416 , 0 ) ;
F_39 ( F_28 ( V_32 -> V_414 ) ,
V_32 -> V_414 ) ;
break;
}
V_2 -> V_91 . V_412 = V_408 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
F_36 ( V_2 , V_413 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
F_36 ( V_2 , V_411 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
int V_338 ;
V_32 = F_10 ( V_2 ) ;
F_36 ( V_2 , V_413 ) ;
for ( V_338 = 0 ; V_338 < F_28 ( V_32 -> V_414 ) ; ++ V_338 )
F_43 ( V_32 -> V_414 [ V_338 ] . V_418 ,
& V_32 -> V_419 [ V_338 ] ) ;
F_44 ( F_28 ( V_32 -> V_414 ) , V_32 -> V_414 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
int V_338 ;
int V_28 ;
V_32 = F_10 ( V_2 ) ;
V_32 -> V_2 = V_2 ;
V_2 -> V_420 = V_32 -> V_415 ;
V_28 = F_46 ( V_2 , 16 , 16 , V_421 ) ;
if ( V_28 < 0 ) {
F_14 ( V_2 -> V_9 , L_36 , V_28 ) ;
return V_28 ;
}
for ( V_338 = 0 ; V_338 < F_28 ( V_32 -> V_414 ) ; V_338 ++ )
V_32 -> V_414 [ V_338 ] . V_422 = V_423 [ V_338 ] ;
V_28 = F_47 ( V_2 -> V_9 , F_28 ( V_32 -> V_414 ) ,
V_32 -> V_414 ) ;
if ( V_28 ) {
F_14 ( V_2 -> V_9 , L_37 , V_28 ) ;
return V_28 ;
}
V_32 -> V_419 [ 0 ] . V_424 = V_425 ;
V_32 -> V_419 [ 1 ] . V_424 = V_426 ;
V_32 -> V_419 [ 2 ] . V_424 = V_427 ;
V_32 -> V_419 [ 3 ] . V_424 = V_428 ;
V_32 -> V_419 [ 4 ] . V_424 = V_429 ;
V_32 -> V_419 [ 5 ] . V_424 = V_430 ;
V_32 -> V_419 [ 6 ] . V_424 = V_431 ;
V_32 -> V_419 [ 7 ] . V_424 = V_432 ;
for ( V_338 = 0 ; V_338 < F_28 ( V_32 -> V_414 ) ; V_338 ++ ) {
V_28 = F_48 ( V_32 -> V_414 [ V_338 ] . V_418 ,
& V_32 -> V_419 [ V_338 ] ) ;
if ( V_28 ) {
F_14 ( V_2 -> V_9 ,
L_38 ,
V_28 ) ;
}
}
V_28 = F_37 ( F_28 ( V_32 -> V_414 ) ,
V_32 -> V_414 ) ;
if ( V_28 ) {
F_14 ( V_2 -> V_9 , L_39 , V_28 ) ;
goto V_433;
}
V_28 = F_2 ( V_2 , V_94 ) ;
if ( V_28 < 0 ) {
F_14 ( V_2 -> V_9 , L_40 , V_28 ) ;
goto V_434;
}
if ( V_28 != 0x8995 ) {
F_14 ( V_2 -> V_9 , L_41 , V_28 ) ;
V_28 = - V_82 ;
goto V_434;
}
V_28 = F_12 ( V_2 , V_94 , 0 ) ;
if ( V_28 < 0 ) {
F_14 ( V_2 -> V_9 , L_42 , V_28 ) ;
goto V_434;
}
F_36 ( V_2 , V_411 ) ;
F_4 ( V_2 , V_163 ,
V_435 , V_436 ) ;
F_4 ( V_2 , V_167 ,
V_437 , V_438 ) ;
F_4 ( V_2 , V_227 ,
V_439 , V_440 ) ;
F_4 ( V_2 , V_161 ,
V_441 , V_442 ) ;
F_4 ( V_2 , V_165 ,
V_443 , V_444 ) ;
F_4 ( V_2 , V_225 ,
V_445 , V_444 ) ;
F_4 ( V_2 , V_103 ,
V_446 , V_447 ) ;
F_4 ( V_2 , V_105 ,
V_448 , V_449 ) ;
F_4 ( V_2 , V_100 ,
V_450 , V_451 ) ;
F_1 ( V_2 ) ;
F_49 ( V_2 , V_452 ,
F_28 ( V_452 ) ) ;
F_50 ( & V_2 -> V_91 , V_453 ,
F_28 ( V_453 ) ) ;
F_51 ( & V_2 -> V_91 , V_454 ,
F_28 ( V_454 ) ) ;
return 0 ;
V_434:
F_39 ( F_28 ( V_32 -> V_414 ) , V_32 -> V_414 ) ;
V_433:
F_44 ( F_28 ( V_32 -> V_414 ) , V_32 -> V_414 ) ;
return V_28 ;
}
static int F_52 ( struct V_455 * V_456 )
{
struct V_31 * V_32 ;
int V_28 ;
V_32 = F_53 ( & V_456 -> V_9 , sizeof( * V_32 ) , V_457 ) ;
if ( ! V_32 )
return - V_458 ;
F_54 ( V_456 , V_32 ) ;
V_32 -> V_415 = F_55 ( V_456 , & V_459 ) ;
if ( F_56 ( V_32 -> V_415 ) ) {
V_28 = F_57 ( V_32 -> V_415 ) ;
F_14 ( & V_456 -> V_9 , L_43 , V_28 ) ;
return V_28 ;
}
V_28 = F_58 ( & V_456 -> V_9 ,
& V_460 , V_461 ,
F_28 ( V_461 ) ) ;
return V_28 ;
}
static int F_59 ( struct V_455 * V_456 )
{
F_60 ( & V_456 -> V_9 ) ;
return 0 ;
}
static int F_61 ( struct V_462 * V_463 ,
const struct V_464 * V_299 )
{
struct V_31 * V_32 ;
int V_28 ;
V_32 = F_53 ( & V_463 -> V_9 , sizeof( * V_32 ) , V_457 ) ;
if ( ! V_32 )
return - V_458 ;
F_62 ( V_463 , V_32 ) ;
V_32 -> V_415 = F_63 ( V_463 , & V_459 ) ;
if ( F_56 ( V_32 -> V_415 ) ) {
V_28 = F_57 ( V_32 -> V_415 ) ;
F_14 ( & V_463 -> V_9 , L_43 , V_28 ) ;
return V_28 ;
}
V_28 = F_58 ( & V_463 -> V_9 ,
& V_460 , V_461 ,
F_28 ( V_461 ) ) ;
if ( V_28 < 0 )
F_14 ( & V_463 -> V_9 , L_44 , V_28 ) ;
return V_28 ;
}
static int F_64 ( struct V_462 * V_465 )
{
F_60 ( & V_465 -> V_9 ) ;
return 0 ;
}
static int T_3 F_65 ( void )
{
int V_28 = 0 ;
#if F_66 ( V_466 ) || F_66 ( V_467 )
V_28 = F_67 ( & V_468 ) ;
if ( V_28 ) {
F_68 ( V_469 L_45 ,
V_28 ) ;
}
#endif
#if F_66 ( V_470 )
V_28 = F_69 ( & V_471 ) ;
if ( V_28 ) {
F_68 ( V_469 L_46 ,
V_28 ) ;
}
#endif
return V_28 ;
}
static void T_4 F_70 ( void )
{
#if F_66 ( V_466 ) || F_66 ( V_467 )
F_71 ( & V_468 ) ;
#endif
#if F_66 ( V_470 )
F_72 ( & V_471 ) ;
#endif
}
