static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 ,
T_1 V_6 , struct V_7 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
T_1 V_15 = 0 ;
T_2 V_16 [ V_17 ] ;
int V_18 ;
memset ( V_16 , 0 , V_17 ) ;
if ( ( V_4 == V_19 ) &&
( V_8 -> V_20 == V_21 ) ) {
V_12 = (struct V_11 * ) V_8 ;
memcpy ( V_16 , & V_12 -> V_22 . V_23 , V_24 ) ;
F_3 ( F_4 ( V_25 , V_10 , L_1
L_2 , V_26 ,
& V_10 -> V_27 . V_28 , V_16 ) ) ;
V_18 = F_5 ( V_10 , V_15 , V_5 , V_6 ,
V_16 ) ;
if ( V_18 )
V_18 = - V_29 ;
} else if ( ( V_4 == V_30 ) &&
( V_8 -> V_20 == V_31 ) ) {
V_14 = (struct V_13 * ) V_8 ;
memcpy ( V_16 , & V_14 -> V_32 . V_33 . V_34 , V_17 ) ;
V_15 |= V_35 ;
if ( ( V_3 == 0 ) || ( V_3 == 1 ) ) {
F_3 ( F_4 ( V_25 , V_10 , L_3
L_4 , V_26 ,
& V_10 -> V_27 . V_36 ,
V_16 ) ) ;
V_15 |= V_37 ;
V_18 = F_5 ( V_10 , V_15 , V_5 ,
V_6 , V_16 ) ;
} else {
F_4 ( V_38 , V_10 , L_5
L_6 , V_26 , V_3 ) ;
V_18 = - V_39 ;
goto V_40;
}
if ( V_18 != V_41 ) {
V_15 &= ~ V_37 ;
if ( V_3 == 0 ) {
V_15 |= V_42 ;
F_3 ( F_4 ( V_25 , V_10 , L_7
L_8
L_9 , V_26 ,
& V_10 -> V_27 . V_43 ,
V_16 ) ) ;
} else if ( V_3 == 1 ) {
V_15 |= V_44 ;
F_3 ( F_4 ( V_25 , V_10 , L_7
L_8
L_9 , V_26 ,
& V_10 -> V_27 . V_45 ,
V_16 ) ) ;
}
V_18 = F_5 ( V_10 , V_15 , V_5 ,
V_6 , V_16 ) ;
if ( V_18 )
V_18 = - V_29 ;
}
} else
V_18 = - V_39 ;
V_40:
return V_18 ;
}
static T_3 F_6 ( int V_46 , int V_47 )
{
switch ( V_46 ) {
case V_48 :
switch ( V_47 ) {
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
return V_54 ;
default:
return 0 ;
}
case V_55 :
switch ( V_47 ) {
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
case V_109 :
case V_110 :
case V_111 :
case V_112 :
return V_54 ;
default:
return 0 ;
}
case V_113 :
switch ( V_47 ) {
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
case V_127 :
case V_128 :
return V_54 ;
default:
return 0 ;
}
case V_129 :
switch ( V_47 ) {
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
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
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
return V_54 ;
default:
return 0 ;
}
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_4 V_186 ,
T_1 * V_187 , char * V_188 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_189 * V_190 ;
struct V_191 * V_192 ;
int V_193 = 0 ;
int V_194 = 0 ;
int V_195 = 0 , V_196 ;
if ( F_8 ( V_10 ) )
V_193 = ( V_10 -> V_197 . V_198 / 2 ) /
sizeof( struct V_189 ) ;
else
V_193 = V_199 ;
F_4 ( V_25 , V_10 , L_10 ,
V_26 , * V_187 , V_186 ) ;
if ( ! V_188 ) {
V_195 = - V_200 ;
goto V_201;
}
V_192 = (struct V_191 * ) V_188 ;
F_9 ( & V_10 -> V_202 ) ;
for ( V_196 = V_186 ; V_196 < V_193 ; V_196 ++ ) {
V_190 = (struct V_189 * ) V_10 -> V_203 + V_196 ;
if ( V_190 -> V_204 !=
F_10 ( V_205 ) )
continue;
V_192 -> V_186 = V_196 ;
strncpy ( V_192 -> V_206 , V_190 -> V_207 ,
V_208 ) ;
strncpy ( V_192 -> V_209 , V_190 -> V_210 ,
V_211 ) ;
V_192 -> V_212 = V_190 -> V_213 ;
if ( V_190 -> V_214 & V_215 )
V_192 -> V_216 = V_217 ;
if ( V_190 -> V_214 & V_218 )
V_192 -> V_216 = V_219 ;
V_192 ++ ;
V_194 ++ ;
if ( V_194 == * V_187 )
break;
else
continue;
}
F_11 ( & V_10 -> V_202 ) ;
V_201:
F_4 ( V_25 , V_10 , L_11 ,
V_26 , V_194 ) ;
* V_187 = V_194 ;
return V_195 ;
}
static int F_12 ( struct V_220 * V_221 , void * V_222 )
{
int V_195 = 0 ;
T_4 * V_186 = ( T_4 * ) V_222 ;
struct V_223 * V_224 ;
struct V_225 * V_226 ;
struct V_227 * V_227 ;
if ( ! F_13 ( V_221 ) )
goto V_228;
V_224 = F_14 ( V_221 ) ;
V_226 = V_224 -> V_229 ;
V_227 = V_226 -> V_229 ;
if ( F_15 ( V_224 ) )
goto V_228;
if ( V_227 -> V_186 == * V_186 )
V_195 = 1 ;
V_228:
return V_195 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_4 V_186 )
{
int V_195 = 0 ;
V_195 = F_17 ( & V_2 -> V_230 , & V_186 ,
F_12 ) ;
return V_195 ;
}
static int F_18 ( struct V_1 * V_2 , T_4 V_186 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_189 * V_190 ;
T_5 V_231 ;
int V_193 = 0 ;
T_1 V_232 = 0 ;
T_1 V_233 ;
int V_195 = 0 ;
V_190 = F_19 ( V_10 -> V_234 , V_235 , & V_231 ) ;
if ( V_190 == NULL )
return - V_200 ;
memset ( V_190 , 0 , sizeof( struct V_189 ) ) ;
if ( F_8 ( V_10 ) )
V_193 = ( V_10 -> V_197 . V_198 / 2 ) /
sizeof( struct V_189 ) ;
else
V_193 = V_199 ;
if ( V_186 > V_193 ) {
V_195 = - V_29 ;
goto V_236;
}
V_195 = F_16 ( V_2 , V_186 ) ;
if ( V_195 ) {
F_4 ( V_25 , V_10 , L_12
L_13 , V_186 ) ;
V_195 = - V_237 ;
goto V_236;
}
V_233 = sizeof( struct V_189 ) ;
if ( F_20 ( V_10 ) )
V_232 = V_238 | ( V_186 * V_233 ) ;
else {
V_232 = V_239 + ( V_10 -> V_197 . V_240 << 2 ) ;
if ( V_10 -> V_241 == 1 )
V_232 += ( V_10 -> V_197 . V_198 / 2 ) ;
V_232 += ( V_186 * V_233 ) ;
}
V_195 = F_21 ( V_10 , V_231 , V_232 , V_233 ) ;
if ( V_195 != V_41 ) {
V_195 = - V_29 ;
goto V_236;
}
F_3 ( F_4 ( V_25 , V_10 , L_14 ,
F_22 ( V_190 -> V_204 ) ) ) ;
if ( F_22 ( V_190 -> V_204 ) != V_205 ) {
F_4 ( V_242 , V_10 , L_15 ) ;
goto V_236;
}
V_190 -> V_204 = F_10 ( 0xFFFF ) ;
V_232 = V_238 |
( V_186 * sizeof( struct V_189 ) ) ;
V_195 = F_23 ( V_10 , V_231 , V_232 , V_233 ,
V_243 ) ;
if ( V_195 == V_41 && V_10 -> V_203 ) {
F_9 ( & V_10 -> V_202 ) ;
memcpy ( (struct V_189 * ) V_10 -> V_203 + V_186 ,
V_190 , sizeof( struct V_189 ) ) ;
F_11 ( & V_10 -> V_202 ) ;
}
if ( V_195 != V_41 )
V_195 = - V_29 ;
V_236:
F_24 ( V_10 -> V_234 , V_190 , V_231 ) ;
return V_195 ;
}
static int F_25 ( struct V_244 * V_245 ,
enum V_246 V_46 ,
int V_47 , char * V_188 )
{
struct V_1 * V_2 = F_26 ( V_245 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_247 = - V_39 ;
if ( V_46 != V_113 )
return - V_39 ;
switch ( V_47 ) {
case V_114 :
V_247 = sprintf ( V_188 , L_16 , & V_10 -> V_27 . V_28 ) ;
break;
case V_115 :
V_247 = sprintf ( V_188 , L_16 , & V_10 -> V_27 . V_248 ) ;
break;
case V_116 :
V_247 = sprintf ( V_188 , L_16 , & V_10 -> V_27 . V_249 ) ;
break;
case V_118 :
if ( V_245 -> V_4 == V_19 )
V_247 = sprintf ( V_188 , L_17 ,
( V_10 -> V_27 . V_250 &
V_251 ) ?
L_18 : L_19 ) ;
else if ( V_245 -> V_4 == V_30 )
V_247 = sprintf ( V_188 , L_17 ,
( V_10 -> V_27 . V_252 &
V_253 ) ?
L_18 : L_19 ) ;
break;
case V_117 :
V_247 = sprintf ( V_188 , L_17 ,
( V_10 -> V_27 . V_254 & V_255 ) ?
L_20 : L_21 ) ;
break;
case V_120 :
if ( V_245 -> V_3 == 0 )
V_247 = sprintf ( V_188 , L_22 , & V_10 -> V_27 . V_43 ) ;
if ( V_245 -> V_3 == 1 )
V_247 = sprintf ( V_188 , L_22 , & V_10 -> V_27 . V_45 ) ;
break;
case V_119 :
V_247 = sprintf ( V_188 , L_22 ,
& V_10 -> V_27 . V_36 ) ;
break;
case V_121 :
V_247 = sprintf ( V_188 , L_22 ,
& V_10 -> V_27 . V_256 ) ;
break;
case V_122 :
V_247 = sprintf ( V_188 , L_17 ,
( V_10 -> V_27 . V_257 &
V_258 ) ?
L_23 : L_21 ) ;
break;
case V_123 :
V_247 = sprintf ( V_188 , L_17 ,
( V_10 -> V_27 . V_257 &
V_259 ) ?
L_24 : L_21 ) ;
break;
case V_124 :
if ( V_245 -> V_4 == V_19 )
V_247 = sprintf ( V_188 , L_25 ,
( V_10 -> V_27 . V_260 &
V_261 ) ) ;
else if ( V_245 -> V_4 == V_30 )
V_247 = sprintf ( V_188 , L_25 ,
( V_10 -> V_27 . V_262 &
V_261 ) ) ;
break;
case V_125 :
if ( V_245 -> V_4 == V_19 )
V_247 = sprintf ( V_188 , L_25 ,
( ( V_10 -> V_27 . V_260 >> 13 ) &
V_263 ) ) ;
else if ( V_245 -> V_4 == V_30 )
V_247 = sprintf ( V_188 , L_25 ,
( ( V_10 -> V_27 . V_262 >> 13 ) &
V_263 ) ) ;
break;
case V_126 :
if ( V_245 -> V_4 == V_19 )
V_247 = sprintf ( V_188 , L_17 ,
( V_10 -> V_27 . V_250 &
V_264 ) ?
L_18 : L_19 ) ;
else if ( V_245 -> V_4 == V_30 )
V_247 = sprintf ( V_188 , L_17 ,
( V_10 -> V_27 . V_252 &
V_265 ) ?
L_18 : L_19 ) ;
break;
case V_127 :
V_247 = sprintf ( V_188 , L_25 , V_10 -> V_27 . V_266 ) ;
break;
case V_128 :
if ( V_245 -> V_4 == V_19 )
V_247 = sprintf ( V_188 , L_25 , V_10 -> V_27 . V_267 ) ;
else if ( V_245 -> V_4 == V_30 )
V_247 = sprintf ( V_188 , L_25 , V_10 -> V_27 . V_268 ) ;
break;
default:
V_247 = - V_39 ;
}
return V_247 ;
}
static struct V_269 *
F_27 ( struct V_1 * V_2 , struct V_7 * V_8 ,
int V_270 )
{
int V_195 ;
struct V_269 * V_271 ;
struct V_272 * V_273 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
if ( ! V_2 ) {
V_195 = - V_274 ;
F_28 ( V_242 L_27 ,
V_26 ) ;
return F_29 ( V_195 ) ;
}
V_10 = F_30 ( V_2 ) ;
V_271 = F_31 ( sizeof( struct V_272 ) ) ;
if ( ! V_271 ) {
V_195 = - V_200 ;
return F_29 ( V_195 ) ;
}
V_273 = V_271 -> V_229 ;
memset ( V_273 , 0 , sizeof( struct V_272 ) ) ;
if ( V_8 -> V_20 == V_21 ) {
memcpy ( & V_273 -> V_8 , V_8 , sizeof( struct V_11 ) ) ;
V_12 = (struct V_11 * ) & V_273 -> V_8 ;
F_3 ( F_4 ( V_25 , V_10 , L_28 , V_26 ,
( char * ) & V_12 -> V_22 ) ) ;
} else if ( V_8 -> V_20 == V_31 ) {
memcpy ( & V_273 -> V_8 , V_8 ,
sizeof( struct V_13 ) ) ;
V_14 = (struct V_13 * ) & V_273 -> V_8 ;
F_3 ( F_4 ( V_25 , V_10 , L_29 , V_26 ,
( char * ) & V_14 -> V_32 ) ) ;
}
V_273 -> V_275 = V_2 ;
return V_271 ;
}
static int F_32 ( struct V_269 * V_271 , int V_276 )
{
struct V_272 * V_273 ;
struct V_9 * V_10 ;
int V_195 = 0 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
V_273 = V_271 -> V_229 ;
V_10 = F_2 ( V_273 -> V_275 ) ;
if ( F_33 ( V_10 ) && ! F_34 ( V_277 , & V_10 -> V_214 ) )
V_195 = 1 ;
return V_195 ;
}
static void F_35 ( struct V_269 * V_271 )
{
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
F_36 ( V_271 ) ;
}
static int F_37 ( struct V_269 * V_271 ,
enum V_278 V_47 ,
char * V_188 )
{
struct V_272 * V_273 = V_271 -> V_229 ;
struct V_7 * V_8 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
switch ( V_47 ) {
case V_59 :
case V_58 :
if ( ! V_273 )
return - V_279 ;
V_8 = (struct V_7 * ) & V_273 -> V_8 ;
if ( ! V_8 )
return - V_279 ;
return F_38 ( (struct V_280 * )
& V_273 -> V_8 , V_47 , V_188 ) ;
default:
return - V_39 ;
}
}
static void F_39 ( struct V_281 * V_282 ,
struct V_283 * V_284 )
{
struct V_225 * V_226 ;
struct V_223 * V_285 ;
struct V_227 * V_227 ;
struct V_9 * V_10 ;
struct V_286 * V_286 ;
int V_287 ;
int V_195 ;
T_5 V_288 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
V_285 = F_40 ( V_282 ) ;
V_226 = V_285 -> V_229 ;
V_227 = V_226 -> V_229 ;
V_10 = V_227 -> V_10 ;
V_287 = F_41 ( sizeof( struct V_286 ) ) ;
V_286 = F_42 ( & V_10 -> V_289 -> V_221 , V_287 ,
& V_288 , V_235 ) ;
if ( ! V_286 ) {
F_4 ( V_242 , V_10 ,
L_30 ) ;
goto V_290;
}
V_195 = F_43 ( V_10 , V_227 -> V_291 , V_287 ,
V_288 ) ;
if ( V_195 != V_41 ) {
F_4 ( V_242 , V_10 ,
L_31 ) ;
goto V_292;
}
V_284 -> V_293 = F_44 ( V_286 -> V_294 ) ;
V_284 -> V_295 = F_44 ( V_286 -> V_296 ) ;
V_284 -> V_297 = F_45 ( V_286 -> V_298 ) ;
V_284 -> V_299 = F_45 ( V_286 -> V_300 ) ;
V_284 -> V_301 = F_45 ( V_286 -> V_302 ) ;
V_284 -> V_303 = F_45 ( V_286 -> V_304 ) ;
V_284 -> V_305 = F_45 ( V_286 -> V_306 ) ;
V_284 -> V_307 = F_45 ( V_286 -> V_308 ) ;
V_284 -> V_309 = F_45 ( V_286 -> V_310 ) ;
V_284 -> V_311 = F_45 ( V_286 -> V_312 ) ;
V_284 -> V_313 = F_45 ( V_286 -> V_314 ) ;
V_284 -> V_315 = F_45 ( V_286 -> V_316 ) ;
V_284 -> V_317 = F_45 ( V_286 -> V_318 ) ;
V_284 -> V_319 = F_45 ( V_286 -> V_320 ) ;
V_284 -> V_321 = F_45 ( V_286 -> V_322 ) ;
V_284 -> V_323 =
F_45 ( V_286 -> V_324 ) ;
V_284 -> V_325 = F_45 ( V_286 -> V_326 ) ;
V_284 -> V_327 = F_45 ( V_286 -> V_328 ) ;
V_284 -> V_329 = F_45 ( V_286 -> V_330 ) ;
V_292:
F_46 ( & V_10 -> V_289 -> V_221 , V_287 , V_286 ,
V_288 ) ;
V_290:
return;
}
static enum V_331 F_47 ( struct V_332 * V_333 )
{
struct V_223 * V_334 ;
struct V_225 * V_226 ;
unsigned long V_214 ;
enum V_331 V_195 = V_335 ;
V_334 = F_48 ( F_49 ( V_333 -> V_220 ) ) ;
V_226 = V_334 -> V_229 ;
F_50 ( & V_334 -> V_336 , V_214 ) ;
if ( V_334 -> V_337 == V_338 )
V_195 = V_339 ;
F_51 ( & V_334 -> V_336 , V_214 ) ;
return V_195 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_340 * V_341 = V_2 -> V_342 ;
T_1 V_343 = V_344 ;
F_53 ( V_10 ) ;
switch ( V_10 -> V_345 & 0x0F00 ) {
case V_346 :
V_343 = V_347 ;
break;
case V_348 :
V_343 = V_349 ;
break;
case V_350 :
V_343 = V_351 ;
break;
case V_352 :
V_343 = V_353 ;
break;
}
V_341 -> V_354 = V_343 ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_340 * V_341 = V_2 -> V_342 ;
T_1 V_337 = V_355 ;
if ( F_34 ( V_356 , & V_10 -> V_214 ) )
V_337 = V_357 ;
V_341 -> V_358 = V_337 ;
}
static int F_55 ( struct V_1 * V_2 ,
enum V_359 V_47 , char * V_188 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_247 ;
switch ( V_47 ) {
case V_49 :
V_247 = F_56 ( V_188 , V_10 -> V_360 , V_361 ) ;
break;
case V_50 :
V_247 = sprintf ( V_188 , L_16 , & V_10 -> V_27 . V_28 ) ;
break;
case V_51 :
V_247 = sprintf ( V_188 , L_17 , V_10 -> V_362 ) ;
break;
case V_52 :
F_54 ( V_2 ) ;
V_247 = sprintf ( V_188 , L_17 , F_57 ( V_2 ) ) ;
break;
case V_53 :
F_52 ( V_2 ) ;
V_247 = sprintf ( V_188 , L_17 , F_58 ( V_2 ) ) ;
break;
default:
return - V_39 ;
}
return V_247 ;
}
static void F_59 ( struct V_9 * V_10 )
{
if ( V_10 -> V_363 )
return;
V_10 -> V_363 = F_60 ( V_10 -> V_275 ,
& V_364 ,
V_19 , 0 , 0 ) ;
if ( ! V_10 -> V_363 )
F_4 ( V_242 , V_10 , L_32
L_33 ) ;
}
static void F_61 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_365 )
V_10 -> V_365 = F_60 ( V_10 -> V_275 ,
& V_364 ,
V_30 , 0 ,
0 ) ;
if ( ! V_10 -> V_365 )
F_4 ( V_242 , V_10 , L_34
L_33 ) ;
if ( ! V_10 -> V_366 )
V_10 -> V_366 = F_60 ( V_10 -> V_275 ,
& V_364 ,
V_30 , 1 ,
0 ) ;
if ( ! V_10 -> V_366 )
F_4 ( V_242 , V_10 , L_34
L_35 ) ;
}
static void F_62 ( struct V_9 * V_10 )
{
if ( V_10 -> V_27 . V_250 & V_251 )
F_59 ( V_10 ) ;
if ( V_10 -> V_27 . V_252 & V_253 )
F_61 ( V_10 ) ;
}
static void F_63 ( struct V_9 * V_10 )
{
if ( V_10 -> V_363 ) {
F_64 ( V_10 -> V_363 ) ;
V_10 -> V_363 = NULL ;
}
}
static void F_65 ( struct V_9 * V_10 )
{
if ( V_10 -> V_365 ) {
F_64 ( V_10 -> V_365 ) ;
V_10 -> V_365 = NULL ;
}
if ( V_10 -> V_366 ) {
F_64 ( V_10 -> V_366 ) ;
V_10 -> V_366 = NULL ;
}
}
static void F_66 ( struct V_9 * V_10 )
{
F_63 ( V_10 ) ;
F_65 ( V_10 ) ;
}
static void F_67 ( struct V_9 * V_10 ,
struct V_367 * V_368 ,
struct V_369 * V_370 )
{
switch ( V_368 -> V_47 ) {
case V_120 :
if ( V_368 -> V_3 & 0x1 )
memcpy ( V_370 -> V_45 , V_368 -> V_371 ,
sizeof( V_370 -> V_45 ) ) ;
else
memcpy ( V_370 -> V_43 , V_368 -> V_371 ,
sizeof( V_370 -> V_43 ) ) ;
break;
case V_119 :
if ( V_368 -> V_3 & 0x1 )
break;
memcpy ( V_370 -> V_372 , & V_368 -> V_371 [ 8 ] ,
sizeof( V_370 -> V_372 ) ) ;
break;
case V_121 :
if ( V_368 -> V_3 & 0x1 )
break;
memcpy ( V_370 -> V_373 , V_368 -> V_371 ,
sizeof( V_370 -> V_373 ) ) ;
break;
case V_122 :
if ( V_368 -> V_3 & 0x1 )
break;
if ( V_368 -> V_371 [ 0 ] == V_374 )
V_370 -> V_375 &=
F_68 (
~ V_258 ) ;
else if ( V_368 -> V_371 [ 0 ] == V_376 )
V_370 -> V_375 |=
F_68 (
V_258 ) ;
else
F_4 ( V_242 , V_10 , L_36
L_37 ) ;
break;
case V_123 :
if ( V_368 -> V_3 & 0x1 )
break;
if ( V_368 -> V_371 [ 0 ] ==
V_377 )
V_370 -> V_375 |= F_68 (
V_259 ) ;
else if ( V_368 -> V_371 [ 0 ] ==
V_378 )
V_370 -> V_375 &= F_68 (
~ V_259 ) ;
else
F_4 ( V_242 , V_10 , L_36
L_38 ) ;
break;
case V_379 :
if ( V_368 -> V_3 & 0x1 )
break;
if ( V_368 -> V_371 [ 0 ] == V_380 )
memset ( V_370 -> V_373 , 0 ,
sizeof( V_370 -> V_373 ) ) ;
break;
case V_118 :
if ( V_368 -> V_371 [ 0 ] == V_381 ) {
V_370 -> V_382 |=
F_68 ( V_253 ) ;
F_61 ( V_10 ) ;
} else {
V_370 -> V_382 &=
F_68 ( ~ V_253 &
0xFFFF ) ;
F_65 ( V_10 ) ;
}
break;
case V_383 :
if ( V_368 -> V_247 != sizeof( V_370 -> V_262 ) )
break;
V_370 -> V_262 =
F_69 ( * ( T_4 * ) V_368 -> V_371 ) ;
break;
case V_126 :
if ( V_368 -> V_371 [ 0 ] == V_384 )
V_370 -> V_382 |=
F_68 ( V_265 ) ;
else
V_370 -> V_382 &=
F_68 ( ~ V_265 ) ;
break;
case V_127 :
V_370 -> V_266 =
F_68 ( * ( T_4 * ) V_368 -> V_371 ) ;
break;
case V_128 :
if ( V_368 -> V_3 & 0x1 )
break;
V_370 -> V_268 =
F_68 ( * ( T_4 * ) V_368 -> V_371 ) ;
break;
default:
F_4 ( V_242 , V_10 , L_39 ,
V_368 -> V_47 ) ;
break;
}
}
static void F_70 ( struct V_9 * V_10 ,
struct V_367 * V_368 ,
struct V_369 * V_370 )
{
switch ( V_368 -> V_47 ) {
case V_114 :
memcpy ( V_370 -> V_385 , V_368 -> V_371 ,
sizeof( V_370 -> V_385 ) ) ;
break;
case V_115 :
memcpy ( V_370 -> V_386 , V_368 -> V_371 ,
sizeof( V_370 -> V_386 ) ) ;
break;
case V_116 :
memcpy ( V_370 -> V_387 , V_368 -> V_371 ,
sizeof( V_370 -> V_387 ) ) ;
break;
case V_117 :
if ( V_368 -> V_371 [ 0 ] == V_388 )
V_370 -> V_389 |=
F_68 ( V_255 ) ;
else if ( V_368 -> V_371 [ 0 ] == V_390 )
V_370 -> V_389 &=
F_68 ( ~ V_255 ) ;
else
F_4 ( V_242 , V_10 , L_40 ) ;
break;
case V_118 :
if ( V_368 -> V_371 [ 0 ] == V_381 ) {
V_370 -> V_391 |=
F_68 ( V_251 ) ;
F_59 ( V_10 ) ;
} else {
V_370 -> V_391 &=
F_68 ( ~ V_251 &
0xFFFF ) ;
F_63 ( V_10 ) ;
}
break;
case V_383 :
if ( V_368 -> V_247 != sizeof( V_370 -> V_260 ) )
break;
V_370 -> V_260 =
F_69 ( * ( T_4 * ) V_368 -> V_371 ) ;
break;
case V_126 :
if ( V_368 -> V_371 [ 0 ] == V_384 )
V_370 -> V_391 |=
F_68 ( V_264 ) ;
else
V_370 -> V_391 &=
F_68 ( ~ V_264 ) ;
break;
case V_127 :
V_370 -> V_266 =
F_68 ( * ( T_4 * ) V_368 -> V_371 ) ;
break;
case V_128 :
V_370 -> V_267 =
F_68 ( * ( T_4 * ) V_368 -> V_371 ) ;
break;
default:
F_4 ( V_242 , V_10 , L_41 ,
V_368 -> V_47 ) ;
break;
}
}
static void
F_71 ( struct V_369 * V_370 )
{
struct V_392 * V_393 ;
V_393 = (struct V_392 * ) V_370 ;
memset ( V_393 -> V_394 , 0 , sizeof( V_393 -> V_394 ) ) ;
memset ( V_393 -> V_395 , 0 , sizeof( V_393 -> V_395 ) ) ;
memset ( V_393 -> V_396 , 0 , sizeof( V_393 -> V_396 ) ) ;
memset ( V_393 -> V_397 , 0 , sizeof( V_393 -> V_397 ) ) ;
memset ( V_393 -> V_398 , 0 , sizeof( V_393 -> V_398 ) ) ;
memset ( V_393 -> V_399 , 0 , sizeof( V_393 -> V_399 ) ) ;
memset ( V_393 -> V_400 , 0 , sizeof( V_393 -> V_400 ) ) ;
memset ( V_393 -> V_401 , 0 , sizeof( V_393 -> V_401 ) ) ;
memset ( V_393 -> V_402 , 0 , sizeof( V_393 -> V_402 ) ) ;
memset ( V_393 -> V_403 , 0 , sizeof( V_393 -> V_403 ) ) ;
memset ( V_393 -> V_404 , 0 , sizeof( V_393 -> V_404 ) ) ;
memset ( V_393 -> V_405 , 0 , sizeof( V_393 -> V_405 ) ) ;
memset ( V_393 -> V_406 , 0 , sizeof( V_393 -> V_406 ) ) ;
memset ( V_393 -> V_407 , 0 , sizeof( V_393 -> V_407 ) ) ;
memset ( V_393 -> V_408 , 0 , sizeof( V_393 -> V_408 ) ) ;
}
static int
F_72 ( struct V_1 * V_2 , void * V_222 , T_1 V_247 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_18 = 0 ;
struct V_367 * V_368 = NULL ;
struct V_369 * V_370 = NULL ;
T_5 V_409 ;
T_1 V_410 [ V_411 ] ;
T_1 V_412 [ V_411 ] ;
T_1 V_413 = V_247 ;
struct V_414 * V_415 ;
V_370 = F_42 ( & V_10 -> V_289 -> V_221 ,
sizeof( struct V_369 ) ,
& V_409 , V_235 ) ;
if ( ! V_370 ) {
F_4 ( V_242 , V_10 , L_42 ,
V_26 ) ;
return - V_200 ;
}
memset ( V_370 , 0 , sizeof( struct V_369 ) ) ;
memset ( & V_410 , 0 , sizeof( V_410 ) ) ;
memset ( & V_412 , 0 , sizeof( V_412 ) ) ;
if ( F_73 ( V_10 , & V_410 [ 0 ] , & V_412 [ 0 ] , V_409 ) ) {
F_4 ( V_242 , V_10 , L_43 , V_26 ) ;
V_18 = - V_416 ;
goto V_417;
}
F_74 (attr, data, len, rem) {
V_368 = F_75 ( V_415 ) ;
if ( V_368 -> V_46 != V_113 )
continue;
switch ( V_368 -> V_4 ) {
case V_19 :
switch ( V_368 -> V_3 ) {
case 0 :
F_70 ( V_10 , V_368 , V_370 ) ;
break;
default:
F_4 ( V_242 , V_10 , L_44
L_45 ,
V_368 -> V_3 ) ;
break;
}
break;
case V_30 :
switch ( V_368 -> V_3 ) {
case 0 :
case 1 :
F_67 ( V_10 , V_368 , V_370 ) ;
break;
default:
F_4 ( V_242 , V_10 , L_46
L_45 ,
V_368 -> V_3 ) ;
break;
}
break;
default:
F_4 ( V_242 , V_10 , L_47 ) ;
break;
}
}
V_370 -> V_204 = F_76 ( 0x11BEAD5A ) ;
V_18 = F_23 ( V_10 , V_409 , V_418 ,
sizeof( struct V_369 ) ,
V_243 ) ;
if ( V_18 != V_41 ) {
F_4 ( V_242 , V_10 , L_48 ,
V_26 ) ;
V_18 = - V_416 ;
goto V_417;
}
V_18 = F_77 ( V_10 ) ;
if ( V_18 != V_41 ) {
F_4 ( V_242 , V_10 , L_49 ,
V_26 ) ;
V_18 = - V_416 ;
goto V_417;
}
F_78 ( & V_10 -> V_419 ,
V_420 * V_421 ) ;
F_71 ( V_370 ) ;
V_18 = F_79 ( V_10 , & V_410 [ 0 ] , & V_412 [ 0 ] , V_409 ) ;
if ( V_18 != V_41 ) {
F_4 ( V_242 , V_10 , L_50 ,
V_26 ) ;
V_18 = - V_416 ;
goto V_417;
}
memset ( V_370 , 0 , sizeof( struct V_369 ) ) ;
F_80 ( V_10 , & V_410 [ 0 ] , & V_412 [ 0 ] , V_370 ,
V_409 ) ;
V_417:
F_46 ( & V_10 -> V_289 -> V_221 , sizeof( struct V_369 ) ,
V_370 , V_409 ) ;
return V_18 ;
}
static int F_81 ( struct V_223 * V_285 ,
enum V_278 V_47 , char * V_188 )
{
struct V_225 * V_226 = V_285 -> V_229 ;
struct V_227 * V_227 = V_226 -> V_229 ;
struct V_9 * V_10 = V_227 -> V_10 ;
int V_18 , V_247 ;
T_4 V_422 ;
switch ( V_47 ) {
case V_70 :
V_18 = F_82 ( V_10 , V_226 -> V_423 ,
V_226 -> V_424 , V_425 ,
& V_422 ) ;
if ( V_18 )
V_247 = sprintf ( V_188 , L_51 ) ;
else
V_247 = sprintf ( V_188 , L_52 , V_422 ) ;
break;
case V_69 :
V_18 = F_82 ( V_10 , V_226 -> V_206 ,
V_226 -> V_209 , V_426 ,
& V_422 ) ;
if ( V_18 )
V_247 = sprintf ( V_188 , L_51 ) ;
else
V_247 = sprintf ( V_188 , L_52 , V_422 ) ;
break;
default:
return F_83 ( V_285 , V_47 , V_188 ) ;
}
return V_247 ;
}
static int F_84 ( struct V_281 * V_282 ,
enum V_278 V_47 , char * V_188 )
{
struct V_427 * V_428 ;
struct V_429 * V_429 ;
struct V_7 * V_8 ;
int V_247 = 0 ;
V_428 = V_282 -> V_229 ;
V_429 = V_428 -> V_229 ;
V_8 = (struct V_7 * ) & V_429 -> V_273 -> V_8 ;
switch ( V_47 ) {
case V_59 :
case V_58 :
return F_38 ( (struct V_280 * )
V_8 , V_47 , V_188 ) ;
default:
return F_85 ( V_282 , V_47 , V_188 ) ;
}
return V_247 ;
}
int F_86 ( struct V_9 * V_10 , T_4 * V_430 )
{
T_1 V_431 = 0 ;
T_4 V_432 ;
int V_195 ;
V_433:
V_432 = F_87 ( V_10 -> V_434 , V_435 ) ;
if ( V_432 >= V_435 ) {
F_3 ( F_4 ( V_25 , V_10 ,
L_53 ) ) ;
V_195 = V_436 ;
goto V_437;
}
if ( F_88 ( V_432 , V_10 -> V_434 ) )
goto V_433;
F_3 ( F_4 ( V_25 , V_10 ,
L_54 , V_432 ) ) ;
V_195 = F_89 ( V_10 , V_432 , & V_431 ) ;
if ( V_195 == V_436 ) {
if ( V_431 == V_438 ) {
F_4 ( V_25 , V_10 ,
L_55 ,
V_432 ) ;
goto V_433;
}
F_3 ( F_4 ( V_25 , V_10 ,
L_56 ) ) ;
}
* V_430 = V_432 ;
V_437:
return V_195 ;
}
static int F_90 ( struct V_9 * V_10 ,
struct V_227 * V_227 ,
char * V_439 ,
char * V_440 )
{
T_2 V_441 [ V_17 ] ;
char V_442 [ V_443 ] ;
int V_444 = V_41 , V_195 = 0 ;
if ( V_227 -> V_445 . V_15 & V_446 ) {
V_195 = F_91 ( V_440 , strlen ( V_440 ) , V_441 ,
'\0' , NULL ) ;
if ( V_195 == 0 ) {
V_444 = V_436 ;
goto V_447;
}
V_195 = sprintf ( V_442 , L_57 , V_441 ) ;
} else {
V_195 = F_92 ( V_440 , strlen ( V_440 ) , V_441 ,
'\0' , NULL ) ;
if ( V_195 == 0 ) {
V_444 = V_436 ;
goto V_447;
}
V_195 = sprintf ( V_442 , L_58 , V_441 ) ;
}
if ( strcmp ( V_439 , V_442 ) )
V_444 = V_436 ;
V_447:
return V_444 ;
}
static int F_93 ( struct V_9 * V_10 ,
struct V_281 * V_282 )
{
int V_422 = 0 , V_448 , V_18 ;
struct V_223 * V_285 = F_40 ( V_282 ) ;
struct V_225 * V_226 , * V_449 ;
struct V_427 * V_428 , * V_450 ;
struct V_227 * V_227 ;
V_226 = V_285 -> V_229 ;
V_428 = V_282 -> V_229 ;
if ( V_226 -> V_451 == NULL ||
V_428 -> V_452 == NULL ||
V_428 -> V_453 == 0 )
return V_436 ;
V_448 = F_20 ( V_10 ) ? V_454 :
V_455 ;
for ( V_422 = 0 ; V_422 < V_448 ; V_422 ++ ) {
V_227 = F_94 ( V_10 , V_422 ) ;
if ( V_227 == NULL )
continue;
if ( V_227 -> V_456 != V_457 )
continue;
V_449 = V_227 -> V_226 -> V_229 ;
V_450 = V_227 -> V_428 -> V_229 ;
if ( V_449 -> V_451 == NULL ||
V_450 -> V_452 == NULL ||
V_450 -> V_453 == 0 )
continue;
F_3 ( F_4 ( V_25 , V_10 ,
L_59 ,
V_449 -> V_451 ,
V_226 -> V_451 ) ) ;
F_3 ( F_4 ( V_25 , V_10 ,
L_60 ,
V_450 -> V_452 ,
V_428 -> V_452 ) ) ;
F_3 ( F_4 ( V_25 , V_10 ,
L_61 ,
V_450 -> V_453 ,
V_428 -> V_453 ) ) ;
if ( strcmp ( V_449 -> V_451 , V_226 -> V_451 ) )
continue;
V_18 = F_90 ( V_10 , V_227 ,
V_450 -> V_452 ,
V_428 -> V_452 ) ;
if ( V_18 == V_436 )
continue;
if ( V_450 -> V_453 != V_428 -> V_453 )
continue;
break;
}
if ( V_422 == V_448 )
return V_436 ;
F_3 ( F_4 ( V_25 , V_10 ,
L_62 ) ) ;
return V_41 ;
}
static struct V_223 *
F_95 ( struct V_269 * V_271 ,
T_4 V_458 , T_4 V_459 ,
T_1 V_460 )
{
struct V_223 * V_285 ;
struct V_9 * V_10 ;
struct V_272 * V_273 ;
struct V_227 * V_227 ;
T_4 V_430 ;
struct V_225 * V_226 ;
struct V_7 * V_8 ;
int V_195 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
if ( ! V_271 ) {
F_28 ( V_242 L_63 ) ;
return NULL ;
}
V_273 = V_271 -> V_229 ;
V_8 = (struct V_7 * ) & V_273 -> V_8 ;
V_10 = F_2 ( V_273 -> V_275 ) ;
V_195 = F_86 ( V_10 , & V_430 ) ;
if ( V_195 == V_436 )
return NULL ;
V_285 = F_96 ( & V_364 , V_273 -> V_275 ,
V_458 , sizeof( struct V_227 ) ,
sizeof( struct V_461 ) ,
V_460 , V_430 ) ;
if ( ! V_285 )
return NULL ;
V_226 = V_285 -> V_229 ;
V_227 = V_226 -> V_229 ;
V_227 -> V_291 = V_430 ;
V_227 -> V_462 = V_463 ;
V_227 -> V_10 = V_10 ;
V_227 -> V_226 = V_285 ;
V_227 -> V_464 = V_465 ;
V_227 -> V_466 = V_467 ;
V_285 -> V_468 = V_469 ;
V_10 -> V_470 [ V_227 -> V_291 ] = V_227 ;
V_10 -> V_471 ++ ;
return V_285 ;
}
static void F_97 ( struct V_223 * V_285 )
{
struct V_225 * V_226 ;
struct V_227 * V_227 ;
struct V_9 * V_10 ;
unsigned long V_214 , V_472 ;
struct V_473 * V_445 = NULL ;
T_5 V_474 ;
T_1 V_475 ;
int V_195 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
V_226 = V_285 -> V_229 ;
V_227 = V_226 -> V_229 ;
V_10 = V_227 -> V_10 ;
V_445 = F_42 ( & V_10 -> V_289 -> V_221 , sizeof( * V_445 ) ,
& V_474 , V_235 ) ;
if ( ! V_445 ) {
F_4 ( V_242 , V_10 ,
L_64 , V_26 ) ;
goto V_476;
}
V_472 = V_477 + ( V_421 * V_478 ) ;
do {
V_195 = F_98 ( V_10 , V_227 -> V_291 ,
V_445 , V_474 ,
NULL , NULL , & V_475 , NULL ,
NULL , NULL ) ;
if ( V_195 == V_436 )
goto V_476;
if ( ( V_475 == V_463 ) ||
( V_475 == V_479 ) )
goto V_476;
F_99 ( V_421 ) ;
} while ( ( F_100 ( V_472 , V_477 ) ) );
V_476:
F_101 ( V_10 , V_227 -> V_291 ) ;
F_50 ( & V_10 -> V_480 , V_214 ) ;
F_102 ( V_10 , V_227 ) ;
F_51 ( & V_10 -> V_480 , V_214 ) ;
F_103 ( V_285 ) ;
if ( V_445 )
F_46 ( & V_10 -> V_289 -> V_221 , sizeof( * V_445 ) ,
V_445 , V_474 ) ;
}
static struct V_281 *
F_104 ( struct V_223 * V_285 , T_1 V_481 )
{
struct V_281 * V_282 ;
struct V_225 * V_226 ;
struct V_227 * V_227 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
V_282 = F_105 ( V_285 , sizeof( struct V_429 ) ,
V_481 ) ;
if ( ! V_282 )
return NULL ;
V_226 = V_285 -> V_229 ;
V_227 = V_226 -> V_229 ;
V_227 -> V_428 = V_282 ;
return V_282 ;
}
static int F_106 ( struct V_223 * V_224 ,
struct V_281 * V_282 ,
T_6 V_482 , int V_483 )
{
struct V_427 * V_428 ;
struct V_429 * V_429 ;
struct V_269 * V_271 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
if ( F_107 ( V_224 , V_282 , V_483 ) )
return - V_29 ;
V_271 = F_108 ( V_482 ) ;
V_428 = V_282 -> V_229 ;
V_429 = V_428 -> V_229 ;
V_429 -> V_273 = V_271 -> V_229 ;
return 0 ;
}
static int F_109 ( struct V_281 * V_282 )
{
struct V_223 * V_285 = F_40 ( V_282 ) ;
struct V_225 * V_226 ;
struct V_227 * V_227 ;
struct V_9 * V_10 ;
struct V_473 * V_445 = NULL ;
T_5 V_474 ;
T_1 V_431 = 0 ;
int V_195 = 0 ;
int V_444 = V_41 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
V_226 = V_285 -> V_229 ;
V_227 = V_226 -> V_229 ;
V_10 = V_227 -> V_10 ;
V_195 = F_93 ( V_10 , V_282 ) ;
if ( V_195 == V_41 ) {
F_4 ( V_25 , V_10 ,
L_65 ) ;
V_195 = - V_484 ;
goto V_485;
}
V_445 = F_42 ( & V_10 -> V_289 -> V_221 , sizeof( * V_445 ) ,
& V_474 , V_235 ) ;
if ( ! V_445 ) {
F_4 ( V_242 , V_10 ,
L_64 , V_26 ) ;
V_195 = - V_200 ;
goto V_485;
}
V_195 = F_110 ( V_10 , V_227 , V_282 , & V_431 ) ;
if ( V_195 ) {
if ( V_431 )
if ( V_227 -> V_462 ==
V_486 ) {
V_227 -> V_464 ( V_227 -> V_226 ) ;
goto V_487;
}
F_4 ( V_242 , V_10 , L_66 ,
V_26 , V_227 -> V_291 ) ;
goto V_485;
}
V_444 = F_111 ( V_10 , V_227 -> V_291 ) ;
if ( V_444 == V_436 ) {
F_4 ( V_242 , V_10 , L_67 , V_26 ,
V_226 -> V_451 ) ;
V_195 = - V_29 ;
goto V_485;
}
if ( V_227 -> V_462 == V_463 )
V_227 -> V_462 = V_488 ;
F_3 ( F_28 ( V_25 L_68 , V_26 ,
V_227 -> V_462 ) ) ;
V_487:
V_195 = 0 ;
V_485:
if ( V_445 )
F_46 ( & V_10 -> V_289 -> V_221 , sizeof( * V_445 ) ,
V_445 , V_474 ) ;
return V_195 ;
}
static void F_112 ( struct V_281 * V_282 )
{
struct V_223 * V_285 = F_40 ( V_282 ) ;
struct V_225 * V_226 ;
struct V_9 * V_10 ;
struct V_227 * V_227 ;
int V_15 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
V_226 = V_285 -> V_229 ;
V_227 = V_226 -> V_229 ;
V_10 = V_227 -> V_10 ;
V_15 = V_489 ;
if ( F_113 ( V_10 , V_227 , V_15 ) == V_436 )
F_4 ( V_242 , V_10 , L_69 , V_26 ) ;
}
static void F_114 ( struct V_490 * V_491 )
{
struct V_461 * V_492 ;
struct V_9 * V_10 ;
struct V_493 * V_494 ;
struct V_495 * V_496 ;
struct V_497 * V_498 ;
T_2 * V_222 ;
T_1 V_499 ;
struct V_427 * V_428 ;
int V_500 ;
T_7 V_501 ;
V_492 = F_115 ( V_491 , struct V_461 , V_502 ) ;
V_10 = V_492 -> V_10 ;
V_496 = V_492 -> V_496 ;
V_494 = & V_492 -> V_494 ;
V_500 = sizeof( struct V_497 ) ;
F_116 ( F_28 ( V_25 L_70 ) ) ;
F_116 ( F_117 ( V_494 , 64 ) ) ;
F_116 ( F_28 ( V_25 L_71 ) ) ;
F_116 ( F_117 ( V_492 -> V_503 , 64 ) ) ;
V_428 = V_496 -> V_428 ;
switch ( V_494 -> V_504 ) {
case V_505 :
V_498 = (struct V_497 * ) V_492 -> V_503 ;
V_501 = V_494 -> V_506 ;
V_498 -> V_501 = V_501 ;
V_222 = V_492 -> V_503 + V_500 ;
V_499 = V_492 -> V_507 - V_500 ;
F_118 ( V_428 , V_498 , V_222 , V_499 ) ;
break;
default:
F_4 ( V_242 , V_10 , L_72 ,
V_494 -> V_504 ) ;
break;
}
return;
}
static int F_119 ( struct V_495 * V_496 , T_2 V_508 )
{
struct V_461 * V_492 ;
struct V_225 * V_226 ;
struct V_227 * V_227 ;
struct V_9 * V_10 ;
int V_500 ;
V_226 = V_496 -> V_428 -> V_334 ;
V_227 = V_226 -> V_229 ;
V_10 = V_227 -> V_10 ;
V_492 = V_496 -> V_229 ;
memset ( V_492 , 0 , sizeof( struct V_461 ) ) ;
if ( V_496 -> V_333 ) {
F_4 ( V_25 , V_10 ,
L_73 , V_26 ) ;
return - V_29 ;
}
V_500 = sizeof( struct V_497 ) ;
V_492 -> V_10 = V_10 ;
V_492 -> V_496 = V_496 ;
if ( V_496 -> V_509 ) {
V_492 -> V_510 = F_120 ( & V_10 -> V_289 -> V_221 , V_496 -> V_222 ,
V_496 -> V_509 ,
V_511 ) ;
}
F_3 ( F_4 ( V_25 , V_10 , L_74 ,
V_26 , V_496 -> V_428 -> V_512 , V_500 ) ) ;
V_492 -> V_507 = V_496 -> V_428 -> V_512 + V_500 ;
V_492 -> V_503 = F_42 ( & V_10 -> V_289 -> V_221 ,
V_492 -> V_507 ,
& V_492 -> V_513 ,
V_514 ) ;
if ( ! V_492 -> V_503 )
goto V_515;
V_492 -> V_516 = V_496 -> V_509 + V_500 ;
V_492 -> V_517 = F_42 ( & V_10 -> V_289 -> V_221 ,
V_492 -> V_516 ,
& V_492 -> V_518 ,
V_514 ) ;
if ( ! V_492 -> V_517 )
goto V_515;
V_496 -> V_498 = V_492 -> V_517 ;
F_121 ( & V_492 -> V_502 , F_114 ) ;
return 0 ;
V_515:
if ( V_492 -> V_503 )
F_46 ( & V_10 -> V_289 -> V_221 , V_492 -> V_507 ,
V_492 -> V_503 , V_492 -> V_513 ) ;
if ( V_492 -> V_517 )
F_46 ( & V_10 -> V_289 -> V_221 , V_492 -> V_516 ,
V_492 -> V_517 , V_492 -> V_518 ) ;
return - V_200 ;
}
static void F_122 ( struct V_495 * V_496 )
{
struct V_461 * V_492 ;
struct V_225 * V_226 ;
struct V_227 * V_227 ;
struct V_9 * V_10 ;
int V_500 ;
V_500 = sizeof( struct V_497 ) ;
V_226 = V_496 -> V_428 -> V_334 ;
V_227 = V_226 -> V_229 ;
V_10 = V_227 -> V_10 ;
V_492 = V_496 -> V_229 ;
if ( V_496 -> V_509 ) {
F_123 ( & V_10 -> V_289 -> V_221 , V_492 -> V_510 ,
V_496 -> V_509 , V_511 ) ;
}
F_3 ( F_4 ( V_25 , V_10 , L_74 ,
V_26 , V_496 -> V_428 -> V_512 , V_500 ) ) ;
F_46 ( & V_10 -> V_289 -> V_221 , V_492 -> V_507 ,
V_492 -> V_503 , V_492 -> V_513 ) ;
F_46 ( & V_10 -> V_289 -> V_221 , V_492 -> V_516 ,
V_492 -> V_517 , V_492 -> V_518 ) ;
return;
}
static int F_124 ( struct V_495 * V_496 )
{
struct V_332 * V_333 = V_496 -> V_333 ;
struct V_225 * V_226 = V_496 -> V_428 -> V_334 ;
struct V_227 * V_227 = V_226 -> V_229 ;
struct V_9 * V_10 = V_227 -> V_10 ;
if ( ! V_333 )
return F_125 ( V_496 ) ;
F_4 ( V_25 , V_10 , L_75 ,
V_26 ) ;
return - V_39 ;
}
static int F_126 ( struct V_519 * V_226 ,
struct V_520 * V_428 ,
struct V_473 * V_445 )
{
unsigned long V_15 = 0 ;
int V_521 = 0 ;
V_15 = F_127 ( V_445 -> V_15 ) ;
V_428 -> V_522 = F_34 ( V_523 , & V_15 ) ;
if ( F_34 ( V_524 , & V_15 ) ) {
V_521 = F_128 ( & V_226 -> V_525 ,
V_526 ) ;
if ( V_521 )
goto V_527;
} else {
V_521 = F_128 ( & V_226 -> V_525 ,
V_528 ) ;
if ( V_521 )
goto V_527;
}
V_226 -> V_529 = F_34 ( V_530 ,
& V_15 ) ;
V_226 -> V_531 = F_34 ( V_532 , & V_15 ) ;
V_226 -> V_533 = F_34 ( V_534 , & V_15 ) ;
V_15 = F_127 ( V_445 -> V_535 ) ;
V_428 -> V_536 = F_34 ( V_537 , & V_15 ) ;
V_428 -> V_538 = F_34 ( V_539 , & V_15 ) ;
V_226 -> V_540 = F_34 ( V_541 , & V_15 ) ;
V_226 -> V_542 = F_34 ( V_543 , & V_15 ) ;
V_226 -> V_544 = F_34 ( V_545 ,
& V_15 ) ;
V_226 -> V_546 = F_34 ( V_547 , & V_15 ) ;
V_226 -> V_548 = F_34 ( V_549 , & V_15 ) ;
V_428 -> V_550 = F_34 ( V_551 , & V_15 ) ;
V_226 -> V_552 = F_34 ( V_553 ,
& V_15 ) ;
V_226 -> V_554 = F_34 ( V_555 , & V_15 ) ;
V_226 -> V_556 =
F_34 ( V_557 , & V_15 ) ;
if ( F_34 ( V_558 , & V_15 ) )
V_226 -> V_559 |= V_560 ;
if ( F_34 ( V_561 , & V_15 ) )
V_226 -> V_559 |= V_562 ;
V_15 = F_127 ( V_445 -> V_254 ) ;
V_428 -> V_563 = F_34 ( V_564 , & V_15 ) ;
V_428 -> V_565 = F_34 ( V_566 , & V_15 ) ;
V_428 -> V_567 = F_34 ( V_568 , & V_15 ) ;
if ( F_34 ( V_569 , & V_15 ) )
V_428 -> V_570 |= V_571 ;
if ( F_34 ( V_572 , & V_15 ) )
V_428 -> V_570 |= V_573 ;
if ( F_34 ( V_574 , & V_15 ) )
V_428 -> V_570 |= V_560 ;
V_428 -> V_570 >>= 1 ;
V_428 -> V_575 = F_34 ( V_576 , & V_15 ) ;
V_15 = F_127 ( V_445 -> V_577 ) ;
V_428 -> V_578 = F_34 ( V_579 , & V_15 ) ;
V_428 -> V_512 = V_580 *
F_127 ( V_445 -> V_581 ) ;
V_428 -> V_582 = V_580 *
F_127 ( V_445 -> V_583 ) ;
V_226 -> V_584 = V_580 *
F_127 ( V_445 -> V_585 ) ;
V_226 -> V_586 = V_580 *
F_127 ( V_445 -> V_587 ) ;
V_226 -> V_588 = F_127 ( V_445 -> V_589 ) ;
V_226 -> V_590 = F_127 ( V_445 -> V_591 ) ;
V_226 -> V_592 = F_127 ( V_445 -> V_593 ) ;
V_226 -> V_594 = F_45 ( V_445 -> V_595 ) ;
V_428 -> V_596 = F_127 ( V_445 -> V_597 ) ;
V_428 -> V_598 = V_445 -> V_599 ;
V_428 -> V_600 = V_445 -> V_601 ;
V_428 -> V_602 = F_127 ( V_445 -> V_603 ) ;
V_428 -> V_604 = F_127 ( V_445 -> V_605 ) ;
V_428 -> V_606 = F_127 ( V_445 -> V_607 ) ;
V_428 -> V_608 = F_45 ( V_445 -> V_609 ) ;
V_428 -> V_610 = F_45 ( V_445 -> V_611 ) ;
V_226 -> V_612 = F_127 ( V_445 -> V_613 ) ;
V_226 -> V_614 = F_127 ( V_445 -> V_613 ) ;
V_226 -> V_615 = F_127 ( V_445 -> V_186 ) ;
V_226 -> V_616 = F_127 ( V_445 -> V_616 ) ;
V_226 -> V_617 =
F_127 ( V_445 -> V_618 ) ;
V_428 -> V_619 = F_127 ( V_445 -> V_619 ) ;
V_15 = F_127 ( V_445 -> V_15 ) ;
V_428 -> V_620 = F_129 ( V_17 , V_235 ) ;
if ( ! V_428 -> V_620 ) {
V_521 = - V_200 ;
goto V_527;
}
V_428 -> V_621 = F_129 ( V_17 , V_235 ) ;
if ( ! V_428 -> V_621 ) {
V_521 = - V_200 ;
goto V_527;
}
memcpy ( V_428 -> V_620 , V_445 -> V_622 , V_17 ) ;
memcpy ( V_428 -> V_621 , V_445 -> V_623 , V_17 ) ;
if ( F_34 ( V_524 , & V_15 ) ) {
V_428 -> V_624 = V_445 -> V_625 ;
V_428 -> V_626 = F_129 ( V_17 , V_235 ) ;
if ( ! V_428 -> V_626 ) {
V_521 = - V_200 ;
goto V_527;
}
memcpy ( V_428 -> V_626 ,
V_445 -> V_626 , V_17 ) ;
} else {
V_428 -> V_625 = V_445 -> V_625 ;
}
if ( V_445 -> V_627 [ 0 ] ) {
V_521 = F_128 ( & V_226 -> V_451 ,
( char * ) V_445 -> V_627 ) ;
if ( V_521 )
goto V_527;
}
if ( V_445 -> V_628 [ 0 ] ) {
V_521 = F_128 ( & V_226 -> V_629 ,
( char * ) V_445 -> V_628 ) ;
if ( V_521 )
goto V_527;
}
F_130 ( V_226 -> V_630 , V_445 -> V_630 ) ;
V_527:
return V_521 ;
}
static int F_131 ( struct V_519 * V_226 ,
struct V_520 * V_428 ,
struct V_473 * V_445 )
{
T_4 V_15 ;
int V_521 = 0 ;
V_15 = F_127 ( V_445 -> V_15 ) ;
F_132 ( V_428 -> V_522 , V_15 , V_631 ) ;
if ( ! strncmp ( V_226 -> V_525 , V_526 , 4 ) )
V_15 |= V_632 ;
else
V_15 &= ~ V_632 ;
F_132 ( V_226 -> V_529 , V_15 , V_218 ) ;
F_132 ( V_226 -> V_531 , V_15 , V_633 ) ;
F_132 ( V_226 -> V_533 , V_15 , V_571 ) ;
V_445 -> V_15 = F_68 ( V_15 ) ;
V_15 = F_127 ( V_445 -> V_535 ) ;
F_132 ( V_428 -> V_536 , V_15 , V_634 ) ;
F_132 ( V_428 -> V_538 , V_15 , V_635 ) ;
F_132 ( V_226 -> V_540 , V_15 , V_631 ) ;
F_132 ( V_226 -> V_542 , V_15 , V_636 ) ;
F_132 ( V_226 -> V_544 , V_15 , V_637 ) ;
F_132 ( V_226 -> V_546 , V_15 , V_632 ) ;
F_132 ( V_226 -> V_548 , V_15 , V_215 ) ;
F_132 ( V_428 -> V_550 , V_15 , V_218 ) ;
F_132 ( V_226 -> V_552 , V_15 , V_638 ) ;
F_132 ( V_226 -> V_554 , V_15 , V_633 ) ;
F_132 ( V_226 -> V_556 , V_15 , V_571 ) ;
F_132 ( V_226 -> V_559 & V_560 , V_15 , V_560 ) ;
F_132 ( V_226 -> V_559 & V_562 , V_15 , V_562 ) ;
V_445 -> V_535 = F_68 ( V_15 ) ;
V_15 = F_127 ( V_445 -> V_254 ) ;
F_132 ( V_428 -> V_563 , V_15 , V_218 ) ;
F_132 ( V_428 -> V_565 , V_15 , V_638 ) ;
F_132 ( V_428 -> V_567 , V_15 , V_633 ) ;
F_132 ( V_428 -> V_570 & V_573 , V_15 , V_571 ) ;
F_132 ( V_428 -> V_570 & V_560 , V_15 , V_573 ) ;
F_132 ( V_428 -> V_570 & V_562 , V_15 , V_560 ) ;
F_132 ( V_428 -> V_575 , V_15 , V_562 ) ;
V_445 -> V_254 = F_68 ( V_15 ) ;
V_15 = F_127 ( V_445 -> V_577 ) ;
F_132 ( V_428 -> V_578 , V_15 , V_633 ) ;
V_445 -> V_577 = F_68 ( V_15 ) ;
V_445 -> V_589 = F_68 ( V_226 -> V_588 ) ;
V_445 -> V_581 =
F_68 ( V_428 -> V_512 / V_580 ) ;
V_445 -> V_583 =
F_68 ( V_428 -> V_582 / V_580 ) ;
V_445 -> V_585 =
F_68 ( V_226 -> V_584 / V_580 ) ;
V_445 -> V_587 = F_68 ( V_226 -> V_586 /
V_580 ) ;
V_445 -> V_591 = F_68 ( V_226 -> V_590 ) ;
V_445 -> V_593 = F_68 ( V_226 -> V_592 ) ;
V_445 -> V_595 = F_68 ( V_226 -> V_594 ) ;
V_445 -> V_597 = F_68 ( V_428 -> V_596 ) ;
V_445 -> V_599 = ( T_2 ) F_76 ( V_428 -> V_598 ) ;
V_445 -> V_601 = ( T_2 ) F_76 ( V_428 -> V_600 ) ;
V_445 -> V_603 = F_68 ( V_428 -> V_602 ) ;
V_445 -> V_605 = F_68 ( V_428 -> V_604 ) ;
V_445 -> V_607 = F_68 ( V_428 -> V_606 ) ;
V_445 -> V_609 = F_76 ( V_428 -> V_608 ) ;
V_445 -> V_611 = F_76 ( V_428 -> V_610 ) ;
V_445 -> V_613 = F_68 ( V_226 -> V_612 ) ;
V_445 -> V_186 = F_68 ( V_226 -> V_615 ) ;
V_445 -> V_616 = F_68 ( V_226 -> V_616 ) ;
V_445 -> V_619 = F_68 ( V_428 -> V_619 ) ;
V_445 -> V_618 =
F_68 ( V_226 -> V_617 ) ;
if ( ! strncmp ( V_226 -> V_525 , V_526 , 4 ) )
V_445 -> V_625 = V_428 -> V_624 ;
else
V_445 -> V_625 = V_428 -> V_625 ;
if ( V_428 -> V_620 )
memcpy ( V_445 -> V_622 , V_428 -> V_620 ,
sizeof( V_445 -> V_622 ) ) ;
if ( V_428 -> V_621 )
memcpy ( V_445 -> V_623 , V_428 -> V_621 ,
sizeof( V_445 -> V_623 ) ) ;
if ( V_428 -> V_626 )
memcpy ( V_445 -> V_626 ,
V_428 -> V_626 ,
sizeof( V_445 -> V_626 ) ) ;
if ( V_226 -> V_451 )
memcpy ( V_445 -> V_627 , V_226 -> V_451 ,
sizeof( V_445 -> V_627 ) ) ;
if ( V_226 -> V_629 )
memcpy ( V_445 -> V_628 , V_226 -> V_629 ,
sizeof( V_445 -> V_628 ) ) ;
F_130 ( V_445 -> V_630 , V_226 -> V_630 ) ;
return V_521 ;
}
static void F_133 ( struct V_427 * V_428 ,
struct V_225 * V_226 ,
struct V_473 * V_445 )
{
unsigned long V_15 = 0 ;
T_4 V_613 ;
T_4 V_639 ;
V_15 = F_127 ( V_445 -> V_15 ) ;
V_428 -> V_522 = F_34 ( V_523 , & V_15 ) ;
V_226 -> V_529 = F_34 ( V_530 ,
& V_15 ) ;
V_226 -> V_531 = F_34 ( V_532 , & V_15 ) ;
V_15 = F_127 ( V_445 -> V_535 ) ;
V_428 -> V_536 = F_34 ( V_537 , & V_15 ) ;
V_428 -> V_538 = F_34 ( V_539 , & V_15 ) ;
V_226 -> V_540 = F_34 ( V_541 , & V_15 ) ;
V_226 -> V_542 = F_34 ( V_543 , & V_15 ) ;
V_226 -> V_544 = F_34 ( V_545 ,
& V_15 ) ;
V_226 -> V_546 = F_34 ( V_547 , & V_15 ) ;
V_226 -> V_548 = F_34 ( V_549 , & V_15 ) ;
V_226 -> V_552 = F_34 ( V_553 ,
& V_15 ) ;
V_226 -> V_554 = F_34 ( V_555 , & V_15 ) ;
V_226 -> V_556 =
F_34 ( V_557 , & V_15 ) ;
if ( F_34 ( V_558 , & V_15 ) )
V_226 -> V_559 |= V_560 ;
if ( F_34 ( V_561 , & V_15 ) )
V_226 -> V_559 |= V_562 ;
V_15 = F_127 ( V_445 -> V_254 ) ;
V_428 -> V_563 = F_34 ( V_564 , & V_15 ) ;
V_428 -> V_565 = F_34 ( V_566 , & V_15 ) ;
V_428 -> V_567 = F_34 ( V_568 , & V_15 ) ;
if ( F_34 ( V_569 , & V_15 ) )
V_428 -> V_570 |= V_571 ;
if ( F_34 ( V_572 , & V_15 ) )
V_428 -> V_570 |= V_573 ;
if ( F_34 ( V_574 , & V_15 ) )
V_428 -> V_570 |= V_560 ;
V_428 -> V_570 >>= 1 ;
V_428 -> V_575 = F_34 ( V_576 , & V_15 ) ;
V_15 = F_127 ( V_445 -> V_577 ) ;
V_428 -> V_578 = F_34 ( V_579 , & V_15 ) ;
V_428 -> V_512 = V_580 *
F_127 ( V_445 -> V_581 ) ;
V_428 -> V_582 = V_580 *
F_127 ( V_445 -> V_583 ) ;
V_226 -> V_588 = F_127 ( V_445 -> V_589 ) ;
V_226 -> V_584 = V_580 *
F_127 ( V_445 -> V_585 ) ;
V_226 -> V_586 = V_580 *
F_127 ( V_445 -> V_587 ) ;
V_226 -> V_590 = F_127 ( V_445 -> V_591 ) ;
V_226 -> V_592 = F_127 ( V_445 -> V_593 ) ;
V_226 -> V_594 = F_45 ( V_445 -> V_595 ) ;
V_428 -> V_596 = F_127 ( V_445 -> V_597 ) ;
V_428 -> V_598 = V_445 -> V_599 ;
V_428 -> V_600 = V_445 -> V_601 ;
V_428 -> V_625 = V_445 -> V_625 ;
V_428 -> V_640 = F_127 ( V_445 -> V_605 ) ;
V_428 -> V_606 = F_127 ( V_445 -> V_607 ) ;
V_428 -> V_608 = F_45 ( V_445 -> V_609 ) ;
V_428 -> V_610 = F_45 ( V_445 -> V_611 ) ;
V_226 -> V_616 = F_127 ( V_445 -> V_616 ) ;
F_130 ( V_226 -> V_630 , V_445 -> V_630 ) ;
V_613 = F_127 ( V_445 -> V_613 ) ;
if ( V_613 < V_435 )
V_226 -> V_612 = V_613 ;
else
V_226 -> V_612 = V_641 ;
if ( V_613 == V_642 )
V_639 = V_643 ;
else if ( V_613 == V_641 )
V_639 = V_644 ;
else if ( V_613 < V_435 )
V_639 = V_645 ;
else
V_639 = V_644 ;
F_134 ( V_428 -> V_282 , V_112 ,
F_135 ( V_639 ) , 0 ) ;
F_134 ( V_428 -> V_282 , V_62 ,
( char * ) V_445 -> V_628 , 0 ) ;
}
static void F_136 ( struct V_9 * V_10 ,
struct V_473 * V_445 ,
struct V_223 * V_285 ,
struct V_281 * V_282 )
{
int V_646 = 0 ;
struct V_225 * V_226 ;
struct V_227 * V_227 ;
struct V_427 * V_428 ;
char V_622 [ V_443 ] ;
T_4 V_15 = 0 ;
V_226 = V_285 -> V_229 ;
V_227 = V_226 -> V_229 ;
V_428 = V_282 -> V_229 ;
V_227 -> V_186 = F_127 ( V_445 -> V_186 ) ;
F_133 ( V_428 , V_226 , V_445 ) ;
V_226 -> V_647 = F_127 ( V_445 -> V_618 ) ;
V_428 -> V_453 = F_127 ( V_445 -> V_619 ) ;
memset ( V_622 , 0 , sizeof( V_622 ) ) ;
V_15 = F_127 ( V_445 -> V_15 ) ;
if ( V_15 & V_446 ) {
F_134 ( V_282 , V_77 , L_76 , 4 ) ;
memset ( V_622 , 0 , sizeof( V_622 ) ) ;
sprintf ( V_622 , L_57 , V_445 -> V_622 ) ;
} else {
F_134 ( V_282 , V_77 , L_77 , 4 ) ;
sprintf ( V_622 , L_58 , V_445 -> V_622 ) ;
}
F_134 ( V_282 , V_56 ,
( char * ) V_622 , V_646 ) ;
F_134 ( V_282 , V_60 ,
( char * ) V_445 -> V_627 , V_646 ) ;
F_134 ( V_282 , V_648 ,
( char * ) V_10 -> V_362 , V_646 ) ;
}
void F_137 ( struct V_9 * V_10 ,
struct V_227 * V_227 )
{
struct V_223 * V_285 ;
struct V_281 * V_282 ;
T_1 V_475 ;
T_5 V_474 ;
struct V_473 * V_445 ;
V_445 = F_42 ( & V_10 -> V_289 -> V_221 , sizeof( * V_445 ) ,
& V_474 , V_235 ) ;
if ( ! V_445 ) {
F_4 ( V_242 , V_10 ,
L_64 , V_26 ) ;
goto V_649;
}
if ( F_98 ( V_10 , V_227 -> V_291 , V_445 ,
V_474 , NULL , NULL , & V_475 ,
NULL , NULL , NULL ) == V_436 ) {
F_3 ( F_4 ( V_242 , V_10 , L_78
L_79 ,
V_10 -> V_650 , V_26 ,
V_227 -> V_291 ) ) ;
goto V_649;
}
V_285 = V_227 -> V_226 ;
V_282 = V_227 -> V_428 ;
F_136 ( V_10 , V_445 , V_285 , V_282 ) ;
V_649:
if ( V_445 )
F_46 ( & V_10 -> V_289 -> V_221 , sizeof( * V_445 ) ,
V_445 , V_474 ) ;
}
void F_138 ( struct V_9 * V_10 ,
struct V_227 * V_227 )
{
struct V_223 * V_285 ;
struct V_281 * V_282 ;
struct V_225 * V_226 ;
struct V_427 * V_428 ;
T_1 V_475 ;
T_5 V_474 ;
struct V_473 * V_445 ;
V_445 = F_42 ( & V_10 -> V_289 -> V_221 , sizeof( * V_445 ) ,
& V_474 , V_235 ) ;
if ( ! V_445 ) {
F_4 ( V_242 , V_10 ,
L_64 , V_26 ) ;
goto V_651;
}
if ( F_98 ( V_10 , V_227 -> V_291 , V_445 ,
V_474 , NULL , NULL , & V_475 ,
NULL , NULL , NULL ) == V_436 ) {
F_3 ( F_4 ( V_242 , V_10 , L_78
L_79 ,
V_10 -> V_650 , V_26 ,
V_227 -> V_291 ) ) ;
goto V_651;
}
V_285 = V_227 -> V_226 ;
V_226 = V_285 -> V_229 ;
V_282 = V_227 -> V_428 ;
V_428 = V_282 -> V_229 ;
V_227 -> V_652 =
( F_127 ( V_445 -> V_618 ) > V_653 ) &&
( F_127 ( V_445 -> V_618 ) < V_653 * 10 ) ?
F_127 ( V_445 -> V_618 ) : V_653 ;
V_227 -> V_654 =
F_127 ( V_445 -> V_591 ) ;
V_227 -> V_186 = F_127 ( V_445 -> V_186 ) ;
F_133 ( V_428 , V_226 , V_445 ) ;
memcpy ( V_226 -> V_655 , V_10 -> V_362 ,
F_139 ( sizeof( V_10 -> V_362 ) , sizeof( V_226 -> V_655 ) ) ) ;
V_651:
if ( V_445 )
F_46 ( & V_10 -> V_289 -> V_221 , sizeof( * V_445 ) ,
V_445 , V_474 ) ;
}
static void F_140 ( struct V_9 * V_10 , void * V_656 ,
unsigned long V_657 )
{
F_141 ( F_28 ( L_80 ,
V_26 , V_10 -> V_275 -> V_650 ) ) ;
F_142 ( & V_10 -> V_658 ) ;
V_10 -> V_658 . V_659 = V_477 + V_657 * V_421 ;
V_10 -> V_658 . V_222 = ( unsigned long ) V_10 ;
V_10 -> V_658 . V_660 = ( void (*) ( unsigned long ) ) V_656 ;
F_143 ( & V_10 -> V_658 ) ;
V_10 -> V_661 = 1 ;
}
static void F_144 ( struct V_9 * V_10 )
{
F_145 ( & V_10 -> V_658 ) ;
V_10 -> V_661 = 0 ;
}
void F_146 ( struct V_223 * V_224 )
{
F_147 ( V_224 ) ;
}
void F_148 ( struct V_9 * V_10 )
{
F_149 ( V_10 -> V_275 , F_146 ) ;
}
static struct V_662 * F_150 ( struct V_9 * V_10 ,
struct V_227 * V_227 ,
struct V_332 * V_663 )
{
struct V_662 * V_662 ;
V_662 = F_151 ( V_10 -> V_664 , V_514 ) ;
if ( ! V_662 )
return V_662 ;
F_152 ( & V_662 -> V_665 ) ;
V_662 -> V_10 = V_10 ;
V_662 -> V_666 = V_227 ;
V_662 -> V_663 = V_663 ;
V_662 -> V_214 = 0 ;
F_153 ( V_663 ) = ( void * ) V_662 ;
return V_662 ;
}
static void F_154 ( struct V_9 * V_10 , struct V_662 * V_662 )
{
struct V_332 * V_663 = V_662 -> V_663 ;
if ( V_662 -> V_214 & V_667 ) {
F_155 ( V_663 ) ;
V_662 -> V_214 &= ~ V_667 ;
}
F_153 ( V_663 ) = NULL ;
}
void F_156 ( struct V_668 * V_669 )
{
struct V_662 * V_662 = F_115 ( V_669 , struct V_662 , V_665 ) ;
struct V_332 * V_663 = V_662 -> V_663 ;
struct V_9 * V_10 = V_662 -> V_10 ;
F_154 ( V_10 , V_662 ) ;
F_157 ( V_662 , V_10 -> V_664 ) ;
V_663 -> V_670 ( V_663 ) ;
}
static int F_158 ( struct V_1 * V_275 , struct V_332 * V_663 )
{
struct V_9 * V_10 = F_2 ( V_275 ) ;
struct V_227 * V_227 = V_663 -> V_220 -> V_671 ;
struct V_223 * V_226 = V_227 -> V_226 ;
struct V_662 * V_662 ;
int V_18 ;
if ( F_34 ( V_672 , & V_10 -> V_214 ) ) {
if ( F_34 ( V_673 , & V_10 -> V_214 ) )
V_663 -> V_674 = V_675 << 16 ;
else
V_663 -> V_674 = V_676 << 16 ;
goto V_677;
}
if ( ! V_226 ) {
V_663 -> V_674 = V_678 << 16 ;
goto V_677;
}
V_18 = F_15 ( V_226 ) ;
if ( V_18 ) {
V_663 -> V_674 = V_18 ;
goto V_677;
}
if ( F_34 ( V_679 , & V_10 -> V_680 ) ||
F_34 ( V_681 , & V_10 -> V_680 ) ||
F_34 ( V_682 , & V_10 -> V_680 ) ||
F_34 ( V_683 , & V_10 -> V_680 ) ||
F_34 ( V_684 , & V_10 -> V_680 ) ||
! F_34 ( V_685 , & V_10 -> V_214 ) ||
! F_34 ( V_356 , & V_10 -> V_214 ) ||
F_34 ( V_686 , & V_10 -> V_214 ) ||
F_34 ( V_687 , & V_10 -> V_680 ) ||
F_34 ( V_688 , & V_10 -> V_680 ) ||
F_34 ( V_689 , & V_10 -> V_680 ) )
goto V_690;
V_662 = F_150 ( V_10 , V_227 , V_663 ) ;
if ( ! V_662 )
goto V_690;
V_18 = F_159 ( V_10 , V_662 ) ;
if ( V_18 != V_41 )
goto V_691;
return 0 ;
V_691:
F_154 ( V_10 , V_662 ) ;
F_157 ( V_662 , V_10 -> V_664 ) ;
V_690:
return V_692 ;
V_677:
V_663 -> V_670 ( V_663 ) ;
return 0 ;
}
static void F_160 ( struct V_9 * V_10 )
{
if ( V_10 -> V_693 )
F_46 ( & V_10 -> V_289 -> V_221 , V_10 -> V_694 , V_10 -> V_693 ,
V_10 -> V_695 ) ;
if ( V_10 -> V_696 )
F_161 ( V_10 -> V_696 ) ;
V_10 -> V_694 = 0 ;
V_10 -> V_693 = NULL ;
V_10 -> V_695 = 0 ;
V_10 -> V_697 = NULL ;
V_10 -> V_698 = 0 ;
V_10 -> V_699 = NULL ;
V_10 -> V_700 = 0 ;
V_10 -> V_701 = NULL ;
V_10 -> V_702 = 0 ;
V_10 -> V_696 = NULL ;
V_10 -> V_703 = 0 ;
if ( V_10 -> V_664 )
F_162 ( V_10 -> V_664 ) ;
V_10 -> V_664 = NULL ;
if ( V_10 -> V_234 )
F_163 ( V_10 -> V_234 ) ;
if ( V_10 -> V_203 )
F_161 ( V_10 -> V_203 ) ;
V_10 -> V_203 = NULL ;
if ( V_10 -> V_704 )
F_163 ( V_10 -> V_704 ) ;
if ( F_164 ( V_10 ) ) {
if ( V_10 -> V_705 )
F_165 (
(struct V_706 V_707 * ) V_10 -> V_705 ) ;
} else if ( F_166 ( V_10 ) || F_167 ( V_10 ) ) {
if ( V_10 -> V_705 )
F_165 (
(struct V_708 V_707 * ) V_10 -> V_705 ) ;
} else if ( V_10 -> V_709 ) {
F_165 ( V_10 -> V_709 ) ;
}
if ( V_10 -> V_710 . V_711 )
F_161 ( V_10 -> V_710 . V_711 ) ;
F_168 ( V_10 -> V_289 ) ;
}
static int F_169 ( struct V_9 * V_10 )
{
unsigned long V_712 ;
V_10 -> V_694 = ( ( V_713 * V_714 ) +
( V_715 * V_714 ) +
sizeof( struct V_701 ) +
V_716 +
( V_717 - 1 ) ) & ~ ( V_717 - 1 ) ;
V_10 -> V_693 = F_42 ( & V_10 -> V_289 -> V_221 , V_10 -> V_694 ,
& V_10 -> V_695 , V_235 ) ;
if ( V_10 -> V_693 == NULL ) {
F_4 ( V_38 , V_10 ,
L_81 ) ;
goto V_718;
}
memset ( V_10 -> V_693 , 0 , V_10 -> V_694 ) ;
V_712 = 0 ;
if ( ( unsigned long ) V_10 -> V_695 & ( V_716 - 1 ) )
V_712 = V_716 - ( ( unsigned long ) V_10 -> V_695 &
( V_716 - 1 ) ) ;
V_10 -> V_698 = V_10 -> V_695 + V_712 ;
V_10 -> V_697 = (struct V_719 * ) ( V_10 -> V_693 + V_712 ) ;
V_10 -> V_700 = V_10 -> V_695 + V_712 +
( V_713 * V_714 ) ;
V_10 -> V_699 = (struct V_719 * ) ( V_10 -> V_693 + V_712 +
( V_713 *
V_714 ) ) ;
V_10 -> V_702 = V_10 -> V_695 + V_712 +
( V_713 * V_714 ) +
( V_715 * V_714 ) ;
V_10 -> V_701 = (struct V_701 * ) ( V_10 -> V_693 + V_712 +
( V_713 *
V_714 ) +
( V_715 *
V_714 ) ) ;
V_10 -> V_664 = F_170 ( V_720 , V_721 ,
V_722 , V_723 ) ;
if ( V_10 -> V_664 == NULL ) {
F_4 ( V_38 , V_10 ,
L_82 ) ;
goto V_718;
}
V_10 -> V_234 = F_171 ( L_83 , & V_10 -> V_289 -> V_221 ,
V_724 , 8 , 0 ) ;
if ( V_10 -> V_234 == NULL ) {
F_4 ( V_38 , V_10 ,
L_84 , V_26 ) ;
goto V_718;
}
V_10 -> V_704 = F_171 ( L_85 , & V_10 -> V_289 -> V_221 ,
V_725 , 8 , 0 ) ;
if ( V_10 -> V_704 == NULL ) {
F_4 ( V_38 , V_10 ,
L_86 ,
V_26 ) ;
goto V_718;
}
return V_41 ;
V_718:
F_160 ( V_10 ) ;
return V_436 ;
}
static int F_172 ( struct V_9 * V_10 )
{
T_1 V_726 , V_727 , V_728 ;
int V_444 = V_41 ;
V_726 = F_173 ( V_10 , V_729 ) ;
V_727 = F_174 ( V_726 ) ;
V_728 = F_175 ( V_726 ) ;
if ( V_727 == V_730 ) {
F_4 ( V_38 , V_10 , L_87
L_88
L_89 , V_728 ) ;
V_444 = V_436 ;
} else if ( V_727 == V_731 ) {
if ( V_10 -> V_732 == V_733 )
F_4 ( V_38 , V_10 , L_90
L_91
L_92 , V_728 ) ;
} else {
if ( V_10 -> V_732 == V_731 )
F_4 ( V_25 , V_10 , L_93
L_94 ,
V_728 ) ;
}
V_10 -> V_732 = V_727 ;
return V_444 ;
}
static int F_176 ( struct V_9 * V_10 )
{
T_1 V_734 ;
int V_444 = V_41 ;
V_734 = F_173 ( V_10 ,
V_735 ) ;
if ( V_734 == 0xffffffff ) {
F_3 ( F_28 ( V_38 L_95
L_96 ,
V_10 -> V_650 , V_26 ) ) ;
return V_444 ;
}
if ( V_10 -> V_734 == V_734 ) {
V_10 -> V_736 ++ ;
if ( V_10 -> V_736 == 2 ) {
V_10 -> V_736 = 0 ;
F_177 ( V_10 ) ;
V_444 = V_436 ;
}
} else
V_10 -> V_736 = 0 ;
V_10 -> V_734 = V_734 ;
return V_444 ;
}
static void F_178 ( struct V_9 * V_10 )
{
T_1 V_737 ;
int V_738 = 0 ;
V_737 = F_173 ( V_10 , V_739 ) ;
if ( F_164 ( V_10 ) ) {
F_4 ( V_25 , V_10 , L_97 ,
V_26 ) ;
F_179 ( V_10 , V_740 + 0x98 ,
V_741 |
V_742 ) ;
if ( F_180 ( V_737 ) == 0x67 )
F_4 ( V_242 , V_10 , L_98 ,
V_26 ) ;
if ( V_737 & V_743 )
V_738 = 1 ;
} else if ( F_166 ( V_10 ) || F_167 ( V_10 ) ) {
if ( V_737 & V_744 )
F_4 ( V_242 , V_10 , L_99 ,
V_26 ) ;
else if ( V_737 & V_745 )
V_738 = 1 ;
}
if ( V_738 ) {
F_181 ( V_683 , & V_10 -> V_680 ) ;
} else {
F_4 ( V_25 , V_10 , L_100 ,
V_26 ) ;
F_181 ( V_682 , & V_10 -> V_680 ) ;
}
F_182 ( V_10 ) ;
F_183 ( V_10 ) ;
}
void F_184 ( struct V_9 * V_10 )
{
T_1 V_746 ;
T_1 V_747 ;
if ( ! ( F_34 ( V_681 , & V_10 -> V_680 ) ||
F_34 ( V_682 , & V_10 -> V_680 ) ||
F_34 ( V_748 , & V_10 -> V_680 ) ) ) {
V_746 = F_173 ( V_10 , V_749 ) ;
if ( F_172 ( V_10 ) ) {
if ( F_164 ( V_10 ) ) {
F_4 ( V_25 , V_10 , L_101 ) ;
F_179 ( V_10 , V_740 + 0x98 ,
V_741 |
V_742 ) ;
}
F_181 ( V_683 , & V_10 -> V_680 ) ;
F_183 ( V_10 ) ;
} else if ( V_746 == V_750 &&
! F_34 ( V_682 , & V_10 -> V_680 ) ) {
F_4 ( V_25 , V_10 , L_102 ,
V_26 ) ;
if ( F_166 ( V_10 ) || F_167 ( V_10 ) ) {
V_747 = F_185 ( V_10 ,
V_751 ) ;
if ( ! ( V_747 & V_752 ) ) {
F_4 ( V_25 , V_10 , L_103 ,
V_26 ) ;
F_182 (
V_10 ) ;
}
}
if ( ( F_166 ( V_10 ) || F_167 ( V_10 ) ) ||
( F_164 ( V_10 ) && ! V_753 ) ) {
F_181 ( V_682 , & V_10 -> V_680 ) ;
F_183 ( V_10 ) ;
}
} else if ( V_746 == V_754 &&
! F_34 ( V_684 , & V_10 -> V_680 ) ) {
F_4 ( V_25 , V_10 , L_104 ,
V_26 ) ;
F_181 ( V_684 , & V_10 -> V_680 ) ;
F_183 ( V_10 ) ;
} else {
if ( F_176 ( V_10 ) )
F_178 ( V_10 ) ;
}
}
}
static void F_186 ( struct V_223 * V_285 )
{
struct V_225 * V_226 ;
struct V_227 * V_227 ;
struct V_9 * V_10 ;
V_226 = V_285 -> V_229 ;
V_227 = V_226 -> V_229 ;
V_10 = V_227 -> V_10 ;
if ( ! ( V_227 -> V_456 == V_457 ) )
return;
if ( F_33 ( V_10 ) && ! F_34 ( V_755 , & V_227 -> V_214 ) &&
! F_187 ( V_285 ) ) {
if ( F_188 ( & V_227 -> V_756 ) !=
V_757 ) {
if ( F_188 ( & V_227 -> V_756 ) ==
0 ) {
F_189 ( & V_227 -> V_756 ,
V_757 ) ;
F_181 ( V_758 , & V_10 -> V_680 ) ;
F_181 ( V_755 , & V_227 -> V_214 ) ;
F_3 ( F_4 ( V_25 , V_10 ,
L_105 ,
V_26 , V_227 -> V_291 ) ) ;
} else
F_190 ( & V_227 -> V_756 ) ;
}
}
if ( F_188 ( & V_227 -> V_759 ) &&
( F_191 ( & V_227 -> V_759 ) != 0 ) ) {
if ( ! F_187 ( V_285 ) ) {
F_192 ( & V_227 -> V_760 ) ;
F_3 ( F_4 ( V_25 , V_10 ,
L_106
L_107 , V_26 ,
V_227 -> V_291 ,
F_188 ( & V_227 -> V_760 ) ,
V_227 -> V_654 + 4 ) ) ;
F_181 ( V_758 , & V_10 -> V_680 ) ;
F_189 ( & V_227 -> V_756 ,
V_227 -> V_654 + 4 ) ;
}
}
}
static void F_193 ( struct V_9 * V_10 )
{
int V_761 = 0 ;
T_4 V_762 ;
F_149 ( V_10 -> V_275 , F_186 ) ;
if ( F_34 ( V_672 , & V_10 -> V_214 ) ) {
F_194 ( & V_10 -> V_658 , V_477 + V_421 ) ;
return;
}
if ( ! F_195 ( V_10 -> V_289 ) )
F_196 ( V_10 -> V_289 , V_763 , & V_762 ) ;
if ( F_8 ( V_10 ) )
F_184 ( V_10 ) ;
if ( F_20 ( V_10 ) ) {
if ( V_10 -> V_764 & V_765 &&
V_10 -> V_766 != 0 ) {
V_10 -> V_736 ++ ;
if ( V_10 -> V_736 >
V_10 -> V_766 + 2 )
F_181 ( V_682 , & V_10 -> V_680 ) ;
}
}
if ( ! F_197 ( & V_10 -> V_767 ) )
V_761 ++ ;
if ( V_761 ||
F_34 ( V_682 , & V_10 -> V_680 ) ||
F_34 ( V_748 , & V_10 -> V_680 ) ||
F_34 ( V_758 , & V_10 -> V_680 ) ||
F_34 ( V_689 , & V_10 -> V_680 ) ||
F_34 ( V_679 , & V_10 -> V_680 ) ||
F_34 ( V_768 , & V_10 -> V_680 ) ||
F_34 ( V_769 , & V_10 -> V_680 ) ||
F_34 ( V_683 , & V_10 -> V_680 ) ||
F_34 ( V_684 , & V_10 -> V_680 ) ||
F_34 ( V_770 , & V_10 -> V_680 ) ) {
F_3 ( F_28 ( L_108
L_109 ,
V_10 -> V_650 , V_26 , V_10 -> V_680 ) ) ;
F_183 ( V_10 ) ;
}
F_194 ( & V_10 -> V_658 , V_477 + V_421 ) ;
F_3 ( V_10 -> V_771 ++ ) ;
}
static int F_198 ( struct V_9 * V_10 )
{
T_1 V_772 = 0 ;
unsigned long V_214 ;
struct V_332 * V_663 ;
unsigned long V_472 = V_477 + ( V_773 * V_421 ) ;
F_3 ( F_4 ( V_25 , V_10 , L_110
L_111 , V_773 ) ) ;
while ( ! F_199 ( V_477 , V_472 ) ) {
F_50 ( & V_10 -> V_480 , V_214 ) ;
for ( V_772 = 0 ; V_772 < V_10 -> V_275 -> V_774 ; V_772 ++ ) {
V_663 = F_200 ( V_10 -> V_275 , V_772 ) ;
if ( V_663 != NULL && F_153 ( V_663 ) )
break;
}
F_51 ( & V_10 -> V_480 , V_214 ) ;
if ( V_772 == V_10 -> V_275 -> V_774 )
return V_41 ;
F_201 ( 1000 ) ;
}
return V_436 ;
}
int F_202 ( struct V_9 * V_10 )
{
T_1 V_775 ;
unsigned long V_214 = 0 ;
F_3 ( F_28 ( V_242 L_112 , V_10 -> V_650 , V_26 ) ) ;
if ( F_203 ( V_10 ) != V_41 )
return V_436 ;
F_50 ( & V_10 -> V_480 , V_214 ) ;
V_775 = F_204 ( & V_10 -> V_709 -> V_775 ) ;
if ( ( V_775 & V_776 ) != 0 )
F_205 ( F_206 ( V_776 ) , & V_10 -> V_709 -> V_775 ) ;
F_205 ( F_206 ( V_777 ) , & V_10 -> V_709 -> V_775 ) ;
F_207 ( & V_10 -> V_709 -> V_775 ) ;
F_51 ( & V_10 -> V_480 , V_214 ) ;
return V_41 ;
}
int F_208 ( struct V_9 * V_10 )
{
T_1 V_778 ;
unsigned long V_214 = 0 ;
int V_444 ;
T_1 V_775 ;
V_444 = F_202 ( V_10 ) ;
if ( V_444 != V_41 )
return V_444 ;
V_444 = V_436 ;
V_778 = V_779 ;
do {
F_50 ( & V_10 -> V_480 , V_214 ) ;
V_775 = F_204 ( & V_10 -> V_709 -> V_775 ) ;
F_51 ( & V_10 -> V_480 , V_214 ) ;
if ( ( V_775 & V_780 ) == 0 )
break;
F_201 ( 1000 ) ;
} while ( ( -- V_778 ) );
if ( ( V_775 & V_780 ) != 0 ) {
F_3 ( F_28 ( V_38
L_113
L_114 ,
V_10 -> V_650 ) ) ;
F_50 ( & V_10 -> V_480 , V_214 ) ;
F_205 ( F_206 ( V_780 ) , & V_10 -> V_709 -> V_775 ) ;
F_207 ( & V_10 -> V_709 -> V_775 ) ;
F_51 ( & V_10 -> V_480 , V_214 ) ;
}
V_778 = V_781 ;
do {
F_50 ( & V_10 -> V_480 , V_214 ) ;
V_775 = F_204 ( & V_10 -> V_709 -> V_775 ) ;
F_51 ( & V_10 -> V_480 , V_214 ) ;
if ( ( V_775 & V_777 ) == 0 ) {
V_444 = V_41 ;
break;
}
F_201 ( 1000 ) ;
} while ( ( -- V_778 ) );
F_50 ( & V_10 -> V_480 , V_214 ) ;
V_775 = F_204 ( & V_10 -> V_709 -> V_775 ) ;
if ( ( V_775 & V_776 ) != 0 ) {
F_205 ( F_206 ( V_776 ) , & V_10 -> V_709 -> V_775 ) ;
F_207 ( & V_10 -> V_709 -> V_775 ) ;
}
F_51 ( & V_10 -> V_480 , V_214 ) ;
if ( V_778 == 0 ) {
F_50 ( & V_10 -> V_480 , V_214 ) ;
F_205 ( F_206 ( V_782 ) , & V_10 -> V_709 -> V_775 ) ;
F_207 ( & V_10 -> V_709 -> V_775 ) ;
F_51 ( & V_10 -> V_480 , V_214 ) ;
V_778 = V_781 ;
do {
F_50 ( & V_10 -> V_480 , V_214 ) ;
V_775 = F_204 ( & V_10 -> V_709 -> V_775 ) ;
F_51 ( & V_10 -> V_480 , V_214 ) ;
if ( ( V_775 & V_782 ) == 0 ) {
V_444 = V_41 ;
break;
}
F_201 ( 1000 ) ;
} while ( ( -- V_778 ) );
}
return V_444 ;
}
static void F_209 ( struct V_9 * V_10 , int V_783 )
{
struct V_662 * V_662 ;
int V_196 ;
unsigned long V_214 ;
F_50 ( & V_10 -> V_480 , V_214 ) ;
for ( V_196 = 0 ; V_196 < V_10 -> V_275 -> V_774 ; V_196 ++ ) {
V_662 = F_210 ( V_10 , V_196 ) ;
if ( V_662 != NULL ) {
V_662 -> V_663 -> V_674 = V_783 ;
F_211 ( & V_662 -> V_665 , F_156 ) ;
}
}
F_51 ( & V_10 -> V_480 , V_214 ) ;
}
void F_212 ( struct V_9 * V_10 )
{
F_213 ( V_685 , & V_10 -> V_214 ) ;
F_4 ( V_25 , V_10 , L_115 ) ;
F_209 ( V_10 , V_675 << 16 ) ;
F_148 ( V_10 ) ;
F_213 ( V_784 , & V_10 -> V_214 ) ;
}
static void F_214 ( struct V_223 * V_224 )
{
struct V_225 * V_226 ;
struct V_227 * V_227 ;
V_226 = V_224 -> V_229 ;
V_227 = V_226 -> V_229 ;
V_227 -> V_462 = V_479 ;
if ( V_227 -> V_456 == V_457 )
F_147 ( V_227 -> V_226 ) ;
else
F_215 ( V_224 -> V_229 ,
V_785 ) ;
}
static int F_216 ( struct V_9 * V_10 )
{
int V_444 = V_436 ;
T_2 V_786 = 0 ;
T_1 V_746 ;
unsigned long V_787 ;
F_217 ( V_10 -> V_275 ) ;
F_213 ( V_685 , & V_10 -> V_214 ) ;
F_213 ( V_356 , & V_10 -> V_214 ) ;
F_3 ( F_4 ( V_25 , V_10 , L_116 , V_26 ) ) ;
F_181 ( V_681 , & V_10 -> V_680 ) ;
if ( ( F_166 ( V_10 ) || F_167 ( V_10 ) ) &&
! F_34 ( V_689 , & V_10 -> V_680 ) ) {
F_4 ( V_25 , V_10 , L_97 ,
V_26 ) ;
F_218 ( V_10 ) ;
}
F_149 ( V_10 -> V_275 , F_214 ) ;
if ( F_34 ( V_682 , & V_10 -> V_680 ) )
V_786 = 1 ;
if ( F_34 ( V_679 , & V_10 -> V_680 ) ) {
V_444 = V_41 ;
goto V_788;
}
if ( F_8 ( V_10 ) && ! V_786 &&
F_34 ( V_689 , & V_10 -> V_680 ) ) {
F_3 ( F_4 ( V_25 , V_10 ,
L_117 ,
V_10 -> V_650 , V_26 ) ) ;
V_444 = V_10 -> V_789 -> V_790 ( V_10 ) ;
if ( V_444 == V_41 ) {
if ( ! F_34 ( V_791 , & V_10 -> V_214 ) )
F_198 ( V_10 ) ;
V_10 -> V_789 -> V_792 ( V_10 ) ;
F_219 ( V_10 , V_793 ) ;
F_209 ( V_10 , V_794 << 16 ) ;
} else {
V_786 = 1 ;
F_213 ( V_689 , & V_10 -> V_680 ) ;
F_181 ( V_682 , & V_10 -> V_680 ) ;
}
}
if ( F_20 ( V_10 ) || V_786 ) {
if ( F_20 ( V_10 ) )
goto V_795;
if ( F_34 ( V_791 , & V_10 -> V_214 ) )
goto V_795;
V_787 = V_477 + ( V_796 * V_421 ) ;
while ( F_220 ( V_477 , V_787 ) ) {
if ( F_176 ( V_10 ) ) {
F_182 ( V_10 ) ;
break;
}
F_221 ( V_797 ) ;
F_222 ( V_421 ) ;
}
V_795:
if ( ! F_34 ( V_791 , & V_10 -> V_214 ) )
F_198 ( V_10 ) ;
F_219 ( V_10 , V_793 ) ;
F_209 ( V_10 , V_794 << 16 ) ;
F_3 ( F_4 ( V_25 , V_10 ,
L_118 ,
V_10 -> V_650 , V_26 ) ) ;
V_444 = V_10 -> V_789 -> V_786 ( V_10 ) ;
}
F_219 ( V_10 , V_793 ) ;
V_788:
if ( V_444 == V_41 ) {
if ( F_20 ( V_10 ) && ( V_10 -> V_798 == 3 ) )
F_223 ( 6 ) ;
V_444 = F_224 ( V_10 , V_799 ) ;
}
if ( ! F_34 ( V_685 , & V_10 -> V_214 ) &&
! F_34 ( V_679 , & V_10 -> V_680 ) ) {
if ( F_8 ( V_10 ) ) {
V_10 -> V_789 -> V_800 ( V_10 ) ;
V_746 = F_173 ( V_10 ,
V_749 ) ;
V_10 -> V_789 -> V_801 ( V_10 ) ;
if ( V_746 == V_802 ) {
F_4 ( V_25 , V_10 , L_119
L_120
L_121 , V_26 ) ;
F_212 ( V_10 ) ;
F_213 ( V_748 , & V_10 -> V_680 ) ;
F_213 ( V_682 , & V_10 -> V_680 ) ;
F_213 ( V_689 ,
& V_10 -> V_680 ) ;
V_444 = V_436 ;
goto V_803;
}
}
if ( ! F_34 ( V_748 , & V_10 -> V_680 ) ) {
V_10 -> V_804 = V_805 ;
F_3 ( F_28 ( L_122
L_123 , V_10 -> V_650 ,
V_10 -> V_804 ) ) ;
F_181 ( V_748 , & V_10 -> V_680 ) ;
V_444 = V_436 ;
} else {
if ( V_10 -> V_804 > 0 ) {
V_10 -> V_804 -- ;
F_3 ( F_28 ( L_124
L_125 ,
V_10 -> V_650 ,
V_10 -> V_804 ) ) ;
V_444 = V_436 ;
}
if ( V_10 -> V_804 == 0 ) {
F_3 ( F_28 ( L_126
L_127 ,
V_10 -> V_650 ) ) ;
F_212 ( V_10 ) ;
F_213 ( V_748 , & V_10 -> V_680 ) ;
F_213 ( V_682 , & V_10 -> V_680 ) ;
F_213 ( V_689 ,
& V_10 -> V_680 ) ;
V_444 = V_436 ;
}
}
} else {
F_213 ( V_682 , & V_10 -> V_680 ) ;
F_213 ( V_689 , & V_10 -> V_680 ) ;
F_213 ( V_748 , & V_10 -> V_680 ) ;
}
V_803:
V_10 -> V_806 ++ ;
if ( F_34 ( V_685 , & V_10 -> V_214 ) )
V_10 -> V_789 -> V_807 ( V_10 ) ;
F_225 ( V_10 -> V_275 ) ;
F_213 ( V_681 , & V_10 -> V_680 ) ;
F_3 ( F_28 ( L_128 , V_10 -> V_650 ,
V_444 == V_436 ? L_129 : L_130 ) ) ;
return V_444 ;
}
static void F_226 ( struct V_223 * V_224 )
{
struct V_225 * V_226 ;
struct V_227 * V_227 ;
struct V_9 * V_10 ;
V_226 = V_224 -> V_229 ;
V_227 = V_226 -> V_229 ;
V_10 = V_227 -> V_10 ;
if ( ! F_187 ( V_224 ) ) {
if ( V_227 -> V_462 == V_486 ) {
F_4 ( V_25 , V_10 , L_131
L_132 , V_10 -> V_650 , V_26 ,
V_227 -> V_291 ) ;
F_227 ( V_227 -> V_226 ) ;
} else {
if ( V_227 -> V_456 == V_457 ) {
if ( ! ( F_34 ( V_755 , & V_227 -> V_214 ) ||
F_34 ( V_808 ,
& V_227 -> V_214 ) ) )
F_228 ( V_227 ) ;
} else
F_215 ( V_224 -> V_229 ,
V_785 ) ;
}
}
}
int F_229 ( struct V_223 * V_224 )
{
struct V_225 * V_226 ;
struct V_227 * V_227 ;
struct V_9 * V_10 ;
V_226 = V_224 -> V_229 ;
V_227 = V_226 -> V_229 ;
V_10 = V_227 -> V_10 ;
F_4 ( V_25 , V_10 , L_131
L_132 , V_10 -> V_650 , V_26 ,
V_227 -> V_291 ) ;
F_227 ( V_227 -> V_226 ) ;
if ( F_34 ( V_685 , & V_10 -> V_214 ) ) {
F_4 ( V_25 , V_10 , L_131
L_133 , V_10 -> V_650 , V_26 ,
V_227 -> V_291 ) ;
F_230 ( V_10 -> V_275 , & V_227 -> V_226 -> V_809 ) ;
}
return V_41 ;
}
int V_465 ( struct V_223 * V_224 )
{
struct V_225 * V_226 ;
struct V_227 * V_227 ;
struct V_9 * V_10 ;
int V_444 = V_41 ;
V_226 = V_224 -> V_229 ;
V_227 = V_226 -> V_229 ;
V_10 = V_227 -> V_10 ;
F_4 ( V_25 , V_10 , L_131
L_134 , V_10 -> V_650 , V_26 ,
V_227 -> V_291 ) ;
if ( ! F_187 ( V_224 ) ) {
F_231 ( V_227 -> V_428 ) ;
F_232 ( V_227 -> V_428 ,
V_810 ) ;
} else {
F_4 ( V_25 , V_10 ,
L_135 ,
V_10 -> V_650 , V_26 , V_227 -> V_291 ,
V_224 -> V_811 ) ;
V_444 = V_436 ;
}
return V_444 ;
}
static void F_233 ( struct V_9 * V_10 )
{
F_149 ( V_10 -> V_275 , F_226 ) ;
}
static void F_234 ( struct V_223 * V_285 )
{
T_4 V_759 ;
struct V_225 * V_226 ;
struct V_227 * V_227 ;
struct V_9 * V_10 ;
V_226 = V_285 -> V_229 ;
V_227 = V_226 -> V_229 ;
V_10 = V_227 -> V_10 ;
V_759 = F_235 ( V_227 -> V_652 ,
( T_4 ) V_812 ) ;
F_189 ( & V_227 -> V_759 , V_759 ) ;
F_3 ( F_4 ( V_25 , V_10 ,
L_136 , V_10 -> V_650 ,
V_227 -> V_291 , V_759 ) ) ;
F_236 ( V_285 ) ;
}
static void F_237 ( struct V_223 * V_285 )
{
struct V_225 * V_226 ;
struct V_227 * V_227 ;
struct V_9 * V_10 ;
V_226 = V_285 -> V_229 ;
V_227 = V_226 -> V_229 ;
V_10 = V_227 -> V_10 ;
if ( ! ( V_227 -> V_456 == V_457 ) )
return;
if ( F_34 ( V_808 , & V_227 -> V_214 ) )
return;
if ( F_238 ( V_755 , & V_227 -> V_214 ) &&
! F_187 ( V_285 ) ) {
F_3 ( F_4 ( V_25 , V_10 ,
L_137 ) ) ;
F_234 ( V_285 ) ;
}
}
void F_183 ( struct V_9 * V_10 )
{
if ( V_10 -> V_813 )
F_239 ( V_10 -> V_813 , & V_10 -> V_814 ) ;
}
static struct V_815 *
F_240 ( struct V_9 * V_10 , T_1 V_816 ,
enum V_817 type )
{
struct V_815 * V_818 ;
T_1 V_819 = sizeof( struct V_815 ) + V_816 ;
V_818 = F_129 ( V_819 , V_514 ) ;
if ( ! V_818 )
return NULL ;
F_241 ( & V_818 -> V_820 ) ;
V_818 -> type = type ;
return V_818 ;
}
static void F_242 ( struct V_9 * V_10 ,
struct V_815 * V_818 )
{
unsigned long V_214 ;
F_50 ( & V_10 -> V_821 , V_214 ) ;
F_243 ( & V_818 -> V_820 , & V_10 -> V_767 ) ;
F_51 ( & V_10 -> V_821 , V_214 ) ;
F_183 ( V_10 ) ;
}
int F_244 ( struct V_9 * V_10 ,
enum V_822 V_823 ,
T_1 V_816 , T_2 * V_222 )
{
struct V_815 * V_818 ;
V_818 = F_240 ( V_10 , V_816 , V_824 ) ;
if ( ! V_818 )
return V_436 ;
V_818 -> V_825 . V_826 . V_827 = V_823 ;
V_818 -> V_825 . V_826 . V_816 = V_816 ;
memcpy ( V_818 -> V_825 . V_826 . V_222 , V_222 , V_816 ) ;
F_242 ( V_10 , V_818 ) ;
return V_41 ;
}
int F_245 ( struct V_9 * V_10 ,
T_1 V_444 , T_1 V_6 ,
T_1 V_816 , T_2 * V_222 )
{
struct V_815 * V_818 ;
V_818 = F_240 ( V_10 , V_816 , V_828 ) ;
if ( ! V_818 )
return V_436 ;
V_818 -> V_825 . V_829 . V_444 = V_444 ;
V_818 -> V_825 . V_829 . V_6 = V_6 ;
V_818 -> V_825 . V_829 . V_816 = V_816 ;
memcpy ( V_818 -> V_825 . V_829 . V_222 , V_222 , V_816 ) ;
F_242 ( V_10 , V_818 ) ;
return V_41 ;
}
static void F_246 ( struct V_9 * V_10 )
{
struct V_815 * V_818 , * V_830 ;
unsigned long V_214 ;
F_247 ( V_831 ) ;
F_50 ( & V_10 -> V_821 , V_214 ) ;
F_248 ( & V_10 -> V_767 , & V_831 ) ;
F_51 ( & V_10 -> V_821 , V_214 ) ;
F_249 (e, tmp, &work, list) {
F_250 ( & V_818 -> V_820 ) ;
switch ( V_818 -> type ) {
case V_824 :
F_251 ( V_10 -> V_650 ,
& V_364 ,
V_818 -> V_825 . V_826 . V_827 ,
V_818 -> V_825 . V_826 . V_816 ,
V_818 -> V_825 . V_826 . V_222 ) ;
break;
case V_828 :
F_252 ( V_10 -> V_650 ,
& V_364 ,
V_818 -> V_825 . V_829 . V_444 ,
V_818 -> V_825 . V_829 . V_6 ,
V_818 -> V_825 . V_829 . V_816 ,
V_818 -> V_825 . V_829 . V_222 ) ;
break;
default:
F_4 ( V_38 , V_10 , L_138
L_139 , V_818 -> type ) ;
}
F_253 ( V_818 ) ;
}
}
static void F_254 ( struct V_490 * V_831 )
{
struct V_9 * V_10 =
F_115 ( V_831 , struct V_9 , V_814 ) ;
int V_444 = V_436 ;
F_3 (printk(L_140
L_141,
ha->host_no, __func__, ha->flags, ha->dpc_flags))
if ( ! F_34 ( V_784 , & V_10 -> V_214 ) )
return;
if ( F_34 ( V_672 , & V_10 -> V_214 ) ) {
F_3 ( F_28 ( V_25 L_142 ,
V_10 -> V_650 , V_26 , V_10 -> V_214 ) ) ;
return;
}
F_246 ( V_10 ) ;
if ( F_8 ( V_10 ) ) {
if ( F_34 ( V_683 , & V_10 -> V_680 ) ) {
if ( F_166 ( V_10 ) || F_167 ( V_10 ) ) {
F_4 ( V_25 , V_10 , L_97 ,
V_26 ) ;
F_218 ( V_10 ) ;
}
V_10 -> V_789 -> V_800 ( V_10 ) ;
F_255 ( V_10 , V_749 ,
V_802 ) ;
V_10 -> V_789 -> V_801 ( V_10 ) ;
F_4 ( V_25 , V_10 , L_143 ) ;
F_256 ( V_10 ) ;
}
if ( F_34 ( V_687 , & V_10 -> V_680 ) ) {
if ( F_167 ( V_10 ) ) {
if ( V_10 -> V_832 . V_833 &
V_834 ) {
F_4 ( V_25 , V_10 , L_144 ,
V_26 ) ;
V_444 = F_257 ( V_10 ,
V_835 ) ;
if ( V_444 != V_41 ) {
F_4 ( V_25 , V_10 , L_145 ,
V_26 ) ;
}
}
}
F_258 ( V_10 ) ;
F_213 ( V_687 , & V_10 -> V_680 ) ;
}
if ( F_167 ( V_10 ) &&
F_34 ( V_688 , & V_10 -> V_680 ) ) {
F_4 ( V_25 , V_10 , L_146 ,
V_26 ) ;
if ( F_257 ( V_10 , V_836 ) !=
V_41 ) {
F_4 ( V_25 , V_10 , L_147 ,
V_26 ) ;
}
F_213 ( V_688 , & V_10 -> V_680 ) ;
}
if ( F_238 ( V_684 , & V_10 -> V_680 ) ) {
F_259 ( V_10 ) ;
}
}
if ( ! F_34 ( V_681 , & V_10 -> V_680 ) &&
( F_34 ( V_682 , & V_10 -> V_680 ) ||
F_34 ( V_679 , & V_10 -> V_680 ) ||
F_34 ( V_689 , & V_10 -> V_680 ) ) ) {
if ( ( F_164 ( V_10 ) && V_753 ) ||
( ( F_166 ( V_10 ) || F_167 ( V_10 ) ) &&
F_260 ( V_10 ) ) ) {
F_3 ( F_28 ( L_148 ,
V_10 -> V_650 , V_26 ) ) ;
F_213 ( V_682 , & V_10 -> V_680 ) ;
F_213 ( V_679 , & V_10 -> V_680 ) ;
F_213 ( V_689 , & V_10 -> V_680 ) ;
goto V_837;
}
if ( F_34 ( V_689 , & V_10 -> V_680 ) ||
F_34 ( V_682 , & V_10 -> V_680 ) )
F_216 ( V_10 ) ;
if ( F_34 ( V_679 , & V_10 -> V_680 ) ) {
T_2 V_838 = V_779 ;
while ( ( F_204 ( & V_10 -> V_709 -> V_775 ) &
( V_777 | V_782 ) ) != 0 ) {
if ( -- V_838 == 0 )
break;
F_201 ( 1000 ) ;
}
if ( V_838 == 0 )
F_3 ( F_28 ( L_149
L_150 ,
V_10 -> V_650 , V_26 ) ) ;
F_209 ( V_10 , V_794 << 16 ) ;
if ( F_203 ( V_10 ) == V_41 ) {
F_219 ( V_10 , V_793 ) ;
V_444 = F_216 ( V_10 ) ;
}
F_213 ( V_679 , & V_10 -> V_680 ) ;
if ( V_444 == V_41 )
V_10 -> V_789 -> V_807 ( V_10 ) ;
}
}
V_837:
if ( F_238 ( V_770 , & V_10 -> V_680 ) )
F_219 ( V_10 , V_839 ) ;
if ( F_238 ( V_768 , & V_10 -> V_680 ) )
F_261 ( V_10 ) ;
if ( F_33 ( V_10 ) &&
F_238 ( V_758 , & V_10 -> V_680 ) ) {
F_149 ( V_10 -> V_275 , F_237 ) ;
}
if ( ! F_34 ( V_686 , & V_10 -> V_214 ) &&
F_238 ( V_769 , & V_10 -> V_680 ) ) {
if ( ! F_34 ( V_356 , & V_10 -> V_214 ) ) {
F_148 ( V_10 ) ;
} else {
if ( F_238 ( V_277 , & V_10 -> V_214 ) ) {
F_262 ( V_10 , V_10 -> V_840 ) ;
F_149 ( V_10 -> V_275 ,
F_236 ) ;
} else
F_233 ( V_10 ) ;
}
}
}
static void F_263 ( struct V_9 * V_10 )
{
F_209 ( V_10 , V_675 << 16 ) ;
V_10 -> V_789 -> V_792 ( V_10 ) ;
if ( F_20 ( V_10 ) ) {
F_205 ( F_206 ( V_841 ) ,
& V_10 -> V_709 -> V_775 ) ;
F_207 ( & V_10 -> V_709 -> V_775 ) ;
} else if ( F_164 ( V_10 ) ) {
F_205 ( 0 , & V_10 -> V_842 -> V_843 ) ;
F_207 ( & V_10 -> V_842 -> V_843 ) ;
} else if ( F_166 ( V_10 ) || F_167 ( V_10 ) ) {
F_205 ( 0 , & V_10 -> V_844 -> V_845 ) ;
F_207 ( & V_10 -> V_844 -> V_845 ) ;
}
if ( V_10 -> V_661 )
F_144 ( V_10 ) ;
if ( V_10 -> V_813 )
F_264 ( V_10 -> V_813 ) ;
if ( V_10 -> V_846 )
F_264 ( V_10 -> V_846 ) ;
V_10 -> V_789 -> V_790 ( V_10 ) ;
if ( F_8 ( V_10 ) ) {
V_10 -> V_789 -> V_800 ( V_10 ) ;
F_265 ( V_10 ) ;
V_10 -> V_789 -> V_801 ( V_10 ) ;
}
F_266 ( V_10 ) ;
F_160 ( V_10 ) ;
}
int F_267 ( struct V_9 * V_10 )
{
int V_444 = 0 ;
unsigned long V_847 , V_848 , V_849 , V_850 ;
struct V_851 * V_289 = V_10 -> V_289 ;
V_444 = F_268 ( V_289 , V_852 ) ;
if ( V_444 ) {
F_28 ( V_38
L_151
L_152 , V_10 -> V_650 , F_269 ( V_289 ) , V_444 ) ;
goto V_853;
}
F_3 ( F_28 ( V_25 L_153 ,
V_26 , V_289 -> V_854 ) ) ;
V_10 -> V_855 = V_289 -> V_854 ;
V_847 = F_270 ( V_289 , 0 ) ;
V_848 = F_271 ( V_289 , 0 ) ;
F_3 ( F_28 ( V_25 L_154 ,
V_26 , V_847 , V_848 ) ) ;
V_10 -> V_705 = ( unsigned long ) F_272 ( V_847 , V_848 ) ;
if ( ! V_10 -> V_705 ) {
F_28 ( V_242
L_155 , F_269 ( V_289 ) ) ;
F_168 ( V_10 -> V_289 ) ;
goto V_853;
}
if ( F_164 ( V_10 ) ) {
V_10 -> V_842 = (struct V_706 V_707 * )
( ( T_2 * ) V_10 -> V_705 + 0xbc000 +
( V_10 -> V_289 -> V_856 << 11 ) ) ;
V_10 -> V_857 = ( V_10 -> V_289 -> V_856 == 4 ? V_858 :
V_859 ) ;
} else if ( F_166 ( V_10 ) || F_167 ( V_10 ) ) {
V_10 -> V_844 = (struct V_708 V_707 * )
( ( T_2 * ) V_10 -> V_705 ) ;
}
V_849 = F_270 ( V_289 , 4 ) ;
V_850 = F_271 ( V_289 , 4 ) ;
return 0 ;
V_853:
return - V_200 ;
}
int F_273 ( struct V_9 * V_10 )
{
unsigned long V_860 , V_861 , V_862 ;
unsigned long V_863 , V_864 , V_865 ;
V_860 = F_270 ( V_10 -> V_289 , 0 ) ;
V_861 = F_271 ( V_10 -> V_289 , 0 ) ;
V_862 = F_274 ( V_10 -> V_289 , 0 ) ;
if ( V_862 & V_866 ) {
if ( V_861 < V_867 ) {
F_4 ( V_38 , V_10 ,
L_156 ) ;
V_860 = 0 ;
}
} else {
F_4 ( V_38 , V_10 , L_157 ) ;
V_860 = 0 ;
}
V_863 = F_270 ( V_10 -> V_289 , 1 ) ;
V_864 = F_271 ( V_10 -> V_289 , 1 ) ;
V_865 = F_274 ( V_10 -> V_289 , 1 ) ;
if ( ! ( V_865 & V_868 ) ) {
F_4 ( V_242 , V_10 ,
L_158 ) ;
goto V_853;
}
if ( V_864 < V_867 ) {
F_4 ( V_242 , V_10 ,
L_159 ) ;
goto V_853;
}
if ( F_268 ( V_10 -> V_289 , V_852 ) ) {
F_4 ( V_38 , V_10 ,
L_160 ) ;
goto V_853;
}
V_10 -> V_869 = V_860 ;
V_10 -> V_870 = V_861 ;
V_10 -> V_709 = F_272 ( V_863 , V_867 ) ;
if ( ! V_10 -> V_709 ) {
F_4 ( V_242 , V_10 ,
L_161 ) ;
goto V_853;
}
return 0 ;
V_853:
return - V_200 ;
}
T_4 F_275 ( struct V_9 * V_10 )
{
return ( T_4 ) F_45 ( V_10 -> V_701 -> V_871 ) ;
}
T_4 F_276 ( struct V_9 * V_10 )
{
return ( T_4 ) F_45 ( F_207 ( & V_10 -> V_842 -> V_871 ) ) ;
}
T_4 F_277 ( struct V_9 * V_10 )
{
return ( T_4 ) F_45 ( V_10 -> V_701 -> V_872 ) ;
}
T_4 F_278 ( struct V_9 * V_10 )
{
return ( T_4 ) F_45 ( F_207 ( & V_10 -> V_842 -> V_872 ) ) ;
}
static T_8 F_279 ( void * V_222 , int type , char * V_188 )
{
struct V_9 * V_10 = V_222 ;
char * V_873 = V_188 ;
int V_521 ;
switch ( type ) {
case V_874 :
V_521 = sprintf ( V_873 , L_25 , V_875 ) ;
break;
case V_876 :
V_521 = sprintf ( V_873 , L_162 ) ;
break;
case V_877 :
V_521 = F_56 ( V_873 , V_10 -> V_360 ,
V_361 ) ;
break;
default:
V_521 = - V_39 ;
break;
}
return V_521 ;
}
static T_3 F_280 ( void * V_222 , int type )
{
int V_521 ;
switch ( type ) {
case V_874 :
case V_877 :
case V_876 :
V_521 = V_54 ;
break;
default:
V_521 = 0 ;
break;
}
return V_521 ;
}
static T_8 F_281 ( void * V_222 , int type , char * V_188 )
{
struct V_9 * V_10 = V_222 ;
char * V_873 = V_188 ;
int V_521 ;
switch ( type ) {
case V_878 :
V_521 = sprintf ( V_873 , L_17 , V_10 -> V_362 ) ;
break;
default:
V_521 = - V_39 ;
break;
}
return V_521 ;
}
static T_3 F_282 ( void * V_222 , int type )
{
int V_521 ;
switch ( type ) {
case V_878 :
V_521 = V_54 ;
break;
default:
V_521 = 0 ;
break;
}
return V_521 ;
}
static T_8
F_283 ( struct V_879 * V_880 , int type ,
char * V_188 )
{
struct V_881 * V_882 = & V_880 -> V_883 [ 0 ] ;
char * V_873 = V_188 ;
int V_521 ;
switch ( type ) {
case V_884 :
V_521 = sprintf ( V_188 , L_17 , ( char * ) & V_880 -> V_885 ) ;
break;
case V_886 :
if ( V_880 -> V_883 [ 0 ] . V_887 . V_888 == 0x1 )
V_521 = sprintf ( V_188 , L_16 ,
& V_882 -> V_887 . V_28 ) ;
else
V_521 = sprintf ( V_873 , L_22 ,
& V_882 -> V_887 . V_28 ) ;
break;
case V_889 :
V_521 = sprintf ( V_873 , L_25 , V_882 -> V_890 ) ;
break;
case V_891 :
V_521 = sprintf ( V_873 , L_163 ,
V_882 -> V_892 . V_893 ,
( char * ) & V_882 -> V_892 . V_894 ) ;
break;
case V_895 :
V_521 = sprintf ( V_873 , L_163 ,
V_882 -> V_892 . V_896 ,
( char * ) & V_882 -> V_892 . V_897 ) ;
break;
case V_898 :
V_521 = sprintf ( V_873 , L_163 ,
V_882 -> V_892 . V_899 ,
( char * ) & V_882 -> V_892 . V_900 ) ;
break;
case V_901 :
V_521 = sprintf ( V_873 , L_163 ,
V_882 -> V_892 . V_902 ,
( char * ) & V_882 -> V_892 . V_903 ) ;
break;
case V_904 :
V_521 = sprintf ( V_873 , L_25 , V_875 ) ;
break;
case V_905 :
V_521 = sprintf ( V_873 , L_162 ) ;
break;
default:
V_521 = - V_39 ;
break;
}
return V_521 ;
}
static T_8 F_284 ( void * V_222 , int type , char * V_188 )
{
struct V_9 * V_10 = V_222 ;
struct V_879 * V_880 = & ( V_10 -> V_906 . V_907 ) ;
return F_283 ( V_880 , type , V_188 ) ;
}
static T_8 F_285 ( void * V_222 , int type , char * V_188 )
{
struct V_9 * V_10 = V_222 ;
struct V_879 * V_880 = & ( V_10 -> V_906 . V_908 ) ;
return F_283 ( V_880 , type , V_188 ) ;
}
static T_3 F_286 ( void * V_222 , int type )
{
int V_521 ;
switch ( type ) {
case V_884 :
case V_886 :
case V_889 :
case V_891 :
case V_895 :
case V_898 :
case V_901 :
case V_905 :
case V_904 :
V_521 = V_54 ;
break;
default:
V_521 = 0 ;
break;
}
return V_521 ;
}
static void F_287 ( void * V_222 )
{
struct V_9 * V_10 = V_222 ;
F_288 ( V_10 -> V_275 ) ;
}
static int F_289 ( struct V_9 * V_10 , T_4 V_430 [] )
{
T_5 V_909 ;
T_1 V_12 , V_910 , V_911 ;
T_1 V_232 ;
T_4 V_912 ;
T_2 V_913 ;
T_2 * V_188 = NULL ;
T_9 V_819 = 13 * sizeof( T_2 ) ;
int V_195 = V_41 ;
V_912 = F_290 ( V_10 -> V_289 -> V_856 ) ;
F_4 ( V_25 , V_10 , L_164 ,
V_26 , V_10 -> V_289 -> V_220 , V_912 ) ;
if ( F_20 ( V_10 ) ) {
if ( V_912 == 1 ) {
V_12 = V_914 ;
V_910 = V_915 ;
V_911 = V_916 ;
} else if ( V_912 == 3 ) {
V_12 = V_917 ;
V_910 = V_918 ;
V_911 = V_919 ;
} else {
V_195 = V_436 ;
goto V_920;
}
V_913 = F_291 ( V_10 , V_12 ) ;
if ( ! ( V_913 & 0x07 ) ) {
F_3 ( F_4 ( V_25 , V_10 , L_165
L_166 , V_26 , V_913 ) ) ;
V_195 = V_436 ;
goto V_920;
}
V_913 = F_291 ( V_10 , V_910 ) ;
if ( V_913 & V_215 )
V_430 [ 0 ] = ( V_913 & 0x7f ) ;
V_913 = F_291 ( V_10 , V_911 ) ;
if ( V_913 & V_215 )
V_430 [ 1 ] = ( V_913 & 0x7f ) ;
} else if ( F_8 ( V_10 ) ) {
V_188 = F_42 ( & V_10 -> V_289 -> V_221 , V_819 ,
& V_909 , V_235 ) ;
if ( ! V_188 ) {
F_3 ( F_4 ( V_242 , V_10 ,
L_64 ,
V_26 ) ) ;
V_195 = V_436 ;
goto V_920;
}
if ( V_10 -> V_241 == 0 )
V_232 = V_921 ;
else if ( V_10 -> V_241 == 1 )
V_232 = V_922 ;
else {
V_195 = V_436 ;
goto V_923;
}
V_12 = V_239 + ( V_10 -> V_197 . V_924 * 4 ) +
V_232 ;
if ( F_21 ( V_10 , V_909 , V_12 ,
13 * sizeof( T_2 ) ) != V_41 ) {
F_3 ( F_4 ( V_242 , V_10 , L_167
L_168 , V_10 -> V_650 , V_26 ) ) ;
V_195 = V_436 ;
goto V_923;
}
if ( ! ( V_188 [ 1 ] & 0x07 ) ) {
F_3 ( F_4 ( V_25 , V_10 , L_169
L_170 , V_188 [ 1 ] ) ) ;
V_195 = V_436 ;
goto V_923;
}
if ( V_188 [ 2 ] & V_215 )
V_430 [ 0 ] = V_188 [ 2 ] & 0x7f ;
if ( V_188 [ 11 ] & V_215 )
V_430 [ 1 ] = V_188 [ 11 ] & 0x7f ;
} else {
V_195 = V_436 ;
goto V_920;
}
F_3 ( F_4 ( V_25 , V_10 , L_171
L_172 , V_26 , V_430 [ 0 ] ,
V_430 [ 1 ] ) ) ;
V_923:
F_46 ( & V_10 -> V_289 -> V_221 , V_819 , V_188 , V_909 ) ;
V_920:
V_10 -> V_925 = V_430 [ 0 ] ;
V_10 -> V_926 = V_430 [ 1 ] ;
return V_195 ;
}
static int F_292 ( struct V_9 * V_10 , char * V_206 ,
char * V_209 )
{
int V_196 , V_195 = - V_29 ;
int V_193 = 0 ;
struct V_189 * V_190 ;
if ( F_8 ( V_10 ) )
V_193 = ( V_10 -> V_197 . V_198 / 2 ) /
sizeof( struct V_189 ) ;
else
V_193 = V_199 ;
if ( ! V_10 -> V_203 ) {
F_4 ( V_242 , V_10 , L_173 ) ;
return V_195 ;
}
F_9 ( & V_10 -> V_202 ) ;
for ( V_196 = 0 ; V_196 < V_193 ; V_196 ++ ) {
V_190 = (struct V_189 * ) V_10 -> V_203 + V_196 ;
if ( V_190 -> V_204 !=
F_10 ( V_205 ) ) {
continue;
}
if ( V_190 -> V_214 & V_215 )
continue;
if ( ! ( V_190 -> V_214 & V_218 ) )
continue;
strncpy ( V_209 , V_190 -> V_210 , V_211 ) ;
strncpy ( V_206 , V_190 -> V_207 , V_927 ) ;
V_195 = 0 ;
break;
}
F_11 ( & V_10 -> V_202 ) ;
return V_195 ;
}
static int F_293 ( struct V_9 * V_10 ,
struct V_879 * V_880 ,
T_4 V_430 )
{
struct V_881 * V_882 = & V_880 -> V_883 [ 0 ] ;
struct V_473 * V_445 ;
T_5 V_474 ;
T_4 V_422 ;
T_4 V_15 ;
int V_195 = V_41 ;
V_445 = F_42 ( & V_10 -> V_289 -> V_221 , sizeof( * V_445 ) ,
& V_474 , V_235 ) ;
if ( ! V_445 ) {
F_3 ( F_4 ( V_242 , V_10 ,
L_174 ,
V_26 ) ) ;
V_195 = V_436 ;
return V_195 ;
}
if ( F_294 ( V_10 , V_445 ,
V_474 , V_430 ) ) {
F_3 ( F_4 ( V_25 , V_10 , L_175
L_176 , V_26 , V_430 ) ) ;
V_195 = V_436 ;
goto V_928;
}
memcpy ( V_880 -> V_885 , V_445 -> V_627 ,
F_139 ( sizeof( V_880 -> V_885 ) ,
sizeof( V_445 -> V_627 ) ) ) ;
V_15 = F_127 ( V_445 -> V_15 ) ;
if ( V_15 & V_446 ) {
memcpy ( & V_882 -> V_887 . V_28 ,
& V_445 -> V_622 [ 0 ] , V_17 ) ;
} else {
V_882 -> V_887 . V_888 = 0x1 ;
memcpy ( & V_882 -> V_887 . V_28 ,
& V_445 -> V_622 [ 0 ] , V_24 ) ;
}
V_882 -> V_890 = F_127 ( V_445 -> V_619 ) ;
V_422 = F_22 ( V_445 -> V_186 ) ;
if ( V_215 & F_127 ( V_445 -> V_535 ) ) {
F_3 ( F_4 ( V_25 , V_10 , L_177 ) ) ;
V_195 = F_295 ( V_10 , ( char * ) & V_882 -> V_892 .
V_894 ,
( char * ) & V_882 -> V_892 . V_897 ,
V_422 ) ;
if ( V_195 ) {
F_4 ( V_242 , V_10 , L_178 ) ;
V_195 = V_436 ;
goto V_928;
}
V_882 -> V_892 . V_893 = V_927 ;
V_882 -> V_892 . V_896 = V_211 ;
}
if ( V_633 & F_127 ( V_445 -> V_535 ) ) {
F_3 ( F_4 ( V_25 , V_10 , L_179 ) ) ;
V_195 = F_292 ( V_10 ,
( char * ) & V_882 -> V_892 . V_900 ,
( char * ) & V_882 -> V_892 . V_903 ) ;
if ( V_195 ) {
F_4 ( V_242 , V_10 , L_180 ) ;
V_195 = V_436 ;
goto V_928;
}
V_882 -> V_892 . V_899 = V_927 ;
V_882 -> V_892 . V_902 = V_211 ;
}
V_928:
F_46 ( & V_10 -> V_289 -> V_221 , sizeof( * V_445 ) ,
V_445 , V_474 ) ;
return V_195 ;
}
static int F_296 ( struct V_9 * V_10 )
{
T_4 V_430 [ 2 ] ;
int V_195 = V_436 ;
int V_18 ;
memset ( V_430 , 0 , sizeof( V_430 ) ) ;
V_430 [ 0 ] = 0xffff ;
V_430 [ 1 ] = 0xffff ;
V_195 = F_289 ( V_10 , V_430 ) ;
if ( V_195 != V_41 ) {
F_3 ( F_4 ( V_25 , V_10 ,
L_181 , V_26 ) ) ;
return V_195 ;
}
if ( V_929 )
return V_41 ;
if ( V_430 [ 0 ] == 0xffff )
goto V_930;
V_18 = F_293 ( V_10 , & ( V_10 -> V_906 . V_907 ) ,
V_430 [ 0 ] ) ;
if ( V_18 != V_41 ) {
F_3 ( F_4 ( V_25 , V_10 , L_182
L_183 , V_26 ) ) ;
} else
V_195 = V_41 ;
V_930:
if ( V_430 [ 1 ] == 0xffff )
goto V_931;
V_18 = F_293 ( V_10 , & ( V_10 -> V_906 . V_908 ) ,
V_430 [ 1 ] ) ;
if ( V_18 != V_41 ) {
F_3 ( F_4 ( V_25 , V_10 , L_184
L_185 , V_26 ) ) ;
} else
V_195 = V_41 ;
V_931:
return V_195 ;
}
static int F_297 ( struct V_9 * V_10 )
{
struct V_932 * V_933 ;
if ( F_296 ( V_10 ) != V_41 )
return V_436 ;
if ( V_929 ) {
F_4 ( V_25 , V_10 ,
L_186
L_187 , V_26 ) ;
return V_41 ;
}
V_10 -> V_934 = F_298 ( V_10 -> V_275 -> V_650 ) ;
if ( ! V_10 -> V_934 )
goto V_935;
if ( ! F_299 ( V_10 -> V_275 ) )
goto V_935;
V_933 = F_300 ( V_10 -> V_934 , 0 , V_10 ,
F_284 ,
F_286 ,
F_287 ) ;
if ( ! V_933 )
goto V_936;
if ( ! F_299 ( V_10 -> V_275 ) )
goto V_935;
V_933 = F_300 ( V_10 -> V_934 , 1 , V_10 ,
F_285 ,
F_286 ,
F_287 ) ;
if ( ! V_933 )
goto V_936;
if ( ! F_299 ( V_10 -> V_275 ) )
goto V_935;
V_933 = F_301 ( V_10 -> V_934 , 0 , V_10 ,
F_281 ,
F_282 ,
F_287 ) ;
if ( ! V_933 )
goto V_936;
if ( ! F_299 ( V_10 -> V_275 ) )
goto V_935;
V_933 = F_302 ( V_10 -> V_934 , 0 , V_10 ,
F_279 ,
F_280 ,
F_287 ) ;
if ( ! V_933 )
goto V_936;
return V_41 ;
V_936:
F_288 ( V_10 -> V_275 ) ;
V_935:
F_303 ( V_10 -> V_934 ) ;
return - V_200 ;
}
static void F_304 ( struct V_9 * V_10 )
{
int V_18 = 0 ;
T_2 * V_937 = NULL ;
T_1 V_232 ;
T_5 V_231 ;
T_1 V_233 = 0 ;
if ( F_20 ( V_10 ) )
V_233 = V_199 *
sizeof( struct V_189 ) ;
else
V_233 = V_10 -> V_197 . V_198 / 2 ;
V_937 = F_42 ( & V_10 -> V_289 -> V_221 , V_233 ,
& V_231 , V_235 ) ;
if ( ! V_937 ) {
F_4 ( V_242 , V_10 , L_188 ) ;
return;
}
if ( F_20 ( V_10 ) )
V_232 = V_238 ;
else {
V_232 = V_239 + ( V_10 -> V_197 . V_240 << 2 ) ;
if ( V_10 -> V_241 == 1 )
V_232 += V_233 ;
}
V_18 = F_21 ( V_10 , V_231 , V_232 , V_233 ) ;
if ( V_18 != V_41 )
goto V_938;
if ( V_10 -> V_203 == NULL )
V_10 -> V_203 = F_305 ( V_233 ) ;
if ( V_10 -> V_203 == NULL ) {
F_4 ( V_242 , V_10 , L_189 ) ;
goto V_938;
}
memcpy ( V_10 -> V_203 , V_937 , V_233 ) ;
V_938:
F_46 ( & V_10 -> V_289 -> V_221 , V_233 ,
V_937 , V_231 ) ;
}
static void F_306 ( struct V_227 * V_227 ,
struct V_939 * V_940 )
{
struct V_9 * V_10 ;
struct V_223 * V_285 ;
struct V_281 * V_282 ;
struct V_225 * V_226 ;
struct V_427 * V_428 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
V_10 = V_227 -> V_10 ;
V_285 = V_227 -> V_226 ;
V_226 = V_285 -> V_229 ;
V_282 = V_227 -> V_428 ;
V_428 = V_282 -> V_229 ;
V_940 -> V_594 = V_226 -> V_594 ;
V_940 -> V_619 = V_428 -> V_453 ;
strncpy ( V_940 -> V_627 , V_226 -> V_451 , V_941 ) ;
strncpy ( V_940 -> V_622 , V_428 -> V_452 , V_443 ) ;
}
static void F_307 ( struct V_473 * V_445 ,
struct V_939 * V_940 ,
T_2 * V_942 )
{
T_4 V_15 = 0 ;
V_940 -> V_594 = F_45 ( V_445 -> V_595 ) ;
memcpy ( & V_940 -> V_627 [ 0 ] , & V_445 -> V_627 [ 0 ] ,
F_139 ( sizeof( V_940 -> V_627 ) , sizeof( V_445 -> V_627 ) ) ) ;
V_15 = F_127 ( V_445 -> V_15 ) ;
if ( V_15 & V_446 )
sprintf ( V_940 -> V_622 , L_57 , V_445 -> V_622 ) ;
else
sprintf ( V_940 -> V_622 , L_58 , V_445 -> V_622 ) ;
V_940 -> V_619 = F_127 ( V_445 -> V_619 ) ;
if ( V_942 == NULL )
memcpy ( & V_940 -> V_630 [ 0 ] , & V_445 -> V_630 [ 0 ] ,
sizeof( V_940 -> V_630 ) ) ;
else
memcpy ( & V_940 -> V_630 [ 0 ] , & V_942 [ 0 ] , sizeof( V_940 -> V_630 ) ) ;
}
static int F_308 ( struct V_9 * V_10 ,
struct V_939 * V_943 ,
struct V_939 * V_944 ,
T_2 V_945 )
{
if ( strcmp ( V_943 -> V_627 , V_944 -> V_627 ) )
return V_436 ;
if ( strcmp ( V_943 -> V_622 , V_944 -> V_622 ) )
return V_436 ;
if ( V_943 -> V_619 != V_944 -> V_619 )
return V_436 ;
if ( V_945 ) {
F_3 ( F_4 ( V_25 , V_10 , L_190
L_191 ,
V_26 , V_943 -> V_630 [ 5 ] , V_943 -> V_630 [ 4 ] ,
V_943 -> V_630 [ 3 ] , V_943 -> V_630 [ 2 ] , V_943 -> V_630 [ 1 ] ,
V_943 -> V_630 [ 0 ] , V_944 -> V_630 [ 5 ] , V_944 -> V_630 [ 4 ] ,
V_944 -> V_630 [ 3 ] , V_944 -> V_630 [ 2 ] , V_944 -> V_630 [ 1 ] ,
V_944 -> V_630 [ 0 ] ) ) ;
if ( memcmp ( & V_943 -> V_630 [ 0 ] , & V_944 -> V_630 [ 0 ] ,
sizeof( V_943 -> V_630 ) ) )
return V_436 ;
}
F_3 ( F_4 ( V_25 , V_10 ,
L_192 ,
V_943 -> V_619 , V_943 -> V_594 , V_943 -> V_622 ,
V_943 -> V_627 , V_944 -> V_619 , V_944 -> V_594 ,
V_944 -> V_622 , V_944 -> V_627 ) ) ;
return V_41 ;
}
static int F_309 ( struct V_9 * V_10 ,
struct V_473 * V_445 )
{
struct V_227 * V_227 ;
struct V_939 * V_946 = NULL ;
struct V_939 * V_947 = NULL ;
int V_422 ;
int V_195 = V_436 ;
V_946 = F_310 ( sizeof( * V_946 ) ) ;
if ( ! V_946 ) {
F_3 ( F_4 ( V_38 , V_10 ,
L_193 ) ) ;
V_195 = V_41 ;
goto V_948;
}
V_947 = F_310 ( sizeof( * V_947 ) ) ;
if ( ! V_947 ) {
F_3 ( F_4 ( V_38 , V_10 ,
L_193 ) ) ;
V_195 = V_41 ;
goto V_948;
}
F_307 ( V_445 , V_946 , NULL ) ;
for ( V_422 = 0 ; V_422 < V_435 ; V_422 ++ ) {
V_227 = F_94 ( V_10 , V_422 ) ;
if ( V_227 == NULL )
continue;
F_306 ( V_227 , V_947 ) ;
if ( ! F_308 ( V_10 , V_946 , V_947 , false ) ) {
V_195 = V_41 ;
goto V_948;
}
}
V_948:
if ( V_946 )
F_161 ( V_946 ) ;
if ( V_947 )
F_161 ( V_947 ) ;
return V_195 ;
}
static int F_311 ( struct V_949 * V_950 , T_2 * V_630 )
{
struct V_951 * V_952 , * V_953 ;
struct V_473 * V_445 ;
F_249 (nt_ddb_idx, nt_ddb_idx_tmp, list_nt, list) {
V_445 = & V_952 -> V_954 ;
if ( memcmp ( & V_445 -> V_630 [ 0 ] , & V_630 [ 0 ] ,
sizeof( V_952 -> V_954 . V_630 ) ) == 0 ) {
return V_41 ;
}
}
return V_436 ;
}
static int F_312 ( struct V_9 * V_10 ,
struct V_949 * V_950 ,
struct V_473 * V_445 )
{
T_2 V_955 , V_196 ;
V_955 = V_445 -> V_630 [ 1 ] & 0x1f ;
for ( V_196 = 0 ; V_196 < 8 ; V_196 ++ ) {
V_445 -> V_630 [ 1 ] = ( V_955 | ( V_196 << 5 ) ) ;
if ( F_311 ( V_950 , V_445 -> V_630 ) )
break;
}
if ( ! F_311 ( V_950 , V_445 -> V_630 ) )
return V_436 ;
return V_41 ;
}
static int F_313 ( struct V_9 * V_10 ,
struct V_939 * V_943 ,
struct V_939 * V_944 )
{
if ( strcmp ( V_943 -> V_622 , V_944 -> V_622 ) == 0 ) {
if ( V_943 -> V_619 == V_944 -> V_619 )
return V_436 ;
}
if ( strcmp ( V_943 -> V_627 , V_944 -> V_627 ) )
return V_436 ;
if ( memcmp ( & V_943 -> V_630 [ 0 ] , & V_944 -> V_630 [ 0 ] ,
sizeof( V_943 -> V_630 ) ) )
return V_436 ;
return V_41 ;
}
static int F_314 ( struct V_9 * V_10 ,
struct V_949 * V_950 ,
struct V_473 * V_445 )
{
struct V_951 * V_952 , * V_953 ;
struct V_939 * V_946 = NULL ;
struct V_939 * V_947 = NULL ;
int V_18 , V_195 = V_436 ;
V_946 = F_310 ( sizeof( * V_946 ) ) ;
if ( ! V_946 ) {
F_3 ( F_4 ( V_38 , V_10 ,
L_193 ) ) ;
V_195 = V_41 ;
goto V_948;
}
V_947 = F_310 ( sizeof( * V_947 ) ) ;
if ( ! V_947 ) {
F_3 ( F_4 ( V_38 , V_10 ,
L_193 ) ) ;
V_195 = V_41 ;
goto V_948;
}
F_307 ( V_445 , V_946 , NULL ) ;
F_249 (nt_ddb_idx, nt_ddb_idx_tmp, list_nt, list) {
F_307 ( & V_952 -> V_954 , V_947 ,
V_952 -> V_942 ) ;
V_195 = F_308 ( V_10 , V_946 , V_947 , true ) ;
if ( V_195 == V_41 )
goto V_948;
}
F_249 (nt_ddb_idx, nt_ddb_idx_tmp, list_nt, list) {
F_307 ( & V_952 -> V_954 , V_947 , NULL ) ;
V_195 = F_313 ( V_10 , V_947 , V_946 ) ;
if ( V_195 == V_41 ) {
V_18 = F_312 ( V_10 , V_950 , V_445 ) ;
if ( V_18 == V_41 )
V_195 = V_436 ;
else
V_195 = V_41 ;
goto V_948;
}
}
V_948:
if ( V_946 )
F_161 ( V_946 ) ;
if ( V_947 )
F_161 ( V_947 ) ;
return V_195 ;
}
static void F_315 ( struct V_949 * V_956 )
{
struct V_951 * V_957 , * V_958 ;
F_249 (ddb_idx, ddb_idx_tmp, list_ddb, list) {
F_250 ( & V_957 -> V_820 ) ;
F_161 ( V_957 ) ;
}
}
static struct V_269 * F_316 ( struct V_9 * V_10 ,
struct V_473 * V_445 )
{
struct V_269 * V_271 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_7 * V_959 ;
struct V_280 * V_8 ;
char * V_960 ;
V_8 = F_305 ( sizeof( * V_8 ) ) ;
if ( ! V_8 )
return NULL ;
if ( V_445 -> V_15 & V_446 ) {
V_959 = (struct V_7 * ) V_8 ;
V_959 -> V_20 = V_31 ;
V_14 = (struct V_13 * ) V_8 ;
V_960 = ( char * ) & V_14 -> V_32 ;
memcpy ( V_960 , V_445 -> V_622 , V_17 ) ;
V_14 -> V_961 = F_317 ( F_127 ( V_445 -> V_619 ) ) ;
} else {
V_959 = (struct V_7 * ) V_8 ;
V_959 -> V_20 = V_21 ;
V_12 = (struct V_11 * ) V_8 ;
V_960 = ( char * ) & V_12 -> V_22 ;
memcpy ( V_960 , V_445 -> V_622 , V_24 ) ;
V_12 -> V_962 = F_317 ( F_127 ( V_445 -> V_619 ) ) ;
}
V_271 = F_27 ( V_10 -> V_275 , (struct V_7 * ) V_8 , 0 ) ;
F_161 ( V_8 ) ;
return V_271 ;
}
static int F_318 ( struct V_9 * V_10 , T_4 V_422 )
{
if ( V_929 )
return V_41 ;
if ( V_422 == V_10 -> V_925 || V_422 == V_10 -> V_926 )
return V_436 ;
return V_41 ;
}
static void F_319 ( struct V_9 * V_10 ,
struct V_227 * V_227 ,
T_4 V_422 )
{
T_4 V_618 ;
V_227 -> V_456 = V_457 ;
V_227 -> V_291 = V_757 ;
V_227 -> V_462 = V_463 ;
V_227 -> V_10 = V_10 ;
V_227 -> V_464 = F_229 ;
V_227 -> V_466 = V_963 ;
F_189 ( & V_227 -> V_756 , V_757 ) ;
F_189 ( & V_227 -> V_759 , 0 ) ;
F_189 ( & V_227 -> V_760 , 0 ) ;
V_618 = F_127 ( V_227 -> V_445 . V_618 ) ;
V_227 -> V_652 =
( V_618 > V_653 ) && ( V_618 < V_653 * 10 ) ?
V_618 : V_653 ;
V_227 -> V_654 =
F_127 ( V_227 -> V_445 . V_591 ) ;
if ( V_929 &&
( V_422 == V_10 -> V_925 || V_422 == V_10 -> V_926 ) )
F_181 ( V_964 , & V_227 -> V_214 ) ;
}
static void F_320 ( struct V_9 * V_10 )
{
T_1 V_422 = 0 ;
T_1 V_965 [ V_966 ] = { 0 , 1 , 2 , 3 } ;
T_1 V_494 [ V_411 ] ;
T_1 V_967 ;
unsigned long V_472 ;
int V_195 ;
V_472 = V_477 + ( V_421 * V_968 ) ;
do {
for ( V_422 = 0 ; V_422 < V_966 ; V_422 ++ ) {
if ( V_965 [ V_422 ] == - 1 )
continue;
V_195 = F_321 ( V_10 , 0 , V_965 [ V_422 ] , V_494 ) ;
if ( V_195 == V_436 ) {
V_965 [ V_422 ] = - 1 ;
continue;
}
V_967 = ( V_494 [ 1 ] & V_969 ) >> V_970 ;
F_3 ( F_4 ( V_25 , V_10 ,
L_194 ,
V_965 [ V_422 ] , V_967 ) ) ;
if ( V_967 == V_971 ||
V_967 == V_972 ||
V_967 == V_973 ||
V_967 == V_974 ||
V_967 == V_975 )
V_965 [ V_422 ] = - 1 ;
}
if ( ( V_965 [ 0 ] == - 1 ) &&
( V_965 [ 1 ] == - 1 ) &&
( V_965 [ 2 ] == - 1 ) &&
( V_965 [ 3 ] == - 1 ) )
break;
F_99 ( V_421 ) ;
} while ( F_100 ( V_472 , V_477 ) );
}
static void F_322 ( struct V_9 * V_10 ,
struct V_949 * V_976 )
{
struct V_951 * V_977 ;
int V_448 ;
int V_978 ;
struct V_473 * V_445 ;
T_5 V_979 ;
int V_195 ;
T_1 V_422 = 0 , V_980 = 0 ;
T_1 V_337 = 0 , V_981 = 0 ;
T_4 V_982 = 0 ;
V_445 = F_19 ( V_10 -> V_704 , V_235 ,
& V_979 ) ;
if ( V_445 == NULL ) {
F_3 ( F_4 ( V_242 , V_10 , L_195 ) ) ;
goto V_983;
}
V_448 = F_20 ( V_10 ) ? V_454 :
V_455 ;
V_978 = sizeof( struct V_951 ) ;
for ( V_422 = 0 ; V_422 < V_448 ; V_422 = V_980 ) {
V_195 = F_98 ( V_10 , V_422 , V_445 , V_979 ,
NULL , & V_980 , & V_337 ,
& V_981 , NULL , & V_982 ) ;
if ( V_195 == V_436 )
break;
if ( V_337 == V_984 )
goto V_985;
if ( strlen ( ( char * ) V_445 -> V_627 ) != 0 )
goto V_985;
V_977 = F_310 ( V_978 ) ;
if ( ! V_977 )
break;
V_977 -> V_986 = V_422 ;
F_243 ( & V_977 -> V_820 , V_976 ) ;
V_985:
if ( V_980 == 0 )
break;
}
V_983:
if ( V_445 )
F_24 ( V_10 -> V_704 , V_445 , V_979 ) ;
}
static void F_323 ( struct V_9 * V_10 ,
struct V_949 * V_956 )
{
struct V_951 * V_957 , * V_958 ;
T_1 V_980 = 0 ;
T_1 V_337 = 0 , V_981 = 0 ;
int V_195 ;
F_249 (ddb_idx, ddb_idx_tmp, list_ddb, list) {
V_195 = F_98 ( V_10 , V_957 -> V_986 ,
NULL , 0 , NULL , & V_980 , & V_337 ,
& V_981 , NULL , NULL ) ;
if ( V_195 == V_436 )
continue;
if ( V_337 == V_463 ||
V_337 == V_479 ) {
F_250 ( & V_957 -> V_820 ) ;
F_161 ( V_957 ) ;
}
}
}
static int F_324 ( struct V_9 * V_10 ,
struct V_473 * V_445 ,
int V_840 , T_4 V_422 )
{
struct V_223 * V_285 ;
struct V_225 * V_226 ;
struct V_281 * V_282 ;
struct V_269 * V_271 ;
T_4 V_458 = 32 ;
T_4 V_982 = 0 ;
T_1 V_460 = 0 ;
int V_195 = V_41 ;
struct V_227 * V_227 = NULL ;
V_285 = F_96 ( & V_364 , V_10 -> V_275 ,
V_458 , sizeof( struct V_227 ) ,
sizeof( struct V_461 ) ,
V_460 , V_757 ) ;
if ( ! V_285 ) {
V_195 = V_436 ;
goto V_987;
}
F_325 ( V_364 . V_988 ) ;
V_226 = V_285 -> V_229 ;
V_227 = V_226 -> V_229 ;
V_227 -> V_226 = V_285 ;
V_285 -> V_468 = V_469 ;
memcpy ( & V_227 -> V_445 , V_445 ,
sizeof( struct V_473 ) ) ;
F_319 ( V_10 , V_227 , V_422 ) ;
V_282 = F_105 ( V_285 , sizeof( struct V_429 ) , V_982 ) ;
if ( ! V_282 ) {
V_195 = V_436 ;
goto V_987;
}
V_227 -> V_428 = V_282 ;
V_271 = F_316 ( V_10 , V_445 ) ;
if ( V_271 ) {
V_271 -> V_428 = V_282 ;
V_282 -> V_271 = V_271 ;
} else {
F_3 ( F_4 ( V_242 , V_10 , L_196 ) ) ;
V_195 = V_436 ;
goto V_987;
}
F_136 ( V_10 , V_445 , V_285 , V_282 ) ;
if ( V_840 == V_799 ) {
F_147 ( V_285 ) ;
F_181 ( V_758 , & V_10 -> V_680 ) ;
F_181 ( V_755 , & V_227 -> V_214 ) ;
}
V_987:
return V_195 ;
}
static void F_326 ( struct V_9 * V_10 ,
struct V_949 * V_950 , int V_840 )
{
struct V_473 * V_445 ;
T_5 V_979 ;
int V_448 ;
int V_978 ;
int V_195 ;
T_1 V_422 = 0 , V_980 = 0 ;
T_1 V_337 = 0 , V_981 = 0 ;
T_4 V_982 = 0 ;
struct V_951 * V_952 ;
V_445 = F_19 ( V_10 -> V_704 , V_235 ,
& V_979 ) ;
if ( V_445 == NULL ) {
F_3 ( F_4 ( V_242 , V_10 , L_195 ) ) ;
goto V_989;
}
V_448 = F_20 ( V_10 ) ? V_454 :
V_455 ;
V_978 = sizeof( struct V_951 ) ;
for ( V_422 = 0 ; V_422 < V_448 ; V_422 = V_980 ) {
V_195 = F_98 ( V_10 , V_422 , V_445 , V_979 ,
NULL , & V_980 , & V_337 ,
& V_981 , NULL , & V_982 ) ;
if ( V_195 == V_436 )
break;
if ( F_318 ( V_10 , V_422 ) != V_41 )
goto V_990;
if ( strlen ( ( char * ) V_445 -> V_627 ) == 0 )
goto V_990;
if ( ! ( V_337 == V_463 ||
V_337 == V_479 ) )
goto V_990;
F_3 ( F_4 ( V_25 , V_10 ,
L_197 , V_422 ) ) ;
if ( V_840 == V_991 ) {
V_952 = F_305 ( V_978 ) ;
if ( ! V_952 )
break;
V_952 -> V_986 = V_422 ;
memcpy ( & V_952 -> V_942 [ 0 ] ,
& V_445 -> V_630 [ 0 ] ,
sizeof( V_952 -> V_942 ) ) ;
V_195 = F_314 ( V_10 , V_950 ,
V_445 ) ;
if ( V_195 == V_41 ) {
F_161 ( V_952 ) ;
goto V_990;
}
memcpy ( & V_952 -> V_954 , V_445 ,
sizeof( struct V_473 ) ) ;
F_243 ( & V_952 -> V_820 , V_950 ) ;
} else if ( V_840 == V_799 ) {
if ( F_309 ( V_10 , V_445 ) ==
V_41 )
goto V_990;
}
V_195 = F_324 ( V_10 , V_445 , V_840 , V_422 ) ;
if ( V_195 == V_436 )
goto V_989;
V_990:
if ( V_980 == 0 )
break;
}
V_989:
if ( V_445 )
F_24 ( V_10 -> V_704 , V_445 , V_979 ) ;
}
static void F_327 ( struct V_9 * V_10 ,
struct V_949 * V_950 )
{
struct V_473 * V_445 ;
T_5 V_979 ;
int V_448 ;
int V_978 ;
int V_195 ;
T_1 V_422 = 0 , V_980 = 0 ;
T_1 V_337 = 0 , V_981 = 0 ;
T_4 V_982 = 0 ;
struct V_951 * V_952 ;
V_445 = F_19 ( V_10 -> V_704 , V_235 ,
& V_979 ) ;
if ( V_445 == NULL ) {
F_3 ( F_4 ( V_242 , V_10 , L_195 ) ) ;
goto V_992;
}
V_448 = F_20 ( V_10 ) ? V_454 :
V_455 ;
V_978 = sizeof( struct V_951 ) ;
for ( V_422 = 0 ; V_422 < V_448 ; V_422 = V_980 ) {
V_195 = F_98 ( V_10 , V_422 , V_445 , V_979 ,
NULL , & V_980 , & V_337 ,
& V_981 , NULL , & V_982 ) ;
if ( V_195 == V_436 )
break;
if ( strlen ( ( char * ) V_445 -> V_627 ) == 0 )
goto V_993;
if ( ! ( V_337 == V_463 ) )
goto V_993;
F_3 ( F_4 ( V_25 , V_10 ,
L_197 , V_422 ) ) ;
V_952 = F_305 ( V_978 ) ;
if ( ! V_952 )
break;
V_952 -> V_986 = V_422 ;
V_195 = F_309 ( V_10 , V_445 ) ;
if ( V_195 == V_41 ) {
F_161 ( V_952 ) ;
goto V_993;
}
F_243 ( & V_952 -> V_820 , V_950 ) ;
V_195 = F_324 ( V_10 , V_445 , V_799 ,
V_422 ) ;
if ( V_195 == V_436 )
goto V_992;
V_993:
if ( V_980 == 0 )
break;
}
V_992:
if ( V_445 )
F_24 ( V_10 -> V_704 , V_445 , V_979 ) ;
}
static int F_328 ( struct V_220 * V_221 , void * V_222 )
{
struct V_519 * V_994 ;
if ( ! F_329 ( V_221 , NULL ) )
return 0 ;
V_994 = F_330 ( V_221 ) ;
return ( V_994 -> V_995 == V_996 ) ;
}
static int F_331 ( struct V_9 * V_10 ,
struct V_473 * V_445 ,
T_4 * V_422 , int V_997 )
{
struct V_519 * V_994 = NULL ;
struct V_520 * V_998 = NULL ;
int V_521 = V_436 ;
V_994 = F_332 ( V_10 -> V_275 , * V_422 ,
& V_364 , 0 ) ;
if ( ! V_994 ) {
F_4 ( V_242 , V_10 ,
L_198 ,
V_26 , * V_422 , V_10 -> V_650 ) ;
goto V_999;
}
V_998 = F_333 ( V_10 -> V_275 , V_994 ,
& V_364 , 0 ) ;
if ( ! V_998 ) {
F_4 ( V_242 , V_10 ,
L_199 ,
V_26 , * V_422 , V_10 -> V_650 ) ;
goto V_1000;
}
if ( V_997 ) {
V_994 -> V_995 = V_996 ;
} else {
V_994 -> V_995 = V_1001 ;
if ( * V_422 == V_10 -> V_925 || * V_422 == V_10 -> V_926 )
V_994 -> V_1002 = 1 ;
else
V_994 -> V_1002 = 0 ;
}
V_521 = F_126 ( V_994 , V_998 ,
V_445 ) ;
F_4 ( V_25 , V_10 , L_200 ,
V_26 , V_994 -> V_221 . V_1003 . V_207 ) ;
F_4 ( V_25 , V_10 , L_200 ,
V_26 , V_998 -> V_221 . V_1003 . V_207 ) ;
return V_41 ;
V_1000:
F_334 ( V_994 ) ;
V_999:
return V_436 ;
}
static int F_335 ( struct V_1 * V_2 , const char * V_188 ,
int V_247 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_473 * V_445 = NULL ;
T_5 V_474 ;
struct V_220 * V_221 ;
T_4 V_422 = 0 ;
T_4 V_448 = 0 ;
T_1 V_15 = 0 ;
T_1 V_18 = V_436 ;
if ( strncasecmp ( V_528 , V_188 , 4 ) &&
strncasecmp ( V_526 , V_188 , 4 ) ) {
F_3 ( F_4 ( V_242 , V_10 , L_201 ,
V_26 ) ) ;
goto V_1004;
}
V_448 = F_20 ( V_10 ) ? V_1005 :
V_455 ;
V_445 = F_42 ( & V_10 -> V_289 -> V_221 , sizeof( * V_445 ) ,
& V_474 , V_235 ) ;
if ( ! V_445 ) {
F_3 ( F_4 ( V_242 , V_10 ,
L_64 ,
V_26 ) ) ;
goto V_1004;
}
V_221 = F_336 ( V_10 -> V_275 , NULL ,
F_328 ) ;
if ( V_221 ) {
F_4 ( V_242 , V_10 ,
L_202 ,
V_26 , V_221 -> V_1003 . V_207 ) ;
F_337 ( V_221 ) ;
goto V_1004;
}
for ( V_422 = 2 ; V_422 < V_448 ; V_422 ++ ) {
if ( F_338 ( V_10 , V_445 ,
V_474 , V_422 ) )
break;
}
if ( V_422 == V_448 )
goto V_1004;
if ( ! strncasecmp ( L_76 , V_188 , 4 ) )
V_15 |= V_1006 ;
V_18 = F_339 ( V_10 , V_15 , V_474 ) ;
if ( V_18 == V_436 )
goto V_1004;
V_18 = F_331 ( V_10 , V_445 , & V_422 , 1 ) ;
V_1004:
if ( V_445 )
F_46 ( & V_10 -> V_289 -> V_221 , sizeof( * V_445 ) ,
V_445 , V_474 ) ;
if ( V_18 == V_41 )
return V_422 ;
else
return - V_416 ;
}
static int F_340 ( struct V_519 * V_994 ,
struct V_520 * V_998 )
{
struct V_1 * V_2 = F_341 ( V_994 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
T_1 V_1007 = V_1008 ;
struct V_473 * V_445 = NULL ;
T_5 V_474 ;
T_1 V_15 = 0 ;
int V_18 = 0 ;
V_445 = F_42 ( & V_10 -> V_289 -> V_221 , sizeof( * V_445 ) ,
& V_474 , V_235 ) ;
if ( ! V_445 ) {
F_3 ( F_4 ( V_242 , V_10 ,
L_64 ,
V_26 ) ) ;
V_18 = - V_200 ;
goto V_1009;
}
if ( ! strncasecmp ( V_994 -> V_525 , V_526 , 4 ) )
V_15 |= V_1006 ;
V_18 = F_339 ( V_10 , V_15 , V_474 ) ;
if ( V_18 == V_436 )
goto V_1009;
V_1007 += ( V_994 -> V_1010 *
sizeof( * V_445 ) ) ;
F_131 ( V_994 , V_998 , V_445 ) ;
V_445 -> V_204 = V_1011 ;
V_18 = F_23 ( V_10 , V_474 , V_1007 ,
sizeof( * V_445 ) , V_243 ) ;
if ( V_18 == V_41 ) {
V_994 -> V_995 = V_1001 ;
F_4 ( V_25 , V_10 ,
L_203 ,
V_26 , V_994 -> V_1010 , V_10 -> V_650 ) ;
} else {
V_18 = - V_416 ;
F_4 ( V_242 , V_10 ,
L_204 ,
V_26 , V_994 -> V_1010 , V_10 -> V_650 ) ;
}
V_1009:
if ( V_445 )
F_46 ( & V_10 -> V_289 -> V_221 , sizeof( * V_445 ) ,
V_445 , V_474 ) ;
return V_18 ;
}
static T_8 F_342 ( struct V_9 * V_10 ,
struct V_473 * V_445 ,
T_4 V_422 )
{
struct V_473 * V_227 = NULL ;
T_5 V_1012 ;
unsigned long V_472 ;
T_1 V_431 = 0 ;
T_1 V_337 = 0 , V_981 = 0 ;
T_4 V_1013 = 0 ;
int V_195 = 0 ;
V_227 = F_42 ( & V_10 -> V_289 -> V_221 , sizeof( * V_227 ) ,
& V_1012 , V_235 ) ;
if ( ! V_227 ) {
F_3 ( F_4 ( V_242 , V_10 ,
L_64 ,
V_26 ) ) ;
return V_436 ;
}
memcpy ( V_227 , V_445 , sizeof( * V_227 ) ) ;
V_195 = F_343 ( V_10 , V_422 , V_1012 , & V_431 ) ;
if ( V_195 != V_41 ) {
F_3 ( F_4 ( V_242 , V_10 ,
L_205 ,
V_26 , V_422 ) ) ;
goto V_1014;
}
F_111 ( V_10 , V_422 ) ;
V_1013 = ( ( V_10 -> V_618 > V_653 ) &&
( V_10 -> V_618 < V_653 * 10 ) ?
V_10 -> V_618 : V_653 ) ;
F_3 ( F_4 ( V_25 , V_10 ,
L_206 , V_1013 ) ) ;
V_472 = V_477 + ( V_421 * V_1013 ) ;
do {
V_195 = F_98 ( V_10 , V_422 , NULL , 0 , NULL ,
NULL , & V_337 , & V_981 , NULL ,
NULL ) ;
if ( V_195 == V_436 )
continue;
if ( V_337 == V_463 ||
V_337 == V_479 )
break;
F_99 ( V_421 / 10 ) ;
} while ( F_100 ( V_472 , V_477 ) );
V_1014:
if ( V_227 )
F_46 ( & V_10 -> V_289 -> V_221 , sizeof( * V_227 ) ,
V_227 , V_1012 ) ;
return V_195 ;
}
static int F_344 ( struct V_9 * V_10 ,
struct V_473 * V_445 )
{
struct V_951 * V_957 , * V_958 ;
struct V_949 V_950 ;
T_4 V_430 ;
int V_195 = 0 ;
if ( F_34 ( V_1015 , & V_10 -> V_214 ) ) {
F_4 ( V_38 , V_10 ,
L_207 , V_26 ) ;
return V_436 ;
}
F_241 ( & V_950 ) ;
F_181 ( V_1015 , & V_10 -> V_214 ) ;
V_195 = F_86 ( V_10 , & V_430 ) ;
if ( V_195 == V_436 )
goto V_1016;
V_195 = F_342 ( V_10 , V_445 , V_430 ) ;
if ( V_195 == V_436 )
goto V_1017;
F_327 ( V_10 , & V_950 ) ;
F_249 (ddb_idx, ddb_idx_tmp, &list_nt, list) {
F_250 ( & V_957 -> V_820 ) ;
F_101 ( V_10 , V_957 -> V_986 ) ;
F_161 ( V_957 ) ;
}
V_1017:
if ( F_101 ( V_10 , V_430 ) == V_436 ) {
F_4 ( V_242 , V_10 ,
L_208 , V_430 ) ;
}
F_213 ( V_430 , V_10 -> V_434 ) ;
V_1016:
F_213 ( V_1015 , & V_10 -> V_214 ) ;
return V_195 ;
}
static int F_345 ( struct V_9 * V_10 ,
struct V_473 * V_445 ,
T_4 V_422 )
{
int V_195 = V_436 ;
V_195 = F_309 ( V_10 , V_445 ) ;
if ( V_195 != V_41 )
V_195 = F_324 ( V_10 , V_445 , V_799 ,
V_422 ) ;
else
V_195 = - V_1018 ;
return V_195 ;
}
static int F_346 ( struct V_519 * V_994 ,
struct V_520 * V_998 )
{
struct V_1 * V_2 = F_341 ( V_994 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_473 * V_445 = NULL ;
T_5 V_474 ;
T_1 V_15 = 0 ;
int V_195 = 0 ;
if ( V_994 -> V_995 == V_996 ) {
F_4 ( V_242 , V_10 ,
L_209 , V_26 ) ;
V_195 = - V_416 ;
goto V_1019;
}
V_445 = F_42 ( & V_10 -> V_289 -> V_221 , sizeof( * V_445 ) ,
& V_474 , V_235 ) ;
if ( ! V_445 ) {
F_3 ( F_4 ( V_242 , V_10 ,
L_64 ,
V_26 ) ) ;
V_195 = - V_200 ;
goto V_1019;
}
if ( ! strncasecmp ( V_994 -> V_525 , V_526 , 4 ) )
V_15 |= V_1006 ;
V_195 = F_339 ( V_10 , V_15 , V_474 ) ;
if ( V_195 == V_436 )
goto V_1019;
F_131 ( V_994 , V_998 , V_445 ) ;
V_445 -> V_204 = V_1011 ;
if ( strlen ( ( char * ) V_445 -> V_627 ) == 0 )
V_195 = F_344 ( V_10 , V_445 ) ;
else
V_195 = F_345 ( V_10 , V_445 ,
V_994 -> V_1010 ) ;
if ( V_195 > 0 )
V_195 = - V_416 ;
V_1019:
if ( V_445 )
F_46 ( & V_10 -> V_289 -> V_221 , sizeof( * V_445 ) ,
V_445 , V_474 ) ;
return V_195 ;
}
static int F_347 ( struct V_223 * V_285 )
{
struct V_225 * V_226 ;
struct V_227 * V_227 = NULL ;
struct V_9 * V_10 ;
struct V_473 * V_445 = NULL ;
T_5 V_474 ;
unsigned long V_214 ;
unsigned long V_472 ;
T_1 V_475 ;
int V_15 ;
int V_195 = 0 ;
V_226 = V_285 -> V_229 ;
V_227 = V_226 -> V_229 ;
V_10 = V_227 -> V_10 ;
if ( V_227 -> V_456 != V_457 ) {
F_4 ( V_242 , V_10 , L_210 ,
V_26 ) ;
V_195 = - V_274 ;
goto V_1020;
}
if ( F_34 ( V_964 , & V_227 -> V_214 ) ) {
F_4 ( V_242 , V_10 ,
L_211 ,
V_26 ) ;
V_195 = - V_1018 ;
goto V_1020;
}
V_445 = F_42 ( & V_10 -> V_289 -> V_221 , sizeof( * V_445 ) ,
& V_474 , V_235 ) ;
if ( ! V_445 ) {
F_4 ( V_242 , V_10 ,
L_64 , V_26 ) ;
V_195 = - V_200 ;
goto V_1020;
}
if ( F_88 ( V_808 , & V_227 -> V_214 ) )
goto V_1021;
V_195 = F_98 ( V_10 , V_227 -> V_291 ,
V_445 , V_474 ,
NULL , NULL , & V_475 , NULL ,
NULL , NULL ) ;
if ( V_195 == V_436 )
goto V_1021;
if ( V_475 == V_486 )
goto V_1021;
V_472 = V_477 + ( V_421 * V_812 ) ;
do {
if ( F_238 ( V_755 , & V_227 -> V_214 ) )
goto V_1021;
F_99 ( V_421 ) ;
} while ( ( F_100 ( V_472 , V_477 ) ) );
V_1021:
F_189 ( & V_227 -> V_756 , V_757 ) ;
F_189 ( & V_227 -> V_759 , 0 ) ;
V_15 = V_489 ;
F_113 ( V_10 , V_227 , V_15 ) ;
memset ( V_445 , 0 , sizeof( * V_445 ) ) ;
V_472 = V_477 + ( V_421 * V_478 ) ;
do {
V_195 = F_98 ( V_10 , V_227 -> V_291 ,
V_445 , V_474 ,
NULL , NULL , & V_475 , NULL ,
NULL , NULL ) ;
if ( V_195 == V_436 )
goto V_1022;
if ( ( V_475 == V_463 ) ||
( V_475 == V_479 ) )
goto V_1022;
F_99 ( V_421 ) ;
} while ( ( F_100 ( V_472 , V_477 ) ) );
V_1022:
F_101 ( V_10 , V_227 -> V_291 ) ;
F_348 ( V_364 . V_988 ) ;
F_36 ( V_227 -> V_428 -> V_271 ) ;
F_50 ( & V_10 -> V_480 , V_214 ) ;
F_102 ( V_10 , V_227 ) ;
F_213 ( V_227 -> V_291 , V_10 -> V_434 ) ;
F_51 ( & V_10 -> V_480 , V_214 ) ;
F_103 ( V_227 -> V_226 ) ;
F_213 ( V_808 , & V_227 -> V_214 ) ;
V_195 = V_41 ;
V_1020:
if ( V_445 )
F_46 ( & V_10 -> V_289 -> V_221 , sizeof( * V_445 ) ,
V_445 , V_474 ) ;
return V_195 ;
}
static int F_349 ( struct V_519 * V_994 ,
struct V_520 * V_998 )
{
struct V_1 * V_2 = F_341 ( V_994 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_939 * V_1023 = NULL ;
struct V_939 * V_947 = NULL ;
struct V_473 * V_445 = NULL ;
struct V_227 * V_227 = NULL ;
T_5 V_979 ;
T_1 V_980 = 0 ;
T_1 V_337 = 0 , V_981 = 0 ;
T_4 V_982 = 0 ;
int V_422 , V_772 ;
int V_444 , V_195 = 0 ;
V_445 = F_19 ( V_10 -> V_704 , V_235 ,
& V_979 ) ;
if ( V_445 == NULL ) {
F_4 ( V_242 , V_10 , L_212 , V_26 ) ;
V_195 = - V_200 ;
goto V_1020;
}
V_1023 = F_310 ( sizeof( * V_1023 ) ) ;
if ( ! V_1023 ) {
F_4 ( V_38 , V_10 ,
L_213 , V_26 ) ;
V_195 = - V_200 ;
goto V_1020;
}
V_947 = F_310 ( sizeof( * V_947 ) ) ;
if ( ! V_947 ) {
F_4 ( V_38 , V_10 ,
L_213 , V_26 ) ;
V_195 = - V_200 ;
goto V_1020;
}
if ( ! V_994 -> V_451 ) {
F_4 ( V_242 , V_10 ,
L_214 ,
V_26 ) ;
V_195 = - V_1018 ;
goto V_1020;
}
if ( V_994 -> V_1002 ) {
F_4 ( V_242 , V_10 ,
L_211 ,
V_26 ) ;
V_195 = - V_1018 ;
goto V_1020;
}
strncpy ( V_1023 -> V_627 , V_994 -> V_451 ,
V_941 ) ;
if ( ! strncmp ( V_994 -> V_525 , V_526 , 4 ) )
sprintf ( V_1023 -> V_622 , L_57 , V_998 -> V_620 ) ;
else
sprintf ( V_1023 -> V_622 , L_58 , V_998 -> V_620 ) ;
V_1023 -> V_594 = V_994 -> V_594 ;
V_1023 -> V_619 = V_998 -> V_619 ;
F_130 ( V_1023 -> V_630 , V_994 -> V_630 ) ;
for ( V_422 = 0 ; V_422 < V_435 ; V_422 ++ ) {
V_227 = F_94 ( V_10 , V_422 ) ;
if ( V_227 == NULL )
continue;
if ( V_227 -> V_456 != V_457 )
continue;
V_772 = V_227 -> V_226 -> V_1010 ;
V_444 = F_98 ( V_10 , V_772 , V_445 ,
V_979 , NULL , & V_980 ,
& V_337 , & V_981 , NULL ,
& V_982 ) ;
if ( V_444 == V_436 ) {
V_195 = - V_200 ;
break;
}
F_307 ( V_445 , V_947 , NULL ) ;
V_444 = F_308 ( V_10 , V_1023 , V_947 ,
true ) ;
if ( V_444 == V_41 ) {
V_195 = F_347 ( V_227 -> V_226 ) ;
break;
}
}
if ( V_422 == V_435 )
V_195 = - V_1024 ;
V_1020:
if ( V_1023 )
F_161 ( V_1023 ) ;
if ( V_947 )
F_161 ( V_947 ) ;
if ( V_445 )
F_24 ( V_10 -> V_704 , V_445 , V_979 ) ;
return V_195 ;
}
static int
F_350 ( struct V_519 * V_994 ,
int V_47 , char * V_188 )
{
struct V_1 * V_2 = F_341 ( V_994 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_520 * V_998 ;
struct V_189 V_1025 ;
struct V_220 * V_221 ;
int V_1026 ;
int V_521 = 0 ;
V_221 = F_351 ( V_994 ) ;
if ( ! V_221 )
return - V_416 ;
V_998 = F_352 ( V_221 ) ;
switch ( V_47 ) {
case V_130 :
V_521 = sprintf ( V_188 , L_215 , V_998 -> V_522 ) ;
break;
case V_131 :
V_521 = sprintf ( V_188 , L_17 , V_994 -> V_525 ) ;
break;
case V_132 :
V_521 = sprintf ( V_188 , L_215 , V_994 -> V_529 ) ;
break;
case V_133 :
V_521 = sprintf ( V_188 , L_215 , V_994 -> V_531 ) ;
break;
case V_134 :
V_521 = sprintf ( V_188 , L_215 , V_994 -> V_533 ) ;
break;
case V_135 :
V_521 = sprintf ( V_188 , L_215 , V_998 -> V_536 ) ;
break;
case V_136 :
V_521 = sprintf ( V_188 , L_215 , V_998 -> V_538 ) ;
break;
case V_137 :
V_521 = sprintf ( V_188 , L_215 , V_994 -> V_540 ) ;
break;
case V_138 :
V_521 = sprintf ( V_188 , L_215 , V_994 -> V_542 ) ;
break;
case V_139 :
V_521 = sprintf ( V_188 , L_215 , V_994 -> V_544 ) ;
break;
case V_140 :
V_521 = sprintf ( V_188 , L_215 , V_994 -> V_546 ) ;
break;
case V_141 :
V_521 = sprintf ( V_188 , L_215 , V_994 -> V_548 ) ;
break;
case V_142 :
V_521 = sprintf ( V_188 , L_215 , V_998 -> V_550 ) ;
break;
case V_143 :
V_521 = sprintf ( V_188 , L_215 , V_994 -> V_552 ) ;
break;
case V_144 :
V_521 = sprintf ( V_188 , L_215 , V_994 -> V_554 ) ;
break;
case V_145 :
V_521 = sprintf ( V_188 , L_215 , V_994 -> V_556 ) ;
break;
case V_146 :
V_521 = sprintf ( V_188 , L_215 , V_994 -> V_559 ) ;
break;
case V_147 :
V_521 = sprintf ( V_188 , L_215 , V_998 -> V_563 ) ;
break;
case V_148 :
V_521 = sprintf ( V_188 , L_215 , V_998 -> V_565 ) ;
break;
case V_149 :
V_521 = sprintf ( V_188 , L_215 , V_998 -> V_567 ) ;
break;
case V_150 :
V_521 = sprintf ( V_188 , L_215 , V_998 -> V_570 ) ;
break;
case V_151 :
V_521 = sprintf ( V_188 , L_215 , V_998 -> V_575 ) ;
break;
case V_152 :
V_521 = sprintf ( V_188 , L_215 , V_998 -> V_578 ) ;
break;
case V_153 :
V_521 = sprintf ( V_188 , L_215 , V_998 -> V_512 ) ;
break;
case V_154 :
V_521 = sprintf ( V_188 , L_215 , V_998 -> V_582 ) ;
break;
case V_155 :
V_521 = sprintf ( V_188 , L_215 , V_994 -> V_584 ) ;
break;
case V_156 :
V_521 = sprintf ( V_188 , L_215 , V_994 -> V_590 ) ;
break;
case V_157 :
V_521 = sprintf ( V_188 , L_215 , V_994 -> V_592 ) ;
break;
case V_158 :
V_521 = sprintf ( V_188 , L_215 , V_994 -> V_588 ) ;
break;
case V_159 :
V_521 = sprintf ( V_188 , L_215 , V_998 -> V_604 ) ;
break;
case V_160 :
V_521 = sprintf ( V_188 , L_216 ,
V_994 -> V_630 [ 0 ] , V_994 -> V_630 [ 1 ] ,
V_994 -> V_630 [ 2 ] , V_994 -> V_630 [ 3 ] ,
V_994 -> V_630 [ 4 ] , V_994 -> V_630 [ 5 ] ) ;
break;
case V_161 :
V_521 = sprintf ( V_188 , L_215 , V_994 -> V_616 ) ;
break;
case V_162 :
V_521 = sprintf ( V_188 , L_25 , V_998 -> V_619 ) ;
break;
case V_163 :
V_521 = sprintf ( V_188 , L_215 , V_994 -> V_586 ) ;
break;
case V_164 :
V_521 = sprintf ( V_188 , L_215 ,
V_994 -> V_617 ) ;
break;
case V_165 :
if ( ! strncmp ( V_994 -> V_525 , V_526 , 4 ) )
V_521 = sprintf ( V_188 , L_22 , V_998 -> V_620 ) ;
else
V_521 = sprintf ( V_188 , L_16 , V_998 -> V_620 ) ;
break;
case V_166 :
if ( V_994 -> V_629 )
V_521 = sprintf ( V_188 , L_17 , V_994 -> V_629 ) ;
else
V_521 = sprintf ( V_188 , L_51 ) ;
break;
case V_167 :
if ( ! strncmp ( V_994 -> V_525 , V_526 , 4 ) )
V_521 = sprintf ( V_188 , L_22 ,
V_998 -> V_621 ) ;
else
V_521 = sprintf ( V_188 , L_16 ,
V_998 -> V_621 ) ;
break;
case V_168 :
V_521 = sprintf ( V_188 , L_215 , V_998 -> V_596 ) ;
break;
case V_169 :
V_521 = sprintf ( V_188 , L_215 , V_998 -> V_606 ) ;
break;
case V_170 :
V_521 = sprintf ( V_188 , L_215 , V_998 -> V_625 ) ;
break;
case V_171 :
if ( ! strncmp ( V_994 -> V_525 , V_526 , 4 ) )
V_521 = sprintf ( V_188 , L_215 ,
V_998 -> V_624 ) ;
else
V_521 = sprintf ( V_188 , L_51 ) ;
break;
case V_172 :
V_521 = sprintf ( V_188 , L_215 , V_998 -> V_602 ) ;
break;
case V_175 :
if ( ! strncmp ( V_994 -> V_525 , V_526 , 4 ) )
V_521 = sprintf ( V_188 , L_22 ,
V_998 -> V_626 ) ;
else
V_521 = sprintf ( V_188 , L_51 ) ;
break;
case V_176 :
V_521 = sprintf ( V_188 , L_215 , V_994 -> V_612 ) ;
break;
case V_177 :
if ( V_994 -> V_614 == V_642 )
V_1026 = V_643 ;
else if ( V_994 -> V_614 == V_641 )
V_1026 = V_644 ;
else if ( V_994 -> V_614 < V_435 )
V_1026 = V_645 ;
else
V_1026 = V_644 ;
V_521 = sprintf ( V_188 , L_17 ,
F_135 ( V_1026 ) ) ;
break;
case V_173 :
if ( V_994 -> V_451 )
V_521 = sprintf ( V_188 , L_17 , V_994 -> V_451 ) ;
else
V_521 = sprintf ( V_188 , L_51 ) ;
break;
case V_174 :
V_521 = sprintf ( V_188 , L_215 , V_994 -> V_594 ) ;
break;
case V_178 :
V_521 = sprintf ( V_188 , L_215 , V_998 -> V_598 ) ;
break;
case V_179 :
V_521 = sprintf ( V_188 , L_215 , V_998 -> V_600 ) ;
break;
case V_180 :
V_521 = sprintf ( V_188 , L_215 , V_994 -> V_615 ) ;
break;
case V_181 :
if ( V_994 -> V_548 ) {
F_353 ( V_10 ,
V_1025 . V_207 ,
V_1025 . V_210 ,
V_994 -> V_615 ) ;
V_521 = sprintf ( V_188 , L_17 , V_1025 . V_207 ) ;
} else {
V_521 = sprintf ( V_188 , L_51 ) ;
}
break;
case V_182 :
if ( V_994 -> V_548 ) {
F_353 ( V_10 ,
V_1025 . V_207 ,
V_1025 . V_210 ,
V_994 -> V_615 ) ;
V_521 = sprintf ( V_188 , L_17 , V_1025 . V_210 ) ;
} else {
V_521 = sprintf ( V_188 , L_51 ) ;
}
break;
case V_183 :
V_521 = sprintf ( V_188 , L_215 , V_998 -> V_608 ) ;
break;
case V_184 :
V_521 = sprintf ( V_188 , L_215 , V_998 -> V_610 ) ;
break;
case V_185 :
V_521 = sprintf ( V_188 , L_215 , V_994 -> V_1002 ) ;
break;
default:
V_521 = - V_39 ;
break;
}
F_337 ( V_221 ) ;
return V_521 ;
}
static int
F_354 ( struct V_519 * V_994 ,
struct V_520 * V_998 ,
void * V_222 , int V_247 )
{
struct V_1 * V_2 = F_341 ( V_994 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_1027 * V_1028 ;
struct V_414 * V_415 ;
int V_521 = V_436 ;
T_1 V_413 = V_247 ;
F_74 (attr, data, len, rem) {
V_1028 = F_75 ( V_415 ) ;
switch ( V_1028 -> V_47 ) {
case V_130 :
V_998 -> V_522 = V_1028 -> V_371 [ 0 ] ;
break;
case V_131 :
memcpy ( V_994 -> V_525 , V_1028 -> V_371 ,
strlen ( V_994 -> V_525 ) ) ;
break;
case V_132 :
V_994 -> V_529 =
V_1028 -> V_371 [ 0 ] ;
break;
case V_133 :
V_994 -> V_531 = V_1028 -> V_371 [ 0 ] ;
break;
case V_134 :
V_994 -> V_533 = V_1028 -> V_371 [ 0 ] ;
break;
case V_135 :
V_998 -> V_536 = V_1028 -> V_371 [ 0 ] ;
break;
case V_136 :
V_998 -> V_538 = V_1028 -> V_371 [ 0 ] ;
break;
case V_137 :
V_994 -> V_540 = V_1028 -> V_371 [ 0 ] ;
break;
case V_138 :
V_994 -> V_542 = V_1028 -> V_371 [ 0 ] ;
break;
case V_139 :
V_994 -> V_544 = V_1028 -> V_371 [ 0 ] ;
break;
case V_140 :
V_994 -> V_546 = V_1028 -> V_371 [ 0 ] ;
break;
case V_141 :
V_994 -> V_548 = V_1028 -> V_371 [ 0 ] ;
break;
case V_142 :
V_998 -> V_550 = V_1028 -> V_371 [ 0 ] ;
break;
case V_143 :
V_994 -> V_552 = V_1028 -> V_371 [ 0 ] ;
break;
case V_144 :
V_994 -> V_554 = V_1028 -> V_371 [ 0 ] ;
break;
case V_145 :
V_994 -> V_556 =
V_1028 -> V_371 [ 0 ] ;
break;
case V_146 :
V_994 -> V_559 = V_1028 -> V_371 [ 0 ] ;
break;
case V_147 :
V_998 -> V_563 = V_1028 -> V_371 [ 0 ] ;
break;
case V_148 :
V_998 -> V_565 = V_1028 -> V_371 [ 0 ] ;
break;
case V_149 :
V_998 -> V_567 = V_1028 -> V_371 [ 0 ] ;
break;
case V_150 :
V_998 -> V_570 = V_1028 -> V_371 [ 0 ] ;
break;
case V_151 :
V_998 -> V_575 = V_1028 -> V_371 [ 0 ] ;
break;
case V_152 :
V_998 -> V_578 = V_1028 -> V_371 [ 0 ] ;
break;
case V_153 :
V_998 -> V_512 =
* ( unsigned * ) V_1028 -> V_371 ;
break;
case V_154 :
V_998 -> V_582 =
* ( unsigned * ) V_1028 -> V_371 ;
break;
case V_155 :
V_994 -> V_584 =
* ( unsigned * ) V_1028 -> V_371 ;
break;
case V_156 :
V_994 -> V_590 = * ( T_4 * ) V_1028 -> V_371 ;
break;
case V_157 :
V_994 -> V_592 =
* ( T_4 * ) V_1028 -> V_371 ;
break;
case V_158 :
V_994 -> V_588 =
* ( T_4 * ) V_1028 -> V_371 ;
break;
case V_159 :
V_998 -> V_604 =
* ( T_4 * ) V_1028 -> V_371 ;
break;
case V_160 :
memcpy ( V_994 -> V_630 , V_1028 -> V_371 ,
sizeof( V_994 -> V_630 ) ) ;
break;
case V_161 :
V_994 -> V_616 = * ( T_4 * ) V_1028 -> V_371 ;
break;
case V_162 :
V_998 -> V_619 = * ( T_4 * ) V_1028 -> V_371 ;
break;
case V_163 :
V_994 -> V_586 = * ( unsigned * ) V_1028 -> V_371 ;
break;
case V_164 :
V_994 -> V_617 =
* ( T_4 * ) V_1028 -> V_371 ;
break;
case V_165 :
memcpy ( V_998 -> V_620 , V_1028 -> V_371 ,
V_17 ) ;
break;
case V_166 :
V_521 = F_128 ( & V_994 -> V_629 ,
( char * ) V_1028 -> V_371 ) ;
break;
case V_167 :
memcpy ( V_998 -> V_621 , V_1028 -> V_371 ,
V_17 ) ;
break;
case V_168 :
V_998 -> V_596 =
* ( unsigned * ) V_1028 -> V_371 ;
break;
case V_169 :
V_998 -> V_606 =
* ( T_4 * ) V_1028 -> V_371 ;
break;
case V_170 :
V_998 -> V_625 = V_1028 -> V_371 [ 0 ] ;
break;
case V_171 :
V_998 -> V_624 = V_1028 -> V_371 [ 0 ] ;
break;
case V_172 :
V_998 -> V_602 = V_1028 -> V_371 [ 0 ] ;
break;
case V_173 :
V_521 = F_128 ( & V_994 -> V_451 ,
( char * ) V_1028 -> V_371 ) ;
break;
case V_174 :
V_994 -> V_594 = * ( T_4 * ) V_1028 -> V_371 ;
break;
case V_175 :
memcpy ( V_998 -> V_626 ,
V_1028 -> V_371 , V_17 ) ;
break;
case V_176 :
V_994 -> V_612 =
* ( T_4 * ) V_1028 -> V_371 ;
break;
case V_178 :
V_998 -> V_598 =
* ( T_2 * ) V_1028 -> V_371 ;
break;
case V_179 :
V_998 -> V_600 =
* ( T_2 * ) V_1028 -> V_371 ;
break;
case V_183 :
V_998 -> V_608 = * ( T_1 * ) V_1028 -> V_371 ;
break;
case V_184 :
V_998 -> V_610 =
* ( T_1 * ) V_1028 -> V_371 ;
break;
default:
F_4 ( V_242 , V_10 ,
L_217 , V_26 ) ;
V_521 = - V_39 ;
goto V_487;
}
}
V_521 = F_340 ( V_994 , V_998 ) ;
V_487:
return V_521 ;
}
static int F_355 ( struct V_519 * V_994 )
{
struct V_1 * V_2 = F_341 ( V_994 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
T_1 V_1007 ;
T_1 V_1029 ;
struct V_473 * V_445 = NULL ;
T_5 V_474 ;
T_4 * V_1030 = NULL ;
T_9 V_1031 = 0 ;
void * V_1032 = NULL ;
int V_1010 ;
int V_521 = 0 ;
if ( V_994 -> V_1002 ) {
V_521 = - V_1018 ;
F_3 ( F_4 ( V_242 , V_10 ,
L_218 ,
V_26 ) ) ;
goto V_1033;
}
if ( V_994 -> V_995 == V_996 )
goto V_1034;
if ( F_20 ( V_10 ) ) {
V_1007 = V_1008 ;
V_1029 = V_1035 ;
V_1007 += ( V_994 -> V_1010 *
sizeof( * V_445 ) ) ;
V_1031 = sizeof( * V_445 ) ;
} else {
V_1007 = V_239 +
( V_10 -> V_197 . V_1036 << 2 ) ;
if ( V_10 -> V_241 == 1 )
V_1007 += ( V_10 -> V_197 . V_1037 / 2 ) ;
V_1029 = V_1007 +
( V_10 -> V_197 . V_1037 / 2 ) ;
V_1007 += ( V_994 -> V_1010 *
sizeof( * V_445 ) ) ;
V_1007 += F_356 ( struct V_473 , V_204 ) ;
V_1031 = sizeof( * V_1030 ) ;
}
F_3 ( F_4 ( V_242 , V_10 , L_219 ,
V_26 , V_1007 , V_1029 ) ) ;
if ( V_1007 > V_1029 ) {
V_521 = - V_416 ;
F_3 ( F_4 ( V_242 , V_10 , L_220 ,
V_26 , V_994 -> V_1010 ) ) ;
goto V_1033;
}
V_1032 = F_42 ( & V_10 -> V_289 -> V_221 , V_1031 ,
& V_474 , V_235 ) ;
if ( ! V_1032 ) {
V_521 = - V_200 ;
F_3 ( F_4 ( V_242 , V_10 ,
L_64 ,
V_26 ) ) ;
goto V_1033;
}
if ( F_20 ( V_10 ) ) {
V_445 = V_1032 ;
memset ( V_445 , 0 , V_1031 ) ;
V_1030 = & V_445 -> V_204 ;
} else {
V_1030 = V_1032 ;
}
* V_1030 = 0xFFEE ;
F_23 ( V_10 , V_474 , V_1007 ,
V_1031 , V_243 ) ;
V_1034:
V_1010 = V_994 -> V_1010 ;
F_334 ( V_994 ) ;
F_4 ( V_25 , V_10 ,
L_221 ,
V_26 , V_1010 , V_10 -> V_650 ) ;
V_1033:
if ( V_1032 )
F_46 ( & V_10 -> V_289 -> V_221 , V_1031 , V_1032 ,
V_474 ) ;
return V_521 ;
}
static int F_357 ( struct V_9 * V_10 )
{
struct V_473 * V_445 = NULL ;
T_5 V_474 ;
T_4 V_448 ;
T_4 V_422 = 0 ;
int V_195 = V_41 ;
V_445 = F_42 ( & V_10 -> V_289 -> V_221 ,
sizeof( * V_445 ) ,
& V_474 , V_235 ) ;
if ( ! V_445 ) {
F_3 ( F_4 ( V_242 , V_10 ,
L_64 ,
V_26 ) ) ;
return - V_200 ;
}
V_448 = F_20 ( V_10 ) ? V_1005 :
V_455 ;
for ( V_422 = 0 ; V_422 < V_448 ; V_422 ++ ) {
if ( F_338 ( V_10 , V_445 , V_474 ,
V_422 ) )
continue;
V_195 = F_331 ( V_10 , V_445 , & V_422 , 0 ) ;
if ( V_195 ) {
V_195 = - V_416 ;
break;
}
}
F_46 ( & V_10 -> V_289 -> V_221 , sizeof( * V_445 ) , V_445 ,
V_474 ) ;
return V_195 ;
}
static void F_358 ( struct V_9 * V_10 )
{
F_359 ( V_10 -> V_275 ) ;
}
void F_262 ( struct V_9 * V_10 , int V_840 )
{
T_4 V_1013 = 0 ;
struct V_949 V_976 , V_950 ;
struct V_951 * V_977 , * V_1038 ;
unsigned long V_472 ;
if ( ! F_34 ( V_356 , & V_10 -> V_214 ) ) {
F_181 ( V_277 , & V_10 -> V_214 ) ;
V_10 -> V_840 = V_840 ;
return;
}
F_241 ( & V_976 ) ;
F_241 ( & V_950 ) ;
F_322 ( V_10 , & V_976 ) ;
F_320 ( V_10 ) ;
F_249 (st_ddb_idx, st_ddb_idx_tmp, &list_st, list) {
F_111 ( V_10 , V_977 -> V_986 ) ;
}
V_1013 = ( ( V_10 -> V_618 > V_653 ) &&
( V_10 -> V_618 < V_653 * 10 ) ?
V_10 -> V_618 : V_653 ) ;
F_3 ( F_4 ( V_25 , V_10 ,
L_222 , V_1013 ) ) ;
V_472 = V_477 + ( V_421 * V_1013 ) ;
do {
if ( F_197 ( & V_976 ) )
break;
F_323 ( V_10 , & V_976 ) ;
F_99 ( V_421 / 10 ) ;
} while ( F_100 ( V_472 , V_477 ) );
F_315 ( & V_976 ) ;
F_326 ( V_10 , & V_950 , V_840 ) ;
F_315 ( & V_950 ) ;
F_360 ( V_10 ) ;
}
static void F_361 ( struct V_9 * V_10 )
{
struct V_227 * V_227 ;
struct V_473 * V_445 = NULL ;
T_5 V_474 ;
unsigned long V_472 ;
T_1 V_475 ;
int V_448 , V_422 , V_195 ;
V_448 = F_20 ( V_10 ) ? V_454 :
V_455 ;
V_445 = F_42 ( & V_10 -> V_289 -> V_221 , sizeof( * V_445 ) ,
& V_474 , V_235 ) ;
if ( ! V_445 ) {
F_4 ( V_242 , V_10 ,
L_64 , V_26 ) ;
goto V_1039;
}
V_472 = V_477 + ( V_421 * V_1040 ) ;
for ( V_422 = 0 ; V_422 < V_448 ; V_422 ++ ) {
V_227 = F_94 ( V_10 , V_422 ) ;
if ( V_227 == NULL )
continue;
if ( F_34 ( V_964 , & V_227 -> V_214 ) ) {
F_3 ( F_4 ( V_25 , V_10 ,
L_223 , V_26 ,
V_227 -> V_291 ) ) ;
do {
V_195 = F_98 ( V_10 ,
V_227 -> V_291 ,
V_445 , V_474 ,
NULL , NULL , & V_475 , NULL ,
NULL , NULL ) ;
if ( V_195 == V_436 )
goto V_1039;
if ( ( V_475 == V_486 ) ||
( V_475 == V_479 ) )
break;
F_99 ( V_421 ) ;
} while ( ( F_100 ( V_472 , V_477 ) ) );
if ( ! F_100 ( V_472 , V_477 ) ) {
F_3 ( F_4 ( V_25 , V_10 ,
L_224 ,
V_26 ) ) ;
goto V_1039;
}
}
}
V_1039:
if ( V_445 )
F_46 ( & V_10 -> V_289 -> V_221 , sizeof( * V_445 ) ,
V_445 , V_474 ) ;
}
static int F_362 ( struct V_851 * V_289 ,
const struct V_1041 * V_1042 )
{
int V_195 = - V_1043 , V_444 ;
struct V_1 * V_275 ;
struct V_9 * V_10 ;
T_2 V_1044 = 0 ;
char V_188 [ 34 ] ;
struct V_1045 * V_1046 ;
T_1 V_746 ;
if ( F_363 ( V_289 ) )
return - 1 ;
V_275 = F_364 ( & V_1047 , sizeof( * V_10 ) , 0 ) ;
if ( V_275 == NULL ) {
F_28 ( V_38
L_225 ) ;
goto V_1048;
}
V_10 = F_2 ( V_275 ) ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_289 = V_289 ;
V_10 -> V_275 = V_275 ;
V_10 -> V_650 = V_275 -> V_650 ;
V_10 -> V_912 = F_290 ( V_10 -> V_289 -> V_856 ) ;
F_365 ( V_289 ) ;
if ( F_164 ( V_10 ) ) {
V_10 -> V_789 = & V_1049 ;
V_10 -> V_1050 = ( T_1 * ) V_1051 ;
V_10 -> V_1052 = - 1 ;
V_10 -> V_1053 = - 1 ;
V_10 -> V_1054 = 255 ;
V_1046 = & V_1055 [ V_10 -> V_912 ] ;
V_10 -> V_1046 . V_1056 = V_1046 -> V_1056 ;
V_10 -> V_1046 . V_1057 =
V_1046 -> V_1057 ;
V_10 -> V_1046 . V_1058 = V_1046 -> V_1058 ;
V_10 -> V_1046 . V_1059 = V_1046 -> V_1059 ;
} else if ( F_166 ( V_10 ) || F_167 ( V_10 ) ) {
V_10 -> V_789 = & V_1060 ;
V_10 -> V_1050 = ( T_1 * ) V_1061 ;
} else {
V_10 -> V_789 = & V_1062 ;
}
if ( F_8 ( V_10 ) ) {
F_366 ( & V_10 -> V_1063 ) ;
V_10 -> V_1064 = V_10 -> V_912 << 16 ;
V_289 -> V_1065 = 1 ;
}
V_195 = V_10 -> V_789 -> V_1066 ( V_10 ) ;
if ( V_195 )
goto V_1067;
F_4 ( V_25 , V_10 , L_226 ,
V_289 -> V_220 , V_289 -> V_1068 , V_10 -> V_709 ) ;
F_367 ( V_10 ) ;
F_241 ( & V_10 -> V_1069 ) ;
F_368 ( & V_10 -> V_1070 ) ;
F_368 ( & V_10 -> V_202 ) ;
F_369 ( & V_10 -> V_1071 ) ;
F_369 ( & V_10 -> V_419 ) ;
F_370 ( & V_10 -> V_480 ) ;
F_370 ( & V_10 -> V_821 ) ;
F_241 ( & V_10 -> V_767 ) ;
if ( F_169 ( V_10 ) ) {
F_4 ( V_38 , V_10 ,
L_227 ) ;
V_195 = - V_200 ;
goto V_1072;
}
V_275 -> V_1073 = 3 ;
V_275 -> V_1074 = 0 ;
V_275 -> V_1075 = V_1076 - 1 ;
V_275 -> V_1077 = V_1078 ;
V_275 -> V_1079 = V_1080 ;
V_275 -> V_774 = V_1081 ;
V_275 -> V_1082 = V_1083 ;
V_195 = F_371 ( V_275 , V_1081 ) ;
if ( V_195 ) {
F_4 ( V_38 , V_10 ,
L_228 , V_26 ) ;
goto V_1072;
}
F_372 ( V_289 , V_10 ) ;
V_195 = F_373 ( V_275 , & V_289 -> V_221 ) ;
if ( V_195 )
goto V_1072;
if ( F_8 ( V_10 ) )
F_374 ( V_10 ) ;
if ( F_166 ( V_10 ) || F_167 ( V_10 ) ) {
F_375 ( V_10 ) ;
if ( V_753 == 1 )
F_376 ( V_10 ) ;
}
V_444 = F_224 ( V_10 , V_991 ) ;
if ( F_8 ( V_10 ) && ! F_34 ( V_1084 , & V_10 -> V_214 ) ) {
F_4 ( V_38 , V_10 , L_229 ,
V_26 ) ;
goto V_1085;
}
while ( ( ! F_34 ( V_685 , & V_10 -> V_214 ) ) &&
V_1044 ++ < V_1086 ) {
if ( F_8 ( V_10 ) ) {
V_10 -> V_789 -> V_800 ( V_10 ) ;
V_746 = F_173 ( V_10 ,
V_749 ) ;
V_10 -> V_789 -> V_801 ( V_10 ) ;
if ( V_746 == V_802 ) {
F_4 ( V_38 , V_10 , L_119
L_230 ,
V_26 ) ;
break;
}
}
F_3 ( F_28 ( L_231
L_232 , V_26 , V_1044 ) ) ;
if ( V_10 -> V_789 -> V_786 ( V_10 ) == V_436 )
continue;
V_444 = F_224 ( V_10 , V_991 ) ;
}
V_1085:
if ( ! F_34 ( V_685 , & V_10 -> V_214 ) ) {
F_4 ( V_38 , V_10 , L_233 ) ;
if ( ( F_164 ( V_10 ) && V_753 ) ||
( ( F_166 ( V_10 ) || F_167 ( V_10 ) ) &&
F_260 ( V_10 ) ) ) {
F_3 ( F_28 ( V_242 L_234 ) ) ;
V_10 -> V_789 -> V_800 ( V_10 ) ;
F_255 ( V_10 , V_749 ,
V_802 ) ;
V_10 -> V_789 -> V_801 ( V_10 ) ;
}
V_195 = - V_1043 ;
goto V_1087;
}
F_3 ( F_28 ( L_235
L_236 , V_26 ) ) ;
sprintf ( V_188 , L_237 , V_10 -> V_650 ) ;
V_10 -> V_813 = F_377 ( V_188 ) ;
if ( ! V_10 -> V_813 ) {
F_4 ( V_38 , V_10 , L_238 ) ;
V_195 = - V_1043 ;
goto V_1087;
}
F_121 ( & V_10 -> V_814 , F_254 ) ;
V_10 -> V_846 = F_378 ( L_239 , V_1088 , 1 ,
V_10 -> V_650 ) ;
if ( ! V_10 -> V_846 ) {
F_4 ( V_38 , V_10 , L_240 ) ;
V_195 = - V_1043 ;
goto V_1087;
}
if ( F_20 ( V_10 ) ) {
V_195 = F_379 ( V_10 ) ;
if ( V_195 ) {
F_4 ( V_38 , V_10 , L_241
L_242 , V_289 -> V_1068 ) ;
goto V_1087;
}
}
F_380 ( V_10 -> V_289 ) ;
V_10 -> V_789 -> V_807 ( V_10 ) ;
F_140 ( V_10 , F_193 , 1 ) ;
F_181 ( V_784 , & V_10 -> V_214 ) ;
F_381 ( V_10 ) ;
F_28 ( V_25
L_243
L_244 ,
V_1089 , V_10 -> V_289 -> V_220 , F_269 ( V_10 -> V_289 ) ,
V_10 -> V_650 , V_10 -> V_1090 . V_1091 , V_10 -> V_1090 . V_1092 ,
V_10 -> V_1090 . V_1093 , V_10 -> V_1090 . V_1094 ) ;
if ( F_8 ( V_10 ) )
F_382 ( V_10 , V_1095 ) ;
if ( F_297 ( V_10 ) )
F_4 ( V_242 , V_10 ,
L_245 , V_26 ) ;
if ( F_357 ( V_10 ) )
F_4 ( V_242 , V_10 ,
L_246 , V_26 ) ;
F_262 ( V_10 , V_991 ) ;
F_149 ( V_10 -> V_275 , F_236 ) ;
F_361 ( V_10 ) ;
F_304 ( V_10 ) ;
F_62 ( V_10 ) ;
return 0 ;
V_1087:
F_383 ( V_10 -> V_275 ) ;
V_1072:
F_263 ( V_10 ) ;
V_1067:
F_384 ( V_289 ) ;
F_288 ( V_10 -> V_275 ) ;
V_1048:
F_385 ( V_289 ) ;
return V_195 ;
}
static void F_386 ( struct V_9 * V_10 )
{
struct V_9 * V_1096 = NULL ;
struct V_851 * V_1097 = NULL ;
int V_1098 = V_1099 ;
if ( F_290 ( V_10 -> V_289 -> V_856 ) & V_560 )
V_1098 = V_1100 ;
V_1097 =
F_387 ( F_388 ( V_10 -> V_289 -> V_1101 ) ,
V_10 -> V_289 -> V_1101 -> V_1102 , F_389 ( F_390 ( V_10 -> V_289 -> V_856 ) ,
V_1098 ) ) ;
if ( V_1097 ) {
if ( F_188 ( & V_1097 -> V_1103 ) ) {
V_1096 = F_391 ( V_1097 ) ;
if ( V_1096 ) {
F_181 ( V_1104 , & V_1096 -> V_214 ) ;
F_3 ( F_4 ( V_25 , V_10 , L_247
L_248 , V_26 ,
F_392 ( & V_1096 -> V_289 -> V_221 ) ) ) ;
}
}
F_393 ( V_1097 ) ;
}
}
static void F_394 ( struct V_9 * V_10 )
{
struct V_227 * V_227 ;
int V_15 ;
int V_422 ;
for ( V_422 = 0 ; V_422 < V_435 ; V_422 ++ ) {
V_227 = F_94 ( V_10 , V_422 ) ;
if ( ( V_227 != NULL ) &&
( V_227 -> V_456 == V_457 ) ) {
V_15 = V_489 ;
if ( F_113 ( V_10 , V_227 , V_15 )
== V_436 )
F_4 ( V_242 , V_10 , L_69 ,
V_26 ) ;
F_101 ( V_10 , V_227 -> V_291 ) ;
F_348 ( V_364 . V_988 ) ;
F_36 ( V_227 -> V_428 -> V_271 ) ;
F_102 ( V_10 , V_227 ) ;
F_103 ( V_227 -> V_226 ) ;
}
}
}
static void F_395 ( struct V_851 * V_289 )
{
struct V_9 * V_10 ;
if ( ! F_396 ( V_289 ) )
return;
V_10 = F_391 ( V_289 ) ;
if ( F_20 ( V_10 ) )
F_386 ( V_10 ) ;
F_66 ( V_10 ) ;
if ( ( ! V_929 ) && V_10 -> V_934 )
F_303 ( V_10 -> V_934 ) ;
F_394 ( V_10 ) ;
F_397 ( V_10 ) ;
F_358 ( V_10 ) ;
F_383 ( V_10 -> V_275 ) ;
F_263 ( V_10 ) ;
F_288 ( V_10 -> V_275 ) ;
F_384 ( V_289 ) ;
F_385 ( V_289 ) ;
F_372 ( V_289 , NULL ) ;
}
static void F_367 ( struct V_9 * V_10 )
{
int V_1105 ;
if ( F_398 ( V_10 -> V_289 , F_399 ( 64 ) ) == 0 ) {
if ( F_400 ( V_10 -> V_289 , F_399 ( 64 ) ) ) {
F_401 ( & V_10 -> V_289 -> V_221 ,
L_249
L_250 ) ;
V_1105 = F_400 ( V_10 -> V_289 ,
F_399 ( 32 ) ) ;
}
} else
V_1105 = F_398 ( V_10 -> V_289 , F_399 ( 32 ) ) ;
}
static int F_402 ( struct V_1106 * V_1107 )
{
struct V_223 * V_285 ;
struct V_225 * V_226 ;
struct V_227 * V_666 ;
int V_1108 = V_1109 ;
V_285 = F_48 ( V_1107 -> V_1110 ) ;
V_226 = V_285 -> V_229 ;
V_666 = V_226 -> V_229 ;
V_1107 -> V_671 = V_666 ;
V_1107 -> V_1111 = 1 ;
if ( V_1112 != 0 && V_1112 <= 0xffffU )
V_1108 = V_1112 ;
F_403 ( V_1107 , V_1108 ) ;
return 0 ;
}
static int F_404 ( struct V_1106 * V_1107 )
{
V_1107 -> V_1111 = 1 ;
return 0 ;
}
static void F_405 ( struct V_1106 * V_1107 )
{
F_406 ( V_1107 , 1 ) ;
}
static int F_407 ( struct V_1106 * V_1107 , int V_459 ,
int V_1113 )
{
if ( ! V_1114 )
return - V_1115 ;
return F_408 ( V_1107 , V_459 , V_1113 ) ;
}
struct V_662 * F_210 ( struct V_9 * V_10 ,
T_1 V_772 )
{
struct V_662 * V_662 = NULL ;
struct V_332 * V_663 = NULL ;
V_663 = F_200 ( V_10 -> V_275 , V_772 ) ;
if ( ! V_663 )
return V_662 ;
V_662 = (struct V_662 * ) F_153 ( V_663 ) ;
if ( ! V_662 )
return V_662 ;
if ( V_662 -> V_214 & V_667 ) {
V_10 -> V_1116 -= V_662 -> V_1116 ;
if ( V_662 -> V_663 )
V_662 -> V_663 -> V_1117 =
( unsigned char * ) ( unsigned long ) V_1081 ;
}
return V_662 ;
}
static int F_409 ( struct V_9 * V_10 ,
struct V_332 * V_663 )
{
int V_1118 = 0 ;
struct V_662 * V_1119 ;
T_1 V_778 = V_1120 ;
int V_195 = V_1121 ;
if ( F_410 ( F_195 ( V_10 -> V_289 ) ) ||
( F_34 ( V_672 , & V_10 -> V_214 ) ) ) {
F_4 ( V_38 , V_10 , L_251 ,
V_10 -> V_650 , V_26 ) ;
return V_195 ;
}
do {
V_1119 = (struct V_662 * ) F_153 ( V_663 ) ;
if ( V_1119 == NULL ) {
V_1118 ++ ;
break;
}
F_201 ( 2000 ) ;
} while ( V_778 -- );
return V_1118 ;
}
static int F_411 ( struct V_9 * V_10 )
{
unsigned long V_1122 ;
V_1122 = V_477 + ( V_1123 * V_421 ) ;
while ( F_220 ( V_477 , V_1122 ) ) {
if ( F_33 ( V_10 ) )
return V_41 ;
F_201 ( 2000 ) ;
}
return V_436 ;
}
static int F_412 ( struct V_9 * V_10 ,
struct F_49 * V_1124 ,
struct V_1106 * V_1107 )
{
int V_1125 ;
int V_444 = 0 ;
struct V_332 * V_663 ;
for ( V_1125 = 0 ; V_1125 < V_10 -> V_275 -> V_774 ; V_1125 ++ ) {
V_663 = F_200 ( V_10 -> V_275 , V_1125 ) ;
if ( V_663 && V_1124 == F_49 ( V_663 -> V_220 ) &&
( ! V_1107 || V_1107 == V_663 -> V_220 ) ) {
if ( ! F_409 ( V_10 , V_663 ) ) {
V_444 ++ ;
break;
}
}
}
return V_444 ;
}
static int F_413 ( struct V_332 * V_663 )
{
struct V_9 * V_10 = F_2 ( V_663 -> V_220 -> V_275 ) ;
unsigned int V_1126 = V_663 -> V_220 -> V_1126 ;
unsigned int V_1127 = V_663 -> V_220 -> V_1127 ;
unsigned long V_214 ;
struct V_662 * V_662 = NULL ;
int V_195 = V_1121 ;
int V_787 = 0 ;
F_4 ( V_25 , V_10 ,
L_252 ,
V_10 -> V_650 , V_1126 , V_1127 , V_663 ) ;
F_50 ( & V_10 -> V_480 , V_214 ) ;
V_662 = (struct V_662 * ) F_153 ( V_663 ) ;
if ( ! V_662 ) {
F_51 ( & V_10 -> V_480 , V_214 ) ;
return V_1121 ;
}
F_414 ( & V_662 -> V_665 ) ;
F_51 ( & V_10 -> V_480 , V_214 ) ;
if ( F_415 ( V_10 , V_662 ) != V_41 ) {
F_116 ( F_28 ( L_253 ,
V_10 -> V_650 , V_1126 , V_1127 ) ) ;
V_195 = V_1128 ;
} else {
F_116 ( F_28 ( L_254 ,
V_10 -> V_650 , V_1126 , V_1127 ) ) ;
V_787 = 1 ;
}
F_211 ( & V_662 -> V_665 , F_156 ) ;
if ( V_787 ) {
if ( ! F_409 ( V_10 , V_663 ) ) {
F_3 ( F_28 ( L_255 ,
V_10 -> V_650 , V_1126 , V_1127 ) ) ;
V_195 = V_1128 ;
}
}
F_4 ( V_25 , V_10 ,
L_256 ,
V_10 -> V_650 , V_1126 , V_1127 , ( V_195 == V_1121 ) ? L_257 : L_258 ) ;
return V_195 ;
}
static int F_416 ( struct V_332 * V_663 )
{
struct V_9 * V_10 = F_2 ( V_663 -> V_220 -> V_275 ) ;
struct V_227 * V_227 = V_663 -> V_220 -> V_671 ;
int V_195 = V_1128 , V_1129 ;
if ( ! V_227 )
return V_195 ;
V_195 = F_417 ( V_663 ) ;
if ( V_195 )
return V_195 ;
V_195 = V_1128 ;
F_4 ( V_25 , V_10 ,
L_259 , V_10 -> V_650 ,
V_663 -> V_220 -> V_1130 , V_663 -> V_220 -> V_1126 , V_663 -> V_220 -> V_1127 ) ;
F_3 ( F_28 ( V_25
L_260
L_261 , V_10 -> V_650 ,
V_663 , V_477 , V_663 -> V_1131 -> V_1132 / V_421 ,
V_10 -> V_680 , V_663 -> V_674 , V_663 -> V_1133 ) ) ;
V_1129 = F_418 ( V_10 , V_227 , V_663 -> V_220 -> V_1127 ) ;
if ( V_1129 != V_41 ) {
F_4 ( V_25 , V_10 , L_262 , V_1129 ) ;
goto V_1134;
}
if ( F_412 ( V_10 , F_49 ( V_663 -> V_220 ) ,
V_663 -> V_220 ) ) {
F_4 ( V_25 , V_10 ,
L_263
L_264 ) ;
goto V_1134;
}
if ( F_419 ( V_10 , V_227 , V_663 -> V_220 -> V_1127 ,
V_1135 ) != V_41 )
goto V_1134;
F_4 ( V_25 , V_10 ,
L_265 ,
V_10 -> V_650 , V_663 -> V_220 -> V_1130 , V_663 -> V_220 -> V_1126 ,
V_663 -> V_220 -> V_1127 ) ;
V_195 = V_1121 ;
V_1134:
return V_195 ;
}
static int F_420 ( struct V_332 * V_663 )
{
struct V_9 * V_10 = F_2 ( V_663 -> V_220 -> V_275 ) ;
struct V_227 * V_227 = V_663 -> V_220 -> V_671 ;
int V_1129 , V_195 ;
if ( ! V_227 )
return V_1128 ;
V_195 = F_417 ( V_663 ) ;
if ( V_195 )
return V_195 ;
F_421 ( V_25 , F_49 ( V_663 -> V_220 ) ,
L_266 ) ;
F_3 ( F_28 ( V_25
L_267
L_268 ,
V_10 -> V_650 , V_663 , V_477 , V_663 -> V_1131 -> V_1132 / V_421 ,
V_10 -> V_680 , V_663 -> V_674 , V_663 -> V_1133 ) ) ;
V_1129 = F_422 ( V_10 , V_227 ) ;
if ( V_1129 != V_41 ) {
F_421 ( V_25 , F_49 ( V_663 -> V_220 ) ,
L_269 ) ;
return V_1128 ;
}
if ( F_412 ( V_10 , F_49 ( V_663 -> V_220 ) ,
NULL ) ) {
F_421 ( V_25 , F_49 ( V_663 -> V_220 ) ,
L_270
L_271 ) ;
return V_1128 ;
}
if ( F_419 ( V_10 , V_227 , V_663 -> V_220 -> V_1127 ,
V_1136 ) != V_41 ) {
F_421 ( V_25 , F_49 ( V_663 -> V_220 ) ,
L_270
L_272 ) ;
return V_1128 ;
}
F_421 ( V_25 , F_49 ( V_663 -> V_220 ) ,
L_273 ) ;
return V_1121 ;
}
static int F_423 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1137 == V_1138 )
return 1 ;
return 0 ;
}
static int F_424 ( struct V_332 * V_663 )
{
int V_1139 = V_1128 ;
struct V_9 * V_10 ;
V_10 = F_2 ( V_663 -> V_220 -> V_275 ) ;
if ( ( F_166 ( V_10 ) || F_167 ( V_10 ) ) && V_753 )
F_376 ( V_10 ) ;
if ( V_753 ||
( ( F_166 ( V_10 ) || F_167 ( V_10 ) ) &&
F_260 ( V_10 ) ) ) {
F_3 ( F_28 ( L_148 ,
V_10 -> V_650 , V_26 ) ) ;
if ( F_423 ( V_663 -> V_220 -> V_275 ) )
F_209 ( V_10 , V_1140 << 16 ) ;
return V_1128 ;
}
F_4 ( V_25 , V_10 ,
L_274 , V_10 -> V_650 ,
V_663 -> V_220 -> V_1130 , V_663 -> V_220 -> V_1126 , V_663 -> V_220 -> V_1127 ) ;
if ( F_411 ( V_10 ) != V_41 ) {
F_3 ( F_28 ( L_275
L_276 , V_10 -> V_650 , V_663 -> V_220 -> V_1130 ,
V_26 ) ) ;
return V_1128 ;
}
if ( ! F_34 ( V_682 , & V_10 -> V_680 ) ) {
if ( F_8 ( V_10 ) )
F_181 ( V_689 , & V_10 -> V_680 ) ;
else
F_181 ( V_682 , & V_10 -> V_680 ) ;
}
if ( F_216 ( V_10 ) == V_41 )
V_1139 = V_1121 ;
F_4 ( V_25 , V_10 , L_277 ,
V_1139 == V_1128 ? L_129 : L_130 ) ;
return V_1139 ;
}
static int F_425 ( struct V_9 * V_10 )
{
T_1 V_410 [ V_411 ] ;
T_1 V_412 [ V_411 ] ;
struct V_392 * V_393 = NULL ;
T_1 V_1141 = sizeof( struct V_392 ) ;
int V_18 = V_41 ;
T_5 V_1142 ;
V_393 = F_42 ( & V_10 -> V_289 -> V_221 ,
sizeof( struct V_392 ) ,
& V_1142 , V_235 ) ;
if ( ! V_393 ) {
F_4 ( V_242 , V_10 , L_278 ,
V_26 ) ;
V_18 = - V_200 ;
goto V_1143;
}
memset ( V_393 , 0 , V_1141 ) ;
V_18 = F_426 ( V_10 , V_1142 , V_1144 , V_1141 ) ;
if ( V_18 != V_41 ) {
V_18 = - V_416 ;
goto V_1145;
}
V_18 = F_77 ( V_10 ) ;
if ( V_18 != V_41 ) {
V_18 = - V_416 ;
goto V_1145;
}
F_78 ( & V_10 -> V_419 ,
V_420 * V_421 ) ;
V_18 = F_79 ( V_10 , & V_410 [ 0 ] , & V_412 [ 0 ] , V_1142 ) ;
if ( V_18 != V_41 ) {
V_18 = - V_416 ;
goto V_1145;
}
V_1145:
F_46 ( & V_10 -> V_289 -> V_221 , sizeof( struct V_392 ) ,
V_393 , V_1142 ) ;
V_1143:
F_3 ( F_4 ( V_25 , V_10 , L_279 , V_26 ,
V_18 == V_41 ? L_130 : L_129 ) ) ;
return V_18 ;
}
static int F_427 ( struct V_1 * V_2 , int V_1146 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_18 = V_41 ;
T_1 V_747 ;
if ( V_753 ) {
F_3 ( F_4 ( V_25 , V_10 , L_280 ,
V_26 ) ) ;
V_18 = - V_1018 ;
goto V_1147;
}
if ( F_34 ( V_682 , & V_10 -> V_680 ) )
goto V_1148;
switch ( V_1146 ) {
case V_1149 :
F_181 ( V_682 , & V_10 -> V_680 ) ;
break;
case V_1150 :
if ( ! F_34 ( V_682 , & V_10 -> V_680 ) ) {
if ( F_8 ( V_10 ) )
F_181 ( V_689 ,
& V_10 -> V_680 ) ;
else {
V_18 = F_425 ( V_10 ) ;
goto V_1147;
}
}
break;
}
V_1148:
if ( ( F_166 ( V_10 ) || F_167 ( V_10 ) ) &&
F_34 ( V_682 , & V_10 -> V_680 ) ) {
V_747 = F_185 ( V_10 , V_751 ) ;
F_428 ( V_10 , V_751 ,
( V_747 | V_752 ) ) ;
}
V_18 = F_216 ( V_10 ) ;
if ( V_18 != V_41 ) {
F_3 ( F_4 ( V_25 , V_10 , L_281 ,
V_26 ) ) ;
V_18 = - V_416 ;
}
V_1147:
return V_18 ;
}
static T_10
F_429 ( struct V_851 * V_289 , T_11 V_337 )
{
struct V_9 * V_10 = F_391 ( V_289 ) ;
F_4 ( V_38 , V_10 , L_282 ,
V_10 -> V_650 , V_26 , V_337 ) ;
if ( ! F_430 ( V_10 ) )
return V_1151 ;
switch ( V_337 ) {
case V_1152 :
F_213 ( V_672 , & V_10 -> V_214 ) ;
return V_1153 ;
case V_1154 :
F_181 ( V_672 , & V_10 -> V_214 ) ;
F_182 ( V_10 ) ;
F_266 ( V_10 ) ;
F_385 ( V_289 ) ;
F_209 ( V_10 , V_794 << 16 ) ;
return V_1155 ;
case V_1156 :
F_181 ( V_672 , & V_10 -> V_214 ) ;
F_181 ( V_673 , & V_10 -> V_214 ) ;
F_209 ( V_10 , V_675 << 16 ) ;
return V_1157 ;
}
return V_1155 ;
}
static T_10
F_431 ( struct V_851 * V_289 )
{
struct V_9 * V_10 = F_391 ( V_289 ) ;
if ( ! F_430 ( V_10 ) )
return V_1151 ;
return V_1158 ;
}
static T_1 F_432 ( struct V_9 * V_10 )
{
T_1 V_18 = V_436 ;
int V_1098 ;
struct V_851 * V_1097 = NULL ;
F_4 ( V_38 , V_10 , L_283 , V_10 -> V_650 , V_26 ) ;
F_181 ( V_681 , & V_10 -> V_680 ) ;
if ( F_34 ( V_685 , & V_10 -> V_214 ) ) {
F_213 ( V_685 , & V_10 -> V_214 ) ;
F_213 ( V_356 , & V_10 -> V_214 ) ;
F_149 ( V_10 -> V_275 , F_214 ) ;
F_219 ( V_10 , V_793 ) ;
}
V_1098 = F_290 ( V_10 -> V_289 -> V_856 ) ;
while ( V_1098 > 0 ) {
V_1098 -- ;
F_4 ( V_25 , V_10 , L_284
L_285 , V_10 -> V_650 , V_26 , V_1098 ) ;
V_1097 =
F_387 ( F_388 ( V_10 -> V_289 -> V_1101 ) ,
V_10 -> V_289 -> V_1101 -> V_1102 , F_389 ( F_390 ( V_10 -> V_289 -> V_856 ) ,
V_1098 ) ) ;
if ( ! V_1097 )
continue;
if ( F_188 ( & V_1097 -> V_1103 ) ) {
F_4 ( V_25 , V_10 , L_286
L_287 , V_10 -> V_650 ,
V_26 , V_1098 ) ;
F_393 ( V_1097 ) ;
break;
}
F_393 ( V_1097 ) ;
}
if ( ! V_1098 ) {
F_4 ( V_25 , V_10 , L_288
L_289 , V_10 -> V_650 , V_26 ,
V_10 -> V_289 -> V_856 ) ;
V_10 -> V_789 -> V_800 ( V_10 ) ;
F_255 ( V_10 , V_749 ,
V_1159 ) ;
V_10 -> V_789 -> V_801 ( V_10 ) ;
V_18 = F_433 ( V_10 ) ;
if ( V_18 == V_436 ) {
F_4 ( V_25 , V_10 , L_290 ,
V_10 -> V_650 , V_26 ) ;
V_10 -> V_789 -> V_800 ( V_10 ) ;
F_255 ( V_10 , V_749 ,
V_802 ) ;
V_10 -> V_789 -> V_801 ( V_10 ) ;
goto V_1160;
}
F_213 ( V_791 , & V_10 -> V_214 ) ;
V_18 = F_224 ( V_10 , V_799 ) ;
if ( V_18 != V_41 ) {
F_4 ( V_25 , V_10 , L_291
L_292 , V_10 -> V_650 , V_26 ) ;
V_10 -> V_789 -> V_800 ( V_10 ) ;
F_265 ( V_10 ) ;
F_255 ( V_10 , V_749 ,
V_802 ) ;
V_10 -> V_789 -> V_801 ( V_10 ) ;
} else {
F_4 ( V_25 , V_10 , L_291
L_293 , V_10 -> V_650 , V_26 ) ;
V_10 -> V_789 -> V_800 ( V_10 ) ;
F_255 ( V_10 , V_749 ,
V_1161 ) ;
F_255 ( V_10 , V_1162 , 0 ) ;
F_434 ( V_10 ) ;
V_10 -> V_789 -> V_801 ( V_10 ) ;
V_10 -> V_789 -> V_807 ( V_10 ) ;
}
} else {
F_4 ( V_25 , V_10 , L_294
L_295 , V_10 -> V_650 , V_26 ,
V_10 -> V_289 -> V_856 ) ;
if ( ( F_173 ( V_10 , V_749 ) ==
V_1161 ) ) {
F_213 ( V_791 , & V_10 -> V_214 ) ;
V_18 = F_224 ( V_10 , V_799 ) ;
if ( V_18 == V_41 )
V_10 -> V_789 -> V_807 ( V_10 ) ;
V_10 -> V_789 -> V_800 ( V_10 ) ;
F_434 ( V_10 ) ;
V_10 -> V_789 -> V_801 ( V_10 ) ;
}
}
V_1160:
F_213 ( V_681 , & V_10 -> V_680 ) ;
return V_18 ;
}
static T_10
F_435 ( struct V_851 * V_289 )
{
T_10 V_195 = V_1157 ;
struct V_9 * V_10 = F_391 ( V_289 ) ;
int V_521 ;
F_4 ( V_38 , V_10 , L_296 ,
V_10 -> V_650 , V_26 ) ;
if ( ! F_430 ( V_10 ) )
return V_1151 ;
F_436 ( V_289 ) ;
F_380 ( V_289 ) ;
V_521 = F_363 ( V_289 ) ;
if ( V_521 ) {
F_4 ( V_38 , V_10 , L_297
L_298 , V_10 -> V_650 , V_26 ) ;
goto V_1163;
}
V_10 -> V_789 -> V_792 ( V_10 ) ;
if ( F_8 ( V_10 ) ) {
if ( F_432 ( V_10 ) == V_41 ) {
V_195 = V_1158 ;
goto V_1163;
} else
goto V_1163;
}
V_1163:
F_4 ( V_38 , V_10 , L_299
L_298 , V_10 -> V_650 , V_26 , V_195 ) ;
return V_195 ;
}
static void
F_437 ( struct V_851 * V_289 )
{
struct V_9 * V_10 = F_391 ( V_289 ) ;
int V_195 ;
F_4 ( V_38 , V_10 , L_300 ,
V_10 -> V_650 , V_26 ) ;
V_195 = F_411 ( V_10 ) ;
if ( V_195 != V_41 ) {
F_4 ( V_242 , V_10 , L_301
L_302 , V_10 -> V_650 ,
V_26 ) ;
}
F_438 ( V_289 ) ;
F_213 ( V_672 , & V_10 -> V_214 ) ;
}
static int T_12 F_439 ( void )
{
int V_195 ;
V_723 = F_440 ( L_303 , sizeof( struct V_662 ) , 0 ,
V_1164 , NULL ) ;
if ( V_723 == NULL ) {
F_28 ( V_242
L_304
L_305 , V_852 ) ;
V_195 = - V_200 ;
goto V_1165;
}
strcpy ( V_1089 , V_1166 ) ;
if ( V_1167 )
strcat ( V_1089 , L_306 ) ;
V_1083 =
F_441 ( & V_364 ) ;
if ( ! V_1083 ) {
V_195 = - V_1043 ;
goto V_1168;
}
V_195 = F_442 ( & V_1169 ) ;
if ( V_195 )
goto V_1170;
F_28 ( V_25 L_307 ) ;
return 0 ;
V_1170:
F_443 ( & V_364 ) ;
V_1168:
F_444 ( V_723 ) ;
V_1165:
return V_195 ;
}
static void T_13 F_445 ( void )
{
F_446 ( & V_1169 ) ;
F_443 ( & V_364 ) ;
F_444 ( V_723 ) ;
}
