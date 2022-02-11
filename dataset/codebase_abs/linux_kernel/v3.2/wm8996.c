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
static void F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_41 ++ ;
if ( V_5 -> V_41 == 1 ) {
F_6 ( V_2 , V_42 ,
V_43 , V_43 ) ;
F_12 ( 2 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_41 -- ;
if ( ! V_5 -> V_41 )
F_6 ( V_2 , V_42 ,
V_43 , 0 ) ;
}
static int F_14 ( struct V_44 * V_45 ,
struct V_33 * V_34 , int V_46 )
{
struct V_1 * V_2 = V_45 -> V_2 ;
int V_47 = 0 ;
switch ( V_46 ) {
case V_48 :
F_11 ( V_2 ) ;
break;
case V_49 :
F_13 ( V_2 ) ;
break;
default:
F_15 () ;
V_47 = - V_32 ;
}
return V_47 ;
}
static int F_16 ( struct V_44 * V_45 ,
struct V_33 * V_34 , int V_46 )
{
struct V_1 * V_2 = V_45 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_47 = 0 ;
switch ( V_46 ) {
case V_48 :
V_47 = F_17 ( V_5 -> V_50 ) ;
if ( V_47 != 0 )
F_18 ( V_2 -> V_29 , L_4 ,
V_47 ) ;
break;
case V_51 :
F_12 ( 5 ) ;
break;
case V_49 :
F_19 ( V_5 -> V_50 , 20 ) ;
break;
default:
F_15 () ;
V_47 = - V_32 ;
}
return V_47 ;
}
static int F_20 ( struct V_44 * V_45 ,
struct V_33 * V_34 , int V_46 )
{
struct V_4 * V_5 = F_2 ( V_45 -> V_2 ) ;
switch ( V_46 ) {
case V_52 :
V_5 -> V_53 &= ~ V_45 -> V_54 ;
break;
case V_48 :
V_5 -> V_53 |= V_45 -> V_54 ;
break;
default:
F_15 () ;
return - V_32 ;
}
return 0 ;
}
static void F_21 ( struct V_1 * V_2 , T_1 V_55 )
{
struct V_56 * V_57 = F_22 ( V_2 -> V_29 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_47 ;
unsigned long V_58 = 200 ;
F_23 ( V_2 , V_59 , V_55 ) ;
do {
if ( V_57 -> V_60 ) {
V_58 = F_24 ( & V_5 -> V_61 ,
F_25 ( 200 ) ) ;
if ( V_58 == 0 )
F_18 ( V_2 -> V_29 , L_5 ) ;
} else {
F_12 ( 1 ) ;
V_58 -- ;
}
V_47 = F_3 ( V_2 , V_59 ) ;
F_4 ( V_2 -> V_29 , L_6 , V_47 ) ;
} while ( V_58 && V_47 & V_55 );
if ( V_58 == 0 )
F_18 ( V_2 -> V_29 , L_7 , V_55 ) ;
else
F_4 ( V_2 -> V_29 , L_8 , V_55 ) ;
}
static void F_26 ( struct V_62 * V_63 ,
enum V_64 V_46 , int V_65 )
{
struct V_1 * V_2 = F_27 ( V_63 ,
struct V_1 , V_63 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_66 , V_55 ;
if ( V_5 -> V_67 ) {
F_4 ( V_2 -> V_29 , L_9 ,
V_5 -> V_67 ) ;
F_21 ( V_2 , V_5 -> V_67
<< V_68 ) ;
V_5 -> V_67 = 0 ;
}
if ( V_5 -> V_53 != V_5 -> V_69 ) {
F_4 ( V_2 -> V_29 , L_10 ,
V_5 -> V_69 , V_5 -> V_53 ) ;
V_66 = 0 ;
V_55 = 0 ;
if ( V_5 -> V_53 & V_70 ) {
V_66 |= V_71 ;
V_55 |= V_71 ;
} else {
V_55 |= V_71 |
V_72 |
V_73 ;
}
if ( V_5 -> V_53 & V_74 ) {
V_66 |= V_75 ;
V_55 |= V_75 ;
} else {
V_55 |= V_75 |
V_76 |
V_77 ;
}
F_6 ( V_2 , V_78 , V_55 , V_66 ) ;
V_66 = 0 ;
V_55 = 0 ;
if ( V_5 -> V_53 & V_79 ) {
V_66 |= V_80 ;
V_55 |= V_80 ;
} else {
V_55 |= V_80 |
V_81 |
V_82 ;
}
if ( V_5 -> V_53 & V_83 ) {
V_66 |= V_84 ;
V_55 |= V_84 ;
} else {
V_55 |= V_84 |
V_85 |
V_86 ;
}
F_6 ( V_2 , V_87 , V_55 , V_66 ) ;
V_5 -> V_69 = V_5 -> V_53 ;
}
}
static int F_28 ( struct V_44 * V_45 ,
struct V_33 * V_34 , int V_46 )
{
struct V_4 * V_5 = F_2 ( V_45 -> V_2 ) ;
switch ( V_46 ) {
case V_51 :
V_5 -> V_67 |= 1 << V_45 -> V_54 ;
break;
default:
F_15 () ;
return - V_32 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
unsigned int V_88 )
{
switch ( V_88 ) {
case V_89 :
case V_42 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_17 :
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
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_59 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_78 :
case V_87 :
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
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_16 :
case V_19 :
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
case V_272 :
case V_273 :
case V_274 :
case V_275 :
return 1 ;
default:
return 0 ;
}
}
static int F_30 ( struct V_1 * V_2 ,
unsigned int V_88 )
{
switch ( V_88 ) {
case V_89 :
case V_128 :
case V_111 :
case V_112 :
case V_266 :
case V_267 :
case V_268 :
case V_127 :
case V_59 :
case V_125 :
case V_126 :
case V_142 :
case V_119 :
case V_115 :
case V_116 :
return 1 ;
default:
return 0 ;
}
}
static int F_31 ( struct V_1 * V_2 )
{
return F_23 ( V_2 , V_89 , 0x8915 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_276 , V_9 , V_277 , V_278 , V_279 , V_12 ;
if ( V_5 -> V_280 < 64000 )
return;
for ( V_276 = 0 ; V_276 < V_281 ; V_276 ++ ) {
switch ( V_276 ) {
case 0 :
V_279 = V_146 ;
break;
case 1 :
V_279 = V_169 ;
break;
}
V_278 = V_5 -> V_278 [ V_276 ] ;
V_9 = 0 ;
for ( V_12 = 0 ; V_12 < F_5 ( V_282 ) ; V_12 ++ ) {
V_277 = ( V_5 -> V_280 / V_282 [ V_12 ] ) - V_278 ;
if ( V_277 < 0 )
break;
V_9 = V_12 ;
}
V_278 = V_5 -> V_280 / V_282 [ V_9 ] ;
F_4 ( V_2 -> V_29 , L_11 ,
V_282 [ V_9 ] , V_278 ) ;
F_6 ( V_2 , V_279 ,
V_283 , V_9 ) ;
}
}
static int F_33 ( struct V_1 * V_2 ,
enum V_284 V_285 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_47 ;
switch ( V_285 ) {
case V_286 :
case V_287 :
break;
case V_288 :
if ( V_2 -> V_63 . V_289 == V_290 ) {
V_47 = F_34 ( F_5 ( V_5 -> V_291 ) ,
V_5 -> V_291 ) ;
if ( V_47 != 0 ) {
F_18 ( V_2 -> V_29 ,
L_12 ,
V_47 ) ;
return V_47 ;
}
if ( V_5 -> V_7 . V_292 >= 0 ) {
F_35 ( V_5 -> V_7 . V_292 ,
1 ) ;
F_12 ( 5 ) ;
}
V_2 -> V_293 = false ;
F_36 ( V_2 ) ;
}
break;
case V_290 :
V_2 -> V_293 = true ;
if ( V_5 -> V_7 . V_292 >= 0 )
F_35 ( V_5 -> V_7 . V_292 , 0 ) ;
F_37 ( F_5 ( V_5 -> V_291 ) ,
V_5 -> V_291 ) ;
break;
}
V_2 -> V_63 . V_289 = V_285 ;
return 0 ;
}
static int F_38 ( struct V_294 * V_295 , unsigned int V_296 )
{
struct V_1 * V_2 = V_295 -> V_2 ;
int V_297 = 0 ;
int V_298 = 0 ;
int V_299 = 0 ;
int V_300 = 0 ;
int V_301 , V_279 , V_302 , V_303 ;
switch ( V_295 -> V_37 ) {
case 0 :
V_301 = V_145 ;
V_279 = V_146 ;
V_302 = V_148 ;
V_303 = V_150 ;
break;
case 1 :
V_301 = V_168 ;
V_279 = V_169 ;
V_302 = V_171 ;
V_303 = V_173 ;
break;
default:
F_15 () ;
return - V_32 ;
}
switch ( V_296 & V_304 ) {
case V_305 :
break;
case V_306 :
V_298 |= V_307 ;
break;
case V_308 :
V_299 |= V_309 ;
V_300 |= V_310 ;
break;
case V_311 :
V_298 |= V_307 ;
V_299 |= V_309 ;
V_300 |= V_310 ;
break;
}
switch ( V_296 & V_312 ) {
case V_313 :
break;
case V_314 :
V_299 |= V_315 ;
V_300 |= V_316 ;
break;
case V_317 :
V_298 |= V_318 ;
break;
case V_319 :
V_298 |= V_318 ;
V_299 |= V_315 ;
V_300 |= V_316 ;
break;
default:
return - V_32 ;
}
switch ( V_296 & V_320 ) {
case V_321 :
break;
case V_322 :
V_297 |= 1 ;
break;
case V_323 :
V_297 |= 2 ;
break;
case V_324 :
V_297 |= 3 ;
break;
default:
return - V_32 ;
}
F_6 ( V_2 , V_301 , V_325 , V_297 ) ;
F_6 ( V_2 , V_279 ,
V_307 | V_318 ,
V_298 ) ;
F_6 ( V_2 , V_302 ,
V_309 |
V_315 ,
V_299 ) ;
F_6 ( V_2 , V_303 ,
V_310 |
V_316 ,
V_300 ) ;
return 0 ;
}
static int F_39 ( struct V_326 * V_327 ,
struct V_328 * V_329 ,
struct V_294 * V_295 )
{
struct V_1 * V_2 = V_295 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_330 , V_12 , V_278 ;
int V_331 = 0 ;
int V_332 = 0 ;
int V_333 = 0 ;
int V_334 , V_335 , V_336 ;
switch ( V_295 -> V_37 ) {
case 0 :
if ( V_327 -> V_337 == V_338 ||
( F_3 ( V_2 , V_259 ) ) & V_339 ) {
V_334 = V_153 ;
V_335 = V_149 ;
} else {
V_334 = V_151 ;
V_335 = V_147 ;
}
V_336 = 0 ;
break;
case 1 :
if ( V_327 -> V_337 == V_338 ||
( F_3 ( V_2 , V_260 ) ) & V_340 ) {
V_334 = V_176 ;
V_335 = V_172 ;
} else {
V_334 = V_174 ;
V_335 = V_170 ;
}
V_336 = V_341 ;
break;
default:
F_15 () ;
return - V_32 ;
}
V_278 = F_40 ( V_329 ) ;
if ( V_278 < 0 ) {
F_18 ( V_2 -> V_29 , L_13 , V_278 ) ;
return V_278 ;
}
V_5 -> V_278 [ V_295 -> V_37 ] = V_278 ;
V_5 -> V_28 [ V_295 -> V_37 ] = F_41 ( V_329 ) ;
V_330 = F_42 ( F_43 ( V_329 ) ) ;
if ( V_330 < 0 )
return V_330 ;
V_331 |= ( V_330 << V_342 ) | V_330 ;
for ( V_12 = 0 ; V_12 < F_5 ( V_343 ) ; V_12 ++ ) {
if ( V_343 [ V_12 ] == F_41 ( V_329 ) )
break;
}
if ( V_12 == F_5 ( V_343 ) ) {
F_18 ( V_2 -> V_29 , L_14 ,
F_41 ( V_329 ) ) ;
return - V_32 ;
}
V_333 |= V_12 << V_336 ;
F_32 ( V_2 ) ;
V_332 = V_278 / F_41 ( V_329 ) ;
F_4 ( V_295 -> V_29 , L_15 ,
V_332 , V_278 / V_332 ) ;
F_6 ( V_2 , V_334 ,
V_344 |
V_345 ,
V_331 ) ;
F_6 ( V_2 , V_335 , V_346 ,
V_332 ) ;
F_6 ( V_2 , V_133 ,
V_347 << V_336 , V_333 ) ;
return 0 ;
}
static int F_44 ( struct V_294 * V_295 ,
int V_348 , unsigned int V_349 , int V_350 )
{
struct V_1 * V_2 = V_295 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_351 = 0 ;
int V_352 = 0 ;
int V_353 ;
int V_354 ;
if ( V_349 == V_5 -> V_280 && V_348 == V_5 -> V_355 )
return 0 ;
V_354 = F_3 ( V_2 , V_132 ) & V_356 ;
F_6 ( V_2 , V_132 ,
V_356 , 0 ) ;
switch ( V_348 ) {
case V_357 :
V_5 -> V_280 = V_349 ;
V_353 = 0 ;
break;
case V_358 :
V_5 -> V_280 = V_349 ;
V_353 = 1 ;
break;
case V_359 :
V_5 -> V_280 = V_349 ;
V_353 = 2 ;
break;
default:
F_18 ( V_2 -> V_29 , L_16 , V_348 ) ;
return - V_32 ;
}
switch ( V_5 -> V_280 ) {
case 6144000 :
F_6 ( V_2 , V_136 ,
V_360 , 0 ) ;
break;
case 24576000 :
V_352 = V_361 ;
V_5 -> V_280 /= 2 ;
case 12288000 :
F_6 ( V_2 , V_136 ,
V_360 , V_360 ) ;
break;
case 32000 :
case 32768 :
V_351 = V_362 ;
break;
default:
F_45 ( V_2 -> V_29 , L_17 ,
V_5 -> V_280 ) ;
return - V_32 ;
}
F_32 ( V_2 ) ;
F_6 ( V_2 , V_132 ,
V_363 | V_364 ,
V_353 << V_365 | V_352 ) ;
F_6 ( V_2 , V_134 , V_362 , V_351 ) ;
F_6 ( V_2 , V_132 ,
V_356 , V_354 ) ;
V_5 -> V_355 = V_348 ;
return 0 ;
}
static int F_46 ( struct V_366 * V_367 , unsigned int V_368 ,
unsigned int V_369 )
{
unsigned int V_370 ;
unsigned int div ;
unsigned int V_371 , V_372 ;
int V_12 ;
div = 1 ;
V_367 -> V_373 = 0 ;
while ( ( V_368 / div ) > 13500000 ) {
div *= 2 ;
V_367 -> V_373 ++ ;
if ( div > 8 ) {
F_47 ( L_18 ,
V_368 ) ;
return - V_32 ;
}
}
F_48 ( L_19 , V_368 , V_369 ) ;
V_368 /= div ;
if ( V_368 >= 3000000 )
V_367 -> V_374 = 5 ;
else
V_367 -> V_374 = 0 ;
if ( V_368 >= 48000 )
V_367 -> V_375 = 0 ;
else
V_367 -> V_375 = 1 ;
div = 2 ;
while ( V_369 * div < 90000000 ) {
div ++ ;
if ( div > 64 ) {
F_47 ( L_20 ,
V_369 ) ;
return - V_32 ;
}
}
V_370 = V_369 * div ;
V_367 -> V_376 = div - 1 ;
F_48 ( L_21 , V_370 ) ;
for ( V_12 = 0 ; V_12 < F_5 ( V_377 ) ; V_12 ++ ) {
if ( V_377 [ V_12 ] . V_378 <= V_368 && V_368 <= V_377 [ V_12 ] . V_379 ) {
V_367 -> V_380 = V_377 [ V_12 ] . V_380 ;
V_371 = V_377 [ V_12 ] . V_381 ;
break;
}
}
if ( V_12 == F_5 ( V_377 ) ) {
F_47 ( L_22 , V_368 ) ;
return - V_32 ;
}
V_367 -> V_382 = V_370 / ( V_371 * V_368 ) ;
if ( V_370 % V_368 == 0 ) {
V_367 -> V_383 = 0 ;
V_367 -> V_384 = 0 ;
} else {
V_372 = F_49 ( V_370 , V_371 * V_368 ) ;
V_367 -> V_383 = ( V_370 - ( V_367 -> V_382 * V_371 * V_368 ) )
/ V_372 ;
V_367 -> V_384 = ( V_371 * V_368 ) / V_372 ;
}
F_48 ( L_23 ,
V_367 -> V_382 , V_367 -> V_383 , V_367 -> V_384 ) ;
F_48 ( L_24 ,
V_367 -> V_380 , V_367 -> V_376 ,
V_367 -> V_373 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , int V_385 , int V_386 ,
unsigned int V_368 , unsigned int V_369 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_56 * V_57 = F_22 ( V_2 -> V_29 ) ;
struct V_366 V_367 ;
unsigned long V_58 ;
int V_47 , V_88 , V_387 ;
if ( V_386 == V_5 -> V_388 && V_368 == V_5 -> V_389 &&
V_369 == V_5 -> V_390 )
return 0 ;
if ( V_369 == 0 ) {
F_4 ( V_2 -> V_29 , L_25 ) ;
V_5 -> V_389 = 0 ;
V_5 -> V_390 = 0 ;
F_6 ( V_2 , V_137 ,
V_391 , 0 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
V_47 = F_46 ( & V_367 , V_368 , V_369 ) ;
if ( V_47 != 0 )
return V_47 ;
switch ( V_386 ) {
case V_392 :
V_88 = 0 ;
break;
case V_393 :
V_88 = 1 ;
break;
case V_394 :
V_88 = 2 ;
break;
case V_395 :
V_88 = 3 ;
break;
default:
F_18 ( V_2 -> V_29 , L_26 , V_47 ) ;
return - V_32 ;
}
V_88 |= V_367 . V_373 << V_396 ;
V_88 |= V_367 . V_375 << V_397 ;
F_6 ( V_2 , V_141 ,
V_398 | V_399 |
V_400 , V_88 ) ;
V_88 = 0 ;
if ( V_367 . V_383 || V_367 . V_384 )
V_88 |= V_401 | ( 3 << V_402 ) ;
else
V_88 |= 1 << V_402 ;
F_23 ( V_2 , V_144 , V_88 ) ;
F_6 ( V_2 , V_138 ,
V_403 |
V_404 ,
( V_367 . V_376 << V_405 ) |
( V_367 . V_380 ) ) ;
F_23 ( V_2 , V_139 , V_367 . V_383 ) ;
F_6 ( V_2 , V_140 ,
V_406 | V_407 ,
( V_367 . V_382 << V_408 ) |
V_367 . V_374 ) ;
F_23 ( V_2 , V_143 , V_367 . V_384 ) ;
V_47 = F_3 ( V_2 , V_137 ) ;
if ( ! ( V_47 & V_391 ) )
F_11 ( V_2 ) ;
F_51 ( & V_5 -> V_409 ) ;
F_6 ( V_2 , V_137 ,
V_391 , V_391 ) ;
F_23 ( V_2 , V_142 , V_410 ) ;
if ( V_368 > 1000000 )
V_58 = F_52 ( 300 ) ;
else
V_58 = F_25 ( 2 ) ;
if ( V_57 -> V_60 )
V_58 *= 10 ;
else
V_58 /= 2 ;
for ( V_387 = 0 ; V_387 < 10 ; V_387 ++ ) {
V_47 = F_24 ( & V_5 -> V_409 ,
V_58 ) ;
if ( V_47 != 0 ) {
F_53 ( ! V_57 -> V_60 ) ;
break;
}
V_47 = F_3 ( V_2 , V_268 ) ;
if ( V_47 & V_411 )
break;
}
if ( V_387 == 10 ) {
F_18 ( V_2 -> V_29 , L_27 ) ;
V_47 = - V_412 ;
}
F_4 ( V_2 -> V_29 , L_28 , V_368 , V_369 ) ;
V_5 -> V_389 = V_368 ;
V_5 -> V_390 = V_369 ;
V_5 -> V_388 = V_386 ;
return V_47 ;
}
static inline struct V_4 * F_54 ( struct V_413 * V_414 )
{
return F_27 ( V_414 , struct V_4 , V_413 ) ;
}
static void F_55 ( struct V_413 * V_414 , unsigned V_415 , int V_38 )
{
struct V_4 * V_5 = F_54 ( V_414 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
F_6 ( V_2 , V_259 + V_415 ,
V_416 , ! ! V_38 << V_417 ) ;
}
static int F_56 ( struct V_413 * V_414 ,
unsigned V_415 , int V_38 )
{
struct V_4 * V_5 = F_54 ( V_414 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
int V_66 ;
V_66 = ( 1 << V_418 ) | ( ! ! V_38 << V_417 ) ;
return F_6 ( V_2 , V_259 + V_415 ,
V_339 | V_419 |
V_416 , V_66 ) ;
}
static int F_57 ( struct V_413 * V_414 , unsigned V_415 )
{
struct V_4 * V_5 = F_54 ( V_414 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
int V_47 ;
V_47 = F_3 ( V_2 , V_259 + V_415 ) ;
if ( V_47 < 0 )
return V_47 ;
return ( V_47 & V_416 ) != 0 ;
}
static int F_58 ( struct V_413 * V_414 , unsigned V_415 )
{
struct V_4 * V_5 = F_54 ( V_414 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
return F_6 ( V_2 , V_259 + V_415 ,
V_339 | V_419 ,
( 1 << V_418 ) |
( 1 << V_420 ) ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_47 ;
V_5 -> V_413 = V_421 ;
V_5 -> V_413 . V_422 = 5 ;
V_5 -> V_413 . V_29 = V_2 -> V_29 ;
if ( V_5 -> V_7 . V_423 )
V_5 -> V_413 . V_8 = V_5 -> V_7 . V_423 ;
else
V_5 -> V_413 . V_8 = - 1 ;
V_47 = F_60 ( & V_5 -> V_413 ) ;
if ( V_47 != 0 )
F_18 ( V_2 -> V_29 , L_29 , V_47 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_47 ;
V_47 = F_62 ( & V_5 -> V_413 ) ;
if ( V_47 != 0 )
F_18 ( V_2 -> V_29 , L_30 , V_47 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
}
static void F_61 ( struct V_1 * V_2 )
{
}
int F_63 ( struct V_1 * V_2 , struct V_424 * V_425 ,
T_2 V_426 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_425 = V_425 ;
V_5 -> V_427 = true ;
V_5 -> V_426 = V_426 ;
if ( V_5 -> V_426 )
V_5 -> V_426 ( V_2 , 0 ) ;
F_6 ( V_2 , V_109 ,
V_428 , 0 ) ;
F_6 ( V_2 , V_110 ,
V_429 , 0 ) ;
F_64 ( & V_2 -> V_63 , L_31 ) ;
F_64 ( & V_2 -> V_63 , L_32 ) ;
F_6 ( V_2 , V_117 ,
V_430 , V_430 ) ;
F_6 ( V_2 , V_117 ,
V_431 ,
V_431 ) ;
F_6 ( V_2 , V_270 ,
V_432 | V_433 , 0 ) ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_66 , V_88 , V_434 ;
V_434 = V_435 ;
V_88 = F_3 ( V_2 , V_116 ) ;
if ( V_88 < 0 ) {
F_18 ( V_2 -> V_29 , L_33 ) ;
goto V_436;
}
if ( ! ( V_88 & V_437 ) ) {
F_18 ( V_2 -> V_29 , L_34 ) ;
goto V_436;
}
V_66 = V_88 & V_438 ;
F_4 ( V_2 -> V_29 , L_35 , V_66 ) ;
if ( V_66 >= 126 )
V_434 = V_439 ;
else
V_434 = V_435 ;
V_436:
if ( V_5 -> V_440 )
V_434 |= V_441 ;
F_66 ( V_5 -> V_425 , V_434 ,
V_439 | V_442 ) ;
V_5 -> V_427 = false ;
if ( ! ( F_3 ( V_2 , V_42 ) &
( V_443 | V_75 ) ) )
F_6 ( V_2 , V_78 ,
V_71 |
V_75 , 0 ) ;
F_6 ( V_2 , V_113 ,
V_444 , 0 ) ;
F_6 ( V_2 , V_117 , V_430 ,
V_430 ) ;
F_67 ( & V_2 -> V_63 , L_36 ) ;
F_68 ( & V_2 -> V_63 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_78 ,
V_71 |
V_75 ,
V_71 |
V_75 ) ;
F_64 ( & V_2 -> V_63 , L_36 ) ;
F_68 ( & V_2 -> V_63 ) ;
F_6 ( V_2 , V_117 , V_430 , 0 ) ;
F_6 ( V_2 , V_113 ,
V_444 , 1 ) ;
F_6 ( V_2 , V_115 ,
V_445 , V_445 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_66 , V_88 ;
V_66 = F_3 ( V_2 , V_119 ) ;
F_4 ( V_2 -> V_29 , L_37 , V_66 ) ;
if ( ! ( V_66 & V_446 ) ) {
F_45 ( V_2 -> V_29 , L_38 ) ;
return;
}
if ( ! ( V_66 & V_447 ) ) {
F_4 ( V_2 -> V_29 , L_39 ) ;
V_5 -> V_440 = false ;
V_5 -> V_427 = true ;
F_66 ( V_5 -> V_425 , 0 ,
V_439 | V_442 |
V_448 ) ;
F_6 ( V_2 , V_117 ,
V_431 ,
V_431 ) ;
return;
}
if ( V_66 & 0x400 ) {
if ( V_5 -> V_427 ) {
F_4 ( V_2 -> V_29 , L_40 ) ;
V_5 -> V_440 = true ;
F_69 ( V_2 ) ;
F_6 ( V_2 , V_117 ,
V_431 ,
5 << V_449 ) ;
} else {
F_4 ( V_2 -> V_29 , L_41 ) ;
F_66 ( V_5 -> V_425 , 0 , V_448 ) ;
}
return;
}
if ( V_5 -> V_427 && ( V_66 & 0x3f0 ) ) {
V_88 = F_3 ( V_2 , V_114 ) ;
V_88 ^= V_450 | V_451 |
V_452 ;
F_6 ( V_2 , V_114 ,
V_450 | V_451 |
V_452 , V_88 ) ;
if ( V_5 -> V_426 )
V_5 -> V_426 ( V_2 ,
( V_88 & V_451 ) != 0 ) ;
F_4 ( V_2 -> V_29 , L_42 ,
( V_88 & V_451 ) != 0 ) ;
return;
}
if ( V_66 & 0x3fc ) {
if ( V_5 -> V_440 ) {
F_4 ( V_2 -> V_29 , L_43 ) ;
F_66 ( V_5 -> V_425 , V_448 ,
V_448 ) ;
} else if ( V_5 -> V_427 ) {
F_4 ( V_2 -> V_29 , L_44 ) ;
F_69 ( V_2 ) ;
F_6 ( V_2 , V_117 ,
V_431 ,
7 << V_449 ) ;
}
}
}
static T_3 F_71 ( int V_60 , void * V_453 )
{
struct V_1 * V_2 = V_453 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_454 ;
V_454 = F_3 ( V_2 , V_267 ) ;
if ( V_454 < 0 ) {
F_18 ( V_2 -> V_29 , L_45 ,
V_454 ) ;
return V_455 ;
}
V_454 &= ~ F_3 ( V_2 , V_270 ) ;
if ( ! V_454 )
return V_455 ;
F_23 ( V_2 , V_267 , V_454 ) ;
if ( V_454 & ( V_456 | V_457 ) ) {
F_4 ( V_2 -> V_29 , L_46 ) ;
F_72 ( & V_5 -> V_61 ) ;
}
if ( V_454 & V_458 )
F_18 ( V_2 -> V_29 , L_47 ) ;
if ( V_454 & V_459 ) {
F_4 ( V_2 -> V_29 , L_48 ) ;
F_72 ( & V_5 -> V_409 ) ;
}
if ( V_454 & V_460 )
F_70 ( V_2 ) ;
if ( V_454 & V_433 )
F_65 ( V_2 ) ;
return V_461 ;
}
static T_3 F_73 ( int V_60 , void * V_453 )
{
T_3 V_47 = V_455 ;
T_3 V_66 ;
do {
V_66 = F_71 ( V_60 , V_453 ) ;
if ( V_66 != V_455 )
V_47 = V_66 ;
} while ( V_66 != V_455 );
return V_47 ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_462 V_463 [] = {
F_75 ( L_2 ,
V_5 -> V_464 ,
F_10 ,
F_8 ) ,
F_75 ( L_3 ,
V_5 -> V_464 ,
F_10 ,
F_8 ) ,
} ;
int V_47 , V_12 , V_465 ;
const char * * V_466 ;
V_5 -> V_15 = 0 ;
V_5 -> V_26 = NULL ;
for ( V_12 = 0 ; V_12 < V_7 -> V_23 ; V_12 ++ ) {
for ( V_465 = 0 ; V_465 < V_5 -> V_15 ; V_465 ++ ) {
if ( strcmp ( V_7 -> V_24 [ V_12 ] . V_25 ,
V_5 -> V_26 [ V_465 ] ) == 0 )
break;
}
if ( V_465 != V_5 -> V_15 )
continue;
V_466 = F_76 ( V_5 -> V_26 ,
sizeof( char * ) *
( V_5 -> V_15 + 1 ) ,
V_467 ) ;
if ( V_466 == NULL )
continue;
V_466 [ V_5 -> V_15 ] =
V_7 -> V_24 [ V_12 ] . V_25 ;
V_5 -> V_15 ++ ;
V_5 -> V_26 = V_466 ;
}
F_4 ( V_2 -> V_29 , L_49 ,
V_5 -> V_15 ) ;
V_5 -> V_464 . V_379 = V_5 -> V_15 ;
V_5 -> V_464 . V_468 = V_5 -> V_26 ;
V_47 = F_77 ( V_2 , V_463 , F_5 ( V_463 ) ) ;
if ( V_47 != 0 )
F_18 ( V_2 -> V_29 ,
L_50 , V_47 ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
int V_47 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_56 * V_57 = F_22 ( V_2 -> V_29 ) ;
struct V_62 * V_63 = & V_2 -> V_63 ;
int V_12 , V_469 ;
V_5 -> V_2 = V_2 ;
F_79 ( & V_5 -> V_61 ) ;
F_79 ( & V_5 -> V_409 ) ;
V_63 -> V_470 = true ;
V_47 = F_80 ( V_2 , 16 , 16 , V_471 ) ;
if ( V_47 != 0 ) {
F_18 ( V_2 -> V_29 , L_51 , V_47 ) ;
goto V_472;
}
for ( V_12 = 0 ; V_12 < F_5 ( V_5 -> V_291 ) ; V_12 ++ )
V_5 -> V_291 [ V_12 ] . V_473 = V_474 [ V_12 ] ;
V_47 = F_81 ( V_2 -> V_29 , F_5 ( V_5 -> V_291 ) ,
V_5 -> V_291 ) ;
if ( V_47 != 0 ) {
F_18 ( V_2 -> V_29 , L_52 , V_47 ) ;
goto V_472;
}
V_5 -> V_475 [ 0 ] . V_476 = V_477 ;
V_5 -> V_475 [ 1 ] . V_476 = V_478 ;
V_5 -> V_475 [ 2 ] . V_476 = V_479 ;
V_5 -> V_50 = F_82 ( & V_57 -> V_29 , L_53 ) ;
if ( F_83 ( V_5 -> V_50 ) ) {
V_47 = F_84 ( V_5 -> V_50 ) ;
F_18 ( & V_57 -> V_29 , L_54 , V_47 ) ;
goto V_480;
}
for ( V_12 = 0 ; V_12 < F_5 ( V_5 -> V_291 ) ; V_12 ++ ) {
V_47 = F_85 ( V_5 -> V_291 [ V_12 ] . V_481 ,
& V_5 -> V_475 [ V_12 ] ) ;
if ( V_47 != 0 ) {
F_18 ( V_2 -> V_29 ,
L_55 ,
V_47 ) ;
}
}
V_47 = F_34 ( F_5 ( V_5 -> V_291 ) ,
V_5 -> V_291 ) ;
if ( V_47 != 0 ) {
F_18 ( V_2 -> V_29 , L_12 , V_47 ) ;
goto V_482;
}
if ( V_5 -> V_7 . V_292 >= 0 ) {
F_35 ( V_5 -> V_7 . V_292 , 1 ) ;
F_12 ( 5 ) ;
}
V_47 = F_3 ( V_2 , V_89 ) ;
if ( V_47 < 0 ) {
F_18 ( V_2 -> V_29 , L_56 , V_47 ) ;
goto V_483;
}
if ( V_47 != 0x8915 ) {
F_18 ( V_2 -> V_29 , L_57 , V_47 ) ;
V_47 = - V_32 ;
goto V_483;
}
V_47 = F_3 ( V_2 , V_128 ) ;
if ( V_47 < 0 ) {
F_18 ( V_2 -> V_29 , L_58 ,
V_47 ) ;
goto V_483;
}
F_86 ( V_2 -> V_29 , L_59 ,
( V_47 & V_484 ) + 'A' ) ;
if ( V_5 -> V_7 . V_292 >= 0 ) {
F_35 ( V_5 -> V_7 . V_292 , 0 ) ;
} else {
V_47 = F_31 ( V_2 ) ;
if ( V_47 < 0 ) {
F_18 ( V_2 -> V_29 , L_60 ) ;
goto V_483;
}
}
V_2 -> V_293 = true ;
F_6 ( V_2 , V_98 ,
V_485 | V_486 ,
V_5 -> V_7 . V_487 << V_488 |
V_5 -> V_7 . V_489 ) ;
for ( V_12 = 0 ; V_12 < F_5 ( V_5 -> V_7 . V_490 ) ; V_12 ++ ) {
if ( ! V_5 -> V_7 . V_490 [ V_12 ] )
continue;
F_23 ( V_2 , V_259 + V_12 ,
V_5 -> V_7 . V_490 [ V_12 ] & 0xffff ) ;
}
if ( V_5 -> V_7 . V_491 )
F_6 ( V_2 , V_274 ,
V_492 |
V_493 ,
V_5 -> V_7 . V_491 ) ;
F_6 ( V_2 , V_114 ,
V_452 | V_450 |
V_451 , V_5 -> V_7 . V_494 ) ;
F_6 ( V_2 , V_96 ,
V_495 , V_495 ) ;
F_6 ( V_2 , V_97 ,
V_495 , V_495 ) ;
F_6 ( V_2 , V_101 ,
V_496 , V_496 ) ;
F_6 ( V_2 , V_102 ,
V_496 , V_496 ) ;
F_6 ( V_2 , V_103 ,
V_497 , V_497 ) ;
F_6 ( V_2 , V_104 ,
V_497 , V_497 ) ;
F_6 ( V_2 , V_105 ,
V_496 , V_496 ) ;
F_6 ( V_2 , V_106 ,
V_496 , V_496 ) ;
F_6 ( V_2 , V_107 ,
V_497 , V_497 ) ;
F_6 ( V_2 , V_108 ,
V_497 , V_497 ) ;
F_6 ( V_2 , V_183 ,
V_498 , V_498 ) ;
F_6 ( V_2 , V_184 ,
V_498 , V_498 ) ;
F_6 ( V_2 , V_213 ,
V_499 , V_499 ) ;
F_6 ( V_2 , V_214 ,
V_499 , V_499 ) ;
F_6 ( V_2 , V_185 ,
V_500 , V_500 ) ;
F_6 ( V_2 , V_186 ,
V_500 , V_500 ) ;
F_6 ( V_2 , V_215 ,
V_501 , V_501 ) ;
F_6 ( V_2 , V_216 ,
V_501 , V_501 ) ;
F_6 ( V_2 , V_160 ,
V_502 |
V_503 ,
1 << V_504 | 0 ) ;
F_6 ( V_2 , V_161 ,
V_505 |
V_506 ,
1 << V_507 | 1 ) ;
F_6 ( V_2 , V_162 ,
V_508 |
V_509 ,
1 << V_510 | 0 ) ;
F_6 ( V_2 , V_163 ,
V_511 |
V_503 ,
1 << V_512 | 1 ) ;
F_6 ( V_2 , V_164 ,
V_513 |
V_503 ,
1 << V_514 | 0 ) ;
F_6 ( V_2 , V_165 ,
V_515 |
V_503 ,
1 << V_516 | 1 ) ;
F_6 ( V_2 , V_179 ,
V_517 |
V_518 ,
1 << V_519 | 0 ) ;
F_6 ( V_2 , V_180 ,
V_520 |
V_521 ,
1 << V_522 | 1 ) ;
F_6 ( V_2 , V_154 ,
V_523 |
V_524 ,
1 << V_525 | 0 ) ;
F_6 ( V_2 , V_155 ,
V_526 |
V_524 ,
1 << V_527 | 1 ) ;
F_6 ( V_2 , V_156 ,
V_528 |
V_524 ,
1 << V_529 | 0 ) ;
F_6 ( V_2 , V_157 ,
V_530 |
V_524 ,
1 << V_531 | 1 ) ;
F_6 ( V_2 , V_158 ,
V_532 |
V_524 ,
1 << V_533 | 0 ) ;
F_6 ( V_2 , V_159 ,
V_534 |
V_524 ,
1 << V_535 | 1 ) ;
F_6 ( V_2 , V_177 ,
V_536 |
V_537 ,
1 << V_538 | 0 ) ;
F_6 ( V_2 , V_155 ,
V_539 |
V_540 ,
1 << V_527 | 1 ) ;
if ( V_5 -> V_7 . V_23 )
F_74 ( V_2 ) ;
else
F_77 ( V_2 , V_541 ,
F_5 ( V_541 ) ) ;
if ( ( F_3 ( V_2 , V_259 ) ) )
F_6 ( V_2 , V_148 ,
V_542 ,
V_542 ) ;
if ( ( F_3 ( V_2 , V_260 ) ) )
F_6 ( V_2 , V_171 ,
V_543 ,
V_543 ) ;
F_37 ( F_5 ( V_5 -> V_291 ) , V_5 -> V_291 ) ;
F_59 ( V_2 ) ;
if ( V_57 -> V_60 ) {
if ( V_5 -> V_7 . V_469 )
V_469 = V_5 -> V_7 . V_469 ;
else
V_469 = V_544 ;
V_469 |= V_545 ;
if ( V_469 & ( V_546 | V_547 ) )
V_47 = F_87 ( V_57 -> V_60 , NULL ,
F_73 ,
V_469 , L_61 , V_2 ) ;
else
V_47 = F_87 ( V_57 -> V_60 , NULL , F_71 ,
V_469 , L_61 , V_2 ) ;
if ( V_47 == 0 ) {
F_6 ( V_2 , V_271 ,
V_548 , 0 ) ;
F_6 ( V_2 ,
V_270 ,
V_549 |
V_550 |
V_551 |
V_552 ,
0 ) ;
} else {
F_18 ( V_2 -> V_29 , L_62 ,
V_47 ) ;
}
}
return 0 ;
V_483:
if ( V_5 -> V_7 . V_292 >= 0 )
F_35 ( V_5 -> V_7 . V_292 , 0 ) ;
F_37 ( F_5 ( V_5 -> V_291 ) , V_5 -> V_291 ) ;
V_482:
F_88 ( V_5 -> V_50 ) ;
V_480:
F_89 ( F_5 ( V_5 -> V_291 ) , V_5 -> V_291 ) ;
V_472:
return V_47 ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_56 * V_57 = F_22 ( V_2 -> V_29 ) ;
int V_12 ;
F_6 ( V_2 , V_271 ,
V_548 , V_548 ) ;
if ( V_57 -> V_60 )
F_91 ( V_57 -> V_60 , V_2 ) ;
F_61 ( V_2 ) ;
for ( V_12 = 0 ; V_12 < F_5 ( V_5 -> V_291 ) ; V_12 ++ )
F_92 ( V_5 -> V_291 [ V_12 ] . V_481 ,
& V_5 -> V_475 [ V_12 ] ) ;
F_88 ( V_5 -> V_50 ) ;
F_89 ( F_5 ( V_5 -> V_291 ) , V_5 -> V_291 ) ;
return 0 ;
}
static T_4 int F_93 ( struct V_56 * V_57 ,
const struct V_553 * V_37 )
{
struct V_4 * V_5 ;
int V_47 ;
V_5 = F_94 ( sizeof( struct V_4 ) , V_467 ) ;
if ( V_5 == NULL )
return - V_554 ;
F_95 ( V_57 , V_5 ) ;
if ( F_96 ( & V_57 -> V_29 ) )
memcpy ( & V_5 -> V_7 , F_96 ( & V_57 -> V_29 ) ,
sizeof( V_5 -> V_7 ) ) ;
if ( V_5 -> V_7 . V_292 > 0 ) {
V_47 = F_97 ( V_5 -> V_7 . V_292 ,
V_555 , L_63 ) ;
if ( V_47 < 0 ) {
F_18 ( & V_57 -> V_29 , L_64 ,
V_5 -> V_7 . V_292 , V_47 ) ;
goto V_472;
}
}
V_47 = F_98 ( & V_57 -> V_29 ,
& V_556 , V_557 ,
F_5 ( V_557 ) ) ;
if ( V_47 < 0 )
goto V_558;
return V_47 ;
V_558:
if ( V_5 -> V_7 . V_292 > 0 )
F_99 ( V_5 -> V_7 . V_292 ) ;
V_472:
F_100 ( V_5 ) ;
return V_47 ;
}
static T_5 int F_101 ( struct V_56 * V_559 )
{
struct V_4 * V_5 = F_102 ( V_559 ) ;
F_103 ( & V_559 -> V_29 ) ;
if ( V_5 -> V_7 . V_292 > 0 )
F_99 ( V_5 -> V_7 . V_292 ) ;
F_100 ( F_102 ( V_559 ) ) ;
return 0 ;
}
static int T_6 F_104 ( void )
{
int V_47 ;
V_47 = F_105 ( & V_560 ) ;
if ( V_47 != 0 ) {
F_106 ( V_561 L_65 ,
V_47 ) ;
}
return V_47 ;
}
static void T_7 F_107 ( void )
{
F_108 ( & V_560 ) ;
}
