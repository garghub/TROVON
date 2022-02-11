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
case V_108 :
case V_15 :
case V_109 :
case V_110 :
case V_16 :
case V_111 :
case V_17 :
case V_112 :
case V_18 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_19 :
case V_20 :
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
case V_22 :
case V_130 :
case V_131 :
case V_23 :
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
case V_24 :
case V_25 :
case V_26 :
return true ;
default:
return false ;
}
}
static int F_6 ( struct V_147 * V_148 ,
struct V_149 * V_150 , int V_151 )
{
struct V_1 * V_2 = F_7 ( V_148 -> V_152 ) ;
struct V_153 * V_154 = F_8 ( V_2 ) ;
int V_155 , V_156 ;
V_156 = V_154 -> V_157 / F_9 ( V_154 -> V_158 ,
V_89 , V_159 ) ;
V_155 = F_10 ( V_156 ) ;
if ( V_155 < 0 )
F_11 ( V_2 -> V_5 , L_1 ) ;
else
F_12 ( V_2 , V_91 ,
V_160 , V_155 << V_161 ) ;
return V_155 ;
}
static int F_13 ( struct V_147 * V_162 ,
struct V_147 * V_163 )
{
struct V_1 * V_2 = F_7 ( V_162 -> V_152 ) ;
unsigned int V_164 ;
V_164 = F_14 ( V_2 , V_97 ) ;
V_164 &= V_165 ;
if ( V_164 == V_166 )
return 1 ;
else
return 0 ;
}
static int F_15 ( struct V_147 * V_162 ,
struct V_147 * V_163 )
{
struct V_1 * V_2 = F_7 ( V_162 -> V_152 ) ;
unsigned int V_6 , V_167 , V_164 ;
switch ( V_162 -> V_167 ) {
case 0 :
V_6 = V_102 ;
V_167 = 0 ;
break;
case 1 :
V_6 = V_102 ;
V_167 = 4 ;
break;
case 3 :
V_6 = V_101 ;
V_167 = 0 ;
break;
case 8 :
V_6 = V_101 ;
V_167 = 4 ;
break;
case 9 :
V_6 = V_101 ;
V_167 = 8 ;
break;
case 10 :
V_6 = V_101 ;
V_167 = 12 ;
break;
default:
return 0 ;
}
V_164 = ( F_14 ( V_2 , V_6 ) >> V_167 ) & 0xf ;
switch ( V_164 ) {
case 1 :
case 2 :
case 3 :
case 4 :
return 1 ;
default:
return 0 ;
}
}
int F_16 ( struct V_1 * V_2 ,
unsigned int V_168 , unsigned int V_169 )
{
unsigned int V_170 = 0 ;
unsigned int V_171 = 0 ;
unsigned int V_172 = 0 ;
unsigned int V_173 = 0 ;
switch ( V_169 ) {
case V_174 :
case V_175 :
case V_176 :
case V_177 :
break;
default:
return - V_178 ;
}
if ( V_168 & V_179 ) {
V_170 |= V_180 ;
V_171 = ( V_171 & ~ V_180 )
| ( V_169 << V_181 ) ;
}
if ( V_168 & V_182 ) {
V_170 |= V_183 ;
V_171 = ( V_171 & ~ V_183 )
| ( V_169 << V_184 ) ;
}
if ( V_168 & V_185 ) {
V_170 |= V_186 ;
V_171 = ( V_171 & ~ V_186 )
| ( V_169 << V_187 ) ;
}
if ( V_168 & V_188 ) {
V_170 |= V_189 ;
V_171 = ( V_171 & ~ V_189 )
| ( V_169 << V_190 ) ;
}
if ( V_168 & V_191 ) {
V_172 |= V_192 ;
V_173 = ( V_173 & ~ V_192 )
| ( V_169 << V_193 ) ;
}
if ( V_168 & V_194 ) {
V_172 |= V_195 ;
V_173 = ( V_173 & ~ V_195 )
| ( V_169 << V_196 ) ;
}
if ( V_170 )
F_12 ( V_2 , V_101 ,
V_170 , V_171 ) ;
if ( V_172 )
F_12 ( V_2 , V_102 ,
V_172 , V_173 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 , int V_197 )
{
static int V_198 ;
struct V_153 * V_154 = F_8 ( V_2 ) ;
if ( V_197 ) {
if ( V_198 <= 0 ) {
if ( V_154 -> V_199 == V_200 ) {
F_2 ( V_2 , V_105 , 0x3100 ) ;
F_2 ( V_2 , V_107 ,
0x0e06 ) ;
F_2 ( V_2 , V_104 , 0x000d ) ;
F_18 ( V_154 -> V_158 , V_201 +
V_202 , 0x9f01 ) ;
F_19 ( 20 ) ;
F_12 ( V_2 , V_104 ,
V_203 , V_204 ) ;
F_18 ( V_154 -> V_158 , V_201 +
0x3e , 0x7400 ) ;
F_2 ( V_2 , V_106 , 0x0737 ) ;
F_18 ( V_154 -> V_158 , V_201 +
V_205 , 0xfc00 ) ;
F_2 ( V_2 , V_105 , 0x1140 ) ;
F_19 ( 40 ) ;
V_154 -> V_206 = true ;
} else {
F_12 ( V_2 , V_105 ,
V_207 , V_208 ) ;
F_2 ( V_2 , V_104 , 0x000d ) ;
F_18 ( V_154 -> V_158 , V_201 +
V_202 , 0x9f01 ) ;
F_20 ( 150 ) ;
F_12 ( V_2 , V_82 ,
V_209 | V_210 , 0 ) ;
F_12 ( V_2 , V_85 ,
V_211 | V_212 ,
V_211 | V_212 ) ;
F_12 ( V_2 , V_82 ,
V_213 | V_214 |
V_215 ,
V_213 | V_214 |
V_215 ) ;
F_20 ( 5 ) ;
F_12 ( V_2 , V_82 ,
V_209 | V_210 ,
V_209 | V_210 ) ;
F_12 ( V_2 , V_104 ,
V_203 | V_216 ,
V_204 | V_217 ) ;
F_18 ( V_154 -> V_158 , V_201 +
0x14 , 0x1aaa ) ;
F_18 ( V_154 -> V_158 , V_201 +
0x24 , 0x0430 ) ;
}
}
V_198 ++ ;
} else {
V_198 -- ;
if ( V_198 <= 0 ) {
if ( V_154 -> V_199 == V_200 ) {
F_18 ( V_154 -> V_158 , V_201 +
0x3e , 0x7400 ) ;
F_2 ( V_2 , V_106 , 0x0737 ) ;
F_18 ( V_154 -> V_158 , V_201 +
V_205 , 0xfc00 ) ;
F_2 ( V_2 , V_105 , 0x1140 ) ;
F_19 ( 100 ) ;
F_2 ( V_2 , V_104 , 0x0001 ) ;
} else {
F_12 ( V_2 , V_104 ,
V_216 |
V_218 |
V_219 ,
V_220 |
V_221 |
V_222 ) ;
F_2 ( V_2 , V_104 , 0x0000 ) ;
F_12 ( V_2 , V_82 ,
V_213 | V_214 |
V_215 , 0 ) ;
F_12 ( V_2 , V_105 ,
V_207 , 0 ) ;
}
}
}
}
static int F_21 ( struct V_147 * V_148 ,
struct V_149 * V_150 , int V_151 )
{
struct V_1 * V_2 = F_7 ( V_148 -> V_152 ) ;
struct V_153 * V_154 = F_8 ( V_2 ) ;
switch ( V_151 ) {
case V_223 :
F_17 ( V_2 , 1 ) ;
if ( V_154 -> V_199 == V_224 ) {
F_12 ( V_2 , V_106 ,
V_225 | V_226 |
V_227 ,
( V_228 << V_229 ) |
( V_230 << V_231 ) |
( V_228 << V_232 ) ) ;
F_18 ( V_154 -> V_158 , V_201 +
V_205 , 0xfc00 ) ;
F_12 ( V_2 , V_104 ,
V_233 , V_234 ) ;
F_12 ( V_2 , V_104 ,
V_235 , V_236 ) ;
F_12 ( V_2 , V_104 ,
V_235 | V_218 |
V_219 , V_237 |
V_238 | V_239 ) ;
F_19 ( 40 ) ;
F_12 ( V_2 , V_104 ,
V_216 | V_218 |
V_219 , V_220 |
V_221 | V_222 ) ;
}
break;
case V_240 :
if ( V_154 -> V_199 == V_224 ) {
F_12 ( V_2 , V_106 ,
V_225 | V_226 |
V_227 ,
( V_241 << V_229 ) |
( V_230 << V_231 ) |
( V_241 << V_232 ) ) ;
F_18 ( V_154 -> V_158 , V_201 +
V_205 , 0xfc00 ) ;
F_12 ( V_2 , V_104 ,
V_216 , V_217 ) ;
F_12 ( V_2 , V_104 ,
V_242 , V_243 ) ;
F_12 ( V_2 , V_104 ,
V_242 | V_218 |
V_219 , V_244 |
V_238 | V_239 ) ;
F_19 ( 30 ) ;
}
F_17 ( V_2 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_22 ( struct V_147 * V_148 ,
struct V_149 * V_150 , int V_151 )
{
struct V_1 * V_2 = F_7 ( V_148 -> V_152 ) ;
switch ( V_151 ) {
case V_223 :
F_12 ( V_2 , V_80 ,
V_245 | V_246 |
V_247 ,
V_245 | V_246 |
V_247 ) ;
break;
case V_240 :
F_12 ( V_2 , V_80 ,
V_245 | V_246 |
V_247 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_23 ( struct V_147 * V_148 ,
struct V_149 * V_150 , int V_151 )
{
struct V_1 * V_2 = F_7 ( V_148 -> V_152 ) ;
switch ( V_151 ) {
case V_223 :
F_17 ( V_2 , 1 ) ;
F_12 ( V_2 , V_82 ,
V_248 , V_248 ) ;
F_12 ( V_2 , V_29 ,
V_249 | V_250 , 0 ) ;
break;
case V_240 :
F_12 ( V_2 , V_29 ,
V_249 | V_250 ,
V_249 | V_250 ) ;
F_12 ( V_2 , V_82 ,
V_248 , 0 ) ;
F_17 ( V_2 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_24 ( struct V_147 * V_148 ,
struct V_149 * V_150 , int V_151 )
{
struct V_1 * V_2 = F_7 ( V_148 -> V_152 ) ;
switch ( V_151 ) {
case V_223 :
F_12 ( V_2 , V_83 ,
V_251 , V_251 ) ;
break;
case V_240 :
F_12 ( V_2 , V_83 ,
V_251 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_25 ( struct V_147 * V_148 ,
struct V_149 * V_252 , int V_151 )
{
struct V_1 * V_2 = F_7 ( V_148 -> V_152 ) ;
struct V_153 * V_154 = F_8 ( V_2 ) ;
switch ( V_151 ) {
case V_223 :
if ( V_154 -> V_206 ) {
F_19 ( 100 ) ;
V_154 -> V_206 = false ;
}
break;
default:
return 0 ;
}
return 0 ;
}
static int F_26 ( struct V_253 * V_254 ,
struct V_255 * V_256 , struct V_257 * V_258 )
{
struct V_1 * V_2 = V_258 -> V_2 ;
struct V_153 * V_154 = F_8 ( V_2 ) ;
unsigned int V_259 = 0 , V_260 , V_261 , V_262 ;
int V_263 , V_264 , V_265 ;
V_154 -> V_266 [ V_258 -> V_267 ] = F_27 ( V_256 ) ;
V_263 = F_28 ( V_154 -> V_157 , V_154 -> V_266 [ V_258 -> V_267 ] ) ;
if ( V_263 < 0 ) {
F_11 ( V_2 -> V_5 , L_2 ) ;
return - V_178 ;
}
V_265 = F_29 ( V_256 ) ;
if ( V_265 < 0 ) {
F_11 ( V_2 -> V_5 , L_3 , V_265 ) ;
return - V_178 ;
}
switch ( V_154 -> V_199 ) {
case V_200 :
V_262 = 4 ;
break;
default:
V_262 = 2 ;
break;
}
V_264 = V_265 > 32 ;
V_154 -> V_268 [ V_258 -> V_267 ] = V_154 -> V_266 [ V_258 -> V_267 ] * ( 32 << V_264 ) ;
F_30 ( V_258 -> V_5 , L_4 ,
V_154 -> V_268 [ V_258 -> V_267 ] , V_154 -> V_266 [ V_258 -> V_267 ] ) ;
F_30 ( V_258 -> V_5 , L_5 ,
V_264 , V_263 , V_258 -> V_267 ) ;
switch ( F_31 ( V_256 ) ) {
case 16 :
break;
case 20 :
V_259 = 0x1 ;
break;
case 24 :
V_259 = 0x2 ;
break;
case 8 :
V_259 = 0x3 ;
break;
default:
return - V_178 ;
}
switch ( V_258 -> V_267 ) {
case V_269 :
V_261 = V_270 ;
V_260 = V_263 << V_159 ;
F_12 ( V_2 , V_87 ,
( 0x3 << V_262 ) , ( V_259 << V_262 ) ) ;
F_12 ( V_2 , V_89 , V_261 , V_260 ) ;
break;
case V_271 :
V_261 = V_272 | V_273 ;
V_260 = V_264 << V_274 |
V_263 << V_275 ;
F_12 ( V_2 , V_88 ,
( 0x3 << V_262 ) , ( V_259 << V_262 ) ) ;
F_12 ( V_2 , V_89 , V_261 , V_260 ) ;
break;
default:
F_11 ( V_2 -> V_5 , L_6 , V_258 -> V_267 ) ;
return - V_178 ;
}
return 0 ;
}
static int F_32 ( struct V_257 * V_258 , unsigned int V_276 )
{
struct V_1 * V_2 = V_258 -> V_2 ;
struct V_153 * V_154 = F_8 ( V_2 ) ;
unsigned int V_277 = 0 , V_278 ;
switch ( V_154 -> V_199 ) {
case V_200 :
V_278 = 8 ;
break;
default:
V_278 = 7 ;
break;
}
switch ( V_276 & V_279 ) {
case V_280 :
V_154 -> V_281 [ V_258 -> V_267 ] = 1 ;
break;
case V_282 :
V_277 |= V_283 ;
V_154 -> V_281 [ V_258 -> V_267 ] = 0 ;
break;
default:
return - V_178 ;
}
switch ( V_276 & V_284 ) {
case V_285 :
break;
case V_286 :
V_277 |= ( 1 << V_278 ) ;
break;
default:
return - V_178 ;
}
switch ( V_276 & V_287 ) {
case V_288 :
break;
case V_289 :
V_277 |= V_290 ;
break;
case V_291 :
V_277 |= V_292 ;
break;
case V_293 :
V_277 |= V_294 ;
break;
default:
return - V_178 ;
}
switch ( V_258 -> V_267 ) {
case V_269 :
F_12 ( V_2 , V_87 ,
V_295 | ( 1 << V_278 ) |
V_296 , V_277 ) ;
break;
case V_271 :
F_12 ( V_2 , V_88 ,
V_295 | ( 1 << V_278 ) |
V_296 , V_277 ) ;
break;
default:
F_11 ( V_2 -> V_5 , L_6 , V_258 -> V_267 ) ;
return - V_178 ;
}
return 0 ;
}
static int F_33 ( struct V_257 * V_258 ,
int V_297 , unsigned int V_298 , int V_299 )
{
struct V_1 * V_2 = V_258 -> V_2 ;
struct V_153 * V_154 = F_8 ( V_2 ) ;
unsigned int V_277 = 0 ;
if ( V_298 == V_154 -> V_157 && V_297 == V_154 -> V_300 )
return 0 ;
switch ( V_297 ) {
case V_301 :
V_277 |= V_302 ;
break;
case V_303 :
V_277 |= V_166 ;
break;
case V_304 :
V_277 |= V_305 ;
break;
default:
F_11 ( V_2 -> V_5 , L_7 , V_297 ) ;
return - V_178 ;
}
F_12 ( V_2 , V_97 ,
V_165 , V_277 ) ;
V_154 -> V_157 = V_298 ;
V_154 -> V_300 = V_297 ;
F_30 ( V_258 -> V_5 , L_8 , V_298 , V_297 ) ;
return 0 ;
}
static int F_34 ( struct V_257 * V_258 , int V_306 , int V_162 ,
unsigned int V_307 , unsigned int V_308 )
{
struct V_1 * V_2 = V_258 -> V_2 ;
struct V_153 * V_154 = F_8 ( V_2 ) ;
struct V_309 V_310 ;
int V_311 ;
if ( V_162 == V_154 -> V_312 && V_307 == V_154 -> V_313 &&
V_308 == V_154 -> V_314 )
return 0 ;
if ( ! V_307 || ! V_308 ) {
F_30 ( V_2 -> V_5 , L_9 ) ;
V_154 -> V_313 = 0 ;
V_154 -> V_314 = 0 ;
F_12 ( V_2 , V_97 ,
V_165 , V_302 ) ;
return 0 ;
}
switch ( V_162 ) {
case V_315 :
F_12 ( V_2 , V_97 ,
V_316 , V_317 ) ;
break;
case V_318 :
case V_319 :
switch ( V_258 -> V_267 ) {
case V_269 :
F_12 ( V_2 , V_97 ,
V_316 , V_320 ) ;
break;
case V_271 :
F_12 ( V_2 , V_97 ,
V_316 , V_321 ) ;
break;
default:
F_11 ( V_2 -> V_5 , L_6 , V_258 -> V_267 ) ;
return - V_178 ;
}
break;
default:
F_11 ( V_2 -> V_5 , L_10 , V_162 ) ;
return - V_178 ;
}
V_311 = F_35 ( V_307 , V_308 , & V_310 ) ;
if ( V_311 < 0 ) {
F_11 ( V_2 -> V_5 , L_11 , V_307 ) ;
return V_311 ;
}
F_30 ( V_2 -> V_5 , L_12 ,
V_310 . V_322 , ( V_310 . V_322 ? 0 : V_310 . V_323 ) ,
V_310 . V_324 , V_310 . V_325 ) ;
F_2 ( V_2 , V_98 ,
V_310 . V_324 << V_326 | V_310 . V_325 ) ;
F_2 ( V_2 , V_99 ,
( V_310 . V_322 ? 0 : V_310 . V_323 ) << V_327 |
V_310 . V_322 << V_328 ) ;
V_154 -> V_313 = V_307 ;
V_154 -> V_314 = V_308 ;
V_154 -> V_312 = V_162 ;
return 0 ;
}
static int F_36 ( struct V_257 * V_258 , unsigned int V_329 ,
unsigned int V_330 , int V_331 , int V_332 )
{
struct V_1 * V_2 = V_258 -> V_2 ;
struct V_153 * V_154 = F_8 ( V_2 ) ;
unsigned int V_333 , V_334 , V_335 , V_336 , V_337 ;
unsigned int V_338 , V_164 = 0 ;
switch ( V_154 -> V_199 ) {
case V_200 :
V_337 = 15 ;
V_333 = 10 ;
V_334 = 8 ;
V_335 = 6 ;
V_336 = 4 ;
V_338 = 0x8ff0 ;
break;
default:
V_337 = 14 ;
V_333 = V_334 = 12 ;
V_335 = V_336 = 10 ;
V_338 = 0x7c00 ;
break;
}
if ( V_330 || V_329 ) {
V_164 |= ( 1 << V_337 ) ;
if ( V_154 -> V_199 == V_224 )
F_12 ( V_2 , V_122 ,
V_339 , V_340 ) ;
}
switch ( V_331 ) {
case 4 :
V_164 |= ( 1 << V_333 ) | ( 1 << V_334 ) ;
break;
case 6 :
V_164 |= ( 2 << V_333 ) | ( 2 << V_334 ) ;
break;
case 8 :
V_164 |= ( 3 << V_333 ) | ( 3 << V_334 ) ;
break;
case 2 :
default:
break;
}
switch ( V_332 ) {
case 20 :
V_164 |= ( 1 << V_335 ) | ( 1 << V_336 ) ;
break;
case 24 :
V_164 |= ( 2 << V_335 ) | ( 2 << V_336 ) ;
break;
case 32 :
V_164 |= ( 3 << V_335 ) | ( 3 << V_336 ) ;
break;
case 16 :
default:
break;
}
F_12 ( V_2 , V_93 , V_338 , V_164 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
enum V_341 V_342 )
{
struct V_153 * V_154 = F_8 ( V_2 ) ;
switch ( V_342 ) {
case V_343 :
if ( V_344 == F_38 ( V_2 ) ) {
F_12 ( V_2 , V_82 ,
V_345 | V_346 |
V_347 | V_348 ,
V_345 | V_346 |
V_347 | V_348 ) ;
F_20 ( 10 ) ;
F_12 ( V_2 , V_82 ,
V_209 | V_210 ,
V_209 | V_210 ) ;
F_12 ( V_2 , V_144 ,
V_349 , V_349 ) ;
}
break;
case V_344 :
F_12 ( V_2 , V_82 ,
V_345 | V_346 |
V_347 | V_348 ,
V_345 | V_346 |
V_347 | V_348 ) ;
F_12 ( V_2 , V_82 ,
V_209 | V_210 ,
V_209 | V_210 ) ;
break;
case V_350 :
F_2 ( V_2 , V_105 , 0x1100 ) ;
if ( ! V_154 -> V_351 )
F_12 ( V_2 , V_144 ,
V_349 , 0 ) ;
F_12 ( V_2 , V_82 ,
V_345 | V_346 |
V_347 | V_348 |
V_209 | V_210 , 0x0 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_39 ( struct V_1 * V_2 ,
bool V_352 )
{
struct V_353 * V_152 = F_40 ( V_2 ) ;
if ( V_352 ) {
F_41 ( V_152 , L_13 ) ;
F_41 ( V_152 , L_14 ) ;
F_42 ( V_152 ) ;
F_12 ( V_2 ,
V_21 , 0x8 , 0x8 ) ;
F_12 ( V_2 ,
V_132 , 0x8000 , 0x8000 ) ;
F_14 ( V_2 , V_23 ) ;
F_43 ( L_15 , V_354 , V_23 ,
F_14 ( V_2 , V_23 ) ) ;
} else {
F_12 ( V_2 , V_132 , 0x8000 , 0x0 ) ;
F_12 ( V_2 , V_21 , 0x8 , 0x0 ) ;
F_44 ( V_152 , L_13 ) ;
F_44 ( V_152 , L_14 ) ;
F_42 ( V_152 ) ;
}
}
static int F_45 ( struct V_1 * V_2 , int V_355 )
{
struct V_353 * V_152 = F_40 ( V_2 ) ;
struct V_153 * V_154 = F_8 ( V_2 ) ;
unsigned int V_164 ;
if ( V_355 ) {
F_18 ( V_154 -> V_158 , V_107 , 0x0006 ) ;
F_41 ( V_152 , L_16 ) ;
F_41 ( V_152 , L_17 ) ;
F_42 ( V_152 ) ;
if ( ! V_152 -> V_356 -> V_357 ) {
F_46 ( V_154 -> V_158 , V_82 ,
V_346 | V_348 ,
V_346 | V_348 ) ;
F_46 ( V_154 -> V_158 , V_84 ,
V_358 , V_358 ) ;
F_46 ( V_154 -> V_158 , V_85 ,
V_359 , V_359 ) ;
}
F_18 ( V_154 -> V_158 , V_142 , 0x00f0 ) ;
F_46 ( V_154 -> V_158 , V_13 ,
V_360 , V_360 ) ;
F_46 ( V_154 -> V_158 , V_12 ,
V_361 , V_361 ) ;
F_19 ( 100 ) ;
F_46 ( V_154 -> V_158 , V_13 ,
V_360 , 0 ) ;
F_19 ( 600 ) ;
F_47 ( V_154 -> V_158 , V_14 , & V_164 ) ;
V_164 &= 0x7 ;
F_30 ( V_2 -> V_5 , L_18 , V_164 ) ;
if ( V_164 == 1 || V_164 == 2 ) {
V_154 -> V_362 = V_363 ;
if ( V_154 -> V_351 ) {
F_39 ( V_2 , true ) ;
}
} else {
F_44 ( V_152 , L_17 ) ;
F_42 ( V_152 ) ;
V_154 -> V_362 = V_364 ;
}
} else {
V_154 -> V_362 = 0 ;
F_46 ( V_154 -> V_158 , V_28 ,
V_249 | V_250 ,
V_249 | V_250 ) ;
F_46 ( V_154 -> V_158 , V_13 ,
V_360 , V_360 ) ;
F_46 ( V_154 -> V_158 , V_12 ,
V_361 , 0 ) ;
if ( V_154 -> V_351 )
F_39 ( V_2 , false ) ;
if ( V_154 -> V_365 . V_366 == 0 )
F_44 ( V_152 , L_16 ) ;
F_44 ( V_152 , L_17 ) ;
F_42 ( V_152 ) ;
}
return V_154 -> V_362 ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_367 , V_164 ;
V_164 = F_14 ( V_2 , V_23 ) ;
F_43 ( L_19 , V_164 ) ;
V_367 = V_164 & 0xfff0 ;
F_2 ( V_2 , V_23 , V_164 ) ;
return V_367 ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_368 * V_369 , struct V_368 * V_370 ,
struct V_368 * V_371 )
{
struct V_153 * V_154 = F_8 ( V_2 ) ;
V_154 -> V_369 = V_369 ;
V_154 -> V_370 = V_370 ;
V_154 -> V_371 = V_371 ;
if ( V_154 -> V_371 && V_154 -> V_199 == V_200 ) {
V_154 -> V_351 = true ;
F_46 ( V_154 -> V_158 , V_119 ,
V_372 , V_372 ) ;
F_46 ( V_154 -> V_158 , V_144 ,
V_349 , V_349 ) ;
}
F_50 ( 0 , V_154 ) ;
return 0 ;
}
static void F_51 ( struct V_373 * V_374 )
{
struct V_153 * V_154 =
F_52 ( V_374 , struct V_153 , V_375 . V_374 ) ;
int V_164 , V_367 , V_376 = 0 , V_377 = 0 ;
if ( ! V_154 -> V_2 )
return;
switch ( V_154 -> V_365 . V_366 ) {
case 0 :
if ( V_154 -> V_378 ) {
V_376 = F_53 ( V_154 -> V_378 ) ;
F_30 ( V_154 -> V_2 -> V_5 , L_20 ,
V_376 ) ;
V_377 = F_45 ( V_154 -> V_2 , V_376 ) ;
}
F_54 ( V_154 -> V_369 ,
V_377 , V_364 ) ;
F_54 ( V_154 -> V_370 ,
V_377 , V_379 ) ;
return;
case 1 :
V_164 = F_14 ( V_154 -> V_2 , V_15 ) & 0x0070 ;
break;
default:
V_164 = F_14 ( V_154 -> V_2 , V_15 ) & 0x0020 ;
break;
}
switch ( V_164 ) {
case 0x30 :
case 0x0 :
if ( V_154 -> V_362 == 0 ) {
V_377 = F_45 ( V_154 -> V_2 , 1 ) ;
break;
}
V_367 = 0 ;
if ( F_14 ( V_154 -> V_2 , V_21 ) & 0x4 ) {
V_377 = V_363 ;
V_367 = F_48 ( V_154 -> V_2 ) ;
switch ( V_367 ) {
case 0x8000 :
case 0x4000 :
case 0x2000 :
V_377 |= V_380 ;
break;
case 0x1000 :
case 0x0800 :
case 0x0400 :
V_377 |= V_381 ;
break;
case 0x0200 :
case 0x0100 :
case 0x0080 :
V_377 |= V_382 ;
break;
case 0x0040 :
case 0x0020 :
case 0x0010 :
V_377 |= V_383 ;
break;
case 0x0000 :
break;
default:
F_11 ( V_154 -> V_2 -> V_5 ,
L_21 ,
V_367 ) ;
break;
}
}
if ( V_367 == 0 )
V_377 = V_154 -> V_362 ;
break;
case 0x70 :
case 0x10 :
case 0x20 :
V_377 = 0 ;
F_12 ( V_154 -> V_2 ,
V_21 , 0x1 , 0x0 ) ;
F_45 ( V_154 -> V_2 , 0 ) ;
break;
default:
break;
}
F_54 ( V_154 -> V_369 , V_377 , V_364 ) ;
F_54 ( V_154 -> V_370 , V_377 , V_379 ) ;
if ( V_154 -> V_351 )
F_54 ( V_154 -> V_371 ,
V_377 , V_380 | V_381 |
V_382 | V_383 ) ;
}
static T_1 F_50 ( int V_384 , void * V_385 )
{
struct V_153 * V_154 = V_385 ;
F_55 ( V_386 ,
& V_154 -> V_375 , F_56 ( 250 ) ) ;
return V_387 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_353 * V_152 = F_40 ( V_2 ) ;
struct V_153 * V_154 = F_8 ( V_2 ) ;
V_154 -> V_2 = V_2 ;
switch ( V_154 -> V_199 ) {
case V_224 :
F_58 ( V_152 ,
V_388 ,
F_4 ( V_388 ) ) ;
F_59 ( V_152 ,
V_389 ,
F_4 ( V_389 ) ) ;
break;
case V_200 :
F_58 ( V_152 ,
V_390 ,
F_4 ( V_390 ) ) ;
F_59 ( V_152 ,
V_391 ,
F_4 ( V_391 ) ) ;
break;
}
F_60 ( V_2 , V_350 ) ;
if ( V_154 -> V_365 . V_366 ) {
F_41 ( V_152 , L_22 ) ;
F_41 ( V_152 , L_16 ) ;
F_42 ( V_152 ) ;
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_153 * V_154 = F_8 ( V_2 ) ;
F_63 ( V_154 -> V_158 , true ) ;
F_64 ( V_154 -> V_158 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_153 * V_154 = F_8 ( V_2 ) ;
F_63 ( V_154 -> V_158 , false ) ;
F_66 ( V_154 -> V_158 ) ;
return 0 ;
}
static int F_67 ( const struct V_392 * V_267 )
{
V_393 = & V_394 ;
return 1 ;
}
static int F_68 ( struct V_153 * V_154 , struct V_4 * V_5 )
{
V_154 -> V_365 . V_395 = F_69 ( V_5 ,
L_23 ) ;
F_70 ( V_5 ,
L_24 , & V_154 -> V_365 . V_396 ) ;
F_70 ( V_5 ,
L_25 , & V_154 -> V_365 . V_397 ) ;
F_70 ( V_5 ,
L_26 , & V_154 -> V_365 . V_366 ) ;
return 0 ;
}
static int F_71 ( struct V_398 * V_399 ,
const struct V_400 * V_267 )
{
struct V_401 * V_365 = F_72 ( & V_399 -> V_5 ) ;
struct V_153 * V_154 ;
int V_311 , V_7 ;
unsigned int V_164 ;
V_154 = F_73 ( & V_399 -> V_5 , sizeof( struct V_153 ) ,
V_402 ) ;
if ( V_154 == NULL )
return - V_403 ;
V_154 -> V_399 = V_399 ;
F_74 ( V_399 , V_154 ) ;
if ( V_365 )
V_154 -> V_365 = * V_365 ;
else if ( F_75 ( V_404 ) )
V_154 -> V_365 = * V_393 ;
else
F_68 ( V_154 , & V_399 -> V_5 ) ;
V_154 -> V_378 = F_76 ( & V_399 -> V_5 , L_27 ,
V_405 ) ;
if ( F_77 ( V_154 -> V_378 ) ) {
F_11 ( & V_399 -> V_5 , L_28 ) ;
return F_78 ( V_154 -> V_378 ) ;
}
V_154 -> V_158 = F_79 ( V_399 , & V_406 ) ;
if ( F_77 ( V_154 -> V_158 ) ) {
V_311 = F_78 ( V_154 -> V_158 ) ;
F_11 ( & V_399 -> V_5 , L_29 ,
V_311 ) ;
return V_311 ;
}
for ( V_7 = 0 ; V_7 < F_4 ( V_154 -> V_407 ) ; V_7 ++ )
V_154 -> V_407 [ V_7 ] . V_408 = V_409 [ V_7 ] ;
V_311 = F_80 ( & V_399 -> V_5 ,
F_4 ( V_154 -> V_407 ) ,
V_154 -> V_407 ) ;
if ( V_311 ) {
F_11 ( & V_399 -> V_5 , L_30 , V_311 ) ;
return V_311 ;
}
V_311 = F_81 ( F_4 ( V_154 -> V_407 ) ,
V_154 -> V_407 ) ;
if ( V_311 ) {
F_11 ( & V_399 -> V_5 , L_31 , V_311 ) ;
return V_311 ;
}
F_47 ( V_154 -> V_158 , V_26 , & V_164 ) ;
switch ( V_164 ) {
case V_410 :
V_154 -> V_199 = V_224 ;
break;
case V_411 :
V_154 -> V_199 = V_200 ;
break;
default:
F_11 ( & V_399 -> V_5 ,
L_32 ,
V_164 ) ;
V_311 = - V_412 ;
goto V_413;
}
F_18 ( V_154 -> V_158 , V_3 , 0 ) ;
V_311 = F_82 ( V_154 -> V_158 , V_414 ,
F_4 ( V_414 ) ) ;
if ( V_311 != 0 )
F_83 ( & V_399 -> V_5 , L_33 , V_311 ) ;
if ( V_154 -> V_199 == V_200 ) {
V_311 = F_82 ( V_154 -> V_158 , V_415 ,
F_4 ( V_415 ) ) ;
if ( V_311 != 0 )
F_83 ( & V_399 -> V_5 , L_34 ,
V_311 ) ;
}
if ( V_154 -> V_365 . V_395 )
F_46 ( V_154 -> V_158 , V_30 ,
V_416 , V_416 ) ;
if ( V_154 -> V_365 . V_396 || V_154 -> V_365 . V_397 ) {
F_46 ( V_154 -> V_158 , V_119 ,
V_417 , V_418 ) ;
}
switch ( V_154 -> V_365 . V_396 ) {
case V_419 :
F_46 ( V_154 -> V_158 , V_91 ,
V_420 , V_421 ) ;
break;
case V_422 :
F_46 ( V_154 -> V_158 , V_119 ,
V_423 , V_424 ) ;
F_46 ( V_154 -> V_158 , V_91 ,
V_420 , V_425 ) ;
F_46 ( V_154 -> V_158 , V_119 ,
V_426 , V_427 ) ;
break;
case V_428 :
F_46 ( V_154 -> V_158 , V_91 ,
V_420 , V_429 ) ;
F_46 ( V_154 -> V_158 , V_119 ,
V_430 ,
V_431 ) ;
break;
default:
break;
}
switch ( V_154 -> V_365 . V_397 ) {
case V_432 :
F_46 ( V_154 -> V_158 , V_91 ,
V_433 , V_434 ) ;
break;
case V_435 :
F_46 ( V_154 -> V_158 , V_91 ,
V_433 , V_436 ) ;
F_46 ( V_154 -> V_158 , V_119 ,
V_437 , V_438 ) ;
break;
case V_439 :
F_46 ( V_154 -> V_158 , V_91 ,
V_433 , V_440 ) ;
F_46 ( V_154 -> V_158 , V_119 ,
V_441 ,
V_442 ) ;
break;
case V_443 :
F_46 ( V_154 -> V_158 , V_91 ,
V_433 , V_444 ) ;
F_46 ( V_154 -> V_158 , V_119 ,
V_445 ,
V_446 ) ;
break;
default:
break;
}
if ( V_154 -> V_365 . V_366 ) {
F_46 ( V_154 -> V_158 , V_146 ,
V_447 ,
V_447 ) ;
F_46 ( V_154 -> V_158 , V_108 ,
V_448 , V_448 ) ;
F_46 ( V_154 -> V_158 , V_19 ,
V_449 , V_449 ) ;
F_46 ( V_154 -> V_158 , V_146 ,
V_450 , V_450 ) ;
F_46 ( V_154 -> V_158 , V_58 ,
V_451 , V_451 ) ;
F_46 ( V_154 -> V_158 , V_108 ,
V_452 , V_452 ) ;
F_46 ( V_154 -> V_158 , V_119 ,
V_372 , V_372 ) ;
switch ( V_154 -> V_365 . V_366 ) {
case 1 :
F_46 ( V_154 -> V_158 , V_15 ,
V_453 ,
V_454 ) ;
break;
case 2 :
F_46 ( V_154 -> V_158 , V_15 ,
V_453 ,
V_455 ) ;
break;
case 3 :
F_46 ( V_154 -> V_158 , V_15 ,
V_453 ,
V_456 ) ;
break;
default:
break;
}
}
F_84 ( & V_154 -> V_375 , F_51 ) ;
if ( V_154 -> V_399 -> V_384 ) {
V_311 = F_85 ( V_154 -> V_399 -> V_384 , NULL , F_50 ,
V_457 | V_458
| V_459 , L_35 , V_154 ) ;
if ( V_311 ) {
F_11 ( & V_399 -> V_5 , L_36 , V_311 ) ;
goto V_413;
}
}
V_311 = F_86 ( & V_399 -> V_5 , & V_460 ,
V_461 , F_4 ( V_461 ) ) ;
if ( V_311 )
goto V_462;
return 0 ;
V_462:
if ( V_154 -> V_399 -> V_384 )
F_87 ( V_154 -> V_399 -> V_384 , V_154 ) ;
V_413:
F_88 ( F_4 ( V_154 -> V_407 ) , V_154 -> V_407 ) ;
return V_311 ;
}
static int F_89 ( struct V_398 * V_399 )
{
struct V_153 * V_154 = F_90 ( V_399 ) ;
if ( V_399 -> V_384 )
F_87 ( V_399 -> V_384 , V_154 ) ;
F_91 ( & V_154 -> V_375 ) ;
F_92 ( & V_399 -> V_5 ) ;
F_88 ( F_4 ( V_154 -> V_407 ) , V_154 -> V_407 ) ;
return 0 ;
}
static void F_93 ( struct V_398 * V_399 )
{
struct V_153 * V_154 = F_90 ( V_399 ) ;
F_46 ( V_154 -> V_158 , V_146 ,
V_463 , V_463 ) ;
F_46 ( V_154 -> V_158 , V_13 , V_360 ,
V_360 ) ;
F_46 ( V_154 -> V_158 , V_12 , V_361 ,
0 ) ;
}
