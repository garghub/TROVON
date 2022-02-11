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
F_15 ( V_212 -> V_230 , V_106 , 0x2 , 0x2 ) ;
V_212 -> V_231 = true ;
} else {
F_15 ( V_212 -> V_230 , V_106 , 0x2 , 0x0 ) ;
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
F_15 ( V_212 -> V_230 , V_104 ,
V_237 , 0x0 ) ;
F_15 ( V_212 -> V_230 , V_105 ,
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
F_6 ( V_212 -> V_230 , V_107 , 0x07ff ) ;
F_6 ( V_212 -> V_230 , V_106 , 0x07fd ) ;
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
F_15 ( V_212 -> V_230 , V_106 , 0x1 , 0x0 ) ;
F_19 ( V_212 -> V_230 , false ) ;
F_18 ( V_212 -> V_230 , true ) ;
} else if ( ! V_229 && V_232 ) {
V_232 = false ;
F_18 ( V_212 -> V_230 , false ) ;
F_19 ( V_212 -> V_230 , true ) ;
F_15 ( V_212 -> V_230 , V_106 , 0x1 , 0x1 ) ;
F_13 ( V_217 , false ) ;
F_6 ( V_212 -> V_230 , V_106 , 0x0001 ) ;
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
int V_263 = F_33 ( V_212 -> V_264 [ V_265 ] << 8 ) ;
if ( V_263 < 0 )
F_7 ( V_217 -> V_2 , L_6 ) ;
else
F_15 ( V_212 -> V_230 , V_91 ,
V_266 , V_263 << V_267 ) ;
return V_263 ;
}
static int F_34 ( struct V_259 * V_268 ,
struct V_259 * V_269 )
{
struct V_216 * V_217 = F_32 ( V_268 -> V_262 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_270 ;
F_10 ( V_212 -> V_230 , V_119 , & V_270 ) ;
V_270 &= V_271 ;
if ( V_270 == V_272 )
return 1 ;
else
return 0 ;
}
static int F_35 ( struct V_259 * V_268 ,
struct V_259 * V_269 )
{
struct V_216 * V_217 = F_32 ( V_268 -> V_262 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_3 , V_273 , V_270 ;
if ( V_268 -> V_3 == V_121 ) {
switch ( V_268 -> V_273 ) {
case 12 :
V_3 = V_124 ;
V_273 = 0 ;
break;
case 13 :
V_3 = V_124 ;
V_273 = 4 ;
break;
case 14 :
V_3 = V_124 ;
V_273 = 8 ;
break;
case 15 :
V_3 = V_124 ;
V_273 = 12 ;
break;
default:
return 0 ;
}
} else {
switch ( V_268 -> V_273 ) {
case 0 :
V_3 = V_126 ;
V_273 = 8 ;
break;
case 1 :
V_3 = V_126 ;
V_273 = 12 ;
break;
case 2 :
V_3 = V_125 ;
V_273 = 0 ;
break;
case 3 :
V_3 = V_125 ;
V_273 = 4 ;
break;
case 4 :
V_3 = V_125 ;
V_273 = 8 ;
break;
case 5 :
V_3 = V_125 ;
V_273 = 12 ;
break;
case 12 :
V_3 = V_123 ;
V_273 = 0 ;
break;
case 13 :
V_3 = V_123 ;
V_273 = 4 ;
break;
case 14 :
V_3 = V_123 ;
V_273 = 12 ;
break;
default:
return 0 ;
}
}
F_10 ( V_212 -> V_230 , V_3 , & V_270 ) ;
V_270 = ( V_270 >> V_273 ) & 0xf ;
switch ( V_270 ) {
case 1 ... 6 :
return 1 ;
default:
return 0 ;
}
}
static int F_36 ( struct V_259 * V_268 ,
struct V_259 * V_269 )
{
struct V_216 * V_217 = F_32 ( V_268 -> V_262 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
if ( V_212 -> V_274 > V_212 -> V_264 [ V_265 ] * 384 )
return 1 ;
return 0 ;
}
int F_37 ( struct V_216 * V_217 ,
unsigned int V_275 , unsigned int V_276 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_277 = 0 , V_278 = 0 ;
unsigned int V_279 = 0 , V_280 = 0 ;
unsigned int V_281 = 0 , V_282 = 0 ;
unsigned int V_283 = 0 , V_284 = 0 ;
unsigned int V_285 = 0 , V_286 = 0 ;
unsigned int V_287 = 0 , V_288 = 0 ;
switch ( V_276 ) {
case V_289 :
case V_290 :
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
break;
default:
return - V_302 ;
}
if ( V_275 & V_303 ) {
V_277 |= V_304 ;
V_278 = ( V_278 & ~ V_304 )
| ( V_276 << V_305 ) ;
}
if ( V_275 & V_306 ) {
V_277 |= V_307 ;
V_278 = ( V_278 & ~ V_307 )
| ( V_276 << V_308 ) ;
}
if ( V_275 & V_309 ) {
V_277 |= V_310 ;
V_278 = ( V_278 & ~ V_310 )
| ( V_276 << V_311 ) ;
}
if ( V_277 )
F_15 ( V_212 -> V_230 , V_123 , V_277 ,
V_278 ) ;
if ( V_275 & V_312 ) {
V_279 |= V_313 ;
V_280 = ( V_280 & ~ V_313 )
| ( V_276 << V_314 ) ;
}
if ( V_275 & V_315 ) {
V_279 |= V_316 ;
V_280 = ( V_280 & ~ V_316 )
| ( V_276 << V_317 ) ;
}
if ( V_275 & V_318 ) {
V_279 |= V_319 ;
V_280 = ( V_280 & ~ V_319 )
| ( V_276 << V_320 ) ;
}
if ( V_275 & V_321 ) {
V_279 |= V_322 ;
V_280 = ( V_280 & ~ V_322 )
| ( V_276 << V_323 ) ;
}
if ( V_279 )
F_15 ( V_212 -> V_230 , V_124 , V_279 ,
V_280 ) ;
if ( V_275 & V_324 ) {
V_281 |= V_325 ;
V_282 = ( V_282 & ~ V_325 )
| ( V_276 << V_326 ) ;
}
if ( V_275 & V_327 ) {
V_281 |= V_328 ;
V_282 = ( V_282 & ~ V_328 )
| ( V_276 << V_329 ) ;
}
if ( V_275 & V_330 ) {
V_281 |= V_331 ;
V_282 = ( V_282 & ~ V_331 )
| ( V_276 << V_332 ) ;
}
if ( V_275 & V_333 ) {
V_281 |= V_334 ;
V_282 = ( V_282 & ~ V_334 )
| ( V_276 << V_335 ) ;
}
if ( V_281 )
F_15 ( V_212 -> V_230 , V_125 , V_281 ,
V_282 ) ;
if ( V_275 & V_336 ) {
V_283 |= V_337 ;
V_284 = ( V_284 & ~ V_337 )
| ( V_276 << V_338 ) ;
}
if ( V_275 & V_339 ) {
V_283 |= V_340 ;
V_284 = ( V_284 & ~ V_340 )
| ( V_276 << V_341 ) ;
}
if ( V_283 )
F_15 ( V_212 -> V_230 , V_126 , V_283 ,
V_284 ) ;
if ( V_275 & V_342 ) {
V_285 |= V_343 ;
V_286 = ( V_286 & ~ V_343 )
| ( V_276 << V_344 ) ;
}
if ( V_275 & V_345 ) {
V_285 |= V_346 ;
V_286 = ( V_286 & ~ V_346 )
| ( V_276 << V_347 ) ;
}
if ( V_285 )
F_15 ( V_212 -> V_230 , V_127 , V_285 ,
V_286 ) ;
if ( V_275 & V_348 ) {
V_287 |= V_349 ;
V_288 = ( V_288 & ~ V_349 )
| ( ( V_276 - 1 ) << V_350 ) ;
}
if ( V_275 & V_351 ) {
V_287 |= V_352 ;
V_288 = ( V_288 & ~ V_352 )
| ( ( V_276 - 1 ) << V_353 ) ;
}
if ( V_275 & V_354 ) {
V_287 |= V_355 ;
V_288 = ( V_288 & ~ V_355 )
| ( ( V_276 - 1 ) << V_356 ) ;
}
if ( V_275 & V_357 ) {
V_287 |= V_358 ;
V_288 = ( V_288 & ~ V_358 )
| ( ( V_276 - 1 ) << V_359 ) ;
}
if ( V_287 )
F_15 ( V_212 -> V_230 , V_128 , V_287 ,
V_288 ) ;
return 0 ;
}
static int F_38 ( struct V_259 * V_268 ,
struct V_259 * V_269 )
{
struct V_216 * V_217 = F_32 ( V_268 -> V_262 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_360 ;
switch ( V_268 -> V_273 ) {
case 11 :
F_10 ( V_212 -> V_230 , V_125 , & V_360 ) ;
V_360 = ( V_360 & V_325 ) >>
V_326 ;
if ( V_360 >= V_290 &&
V_360 <= V_295 )
return 1 ;
break;
case 10 :
F_10 ( V_212 -> V_230 , V_125 , & V_360 ) ;
V_360 = ( V_360 & V_328 ) >>
V_329 ;
if ( V_360 >= V_290 &&
V_360 <= V_295 )
return 1 ;
break;
case 9 :
F_10 ( V_212 -> V_230 , V_125 , & V_360 ) ;
V_360 = ( V_360 & V_331 ) >>
V_332 ;
if ( V_360 >= V_290 &&
V_360 <= V_295 )
return 1 ;
break;
case 8 :
F_10 ( V_212 -> V_230 , V_125 , & V_360 ) ;
V_360 = ( V_360 & V_334 ) >>
V_335 ;
if ( V_360 >= V_290 &&
V_360 <= V_295 )
return 1 ;
break;
case 7 :
F_10 ( V_212 -> V_230 , V_126 , & V_360 ) ;
V_360 = ( V_360 & V_337 ) >>
V_338 ;
if ( V_360 >= V_290 &&
V_360 <= V_295 )
return 1 ;
break;
case 6 :
F_10 ( V_212 -> V_230 , V_126 , & V_360 ) ;
V_360 = ( V_360 & V_340 ) >>
V_341 ;
if ( V_360 >= V_290 &&
V_360 <= V_295 )
return 1 ;
break;
default:
break;
}
return 0 ;
}
static int F_39 ( struct V_259 * V_260 ,
struct V_251 * V_252 , int V_261 )
{
struct V_216 * V_217 = F_32 ( V_260 -> V_262 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_261 ) {
case V_361 :
F_15 ( V_212 -> V_230 , V_105 ,
V_362 , V_362 ) ;
break;
case V_363 :
F_15 ( V_212 -> V_230 , V_105 ,
V_362 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_40 ( struct V_259 * V_260 ,
struct V_251 * V_252 , int V_261 )
{
struct V_216 * V_217 = F_32 ( V_260 -> V_262 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_261 ) {
case V_361 :
F_15 ( V_212 -> V_230 , V_105 ,
V_364 , V_364 ) ;
break;
case V_363 :
F_15 ( V_212 -> V_230 , V_105 ,
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
case V_365 :
F_15 ( V_212 -> V_230 , V_20 , 0x2 , 0x2 ) ;
break;
case V_361 :
F_15 ( V_212 -> V_230 , V_20 , 0x2 , 0x0 ) ;
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
case V_365 :
F_15 ( V_212 -> V_230 , V_21 , 0x2 , 0x2 ) ;
break;
case V_361 :
F_15 ( V_212 -> V_230 , V_21 , 0x2 , 0x0 ) ;
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
case V_361 :
F_15 ( V_212 -> V_230 , V_105 ,
V_366 | V_367 |
V_368 , V_366 |
V_367 | V_368 ) ;
break;
case V_363 :
F_15 ( V_212 -> V_230 , V_105 ,
V_366 | V_367 |
V_368 , 0 ) ;
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
unsigned int V_214 ;
switch ( V_261 ) {
case V_365 :
F_10 ( V_212 -> V_230 , V_77 , & V_214 ) ;
if ( V_214 & V_369 )
F_15 ( V_212 -> V_230 , V_76 ,
V_370 ,
V_371 ) ;
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
case V_365 :
F_10 ( V_212 -> V_230 , V_82 , & V_214 ) ;
if ( V_214 & V_372 )
F_15 ( V_212 -> V_230 , V_81 ,
V_373 ,
V_374 ) ;
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
switch ( V_261 ) {
case V_361 :
if ( F_30 ( V_217 ) != V_375 &&
! V_212 -> V_376 ) {
F_47 ( 20 ) ;
F_15 ( V_212 -> V_230 , V_104 ,
V_377 | V_378 ,
V_377 | V_378 ) ;
V_212 -> V_376 = true ;
}
break;
default:
return 0 ;
}
return 0 ;
}
static int F_48 ( struct V_379 * V_380 ,
struct V_381 * V_382 , struct V_383 * V_384 )
{
struct V_216 * V_217 = V_384 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_385 = 0 , V_386 , V_387 ;
int V_388 , V_389 , V_390 ;
V_212 -> V_264 [ V_384 -> V_391 ] = F_49 ( V_382 ) ;
V_388 = F_50 ( V_212 -> V_274 , V_212 -> V_264 [ V_384 -> V_391 ] ) ;
if ( V_388 < 0 ) {
F_7 ( V_217 -> V_2 , L_7 ,
V_212 -> V_274 , V_212 -> V_264 [ V_384 -> V_391 ] ) ;
return - V_302 ;
}
V_390 = F_51 ( V_382 ) ;
if ( V_390 < 0 ) {
F_7 ( V_217 -> V_2 , L_8 , V_390 ) ;
return - V_302 ;
}
V_389 = V_390 > 32 ;
V_212 -> V_392 [ V_384 -> V_391 ] = V_212 -> V_264 [ V_384 -> V_391 ] * ( 32 << V_389 ) ;
F_52 ( V_384 -> V_2 , L_9 ,
V_212 -> V_392 [ V_384 -> V_391 ] , V_212 -> V_264 [ V_384 -> V_391 ] ) ;
F_52 ( V_384 -> V_2 , L_10 ,
V_389 , V_388 , V_384 -> V_391 ) ;
switch ( F_53 ( V_382 ) ) {
case 16 :
break;
case 20 :
V_385 |= V_393 ;
break;
case 24 :
V_385 |= V_394 ;
break;
case 8 :
V_385 |= V_395 ;
break;
default:
return - V_302 ;
}
switch ( V_384 -> V_391 ) {
case V_265 :
V_387 = V_396 ;
V_386 = V_388 << V_397 ;
F_15 ( V_212 -> V_230 , V_111 ,
V_398 , V_385 ) ;
F_15 ( V_212 -> V_230 , V_114 ,
V_387 , V_386 ) ;
break;
case V_399 :
V_387 = V_400 ;
V_386 = V_388 << V_401 ;
F_15 ( V_212 -> V_230 , V_112 ,
V_398 , V_385 ) ;
F_15 ( V_212 -> V_230 , V_114 ,
V_387 , V_386 ) ;
break;
case V_402 :
V_387 = V_403 | V_404 ;
V_386 = V_389 << V_405 |
V_388 << V_406 ;
F_15 ( V_212 -> V_230 , V_113 ,
V_398 , V_385 ) ;
F_15 ( V_212 -> V_230 , V_114 ,
V_387 , V_386 ) ;
break;
case V_407 :
V_387 = V_408 | V_409 ;
V_386 = V_389 << V_410 |
V_388 << V_411 ;
F_15 ( V_212 -> V_230 , V_110 ,
V_398 , V_385 ) ;
F_15 ( V_212 -> V_230 , V_114 ,
V_387 , V_386 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_54 ( struct V_383 * V_384 , unsigned int V_412 )
{
struct V_216 * V_217 = V_384 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_413 = 0 ;
switch ( V_412 & V_414 ) {
case V_415 :
V_212 -> V_416 [ V_384 -> V_391 ] = 1 ;
break;
case V_417 :
V_413 |= V_418 ;
V_212 -> V_416 [ V_384 -> V_391 ] = 0 ;
break;
default:
return - V_302 ;
}
switch ( V_412 & V_419 ) {
case V_420 :
break;
case V_421 :
V_413 |= V_422 ;
break;
default:
return - V_302 ;
}
switch ( V_412 & V_423 ) {
case V_424 :
break;
case V_425 :
V_413 |= V_426 ;
break;
case V_427 :
V_413 |= V_428 ;
break;
case V_429 :
V_413 |= V_430 ;
break;
default:
return - V_302 ;
}
switch ( V_384 -> V_391 ) {
case V_265 :
F_15 ( V_212 -> V_230 , V_111 ,
V_431 | V_432 |
V_433 , V_413 ) ;
break;
case V_399 :
F_15 ( V_212 -> V_230 , V_112 ,
V_431 | V_432 |
V_433 , V_413 ) ;
break;
case V_402 :
F_15 ( V_212 -> V_230 , V_113 ,
V_431 | V_432 |
V_433 , V_413 ) ;
break;
case V_407 :
F_15 ( V_212 -> V_230 , V_110 ,
V_431 | V_432 |
V_433 , V_413 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_55 ( struct V_383 * V_384 ,
int V_434 , unsigned int V_435 , int V_436 )
{
struct V_216 * V_217 = V_384 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_413 = 0 ;
if ( V_435 == V_212 -> V_274 && V_434 == V_212 -> V_437 )
return 0 ;
switch ( V_434 ) {
case V_438 :
V_413 |= V_439 ;
break;
case V_440 :
V_413 |= V_272 ;
break;
case V_441 :
V_413 |= V_442 ;
break;
default:
F_7 ( V_217 -> V_2 , L_11 , V_434 ) ;
return - V_302 ;
}
F_15 ( V_212 -> V_230 , V_119 ,
V_271 , V_413 ) ;
V_212 -> V_274 = V_435 ;
V_212 -> V_437 = V_434 ;
F_52 ( V_384 -> V_2 , L_12 , V_435 , V_434 ) ;
return 0 ;
}
static int F_56 ( const unsigned int V_443 ,
const unsigned int V_444 , struct V_445 * V_446 )
{
if ( V_447 > V_443 )
return - V_302 ;
return F_57 ( V_443 , V_444 , V_446 ) ;
}
static int F_58 ( struct V_383 * V_384 , int V_448 , int V_268 ,
unsigned int V_443 , unsigned int V_444 )
{
struct V_216 * V_217 = V_384 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
struct V_445 V_446 ;
int V_218 ;
if ( V_268 == V_212 -> V_449 && V_443 == V_212 -> V_450 &&
V_444 == V_212 -> V_451 )
return 0 ;
if ( ! V_443 || ! V_444 ) {
F_52 ( V_217 -> V_2 , L_13 ) ;
V_212 -> V_450 = 0 ;
V_212 -> V_451 = 0 ;
F_15 ( V_212 -> V_230 , V_119 ,
V_271 , V_439 ) ;
return 0 ;
}
switch ( V_268 ) {
case V_452 :
F_15 ( V_212 -> V_230 , V_119 ,
V_453 , V_454 ) ;
break;
case V_455 :
case V_456 :
case V_457 :
case V_458 :
switch ( V_384 -> V_391 ) {
case V_265 :
F_15 ( V_212 -> V_230 , V_119 ,
V_453 , V_459 ) ;
break;
case V_399 :
F_15 ( V_212 -> V_230 , V_119 ,
V_453 , V_460 ) ;
break;
case V_402 :
F_15 ( V_212 -> V_230 , V_119 ,
V_453 , V_461 ) ;
break;
case V_407 :
F_15 ( V_212 -> V_230 , V_119 ,
V_453 , V_462 ) ;
break;
default:
break;
}
break;
default:
F_7 ( V_217 -> V_2 , L_14 , V_268 ) ;
return - V_302 ;
}
V_218 = F_56 ( V_443 , V_444 , & V_446 ) ;
if ( V_218 < 0 ) {
F_7 ( V_217 -> V_2 , L_15 , V_443 ) ;
return V_218 ;
}
F_52 ( V_217 -> V_2 , L_16 ,
V_446 . V_463 , ( V_446 . V_463 ? 0 : V_446 . V_464 ) ,
V_446 . V_465 , V_446 . V_466 ) ;
F_6 ( V_212 -> V_230 , V_117 ,
V_446 . V_465 << V_467 | V_446 . V_466 ) ;
F_6 ( V_212 -> V_230 , V_20 ,
( V_446 . V_463 ? 0 : V_446 . V_464 ) << V_468 |
V_446 . V_463 << V_469 ) ;
V_212 -> V_450 = V_443 ;
V_212 -> V_451 = V_444 ;
V_212 -> V_449 = V_268 ;
return 0 ;
}
static int F_59 ( struct V_383 * V_384 , unsigned int V_470 ,
unsigned int V_471 , int V_472 , int V_473 )
{
struct V_216 * V_217 = V_384 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_270 = 0 , V_474 = 0 ;
if ( V_471 || V_470 )
V_270 |= ( 1 << 12 ) ;
switch ( V_472 ) {
case 4 :
V_270 |= ( 1 << 10 ) ;
break;
case 6 :
V_270 |= ( 2 << 10 ) ;
break;
case 8 :
V_270 |= ( 3 << 10 ) ;
break;
case 2 :
default:
break;
}
switch ( V_473 ) {
case 20 :
V_270 |= ( 1 << 8 ) ;
break;
case 25 :
V_474 = 0x8080 ;
case 24 :
V_270 |= ( 2 << 8 ) ;
break;
case 32 :
V_270 |= ( 3 << 8 ) ;
break;
case 16 :
default:
break;
}
switch ( V_384 -> V_391 ) {
case V_265 :
F_15 ( V_212 -> V_230 , V_76 , 0x1f00 ,
V_270 ) ;
F_15 ( V_212 -> V_230 , V_208 , 0x8000 ,
V_474 ) ;
break;
case V_399 :
F_15 ( V_212 -> V_230 , V_81 , 0x1f00 ,
V_270 ) ;
F_15 ( V_212 -> V_230 , V_208 , 0x80 ,
V_474 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_60 ( struct V_216 * V_217 ,
enum V_475 V_476 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_476 ) {
case V_375 :
break;
case V_477 :
if ( F_30 ( V_217 ) == V_478 ) {
F_16 ( V_217 , false ) ;
F_15 ( V_212 -> V_230 , V_104 ,
V_237 | V_479 ,
0x0055 ) ;
F_15 ( V_212 -> V_230 ,
V_235 + V_236 ,
0x0f00 , 0x0f00 ) ;
F_15 ( V_212 -> V_230 , V_104 ,
V_377 | V_378 |
V_480 | V_481 |
V_482 | V_483 ,
V_480 | V_481 |
V_482 | V_483 ) ;
V_212 -> V_376 = false ;
F_15 ( V_212 -> V_230 , V_105 ,
V_484 , V_484 ) ;
F_15 ( V_212 -> V_230 , V_208 ,
0x1 , 0x1 ) ;
}
break;
case V_478 :
break;
case V_258 :
F_15 ( V_212 -> V_230 , V_208 , 0x1 , 0x0 ) ;
F_6 ( V_212 -> V_230 , V_102 , 0x0000 ) ;
F_6 ( V_212 -> V_230 , V_103 , 0x0000 ) ;
F_6 ( V_212 -> V_230 , V_104 , 0x0022 ) ;
F_6 ( V_212 -> V_230 , V_105 , 0x0000 ) ;
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
static inline struct V_211 * F_61 ( struct V_485 * V_486 )
{
return F_62 ( V_486 , struct V_211 , V_485 ) ;
}
static void F_63 ( struct V_485 * V_486 , unsigned V_487 , int V_214 )
{
struct V_211 * V_212 = F_61 ( V_486 ) ;
switch ( V_487 ) {
case V_488 ... V_489 :
F_15 ( V_212 -> V_230 , V_161 ,
0x1 << ( V_487 * 3 + 1 ) , ! ! V_214 << ( V_487 * 3 + 1 ) ) ;
break;
case V_490 :
F_15 ( V_212 -> V_230 , V_162 ,
V_491 , ! ! V_214 << V_492 ) ;
break;
default:
break;
}
}
static int F_64 ( struct V_485 * V_486 ,
unsigned V_487 , int V_214 )
{
struct V_211 * V_212 = F_61 ( V_486 ) ;
switch ( V_487 ) {
case V_488 ... V_489 :
F_15 ( V_212 -> V_230 , V_161 ,
0x3 << ( V_487 * 3 + 1 ) ,
( 0x2 | ! ! V_214 ) << ( V_487 * 3 + 1 ) ) ;
break;
case V_490 :
F_15 ( V_212 -> V_230 , V_162 ,
V_493 | V_491 ,
V_494 | ! ! V_214 << V_492 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_65 ( struct V_485 * V_486 , unsigned V_487 )
{
struct V_211 * V_212 = F_61 ( V_486 ) ;
int V_214 , V_218 ;
V_218 = F_10 ( V_212 -> V_230 , V_29 , & V_214 ) ;
if ( V_218 < 0 )
return V_218 ;
return ( V_214 & ( 0x1 << V_487 ) ) >> V_487 ;
}
static int F_66 ( struct V_485 * V_486 , unsigned V_487 )
{
struct V_211 * V_212 = F_61 ( V_486 ) ;
switch ( V_487 ) {
case V_488 ... V_489 :
F_15 ( V_212 -> V_230 , V_161 ,
0x1 << ( V_487 * 3 + 2 ) , 0x0 ) ;
break;
case V_490 :
F_15 ( V_212 -> V_230 , V_162 ,
V_493 , V_495 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_67 ( struct V_211 * V_212 , unsigned V_487 ,
int V_214 )
{
int V_273 ;
switch ( V_487 ) {
case V_488 ... V_496 :
V_273 = 2 * ( 1 - V_487 ) ;
F_15 ( V_212 -> V_230 ,
V_235 + V_497 ,
0x3 << V_273 ,
( V_214 & 0x3 ) << V_273 ) ;
break;
case V_498 ... V_490 :
V_273 = 2 * ( 9 - V_487 ) ;
F_15 ( V_212 -> V_230 ,
V_235 + V_499 ,
0x3 << V_273 ,
( V_214 & 0x3 ) << V_273 ) ;
break;
default:
break;
}
}
static int F_68 ( struct V_485 * V_486 , unsigned V_487 )
{
struct V_211 * V_212 = F_61 ( V_486 ) ;
struct V_500 * V_501 = V_212 -> V_502 ;
int V_503 ;
if ( V_487 >= V_488 && V_487 <= V_498 ) {
if ( ( V_212 -> V_504 . V_505 == 1 && V_487 == V_488 ) ||
( V_212 -> V_504 . V_505 == 2 &&
V_487 == V_496 ) ||
( V_212 -> V_504 . V_505 == 3 &&
V_487 == V_498 ) ) {
V_503 = V_506 ;
} else {
return - V_234 ;
}
}
if ( V_487 >= V_507 && V_487 <= V_490 ) {
if ( ( V_212 -> V_504 . V_508 == 1 && V_487 == V_507 ) ||
( V_212 -> V_504 . V_508 == 2 &&
V_487 == V_489 ) ||
( V_212 -> V_504 . V_508 == 3 &&
V_487 == V_490 ) ) {
V_503 = V_509 ;
} else if ( ( V_212 -> V_504 . V_510 == 1 &&
V_487 == V_507 ) ||
( V_212 -> V_504 . V_510 == 2 &&
V_487 == V_489 ) ||
( V_212 -> V_504 . V_510 == 3 &&
V_487 == V_490 ) ) {
V_503 = V_511 ;
} else {
return - V_234 ;
}
}
return F_69 ( V_501 , V_503 ) ;
}
static void F_70 ( struct V_512 * V_513 )
{
struct V_211 * V_212 = F_71 ( V_513 ) ;
int V_218 ;
V_212 -> V_485 = V_514 ;
V_212 -> V_485 . V_515 = V_516 ;
V_212 -> V_485 . V_2 = & V_513 -> V_2 ;
V_212 -> V_485 . V_517 = - 1 ;
V_218 = F_72 ( & V_212 -> V_485 ) ;
if ( V_218 != 0 )
F_7 ( & V_513 -> V_2 , L_17 , V_218 ) ;
}
static void F_73 ( struct V_512 * V_513 )
{
struct V_211 * V_212 = F_71 ( V_513 ) ;
F_74 ( & V_212 -> V_485 ) ;
}
static void F_67 ( struct V_211 * V_212 , unsigned V_487 ,
int V_214 )
{
}
static void F_70 ( struct V_512 * V_513 )
{
}
static void F_73 ( struct V_512 * V_513 )
{
}
static int F_75 ( struct V_216 * V_217 )
{
struct V_518 * V_262 = F_76 ( V_217 ) ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
int V_4 ;
V_212 -> V_217 = V_217 ;
if ( V_212 -> V_504 . V_519 == V_520 ) {
F_77 ( V_262 ,
V_521 ,
F_2 ( V_521 ) ) ;
} else {
F_77 ( V_262 ,
V_522 ,
F_2 ( V_522 ) ) ;
}
F_78 ( V_217 , V_258 ) ;
F_6 ( V_212 -> V_230 , V_208 , 0x0020 ) ;
F_6 ( V_212 -> V_230 , V_107 , 0x0c00 ) ;
for ( V_4 = 0 ; V_4 < V_516 ; V_4 ++ )
F_67 ( V_212 , V_4 , V_212 -> V_504 . V_523 [ V_4 ] ) ;
if ( V_212 -> V_502 ) {
F_15 ( V_212 -> V_230 , V_160 , 0x8000 ,
0x8000 ) ;
F_15 ( V_212 -> V_230 , V_208 , 0x0018 ,
0x0008 ) ;
if ( V_212 -> V_504 . V_505 )
F_15 ( V_212 -> V_230 , V_157 ,
V_524 ,
V_212 -> V_504 . V_505 <<
V_525 ) ;
if ( V_212 -> V_504 . V_508 )
F_15 ( V_212 -> V_230 , V_157 ,
V_526 ,
V_212 -> V_504 . V_508 <<
V_527 ) ;
if ( V_212 -> V_504 . V_510 )
F_15 ( V_212 -> V_230 , V_157 ,
V_528 ,
V_212 -> V_504 . V_510 <<
V_529 ) ;
}
F_79 ( & V_212 -> V_219 ) ;
F_79 ( & V_212 -> V_530 ) ;
return 0 ;
}
static int F_80 ( struct V_216 * V_217 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
F_6 ( V_212 -> V_230 , V_8 , 0x10ec ) ;
if ( F_81 ( V_212 -> V_531 ) )
F_82 ( V_212 -> V_531 , 0 ) ;
if ( F_81 ( V_212 -> V_532 ) )
F_82 ( V_212 -> V_532 , 0 ) ;
return 0 ;
}
static int F_83 ( struct V_216 * V_217 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
if ( ! V_212 -> V_257 ) {
F_18 ( V_212 -> V_230 , true ) ;
F_23 ( V_212 -> V_230 ) ;
if ( F_81 ( V_212 -> V_531 ) )
F_82 ( V_212 -> V_531 , 0 ) ;
if ( F_81 ( V_212 -> V_532 ) )
F_82 ( V_212 -> V_532 , 0 ) ;
}
return 0 ;
}
static int F_84 ( struct V_216 * V_217 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
if ( ! V_212 -> V_257 ) {
if ( F_81 ( V_212 -> V_531 ) )
F_82 ( V_212 -> V_531 , 1 ) ;
if ( F_81 ( V_212 -> V_532 ) )
F_82 ( V_212 -> V_532 , 1 ) ;
if ( F_81 ( V_212 -> V_531 ) ||
F_81 ( V_212 -> V_532 ) )
F_85 ( 10 ) ;
F_18 ( V_212 -> V_230 , false ) ;
F_24 ( V_212 -> V_230 ) ;
}
return 0 ;
}
static int F_86 ( void * V_533 , unsigned int V_3 , unsigned int * V_270 )
{
struct V_512 * V_534 = V_533 ;
struct V_211 * V_212 = F_71 ( V_534 ) ;
if ( V_212 -> V_231 ) {
if ( V_3 > 0xff ) {
F_5 ( & V_212 -> V_530 ) ;
F_11 ( V_212 , V_109 ,
V_3 & 0xff ) ;
F_12 ( V_212 , V_19 , V_270 ) ;
F_8 ( & V_212 -> V_530 ) ;
} else {
F_12 ( V_212 , V_3 , V_270 ) ;
}
} else {
F_10 ( V_212 -> V_220 , V_3 , V_270 ) ;
}
return 0 ;
}
static int F_87 ( void * V_533 , unsigned int V_3 , unsigned int V_270 )
{
struct V_512 * V_534 = V_533 ;
struct V_211 * V_212 = F_71 ( V_534 ) ;
if ( V_212 -> V_231 ) {
if ( V_3 > 0xff ) {
F_5 ( & V_212 -> V_530 ) ;
F_11 ( V_212 , V_109 ,
V_3 & 0xff ) ;
F_11 ( V_212 , V_19 ,
V_270 ) ;
F_8 ( & V_212 -> V_530 ) ;
} else {
F_11 ( V_212 , V_3 , V_270 ) ;
}
} else {
F_6 ( V_212 -> V_220 , V_3 , V_270 ) ;
}
return 0 ;
}
static int F_88 ( struct V_211 * V_212 , struct V_535 * V_536 )
{
V_212 -> V_504 . V_537 = F_89 ( V_536 ,
L_18 ) ;
V_212 -> V_504 . V_538 = F_89 ( V_536 ,
L_19 ) ;
V_212 -> V_504 . V_539 = F_89 ( V_536 ,
L_20 ) ;
V_212 -> V_504 . V_540 = F_89 ( V_536 ,
L_21 ) ;
V_212 -> V_504 . V_541 = F_89 ( V_536 ,
L_22 ) ;
V_212 -> V_531 = F_90 ( V_536 ,
L_23 , 0 ) ;
V_212 -> V_532 = F_90 ( V_536 ,
L_24 , 0 ) ;
if ( ! F_81 ( V_212 -> V_531 ) &&
( V_212 -> V_531 != - V_542 ) )
return V_212 -> V_531 ;
if ( ! F_81 ( V_212 -> V_532 ) &&
( V_212 -> V_532 != - V_542 ) )
return V_212 -> V_532 ;
F_91 ( V_536 , L_25 ,
V_212 -> V_504 . V_523 , V_516 ) ;
F_92 ( V_536 , L_26 , & V_212 -> V_504 . V_505 ) ;
F_92 ( V_536 , L_27 , & V_212 -> V_504 . V_508 ) ;
F_92 ( V_536 , L_28 , & V_212 -> V_504 . V_510 ) ;
return 0 ;
}
static int F_93 ( struct V_512 * V_513 )
{
int V_218 ;
struct V_211 * V_212 = F_71 ( V_513 ) ;
if ( ! V_212 -> V_504 . V_505 &&
! V_212 -> V_504 . V_508 &&
! V_212 -> V_504 . V_510 )
return 0 ;
if ( ! V_513 -> V_503 ) {
F_7 ( & V_513 -> V_2 , L_29 ) ;
return - V_302 ;
}
V_218 = F_94 ( V_212 -> V_230 , V_513 -> V_503 ,
V_543 | V_544 | V_545 , 0 ,
& V_546 , & V_212 -> V_502 ) ;
if ( V_218 != 0 ) {
F_7 ( & V_513 -> V_2 , L_30 , V_218 ) ;
return V_218 ;
}
return 0 ;
}
static void F_95 ( struct V_512 * V_513 )
{
struct V_211 * V_212 = F_71 ( V_513 ) ;
if ( V_212 -> V_502 )
F_96 ( V_513 -> V_503 , V_212 -> V_502 ) ;
}
static int F_97 ( struct V_512 * V_513 ,
const struct V_547 * V_391 )
{
struct V_548 * V_504 = F_98 ( & V_513 -> V_2 ) ;
struct V_211 * V_212 ;
int V_218 ;
unsigned int V_270 ;
V_212 = F_99 ( & V_513 -> V_2 , sizeof( struct V_211 ) ,
V_549 ) ;
if ( V_212 == NULL )
return - V_550 ;
F_100 ( V_513 , V_212 ) ;
V_212 -> type = V_391 -> V_551 ;
if ( V_504 )
V_212 -> V_504 = * V_504 ;
if ( V_513 -> V_2 . V_552 ) {
V_218 = F_88 ( V_212 , V_513 -> V_2 . V_552 ) ;
if ( V_218 ) {
F_7 ( & V_513 -> V_2 , L_31 ,
V_218 ) ;
return V_218 ;
}
} else {
V_212 -> V_531 = - V_302 ;
V_212 -> V_532 = - V_302 ;
}
if ( F_81 ( V_212 -> V_531 ) ) {
V_218 = F_101 ( & V_513 -> V_2 , V_212 -> V_531 ,
V_553 ,
L_32 ) ;
if ( V_218 < 0 ) {
F_7 ( & V_513 -> V_2 , L_33 ,
V_212 -> V_531 , V_218 ) ;
return V_218 ;
}
}
if ( F_81 ( V_212 -> V_532 ) ) {
V_218 = F_101 ( & V_513 -> V_2 , V_212 -> V_532 ,
V_553 ,
L_34 ) ;
if ( V_218 < 0 ) {
F_7 ( & V_513 -> V_2 , L_35 ,
V_212 -> V_532 , V_218 ) ;
return V_218 ;
}
}
if ( F_81 ( V_212 -> V_531 ) ||
F_81 ( V_212 -> V_532 ) ) {
F_85 ( 10 ) ;
}
V_212 -> V_220 = F_102 ( V_513 ,
& V_554 ) ;
if ( F_103 ( V_212 -> V_220 ) ) {
V_218 = F_104 ( V_212 -> V_220 ) ;
F_7 ( & V_513 -> V_2 , L_36 ,
V_218 ) ;
return V_218 ;
}
V_212 -> V_230 = F_105 ( & V_513 -> V_2 , NULL , V_513 , & V_555 ) ;
if ( F_103 ( V_212 -> V_230 ) ) {
V_218 = F_104 ( V_212 -> V_230 ) ;
F_7 ( & V_513 -> V_2 , L_36 ,
V_218 ) ;
return V_218 ;
}
F_10 ( V_212 -> V_230 , V_37 , & V_270 ) ;
if ( V_270 != V_556 ) {
F_7 ( & V_513 -> V_2 ,
L_37 , V_270 ) ;
return - V_557 ;
}
F_6 ( V_212 -> V_230 , V_8 , 0x10ec ) ;
V_218 = F_106 ( V_212 -> V_230 , V_558 ,
F_2 ( V_558 ) ) ;
if ( V_218 != 0 )
F_107 ( & V_513 -> V_2 , L_38 , V_218 ) ;
if ( V_212 -> V_504 . V_537 )
F_15 ( V_212 -> V_230 , V_39 ,
V_559 , V_559 ) ;
if ( V_212 -> V_504 . V_538 )
F_15 ( V_212 -> V_230 , V_39 ,
V_560 , V_560 ) ;
if ( V_212 -> V_504 . V_539 )
F_15 ( V_212 -> V_230 , V_38 ,
V_561 , V_561 ) ;
if ( V_212 -> V_504 . V_540 )
F_15 ( V_212 -> V_230 , V_38 ,
V_562 , V_562 ) ;
if ( V_212 -> V_504 . V_541 )
F_15 ( V_212 -> V_230 , V_38 ,
V_563 , V_563 ) ;
if ( V_212 -> V_504 . V_519 == V_520 ) {
F_15 ( V_212 -> V_230 , V_210 ,
V_564 ,
V_565 ) ;
F_15 ( V_212 -> V_230 , V_161 ,
V_566 ,
V_567 ) ;
}
if ( V_212 -> V_504 . V_568 )
F_15 ( V_212 -> V_230 , V_40 ,
V_569 ,
V_570 ) ;
F_70 ( V_513 ) ;
F_93 ( V_513 ) ;
return F_108 ( & V_513 -> V_2 , & V_571 ,
V_572 , F_2 ( V_572 ) ) ;
}
static int F_109 ( struct V_512 * V_513 )
{
F_110 ( & V_513 -> V_2 ) ;
F_95 ( V_513 ) ;
F_73 ( V_513 ) ;
return 0 ;
}
