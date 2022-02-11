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
case V_26 :
case V_27 :
case V_28 :
case V_12 :
case V_13 :
case V_14 :
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
case V_11 :
case V_85 :
case V_86 :
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
case V_15 :
case V_104 :
case V_105 :
case V_16 :
case V_106 :
case V_17 :
case V_107 :
case V_18 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_19 :
case V_20 :
case V_21 :
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
case V_22 :
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
case V_23 :
case V_24 :
case V_25 :
return true ;
default:
return false ;
}
}
static int F_6 ( struct V_141 * V_142 ,
struct V_143 * V_144 , int V_145 )
{
struct V_1 * V_2 = V_142 -> V_2 ;
struct V_146 * V_147 = F_7 ( V_2 ) ;
int V_148 = - V_149 ;
V_148 = F_8 ( V_147 -> V_150 ) ;
if ( V_148 < 0 )
F_9 ( V_2 -> V_5 , L_1 ) ;
else
F_10 ( V_2 , V_89 ,
V_151 , V_148 << V_152 ) ;
return V_148 ;
}
static int F_11 ( struct V_141 * V_153 ,
struct V_141 * V_154 )
{
unsigned int V_155 ;
V_155 = F_12 ( V_153 -> V_2 , V_93 ) ;
V_155 &= V_156 ;
if ( V_155 == V_157 )
return 1 ;
else
return 0 ;
}
static void F_13 ( struct V_1 * V_2 , int V_158 )
{
static int V_159 ;
struct V_146 * V_147 = F_7 ( V_2 ) ;
if ( V_158 ) {
if ( V_159 <= 0 ) {
F_10 ( V_2 , V_101 ,
V_160 , V_161 ) ;
F_2 ( V_2 , V_100 , 0x000d ) ;
F_14 ( V_147 -> V_162 , V_163 +
V_164 , 0x9f01 ) ;
F_15 ( 150 ) ;
F_10 ( V_2 , V_80 ,
V_165 | V_166 , 0 ) ;
F_10 ( V_2 , V_83 ,
V_167 | V_168 ,
V_167 | V_168 ) ;
F_10 ( V_2 , V_80 ,
V_169 | V_170 |
V_171 ,
V_169 | V_170 |
V_171 ) ;
F_15 ( 5 ) ;
F_10 ( V_2 , V_80 ,
V_165 | V_166 ,
V_165 | V_166 ) ;
F_10 ( V_2 , V_100 ,
V_172 | V_173 ,
V_174 | V_175 ) ;
F_14 ( V_147 -> V_162 , V_163 +
0x14 , 0x1aaa ) ;
F_14 ( V_147 -> V_162 , V_163 +
0x24 , 0x0430 ) ;
}
V_159 ++ ;
} else {
V_159 -- ;
if ( V_159 <= 0 ) {
F_10 ( V_2 , V_100 ,
V_173 | V_176 |
V_177 , V_178 |
V_179 | V_180 ) ;
F_2 ( V_2 , V_100 , 0x0000 ) ;
F_10 ( V_2 , V_80 ,
V_169 | V_170 |
V_171 , 0 ) ;
}
}
}
static int F_16 ( struct V_141 * V_142 ,
struct V_143 * V_144 , int V_145 )
{
struct V_1 * V_2 = V_142 -> V_2 ;
struct V_146 * V_147 = F_7 ( V_2 ) ;
switch ( V_145 ) {
case V_181 :
F_13 ( V_2 , 1 ) ;
F_10 ( V_2 , V_102 , V_182 |
V_183 | V_184 ,
( V_185 << V_186 ) |
( V_187 << V_188 ) |
( V_185 << V_189 ) ) ;
F_14 ( V_147 -> V_162 ,
V_163 + V_190 , 0xfc00 ) ;
F_10 ( V_2 , V_100 ,
V_191 , V_192 ) ;
F_10 ( V_2 , V_100 ,
V_193 , V_194 ) ;
F_10 ( V_2 , V_100 ,
V_193 | V_176 |
V_177 , V_195 |
V_196 | V_197 ) ;
F_17 ( 40 ) ;
F_10 ( V_2 , V_100 ,
V_173 | V_176 |
V_177 , V_178 |
V_179 | V_180 ) ;
break;
case V_198 :
F_10 ( V_2 , V_102 ,
V_182 | V_183 |
V_184 ,
( V_199 << V_186 ) |
( V_187 << V_188 ) |
( V_199 << V_189 ) ) ;
F_14 ( V_147 -> V_162 ,
V_163 + V_190 , 0xfc00 ) ;
F_10 ( V_2 , V_100 ,
V_173 , V_175 ) ;
F_10 ( V_2 , V_100 ,
V_200 , V_201 ) ;
F_10 ( V_2 , V_100 ,
V_200 | V_176 |
V_177 , V_202 |
V_196 | V_197 ) ;
F_17 ( 30 ) ;
F_13 ( V_2 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_18 ( struct V_141 * V_142 ,
struct V_143 * V_144 , int V_145 )
{
struct V_1 * V_2 = V_142 -> V_2 ;
switch ( V_145 ) {
case V_181 :
F_10 ( V_2 , V_78 ,
V_203 | V_204 |
V_205 ,
V_203 | V_204 |
V_205 ) ;
break;
case V_198 :
F_10 ( V_2 , V_78 ,
V_203 | V_204 |
V_205 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_19 ( struct V_141 * V_142 ,
struct V_143 * V_144 , int V_145 )
{
struct V_1 * V_2 = V_142 -> V_2 ;
switch ( V_145 ) {
case V_181 :
F_13 ( V_2 , 1 ) ;
F_10 ( V_2 , V_80 ,
V_206 , V_206 ) ;
F_10 ( V_2 , V_28 ,
V_207 | V_208 , 0 ) ;
break;
case V_198 :
F_10 ( V_2 , V_28 ,
V_207 | V_208 ,
V_207 | V_208 ) ;
F_10 ( V_2 , V_80 ,
V_206 , 0 ) ;
F_13 ( V_2 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_20 ( struct V_141 * V_142 ,
struct V_143 * V_144 , int V_145 )
{
struct V_1 * V_2 = V_142 -> V_2 ;
switch ( V_145 ) {
case V_181 :
F_10 ( V_2 , V_81 ,
V_209 , V_209 ) ;
break;
case V_198 :
F_10 ( V_2 , V_81 ,
V_209 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_21 ( struct V_210 * V_211 ,
struct V_212 * V_213 , struct V_214 * V_215 )
{
struct V_1 * V_2 = V_215 -> V_2 ;
struct V_146 * V_147 = F_7 ( V_2 ) ;
unsigned int V_216 = 0 , V_217 , V_218 ;
int V_219 , V_220 , V_221 ;
V_147 -> V_222 [ V_215 -> V_223 ] = F_22 ( V_213 ) ;
V_219 = F_23 ( V_147 -> V_150 , V_147 -> V_222 [ V_215 -> V_223 ] ) ;
if ( V_219 < 0 ) {
F_9 ( V_2 -> V_5 , L_2 ) ;
return - V_149 ;
}
V_221 = F_24 ( V_213 ) ;
if ( V_221 < 0 ) {
F_9 ( V_2 -> V_5 , L_3 , V_221 ) ;
return - V_149 ;
}
V_220 = V_221 > 32 ;
V_147 -> V_224 [ V_215 -> V_223 ] = V_147 -> V_222 [ V_215 -> V_223 ] * ( 32 << V_220 ) ;
F_25 ( V_215 -> V_5 , L_4 ,
V_147 -> V_224 [ V_215 -> V_223 ] , V_147 -> V_222 [ V_215 -> V_223 ] ) ;
F_25 ( V_215 -> V_5 , L_5 ,
V_220 , V_219 , V_215 -> V_223 ) ;
switch ( F_26 ( V_213 ) ) {
case 16 :
break;
case 20 :
V_216 |= V_225 ;
break;
case 24 :
V_216 |= V_226 ;
break;
case 8 :
V_216 |= V_227 ;
break;
default:
return - V_149 ;
}
switch ( V_215 -> V_223 ) {
case V_228 :
V_218 = V_229 | V_230 ;
V_217 = V_220 << V_231 |
V_219 << V_232 ;
F_10 ( V_2 , V_85 ,
V_233 , V_216 ) ;
F_10 ( V_2 , V_87 , V_218 , V_217 ) ;
break;
case V_234 :
V_218 = V_235 | V_236 ;
V_217 = V_220 << V_237 |
V_219 << V_238 ;
F_10 ( V_2 , V_86 ,
V_233 , V_216 ) ;
F_10 ( V_2 , V_87 , V_218 , V_217 ) ;
break;
default:
F_9 ( V_2 -> V_5 , L_6 , V_215 -> V_223 ) ;
return - V_149 ;
}
return 0 ;
}
static int F_27 ( struct V_214 * V_215 , unsigned int V_239 )
{
struct V_1 * V_2 = V_215 -> V_2 ;
struct V_146 * V_147 = F_7 ( V_2 ) ;
unsigned int V_240 = 0 ;
switch ( V_239 & V_241 ) {
case V_242 :
V_147 -> V_243 [ V_215 -> V_223 ] = 1 ;
break;
case V_244 :
V_240 |= V_245 ;
V_147 -> V_243 [ V_215 -> V_223 ] = 0 ;
break;
default:
return - V_149 ;
}
switch ( V_239 & V_246 ) {
case V_247 :
break;
case V_248 :
V_240 |= V_249 ;
break;
default:
return - V_149 ;
}
switch ( V_239 & V_250 ) {
case V_251 :
break;
case V_252 :
V_240 |= V_253 ;
break;
case V_254 :
V_240 |= V_255 ;
break;
case V_256 :
V_240 |= V_257 ;
break;
default:
return - V_149 ;
}
switch ( V_215 -> V_223 ) {
case V_228 :
F_10 ( V_2 , V_85 ,
V_258 | V_259 |
V_260 , V_240 ) ;
break;
case V_234 :
F_10 ( V_2 , V_86 ,
V_258 | V_259 |
V_260 , V_240 ) ;
break;
default:
F_9 ( V_2 -> V_5 , L_6 , V_215 -> V_223 ) ;
return - V_149 ;
}
return 0 ;
}
static int F_28 ( struct V_214 * V_215 ,
int V_261 , unsigned int V_262 , int V_263 )
{
struct V_1 * V_2 = V_215 -> V_2 ;
struct V_146 * V_147 = F_7 ( V_2 ) ;
unsigned int V_240 = 0 ;
if ( V_262 == V_147 -> V_150 && V_261 == V_147 -> V_264 )
return 0 ;
switch ( V_261 ) {
case V_265 :
V_240 |= V_266 ;
break;
case V_267 :
V_240 |= V_157 ;
break;
case V_268 :
V_240 |= V_269 ;
break;
default:
F_9 ( V_2 -> V_5 , L_7 , V_261 ) ;
return - V_149 ;
}
F_10 ( V_2 , V_93 ,
V_156 , V_240 ) ;
V_147 -> V_150 = V_262 ;
V_147 -> V_264 = V_261 ;
F_25 ( V_215 -> V_5 , L_8 , V_262 , V_261 ) ;
return 0 ;
}
static int F_29 ( struct V_214 * V_215 , int V_270 , int V_153 ,
unsigned int V_271 , unsigned int V_272 )
{
struct V_1 * V_2 = V_215 -> V_2 ;
struct V_146 * V_147 = F_7 ( V_2 ) ;
struct V_273 V_274 ;
int V_275 ;
if ( V_153 == V_147 -> V_276 && V_271 == V_147 -> V_277 &&
V_272 == V_147 -> V_278 )
return 0 ;
if ( ! V_271 || ! V_272 ) {
F_25 ( V_2 -> V_5 , L_9 ) ;
V_147 -> V_277 = 0 ;
V_147 -> V_278 = 0 ;
F_10 ( V_2 , V_93 ,
V_156 , V_266 ) ;
return 0 ;
}
switch ( V_153 ) {
case V_279 :
F_10 ( V_2 , V_93 ,
V_280 , V_281 ) ;
break;
case V_282 :
case V_283 :
switch ( V_215 -> V_223 ) {
case V_228 :
F_10 ( V_2 , V_93 ,
V_280 , V_284 ) ;
break;
case V_234 :
F_10 ( V_2 , V_93 ,
V_280 , V_285 ) ;
break;
default:
F_9 ( V_2 -> V_5 , L_6 , V_215 -> V_223 ) ;
return - V_149 ;
}
break;
default:
F_9 ( V_2 -> V_5 , L_10 , V_153 ) ;
return - V_149 ;
}
V_275 = F_30 ( V_271 , V_272 , & V_274 ) ;
if ( V_275 < 0 ) {
F_9 ( V_2 -> V_5 , L_11 , V_271 ) ;
return V_275 ;
}
F_25 ( V_2 -> V_5 , L_12 ,
V_274 . V_286 , ( V_274 . V_286 ? 0 : V_274 . V_287 ) ,
V_274 . V_288 , V_274 . V_289 ) ;
F_2 ( V_2 , V_94 ,
V_274 . V_288 << V_290 | V_274 . V_289 ) ;
F_2 ( V_2 , V_95 ,
( V_274 . V_286 ? 0 : V_274 . V_287 ) << V_291 |
V_274 . V_286 << V_292 ) ;
V_147 -> V_277 = V_271 ;
V_147 -> V_278 = V_272 ;
V_147 -> V_276 = V_153 ;
return 0 ;
}
static int F_31 ( struct V_214 * V_215 , unsigned int V_293 ,
unsigned int V_294 , int V_295 , int V_296 )
{
struct V_1 * V_2 = V_215 -> V_2 ;
unsigned int V_155 = 0 ;
if ( V_294 || V_293 )
V_155 |= ( 1 << 14 ) ;
switch ( V_295 ) {
case 4 :
V_155 |= ( 1 << 12 ) ;
break;
case 6 :
V_155 |= ( 2 << 12 ) ;
break;
case 8 :
V_155 |= ( 3 << 12 ) ;
break;
case 2 :
default:
break;
}
switch ( V_296 ) {
case 20 :
V_155 |= ( 1 << 10 ) ;
break;
case 24 :
V_155 |= ( 2 << 10 ) ;
break;
case 32 :
V_155 |= ( 3 << 10 ) ;
break;
case 16 :
default:
break;
}
F_10 ( V_2 , V_91 , 0x7c00 , V_155 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
enum V_297 V_298 )
{
switch ( V_298 ) {
case V_299 :
if ( V_300 == V_2 -> V_301 . V_302 ) {
F_10 ( V_2 , V_80 ,
V_303 | V_304 |
V_305 | V_306 ,
V_303 | V_304 |
V_305 | V_306 ) ;
F_15 ( 10 ) ;
F_10 ( V_2 , V_80 ,
V_165 | V_166 ,
V_165 | V_166 ) ;
F_10 ( V_2 , V_138 ,
V_307 , V_307 ) ;
}
break;
case V_300 :
F_2 ( V_2 , V_101 , 0x1100 ) ;
F_2 ( V_2 , V_138 , 0x0128 ) ;
F_2 ( V_2 , V_78 , 0x0000 ) ;
F_2 ( V_2 , V_79 , 0x0000 ) ;
F_2 ( V_2 , V_83 , 0x0000 ) ;
F_2 ( V_2 , V_82 , 0x0000 ) ;
F_2 ( V_2 , V_80 , 0x0000 ) ;
F_2 ( V_2 , V_81 , 0x0000 ) ;
break;
default:
break;
}
V_2 -> V_301 . V_302 = V_298 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_146 * V_147 = F_7 ( V_2 ) ;
V_147 -> V_2 = V_2 ;
F_32 ( V_2 , V_300 ) ;
F_10 ( V_2 , V_308 , 0x0300 , 0x0200 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_146 * V_147 = F_7 ( V_2 ) ;
F_36 ( V_147 -> V_162 , true ) ;
F_37 ( V_147 -> V_162 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_146 * V_147 = F_7 ( V_2 ) ;
F_36 ( V_147 -> V_162 , false ) ;
F_39 ( V_147 -> V_162 ) ;
return 0 ;
}
static int F_40 ( struct V_309 * V_310 ,
const struct V_311 * V_223 )
{
struct V_312 * V_313 = F_41 ( & V_310 -> V_5 ) ;
struct V_146 * V_147 ;
int V_275 ;
unsigned int V_155 ;
V_147 = F_42 ( & V_310 -> V_5 , sizeof( struct V_146 ) ,
V_314 ) ;
if ( V_147 == NULL )
return - V_315 ;
F_43 ( V_310 , V_147 ) ;
if ( V_313 )
V_147 -> V_313 = * V_313 ;
V_147 -> V_162 = F_44 ( V_310 , & V_316 ) ;
if ( F_45 ( V_147 -> V_162 ) ) {
V_275 = F_46 ( V_147 -> V_162 ) ;
F_9 ( & V_310 -> V_5 , L_13 ,
V_275 ) ;
return V_275 ;
}
F_47 ( V_147 -> V_162 , V_25 , & V_155 ) ;
if ( V_155 != V_317 ) {
F_9 ( & V_310 -> V_5 ,
L_14 , V_155 ) ;
return - V_318 ;
}
F_14 ( V_147 -> V_162 , V_3 , 0 ) ;
V_275 = F_48 ( V_147 -> V_162 , V_319 ,
F_4 ( V_319 ) ) ;
if ( V_275 != 0 )
F_49 ( & V_310 -> V_5 , L_15 , V_275 ) ;
if ( V_147 -> V_313 . V_320 )
F_50 ( V_147 -> V_162 , V_29 ,
V_321 , V_321 ) ;
if ( V_147 -> V_313 . V_322 ) {
F_50 ( V_147 -> V_162 , V_114 ,
V_323 , V_324 ) ;
switch ( V_147 -> V_313 . V_325 ) {
case V_326 :
F_50 ( V_147 -> V_162 , V_89 ,
V_327 , V_328 ) ;
break;
case V_329 :
F_50 ( V_147 -> V_162 , V_89 ,
V_327 , V_330 ) ;
F_50 ( V_147 -> V_162 , V_114 ,
V_331 , V_332 ) ;
break;
case V_333 :
F_50 ( V_147 -> V_162 , V_89 ,
V_327 , V_334 ) ;
F_50 ( V_147 -> V_162 , V_114 ,
V_335 ,
V_336 ) ;
break;
default:
break;
}
switch ( V_147 -> V_313 . V_337 ) {
case V_338 :
F_50 ( V_147 -> V_162 , V_89 ,
V_339 , V_340 ) ;
break;
case V_341 :
F_50 ( V_147 -> V_162 , V_89 ,
V_339 , V_342 ) ;
F_50 ( V_147 -> V_162 , V_114 ,
V_343 , V_344 ) ;
break;
case V_345 :
F_50 ( V_147 -> V_162 , V_89 ,
V_339 , V_346 ) ;
F_50 ( V_147 -> V_162 , V_114 ,
V_347 ,
V_348 ) ;
break;
case V_349 :
F_50 ( V_147 -> V_162 , V_89 ,
V_327 , V_350 ) ;
F_50 ( V_147 -> V_162 , V_114 ,
V_351 ,
V_352 ) ;
break;
default:
break;
}
}
return F_51 ( & V_310 -> V_5 , & V_353 ,
V_354 , F_4 ( V_354 ) ) ;
}
static int F_52 ( struct V_309 * V_310 )
{
F_53 ( & V_310 -> V_5 ) ;
return 0 ;
}
