static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = & V_5 -> V_7 ;
int V_8 , V_9 , V_10 , V_11 , V_12 , V_13 , V_14 ;
if ( ! V_5 -> V_15 )
return;
switch ( V_3 ) {
case 0 :
V_8 = V_16 ;
if ( F_3 ( V_2 , V_17 ) &
V_18 )
V_14 = 1 ;
else
V_14 = 0 ;
break;
case 1 :
V_8 = V_19 ;
if ( F_3 ( V_2 , V_17 ) &
V_20 )
V_14 = 1 ;
else
V_14 = 0 ;
break;
default:
return;
}
V_13 = V_5 -> V_21 [ V_3 ] ;
V_9 = 0 ;
V_10 = V_22 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_23 ; V_12 ++ ) {
if ( strcmp ( V_7 -> V_24 [ V_12 ] . V_25 ,
V_5 -> V_26 [ V_13 ] ) == 0 &&
abs ( V_7 -> V_24 [ V_12 ] . V_27
- V_5 -> V_28 [ V_14 ] ) < V_10 ) {
V_9 = V_12 ;
V_10 = abs ( V_7 -> V_24 [ V_12 ] . V_27
- V_5 -> V_28 [ V_14 ] ) ;
}
}
F_4 ( V_2 -> V_29 , L_1 ,
V_3 ,
V_7 -> V_24 [ V_9 ] . V_25 ,
V_7 -> V_24 [ V_9 ] . V_27 ,
V_5 -> V_28 [ V_14 ] ) ;
V_11 = F_3 ( V_2 , V_8 ) ;
V_11 &= V_30 ;
for ( V_12 = 0 ; V_12 < F_5 ( V_7 -> V_24 [ V_9 ] . V_31 ) ; V_12 ++ )
F_6 ( V_2 , V_8 + V_12 , 0xffff ,
V_7 -> V_24 [ V_9 ] . V_31 [ V_12 ] ) ;
F_6 ( V_2 , V_8 , V_30 , V_11 ) ;
}
static int F_7 ( const char * V_25 )
{
if ( strcmp ( V_25 , L_2 ) == 0 )
return 0 ;
if ( strcmp ( V_25 , L_3 ) == 0 )
return 1 ;
return - V_32 ;
}
static int F_8 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = F_9 ( V_34 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = & V_5 -> V_7 ;
int V_3 = F_7 ( V_34 -> V_37 . V_25 ) ;
int V_38 = V_36 -> V_38 . integer . V_38 [ 0 ] ;
if ( V_3 < 0 )
return V_3 ;
if ( V_38 >= V_7 -> V_23 )
return - V_32 ;
V_5 -> V_21 [ V_3 ] = V_38 ;
F_1 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_10 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = F_9 ( V_34 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_3 = F_7 ( V_34 -> V_37 . V_25 ) ;
V_36 -> V_38 . V_39 . V_40 [ 0 ] = V_5 -> V_21 [ V_3 ] ;
return 0 ;
}
static int F_11 ( struct V_41 * V_42 ,
struct V_33 * V_34 , int V_43 )
{
switch ( V_43 ) {
case V_44 :
F_12 ( 5 ) ;
break;
default:
F_13 () ;
return - V_32 ;
}
return 0 ;
}
static int F_14 ( struct V_41 * V_42 ,
struct V_33 * V_34 , int V_43 )
{
struct V_4 * V_5 = F_2 ( V_42 -> V_2 ) ;
switch ( V_43 ) {
case V_45 :
V_5 -> V_46 &= ~ V_42 -> V_47 ;
break;
case V_48 :
V_5 -> V_46 |= V_42 -> V_47 ;
break;
default:
F_13 () ;
return - V_32 ;
}
return 0 ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_49 )
{
struct V_50 * V_51 = F_16 ( V_2 -> V_29 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_12 , V_52 ;
unsigned long V_53 = 200 ;
F_17 ( V_2 , V_54 , V_49 ) ;
do {
if ( V_51 -> V_55 ) {
V_53 = F_18 ( & V_5 -> V_56 ,
F_19 ( 200 ) ) ;
if ( V_53 == 0 )
F_20 ( V_2 -> V_29 , L_4 ) ;
} else {
F_12 ( 1 ) ;
if ( -- V_12 ) {
V_53 = 0 ;
break;
}
}
V_52 = F_3 ( V_2 , V_54 ) ;
F_4 ( V_2 -> V_29 , L_5 , V_52 ) ;
} while ( V_52 & V_49 );
if ( V_53 == 0 )
F_20 ( V_2 -> V_29 , L_6 , V_49 ) ;
else
F_4 ( V_2 -> V_29 , L_7 , V_49 ) ;
}
static void F_21 ( struct V_57 * V_58 ,
enum V_59 V_43 , int V_60 )
{
struct V_1 * V_2 = F_22 ( V_58 ,
struct V_1 , V_58 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_61 , V_49 ;
if ( V_5 -> V_62 ) {
F_4 ( V_2 -> V_29 , L_8 ,
V_5 -> V_62 ) ;
F_15 ( V_2 , V_5 -> V_62
<< V_63 ) ;
V_5 -> V_62 = 0 ;
}
if ( V_5 -> V_46 != V_5 -> V_64 ) {
F_4 ( V_2 -> V_29 , L_9 ,
V_5 -> V_64 , V_5 -> V_46 ) ;
V_61 = 0 ;
V_49 = 0 ;
if ( V_5 -> V_46 & V_65 ) {
V_61 |= V_66 ;
V_49 |= V_66 ;
} else {
V_49 |= V_66 |
V_67 |
V_68 ;
}
if ( V_5 -> V_46 & V_69 ) {
V_61 |= V_70 ;
V_49 |= V_70 ;
} else {
V_49 |= V_70 |
V_71 |
V_72 ;
}
F_6 ( V_2 , V_73 , V_49 , V_61 ) ;
V_61 = 0 ;
V_49 = 0 ;
if ( V_5 -> V_46 & V_74 ) {
V_61 |= V_75 ;
V_49 |= V_75 ;
} else {
V_49 |= V_75 |
V_76 |
V_77 ;
}
if ( V_5 -> V_46 & V_78 ) {
V_61 |= V_79 ;
V_49 |= V_79 ;
} else {
V_49 |= V_79 |
V_80 |
V_81 ;
}
F_6 ( V_2 , V_82 , V_49 , V_61 ) ;
V_5 -> V_64 = V_5 -> V_46 ;
}
}
static int F_23 ( struct V_41 * V_42 ,
struct V_33 * V_34 , int V_43 )
{
struct V_4 * V_5 = F_2 ( V_42 -> V_2 ) ;
switch ( V_43 ) {
case V_44 :
V_5 -> V_62 |= 1 << V_42 -> V_47 ;
break;
default:
F_13 () ;
return - V_32 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
unsigned int V_83 )
{
switch ( V_83 ) {
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
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
case V_54 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_73 :
case V_82 :
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
case V_16 :
case V_19 :
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
return 1 ;
default:
return 0 ;
}
}
static int F_25 ( struct V_1 * V_2 ,
unsigned int V_83 )
{
switch ( V_83 ) {
case V_84 :
case V_124 :
case V_107 :
case V_108 :
case V_262 :
case V_263 :
case V_264 :
case V_123 :
case V_54 :
case V_121 :
case V_122 :
case V_138 :
case V_115 :
case V_111 :
case V_112 :
return 1 ;
default:
return 0 ;
}
}
static int F_26 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_84 , 0x8915 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
enum V_272 V_273 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_52 ;
switch ( V_273 ) {
case V_274 :
break;
case V_275 :
if ( V_2 -> V_58 . V_276 == V_277 ) {
F_6 ( V_2 , V_85 ,
V_278 , V_278 ) ;
F_12 ( 2 ) ;
}
break;
case V_277 :
if ( V_2 -> V_58 . V_276 == V_279 ) {
V_52 = F_28 ( F_5 ( V_5 -> V_280 ) ,
V_5 -> V_280 ) ;
if ( V_52 != 0 ) {
F_20 ( V_2 -> V_29 ,
L_10 ,
V_52 ) ;
return V_52 ;
}
if ( V_5 -> V_7 . V_281 >= 0 ) {
F_29 ( V_5 -> V_7 . V_281 ,
1 ) ;
F_12 ( 5 ) ;
}
V_2 -> V_282 = false ;
F_30 ( V_2 ) ;
}
F_6 ( V_2 , V_85 ,
V_278 , 0 ) ;
break;
case V_279 :
V_2 -> V_282 = true ;
if ( V_5 -> V_7 . V_281 >= 0 )
F_29 ( V_5 -> V_7 . V_281 , 0 ) ;
F_31 ( F_5 ( V_5 -> V_280 ) ,
V_5 -> V_280 ) ;
break;
}
V_2 -> V_58 . V_276 = V_273 ;
return 0 ;
}
static int F_32 ( struct V_283 * V_284 , unsigned int V_285 )
{
struct V_1 * V_2 = V_284 -> V_2 ;
int V_286 = 0 ;
int V_287 = 0 ;
int V_288 = 0 ;
int V_289 = 0 ;
int V_290 , V_291 , V_292 , V_293 ;
switch ( V_284 -> V_37 ) {
case 0 :
V_290 = V_141 ;
V_291 = V_142 ;
V_292 = V_144 ;
V_293 = V_146 ;
break;
case 1 :
V_290 = V_164 ;
V_291 = V_165 ;
V_292 = V_167 ;
V_293 = V_169 ;
break;
default:
F_13 () ;
return - V_32 ;
}
switch ( V_285 & V_294 ) {
case V_295 :
break;
case V_296 :
V_287 |= V_297 ;
break;
case V_298 :
V_288 |= V_299 ;
V_289 |= V_300 ;
break;
case V_301 :
V_287 |= V_297 ;
V_288 |= V_299 ;
V_289 |= V_300 ;
break;
}
switch ( V_285 & V_302 ) {
case V_303 :
break;
case V_304 :
V_288 |= V_305 ;
V_289 |= V_306 ;
break;
case V_307 :
V_287 |= V_308 ;
break;
case V_309 :
V_287 |= V_308 ;
V_288 |= V_305 ;
V_289 |= V_306 ;
break;
default:
return - V_32 ;
}
switch ( V_285 & V_310 ) {
case V_311 :
break;
case V_312 :
V_286 |= 1 ;
break;
case V_313 :
V_286 |= 2 ;
break;
case V_314 :
V_286 |= 3 ;
break;
default:
return - V_32 ;
}
F_6 ( V_2 , V_290 , V_315 , V_286 ) ;
F_6 ( V_2 , V_291 ,
V_297 | V_308 ,
V_287 ) ;
F_6 ( V_2 , V_292 ,
V_299 |
V_305 ,
V_288 ) ;
F_6 ( V_2 , V_293 ,
V_300 |
V_306 ,
V_289 ) ;
return 0 ;
}
static int F_33 ( struct V_316 * V_317 ,
struct V_318 * V_319 ,
struct V_283 * V_284 )
{
struct V_1 * V_2 = V_284 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_320 , V_12 , V_321 , V_9 , V_322 ;
int V_323 = 0 ;
int V_287 = 0 ;
int V_324 = 0 ;
int V_325 = 0 ;
int V_326 , V_291 , V_327 , V_328 ;
if ( ! V_5 -> V_329 ) {
F_20 ( V_2 -> V_29 , L_11 ) ;
return - V_32 ;
}
switch ( V_284 -> V_37 ) {
case 0 :
if ( V_317 -> V_330 == V_331 ||
( F_3 ( V_2 , V_255 ) ) & V_332 ) {
V_326 = V_149 ;
V_327 = V_145 ;
} else {
V_326 = V_147 ;
V_327 = V_143 ;
}
V_291 = V_142 ;
V_328 = 0 ;
break;
case 1 :
if ( V_317 -> V_330 == V_331 ||
( F_3 ( V_2 , V_256 ) ) & V_333 ) {
V_326 = V_172 ;
V_327 = V_168 ;
} else {
V_326 = V_170 ;
V_327 = V_166 ;
}
V_291 = V_165 ;
V_328 = V_334 ;
break;
default:
F_13 () ;
return - V_32 ;
}
V_321 = F_34 ( V_319 ) ;
if ( V_321 < 0 ) {
F_20 ( V_2 -> V_29 , L_12 , V_321 ) ;
return V_321 ;
}
V_320 = F_35 ( F_36 ( V_319 ) ) ;
if ( V_320 < 0 )
return V_320 ;
V_323 |= ( V_320 << V_335 ) | V_320 ;
for ( V_12 = 0 ; V_12 < F_5 ( V_336 ) ; V_12 ++ ) {
if ( V_336 [ V_12 ] == F_37 ( V_319 ) )
break;
}
if ( V_12 == F_5 ( V_336 ) ) {
F_20 ( V_2 -> V_29 , L_13 ,
F_37 ( V_319 ) ) ;
return - V_32 ;
}
V_325 |= V_12 << V_328 ;
V_9 = 0 ;
for ( V_12 = 0 ; V_12 < F_5 ( V_337 ) ; V_12 ++ ) {
V_322 = ( V_5 -> V_329 / V_337 [ V_12 ] ) - V_321 ;
if ( V_322 < 0 )
break;
V_9 = V_12 ;
}
V_321 = V_5 -> V_329 / V_337 [ V_9 ] ;
F_4 ( V_284 -> V_29 , L_14 ,
V_337 [ V_9 ] , V_321 ) ;
V_287 |= V_9 ;
V_324 = V_321 / F_37 ( V_319 ) ;
F_4 ( V_284 -> V_29 , L_15 ,
V_324 , V_321 / V_324 ) ;
F_6 ( V_2 , V_326 ,
V_338 |
V_339 ,
V_323 ) ;
F_6 ( V_2 , V_291 , V_340 , V_287 ) ;
F_6 ( V_2 , V_327 , V_341 ,
V_324 ) ;
F_6 ( V_2 , V_129 ,
V_342 << V_328 , V_325 ) ;
V_5 -> V_28 [ V_284 -> V_37 ] = F_37 ( V_319 ) ;
return 0 ;
}
static int F_38 ( struct V_283 * V_284 ,
int V_343 , unsigned int V_344 , int V_345 )
{
struct V_1 * V_2 = V_284 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_346 = 0 ;
int V_347 = 0 ;
int V_348 ;
int V_349 ;
V_349 = F_3 ( V_2 , V_128 ) & V_350 ;
F_6 ( V_2 , V_128 ,
V_350 , 0 ) ;
switch ( V_343 ) {
case V_351 :
V_5 -> V_329 = V_344 ;
V_348 = 0 ;
break;
case V_352 :
V_5 -> V_329 = V_344 ;
V_348 = 1 ;
break;
case V_353 :
V_5 -> V_329 = V_344 ;
V_348 = 2 ;
break;
default:
F_20 ( V_2 -> V_29 , L_16 , V_343 ) ;
return - V_32 ;
}
switch ( V_5 -> V_329 ) {
case 6144000 :
F_6 ( V_2 , V_132 ,
V_354 , 0 ) ;
break;
case 24576000 :
V_347 = V_355 ;
case 12288000 :
F_6 ( V_2 , V_132 ,
V_354 , V_354 ) ;
break;
case 32000 :
case 32768 :
V_346 = V_356 ;
break;
default:
F_39 ( V_2 -> V_29 , L_17 ,
V_5 -> V_329 ) ;
return - V_32 ;
}
F_6 ( V_2 , V_128 ,
V_357 | V_358 ,
V_348 << V_359 | V_347 ) ;
F_6 ( V_2 , V_130 , V_356 , V_346 ) ;
F_6 ( V_2 , V_128 ,
V_350 , V_349 ) ;
return 0 ;
}
static int F_40 ( struct V_360 * V_361 , unsigned int V_362 ,
unsigned int V_363 )
{
unsigned int V_364 ;
unsigned int div ;
unsigned int V_365 , V_366 ;
int V_12 ;
div = 1 ;
V_361 -> V_367 = 0 ;
while ( ( V_362 / div ) > 13500000 ) {
div *= 2 ;
V_361 -> V_367 ++ ;
if ( div > 8 ) {
F_41 ( L_18 ,
V_362 ) ;
return - V_32 ;
}
}
F_42 ( L_19 , V_362 , V_363 ) ;
V_362 /= div ;
if ( V_362 >= 3000000 )
V_361 -> V_368 = 5 ;
else
V_361 -> V_368 = 0 ;
if ( V_362 >= 48000 )
V_361 -> V_369 = 0 ;
else
V_361 -> V_369 = 1 ;
div = 2 ;
while ( V_363 * div < 90000000 ) {
div ++ ;
if ( div > 64 ) {
F_41 ( L_20 ,
V_363 ) ;
return - V_32 ;
}
}
V_364 = V_363 * div ;
V_361 -> V_370 = div - 1 ;
F_42 ( L_21 , V_364 ) ;
for ( V_12 = 0 ; V_12 < F_5 ( V_371 ) ; V_12 ++ ) {
if ( V_371 [ V_12 ] . V_372 <= V_362 && V_362 <= V_371 [ V_12 ] . V_373 ) {
V_361 -> V_374 = V_371 [ V_12 ] . V_374 ;
V_365 = V_371 [ V_12 ] . V_375 ;
break;
}
}
if ( V_12 == F_5 ( V_371 ) ) {
F_41 ( L_22 , V_362 ) ;
return - V_32 ;
}
V_361 -> V_376 = V_364 / ( V_365 * V_362 ) ;
if ( V_364 % V_362 == 0 ) {
V_361 -> V_377 = 0 ;
V_361 -> V_378 = 0 ;
} else {
V_366 = F_43 ( V_364 , V_365 * V_362 ) ;
V_361 -> V_377 = ( V_364 - ( V_361 -> V_376 * V_365 * V_362 ) )
/ V_366 ;
V_361 -> V_378 = ( V_365 * V_362 ) / V_366 ;
}
F_42 ( L_23 ,
V_361 -> V_376 , V_361 -> V_377 , V_361 -> V_378 ) ;
F_42 ( L_24 ,
V_361 -> V_374 , V_361 -> V_370 ,
V_361 -> V_367 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , int V_379 , int V_380 ,
unsigned int V_362 , unsigned int V_363 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_360 V_361 ;
unsigned long V_53 ;
int V_52 , V_83 ;
if ( V_380 == V_5 -> V_381 && V_362 == V_5 -> V_382 &&
V_363 == V_5 -> V_383 )
return 0 ;
if ( V_363 == 0 ) {
F_4 ( V_2 -> V_29 , L_25 ) ;
V_5 -> V_382 = 0 ;
V_5 -> V_383 = 0 ;
F_6 ( V_2 , V_133 ,
V_384 , 0 ) ;
return 0 ;
}
V_52 = F_40 ( & V_361 , V_362 , V_363 ) ;
if ( V_52 != 0 )
return V_52 ;
switch ( V_380 ) {
case V_385 :
V_83 = 0 ;
break;
case V_386 :
V_83 = 1 ;
break;
case V_387 :
V_83 = 2 ;
break;
case V_388 :
V_83 = 3 ;
break;
default:
F_20 ( V_2 -> V_29 , L_26 , V_52 ) ;
return - V_32 ;
}
V_83 |= V_361 . V_367 << V_389 ;
V_83 |= V_361 . V_369 << V_390 ;
F_6 ( V_2 , V_137 ,
V_391 | V_392 |
V_393 , V_83 ) ;
V_83 = 0 ;
if ( V_361 . V_377 || V_361 . V_378 )
V_83 |= V_394 | ( 3 << V_395 ) ;
else
V_83 |= 1 << V_395 ;
F_17 ( V_2 , V_140 , V_83 ) ;
F_6 ( V_2 , V_134 ,
V_396 |
V_397 ,
( V_361 . V_370 << V_398 ) |
( V_361 . V_374 ) ) ;
F_17 ( V_2 , V_135 , V_361 . V_377 ) ;
F_6 ( V_2 , V_136 ,
V_399 | V_400 ,
( V_361 . V_376 << V_401 ) |
V_361 . V_368 ) ;
F_17 ( V_2 , V_139 , V_361 . V_378 ) ;
F_6 ( V_2 , V_133 ,
V_384 , V_384 ) ;
F_17 ( V_2 , V_138 , V_402 ) ;
if ( V_362 > 1000000 )
V_53 = F_45 ( 300 ) ;
else
V_53 = F_19 ( 2 ) ;
F_18 ( & V_5 -> V_403 , V_53 ) ;
F_4 ( V_2 -> V_29 , L_27 , V_362 , V_363 ) ;
V_5 -> V_382 = V_362 ;
V_5 -> V_383 = V_363 ;
V_5 -> V_381 = V_380 ;
return 0 ;
}
static inline struct V_4 * F_46 ( struct V_404 * V_405 )
{
return F_22 ( V_405 , struct V_4 , V_404 ) ;
}
static void F_47 ( struct V_404 * V_405 , unsigned V_406 , int V_38 )
{
struct V_4 * V_5 = F_46 ( V_405 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
F_6 ( V_2 , V_255 + V_406 ,
V_407 , ! ! V_38 << V_408 ) ;
}
static int F_48 ( struct V_404 * V_405 ,
unsigned V_406 , int V_38 )
{
struct V_4 * V_5 = F_46 ( V_405 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
int V_61 ;
V_61 = ( 1 << V_409 ) | ( ! ! V_38 << V_408 ) ;
return F_6 ( V_2 , V_255 + V_406 ,
V_332 | V_410 |
V_407 , V_61 ) ;
}
static int F_49 ( struct V_404 * V_405 , unsigned V_406 )
{
struct V_4 * V_5 = F_46 ( V_405 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
int V_52 ;
V_52 = F_3 ( V_2 , V_255 + V_406 ) ;
if ( V_52 < 0 )
return V_52 ;
return ( V_52 & V_407 ) != 0 ;
}
static int F_50 ( struct V_404 * V_405 , unsigned V_406 )
{
struct V_4 * V_5 = F_46 ( V_405 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
return F_6 ( V_2 , V_255 + V_406 ,
V_332 | V_410 ,
( 1 << V_409 ) |
( 1 << V_411 ) ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_52 ;
V_5 -> V_404 = V_412 ;
V_5 -> V_404 . V_413 = 5 ;
V_5 -> V_404 . V_29 = V_2 -> V_29 ;
if ( V_5 -> V_7 . V_414 )
V_5 -> V_404 . V_8 = V_5 -> V_7 . V_414 ;
else
V_5 -> V_404 . V_8 = - 1 ;
V_52 = F_52 ( & V_5 -> V_404 ) ;
if ( V_52 != 0 )
F_20 ( V_2 -> V_29 , L_28 , V_52 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_52 ;
V_52 = F_54 ( & V_5 -> V_404 ) ;
if ( V_52 != 0 )
F_20 ( V_2 -> V_29 , L_29 , V_52 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
}
static void F_53 ( struct V_1 * V_2 )
{
}
int F_55 ( struct V_1 * V_2 , struct V_415 * V_416 ,
T_2 V_417 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_416 = V_416 ;
V_5 -> V_418 = true ;
V_5 -> V_417 = V_417 ;
if ( V_5 -> V_417 )
V_5 -> V_417 ( V_2 , 0 ) ;
F_6 ( V_2 , V_105 ,
V_419 , 0 ) ;
F_6 ( V_2 , V_106 ,
V_420 , 0 ) ;
F_56 ( & V_2 -> V_58 , L_30 ) ;
F_56 ( & V_2 -> V_58 , L_31 ) ;
F_6 ( V_2 , V_113 ,
V_421 , V_421 ) ;
F_6 ( V_2 , V_113 ,
V_422 ,
V_422 ) ;
F_6 ( V_2 , V_266 ,
V_423 , 0 ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_61 , V_83 ;
V_61 = F_3 ( V_2 , V_115 ) ;
F_4 ( V_2 -> V_29 , L_32 , V_61 ) ;
if ( ! ( V_61 & V_424 ) ) {
F_39 ( V_2 -> V_29 , L_33 ) ;
return;
}
if ( ! ( V_61 & V_425 ) ) {
F_4 ( V_2 -> V_29 , L_34 ) ;
V_5 -> V_426 = false ;
V_5 -> V_418 = true ;
F_58 ( V_5 -> V_416 , 0 ,
V_427 | V_428 ) ;
F_6 ( V_2 , V_113 ,
V_422 ,
V_422 ) ;
return;
}
if ( V_61 & 0x400 ) {
F_4 ( V_2 -> V_29 , L_35 ) ;
F_58 ( V_5 -> V_416 , V_427 ,
V_427 | V_428 ) ;
V_5 -> V_426 = true ;
V_5 -> V_418 = false ;
}
if ( V_5 -> V_418 && ( V_61 & 0x3f0 ) ) {
V_83 = F_3 ( V_2 , V_110 ) ;
V_83 ^= V_429 | V_430 |
V_431 ;
F_6 ( V_2 , V_110 ,
V_429 | V_430 |
V_431 , V_83 ) ;
if ( V_5 -> V_417 )
V_5 -> V_417 ( V_2 ,
( V_83 & V_430 ) != 0 ) ;
F_4 ( V_2 -> V_29 , L_36 ,
( V_83 & V_430 ) != 0 ) ;
return;
}
if ( V_61 & 0x3fc ) {
if ( V_5 -> V_426 ) {
F_4 ( V_2 -> V_29 , L_37 ) ;
F_58 ( V_5 -> V_416 ,
V_427 | V_428 ,
V_427 | V_428 ) ;
} else {
F_4 ( V_2 -> V_29 , L_38 ) ;
F_58 ( V_5 -> V_416 ,
V_432 ,
V_427 |
V_428 ) ;
V_5 -> V_418 = false ;
}
}
if ( ! V_5 -> V_418 )
F_6 ( V_2 , V_113 ,
V_422 ,
5 << V_433 ) ;
}
static T_3 F_59 ( int V_55 , void * V_434 )
{
struct V_1 * V_2 = V_434 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_435 ;
V_435 = F_3 ( V_2 , V_263 ) ;
if ( V_435 < 0 ) {
F_20 ( V_2 -> V_29 , L_39 ,
V_435 ) ;
return V_436 ;
}
V_435 &= ~ F_3 ( V_2 , V_266 ) ;
if ( V_435 & ( V_437 | V_438 ) ) {
F_4 ( V_2 -> V_29 , L_40 ) ;
F_60 ( & V_5 -> V_56 ) ;
}
if ( V_435 & V_439 )
F_20 ( V_2 -> V_29 , L_41 ) ;
if ( V_435 & V_440 ) {
F_4 ( V_2 -> V_29 , L_42 ) ;
F_60 ( & V_5 -> V_403 ) ;
}
if ( V_435 & V_441 )
F_57 ( V_2 ) ;
if ( V_435 ) {
F_17 ( V_2 , V_263 , V_435 ) ;
return V_442 ;
} else {
return V_436 ;
}
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_443 V_444 [] = {
F_62 ( L_2 ,
V_5 -> V_445 ,
F_10 ,
F_8 ) ,
F_62 ( L_3 ,
V_5 -> V_445 ,
F_10 ,
F_8 ) ,
} ;
int V_52 , V_12 , V_446 ;
const char * * V_447 ;
V_5 -> V_15 = 0 ;
V_5 -> V_26 = NULL ;
for ( V_12 = 0 ; V_12 < V_7 -> V_23 ; V_12 ++ ) {
for ( V_446 = 0 ; V_446 < V_5 -> V_15 ; V_446 ++ ) {
if ( strcmp ( V_7 -> V_24 [ V_12 ] . V_25 ,
V_5 -> V_26 [ V_446 ] ) == 0 )
break;
}
if ( V_446 != V_5 -> V_15 )
continue;
V_447 = F_63 ( V_5 -> V_26 ,
sizeof( char * ) *
( V_5 -> V_15 + 1 ) ,
V_448 ) ;
if ( V_447 == NULL )
continue;
V_447 [ V_5 -> V_15 ] =
V_7 -> V_24 [ V_12 ] . V_25 ;
V_5 -> V_15 ++ ;
V_5 -> V_26 = V_447 ;
}
F_4 ( V_2 -> V_29 , L_43 ,
V_5 -> V_15 ) ;
V_5 -> V_445 . V_373 = V_5 -> V_15 ;
V_5 -> V_445 . V_449 = V_5 -> V_26 ;
V_52 = F_64 ( V_2 , V_444 , F_5 ( V_444 ) ) ;
if ( V_52 != 0 )
F_20 ( V_2 -> V_29 ,
L_44 , V_52 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
int V_52 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_50 * V_51 = F_16 ( V_2 -> V_29 ) ;
struct V_57 * V_58 = & V_2 -> V_58 ;
int V_12 , V_450 ;
V_5 -> V_2 = V_2 ;
F_66 ( & V_5 -> V_56 ) ;
F_66 ( & V_5 -> V_403 ) ;
V_58 -> V_451 = true ;
V_58 -> V_276 = V_279 ;
V_52 = F_67 ( V_2 , 16 , 16 , V_452 ) ;
if ( V_52 != 0 ) {
F_20 ( V_2 -> V_29 , L_45 , V_52 ) ;
goto V_453;
}
for ( V_12 = 0 ; V_12 < F_5 ( V_5 -> V_280 ) ; V_12 ++ )
V_5 -> V_280 [ V_12 ] . V_454 = V_455 [ V_12 ] ;
V_52 = F_68 ( V_2 -> V_29 , F_5 ( V_5 -> V_280 ) ,
V_5 -> V_280 ) ;
if ( V_52 != 0 ) {
F_20 ( V_2 -> V_29 , L_46 , V_52 ) ;
goto V_453;
}
V_5 -> V_456 [ 0 ] . V_457 = V_458 ;
V_5 -> V_456 [ 1 ] . V_457 = V_459 ;
V_5 -> V_456 [ 2 ] . V_457 = V_460 ;
V_5 -> V_456 [ 3 ] . V_457 = V_461 ;
V_5 -> V_456 [ 4 ] . V_457 = V_462 ;
V_5 -> V_456 [ 5 ] . V_457 = V_463 ;
for ( V_12 = 0 ; V_12 < F_5 ( V_5 -> V_280 ) ; V_12 ++ ) {
V_52 = F_69 ( V_5 -> V_280 [ V_12 ] . V_464 ,
& V_5 -> V_456 [ V_12 ] ) ;
if ( V_52 != 0 ) {
F_20 ( V_2 -> V_29 ,
L_47 ,
V_52 ) ;
}
}
V_52 = F_28 ( F_5 ( V_5 -> V_280 ) ,
V_5 -> V_280 ) ;
if ( V_52 != 0 ) {
F_20 ( V_2 -> V_29 , L_10 , V_52 ) ;
goto V_465;
}
if ( V_5 -> V_7 . V_281 >= 0 ) {
F_29 ( V_5 -> V_7 . V_281 , 1 ) ;
F_12 ( 5 ) ;
}
V_52 = F_3 ( V_2 , V_84 ) ;
if ( V_52 < 0 ) {
F_20 ( V_2 -> V_29 , L_48 , V_52 ) ;
goto V_466;
}
if ( V_52 != 0x8915 ) {
F_20 ( V_2 -> V_29 , L_49 , V_52 ) ;
V_52 = - V_32 ;
goto V_466;
}
V_52 = F_3 ( V_2 , V_124 ) ;
if ( V_52 < 0 ) {
F_20 ( V_2 -> V_29 , L_50 ,
V_52 ) ;
goto V_466;
}
F_70 ( V_2 -> V_29 , L_51 ,
( V_52 & V_467 ) + 'A' ) ;
if ( V_5 -> V_7 . V_281 >= 0 ) {
F_29 ( V_5 -> V_7 . V_281 , 0 ) ;
} else {
V_52 = F_26 ( V_2 ) ;
if ( V_52 < 0 ) {
F_20 ( V_2 -> V_29 , L_52 ) ;
goto V_466;
}
}
V_2 -> V_282 = true ;
F_6 ( V_2 , V_94 ,
V_468 | V_469 ,
V_5 -> V_7 . V_470 << V_471 |
V_5 -> V_7 . V_472 ) ;
for ( V_12 = 0 ; V_12 < F_5 ( V_5 -> V_7 . V_473 ) ; V_12 ++ ) {
if ( ! V_5 -> V_7 . V_473 [ V_12 ] )
continue;
F_17 ( V_2 , V_255 + V_12 ,
V_5 -> V_7 . V_473 [ V_12 ] & 0xffff ) ;
}
if ( V_5 -> V_7 . V_474 )
F_6 ( V_2 , V_270 ,
V_475 |
V_476 ,
V_5 -> V_7 . V_474 ) ;
F_6 ( V_2 , V_110 ,
V_431 | V_429 |
V_430 , V_5 -> V_7 . V_477 ) ;
F_6 ( V_2 , V_92 ,
V_478 , V_478 ) ;
F_6 ( V_2 , V_93 ,
V_478 , V_478 ) ;
F_6 ( V_2 , V_97 ,
V_479 , V_479 ) ;
F_6 ( V_2 , V_98 ,
V_479 , V_479 ) ;
F_6 ( V_2 , V_99 ,
V_480 , V_480 ) ;
F_6 ( V_2 , V_100 ,
V_480 , V_480 ) ;
F_6 ( V_2 , V_101 ,
V_479 , V_479 ) ;
F_6 ( V_2 , V_102 ,
V_479 , V_479 ) ;
F_6 ( V_2 , V_103 ,
V_480 , V_480 ) ;
F_6 ( V_2 , V_104 ,
V_480 , V_480 ) ;
F_6 ( V_2 , V_179 ,
V_481 , V_481 ) ;
F_6 ( V_2 , V_180 ,
V_481 , V_481 ) ;
F_6 ( V_2 , V_209 ,
V_482 , V_482 ) ;
F_6 ( V_2 , V_210 ,
V_482 , V_482 ) ;
F_6 ( V_2 , V_181 ,
V_483 , V_483 ) ;
F_6 ( V_2 , V_182 ,
V_483 , V_483 ) ;
F_6 ( V_2 , V_211 ,
V_484 , V_484 ) ;
F_6 ( V_2 , V_212 ,
V_484 , V_484 ) ;
F_6 ( V_2 , V_156 ,
V_485 |
V_486 ,
1 << V_487 | 0 ) ;
F_6 ( V_2 , V_157 ,
V_488 |
V_489 ,
1 << V_490 | 1 ) ;
F_6 ( V_2 , V_158 ,
V_491 |
V_492 ,
1 << V_493 | 0 ) ;
F_6 ( V_2 , V_159 ,
V_494 |
V_486 ,
1 << V_495 | 1 ) ;
F_6 ( V_2 , V_160 ,
V_496 |
V_486 ,
1 << V_497 | 0 ) ;
F_6 ( V_2 , V_161 ,
V_498 |
V_486 ,
1 << V_499 | 1 ) ;
F_6 ( V_2 , V_175 ,
V_500 |
V_501 ,
1 << V_502 | 0 ) ;
F_6 ( V_2 , V_176 ,
V_503 |
V_504 ,
1 << V_505 | 1 ) ;
F_6 ( V_2 , V_150 ,
V_506 |
V_507 ,
1 << V_508 | 0 ) ;
F_6 ( V_2 , V_151 ,
V_509 |
V_507 ,
1 << V_510 | 1 ) ;
F_6 ( V_2 , V_152 ,
V_511 |
V_507 ,
1 << V_512 | 0 ) ;
F_6 ( V_2 , V_153 ,
V_513 |
V_507 ,
1 << V_514 | 1 ) ;
F_6 ( V_2 , V_154 ,
V_515 |
V_507 ,
1 << V_516 | 0 ) ;
F_6 ( V_2 , V_155 ,
V_517 |
V_507 ,
1 << V_518 | 1 ) ;
F_6 ( V_2 , V_173 ,
V_519 |
V_520 ,
1 << V_521 | 0 ) ;
F_6 ( V_2 , V_151 ,
V_522 |
V_523 ,
1 << V_510 | 1 ) ;
if ( V_5 -> V_7 . V_23 )
F_61 ( V_2 ) ;
else
F_64 ( V_2 , V_524 ,
F_5 ( V_524 ) ) ;
if ( ( F_3 ( V_2 , V_255 ) ) )
F_6 ( V_2 , V_144 ,
V_525 ,
V_525 ) ;
if ( ( F_3 ( V_2 , V_256 ) ) )
F_6 ( V_2 , V_167 ,
V_526 ,
V_526 ) ;
F_31 ( F_5 ( V_5 -> V_280 ) , V_5 -> V_280 ) ;
F_51 ( V_2 ) ;
if ( V_51 -> V_55 ) {
if ( V_5 -> V_7 . V_450 )
V_450 = V_5 -> V_7 . V_450 ;
else
V_450 = V_527 ;
V_450 |= V_528 ;
V_52 = F_71 ( V_51 -> V_55 , NULL , F_59 ,
V_450 , L_53 , V_2 ) ;
if ( V_52 == 0 ) {
F_6 ( V_2 , V_267 ,
V_529 , 0 ) ;
F_6 ( V_2 ,
V_266 ,
V_530 |
V_531 |
V_532 |
V_533 ,
0 ) ;
} else {
F_20 ( V_2 -> V_29 , L_54 ,
V_52 ) ;
}
}
return 0 ;
V_466:
if ( V_5 -> V_7 . V_281 >= 0 )
F_29 ( V_5 -> V_7 . V_281 , 0 ) ;
F_31 ( F_5 ( V_5 -> V_280 ) , V_5 -> V_280 ) ;
V_465:
F_72 ( F_5 ( V_5 -> V_280 ) , V_5 -> V_280 ) ;
V_453:
return V_52 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_50 * V_51 = F_16 ( V_2 -> V_29 ) ;
int V_12 ;
F_6 ( V_2 , V_267 ,
V_529 , V_529 ) ;
if ( V_51 -> V_55 )
F_74 ( V_51 -> V_55 , V_2 ) ;
F_53 ( V_2 ) ;
for ( V_12 = 0 ; V_12 < F_5 ( V_5 -> V_280 ) ; V_12 ++ )
F_75 ( V_5 -> V_280 [ V_12 ] . V_464 ,
& V_5 -> V_456 [ V_12 ] ) ;
F_72 ( F_5 ( V_5 -> V_280 ) , V_5 -> V_280 ) ;
return 0 ;
}
static T_4 int F_76 ( struct V_50 * V_51 ,
const struct V_534 * V_37 )
{
struct V_4 * V_5 ;
int V_52 ;
V_5 = F_77 ( sizeof( struct V_4 ) , V_448 ) ;
if ( V_5 == NULL )
return - V_535 ;
F_78 ( V_51 , V_5 ) ;
if ( F_79 ( & V_51 -> V_29 ) )
memcpy ( & V_5 -> V_7 , F_79 ( & V_51 -> V_29 ) ,
sizeof( V_5 -> V_7 ) ) ;
if ( V_5 -> V_7 . V_281 > 0 ) {
V_52 = F_80 ( V_5 -> V_7 . V_281 ,
V_536 , L_55 ) ;
if ( V_52 < 0 ) {
F_20 ( & V_51 -> V_29 , L_56 ,
V_5 -> V_7 . V_281 , V_52 ) ;
goto V_453;
}
}
V_52 = F_81 ( & V_51 -> V_29 ,
& V_537 , V_538 ,
F_5 ( V_538 ) ) ;
if ( V_52 < 0 )
goto V_539;
return V_52 ;
V_539:
if ( V_5 -> V_7 . V_281 > 0 )
F_82 ( V_5 -> V_7 . V_281 ) ;
V_453:
F_83 ( V_5 ) ;
return V_52 ;
}
static T_5 int F_84 ( struct V_50 * V_540 )
{
struct V_4 * V_5 = F_85 ( V_540 ) ;
F_86 ( & V_540 -> V_29 ) ;
if ( V_5 -> V_7 . V_281 > 0 )
F_82 ( V_5 -> V_7 . V_281 ) ;
F_83 ( F_85 ( V_540 ) ) ;
return 0 ;
}
static int T_6 F_87 ( void )
{
int V_52 ;
V_52 = F_88 ( & V_541 ) ;
if ( V_52 != 0 ) {
F_89 ( V_542 L_57 ,
V_52 ) ;
}
return V_52 ;
}
static void T_7 F_90 ( void )
{
F_91 ( & V_541 ) ;
}
