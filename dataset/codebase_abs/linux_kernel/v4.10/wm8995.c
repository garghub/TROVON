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
struct V_1 * V_2 = F_6 ( V_4 -> V_20 ) ;
unsigned int V_5 ;
const char * V_21 ;
V_5 = F_2 ( V_2 , V_22 ) ;
if ( V_5 & V_23 )
V_21 = L_8 ;
else
V_21 = L_9 ;
return ! strcmp ( V_4 -> V_24 , V_21 ) ;
}
static int F_7 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
struct V_1 * V_2 = F_8 ( V_26 ) ;
int V_29 ;
V_29 = F_9 ( V_26 , V_28 ) ;
F_1 ( V_2 ) ;
return V_29 ;
}
static int F_10 ( struct V_18 * V_30 ,
struct V_25 * V_26 , int V_31 )
{
struct V_1 * V_2 = F_6 ( V_30 -> V_20 ) ;
switch ( V_31 ) {
case V_32 :
F_4 ( V_2 , V_33 ,
V_34 |
V_35 ,
V_36 |
V_37 ) ;
F_4 ( V_2 , V_38 ,
V_39 |
V_40 ,
V_41 |
V_42 ) ;
break;
case V_43 :
F_4 ( V_2 , V_44 ,
V_45 , 0 ) ;
break;
}
return 0 ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned int V_5 , unsigned int V_46 , unsigned int V_47 )
{
int V_48 = 10 ;
F_3 ( V_2 -> V_9 , L_10 ,
V_49 , V_5 , V_46 , V_47 ) ;
F_12 ( V_2 , V_5 , V_46 ) ;
while ( V_48 -- ) {
F_13 ( 10 ) ;
V_46 = F_2 ( V_2 , V_50 ) ;
if ( ( V_46 & V_47 ) == V_47 )
return;
}
F_14 ( V_2 -> V_9 , L_11 ) ;
}
static int F_15 ( struct V_18 * V_30 ,
struct V_25 * V_26 , int V_31 )
{
struct V_1 * V_2 = F_6 ( V_30 -> V_20 ) ;
unsigned int V_5 ;
V_5 = F_2 ( V_2 , V_38 ) ;
switch ( V_31 ) {
case V_51 :
F_4 ( V_2 , V_44 ,
V_45 , V_52 ) ;
F_13 ( 5 ) ;
F_4 ( V_2 , V_33 ,
V_34 |
V_35 ,
V_36 | V_37 ) ;
F_16 ( 20 ) ;
V_5 |= V_41 | V_42 ;
F_12 ( V_2 , V_38 , V_5 ) ;
F_12 ( V_2 , V_53 , V_54 |
V_55 ) ;
F_11 ( V_2 , V_56 ,
V_57 |
V_58 ,
V_59 |
V_60 ) ;
V_5 |= V_61 | V_62 |
V_63 | V_64 ;
F_12 ( V_2 , V_38 , V_5 ) ;
break;
case V_43 :
F_4 ( V_2 , V_38 ,
V_65 |
V_66 |
V_67 |
V_68 , 0 ) ;
F_4 ( V_2 , V_38 ,
V_39 |
V_40 , 0 ) ;
F_12 ( V_2 , V_53 , 0 ) ;
F_4 ( V_2 , V_33 ,
V_34 |
V_35 ,
0 ) ;
break;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_69 )
{
struct V_70 * V_71 ;
int V_72 ;
int V_73 = 0 ;
int V_74 ;
V_71 = F_18 ( V_2 ) ;
if ( V_69 )
V_74 = 4 ;
else
V_74 = 0 ;
switch ( V_71 -> V_75 [ V_69 ] ) {
case V_76 :
V_72 = V_71 -> V_77 [ 0 ] ;
break;
case V_78 :
V_73 |= 0x8 ;
V_72 = V_71 -> V_77 [ 1 ] ;
break;
case V_79 :
V_73 |= 0x10 ;
V_72 = V_71 -> V_80 [ 0 ] . V_81 ;
break;
case V_82 :
V_73 |= 0x18 ;
V_72 = V_71 -> V_80 [ 1 ] . V_81 ;
break;
default:
return - V_83 ;
}
if ( V_72 >= 13500000 ) {
V_72 /= 2 ;
V_73 |= V_84 ;
F_3 ( V_2 -> V_9 , L_12 ,
V_69 + 1 , V_72 ) ;
}
V_71 -> V_85 [ V_69 ] = V_72 ;
F_4 ( V_2 , V_86 + V_74 ,
V_87 | V_88 ,
V_73 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_89 * V_20 = F_20 ( V_2 ) ;
struct V_70 * V_71 ;
int V_90 , V_91 ;
V_71 = F_18 ( V_2 ) ;
F_17 ( V_2 , 0 ) ;
F_17 ( V_2 , 1 ) ;
if ( V_71 -> V_85 [ 0 ] == V_71 -> V_85 [ 1 ] )
return 0 ;
if ( V_71 -> V_85 [ 0 ] < V_71 -> V_85 [ 1 ] )
V_91 = V_23 ;
else
V_91 = 0 ;
V_90 = F_4 ( V_2 , V_22 ,
V_92 , V_91 ) ;
if ( ! V_90 )
return 0 ;
F_21 ( V_20 ) ;
return 0 ;
}
static int F_22 ( struct V_18 * V_30 ,
struct V_25 * V_26 , int V_31 )
{
struct V_1 * V_2 = F_6 ( V_30 -> V_20 ) ;
switch ( V_31 ) {
case V_32 :
return F_19 ( V_2 ) ;
case V_93 :
F_19 ( V_2 ) ;
break;
}
return 0 ;
}
static bool F_23 ( struct V_94 * V_9 , unsigned int V_5 )
{
switch ( V_5 ) {
case V_95 :
case V_33 :
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
case V_117 :
case V_44 :
case V_14 :
case V_53 :
case V_56 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_50 :
case V_38 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_86 :
case V_128 :
case V_129 :
case V_130 :
case V_22 :
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
case V_257 :
case V_7 :
case V_13 :
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
case V_295 :
return true ;
default:
return false ;
}
}
static bool F_24 ( struct V_94 * V_9 , unsigned int V_5 )
{
switch ( V_5 ) {
case V_95 :
case V_50 :
case V_284 :
case V_285 :
case V_289 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_134 :
return true ;
default:
return false ;
}
}
static int F_25 ( struct V_296 * V_297 , int V_298 )
{
struct V_1 * V_2 = V_297 -> V_2 ;
int V_299 ;
switch ( V_297 -> V_300 ) {
case 0 :
V_299 = V_171 ;
break;
case 1 :
V_299 = V_230 ;
break;
default:
return - V_83 ;
}
F_4 ( V_2 , V_299 , V_301 ,
! ! V_298 << V_302 ) ;
return 0 ;
}
static int F_26 ( struct V_296 * V_297 , unsigned int V_303 )
{
struct V_1 * V_2 ;
int V_304 ;
int V_69 ;
V_2 = V_297 -> V_2 ;
V_304 = 0 ;
switch ( V_303 & V_305 ) {
case V_306 :
break;
case V_307 :
V_304 = V_308 ;
break;
default:
F_14 ( V_297 -> V_9 , L_13 ) ;
return - V_83 ;
}
V_69 = 0 ;
switch ( V_303 & V_309 ) {
case V_310 :
V_69 |= V_311 ;
case V_312 :
V_69 |= ( 0x3 << V_313 ) ;
break;
case V_314 :
V_69 |= ( 0x2 << V_313 ) ;
break;
case V_315 :
break;
case V_316 :
V_69 |= ( 0x1 << V_313 ) ;
break;
default:
F_14 ( V_297 -> V_9 , L_14 ) ;
return - V_83 ;
}
switch ( V_303 & V_309 ) {
case V_312 :
case V_310 :
switch ( V_303 & V_317 ) {
case V_318 :
break;
case V_319 :
V_69 |= V_320 ;
break;
default:
return - V_83 ;
}
break;
case V_314 :
case V_315 :
case V_316 :
switch ( V_303 & V_317 ) {
case V_318 :
break;
case V_321 :
V_69 |= V_320 | V_311 ;
break;
case V_319 :
V_69 |= V_320 ;
break;
case V_322 :
V_69 |= V_311 ;
break;
default:
return - V_83 ;
}
break;
default:
return - V_83 ;
}
F_4 ( V_2 , V_145 ,
V_323 |
V_324 |
V_325 , V_69 ) ;
F_4 ( V_2 , V_147 ,
V_326 , V_304 ) ;
return 0 ;
}
static int F_27 ( struct V_327 * V_328 ,
struct V_329 * V_330 ,
struct V_296 * V_297 )
{
struct V_1 * V_2 ;
struct V_70 * V_71 ;
int V_331 ;
int V_332 ;
int V_333 ;
int V_334 ;
int V_335 ;
int V_336 ;
int V_337 , V_338 ;
int V_339 , V_340 , V_341 , V_342 , V_343 ;
V_2 = V_297 -> V_2 ;
V_71 = F_18 ( V_2 ) ;
switch ( V_297 -> V_300 ) {
case 0 :
V_331 = V_145 ;
V_332 = V_148 ;
V_334 = V_132 ;
if ( V_328 -> V_344 == V_345 ) {
V_333 = V_150 ;
} else {
V_333 = V_149 ;
F_3 ( V_2 -> V_9 , L_15 ) ;
}
break;
case 1 :
V_331 = V_153 ;
V_332 = V_156 ;
V_334 = V_133 ;
if ( V_328 -> V_344 == V_345 ) {
V_333 = V_158 ;
} else {
V_333 = V_157 ;
F_3 ( V_2 -> V_9 , L_16 ) ;
}
break;
default:
return - V_83 ;
}
V_335 = F_28 ( V_330 ) ;
if ( V_335 < 0 )
return V_335 ;
V_336 = 0 ;
switch ( F_29 ( V_330 ) ) {
case 16 :
break;
case 20 :
V_336 |= ( 0x1 << V_346 ) ;
break;
case 24 :
V_336 |= ( 0x2 << V_346 ) ;
break;
case 32 :
V_336 |= ( 0x3 << V_346 ) ;
break;
default:
F_14 ( V_297 -> V_9 , L_17 ,
F_29 ( V_330 ) ) ;
return - V_83 ;
}
for ( V_339 = 0 ; V_339 < F_30 ( V_347 ) ; ++ V_339 )
if ( V_347 [ V_339 ] == F_31 ( V_330 ) )
break;
if ( V_339 == F_30 ( V_347 ) ) {
F_14 ( V_297 -> V_9 , L_18 ,
F_31 ( V_330 ) ) ;
return - V_83 ;
}
V_340 = V_339 << V_348 ;
F_3 ( V_297 -> V_9 , L_19 , V_347 [ V_339 ] ) ;
F_3 ( V_297 -> V_9 , L_20 ,
V_297 -> V_300 + 1 , V_71 -> V_85 [ V_297 -> V_300 ] , V_335 ) ;
V_341 = 1 ;
V_342 = abs ( ( V_349 [ 1 ] * F_31 ( V_330 ) )
- V_71 -> V_85 [ V_297 -> V_300 ] ) ;
for ( V_339 = 2 ; V_339 < F_30 ( V_349 ) ; V_339 ++ ) {
V_343 = abs ( ( V_349 [ V_339 ] * F_31 ( V_330 ) )
- V_71 -> V_85 [ V_297 -> V_300 ] ) ;
if ( V_343 >= V_342 )
continue;
V_341 = V_339 ;
V_342 = V_343 ;
}
V_340 |= V_341 ;
F_3 ( V_297 -> V_9 , L_21 ,
V_297 -> V_300 + 1 , V_349 [ V_341 ] ) ;
V_341 = 0 ;
V_338 = 0 ;
for ( V_339 = 0 ; V_339 < F_30 ( V_350 ) ; V_339 ++ ) {
V_343 = ( V_71 -> V_85 [ V_297 -> V_300 ] * 10 / V_350 [ V_339 ] ) - V_335 ;
if ( V_343 < 0 )
break;
V_341 = V_339 ;
}
V_338 |= V_341 << V_351 ;
V_335 = V_71 -> V_85 [ V_297 -> V_300 ] * 10 / V_350 [ V_341 ] ;
F_3 ( V_297 -> V_9 , L_22 ,
V_350 [ V_341 ] , V_335 ) ;
V_337 = V_335 / F_31 ( V_330 ) ;
F_3 ( V_297 -> V_9 , L_23 ,
V_337 , V_335 / V_337 ) ;
F_4 ( V_2 , V_331 ,
V_352 , V_336 ) ;
F_4 ( V_2 , V_332 ,
V_353 , V_338 ) ;
F_4 ( V_2 , V_333 ,
V_354 , V_337 ) ;
F_4 ( V_2 , V_334 ,
V_355 |
V_356 , V_340 ) ;
return 0 ;
}
static int F_32 ( struct V_296 * V_357 , int V_358 )
{
struct V_1 * V_2 = V_357 -> V_2 ;
int V_5 , V_46 , V_47 ;
switch ( V_357 -> V_300 ) {
case 0 :
V_5 = V_147 ;
V_47 = V_359 ;
break;
case 1 :
V_5 = V_155 ;
V_47 = V_360 ;
break;
case 2 :
V_5 = V_99 ;
V_47 = V_361 ;
break;
default:
return - V_83 ;
}
if ( V_358 )
V_46 = V_47 ;
else
V_46 = 0 ;
return F_4 ( V_2 , V_5 , V_47 , V_46 ) ;
}
static int F_33 ( struct V_362 * V_80 ,
int V_363 , int V_364 )
{
T_1 V_365 ;
unsigned int V_366 , V_367 , V_368 ;
F_34 ( L_24 , V_363 , V_364 ) ;
V_80 -> V_369 = 0 ;
while ( V_363 > 13500000 ) {
V_80 -> V_369 ++ ;
V_363 /= 2 ;
if ( V_80 -> V_369 > 3 )
return - V_83 ;
}
F_34 ( L_25 , V_80 -> V_369 , V_363 ) ;
V_80 -> V_370 = 3 ;
while ( V_364 * ( V_80 -> V_370 + 1 ) < 90000000 ) {
V_80 -> V_370 ++ ;
if ( V_80 -> V_370 > 63 )
return - V_83 ;
}
V_364 *= V_80 -> V_370 + 1 ;
F_34 ( L_26 , V_80 -> V_370 , V_364 ) ;
if ( V_363 > 1000000 ) {
V_80 -> V_371 = 0 ;
} else if ( V_363 > 256000 ) {
V_80 -> V_371 = 1 ;
V_363 *= 2 ;
} else if ( V_363 > 128000 ) {
V_80 -> V_371 = 2 ;
V_363 *= 4 ;
} else if ( V_363 > 64000 ) {
V_80 -> V_371 = 3 ;
V_363 *= 8 ;
} else {
V_80 -> V_371 = 4 ;
V_363 *= 16 ;
}
F_34 ( L_27 , V_80 -> V_371 , V_363 ) ;
V_367 = V_364 / V_363 ;
V_80 -> V_372 = V_367 ;
V_368 = V_364 % V_363 ;
F_34 ( L_28 , V_368 ) ;
V_365 = V_373 * ( long long ) V_368 ;
F_35 ( V_365 , V_363 ) ;
V_366 = V_365 & 0xFFFFFFFF ;
if ( ( V_366 % 10 ) >= 5 )
V_366 += 5 ;
V_80 -> V_374 = V_366 / 10 ;
F_34 ( L_29 , V_80 -> V_372 , V_80 -> V_374 ) ;
return 0 ;
}
static int F_36 ( struct V_296 * V_297 , int V_300 ,
int V_375 , unsigned int V_363 ,
unsigned int V_364 )
{
struct V_1 * V_2 ;
struct V_70 * V_71 ;
int V_376 , V_29 ;
struct V_362 V_80 ;
T_2 V_5 , V_336 , V_377 ;
V_2 = V_297 -> V_2 ;
V_71 = F_18 ( V_2 ) ;
V_336 = F_2 ( V_2 , V_86 )
& V_378 ;
V_377 = F_2 ( V_2 , V_129 )
& V_379 ;
switch ( V_300 ) {
case V_380 :
V_376 = 0 ;
V_300 = 0 ;
break;
case V_381 :
V_376 = 0x20 ;
V_300 = 1 ;
break;
default:
return - V_83 ;
}
switch ( V_375 ) {
case 0 :
if ( V_364 )
return - V_83 ;
break;
case V_382 :
case V_383 :
case V_384 :
case V_385 :
break;
default:
return - V_83 ;
}
if ( V_71 -> V_80 [ V_300 ] . V_375 == V_375 &&
V_71 -> V_80 [ V_300 ] . V_386 == V_363 && V_71 -> V_80 [ V_300 ] . V_81 == V_364 )
return 0 ;
if ( V_364 )
V_29 = F_33 ( & V_80 , V_363 , V_364 ) ;
else
V_29 = F_33 ( & V_80 , V_71 -> V_80 [ V_300 ] . V_386 ,
V_71 -> V_80 [ V_300 ] . V_81 ) ;
if ( V_29 < 0 )
return V_29 ;
F_4 ( V_2 , V_86 ,
V_387 , 0 ) ;
F_4 ( V_2 , V_129 ,
V_388 , 0 ) ;
F_4 ( V_2 , V_135 + V_376 ,
V_389 , 0 ) ;
V_5 = ( V_80 . V_370 << V_390 ) |
( V_80 . V_371 << V_391 ) ;
F_4 ( V_2 , V_136 + V_376 ,
V_392 |
V_393 , V_5 ) ;
F_12 ( V_2 , V_137 + V_376 , V_80 . V_374 ) ;
F_4 ( V_2 , V_138 + V_376 ,
V_394 ,
V_80 . V_372 << V_395 ) ;
F_4 ( V_2 , V_139 + V_376 ,
V_396 |
V_397 ,
( V_80 . V_369 << V_398 ) |
( V_375 - 1 ) ) ;
if ( V_364 )
F_4 ( V_2 , V_135 + V_376 ,
V_389 , V_399 ) ;
V_71 -> V_80 [ V_300 ] . V_386 = V_363 ;
V_71 -> V_80 [ V_300 ] . V_81 = V_364 ;
V_71 -> V_80 [ V_300 ] . V_375 = V_375 ;
F_4 ( V_2 , V_86 ,
V_387 , V_336 ) ;
F_4 ( V_2 , V_129 ,
V_388 , V_377 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_37 ( struct V_296 * V_297 ,
int V_400 , unsigned int V_401 , int V_402 )
{
struct V_1 * V_2 ;
struct V_70 * V_71 ;
V_2 = V_297 -> V_2 ;
V_71 = F_18 ( V_2 ) ;
switch ( V_297 -> V_300 ) {
case 0 :
case 1 :
break;
default:
return - V_83 ;
}
switch ( V_400 ) {
case V_76 :
V_71 -> V_75 [ V_297 -> V_300 ] = V_76 ;
V_71 -> V_77 [ 0 ] = V_401 ;
F_3 ( V_297 -> V_9 , L_30 ,
V_297 -> V_300 + 1 , V_401 ) ;
break;
case V_78 :
V_71 -> V_75 [ V_297 -> V_300 ] = V_78 ;
V_71 -> V_77 [ 1 ] = V_401 ;
F_3 ( V_297 -> V_9 , L_31 ,
V_297 -> V_300 + 1 , V_401 ) ;
break;
case V_79 :
V_71 -> V_75 [ V_297 -> V_300 ] = V_79 ;
F_3 ( V_297 -> V_9 , L_32 , V_297 -> V_300 + 1 ) ;
break;
case V_82 :
V_71 -> V_75 [ V_297 -> V_300 ] = V_82 ;
F_3 ( V_297 -> V_9 , L_33 , V_297 -> V_300 + 1 ) ;
break;
case V_403 :
default:
F_14 ( V_297 -> V_9 , L_34 , V_400 ) ;
return - V_83 ;
}
F_19 ( V_2 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
enum V_404 V_405 )
{
struct V_70 * V_71 ;
int V_29 ;
V_71 = F_18 ( V_2 ) ;
switch ( V_405 ) {
case V_406 :
case V_407 :
break;
case V_408 :
if ( F_39 ( V_2 ) == V_409 ) {
V_29 = F_40 ( F_30 ( V_71 -> V_410 ) ,
V_71 -> V_410 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_41 ( V_71 -> V_411 ) ;
if ( V_29 ) {
F_14 ( V_2 -> V_9 ,
L_35 , V_29 ) ;
return V_29 ;
}
F_4 ( V_2 , V_33 ,
V_412 , V_413 ) ;
}
break;
case V_409 :
F_4 ( V_2 , V_33 ,
V_412 , 0 ) ;
F_42 ( F_30 ( V_71 -> V_410 ) ,
V_71 -> V_410 ) ;
break;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_70 * V_71 ;
int V_339 ;
V_71 = F_18 ( V_2 ) ;
for ( V_339 = 0 ; V_339 < F_30 ( V_71 -> V_410 ) ; ++ V_339 )
F_44 ( V_71 -> V_410 [ V_339 ] . V_414 ,
& V_71 -> V_415 [ V_339 ] ) ;
F_45 ( F_30 ( V_71 -> V_410 ) , V_71 -> V_410 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_70 * V_71 ;
int V_339 ;
int V_29 ;
V_71 = F_18 ( V_2 ) ;
V_71 -> V_2 = V_2 ;
for ( V_339 = 0 ; V_339 < F_30 ( V_71 -> V_410 ) ; V_339 ++ )
V_71 -> V_410 [ V_339 ] . V_416 = V_417 [ V_339 ] ;
V_29 = F_47 ( V_2 -> V_9 , F_30 ( V_71 -> V_410 ) ,
V_71 -> V_410 ) ;
if ( V_29 ) {
F_14 ( V_2 -> V_9 , L_36 , V_29 ) ;
return V_29 ;
}
V_71 -> V_415 [ 0 ] . V_418 = V_419 ;
V_71 -> V_415 [ 1 ] . V_418 = V_420 ;
V_71 -> V_415 [ 2 ] . V_418 = V_421 ;
V_71 -> V_415 [ 3 ] . V_418 = V_422 ;
V_71 -> V_415 [ 4 ] . V_418 = V_423 ;
V_71 -> V_415 [ 5 ] . V_418 = V_424 ;
V_71 -> V_415 [ 6 ] . V_418 = V_425 ;
V_71 -> V_415 [ 7 ] . V_418 = V_426 ;
for ( V_339 = 0 ; V_339 < F_30 ( V_71 -> V_410 ) ; V_339 ++ ) {
V_29 = F_48 ( V_71 -> V_410 [ V_339 ] . V_414 ,
& V_71 -> V_415 [ V_339 ] ) ;
if ( V_29 ) {
F_14 ( V_2 -> V_9 ,
L_37 ,
V_29 ) ;
}
}
V_29 = F_40 ( F_30 ( V_71 -> V_410 ) ,
V_71 -> V_410 ) ;
if ( V_29 ) {
F_14 ( V_2 -> V_9 , L_38 , V_29 ) ;
goto V_427;
}
V_29 = F_2 ( V_2 , V_95 ) ;
if ( V_29 < 0 ) {
F_14 ( V_2 -> V_9 , L_39 , V_29 ) ;
goto V_428;
}
if ( V_29 != 0x8995 ) {
F_14 ( V_2 -> V_9 , L_40 , V_29 ) ;
V_29 = - V_83 ;
goto V_428;
}
V_29 = F_12 ( V_2 , V_95 , 0 ) ;
if ( V_29 < 0 ) {
F_14 ( V_2 -> V_9 , L_41 , V_29 ) ;
goto V_428;
}
F_4 ( V_2 , V_164 ,
V_429 , V_430 ) ;
F_4 ( V_2 , V_168 ,
V_431 , V_432 ) ;
F_4 ( V_2 , V_228 ,
V_433 , V_434 ) ;
F_4 ( V_2 , V_162 ,
V_435 , V_436 ) ;
F_4 ( V_2 , V_166 ,
V_437 , V_438 ) ;
F_4 ( V_2 , V_226 ,
V_439 , V_438 ) ;
F_4 ( V_2 , V_104 ,
V_440 , V_441 ) ;
F_4 ( V_2 , V_106 ,
V_442 , V_443 ) ;
F_4 ( V_2 , V_101 ,
V_444 , V_445 ) ;
F_1 ( V_2 ) ;
return 0 ;
V_428:
F_42 ( F_30 ( V_71 -> V_410 ) , V_71 -> V_410 ) ;
V_427:
F_45 ( F_30 ( V_71 -> V_410 ) , V_71 -> V_410 ) ;
return V_29 ;
}
static int F_49 ( struct V_446 * V_447 )
{
struct V_70 * V_71 ;
int V_29 ;
V_71 = F_50 ( & V_447 -> V_9 , sizeof( * V_71 ) , V_448 ) ;
if ( ! V_71 )
return - V_449 ;
F_51 ( V_447 , V_71 ) ;
V_71 -> V_411 = F_52 ( V_447 , & V_450 ) ;
if ( F_53 ( V_71 -> V_411 ) ) {
V_29 = F_54 ( V_71 -> V_411 ) ;
F_14 ( & V_447 -> V_9 , L_42 , V_29 ) ;
return V_29 ;
}
V_29 = F_55 ( & V_447 -> V_9 ,
& V_451 , V_452 ,
F_30 ( V_452 ) ) ;
return V_29 ;
}
static int F_56 ( struct V_446 * V_447 )
{
F_57 ( & V_447 -> V_9 ) ;
return 0 ;
}
static int F_58 ( struct V_453 * V_454 ,
const struct V_455 * V_300 )
{
struct V_70 * V_71 ;
int V_29 ;
V_71 = F_50 ( & V_454 -> V_9 , sizeof( * V_71 ) , V_448 ) ;
if ( ! V_71 )
return - V_449 ;
F_59 ( V_454 , V_71 ) ;
V_71 -> V_411 = F_60 ( V_454 , & V_450 ) ;
if ( F_53 ( V_71 -> V_411 ) ) {
V_29 = F_54 ( V_71 -> V_411 ) ;
F_14 ( & V_454 -> V_9 , L_42 , V_29 ) ;
return V_29 ;
}
V_29 = F_55 ( & V_454 -> V_9 ,
& V_451 , V_452 ,
F_30 ( V_452 ) ) ;
if ( V_29 < 0 )
F_14 ( & V_454 -> V_9 , L_43 , V_29 ) ;
return V_29 ;
}
static int F_61 ( struct V_453 * V_456 )
{
F_57 ( & V_456 -> V_9 ) ;
return 0 ;
}
static int T_3 F_62 ( void )
{
int V_29 = 0 ;
#if F_63 ( V_457 )
V_29 = F_64 ( & V_458 ) ;
if ( V_29 ) {
F_65 ( V_459 L_44 ,
V_29 ) ;
}
#endif
#if F_66 ( V_460 )
V_29 = F_67 ( & V_461 ) ;
if ( V_29 ) {
F_65 ( V_459 L_45 ,
V_29 ) ;
}
#endif
return V_29 ;
}
static void T_4 F_68 ( void )
{
#if F_63 ( V_457 )
F_69 ( & V_458 ) ;
#endif
#if F_66 ( V_460 )
F_70 ( & V_461 ) ;
#endif
}
