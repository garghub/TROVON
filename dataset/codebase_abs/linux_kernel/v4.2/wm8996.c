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
struct V_1 * V_2 = F_15 ( V_45 -> V_47 ) ;
int V_48 = 0 ;
switch ( V_46 ) {
case V_49 :
F_11 ( V_2 ) ;
break;
case V_50 :
F_13 ( V_2 ) ;
break;
default:
F_16 ( 1 , L_4 , V_46 ) ;
V_48 = - V_32 ;
}
return V_48 ;
}
static int F_17 ( struct V_44 * V_45 ,
struct V_33 * V_34 , int V_46 )
{
switch ( V_46 ) {
case V_51 :
F_12 ( 5 ) ;
break;
default:
F_16 ( 1 , L_4 , V_46 ) ;
}
return 0 ;
}
static int F_18 ( struct V_44 * V_45 ,
struct V_33 * V_34 , int V_46 )
{
struct V_1 * V_2 = F_15 ( V_45 -> V_47 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_46 ) {
case V_52 :
V_5 -> V_53 &= ~ V_45 -> V_54 ;
break;
case V_49 :
V_5 -> V_53 |= V_45 -> V_54 ;
break;
default:
F_16 ( 1 , L_4 , V_46 ) ;
return - V_32 ;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 , T_1 V_55 )
{
struct V_56 * V_57 = F_20 ( V_2 -> V_29 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_48 ;
unsigned long V_58 = 200 ;
F_21 ( V_2 , V_59 , V_55 ) ;
do {
if ( V_57 -> V_60 ) {
V_58 = F_22 ( & V_5 -> V_61 ,
F_23 ( 200 ) ) ;
if ( V_58 == 0 )
F_24 ( V_2 -> V_29 , L_5 ) ;
} else {
F_12 ( 1 ) ;
V_58 -- ;
}
V_48 = F_3 ( V_2 , V_59 ) ;
F_4 ( V_2 -> V_29 , L_6 , V_48 ) ;
} while ( V_58 && V_48 & V_55 );
if ( V_58 == 0 )
F_24 ( V_2 -> V_29 , L_7 , V_55 ) ;
else
F_4 ( V_2 -> V_29 , L_8 , V_55 ) ;
}
static void F_25 ( struct V_62 * V_47 ,
enum V_63 V_46 , int V_64 )
{
struct V_1 * V_2 = F_15 ( V_47 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_65 , V_55 ;
if ( V_5 -> V_66 ) {
F_4 ( V_2 -> V_29 , L_9 ,
V_5 -> V_66 ) ;
F_19 ( V_2 , V_5 -> V_66
<< V_67 ) ;
V_5 -> V_66 = 0 ;
}
if ( V_5 -> V_53 != V_5 -> V_68 ) {
F_4 ( V_2 -> V_29 , L_10 ,
V_5 -> V_68 , V_5 -> V_53 ) ;
V_65 = 0 ;
V_55 = 0 ;
if ( V_5 -> V_53 & V_69 ) {
V_65 |= V_70 | V_71 ;
V_55 |= V_70 | V_71 ;
} else {
V_55 |= V_70 |
V_71 |
V_72 ;
}
if ( V_5 -> V_53 & V_73 ) {
V_65 |= V_74 | V_75 ;
V_55 |= V_74 | V_75 ;
} else {
V_55 |= V_74 |
V_75 |
V_76 ;
}
F_6 ( V_2 , V_77 , V_55 , V_65 ) ;
V_65 = 0 ;
V_55 = 0 ;
if ( V_5 -> V_53 & V_78 ) {
V_65 |= V_79 | V_80 ;
V_55 |= V_79 | V_80 ;
} else {
V_55 |= V_79 |
V_80 |
V_81 ;
}
if ( V_5 -> V_53 & V_82 ) {
V_65 |= V_83 | V_84 ;
V_55 |= V_83 | V_84 ;
} else {
V_55 |= V_83 |
V_84 |
V_85 ;
}
F_6 ( V_2 , V_86 , V_55 , V_65 ) ;
V_5 -> V_68 = V_5 -> V_53 ;
}
}
static int F_26 ( struct V_44 * V_45 ,
struct V_33 * V_34 , int V_46 )
{
struct V_1 * V_2 = F_15 ( V_45 -> V_47 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_46 ) {
case V_51 :
V_5 -> V_66 |= 1 << V_45 -> V_54 ;
break;
default:
F_16 ( 1 , L_4 , V_46 ) ;
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
case V_59 :
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
int V_48 ;
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
if ( F_31 ( V_2 ) == V_291 ) {
V_48 = F_32 ( F_5 ( V_5 -> V_292 ) ,
V_5 -> V_292 ) ;
if ( V_48 != 0 ) {
F_24 ( V_2 -> V_29 ,
L_12 ,
V_48 ) ;
return V_48 ;
}
if ( V_5 -> V_7 . V_293 >= 0 ) {
F_33 ( V_5 -> V_7 . V_293 ,
1 ) ;
F_12 ( 5 ) ;
}
F_34 ( V_5 -> V_294 , false ) ;
F_35 ( V_5 -> V_294 ) ;
}
F_6 ( V_2 , V_109 ,
V_288 , V_288 ) ;
F_6 ( V_2 , V_110 ,
V_289 , V_289 ) ;
break;
case V_291 :
F_34 ( V_5 -> V_294 , true ) ;
if ( V_5 -> V_7 . V_293 >= 0 ) {
F_33 ( V_5 -> V_7 . V_293 , 0 ) ;
F_34 ( V_5 -> V_294 , true ) ;
}
F_36 ( F_5 ( V_5 -> V_292 ) ,
V_5 -> V_292 ) ;
break;
}
return 0 ;
}
static int F_37 ( struct V_295 * V_296 , unsigned int V_297 )
{
struct V_1 * V_2 = V_296 -> V_2 ;
int V_298 = 0 ;
int V_299 = 0 ;
int V_300 = 0 ;
int V_301 = 0 ;
int V_302 , V_279 , V_303 , V_304 ;
switch ( V_296 -> V_37 ) {
case 0 :
V_302 = V_145 ;
V_279 = V_146 ;
V_303 = V_148 ;
V_304 = V_150 ;
break;
case 1 :
V_302 = V_168 ;
V_279 = V_169 ;
V_303 = V_171 ;
V_304 = V_173 ;
break;
default:
F_16 ( 1 , L_13 , V_296 -> V_37 ) ;
return - V_32 ;
}
switch ( V_297 & V_305 ) {
case V_306 :
break;
case V_307 :
V_299 |= V_308 ;
break;
case V_309 :
V_300 |= V_310 ;
V_301 |= V_311 ;
break;
case V_312 :
V_299 |= V_308 ;
V_300 |= V_310 ;
V_301 |= V_311 ;
break;
}
switch ( V_297 & V_313 ) {
case V_314 :
break;
case V_315 :
V_300 |= V_316 ;
V_301 |= V_317 ;
break;
case V_318 :
V_299 |= V_319 ;
break;
case V_320 :
V_299 |= V_319 ;
V_300 |= V_316 ;
V_301 |= V_317 ;
break;
default:
return - V_32 ;
}
switch ( V_297 & V_321 ) {
case V_322 :
break;
case V_323 :
V_298 |= 1 ;
break;
case V_324 :
V_298 |= 2 ;
break;
case V_325 :
V_298 |= 3 ;
break;
default:
return - V_32 ;
}
F_6 ( V_2 , V_302 , V_326 , V_298 ) ;
F_6 ( V_2 , V_279 ,
V_308 | V_319 ,
V_299 ) ;
F_6 ( V_2 , V_303 ,
V_310 |
V_316 ,
V_300 ) ;
F_6 ( V_2 , V_304 ,
V_311 |
V_317 ,
V_301 ) ;
return 0 ;
}
static int F_38 ( struct V_327 * V_328 ,
struct V_329 * V_330 ,
struct V_295 * V_296 )
{
struct V_1 * V_2 = V_296 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_331 , V_12 , V_278 , V_9 ;
int V_332 = 0 ;
int V_333 = 0 ;
int V_334 = 0 ;
int V_335 , V_336 , V_337 ;
switch ( V_296 -> V_37 ) {
case 0 :
if ( V_328 -> V_338 == V_339 ||
( F_3 ( V_2 , V_259 ) ) & V_340 ) {
V_335 = V_153 ;
V_336 = V_149 ;
} else {
V_335 = V_151 ;
V_336 = V_147 ;
}
V_337 = 0 ;
break;
case 1 :
if ( V_328 -> V_338 == V_339 ||
( F_3 ( V_2 , V_260 ) ) & V_341 ) {
V_335 = V_176 ;
V_336 = V_172 ;
} else {
V_335 = V_174 ;
V_336 = V_170 ;
}
V_337 = V_342 ;
break;
default:
F_16 ( 1 , L_13 , V_296 -> V_37 ) ;
return - V_32 ;
}
V_278 = F_39 ( V_330 ) ;
if ( V_278 < 0 ) {
F_24 ( V_2 -> V_29 , L_14 , V_278 ) ;
return V_278 ;
}
V_5 -> V_278 [ V_296 -> V_37 ] = V_278 ;
V_5 -> V_28 [ V_296 -> V_37 ] = F_40 ( V_330 ) ;
V_331 = F_41 ( F_42 ( V_330 ) ) ;
if ( V_331 < 0 )
return V_331 ;
V_332 |= ( V_331 << V_343 ) | V_331 ;
V_9 = 0 ;
for ( V_12 = 0 ; V_12 < F_5 ( V_344 ) ; V_12 ++ ) {
if ( abs ( V_344 [ V_12 ] - F_40 ( V_330 ) ) <
abs ( V_344 [ V_9 ] - F_40 ( V_330 ) ) )
V_9 = V_12 ;
}
V_334 |= V_12 << V_337 ;
F_29 ( V_2 ) ;
V_333 = V_278 / F_40 ( V_330 ) ;
F_4 ( V_296 -> V_29 , L_15 ,
V_333 , V_278 / V_333 ) ;
F_6 ( V_2 , V_335 ,
V_345 |
V_346 ,
V_332 ) ;
F_6 ( V_2 , V_336 , V_347 ,
V_333 ) ;
F_6 ( V_2 , V_133 ,
V_348 << V_337 , V_334 ) ;
return 0 ;
}
static int F_43 ( struct V_295 * V_296 ,
int V_349 , unsigned int V_350 , int V_351 )
{
struct V_1 * V_2 = V_296 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_352 = 0 ;
int V_353 = 0 ;
int V_354 = V_355 ;
int V_356 ;
int V_357 ;
if ( V_350 == V_5 -> V_280 && V_349 == V_5 -> V_358 )
return 0 ;
V_357 = F_3 ( V_2 , V_132 ) & V_359 ;
F_6 ( V_2 , V_132 ,
V_359 , 0 ) ;
switch ( V_349 ) {
case V_360 :
V_5 -> V_280 = V_350 ;
V_356 = 0 ;
break;
case V_361 :
V_5 -> V_280 = V_350 ;
V_356 = 1 ;
break;
case V_362 :
V_5 -> V_280 = V_350 ;
V_356 = 2 ;
break;
default:
F_24 ( V_2 -> V_29 , L_16 , V_349 ) ;
return - V_32 ;
}
switch ( V_5 -> V_280 ) {
case 5644800 :
case 6144000 :
F_6 ( V_2 , V_136 ,
V_363 , 0 ) ;
break;
case 22579200 :
case 24576000 :
V_353 = V_364 ;
V_5 -> V_280 /= 2 ;
case 11289600 :
case 12288000 :
F_6 ( V_2 , V_136 ,
V_363 , V_363 ) ;
break;
case 32000 :
case 32768 :
V_352 = V_365 ;
V_354 = 0 ;
break;
default:
F_44 ( V_2 -> V_29 , L_17 ,
V_5 -> V_280 ) ;
return - V_32 ;
}
F_29 ( V_2 ) ;
F_6 ( V_2 , V_132 ,
V_366 | V_367 ,
V_356 << V_368 | V_353 ) ;
F_6 ( V_2 , V_134 , V_365 , V_352 ) ;
F_6 ( V_2 , V_129 ,
V_355 , V_354 ) ;
F_6 ( V_2 , V_132 ,
V_359 , V_357 ) ;
V_5 -> V_358 = V_349 ;
return 0 ;
}
static int F_45 ( struct V_369 * V_370 , unsigned int V_371 ,
unsigned int V_372 )
{
unsigned int V_373 ;
unsigned int div ;
unsigned int V_374 , V_375 ;
int V_12 ;
div = 1 ;
V_370 -> V_376 = 0 ;
while ( ( V_371 / div ) > 13500000 ) {
div *= 2 ;
V_370 -> V_376 ++ ;
if ( div > 8 ) {
F_46 ( L_18 ,
V_371 ) ;
return - V_32 ;
}
}
F_47 ( L_19 , V_371 , V_372 ) ;
V_371 /= div ;
if ( V_371 >= 3000000 )
V_370 -> V_377 = 5 ;
else
V_370 -> V_377 = 0 ;
if ( V_371 >= 48000 )
V_370 -> V_378 = 0 ;
else
V_370 -> V_378 = 1 ;
div = 2 ;
while ( V_372 * div < 90000000 ) {
div ++ ;
if ( div > 64 ) {
F_46 ( L_20 ,
V_372 ) ;
return - V_32 ;
}
}
V_373 = V_372 * div ;
V_370 -> V_379 = div - 1 ;
F_47 ( L_21 , V_373 ) ;
for ( V_12 = 0 ; V_12 < F_5 ( V_380 ) ; V_12 ++ ) {
if ( V_380 [ V_12 ] . V_381 <= V_371 && V_371 <= V_380 [ V_12 ] . V_382 ) {
V_370 -> V_383 = V_380 [ V_12 ] . V_383 ;
V_374 = V_380 [ V_12 ] . V_384 ;
break;
}
}
if ( V_12 == F_5 ( V_380 ) ) {
F_46 ( L_22 , V_371 ) ;
return - V_32 ;
}
V_370 -> V_385 = V_373 / ( V_374 * V_371 ) ;
if ( V_373 % V_371 == 0 ) {
V_370 -> V_386 = 0 ;
V_370 -> V_387 = 0 ;
} else {
V_375 = F_48 ( V_373 , V_374 * V_371 ) ;
V_370 -> V_386 = ( V_373 - ( V_370 -> V_385 * V_374 * V_371 ) )
/ V_375 ;
V_370 -> V_387 = ( V_374 * V_371 ) / V_375 ;
}
F_47 ( L_23 ,
V_370 -> V_385 , V_370 -> V_386 , V_370 -> V_387 ) ;
F_47 ( L_24 ,
V_370 -> V_383 , V_370 -> V_379 ,
V_370 -> V_376 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , int V_388 , int V_389 ,
unsigned int V_371 , unsigned int V_372 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_56 * V_57 = F_20 ( V_2 -> V_29 ) ;
struct V_369 V_370 ;
unsigned long V_58 , V_390 ;
int V_48 , V_88 , V_391 ;
if ( V_389 == V_5 -> V_392 && V_371 == V_5 -> V_393 &&
V_372 == V_5 -> V_394 )
return 0 ;
if ( V_372 == 0 ) {
F_4 ( V_2 -> V_29 , L_25 ) ;
V_5 -> V_393 = 0 ;
V_5 -> V_394 = 0 ;
F_6 ( V_2 , V_137 ,
V_395 , 0 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
V_48 = F_45 ( & V_370 , V_371 , V_372 ) ;
if ( V_48 != 0 )
return V_48 ;
switch ( V_389 ) {
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
F_24 ( V_2 -> V_29 , L_26 , V_48 ) ;
return - V_32 ;
}
V_88 |= V_370 . V_376 << V_400 ;
V_88 |= V_370 . V_378 << V_401 ;
F_6 ( V_2 , V_141 ,
V_402 | V_403 |
V_404 , V_88 ) ;
V_88 = 0 ;
if ( V_370 . V_386 || V_370 . V_387 )
V_88 |= V_405 | ( 3 << V_406 ) ;
else
V_88 |= 1 << V_406 ;
F_21 ( V_2 , V_144 , V_88 ) ;
F_6 ( V_2 , V_138 ,
V_407 |
V_408 ,
( V_370 . V_379 << V_409 ) |
( V_370 . V_383 ) ) ;
F_21 ( V_2 , V_139 , V_370 . V_386 ) ;
F_6 ( V_2 , V_140 ,
V_410 | V_411 ,
( V_370 . V_385 << V_412 ) |
V_370 . V_377 ) ;
F_21 ( V_2 , V_143 , V_370 . V_387 ) ;
V_48 = F_3 ( V_2 , V_137 ) ;
if ( ! ( V_48 & V_395 ) )
F_11 ( V_2 ) ;
F_50 ( & V_5 -> V_413 ) ;
F_6 ( V_2 , V_137 ,
V_395 , V_395 ) ;
F_21 ( V_2 , V_142 , V_414 ) ;
if ( V_371 > 1000000 )
V_58 = F_51 ( 300 ) ;
else
V_58 = F_23 ( 2 ) ;
if ( V_57 -> V_60 )
V_58 *= 10 ;
else
V_58 = V_58 / 2 ? : 1 ;
for ( V_391 = 0 ; V_391 < 10 ; V_391 ++ ) {
V_390 = F_22 ( & V_5 -> V_413 ,
V_58 ) ;
if ( V_390 != 0 ) {
F_52 ( ! V_57 -> V_60 ) ;
V_48 = 1 ;
break;
}
V_48 = F_3 ( V_2 , V_268 ) ;
if ( V_48 & V_415 )
break;
}
if ( V_391 == 10 ) {
F_24 ( V_2 -> V_29 , L_27 ) ;
V_48 = - V_416 ;
}
F_4 ( V_2 -> V_29 , L_28 , V_371 , V_372 ) ;
V_5 -> V_393 = V_371 ;
V_5 -> V_394 = V_372 ;
V_5 -> V_392 = V_389 ;
return V_48 ;
}
static inline struct V_4 * F_53 ( struct V_417 * V_418 )
{
return F_54 ( V_418 , struct V_4 , V_417 ) ;
}
static void F_55 ( struct V_417 * V_418 , unsigned V_419 , int V_38 )
{
struct V_4 * V_5 = F_53 ( V_418 ) ;
F_56 ( V_5 -> V_294 , V_259 + V_419 ,
V_420 , ! ! V_38 << V_421 ) ;
}
static int F_57 ( struct V_417 * V_418 ,
unsigned V_419 , int V_38 )
{
struct V_4 * V_5 = F_53 ( V_418 ) ;
int V_65 ;
V_65 = ( 1 << V_422 ) | ( ! ! V_38 << V_421 ) ;
return F_56 ( V_5 -> V_294 , V_259 + V_419 ,
V_340 | V_423 |
V_420 , V_65 ) ;
}
static int F_58 ( struct V_417 * V_418 , unsigned V_419 )
{
struct V_4 * V_5 = F_53 ( V_418 ) ;
unsigned int V_88 ;
int V_48 ;
V_48 = F_59 ( V_5 -> V_294 , V_259 + V_419 , & V_88 ) ;
if ( V_48 < 0 )
return V_48 ;
return ( V_88 & V_420 ) != 0 ;
}
static int F_60 ( struct V_417 * V_418 , unsigned V_419 )
{
struct V_4 * V_5 = F_53 ( V_418 ) ;
return F_56 ( V_5 -> V_294 , V_259 + V_419 ,
V_340 | V_423 ,
( 1 << V_422 ) |
( 1 << V_424 ) ) ;
}
static void F_61 ( struct V_4 * V_5 )
{
int V_48 ;
V_5 -> V_417 = V_425 ;
V_5 -> V_417 . V_426 = 5 ;
V_5 -> V_417 . V_29 = V_5 -> V_29 ;
if ( V_5 -> V_7 . V_427 )
V_5 -> V_417 . V_8 = V_5 -> V_7 . V_427 ;
else
V_5 -> V_417 . V_8 = - 1 ;
V_48 = F_62 ( & V_5 -> V_417 ) ;
if ( V_48 != 0 )
F_24 ( V_5 -> V_29 , L_29 , V_48 ) ;
}
static void F_63 ( struct V_4 * V_5 )
{
F_64 ( & V_5 -> V_417 ) ;
}
static void F_61 ( struct V_4 * V_5 )
{
}
static void F_63 ( struct V_4 * V_5 )
{
}
int F_65 ( struct V_1 * V_2 , struct V_428 * V_429 ,
T_2 V_430 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_62 * V_47 = F_66 ( V_2 ) ;
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
F_67 ( V_47 ) ;
F_68 ( V_47 , L_30 ) ;
F_68 ( V_47 , L_31 ) ;
F_69 ( V_47 ) ;
F_6 ( V_2 , V_117 ,
V_435 , V_435 ) ;
F_6 ( V_2 , V_117 ,
V_436 ,
V_436 ) ;
F_6 ( V_2 , V_270 ,
V_437 | V_438 , 0 ) ;
return 0 ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_62 * V_47 = F_66 ( V_2 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_65 , V_88 , V_439 ;
V_439 = V_440 ;
V_88 = F_3 ( V_2 , V_116 ) ;
if ( V_88 < 0 ) {
F_24 ( V_2 -> V_29 , L_32 ) ;
goto V_441;
}
if ( ! ( V_88 & V_442 ) ) {
F_24 ( V_2 -> V_29 , L_33 ) ;
goto V_441;
}
V_65 = V_88 & V_443 ;
F_4 ( V_2 -> V_29 , L_34 , V_65 ) ;
if ( V_65 >= 126 )
V_439 = V_444 ;
else
V_439 = V_440 ;
V_441:
if ( V_5 -> V_445 )
V_439 |= V_446 ;
F_71 ( V_5 -> V_429 , V_439 ,
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
F_72 ( V_47 , L_35 ) ;
F_73 ( V_47 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_62 * V_47 = F_66 ( V_2 ) ;
F_6 ( V_2 , V_77 ,
V_70 |
V_74 ,
V_70 |
V_74 ) ;
F_75 ( V_47 , L_35 ) ;
F_73 ( V_47 ) ;
F_6 ( V_2 , V_117 , V_435 , 0 ) ;
F_6 ( V_2 , V_113 ,
V_449 , 1 ) ;
F_6 ( V_2 , V_115 ,
V_450 , V_450 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_29 , L_36 ) ;
F_74 ( V_2 ) ;
F_6 ( V_2 , V_117 ,
V_436 |
V_451 ,
7 << V_452 |
7 << V_453 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_65 , V_88 ;
V_65 = F_3 ( V_2 , V_119 ) ;
F_4 ( V_2 -> V_29 , L_37 , V_65 ) ;
if ( ! ( V_65 & V_454 ) ) {
F_44 ( V_2 -> V_29 , L_38 ) ;
return;
}
if ( ! ( V_65 & V_455 ) ) {
F_4 ( V_2 -> V_29 , L_39 ) ;
V_5 -> V_445 = false ;
V_5 -> V_431 = true ;
V_5 -> V_432 = 0 ;
F_71 ( V_5 -> V_429 , 0 ,
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
F_4 ( V_2 -> V_29 , L_40 ) ;
V_5 -> V_445 = true ;
F_74 ( V_2 ) ;
F_6 ( V_2 , V_117 ,
V_436 |
V_451 ,
5 << V_452 |
7 << V_453 ) ;
} else {
F_4 ( V_2 -> V_29 , L_41 ) ;
F_71 ( V_5 -> V_429 , 0 , V_456 ) ;
}
return;
}
if ( V_5 -> V_431 && ( V_65 & 0x3f0 ) ) {
V_5 -> V_432 ++ ;
if ( V_5 -> V_432 > 1 ) {
F_76 ( V_2 ) ;
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
F_4 ( V_2 -> V_29 , L_42 ,
( V_88 & V_458 ) != 0 ) ;
return;
}
if ( V_65 & 0x3fc ) {
if ( V_5 -> V_445 ) {
F_4 ( V_2 -> V_29 , L_43 ) ;
F_71 ( V_5 -> V_429 , V_456 ,
V_456 ) ;
} else if ( V_5 -> V_431 ) {
F_76 ( V_2 ) ;
}
}
}
static T_3 F_78 ( int V_60 , void * V_460 )
{
struct V_1 * V_2 = V_460 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_461 ;
V_461 = F_3 ( V_2 , V_267 ) ;
if ( V_461 < 0 ) {
F_24 ( V_2 -> V_29 , L_44 ,
V_461 ) ;
return V_462 ;
}
V_461 &= ~ F_3 ( V_2 , V_270 ) ;
if ( ! V_461 )
return V_462 ;
F_21 ( V_2 , V_267 , V_461 ) ;
if ( V_461 & ( V_463 | V_464 ) ) {
F_4 ( V_2 -> V_29 , L_45 ) ;
F_79 ( & V_5 -> V_61 ) ;
}
if ( V_461 & V_465 )
F_24 ( V_2 -> V_29 , L_46 ) ;
if ( V_461 & V_466 ) {
F_4 ( V_2 -> V_29 , L_47 ) ;
F_79 ( & V_5 -> V_413 ) ;
}
if ( V_461 & V_467 )
F_77 ( V_2 ) ;
if ( V_461 & V_438 )
F_70 ( V_2 ) ;
return V_468 ;
}
static T_3 F_80 ( int V_60 , void * V_460 )
{
T_3 V_48 = V_462 ;
T_3 V_65 ;
do {
V_65 = F_78 ( V_60 , V_460 ) ;
if ( V_65 != V_462 )
V_48 = V_65 ;
} while ( V_65 != V_462 );
return V_48 ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_469 V_470 [] = {
F_82 ( L_2 ,
V_5 -> V_471 ,
F_10 ,
F_8 ) ,
F_82 ( L_3 ,
V_5 -> V_471 ,
F_10 ,
F_8 ) ,
} ;
int V_48 , V_12 , V_472 ;
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
V_473 = F_83 ( V_5 -> V_26 ,
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
F_4 ( V_2 -> V_29 , L_48 ,
V_5 -> V_15 ) ;
V_5 -> V_471 . V_475 = V_5 -> V_15 ;
V_5 -> V_471 . V_476 = V_5 -> V_26 ;
V_48 = F_84 ( V_2 , V_470 , F_5 ( V_470 ) ) ;
if ( V_48 != 0 )
F_24 ( V_2 -> V_29 ,
L_49 , V_48 ) ;
}
static int F_85 ( struct V_1 * V_2 )
{
int V_48 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_56 * V_57 = F_20 ( V_2 -> V_29 ) ;
int V_477 ;
V_5 -> V_2 = V_2 ;
F_86 ( & V_5 -> V_61 ) ;
F_86 ( & V_5 -> V_413 ) ;
if ( V_5 -> V_7 . V_23 )
F_81 ( V_2 ) ;
else
F_84 ( V_2 , V_478 ,
F_5 ( V_478 ) ) ;
if ( V_57 -> V_60 ) {
if ( V_5 -> V_7 . V_477 )
V_477 = V_5 -> V_7 . V_477 ;
else
V_477 = V_479 ;
V_477 |= V_480 ;
if ( V_477 & ( V_481 | V_482 ) )
V_48 = F_87 ( V_57 -> V_60 , NULL ,
F_80 ,
V_477 | V_480 ,
L_50 , V_2 ) ;
else
V_48 = F_87 ( V_57 -> V_60 , NULL , F_78 ,
V_477 | V_480 ,
L_50 , V_2 ) ;
if ( V_48 == 0 ) {
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
F_24 ( V_2 -> V_29 , L_51 ,
V_48 ) ;
return V_48 ;
}
}
return 0 ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = F_20 ( V_2 -> V_29 ) ;
F_6 ( V_2 , V_271 ,
V_483 , V_483 ) ;
if ( V_57 -> V_60 )
F_89 ( V_57 -> V_60 , V_2 ) ;
return 0 ;
}
static int F_90 ( struct V_56 * V_57 ,
const struct V_488 * V_37 )
{
struct V_4 * V_5 ;
int V_48 , V_12 ;
unsigned int V_88 ;
V_5 = F_91 ( & V_57 -> V_29 , sizeof( struct V_4 ) ,
V_474 ) ;
if ( V_5 == NULL )
return - V_489 ;
F_92 ( V_57 , V_5 ) ;
V_5 -> V_29 = & V_57 -> V_29 ;
if ( F_93 ( & V_57 -> V_29 ) )
memcpy ( & V_5 -> V_7 , F_93 ( & V_57 -> V_29 ) ,
sizeof( V_5 -> V_7 ) ) ;
if ( V_5 -> V_7 . V_293 > 0 ) {
V_48 = F_94 ( V_5 -> V_7 . V_293 ,
V_490 , L_52 ) ;
if ( V_48 < 0 ) {
F_24 ( & V_57 -> V_29 , L_53 ,
V_5 -> V_7 . V_293 , V_48 ) ;
goto V_491;
}
}
for ( V_12 = 0 ; V_12 < F_5 ( V_5 -> V_292 ) ; V_12 ++ )
V_5 -> V_292 [ V_12 ] . V_492 = V_493 [ V_12 ] ;
V_48 = F_95 ( & V_57 -> V_29 , F_5 ( V_5 -> V_292 ) ,
V_5 -> V_292 ) ;
if ( V_48 != 0 ) {
F_24 ( & V_57 -> V_29 , L_54 , V_48 ) ;
goto V_494;
}
V_5 -> V_495 [ 0 ] . V_496 = V_497 ;
V_5 -> V_495 [ 1 ] . V_496 = V_498 ;
V_5 -> V_495 [ 2 ] . V_496 = V_499 ;
for ( V_12 = 0 ; V_12 < F_5 ( V_5 -> V_292 ) ; V_12 ++ ) {
V_48 = F_96 ( V_5 -> V_292 [ V_12 ] . V_500 ,
& V_5 -> V_495 [ V_12 ] ) ;
if ( V_48 != 0 ) {
F_24 ( & V_57 -> V_29 ,
L_55 ,
V_48 ) ;
}
}
V_48 = F_32 ( F_5 ( V_5 -> V_292 ) ,
V_5 -> V_292 ) ;
if ( V_48 != 0 ) {
F_24 ( & V_57 -> V_29 , L_12 , V_48 ) ;
goto V_494;
}
if ( V_5 -> V_7 . V_293 > 0 ) {
F_33 ( V_5 -> V_7 . V_293 , 1 ) ;
F_12 ( 5 ) ;
}
V_5 -> V_294 = F_97 ( V_57 , & V_501 ) ;
if ( F_98 ( V_5 -> V_294 ) ) {
V_48 = F_99 ( V_5 -> V_294 ) ;
F_24 ( & V_57 -> V_29 , L_56 , V_48 ) ;
goto V_502;
}
V_48 = F_59 ( V_5 -> V_294 , V_89 , & V_88 ) ;
if ( V_48 < 0 ) {
F_24 ( & V_57 -> V_29 , L_57 , V_48 ) ;
goto V_503;
}
if ( V_88 != 0x8915 ) {
F_24 ( & V_57 -> V_29 , L_58 , V_88 ) ;
V_48 = - V_32 ;
goto V_503;
}
V_48 = F_59 ( V_5 -> V_294 , V_128 , & V_88 ) ;
if ( V_48 < 0 ) {
F_24 ( & V_57 -> V_29 , L_59 ,
V_48 ) ;
goto V_503;
}
F_100 ( & V_57 -> V_29 , L_60 ,
( V_88 & V_504 ) + 'A' ) ;
if ( V_5 -> V_7 . V_293 > 0 ) {
F_33 ( V_5 -> V_7 . V_293 , 0 ) ;
F_34 ( V_5 -> V_294 , true ) ;
} else {
V_48 = F_101 ( V_5 -> V_294 , V_89 ,
0x8915 ) ;
if ( V_48 != 0 ) {
F_24 ( & V_57 -> V_29 , L_61 , V_48 ) ;
goto V_503;
}
}
F_36 ( F_5 ( V_5 -> V_292 ) , V_5 -> V_292 ) ;
F_56 ( V_5 -> V_294 , V_98 ,
V_505 | V_506 ,
V_5 -> V_7 . V_507 << V_508 |
V_5 -> V_7 . V_509 ) ;
for ( V_12 = 0 ; V_12 < F_5 ( V_5 -> V_7 . V_510 ) ; V_12 ++ ) {
if ( ! V_5 -> V_7 . V_510 [ V_12 ] )
continue;
F_101 ( V_5 -> V_294 , V_259 + V_12 ,
V_5 -> V_7 . V_510 [ V_12 ] & 0xffff ) ;
}
if ( V_5 -> V_7 . V_511 )
F_56 ( V_5 -> V_294 ,
V_274 ,
V_512 |
V_513 ,
V_5 -> V_7 . V_511 ) ;
F_56 ( V_5 -> V_294 , V_114 ,
V_459 | V_457 |
V_458 , V_5 -> V_7 . V_514 ) ;
F_56 ( V_5 -> V_294 , V_96 ,
V_515 , V_515 ) ;
F_56 ( V_5 -> V_294 , V_97 ,
V_515 , V_515 ) ;
F_56 ( V_5 -> V_294 , V_101 ,
V_516 , V_516 ) ;
F_56 ( V_5 -> V_294 , V_102 ,
V_516 , V_516 ) ;
F_56 ( V_5 -> V_294 , V_103 ,
V_517 , V_517 ) ;
F_56 ( V_5 -> V_294 , V_104 ,
V_517 , V_517 ) ;
F_56 ( V_5 -> V_294 , V_105 ,
V_516 , V_516 ) ;
F_56 ( V_5 -> V_294 , V_106 ,
V_516 , V_516 ) ;
F_56 ( V_5 -> V_294 , V_107 ,
V_517 , V_517 ) ;
F_56 ( V_5 -> V_294 , V_108 ,
V_517 , V_517 ) ;
F_56 ( V_5 -> V_294 , V_183 ,
V_518 , V_518 ) ;
F_56 ( V_5 -> V_294 , V_184 ,
V_518 , V_518 ) ;
F_56 ( V_5 -> V_294 , V_213 ,
V_519 , V_519 ) ;
F_56 ( V_5 -> V_294 , V_214 ,
V_519 , V_519 ) ;
F_56 ( V_5 -> V_294 , V_185 ,
V_520 , V_520 ) ;
F_56 ( V_5 -> V_294 , V_186 ,
V_520 , V_520 ) ;
F_56 ( V_5 -> V_294 , V_215 ,
V_521 , V_521 ) ;
F_56 ( V_5 -> V_294 , V_216 ,
V_521 , V_521 ) ;
F_56 ( V_5 -> V_294 ,
V_160 ,
V_522 |
V_523 ,
1 << V_524 | 0 ) ;
F_56 ( V_5 -> V_294 ,
V_161 ,
V_525 |
V_526 ,
1 << V_527 | 1 ) ;
F_56 ( V_5 -> V_294 ,
V_162 ,
V_528 |
V_529 ,
1 << V_530 | 0 ) ;
F_56 ( V_5 -> V_294 ,
V_163 ,
V_531 |
V_523 ,
1 << V_532 | 1 ) ;
F_56 ( V_5 -> V_294 ,
V_164 ,
V_533 |
V_523 ,
1 << V_534 | 0 ) ;
F_56 ( V_5 -> V_294 ,
V_165 ,
V_535 |
V_523 ,
1 << V_536 | 1 ) ;
F_56 ( V_5 -> V_294 ,
V_179 ,
V_537 |
V_538 ,
1 << V_539 | 0 ) ;
F_56 ( V_5 -> V_294 ,
V_180 ,
V_540 |
V_541 ,
1 << V_542 | 1 ) ;
F_56 ( V_5 -> V_294 ,
V_154 ,
V_543 |
V_544 ,
1 << V_545 | 0 ) ;
F_56 ( V_5 -> V_294 ,
V_155 ,
V_546 |
V_544 ,
1 << V_547 | 1 ) ;
F_56 ( V_5 -> V_294 ,
V_156 ,
V_548 |
V_544 ,
1 << V_549 | 0 ) ;
F_56 ( V_5 -> V_294 ,
V_157 ,
V_550 |
V_544 ,
1 << V_551 | 1 ) ;
F_56 ( V_5 -> V_294 ,
V_158 ,
V_552 |
V_544 ,
1 << V_553 | 0 ) ;
F_56 ( V_5 -> V_294 ,
V_159 ,
V_554 |
V_544 ,
1 << V_555 | 1 ) ;
F_56 ( V_5 -> V_294 ,
V_177 ,
V_556 |
V_557 ,
1 << V_558 | 0 ) ;
F_56 ( V_5 -> V_294 ,
V_155 ,
V_559 |
V_560 ,
1 << V_547 | 1 ) ;
V_48 = F_59 ( V_5 -> V_294 , V_259 , & V_88 ) ;
if ( V_48 != 0 ) {
F_24 ( & V_57 -> V_29 , L_62 , V_48 ) ;
goto V_503;
}
if ( V_88 & V_340 )
F_56 ( V_5 -> V_294 , V_148 ,
V_561 ,
V_561 ) ;
V_48 = F_59 ( V_5 -> V_294 , V_260 , & V_88 ) ;
if ( V_48 != 0 ) {
F_24 ( & V_57 -> V_29 , L_63 , V_48 ) ;
goto V_503;
}
if ( V_88 & V_341 )
F_56 ( V_5 -> V_294 , V_171 ,
V_562 ,
V_562 ) ;
F_61 ( V_5 ) ;
V_48 = F_102 ( & V_57 -> V_29 ,
& V_563 , V_564 ,
F_5 ( V_564 ) ) ;
if ( V_48 < 0 )
goto V_565;
return V_48 ;
V_565:
F_63 ( V_5 ) ;
V_503:
V_502:
if ( V_5 -> V_7 . V_293 > 0 )
F_33 ( V_5 -> V_7 . V_293 , 0 ) ;
F_36 ( F_5 ( V_5 -> V_292 ) , V_5 -> V_292 ) ;
V_494:
if ( V_5 -> V_7 . V_293 > 0 )
F_103 ( V_5 -> V_7 . V_293 ) ;
V_491:
return V_48 ;
}
static int F_104 ( struct V_56 * V_566 )
{
struct V_4 * V_5 = F_105 ( V_566 ) ;
int V_12 ;
F_106 ( & V_566 -> V_29 ) ;
F_63 ( V_5 ) ;
if ( V_5 -> V_7 . V_293 > 0 ) {
F_33 ( V_5 -> V_7 . V_293 , 0 ) ;
F_103 ( V_5 -> V_7 . V_293 ) ;
}
for ( V_12 = 0 ; V_12 < F_5 ( V_5 -> V_292 ) ; V_12 ++ )
F_107 ( V_5 -> V_292 [ V_12 ] . V_500 ,
& V_5 -> V_495 [ V_12 ] ) ;
return 0 ;
}
