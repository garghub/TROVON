static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 , 0 ) ;
}
static bool F_3 ( struct V_4 * V_5 , unsigned int V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_8 ) ; V_7 ++ ) {
if ( V_6 >= V_8 [ V_7 ] . V_9 &&
V_6 <= V_8 [ V_7 ] . V_10 ) {
return true ;
}
}
switch ( V_6 ) {
case V_3 :
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
return true ;
default:
return false ;
}
}
static bool F_5 ( struct V_4 * V_5 , unsigned int V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_8 ) ; V_7 ++ ) {
if ( V_6 >= V_8 [ V_7 ] . V_9 &&
V_6 <= V_8 [ V_7 ] . V_10 ) {
return true ;
}
}
switch ( V_6 ) {
case V_3 :
case V_27 :
case V_28 :
case V_29 :
case V_12 :
case V_13 :
case V_14 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
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
case V_72 :
case V_73 :
case V_74 :
case V_75 :
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
case V_86 :
case V_11 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
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
case V_15 :
case V_108 :
case V_109 :
case V_16 :
case V_110 :
case V_17 :
case V_111 :
case V_18 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_19 :
case V_20 :
case V_21 :
case V_118 :
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
case V_22 :
case V_129 :
case V_130 :
case V_23 :
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
case V_24 :
case V_25 :
case V_26 :
return true ;
default:
return false ;
}
}
static int F_6 ( struct V_146 * V_147 ,
struct V_148 * V_149 , int V_150 )
{
struct V_1 * V_2 = F_7 ( V_147 -> V_151 ) ;
struct V_152 * V_153 = F_8 ( V_2 ) ;
int V_154 = - V_155 ;
V_154 = F_9 ( V_153 -> V_156 ) ;
if ( V_154 < 0 )
F_10 ( V_2 -> V_5 , L_1 ) ;
else
F_11 ( V_2 , V_91 ,
V_157 , V_154 << V_158 ) ;
return V_154 ;
}
static int F_12 ( struct V_146 * V_159 ,
struct V_146 * V_160 )
{
struct V_1 * V_2 = F_7 ( V_159 -> V_151 ) ;
unsigned int V_161 ;
V_161 = F_13 ( V_2 , V_97 ) ;
V_161 &= V_162 ;
if ( V_161 == V_163 )
return 1 ;
else
return 0 ;
}
static int F_14 ( struct V_146 * V_159 ,
struct V_146 * V_160 )
{
struct V_1 * V_2 = F_7 ( V_159 -> V_151 ) ;
unsigned int V_6 , V_164 , V_161 ;
switch ( V_159 -> V_164 ) {
case 0 :
V_6 = V_102 ;
V_164 = 0 ;
break;
case 1 :
V_6 = V_102 ;
V_164 = 4 ;
break;
case 3 :
V_6 = V_101 ;
V_164 = 0 ;
break;
case 8 :
V_6 = V_101 ;
V_164 = 4 ;
break;
case 9 :
V_6 = V_101 ;
V_164 = 8 ;
break;
case 10 :
V_6 = V_101 ;
V_164 = 12 ;
break;
default:
return 0 ;
}
V_161 = ( F_13 ( V_2 , V_6 ) >> V_164 ) & 0xf ;
switch ( V_161 ) {
case 1 :
case 2 :
case 3 :
case 4 :
return 1 ;
default:
return 0 ;
}
}
int F_15 ( struct V_1 * V_2 ,
unsigned int V_165 , unsigned int V_166 )
{
unsigned int V_167 = 0 ;
unsigned int V_168 = 0 ;
unsigned int V_169 = 0 ;
unsigned int V_170 = 0 ;
switch ( V_166 ) {
case V_171 :
case V_172 :
case V_173 :
case V_174 :
break;
default:
return - V_155 ;
}
if ( V_165 & V_175 ) {
V_167 |= V_176 ;
V_168 = ( V_168 & ~ V_176 )
| ( V_166 << V_177 ) ;
}
if ( V_165 & V_178 ) {
V_167 |= V_179 ;
V_168 = ( V_168 & ~ V_179 )
| ( V_166 << V_180 ) ;
}
if ( V_165 & V_181 ) {
V_167 |= V_182 ;
V_168 = ( V_168 & ~ V_182 )
| ( V_166 << V_183 ) ;
}
if ( V_165 & V_184 ) {
V_167 |= V_185 ;
V_168 = ( V_168 & ~ V_185 )
| ( V_166 << V_186 ) ;
}
if ( V_165 & V_187 ) {
V_169 |= V_188 ;
V_170 = ( V_170 & ~ V_188 )
| ( V_166 << V_189 ) ;
}
if ( V_165 & V_190 ) {
V_169 |= V_191 ;
V_170 = ( V_170 & ~ V_191 )
| ( V_166 << V_192 ) ;
}
if ( V_167 )
F_11 ( V_2 , V_101 ,
V_167 , V_168 ) ;
if ( V_169 )
F_11 ( V_2 , V_102 ,
V_169 , V_170 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , int V_193 )
{
static int V_194 ;
struct V_152 * V_153 = F_8 ( V_2 ) ;
if ( V_193 ) {
if ( V_194 <= 0 ) {
if ( V_153 -> V_195 == V_196 ) {
F_2 ( V_2 , V_197 ,
0x0e06 ) ;
F_2 ( V_2 , V_104 , 0x001d ) ;
F_17 ( V_153 -> V_198 , V_199 +
0x3e , 0x7400 ) ;
F_2 ( V_2 , V_106 , 0x0737 ) ;
F_17 ( V_153 -> V_198 , V_199 +
V_200 , 0xfc00 ) ;
F_2 ( V_2 , V_105 , 0x1140 ) ;
} else {
F_11 ( V_2 , V_105 ,
V_201 , V_202 ) ;
F_2 ( V_2 , V_104 , 0x000d ) ;
F_17 ( V_153 -> V_198 , V_199 +
V_203 , 0x9f01 ) ;
F_18 ( 150 ) ;
F_11 ( V_2 , V_82 ,
V_204 | V_205 , 0 ) ;
F_11 ( V_2 , V_85 ,
V_206 | V_207 ,
V_206 | V_207 ) ;
F_11 ( V_2 , V_82 ,
V_208 | V_209 |
V_210 ,
V_208 | V_209 |
V_210 ) ;
F_18 ( 5 ) ;
F_11 ( V_2 , V_82 ,
V_204 | V_205 ,
V_204 | V_205 ) ;
F_11 ( V_2 , V_104 ,
V_211 | V_212 ,
V_213 | V_214 ) ;
F_17 ( V_153 -> V_198 , V_199 +
0x14 , 0x1aaa ) ;
F_17 ( V_153 -> V_198 , V_199 +
0x24 , 0x0430 ) ;
}
}
V_194 ++ ;
} else {
V_194 -- ;
if ( V_194 <= 0 ) {
if ( V_153 -> V_195 == V_196 ) {
F_17 ( V_153 -> V_198 , V_199 +
0x3e , 0x7400 ) ;
F_2 ( V_2 , V_106 , 0x0737 ) ;
F_17 ( V_153 -> V_198 , V_199 +
V_200 , 0xfc00 ) ;
F_2 ( V_2 , V_105 , 0x1140 ) ;
F_19 ( 100 ) ;
F_2 ( V_2 , V_104 , 0x0001 ) ;
} else {
F_11 ( V_2 , V_104 ,
V_212 |
V_215 |
V_216 ,
V_217 |
V_218 |
V_219 ) ;
F_2 ( V_2 , V_104 , 0x0000 ) ;
F_11 ( V_2 , V_82 ,
V_208 | V_209 |
V_210 , 0 ) ;
F_11 ( V_2 , V_105 ,
V_201 , 0 ) ;
}
}
}
}
static int F_20 ( struct V_146 * V_147 ,
struct V_148 * V_149 , int V_150 )
{
struct V_1 * V_2 = F_7 ( V_147 -> V_151 ) ;
struct V_152 * V_153 = F_8 ( V_2 ) ;
switch ( V_150 ) {
case V_220 :
F_16 ( V_2 , 1 ) ;
if ( V_153 -> V_195 == V_221 ) {
F_11 ( V_2 , V_106 ,
V_222 | V_223 |
V_224 ,
( V_225 << V_226 ) |
( V_227 << V_228 ) |
( V_225 << V_229 ) ) ;
F_17 ( V_153 -> V_198 , V_199 +
V_200 , 0xfc00 ) ;
F_11 ( V_2 , V_104 ,
V_230 , V_231 ) ;
F_11 ( V_2 , V_104 ,
V_232 , V_233 ) ;
F_11 ( V_2 , V_104 ,
V_232 | V_215 |
V_216 , V_234 |
V_235 | V_236 ) ;
F_19 ( 40 ) ;
F_11 ( V_2 , V_104 ,
V_212 | V_215 |
V_216 , V_217 |
V_218 | V_219 ) ;
}
break;
case V_237 :
if ( V_153 -> V_195 == V_221 ) {
F_11 ( V_2 , V_106 ,
V_222 | V_223 |
V_224 ,
( V_238 << V_226 ) |
( V_227 << V_228 ) |
( V_238 << V_229 ) ) ;
F_17 ( V_153 -> V_198 , V_199 +
V_200 , 0xfc00 ) ;
F_11 ( V_2 , V_104 ,
V_212 , V_214 ) ;
F_11 ( V_2 , V_104 ,
V_239 , V_240 ) ;
F_11 ( V_2 , V_104 ,
V_239 | V_215 |
V_216 , V_241 |
V_235 | V_236 ) ;
F_19 ( 30 ) ;
}
F_16 ( V_2 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_21 ( struct V_146 * V_147 ,
struct V_148 * V_149 , int V_150 )
{
struct V_1 * V_2 = F_7 ( V_147 -> V_151 ) ;
switch ( V_150 ) {
case V_220 :
F_11 ( V_2 , V_80 ,
V_242 | V_243 |
V_244 ,
V_242 | V_243 |
V_244 ) ;
break;
case V_237 :
F_11 ( V_2 , V_80 ,
V_242 | V_243 |
V_244 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_22 ( struct V_146 * V_147 ,
struct V_148 * V_149 , int V_150 )
{
struct V_1 * V_2 = F_7 ( V_147 -> V_151 ) ;
switch ( V_150 ) {
case V_220 :
F_16 ( V_2 , 1 ) ;
F_11 ( V_2 , V_82 ,
V_245 , V_245 ) ;
F_11 ( V_2 , V_29 ,
V_246 | V_247 , 0 ) ;
break;
case V_237 :
F_11 ( V_2 , V_29 ,
V_246 | V_247 ,
V_246 | V_247 ) ;
F_11 ( V_2 , V_82 ,
V_245 , 0 ) ;
F_16 ( V_2 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_23 ( struct V_146 * V_147 ,
struct V_148 * V_149 , int V_150 )
{
struct V_1 * V_2 = F_7 ( V_147 -> V_151 ) ;
switch ( V_150 ) {
case V_220 :
F_11 ( V_2 , V_83 ,
V_248 , V_248 ) ;
break;
case V_237 :
F_11 ( V_2 , V_83 ,
V_248 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_24 ( struct V_249 * V_250 ,
struct V_251 * V_252 , struct V_253 * V_254 )
{
struct V_1 * V_2 = V_254 -> V_2 ;
struct V_152 * V_153 = F_8 ( V_2 ) ;
unsigned int V_255 = 0 , V_256 , V_257 , V_258 ;
int V_259 , V_260 , V_261 ;
V_153 -> V_262 [ V_254 -> V_263 ] = F_25 ( V_252 ) ;
V_259 = F_26 ( V_153 -> V_156 , V_153 -> V_262 [ V_254 -> V_263 ] ) ;
if ( V_259 < 0 ) {
F_10 ( V_2 -> V_5 , L_2 ) ;
return - V_155 ;
}
V_261 = F_27 ( V_252 ) ;
if ( V_261 < 0 ) {
F_10 ( V_2 -> V_5 , L_3 , V_261 ) ;
return - V_155 ;
}
switch ( V_153 -> V_195 ) {
case V_196 :
V_258 = 4 ;
break;
default:
V_258 = 2 ;
break;
}
V_260 = V_261 > 32 ;
V_153 -> V_264 [ V_254 -> V_263 ] = V_153 -> V_262 [ V_254 -> V_263 ] * ( 32 << V_260 ) ;
F_28 ( V_254 -> V_5 , L_4 ,
V_153 -> V_264 [ V_254 -> V_263 ] , V_153 -> V_262 [ V_254 -> V_263 ] ) ;
F_28 ( V_254 -> V_5 , L_5 ,
V_260 , V_259 , V_254 -> V_263 ) ;
switch ( F_29 ( V_252 ) ) {
case 16 :
break;
case 20 :
V_255 = 0x1 ;
break;
case 24 :
V_255 = 0x2 ;
break;
case 8 :
V_255 = 0x3 ;
break;
default:
return - V_155 ;
}
switch ( V_254 -> V_263 ) {
case V_265 :
V_257 = V_266 ;
V_256 = V_259 << V_267 ;
F_11 ( V_2 , V_87 ,
( 0x3 << V_258 ) , ( V_255 << V_258 ) ) ;
F_11 ( V_2 , V_89 , V_257 , V_256 ) ;
break;
case V_268 :
V_257 = V_269 | V_270 ;
V_256 = V_260 << V_271 |
V_259 << V_272 ;
F_11 ( V_2 , V_88 ,
( 0x3 << V_258 ) , ( V_255 << V_258 ) ) ;
F_11 ( V_2 , V_89 , V_257 , V_256 ) ;
break;
default:
F_10 ( V_2 -> V_5 , L_6 , V_254 -> V_263 ) ;
return - V_155 ;
}
return 0 ;
}
static int F_30 ( struct V_253 * V_254 , unsigned int V_273 )
{
struct V_1 * V_2 = V_254 -> V_2 ;
struct V_152 * V_153 = F_8 ( V_2 ) ;
unsigned int V_274 = 0 , V_275 ;
switch ( V_153 -> V_195 ) {
case V_196 :
V_275 = 8 ;
break;
default:
V_275 = 7 ;
break;
}
switch ( V_273 & V_276 ) {
case V_277 :
V_153 -> V_278 [ V_254 -> V_263 ] = 1 ;
break;
case V_279 :
V_274 |= V_280 ;
V_153 -> V_278 [ V_254 -> V_263 ] = 0 ;
break;
default:
return - V_155 ;
}
switch ( V_273 & V_281 ) {
case V_282 :
break;
case V_283 :
V_274 |= ( 1 << V_275 ) ;
break;
default:
return - V_155 ;
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
return - V_155 ;
}
switch ( V_254 -> V_263 ) {
case V_265 :
F_11 ( V_2 , V_87 ,
V_292 | ( 1 << V_275 ) |
V_293 , V_274 ) ;
break;
case V_268 :
F_11 ( V_2 , V_88 ,
V_292 | ( 1 << V_275 ) |
V_293 , V_274 ) ;
break;
default:
F_10 ( V_2 -> V_5 , L_6 , V_254 -> V_263 ) ;
return - V_155 ;
}
return 0 ;
}
static int F_31 ( struct V_253 * V_254 ,
int V_294 , unsigned int V_295 , int V_296 )
{
struct V_1 * V_2 = V_254 -> V_2 ;
struct V_152 * V_153 = F_8 ( V_2 ) ;
unsigned int V_274 = 0 ;
if ( V_295 == V_153 -> V_156 && V_294 == V_153 -> V_297 )
return 0 ;
switch ( V_294 ) {
case V_298 :
V_274 |= V_299 ;
break;
case V_300 :
V_274 |= V_163 ;
break;
case V_301 :
V_274 |= V_302 ;
break;
default:
F_10 ( V_2 -> V_5 , L_7 , V_294 ) ;
return - V_155 ;
}
F_11 ( V_2 , V_97 ,
V_162 , V_274 ) ;
V_153 -> V_156 = V_295 ;
V_153 -> V_297 = V_294 ;
F_28 ( V_254 -> V_5 , L_8 , V_295 , V_294 ) ;
return 0 ;
}
static int F_32 ( struct V_253 * V_254 , int V_303 , int V_159 ,
unsigned int V_304 , unsigned int V_305 )
{
struct V_1 * V_2 = V_254 -> V_2 ;
struct V_152 * V_153 = F_8 ( V_2 ) ;
struct V_306 V_307 ;
int V_308 ;
if ( V_159 == V_153 -> V_309 && V_304 == V_153 -> V_310 &&
V_305 == V_153 -> V_311 )
return 0 ;
if ( ! V_304 || ! V_305 ) {
F_28 ( V_2 -> V_5 , L_9 ) ;
V_153 -> V_310 = 0 ;
V_153 -> V_311 = 0 ;
F_11 ( V_2 , V_97 ,
V_162 , V_299 ) ;
return 0 ;
}
switch ( V_159 ) {
case V_312 :
F_11 ( V_2 , V_97 ,
V_313 , V_314 ) ;
break;
case V_315 :
case V_316 :
switch ( V_254 -> V_263 ) {
case V_265 :
F_11 ( V_2 , V_97 ,
V_313 , V_317 ) ;
break;
case V_268 :
F_11 ( V_2 , V_97 ,
V_313 , V_318 ) ;
break;
default:
F_10 ( V_2 -> V_5 , L_6 , V_254 -> V_263 ) ;
return - V_155 ;
}
break;
default:
F_10 ( V_2 -> V_5 , L_10 , V_159 ) ;
return - V_155 ;
}
V_308 = F_33 ( V_304 , V_305 , & V_307 ) ;
if ( V_308 < 0 ) {
F_10 ( V_2 -> V_5 , L_11 , V_304 ) ;
return V_308 ;
}
F_28 ( V_2 -> V_5 , L_12 ,
V_307 . V_319 , ( V_307 . V_319 ? 0 : V_307 . V_320 ) ,
V_307 . V_321 , V_307 . V_322 ) ;
F_2 ( V_2 , V_98 ,
V_307 . V_321 << V_323 | V_307 . V_322 ) ;
F_2 ( V_2 , V_99 ,
( V_307 . V_319 ? 0 : V_307 . V_320 ) << V_324 |
V_307 . V_319 << V_325 ) ;
V_153 -> V_310 = V_304 ;
V_153 -> V_311 = V_305 ;
V_153 -> V_309 = V_159 ;
return 0 ;
}
static int F_34 ( struct V_253 * V_254 , unsigned int V_326 ,
unsigned int V_327 , int V_328 , int V_329 )
{
struct V_1 * V_2 = V_254 -> V_2 ;
struct V_152 * V_153 = F_8 ( V_2 ) ;
unsigned int V_330 , V_331 , V_332 , V_333 , V_334 ;
unsigned int V_335 , V_161 = 0 ;
switch ( V_153 -> V_195 ) {
case V_196 :
V_334 = 15 ;
V_330 = 10 ;
V_331 = 8 ;
V_332 = 6 ;
V_333 = 4 ;
V_335 = 0x8ff0 ;
break;
default:
V_334 = 14 ;
V_330 = V_331 = 12 ;
V_332 = V_333 = 10 ;
V_335 = 0x7c00 ;
break;
}
if ( V_327 || V_326 ) {
V_161 |= ( 1 << V_334 ) ;
if ( V_153 -> V_195 == V_221 )
F_11 ( V_2 , V_121 ,
V_336 , V_337 ) ;
}
switch ( V_328 ) {
case 4 :
V_161 |= ( 1 << V_330 ) | ( 1 << V_331 ) ;
break;
case 6 :
V_161 |= ( 2 << V_330 ) | ( 2 << V_331 ) ;
break;
case 8 :
V_161 |= ( 3 << V_330 ) | ( 3 << V_331 ) ;
break;
case 2 :
default:
break;
}
switch ( V_329 ) {
case 20 :
V_161 |= ( 1 << V_332 ) | ( 1 << V_333 ) ;
break;
case 24 :
V_161 |= ( 2 << V_332 ) | ( 2 << V_333 ) ;
break;
case 32 :
V_161 |= ( 3 << V_332 ) | ( 3 << V_333 ) ;
break;
case 16 :
default:
break;
}
F_11 ( V_2 , V_93 , V_335 , V_161 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
enum V_338 V_339 )
{
struct V_152 * V_153 = F_8 ( V_2 ) ;
switch ( V_339 ) {
case V_340 :
if ( V_341 == V_2 -> V_151 . V_342 ) {
F_11 ( V_2 , V_82 ,
V_343 | V_344 |
V_345 | V_346 ,
V_343 | V_344 |
V_345 | V_346 ) ;
F_18 ( 10 ) ;
F_11 ( V_2 , V_82 ,
V_204 | V_205 ,
V_204 | V_205 ) ;
F_11 ( V_2 , V_143 ,
V_347 , V_347 ) ;
}
break;
case V_341 :
F_11 ( V_2 , V_82 ,
V_343 | V_344 |
V_345 | V_346 ,
V_343 | V_344 |
V_345 | V_346 ) ;
F_11 ( V_2 , V_82 ,
V_204 | V_205 ,
V_204 | V_205 ) ;
break;
case V_348 :
F_2 ( V_2 , V_105 , 0x1100 ) ;
if ( ! V_153 -> V_349 )
F_11 ( V_2 , V_143 ,
V_347 , 0 ) ;
F_11 ( V_2 , V_82 ,
V_343 | V_344 |
V_345 | V_346 |
V_204 | V_205 , 0x0 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_36 ( struct V_152 * V_153 )
{
int V_161 , V_7 ;
int V_308 = - 1 ;
F_37 ( V_153 -> V_198 , true ) ;
F_17 ( V_153 -> V_198 , V_3 , 0 ) ;
F_17 ( V_153 -> V_198 , V_145 , 0x0800 ) ;
F_17 ( V_153 -> V_198 , V_199 + V_350 ,
0x3600 ) ;
F_17 ( V_153 -> V_198 , V_199 + 0x25 , 0x7000 ) ;
F_17 ( V_153 -> V_198 , V_87 , 0x8008 ) ;
F_17 ( V_153 -> V_198 , V_143 , 0x2061 ) ;
F_17 ( V_153 -> V_198 , V_197 , 0x0006 ) ;
F_17 ( V_153 -> V_198 , V_82 , 0x2012 ) ;
F_17 ( V_153 -> V_198 , V_84 , 0x0002 ) ;
F_17 ( V_153 -> V_198 , V_85 , 0x0020 ) ;
F_17 ( V_153 -> V_198 , V_141 , 0x00f0 ) ;
F_17 ( V_153 -> V_198 , V_12 , 0x0006 ) ;
F_17 ( V_153 -> V_198 , V_13 , 0x1827 ) ;
F_17 ( V_153 -> V_198 , V_13 , 0x0827 ) ;
F_19 ( 400 ) ;
F_17 ( V_153 -> V_198 , V_104 , 0x0001 ) ;
F_17 ( V_153 -> V_198 , V_131 , 0xc000 ) ;
F_17 ( V_153 -> V_198 , V_23 , 0x0008 ) ;
F_17 ( V_153 -> V_198 , V_97 , 0x8000 ) ;
F_17 ( V_153 -> V_198 , V_104 , 0x0000 ) ;
F_17 ( V_153 -> V_198 , V_131 , 0xc000 ) ;
F_17 ( V_153 -> V_198 , V_23 , 0x0008 ) ;
F_17 ( V_153 -> V_198 , V_81 , 0x8800 ) ;
F_17 ( V_153 -> V_198 , V_82 , 0xe8fa ) ;
F_17 ( V_153 -> V_198 , V_83 , 0x8c04 ) ;
F_17 ( V_153 -> V_198 , V_105 , 0x3100 ) ;
F_17 ( V_153 -> V_198 , V_197 , 0x0e06 ) ;
F_17 ( V_153 -> V_198 , V_121 , 0x8a13 ) ;
F_17 ( V_153 -> V_198 , V_145 , 0x0820 ) ;
F_17 ( V_153 -> V_198 , V_104 , 0x000d ) ;
F_17 ( V_153 -> V_198 , V_199 + V_203 ,
0x9f01 ) ;
F_19 ( 200 ) ;
for ( V_7 = 0 ; V_7 < 5 ; V_7 ++ ) {
F_38 ( V_153 -> V_198 , V_199 + 0x7a , & V_161 ) ;
if ( V_161 != 0 && V_161 != 0x3f3f ) {
V_308 = 0 ;
break;
}
F_19 ( 50 ) ;
}
F_39 ( L_13 , V_351 , V_161 ) ;
F_17 ( V_153 -> V_198 , V_199 + 0x3e , 0x7400 ) ;
F_17 ( V_153 -> V_198 , V_106 , 0x0737 ) ;
F_17 ( V_153 -> V_198 , V_199 + V_200 ,
0xfc00 ) ;
F_17 ( V_153 -> V_198 , V_105 , 0x1140 ) ;
F_17 ( V_153 -> V_198 , V_104 , 0x0000 ) ;
F_17 ( V_153 -> V_198 , V_144 , 0x4020 ) ;
F_17 ( V_153 -> V_198 , V_83 , 0x0006 ) ;
F_17 ( V_153 -> V_198 , V_81 , 0x0000 ) ;
F_19 ( 350 ) ;
F_37 ( V_153 -> V_198 , false ) ;
return V_308 ;
}
static void F_40 ( struct V_1 * V_2 ,
bool V_352 )
{
struct V_152 * V_153 = F_8 ( V_2 ) ;
if ( V_352 ) {
F_41 ( & V_2 -> V_151 ) ;
F_42 ( & V_2 -> V_151 ,
L_14 ) ;
F_42 ( & V_2 -> V_151 ,
L_15 ) ;
F_42 ( & V_2 -> V_151 ,
L_16 ) ;
F_42 ( & V_2 -> V_151 ,
L_17 ) ;
F_43 ( & V_2 -> V_151 ) ;
F_44 ( & V_2 -> V_151 ) ;
F_11 ( V_2 ,
V_21 , 0x8 , 0x8 ) ;
F_11 ( V_2 ,
V_131 , 0x8000 , 0x8000 ) ;
F_13 ( V_2 , V_23 ) ;
F_39 ( L_18 , V_351 , V_23 ,
F_13 ( V_2 , V_23 ) ) ;
} else {
F_11 ( V_2 , V_131 , 0x8000 , 0x0 ) ;
F_11 ( V_2 , V_21 , 0x8 , 0x0 ) ;
F_41 ( & V_2 -> V_151 ) ;
F_45 ( & V_2 -> V_151 ,
L_14 ) ;
F_45 ( & V_2 -> V_151 ,
L_15 ) ;
if ( V_153 -> V_353 . V_354 == 0 )
F_45 ( & V_2 -> V_151 ,
L_16 ) ;
F_45 ( & V_2 -> V_151 ,
L_17 ) ;
F_43 ( & V_2 -> V_151 ) ;
F_44 ( & V_2 -> V_151 ) ;
}
}
static int F_46 ( struct V_1 * V_2 , int V_355 )
{
struct V_152 * V_153 = F_8 ( V_2 ) ;
unsigned int V_161 ;
if ( V_355 ) {
F_17 ( V_153 -> V_198 , V_197 , 0x0006 ) ;
if ( V_2 -> V_356 . V_357 -> V_358 ) {
F_47 ( & V_2 -> V_151 , L_16 ) ;
F_47 ( & V_2 -> V_151 ,
L_17 ) ;
F_48 ( & V_2 -> V_151 ) ;
} else {
F_49 ( V_153 -> V_198 , V_82 ,
V_344 | V_346 ,
V_344 | V_346 ) ;
F_49 ( V_153 -> V_198 , V_84 ,
V_359 , V_359 ) ;
F_49 ( V_153 -> V_198 , V_85 ,
V_360 , V_360 ) ;
}
F_17 ( V_153 -> V_198 , V_141 , 0x00f0 ) ;
F_17 ( V_153 -> V_198 , V_12 , 0x0006 ) ;
F_49 ( V_153 -> V_198 ,
V_13 , 0x1000 , 0x1000 ) ;
F_19 ( 100 ) ;
F_49 ( V_153 -> V_198 ,
V_13 , 0x1000 , 0x0000 ) ;
F_19 ( 450 ) ;
F_38 ( V_153 -> V_198 , V_14 , & V_161 ) ;
V_161 &= 0x7 ;
F_28 ( V_2 -> V_5 , L_19 , V_161 ) ;
if ( V_161 == 1 || V_161 == 2 ) {
V_153 -> V_361 = V_362 ;
if ( V_153 -> V_349 ) {
F_40 ( V_2 , true ) ;
}
} else {
if ( V_2 -> V_356 . V_357 -> V_358 ) {
F_50 ( & V_2 -> V_151 ,
L_17 ) ;
F_48 ( & V_2 -> V_151 ) ;
} else
F_49 ( V_153 -> V_198 ,
V_85 , V_360 , 0 ) ;
V_153 -> V_361 = V_363 ;
}
} else {
V_153 -> V_361 = 0 ;
if ( V_153 -> V_349 )
F_40 ( V_2 , false ) ;
else {
if ( V_2 -> V_356 . V_357 -> V_358 ) {
if ( V_153 -> V_353 . V_354 == 0 )
F_50 ( & V_2 -> V_151 ,
L_16 ) ;
F_50 ( & V_2 -> V_151 ,
L_17 ) ;
F_48 ( & V_2 -> V_151 ) ;
} else {
if ( V_153 -> V_353 . V_354 == 0 )
F_49 ( V_153 -> V_198 ,
V_84 ,
V_359 , 0 ) ;
F_49 ( V_153 -> V_198 ,
V_85 , V_360 , 0 ) ;
}
}
}
return V_153 -> V_361 ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_364 * V_365 , struct V_364 * V_366 ,
struct V_364 * V_367 )
{
struct V_152 * V_153 = F_8 ( V_2 ) ;
V_153 -> V_365 = V_365 ;
V_153 -> V_366 = V_366 ;
V_153 -> V_367 = V_367 ;
if ( V_153 -> V_367 && V_153 -> V_195 == V_196 ) {
V_153 -> V_349 = true ;
F_49 ( V_153 -> V_198 , V_118 ,
V_368 , V_368 ) ;
F_49 ( V_153 -> V_198 , V_104 ,
V_369 , V_370 ) ;
F_49 ( V_153 -> V_198 , V_143 ,
V_347 , V_347 ) ;
}
F_52 ( 0 , V_153 ) ;
return 0 ;
}
static void F_53 ( struct V_371 * V_372 )
{
struct V_152 * V_153 =
F_54 ( V_372 , struct V_152 , V_373 . V_372 ) ;
F_55 ( V_153 ) ;
}
static T_1 F_52 ( int V_374 , void * V_375 )
{
struct V_152 * V_153 = V_375 ;
F_56 ( V_376 ,
& V_153 -> V_373 , F_57 ( 250 ) ) ;
return V_377 ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_378 , V_161 ;
V_161 = F_13 ( V_2 , V_23 ) ;
F_39 ( L_20 , V_161 ) ;
V_378 = V_161 & 0xfff0 ;
F_2 ( V_2 , V_23 , V_161 ) ;
return V_378 ;
}
static int F_55 ( struct V_152 * V_153 )
{
int V_161 , V_378 , V_379 = 0 , V_380 = 0 ;
if ( ! V_153 -> V_2 )
return - V_155 ;
switch ( V_153 -> V_353 . V_354 ) {
case 0 :
if ( V_153 -> V_381 ) {
V_379 = F_59 ( V_153 -> V_381 ) ;
F_28 ( V_153 -> V_2 -> V_5 , L_21 ,
V_379 ) ;
V_380 = F_46 ( V_153 -> V_2 , V_379 ) ;
}
F_60 ( V_153 -> V_365 ,
V_380 , V_363 ) ;
F_60 ( V_153 -> V_366 ,
V_380 , V_382 ) ;
return V_380 ;
case 1 :
V_161 = F_13 ( V_153 -> V_2 , V_15 ) & 0x0070 ;
break;
default:
V_161 = F_13 ( V_153 -> V_2 , V_15 ) & 0x0020 ;
break;
}
switch ( V_161 ) {
case 0x30 :
case 0x0 :
if ( V_153 -> V_361 == 0 ) {
V_380 = F_46 ( V_153 -> V_2 , 1 ) ;
break;
}
V_378 = 0 ;
if ( F_13 ( V_153 -> V_2 , V_21 ) & 0x4 ) {
V_380 = V_362 ;
V_378 = F_58 ( V_153 -> V_2 ) ;
switch ( V_378 ) {
case 0x8000 :
case 0x4000 :
case 0x2000 :
V_380 |= V_383 ;
break;
case 0x1000 :
case 0x0800 :
case 0x0400 :
V_380 |= V_384 ;
break;
case 0x0200 :
case 0x0100 :
case 0x0080 :
V_380 |= V_385 ;
break;
case 0x0040 :
case 0x0020 :
case 0x0010 :
V_380 |= V_386 ;
break;
case 0x0000 :
break;
default:
F_10 ( V_153 -> V_2 -> V_5 ,
L_22 ,
V_378 ) ;
break;
}
}
if ( V_378 == 0 )
V_380 = V_153 -> V_361 ;
break;
case 0x70 :
case 0x10 :
case 0x20 :
V_380 = 0 ;
F_11 ( V_153 -> V_2 ,
V_21 , 0x1 , 0x0 ) ;
F_46 ( V_153 -> V_2 , 0 ) ;
break;
default:
break;
}
F_60 ( V_153 -> V_365 , V_380 , V_363 ) ;
F_60 ( V_153 -> V_366 , V_380 , V_382 ) ;
if ( V_153 -> V_349 )
F_60 ( V_153 -> V_367 ,
V_380 , V_383 | V_384 |
V_385 | V_386 ) ;
return V_380 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_152 * V_153 = F_8 ( V_2 ) ;
V_153 -> V_2 = V_2 ;
switch ( V_153 -> V_195 ) {
case V_221 :
F_62 ( & V_2 -> V_151 ,
V_387 ,
F_4 ( V_387 ) ) ;
break;
case V_196 :
F_63 ( & V_2 -> V_151 ,
V_388 ,
F_4 ( V_388 ) ) ;
F_62 ( & V_2 -> V_151 ,
V_389 ,
F_4 ( V_389 ) ) ;
break;
}
F_64 ( V_2 , V_348 ) ;
if ( V_153 -> V_353 . V_354 ) {
F_47 ( & V_2 -> V_151 , L_23 ) ;
F_47 ( & V_2 -> V_151 , L_16 ) ;
F_48 ( & V_2 -> V_151 ) ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_152 * V_153 = F_8 ( V_2 ) ;
F_67 ( V_153 -> V_198 , true ) ;
F_68 ( V_153 -> V_198 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_152 * V_153 = F_8 ( V_2 ) ;
F_67 ( V_153 -> V_198 , false ) ;
F_70 ( V_153 -> V_198 ) ;
return 0 ;
}
static int F_71 ( const struct V_390 * V_263 )
{
V_391 = & V_392 ;
return 1 ;
}
static int F_72 ( struct V_152 * V_153 , struct V_4 * V_5 )
{
V_153 -> V_353 . V_393 = F_73 ( V_5 ,
L_24 ) ;
F_74 ( V_5 ,
L_25 , & V_153 -> V_353 . V_394 ) ;
F_74 ( V_5 ,
L_26 , & V_153 -> V_353 . V_395 ) ;
F_74 ( V_5 ,
L_27 , & V_153 -> V_353 . V_354 ) ;
return 0 ;
}
static int F_75 ( struct V_396 * V_397 ,
const struct V_398 * V_263 )
{
struct V_399 * V_353 = F_76 ( & V_397 -> V_5 ) ;
struct V_152 * V_153 ;
int V_308 ;
unsigned int V_161 ;
V_153 = F_77 ( & V_397 -> V_5 , sizeof( struct V_152 ) ,
V_400 ) ;
if ( V_153 == NULL )
return - V_401 ;
V_153 -> V_397 = V_397 ;
F_78 ( V_397 , V_153 ) ;
if ( V_353 )
V_153 -> V_353 = * V_353 ;
else if ( F_79 ( V_402 ) )
V_153 -> V_353 = * V_391 ;
else
F_72 ( V_153 , & V_397 -> V_5 ) ;
V_153 -> V_381 = F_80 ( & V_397 -> V_5 , L_28 ,
V_403 ) ;
if ( F_81 ( V_153 -> V_381 ) ) {
F_10 ( & V_397 -> V_5 , L_29 ) ;
return F_82 ( V_153 -> V_381 ) ;
}
V_153 -> V_198 = F_83 ( V_397 , & V_404 ) ;
if ( F_81 ( V_153 -> V_198 ) ) {
V_308 = F_82 ( V_153 -> V_198 ) ;
F_10 ( & V_397 -> V_5 , L_30 ,
V_308 ) ;
return V_308 ;
}
F_38 ( V_153 -> V_198 , V_26 , & V_161 ) ;
switch ( V_161 ) {
case V_405 :
V_153 -> V_195 = V_221 ;
break;
case V_406 :
V_153 -> V_195 = V_196 ;
break;
default:
F_10 ( & V_397 -> V_5 ,
L_31 ,
V_161 ) ;
return - V_407 ;
}
if ( V_153 -> V_195 == V_196 ) {
V_308 = F_36 ( V_153 ) ;
if ( V_308 < 0 )
F_84 ( L_32 ) ;
}
F_17 ( V_153 -> V_198 , V_3 , 0 ) ;
V_308 = F_85 ( V_153 -> V_198 , V_408 ,
F_4 ( V_408 ) ) ;
if ( V_308 != 0 )
F_86 ( & V_397 -> V_5 , L_33 , V_308 ) ;
if ( V_153 -> V_195 == V_196 ) {
V_308 = F_85 ( V_153 -> V_198 , V_409 ,
F_4 ( V_409 ) ) ;
if ( V_308 != 0 )
F_86 ( & V_397 -> V_5 , L_34 ,
V_308 ) ;
}
if ( V_153 -> V_353 . V_393 )
F_49 ( V_153 -> V_198 , V_30 ,
V_410 , V_410 ) ;
if ( V_153 -> V_353 . V_394 || V_153 -> V_353 . V_395 ) {
F_49 ( V_153 -> V_198 , V_118 ,
V_411 , V_412 ) ;
}
switch ( V_153 -> V_353 . V_394 ) {
case V_413 :
F_49 ( V_153 -> V_198 , V_91 ,
V_414 , V_415 ) ;
break;
case V_416 :
F_49 ( V_153 -> V_198 , V_118 ,
V_417 , V_418 ) ;
F_49 ( V_153 -> V_198 , V_91 ,
V_414 , V_419 ) ;
F_49 ( V_153 -> V_198 , V_118 ,
V_420 , V_421 ) ;
break;
case V_422 :
F_49 ( V_153 -> V_198 , V_91 ,
V_414 , V_423 ) ;
F_49 ( V_153 -> V_198 , V_118 ,
V_424 ,
V_425 ) ;
break;
default:
break;
}
switch ( V_153 -> V_353 . V_395 ) {
case V_426 :
F_49 ( V_153 -> V_198 , V_91 ,
V_427 , V_428 ) ;
break;
case V_429 :
F_49 ( V_153 -> V_198 , V_91 ,
V_427 , V_430 ) ;
F_49 ( V_153 -> V_198 , V_118 ,
V_431 , V_432 ) ;
break;
case V_433 :
F_49 ( V_153 -> V_198 , V_91 ,
V_427 , V_434 ) ;
F_49 ( V_153 -> V_198 , V_118 ,
V_435 ,
V_436 ) ;
break;
case V_437 :
F_49 ( V_153 -> V_198 , V_91 ,
V_427 , V_438 ) ;
F_49 ( V_153 -> V_198 , V_118 ,
V_439 ,
V_440 ) ;
break;
default:
break;
}
if ( V_153 -> V_353 . V_354 ) {
F_49 ( V_153 -> V_198 , V_145 ,
V_441 ,
V_441 ) ;
F_49 ( V_153 -> V_198 , V_12 ,
V_442 , V_442 ) ;
F_49 ( V_153 -> V_198 , V_107 ,
V_443 , V_443 ) ;
F_49 ( V_153 -> V_198 , V_19 ,
V_444 , V_444 ) ;
F_49 ( V_153 -> V_198 , V_145 ,
V_445 , V_445 ) ;
F_49 ( V_153 -> V_198 , V_58 ,
V_446 , V_446 ) ;
F_49 ( V_153 -> V_198 , V_107 ,
V_447 , V_447 ) ;
F_49 ( V_153 -> V_198 , V_118 ,
V_368 , V_368 ) ;
switch ( V_153 -> V_353 . V_354 ) {
case 1 :
F_49 ( V_153 -> V_198 , V_15 ,
V_448 ,
V_449 ) ;
break;
case 2 :
F_49 ( V_153 -> V_198 , V_15 ,
V_448 ,
V_450 ) ;
break;
case 3 :
F_49 ( V_153 -> V_198 , V_15 ,
V_448 ,
V_451 ) ;
break;
default:
break;
}
}
F_87 ( & V_153 -> V_373 , F_53 ) ;
if ( V_153 -> V_397 -> V_374 ) {
V_308 = F_88 ( V_153 -> V_397 -> V_374 , NULL , F_52 ,
V_452 | V_453
| V_454 , L_35 , V_153 ) ;
if ( V_308 )
F_10 ( & V_397 -> V_5 , L_36 , V_308 ) ;
}
return F_89 ( & V_397 -> V_5 , & V_455 ,
V_456 , F_4 ( V_456 ) ) ;
}
static int F_90 ( struct V_396 * V_397 )
{
struct V_152 * V_153 = F_91 ( V_397 ) ;
if ( V_397 -> V_374 )
F_92 ( V_397 -> V_374 , V_153 ) ;
F_93 ( & V_153 -> V_373 ) ;
F_94 ( & V_397 -> V_5 ) ;
return 0 ;
}
