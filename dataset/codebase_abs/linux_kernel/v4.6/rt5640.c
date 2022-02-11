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
struct V_1 * V_2 = F_7 ( V_128 -> V_132 ) ;
struct V_133 * V_134 = F_8 ( V_2 ) ;
int V_135 , V_136 ;
V_136 = V_134 -> V_137 / F_9 ( V_134 -> V_138 ,
V_76 , V_139 ) ;
V_135 = F_10 ( V_136 ) ;
if ( V_135 < 0 )
F_11 ( V_2 -> V_5 , L_1 ) ;
else
F_12 ( V_2 , V_78 , V_140 ,
V_135 << V_141 ) ;
return V_135 ;
}
static int F_13 ( struct V_127 * V_142 ,
struct V_127 * V_143 )
{
struct V_1 * V_2 = F_7 ( V_142 -> V_132 ) ;
unsigned int V_144 ;
V_144 = F_14 ( V_2 , V_79 ) ;
V_144 &= V_145 ;
if ( V_144 == V_146 )
return 1 ;
else
return 0 ;
}
static int F_15 ( struct V_127 * V_142 ,
struct V_127 * V_143 )
{
struct V_1 * V_2 = F_7 ( V_142 -> V_132 ) ;
struct V_133 * V_134 = F_8 ( V_2 ) ;
if ( ! V_134 -> V_147 )
return 0 ;
return 1 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = F_8 ( V_2 ) ;
F_17 ( V_134 -> V_138 , V_148 +
V_149 , 0x0700 , 0x0200 ) ;
F_17 ( V_134 -> V_138 , V_90 ,
V_150 , V_151 ) ;
F_17 ( V_134 -> V_138 , V_89 ,
V_152 | V_153 | V_154 ,
V_155 | V_156 | V_157 ) ;
F_18 ( V_134 -> V_138 , V_148 + V_158 ,
0x9f00 ) ;
F_17 ( V_134 -> V_138 , V_70 ,
V_159 | V_160 , 0 ) ;
F_17 ( V_134 -> V_138 , V_70 ,
V_161 ,
V_161 ) ;
F_19 ( 10000 , 15000 ) ;
F_17 ( V_134 -> V_138 , V_70 ,
V_159 | V_160 ,
V_159 | V_160 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = F_8 ( V_2 ) ;
F_17 ( V_134 -> V_138 , V_90 ,
V_150 | V_162 ,
V_163 | V_164 ) ;
F_17 ( V_134 -> V_138 , V_92 ,
V_165 , V_166 ) ;
F_17 ( V_134 -> V_138 , V_91 ,
V_167 | V_168 | V_169 ,
( V_170 << V_171 ) |
( V_172 << V_173 ) |
( V_170 << V_174 ) ) ;
F_18 ( V_134 -> V_138 , V_148 +
V_175 , 0x1c00 ) ;
F_17 ( V_134 -> V_138 , V_89 ,
V_152 | V_153 ,
V_176 | V_177 ) ;
F_17 ( V_134 -> V_138 , V_148 +
V_149 , 0x0700 , 0x0400 ) ;
}
static int F_21 ( struct V_127 * V_128 ,
struct V_129 * V_130 , int V_131 )
{
struct V_1 * V_2 = F_7 ( V_128 -> V_132 ) ;
struct V_133 * V_134 = F_8 ( V_2 ) ;
switch ( V_131 ) {
case V_178 :
F_20 ( V_2 ) ;
V_134 -> V_179 = 0 ;
break;
case V_180 :
V_134 -> V_179 = 1 ;
F_19 ( 70000 , 75000 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_22 ( struct V_127 * V_128 ,
struct V_129 * V_130 , int V_131 )
{
struct V_1 * V_2 = F_7 ( V_128 -> V_132 ) ;
switch ( V_131 ) {
case V_178 :
F_16 ( V_2 ) ;
F_12 ( V_2 , V_70 ,
V_181 , V_181 ) ;
F_12 ( V_2 , V_30 ,
V_182 | V_183 , 0 ) ;
break;
case V_180 :
F_12 ( V_2 , V_30 ,
V_182 | V_183 ,
V_182 | V_183 ) ;
F_12 ( V_2 , V_70 ,
V_181 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_23 ( struct V_127 * V_128 ,
struct V_129 * V_130 , int V_131 )
{
struct V_1 * V_2 = F_7 ( V_128 -> V_132 ) ;
switch ( V_131 ) {
case V_178 :
F_16 ( V_2 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_24 ( struct V_127 * V_128 ,
struct V_129 * V_130 , int V_131 )
{
struct V_1 * V_2 = F_7 ( V_128 -> V_132 ) ;
struct V_133 * V_134 = F_8 ( V_2 ) ;
switch ( V_131 ) {
case V_178 :
if ( ! V_134 -> V_179 )
F_19 ( 80000 , 85000 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , int V_184 )
{
int V_185 = 0 , V_144 ;
if ( V_2 == NULL )
return - V_186 ;
V_144 = F_14 ( V_2 , V_74 ) ;
V_144 = ( V_144 & V_187 ) >> V_188 ;
switch ( V_184 ) {
case V_189 :
switch ( V_144 ) {
case V_190 :
case V_191 :
V_185 |= V_192 ;
break;
case V_193 :
V_185 |= V_192 ;
case V_194 :
case V_195 :
V_185 |= V_196 ;
break;
}
break;
case V_197 :
switch ( V_144 ) {
case V_198 :
case V_195 :
V_185 |= V_192 ;
break;
case V_199 :
V_185 |= V_192 ;
case V_190 :
case V_200 :
V_185 |= V_196 ;
break;
}
break;
default:
V_185 = - V_186 ;
break;
}
return V_185 ;
}
static int F_26 ( struct V_201 * V_202 ,
struct V_203 * V_204 , struct V_205 * V_206 )
{
struct V_1 * V_2 = V_206 -> V_2 ;
struct V_133 * V_134 = F_8 ( V_2 ) ;
unsigned int V_207 = 0 , V_208 , V_209 ;
int V_210 , V_211 , V_212 , V_213 ;
V_134 -> V_214 [ V_206 -> V_215 ] = F_27 ( V_204 ) ;
V_211 = F_28 ( V_134 -> V_137 , V_134 -> V_214 [ V_206 -> V_215 ] ) ;
if ( V_211 < 0 ) {
F_11 ( V_2 -> V_5 , L_2 ,
V_134 -> V_214 [ V_206 -> V_215 ] , V_206 -> V_215 ) ;
return - V_186 ;
}
V_213 = F_29 ( V_204 ) ;
if ( V_213 < 0 ) {
F_11 ( V_2 -> V_5 , L_3 , V_213 ) ;
return V_213 ;
}
if ( V_213 > 32 )
V_212 = 1 ;
else
V_212 = 0 ;
V_134 -> V_216 [ V_206 -> V_215 ] = V_134 -> V_214 [ V_206 -> V_215 ] * ( 32 << V_212 ) ;
F_30 ( V_206 -> V_5 , L_4 ,
V_134 -> V_216 [ V_206 -> V_215 ] , V_134 -> V_214 [ V_206 -> V_215 ] ) ;
F_30 ( V_206 -> V_5 , L_5 ,
V_212 , V_211 , V_206 -> V_215 ) ;
switch ( F_31 ( V_204 ) ) {
case 16 :
break;
case 20 :
V_207 |= V_217 ;
break;
case 24 :
V_207 |= V_218 ;
break;
case 8 :
V_207 |= V_219 ;
break;
default:
return - V_186 ;
}
V_210 = F_25 ( V_2 , V_206 -> V_215 ) ;
if ( V_210 < 0 ) {
F_11 ( V_2 -> V_5 , L_6 , V_210 ) ;
return - V_186 ;
}
if ( V_210 & V_192 ) {
V_209 = V_220 | V_221 ;
V_208 = V_212 << V_222 |
V_211 << V_139 ;
F_12 ( V_2 , V_74 ,
V_223 , V_207 ) ;
F_12 ( V_2 , V_76 , V_209 , V_208 ) ;
}
if ( V_210 & V_196 ) {
V_209 = V_224 | V_225 ;
V_208 = V_212 << V_226 |
V_211 << V_227 ;
F_12 ( V_2 , V_75 ,
V_223 , V_207 ) ;
F_12 ( V_2 , V_76 , V_209 , V_208 ) ;
}
return 0 ;
}
static int F_32 ( struct V_205 * V_206 , unsigned int V_228 )
{
struct V_1 * V_2 = V_206 -> V_2 ;
struct V_133 * V_134 = F_8 ( V_2 ) ;
unsigned int V_229 = 0 ;
int V_210 ;
switch ( V_228 & V_230 ) {
case V_231 :
V_134 -> V_232 [ V_206 -> V_215 ] = 1 ;
break;
case V_233 :
V_229 |= V_234 ;
V_134 -> V_232 [ V_206 -> V_215 ] = 0 ;
break;
default:
return - V_186 ;
}
switch ( V_228 & V_235 ) {
case V_236 :
break;
case V_237 :
V_229 |= V_238 ;
break;
default:
return - V_186 ;
}
switch ( V_228 & V_239 ) {
case V_240 :
break;
case V_241 :
V_229 |= V_242 ;
break;
case V_243 :
V_229 |= V_244 ;
break;
case V_245 :
V_229 |= V_246 ;
break;
default:
return - V_186 ;
}
V_210 = F_25 ( V_2 , V_206 -> V_215 ) ;
if ( V_210 < 0 ) {
F_11 ( V_2 -> V_5 , L_6 , V_210 ) ;
return - V_186 ;
}
if ( V_210 & V_192 ) {
F_12 ( V_2 , V_74 ,
V_247 | V_248 |
V_249 , V_229 ) ;
}
if ( V_210 & V_196 ) {
F_12 ( V_2 , V_75 ,
V_247 | V_248 |
V_249 , V_229 ) ;
}
return 0 ;
}
static int F_33 ( struct V_205 * V_206 ,
int V_250 , unsigned int V_251 , int V_252 )
{
struct V_1 * V_2 = V_206 -> V_2 ;
struct V_133 * V_134 = F_8 ( V_2 ) ;
unsigned int V_229 = 0 ;
if ( V_251 == V_134 -> V_137 && V_250 == V_134 -> V_253 )
return 0 ;
switch ( V_250 ) {
case V_254 :
V_229 |= V_255 ;
break;
case V_256 :
V_229 |= V_146 ;
break;
default:
F_11 ( V_2 -> V_5 , L_7 , V_250 ) ;
return - V_186 ;
}
F_12 ( V_2 , V_79 ,
V_145 , V_229 ) ;
V_134 -> V_137 = V_251 ;
V_134 -> V_253 = V_250 ;
F_30 ( V_206 -> V_5 , L_8 , V_251 , V_250 ) ;
return 0 ;
}
static int F_34 ( struct V_205 * V_206 , int V_257 , int V_142 ,
unsigned int V_258 , unsigned int V_259 )
{
struct V_1 * V_2 = V_206 -> V_2 ;
struct V_133 * V_134 = F_8 ( V_2 ) ;
struct V_260 V_261 ;
int V_185 ;
if ( V_142 == V_134 -> V_262 && V_258 == V_134 -> V_263 &&
V_259 == V_134 -> V_264 )
return 0 ;
if ( ! V_258 || ! V_259 ) {
F_30 ( V_2 -> V_5 , L_9 ) ;
V_134 -> V_263 = 0 ;
V_134 -> V_264 = 0 ;
F_12 ( V_2 , V_79 ,
V_145 , V_255 ) ;
return 0 ;
}
switch ( V_142 ) {
case V_265 :
F_12 ( V_2 , V_79 ,
V_266 , V_267 ) ;
break;
case V_268 :
F_12 ( V_2 , V_79 ,
V_266 , V_269 ) ;
break;
case V_270 :
F_12 ( V_2 , V_79 ,
V_266 , V_271 ) ;
break;
default:
F_11 ( V_2 -> V_5 , L_10 , V_142 ) ;
return - V_186 ;
}
V_185 = F_35 ( V_258 , V_259 , & V_261 ) ;
if ( V_185 < 0 ) {
F_11 ( V_2 -> V_5 , L_11 , V_258 ) ;
return V_185 ;
}
F_30 ( V_2 -> V_5 , L_12 ,
V_261 . V_272 , ( V_261 . V_272 ? 0 : V_261 . V_273 ) ,
V_261 . V_274 , V_261 . V_275 ) ;
F_2 ( V_2 , V_80 ,
V_261 . V_274 << V_276 | V_261 . V_275 ) ;
F_2 ( V_2 , V_81 ,
( V_261 . V_272 ? 0 : V_261 . V_273 ) << V_277 |
V_261 . V_272 << V_278 ) ;
V_134 -> V_263 = V_258 ;
V_134 -> V_264 = V_259 ;
V_134 -> V_262 = V_142 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
enum V_279 V_280 )
{
struct V_133 * V_134 = F_8 ( V_2 ) ;
int V_185 ;
switch ( V_280 ) {
case V_281 :
break;
case V_282 :
if ( F_37 ( V_134 -> V_283 ) )
break;
if ( F_38 ( V_2 ) == V_281 ) {
F_39 ( V_134 -> V_283 ) ;
} else {
V_185 = F_40 ( V_134 -> V_283 ) ;
if ( V_185 )
return V_185 ;
}
break;
case V_284 :
if ( V_285 == F_38 ( V_2 ) ) {
F_12 ( V_2 , V_70 ,
V_286 | V_287 |
V_288 | V_289 ,
V_286 | V_287 |
V_288 | V_289 ) ;
F_19 ( 10000 , 15000 ) ;
F_12 ( V_2 , V_70 ,
V_159 | V_160 ,
V_159 | V_160 ) ;
F_12 ( V_2 , V_124 ,
0x0301 , 0x0301 ) ;
F_12 ( V_2 , V_94 ,
0x0030 , 0x0030 ) ;
}
break;
case V_285 :
F_2 ( V_2 , V_89 , 0x0004 ) ;
F_2 ( V_2 , V_90 , 0x1100 ) ;
F_12 ( V_2 , V_124 , 0x1 , 0 ) ;
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
return 0 ;
}
int F_41 ( struct V_1 * V_2 ,
bool V_290 , bool V_291 )
{
struct V_133 * V_134 = F_8 ( V_2 ) ;
F_17 ( V_134 -> V_138 , V_105 ,
V_292 , V_293 ) ;
if ( V_290 ) {
F_17 ( V_134 -> V_138 , V_78 ,
V_294 , V_295 ) ;
F_17 ( V_134 -> V_138 , V_105 ,
V_296 , V_297 ) ;
}
if ( V_291 ) {
F_17 ( V_134 -> V_138 , V_78 ,
V_298 , V_299 ) ;
F_17 ( V_134 -> V_138 , V_105 ,
V_300 , V_301 ) ;
}
return 0 ;
}
int F_42 ( struct V_1 * V_2 ,
unsigned int V_302 , unsigned int V_303 )
{
struct V_133 * V_134 = F_8 ( V_2 ) ;
unsigned int V_304 = 0 ;
unsigned int V_305 = 0 ;
switch ( V_303 ) {
case V_306 :
case V_307 :
break;
default:
return - V_186 ;
}
if ( ! V_302 )
return - V_186 ;
if ( V_302 & V_308 ) {
V_304 |= V_309 ;
V_305 = ( V_305 & ~ V_309 )
| ( V_303 << V_310 ) ;
}
if ( V_302 & V_311 ) {
V_304 |= V_312 ;
V_305 = ( V_305 & ~ V_312 )
| ( V_303 << V_313 ) ;
}
if ( V_302 & V_314 ) {
V_304 |= V_315 ;
V_305 = ( V_305 & ~ V_315 )
| ( V_303 << V_316 ) ;
}
if ( V_302 & V_317 ) {
V_304 |= V_318 ;
V_305 = ( V_305 & ~ V_318 )
| ( V_303 << V_319 ) ;
}
if ( V_302 & V_320 ) {
V_304 |= V_321 ;
V_305 = ( V_305 & ~ V_321 )
| ( V_303 << V_322 ) ;
}
if ( V_302 & V_323 ) {
V_304 |= V_324 ;
V_305 = ( V_305 & ~ V_324 )
| ( V_303 << V_325 ) ;
}
F_12 ( V_2 , V_83 ,
V_304 , V_305 ) ;
if ( F_14 ( V_2 , V_83 ) ) {
V_134 -> V_147 = true ;
F_12 ( V_2 , V_102 , 0x3 , 0x3 ) ;
} else {
V_134 -> V_147 = false ;
F_12 ( V_2 , V_102 , 0x3 , 0x0 ) ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_326 * V_132 = F_44 ( V_2 ) ;
struct V_133 * V_134 = F_8 ( V_2 ) ;
V_134 -> V_283 = F_45 ( V_2 -> V_5 , L_13 ) ;
if ( F_46 ( V_134 -> V_283 ) == - V_327 )
return - V_327 ;
V_134 -> V_2 = V_2 ;
F_47 ( V_2 , V_285 ) ;
F_12 ( V_2 , V_124 , 0x0301 , 0x0301 ) ;
F_12 ( V_2 , V_94 , 0x0030 , 0x0030 ) ;
F_12 ( V_2 , V_48 , 0xfc00 , 0x0c00 ) ;
switch ( F_14 ( V_2 , V_3 ) & V_328 ) {
case V_329 :
case V_330 :
F_48 ( V_2 ,
V_331 ,
F_4 ( V_331 ) ) ;
F_49 ( V_132 ,
V_332 ,
F_4 ( V_332 ) ) ;
F_50 ( V_132 ,
V_333 ,
F_4 ( V_333 ) ) ;
break;
case V_334 :
F_49 ( V_132 ,
V_335 ,
F_4 ( V_335 ) ) ;
F_50 ( V_132 ,
V_336 ,
F_4 ( V_336 ) ) ;
break;
default:
F_11 ( V_2 -> V_5 ,
L_14 ) ;
return - V_337 ;
}
if ( V_134 -> V_338 . V_339 )
F_41 ( V_2 , V_134 -> V_338 . V_290 ,
V_134 -> V_338 . V_291 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = F_8 ( V_2 ) ;
F_47 ( V_2 , V_285 ) ;
F_1 ( V_2 ) ;
F_53 ( V_134 -> V_138 , true ) ;
F_54 ( V_134 -> V_138 ) ;
if ( F_55 ( V_134 -> V_338 . V_340 ) )
F_56 ( V_134 -> V_338 . V_340 , 0 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = F_8 ( V_2 ) ;
if ( F_55 ( V_134 -> V_338 . V_340 ) ) {
F_56 ( V_134 -> V_338 . V_340 , 1 ) ;
F_58 ( 400 ) ;
}
F_53 ( V_134 -> V_138 , false ) ;
F_59 ( V_134 -> V_138 ) ;
return 0 ;
}
static int F_60 ( struct V_133 * V_134 , struct V_341 * V_342 )
{
V_134 -> V_338 . V_343 = F_61 ( V_342 ,
L_15 ) ;
V_134 -> V_338 . V_344 = F_61 ( V_342 ,
L_16 ) ;
V_134 -> V_338 . V_340 = F_62 ( V_342 ,
L_17 , 0 ) ;
if ( ! F_55 ( V_134 -> V_338 . V_340 ) &&
( V_134 -> V_338 . V_340 != - V_345 ) )
return V_134 -> V_338 . V_340 ;
return 0 ;
}
static int F_63 ( struct V_346 * V_347 ,
const struct V_348 * V_215 )
{
struct V_349 * V_338 = F_64 ( & V_347 -> V_5 ) ;
struct V_133 * V_134 ;
int V_185 ;
unsigned int V_144 ;
V_134 = F_65 ( & V_347 -> V_5 ,
sizeof( struct V_133 ) ,
V_350 ) ;
if ( NULL == V_134 )
return - V_351 ;
F_66 ( V_347 , V_134 ) ;
if ( V_338 ) {
V_134 -> V_338 = * V_338 ;
if ( ! V_134 -> V_338 . V_340 )
V_134 -> V_338 . V_340 = - V_186 ;
} else if ( V_347 -> V_5 . V_352 ) {
V_185 = F_60 ( V_134 , V_347 -> V_5 . V_352 ) ;
if ( V_185 )
return V_185 ;
} else
V_134 -> V_338 . V_340 = - V_186 ;
V_134 -> V_138 = F_67 ( V_347 , & V_353 ) ;
if ( F_37 ( V_134 -> V_138 ) ) {
V_185 = F_46 ( V_134 -> V_138 ) ;
F_11 ( & V_347 -> V_5 , L_18 ,
V_185 ) ;
return V_185 ;
}
if ( F_55 ( V_134 -> V_338 . V_340 ) ) {
V_185 = F_68 ( & V_347 -> V_5 , V_134 -> V_338 . V_340 ,
V_354 ,
L_19 ) ;
if ( V_185 < 0 ) {
F_11 ( & V_347 -> V_5 , L_20 ,
V_134 -> V_338 . V_340 , V_185 ) ;
return V_185 ;
}
F_58 ( 400 ) ;
}
F_69 ( V_134 -> V_138 , V_27 , & V_144 ) ;
if ( V_144 != V_355 ) {
F_11 ( & V_347 -> V_5 ,
L_21 , V_144 ) ;
return - V_337 ;
}
F_18 ( V_134 -> V_138 , V_3 , 0 ) ;
V_185 = F_70 ( V_134 -> V_138 , V_356 ,
F_4 ( V_356 ) ) ;
if ( V_185 != 0 )
F_71 ( & V_347 -> V_5 , L_22 , V_185 ) ;
if ( V_134 -> V_338 . V_343 )
F_17 ( V_134 -> V_138 , V_32 ,
V_357 , V_357 ) ;
if ( V_134 -> V_338 . V_344 )
F_17 ( V_134 -> V_138 , V_33 ,
V_358 , V_358 ) ;
if ( V_134 -> V_338 . V_359 )
F_17 ( V_134 -> V_138 , V_32 ,
V_358 , V_358 ) ;
V_134 -> V_179 = 1 ;
return F_72 ( & V_347 -> V_5 , & V_360 ,
V_361 , F_4 ( V_361 ) ) ;
}
static int F_73 ( struct V_346 * V_347 )
{
F_74 ( & V_347 -> V_5 ) ;
return 0 ;
}
