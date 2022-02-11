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
if ( V_3 < 0 )
return V_3 ;
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
F_15 ( 1 , L_4 , V_46 ) ;
V_47 = - V_32 ;
}
return V_47 ;
}
static int F_16 ( struct V_44 * V_45 ,
struct V_33 * V_34 , int V_46 )
{
int V_47 = 0 ;
switch ( V_46 ) {
case V_50 :
F_12 ( 5 ) ;
break;
default:
F_15 ( 1 , L_4 , V_46 ) ;
V_47 = - V_32 ;
}
return 0 ;
}
static int F_17 ( struct V_44 * V_45 ,
struct V_33 * V_34 , int V_46 )
{
struct V_4 * V_5 = F_2 ( V_45 -> V_2 ) ;
switch ( V_46 ) {
case V_51 :
V_5 -> V_52 &= ~ V_45 -> V_53 ;
break;
case V_48 :
V_5 -> V_52 |= V_45 -> V_53 ;
break;
default:
F_15 ( 1 , L_4 , V_46 ) ;
return - V_32 ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , T_1 V_54 )
{
struct V_55 * V_56 = F_19 ( V_2 -> V_29 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_47 ;
unsigned long V_57 = 200 ;
F_20 ( V_2 , V_58 , V_54 ) ;
do {
if ( V_56 -> V_59 ) {
V_57 = F_21 ( & V_5 -> V_60 ,
F_22 ( 200 ) ) ;
if ( V_57 == 0 )
F_23 ( V_2 -> V_29 , L_5 ) ;
} else {
F_12 ( 1 ) ;
V_57 -- ;
}
V_47 = F_3 ( V_2 , V_58 ) ;
F_4 ( V_2 -> V_29 , L_6 , V_47 ) ;
} while ( V_57 && V_47 & V_54 );
if ( V_57 == 0 )
F_23 ( V_2 -> V_29 , L_7 , V_54 ) ;
else
F_4 ( V_2 -> V_29 , L_8 , V_54 ) ;
}
static void F_24 ( struct V_61 * V_62 ,
enum V_63 V_46 , int V_64 )
{
struct V_1 * V_2 = F_25 ( V_62 ,
struct V_1 , V_62 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_65 , V_54 ;
if ( V_5 -> V_66 ) {
F_4 ( V_2 -> V_29 , L_9 ,
V_5 -> V_66 ) ;
F_18 ( V_2 , V_5 -> V_66
<< V_67 ) ;
V_5 -> V_66 = 0 ;
}
if ( V_5 -> V_52 != V_5 -> V_68 ) {
F_4 ( V_2 -> V_29 , L_10 ,
V_5 -> V_68 , V_5 -> V_52 ) ;
V_65 = 0 ;
V_54 = 0 ;
if ( V_5 -> V_52 & V_69 ) {
V_65 |= V_70 | V_71 ;
V_54 |= V_70 | V_71 ;
} else {
V_54 |= V_70 |
V_71 |
V_72 ;
}
if ( V_5 -> V_52 & V_73 ) {
V_65 |= V_74 | V_75 ;
V_54 |= V_74 | V_75 ;
} else {
V_54 |= V_74 |
V_75 |
V_76 ;
}
F_6 ( V_2 , V_77 , V_54 , V_65 ) ;
V_65 = 0 ;
V_54 = 0 ;
if ( V_5 -> V_52 & V_78 ) {
V_65 |= V_79 | V_80 ;
V_54 |= V_79 | V_80 ;
} else {
V_54 |= V_79 |
V_80 |
V_81 ;
}
if ( V_5 -> V_52 & V_82 ) {
V_65 |= V_83 | V_84 ;
V_54 |= V_83 | V_84 ;
} else {
V_54 |= V_83 |
V_84 |
V_85 ;
}
F_6 ( V_2 , V_86 , V_54 , V_65 ) ;
V_5 -> V_68 = V_5 -> V_52 ;
}
}
static int F_26 ( struct V_44 * V_45 ,
struct V_33 * V_34 , int V_46 )
{
struct V_4 * V_5 = F_2 ( V_45 -> V_2 ) ;
switch ( V_46 ) {
case V_50 :
V_5 -> V_66 |= 1 << V_45 -> V_53 ;
break;
default:
F_15 ( 1 , L_4 , V_46 ) ;
return - V_32 ;
}
return 0 ;
}
static bool F_27 ( struct V_87 * V_29 , unsigned int V_88 )
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
case V_58 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_77 :
case V_86 :
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
static bool F_28 ( struct V_87 * V_29 , unsigned int V_88 )
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
case V_58 :
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
static void F_29 ( struct V_1 * V_2 )
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
static int F_30 ( struct V_1 * V_2 ,
enum V_284 V_285 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_47 ;
switch ( V_285 ) {
case V_286 :
break;
case V_287 :
F_6 ( V_2 , V_109 ,
V_288 , 0 ) ;
F_6 ( V_2 , V_110 ,
V_289 , 0 ) ;
break;
case V_290 :
if ( V_2 -> V_62 . V_291 == V_292 ) {
V_47 = F_31 ( F_5 ( V_5 -> V_293 ) ,
V_5 -> V_293 ) ;
if ( V_47 != 0 ) {
F_23 ( V_2 -> V_29 ,
L_12 ,
V_47 ) ;
return V_47 ;
}
if ( V_5 -> V_7 . V_294 >= 0 ) {
F_32 ( V_5 -> V_7 . V_294 ,
1 ) ;
F_12 ( 5 ) ;
}
F_33 ( V_5 -> V_295 , false ) ;
F_34 ( V_5 -> V_295 ) ;
}
F_6 ( V_2 , V_109 ,
V_288 , V_288 ) ;
F_6 ( V_2 , V_110 ,
V_289 , V_289 ) ;
break;
case V_292 :
F_33 ( V_5 -> V_295 , true ) ;
if ( V_5 -> V_7 . V_294 >= 0 ) {
F_32 ( V_5 -> V_7 . V_294 , 0 ) ;
F_33 ( V_5 -> V_295 , true ) ;
}
F_35 ( F_5 ( V_5 -> V_293 ) ,
V_5 -> V_293 ) ;
break;
}
V_2 -> V_62 . V_291 = V_285 ;
return 0 ;
}
static int F_36 ( struct V_296 * V_297 , unsigned int V_298 )
{
struct V_1 * V_2 = V_297 -> V_2 ;
int V_299 = 0 ;
int V_300 = 0 ;
int V_301 = 0 ;
int V_302 = 0 ;
int V_303 , V_279 , V_304 , V_305 ;
switch ( V_297 -> V_37 ) {
case 0 :
V_303 = V_145 ;
V_279 = V_146 ;
V_304 = V_148 ;
V_305 = V_150 ;
break;
case 1 :
V_303 = V_168 ;
V_279 = V_169 ;
V_304 = V_171 ;
V_305 = V_173 ;
break;
default:
F_15 ( 1 , L_13 , V_297 -> V_37 ) ;
return - V_32 ;
}
switch ( V_298 & V_306 ) {
case V_307 :
break;
case V_308 :
V_300 |= V_309 ;
break;
case V_310 :
V_301 |= V_311 ;
V_302 |= V_312 ;
break;
case V_313 :
V_300 |= V_309 ;
V_301 |= V_311 ;
V_302 |= V_312 ;
break;
}
switch ( V_298 & V_314 ) {
case V_315 :
break;
case V_316 :
V_301 |= V_317 ;
V_302 |= V_318 ;
break;
case V_319 :
V_300 |= V_320 ;
break;
case V_321 :
V_300 |= V_320 ;
V_301 |= V_317 ;
V_302 |= V_318 ;
break;
default:
return - V_32 ;
}
switch ( V_298 & V_322 ) {
case V_323 :
break;
case V_324 :
V_299 |= 1 ;
break;
case V_325 :
V_299 |= 2 ;
break;
case V_326 :
V_299 |= 3 ;
break;
default:
return - V_32 ;
}
F_6 ( V_2 , V_303 , V_327 , V_299 ) ;
F_6 ( V_2 , V_279 ,
V_309 | V_320 ,
V_300 ) ;
F_6 ( V_2 , V_304 ,
V_311 |
V_317 ,
V_301 ) ;
F_6 ( V_2 , V_305 ,
V_312 |
V_318 ,
V_302 ) ;
return 0 ;
}
static int F_37 ( struct V_328 * V_329 ,
struct V_330 * V_331 ,
struct V_296 * V_297 )
{
struct V_1 * V_2 = V_297 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_332 , V_12 , V_278 , V_9 ;
int V_333 = 0 ;
int V_334 = 0 ;
int V_335 = 0 ;
int V_336 , V_337 , V_338 ;
switch ( V_297 -> V_37 ) {
case 0 :
if ( V_329 -> V_339 == V_340 ||
( F_3 ( V_2 , V_259 ) ) & V_341 ) {
V_336 = V_153 ;
V_337 = V_149 ;
} else {
V_336 = V_151 ;
V_337 = V_147 ;
}
V_338 = 0 ;
break;
case 1 :
if ( V_329 -> V_339 == V_340 ||
( F_3 ( V_2 , V_260 ) ) & V_342 ) {
V_336 = V_176 ;
V_337 = V_172 ;
} else {
V_336 = V_174 ;
V_337 = V_170 ;
}
V_338 = V_343 ;
break;
default:
F_15 ( 1 , L_13 , V_297 -> V_37 ) ;
return - V_32 ;
}
V_278 = F_38 ( V_331 ) ;
if ( V_278 < 0 ) {
F_23 ( V_2 -> V_29 , L_14 , V_278 ) ;
return V_278 ;
}
V_5 -> V_278 [ V_297 -> V_37 ] = V_278 ;
V_5 -> V_28 [ V_297 -> V_37 ] = F_39 ( V_331 ) ;
V_332 = F_40 ( F_41 ( V_331 ) ) ;
if ( V_332 < 0 )
return V_332 ;
V_333 |= ( V_332 << V_344 ) | V_332 ;
V_9 = 0 ;
for ( V_12 = 0 ; V_12 < F_5 ( V_345 ) ; V_12 ++ ) {
if ( abs ( V_345 [ V_12 ] - F_39 ( V_331 ) ) <
abs ( V_345 [ V_9 ] - F_39 ( V_331 ) ) )
V_9 = V_12 ;
}
V_335 |= V_12 << V_338 ;
F_29 ( V_2 ) ;
V_334 = V_278 / F_39 ( V_331 ) ;
F_4 ( V_297 -> V_29 , L_15 ,
V_334 , V_278 / V_334 ) ;
F_6 ( V_2 , V_336 ,
V_346 |
V_347 ,
V_333 ) ;
F_6 ( V_2 , V_337 , V_348 ,
V_334 ) ;
F_6 ( V_2 , V_133 ,
V_349 << V_338 , V_335 ) ;
return 0 ;
}
static int F_42 ( struct V_296 * V_297 ,
int V_350 , unsigned int V_351 , int V_352 )
{
struct V_1 * V_2 = V_297 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_353 = 0 ;
int V_354 = 0 ;
int V_355 = V_356 ;
int V_357 ;
int V_358 ;
if ( V_351 == V_5 -> V_280 && V_350 == V_5 -> V_359 )
return 0 ;
V_358 = F_3 ( V_2 , V_132 ) & V_360 ;
F_6 ( V_2 , V_132 ,
V_360 , 0 ) ;
switch ( V_350 ) {
case V_361 :
V_5 -> V_280 = V_351 ;
V_357 = 0 ;
break;
case V_362 :
V_5 -> V_280 = V_351 ;
V_357 = 1 ;
break;
case V_363 :
V_5 -> V_280 = V_351 ;
V_357 = 2 ;
break;
default:
F_23 ( V_2 -> V_29 , L_16 , V_350 ) ;
return - V_32 ;
}
switch ( V_5 -> V_280 ) {
case 5644800 :
case 6144000 :
F_6 ( V_2 , V_136 ,
V_364 , 0 ) ;
break;
case 22579200 :
case 24576000 :
V_354 = V_365 ;
V_5 -> V_280 /= 2 ;
case 11289600 :
case 12288000 :
F_6 ( V_2 , V_136 ,
V_364 , V_364 ) ;
break;
case 32000 :
case 32768 :
V_353 = V_366 ;
V_355 = 0 ;
break;
default:
F_43 ( V_2 -> V_29 , L_17 ,
V_5 -> V_280 ) ;
return - V_32 ;
}
F_29 ( V_2 ) ;
F_6 ( V_2 , V_132 ,
V_367 | V_368 ,
V_357 << V_369 | V_354 ) ;
F_6 ( V_2 , V_134 , V_366 , V_353 ) ;
F_6 ( V_2 , V_129 ,
V_356 , V_355 ) ;
F_6 ( V_2 , V_132 ,
V_360 , V_358 ) ;
V_5 -> V_359 = V_350 ;
return 0 ;
}
static int F_44 ( struct V_370 * V_371 , unsigned int V_372 ,
unsigned int V_373 )
{
unsigned int V_374 ;
unsigned int div ;
unsigned int V_375 , V_376 ;
int V_12 ;
div = 1 ;
V_371 -> V_377 = 0 ;
while ( ( V_372 / div ) > 13500000 ) {
div *= 2 ;
V_371 -> V_377 ++ ;
if ( div > 8 ) {
F_45 ( L_18 ,
V_372 ) ;
return - V_32 ;
}
}
F_46 ( L_19 , V_372 , V_373 ) ;
V_372 /= div ;
if ( V_372 >= 3000000 )
V_371 -> V_378 = 5 ;
else
V_371 -> V_378 = 0 ;
if ( V_372 >= 48000 )
V_371 -> V_379 = 0 ;
else
V_371 -> V_379 = 1 ;
div = 2 ;
while ( V_373 * div < 90000000 ) {
div ++ ;
if ( div > 64 ) {
F_45 ( L_20 ,
V_373 ) ;
return - V_32 ;
}
}
V_374 = V_373 * div ;
V_371 -> V_380 = div - 1 ;
F_46 ( L_21 , V_374 ) ;
for ( V_12 = 0 ; V_12 < F_5 ( V_381 ) ; V_12 ++ ) {
if ( V_381 [ V_12 ] . V_382 <= V_372 && V_372 <= V_381 [ V_12 ] . V_383 ) {
V_371 -> V_384 = V_381 [ V_12 ] . V_384 ;
V_375 = V_381 [ V_12 ] . V_385 ;
break;
}
}
if ( V_12 == F_5 ( V_381 ) ) {
F_45 ( L_22 , V_372 ) ;
return - V_32 ;
}
V_371 -> V_386 = V_374 / ( V_375 * V_372 ) ;
if ( V_374 % V_372 == 0 ) {
V_371 -> V_387 = 0 ;
V_371 -> V_388 = 0 ;
} else {
V_376 = F_47 ( V_374 , V_375 * V_372 ) ;
V_371 -> V_387 = ( V_374 - ( V_371 -> V_386 * V_375 * V_372 ) )
/ V_376 ;
V_371 -> V_388 = ( V_375 * V_372 ) / V_376 ;
}
F_46 ( L_23 ,
V_371 -> V_386 , V_371 -> V_387 , V_371 -> V_388 ) ;
F_46 ( L_24 ,
V_371 -> V_384 , V_371 -> V_380 ,
V_371 -> V_377 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , int V_389 , int V_390 ,
unsigned int V_372 , unsigned int V_373 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_55 * V_56 = F_19 ( V_2 -> V_29 ) ;
struct V_370 V_371 ;
unsigned long V_57 ;
int V_47 , V_88 , V_391 ;
if ( V_390 == V_5 -> V_392 && V_372 == V_5 -> V_393 &&
V_373 == V_5 -> V_394 )
return 0 ;
if ( V_373 == 0 ) {
F_4 ( V_2 -> V_29 , L_25 ) ;
V_5 -> V_393 = 0 ;
V_5 -> V_394 = 0 ;
F_6 ( V_2 , V_137 ,
V_395 , 0 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
V_47 = F_44 ( & V_371 , V_372 , V_373 ) ;
if ( V_47 != 0 )
return V_47 ;
switch ( V_390 ) {
case V_396 :
V_88 = 0 ;
break;
case V_397 :
V_88 = 1 ;
break;
case V_398 :
V_88 = 2 ;
break;
case V_399 :
V_88 = 3 ;
break;
default:
F_23 ( V_2 -> V_29 , L_26 , V_47 ) ;
return - V_32 ;
}
V_88 |= V_371 . V_377 << V_400 ;
V_88 |= V_371 . V_379 << V_401 ;
F_6 ( V_2 , V_141 ,
V_402 | V_403 |
V_404 , V_88 ) ;
V_88 = 0 ;
if ( V_371 . V_387 || V_371 . V_388 )
V_88 |= V_405 | ( 3 << V_406 ) ;
else
V_88 |= 1 << V_406 ;
F_20 ( V_2 , V_144 , V_88 ) ;
F_6 ( V_2 , V_138 ,
V_407 |
V_408 ,
( V_371 . V_380 << V_409 ) |
( V_371 . V_384 ) ) ;
F_20 ( V_2 , V_139 , V_371 . V_387 ) ;
F_6 ( V_2 , V_140 ,
V_410 | V_411 ,
( V_371 . V_386 << V_412 ) |
V_371 . V_378 ) ;
F_20 ( V_2 , V_143 , V_371 . V_388 ) ;
V_47 = F_3 ( V_2 , V_137 ) ;
if ( ! ( V_47 & V_395 ) )
F_11 ( V_2 ) ;
F_49 ( & V_5 -> V_413 ) ;
F_6 ( V_2 , V_137 ,
V_395 , V_395 ) ;
F_20 ( V_2 , V_142 , V_414 ) ;
if ( V_372 > 1000000 )
V_57 = F_50 ( 300 ) ;
else
V_57 = F_22 ( 2 ) ;
if ( V_56 -> V_59 )
V_57 *= 10 ;
else
V_57 /= 2 ;
for ( V_391 = 0 ; V_391 < 10 ; V_391 ++ ) {
V_47 = F_21 ( & V_5 -> V_413 ,
V_57 ) ;
if ( V_47 != 0 ) {
F_51 ( ! V_56 -> V_59 ) ;
break;
}
V_47 = F_3 ( V_2 , V_268 ) ;
if ( V_47 & V_415 )
break;
}
if ( V_391 == 10 ) {
F_23 ( V_2 -> V_29 , L_27 ) ;
V_47 = - V_416 ;
}
F_4 ( V_2 -> V_29 , L_28 , V_372 , V_373 ) ;
V_5 -> V_393 = V_372 ;
V_5 -> V_394 = V_373 ;
V_5 -> V_392 = V_390 ;
return V_47 ;
}
static inline struct V_4 * F_52 ( struct V_417 * V_418 )
{
return F_25 ( V_418 , struct V_4 , V_417 ) ;
}
static void F_53 ( struct V_417 * V_418 , unsigned V_419 , int V_38 )
{
struct V_4 * V_5 = F_52 ( V_418 ) ;
F_54 ( V_5 -> V_295 , V_259 + V_419 ,
V_420 , ! ! V_38 << V_421 ) ;
}
static int F_55 ( struct V_417 * V_418 ,
unsigned V_419 , int V_38 )
{
struct V_4 * V_5 = F_52 ( V_418 ) ;
int V_65 ;
V_65 = ( 1 << V_422 ) | ( ! ! V_38 << V_421 ) ;
return F_54 ( V_5 -> V_295 , V_259 + V_419 ,
V_341 | V_423 |
V_420 , V_65 ) ;
}
static int F_56 ( struct V_417 * V_418 , unsigned V_419 )
{
struct V_4 * V_5 = F_52 ( V_418 ) ;
unsigned int V_88 ;
int V_47 ;
V_47 = F_57 ( V_5 -> V_295 , V_259 + V_419 , & V_88 ) ;
if ( V_47 < 0 )
return V_47 ;
return ( V_88 & V_420 ) != 0 ;
}
static int F_58 ( struct V_417 * V_418 , unsigned V_419 )
{
struct V_4 * V_5 = F_52 ( V_418 ) ;
return F_54 ( V_5 -> V_295 , V_259 + V_419 ,
V_341 | V_423 ,
( 1 << V_422 ) |
( 1 << V_424 ) ) ;
}
static void F_59 ( struct V_4 * V_5 )
{
int V_47 ;
V_5 -> V_417 = V_425 ;
V_5 -> V_417 . V_426 = 5 ;
V_5 -> V_417 . V_29 = V_5 -> V_29 ;
if ( V_5 -> V_7 . V_427 )
V_5 -> V_417 . V_8 = V_5 -> V_7 . V_427 ;
else
V_5 -> V_417 . V_8 = - 1 ;
V_47 = F_60 ( & V_5 -> V_417 ) ;
if ( V_47 != 0 )
F_23 ( V_5 -> V_29 , L_29 , V_47 ) ;
}
static void F_61 ( struct V_4 * V_5 )
{
int V_47 ;
V_47 = F_62 ( & V_5 -> V_417 ) ;
if ( V_47 != 0 )
F_23 ( V_5 -> V_29 , L_30 , V_47 ) ;
}
static void F_59 ( struct V_4 * V_5 )
{
}
static void F_61 ( struct V_4 * V_5 )
{
}
int F_63 ( struct V_1 * V_2 , struct V_428 * V_429 ,
T_2 V_430 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_61 * V_62 = & V_2 -> V_62 ;
V_5 -> V_429 = V_429 ;
V_5 -> V_431 = true ;
V_5 -> V_430 = V_430 ;
V_5 -> V_432 = 0 ;
if ( V_5 -> V_430 )
V_5 -> V_430 ( V_2 , 0 ) ;
F_6 ( V_2 , V_109 ,
V_433 , 0 ) ;
F_6 ( V_2 , V_110 ,
V_434 , 0 ) ;
F_64 ( V_62 ) ;
F_65 ( V_62 , L_31 ) ;
F_65 ( V_62 , L_32 ) ;
F_66 ( V_62 ) ;
F_6 ( V_2 , V_117 ,
V_435 , V_435 ) ;
F_6 ( V_2 , V_117 ,
V_436 ,
V_436 ) ;
F_6 ( V_2 , V_270 ,
V_437 | V_438 , 0 ) ;
return 0 ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_65 , V_88 , V_439 ;
V_439 = V_440 ;
V_88 = F_3 ( V_2 , V_116 ) ;
if ( V_88 < 0 ) {
F_23 ( V_2 -> V_29 , L_33 ) ;
goto V_441;
}
if ( ! ( V_88 & V_442 ) ) {
F_23 ( V_2 -> V_29 , L_34 ) ;
goto V_441;
}
V_65 = V_88 & V_443 ;
F_4 ( V_2 -> V_29 , L_35 , V_65 ) ;
if ( V_65 >= 126 )
V_439 = V_444 ;
else
V_439 = V_440 ;
V_441:
if ( V_5 -> V_445 )
V_439 |= V_446 ;
F_68 ( V_5 -> V_429 , V_439 ,
V_444 | V_447 ) ;
V_5 -> V_431 = false ;
if ( ! ( F_3 ( V_2 , V_42 ) &
( V_448 | V_74 ) ) )
F_6 ( V_2 , V_77 ,
V_70 |
V_74 , 0 ) ;
F_6 ( V_2 , V_113 ,
V_449 , 0 ) ;
F_6 ( V_2 , V_117 , V_435 ,
V_435 ) ;
F_69 ( & V_2 -> V_62 , L_36 ) ;
F_70 ( & V_2 -> V_62 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_77 ,
V_70 |
V_74 ,
V_70 |
V_74 ) ;
F_72 ( & V_2 -> V_62 , L_36 ) ;
F_70 ( & V_2 -> V_62 ) ;
F_6 ( V_2 , V_117 , V_435 , 0 ) ;
F_6 ( V_2 , V_113 ,
V_449 , 1 ) ;
F_6 ( V_2 , V_115 ,
V_450 , V_450 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_29 , L_37 ) ;
F_71 ( V_2 ) ;
F_6 ( V_2 , V_117 ,
V_436 |
V_451 ,
7 << V_452 |
7 << V_453 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_65 , V_88 ;
V_65 = F_3 ( V_2 , V_119 ) ;
F_4 ( V_2 -> V_29 , L_38 , V_65 ) ;
if ( ! ( V_65 & V_454 ) ) {
F_43 ( V_2 -> V_29 , L_39 ) ;
return;
}
if ( ! ( V_65 & V_455 ) ) {
F_4 ( V_2 -> V_29 , L_40 ) ;
V_5 -> V_445 = false ;
V_5 -> V_431 = true ;
V_5 -> V_432 = 0 ;
F_68 ( V_5 -> V_429 , 0 ,
V_444 | V_447 |
V_456 ) ;
F_6 ( V_2 , V_117 ,
V_436 |
V_451 ,
V_436 |
9 << V_453 ) ;
return;
}
if ( V_65 & 0x400 ) {
if ( V_5 -> V_431 ) {
F_4 ( V_2 -> V_29 , L_41 ) ;
V_5 -> V_445 = true ;
F_71 ( V_2 ) ;
F_6 ( V_2 , V_117 ,
V_436 |
V_451 ,
5 << V_452 |
7 << V_453 ) ;
} else {
F_4 ( V_2 -> V_29 , L_42 ) ;
F_68 ( V_5 -> V_429 , 0 , V_456 ) ;
}
return;
}
if ( V_5 -> V_431 && ( V_65 & 0x3f0 ) ) {
V_5 -> V_432 ++ ;
if ( V_5 -> V_432 > 1 ) {
F_73 ( V_2 ) ;
return;
}
V_88 = F_3 ( V_2 , V_114 ) ;
V_88 ^= V_457 | V_458 |
V_459 ;
F_6 ( V_2 , V_114 ,
V_457 | V_458 |
V_459 , V_88 ) ;
if ( V_5 -> V_430 )
V_5 -> V_430 ( V_2 ,
( V_88 & V_458 ) != 0 ) ;
F_4 ( V_2 -> V_29 , L_43 ,
( V_88 & V_458 ) != 0 ) ;
return;
}
if ( V_65 & 0x3fc ) {
if ( V_5 -> V_445 ) {
F_4 ( V_2 -> V_29 , L_44 ) ;
F_68 ( V_5 -> V_429 , V_456 ,
V_456 ) ;
} else if ( V_5 -> V_431 ) {
F_73 ( V_2 ) ;
}
}
}
static T_3 F_75 ( int V_59 , void * V_460 )
{
struct V_1 * V_2 = V_460 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_461 ;
V_461 = F_3 ( V_2 , V_267 ) ;
if ( V_461 < 0 ) {
F_23 ( V_2 -> V_29 , L_45 ,
V_461 ) ;
return V_462 ;
}
V_461 &= ~ F_3 ( V_2 , V_270 ) ;
if ( ! V_461 )
return V_462 ;
F_20 ( V_2 , V_267 , V_461 ) ;
if ( V_461 & ( V_463 | V_464 ) ) {
F_4 ( V_2 -> V_29 , L_46 ) ;
F_76 ( & V_5 -> V_60 ) ;
}
if ( V_461 & V_465 )
F_23 ( V_2 -> V_29 , L_47 ) ;
if ( V_461 & V_466 ) {
F_4 ( V_2 -> V_29 , L_48 ) ;
F_76 ( & V_5 -> V_413 ) ;
}
if ( V_461 & V_467 )
F_74 ( V_2 ) ;
if ( V_461 & V_438 )
F_67 ( V_2 ) ;
return V_468 ;
}
static T_3 F_77 ( int V_59 , void * V_460 )
{
T_3 V_47 = V_462 ;
T_3 V_65 ;
do {
V_65 = F_75 ( V_59 , V_460 ) ;
if ( V_65 != V_462 )
V_47 = V_65 ;
} while ( V_65 != V_462 );
return V_47 ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_469 V_470 [] = {
F_79 ( L_2 ,
V_5 -> V_471 ,
F_10 ,
F_8 ) ,
F_79 ( L_3 ,
V_5 -> V_471 ,
F_10 ,
F_8 ) ,
} ;
int V_47 , V_12 , V_472 ;
const char * * V_473 ;
V_5 -> V_15 = 0 ;
V_5 -> V_26 = NULL ;
for ( V_12 = 0 ; V_12 < V_7 -> V_23 ; V_12 ++ ) {
for ( V_472 = 0 ; V_472 < V_5 -> V_15 ; V_472 ++ ) {
if ( strcmp ( V_7 -> V_24 [ V_12 ] . V_25 ,
V_5 -> V_26 [ V_472 ] ) == 0 )
break;
}
if ( V_472 != V_5 -> V_15 )
continue;
V_473 = F_80 ( V_5 -> V_26 ,
sizeof( char * ) *
( V_5 -> V_15 + 1 ) ,
V_474 ) ;
if ( V_473 == NULL )
continue;
V_473 [ V_5 -> V_15 ] =
V_7 -> V_24 [ V_12 ] . V_25 ;
V_5 -> V_15 ++ ;
V_5 -> V_26 = V_473 ;
}
F_4 ( V_2 -> V_29 , L_49 ,
V_5 -> V_15 ) ;
V_5 -> V_471 . V_475 = V_5 -> V_15 ;
V_5 -> V_471 . V_476 = V_5 -> V_26 ;
V_47 = F_81 ( V_2 , V_470 , F_5 ( V_470 ) ) ;
if ( V_47 != 0 )
F_23 ( V_2 -> V_29 ,
L_50 , V_47 ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
int V_47 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_55 * V_56 = F_19 ( V_2 -> V_29 ) ;
int V_477 ;
V_5 -> V_2 = V_2 ;
F_83 ( & V_5 -> V_60 ) ;
F_83 ( & V_5 -> V_413 ) ;
if ( V_5 -> V_7 . V_23 )
F_78 ( V_2 ) ;
else
F_81 ( V_2 , V_478 ,
F_5 ( V_478 ) ) ;
if ( V_56 -> V_59 ) {
if ( V_5 -> V_7 . V_477 )
V_477 = V_5 -> V_7 . V_477 ;
else
V_477 = V_479 ;
V_477 |= V_480 ;
if ( V_477 & ( V_481 | V_482 ) )
V_47 = F_84 ( V_56 -> V_59 , NULL ,
F_77 ,
V_477 , L_51 , V_2 ) ;
else
V_47 = F_84 ( V_56 -> V_59 , NULL , F_75 ,
V_477 , L_51 , V_2 ) ;
if ( V_47 == 0 ) {
F_6 ( V_2 , V_271 ,
V_483 , 0 ) ;
F_6 ( V_2 ,
V_270 ,
V_484 |
V_485 |
V_486 |
V_487 ,
0 ) ;
} else {
F_23 ( V_2 -> V_29 , L_52 ,
V_47 ) ;
return V_47 ;
}
}
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = F_19 ( V_2 -> V_29 ) ;
F_6 ( V_2 , V_271 ,
V_483 , V_483 ) ;
if ( V_56 -> V_59 )
F_86 ( V_56 -> V_59 , V_2 ) ;
return 0 ;
}
static int F_87 ( struct V_55 * V_56 ,
const struct V_488 * V_37 )
{
struct V_4 * V_5 ;
int V_47 , V_12 ;
unsigned int V_88 ;
V_5 = F_88 ( & V_56 -> V_29 , sizeof( struct V_4 ) ,
V_474 ) ;
if ( V_5 == NULL )
return - V_489 ;
F_89 ( V_56 , V_5 ) ;
V_5 -> V_29 = & V_56 -> V_29 ;
if ( F_90 ( & V_56 -> V_29 ) )
memcpy ( & V_5 -> V_7 , F_90 ( & V_56 -> V_29 ) ,
sizeof( V_5 -> V_7 ) ) ;
if ( V_5 -> V_7 . V_294 > 0 ) {
V_47 = F_91 ( V_5 -> V_7 . V_294 ,
V_490 , L_53 ) ;
if ( V_47 < 0 ) {
F_23 ( & V_56 -> V_29 , L_54 ,
V_5 -> V_7 . V_294 , V_47 ) ;
goto V_491;
}
}
for ( V_12 = 0 ; V_12 < F_5 ( V_5 -> V_293 ) ; V_12 ++ )
V_5 -> V_293 [ V_12 ] . V_492 = V_493 [ V_12 ] ;
V_47 = F_92 ( & V_56 -> V_29 , F_5 ( V_5 -> V_293 ) ,
V_5 -> V_293 ) ;
if ( V_47 != 0 ) {
F_23 ( & V_56 -> V_29 , L_55 , V_47 ) ;
goto V_494;
}
V_5 -> V_495 [ 0 ] . V_496 = V_497 ;
V_5 -> V_495 [ 1 ] . V_496 = V_498 ;
V_5 -> V_495 [ 2 ] . V_496 = V_499 ;
for ( V_12 = 0 ; V_12 < F_5 ( V_5 -> V_293 ) ; V_12 ++ ) {
V_47 = F_93 ( V_5 -> V_293 [ V_12 ] . V_500 ,
& V_5 -> V_495 [ V_12 ] ) ;
if ( V_47 != 0 ) {
F_23 ( & V_56 -> V_29 ,
L_56 ,
V_47 ) ;
}
}
V_47 = F_31 ( F_5 ( V_5 -> V_293 ) ,
V_5 -> V_293 ) ;
if ( V_47 != 0 ) {
F_23 ( & V_56 -> V_29 , L_12 , V_47 ) ;
goto V_494;
}
if ( V_5 -> V_7 . V_294 > 0 ) {
F_32 ( V_5 -> V_7 . V_294 , 1 ) ;
F_12 ( 5 ) ;
}
V_5 -> V_295 = F_94 ( V_56 , & V_501 ) ;
if ( F_95 ( V_5 -> V_295 ) ) {
V_47 = F_96 ( V_5 -> V_295 ) ;
F_23 ( & V_56 -> V_29 , L_57 , V_47 ) ;
goto V_502;
}
V_47 = F_57 ( V_5 -> V_295 , V_89 , & V_88 ) ;
if ( V_47 < 0 ) {
F_23 ( & V_56 -> V_29 , L_58 , V_47 ) ;
goto V_503;
}
if ( V_88 != 0x8915 ) {
F_23 ( & V_56 -> V_29 , L_59 , V_88 ) ;
V_47 = - V_32 ;
goto V_503;
}
V_47 = F_57 ( V_5 -> V_295 , V_128 , & V_88 ) ;
if ( V_47 < 0 ) {
F_23 ( & V_56 -> V_29 , L_60 ,
V_47 ) ;
goto V_503;
}
F_97 ( & V_56 -> V_29 , L_61 ,
( V_88 & V_504 ) + 'A' ) ;
if ( V_5 -> V_7 . V_294 > 0 ) {
F_32 ( V_5 -> V_7 . V_294 , 0 ) ;
F_33 ( V_5 -> V_295 , true ) ;
} else {
V_47 = F_98 ( V_5 -> V_295 , V_89 ,
0x8915 ) ;
if ( V_47 != 0 ) {
F_23 ( & V_56 -> V_29 , L_62 , V_47 ) ;
goto V_503;
}
}
F_35 ( F_5 ( V_5 -> V_293 ) , V_5 -> V_293 ) ;
F_54 ( V_5 -> V_295 , V_98 ,
V_505 | V_506 ,
V_5 -> V_7 . V_507 << V_508 |
V_5 -> V_7 . V_509 ) ;
for ( V_12 = 0 ; V_12 < F_5 ( V_5 -> V_7 . V_510 ) ; V_12 ++ ) {
if ( ! V_5 -> V_7 . V_510 [ V_12 ] )
continue;
F_98 ( V_5 -> V_295 , V_259 + V_12 ,
V_5 -> V_7 . V_510 [ V_12 ] & 0xffff ) ;
}
if ( V_5 -> V_7 . V_511 )
F_54 ( V_5 -> V_295 ,
V_274 ,
V_512 |
V_513 ,
V_5 -> V_7 . V_511 ) ;
F_54 ( V_5 -> V_295 , V_114 ,
V_459 | V_457 |
V_458 , V_5 -> V_7 . V_514 ) ;
F_54 ( V_5 -> V_295 , V_96 ,
V_515 , V_515 ) ;
F_54 ( V_5 -> V_295 , V_97 ,
V_515 , V_515 ) ;
F_54 ( V_5 -> V_295 , V_101 ,
V_516 , V_516 ) ;
F_54 ( V_5 -> V_295 , V_102 ,
V_516 , V_516 ) ;
F_54 ( V_5 -> V_295 , V_103 ,
V_517 , V_517 ) ;
F_54 ( V_5 -> V_295 , V_104 ,
V_517 , V_517 ) ;
F_54 ( V_5 -> V_295 , V_105 ,
V_516 , V_516 ) ;
F_54 ( V_5 -> V_295 , V_106 ,
V_516 , V_516 ) ;
F_54 ( V_5 -> V_295 , V_107 ,
V_517 , V_517 ) ;
F_54 ( V_5 -> V_295 , V_108 ,
V_517 , V_517 ) ;
F_54 ( V_5 -> V_295 , V_183 ,
V_518 , V_518 ) ;
F_54 ( V_5 -> V_295 , V_184 ,
V_518 , V_518 ) ;
F_54 ( V_5 -> V_295 , V_213 ,
V_519 , V_519 ) ;
F_54 ( V_5 -> V_295 , V_214 ,
V_519 , V_519 ) ;
F_54 ( V_5 -> V_295 , V_185 ,
V_520 , V_520 ) ;
F_54 ( V_5 -> V_295 , V_186 ,
V_520 , V_520 ) ;
F_54 ( V_5 -> V_295 , V_215 ,
V_521 , V_521 ) ;
F_54 ( V_5 -> V_295 , V_216 ,
V_521 , V_521 ) ;
F_54 ( V_5 -> V_295 ,
V_160 ,
V_522 |
V_523 ,
1 << V_524 | 0 ) ;
F_54 ( V_5 -> V_295 ,
V_161 ,
V_525 |
V_526 ,
1 << V_527 | 1 ) ;
F_54 ( V_5 -> V_295 ,
V_162 ,
V_528 |
V_529 ,
1 << V_530 | 0 ) ;
F_54 ( V_5 -> V_295 ,
V_163 ,
V_531 |
V_523 ,
1 << V_532 | 1 ) ;
F_54 ( V_5 -> V_295 ,
V_164 ,
V_533 |
V_523 ,
1 << V_534 | 0 ) ;
F_54 ( V_5 -> V_295 ,
V_165 ,
V_535 |
V_523 ,
1 << V_536 | 1 ) ;
F_54 ( V_5 -> V_295 ,
V_179 ,
V_537 |
V_538 ,
1 << V_539 | 0 ) ;
F_54 ( V_5 -> V_295 ,
V_180 ,
V_540 |
V_541 ,
1 << V_542 | 1 ) ;
F_54 ( V_5 -> V_295 ,
V_154 ,
V_543 |
V_544 ,
1 << V_545 | 0 ) ;
F_54 ( V_5 -> V_295 ,
V_155 ,
V_546 |
V_544 ,
1 << V_547 | 1 ) ;
F_54 ( V_5 -> V_295 ,
V_156 ,
V_548 |
V_544 ,
1 << V_549 | 0 ) ;
F_54 ( V_5 -> V_295 ,
V_157 ,
V_550 |
V_544 ,
1 << V_551 | 1 ) ;
F_54 ( V_5 -> V_295 ,
V_158 ,
V_552 |
V_544 ,
1 << V_553 | 0 ) ;
F_54 ( V_5 -> V_295 ,
V_159 ,
V_554 |
V_544 ,
1 << V_555 | 1 ) ;
F_54 ( V_5 -> V_295 ,
V_177 ,
V_556 |
V_557 ,
1 << V_558 | 0 ) ;
F_54 ( V_5 -> V_295 ,
V_155 ,
V_559 |
V_560 ,
1 << V_547 | 1 ) ;
V_47 = F_57 ( V_5 -> V_295 , V_259 , & V_88 ) ;
if ( V_47 != 0 ) {
F_23 ( & V_56 -> V_29 , L_63 , V_47 ) ;
goto V_503;
}
if ( V_88 & V_341 )
F_54 ( V_5 -> V_295 , V_148 ,
V_561 ,
V_561 ) ;
V_47 = F_57 ( V_5 -> V_295 , V_260 , & V_88 ) ;
if ( V_47 != 0 ) {
F_23 ( & V_56 -> V_29 , L_64 , V_47 ) ;
goto V_503;
}
if ( V_88 & V_342 )
F_54 ( V_5 -> V_295 , V_171 ,
V_562 ,
V_562 ) ;
F_59 ( V_5 ) ;
V_47 = F_99 ( & V_56 -> V_29 ,
& V_563 , V_564 ,
F_5 ( V_564 ) ) ;
if ( V_47 < 0 )
goto V_565;
return V_47 ;
V_565:
F_61 ( V_5 ) ;
V_503:
V_502:
if ( V_5 -> V_7 . V_294 > 0 )
F_32 ( V_5 -> V_7 . V_294 , 0 ) ;
F_35 ( F_5 ( V_5 -> V_293 ) , V_5 -> V_293 ) ;
V_494:
if ( V_5 -> V_7 . V_294 > 0 )
F_100 ( V_5 -> V_7 . V_294 ) ;
V_491:
return V_47 ;
}
static int F_101 ( struct V_55 * V_566 )
{
struct V_4 * V_5 = F_102 ( V_566 ) ;
int V_12 ;
F_103 ( & V_566 -> V_29 ) ;
F_61 ( V_5 ) ;
if ( V_5 -> V_7 . V_294 > 0 ) {
F_32 ( V_5 -> V_7 . V_294 , 0 ) ;
F_100 ( V_5 -> V_7 . V_294 ) ;
}
for ( V_12 = 0 ; V_12 < F_5 ( V_5 -> V_293 ) ; V_12 ++ )
F_104 ( V_5 -> V_293 [ V_12 ] . V_500 ,
& V_5 -> V_495 [ V_12 ] ) ;
return 0 ;
}
