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
struct V_226 * V_227 = V_221 -> V_228 ;
struct V_1 * V_2 = V_227 -> V_2 ;
struct V_132 * V_133 = F_7 ( V_2 ) ;
unsigned int V_229 = 0 , V_230 , V_231 ;
int V_232 , V_233 , V_234 , V_235 ;
V_133 -> V_236 [ V_225 -> V_237 ] = F_25 ( V_223 ) ;
V_233 = F_23 ( V_133 -> V_140 , V_133 -> V_236 [ V_225 -> V_237 ] ) ;
if ( V_233 < 0 ) {
F_8 ( V_2 -> V_5 , L_2 ,
V_133 -> V_236 [ V_225 -> V_237 ] , V_225 -> V_237 ) ;
return - V_135 ;
}
V_235 = F_26 ( V_223 ) ;
if ( V_235 < 0 ) {
F_8 ( V_2 -> V_5 , L_3 , V_235 ) ;
return V_235 ;
}
if ( V_235 > 32 )
V_234 = 1 ;
else
V_234 = 0 ;
V_133 -> V_238 [ V_225 -> V_237 ] = V_133 -> V_236 [ V_225 -> V_237 ] * ( 32 << V_234 ) ;
F_27 ( V_225 -> V_5 , L_4 ,
V_133 -> V_238 [ V_225 -> V_237 ] , V_133 -> V_236 [ V_225 -> V_237 ] ) ;
F_27 ( V_225 -> V_5 , L_5 ,
V_234 , V_233 , V_225 -> V_237 ) ;
switch ( F_28 ( V_223 ) ) {
case V_239 :
break;
case V_240 :
V_229 |= V_241 ;
break;
case V_242 :
V_229 |= V_243 ;
break;
case V_244 :
V_229 |= V_245 ;
break;
default:
return - V_135 ;
}
V_232 = F_22 ( V_2 , V_225 -> V_237 ) ;
if ( V_232 < 0 ) {
F_8 ( V_2 -> V_5 , L_6 , V_232 ) ;
return - V_135 ;
}
if ( V_232 & V_209 ) {
V_231 = V_246 | V_247 ;
V_230 = V_234 << V_248 |
V_233 << V_249 ;
F_9 ( V_2 , V_74 ,
V_250 , V_229 ) ;
F_9 ( V_2 , V_76 , V_231 , V_230 ) ;
}
if ( V_232 & V_213 ) {
V_231 = V_251 | V_252 ;
V_230 = V_234 << V_253 |
V_233 << V_254 ;
F_9 ( V_2 , V_75 ,
V_250 , V_229 ) ;
F_9 ( V_2 , V_76 , V_231 , V_230 ) ;
}
return 0 ;
}
static int F_29 ( struct V_224 * V_225 , unsigned int V_255 )
{
struct V_1 * V_2 = V_225 -> V_2 ;
struct V_132 * V_133 = F_7 ( V_2 ) ;
unsigned int V_256 = 0 ;
int V_232 ;
switch ( V_255 & V_257 ) {
case V_258 :
V_133 -> V_259 [ V_225 -> V_237 ] = 1 ;
break;
case V_260 :
V_256 |= V_261 ;
V_133 -> V_259 [ V_225 -> V_237 ] = 0 ;
break;
default:
return - V_135 ;
}
switch ( V_255 & V_262 ) {
case V_263 :
break;
case V_264 :
V_256 |= V_265 ;
break;
default:
return - V_135 ;
}
switch ( V_255 & V_266 ) {
case V_267 :
break;
case V_268 :
V_256 |= V_269 ;
break;
case V_270 :
V_256 |= V_271 ;
break;
case V_272 :
V_256 |= V_273 ;
break;
default:
return - V_135 ;
}
V_232 = F_22 ( V_2 , V_225 -> V_237 ) ;
if ( V_232 < 0 ) {
F_8 ( V_2 -> V_5 , L_6 , V_232 ) ;
return - V_135 ;
}
if ( V_232 & V_209 ) {
F_9 ( V_2 , V_74 ,
V_274 | V_275 |
V_276 , V_256 ) ;
}
if ( V_232 & V_213 ) {
F_9 ( V_2 , V_75 ,
V_274 | V_275 |
V_276 , V_256 ) ;
}
return 0 ;
}
static int F_30 ( struct V_224 * V_225 ,
int V_277 , unsigned int V_278 , int V_279 )
{
struct V_1 * V_2 = V_225 -> V_2 ;
struct V_132 * V_133 = F_7 ( V_2 ) ;
unsigned int V_256 = 0 ;
if ( V_278 == V_133 -> V_140 && V_277 == V_133 -> V_280 )
return 0 ;
switch ( V_277 ) {
case V_281 :
V_256 |= V_282 ;
break;
case V_283 :
V_256 |= V_147 ;
break;
case V_284 :
V_256 |= V_148 ;
break;
case V_285 :
V_256 |= V_286 ;
break;
default:
F_8 ( V_2 -> V_5 , L_7 , V_277 ) ;
return - V_135 ;
}
F_9 ( V_2 , V_79 ,
V_146 , V_256 ) ;
V_133 -> V_140 = V_278 ;
V_133 -> V_280 = V_277 ;
F_27 ( V_225 -> V_5 , L_8 , V_278 , V_277 ) ;
return 0 ;
}
static int F_31 ( const unsigned int V_287 ,
const unsigned int V_288 , struct V_289 * V_290 )
{
int V_291 = V_292 , V_293 = V_294 ;
int V_295 = 0 , V_296 = 0 , V_137 , V_297 , V_298 , V_299 , V_300 ;
int V_301 = abs ( V_288 - V_287 ) ;
bool V_302 = false ;
if ( V_303 < V_287 || V_304 > V_287 )
return - V_135 ;
for ( V_297 = 0 ; V_297 <= V_291 ; V_297 ++ ) {
V_299 = ( V_287 >> 1 ) + ( V_287 >> 2 ) * V_297 ;
if ( V_299 < 0 )
continue;
if ( V_299 == V_288 ) {
V_302 = true ;
V_295 = V_297 ;
goto V_305;
}
for ( V_298 = 0 ; V_298 <= V_293 ; V_298 ++ ) {
V_300 = V_299 / ( V_298 + 2 ) ;
V_137 = abs ( V_300 - V_288 ) ;
if ( V_137 < V_301 ) {
V_295 = V_297 ;
V_296 = V_298 ;
if ( V_137 == 0 )
goto V_305;
V_301 = V_137 ;
}
}
}
F_32 ( L_9 ) ;
V_305:
V_290 -> V_306 = V_302 ;
V_290 -> V_307 = V_296 ;
V_290 -> V_308 = V_295 ;
V_290 -> V_309 = 2 ;
return 0 ;
}
static int F_33 ( struct V_224 * V_225 , int V_310 , int V_143 ,
unsigned int V_287 , unsigned int V_288 )
{
struct V_1 * V_2 = V_225 -> V_2 ;
struct V_132 * V_133 = F_7 ( V_2 ) ;
struct V_289 * V_290 = & V_133 -> V_290 ;
int V_203 , V_232 ;
if ( V_143 == V_133 -> V_311 && V_287 == V_133 -> V_312 &&
V_288 == V_133 -> V_313 )
return 0 ;
if ( ! V_287 || ! V_288 ) {
F_27 ( V_2 -> V_5 , L_10 ) ;
V_133 -> V_312 = 0 ;
V_133 -> V_313 = 0 ;
F_9 ( V_2 , V_79 ,
V_146 , V_282 ) ;
return 0 ;
}
switch ( V_143 ) {
case V_314 :
F_9 ( V_2 , V_79 ,
V_315 , V_316 ) ;
break;
case V_317 :
case V_318 :
V_232 = F_22 ( V_2 , V_225 -> V_237 ) ;
if ( V_232 < 0 ) {
F_8 ( V_2 -> V_5 ,
L_6 , V_232 ) ;
return - V_135 ;
}
if ( V_232 & V_209 ) {
F_9 ( V_2 , V_79 ,
V_315 , V_319 ) ;
}
if ( V_232 & V_213 ) {
F_9 ( V_2 , V_79 ,
V_315 , V_320 ) ;
}
break;
default:
F_8 ( V_2 -> V_5 , L_11 , V_143 ) ;
return - V_135 ;
}
V_203 = F_31 ( V_287 , V_288 , V_290 ) ;
if ( V_203 < 0 ) {
F_8 ( V_2 -> V_5 , L_12 , V_287 ) ;
return V_203 ;
}
F_27 ( V_2 -> V_5 , L_13 , V_290 -> V_306 ,
( V_290 -> V_306 ? 0 : V_290 -> V_307 ) , V_290 -> V_308 ) ;
F_2 ( V_2 , V_80 ,
V_290 -> V_308 << V_321 | V_290 -> V_309 ) ;
F_2 ( V_2 , V_81 ,
( V_290 -> V_306 ? 0 : V_290 -> V_307 ) << V_322 |
V_290 -> V_306 << V_323 ) ;
V_133 -> V_312 = V_287 ;
V_133 -> V_313 = V_288 ;
V_133 -> V_311 = V_143 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
enum V_324 V_325 )
{
struct V_132 * V_133 = F_7 ( V_2 ) ;
switch ( V_325 ) {
case V_326 :
if ( V_327 == V_2 -> V_328 . V_329 ) {
F_35 ( V_133 -> V_168 , false ) ;
F_9 ( V_2 , V_70 ,
V_330 | V_331 |
V_332 | V_333 ,
V_330 | V_331 |
V_332 | V_333 ) ;
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
case V_327 :
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
V_2 -> V_328 . V_329 = V_325 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_132 * V_133 = F_7 ( V_2 ) ;
int V_203 ;
V_133 -> V_2 = V_2 ;
V_2 -> V_334 = V_133 -> V_168 ;
V_203 = F_38 ( V_2 , 8 , 16 , V_335 ) ;
if ( V_203 != 0 ) {
F_8 ( V_2 -> V_5 , L_14 , V_203 ) ;
return V_203 ;
}
V_2 -> V_328 . V_336 = 1 ;
F_34 ( V_2 , V_327 ) ;
F_9 ( V_2 , V_124 , 0x0301 , 0x0301 ) ;
F_9 ( V_2 , V_94 , 0x0030 , 0x0030 ) ;
F_9 ( V_2 , V_48 , 0xfc00 , 0x0c00 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_132 * V_133 = F_7 ( V_2 ) ;
F_34 ( V_2 , V_327 ) ;
F_1 ( V_2 ) ;
F_35 ( V_133 -> V_168 , true ) ;
F_41 ( V_133 -> V_168 ) ;
if ( F_42 ( V_133 -> V_337 . V_338 ) )
F_43 ( V_133 -> V_337 . V_338 , 0 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_132 * V_133 = F_7 ( V_2 ) ;
if ( F_42 ( V_133 -> V_337 . V_338 ) ) {
F_43 ( V_133 -> V_337 . V_338 , 1 ) ;
F_45 ( 400 ) ;
}
return 0 ;
}
static int F_46 ( struct V_132 * V_133 , struct V_339 * V_340 )
{
V_133 -> V_337 . V_341 = F_47 ( V_340 ,
L_15 ) ;
V_133 -> V_337 . V_342 = F_47 ( V_340 ,
L_16 ) ;
V_133 -> V_337 . V_338 = F_48 ( V_340 ,
L_17 , 0 ) ;
if ( ! F_42 ( V_133 -> V_337 . V_338 ) &&
( V_133 -> V_337 . V_338 != - V_343 ) )
return V_133 -> V_337 . V_338 ;
return 0 ;
}
static int F_49 ( struct V_344 * V_345 ,
const struct V_346 * V_237 )
{
struct V_347 * V_337 = F_50 ( & V_345 -> V_5 ) ;
struct V_132 * V_133 ;
int V_203 ;
unsigned int V_145 ;
V_133 = F_51 ( & V_345 -> V_5 ,
sizeof( struct V_132 ) ,
V_348 ) ;
if ( NULL == V_133 )
return - V_349 ;
F_52 ( V_345 , V_133 ) ;
if ( V_337 ) {
V_133 -> V_337 = * V_337 ;
if ( ! V_133 -> V_337 . V_338 )
V_133 -> V_337 . V_338 = - V_135 ;
} else if ( V_345 -> V_5 . V_350 ) {
V_203 = F_46 ( V_133 , V_345 -> V_5 . V_350 ) ;
if ( V_203 )
return V_203 ;
} else
V_133 -> V_337 . V_338 = - V_135 ;
V_133 -> V_168 = F_53 ( V_345 , & V_351 ) ;
if ( F_54 ( V_133 -> V_168 ) ) {
V_203 = F_55 ( V_133 -> V_168 ) ;
F_8 ( & V_345 -> V_5 , L_18 ,
V_203 ) ;
return V_203 ;
}
if ( F_42 ( V_133 -> V_337 . V_338 ) ) {
V_203 = F_56 ( & V_345 -> V_5 , V_133 -> V_337 . V_338 ,
V_352 ,
L_19 ) ;
if ( V_203 < 0 ) {
F_8 ( & V_345 -> V_5 , L_20 ,
V_133 -> V_337 . V_338 , V_203 ) ;
return V_203 ;
}
F_45 ( 400 ) ;
}
F_57 ( V_133 -> V_168 , V_27 , & V_145 ) ;
if ( ( V_145 != V_353 ) ) {
F_8 ( & V_345 -> V_5 ,
L_21 , V_145 ) ;
return - V_354 ;
}
F_16 ( V_133 -> V_168 , V_3 , 0 ) ;
V_203 = F_58 ( V_133 -> V_168 , V_355 ,
F_4 ( V_355 ) ) ;
if ( V_203 != 0 )
F_59 ( & V_345 -> V_5 , L_22 , V_203 ) ;
if ( V_133 -> V_337 . V_341 )
F_15 ( V_133 -> V_168 , V_32 ,
V_356 , V_356 ) ;
if ( V_133 -> V_337 . V_342 )
F_15 ( V_133 -> V_168 , V_33 ,
V_357 , V_357 ) ;
V_133 -> V_200 = 1 ;
V_203 = F_60 ( & V_345 -> V_5 , & V_358 ,
V_359 , F_4 ( V_359 ) ) ;
if ( V_203 < 0 )
goto V_360;
return 0 ;
V_360:
return V_203 ;
}
static int F_61 ( struct V_344 * V_345 )
{
F_62 ( & V_345 -> V_5 ) ;
return 0 ;
}
