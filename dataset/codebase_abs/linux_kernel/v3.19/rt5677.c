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
if ( V_229 && ! V_232 ) {
V_232 = true ;
F_17 ( V_212 -> V_230 , false ) ;
F_18 ( V_212 -> V_230 , true ) ;
F_15 ( V_212 -> V_230 , V_208 , 0x1 , 0x1 ) ;
F_15 ( V_212 -> V_230 ,
V_233 + V_234 , 0x0f00 , 0x0f00 ) ;
F_15 ( V_212 -> V_230 , V_104 ,
V_235 , 0x0 ) ;
F_15 ( V_212 -> V_230 , V_105 ,
V_236 , V_236 ) ;
F_15 ( V_212 -> V_230 , V_119 ,
V_237 , V_238 ) ;
F_15 ( V_212 -> V_230 , V_120 ,
V_239 | V_240 ,
V_241 | V_242 ) ;
F_6 ( V_212 -> V_230 , V_107 , 0x07ff ) ;
F_6 ( V_212 -> V_230 , V_106 , 0x07fd ) ;
F_13 ( V_217 , true ) ;
V_218 = F_19 ( & V_212 -> V_243 , V_244 ,
V_217 -> V_2 ) ;
if ( V_218 == 0 ) {
F_20 ( 0x50000000 , V_212 -> V_243 ) ;
F_21 ( V_212 -> V_243 ) ;
}
V_218 = F_19 ( & V_212 -> V_245 , V_246 ,
V_217 -> V_2 ) ;
if ( V_218 == 0 ) {
F_20 ( 0x60000000 , V_212 -> V_245 ) ;
F_21 ( V_212 -> V_245 ) ;
}
F_15 ( V_212 -> V_230 , V_106 , 0x1 , 0x0 ) ;
F_18 ( V_212 -> V_230 , false ) ;
F_17 ( V_212 -> V_230 , true ) ;
} else if ( ! V_229 && V_232 ) {
V_232 = false ;
F_17 ( V_212 -> V_230 , false ) ;
F_18 ( V_212 -> V_230 , true ) ;
F_15 ( V_212 -> V_230 , V_106 , 0x1 , 0x1 ) ;
F_13 ( V_217 , false ) ;
F_6 ( V_212 -> V_230 , V_106 , 0x0001 ) ;
F_6 ( V_212 -> V_230 , V_8 , 0x10ec ) ;
F_18 ( V_212 -> V_230 , false ) ;
F_22 ( V_212 -> V_230 ) ;
F_23 ( V_212 -> V_230 ) ;
}
return 0 ;
}
static int F_24 ( struct V_247 * V_248 ,
struct V_249 * V_250 )
{
struct V_251 * V_252 = F_25 ( V_248 ) ;
struct V_211 * V_212 = F_26 ( V_252 ) ;
V_250 -> V_214 . integer . V_214 [ 0 ] = V_212 -> V_253 ;
return 0 ;
}
static int F_27 ( struct V_247 * V_248 ,
struct V_249 * V_250 )
{
struct V_251 * V_252 = F_25 ( V_248 ) ;
struct V_211 * V_212 = F_26 ( V_252 ) ;
struct V_216 * V_217 = F_28 ( V_252 ) ;
V_212 -> V_253 = ! ! V_250 -> V_214 . integer . V_214 [ 0 ] ;
if ( V_217 -> V_254 . V_255 == V_256 )
F_16 ( V_217 , V_212 -> V_253 ) ;
return 0 ;
}
static int F_29 ( struct V_257 * V_258 ,
struct V_247 * V_248 , int V_259 )
{
struct V_216 * V_217 = V_258 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
int V_260 = F_30 ( V_212 -> V_261 ) ;
if ( V_260 < 0 )
F_7 ( V_217 -> V_2 , L_6 ) ;
else
F_15 ( V_212 -> V_230 , V_91 ,
V_262 , V_260 << V_263 ) ;
return V_260 ;
}
static int F_31 ( struct V_257 * V_264 ,
struct V_257 * V_265 )
{
struct V_211 * V_212 = F_14 ( V_264 -> V_217 ) ;
unsigned int V_266 ;
F_10 ( V_212 -> V_230 , V_119 , & V_266 ) ;
V_266 &= V_267 ;
if ( V_266 == V_268 )
return 1 ;
else
return 0 ;
}
static int F_32 ( struct V_257 * V_258 ,
struct V_247 * V_248 , int V_259 )
{
struct V_216 * V_217 = V_258 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_259 ) {
case V_269 :
F_15 ( V_212 -> V_230 , V_105 ,
V_270 , V_270 ) ;
break;
case V_271 :
F_15 ( V_212 -> V_230 , V_105 ,
V_270 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_33 ( struct V_257 * V_258 ,
struct V_247 * V_248 , int V_259 )
{
struct V_216 * V_217 = V_258 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_259 ) {
case V_269 :
F_15 ( V_212 -> V_230 , V_105 ,
V_272 , V_272 ) ;
break;
case V_271 :
F_15 ( V_212 -> V_230 , V_105 ,
V_272 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_34 ( struct V_257 * V_258 ,
struct V_247 * V_248 , int V_259 )
{
struct V_216 * V_217 = V_258 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_259 ) {
case V_273 :
F_15 ( V_212 -> V_230 , V_20 , 0x2 , 0x2 ) ;
break;
case V_269 :
F_15 ( V_212 -> V_230 , V_20 , 0x2 , 0x0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_35 ( struct V_257 * V_258 ,
struct V_247 * V_248 , int V_259 )
{
struct V_216 * V_217 = V_258 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_259 ) {
case V_273 :
F_15 ( V_212 -> V_230 , V_21 , 0x2 , 0x2 ) ;
break;
case V_269 :
F_15 ( V_212 -> V_230 , V_21 , 0x2 , 0x0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_36 ( struct V_257 * V_258 ,
struct V_247 * V_248 , int V_259 )
{
struct V_216 * V_217 = V_258 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_259 ) {
case V_269 :
F_15 ( V_212 -> V_230 , V_105 ,
V_274 | V_275 |
V_276 , V_274 |
V_275 | V_276 ) ;
break;
case V_271 :
F_15 ( V_212 -> V_230 , V_105 ,
V_274 | V_275 |
V_276 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_37 ( struct V_257 * V_258 ,
struct V_247 * V_248 , int V_259 )
{
struct V_216 * V_217 = V_258 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_214 ;
switch ( V_259 ) {
case V_273 :
F_10 ( V_212 -> V_230 , V_77 , & V_214 ) ;
if ( V_214 & V_277 )
F_15 ( V_212 -> V_230 , V_76 ,
V_278 ,
V_279 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_38 ( struct V_257 * V_258 ,
struct V_247 * V_248 , int V_259 )
{
struct V_216 * V_217 = V_258 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_214 ;
switch ( V_259 ) {
case V_273 :
F_10 ( V_212 -> V_230 , V_82 , & V_214 ) ;
if ( V_214 & V_280 )
F_15 ( V_212 -> V_230 , V_81 ,
V_281 ,
V_282 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_39 ( struct V_257 * V_258 ,
struct V_247 * V_248 , int V_259 )
{
struct V_216 * V_217 = V_258 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_259 ) {
case V_269 :
if ( V_217 -> V_254 . V_255 != V_283 &&
! V_212 -> V_284 ) {
F_40 ( 20 ) ;
F_15 ( V_212 -> V_230 , V_104 ,
V_285 | V_286 ,
V_285 | V_286 ) ;
V_212 -> V_284 = true ;
}
break;
default:
return 0 ;
}
return 0 ;
}
static int F_41 ( struct V_287 * V_288 ,
struct V_289 * V_290 , struct V_291 * V_292 )
{
struct V_216 * V_217 = V_292 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_293 = 0 , V_294 , V_295 ;
int V_296 , V_297 , V_298 ;
V_212 -> V_299 [ V_292 -> V_300 ] = F_42 ( V_290 ) ;
V_296 = F_43 ( V_212 -> V_261 , V_212 -> V_299 [ V_292 -> V_300 ] ) ;
if ( V_296 < 0 ) {
F_7 ( V_217 -> V_2 , L_7 ,
V_212 -> V_261 , V_212 -> V_299 [ V_292 -> V_300 ] ) ;
return - V_301 ;
}
V_298 = F_44 ( V_290 ) ;
if ( V_298 < 0 ) {
F_7 ( V_217 -> V_2 , L_8 , V_298 ) ;
return - V_301 ;
}
V_297 = V_298 > 32 ;
V_212 -> V_302 [ V_292 -> V_300 ] = V_212 -> V_299 [ V_292 -> V_300 ] * ( 32 << V_297 ) ;
F_45 ( V_292 -> V_2 , L_9 ,
V_212 -> V_302 [ V_292 -> V_300 ] , V_212 -> V_299 [ V_292 -> V_300 ] ) ;
F_45 ( V_292 -> V_2 , L_10 ,
V_297 , V_296 , V_292 -> V_300 ) ;
switch ( F_46 ( V_290 ) ) {
case 16 :
break;
case 20 :
V_293 |= V_303 ;
break;
case 24 :
V_293 |= V_304 ;
break;
case 8 :
V_293 |= V_305 ;
break;
default:
return - V_301 ;
}
switch ( V_292 -> V_300 ) {
case V_306 :
V_295 = V_307 ;
V_294 = V_296 << V_308 ;
F_15 ( V_212 -> V_230 , V_111 ,
V_309 , V_293 ) ;
F_15 ( V_212 -> V_230 , V_114 ,
V_295 , V_294 ) ;
break;
case V_310 :
V_295 = V_311 ;
V_294 = V_296 << V_312 ;
F_15 ( V_212 -> V_230 , V_112 ,
V_309 , V_293 ) ;
F_15 ( V_212 -> V_230 , V_114 ,
V_295 , V_294 ) ;
break;
case V_313 :
V_295 = V_314 | V_315 ;
V_294 = V_297 << V_316 |
V_296 << V_317 ;
F_15 ( V_212 -> V_230 , V_113 ,
V_309 , V_293 ) ;
F_15 ( V_212 -> V_230 , V_114 ,
V_295 , V_294 ) ;
break;
case V_318 :
V_295 = V_319 | V_320 ;
V_294 = V_297 << V_321 |
V_296 << V_322 ;
F_15 ( V_212 -> V_230 , V_110 ,
V_309 , V_293 ) ;
F_15 ( V_212 -> V_230 , V_114 ,
V_295 , V_294 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_47 ( struct V_291 * V_292 , unsigned int V_323 )
{
struct V_216 * V_217 = V_292 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_324 = 0 ;
switch ( V_323 & V_325 ) {
case V_326 :
V_212 -> V_327 [ V_292 -> V_300 ] = 1 ;
break;
case V_328 :
V_324 |= V_329 ;
V_212 -> V_327 [ V_292 -> V_300 ] = 0 ;
break;
default:
return - V_301 ;
}
switch ( V_323 & V_330 ) {
case V_331 :
break;
case V_332 :
V_324 |= V_333 ;
break;
default:
return - V_301 ;
}
switch ( V_323 & V_334 ) {
case V_335 :
break;
case V_336 :
V_324 |= V_337 ;
break;
case V_338 :
V_324 |= V_339 ;
break;
case V_340 :
V_324 |= V_341 ;
break;
default:
return - V_301 ;
}
switch ( V_292 -> V_300 ) {
case V_306 :
F_15 ( V_212 -> V_230 , V_111 ,
V_342 | V_343 |
V_344 , V_324 ) ;
break;
case V_310 :
F_15 ( V_212 -> V_230 , V_112 ,
V_342 | V_343 |
V_344 , V_324 ) ;
break;
case V_313 :
F_15 ( V_212 -> V_230 , V_113 ,
V_342 | V_343 |
V_344 , V_324 ) ;
break;
case V_318 :
F_15 ( V_212 -> V_230 , V_110 ,
V_342 | V_343 |
V_344 , V_324 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_48 ( struct V_291 * V_292 ,
int V_345 , unsigned int V_346 , int V_347 )
{
struct V_216 * V_217 = V_292 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
unsigned int V_324 = 0 ;
if ( V_346 == V_212 -> V_261 && V_345 == V_212 -> V_348 )
return 0 ;
switch ( V_345 ) {
case V_349 :
V_324 |= V_350 ;
break;
case V_351 :
V_324 |= V_268 ;
break;
case V_352 :
V_324 |= V_353 ;
break;
default:
F_7 ( V_217 -> V_2 , L_11 , V_345 ) ;
return - V_301 ;
}
F_15 ( V_212 -> V_230 , V_119 ,
V_267 , V_324 ) ;
V_212 -> V_261 = V_346 ;
V_212 -> V_348 = V_345 ;
F_45 ( V_292 -> V_2 , L_12 , V_346 , V_345 ) ;
return 0 ;
}
static int F_49 ( const unsigned int V_354 ,
const unsigned int V_355 , struct V_356 * V_357 )
{
if ( V_358 > V_354 )
return - V_301 ;
return F_50 ( V_354 , V_355 , V_357 ) ;
}
static int F_51 ( struct V_291 * V_292 , int V_359 , int V_264 ,
unsigned int V_354 , unsigned int V_355 )
{
struct V_216 * V_217 = V_292 -> V_217 ;
struct V_211 * V_212 = F_14 ( V_217 ) ;
struct V_356 V_357 ;
int V_218 ;
if ( V_264 == V_212 -> V_360 && V_354 == V_212 -> V_361 &&
V_355 == V_212 -> V_362 )
return 0 ;
if ( ! V_354 || ! V_355 ) {
F_45 ( V_217 -> V_2 , L_13 ) ;
V_212 -> V_361 = 0 ;
V_212 -> V_362 = 0 ;
F_15 ( V_212 -> V_230 , V_119 ,
V_267 , V_350 ) ;
return 0 ;
}
switch ( V_264 ) {
case V_363 :
F_15 ( V_212 -> V_230 , V_119 ,
V_364 , V_365 ) ;
break;
case V_366 :
case V_367 :
case V_368 :
case V_369 :
switch ( V_292 -> V_300 ) {
case V_306 :
F_15 ( V_212 -> V_230 , V_119 ,
V_364 , V_370 ) ;
break;
case V_310 :
F_15 ( V_212 -> V_230 , V_119 ,
V_364 , V_371 ) ;
break;
case V_313 :
F_15 ( V_212 -> V_230 , V_119 ,
V_364 , V_372 ) ;
break;
case V_318 :
F_15 ( V_212 -> V_230 , V_119 ,
V_364 , V_373 ) ;
break;
default:
break;
}
break;
default:
F_7 ( V_217 -> V_2 , L_14 , V_264 ) ;
return - V_301 ;
}
V_218 = F_49 ( V_354 , V_355 , & V_357 ) ;
if ( V_218 < 0 ) {
F_7 ( V_217 -> V_2 , L_15 , V_354 ) ;
return V_218 ;
}
F_45 ( V_217 -> V_2 , L_16 ,
V_357 . V_374 , ( V_357 . V_374 ? 0 : V_357 . V_375 ) ,
V_357 . V_376 , V_357 . V_377 ) ;
F_6 ( V_212 -> V_230 , V_117 ,
V_357 . V_376 << V_378 | V_357 . V_377 ) ;
F_6 ( V_212 -> V_230 , V_20 ,
( V_357 . V_374 ? 0 : V_357 . V_375 ) << V_379 |
V_357 . V_374 << V_380 ) ;
V_212 -> V_361 = V_354 ;
V_212 -> V_362 = V_355 ;
V_212 -> V_360 = V_264 ;
return 0 ;
}
static int F_52 ( struct V_291 * V_292 , unsigned int V_381 ,
unsigned int V_382 , int V_383 , int V_384 )
{
struct V_216 * V_217 = V_292 -> V_217 ;
unsigned int V_266 = 0 ;
if ( V_382 || V_381 )
V_266 |= ( 1 << 12 ) ;
switch ( V_383 ) {
case 4 :
V_266 |= ( 1 << 10 ) ;
break;
case 6 :
V_266 |= ( 2 << 10 ) ;
break;
case 8 :
V_266 |= ( 3 << 10 ) ;
break;
case 2 :
default:
break;
}
switch ( V_384 ) {
case 20 :
V_266 |= ( 1 << 8 ) ;
break;
case 24 :
V_266 |= ( 2 << 8 ) ;
break;
case 32 :
V_266 |= ( 3 << 8 ) ;
break;
case 16 :
default:
break;
}
switch ( V_292 -> V_300 ) {
case V_306 :
F_53 ( V_217 , V_76 , 0x1f00 , V_266 ) ;
break;
case V_310 :
F_53 ( V_217 , V_81 , 0x1f00 , V_266 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_54 ( struct V_216 * V_217 ,
enum V_385 V_386 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
switch ( V_386 ) {
case V_283 :
break;
case V_387 :
if ( V_217 -> V_254 . V_255 == V_388 ) {
F_16 ( V_217 , false ) ;
F_15 ( V_212 -> V_230 , V_104 ,
V_235 | V_389 ,
0x0055 ) ;
F_15 ( V_212 -> V_230 ,
V_233 + V_234 ,
0x0f00 , 0x0f00 ) ;
F_15 ( V_212 -> V_230 , V_104 ,
V_285 | V_286 |
V_390 | V_391 |
V_392 | V_393 ,
V_390 | V_391 |
V_392 | V_393 ) ;
V_212 -> V_284 = false ;
F_15 ( V_212 -> V_230 , V_105 ,
V_394 , V_394 ) ;
F_15 ( V_212 -> V_230 , V_208 ,
0x1 , 0x1 ) ;
}
break;
case V_388 :
break;
case V_256 :
F_15 ( V_212 -> V_230 , V_208 , 0x1 , 0x0 ) ;
F_6 ( V_212 -> V_230 , V_102 , 0x0000 ) ;
F_6 ( V_212 -> V_230 , V_103 , 0x0000 ) ;
F_6 ( V_212 -> V_230 , V_104 , 0x0022 ) ;
F_6 ( V_212 -> V_230 , V_105 , 0x0000 ) ;
F_15 ( V_212 -> V_230 ,
V_233 + V_234 , 0x0f00 , 0x0000 ) ;
if ( V_212 -> V_253 )
F_16 ( V_217 , true ) ;
break;
default:
break;
}
V_217 -> V_254 . V_255 = V_386 ;
return 0 ;
}
static inline struct V_211 * F_55 ( struct V_395 * V_396 )
{
return F_56 ( V_396 , struct V_211 , V_395 ) ;
}
static void F_57 ( struct V_395 * V_396 , unsigned V_397 , int V_214 )
{
struct V_211 * V_212 = F_55 ( V_396 ) ;
switch ( V_397 ) {
case V_398 ... V_399 :
F_15 ( V_212 -> V_230 , V_161 ,
0x1 << ( V_397 * 3 + 1 ) , ! ! V_214 << ( V_397 * 3 + 1 ) ) ;
break;
case V_400 :
F_15 ( V_212 -> V_230 , V_162 ,
V_401 , ! ! V_214 << V_402 ) ;
break;
default:
break;
}
}
static int F_58 ( struct V_395 * V_396 ,
unsigned V_397 , int V_214 )
{
struct V_211 * V_212 = F_55 ( V_396 ) ;
switch ( V_397 ) {
case V_398 ... V_399 :
F_15 ( V_212 -> V_230 , V_161 ,
0x3 << ( V_397 * 3 + 1 ) ,
( 0x2 | ! ! V_214 ) << ( V_397 * 3 + 1 ) ) ;
break;
case V_400 :
F_15 ( V_212 -> V_230 , V_162 ,
V_403 | V_401 ,
V_404 | ! ! V_214 << V_402 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_59 ( struct V_395 * V_396 , unsigned V_397 )
{
struct V_211 * V_212 = F_55 ( V_396 ) ;
int V_214 , V_218 ;
V_218 = F_10 ( V_212 -> V_230 , V_29 , & V_214 ) ;
if ( V_218 < 0 )
return V_218 ;
return ( V_214 & ( 0x1 << V_397 ) ) >> V_397 ;
}
static int F_60 ( struct V_395 * V_396 , unsigned V_397 )
{
struct V_211 * V_212 = F_55 ( V_396 ) ;
switch ( V_397 ) {
case V_398 ... V_399 :
F_15 ( V_212 -> V_230 , V_161 ,
0x1 << ( V_397 * 3 + 2 ) , 0x0 ) ;
break;
case V_400 :
F_15 ( V_212 -> V_230 , V_162 ,
V_403 , V_405 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_61 ( struct V_211 * V_212 , unsigned V_397 ,
int V_214 )
{
int V_406 ;
switch ( V_397 ) {
case V_398 ... V_407 :
V_406 = 2 * ( 1 - V_397 ) ;
F_15 ( V_212 -> V_230 ,
V_233 + V_408 ,
0x3 << V_406 ,
( V_214 & 0x3 ) << V_406 ) ;
break;
case V_409 ... V_400 :
V_406 = 2 * ( 9 - V_397 ) ;
F_15 ( V_212 -> V_230 ,
V_233 + V_410 ,
0x3 << V_406 ,
( V_214 & 0x3 ) << V_406 ) ;
break;
default:
break;
}
}
static int F_62 ( struct V_395 * V_396 , unsigned V_397 )
{
struct V_211 * V_212 = F_55 ( V_396 ) ;
struct V_411 * V_412 = V_212 -> V_413 ;
int V_414 ;
if ( V_397 >= V_398 && V_397 <= V_409 ) {
if ( ( V_212 -> V_415 . V_416 == 1 && V_397 == V_398 ) ||
( V_212 -> V_415 . V_416 == 2 &&
V_397 == V_407 ) ||
( V_212 -> V_415 . V_416 == 3 &&
V_397 == V_409 ) ) {
V_414 = V_417 ;
} else {
return - V_418 ;
}
}
if ( V_397 >= V_419 && V_397 <= V_400 ) {
if ( ( V_212 -> V_415 . V_420 == 1 && V_397 == V_419 ) ||
( V_212 -> V_415 . V_420 == 2 &&
V_397 == V_399 ) ||
( V_212 -> V_415 . V_420 == 3 &&
V_397 == V_400 ) ) {
V_414 = V_421 ;
} else if ( ( V_212 -> V_415 . V_422 == 1 &&
V_397 == V_419 ) ||
( V_212 -> V_415 . V_422 == 2 &&
V_397 == V_399 ) ||
( V_212 -> V_415 . V_422 == 3 &&
V_397 == V_400 ) ) {
V_414 = V_423 ;
} else {
return - V_418 ;
}
}
return F_63 ( V_412 , V_414 ) ;
}
static void F_64 ( struct V_424 * V_425 )
{
struct V_211 * V_212 = F_65 ( V_425 ) ;
int V_218 ;
V_212 -> V_395 = V_426 ;
V_212 -> V_395 . V_427 = V_428 ;
V_212 -> V_395 . V_2 = & V_425 -> V_2 ;
V_212 -> V_395 . V_429 = - 1 ;
V_218 = F_66 ( & V_212 -> V_395 ) ;
if ( V_218 != 0 )
F_7 ( & V_425 -> V_2 , L_17 , V_218 ) ;
}
static void F_67 ( struct V_424 * V_425 )
{
struct V_211 * V_212 = F_65 ( V_425 ) ;
F_68 ( & V_212 -> V_395 ) ;
}
static void F_61 ( struct V_211 * V_212 , unsigned V_397 ,
int V_214 )
{
}
static void F_64 ( struct V_424 * V_425 )
{
}
static void F_67 ( struct V_424 * V_425 )
{
}
static int F_69 ( struct V_216 * V_217 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
int V_4 ;
V_212 -> V_217 = V_217 ;
if ( V_212 -> V_415 . V_430 == V_431 ) {
F_70 ( & V_217 -> V_254 ,
V_432 ,
F_2 ( V_432 ) ) ;
} else {
F_70 ( & V_217 -> V_254 ,
V_433 ,
F_2 ( V_433 ) ) ;
}
F_54 ( V_217 , V_256 ) ;
F_6 ( V_212 -> V_230 , V_208 , 0x0020 ) ;
F_6 ( V_212 -> V_230 , V_107 , 0x0c00 ) ;
for ( V_4 = 0 ; V_4 < V_428 ; V_4 ++ )
F_61 ( V_212 , V_4 , V_212 -> V_415 . V_434 [ V_4 ] ) ;
if ( V_212 -> V_413 ) {
F_15 ( V_212 -> V_230 , V_160 , 0x8000 ,
0x8000 ) ;
F_15 ( V_212 -> V_230 , V_208 , 0x0018 ,
0x0008 ) ;
if ( V_212 -> V_415 . V_416 )
F_15 ( V_212 -> V_230 , V_157 ,
V_435 ,
V_212 -> V_415 . V_416 <<
V_436 ) ;
if ( V_212 -> V_415 . V_420 )
F_15 ( V_212 -> V_230 , V_157 ,
V_437 ,
V_212 -> V_415 . V_420 <<
V_438 ) ;
if ( V_212 -> V_415 . V_422 )
F_15 ( V_212 -> V_230 , V_157 ,
V_439 ,
V_212 -> V_415 . V_422 <<
V_440 ) ;
}
F_71 ( & V_212 -> V_219 ) ;
F_71 ( & V_212 -> V_441 ) ;
return 0 ;
}
static int F_72 ( struct V_216 * V_217 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
F_6 ( V_212 -> V_230 , V_8 , 0x10ec ) ;
if ( F_73 ( V_212 -> V_442 ) )
F_74 ( V_212 -> V_442 , 0 ) ;
return 0 ;
}
static int F_75 ( struct V_216 * V_217 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
if ( ! V_212 -> V_253 ) {
F_17 ( V_212 -> V_230 , true ) ;
F_22 ( V_212 -> V_230 ) ;
}
if ( F_73 ( V_212 -> V_442 ) )
F_74 ( V_212 -> V_442 , 0 ) ;
return 0 ;
}
static int F_76 ( struct V_216 * V_217 )
{
struct V_211 * V_212 = F_14 ( V_217 ) ;
if ( F_73 ( V_212 -> V_442 ) ) {
F_74 ( V_212 -> V_442 , 1 ) ;
F_77 ( 10 ) ;
}
if ( ! V_212 -> V_253 ) {
F_17 ( V_212 -> V_230 , false ) ;
F_23 ( V_212 -> V_230 ) ;
}
return 0 ;
}
static int F_78 ( void * V_443 , unsigned int V_3 , unsigned int * V_266 )
{
struct V_424 * V_444 = V_443 ;
struct V_211 * V_212 = F_65 ( V_444 ) ;
if ( V_212 -> V_231 ) {
if ( V_3 > 0xff ) {
F_5 ( & V_212 -> V_441 ) ;
F_11 ( V_212 , V_109 ,
V_3 & 0xff ) ;
F_12 ( V_212 , V_19 , V_266 ) ;
F_8 ( & V_212 -> V_441 ) ;
} else {
F_12 ( V_212 , V_3 , V_266 ) ;
}
} else {
F_10 ( V_212 -> V_220 , V_3 , V_266 ) ;
}
return 0 ;
}
static int F_79 ( void * V_443 , unsigned int V_3 , unsigned int V_266 )
{
struct V_424 * V_444 = V_443 ;
struct V_211 * V_212 = F_65 ( V_444 ) ;
if ( V_212 -> V_231 ) {
if ( V_3 > 0xff ) {
F_5 ( & V_212 -> V_441 ) ;
F_11 ( V_212 , V_109 ,
V_3 & 0xff ) ;
F_11 ( V_212 , V_19 ,
V_266 ) ;
F_8 ( & V_212 -> V_441 ) ;
} else {
F_11 ( V_212 , V_3 , V_266 ) ;
}
} else {
F_6 ( V_212 -> V_220 , V_3 , V_266 ) ;
}
return 0 ;
}
static int F_80 ( struct V_211 * V_212 , struct V_445 * V_446 )
{
V_212 -> V_415 . V_447 = F_81 ( V_446 ,
L_18 ) ;
V_212 -> V_415 . V_448 = F_81 ( V_446 ,
L_19 ) ;
V_212 -> V_415 . V_449 = F_81 ( V_446 ,
L_20 ) ;
V_212 -> V_415 . V_450 = F_81 ( V_446 ,
L_21 ) ;
V_212 -> V_415 . V_451 = F_81 ( V_446 ,
L_22 ) ;
V_212 -> V_442 = F_82 ( V_446 ,
L_23 , 0 ) ;
if ( ! F_73 ( V_212 -> V_442 ) &&
( V_212 -> V_442 != - V_452 ) )
return V_212 -> V_442 ;
F_83 ( V_446 , L_24 ,
V_212 -> V_415 . V_434 , V_428 ) ;
F_84 ( V_446 , L_25 , & V_212 -> V_415 . V_416 ) ;
F_84 ( V_446 , L_26 , & V_212 -> V_415 . V_420 ) ;
F_84 ( V_446 , L_27 , & V_212 -> V_415 . V_422 ) ;
return 0 ;
}
static int F_85 ( struct V_424 * V_425 )
{
int V_218 ;
struct V_211 * V_212 = F_65 ( V_425 ) ;
if ( ! V_212 -> V_415 . V_416 &&
! V_212 -> V_415 . V_420 &&
! V_212 -> V_415 . V_422 )
return 0 ;
if ( ! V_425 -> V_414 ) {
F_7 ( & V_425 -> V_2 , L_28 ) ;
return - V_301 ;
}
V_218 = F_86 ( V_212 -> V_230 , V_425 -> V_414 ,
V_453 | V_454 | V_455 , 0 ,
& V_456 , & V_212 -> V_413 ) ;
if ( V_218 != 0 ) {
F_7 ( & V_425 -> V_2 , L_29 , V_218 ) ;
return V_218 ;
}
return 0 ;
}
static void F_87 ( struct V_424 * V_425 )
{
struct V_211 * V_212 = F_65 ( V_425 ) ;
if ( V_212 -> V_413 )
F_88 ( V_425 -> V_414 , V_212 -> V_413 ) ;
}
static int F_89 ( struct V_424 * V_425 ,
const struct V_457 * V_300 )
{
struct V_458 * V_415 = F_90 ( & V_425 -> V_2 ) ;
struct V_211 * V_212 ;
int V_218 ;
unsigned int V_266 ;
V_212 = F_91 ( & V_425 -> V_2 , sizeof( struct V_211 ) ,
V_459 ) ;
if ( V_212 == NULL )
return - V_460 ;
F_92 ( V_425 , V_212 ) ;
if ( V_415 )
V_212 -> V_415 = * V_415 ;
if ( V_425 -> V_2 . V_461 ) {
V_218 = F_80 ( V_212 , V_425 -> V_2 . V_461 ) ;
if ( V_218 ) {
F_7 ( & V_425 -> V_2 , L_30 ,
V_218 ) ;
return V_218 ;
}
} else {
V_212 -> V_442 = - V_301 ;
}
if ( F_73 ( V_212 -> V_442 ) ) {
V_218 = F_93 ( & V_425 -> V_2 , V_212 -> V_442 ,
V_462 ,
L_31 ) ;
if ( V_218 < 0 ) {
F_7 ( & V_425 -> V_2 , L_32 ,
V_212 -> V_442 , V_218 ) ;
return V_218 ;
}
F_77 ( 10 ) ;
}
V_212 -> V_220 = F_94 ( V_425 ,
& V_463 ) ;
if ( F_95 ( V_212 -> V_220 ) ) {
V_218 = F_96 ( V_212 -> V_220 ) ;
F_7 ( & V_425 -> V_2 , L_33 ,
V_218 ) ;
return V_218 ;
}
V_212 -> V_230 = F_97 ( & V_425 -> V_2 , NULL , V_425 , & V_464 ) ;
if ( F_95 ( V_212 -> V_230 ) ) {
V_218 = F_96 ( V_212 -> V_230 ) ;
F_7 ( & V_425 -> V_2 , L_33 ,
V_218 ) ;
return V_218 ;
}
F_10 ( V_212 -> V_230 , V_37 , & V_266 ) ;
if ( V_266 != V_465 ) {
F_7 ( & V_425 -> V_2 ,
L_34 , V_266 ) ;
return - V_466 ;
}
F_6 ( V_212 -> V_230 , V_8 , 0x10ec ) ;
V_218 = F_98 ( V_212 -> V_230 , V_467 ,
F_2 ( V_467 ) ) ;
if ( V_218 != 0 )
F_99 ( & V_425 -> V_2 , L_35 , V_218 ) ;
if ( V_212 -> V_415 . V_447 )
F_15 ( V_212 -> V_230 , V_39 ,
V_468 , V_468 ) ;
if ( V_212 -> V_415 . V_448 )
F_15 ( V_212 -> V_230 , V_39 ,
V_469 , V_469 ) ;
if ( V_212 -> V_415 . V_449 )
F_15 ( V_212 -> V_230 , V_38 ,
V_470 , V_470 ) ;
if ( V_212 -> V_415 . V_450 )
F_15 ( V_212 -> V_230 , V_38 ,
V_471 , V_471 ) ;
if ( V_212 -> V_415 . V_451 )
F_15 ( V_212 -> V_230 , V_38 ,
V_472 , V_472 ) ;
if ( V_212 -> V_415 . V_430 == V_431 ) {
F_15 ( V_212 -> V_230 , V_210 ,
V_473 ,
V_474 ) ;
F_15 ( V_212 -> V_230 , V_161 ,
V_475 ,
V_476 ) ;
}
F_64 ( V_425 ) ;
F_85 ( V_425 ) ;
return F_100 ( & V_425 -> V_2 , & V_477 ,
V_478 , F_2 ( V_478 ) ) ;
}
static int F_101 ( struct V_424 * V_425 )
{
F_102 ( & V_425 -> V_2 ) ;
F_87 ( V_425 ) ;
F_67 ( V_425 ) ;
return 0 ;
}
