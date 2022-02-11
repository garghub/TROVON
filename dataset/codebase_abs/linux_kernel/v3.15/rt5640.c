static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 , 0 ) ;
}
static bool F_3 ( struct V_4 * V_5 , unsigned int V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_8 ) ; V_7 ++ )
if ( ( V_6 >= V_8 [ V_7 ] . V_9 &&
V_6 <= V_8 [ V_7 ] . V_9 +
V_8 [ V_7 ] . V_10 ) ||
( V_6 >= V_8 [ V_7 ] . V_11 &&
V_6 <= V_8 [ V_7 ] . V_12 ) )
return true ;
switch ( V_6 ) {
case V_3 :
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
return true ;
default:
return false ;
}
}
static bool F_5 ( struct V_4 * V_5 , unsigned int V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_8 ) ; V_7 ++ )
if ( ( V_6 >= V_8 [ V_7 ] . V_9 &&
V_6 <= V_8 [ V_7 ] . V_9 +
V_8 [ V_7 ] . V_10 ) ||
( V_6 >= V_8 [ V_7 ] . V_11 &&
V_6 <= V_8 [ V_7 ] . V_12 ) )
return true ;
switch ( V_6 ) {
case V_3 :
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
case V_21 :
case V_22 :
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
case V_13 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_14 :
case V_95 :
case V_96 :
case V_15 :
case V_97 :
case V_98 :
case V_99 :
case V_16 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_17 :
case V_18 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_19 :
case V_20 :
case V_109 :
case V_23 :
case V_110 :
case V_24 :
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
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_25 :
case V_26 :
case V_27 :
return true ;
default:
return false ;
}
}
static int F_6 ( struct V_127 * V_128 ,
struct V_129 * V_130 , int V_131 )
{
struct V_1 * V_2 = V_128 -> V_2 ;
struct V_132 * V_133 = F_7 ( V_2 ) ;
int div [] = { 2 , 3 , 4 , 6 , 8 , 12 } ;
int V_134 = - V_135 , V_7 ;
int V_136 , V_137 , V_138 , V_139 ;
V_136 = V_133 -> V_140 ;
V_137 = 3000000 * 12 ;
for ( V_7 = 0 ; V_7 < F_4 ( div ) ; V_7 ++ ) {
V_138 = div [ V_7 ] * 3000000 ;
if ( V_136 > V_138 )
continue;
V_139 = V_138 - V_136 ;
if ( V_139 < V_137 ) {
V_137 = V_139 ;
V_134 = V_7 ;
}
}
if ( V_134 < 0 )
F_8 ( V_2 -> V_5 , L_1 ) ;
else
F_9 ( V_2 , V_78 , V_141 ,
V_134 << V_142 ) ;
return V_134 ;
}
static int F_10 ( struct V_127 * V_143 ,
struct V_127 * V_144 )
{
unsigned int V_145 ;
V_145 = F_11 ( V_143 -> V_2 , V_79 ) ;
V_145 &= V_146 ;
if ( V_145 == V_147 || V_145 == V_148 )
return 1 ;
else
return 0 ;
}
static int F_12 ( struct V_127 * V_128 ,
struct V_129 * V_130 , int V_131 )
{
struct V_1 * V_2 = V_128 -> V_2 ;
switch ( V_131 ) {
case V_149 :
F_9 ( V_2 , V_105 ,
V_150 | V_151 ,
V_152 | V_153 ) ;
F_9 ( V_2 , V_78 ,
V_154 | V_155 |
V_156 ,
V_157 | V_158 |
V_159 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_13 ( struct V_127 * V_128 ,
struct V_129 * V_130 , int V_131 )
{
struct V_1 * V_2 = V_128 -> V_2 ;
switch ( V_131 ) {
case V_149 :
F_9 ( V_2 , V_105 ,
V_150 | V_160 ,
V_152 | V_161 ) ;
F_9 ( V_2 , V_78 ,
V_162 | V_163 |
V_164 ,
V_165 | V_166 |
V_167 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_132 * V_133 = F_7 ( V_2 ) ;
F_15 ( V_133 -> V_168 , V_169 +
V_170 , 0x0700 , 0x0200 ) ;
F_15 ( V_133 -> V_168 , V_90 ,
V_171 , V_172 ) ;
F_15 ( V_133 -> V_168 , V_89 ,
V_173 | V_174 | V_175 ,
V_176 | V_177 | V_178 ) ;
F_16 ( V_133 -> V_168 , V_169 + V_179 ,
0x9f00 ) ;
F_15 ( V_133 -> V_168 , V_70 ,
V_180 | V_181 , 0 ) ;
F_15 ( V_133 -> V_168 , V_70 ,
V_182 ,
V_182 ) ;
F_17 ( 10000 , 15000 ) ;
F_15 ( V_133 -> V_168 , V_70 ,
V_180 | V_181 ,
V_180 | V_181 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_132 * V_133 = F_7 ( V_2 ) ;
F_15 ( V_133 -> V_168 , V_90 ,
V_171 | V_183 ,
V_184 | V_185 ) ;
F_15 ( V_133 -> V_168 , V_92 ,
V_186 , V_187 ) ;
F_15 ( V_133 -> V_168 , V_91 ,
V_188 | V_189 | V_190 ,
( V_191 << V_192 ) |
( V_193 << V_194 ) |
( V_191 << V_195 ) ) ;
F_16 ( V_133 -> V_168 , V_169 +
V_196 , 0x1c00 ) ;
F_15 ( V_133 -> V_168 , V_89 ,
V_173 | V_174 ,
V_197 | V_198 ) ;
F_15 ( V_133 -> V_168 , V_169 +
V_170 , 0x0700 , 0x0400 ) ;
}
static int F_19 ( struct V_127 * V_128 ,
struct V_129 * V_130 , int V_131 )
{
struct V_1 * V_2 = V_128 -> V_2 ;
struct V_132 * V_133 = F_7 ( V_2 ) ;
switch ( V_131 ) {
case V_199 :
F_18 ( V_2 ) ;
V_133 -> V_200 = 0 ;
break;
case V_201 :
V_133 -> V_200 = 1 ;
F_17 ( 70000 , 75000 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_20 ( struct V_127 * V_128 ,
struct V_129 * V_130 , int V_131 )
{
struct V_1 * V_2 = V_128 -> V_2 ;
switch ( V_131 ) {
case V_199 :
F_14 ( V_2 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_21 ( struct V_127 * V_128 ,
struct V_129 * V_130 , int V_131 )
{
struct V_1 * V_2 = V_128 -> V_2 ;
struct V_132 * V_133 = F_7 ( V_2 ) ;
switch ( V_131 ) {
case V_199 :
if ( ! V_133 -> V_200 )
F_17 ( 80000 , 85000 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , int V_202 )
{
int V_203 = 0 , V_145 ;
if ( V_2 == NULL )
return - V_135 ;
V_145 = F_11 ( V_2 , V_74 ) ;
V_145 = ( V_145 & V_204 ) >> V_205 ;
switch ( V_202 ) {
case V_206 :
switch ( V_145 ) {
case V_207 :
case V_208 :
V_203 |= V_209 ;
break;
case V_210 :
V_203 |= V_209 ;
case V_211 :
case V_212 :
V_203 |= V_213 ;
break;
}
break;
case V_214 :
switch ( V_145 ) {
case V_215 :
case V_212 :
V_203 |= V_209 ;
break;
case V_216 :
V_203 |= V_209 ;
case V_207 :
case V_217 :
V_203 |= V_213 ;
break;
}
break;
default:
V_203 = - V_135 ;
break;
}
return V_203 ;
}
static int F_23 ( int V_218 , int V_136 )
{
int V_7 , V_219 [] = { 1 , 2 , 3 , 4 , 6 , 8 , 12 , 16 } ;
if ( V_218 <= 0 || V_136 <= 0 )
return - V_135 ;
V_136 = V_136 << 8 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_219 ) ; V_7 ++ )
if ( V_218 == V_136 * V_219 [ V_7 ] )
return V_7 ;
return - V_135 ;
}
static int F_24 ( struct V_220 * V_221 ,
struct V_222 * V_223 , struct V_224 * V_225 )
{
struct V_1 * V_2 = V_225 -> V_2 ;
struct V_132 * V_133 = F_7 ( V_2 ) ;
unsigned int V_226 = 0 , V_227 , V_228 ;
int V_229 , V_230 , V_231 , V_232 ;
V_133 -> V_233 [ V_225 -> V_234 ] = F_25 ( V_223 ) ;
V_230 = F_23 ( V_133 -> V_140 , V_133 -> V_233 [ V_225 -> V_234 ] ) ;
if ( V_230 < 0 ) {
F_8 ( V_2 -> V_5 , L_2 ,
V_133 -> V_233 [ V_225 -> V_234 ] , V_225 -> V_234 ) ;
return - V_135 ;
}
V_232 = F_26 ( V_223 ) ;
if ( V_232 < 0 ) {
F_8 ( V_2 -> V_5 , L_3 , V_232 ) ;
return V_232 ;
}
if ( V_232 > 32 )
V_231 = 1 ;
else
V_231 = 0 ;
V_133 -> V_235 [ V_225 -> V_234 ] = V_133 -> V_233 [ V_225 -> V_234 ] * ( 32 << V_231 ) ;
F_27 ( V_225 -> V_5 , L_4 ,
V_133 -> V_235 [ V_225 -> V_234 ] , V_133 -> V_233 [ V_225 -> V_234 ] ) ;
F_27 ( V_225 -> V_5 , L_5 ,
V_231 , V_230 , V_225 -> V_234 ) ;
switch ( F_28 ( V_223 ) ) {
case V_236 :
break;
case V_237 :
V_226 |= V_238 ;
break;
case V_239 :
V_226 |= V_240 ;
break;
case V_241 :
V_226 |= V_242 ;
break;
default:
return - V_135 ;
}
V_229 = F_22 ( V_2 , V_225 -> V_234 ) ;
if ( V_229 < 0 ) {
F_8 ( V_2 -> V_5 , L_6 , V_229 ) ;
return - V_135 ;
}
if ( V_229 & V_209 ) {
V_228 = V_243 | V_244 ;
V_227 = V_231 << V_245 |
V_230 << V_246 ;
F_9 ( V_2 , V_74 ,
V_247 , V_226 ) ;
F_9 ( V_2 , V_76 , V_228 , V_227 ) ;
}
if ( V_229 & V_213 ) {
V_228 = V_248 | V_249 ;
V_227 = V_231 << V_250 |
V_230 << V_251 ;
F_9 ( V_2 , V_75 ,
V_247 , V_226 ) ;
F_9 ( V_2 , V_76 , V_228 , V_227 ) ;
}
return 0 ;
}
static int F_29 ( struct V_224 * V_225 , unsigned int V_252 )
{
struct V_1 * V_2 = V_225 -> V_2 ;
struct V_132 * V_133 = F_7 ( V_2 ) ;
unsigned int V_253 = 0 ;
int V_229 ;
switch ( V_252 & V_254 ) {
case V_255 :
V_133 -> V_256 [ V_225 -> V_234 ] = 1 ;
break;
case V_257 :
V_253 |= V_258 ;
V_133 -> V_256 [ V_225 -> V_234 ] = 0 ;
break;
default:
return - V_135 ;
}
switch ( V_252 & V_259 ) {
case V_260 :
break;
case V_261 :
V_253 |= V_262 ;
break;
default:
return - V_135 ;
}
switch ( V_252 & V_263 ) {
case V_264 :
break;
case V_265 :
V_253 |= V_266 ;
break;
case V_267 :
V_253 |= V_268 ;
break;
case V_269 :
V_253 |= V_270 ;
break;
default:
return - V_135 ;
}
V_229 = F_22 ( V_2 , V_225 -> V_234 ) ;
if ( V_229 < 0 ) {
F_8 ( V_2 -> V_5 , L_6 , V_229 ) ;
return - V_135 ;
}
if ( V_229 & V_209 ) {
F_9 ( V_2 , V_74 ,
V_271 | V_272 |
V_273 , V_253 ) ;
}
if ( V_229 & V_213 ) {
F_9 ( V_2 , V_75 ,
V_271 | V_272 |
V_273 , V_253 ) ;
}
return 0 ;
}
static int F_30 ( struct V_224 * V_225 ,
int V_274 , unsigned int V_275 , int V_276 )
{
struct V_1 * V_2 = V_225 -> V_2 ;
struct V_132 * V_133 = F_7 ( V_2 ) ;
unsigned int V_253 = 0 ;
if ( V_275 == V_133 -> V_140 && V_274 == V_133 -> V_277 )
return 0 ;
switch ( V_274 ) {
case V_278 :
V_253 |= V_279 ;
break;
case V_280 :
V_253 |= V_147 ;
break;
case V_281 :
V_253 |= V_148 ;
break;
case V_282 :
V_253 |= V_283 ;
break;
default:
F_8 ( V_2 -> V_5 , L_7 , V_274 ) ;
return - V_135 ;
}
F_9 ( V_2 , V_79 ,
V_146 , V_253 ) ;
V_133 -> V_140 = V_275 ;
V_133 -> V_277 = V_274 ;
F_27 ( V_225 -> V_5 , L_8 , V_275 , V_274 ) ;
return 0 ;
}
static int F_31 ( const unsigned int V_284 ,
const unsigned int V_285 , struct V_286 * V_287 )
{
int V_288 = V_289 , V_290 = V_291 ;
int V_292 = 0 , V_293 = 0 , V_137 , V_294 , V_295 , V_296 , V_297 ;
int V_298 = abs ( V_285 - V_284 ) ;
bool V_299 = false ;
if ( V_300 < V_284 || V_301 > V_284 )
return - V_135 ;
for ( V_294 = 0 ; V_294 <= V_288 ; V_294 ++ ) {
V_296 = ( V_284 >> 1 ) + ( V_284 >> 2 ) * V_294 ;
if ( V_296 < 0 )
continue;
if ( V_296 == V_285 ) {
V_299 = true ;
V_292 = V_294 ;
goto V_302;
}
for ( V_295 = 0 ; V_295 <= V_290 ; V_295 ++ ) {
V_297 = V_296 / ( V_295 + 2 ) ;
V_137 = abs ( V_297 - V_285 ) ;
if ( V_137 < V_298 ) {
V_292 = V_294 ;
V_293 = V_295 ;
if ( V_137 == 0 )
goto V_302;
V_298 = V_137 ;
}
}
}
F_32 ( L_9 ) ;
V_302:
V_287 -> V_303 = V_299 ;
V_287 -> V_304 = V_293 ;
V_287 -> V_305 = V_292 ;
V_287 -> V_306 = 2 ;
return 0 ;
}
static int F_33 ( struct V_224 * V_225 , int V_307 , int V_143 ,
unsigned int V_284 , unsigned int V_285 )
{
struct V_1 * V_2 = V_225 -> V_2 ;
struct V_132 * V_133 = F_7 ( V_2 ) ;
struct V_286 * V_287 = & V_133 -> V_287 ;
int V_203 , V_229 ;
if ( V_143 == V_133 -> V_308 && V_284 == V_133 -> V_309 &&
V_285 == V_133 -> V_310 )
return 0 ;
if ( ! V_284 || ! V_285 ) {
F_27 ( V_2 -> V_5 , L_10 ) ;
V_133 -> V_309 = 0 ;
V_133 -> V_310 = 0 ;
F_9 ( V_2 , V_79 ,
V_146 , V_279 ) ;
return 0 ;
}
switch ( V_143 ) {
case V_311 :
F_9 ( V_2 , V_79 ,
V_312 , V_313 ) ;
break;
case V_314 :
case V_315 :
V_229 = F_22 ( V_2 , V_225 -> V_234 ) ;
if ( V_229 < 0 ) {
F_8 ( V_2 -> V_5 ,
L_6 , V_229 ) ;
return - V_135 ;
}
if ( V_229 & V_209 ) {
F_9 ( V_2 , V_79 ,
V_312 , V_316 ) ;
}
if ( V_229 & V_213 ) {
F_9 ( V_2 , V_79 ,
V_312 , V_317 ) ;
}
break;
default:
F_8 ( V_2 -> V_5 , L_11 , V_143 ) ;
return - V_135 ;
}
V_203 = F_31 ( V_284 , V_285 , V_287 ) ;
if ( V_203 < 0 ) {
F_8 ( V_2 -> V_5 , L_12 , V_284 ) ;
return V_203 ;
}
F_27 ( V_2 -> V_5 , L_13 , V_287 -> V_303 ,
( V_287 -> V_303 ? 0 : V_287 -> V_304 ) , V_287 -> V_305 ) ;
F_2 ( V_2 , V_80 ,
V_287 -> V_305 << V_318 | V_287 -> V_306 ) ;
F_2 ( V_2 , V_81 ,
( V_287 -> V_303 ? 0 : V_287 -> V_304 ) << V_319 |
V_287 -> V_303 << V_320 ) ;
V_133 -> V_309 = V_284 ;
V_133 -> V_310 = V_285 ;
V_133 -> V_308 = V_143 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
enum V_321 V_322 )
{
struct V_132 * V_133 = F_7 ( V_2 ) ;
switch ( V_322 ) {
case V_323 :
if ( V_324 == V_2 -> V_325 . V_326 ) {
F_35 ( V_133 -> V_168 , false ) ;
F_9 ( V_2 , V_70 ,
V_327 | V_328 |
V_329 | V_330 ,
V_327 | V_328 |
V_329 | V_330 ) ;
F_17 ( 10000 , 15000 ) ;
F_9 ( V_2 , V_70 ,
V_180 | V_181 ,
V_180 | V_181 ) ;
F_36 ( V_133 -> V_168 ) ;
F_9 ( V_2 , V_124 ,
0x0301 , 0x0301 ) ;
F_9 ( V_2 , V_94 ,
0x0030 , 0x0030 ) ;
}
break;
case V_324 :
F_2 ( V_2 , V_89 , 0x0004 ) ;
F_2 ( V_2 , V_90 , 0x1100 ) ;
F_9 ( V_2 , V_124 , 0x1 , 0 ) ;
F_2 ( V_2 , V_68 , 0x0000 ) ;
F_2 ( V_2 , V_69 , 0x0000 ) ;
F_2 ( V_2 , V_73 , 0x0000 ) ;
F_2 ( V_2 , V_72 , 0x0000 ) ;
F_2 ( V_2 , V_70 , 0x0000 ) ;
F_2 ( V_2 , V_71 , 0x0000 ) ;
break;
default:
break;
}
V_2 -> V_325 . V_326 = V_322 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_132 * V_133 = F_7 ( V_2 ) ;
V_133 -> V_2 = V_2 ;
V_2 -> V_325 . V_331 = 1 ;
F_34 ( V_2 , V_324 ) ;
F_9 ( V_2 , V_124 , 0x0301 , 0x0301 ) ;
F_9 ( V_2 , V_94 , 0x0030 , 0x0030 ) ;
F_9 ( V_2 , V_48 , 0xfc00 , 0x0c00 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_132 * V_133 = F_7 ( V_2 ) ;
F_34 ( V_2 , V_324 ) ;
F_1 ( V_2 ) ;
F_35 ( V_133 -> V_168 , true ) ;
F_40 ( V_133 -> V_168 ) ;
if ( F_41 ( V_133 -> V_332 . V_333 ) )
F_42 ( V_133 -> V_332 . V_333 , 0 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_132 * V_133 = F_7 ( V_2 ) ;
if ( F_41 ( V_133 -> V_332 . V_333 ) ) {
F_42 ( V_133 -> V_332 . V_333 , 1 ) ;
F_44 ( 400 ) ;
}
return 0 ;
}
static int F_45 ( struct V_132 * V_133 , struct V_334 * V_335 )
{
V_133 -> V_332 . V_336 = F_46 ( V_335 ,
L_14 ) ;
V_133 -> V_332 . V_337 = F_46 ( V_335 ,
L_15 ) ;
V_133 -> V_332 . V_333 = F_47 ( V_335 ,
L_16 , 0 ) ;
if ( ! F_41 ( V_133 -> V_332 . V_333 ) &&
( V_133 -> V_332 . V_333 != - V_338 ) )
return V_133 -> V_332 . V_333 ;
return 0 ;
}
static int F_48 ( struct V_339 * V_340 ,
const struct V_341 * V_234 )
{
struct V_342 * V_332 = F_49 ( & V_340 -> V_5 ) ;
struct V_132 * V_133 ;
int V_203 ;
unsigned int V_145 ;
V_133 = F_50 ( & V_340 -> V_5 ,
sizeof( struct V_132 ) ,
V_343 ) ;
if ( NULL == V_133 )
return - V_344 ;
F_51 ( V_340 , V_133 ) ;
if ( V_332 ) {
V_133 -> V_332 = * V_332 ;
if ( ! V_133 -> V_332 . V_333 )
V_133 -> V_332 . V_333 = - V_135 ;
} else if ( V_340 -> V_5 . V_345 ) {
V_203 = F_45 ( V_133 , V_340 -> V_5 . V_345 ) ;
if ( V_203 )
return V_203 ;
} else
V_133 -> V_332 . V_333 = - V_135 ;
V_133 -> V_168 = F_52 ( V_340 , & V_346 ) ;
if ( F_53 ( V_133 -> V_168 ) ) {
V_203 = F_54 ( V_133 -> V_168 ) ;
F_8 ( & V_340 -> V_5 , L_17 ,
V_203 ) ;
return V_203 ;
}
if ( F_41 ( V_133 -> V_332 . V_333 ) ) {
V_203 = F_55 ( & V_340 -> V_5 , V_133 -> V_332 . V_333 ,
V_347 ,
L_18 ) ;
if ( V_203 < 0 ) {
F_8 ( & V_340 -> V_5 , L_19 ,
V_133 -> V_332 . V_333 , V_203 ) ;
return V_203 ;
}
F_44 ( 400 ) ;
}
F_56 ( V_133 -> V_168 , V_27 , & V_145 ) ;
if ( ( V_145 != V_348 ) ) {
F_8 ( & V_340 -> V_5 ,
L_20 , V_145 ) ;
return - V_349 ;
}
F_16 ( V_133 -> V_168 , V_3 , 0 ) ;
V_203 = F_57 ( V_133 -> V_168 , V_350 ,
F_4 ( V_350 ) ) ;
if ( V_203 != 0 )
F_58 ( & V_340 -> V_5 , L_21 , V_203 ) ;
if ( V_133 -> V_332 . V_336 )
F_15 ( V_133 -> V_168 , V_32 ,
V_351 , V_351 ) ;
if ( V_133 -> V_332 . V_337 )
F_15 ( V_133 -> V_168 , V_33 ,
V_352 , V_352 ) ;
V_133 -> V_200 = 1 ;
V_203 = F_59 ( & V_340 -> V_5 , & V_353 ,
V_354 , F_4 ( V_354 ) ) ;
if ( V_203 < 0 )
goto V_355;
return 0 ;
V_355:
return V_203 ;
}
static int F_60 ( struct V_339 * V_340 )
{
F_61 ( & V_340 -> V_5 ) ;
return 0 ;
}
