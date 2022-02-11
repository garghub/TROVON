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
int V_220 = F_6 ( V_219 -> V_221 ) ;
if ( V_220 < 0 )
F_7 ( V_217 -> V_2 , L_1 ) ;
else
F_8 ( V_219 -> V_222 , V_91 ,
V_223 , V_220 << V_224 ) ;
return V_220 ;
}
static int F_9 ( struct V_211 * V_225 ,
struct V_211 * V_226 )
{
struct V_218 * V_219 = F_5 ( V_225 -> V_217 ) ;
unsigned int V_227 ;
F_10 ( V_219 -> V_222 , V_119 , & V_227 ) ;
V_227 &= V_228 ;
if ( V_227 == V_229 )
return 1 ;
else
return 0 ;
}
static int F_11 ( struct V_211 * V_212 ,
struct V_213 * V_214 , int V_215 )
{
struct V_216 * V_217 = V_212 -> V_217 ;
struct V_218 * V_219 = F_5 ( V_217 ) ;
switch ( V_215 ) {
case V_230 :
F_8 ( V_219 -> V_222 , V_105 ,
V_231 , V_231 ) ;
break;
case V_232 :
F_8 ( V_219 -> V_222 , V_105 ,
V_231 , 0 ) ;
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
case V_230 :
F_8 ( V_219 -> V_222 , V_105 ,
V_233 , V_233 ) ;
break;
case V_232 :
F_8 ( V_219 -> V_222 , V_105 ,
V_233 , 0 ) ;
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
case V_230 :
F_8 ( V_219 -> V_222 , V_20 , 0x2 , 0x2 ) ;
F_8 ( V_219 -> V_222 , V_20 , 0x2 , 0x0 ) ;
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
case V_230 :
F_8 ( V_219 -> V_222 , V_21 , 0x2 , 0x2 ) ;
F_8 ( V_219 -> V_222 , V_21 , 0x2 , 0x0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_15 ( struct V_211 * V_212 ,
struct V_213 * V_214 , int V_215 )
{
struct V_216 * V_217 = V_212 -> V_217 ;
struct V_218 * V_219 = F_5 ( V_217 ) ;
switch ( V_215 ) {
case V_230 :
F_8 ( V_219 -> V_222 , V_105 ,
V_234 | V_235 |
V_236 , V_234 |
V_235 | V_236 ) ;
break;
case V_232 :
F_8 ( V_219 -> V_222 , V_105 ,
V_234 | V_235 |
V_236 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_16 ( struct V_237 * V_238 ,
struct V_239 * V_240 , struct V_241 * V_242 )
{
struct V_216 * V_217 = V_242 -> V_217 ;
struct V_218 * V_219 = F_5 ( V_217 ) ;
unsigned int V_243 = 0 , V_244 , V_245 ;
int V_246 , V_247 , V_248 ;
V_219 -> V_249 [ V_242 -> V_250 ] = F_17 ( V_240 ) ;
V_246 = F_18 ( V_219 -> V_221 , V_219 -> V_249 [ V_242 -> V_250 ] ) ;
if ( V_246 < 0 ) {
F_7 ( V_217 -> V_2 , L_2 ) ;
return - V_251 ;
}
V_248 = F_19 ( V_240 ) ;
if ( V_248 < 0 ) {
F_7 ( V_217 -> V_2 , L_3 , V_248 ) ;
return - V_251 ;
}
V_247 = V_248 > 32 ;
V_219 -> V_252 [ V_242 -> V_250 ] = V_219 -> V_249 [ V_242 -> V_250 ] * ( 32 << V_247 ) ;
F_20 ( V_242 -> V_2 , L_4 ,
V_219 -> V_252 [ V_242 -> V_250 ] , V_219 -> V_249 [ V_242 -> V_250 ] ) ;
F_20 ( V_242 -> V_2 , L_5 ,
V_247 , V_246 , V_242 -> V_250 ) ;
switch ( F_21 ( V_240 ) ) {
case 16 :
break;
case 20 :
V_243 |= V_253 ;
break;
case 24 :
V_243 |= V_254 ;
break;
case 8 :
V_243 |= V_255 ;
break;
default:
return - V_251 ;
}
switch ( V_242 -> V_250 ) {
case V_256 :
V_245 = V_257 ;
V_244 = V_246 << V_258 ;
F_8 ( V_219 -> V_222 , V_111 ,
V_259 , V_243 ) ;
F_8 ( V_219 -> V_222 , V_114 ,
V_245 , V_244 ) ;
break;
case V_260 :
V_245 = V_261 ;
V_244 = V_246 << V_262 ;
F_8 ( V_219 -> V_222 , V_112 ,
V_259 , V_243 ) ;
F_8 ( V_219 -> V_222 , V_114 ,
V_245 , V_244 ) ;
break;
case V_263 :
V_245 = V_264 | V_265 ;
V_244 = V_247 << V_266 |
V_246 << V_267 ;
F_8 ( V_219 -> V_222 , V_113 ,
V_259 , V_243 ) ;
F_8 ( V_219 -> V_222 , V_114 ,
V_245 , V_244 ) ;
break;
case V_268 :
V_245 = V_269 | V_270 ;
V_244 = V_247 << V_271 |
V_246 << V_272 ;
F_8 ( V_219 -> V_222 , V_110 ,
V_259 , V_243 ) ;
F_8 ( V_219 -> V_222 , V_114 ,
V_245 , V_244 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_22 ( struct V_241 * V_242 , unsigned int V_273 )
{
struct V_216 * V_217 = V_242 -> V_217 ;
struct V_218 * V_219 = F_5 ( V_217 ) ;
unsigned int V_274 = 0 ;
switch ( V_273 & V_275 ) {
case V_276 :
V_219 -> V_277 [ V_242 -> V_250 ] = 1 ;
break;
case V_278 :
V_274 |= V_279 ;
V_219 -> V_277 [ V_242 -> V_250 ] = 0 ;
break;
default:
return - V_251 ;
}
switch ( V_273 & V_280 ) {
case V_281 :
break;
case V_282 :
V_274 |= V_283 ;
break;
default:
return - V_251 ;
}
switch ( V_273 & V_284 ) {
case V_285 :
break;
case V_286 :
V_274 |= V_287 ;
break;
case V_288 :
V_274 |= V_289 ;
break;
case V_290 :
V_274 |= V_291 ;
break;
default:
return - V_251 ;
}
switch ( V_242 -> V_250 ) {
case V_256 :
F_8 ( V_219 -> V_222 , V_111 ,
V_292 | V_293 |
V_294 , V_274 ) ;
break;
case V_260 :
F_8 ( V_219 -> V_222 , V_112 ,
V_292 | V_293 |
V_294 , V_274 ) ;
break;
case V_263 :
F_8 ( V_219 -> V_222 , V_113 ,
V_292 | V_293 |
V_294 , V_274 ) ;
break;
case V_268 :
F_8 ( V_219 -> V_222 , V_110 ,
V_292 | V_293 |
V_294 , V_274 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_23 ( struct V_241 * V_242 ,
int V_295 , unsigned int V_296 , int V_297 )
{
struct V_216 * V_217 = V_242 -> V_217 ;
struct V_218 * V_219 = F_5 ( V_217 ) ;
unsigned int V_274 = 0 ;
if ( V_296 == V_219 -> V_221 && V_295 == V_219 -> V_298 )
return 0 ;
switch ( V_295 ) {
case V_299 :
V_274 |= V_300 ;
break;
case V_301 :
V_274 |= V_229 ;
break;
case V_302 :
V_274 |= V_303 ;
break;
default:
F_7 ( V_217 -> V_2 , L_6 , V_295 ) ;
return - V_251 ;
}
F_8 ( V_219 -> V_222 , V_119 ,
V_228 , V_274 ) ;
V_219 -> V_221 = V_296 ;
V_219 -> V_298 = V_295 ;
F_20 ( V_242 -> V_2 , L_7 , V_296 , V_295 ) ;
return 0 ;
}
static int F_24 ( const unsigned int V_304 ,
const unsigned int V_305 , struct V_306 * V_307 )
{
if ( V_308 > V_304 )
return - V_251 ;
return F_25 ( V_304 , V_305 , V_307 ) ;
}
static int F_26 ( struct V_241 * V_242 , int V_309 , int V_225 ,
unsigned int V_304 , unsigned int V_305 )
{
struct V_216 * V_217 = V_242 -> V_217 ;
struct V_218 * V_219 = F_5 ( V_217 ) ;
struct V_306 V_307 ;
int V_310 ;
if ( V_225 == V_219 -> V_311 && V_304 == V_219 -> V_312 &&
V_305 == V_219 -> V_313 )
return 0 ;
if ( ! V_304 || ! V_305 ) {
F_20 ( V_217 -> V_2 , L_8 ) ;
V_219 -> V_312 = 0 ;
V_219 -> V_313 = 0 ;
F_8 ( V_219 -> V_222 , V_119 ,
V_228 , V_300 ) ;
return 0 ;
}
switch ( V_225 ) {
case V_314 :
F_8 ( V_219 -> V_222 , V_119 ,
V_315 , V_316 ) ;
break;
case V_317 :
case V_318 :
case V_319 :
case V_320 :
switch ( V_242 -> V_250 ) {
case V_256 :
F_8 ( V_219 -> V_222 , V_119 ,
V_315 , V_321 ) ;
break;
case V_260 :
F_8 ( V_219 -> V_222 , V_119 ,
V_315 , V_322 ) ;
break;
case V_263 :
F_8 ( V_219 -> V_222 , V_119 ,
V_315 , V_323 ) ;
break;
case V_268 :
F_8 ( V_219 -> V_222 , V_119 ,
V_315 , V_324 ) ;
break;
default:
break;
}
break;
default:
F_7 ( V_217 -> V_2 , L_9 , V_225 ) ;
return - V_251 ;
}
V_310 = F_24 ( V_304 , V_305 , & V_307 ) ;
if ( V_310 < 0 ) {
F_7 ( V_217 -> V_2 , L_10 , V_304 ) ;
return V_310 ;
}
F_20 ( V_217 -> V_2 , L_11 ,
V_307 . V_325 , ( V_307 . V_325 ? 0 : V_307 . V_326 ) ,
V_307 . V_327 , V_307 . V_328 ) ;
F_27 ( V_219 -> V_222 , V_117 ,
V_307 . V_327 << V_329 | V_307 . V_328 ) ;
F_27 ( V_219 -> V_222 , V_20 ,
( V_307 . V_325 ? 0 : V_307 . V_326 ) << V_330 |
V_307 . V_325 << V_331 ) ;
V_219 -> V_312 = V_304 ;
V_219 -> V_313 = V_305 ;
V_219 -> V_311 = V_225 ;
return 0 ;
}
static int F_28 ( struct V_216 * V_217 ,
enum V_332 V_333 )
{
struct V_218 * V_219 = F_5 ( V_217 ) ;
switch ( V_333 ) {
case V_334 :
break;
case V_335 :
if ( V_217 -> V_336 . V_337 == V_338 ) {
F_8 ( V_219 -> V_222 , V_104 ,
V_339 | V_340 ,
0x0055 ) ;
F_8 ( V_219 -> V_222 ,
V_341 + V_342 ,
0x0f00 , 0x0f00 ) ;
F_8 ( V_219 -> V_222 , V_104 ,
V_343 | V_344 |
V_345 | V_346 ,
V_343 | V_344 |
V_345 | V_346 ) ;
F_29 ( 20 ) ;
F_8 ( V_219 -> V_222 , V_104 ,
V_347 | V_348 ,
V_347 | V_348 ) ;
F_8 ( V_219 -> V_222 , V_105 ,
V_349 , V_349 ) ;
F_8 ( V_219 -> V_222 , V_208 ,
0x1 , 0x1 ) ;
}
break;
case V_338 :
break;
case V_350 :
F_8 ( V_219 -> V_222 , V_208 , 0x1 , 0x0 ) ;
F_27 ( V_219 -> V_222 , V_102 , 0x0000 ) ;
F_27 ( V_219 -> V_222 , V_103 , 0x0000 ) ;
F_27 ( V_219 -> V_222 , V_104 , 0x0022 ) ;
F_27 ( V_219 -> V_222 , V_105 , 0x0000 ) ;
F_8 ( V_219 -> V_222 ,
V_341 + V_342 , 0x0f00 , 0x0000 ) ;
break;
default:
break;
}
V_217 -> V_336 . V_337 = V_333 ;
return 0 ;
}
static int F_30 ( struct V_216 * V_217 )
{
struct V_218 * V_219 = F_5 ( V_217 ) ;
V_219 -> V_217 = V_217 ;
F_28 ( V_217 , V_350 ) ;
F_27 ( V_219 -> V_222 , V_208 , 0x0020 ) ;
F_27 ( V_219 -> V_222 , V_107 , 0x0c00 ) ;
return 0 ;
}
static int F_31 ( struct V_216 * V_217 )
{
struct V_218 * V_219 = F_5 ( V_217 ) ;
F_27 ( V_219 -> V_222 , V_8 , 0x10ec ) ;
return 0 ;
}
static int F_32 ( struct V_216 * V_217 )
{
struct V_218 * V_219 = F_5 ( V_217 ) ;
F_33 ( V_219 -> V_222 , true ) ;
F_34 ( V_219 -> V_222 ) ;
return 0 ;
}
static int F_35 ( struct V_216 * V_217 )
{
struct V_218 * V_219 = F_5 ( V_217 ) ;
F_33 ( V_219 -> V_222 , false ) ;
F_36 ( V_219 -> V_222 ) ;
return 0 ;
}
static int F_37 ( struct V_351 * V_352 ,
const struct V_353 * V_250 )
{
struct V_354 * V_355 = F_38 ( & V_352 -> V_2 ) ;
struct V_218 * V_219 ;
int V_310 ;
unsigned int V_227 ;
V_219 = F_39 ( & V_352 -> V_2 , sizeof( struct V_218 ) ,
V_356 ) ;
if ( V_219 == NULL )
return - V_357 ;
F_40 ( V_352 , V_219 ) ;
if ( V_355 )
V_219 -> V_355 = * V_355 ;
V_219 -> V_222 = F_41 ( V_352 , & V_358 ) ;
if ( F_42 ( V_219 -> V_222 ) ) {
V_310 = F_43 ( V_219 -> V_222 ) ;
F_7 ( & V_352 -> V_2 , L_12 ,
V_310 ) ;
return V_310 ;
}
F_10 ( V_219 -> V_222 , V_37 , & V_227 ) ;
if ( V_227 != V_359 ) {
F_7 ( & V_352 -> V_2 ,
L_13 , V_227 ) ;
return - V_360 ;
}
F_27 ( V_219 -> V_222 , V_8 , 0x10ec ) ;
V_310 = F_44 ( V_219 -> V_222 , V_361 ,
F_2 ( V_361 ) ) ;
if ( V_310 != 0 )
F_45 ( & V_352 -> V_2 , L_14 , V_310 ) ;
if ( V_219 -> V_355 . V_362 )
F_8 ( V_219 -> V_222 , V_39 ,
V_363 , V_363 ) ;
if ( V_219 -> V_355 . V_364 )
F_8 ( V_219 -> V_222 , V_39 ,
V_365 , V_365 ) ;
return F_46 ( & V_352 -> V_2 , & V_366 ,
V_367 , F_2 ( V_367 ) ) ;
}
static int F_47 ( struct V_351 * V_352 )
{
F_48 ( & V_352 -> V_2 ) ;
return 0 ;
}
