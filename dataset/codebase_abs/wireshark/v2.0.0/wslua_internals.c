T_1 int F_1 ( T_2 * V_1 ) {
if ( ! F_2 ( V_1 , 1 , L_1 ) )
F_3 ( V_1 , 1 ) ;
if ( ! F_2 ( V_1 , 2 , L_1 ) )
F_3 ( V_1 , 2 ) ;
F_4 ( V_1 , 2 ) ;
return 1 ;
}
T_1 T_3 F_5 ( T_2 * V_1 , int V_2 ) {
T_3 V_3 = FALSE ;
if ( F_6 ( V_1 , V_2 ) || F_7 ( V_1 , V_2 ) || F_8 ( V_1 ) < V_2 ) {
V_3 = F_9 ( V_1 , V_2 ) ;
} else if ( F_10 ( V_1 , V_2 ) == V_4 ) {
int V_5 = ( int ) F_11 ( V_1 , V_2 ) ;
V_3 = V_5 != 0 ? TRUE : FALSE ;
} else {
F_12 ( V_1 , V_2 , L_2 ) ;
}
return V_3 ;
}
T_1 T_3 F_13 ( T_2 * V_1 , int V_2 ) {
if ( ! F_6 ( V_1 , V_2 ) ) {
F_12 ( V_1 , V_2 , L_3 ) ;
}
return F_9 ( V_1 , V_2 ) ; ;
}
T_1 T_3 F_14 ( T_2 * V_1 , int V_2 , T_3 V_6 ) {
T_3 V_3 = FALSE ;
if ( F_6 ( V_1 , V_2 ) ) {
V_3 = F_9 ( V_1 , V_2 ) ;
} else if ( F_7 ( V_1 , V_2 ) || F_8 ( V_1 ) < V_2 ) {
V_3 = V_6 ;
} else {
F_12 ( V_1 , V_2 , L_3 ) ;
}
return V_3 ;
}
T_1 T_4 F_15 ( T_2 * V_1 , int V_2 ) {
T_4 V_3 = 0 ;
if ( F_10 ( V_1 , V_2 ) == V_4 ) {
V_3 = F_16 ( V_1 , V_2 ) ;
} else if ( F_6 ( V_1 , V_2 ) ) {
V_3 = ( T_4 ) ( F_9 ( V_1 , V_2 ) ) ;
} else if ( F_7 ( V_1 , V_2 ) ) {
V_3 = 0 ;
} else {
F_12 ( V_1 , V_2 , L_4 ) ;
}
return V_3 ;
}
T_1 int F_17 ( T_2 * V_1 , int V_2 , int V_6 ) {
int V_3 = 0 ;
if ( F_18 ( V_1 , V_2 ) ) {
V_3 = ( int ) F_16 ( V_1 , V_2 ) ;
} else if ( F_6 ( V_1 , V_2 ) ) {
V_3 = F_9 ( V_1 , V_2 ) ? 1 : 0 ;
} else if ( F_7 ( V_1 , V_2 ) || F_8 ( V_1 ) < V_2 ) {
V_3 = V_6 ;
} else {
F_12 ( V_1 , V_2 , L_5 ) ;
}
return V_3 ;
}
T_1 const char * F_19 ( T_2 * V_1 , int V_2 , T_5 * V_7 ) {
if ( F_10 ( V_1 , V_2 ) != V_8 ) {
F_12 ( V_1 , V_2 , L_6 ) ;
}
return F_20 ( V_1 , V_2 , V_7 ) ;
}
T_1 const char * F_21 ( T_2 * V_1 , int V_2 ) {
return F_19 ( V_1 , V_2 , NULL ) ;
}
T_1 const T_6 * F_22 ( T_2 * V_1 , int V_9 ) {
const T_6 * V_10 = F_23 ( V_1 , V_9 ) ;
if ( V_10 ) {
F_24 ( V_1 , V_9 ) ;
return V_10 ;
} else {
return NULL ;
}
}
T_1 void F_25 ( T_2 * V_1 , const T_7 * V_7 , int V_11 ) {
F_26 ( V_1 , V_11 , L_7 ) ;
for (; V_7 -> V_12 != NULL ; V_7 ++ ) {
int V_9 ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ )
F_3 ( V_1 , - V_11 ) ;
F_27 ( V_1 , V_7 -> V_13 , V_11 ) ;
F_28 ( V_1 , - ( V_11 + 2 ) , V_7 -> V_12 ) ;
}
F_29 ( V_1 , V_11 ) ;
}
static void F_30 ( T_2 * V_1 , int V_14 , const char * V_15 ) {
F_31 ( V_1 , V_15 ) ;
F_32 ( V_1 , V_14 ) ;
}
static void F_33 ( T_2 * V_1 , int V_14 , const char * V_15 ) {
F_31 ( V_1 , V_15 ) ;
F_34 ( V_1 , - 2 ) ;
F_35 ( V_1 , V_14 ) ;
}
T_1 void F_36 ( char * V_16 , T_2 * V_1 ) {
int V_9 ;
for ( V_9 = 1 ; V_9 <= F_8 ( V_1 ) ; V_9 ++ ) {
printf ( L_8 , V_16 , V_9 , F_37 ( V_1 , F_10 ( V_1 , V_9 ) ) ) ;
}
printf ( L_9 ) ;
}
const T_6 * F_38 ( T_2 * V_1 , int V_14 ) {
const T_6 * V_17 = V_18 ;
if ( F_39 ( V_1 , V_14 , V_19 ) ) {
V_17 = F_40 ( V_1 , - 1 , V_18 ) ;
F_29 ( V_1 , 1 ) ;
}
else if ( F_10 ( V_1 , V_14 ) == V_20 ) {
F_30 ( V_1 , V_14 , V_19 ) ;
V_17 = F_40 ( V_1 , - 1 , V_18 ) ;
F_29 ( V_1 , 1 ) ;
}
return V_17 ;
}
T_3 F_41 ( T_2 * V_1 , int V_14 , const T_6 * V_12 ) {
T_3 V_21 = TRUE ;
if ( V_14 < 0 ) V_14 -- ;
F_30 ( V_1 , V_14 , V_12 ) ;
if ( ! F_42 ( V_1 , - 1 ) ) {
F_29 ( V_1 , 1 ) ;
V_21 = FALSE ;
}
return V_21 ;
}
T_3 F_43 ( T_2 * V_1 , int V_14 , const T_6 * V_12 ) {
T_3 V_21 = TRUE ;
if ( V_14 < 0 ) V_14 -- ;
F_30 ( V_1 , V_14 , V_12 ) ;
if ( F_7 ( V_1 , - 1 ) ) {
F_29 ( V_1 , 1 ) ;
V_21 = FALSE ;
}
return V_21 ;
}
void F_44 ( T_2 * V_1 , int V_14 , const T_6 * V_12 ) {
F_30 ( V_1 , V_14 , V_12 ) ;
if ( ! F_7 ( V_1 , - 1 ) ) {
fprintf ( V_22 , L_10 , V_12 ) ;
exit ( 1 ) ;
}
F_29 ( V_1 , 1 ) ; \
}
static int F_45 ( T_2 * V_1 ) {
T_8 V_23 = NULL ;
const T_6 * V_24 = F_22 ( V_1 , 2 ) ;
const T_6 * V_17 = NULL ;
const T_6 * type = NULL ;
if ( ! F_42 ( V_1 , F_46 ( 1 ) ) )
return F_47 ( V_1 , L_11 ) ;
F_30 ( V_1 , F_46 ( 1 ) , V_24 ) ;
if ( ! F_48 ( V_1 , - 1 ) ) {
F_29 ( V_1 , 1 ) ;
if ( F_42 ( V_1 , F_46 ( 2 ) ) ) {
F_30 ( V_1 , F_46 ( 2 ) , V_24 ) ;
if ( F_48 ( V_1 , - 1 ) ) {
return 1 ;
}
F_29 ( V_1 , 1 ) ;
}
V_17 = F_38 ( V_1 , 1 ) ;
type = F_38 ( V_1 , F_46 ( 1 ) ) ;
F_29 ( V_1 , 1 ) ;
return F_47 ( V_1 , L_12 , V_24 , type , V_17 ) ;
}
V_23 = F_49 ( V_1 , - 1 ) ;
F_29 ( V_1 , 1 ) ;
return (* V_23)( V_1 ) ;
}
int F_50 ( T_2 * V_1 , const T_9 * V_25 , T_3 V_26 ) {
int V_27 = F_8 ( V_1 ) ;
const T_6 * V_28 = V_26 ? L_13 : L_14 ;
int V_14 ;
int V_11 = 1 ;
if ( ! F_42 ( V_1 , V_27 ) ) {
fprintf ( V_22 , L_15 ) ;
exit ( 1 ) ;
}
F_30 ( V_1 , V_27 , V_28 ) ;
if ( F_7 ( V_1 , - 1 ) ) {
F_29 ( V_1 , 1 ) ;
}
else if ( F_42 ( V_1 , - 1 ) ) {
V_11 = 2 ;
}
else if ( F_48 ( V_1 , - 1 ) ) {
F_29 ( V_1 , 1 ) ;
F_30 ( V_1 , V_27 , L_16 ) ;
if ( ! F_42 ( V_1 , - 1 ) ) {
fprintf ( V_22 , L_17 ) ;
exit ( 1 ) ;
}
V_11 = 2 ;
}
else {
fprintf ( V_22 , L_18 , V_28 ) ;
exit ( 1 ) ;
}
F_51 ( V_1 ) ;
V_14 = F_8 ( V_1 ) ;
for (; V_25 -> V_24 != NULL ; V_25 ++ ) {
T_8 V_23 = V_26 ? V_25 -> V_29 : V_25 -> V_30 ;
if ( V_23 ) {
if ( V_11 > 1 ) {
F_30 ( V_1 , - 2 , V_25 -> V_24 ) ;
if ( ! F_7 ( V_1 , - 1 ) ) {
fprintf ( V_22 , L_19 , V_25 -> V_24 ) ;
exit ( 1 ) ;
}
F_29 ( V_1 , 1 ) ;
}
F_52 ( V_1 , V_23 ) ;
F_33 ( V_1 , V_14 , V_25 -> V_24 ) ;
}
}
F_31 ( V_1 , ( V_26 ? L_20 : L_21 ) ) ;
F_33 ( V_1 , V_14 , V_19 ) ;
F_3 ( V_1 , V_14 ) ;
F_33 ( V_1 , V_27 , ( V_26 ? L_22 : L_23 ) ) ;
if ( V_11 > 1 ) {
F_34 ( V_1 , - V_11 ) ;
}
F_27 ( V_1 , F_45 , V_11 ) ;
F_33 ( V_1 , V_27 , V_28 ) ;
return 0 ;
}
static int F_53 ( T_2 * V_1 ) {
const T_6 * V_24 = F_22 ( V_1 , 2 ) ;
if ( ! F_54 ( V_1 , 1 ) ) {
return F_47 ( V_1 , L_24 , V_24 ) ;
}
F_30 ( V_1 , 2 , L_16 ) ;
F_24 ( V_1 , 2 ) ;
if ( ! F_42 ( V_1 , - 1 ) ) {
const T_6 * V_17 = F_38 ( V_1 , 1 ) ;
F_29 ( V_1 , 1 ) ;
return F_47 ( V_1 , L_25 , V_24 , V_17 ) ;
}
F_30 ( V_1 , 2 , V_24 ) ;
F_24 ( V_1 , 2 ) ;
if ( F_7 ( V_1 , - 1 ) ) {
const T_6 * V_17 = F_38 ( V_1 , 1 ) ;
F_29 ( V_1 , 1 ) ;
return F_47 ( V_1 , L_26 , V_24 , V_17 ) ;
}
return 1 ;
}
int F_55 ( T_2 * V_1 ) {
if ( ! F_42 ( V_1 , 2 ) || ! F_42 ( V_1 , 1 ) ) {
fprintf ( V_22 , L_27 ) ;
exit ( 1 ) ;
}
F_3 ( V_1 , 1 ) ;
F_33 ( V_1 , 2 , L_16 ) ;
F_52 ( V_1 , F_53 ) ;
F_33 ( V_1 , 2 , L_13 ) ;
return 0 ;
}
int F_56 ( T_2 * V_1 , const T_10 * V_31 , const T_11 V_32 , const T_3 V_33 , const T_6 * V_34 ) {
T_12 V_35 ;
T_11 V_9 = 0 ;
static const char V_36 [ 256 ] [ 3 ] = {
L_28 , L_29 , L_30 , L_31 , L_32 , L_33 , L_34 , L_35 , L_36 , L_37 , L_38 , L_39 , L_40 , L_41 , L_42 , L_43 ,
L_44 , L_45 , L_46 , L_47 , L_48 , L_49 , L_50 , L_51 , L_52 , L_53 , L_54 , L_55 , L_56 , L_57 , L_58 , L_59 ,
L_60 , L_61 , L_62 , L_63 , L_64 , L_65 , L_66 , L_67 , L_68 , L_69 , L_70 , L_71 , L_72 , L_73 , L_74 , L_75 ,
L_76 , L_77 , L_78 , L_79 , L_80 , L_81 , L_82 , L_83 , L_84 , L_85 , L_86 , L_87 , L_88 , L_89 , L_90 , L_91 ,
L_92 , L_93 , L_94 , L_95 , L_96 , L_97 , L_98 , L_99 , L_100 , L_101 , L_102 , L_103 , L_104 , L_105 , L_106 , L_107 ,
L_108 , L_109 , L_110 , L_111 , L_112 , L_113 , L_114 , L_115 , L_116 , L_117 , L_118 , L_119 , L_120 , L_121 , L_122 , L_123 ,
L_124 , L_125 , L_126 , L_127 , L_128 , L_129 , L_130 , L_131 , L_132 , L_133 , L_134 , L_135 , L_136 , L_137 , L_138 , L_139 ,
L_140 , L_141 , L_142 , L_143 , L_144 , L_145 , L_146 , L_147 , L_148 , L_149 , L_150 , L_151 , L_152 , L_153 , L_154 , L_155 ,
L_156 , L_157 , L_158 , L_159 , L_160 , L_161 , L_162 , L_163 , L_164 , L_165 , L_166 , L_167 , L_168 , L_169 , L_170 , L_171 ,
L_172 , L_173 , L_174 , L_175 , L_176 , L_177 , L_178 , L_179 , L_180 , L_181 , L_182 , L_183 , L_184 , L_185 , L_186 , L_187 ,
L_188 , L_189 , L_190 , L_191 , L_192 , L_193 , L_194 , L_195 , L_196 , L_197 , L_198 , L_199 , L_200 , L_201 , L_202 , L_203 ,
L_204 , L_205 , L_206 , L_207 , L_208 , L_209 , L_210 , L_211 , L_212 , L_213 , L_214 , L_215 , L_216 , L_217 , L_218 , L_219 ,
L_220 , L_221 , L_222 , L_223 , L_224 , L_225 , L_226 , L_227 , L_228 , L_229 , L_230 , L_231 , L_232 , L_233 , L_234 , L_235 ,
L_236 , L_237 , L_238 , L_239 , L_240 , L_241 , L_242 , L_243 , L_244 , L_245 , L_246 , L_247 , L_248 , L_249 , L_250 , L_251 ,
L_252 , L_253 , L_254 , L_255 , L_256 , L_257 , L_258 , L_259 , L_260 , L_261 , L_262 , L_263 , L_264 , L_265 , L_266 , L_267 ,
L_268 , L_269 , L_270 , L_271 , L_272 , L_273 , L_274 , L_275 , L_276 , L_277 , L_278 , L_279 , L_280 , L_281 , L_282 , L_283
} ;
static const char V_37 [ 256 ] [ 3 ] = {
L_28 , L_29 , L_30 , L_31 , L_32 , L_33 , L_34 , L_35 , L_36 , L_37 , L_284 , L_285 , L_286 , L_287 , L_288 , L_289 ,
L_44 , L_45 , L_46 , L_47 , L_48 , L_49 , L_50 , L_51 , L_52 , L_53 , L_290 , L_291 , L_292 , L_293 , L_294 , L_295 ,
L_60 , L_61 , L_62 , L_63 , L_64 , L_65 , L_66 , L_67 , L_68 , L_69 , L_296 , L_297 , L_298 , L_299 , L_300 , L_301 ,
L_76 , L_77 , L_78 , L_79 , L_80 , L_81 , L_82 , L_83 , L_84 , L_85 , L_302 , L_303 , L_304 , L_305 , L_306 , L_307 ,
L_92 , L_93 , L_94 , L_95 , L_96 , L_97 , L_98 , L_99 , L_100 , L_101 , L_308 , L_309 , L_310 , L_311 , L_312 , L_313 ,
L_108 , L_109 , L_110 , L_111 , L_112 , L_113 , L_114 , L_115 , L_116 , L_117 , L_314 , L_315 , L_316 , L_317 , L_318 , L_319 ,
L_124 , L_125 , L_126 , L_127 , L_128 , L_129 , L_130 , L_131 , L_132 , L_133 , L_320 , L_321 , L_322 , L_323 , L_324 , L_325 ,
L_140 , L_141 , L_142 , L_143 , L_144 , L_145 , L_146 , L_147 , L_148 , L_149 , L_326 , L_327 , L_328 , L_329 , L_330 , L_331 ,
L_156 , L_157 , L_158 , L_159 , L_160 , L_161 , L_162 , L_163 , L_164 , L_165 , L_332 , L_333 , L_334 , L_335 , L_336 , L_337 ,
L_172 , L_173 , L_174 , L_175 , L_176 , L_177 , L_178 , L_179 , L_180 , L_181 , L_338 , L_339 , L_340 , L_341 , L_342 , L_343 ,
L_344 , L_345 , L_346 , L_347 , L_348 , L_349 , L_350 , L_351 , L_352 , L_353 , L_354 , L_355 , L_356 , L_357 , L_358 , L_359 ,
L_360 , L_361 , L_362 , L_363 , L_364 , L_365 , L_366 , L_367 , L_368 , L_369 , L_370 , L_371 , L_372 , L_373 , L_374 , L_375 ,
L_376 , L_377 , L_378 , L_379 , L_380 , L_381 , L_382 , L_383 , L_384 , L_385 , L_386 , L_387 , L_388 , L_389 , L_390 , L_391 ,
L_392 , L_393 , L_394 , L_395 , L_396 , L_397 , L_398 , L_399 , L_400 , L_401 , L_402 , L_403 , L_404 , L_405 , L_406 , L_407 ,
L_408 , L_409 , L_410 , L_411 , L_412 , L_413 , L_414 , L_415 , L_416 , L_417 , L_418 , L_419 , L_420 , L_421 , L_422 , L_423 ,
L_424 , L_425 , L_426 , L_427 , L_428 , L_429 , L_430 , L_431 , L_432 , L_433 , L_434 , L_435 , L_436 , L_437 , L_438 , L_439
} ;
const char ( * V_38 ) [ 3 ] = V_36 ;
const T_11 V_39 = V_32 - 1 ;
if ( V_33 ) V_38 = V_37 ;
F_57 ( V_1 , & V_35 ) ;
for ( V_9 = 0 ; V_9 < V_32 ; V_9 ++ ) {
F_58 ( & V_35 , & ( * V_38 [ V_31 [ V_9 ] ] ) , 2 ) ;
if ( V_34 && V_9 < V_39 ) F_59 ( & V_35 , V_34 ) ;
}
F_60 ( & V_35 ) ;
return 1 ;
}
int F_61 ( T_2 * V_1 , const char * V_31 , const T_11 V_32 , const T_6 * V_34 ) {
T_12 V_35 ;
T_11 V_9 = 0 ;
T_11 V_40 = 0 ;
T_13 V_41 , V_42 ;
static const T_13 V_43 [ 256 ] = {
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , 10 , 11 , 12 , 13 , 14 , 15 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , 10 , 11 , 12 , 13 , 14 , 15 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1
} ;
if ( V_34 ) V_40 = ( T_11 ) strlen ( V_34 ) ;
F_57 ( V_1 , & V_35 ) ;
for ( V_9 = 0 ; V_9 < V_32 ; ) {
V_41 = V_43 [ ( V_44 ) V_31 [ V_9 ] ] ;
if ( V_41 < 0 ) {
if ( V_40 && strncmp ( & V_31 [ V_9 ] , V_34 , V_40 ) == 0 ) {
V_9 += V_40 ;
continue;
} else {
break;
}
}
V_42 = V_43 [ ( V_44 ) V_31 [ ++ V_9 ] ] ;
if ( V_42 < 0 ) break;
F_62 ( & V_35 , ( V_41 * 16 ) + V_42 ) ;
V_9 ++ ;
}
F_60 ( & V_35 ) ;
return 1 ;
}
