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
struct V_28 * V_29 = F_7 ( V_25 ) ;
struct V_18 * V_30 = V_29 -> V_31 [ 0 ] ;
struct V_1 * V_2 ;
int V_32 ;
V_2 = V_30 -> V_2 ;
V_32 = F_8 ( V_25 , V_27 ) ;
F_1 ( V_2 ) ;
return V_32 ;
}
static int F_9 ( struct V_18 * V_30 ,
struct V_24 * V_25 , int V_33 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
V_2 = V_30 -> V_2 ;
V_35 = F_10 ( V_2 ) ;
switch ( V_33 ) {
case V_36 :
F_4 ( V_2 , V_37 ,
V_38 |
V_39 ,
V_40 |
V_41 ) ;
F_4 ( V_2 , V_42 ,
V_43 |
V_44 ,
V_45 |
V_46 ) ;
break;
case V_47 :
F_4 ( V_2 , V_48 ,
V_49 , 0 ) ;
break;
}
return 0 ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned int V_5 , unsigned int V_50 , unsigned int V_51 )
{
int V_52 = 10 ;
F_3 ( V_2 -> V_9 , L_10 ,
V_53 , V_5 , V_50 , V_51 ) ;
F_12 ( V_2 , V_5 , V_50 ) ;
while ( V_52 -- ) {
F_13 ( 10 ) ;
V_50 = F_2 ( V_2 , V_54 ) ;
if ( ( V_50 & V_51 ) == V_51 )
return;
}
F_14 ( V_2 -> V_9 , L_11 ) ;
}
static int F_15 ( struct V_18 * V_30 ,
struct V_24 * V_25 , int V_33 )
{
struct V_1 * V_2 ;
unsigned int V_5 ;
V_2 = V_30 -> V_2 ;
V_5 = F_2 ( V_2 , V_42 ) ;
switch ( V_33 ) {
case V_55 :
F_4 ( V_2 , V_48 ,
V_49 , V_56 ) ;
F_13 ( 5 ) ;
F_4 ( V_2 , V_37 ,
V_38 |
V_39 ,
V_40 | V_41 ) ;
F_16 ( 20 ) ;
V_5 |= V_45 | V_46 ;
F_12 ( V_2 , V_42 , V_5 ) ;
F_12 ( V_2 , V_57 , V_58 |
V_59 ) ;
F_11 ( V_2 , V_60 ,
V_61 |
V_62 ,
V_63 |
V_64 ) ;
V_5 |= V_65 | V_66 |
V_67 | V_68 ;
F_12 ( V_2 , V_42 , V_5 ) ;
break;
case V_47 :
F_4 ( V_2 , V_42 ,
V_69 |
V_70 |
V_71 |
V_72 , 0 ) ;
F_4 ( V_2 , V_42 ,
V_43 |
V_44 , 0 ) ;
F_12 ( V_2 , V_57 , 0 ) ;
F_4 ( V_2 , V_37 ,
V_38 |
V_39 ,
0 ) ;
break;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_73 )
{
struct V_34 * V_35 ;
int V_74 ;
int V_75 = 0 ;
int V_76 ;
V_35 = F_10 ( V_2 ) ;
if ( V_73 )
V_76 = 4 ;
else
V_76 = 0 ;
switch ( V_35 -> V_77 [ V_73 ] ) {
case V_78 :
V_74 = V_35 -> V_79 [ 0 ] ;
break;
case V_80 :
V_75 |= 0x8 ;
V_74 = V_35 -> V_79 [ 1 ] ;
break;
case V_81 :
V_75 |= 0x10 ;
V_74 = V_35 -> V_82 [ 0 ] . V_83 ;
break;
case V_84 :
V_75 |= 0x18 ;
V_74 = V_35 -> V_82 [ 1 ] . V_83 ;
break;
default:
return - V_85 ;
}
if ( V_74 >= 13500000 ) {
V_74 /= 2 ;
V_75 |= V_86 ;
F_3 ( V_2 -> V_9 , L_12 ,
V_73 + 1 , V_74 ) ;
}
V_35 -> V_87 [ V_73 ] = V_74 ;
F_4 ( V_2 , V_88 + V_76 ,
V_89 | V_90 ,
V_75 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
int V_91 , V_92 ;
V_35 = F_10 ( V_2 ) ;
F_17 ( V_2 , 0 ) ;
F_17 ( V_2 , 1 ) ;
if ( V_35 -> V_87 [ 0 ] == V_35 -> V_87 [ 1 ] )
return 0 ;
if ( V_35 -> V_87 [ 0 ] < V_35 -> V_87 [ 1 ] )
V_92 = V_22 ;
else
V_92 = 0 ;
V_91 = F_4 ( V_2 , V_21 ,
V_93 , V_92 ) ;
if ( ! V_91 )
return 0 ;
F_19 ( & V_2 -> V_94 ) ;
return 0 ;
}
static int F_20 ( struct V_18 * V_30 ,
struct V_24 * V_25 , int V_33 )
{
struct V_1 * V_2 ;
V_2 = V_30 -> V_2 ;
switch ( V_33 ) {
case V_36 :
return F_18 ( V_2 ) ;
case V_95 :
F_18 ( V_2 ) ;
break;
}
return 0 ;
}
static bool F_21 ( struct V_96 * V_9 , unsigned int V_5 )
{
switch ( V_5 ) {
case V_97 :
case V_37 :
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
case V_117 :
case V_118 :
case V_119 :
case V_48 :
case V_14 :
case V_57 :
case V_60 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_54 :
case V_42 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_88 :
case V_130 :
case V_131 :
case V_132 :
case V_21 :
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
case V_257 :
case V_258 :
case V_259 :
case V_7 :
case V_13 :
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
case V_295 :
case V_296 :
case V_297 :
return true ;
default:
return false ;
}
}
static bool F_22 ( struct V_96 * V_9 , unsigned int V_5 )
{
switch ( V_5 ) {
case V_97 :
case V_54 :
case V_286 :
case V_287 :
case V_291 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_136 :
return true ;
default:
return false ;
}
}
static int F_23 ( struct V_298 * V_299 , int V_300 )
{
struct V_1 * V_2 = V_299 -> V_2 ;
int V_301 ;
switch ( V_299 -> V_302 ) {
case 0 :
V_301 = V_173 ;
break;
case 1 :
V_301 = V_232 ;
break;
default:
return - V_85 ;
}
F_4 ( V_2 , V_301 , V_303 ,
! ! V_300 << V_304 ) ;
return 0 ;
}
static int F_24 ( struct V_298 * V_299 , unsigned int V_305 )
{
struct V_1 * V_2 ;
int V_306 ;
int V_73 ;
V_2 = V_299 -> V_2 ;
V_306 = 0 ;
switch ( V_305 & V_307 ) {
case V_308 :
break;
case V_309 :
V_306 = V_310 ;
break;
default:
F_14 ( V_299 -> V_9 , L_13 ) ;
return - V_85 ;
}
V_73 = 0 ;
switch ( V_305 & V_311 ) {
case V_312 :
V_73 |= V_313 ;
case V_314 :
V_73 |= ( 0x3 << V_315 ) ;
break;
case V_316 :
V_73 |= ( 0x2 << V_315 ) ;
break;
case V_317 :
break;
case V_318 :
V_73 |= ( 0x1 << V_315 ) ;
break;
default:
F_14 ( V_299 -> V_9 , L_14 ) ;
return - V_85 ;
}
switch ( V_305 & V_311 ) {
case V_314 :
case V_312 :
switch ( V_305 & V_319 ) {
case V_320 :
break;
case V_321 :
V_73 |= V_322 ;
break;
default:
return - V_85 ;
}
break;
case V_316 :
case V_317 :
case V_318 :
switch ( V_305 & V_319 ) {
case V_320 :
break;
case V_323 :
V_73 |= V_322 | V_313 ;
break;
case V_321 :
V_73 |= V_322 ;
break;
case V_324 :
V_73 |= V_313 ;
break;
default:
return - V_85 ;
}
break;
default:
return - V_85 ;
}
F_4 ( V_2 , V_147 ,
V_325 |
V_326 |
V_327 , V_73 ) ;
F_4 ( V_2 , V_149 ,
V_328 , V_306 ) ;
return 0 ;
}
static int F_25 ( struct V_329 * V_330 ,
struct V_331 * V_332 ,
struct V_298 * V_299 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
int V_333 ;
int V_334 ;
int V_335 ;
int V_336 ;
int V_337 ;
int V_338 ;
int V_339 , V_340 ;
int V_341 , V_342 , V_343 , V_344 , V_345 ;
V_2 = V_299 -> V_2 ;
V_35 = F_10 ( V_2 ) ;
switch ( V_299 -> V_302 ) {
case 0 :
V_333 = V_147 ;
V_334 = V_150 ;
V_336 = V_134 ;
if ( V_330 -> V_346 == V_347 ) {
V_335 = V_152 ;
} else {
V_335 = V_151 ;
F_3 ( V_2 -> V_9 , L_15 ) ;
}
break;
case 1 :
V_333 = V_155 ;
V_334 = V_158 ;
V_336 = V_135 ;
if ( V_330 -> V_346 == V_347 ) {
V_335 = V_160 ;
} else {
V_335 = V_159 ;
F_3 ( V_2 -> V_9 , L_16 ) ;
}
break;
default:
return - V_85 ;
}
V_337 = F_26 ( V_332 ) ;
if ( V_337 < 0 )
return V_337 ;
V_338 = 0 ;
switch ( F_27 ( V_332 ) ) {
case V_348 :
break;
case V_349 :
V_338 |= ( 0x1 << V_350 ) ;
break;
case V_351 :
V_338 |= ( 0x2 << V_350 ) ;
break;
case V_352 :
V_338 |= ( 0x3 << V_350 ) ;
break;
default:
F_14 ( V_299 -> V_9 , L_17 ,
F_27 ( V_332 ) ) ;
return - V_85 ;
}
for ( V_341 = 0 ; V_341 < F_28 ( V_353 ) ; ++ V_341 )
if ( V_353 [ V_341 ] == F_29 ( V_332 ) )
break;
if ( V_341 == F_28 ( V_353 ) ) {
F_14 ( V_299 -> V_9 , L_18 ,
F_29 ( V_332 ) ) ;
return - V_85 ;
}
V_342 = V_341 << V_354 ;
F_3 ( V_299 -> V_9 , L_19 , V_353 [ V_341 ] ) ;
F_3 ( V_299 -> V_9 , L_20 ,
V_299 -> V_302 + 1 , V_35 -> V_87 [ V_299 -> V_302 ] , V_337 ) ;
V_343 = 1 ;
V_344 = abs ( ( V_355 [ 1 ] * F_29 ( V_332 ) )
- V_35 -> V_87 [ V_299 -> V_302 ] ) ;
for ( V_341 = 2 ; V_341 < F_28 ( V_355 ) ; V_341 ++ ) {
V_345 = abs ( ( V_355 [ V_341 ] * F_29 ( V_332 ) )
- V_35 -> V_87 [ V_299 -> V_302 ] ) ;
if ( V_345 >= V_344 )
continue;
V_343 = V_341 ;
V_344 = V_345 ;
}
V_342 |= V_343 ;
F_3 ( V_299 -> V_9 , L_21 ,
V_299 -> V_302 + 1 , V_355 [ V_343 ] ) ;
V_343 = 0 ;
V_340 = 0 ;
for ( V_341 = 0 ; V_341 < F_28 ( V_356 ) ; V_341 ++ ) {
V_345 = ( V_35 -> V_87 [ V_299 -> V_302 ] * 10 / V_356 [ V_341 ] ) - V_337 ;
if ( V_345 < 0 )
break;
V_343 = V_341 ;
}
V_340 |= V_343 << V_357 ;
V_337 = V_35 -> V_87 [ V_299 -> V_302 ] * 10 / V_356 [ V_343 ] ;
F_3 ( V_299 -> V_9 , L_22 ,
V_356 [ V_343 ] , V_337 ) ;
V_339 = V_337 / F_29 ( V_332 ) ;
F_3 ( V_299 -> V_9 , L_23 ,
V_339 , V_337 / V_339 ) ;
F_4 ( V_2 , V_333 ,
V_358 , V_338 ) ;
F_4 ( V_2 , V_334 ,
V_359 , V_340 ) ;
F_4 ( V_2 , V_335 ,
V_360 , V_339 ) ;
F_4 ( V_2 , V_336 ,
V_361 |
V_362 , V_342 ) ;
return 0 ;
}
static int F_30 ( struct V_298 * V_363 , int V_364 )
{
struct V_1 * V_2 = V_363 -> V_2 ;
int V_5 , V_50 , V_51 ;
switch ( V_363 -> V_302 ) {
case 0 :
V_5 = V_149 ;
V_51 = V_365 ;
break;
case 1 :
V_5 = V_157 ;
V_51 = V_366 ;
break;
case 2 :
V_5 = V_101 ;
V_51 = V_367 ;
break;
default:
return - V_85 ;
}
if ( V_364 )
V_50 = V_51 ;
else
V_50 = 0 ;
return F_4 ( V_2 , V_5 , V_51 , V_50 ) ;
}
static int F_31 ( struct V_368 * V_82 ,
int V_369 , int V_370 )
{
T_1 V_371 ;
unsigned int V_372 , V_373 , V_374 ;
F_32 ( L_24 , V_369 , V_370 ) ;
V_82 -> V_375 = 0 ;
while ( V_369 > 13500000 ) {
V_82 -> V_375 ++ ;
V_369 /= 2 ;
if ( V_82 -> V_375 > 3 )
return - V_85 ;
}
F_32 ( L_25 , V_82 -> V_375 , V_369 ) ;
V_82 -> V_376 = 3 ;
while ( V_370 * ( V_82 -> V_376 + 1 ) < 90000000 ) {
V_82 -> V_376 ++ ;
if ( V_82 -> V_376 > 63 )
return - V_85 ;
}
V_370 *= V_82 -> V_376 + 1 ;
F_32 ( L_26 , V_82 -> V_376 , V_370 ) ;
if ( V_369 > 1000000 ) {
V_82 -> V_377 = 0 ;
} else if ( V_369 > 256000 ) {
V_82 -> V_377 = 1 ;
V_369 *= 2 ;
} else if ( V_369 > 128000 ) {
V_82 -> V_377 = 2 ;
V_369 *= 4 ;
} else if ( V_369 > 64000 ) {
V_82 -> V_377 = 3 ;
V_369 *= 8 ;
} else {
V_82 -> V_377 = 4 ;
V_369 *= 16 ;
}
F_32 ( L_27 , V_82 -> V_377 , V_369 ) ;
V_373 = V_370 / V_369 ;
V_82 -> V_378 = V_373 ;
V_374 = V_370 % V_369 ;
F_32 ( L_28 , V_374 ) ;
V_371 = V_379 * ( long long ) V_374 ;
F_33 ( V_371 , V_369 ) ;
V_372 = V_371 & 0xFFFFFFFF ;
if ( ( V_372 % 10 ) >= 5 )
V_372 += 5 ;
V_82 -> V_380 = V_372 / 10 ;
F_32 ( L_29 , V_82 -> V_378 , V_82 -> V_380 ) ;
return 0 ;
}
static int F_34 ( struct V_298 * V_299 , int V_302 ,
int V_381 , unsigned int V_369 ,
unsigned int V_370 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
int V_382 , V_32 ;
struct V_368 V_82 ;
T_2 V_5 , V_338 , V_383 ;
V_2 = V_299 -> V_2 ;
V_35 = F_10 ( V_2 ) ;
V_338 = F_2 ( V_2 , V_88 )
& V_384 ;
V_383 = F_2 ( V_2 , V_131 )
& V_385 ;
switch ( V_302 ) {
case V_386 :
V_382 = 0 ;
V_302 = 0 ;
break;
case V_387 :
V_382 = 0x20 ;
V_302 = 1 ;
break;
default:
return - V_85 ;
}
switch ( V_381 ) {
case 0 :
if ( V_370 )
return - V_85 ;
break;
case V_388 :
case V_389 :
case V_390 :
case V_391 :
break;
default:
return - V_85 ;
}
if ( V_35 -> V_82 [ V_302 ] . V_381 == V_381 &&
V_35 -> V_82 [ V_302 ] . V_392 == V_369 && V_35 -> V_82 [ V_302 ] . V_83 == V_370 )
return 0 ;
if ( V_370 )
V_32 = F_31 ( & V_82 , V_369 , V_370 ) ;
else
V_32 = F_31 ( & V_82 , V_35 -> V_82 [ V_302 ] . V_392 ,
V_35 -> V_82 [ V_302 ] . V_83 ) ;
if ( V_32 < 0 )
return V_32 ;
F_4 ( V_2 , V_88 ,
V_393 , 0 ) ;
F_4 ( V_2 , V_131 ,
V_394 , 0 ) ;
F_4 ( V_2 , V_137 + V_382 ,
V_395 , 0 ) ;
V_5 = ( V_82 . V_376 << V_396 ) |
( V_82 . V_377 << V_397 ) ;
F_4 ( V_2 , V_138 + V_382 ,
V_398 |
V_399 , V_5 ) ;
F_12 ( V_2 , V_139 + V_382 , V_82 . V_380 ) ;
F_4 ( V_2 , V_140 + V_382 ,
V_400 ,
V_82 . V_378 << V_401 ) ;
F_4 ( V_2 , V_141 + V_382 ,
V_402 |
V_403 ,
( V_82 . V_375 << V_404 ) |
( V_381 - 1 ) ) ;
if ( V_370 )
F_4 ( V_2 , V_137 + V_382 ,
V_395 , V_405 ) ;
V_35 -> V_82 [ V_302 ] . V_392 = V_369 ;
V_35 -> V_82 [ V_302 ] . V_83 = V_370 ;
V_35 -> V_82 [ V_302 ] . V_381 = V_381 ;
F_4 ( V_2 , V_88 ,
V_393 , V_338 ) ;
F_4 ( V_2 , V_131 ,
V_394 , V_383 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
static int F_35 ( struct V_298 * V_299 ,
int V_406 , unsigned int V_407 , int V_408 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
V_2 = V_299 -> V_2 ;
V_35 = F_10 ( V_2 ) ;
switch ( V_299 -> V_302 ) {
case 0 :
case 1 :
break;
default:
return - V_85 ;
}
switch ( V_406 ) {
case V_78 :
V_35 -> V_77 [ V_299 -> V_302 ] = V_78 ;
V_35 -> V_79 [ 0 ] = V_407 ;
F_3 ( V_299 -> V_9 , L_30 ,
V_299 -> V_302 + 1 , V_407 ) ;
break;
case V_80 :
V_35 -> V_77 [ V_299 -> V_302 ] = V_78 ;
V_35 -> V_79 [ 1 ] = V_407 ;
F_3 ( V_299 -> V_9 , L_31 ,
V_299 -> V_302 + 1 , V_407 ) ;
break;
case V_81 :
V_35 -> V_77 [ V_299 -> V_302 ] = V_81 ;
F_3 ( V_299 -> V_9 , L_32 , V_299 -> V_302 + 1 ) ;
break;
case V_84 :
V_35 -> V_77 [ V_299 -> V_302 ] = V_84 ;
F_3 ( V_299 -> V_9 , L_33 , V_299 -> V_302 + 1 ) ;
break;
case V_409 :
default:
F_14 ( V_299 -> V_9 , L_34 , V_406 ) ;
return - V_85 ;
}
F_18 ( V_2 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
enum V_410 V_411 )
{
struct V_34 * V_35 ;
int V_32 ;
V_35 = F_10 ( V_2 ) ;
switch ( V_411 ) {
case V_412 :
case V_413 :
break;
case V_414 :
if ( V_2 -> V_94 . V_415 == V_416 ) {
V_32 = F_37 ( F_28 ( V_35 -> V_417 ) ,
V_35 -> V_417 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_38 ( V_35 -> V_418 ) ;
if ( V_32 ) {
F_14 ( V_2 -> V_9 ,
L_35 , V_32 ) ;
return V_32 ;
}
F_4 ( V_2 , V_37 ,
V_419 , V_420 ) ;
}
break;
case V_416 :
F_4 ( V_2 , V_37 ,
V_419 , 0 ) ;
F_39 ( F_28 ( V_35 -> V_417 ) ,
V_35 -> V_417 ) ;
break;
}
V_2 -> V_94 . V_415 = V_411 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
F_36 ( V_2 , V_416 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
F_36 ( V_2 , V_414 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
int V_341 ;
V_35 = F_10 ( V_2 ) ;
F_36 ( V_2 , V_416 ) ;
for ( V_341 = 0 ; V_341 < F_28 ( V_35 -> V_417 ) ; ++ V_341 )
F_43 ( V_35 -> V_417 [ V_341 ] . V_421 ,
& V_35 -> V_422 [ V_341 ] ) ;
F_44 ( F_28 ( V_35 -> V_417 ) , V_35 -> V_417 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
int V_341 ;
int V_32 ;
V_35 = F_10 ( V_2 ) ;
V_35 -> V_2 = V_2 ;
V_2 -> V_423 = V_35 -> V_418 ;
V_32 = F_46 ( V_2 , 16 , 16 , V_424 ) ;
if ( V_32 < 0 ) {
F_14 ( V_2 -> V_9 , L_36 , V_32 ) ;
return V_32 ;
}
for ( V_341 = 0 ; V_341 < F_28 ( V_35 -> V_417 ) ; V_341 ++ )
V_35 -> V_417 [ V_341 ] . V_425 = V_426 [ V_341 ] ;
V_32 = F_47 ( V_2 -> V_9 , F_28 ( V_35 -> V_417 ) ,
V_35 -> V_417 ) ;
if ( V_32 ) {
F_14 ( V_2 -> V_9 , L_37 , V_32 ) ;
return V_32 ;
}
V_35 -> V_422 [ 0 ] . V_427 = V_428 ;
V_35 -> V_422 [ 1 ] . V_427 = V_429 ;
V_35 -> V_422 [ 2 ] . V_427 = V_430 ;
V_35 -> V_422 [ 3 ] . V_427 = V_431 ;
V_35 -> V_422 [ 4 ] . V_427 = V_432 ;
V_35 -> V_422 [ 5 ] . V_427 = V_433 ;
V_35 -> V_422 [ 6 ] . V_427 = V_434 ;
V_35 -> V_422 [ 7 ] . V_427 = V_435 ;
for ( V_341 = 0 ; V_341 < F_28 ( V_35 -> V_417 ) ; V_341 ++ ) {
V_32 = F_48 ( V_35 -> V_417 [ V_341 ] . V_421 ,
& V_35 -> V_422 [ V_341 ] ) ;
if ( V_32 ) {
F_14 ( V_2 -> V_9 ,
L_38 ,
V_32 ) ;
}
}
V_32 = F_37 ( F_28 ( V_35 -> V_417 ) ,
V_35 -> V_417 ) ;
if ( V_32 ) {
F_14 ( V_2 -> V_9 , L_39 , V_32 ) ;
goto V_436;
}
V_32 = F_2 ( V_2 , V_97 ) ;
if ( V_32 < 0 ) {
F_14 ( V_2 -> V_9 , L_40 , V_32 ) ;
goto V_437;
}
if ( V_32 != 0x8995 ) {
F_14 ( V_2 -> V_9 , L_41 , V_32 ) ;
V_32 = - V_85 ;
goto V_437;
}
V_32 = F_12 ( V_2 , V_97 , 0 ) ;
if ( V_32 < 0 ) {
F_14 ( V_2 -> V_9 , L_42 , V_32 ) ;
goto V_437;
}
F_36 ( V_2 , V_414 ) ;
F_4 ( V_2 , V_166 ,
V_438 , V_439 ) ;
F_4 ( V_2 , V_170 ,
V_440 , V_441 ) ;
F_4 ( V_2 , V_230 ,
V_442 , V_443 ) ;
F_4 ( V_2 , V_164 ,
V_444 , V_445 ) ;
F_4 ( V_2 , V_168 ,
V_446 , V_447 ) ;
F_4 ( V_2 , V_228 ,
V_448 , V_447 ) ;
F_4 ( V_2 , V_106 ,
V_449 , V_450 ) ;
F_4 ( V_2 , V_108 ,
V_451 , V_452 ) ;
F_4 ( V_2 , V_103 ,
V_453 , V_454 ) ;
F_1 ( V_2 ) ;
F_49 ( V_2 , V_455 ,
F_28 ( V_455 ) ) ;
F_50 ( & V_2 -> V_94 , V_456 ,
F_28 ( V_456 ) ) ;
F_51 ( & V_2 -> V_94 , V_457 ,
F_28 ( V_457 ) ) ;
return 0 ;
V_437:
F_39 ( F_28 ( V_35 -> V_417 ) , V_35 -> V_417 ) ;
V_436:
F_44 ( F_28 ( V_35 -> V_417 ) , V_35 -> V_417 ) ;
return V_32 ;
}
static int T_3 F_52 ( struct V_458 * V_459 )
{
struct V_34 * V_35 ;
int V_32 ;
V_35 = F_53 ( sizeof *V_35 , V_460 ) ;
if ( ! V_35 )
return - V_461 ;
F_54 ( V_459 , V_35 ) ;
V_35 -> V_418 = F_55 ( V_459 , & V_462 ) ;
if ( F_56 ( V_35 -> V_418 ) ) {
V_32 = F_57 ( V_35 -> V_418 ) ;
F_14 ( & V_459 -> V_9 , L_43 , V_32 ) ;
goto V_463;
}
V_32 = F_58 ( & V_459 -> V_9 ,
& V_464 , V_465 ,
F_28 ( V_465 ) ) ;
if ( V_32 < 0 )
goto V_466;
return V_32 ;
V_466:
F_59 ( V_35 -> V_418 ) ;
V_463:
F_60 ( V_35 ) ;
return V_32 ;
}
static int T_4 F_61 ( struct V_458 * V_459 )
{
struct V_34 * V_35 = F_62 ( V_459 ) ;
F_63 ( & V_459 -> V_9 ) ;
F_59 ( V_35 -> V_418 ) ;
F_60 ( V_35 ) ;
return 0 ;
}
static T_3 int F_64 ( struct V_467 * V_468 ,
const struct V_469 * V_302 )
{
struct V_34 * V_35 ;
int V_32 ;
V_35 = F_53 ( sizeof *V_35 , V_460 ) ;
if ( ! V_35 )
return - V_461 ;
F_65 ( V_468 , V_35 ) ;
V_35 -> V_418 = F_66 ( V_468 , & V_462 ) ;
if ( F_56 ( V_35 -> V_418 ) ) {
V_32 = F_57 ( V_35 -> V_418 ) ;
F_14 ( & V_468 -> V_9 , L_43 , V_32 ) ;
goto V_463;
}
V_32 = F_58 ( & V_468 -> V_9 ,
& V_464 , V_465 ,
F_28 ( V_465 ) ) ;
if ( V_32 < 0 ) {
F_14 ( & V_468 -> V_9 , L_44 , V_32 ) ;
goto V_466;
}
return V_32 ;
V_466:
F_59 ( V_35 -> V_418 ) ;
V_463:
F_60 ( V_35 ) ;
return V_32 ;
}
static T_4 int F_67 ( struct V_467 * V_470 )
{
struct V_34 * V_35 = F_68 ( V_470 ) ;
F_63 ( & V_470 -> V_9 ) ;
F_59 ( V_35 -> V_418 ) ;
F_60 ( V_35 ) ;
return 0 ;
}
static int T_5 F_69 ( void )
{
int V_32 = 0 ;
#if F_70 ( V_471 ) || F_70 ( V_472 )
V_32 = F_71 ( & V_473 ) ;
if ( V_32 ) {
F_72 ( V_474 L_45 ,
V_32 ) ;
}
#endif
#if F_70 ( V_475 )
V_32 = F_73 ( & V_476 ) ;
if ( V_32 ) {
F_72 ( V_474 L_46 ,
V_32 ) ;
}
#endif
return V_32 ;
}
static void T_6 F_74 ( void )
{
#if F_70 ( V_471 ) || F_70 ( V_472 )
F_75 ( & V_473 ) ;
#endif
#if F_70 ( V_475 )
F_76 ( & V_476 ) ;
#endif
}
