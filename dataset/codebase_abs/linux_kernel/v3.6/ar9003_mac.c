static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 , 0 ) ;
}
static void
F_3 ( struct V_1 * V_4 , void * V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 = V_5 ;
int V_10 = 0 ;
T_1 V_11 , V_12 , V_13 ;
T_2 V_14 ;
V_14 = ( F_4 ( V_4 ) ? 0x18 : 0x17 ) ;
V_11 = ( V_15 << V_16 ) |
( 1 << V_17 ) |
( 1 << V_18 ) |
( V_7 -> V_19 << V_20 ) | V_14 ;
V_10 += V_11 ;
F_5 ( V_9 -> V_21 ) = V_11 ;
V_10 += V_7 -> V_22 ;
F_5 ( V_9 -> V_22 ) = V_7 -> V_22 ;
V_10 += V_7 -> V_23 [ 0 ] ;
F_5 ( V_9 -> V_24 ) = V_7 -> V_23 [ 0 ] ;
V_10 += V_7 -> V_23 [ 1 ] ;
F_5 ( V_9 -> V_25 ) = V_7 -> V_23 [ 1 ] ;
V_10 += V_7 -> V_23 [ 2 ] ;
F_5 ( V_9 -> V_26 ) = V_7 -> V_23 [ 2 ] ;
V_10 += V_7 -> V_23 [ 3 ] ;
F_5 ( V_9 -> V_27 ) = V_7 -> V_23 [ 3 ] ;
V_10 += ( V_11 = ( V_7 -> V_28 [ 0 ] << V_29 ) & V_30 ) ;
F_5 ( V_9 -> V_31 ) = V_11 ;
V_10 += ( V_11 = ( V_7 -> V_28 [ 1 ] << V_29 ) & V_30 ) ;
F_5 ( V_9 -> V_32 ) = V_11 ;
V_10 += ( V_11 = ( V_7 -> V_28 [ 2 ] << V_29 ) & V_30 ) ;
F_5 ( V_9 -> V_33 ) = V_11 ;
V_10 += ( V_11 = ( V_7 -> V_28 [ 3 ] << V_29 ) & V_30 ) ;
F_5 ( V_9 -> V_34 ) = V_11 ;
V_10 = ( V_35 ) ( ( ( V_10 & 0xffff ) + ( V_10 >> 16 ) ) & 0xffff ) ;
F_5 ( V_9 -> V_36 ) = V_10 ;
if ( V_7 -> V_37 || V_7 -> V_38 ) {
F_5 ( V_9 -> V_39 ) = F_6 ( V_7 -> V_40 , 0 )
| F_6 ( V_7 -> V_40 , 1 )
| F_6 ( V_7 -> V_40 , 2 )
| F_6 ( V_7 -> V_40 , 3 )
| ( V_7 -> V_41 ? V_42 : 0 )
| F_7 ( 0 , V_43 ) ;
F_5 ( V_9 -> V_44 ) = F_8 ( V_7 -> V_40 , 0 )
| F_8 ( V_7 -> V_40 , 1 )
| F_8 ( V_7 -> V_40 , 2 )
| F_8 ( V_7 -> V_40 , 3 ) ;
} else {
F_5 ( V_9 -> V_39 ) = 0 ;
F_5 ( V_9 -> V_44 ) = 0 ;
}
V_9 -> V_45 = 0 ;
V_9 -> V_46 = 0 ;
V_9 -> V_47 = 0 ;
V_9 -> V_48 = 0 ;
V_13 = F_7 ( V_7 -> V_49 , V_50 ) ;
if ( ! V_7 -> V_37 ) {
F_5 ( V_9 -> V_51 ) = 0 ;
F_5 ( V_9 -> V_12 ) = V_7 -> V_38 ? 0 : V_52 ;
F_5 ( V_9 -> V_53 ) = 0 ;
F_5 ( V_9 -> V_54 ) = 0 ;
F_5 ( V_9 -> V_13 ) = V_13 ;
F_5 ( V_9 -> V_55 ) = 0 ;
F_5 ( V_9 -> V_56 ) = 0 ;
return;
}
F_5 ( V_9 -> V_51 ) = ( V_7 -> V_57 & V_58 )
| ( V_7 -> V_59 & V_60 ? V_61 : 0 )
| F_7 ( V_7 -> V_62 , V_63 )
| ( V_7 -> V_59 & V_64 ? V_65 : 0 )
| ( V_7 -> V_66 != V_67 ? V_68 : 0 )
| ( V_7 -> V_59 & V_69 ? V_70 : 0 )
| ( V_7 -> V_59 & V_71 ? V_72 : 0 )
| ( V_7 -> V_59 & V_73 ? V_74 :
( V_7 -> V_59 & V_75 ? V_76 : 0 ) ) ;
V_12 = ( V_7 -> V_66 != V_67 ?
F_7 ( V_7 -> V_66 , V_77 ) : 0 )
| F_7 ( V_7 -> type , V_78 )
| ( V_7 -> V_59 & V_79 ? V_80 : 0 )
| ( V_7 -> V_59 & V_81 ? V_82 : 0 )
| ( V_7 -> V_59 & V_83 ? V_84 : 0 ) ;
V_13 |= ( V_7 -> V_59 & V_85 ? V_86 : 0 ) ;
switch ( V_7 -> V_87 ) {
case V_88 :
V_13 |= F_7 ( V_7 -> V_89 , V_90 ) ;
case V_91 :
V_12 |= V_92 | V_93 ;
V_13 |= F_7 ( V_7 -> V_94 , V_95 ) ;
break;
case V_96 :
V_12 |= V_92 ;
break;
case V_97 :
break;
}
V_11 = ( V_7 -> V_59 & V_98 ) >> V_99 ;
V_12 |= F_7 ( V_11 , V_100 ) ;
F_5 ( V_9 -> V_12 ) = V_12 ;
F_5 ( V_9 -> V_13 ) = V_13 ;
F_5 ( V_9 -> V_53 ) = F_9 ( V_7 -> V_40 , 0 )
| F_9 ( V_7 -> V_40 , 1 ) ;
F_5 ( V_9 -> V_54 ) = F_9 ( V_7 -> V_40 , 2 )
| F_9 ( V_7 -> V_40 , 3 ) ;
F_5 ( V_9 -> V_55 ) = F_10 ( V_7 -> V_40 , 0 )
| F_10 ( V_7 -> V_40 , 1 )
| F_10 ( V_7 -> V_40 , 2 )
| F_10 ( V_7 -> V_40 , 3 )
| F_7 ( V_7 -> V_101 , V_102 ) ;
F_5 ( V_9 -> V_56 ) = V_103 ;
}
static V_35 F_11 ( struct V_8 * V_9 )
{
int V_10 ;
V_10 = V_9 -> V_21 + V_9 -> V_22
+ V_9 -> V_24 + V_9 -> V_31
+ V_9 -> V_25 + V_9 -> V_32
+ V_9 -> V_26 + V_9 -> V_33
+ V_9 -> V_27 + V_9 -> V_34 ;
return ( ( V_10 & 0xffff ) + ( V_10 >> 16 ) ) & V_104 ;
}
static void F_12 ( void * V_5 , T_1 V_105 )
{
struct V_8 * V_9 = V_5 ;
V_9 -> V_22 = V_105 ;
V_9 -> V_36 &= ~ V_104 ;
V_9 -> V_36 |= F_11 ( V_9 ) ;
}
static bool F_13 ( struct V_1 * V_4 , enum V_106 * V_107 )
{
T_1 V_108 = 0 ;
T_1 V_109 = 0 ;
struct V_110 * V_111 = & V_4 -> V_112 ;
struct V_113 * V_114 = F_14 ( V_4 ) ;
T_1 V_115 = 0 , V_116 , V_117 = V_118 ;
if ( F_15 ( V_4 ) )
V_117 |= V_119 ;
V_116 = F_16 ( V_4 , V_120 ) ;
if ( V_116 & V_117 ) {
if ( ( F_16 ( V_4 , V_121 ) & V_122 )
== V_123 )
V_108 = F_16 ( V_4 , V_124 ) ;
}
V_115 = F_16 ( V_4 , V_125 ) & V_126 ;
* V_107 = 0 ;
if ( ! V_108 && ! V_115 && ! V_116 )
return false ;
if ( V_108 ) {
if ( V_108 & V_127 ) {
T_1 V_128 ;
V_128 = F_16 ( V_4 , V_129 ) ;
V_109 |= ( ( V_128 & V_130 ) >>
V_131 ) ;
V_109 |= ( ( V_128 & V_132 ) >>
V_133 ) ;
V_109 |= ( ( V_128 & V_134 ) >>
V_135 ) ;
V_109 |= ( ( V_128 & V_136 ) >>
V_137 ) ;
V_109 |= ( ( V_128 & V_138 ) <<
V_139 ) ;
V_109 |= ( ( V_128 & V_140 ) <<
V_141 ) ;
V_109 |= ( ( V_128 & V_142 ) >>
V_143 ) ;
V_109 |= ( ( V_128 & V_144 ) >>
V_145 ) ;
if ( ! ( V_111 -> V_146 & V_147 ) ) {
F_2 ( V_4 , V_129 , V_128 ) ;
V_108 &= ~ V_127 ;
}
}
if ( ( V_111 -> V_146 & V_147 ) )
V_108 = F_16 ( V_4 , V_148 ) ;
if ( V_108 == 0xffffffff ) {
* V_107 = 0 ;
return false ;
}
* V_107 = V_108 & V_149 ;
if ( V_4 -> V_150 . V_151 )
if ( V_108 & ( V_152 | V_153 ) )
* V_107 |= V_154 ;
if ( V_4 -> V_150 . V_155 )
if ( V_108 & ( V_156 | V_157 ) )
* V_107 |= V_158 ;
if ( V_108 & ( V_159 | V_160 ) )
* V_107 |= V_154 ;
if ( V_108 & V_161 )
* V_107 |= V_162 ;
if ( V_108 & ( V_163 | V_164 | V_165 ) ) {
* V_107 |= V_158 ;
if ( ! ( V_111 -> V_146 & V_147 ) ) {
T_1 V_166 , V_167 ;
V_166 = F_16 ( V_4 , V_168 ) ;
F_2 ( V_4 , V_168 , V_166 ) ;
V_167 = F_16 ( V_4 , V_169 ) ;
F_2 ( V_4 , V_169 , V_167 ) ;
V_108 &= ~ ( V_163 | V_164 |
V_165 ) ;
}
}
if ( V_108 & V_170 ) {
T_1 V_171 ;
if ( V_111 -> V_146 & V_147 )
V_171 = F_16 ( V_4 , V_172 ) ;
else
V_171 = F_16 ( V_4 , V_173 ) ;
V_4 -> V_174 =
F_17 ( V_171 , V_175 ) ;
V_4 -> V_176 =
F_17 ( V_171 , V_177 ) ;
if ( V_4 -> V_174 )
* V_107 |= V_178 ;
if ( ! ( V_111 -> V_146 & V_147 ) ) {
F_2 ( V_4 , V_173 , V_171 ) ;
V_108 &= ~ V_170 ;
}
}
* V_107 |= V_109 ;
if ( ! ( V_111 -> V_146 & V_147 ) ) {
F_2 ( V_4 , V_124 , V_108 ) ;
( void ) F_16 ( V_4 , V_124 ) ;
}
if ( * V_107 & V_179 )
F_18 ( V_4 ) ;
}
if ( V_116 & V_119 )
F_19 ( V_4 , V_107 ) ;
if ( V_115 ) {
F_20 ( V_114 , V_115 ) ;
if ( V_115 & V_180 ) {
F_2 ( V_4 , V_181 , V_182 ) ;
F_2 ( V_4 , V_181 , 0 ) ;
* V_107 |= V_183 ;
}
if ( V_115 & V_184 )
F_21 ( V_114 , V_185 ,
L_1 ) ;
F_2 ( V_4 , V_186 , V_115 ) ;
( void ) F_16 ( V_4 , V_186 ) ;
}
return true ;
}
static int F_22 ( struct V_1 * V_4 , void * V_5 ,
struct V_187 * V_188 )
{
struct V_189 * V_9 ;
T_1 V_190 ;
V_9 = & V_4 -> V_191 [ V_4 -> V_192 ] ;
V_190 = F_5 ( V_9 -> V_193 ) ;
if ( ( V_190 & V_194 ) == 0 )
return - V_195 ;
V_4 -> V_192 = ( V_4 -> V_192 + 1 ) % V_4 -> V_196 ;
if ( ( F_17 ( V_9 -> V_197 , V_198 ) != V_15 ) ||
( F_17 ( V_9 -> V_197 , V_199 ) != 1 ) ) {
F_21 ( F_14 ( V_4 ) , V_200 ,
L_2 , V_9 -> V_197 ) ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
return - V_201 ;
}
V_188 -> V_202 = F_17 ( V_190 , V_203 ) ;
V_188 -> V_204 = F_17 ( V_190 , V_205 ) ;
V_188 -> V_206 = F_17 ( V_190 , V_207 ) ;
V_188 -> V_208 = F_17 ( V_9 -> V_197 , V_209 ) ;
V_188 -> V_210 = F_17 ( V_9 -> V_211 , V_212 ) ;
V_188 -> V_213 = V_9 -> V_214 ;
V_188 -> V_215 = 0 ;
V_188 -> V_216 = 0 ;
if ( V_190 & V_217 )
V_188 -> V_215 |= V_218 ;
V_190 = F_5 ( V_9 -> V_219 ) ;
V_188 -> V_220 = F_17 ( V_190 , V_221 ) ;
V_188 -> V_222 = F_17 ( V_190 , V_223 ) ;
V_188 -> V_224 = F_17 ( V_190 , V_225 ) ;
if ( V_190 & V_226 ) {
V_188 -> V_216 |= V_227 ;
V_188 -> V_228 = V_9 -> V_229 ;
V_188 -> V_230 = V_9 -> V_231 ;
}
V_190 = F_5 ( V_9 -> V_232 ) ;
if ( V_190 & V_233 )
V_188 -> V_215 |= V_234 ;
if ( V_190 & V_235 )
V_188 -> V_215 |= V_236 ;
if ( V_190 & V_237 ) {
V_188 -> V_215 |= V_238 ;
F_23 ( V_4 , true ) ;
}
if ( V_190 & V_239 )
V_188 -> V_215 |= V_240 ;
if ( V_190 & V_241 )
V_188 -> V_216 |= V_242 ;
if ( V_190 & V_243 ) {
V_188 -> V_216 |= V_244 ;
F_23 ( V_4 , true ) ;
}
if ( V_190 & V_245 ) {
V_188 -> V_216 |= V_246 ;
F_23 ( V_4 , true ) ;
}
V_188 -> V_247 = F_17 ( V_190 , V_248 ) ;
V_188 -> V_249 = F_17 ( V_190 , V_250 ) ;
V_188 -> V_251 = F_17 ( V_190 , V_252 ) ;
V_190 = F_5 ( V_9 -> V_253 ) ;
V_188 -> V_254 = F_17 ( V_190 , V_255 ) ;
V_188 -> V_256 = F_17 ( V_190 , V_257 ) ;
V_188 -> V_258 = F_17 ( V_190 , V_259 ) ;
V_188 -> V_260 = F_17 ( V_190 , V_261 ) ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
return 0 ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_262 * V_263 = F_25 ( V_2 ) ;
V_263 -> V_264 = F_1 ;
V_263 -> V_265 = F_12 ;
V_263 -> V_266 = F_13 ;
V_263 -> V_267 = F_3 ;
V_263 -> V_268 = F_22 ;
}
void F_26 ( struct V_1 * V_4 , V_35 V_269 )
{
F_2 ( V_4 , V_270 , V_269 & V_271 ) ;
}
void F_27 ( struct V_1 * V_4 , T_1 V_272 ,
enum V_273 V_274 )
{
if ( V_274 == V_275 )
F_2 ( V_4 , V_276 , V_272 ) ;
else
F_2 ( V_4 , V_277 , V_272 ) ;
}
int F_28 ( struct V_1 * V_4 , struct V_278 * V_279 ,
void * V_23 )
{
struct V_280 * V_281 = (struct V_280 * ) V_23 ;
unsigned int V_282 ;
if ( ( V_281 -> V_283 & V_284 ) == 0 )
return - V_195 ;
if ( F_17 ( V_281 -> V_197 , V_198 ) != 0x168c )
return - V_285 ;
if ( ( V_281 -> V_197 & ( V_199 | V_286 ) ) != 0 )
return - V_195 ;
V_279 -> V_287 = 0 ;
V_279 -> V_288 = 0 ;
V_279 -> V_289 = V_281 -> V_219 & V_290 ;
V_279 -> V_291 = V_281 -> V_232 ;
V_279 -> V_292 = F_17 ( V_281 -> V_229 , V_293 ) ;
V_279 -> V_294 = F_17 ( V_281 -> V_211 , V_295 ) ;
V_279 -> V_296 = F_17 ( V_281 -> V_211 , V_297 ) ;
V_279 -> V_298 = F_17 ( V_281 -> V_211 , V_299 ) ;
V_279 -> V_300 = F_17 ( V_281 -> V_229 , V_301 ) ;
V_279 -> V_302 = F_17 ( V_281 -> V_229 , V_303 ) ;
V_279 -> V_304 = F_17 ( V_281 -> V_229 , V_305 ) ;
if ( V_281 -> V_283 & V_306 )
V_279 -> V_307 = F_17 ( V_281 -> V_283 , V_308 ) ;
else
V_279 -> V_307 = V_309 ;
V_279 -> V_310 = F_17 ( V_281 -> V_211 , V_311 ) ;
V_279 -> V_312 = ( V_281 -> V_219 & V_313 ) ? 1 : 0 ;
V_279 -> V_314 = ( V_281 -> V_283 & V_315 ) ? 1 : 0 ;
V_279 -> V_316 = ( V_281 -> V_283 & V_317 ) ? 1 : 0 ;
V_279 -> V_318 = ( F_17 ( V_281 -> V_214 , V_319 ) & 0x7 ) ;
V_279 -> V_288 = ( V_281 -> V_214 & V_320 ) ? V_321 : 0 ;
V_279 -> V_288 |= ( V_281 -> V_214 & V_322 ) ? V_323 : 0 ;
V_279 -> V_324 = V_281 -> V_231 ;
V_279 -> V_325 = V_281 -> V_253 ;
V_279 -> V_326 = V_281 -> V_193 ;
V_279 -> V_327 = V_281 -> V_328 ;
V_279 -> V_329 = ( V_281 -> V_330 & 0xffff ) ;
if ( V_281 -> V_283 & V_331 )
V_279 -> V_288 |= V_332 ;
if ( V_281 -> V_283 & V_333 )
V_279 -> V_288 |= V_334 ;
if ( V_281 -> V_283 & V_335 )
V_279 -> V_288 |= V_336 ;
if ( ( V_281 -> V_283 & V_337 ) == 0 ) {
if ( V_281 -> V_283 & V_338 )
V_279 -> V_287 |= V_339 ;
else if ( V_281 -> V_283 & V_340 )
V_279 -> V_287 |= V_341 ;
else if ( V_281 -> V_283 & V_342 )
V_279 -> V_287 |= V_343 ;
if ( V_281 -> V_283 & V_344 ) {
V_282 = F_17 ( V_281 -> V_283 , V_345 ) ;
if ( ( V_282 == V_346 ) &&
( V_281 -> V_283 & V_333 ) ) {
V_279 -> V_347 = 0 ;
} else {
V_279 -> V_287 |= V_348 ;
V_279 -> V_347 = V_282 ;
}
} ;
}
if ( V_281 -> V_283 & V_349 )
V_279 -> V_287 |= V_350 ;
return 0 ;
}
void F_29 ( struct V_1 * V_4 )
{
V_4 -> V_192 = 0 ;
memset ( ( void * ) V_4 -> V_191 , 0 ,
V_4 -> V_196 * sizeof( struct V_189 ) ) ;
F_21 ( F_14 ( V_4 ) , V_200 ,
L_3 ,
V_4 -> V_351 , V_4 -> V_352 ,
V_4 -> V_191 , V_4 -> V_196 ) ;
F_2 ( V_4 , V_353 , V_4 -> V_351 ) ;
F_2 ( V_4 , V_354 , V_4 -> V_352 ) ;
}
void F_30 ( struct V_1 * V_4 , void * V_355 ,
T_1 V_351 ,
V_35 V_356 )
{
V_4 -> V_351 = V_351 ;
V_4 -> V_352 = V_351 + ( V_356 * sizeof( struct V_189 ) ) ;
V_4 -> V_196 = V_356 ;
V_4 -> V_191 = (struct V_189 * ) V_355 ;
F_29 ( V_4 ) ;
}
