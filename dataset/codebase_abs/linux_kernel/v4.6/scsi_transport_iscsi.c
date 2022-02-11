static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 ) ;
}
static T_1
F_4 ( struct V_1 * V_2 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return sprintf ( V_7 , L_1 , ( unsigned long long ) F_5 ( V_4 -> V_8 ) ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
F_3 ( V_10 ) ;
}
static T_1
F_8 ( struct V_1 * V_2 , struct V_5 * V_6 , char * V_7 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
return sprintf ( V_7 , L_1 , ( unsigned long long ) V_10 -> V_11 ) ;
}
static int F_9 ( struct V_1 * V_2 , const void * V_12 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
const T_2 * V_13 = V_12 ;
return * V_13 == V_10 -> V_11 ;
}
struct V_9 *
F_10 ( int V_14 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_2 V_11 ;
int V_15 ;
for ( V_11 = 1 ; V_11 < V_16 ; V_11 ++ ) {
V_2 = F_11 ( & V_17 , NULL , & V_11 ,
F_9 ) ;
if ( ! V_2 )
break;
else
F_12 ( V_2 ) ;
}
if ( V_11 == V_16 ) {
F_13 ( V_18 L_2 ,
V_16 - 1 ) ;
return NULL ;
}
V_10 = F_14 ( sizeof( * V_10 ) + V_14 , V_19 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_11 = V_11 ;
V_10 -> V_2 . V_20 = & V_17 ;
F_15 ( & V_10 -> V_2 , L_3 , ( unsigned long long ) V_11 ) ;
V_15 = F_16 ( & V_10 -> V_2 ) ;
if ( V_15 )
goto V_21;
V_15 = F_17 ( & V_10 -> V_2 . V_22 , & V_23 ) ;
if ( V_15 )
goto V_24;
if ( V_14 )
V_10 -> V_25 = & V_10 [ 1 ] ;
return V_10 ;
V_24:
F_18 ( & V_10 -> V_2 ) ;
return NULL ;
V_21:
F_3 ( V_10 ) ;
return NULL ;
}
void F_19 ( struct V_9 * V_10 )
{
F_20 ( & V_10 -> V_2 . V_22 , & V_23 ) ;
F_18 ( & V_10 -> V_2 ) ;
}
struct V_9 * F_21 ( T_3 V_26 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
V_2 = F_11 ( & V_17 , NULL , & V_26 ,
F_9 ) ;
if ( ! V_2 )
return NULL ;
V_10 = F_7 ( V_2 ) ;
F_12 ( V_2 ) ;
return V_10 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = F_23 ( V_2 ) ;
struct V_1 * V_29 = V_28 -> V_2 . V_29 ;
F_3 ( V_28 ) ;
F_12 ( V_29 ) ;
}
static T_4 F_24 ( struct V_30 * V_22 ,
struct V_31 * V_6 , int V_32 )
{
struct V_1 * V_2 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_27 * V_28 = F_23 ( V_2 ) ;
struct V_8 * V_33 = V_28 -> V_34 ;
int V_35 ;
int V_36 ;
if ( V_6 == & V_37 . V_6 )
V_35 = V_38 ;
else if ( V_6 == & V_39 . V_6 )
V_35 = V_40 ;
else if ( V_6 == & V_41 . V_6 )
V_35 = V_42 ;
else if ( V_6 == & V_43 . V_6 )
V_35 = V_44 ;
else if ( V_6 == & V_45 . V_6 )
V_35 = V_46 ;
else if ( V_6 == & V_47 . V_6 )
V_35 = V_48 ;
else if ( V_6 == & V_49 . V_6 )
V_35 = V_50 ;
else if ( V_6 == & V_51 . V_6 )
V_35 = V_52 ;
else if ( V_6 == & V_53 . V_6 )
V_35 = V_54 ;
else if ( V_6 == & V_55 . V_6 )
V_35 = V_56 ;
else if ( V_6 == & V_57 . V_6 )
V_35 = V_58 ;
else if ( V_6 == & V_59 . V_6 )
V_35 = V_60 ;
else if ( V_6 == & V_61 . V_6 )
V_35 = V_62 ;
else if ( V_6 == & V_63 . V_6 )
V_35 = V_64 ;
else if ( V_6 == & V_65 . V_6 )
V_35 = V_66 ;
else if ( V_6 == & V_67 . V_6 )
V_35 = V_68 ;
else if ( V_6 == & V_69 . V_6 )
V_35 = V_70 ;
else if ( V_6 == & V_71 . V_6 )
V_35 = V_72 ;
else if ( V_6 == & V_73 . V_6 )
V_35 = V_74 ;
else if ( V_6 == & V_75 . V_6 )
V_35 = V_76 ;
else if ( V_6 == & V_77 . V_6 )
V_35 = V_78 ;
else if ( V_6 == & V_79 . V_6 )
V_35 = V_80 ;
else if ( V_6 == & V_81 . V_6 )
V_35 = V_82 ;
else if ( V_6 == & V_83 . V_6 )
V_35 = V_84 ;
else if ( V_6 == & V_85 . V_6 )
V_35 = V_86 ;
else if ( V_6 == & V_87 . V_6 )
V_35 = V_88 ;
else if ( V_6 == & V_89 . V_6 )
V_35 = V_90 ;
else if ( V_6 == & V_91 . V_6 )
V_35 = V_92 ;
else if ( V_6 == & V_93 . V_6 )
V_35 = V_94 ;
else if ( V_6 == & V_95 . V_6 )
V_35 = V_96 ;
else if ( V_6 == & V_97 . V_6 )
V_35 = V_98 ;
else if ( V_6 == & V_99 . V_6 )
V_35 = V_100 ;
else if ( V_6 == & V_101 . V_6 )
V_35 = V_102 ;
else if ( V_28 -> V_103 == V_104 ) {
if ( V_6 == & V_105 . V_6 )
V_35 = V_106 ;
else if ( V_6 == & V_107 . V_6 )
V_35 = V_108 ;
else if ( V_6 == & V_109 . V_6 )
V_35 = V_110 ;
else if ( V_6 == & V_111 . V_6 )
V_35 = V_112 ;
else if ( V_6 ==
& V_113 . V_6 )
V_35 = V_114 ;
else if ( V_6 ==
& V_115 . V_6 )
V_35 = V_116 ;
else if ( V_6 == & V_117 . V_6 )
V_35 = V_118 ;
else if ( V_6 == & V_119 . V_6 )
V_35 = V_120 ;
else if ( V_6 == & V_121 . V_6 )
V_35 = V_122 ;
else if ( V_6 ==
& V_123 . V_6 )
V_35 = V_124 ;
else if ( V_6 == & V_125 . V_6 )
V_35 = V_126 ;
else if ( V_6 ==
& V_127 . V_6 )
V_35 = V_128 ;
else if ( V_6 ==
& V_129 . V_6 )
V_35 = V_130 ;
else if ( V_6 == & V_131 . V_6 )
V_35 = V_132 ;
else if ( V_6 ==
& V_133 . V_6 )
V_35 = V_134 ;
else if ( V_6 ==
& V_135 . V_6 )
V_35 = V_136 ;
else if ( V_6 ==
& V_137 . V_6 )
V_35 = V_138 ;
else if ( V_6 == & V_139 . V_6 )
V_35 = V_140 ;
else
return 0 ;
} else if ( V_28 -> V_103 == V_141 ) {
if ( V_6 == & V_142 . V_6 )
V_35 = V_143 ;
else if ( V_6 == & V_144 . V_6 )
V_35 = V_145 ;
else if ( V_6 == & V_146 . V_6 )
V_35 = V_147 ;
else if ( V_6 == & V_148 . V_6 )
V_35 = V_149 ;
else if ( V_6 == & V_150 . V_6 )
V_35 = V_151 ;
else if ( V_6 == & V_152 . V_6 )
V_35 = V_153 ;
else if ( V_6 == & V_154 . V_6 )
V_35 = V_155 ;
else if ( V_6 ==
& V_156 . V_6 )
V_35 = V_157 ;
else if ( V_6 == & V_158 . V_6 )
V_35 = V_159 ;
else if ( V_6 == & V_160 . V_6 )
V_35 = V_161 ;
else if ( V_6 == & V_162 . V_6 )
V_35 = V_163 ;
else if ( V_6 == & V_164 . V_6 )
V_35 = V_165 ;
else if ( V_6 == & V_166 . V_6 )
V_35 = V_167 ;
else if ( V_6 == & V_168 . V_6 )
V_35 = V_169 ;
else if ( V_6 == & V_170 . V_6 )
V_35 = V_171 ;
else if ( V_6 == & V_172 . V_6 )
V_35 = V_173 ;
else if ( V_6 == & V_174 . V_6 )
V_35 = V_175 ;
else
return 0 ;
} else {
F_26 ( 1 , L_4 ) ;
return 0 ;
}
switch ( V_35 ) {
case V_68 :
case V_70 :
case V_72 :
case V_74 :
case V_76 :
case V_78 :
case V_80 :
case V_82 :
case V_84 :
case V_86 :
case V_88 :
case V_90 :
case V_92 :
case V_94 :
case V_96 :
case V_98 :
case V_100 :
case V_102 :
V_36 = V_176 ;
break;
default:
V_36 = V_177 ;
}
return V_33 -> V_178 ( V_36 , V_35 ) ;
}
char * F_27 ( enum V_179 V_180 )
{
int V_32 ;
char * V_181 = NULL ;
for ( V_32 = 0 ; V_32 < F_28 ( V_182 ) ; V_32 ++ ) {
if ( V_182 [ V_32 ] . V_183 == V_180 ) {
V_181 = V_182 [ V_32 ] . V_184 ;
break;
}
}
return V_181 ;
}
char * F_29 ( enum V_185 V_186 )
{
int V_32 ;
char * V_181 = NULL ;
for ( V_32 = 0 ; V_32 < F_28 ( V_187 ) ; V_32 ++ ) {
if ( V_187 [ V_32 ] . V_183 == V_186 ) {
V_181 = V_187 [ V_32 ] . V_184 ;
break;
}
}
return V_181 ;
}
struct V_27 *
F_30 ( struct V_188 * V_189 , struct V_8 * V_34 ,
T_5 V_103 , T_5 V_190 , int V_14 )
{
struct V_27 * V_28 ;
int V_15 ;
V_28 = F_14 ( sizeof( * V_28 ) + V_14 , V_19 ) ;
if ( ! V_28 )
return NULL ;
V_28 -> V_34 = V_34 ;
V_28 -> V_103 = V_103 ;
V_28 -> V_190 = V_190 ;
V_28 -> V_2 . V_191 = F_22 ;
V_28 -> V_2 . V_20 = & V_192 ;
V_28 -> V_2 . V_29 = F_31 ( & V_189 -> V_193 ) ;
if ( V_103 == V_104 )
F_15 ( & V_28 -> V_2 , L_5 , V_189 -> V_194 ,
V_190 ) ;
else
F_15 ( & V_28 -> V_2 , L_6 , V_189 -> V_194 ,
V_190 ) ;
V_15 = F_16 ( & V_28 -> V_2 ) ;
if ( V_15 )
goto V_195;
V_15 = F_17 ( & V_28 -> V_2 . V_22 , & V_196 ) ;
if ( V_15 )
goto V_197;
if ( V_14 )
V_28 -> V_25 = & V_28 [ 1 ] ;
return V_28 ;
V_197:
F_18 ( & V_28 -> V_2 ) ;
return NULL ;
V_195:
F_12 ( V_28 -> V_2 . V_29 ) ;
F_3 ( V_28 ) ;
return NULL ;
}
void F_32 ( struct V_27 * V_28 )
{
F_20 ( & V_28 -> V_2 . V_22 , & V_196 ) ;
F_18 ( & V_28 -> V_2 ) ;
}
static T_4 F_33 ( struct V_30 * V_22 ,
struct V_31 * V_6 ,
int V_32 )
{
struct V_1 * V_2 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_198 * V_199 =
F_34 ( V_2 ) ;
struct V_8 * V_33 = V_199 -> V_34 ;
int V_35 ;
if ( V_6 == & V_200 . V_6 ) {
V_35 = V_201 ;
} else if ( V_6 == & V_202 . V_6 ) {
V_35 = V_203 ;
} else if ( V_6 == & V_204 . V_6 ) {
V_35 = V_205 ;
} else if ( V_6 == & V_206 . V_6 ) {
V_35 = V_207 ;
} else if ( V_6 == & V_208 . V_6 ) {
V_35 = V_209 ;
} else if ( V_6 == & V_210 . V_6 ) {
V_35 = V_211 ;
} else if ( V_6 == & V_212 . V_6 ) {
V_35 = V_213 ;
} else if ( V_6 == & V_214 . V_6 ) {
V_35 = V_215 ;
} else if ( V_6 == & V_216 . V_6 ) {
V_35 = V_217 ;
} else if ( V_6 == & V_218 . V_6 ) {
V_35 = V_219 ;
} else if ( V_6 == & V_220 . V_6 ) {
V_35 = V_221 ;
} else if ( V_6 == & V_222 . V_6 ) {
V_35 = V_223 ;
} else if ( V_6 == & V_224 . V_6 ) {
V_35 = V_225 ;
} else if ( V_6 == & V_226 . V_6 ) {
V_35 = V_227 ;
} else if ( V_6 == & V_228 . V_6 ) {
V_35 = V_229 ;
} else if ( V_6 == & V_230 . V_6 ) {
V_35 = V_231 ;
} else if ( V_6 == & V_232 . V_6 ) {
V_35 = V_233 ;
} else if ( V_6 == & V_234 . V_6 ) {
V_35 = V_235 ;
} else if ( V_6 == & V_236 . V_6 ) {
V_35 = V_237 ;
} else if ( V_6 == & V_238 . V_6 ) {
V_35 = V_239 ;
} else if ( V_6 == & V_240 . V_6 ) {
V_35 = V_241 ;
} else if ( V_6 == & V_242 . V_6 ) {
V_35 = V_243 ;
} else if ( V_6 == & V_244 . V_6 ) {
V_35 = V_245 ;
} else if ( V_6 == & V_246 . V_6 ) {
V_35 = V_247 ;
} else if ( V_6 == & V_248 . V_6 ) {
V_35 = V_249 ;
} else if ( V_6 == & V_250 . V_6 ) {
V_35 = V_251 ;
} else if ( V_6 == & V_252 . V_6 ) {
V_35 = V_253 ;
} else if ( V_6 == & V_254 . V_6 ) {
V_35 = V_255 ;
} else if ( V_6 == & V_256 . V_6 ) {
V_35 = V_257 ;
} else if ( V_6 == & V_258 . V_6 ) {
V_35 = V_259 ;
} else if ( V_6 == & V_260 . V_6 ) {
V_35 = V_261 ;
} else if ( V_6 == & V_262 . V_6 ) {
V_35 = V_263 ;
} else if ( V_6 == & V_264 . V_6 ) {
V_35 = V_265 ;
} else {
F_26 ( 1 , L_7 ) ;
return 0 ;
}
return V_33 -> V_178 ( V_266 , V_35 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_198 * V_199 =
F_34 ( V_2 ) ;
F_3 ( V_199 -> V_267 ) ;
F_3 ( V_199 -> V_268 ) ;
F_3 ( V_199 -> V_269 ) ;
F_3 ( V_199 ) ;
}
static T_4 F_36 ( struct V_30 * V_22 ,
struct V_31 * V_6 ,
int V_32 )
{
struct V_1 * V_2 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_270 * V_271 = F_37 ( V_2 ) ;
struct V_8 * V_33 = V_271 -> V_34 ;
int V_35 ;
if ( V_6 == & V_272 . V_6 ) {
V_35 = V_273 ;
} else if ( V_6 == & V_274 . V_6 ) {
V_35 = V_275 ;
} else if ( V_6 == & V_276 . V_6 ) {
V_35 = V_277 ;
} else if ( V_6 == & V_278 . V_6 ) {
V_35 = V_279 ;
} else if ( V_6 == & V_280 . V_6 ) {
V_35 = V_281 ;
} else if ( V_6 == & V_282 . V_6 ) {
V_35 = V_283 ;
} else if ( V_6 == & V_284 . V_6 ) {
V_35 = V_285 ;
} else if ( V_6 == & V_286 . V_6 ) {
V_35 = V_287 ;
} else if ( V_6 == & V_288 . V_6 ) {
V_35 = V_289 ;
} else if ( V_6 == & V_290 . V_6 ) {
V_35 = V_291 ;
} else if ( V_6 == & V_292 . V_6 ) {
V_35 = V_293 ;
} else if ( V_6 == & V_294 . V_6 ) {
V_35 = V_295 ;
} else if ( V_6 == & V_296 . V_6 ) {
V_35 = V_297 ;
} else if ( V_6 == & V_298 . V_6 ) {
V_35 = V_299 ;
} else if ( V_6 == & V_300 . V_6 ) {
V_35 = V_301 ;
} else if ( V_6 == & V_302 . V_6 ) {
V_35 = V_303 ;
} else if ( V_6 == & V_304 . V_6 ) {
V_35 = V_305 ;
} else if ( V_6 == & V_306 . V_6 ) {
V_35 = V_307 ;
} else if ( V_6 == & V_308 . V_6 ) {
V_35 = V_309 ;
} else if ( V_6 == & V_310 . V_6 ) {
V_35 = V_311 ;
} else if ( V_6 == & V_312 . V_6 ) {
V_35 = V_313 ;
} else if ( V_6 == & V_314 . V_6 ) {
V_35 = V_315 ;
} else if ( V_6 == & V_316 . V_6 ) {
V_35 = V_317 ;
} else if ( V_6 == & V_318 . V_6 ) {
V_35 = V_319 ;
} else if ( V_6 == & V_320 . V_6 ) {
V_35 = V_321 ;
} else if ( V_6 == & V_322 . V_6 ) {
V_35 = V_323 ;
} else {
F_26 ( 1 , L_8 ) ;
return 0 ;
}
return V_33 -> V_178 ( V_266 , V_35 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_270 * V_271 = F_37 ( V_2 ) ;
F_3 ( V_271 -> V_324 ) ;
F_3 ( V_271 -> V_325 ) ;
F_3 ( V_271 -> V_326 ) ;
F_3 ( V_271 ) ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_327 * V_328 )
{
if ( V_2 -> V_329 == & V_330 )
return 1 ;
return 0 ;
}
struct V_198 *
F_40 ( struct V_188 * V_189 , int V_331 ,
struct V_8 * V_34 ,
int V_14 )
{
struct V_198 * V_199 ;
int V_15 ;
V_199 = F_14 ( sizeof( * V_199 ) + V_14 , V_19 ) ;
if ( ! V_199 )
return NULL ;
V_199 -> V_34 = V_34 ;
V_199 -> V_332 = V_331 ;
V_199 -> V_2 . type = & V_333 ;
V_199 -> V_2 . V_329 = & V_330 ;
V_199 -> V_2 . V_29 = & V_189 -> V_193 ;
F_15 ( & V_199 -> V_2 , L_9 ,
V_189 -> V_194 , V_331 ) ;
V_15 = F_16 ( & V_199 -> V_2 ) ;
if ( V_15 )
goto V_334;
if ( V_14 )
V_199 -> V_25 = & V_199 [ 1 ] ;
return V_199 ;
V_334:
F_3 ( V_199 ) ;
return NULL ;
}
struct V_270 *
F_41 ( struct V_188 * V_189 ,
struct V_198 * V_199 ,
struct V_8 * V_34 ,
int V_14 )
{
struct V_270 * V_271 ;
int V_15 ;
V_271 = F_14 ( sizeof( * V_271 ) + V_14 , V_19 ) ;
if ( ! V_271 )
return NULL ;
V_271 -> V_34 = V_34 ;
V_271 -> V_2 . type = & V_335 ;
V_271 -> V_2 . V_329 = & V_330 ;
V_271 -> V_2 . V_29 = & V_199 -> V_2 ;
F_15 ( & V_271 -> V_2 , L_10 ,
V_189 -> V_194 , V_199 -> V_332 ) ;
V_15 = F_16 ( & V_271 -> V_2 ) ;
if ( V_15 )
goto V_336;
if ( V_14 )
V_271 -> V_25 = & V_271 [ 1 ] ;
return V_271 ;
V_336:
F_3 ( V_271 ) ;
return NULL ;
}
int F_42 ( struct V_1 * V_2 , void * V_12 )
{
return V_2 -> V_329 == & V_330 ;
}
static int F_43 ( struct V_270 * V_271 )
{
F_18 ( & V_271 -> V_2 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , void * V_12 )
{
struct V_198 * V_199 = NULL ;
int V_337 = 0 ;
if ( ! F_39 ( V_2 , NULL ) )
goto V_338;
V_199 = F_34 ( V_2 ) ;
V_337 = ( V_199 -> V_332 == * ( ( int * ) V_12 ) ) ? 1 : 0 ;
V_338:
return V_337 ;
}
static struct V_198 *
F_45 ( struct V_188 * V_189 , T_5 V_339 )
{
struct V_198 * V_199 = NULL ;
struct V_1 * V_2 ;
V_2 = F_46 ( & V_189 -> V_193 , & V_339 ,
F_44 ) ;
if ( V_2 )
V_199 = F_34 ( V_2 ) ;
return V_199 ;
}
struct V_1 *
F_47 ( struct V_188 * V_189 , void * V_12 ,
int (* F_48)( struct V_1 * V_2 , void * V_12 ) )
{
return F_46 ( & V_189 -> V_193 , V_12 , F_48 ) ;
}
struct V_1 *
F_49 ( struct V_198 * V_199 )
{
return F_46 ( & V_199 -> V_2 , NULL ,
F_42 ) ;
}
static int F_50 ( struct V_1 * V_2 , void * V_12 )
{
if ( ! F_42 ( V_2 , NULL ) )
return 0 ;
return F_43 ( F_37 ( V_2 ) ) ;
}
void F_51 ( struct V_198 * V_199 )
{
int V_15 ;
V_15 = F_52 ( & V_199 -> V_2 , NULL ,
F_50 ) ;
if ( V_15 )
F_53 ( L_11 ,
V_199 -> V_2 . V_22 . V_184 , V_15 ) ;
F_18 ( & V_199 -> V_2 ) ;
}
static int F_54 ( struct V_1 * V_2 , void * V_12 )
{
if ( ! F_39 ( V_2 , NULL ) )
return 0 ;
F_51 ( F_34 ( V_2 ) ) ;
return 0 ;
}
void F_55 ( struct V_188 * V_189 )
{
F_52 ( & V_189 -> V_193 , NULL ,
F_54 ) ;
}
static int F_56 ( struct V_340 * V_341 )
{
struct V_188 * V_189 = F_57 ( V_341 ) ;
struct V_342 * V_343 = V_341 -> V_344 ;
struct V_345 * V_346 = V_341 -> V_346 ;
struct V_3 * V_32 = F_58 ( V_189 -> V_347 ) ;
int V_348 = sizeof( T_5 ) ;
int V_337 ;
if ( V_341 -> V_349 < sizeof( T_5 ) ) {
V_337 = - V_350 ;
goto V_351;
}
switch ( V_343 -> V_352 ) {
case V_353 :
V_348 += sizeof( struct V_354 ) ;
if ( ( V_189 -> V_355 -> V_356 == 0L ) ||
( V_343 -> V_357 . V_358 . V_356 !=
V_189 -> V_355 -> V_356 ) ) {
V_337 = - V_359 ;
goto V_351;
}
break;
default:
V_337 = - V_360 ;
goto V_351;
}
if ( V_341 -> V_349 < V_348 ) {
V_337 = - V_350 ;
goto V_351;
}
V_337 = V_32 -> V_8 -> V_361 ( V_341 ) ;
if ( ! V_337 )
return 0 ;
V_351:
F_59 ( V_341 -> V_362 < sizeof( T_5 ) ) ;
V_346 -> V_363 = 0 ;
V_346 -> V_364 = V_337 ;
V_341 -> V_362 = sizeof( T_5 ) ;
F_60 ( V_341 , V_337 , 0 ) ;
return 0 ;
}
static int
F_61 ( struct V_188 * V_189 , struct V_365 * V_366 )
{
struct V_1 * V_2 = & V_189 -> V_193 ;
struct V_3 * V_32 = F_58 ( V_189 -> V_347 ) ;
struct V_367 * V_368 ;
char V_369 [ 20 ] ;
int V_337 ;
if ( ! V_32 -> V_8 -> V_361 )
return - V_370 ;
snprintf ( V_369 , sizeof( V_369 ) , L_12 , V_189 -> V_194 ) ;
V_368 = F_62 ( V_189 , V_371 ) ;
if ( ! V_368 )
return - V_372 ;
V_337 = F_63 ( V_2 , V_368 , V_369 , F_56 , 0 ) ;
if ( V_337 ) {
F_64 ( V_18 , V_189 , L_13
L_14 ) ;
F_65 ( V_368 ) ;
return V_337 ;
}
V_366 -> V_373 = V_368 ;
return 0 ;
}
static int F_66 ( struct V_374 * V_375 , struct V_1 * V_2 ,
struct V_1 * V_376 )
{
struct V_188 * V_189 = F_67 ( V_2 ) ;
struct V_365 * V_366 = V_189 -> V_377 ;
memset ( V_366 , 0 , sizeof( * V_366 ) ) ;
F_68 ( & V_366 -> V_378 , 0 ) ;
F_69 ( & V_366 -> V_379 ) ;
F_61 ( V_189 , V_366 ) ;
return 0 ;
}
static int F_70 ( struct V_374 * V_375 ,
struct V_1 * V_2 , struct V_1 * V_376 )
{
struct V_188 * V_189 = F_67 ( V_2 ) ;
struct V_365 * V_366 = V_189 -> V_377 ;
if ( V_366 -> V_373 ) {
F_71 ( V_366 -> V_373 ) ;
F_65 ( V_366 -> V_373 ) ;
}
return 0 ;
}
static T_5 F_72 ( struct V_380 * V_381 )
{
struct V_382 * V_383 = F_73 ( V_381 -> V_2 . V_29 ) ;
return V_383 -> V_384 ;
}
static struct V_382 * F_74 ( T_5 V_384 )
{
unsigned long V_385 ;
struct V_382 * V_383 ;
F_75 ( & V_386 , V_385 ) ;
F_76 (sess, &sesslist, sess_list) {
if ( V_383 -> V_384 == V_384 ) {
F_77 ( & V_386 , V_385 ) ;
return V_383 ;
}
}
F_77 ( & V_386 , V_385 ) ;
return NULL ;
}
static struct V_380 * F_78 ( T_5 V_384 , T_5 V_387 )
{
unsigned long V_385 ;
struct V_380 * V_381 ;
F_75 ( & V_388 , V_385 ) ;
F_76 (conn, &connlist, conn_list) {
if ( ( V_381 -> V_387 == V_387 ) && ( F_72 ( V_381 ) == V_384 ) ) {
F_77 ( & V_388 , V_385 ) ;
return V_381 ;
}
}
F_77 ( & V_388 , V_385 ) ;
return NULL ;
}
static const char * F_79 ( int V_181 )
{
int V_32 ;
char * V_184 = NULL ;
for ( V_32 = 0 ; V_32 < F_28 ( V_389 ) ; V_32 ++ ) {
if ( V_389 [ V_32 ] . V_183 == V_181 ) {
V_184 = V_389 [ V_32 ] . V_184 ;
break;
}
}
return V_184 ;
}
int F_80 ( struct V_382 * V_390 )
{
unsigned long V_385 ;
int V_15 ;
F_75 ( & V_390 -> V_391 , V_385 ) ;
switch ( V_390 -> V_181 ) {
case V_392 :
V_15 = 0 ;
break;
case V_393 :
V_15 = V_394 << 16 ;
break;
case V_395 :
V_15 = V_396 << 16 ;
break;
default:
V_15 = V_397 << 16 ;
break;
}
F_77 ( & V_390 -> V_391 , V_385 ) ;
return V_15 ;
}
int F_81 ( struct V_382 * V_390 )
{
unsigned long V_385 ;
int V_337 = 0 ;
F_75 ( & V_390 -> V_391 , V_385 ) ;
if ( V_390 -> V_181 == V_392 )
V_337 = 1 ;
F_77 ( & V_390 -> V_391 , V_385 ) ;
return V_337 ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_382 * V_390 = F_73 ( V_2 ) ;
struct V_188 * V_189 ;
V_189 = F_83 ( V_390 ) ;
F_84 ( V_189 ) ;
F_85 ( V_390 , L_15 ) ;
F_3 ( V_390 ) ;
}
int F_86 ( const struct V_1 * V_2 )
{
return V_2 -> V_191 == F_82 ;
}
static int F_87 ( struct V_1 * V_2 , void * V_12 )
{
void (* F_48) ( struct V_382 * ) = V_12 ;
if ( ! F_86 ( V_2 ) )
return 0 ;
F_48 ( F_73 ( V_2 ) ) ;
return 0 ;
}
void F_88 ( struct V_188 * V_189 ,
void (* F_48)( struct V_382 * ) )
{
F_52 ( & V_189 -> V_193 , F_48 ,
F_87 ) ;
}
int F_89 ( struct V_188 * V_189 , unsigned long time )
{
struct V_365 * V_366 = V_189 -> V_377 ;
return ! F_90 ( & V_366 -> V_378 ) ;
}
static int F_91 ( struct V_1 * V_2 , void * V_12 )
{
struct V_398 * V_399 = V_12 ;
struct V_382 * V_390 ;
struct V_188 * V_189 ;
struct V_365 * V_366 ;
unsigned long V_385 ;
unsigned int V_11 ;
if ( ! F_86 ( V_2 ) )
return 0 ;
V_390 = F_73 ( V_2 ) ;
F_85 ( V_390 , L_16 ) ;
V_189 = F_83 ( V_390 ) ;
V_366 = V_189 -> V_377 ;
F_92 ( & V_366 -> V_379 ) ;
F_75 ( & V_390 -> V_391 , V_385 ) ;
if ( V_390 -> V_181 != V_392 ) {
F_77 ( & V_390 -> V_391 , V_385 ) ;
goto V_400;
}
V_11 = V_390 -> V_332 ;
F_77 ( & V_390 -> V_391 , V_385 ) ;
if ( V_11 != V_401 ) {
if ( ( V_399 -> V_402 == V_403 ||
V_399 -> V_402 == 0 ) &&
( V_399 -> V_11 == V_403 ||
V_399 -> V_11 == V_11 ) )
F_93 ( & V_390 -> V_2 , 0 , V_11 ,
V_399 -> V_404 , 1 ) ;
}
V_400:
F_94 ( & V_366 -> V_379 ) ;
F_85 ( V_390 , L_17 ) ;
return 0 ;
}
static int F_95 ( struct V_188 * V_189 , T_6 V_402 ,
T_6 V_11 , T_3 V_404 )
{
struct V_398 V_399 ;
V_399 . V_402 = V_402 ;
V_399 . V_11 = V_11 ;
V_399 . V_404 = V_404 ;
return F_52 ( & V_189 -> V_193 , & V_399 ,
F_91 ) ;
}
static void F_96 ( struct V_405 * V_406 )
{
struct V_382 * V_390 =
F_25 ( V_406 , struct V_382 , V_407 ) ;
struct V_188 * V_189 = F_83 ( V_390 ) ;
struct V_365 * V_366 = V_189 -> V_377 ;
struct V_398 V_399 ;
V_399 . V_402 = 0 ;
V_399 . V_11 = V_403 ;
V_399 . V_404 = V_403 ;
F_91 ( & V_390 -> V_2 , & V_399 ) ;
F_97 ( & V_366 -> V_378 ) ;
}
int F_98 ( struct V_408 * V_409 )
{
struct V_382 * V_390 =
F_99 ( F_100 ( V_409 -> V_1 ) ) ;
unsigned long V_385 ;
int V_337 = 0 ;
F_75 ( & V_390 -> V_391 , V_385 ) ;
while ( V_390 -> V_181 != V_392 ) {
if ( V_390 -> V_181 == V_395 ) {
V_337 = V_410 ;
break;
}
F_77 ( & V_390 -> V_391 , V_385 ) ;
F_101 ( 1000 ) ;
F_75 ( & V_390 -> V_391 , V_385 ) ;
}
F_77 ( & V_390 -> V_391 , V_385 ) ;
return V_337 ;
}
static void F_102 ( struct V_405 * V_406 )
{
struct V_382 * V_390 =
F_25 ( V_406 , struct V_382 ,
V_411 . V_406 ) ;
unsigned long V_385 ;
F_103 ( V_412 , V_390 ,
L_18 ,
V_390 -> V_413 ) ;
F_75 ( & V_390 -> V_391 , V_385 ) ;
switch ( V_390 -> V_181 ) {
case V_393 :
V_390 -> V_181 = V_395 ;
break;
case V_392 :
case V_395 :
F_77 ( & V_390 -> V_391 , V_385 ) ;
return;
}
F_77 ( & V_390 -> V_391 , V_385 ) ;
if ( V_390 -> V_34 -> F_102 )
V_390 -> V_34 -> F_102 ( V_390 ) ;
F_85 ( V_390 , L_19 ) ;
F_104 ( & V_390 -> V_2 , V_414 ) ;
F_85 ( V_390 , L_20 ) ;
}
static void F_105 ( struct V_405 * V_406 )
{
struct V_382 * V_390 =
F_25 ( V_406 , struct V_382 ,
V_415 ) ;
struct V_188 * V_189 = F_83 ( V_390 ) ;
struct V_365 * V_366 = V_189 -> V_377 ;
unsigned long V_385 ;
F_85 ( V_390 , L_21 ) ;
F_106 ( & V_390 -> V_411 ) ;
F_75 ( & V_390 -> V_391 , V_385 ) ;
V_390 -> V_181 = V_392 ;
F_77 ( & V_390 -> V_391 , V_385 ) ;
F_104 ( & V_390 -> V_2 , V_416 ) ;
if ( V_189 -> V_355 -> V_417 ) {
if ( F_107 ( V_189 , & V_390 -> V_407 ) )
F_108 ( & V_366 -> V_378 ) ;
}
F_85 ( V_390 , L_22 ) ;
}
void F_109 ( struct V_382 * V_390 )
{
F_110 ( V_418 , & V_390 -> V_415 ) ;
F_111 ( V_418 ) ;
}
static void F_112 ( struct V_405 * V_406 )
{
struct V_382 * V_390 =
F_25 ( V_406 , struct V_382 ,
V_419 ) ;
unsigned long V_385 ;
F_85 ( V_390 , L_23 ) ;
F_75 ( & V_390 -> V_391 , V_385 ) ;
V_390 -> V_181 = V_393 ;
F_77 ( & V_390 -> V_391 , V_385 ) ;
F_113 ( & V_390 -> V_2 ) ;
F_85 ( V_390 , L_24 ) ;
if ( V_390 -> V_413 >= 0 )
F_114 ( V_418 ,
& V_390 -> V_411 ,
V_390 -> V_413 * V_420 ) ;
}
void F_115 ( struct V_382 * V_390 )
{
F_110 ( V_418 , & V_390 -> V_419 ) ;
}
static void F_116 ( struct V_405 * V_406 )
{
struct V_382 * V_390 =
F_25 ( V_406 , struct V_382 ,
V_421 ) ;
struct V_188 * V_189 = F_83 ( V_390 ) ;
struct V_365 * V_366 = V_189 -> V_377 ;
unsigned long V_385 ;
unsigned int V_332 ;
F_85 ( V_390 , L_25 ) ;
F_92 ( & V_366 -> V_379 ) ;
F_75 ( & V_390 -> V_391 , V_385 ) ;
if ( V_390 -> V_332 == V_401 ) {
F_77 ( & V_390 -> V_391 , V_385 ) ;
F_94 ( & V_366 -> V_379 ) ;
return;
}
V_332 = V_390 -> V_332 ;
V_390 -> V_332 = V_401 ;
F_77 ( & V_390 -> V_391 , V_385 ) ;
F_94 ( & V_366 -> V_379 ) ;
if ( V_390 -> V_422 )
F_117 ( & V_423 , V_332 ) ;
F_118 ( & V_390 -> V_2 ) ;
F_119 ( V_390 , V_424 ) ;
F_85 ( V_390 , L_26 ) ;
}
struct V_382 *
F_120 ( struct V_188 * V_189 , struct V_8 * V_34 ,
int V_14 )
{
struct V_382 * V_390 ;
V_390 = F_14 ( sizeof( * V_390 ) + V_14 ,
V_19 ) ;
if ( ! V_390 )
return NULL ;
V_390 -> V_34 = V_34 ;
V_390 -> V_425 = - 1 ;
V_390 -> V_413 = 120 ;
V_390 -> V_426 = false ;
V_390 -> V_181 = V_395 ;
F_121 ( & V_390 -> V_411 , F_102 ) ;
F_122 ( & V_390 -> V_427 ) ;
F_123 ( & V_390 -> V_415 , F_105 ) ;
F_123 ( & V_390 -> V_419 , F_112 ) ;
F_123 ( & V_390 -> V_421 , F_116 ) ;
F_123 ( & V_390 -> V_407 , F_96 ) ;
F_124 ( & V_390 -> V_391 ) ;
F_125 ( V_189 ) ;
V_390 -> V_2 . V_29 = & V_189 -> V_193 ;
V_390 -> V_2 . V_191 = F_82 ;
F_126 ( & V_390 -> V_2 ) ;
if ( V_14 )
V_390 -> V_25 = & V_390 [ 1 ] ;
F_85 ( V_390 , L_27 ) ;
return V_390 ;
}
int F_127 ( struct V_382 * V_390 , unsigned int V_332 )
{
struct V_188 * V_189 = F_83 ( V_390 ) ;
struct V_365 * V_366 ;
unsigned long V_385 ;
int V_11 = 0 ;
int V_15 ;
V_366 = V_189 -> V_377 ;
V_390 -> V_384 = F_128 ( 1 , & V_428 ) ;
if ( V_332 == V_401 ) {
V_11 = F_129 ( & V_423 , 0 , 0 , V_19 ) ;
if ( V_11 < 0 ) {
F_103 ( V_18 , V_390 ,
L_28 ) ;
return V_11 ;
}
V_390 -> V_332 = ( unsigned int ) V_11 ;
V_390 -> V_422 = true ;
} else
V_390 -> V_332 = V_332 ;
F_15 ( & V_390 -> V_2 , L_29 , V_390 -> V_384 ) ;
V_15 = F_130 ( & V_390 -> V_2 ) ;
if ( V_15 ) {
F_103 ( V_18 , V_390 ,
L_30 ) ;
goto V_429;
}
F_131 ( & V_390 -> V_2 ) ;
F_75 ( & V_386 , V_385 ) ;
F_132 ( & V_390 -> V_427 , & V_430 ) ;
F_77 ( & V_386 , V_385 ) ;
F_119 ( V_390 , V_431 ) ;
F_85 ( V_390 , L_31 ) ;
return 0 ;
V_429:
if ( V_390 -> V_422 )
F_117 ( & V_423 , V_390 -> V_332 ) ;
return V_15 ;
}
struct V_382 *
F_133 ( struct V_188 * V_189 , struct V_8 * V_34 ,
int V_14 , unsigned int V_332 )
{
struct V_382 * V_390 ;
V_390 = F_120 ( V_189 , V_34 , V_14 ) ;
if ( ! V_390 )
return NULL ;
if ( F_127 ( V_390 , V_332 ) ) {
F_134 ( V_390 ) ;
return NULL ;
}
return V_390 ;
}
static void F_135 ( struct V_1 * V_2 )
{
struct V_380 * V_381 = F_136 ( V_2 ) ;
struct V_1 * V_29 = V_381 -> V_2 . V_29 ;
F_137 ( V_381 , L_32 ) ;
F_3 ( V_381 ) ;
F_12 ( V_29 ) ;
}
static int F_138 ( const struct V_1 * V_2 )
{
return V_2 -> V_191 == F_135 ;
}
static int F_139 ( struct V_1 * V_2 , void * V_12 )
{
if ( ! F_138 ( V_2 ) )
return 0 ;
return F_140 ( F_136 ( V_2 ) ) ;
}
void F_141 ( struct V_382 * V_390 )
{
struct V_188 * V_189 = F_83 ( V_390 ) ;
unsigned long V_385 ;
int V_15 ;
F_85 ( V_390 , L_33 ) ;
F_75 ( & V_386 , V_385 ) ;
F_142 ( & V_390 -> V_427 ) ;
F_77 ( & V_386 , V_385 ) ;
F_111 ( V_418 ) ;
if ( ! F_106 ( & V_390 -> V_411 ) )
F_111 ( V_418 ) ;
F_75 ( & V_390 -> V_391 , V_385 ) ;
V_390 -> V_181 = V_395 ;
F_77 ( & V_390 -> V_391 , V_385 ) ;
F_104 ( & V_390 -> V_2 , V_414 ) ;
F_143 ( V_189 ) ;
F_116 ( & V_390 -> V_421 ) ;
V_15 = F_52 ( & V_390 -> V_2 , NULL ,
F_139 ) ;
if ( V_15 )
F_103 ( V_18 , V_390 ,
L_34
L_35 , V_15 ) ;
F_144 ( & V_390 -> V_2 ) ;
F_85 ( V_390 , L_36 ) ;
F_145 ( & V_390 -> V_2 ) ;
}
void F_134 ( struct V_382 * V_390 )
{
F_85 ( V_390 , L_37 ) ;
F_119 ( V_390 , V_432 ) ;
F_12 ( & V_390 -> V_2 ) ;
}
int F_146 ( struct V_382 * V_390 )
{
F_141 ( V_390 ) ;
F_85 ( V_390 , L_38 ) ;
F_134 ( V_390 ) ;
return 0 ;
}
struct V_380 *
F_147 ( struct V_382 * V_390 , int V_14 , T_5 V_387 )
{
struct V_8 * V_34 = V_390 -> V_34 ;
struct V_380 * V_381 ;
unsigned long V_385 ;
int V_15 ;
V_381 = F_14 ( sizeof( * V_381 ) + V_14 , V_19 ) ;
if ( ! V_381 )
return NULL ;
if ( V_14 )
V_381 -> V_25 = & V_381 [ 1 ] ;
F_69 ( & V_381 -> V_433 ) ;
F_122 ( & V_381 -> V_434 ) ;
V_381 -> V_34 = V_34 ;
V_381 -> V_387 = V_387 ;
if ( ! F_31 ( & V_390 -> V_2 ) )
goto V_435;
F_15 ( & V_381 -> V_2 , L_39 , V_390 -> V_384 , V_387 ) ;
V_381 -> V_2 . V_29 = & V_390 -> V_2 ;
V_381 -> V_2 . V_191 = F_135 ;
V_15 = F_16 ( & V_381 -> V_2 ) ;
if ( V_15 ) {
F_103 ( V_18 , V_390 , L_40
L_41 ) ;
goto V_436;
}
F_131 ( & V_381 -> V_2 ) ;
F_75 ( & V_388 , V_385 ) ;
F_132 ( & V_381 -> V_434 , & V_437 ) ;
F_77 ( & V_388 , V_385 ) ;
F_137 ( V_381 , L_42 ) ;
return V_381 ;
V_436:
F_12 ( & V_390 -> V_2 ) ;
V_435:
F_3 ( V_381 ) ;
return NULL ;
}
int F_140 ( struct V_380 * V_381 )
{
unsigned long V_385 ;
F_75 ( & V_388 , V_385 ) ;
F_142 ( & V_381 -> V_434 ) ;
F_77 ( & V_388 , V_385 ) ;
F_144 ( & V_381 -> V_2 ) ;
F_137 ( V_381 , L_43 ) ;
F_18 ( & V_381 -> V_2 ) ;
return 0 ;
}
static struct V_3 *
F_148 ( struct V_8 * V_438 )
{
struct V_3 * V_4 ;
unsigned long V_385 ;
F_75 ( & V_439 , V_385 ) ;
F_76 (priv, &iscsi_transports, list) {
if ( V_438 == V_4 -> V_8 ) {
F_77 ( & V_439 , V_385 ) ;
return V_4 ;
}
}
F_77 ( & V_439 , V_385 ) ;
return NULL ;
}
static int
F_149 ( struct V_440 * V_441 , T_5 V_442 , T_7 V_443 )
{
return F_150 ( V_444 , V_441 , 0 , V_442 , V_443 ) ;
}
int F_151 ( struct V_380 * V_381 , struct V_445 * V_446 ,
char * V_12 , T_5 V_447 )
{
struct V_448 * V_449 ;
struct V_440 * V_441 ;
struct V_450 * V_451 ;
char * V_452 ;
struct V_3 * V_4 ;
int V_453 = F_152 ( sizeof( * V_451 ) + sizeof( struct V_445 ) +
V_447 ) ;
V_4 = F_148 ( V_381 -> V_34 ) ;
if ( ! V_4 )
return - V_454 ;
V_441 = F_153 ( V_453 , V_455 ) ;
if ( ! V_441 ) {
F_154 ( V_381 , V_456 ) ;
F_155 ( V_18 , V_381 , L_44
L_45 ) ;
return - V_372 ;
}
V_449 = F_156 ( V_441 , 0 , 0 , 0 , ( V_453 - sizeof( * V_449 ) ) , 0 ) ;
V_451 = F_157 ( V_449 ) ;
memset ( V_451 , 0 , sizeof( * V_451 ) ) ;
V_451 -> V_457 = F_5 ( V_381 -> V_34 ) ;
V_451 -> type = V_458 ;
V_451 -> V_459 . V_460 . V_387 = V_381 -> V_387 ;
V_451 -> V_459 . V_460 . V_384 = F_72 ( V_381 ) ;
V_452 = ( char * ) V_451 + sizeof( * V_451 ) ;
memcpy ( V_452 , V_446 , sizeof( struct V_445 ) ) ;
memcpy ( V_452 + sizeof( struct V_445 ) , V_12 , V_447 ) ;
return F_149 ( V_441 , V_461 , V_455 ) ;
}
int F_158 ( struct V_188 * V_189 ,
struct V_8 * V_34 , T_5 type ,
char * V_12 , T_8 V_447 )
{
struct V_448 * V_449 ;
struct V_440 * V_441 ;
struct V_450 * V_451 ;
int V_453 = F_152 ( sizeof( * V_451 ) + V_447 ) ;
V_441 = F_153 ( V_453 , V_455 ) ;
if ( ! V_441 ) {
F_13 ( V_18 L_46 ) ;
return - V_372 ;
}
V_449 = F_156 ( V_441 , 0 , 0 , 0 , ( V_453 - sizeof( * V_449 ) ) , 0 ) ;
V_451 = F_157 ( V_449 ) ;
memset ( V_451 , 0 , sizeof( * V_451 ) ) ;
V_451 -> type = type ;
V_451 -> V_457 = F_5 ( V_34 ) ;
switch ( type ) {
case V_462 :
V_451 -> V_459 . V_463 . V_194 = V_189 -> V_194 ;
break;
case V_464 :
V_451 -> V_459 . V_465 . V_194 = V_189 -> V_194 ;
break;
}
memcpy ( ( char * ) V_451 + sizeof( * V_451 ) , V_12 , V_447 ) ;
return F_149 ( V_441 , V_466 , V_455 ) ;
}
void F_154 ( struct V_380 * V_381 , enum V_467 error )
{
struct V_448 * V_449 ;
struct V_440 * V_441 ;
struct V_450 * V_451 ;
struct V_3 * V_4 ;
int V_453 = F_152 ( sizeof( * V_451 ) ) ;
V_4 = F_148 ( V_381 -> V_34 ) ;
if ( ! V_4 )
return;
V_441 = F_153 ( V_453 , V_455 ) ;
if ( ! V_441 ) {
F_155 ( V_18 , V_381 , L_47
L_48 , error ) ;
return;
}
V_449 = F_156 ( V_441 , 0 , 0 , 0 , ( V_453 - sizeof( * V_449 ) ) , 0 ) ;
V_451 = F_157 ( V_449 ) ;
V_451 -> V_457 = F_5 ( V_381 -> V_34 ) ;
V_451 -> type = V_468 ;
V_451 -> V_459 . V_469 . error = error ;
V_451 -> V_459 . V_469 . V_387 = V_381 -> V_387 ;
V_451 -> V_459 . V_469 . V_384 = F_72 ( V_381 ) ;
F_149 ( V_441 , V_461 , V_455 ) ;
F_155 ( V_412 , V_381 , L_49 ,
error ) ;
}
void F_159 ( struct V_380 * V_381 ,
enum V_470 V_181 )
{
struct V_448 * V_449 ;
struct V_440 * V_441 ;
struct V_450 * V_451 ;
struct V_3 * V_4 ;
int V_453 = F_152 ( sizeof( * V_451 ) ) ;
V_4 = F_148 ( V_381 -> V_34 ) ;
if ( ! V_4 )
return;
V_441 = F_153 ( V_453 , V_455 ) ;
if ( ! V_441 ) {
F_155 ( V_18 , V_381 , L_47
L_50 , V_181 ) ;
return;
}
V_449 = F_156 ( V_441 , 0 , 0 , 0 , ( V_453 - sizeof( * V_449 ) ) , 0 ) ;
V_451 = F_157 ( V_449 ) ;
V_451 -> V_457 = F_5 ( V_381 -> V_34 ) ;
V_451 -> type = V_471 ;
V_451 -> V_459 . V_472 . V_181 = V_181 ;
V_451 -> V_459 . V_472 . V_387 = V_381 -> V_387 ;
V_451 -> V_459 . V_472 . V_384 = F_72 ( V_381 ) ;
F_149 ( V_441 , V_461 , V_455 ) ;
F_155 ( V_412 , V_381 , L_51 ,
V_181 ) ;
}
void F_160 ( T_5 V_194 , struct V_8 * V_34 ,
enum V_473 V_474 , T_5 V_447 ,
T_9 * V_12 )
{
struct V_448 * V_449 ;
struct V_440 * V_441 ;
struct V_450 * V_451 ;
int V_453 = F_152 ( sizeof( * V_451 ) + V_447 ) ;
V_441 = F_153 ( V_453 , V_475 ) ;
if ( ! V_441 ) {
F_13 ( V_18 L_52 ,
V_194 , V_474 ) ;
return;
}
V_449 = F_156 ( V_441 , 0 , 0 , 0 , ( V_453 - sizeof( * V_449 ) ) , 0 ) ;
V_451 = F_157 ( V_449 ) ;
V_451 -> V_457 = F_5 ( V_34 ) ;
V_451 -> type = V_476 ;
V_451 -> V_459 . V_477 . V_194 = V_194 ;
V_451 -> V_459 . V_477 . V_474 = V_474 ;
V_451 -> V_459 . V_477 . V_447 = V_447 ;
if ( V_447 )
memcpy ( ( char * ) V_451 + sizeof( * V_451 ) , V_12 , V_447 ) ;
F_149 ( V_441 , V_461 , V_475 ) ;
}
void F_161 ( T_5 V_194 , struct V_8 * V_34 ,
T_5 V_478 , T_5 V_479 , T_5 V_447 ,
T_9 * V_12 )
{
struct V_448 * V_449 ;
struct V_440 * V_441 ;
struct V_450 * V_451 ;
int V_453 = F_152 ( sizeof( * V_451 ) + V_447 ) ;
V_441 = F_153 ( V_453 , V_475 ) ;
if ( ! V_441 ) {
F_13 ( V_18 L_53 ) ;
return;
}
V_449 = F_156 ( V_441 , 0 , 0 , 0 , ( V_453 - sizeof( * V_449 ) ) , 0 ) ;
V_451 = F_157 ( V_449 ) ;
V_451 -> V_457 = F_5 ( V_34 ) ;
V_451 -> type = V_480 ;
V_451 -> V_459 . V_481 . V_194 = V_194 ;
V_451 -> V_459 . V_481 . V_478 = V_478 ;
V_451 -> V_459 . V_481 . V_479 = V_479 ;
V_451 -> V_459 . V_481 . V_447 = V_447 ;
memcpy ( ( char * ) V_451 + sizeof( * V_451 ) , V_12 , V_447 ) ;
F_149 ( V_441 , V_461 , V_475 ) ;
}
static int
F_162 ( T_5 V_442 , int V_482 , int type , int V_483 , int V_484 ,
void * V_485 , int V_486 )
{
struct V_440 * V_441 ;
struct V_448 * V_449 ;
int V_453 = F_152 ( V_486 ) ;
int V_385 = V_484 ? V_487 : 0 ;
int V_33 = V_483 ? V_488 : type ;
V_441 = F_153 ( V_453 , V_455 ) ;
if ( ! V_441 ) {
F_13 ( V_18 L_54 ) ;
return - V_372 ;
}
V_449 = F_156 ( V_441 , 0 , 0 , V_33 , ( V_453 - sizeof( * V_449 ) ) , 0 ) ;
V_449 -> V_489 = V_385 ;
memcpy ( F_157 ( V_449 ) , V_485 , V_486 ) ;
return F_149 ( V_441 , V_442 , V_455 ) ;
}
static int
F_163 ( struct V_8 * V_34 , struct V_448 * V_449 )
{
struct V_450 * V_451 = F_157 ( V_449 ) ;
struct V_490 * V_491 ;
struct V_440 * V_492 ;
struct V_380 * V_381 ;
struct V_448 * V_493 ;
struct V_450 * V_494 ;
struct V_3 * V_4 ;
int V_453 = F_152 ( sizeof( * V_451 ) +
sizeof( struct V_490 ) +
sizeof( struct V_495 ) *
V_496 ) ;
int V_15 = 0 ;
V_4 = F_148 ( V_34 ) ;
if ( ! V_4 )
return - V_454 ;
V_381 = F_78 ( V_451 -> V_497 . V_498 . V_384 , V_451 -> V_497 . V_498 . V_387 ) ;
if ( ! V_381 )
return - V_499 ;
do {
int V_500 ;
V_492 = F_153 ( V_453 , V_455 ) ;
if ( ! V_492 ) {
F_155 ( V_18 , V_381 , L_55
L_56 ) ;
return - V_372 ;
}
V_493 = F_156 ( V_492 , 0 , 0 , 0 ,
( V_453 - sizeof( * V_493 ) ) , 0 ) ;
V_494 = F_157 ( V_493 ) ;
memset ( V_494 , 0 , sizeof( * V_494 ) ) ;
V_494 -> V_457 = F_5 ( V_381 -> V_34 ) ;
V_494 -> type = V_449 -> V_501 ;
V_494 -> V_497 . V_498 . V_387 =
V_451 -> V_497 . V_498 . V_387 ;
V_494 -> V_497 . V_498 . V_384 =
V_451 -> V_497 . V_498 . V_384 ;
V_491 = (struct V_490 * )
( ( char * ) V_494 + sizeof( * V_494 ) ) ;
memset ( V_491 , 0 , sizeof( * V_491 ) ) ;
V_34 -> V_498 ( V_381 , V_491 ) ;
V_500 = F_152 ( sizeof( struct V_450 ) +
sizeof( struct V_490 ) +
sizeof( struct V_495 ) *
V_491 -> V_502 ) ;
V_500 -= sizeof( * V_493 ) ;
V_500 = F_164 ( V_500 ) ;
F_165 ( V_492 , F_166 ( V_500 ) ) ;
V_493 -> V_503 = V_500 ;
V_15 = F_149 ( V_492 , V_461 ,
V_455 ) ;
} while ( V_15 < 0 && V_15 != - V_504 );
return V_15 ;
}
int F_119 ( struct V_382 * V_390 ,
enum V_505 V_506 )
{
struct V_3 * V_4 ;
struct V_188 * V_189 ;
struct V_450 * V_451 ;
struct V_440 * V_441 ;
struct V_448 * V_449 ;
int V_507 , V_453 = F_152 ( sizeof( * V_451 ) ) ;
V_4 = F_148 ( V_390 -> V_34 ) ;
if ( ! V_4 )
return - V_454 ;
V_189 = F_83 ( V_390 ) ;
V_441 = F_153 ( V_453 , V_19 ) ;
if ( ! V_441 ) {
F_103 ( V_18 , V_390 ,
L_57
L_58 , V_506 ) ;
return - V_372 ;
}
V_449 = F_156 ( V_441 , 0 , 0 , 0 , ( V_453 - sizeof( * V_449 ) ) , 0 ) ;
V_451 = F_157 ( V_449 ) ;
V_451 -> V_457 = F_5 ( V_390 -> V_34 ) ;
V_451 -> type = V_506 ;
switch ( V_506 ) {
case V_432 :
V_451 -> V_459 . V_508 . V_194 = V_189 -> V_194 ;
V_451 -> V_459 . V_508 . V_384 = V_390 -> V_384 ;
break;
case V_431 :
V_451 -> V_459 . V_509 . V_194 = V_189 -> V_194 ;
V_451 -> V_459 . V_509 . V_384 = V_390 -> V_384 ;
break;
case V_424 :
V_451 -> V_459 . V_510 . V_194 = V_189 -> V_194 ;
V_451 -> V_459 . V_510 . V_384 = V_390 -> V_384 ;
break;
default:
F_103 ( V_18 , V_390 , L_59
L_60 , V_506 ) ;
F_167 ( V_441 ) ;
return - V_454 ;
}
V_507 = F_149 ( V_441 , V_461 , V_19 ) ;
if ( V_507 == - V_359 )
F_103 ( V_18 , V_390 ,
L_57
L_61 ,
V_506 ) ;
F_85 ( V_390 , L_62 ,
V_506 , V_507 ) ;
return V_507 ;
}
static int
F_168 ( struct V_3 * V_4 , struct V_9 * V_10 ,
struct V_450 * V_451 , T_10 V_479 ,
T_5 V_511 , T_8 V_512 ,
T_8 V_513 )
{
struct V_8 * V_34 = V_4 -> V_8 ;
struct V_382 * V_390 ;
struct V_188 * V_189 ;
V_390 = V_34 -> V_514 ( V_10 , V_512 , V_513 ,
V_511 ) ;
if ( ! V_390 )
return - V_372 ;
V_390 -> V_425 = V_479 ;
V_189 = F_83 ( V_390 ) ;
V_451 -> V_459 . V_509 . V_194 = V_189 -> V_194 ;
V_451 -> V_459 . V_509 . V_384 = V_390 -> V_384 ;
F_85 ( V_390 ,
L_63 ) ;
return 0 ;
}
static int
F_169 ( struct V_8 * V_34 , struct V_450 * V_451 )
{
struct V_380 * V_381 ;
struct V_382 * V_390 ;
V_390 = F_74 ( V_451 -> V_497 . V_515 . V_384 ) ;
if ( ! V_390 ) {
F_13 ( V_18 L_64 ,
V_451 -> V_497 . V_515 . V_384 ) ;
return - V_454 ;
}
V_381 = V_34 -> V_516 ( V_390 , V_451 -> V_497 . V_515 . V_387 ) ;
if ( ! V_381 ) {
F_103 ( V_18 , V_390 ,
L_65 ) ;
return - V_372 ;
}
V_451 -> V_459 . V_517 . V_384 = V_390 -> V_384 ;
V_451 -> V_459 . V_517 . V_387 = V_381 -> V_387 ;
F_137 ( V_381 , L_66 ) ;
return 0 ;
}
static int
F_170 ( struct V_8 * V_34 , struct V_450 * V_451 )
{
struct V_380 * V_381 ;
V_381 = F_78 ( V_451 -> V_497 . V_518 . V_384 , V_451 -> V_497 . V_518 . V_387 ) ;
if ( ! V_381 )
return - V_454 ;
F_137 ( V_381 , L_67 ) ;
if ( V_34 -> V_519 )
V_34 -> V_519 ( V_381 ) ;
return 0 ;
}
static int
F_171 ( struct V_8 * V_34 , struct V_450 * V_451 )
{
char * V_12 = ( char * ) V_451 + sizeof( * V_451 ) ;
struct V_380 * V_381 ;
struct V_382 * V_390 ;
int V_15 = 0 , V_183 = 0 ;
V_390 = F_74 ( V_451 -> V_497 . V_520 . V_384 ) ;
V_381 = F_78 ( V_451 -> V_497 . V_520 . V_384 , V_451 -> V_497 . V_520 . V_387 ) ;
if ( ! V_381 || ! V_390 )
return - V_454 ;
switch ( V_451 -> V_497 . V_520 . V_35 ) {
case V_521 :
sscanf ( V_12 , L_68 , & V_183 ) ;
if ( ! V_390 -> V_426 )
V_390 -> V_413 = V_183 ;
break;
default:
V_15 = V_34 -> V_520 ( V_381 , V_451 -> V_497 . V_520 . V_35 ,
V_12 , V_451 -> V_497 . V_520 . V_453 ) ;
}
return V_15 ;
}
static int F_172 ( struct V_8 * V_34 ,
struct V_450 * V_451 , int V_522 )
{
struct V_9 * V_10 ;
struct V_523 * V_524 ;
struct V_188 * V_189 = NULL ;
int V_525 , V_15 = 0 ;
if ( ! V_34 -> V_526 )
return - V_454 ;
if ( V_522 == V_527 ) {
V_189 = F_173 ( V_451 -> V_497 . V_528 . V_194 ) ;
if ( ! V_189 ) {
F_13 ( V_18 L_69
L_70 ,
V_451 -> V_497 . V_528 . V_194 ) ;
return - V_529 ;
}
V_525 = V_451 -> V_497 . V_528 . V_525 ;
} else
V_525 = V_451 -> V_497 . V_526 . V_525 ;
V_524 = (struct V_523 * ) ( ( char * ) V_451 + sizeof( * V_451 ) ) ;
V_10 = V_34 -> V_526 ( V_189 , V_524 , V_525 ) ;
if ( F_174 ( V_10 ) ) {
V_15 = F_175 ( V_10 ) ;
goto V_530;
}
V_451 -> V_459 . V_531 . V_26 = V_10 -> V_11 ;
V_530:
if ( V_189 )
F_84 ( V_189 ) ;
return V_15 ;
}
static int F_176 ( struct V_8 * V_34 ,
T_3 V_532 )
{
struct V_380 * V_381 ;
struct V_9 * V_10 ;
if ( ! V_34 -> V_533 )
return - V_454 ;
V_10 = F_21 ( V_532 ) ;
if ( ! V_10 )
return - V_454 ;
V_381 = V_10 -> V_381 ;
if ( V_381 ) {
F_92 ( & V_381 -> V_433 ) ;
V_381 -> V_10 = NULL ;
F_94 ( & V_381 -> V_433 ) ;
}
V_34 -> V_533 ( V_10 ) ;
return 0 ;
}
static int
F_177 ( struct V_8 * V_34 ,
struct V_450 * V_451 , int V_522 )
{
struct V_9 * V_10 ;
int V_507 = 0 ;
switch ( V_522 ) {
case V_527 :
case V_534 :
V_507 = F_172 ( V_34 , V_451 , V_522 ) ;
break;
case V_535 :
if ( ! V_34 -> V_536 )
return - V_454 ;
V_10 = F_21 ( V_451 -> V_497 . V_536 . V_532 ) ;
if ( ! V_10 )
return - V_454 ;
V_451 -> V_459 . V_537 = V_34 -> V_536 ( V_10 ,
V_451 -> V_497 . V_536 . V_538 ) ;
break;
case V_539 :
V_507 = F_176 ( V_34 ,
V_451 -> V_497 . V_533 . V_532 ) ;
break;
}
return V_507 ;
}
static int
F_178 ( struct V_8 * V_34 ,
struct V_450 * V_451 )
{
struct V_188 * V_189 ;
struct V_523 * V_524 ;
int V_15 ;
if ( ! V_34 -> V_540 )
return - V_454 ;
V_189 = F_173 ( V_451 -> V_497 . V_540 . V_194 ) ;
if ( ! V_189 ) {
F_13 ( V_18 L_71 ,
V_451 -> V_497 . V_540 . V_194 ) ;
return - V_529 ;
}
V_524 = (struct V_523 * ) ( ( char * ) V_451 + sizeof( * V_451 ) ) ;
V_15 = V_34 -> V_540 ( V_189 , V_451 -> V_497 . V_540 . type ,
V_451 -> V_497 . V_540 . V_541 , V_524 ) ;
F_84 ( V_189 ) ;
return V_15 ;
}
static int
F_179 ( struct V_8 * V_34 ,
struct V_450 * V_451 )
{
char * V_12 = ( char * ) V_451 + sizeof( * V_451 ) ;
struct V_188 * V_189 ;
int V_15 ;
if ( ! V_34 -> V_542 )
return - V_543 ;
V_189 = F_173 ( V_451 -> V_497 . V_542 . V_194 ) ;
if ( ! V_189 ) {
F_13 ( V_18 L_72 ,
V_451 -> V_497 . V_542 . V_194 ) ;
return - V_529 ;
}
V_15 = V_34 -> V_542 ( V_189 , V_451 -> V_497 . V_542 . V_35 ,
V_12 , V_451 -> V_497 . V_542 . V_453 ) ;
F_84 ( V_189 ) ;
return V_15 ;
}
static int
F_180 ( struct V_8 * V_34 , struct V_450 * V_451 )
{
struct V_188 * V_189 ;
struct V_544 * V_545 ;
int V_15 ;
if ( ! V_34 -> V_546 )
return - V_543 ;
V_189 = F_173 ( V_451 -> V_497 . V_546 . V_194 ) ;
if ( ! V_189 ) {
F_13 ( V_18 L_73 ,
V_451 -> V_497 . V_546 . V_194 ) ;
return - V_529 ;
}
V_545 = (struct V_544 * ) ( ( char * ) V_451 + sizeof( * V_451 ) ) ;
V_15 = V_34 -> V_546 ( V_189 , V_545 ) ;
F_84 ( V_189 ) ;
return V_15 ;
}
static int
F_181 ( struct V_8 * V_34 ,
struct V_450 * V_451 , T_5 V_453 )
{
char * V_12 = ( char * ) V_451 + sizeof( * V_451 ) ;
struct V_188 * V_189 ;
int V_15 ;
if ( ! V_34 -> V_547 )
return - V_543 ;
V_189 = F_173 ( V_451 -> V_497 . V_548 . V_194 ) ;
if ( ! V_189 ) {
F_13 ( V_18 L_74 ,
V_451 -> V_497 . V_548 . V_194 ) ;
return - V_529 ;
}
V_15 = V_34 -> V_547 ( V_189 , V_12 , V_453 ) ;
F_84 ( V_189 ) ;
return V_15 ;
}
static int
F_182 ( struct V_8 * V_34 , struct V_450 * V_451 )
{
struct V_188 * V_189 ;
struct V_523 * V_524 ;
int V_15 ;
if ( ! V_34 -> V_549 )
return - V_543 ;
V_189 = F_173 ( V_451 -> V_497 . V_550 . V_194 ) ;
if ( ! V_189 ) {
F_13 ( V_18 L_75 ,
V_451 -> V_497 . V_550 . V_194 ) ;
return - V_529 ;
}
V_524 = (struct V_523 * ) ( ( char * ) V_451 + sizeof( * V_451 ) ) ;
V_15 = V_34 -> V_549 ( V_189 , V_451 -> V_497 . V_550 . V_190 ,
V_451 -> V_497 . V_550 . V_103 ,
V_451 -> V_497 . V_550 . V_551 ,
V_451 -> V_497 . V_550 . V_479 ,
V_524 ) ;
F_84 ( V_189 ) ;
return V_15 ;
}
static int
F_183 ( struct V_8 * V_34 , struct V_448 * V_449 )
{
struct V_450 * V_451 = F_157 ( V_449 ) ;
struct V_188 * V_189 = NULL ;
struct V_552 * V_553 ;
struct V_3 * V_4 ;
struct V_440 * V_554 ;
struct V_448 * V_555 ;
struct V_450 * V_556 ;
T_5 V_557 ;
int V_453 , V_15 = 0 ;
char * V_7 ;
if ( ! V_34 -> V_558 )
return - V_454 ;
V_4 = F_148 ( V_34 ) ;
if ( ! V_4 )
return - V_454 ;
V_557 = ( V_451 -> V_497 . V_558 . V_559 * sizeof( * V_553 ) ) ;
V_453 = F_152 ( sizeof( * V_451 ) + V_557 ) ;
V_189 = F_173 ( V_451 -> V_497 . V_558 . V_194 ) ;
if ( ! V_189 ) {
F_13 ( V_18 L_76 ,
V_560 , V_451 -> V_497 . V_558 . V_194 ) ;
return - V_529 ;
}
do {
int V_500 ;
V_554 = F_153 ( V_453 , V_19 ) ;
if ( ! V_554 ) {
F_13 ( V_18 L_77 ) ;
V_15 = - V_372 ;
goto V_561;
}
V_555 = F_156 ( V_554 , 0 , 0 , 0 ,
( V_453 - sizeof( * V_555 ) ) , 0 ) ;
V_556 = F_157 ( V_555 ) ;
memset ( V_556 , 0 , sizeof( * V_556 ) ) ;
V_556 -> V_457 = F_5 ( V_34 ) ;
V_556 -> type = V_449 -> V_501 ;
V_556 -> V_497 . V_558 . V_194 = V_451 -> V_497 . V_558 . V_194 ;
V_556 -> V_497 . V_558 . V_562 = V_451 -> V_497 . V_558 . V_562 ;
V_556 -> V_497 . V_558 . V_559 = V_451 -> V_497 . V_558 . V_559 ;
V_7 = ( char * ) V_556 + sizeof( * V_556 ) ;
memset ( V_7 , 0 , V_557 ) ;
V_15 = V_34 -> V_558 ( V_189 , V_451 -> V_497 . V_558 . V_562 ,
& V_556 -> V_497 . V_558 . V_559 , V_7 ) ;
V_500 = F_152 ( sizeof( * V_451 ) + V_557 ) ;
F_165 ( V_554 , F_166 ( V_500 ) ) ;
V_555 -> V_503 = V_500 ;
V_15 = F_149 ( V_554 , V_461 ,
V_19 ) ;
} while ( V_15 < 0 && V_15 != - V_504 );
V_561:
F_84 ( V_189 ) ;
return V_15 ;
}
static int F_184 ( struct V_8 * V_34 ,
struct V_450 * V_451 , T_5 V_453 )
{
char * V_12 = ( char * ) V_451 + sizeof( * V_451 ) ;
struct V_188 * V_189 ;
int V_15 = 0 ;
if ( ! V_34 -> V_563 )
return - V_543 ;
V_189 = F_173 ( V_451 -> V_497 . V_546 . V_194 ) ;
if ( ! V_189 ) {
F_53 ( L_78 ,
V_560 , V_451 -> V_497 . V_546 . V_194 ) ;
return - V_529 ;
}
V_15 = V_34 -> V_563 ( V_189 , V_12 , V_453 ) ;
F_84 ( V_189 ) ;
return V_15 ;
}
static int F_185 ( struct V_8 * V_34 ,
struct V_450 * V_451 )
{
struct V_188 * V_189 ;
int V_15 = 0 ;
if ( ! V_34 -> V_564 )
return - V_543 ;
V_189 = F_173 ( V_451 -> V_497 . V_564 . V_194 ) ;
if ( ! V_189 ) {
F_13 ( V_18 L_78 ,
V_560 , V_451 -> V_497 . V_564 . V_194 ) ;
return - V_529 ;
}
V_15 = V_34 -> V_564 ( V_189 , V_451 -> V_497 . V_564 . V_562 ) ;
F_84 ( V_189 ) ;
return V_15 ;
}
char * F_186 ( int V_565 )
{
int V_32 ;
char * V_181 = L_79 ;
for ( V_32 = 0 ; V_32 < F_28 ( V_566 ) ; V_32 ++ ) {
if ( V_566 [ V_32 ] . V_183 & V_565 ) {
V_181 = V_566 [ V_32 ] . V_184 ;
break;
}
}
return V_181 ;
}
static int F_187 ( struct V_8 * V_34 ,
struct V_450 * V_451 , T_5 V_453 )
{
char * V_12 = ( char * ) V_451 + sizeof( * V_451 ) ;
struct V_188 * V_189 ;
struct V_198 * V_199 ;
struct V_270 * V_271 ;
struct V_1 * V_2 ;
T_5 V_339 ;
int V_15 = 0 ;
if ( ! V_34 -> V_567 ) {
V_15 = - V_543 ;
goto V_568;
}
V_189 = F_173 ( V_451 -> V_497 . V_569 . V_194 ) ;
if ( ! V_189 ) {
F_53 ( L_78 ,
V_560 , V_451 -> V_497 . V_569 . V_194 ) ;
V_15 = - V_529 ;
goto V_570;
}
V_339 = V_451 -> V_497 . V_569 . V_571 ;
V_199 = F_45 ( V_189 , V_339 ) ;
if ( ! V_199 ) {
F_53 ( L_80 ,
V_560 , V_339 , V_451 -> V_497 . V_569 . V_194 ) ;
V_15 = - V_529 ;
goto V_570;
}
V_2 = F_49 ( V_199 ) ;
if ( ! V_2 ) {
V_15 = - V_529 ;
goto V_572;
}
V_271 = F_37 ( V_2 ) ;
V_15 = V_34 -> V_567 ( V_199 , V_271 , V_12 , V_453 ) ;
F_12 ( V_2 ) ;
V_572:
F_12 ( & V_199 -> V_2 ) ;
V_570:
F_84 ( V_189 ) ;
V_568:
return V_15 ;
}
static int F_188 ( struct V_8 * V_34 ,
struct V_450 * V_451 , T_5 V_453 )
{
char * V_12 = ( char * ) V_451 + sizeof( * V_451 ) ;
struct V_188 * V_189 ;
int V_331 ;
int V_15 = 0 ;
if ( ! V_34 -> V_573 ) {
V_15 = - V_543 ;
goto V_574;
}
V_189 = F_173 ( V_451 -> V_497 . V_573 . V_194 ) ;
if ( ! V_189 ) {
F_53 ( L_78 ,
V_560 , V_451 -> V_497 . V_573 . V_194 ) ;
V_15 = - V_529 ;
goto V_570;
}
V_331 = V_34 -> V_573 ( V_189 , V_12 , V_453 ) ;
if ( V_331 >= 0 )
V_451 -> V_459 . V_575 . V_571 = V_331 ;
else
V_15 = - V_576 ;
V_570:
F_84 ( V_189 ) ;
V_574:
return V_15 ;
}
static int F_189 ( struct V_8 * V_34 ,
struct V_450 * V_451 )
{
struct V_188 * V_189 ;
struct V_198 * V_199 ;
T_5 V_339 ;
int V_15 = 0 ;
if ( ! V_34 -> V_577 ) {
V_15 = - V_543 ;
goto V_578;
}
V_189 = F_173 ( V_451 -> V_497 . V_577 . V_194 ) ;
if ( ! V_189 ) {
F_53 ( L_78 ,
V_560 , V_451 -> V_497 . V_577 . V_194 ) ;
V_15 = - V_529 ;
goto V_570;
}
V_339 = V_451 -> V_497 . V_577 . V_571 ;
V_199 = F_45 ( V_189 , V_339 ) ;
if ( ! V_199 ) {
F_53 ( L_80 ,
V_560 , V_339 , V_451 -> V_497 . V_577 . V_194 ) ;
V_15 = - V_529 ;
goto V_570;
}
V_15 = V_34 -> V_577 ( V_199 ) ;
F_12 ( & V_199 -> V_2 ) ;
V_570:
F_84 ( V_189 ) ;
V_578:
return V_15 ;
}
static int F_190 ( struct V_8 * V_34 ,
struct V_450 * V_451 )
{
struct V_188 * V_189 ;
struct V_198 * V_199 ;
struct V_270 * V_271 ;
struct V_1 * V_2 ;
T_5 V_339 ;
int V_15 = 0 ;
if ( ! V_34 -> V_579 ) {
V_15 = - V_543 ;
goto V_580;
}
V_189 = F_173 ( V_451 -> V_497 . V_579 . V_194 ) ;
if ( ! V_189 ) {
F_53 ( L_78 ,
V_560 , V_451 -> V_497 . V_579 . V_194 ) ;
V_15 = - V_529 ;
goto V_570;
}
V_339 = V_451 -> V_497 . V_579 . V_571 ;
V_199 = F_45 ( V_189 , V_339 ) ;
if ( ! V_199 ) {
F_53 ( L_80 ,
V_560 , V_339 , V_451 -> V_497 . V_579 . V_194 ) ;
V_15 = - V_529 ;
goto V_570;
}
V_2 = F_49 ( V_199 ) ;
if ( ! V_2 ) {
V_15 = - V_529 ;
goto V_572;
}
V_271 = F_37 ( V_2 ) ;
V_15 = V_34 -> V_579 ( V_199 , V_271 ) ;
F_12 ( V_2 ) ;
V_572:
F_12 ( & V_199 -> V_2 ) ;
V_570:
F_84 ( V_189 ) ;
V_580:
return V_15 ;
}
static int F_191 ( struct V_8 * V_34 ,
struct V_450 * V_451 )
{
struct V_188 * V_189 ;
struct V_198 * V_199 ;
struct V_270 * V_271 ;
struct V_1 * V_2 ;
T_5 V_339 ;
int V_15 = 0 ;
if ( ! V_34 -> V_581 ) {
V_15 = - V_543 ;
goto V_582;
}
V_189 = F_173 ( V_451 -> V_497 . V_581 . V_194 ) ;
if ( ! V_189 ) {
F_53 ( L_78 ,
V_560 , V_451 -> V_497 . V_581 . V_194 ) ;
V_15 = - V_529 ;
goto V_570;
}
V_339 = V_451 -> V_497 . V_581 . V_571 ;
V_199 = F_45 ( V_189 , V_339 ) ;
if ( ! V_199 ) {
F_53 ( L_80 ,
V_560 , V_339 , V_451 -> V_497 . V_581 . V_194 ) ;
V_15 = - V_529 ;
goto V_570;
}
V_2 = F_49 ( V_199 ) ;
if ( ! V_2 ) {
V_15 = - V_529 ;
goto V_572;
}
V_271 = F_37 ( V_2 ) ;
V_15 = V_34 -> V_581 ( V_199 , V_271 ) ;
F_12 ( V_2 ) ;
V_572:
F_12 ( & V_199 -> V_2 ) ;
V_570:
F_84 ( V_189 ) ;
V_582:
return V_15 ;
}
static int F_192 ( struct V_8 * V_34 ,
struct V_450 * V_451 )
{
struct V_188 * V_189 ;
struct V_382 * V_390 ;
int V_15 = 0 ;
if ( ! V_34 -> V_583 ) {
V_15 = - V_543 ;
goto V_584;
}
V_189 = F_173 ( V_451 -> V_497 . V_583 . V_194 ) ;
if ( ! V_189 ) {
F_53 ( L_78 ,
V_560 , V_451 -> V_497 . V_581 . V_194 ) ;
V_15 = - V_529 ;
goto V_570;
}
V_390 = F_74 ( V_451 -> V_497 . V_583 . V_384 ) ;
if ( ! V_390 ) {
F_53 ( L_81 ,
V_560 , V_451 -> V_497 . V_583 . V_384 ) ;
V_15 = - V_454 ;
goto V_570;
}
V_15 = V_34 -> V_583 ( V_390 ) ;
V_570:
F_84 ( V_189 ) ;
V_584:
return V_15 ;
}
static int
F_193 ( struct V_8 * V_34 , struct V_448 * V_449 )
{
struct V_450 * V_451 = F_157 ( V_449 ) ;
struct V_188 * V_189 = NULL ;
struct V_3 * V_4 ;
struct V_440 * V_585 ;
struct V_448 * V_586 ;
struct V_450 * V_587 ;
int V_588 = 0 ;
int V_453 , V_15 = 0 ;
char * V_7 ;
if ( ! V_34 -> V_589 )
return - V_543 ;
V_4 = F_148 ( V_34 ) ;
if ( ! V_4 )
return - V_454 ;
V_588 = sizeof( struct V_590 ) ;
V_453 = F_152 ( sizeof( * V_451 ) + V_588 ) ;
V_189 = F_173 ( V_451 -> V_497 . V_589 . V_194 ) ;
if ( ! V_189 ) {
F_53 ( L_82 ,
V_560 , V_451 -> V_497 . V_589 . V_194 ) ;
return - V_529 ;
}
do {
int V_500 ;
V_585 = F_153 ( V_453 , V_19 ) ;
if ( ! V_585 ) {
F_53 ( L_83 ) ;
V_15 = - V_372 ;
goto V_591;
}
V_586 = F_156 ( V_585 , 0 , 0 , 0 ,
( V_453 - sizeof( * V_586 ) ) , 0 ) ;
V_587 = F_157 ( V_586 ) ;
memset ( V_587 , 0 , sizeof( * V_587 ) ) ;
V_587 -> V_457 = F_5 ( V_34 ) ;
V_587 -> type = V_449 -> V_501 ;
V_587 -> V_497 . V_589 . V_194 =
V_451 -> V_497 . V_589 . V_194 ;
V_7 = ( char * ) V_587 + sizeof( * V_587 ) ;
memset ( V_7 , 0 , V_588 ) ;
V_15 = V_34 -> V_589 ( V_189 , V_7 , V_588 ) ;
if ( V_15 ) {
F_167 ( V_585 ) ;
goto V_591;
}
V_500 = F_152 ( sizeof( * V_451 ) + V_588 ) ;
F_165 ( V_585 , F_166 ( V_500 ) ) ;
V_586 -> V_503 = V_500 ;
V_15 = F_149 ( V_585 , V_461 ,
V_19 ) ;
} while ( V_15 < 0 && V_15 != - V_504 );
V_591:
F_84 ( V_189 ) ;
return V_15 ;
}
static int
F_194 ( struct V_440 * V_441 , struct V_448 * V_449 , T_5 * V_442 )
{
int V_15 = 0 ;
struct V_450 * V_451 = F_157 ( V_449 ) ;
struct V_8 * V_34 = NULL ;
struct V_3 * V_4 ;
struct V_382 * V_390 ;
struct V_380 * V_381 ;
struct V_9 * V_10 = NULL ;
if ( V_449 -> V_501 == V_592 )
* V_442 = V_466 ;
else
* V_442 = V_461 ;
V_4 = F_148 ( F_195 ( V_451 -> V_457 ) ) ;
if ( ! V_4 )
return - V_454 ;
V_34 = V_4 -> V_8 ;
if ( ! F_196 ( V_34 -> V_593 ) )
return - V_454 ;
switch ( V_449 -> V_501 ) {
case V_594 :
V_15 = F_168 ( V_4 , V_10 , V_451 ,
F_197 ( V_441 ) . V_595 ,
V_451 -> V_497 . V_596 . V_511 ,
V_451 -> V_497 . V_596 . V_512 ,
V_451 -> V_497 . V_596 . V_513 ) ;
break;
case V_597 :
V_10 = F_21 ( V_451 -> V_497 . V_598 . V_532 ) ;
if ( ! V_10 ) {
V_15 = - V_454 ;
break;
}
V_15 = F_168 ( V_4 , V_10 , V_451 ,
F_197 ( V_441 ) . V_595 ,
V_451 -> V_497 . V_598 . V_511 ,
V_451 -> V_497 . V_598 . V_512 ,
V_451 -> V_497 . V_598 . V_513 ) ;
break;
case V_599 :
V_390 = F_74 ( V_451 -> V_497 . V_508 . V_384 ) ;
if ( V_390 )
V_34 -> V_600 ( V_390 ) ;
else
V_15 = - V_454 ;
break;
case V_601 :
V_390 = F_74 ( V_451 -> V_497 . V_508 . V_384 ) ;
if ( V_390 )
F_107 ( F_83 ( V_390 ) ,
& V_390 -> V_421 ) ;
else
V_15 = - V_454 ;
break;
case V_602 :
V_15 = F_169 ( V_34 , V_451 ) ;
break;
case V_603 :
V_15 = F_170 ( V_34 , V_451 ) ;
break;
case V_604 :
V_390 = F_74 ( V_451 -> V_497 . V_605 . V_384 ) ;
V_381 = F_78 ( V_451 -> V_497 . V_605 . V_384 , V_451 -> V_497 . V_605 . V_387 ) ;
if ( V_381 && V_381 -> V_10 )
F_176 ( V_34 , V_381 -> V_10 -> V_11 ) ;
if ( ! V_390 || ! V_381 ) {
V_15 = - V_454 ;
break;
}
V_451 -> V_459 . V_537 = V_34 -> V_606 ( V_390 , V_381 ,
V_451 -> V_497 . V_605 . V_607 ,
V_451 -> V_497 . V_605 . V_608 ) ;
if ( V_451 -> V_459 . V_537 || ! V_34 -> V_526 )
break;
V_10 = F_21 ( V_451 -> V_497 . V_605 . V_607 ) ;
if ( V_10 ) {
V_10 -> V_381 = V_381 ;
F_92 ( & V_381 -> V_433 ) ;
V_381 -> V_10 = V_10 ;
F_94 ( & V_381 -> V_433 ) ;
} else
F_155 ( V_18 , V_381 ,
L_84
L_85 ) ;
break;
case V_609 :
V_15 = F_171 ( V_34 , V_451 ) ;
break;
case V_610 :
V_381 = F_78 ( V_451 -> V_497 . V_611 . V_384 , V_451 -> V_497 . V_611 . V_387 ) ;
if ( V_381 )
V_451 -> V_459 . V_537 = V_34 -> V_611 ( V_381 ) ;
else
V_15 = - V_454 ;
break;
case V_612 :
V_381 = F_78 ( V_451 -> V_497 . V_613 . V_384 , V_451 -> V_497 . V_613 . V_387 ) ;
if ( V_381 )
V_34 -> V_613 ( V_381 , V_451 -> V_497 . V_613 . V_614 ) ;
else
V_15 = - V_454 ;
break;
case V_615 :
V_381 = F_78 ( V_451 -> V_497 . V_616 . V_384 , V_451 -> V_497 . V_616 . V_387 ) ;
if ( V_381 )
V_451 -> V_459 . V_537 = V_34 -> V_616 ( V_381 ,
(struct V_445 * ) ( ( char * ) V_451 + sizeof( * V_451 ) ) ,
( char * ) V_451 + sizeof( * V_451 ) + V_451 -> V_497 . V_616 . V_617 ,
V_451 -> V_497 . V_616 . V_447 ) ;
else
V_15 = - V_454 ;
break;
case V_618 :
V_15 = F_163 ( V_34 , V_449 ) ;
break;
case V_534 :
case V_535 :
case V_539 :
case V_527 :
V_15 = F_177 ( V_34 , V_451 , V_449 -> V_501 ) ;
break;
case V_619 :
V_15 = F_178 ( V_34 , V_451 ) ;
break;
case V_620 :
V_15 = F_179 ( V_34 , V_451 ) ;
break;
case V_592 :
V_15 = F_180 ( V_34 , V_451 ) ;
break;
case V_621 :
V_15 = F_181 ( V_34 , V_451 ,
F_198 ( V_449 , sizeof( * V_451 ) ) ) ;
break;
case V_622 :
V_15 = F_182 ( V_34 , V_451 ) ;
break;
case V_623 :
V_15 = F_183 ( V_34 , V_449 ) ;
break;
case V_624 :
V_15 = F_185 ( V_34 , V_451 ) ;
break;
case V_625 :
V_15 = F_187 ( V_34 , V_451 ,
F_198 ( V_449 ,
sizeof( * V_451 ) ) ) ;
break;
case V_626 :
V_15 = F_188 ( V_34 , V_451 ,
F_198 ( V_449 , sizeof( * V_451 ) ) ) ;
break;
case V_627 :
V_15 = F_189 ( V_34 , V_451 ) ;
break;
case V_628 :
V_15 = F_190 ( V_34 , V_451 ) ;
break;
case V_629 :
V_15 = F_191 ( V_34 , V_451 ) ;
break;
case V_630 :
V_15 = F_192 ( V_34 , V_451 ) ;
break;
case V_631 :
V_15 = F_184 ( V_34 , V_451 ,
F_198 ( V_449 , sizeof( * V_451 ) ) ) ;
break;
case V_632 :
V_15 = F_193 ( V_34 , V_449 ) ;
break;
default:
V_15 = - V_543 ;
break;
}
F_199 ( V_34 -> V_593 ) ;
return V_15 ;
}
static void
F_200 ( struct V_440 * V_441 )
{
F_92 ( & V_633 ) ;
while ( V_441 -> V_453 >= V_634 ) {
int V_15 ;
T_5 V_635 ;
struct V_448 * V_449 ;
struct V_450 * V_451 ;
T_5 V_442 ;
V_449 = F_201 ( V_441 ) ;
if ( V_449 -> V_503 < sizeof( * V_449 ) ||
V_441 -> V_453 < V_449 -> V_503 ) {
break;
}
V_451 = F_157 ( V_449 ) ;
V_635 = F_166 ( V_449 -> V_503 ) ;
if ( V_635 > V_441 -> V_453 )
V_635 = V_441 -> V_453 ;
V_15 = F_194 ( V_441 , V_449 , & V_442 ) ;
if ( V_15 ) {
V_451 -> type = V_636 ;
V_451 -> V_637 = V_15 ;
}
do {
if ( V_451 -> type == V_618 && ! V_15 )
break;
if ( V_451 -> type == V_623 && ! V_15 )
break;
V_15 = F_162 ( V_442 , V_449 -> V_638 ,
V_449 -> V_501 , 0 , 0 , V_451 , sizeof( * V_451 ) ) ;
} while ( V_15 < 0 && V_15 != - V_504 && V_15 != - V_359 );
F_202 ( V_441 , V_635 ) ;
}
F_94 ( & V_633 ) ;
}
static T_4 F_203 ( struct V_30 * V_22 ,
struct V_31 * V_6 , int V_32 )
{
struct V_1 * V_376 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_380 * V_381 = F_204 ( V_376 ) ;
struct V_8 * V_33 = V_381 -> V_34 ;
int V_35 ;
if ( V_6 == & V_639 . V_6 )
V_35 = V_640 ;
else if ( V_6 == & V_641 . V_6 )
V_35 = V_642 ;
else if ( V_6 == & V_643 . V_6 )
V_35 = V_644 ;
else if ( V_6 == & V_645 . V_6 )
V_35 = V_646 ;
else if ( V_6 == & V_647 . V_6 )
V_35 = V_648 ;
else if ( V_6 == & V_649 . V_6 )
V_35 = V_650 ;
else if ( V_6 == & V_651 . V_6 )
V_35 = V_652 ;
else if ( V_6 == & V_653 . V_6 )
V_35 = V_654 ;
else if ( V_6 == & V_655 . V_6 )
V_35 = V_656 ;
else if ( V_6 == & V_657 . V_6 )
V_35 = V_658 ;
else if ( V_6 == & V_659 . V_6 )
V_35 = V_660 ;
else if ( V_6 == & V_661 . V_6 )
V_35 = V_662 ;
else if ( V_6 == & V_663 . V_6 )
V_35 = V_664 ;
else if ( V_6 == & V_665 . V_6 )
V_35 = V_666 ;
else if ( V_6 == & V_667 . V_6 )
V_35 = V_668 ;
else if ( V_6 == & V_669 . V_6 )
V_35 = V_670 ;
else if ( V_6 == & V_671 . V_6 )
V_35 = V_672 ;
else if ( V_6 == & V_673 . V_6 )
V_35 = V_674 ;
else if ( V_6 == & V_675 . V_6 )
V_35 = V_676 ;
else if ( V_6 == & V_677 . V_6 )
V_35 = V_678 ;
else if ( V_6 == & V_679 . V_6 )
V_35 = V_680 ;
else if ( V_6 == & V_681 . V_6 )
V_35 = V_682 ;
else if ( V_6 == & V_683 . V_6 )
V_35 = V_684 ;
else if ( V_6 == & V_685 . V_6 )
V_35 = V_686 ;
else if ( V_6 == & V_687 . V_6 )
V_35 = V_688 ;
else if ( V_6 == & V_689 . V_6 )
V_35 = V_690 ;
else if ( V_6 == & V_691 . V_6 )
V_35 = V_692 ;
else if ( V_6 == & V_693 . V_6 )
V_35 = V_694 ;
else if ( V_6 == & V_695 . V_6 )
V_35 = V_696 ;
else if ( V_6 == & V_697 . V_6 )
V_35 = V_698 ;
else {
F_26 ( 1 , L_86 ) ;
return 0 ;
}
return V_33 -> V_178 ( V_699 , V_35 ) ;
}
static T_1
F_205 ( struct V_1 * V_2 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_382 * V_390 = F_73 ( V_2 -> V_29 ) ;
return sprintf ( V_7 , L_87 , F_79 ( V_390 -> V_181 ) ) ;
}
static T_1
F_206 ( struct V_1 * V_2 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_382 * V_390 = F_73 ( V_2 -> V_29 ) ;
return sprintf ( V_7 , L_88 , V_390 -> V_425 ) ;
}
static T_1
F_207 ( struct V_1 * V_2 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_382 * V_390 = F_73 ( V_2 -> V_29 ) ;
return sprintf ( V_7 , L_88 , V_390 -> V_332 ) ;
}
static T_4 F_208 ( struct V_30 * V_22 ,
struct V_31 * V_6 , int V_32 )
{
struct V_1 * V_376 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_382 * V_390 = F_209 ( V_376 ) ;
struct V_8 * V_33 = V_390 -> V_34 ;
int V_35 ;
if ( V_6 == & V_700 . V_6 )
V_35 = V_701 ;
else if ( V_6 == & V_702 . V_6 )
V_35 = V_703 ;
else if ( V_6 == & V_704 . V_6 )
V_35 = V_705 ;
else if ( V_6 == & V_706 . V_6 )
V_35 = V_707 ;
else if ( V_6 == & V_708 . V_6 )
V_35 = V_709 ;
else if ( V_6 == & V_710 . V_6 )
V_35 = V_711 ;
else if ( V_6 == & V_712 . V_6 )
V_35 = V_713 ;
else if ( V_6 == & V_714 . V_6 )
V_35 = V_715 ;
else if ( V_6 == & V_716 . V_6 )
V_35 = V_717 ;
else if ( V_6 == & V_718 . V_6 )
V_35 = V_719 ;
else if ( V_6 == & V_720 . V_6 )
V_35 = V_721 ;
else if ( V_6 == & V_722 . V_6 )
V_35 = V_723 ;
else if ( V_6 == & V_724 . V_6 )
V_35 = V_725 ;
else if ( V_6 == & V_726 . V_6 )
V_35 = V_727 ;
else if ( V_6 == & V_728 . V_6 )
V_35 = V_729 ;
else if ( V_6 == & V_730 . V_6 )
V_35 = V_731 ;
else if ( V_6 == & V_732 . V_6 )
V_35 = V_733 ;
else if ( V_6 == & V_734 . V_6 )
V_35 = V_735 ;
else if ( V_6 == & V_736 . V_6 )
V_35 = V_737 ;
else if ( V_6 == & V_738 . V_6 )
V_35 = V_739 ;
else if ( V_6 == & V_740 . V_6 )
V_35 = V_741 ;
else if ( V_6 == & V_742 . V_6 )
V_35 = V_743 ;
else if ( V_6 == & V_744 . V_6 )
V_35 = V_745 ;
else if ( V_6 == & V_746 . V_6 )
V_35 = V_747 ;
else if ( V_6 == & V_748 . V_6 )
V_35 = V_749 ;
else if ( V_6 == & V_750 . V_6 )
V_35 = V_751 ;
else if ( V_6 == & V_752 . V_6 )
V_35 = V_753 ;
else if ( V_6 == & V_754 . V_6 )
V_35 = V_755 ;
else if ( V_6 == & V_756 . V_6 )
V_35 = V_757 ;
else if ( V_6 == & V_758 . V_6 )
V_35 = V_759 ;
else if ( V_6 == & V_760 . V_6 )
V_35 = V_761 ;
else if ( V_6 == & V_762 . V_6 )
V_35 = V_763 ;
else if ( V_6 == & V_764 . V_6 )
V_35 = V_765 ;
else if ( V_6 == & V_766 . V_6 )
V_35 = V_767 ;
else if ( V_6 == & V_768 . V_6 )
V_35 = V_769 ;
else if ( V_6 == & V_770 . V_6 )
V_35 = V_771 ;
else if ( V_6 == & V_772 . V_6 )
V_35 = V_773 ;
else if ( V_6 == & V_774 . V_6 )
V_35 = V_775 ;
else if ( V_6 == & V_776 . V_6 )
V_35 = V_777 ;
else if ( V_6 == & V_778 . V_6 )
V_35 = V_779 ;
else if ( V_6 == & V_780 . V_6 )
return V_781 | V_782 ;
else if ( V_6 == & V_783 . V_6 )
return V_781 ;
else if ( V_6 == & V_784 . V_6 )
return V_781 ;
else if ( V_6 == & V_785 . V_6 )
return V_781 ;
else {
F_26 ( 1 , L_89 ) ;
return 0 ;
}
return V_33 -> V_178 ( V_699 , V_35 ) ;
}
static T_4 F_210 ( struct V_30 * V_22 ,
struct V_31 * V_6 , int V_32 )
{
struct V_1 * V_376 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_188 * V_189 = F_211 ( V_376 ) ;
struct V_3 * V_4 = F_58 ( V_189 -> V_347 ) ;
int V_35 ;
if ( V_6 == & V_786 . V_6 )
V_35 = V_787 ;
else if ( V_6 == & V_788 . V_6 )
V_35 = V_789 ;
else if ( V_6 == & V_790 . V_6 )
V_35 = V_791 ;
else if ( V_6 == & V_792 . V_6 )
V_35 = V_793 ;
else if ( V_6 == & V_794 . V_6 )
V_35 = V_795 ;
else if ( V_6 == & V_796 . V_6 )
V_35 = V_797 ;
else {
F_26 ( 1 , L_90 ) ;
return 0 ;
}
return V_4 -> V_8 -> V_178 ( V_798 , V_35 ) ;
}
char * F_212 ( struct V_188 * V_189 )
{
int V_32 ;
char * V_799 = L_79 ;
struct V_365 * V_366 = V_189 -> V_377 ;
T_5 V_800 = V_366 -> V_800 ;
for ( V_32 = 0 ; V_32 < F_28 ( V_801 ) ; V_32 ++ ) {
if ( V_801 [ V_32 ] . V_183 & V_800 ) {
V_799 = V_801 [ V_32 ] . V_184 ;
break;
}
}
return V_799 ;
}
char * F_213 ( struct V_188 * V_189 )
{
int V_32 ;
char * V_181 = L_79 ;
struct V_365 * V_366 = V_189 -> V_377 ;
T_5 V_180 = V_366 -> V_180 ;
for ( V_32 = 0 ; V_32 < F_28 ( V_802 ) ; V_32 ++ ) {
if ( V_802 [ V_32 ] . V_183 & V_180 ) {
V_181 = V_802 [ V_32 ] . V_184 ;
break;
}
}
return V_181 ;
}
static int F_214 ( struct V_803 * V_804 ,
struct V_1 * V_2 )
{
struct V_382 * V_390 ;
struct V_188 * V_189 ;
struct V_3 * V_4 ;
if ( ! F_86 ( V_2 ) )
return 0 ;
V_390 = F_73 ( V_2 ) ;
V_189 = F_83 ( V_390 ) ;
if ( ! V_189 -> V_347 )
return 0 ;
V_4 = F_58 ( V_189 -> V_347 ) ;
if ( V_4 -> V_805 . V_806 . V_20 != & V_807 . V_20 )
return 0 ;
return & V_4 -> V_805 . V_806 == V_804 ;
}
static int F_215 ( struct V_803 * V_804 ,
struct V_1 * V_2 )
{
struct V_382 * V_390 ;
struct V_380 * V_381 ;
struct V_188 * V_189 ;
struct V_3 * V_4 ;
if ( ! F_138 ( V_2 ) )
return 0 ;
V_381 = F_136 ( V_2 ) ;
V_390 = F_73 ( V_381 -> V_2 . V_29 ) ;
V_189 = F_83 ( V_390 ) ;
if ( ! V_189 -> V_347 )
return 0 ;
V_4 = F_58 ( V_189 -> V_347 ) ;
if ( V_4 -> V_808 . V_806 . V_20 != & V_809 . V_20 )
return 0 ;
return & V_4 -> V_808 . V_806 == V_804 ;
}
static int F_216 ( struct V_803 * V_804 ,
struct V_1 * V_2 )
{
struct V_188 * V_189 ;
struct V_3 * V_4 ;
if ( ! F_217 ( V_2 ) )
return 0 ;
V_189 = F_67 ( V_2 ) ;
if ( ! V_189 -> V_347 ||
V_189 -> V_347 -> V_810 . V_806 . V_20 != & V_811 . V_20 )
return 0 ;
V_4 = F_58 ( V_189 -> V_347 ) ;
return & V_4 -> V_33 . V_810 . V_806 == V_804 ;
}
struct V_812 *
F_218 ( struct V_8 * V_438 )
{
struct V_3 * V_4 ;
unsigned long V_385 ;
int V_15 ;
F_59 ( ! V_438 ) ;
V_4 = F_148 ( V_438 ) ;
if ( V_4 )
return NULL ;
V_4 = F_14 ( sizeof( * V_4 ) , V_19 ) ;
if ( ! V_4 )
return NULL ;
F_122 ( & V_4 -> V_813 ) ;
V_4 -> V_8 = V_438 ;
V_4 -> V_33 . V_814 = F_95 ;
V_4 -> V_33 . V_815 = 1 ;
V_4 -> V_2 . V_20 = & V_816 ;
F_15 ( & V_4 -> V_2 , L_91 , V_438 -> V_184 ) ;
V_15 = F_16 ( & V_4 -> V_2 ) ;
if ( V_15 )
goto V_817;
V_15 = F_17 ( & V_4 -> V_2 . V_22 , & V_818 ) ;
if ( V_15 )
goto V_24;
V_4 -> V_33 . V_810 . V_806 . V_20 = & V_811 . V_20 ;
V_4 -> V_33 . V_810 . V_806 . V_819 = F_216 ;
V_4 -> V_33 . V_810 . V_806 . V_820 = & V_821 ;
V_4 -> V_33 . V_822 = sizeof( struct V_365 ) ;
F_219 ( & V_4 -> V_33 . V_810 ) ;
V_4 -> V_808 . V_806 . V_20 = & V_809 . V_20 ;
V_4 -> V_808 . V_806 . V_819 = F_215 ;
V_4 -> V_808 . V_806 . V_820 = & V_823 ;
F_219 ( & V_4 -> V_808 ) ;
V_4 -> V_805 . V_806 . V_20 = & V_807 . V_20 ;
V_4 -> V_805 . V_806 . V_819 = F_214 ;
V_4 -> V_805 . V_806 . V_820 = & V_824 ;
F_219 ( & V_4 -> V_805 ) ;
F_75 ( & V_439 , V_385 ) ;
F_132 ( & V_4 -> V_813 , & V_825 ) ;
F_77 ( & V_439 , V_385 ) ;
F_13 ( V_826 L_92 , V_438 -> V_184 ) ;
return & V_4 -> V_33 ;
V_24:
F_18 ( & V_4 -> V_2 ) ;
return NULL ;
V_817:
F_3 ( V_4 ) ;
return NULL ;
}
int F_220 ( struct V_8 * V_438 )
{
struct V_3 * V_4 ;
unsigned long V_385 ;
F_59 ( ! V_438 ) ;
F_92 ( & V_633 ) ;
V_4 = F_148 ( V_438 ) ;
F_59 ( ! V_4 ) ;
F_75 ( & V_439 , V_385 ) ;
F_142 ( & V_4 -> V_813 ) ;
F_77 ( & V_439 , V_385 ) ;
F_221 ( & V_4 -> V_808 ) ;
F_221 ( & V_4 -> V_805 ) ;
F_221 ( & V_4 -> V_33 . V_810 ) ;
F_20 ( & V_4 -> V_2 . V_22 , & V_818 ) ;
F_18 ( & V_4 -> V_2 ) ;
F_94 ( & V_633 ) ;
return 0 ;
}
static T_11 int F_222 ( void )
{
int V_15 ;
struct V_827 V_828 = {
. V_829 = 1 ,
. V_830 = F_200 ,
} ;
F_13 ( V_412 L_93 ,
V_831 ) ;
F_68 ( & V_428 , 0 ) ;
V_15 = F_223 ( & V_816 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_223 ( & V_17 ) ;
if ( V_15 )
goto V_832;
V_15 = F_223 ( & V_192 ) ;
if ( V_15 )
goto V_833;
V_15 = F_224 ( & V_811 ) ;
if ( V_15 )
goto V_834;
V_15 = F_224 ( & V_809 ) ;
if ( V_15 )
goto V_835;
V_15 = F_224 ( & V_807 ) ;
if ( V_15 )
goto V_836;
V_15 = F_225 ( & V_330 ) ;
if ( V_15 )
goto V_837;
V_444 = F_226 ( & V_838 , V_839 , & V_828 ) ;
if ( ! V_444 ) {
V_15 = - V_840 ;
goto V_841;
}
V_418 = F_227 ( L_94 ) ;
if ( ! V_418 ) {
V_15 = - V_372 ;
goto V_842;
}
return 0 ;
V_842:
F_228 ( V_444 ) ;
V_841:
F_229 ( & V_330 ) ;
V_837:
F_230 ( & V_807 ) ;
V_836:
F_230 ( & V_809 ) ;
V_835:
F_230 ( & V_811 ) ;
V_834:
F_231 ( & V_192 ) ;
V_833:
F_231 ( & V_17 ) ;
V_832:
F_231 ( & V_816 ) ;
return V_15 ;
}
static void T_12 F_232 ( void )
{
F_233 ( V_418 ) ;
F_228 ( V_444 ) ;
F_229 ( & V_330 ) ;
F_230 ( & V_809 ) ;
F_230 ( & V_807 ) ;
F_230 ( & V_811 ) ;
F_231 ( & V_17 ) ;
F_231 ( & V_192 ) ;
F_231 ( & V_816 ) ;
}
