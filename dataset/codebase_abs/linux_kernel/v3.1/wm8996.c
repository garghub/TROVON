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
static void F_27 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_272 , V_9 , V_273 , V_274 , V_275 , V_12 ;
if ( V_5 -> V_276 < 64000 )
return;
for ( V_272 = 0 ; V_272 < V_277 ; V_272 ++ ) {
switch ( V_272 ) {
case 0 :
V_275 = V_142 ;
break;
case 1 :
V_275 = V_165 ;
break;
}
V_274 = V_5 -> V_274 [ V_272 ] ;
V_9 = 0 ;
for ( V_12 = 0 ; V_12 < F_5 ( V_278 ) ; V_12 ++ ) {
V_273 = ( V_5 -> V_276 / V_278 [ V_12 ] ) - V_274 ;
if ( V_273 < 0 )
break;
V_9 = V_12 ;
}
V_274 = V_5 -> V_276 / V_278 [ V_9 ] ;
F_4 ( V_2 -> V_29 , L_10 ,
V_278 [ V_9 ] , V_274 ) ;
F_6 ( V_2 , V_275 ,
V_279 , V_9 ) ;
}
}
static int F_28 ( struct V_1 * V_2 ,
enum V_280 V_281 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_52 ;
switch ( V_281 ) {
case V_282 :
break;
case V_283 :
if ( V_2 -> V_58 . V_284 == V_285 ) {
F_6 ( V_2 , V_85 ,
V_286 , V_286 ) ;
F_12 ( 2 ) ;
}
break;
case V_285 :
if ( V_2 -> V_58 . V_284 == V_287 ) {
V_52 = F_29 ( F_5 ( V_5 -> V_288 ) ,
V_5 -> V_288 ) ;
if ( V_52 != 0 ) {
F_20 ( V_2 -> V_29 ,
L_11 ,
V_52 ) ;
return V_52 ;
}
if ( V_5 -> V_7 . V_289 >= 0 ) {
F_30 ( V_5 -> V_7 . V_289 ,
1 ) ;
F_12 ( 5 ) ;
}
V_2 -> V_290 = false ;
F_31 ( V_2 ) ;
}
F_6 ( V_2 , V_85 ,
V_286 , 0 ) ;
break;
case V_287 :
V_2 -> V_290 = true ;
if ( V_5 -> V_7 . V_289 >= 0 )
F_30 ( V_5 -> V_7 . V_289 , 0 ) ;
F_32 ( F_5 ( V_5 -> V_288 ) ,
V_5 -> V_288 ) ;
break;
}
V_2 -> V_58 . V_284 = V_281 ;
return 0 ;
}
static int F_33 ( struct V_291 * V_292 , unsigned int V_293 )
{
struct V_1 * V_2 = V_292 -> V_2 ;
int V_294 = 0 ;
int V_295 = 0 ;
int V_296 = 0 ;
int V_297 = 0 ;
int V_298 , V_275 , V_299 , V_300 ;
switch ( V_292 -> V_37 ) {
case 0 :
V_298 = V_141 ;
V_275 = V_142 ;
V_299 = V_144 ;
V_300 = V_146 ;
break;
case 1 :
V_298 = V_164 ;
V_275 = V_165 ;
V_299 = V_167 ;
V_300 = V_169 ;
break;
default:
F_13 () ;
return - V_32 ;
}
switch ( V_293 & V_301 ) {
case V_302 :
break;
case V_303 :
V_295 |= V_304 ;
break;
case V_305 :
V_296 |= V_306 ;
V_297 |= V_307 ;
break;
case V_308 :
V_295 |= V_304 ;
V_296 |= V_306 ;
V_297 |= V_307 ;
break;
}
switch ( V_293 & V_309 ) {
case V_310 :
break;
case V_311 :
V_296 |= V_312 ;
V_297 |= V_313 ;
break;
case V_314 :
V_295 |= V_315 ;
break;
case V_316 :
V_295 |= V_315 ;
V_296 |= V_312 ;
V_297 |= V_313 ;
break;
default:
return - V_32 ;
}
switch ( V_293 & V_317 ) {
case V_318 :
break;
case V_319 :
V_294 |= 1 ;
break;
case V_320 :
V_294 |= 2 ;
break;
case V_321 :
V_294 |= 3 ;
break;
default:
return - V_32 ;
}
F_6 ( V_2 , V_298 , V_322 , V_294 ) ;
F_6 ( V_2 , V_275 ,
V_304 | V_315 ,
V_295 ) ;
F_6 ( V_2 , V_299 ,
V_306 |
V_312 ,
V_296 ) ;
F_6 ( V_2 , V_300 ,
V_307 |
V_313 ,
V_297 ) ;
return 0 ;
}
static int F_34 ( struct V_323 * V_324 ,
struct V_325 * V_326 ,
struct V_291 * V_292 )
{
struct V_1 * V_2 = V_292 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_327 , V_12 , V_274 ;
int V_328 = 0 ;
int V_329 = 0 ;
int V_330 = 0 ;
int V_331 , V_332 , V_333 ;
switch ( V_292 -> V_37 ) {
case 0 :
if ( V_324 -> V_334 == V_335 ||
( F_3 ( V_2 , V_255 ) ) & V_336 ) {
V_331 = V_149 ;
V_332 = V_145 ;
} else {
V_331 = V_147 ;
V_332 = V_143 ;
}
V_333 = 0 ;
break;
case 1 :
if ( V_324 -> V_334 == V_335 ||
( F_3 ( V_2 , V_256 ) ) & V_337 ) {
V_331 = V_172 ;
V_332 = V_168 ;
} else {
V_331 = V_170 ;
V_332 = V_166 ;
}
V_333 = V_338 ;
break;
default:
F_13 () ;
return - V_32 ;
}
V_274 = F_35 ( V_326 ) ;
if ( V_274 < 0 ) {
F_20 ( V_2 -> V_29 , L_12 , V_274 ) ;
return V_274 ;
}
V_5 -> V_274 [ V_292 -> V_37 ] = V_274 ;
V_5 -> V_28 [ V_292 -> V_37 ] = F_36 ( V_326 ) ;
V_327 = F_37 ( F_38 ( V_326 ) ) ;
if ( V_327 < 0 )
return V_327 ;
V_328 |= ( V_327 << V_339 ) | V_327 ;
for ( V_12 = 0 ; V_12 < F_5 ( V_340 ) ; V_12 ++ ) {
if ( V_340 [ V_12 ] == F_36 ( V_326 ) )
break;
}
if ( V_12 == F_5 ( V_340 ) ) {
F_20 ( V_2 -> V_29 , L_13 ,
F_36 ( V_326 ) ) ;
return - V_32 ;
}
V_330 |= V_12 << V_333 ;
F_27 ( V_2 ) ;
V_329 = V_274 / F_36 ( V_326 ) ;
F_4 ( V_292 -> V_29 , L_14 ,
V_329 , V_274 / V_329 ) ;
F_6 ( V_2 , V_331 ,
V_341 |
V_342 ,
V_328 ) ;
F_6 ( V_2 , V_332 , V_343 ,
V_329 ) ;
F_6 ( V_2 , V_129 ,
V_344 << V_333 , V_330 ) ;
return 0 ;
}
static int F_39 ( struct V_291 * V_292 ,
int V_345 , unsigned int V_346 , int V_347 )
{
struct V_1 * V_2 = V_292 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_348 = 0 ;
int V_349 = 0 ;
int V_350 ;
int V_351 ;
if ( V_346 == V_5 -> V_276 && V_345 == V_5 -> V_352 )
return 0 ;
V_351 = F_3 ( V_2 , V_128 ) & V_353 ;
F_6 ( V_2 , V_128 ,
V_353 , 0 ) ;
switch ( V_345 ) {
case V_354 :
V_5 -> V_276 = V_346 ;
V_350 = 0 ;
break;
case V_355 :
V_5 -> V_276 = V_346 ;
V_350 = 1 ;
break;
case V_356 :
V_5 -> V_276 = V_346 ;
V_350 = 2 ;
break;
default:
F_20 ( V_2 -> V_29 , L_15 , V_345 ) ;
return - V_32 ;
}
switch ( V_5 -> V_276 ) {
case 6144000 :
F_6 ( V_2 , V_132 ,
V_357 , 0 ) ;
break;
case 24576000 :
V_349 = V_358 ;
case 12288000 :
F_6 ( V_2 , V_132 ,
V_357 , V_357 ) ;
break;
case 32000 :
case 32768 :
V_348 = V_359 ;
break;
default:
F_40 ( V_2 -> V_29 , L_16 ,
V_5 -> V_276 ) ;
return - V_32 ;
}
F_27 ( V_2 ) ;
F_6 ( V_2 , V_128 ,
V_360 | V_361 ,
V_350 << V_362 | V_349 ) ;
F_6 ( V_2 , V_130 , V_359 , V_348 ) ;
F_6 ( V_2 , V_128 ,
V_353 , V_351 ) ;
V_5 -> V_352 = V_345 ;
return 0 ;
}
static int F_41 ( struct V_363 * V_364 , unsigned int V_365 ,
unsigned int V_366 )
{
unsigned int V_367 ;
unsigned int div ;
unsigned int V_368 , V_369 ;
int V_12 ;
div = 1 ;
V_364 -> V_370 = 0 ;
while ( ( V_365 / div ) > 13500000 ) {
div *= 2 ;
V_364 -> V_370 ++ ;
if ( div > 8 ) {
F_42 ( L_17 ,
V_365 ) ;
return - V_32 ;
}
}
F_43 ( L_18 , V_365 , V_366 ) ;
V_365 /= div ;
if ( V_365 >= 3000000 )
V_364 -> V_371 = 5 ;
else
V_364 -> V_371 = 0 ;
if ( V_365 >= 48000 )
V_364 -> V_372 = 0 ;
else
V_364 -> V_372 = 1 ;
div = 2 ;
while ( V_366 * div < 90000000 ) {
div ++ ;
if ( div > 64 ) {
F_42 ( L_19 ,
V_366 ) ;
return - V_32 ;
}
}
V_367 = V_366 * div ;
V_364 -> V_373 = div - 1 ;
F_43 ( L_20 , V_367 ) ;
for ( V_12 = 0 ; V_12 < F_5 ( V_374 ) ; V_12 ++ ) {
if ( V_374 [ V_12 ] . V_375 <= V_365 && V_365 <= V_374 [ V_12 ] . V_376 ) {
V_364 -> V_377 = V_374 [ V_12 ] . V_377 ;
V_368 = V_374 [ V_12 ] . V_378 ;
break;
}
}
if ( V_12 == F_5 ( V_374 ) ) {
F_42 ( L_21 , V_365 ) ;
return - V_32 ;
}
V_364 -> V_379 = V_367 / ( V_368 * V_365 ) ;
if ( V_367 % V_365 == 0 ) {
V_364 -> V_380 = 0 ;
V_364 -> V_381 = 0 ;
} else {
V_369 = F_44 ( V_367 , V_368 * V_365 ) ;
V_364 -> V_380 = ( V_367 - ( V_364 -> V_379 * V_368 * V_365 ) )
/ V_369 ;
V_364 -> V_381 = ( V_368 * V_365 ) / V_369 ;
}
F_43 ( L_22 ,
V_364 -> V_379 , V_364 -> V_380 , V_364 -> V_381 ) ;
F_43 ( L_23 ,
V_364 -> V_377 , V_364 -> V_373 ,
V_364 -> V_370 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , int V_382 , int V_383 ,
unsigned int V_365 , unsigned int V_366 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_50 * V_51 = F_16 ( V_2 -> V_29 ) ;
struct V_363 V_364 ;
unsigned long V_53 ;
int V_52 , V_83 ;
if ( V_383 == V_5 -> V_384 && V_365 == V_5 -> V_385 &&
V_366 == V_5 -> V_386 )
return 0 ;
if ( V_366 == 0 ) {
F_4 ( V_2 -> V_29 , L_24 ) ;
V_5 -> V_385 = 0 ;
V_5 -> V_386 = 0 ;
F_6 ( V_2 , V_133 ,
V_387 , 0 ) ;
return 0 ;
}
V_52 = F_41 ( & V_364 , V_365 , V_366 ) ;
if ( V_52 != 0 )
return V_52 ;
switch ( V_383 ) {
case V_388 :
V_83 = 0 ;
break;
case V_389 :
V_83 = 1 ;
break;
case V_390 :
V_83 = 2 ;
break;
case V_391 :
V_83 = 3 ;
break;
default:
F_20 ( V_2 -> V_29 , L_25 , V_52 ) ;
return - V_32 ;
}
V_83 |= V_364 . V_370 << V_392 ;
V_83 |= V_364 . V_372 << V_393 ;
F_6 ( V_2 , V_137 ,
V_394 | V_395 |
V_396 , V_83 ) ;
V_83 = 0 ;
if ( V_364 . V_380 || V_364 . V_381 )
V_83 |= V_397 | ( 3 << V_398 ) ;
else
V_83 |= 1 << V_398 ;
F_17 ( V_2 , V_140 , V_83 ) ;
F_6 ( V_2 , V_134 ,
V_399 |
V_400 ,
( V_364 . V_373 << V_401 ) |
( V_364 . V_377 ) ) ;
F_17 ( V_2 , V_135 , V_364 . V_380 ) ;
F_6 ( V_2 , V_136 ,
V_402 | V_403 ,
( V_364 . V_379 << V_404 ) |
V_364 . V_371 ) ;
F_17 ( V_2 , V_139 , V_364 . V_381 ) ;
F_46 ( & V_5 -> V_405 ) ;
F_6 ( V_2 , V_133 ,
V_387 , V_387 ) ;
F_17 ( V_2 , V_138 , V_406 ) ;
if ( V_365 > 1000000 )
V_53 = F_47 ( 300 ) ;
else
V_53 = F_19 ( 2 ) ;
if ( V_51 -> V_55 )
V_53 *= 1000 ;
V_52 = F_18 ( & V_5 -> V_405 , V_53 ) ;
if ( V_52 == 0 && V_51 -> V_55 ) {
F_20 ( V_2 -> V_29 , L_26 ) ;
V_52 = - V_407 ;
} else {
V_52 = 0 ;
}
F_4 ( V_2 -> V_29 , L_27 , V_365 , V_366 ) ;
V_5 -> V_385 = V_365 ;
V_5 -> V_386 = V_366 ;
V_5 -> V_384 = V_383 ;
return V_52 ;
}
static inline struct V_4 * F_48 ( struct V_408 * V_409 )
{
return F_22 ( V_409 , struct V_4 , V_408 ) ;
}
static void F_49 ( struct V_408 * V_409 , unsigned V_410 , int V_38 )
{
struct V_4 * V_5 = F_48 ( V_409 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
F_6 ( V_2 , V_255 + V_410 ,
V_411 , ! ! V_38 << V_412 ) ;
}
static int F_50 ( struct V_408 * V_409 ,
unsigned V_410 , int V_38 )
{
struct V_4 * V_5 = F_48 ( V_409 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
int V_61 ;
V_61 = ( 1 << V_413 ) | ( ! ! V_38 << V_412 ) ;
return F_6 ( V_2 , V_255 + V_410 ,
V_336 | V_414 |
V_411 , V_61 ) ;
}
static int F_51 ( struct V_408 * V_409 , unsigned V_410 )
{
struct V_4 * V_5 = F_48 ( V_409 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
int V_52 ;
V_52 = F_3 ( V_2 , V_255 + V_410 ) ;
if ( V_52 < 0 )
return V_52 ;
return ( V_52 & V_411 ) != 0 ;
}
static int F_52 ( struct V_408 * V_409 , unsigned V_410 )
{
struct V_4 * V_5 = F_48 ( V_409 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
return F_6 ( V_2 , V_255 + V_410 ,
V_336 | V_414 ,
( 1 << V_413 ) |
( 1 << V_415 ) ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_52 ;
V_5 -> V_408 = V_416 ;
V_5 -> V_408 . V_417 = 5 ;
V_5 -> V_408 . V_29 = V_2 -> V_29 ;
if ( V_5 -> V_7 . V_418 )
V_5 -> V_408 . V_8 = V_5 -> V_7 . V_418 ;
else
V_5 -> V_408 . V_8 = - 1 ;
V_52 = F_54 ( & V_5 -> V_408 ) ;
if ( V_52 != 0 )
F_20 ( V_2 -> V_29 , L_28 , V_52 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_52 ;
V_52 = F_56 ( & V_5 -> V_408 ) ;
if ( V_52 != 0 )
F_20 ( V_2 -> V_29 , L_29 , V_52 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
}
static void F_55 ( struct V_1 * V_2 )
{
}
int F_57 ( struct V_1 * V_2 , struct V_419 * V_420 ,
T_2 V_421 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_420 = V_420 ;
V_5 -> V_422 = true ;
V_5 -> V_421 = V_421 ;
if ( V_5 -> V_421 )
V_5 -> V_421 ( V_2 , 0 ) ;
F_6 ( V_2 , V_105 ,
V_423 , 0 ) ;
F_6 ( V_2 , V_106 ,
V_424 , 0 ) ;
F_58 ( & V_2 -> V_58 , L_30 ) ;
F_58 ( & V_2 -> V_58 , L_31 ) ;
F_6 ( V_2 , V_113 ,
V_425 , V_425 ) ;
F_6 ( V_2 , V_113 ,
V_426 ,
V_426 ) ;
F_6 ( V_2 , V_266 ,
V_427 , 0 ) ;
return 0 ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_61 , V_83 ;
V_61 = F_3 ( V_2 , V_115 ) ;
F_4 ( V_2 -> V_29 , L_32 , V_61 ) ;
if ( ! ( V_61 & V_428 ) ) {
F_40 ( V_2 -> V_29 , L_33 ) ;
return;
}
if ( ! ( V_61 & V_429 ) ) {
F_4 ( V_2 -> V_29 , L_34 ) ;
V_5 -> V_430 = false ;
V_5 -> V_422 = true ;
F_60 ( V_5 -> V_420 , 0 ,
V_431 | V_432 ) ;
F_6 ( V_2 , V_113 ,
V_426 ,
V_426 ) ;
return;
}
if ( V_61 & 0x400 ) {
F_4 ( V_2 -> V_29 , L_35 ) ;
F_60 ( V_5 -> V_420 , V_431 ,
V_431 | V_432 ) ;
V_5 -> V_430 = true ;
V_5 -> V_422 = false ;
F_6 ( V_2 , V_113 ,
V_426 ,
5 << V_433 ) ;
}
if ( V_5 -> V_422 && ( V_61 & 0x3f0 ) ) {
V_83 = F_3 ( V_2 , V_110 ) ;
V_83 ^= V_434 | V_435 |
V_436 ;
F_6 ( V_2 , V_110 ,
V_434 | V_435 |
V_436 , V_83 ) ;
if ( V_5 -> V_421 )
V_5 -> V_421 ( V_2 ,
( V_83 & V_435 ) != 0 ) ;
F_4 ( V_2 -> V_29 , L_36 ,
( V_83 & V_435 ) != 0 ) ;
return;
}
if ( V_61 & 0x3fc ) {
if ( V_5 -> V_430 ) {
F_4 ( V_2 -> V_29 , L_37 ) ;
F_60 ( V_5 -> V_420 ,
V_431 | V_432 ,
V_431 | V_432 ) ;
} else {
F_4 ( V_2 -> V_29 , L_38 ) ;
F_60 ( V_5 -> V_420 ,
V_437 ,
V_431 |
V_432 ) ;
F_6 ( V_2 , V_113 ,
V_426 ,
7 << V_433 ) ;
V_5 -> V_422 = false ;
}
}
}
static T_3 F_61 ( int V_55 , void * V_438 )
{
struct V_1 * V_2 = V_438 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_439 ;
V_439 = F_3 ( V_2 , V_263 ) ;
if ( V_439 < 0 ) {
F_20 ( V_2 -> V_29 , L_39 ,
V_439 ) ;
return V_440 ;
}
V_439 &= ~ F_3 ( V_2 , V_266 ) ;
F_17 ( V_2 , V_263 , V_439 ) ;
if ( V_439 & ( V_441 | V_442 ) ) {
F_4 ( V_2 -> V_29 , L_40 ) ;
F_62 ( & V_5 -> V_56 ) ;
}
if ( V_439 & V_443 )
F_20 ( V_2 -> V_29 , L_41 ) ;
if ( V_439 & V_444 ) {
F_4 ( V_2 -> V_29 , L_42 ) ;
F_62 ( & V_5 -> V_405 ) ;
}
if ( V_439 & V_445 )
F_59 ( V_2 ) ;
if ( V_439 )
return V_446 ;
else
return V_440 ;
}
static T_3 F_63 ( int V_55 , void * V_438 )
{
T_3 V_52 = V_440 ;
T_3 V_61 ;
do {
V_61 = F_61 ( V_55 , V_438 ) ;
if ( V_61 != V_440 )
V_52 = V_61 ;
} while ( V_61 != V_440 );
return V_52 ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_447 V_448 [] = {
F_65 ( L_2 ,
V_5 -> V_449 ,
F_10 ,
F_8 ) ,
F_65 ( L_3 ,
V_5 -> V_449 ,
F_10 ,
F_8 ) ,
} ;
int V_52 , V_12 , V_450 ;
const char * * V_451 ;
V_5 -> V_15 = 0 ;
V_5 -> V_26 = NULL ;
for ( V_12 = 0 ; V_12 < V_7 -> V_23 ; V_12 ++ ) {
for ( V_450 = 0 ; V_450 < V_5 -> V_15 ; V_450 ++ ) {
if ( strcmp ( V_7 -> V_24 [ V_12 ] . V_25 ,
V_5 -> V_26 [ V_450 ] ) == 0 )
break;
}
if ( V_450 != V_5 -> V_15 )
continue;
V_451 = F_66 ( V_5 -> V_26 ,
sizeof( char * ) *
( V_5 -> V_15 + 1 ) ,
V_452 ) ;
if ( V_451 == NULL )
continue;
V_451 [ V_5 -> V_15 ] =
V_7 -> V_24 [ V_12 ] . V_25 ;
V_5 -> V_15 ++ ;
V_5 -> V_26 = V_451 ;
}
F_4 ( V_2 -> V_29 , L_43 ,
V_5 -> V_15 ) ;
V_5 -> V_449 . V_376 = V_5 -> V_15 ;
V_5 -> V_449 . V_453 = V_5 -> V_26 ;
V_52 = F_67 ( V_2 , V_448 , F_5 ( V_448 ) ) ;
if ( V_52 != 0 )
F_20 ( V_2 -> V_29 ,
L_44 , V_52 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_52 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_50 * V_51 = F_16 ( V_2 -> V_29 ) ;
struct V_57 * V_58 = & V_2 -> V_58 ;
int V_12 , V_454 ;
V_5 -> V_2 = V_2 ;
F_69 ( & V_5 -> V_56 ) ;
F_69 ( & V_5 -> V_405 ) ;
V_58 -> V_455 = true ;
V_58 -> V_284 = V_287 ;
V_52 = F_70 ( V_2 , 16 , 16 , V_456 ) ;
if ( V_52 != 0 ) {
F_20 ( V_2 -> V_29 , L_45 , V_52 ) ;
goto V_457;
}
for ( V_12 = 0 ; V_12 < F_5 ( V_5 -> V_288 ) ; V_12 ++ )
V_5 -> V_288 [ V_12 ] . V_458 = V_459 [ V_12 ] ;
V_52 = F_71 ( V_2 -> V_29 , F_5 ( V_5 -> V_288 ) ,
V_5 -> V_288 ) ;
if ( V_52 != 0 ) {
F_20 ( V_2 -> V_29 , L_46 , V_52 ) ;
goto V_457;
}
V_5 -> V_460 [ 0 ] . V_461 = V_462 ;
V_5 -> V_460 [ 1 ] . V_461 = V_463 ;
V_5 -> V_460 [ 2 ] . V_461 = V_464 ;
V_5 -> V_460 [ 3 ] . V_461 = V_465 ;
for ( V_12 = 0 ; V_12 < F_5 ( V_5 -> V_288 ) ; V_12 ++ ) {
V_52 = F_72 ( V_5 -> V_288 [ V_12 ] . V_466 ,
& V_5 -> V_460 [ V_12 ] ) ;
if ( V_52 != 0 ) {
F_20 ( V_2 -> V_29 ,
L_47 ,
V_52 ) ;
}
}
V_52 = F_29 ( F_5 ( V_5 -> V_288 ) ,
V_5 -> V_288 ) ;
if ( V_52 != 0 ) {
F_20 ( V_2 -> V_29 , L_11 , V_52 ) ;
goto V_467;
}
if ( V_5 -> V_7 . V_289 >= 0 ) {
F_30 ( V_5 -> V_7 . V_289 , 1 ) ;
F_12 ( 5 ) ;
}
V_52 = F_3 ( V_2 , V_84 ) ;
if ( V_52 < 0 ) {
F_20 ( V_2 -> V_29 , L_48 , V_52 ) ;
goto V_468;
}
if ( V_52 != 0x8915 ) {
F_20 ( V_2 -> V_29 , L_49 , V_52 ) ;
V_52 = - V_32 ;
goto V_468;
}
V_52 = F_3 ( V_2 , V_124 ) ;
if ( V_52 < 0 ) {
F_20 ( V_2 -> V_29 , L_50 ,
V_52 ) ;
goto V_468;
}
F_73 ( V_2 -> V_29 , L_51 ,
( V_52 & V_469 ) + 'A' ) ;
if ( V_5 -> V_7 . V_289 >= 0 ) {
F_30 ( V_5 -> V_7 . V_289 , 0 ) ;
} else {
V_52 = F_26 ( V_2 ) ;
if ( V_52 < 0 ) {
F_20 ( V_2 -> V_29 , L_52 ) ;
goto V_468;
}
}
V_2 -> V_290 = true ;
F_6 ( V_2 , V_94 ,
V_470 | V_471 ,
V_5 -> V_7 . V_472 << V_473 |
V_5 -> V_7 . V_474 ) ;
for ( V_12 = 0 ; V_12 < F_5 ( V_5 -> V_7 . V_475 ) ; V_12 ++ ) {
if ( ! V_5 -> V_7 . V_475 [ V_12 ] )
continue;
F_17 ( V_2 , V_255 + V_12 ,
V_5 -> V_7 . V_475 [ V_12 ] & 0xffff ) ;
}
if ( V_5 -> V_7 . V_476 )
F_6 ( V_2 , V_270 ,
V_477 |
V_478 ,
V_5 -> V_7 . V_476 ) ;
F_6 ( V_2 , V_110 ,
V_436 | V_434 |
V_435 , V_5 -> V_7 . V_479 ) ;
F_6 ( V_2 , V_92 ,
V_480 , V_480 ) ;
F_6 ( V_2 , V_93 ,
V_480 , V_480 ) ;
F_6 ( V_2 , V_97 ,
V_481 , V_481 ) ;
F_6 ( V_2 , V_98 ,
V_481 , V_481 ) ;
F_6 ( V_2 , V_99 ,
V_482 , V_482 ) ;
F_6 ( V_2 , V_100 ,
V_482 , V_482 ) ;
F_6 ( V_2 , V_101 ,
V_481 , V_481 ) ;
F_6 ( V_2 , V_102 ,
V_481 , V_481 ) ;
F_6 ( V_2 , V_103 ,
V_482 , V_482 ) ;
F_6 ( V_2 , V_104 ,
V_482 , V_482 ) ;
F_6 ( V_2 , V_179 ,
V_483 , V_483 ) ;
F_6 ( V_2 , V_180 ,
V_483 , V_483 ) ;
F_6 ( V_2 , V_209 ,
V_484 , V_484 ) ;
F_6 ( V_2 , V_210 ,
V_484 , V_484 ) ;
F_6 ( V_2 , V_181 ,
V_485 , V_485 ) ;
F_6 ( V_2 , V_182 ,
V_485 , V_485 ) ;
F_6 ( V_2 , V_211 ,
V_486 , V_486 ) ;
F_6 ( V_2 , V_212 ,
V_486 , V_486 ) ;
F_6 ( V_2 , V_156 ,
V_487 |
V_488 ,
1 << V_489 | 0 ) ;
F_6 ( V_2 , V_157 ,
V_490 |
V_491 ,
1 << V_492 | 1 ) ;
F_6 ( V_2 , V_158 ,
V_493 |
V_494 ,
1 << V_495 | 0 ) ;
F_6 ( V_2 , V_159 ,
V_496 |
V_488 ,
1 << V_497 | 1 ) ;
F_6 ( V_2 , V_160 ,
V_498 |
V_488 ,
1 << V_499 | 0 ) ;
F_6 ( V_2 , V_161 ,
V_500 |
V_488 ,
1 << V_501 | 1 ) ;
F_6 ( V_2 , V_175 ,
V_502 |
V_503 ,
1 << V_504 | 0 ) ;
F_6 ( V_2 , V_176 ,
V_505 |
V_506 ,
1 << V_507 | 1 ) ;
F_6 ( V_2 , V_150 ,
V_508 |
V_509 ,
1 << V_510 | 0 ) ;
F_6 ( V_2 , V_151 ,
V_511 |
V_509 ,
1 << V_512 | 1 ) ;
F_6 ( V_2 , V_152 ,
V_513 |
V_509 ,
1 << V_514 | 0 ) ;
F_6 ( V_2 , V_153 ,
V_515 |
V_509 ,
1 << V_516 | 1 ) ;
F_6 ( V_2 , V_154 ,
V_517 |
V_509 ,
1 << V_518 | 0 ) ;
F_6 ( V_2 , V_155 ,
V_519 |
V_509 ,
1 << V_520 | 1 ) ;
F_6 ( V_2 , V_173 ,
V_521 |
V_522 ,
1 << V_523 | 0 ) ;
F_6 ( V_2 , V_151 ,
V_524 |
V_525 ,
1 << V_512 | 1 ) ;
if ( V_5 -> V_7 . V_23 )
F_64 ( V_2 ) ;
else
F_67 ( V_2 , V_526 ,
F_5 ( V_526 ) ) ;
if ( ( F_3 ( V_2 , V_255 ) ) )
F_6 ( V_2 , V_144 ,
V_527 ,
V_527 ) ;
if ( ( F_3 ( V_2 , V_256 ) ) )
F_6 ( V_2 , V_167 ,
V_528 ,
V_528 ) ;
F_32 ( F_5 ( V_5 -> V_288 ) , V_5 -> V_288 ) ;
F_53 ( V_2 ) ;
if ( V_51 -> V_55 ) {
if ( V_5 -> V_7 . V_454 )
V_454 = V_5 -> V_7 . V_454 ;
else
V_454 = V_529 ;
V_454 |= V_530 ;
if ( V_454 & ( V_531 | V_532 ) )
V_52 = F_74 ( V_51 -> V_55 , NULL ,
F_63 ,
V_454 , L_53 , V_2 ) ;
else
V_52 = F_74 ( V_51 -> V_55 , NULL , F_61 ,
V_454 , L_53 , V_2 ) ;
if ( V_52 == 0 ) {
F_6 ( V_2 , V_267 ,
V_533 , 0 ) ;
F_6 ( V_2 ,
V_266 ,
V_534 |
V_535 |
V_536 |
V_537 ,
0 ) ;
} else {
F_20 ( V_2 -> V_29 , L_54 ,
V_52 ) ;
}
}
return 0 ;
V_468:
if ( V_5 -> V_7 . V_289 >= 0 )
F_30 ( V_5 -> V_7 . V_289 , 0 ) ;
F_32 ( F_5 ( V_5 -> V_288 ) , V_5 -> V_288 ) ;
V_467:
F_75 ( F_5 ( V_5 -> V_288 ) , V_5 -> V_288 ) ;
V_457:
return V_52 ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_50 * V_51 = F_16 ( V_2 -> V_29 ) ;
int V_12 ;
F_6 ( V_2 , V_267 ,
V_533 , V_533 ) ;
if ( V_51 -> V_55 )
F_77 ( V_51 -> V_55 , V_2 ) ;
F_55 ( V_2 ) ;
for ( V_12 = 0 ; V_12 < F_5 ( V_5 -> V_288 ) ; V_12 ++ )
F_78 ( V_5 -> V_288 [ V_12 ] . V_466 ,
& V_5 -> V_460 [ V_12 ] ) ;
F_75 ( F_5 ( V_5 -> V_288 ) , V_5 -> V_288 ) ;
return 0 ;
}
static T_4 int F_79 ( struct V_50 * V_51 ,
const struct V_538 * V_37 )
{
struct V_4 * V_5 ;
int V_52 ;
V_5 = F_80 ( sizeof( struct V_4 ) , V_452 ) ;
if ( V_5 == NULL )
return - V_539 ;
F_81 ( V_51 , V_5 ) ;
if ( F_82 ( & V_51 -> V_29 ) )
memcpy ( & V_5 -> V_7 , F_82 ( & V_51 -> V_29 ) ,
sizeof( V_5 -> V_7 ) ) ;
if ( V_5 -> V_7 . V_289 > 0 ) {
V_52 = F_83 ( V_5 -> V_7 . V_289 ,
V_540 , L_55 ) ;
if ( V_52 < 0 ) {
F_20 ( & V_51 -> V_29 , L_56 ,
V_5 -> V_7 . V_289 , V_52 ) ;
goto V_457;
}
}
V_52 = F_84 ( & V_51 -> V_29 ,
& V_541 , V_542 ,
F_5 ( V_542 ) ) ;
if ( V_52 < 0 )
goto V_543;
return V_52 ;
V_543:
if ( V_5 -> V_7 . V_289 > 0 )
F_85 ( V_5 -> V_7 . V_289 ) ;
V_457:
F_86 ( V_5 ) ;
return V_52 ;
}
static T_5 int F_87 ( struct V_50 * V_544 )
{
struct V_4 * V_5 = F_88 ( V_544 ) ;
F_89 ( & V_544 -> V_29 ) ;
if ( V_5 -> V_7 . V_289 > 0 )
F_85 ( V_5 -> V_7 . V_289 ) ;
F_86 ( F_88 ( V_544 ) ) ;
return 0 ;
}
static int T_6 F_90 ( void )
{
int V_52 ;
V_52 = F_91 ( & V_545 ) ;
if ( V_52 != 0 ) {
F_92 ( V_546 L_57 ,
V_52 ) ;
}
return V_52 ;
}
static void T_7 F_93 ( void )
{
F_94 ( & V_545 ) ;
}
