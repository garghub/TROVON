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
static int F_42 ( struct V_1 * V_2 , void * V_12 )
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
if ( ! V_32 -> V_8 -> V_361 )
return - V_370 ;
snprintf ( V_369 , sizeof( V_369 ) , L_12 , V_189 -> V_194 ) ;
V_368 = F_62 ( V_2 , V_369 , F_56 , 0 , NULL ) ;
if ( F_63 ( V_368 ) ) {
F_64 ( V_18 , V_189 , L_13
L_14 ) ;
return F_65 ( V_368 ) ;
}
F_66 ( V_189 , V_368 ) ;
V_366 -> V_371 = V_368 ;
return 0 ;
}
static int F_67 ( struct V_372 * V_373 , struct V_1 * V_2 ,
struct V_1 * V_374 )
{
struct V_188 * V_189 = F_68 ( V_2 ) ;
struct V_365 * V_366 = V_189 -> V_375 ;
memset ( V_366 , 0 , sizeof( * V_366 ) ) ;
F_69 ( & V_366 -> V_376 , 0 ) ;
F_70 ( & V_366 -> V_377 ) ;
F_61 ( V_189 , V_366 ) ;
return 0 ;
}
static int F_71 ( struct V_372 * V_373 ,
struct V_1 * V_2 , struct V_1 * V_374 )
{
struct V_188 * V_189 = F_68 ( V_2 ) ;
struct V_365 * V_366 = V_189 -> V_375 ;
if ( V_366 -> V_371 ) {
F_72 ( V_366 -> V_371 ) ;
F_73 ( V_366 -> V_371 ) ;
}
return 0 ;
}
static T_5 F_74 ( struct V_378 * V_379 )
{
struct V_380 * V_381 = F_75 ( V_379 -> V_2 . V_29 ) ;
return V_381 -> V_382 ;
}
static struct V_380 * F_76 ( T_5 V_382 )
{
unsigned long V_383 ;
struct V_380 * V_381 ;
F_77 ( & V_384 , V_383 ) ;
F_78 (sess, &sesslist, sess_list) {
if ( V_381 -> V_382 == V_382 ) {
F_79 ( & V_384 , V_383 ) ;
return V_381 ;
}
}
F_79 ( & V_384 , V_383 ) ;
return NULL ;
}
static struct V_378 * F_80 ( T_5 V_382 , T_5 V_385 )
{
unsigned long V_383 ;
struct V_378 * V_379 ;
F_77 ( & V_386 , V_383 ) ;
F_78 (conn, &connlist, conn_list) {
if ( ( V_379 -> V_385 == V_385 ) && ( F_74 ( V_379 ) == V_382 ) ) {
F_79 ( & V_386 , V_383 ) ;
return V_379 ;
}
}
F_79 ( & V_386 , V_383 ) ;
return NULL ;
}
static const char * F_81 ( int V_181 )
{
int V_32 ;
char * V_184 = NULL ;
for ( V_32 = 0 ; V_32 < F_28 ( V_387 ) ; V_32 ++ ) {
if ( V_387 [ V_32 ] . V_183 == V_181 ) {
V_184 = V_387 [ V_32 ] . V_184 ;
break;
}
}
return V_184 ;
}
int F_82 ( struct V_380 * V_388 )
{
unsigned long V_383 ;
int V_15 ;
F_77 ( & V_388 -> V_389 , V_383 ) ;
switch ( V_388 -> V_181 ) {
case V_390 :
V_15 = 0 ;
break;
case V_391 :
V_15 = V_392 << 16 ;
break;
case V_393 :
V_15 = V_394 << 16 ;
break;
default:
V_15 = V_395 << 16 ;
break;
}
F_79 ( & V_388 -> V_389 , V_383 ) ;
return V_15 ;
}
int F_83 ( struct V_380 * V_388 )
{
unsigned long V_383 ;
int V_337 = 0 ;
F_77 ( & V_388 -> V_389 , V_383 ) ;
if ( V_388 -> V_181 == V_390 )
V_337 = 1 ;
F_79 ( & V_388 -> V_389 , V_383 ) ;
return V_337 ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_380 * V_388 = F_75 ( V_2 ) ;
struct V_188 * V_189 ;
V_189 = F_85 ( V_388 ) ;
F_86 ( V_189 ) ;
F_87 ( V_388 , L_15 ) ;
F_3 ( V_388 ) ;
}
int F_88 ( const struct V_1 * V_2 )
{
return V_2 -> V_191 == F_84 ;
}
static int F_89 ( struct V_1 * V_2 , void * V_12 )
{
void (* F_48) ( struct V_380 * ) = V_12 ;
if ( ! F_88 ( V_2 ) )
return 0 ;
F_48 ( F_75 ( V_2 ) ) ;
return 0 ;
}
void F_90 ( struct V_188 * V_189 ,
void (* F_48)( struct V_380 * ) )
{
F_52 ( & V_189 -> V_193 , F_48 ,
F_89 ) ;
}
int F_91 ( struct V_188 * V_189 , unsigned long time )
{
struct V_365 * V_366 = V_189 -> V_375 ;
return ! F_92 ( & V_366 -> V_376 ) ;
}
static int F_93 ( struct V_1 * V_2 , void * V_12 )
{
struct V_396 * V_397 = V_12 ;
struct V_380 * V_388 ;
struct V_188 * V_189 ;
struct V_365 * V_366 ;
unsigned long V_383 ;
unsigned int V_11 ;
if ( ! F_88 ( V_2 ) )
return 0 ;
V_388 = F_75 ( V_2 ) ;
F_87 ( V_388 , L_16 ) ;
V_189 = F_85 ( V_388 ) ;
V_366 = V_189 -> V_375 ;
F_94 ( & V_366 -> V_377 ) ;
F_77 ( & V_388 -> V_389 , V_383 ) ;
if ( V_388 -> V_181 != V_390 ) {
F_79 ( & V_388 -> V_389 , V_383 ) ;
goto V_398;
}
V_11 = V_388 -> V_332 ;
F_79 ( & V_388 -> V_389 , V_383 ) ;
if ( V_11 != V_399 ) {
if ( ( V_397 -> V_400 == V_401 ||
V_397 -> V_400 == 0 ) &&
( V_397 -> V_11 == V_401 ||
V_397 -> V_11 == V_11 ) )
F_95 ( & V_388 -> V_2 , 0 , V_11 ,
V_397 -> V_402 , V_397 -> V_403 ) ;
}
V_398:
F_96 ( & V_366 -> V_377 ) ;
F_87 ( V_388 , L_17 ) ;
return 0 ;
}
static int F_97 ( struct V_188 * V_189 , T_6 V_400 ,
T_6 V_11 , T_3 V_402 )
{
struct V_396 V_397 ;
V_397 . V_400 = V_400 ;
V_397 . V_11 = V_11 ;
V_397 . V_402 = V_402 ;
V_397 . V_403 = V_404 ;
return F_52 ( & V_189 -> V_193 , & V_397 ,
F_93 ) ;
}
static void F_98 ( struct V_405 * V_406 )
{
struct V_380 * V_388 =
F_25 ( V_406 , struct V_380 , V_407 ) ;
struct V_188 * V_189 = F_85 ( V_388 ) ;
struct V_365 * V_366 = V_189 -> V_375 ;
struct V_396 V_397 ;
V_397 . V_400 = 0 ;
V_397 . V_11 = V_401 ;
V_397 . V_402 = V_401 ;
V_397 . V_403 = V_408 ;
F_93 ( & V_388 -> V_2 , & V_397 ) ;
F_99 ( & V_366 -> V_376 ) ;
}
int F_100 ( struct V_409 * V_410 )
{
struct V_380 * V_388 =
F_101 ( F_102 ( V_410 -> V_1 ) ) ;
unsigned long V_383 ;
int V_337 = 0 ;
F_77 ( & V_388 -> V_389 , V_383 ) ;
while ( V_388 -> V_181 != V_390 ) {
if ( V_388 -> V_181 == V_393 ) {
V_337 = V_411 ;
break;
}
F_79 ( & V_388 -> V_389 , V_383 ) ;
F_103 ( 1000 ) ;
F_77 ( & V_388 -> V_389 , V_383 ) ;
}
F_79 ( & V_388 -> V_389 , V_383 ) ;
return V_337 ;
}
static void F_104 ( struct V_405 * V_406 )
{
struct V_380 * V_388 =
F_25 ( V_406 , struct V_380 ,
V_412 . V_406 ) ;
unsigned long V_383 ;
F_105 ( V_413 , V_388 ,
L_18 ,
V_388 -> V_414 ) ;
F_77 ( & V_388 -> V_389 , V_383 ) ;
switch ( V_388 -> V_181 ) {
case V_391 :
V_388 -> V_181 = V_393 ;
break;
case V_390 :
case V_393 :
F_79 ( & V_388 -> V_389 , V_383 ) ;
return;
}
F_79 ( & V_388 -> V_389 , V_383 ) ;
if ( V_388 -> V_34 -> F_104 )
V_388 -> V_34 -> F_104 ( V_388 ) ;
F_87 ( V_388 , L_19 ) ;
F_106 ( & V_388 -> V_2 , V_415 ) ;
F_87 ( V_388 , L_20 ) ;
}
static void F_107 ( struct V_405 * V_406 )
{
struct V_380 * V_388 =
F_25 ( V_406 , struct V_380 ,
V_416 ) ;
struct V_188 * V_189 = F_85 ( V_388 ) ;
struct V_365 * V_366 = V_189 -> V_375 ;
unsigned long V_383 ;
F_87 ( V_388 , L_21 ) ;
F_108 ( & V_388 -> V_412 ) ;
F_77 ( & V_388 -> V_389 , V_383 ) ;
V_388 -> V_181 = V_390 ;
F_79 ( & V_388 -> V_389 , V_383 ) ;
F_106 ( & V_388 -> V_2 , V_417 ) ;
if ( V_189 -> V_355 -> V_418 ) {
if ( F_109 ( V_189 , & V_388 -> V_407 ) )
F_110 ( & V_366 -> V_376 ) ;
}
F_87 ( V_388 , L_22 ) ;
}
void F_111 ( struct V_380 * V_388 )
{
F_112 ( V_419 , & V_388 -> V_416 ) ;
F_113 ( V_419 ) ;
}
static void F_114 ( struct V_405 * V_406 )
{
struct V_380 * V_388 =
F_25 ( V_406 , struct V_380 ,
V_420 ) ;
unsigned long V_383 ;
F_87 ( V_388 , L_23 ) ;
F_77 ( & V_388 -> V_389 , V_383 ) ;
V_388 -> V_181 = V_391 ;
F_79 ( & V_388 -> V_389 , V_383 ) ;
F_115 ( & V_388 -> V_2 ) ;
F_87 ( V_388 , L_24 ) ;
if ( V_388 -> V_414 >= 0 )
F_116 ( V_419 ,
& V_388 -> V_412 ,
V_388 -> V_414 * V_421 ) ;
}
void F_117 ( struct V_380 * V_388 )
{
F_112 ( V_419 , & V_388 -> V_420 ) ;
}
static void F_118 ( struct V_405 * V_406 )
{
struct V_380 * V_388 =
F_25 ( V_406 , struct V_380 ,
V_422 ) ;
struct V_188 * V_189 = F_85 ( V_388 ) ;
struct V_365 * V_366 = V_189 -> V_375 ;
unsigned long V_383 ;
unsigned int V_332 ;
F_87 ( V_388 , L_25 ) ;
F_94 ( & V_366 -> V_377 ) ;
F_77 ( & V_388 -> V_389 , V_383 ) ;
if ( V_388 -> V_332 == V_399 ) {
F_79 ( & V_388 -> V_389 , V_383 ) ;
F_96 ( & V_366 -> V_377 ) ;
return;
}
V_332 = V_388 -> V_332 ;
V_388 -> V_332 = V_399 ;
F_79 ( & V_388 -> V_389 , V_383 ) ;
F_96 ( & V_366 -> V_377 ) ;
if ( V_388 -> V_423 )
F_119 ( & V_424 , V_332 ) ;
F_120 ( & V_388 -> V_2 ) ;
F_121 ( V_388 , V_425 ) ;
F_87 ( V_388 , L_26 ) ;
}
struct V_380 *
F_122 ( struct V_188 * V_189 , struct V_8 * V_34 ,
int V_14 )
{
struct V_380 * V_388 ;
V_388 = F_14 ( sizeof( * V_388 ) + V_14 ,
V_19 ) ;
if ( ! V_388 )
return NULL ;
V_388 -> V_34 = V_34 ;
V_388 -> V_426 = - 1 ;
V_388 -> V_414 = 120 ;
V_388 -> V_427 = false ;
V_388 -> V_181 = V_393 ;
F_123 ( & V_388 -> V_412 , F_104 ) ;
F_124 ( & V_388 -> V_428 ) ;
F_125 ( & V_388 -> V_416 , F_107 ) ;
F_125 ( & V_388 -> V_420 , F_114 ) ;
F_125 ( & V_388 -> V_422 , F_118 ) ;
F_125 ( & V_388 -> V_407 , F_98 ) ;
F_126 ( & V_388 -> V_389 ) ;
F_127 ( V_189 ) ;
V_388 -> V_2 . V_29 = & V_189 -> V_193 ;
V_388 -> V_2 . V_191 = F_84 ;
F_128 ( & V_388 -> V_2 ) ;
if ( V_14 )
V_388 -> V_25 = & V_388 [ 1 ] ;
F_87 ( V_388 , L_27 ) ;
return V_388 ;
}
int F_129 ( struct V_380 * V_388 , unsigned int V_332 )
{
unsigned long V_383 ;
int V_11 = 0 ;
int V_15 ;
V_388 -> V_382 = F_130 ( 1 , & V_429 ) ;
if ( V_332 == V_399 ) {
V_11 = F_131 ( & V_424 , 0 , 0 , V_19 ) ;
if ( V_11 < 0 ) {
F_105 ( V_18 , V_388 ,
L_28 ) ;
return V_11 ;
}
V_388 -> V_332 = ( unsigned int ) V_11 ;
V_388 -> V_423 = true ;
} else
V_388 -> V_332 = V_332 ;
F_15 ( & V_388 -> V_2 , L_29 , V_388 -> V_382 ) ;
V_15 = F_132 ( & V_388 -> V_2 ) ;
if ( V_15 ) {
F_105 ( V_18 , V_388 ,
L_30 ) ;
goto V_430;
}
F_133 ( & V_388 -> V_2 ) ;
F_77 ( & V_384 , V_383 ) ;
F_134 ( & V_388 -> V_428 , & V_431 ) ;
F_79 ( & V_384 , V_383 ) ;
F_121 ( V_388 , V_432 ) ;
F_87 ( V_388 , L_31 ) ;
return 0 ;
V_430:
if ( V_388 -> V_423 )
F_119 ( & V_424 , V_388 -> V_332 ) ;
return V_15 ;
}
struct V_380 *
F_135 ( struct V_188 * V_189 , struct V_8 * V_34 ,
int V_14 , unsigned int V_332 )
{
struct V_380 * V_388 ;
V_388 = F_122 ( V_189 , V_34 , V_14 ) ;
if ( ! V_388 )
return NULL ;
if ( F_129 ( V_388 , V_332 ) ) {
F_136 ( V_388 ) ;
return NULL ;
}
return V_388 ;
}
static void F_137 ( struct V_1 * V_2 )
{
struct V_378 * V_379 = F_138 ( V_2 ) ;
struct V_1 * V_29 = V_379 -> V_2 . V_29 ;
F_139 ( V_379 , L_32 ) ;
F_3 ( V_379 ) ;
F_12 ( V_29 ) ;
}
static int F_140 ( const struct V_1 * V_2 )
{
return V_2 -> V_191 == F_137 ;
}
static int F_141 ( struct V_1 * V_2 , void * V_12 )
{
if ( ! F_140 ( V_2 ) )
return 0 ;
return F_142 ( F_138 ( V_2 ) ) ;
}
void F_143 ( struct V_380 * V_388 )
{
unsigned long V_383 ;
int V_15 ;
F_87 ( V_388 , L_33 ) ;
F_77 ( & V_384 , V_383 ) ;
F_144 ( & V_388 -> V_428 ) ;
F_79 ( & V_384 , V_383 ) ;
F_113 ( V_419 ) ;
if ( ! F_108 ( & V_388 -> V_412 ) )
F_113 ( V_419 ) ;
F_77 ( & V_388 -> V_389 , V_383 ) ;
V_388 -> V_181 = V_393 ;
F_79 ( & V_388 -> V_389 , V_383 ) ;
F_106 ( & V_388 -> V_2 , V_415 ) ;
F_145 ( & V_388 -> V_407 ) ;
F_118 ( & V_388 -> V_422 ) ;
V_15 = F_52 ( & V_388 -> V_2 , NULL ,
F_141 ) ;
if ( V_15 )
F_105 ( V_18 , V_388 ,
L_34
L_35 , V_15 ) ;
F_146 ( & V_388 -> V_2 ) ;
F_87 ( V_388 , L_36 ) ;
F_147 ( & V_388 -> V_2 ) ;
}
void F_136 ( struct V_380 * V_388 )
{
F_87 ( V_388 , L_37 ) ;
F_121 ( V_388 , V_433 ) ;
F_12 ( & V_388 -> V_2 ) ;
}
struct V_378 *
F_148 ( struct V_380 * V_388 , int V_14 , T_5 V_385 )
{
struct V_8 * V_34 = V_388 -> V_34 ;
struct V_378 * V_379 ;
unsigned long V_383 ;
int V_15 ;
V_379 = F_14 ( sizeof( * V_379 ) + V_14 , V_19 ) ;
if ( ! V_379 )
return NULL ;
if ( V_14 )
V_379 -> V_25 = & V_379 [ 1 ] ;
F_70 ( & V_379 -> V_434 ) ;
F_124 ( & V_379 -> V_435 ) ;
V_379 -> V_34 = V_34 ;
V_379 -> V_385 = V_385 ;
if ( ! F_31 ( & V_388 -> V_2 ) )
goto V_436;
F_15 ( & V_379 -> V_2 , L_38 , V_388 -> V_382 , V_385 ) ;
V_379 -> V_2 . V_29 = & V_388 -> V_2 ;
V_379 -> V_2 . V_191 = F_137 ;
V_15 = F_16 ( & V_379 -> V_2 ) ;
if ( V_15 ) {
F_105 ( V_18 , V_388 , L_39
L_40 ) ;
goto V_437;
}
F_133 ( & V_379 -> V_2 ) ;
F_77 ( & V_386 , V_383 ) ;
F_134 ( & V_379 -> V_435 , & V_438 ) ;
F_79 ( & V_386 , V_383 ) ;
F_139 ( V_379 , L_41 ) ;
return V_379 ;
V_437:
F_12 ( & V_388 -> V_2 ) ;
V_436:
F_3 ( V_379 ) ;
return NULL ;
}
int F_142 ( struct V_378 * V_379 )
{
unsigned long V_383 ;
F_77 ( & V_386 , V_383 ) ;
F_144 ( & V_379 -> V_435 ) ;
F_79 ( & V_386 , V_383 ) ;
F_146 ( & V_379 -> V_2 ) ;
F_139 ( V_379 , L_42 ) ;
F_18 ( & V_379 -> V_2 ) ;
return 0 ;
}
static struct V_3 *
F_149 ( struct V_8 * V_439 )
{
struct V_3 * V_4 ;
unsigned long V_383 ;
F_77 ( & V_440 , V_383 ) ;
F_78 (priv, &iscsi_transports, list) {
if ( V_439 == V_4 -> V_8 ) {
F_79 ( & V_440 , V_383 ) ;
return V_4 ;
}
}
F_79 ( & V_440 , V_383 ) ;
return NULL ;
}
static int
F_150 ( struct V_441 * V_442 , T_5 V_443 , T_7 V_444 )
{
return F_151 ( V_445 , V_442 , 0 , V_443 , V_444 ) ;
}
int F_152 ( struct V_378 * V_379 , struct V_446 * V_447 ,
char * V_12 , T_5 V_448 )
{
struct V_449 * V_450 ;
struct V_441 * V_442 ;
struct V_451 * V_452 ;
char * V_453 ;
struct V_3 * V_4 ;
int V_454 = F_153 ( sizeof( * V_452 ) + sizeof( struct V_446 ) +
V_448 ) ;
V_4 = F_149 ( V_379 -> V_34 ) ;
if ( ! V_4 )
return - V_455 ;
V_442 = F_154 ( V_454 , V_456 ) ;
if ( ! V_442 ) {
F_155 ( V_379 , V_457 ) ;
F_156 ( V_18 , V_379 , L_43
L_44 ) ;
return - V_458 ;
}
V_450 = F_157 ( V_442 , 0 , 0 , 0 , ( V_454 - sizeof( * V_450 ) ) , 0 ) ;
V_452 = F_158 ( V_450 ) ;
memset ( V_452 , 0 , sizeof( * V_452 ) ) ;
V_452 -> V_459 = F_5 ( V_379 -> V_34 ) ;
V_452 -> type = V_460 ;
V_452 -> V_461 . V_462 . V_385 = V_379 -> V_385 ;
V_452 -> V_461 . V_462 . V_382 = F_74 ( V_379 ) ;
V_453 = ( char * ) V_452 + sizeof( * V_452 ) ;
memcpy ( V_453 , V_447 , sizeof( struct V_446 ) ) ;
memcpy ( V_453 + sizeof( struct V_446 ) , V_12 , V_448 ) ;
return F_150 ( V_442 , V_463 , V_456 ) ;
}
int F_159 ( struct V_188 * V_189 ,
struct V_8 * V_34 , T_5 type ,
char * V_12 , T_8 V_448 )
{
struct V_449 * V_450 ;
struct V_441 * V_442 ;
struct V_451 * V_452 ;
int V_454 = F_153 ( sizeof( * V_452 ) + V_448 ) ;
V_442 = F_154 ( V_454 , V_456 ) ;
if ( ! V_442 ) {
F_13 ( V_18 L_45 ) ;
return - V_458 ;
}
V_450 = F_157 ( V_442 , 0 , 0 , 0 , ( V_454 - sizeof( * V_450 ) ) , 0 ) ;
V_452 = F_158 ( V_450 ) ;
memset ( V_452 , 0 , sizeof( * V_452 ) ) ;
V_452 -> type = type ;
V_452 -> V_459 = F_5 ( V_34 ) ;
switch ( type ) {
case V_464 :
V_452 -> V_461 . V_465 . V_194 = V_189 -> V_194 ;
break;
case V_466 :
V_452 -> V_461 . V_467 . V_194 = V_189 -> V_194 ;
break;
}
memcpy ( ( char * ) V_452 + sizeof( * V_452 ) , V_12 , V_448 ) ;
return F_150 ( V_442 , V_468 , V_456 ) ;
}
void F_155 ( struct V_378 * V_379 , enum V_469 error )
{
struct V_449 * V_450 ;
struct V_441 * V_442 ;
struct V_451 * V_452 ;
struct V_3 * V_4 ;
int V_454 = F_153 ( sizeof( * V_452 ) ) ;
V_4 = F_149 ( V_379 -> V_34 ) ;
if ( ! V_4 )
return;
V_442 = F_154 ( V_454 , V_456 ) ;
if ( ! V_442 ) {
F_156 ( V_18 , V_379 , L_46
L_47 , error ) ;
return;
}
V_450 = F_157 ( V_442 , 0 , 0 , 0 , ( V_454 - sizeof( * V_450 ) ) , 0 ) ;
V_452 = F_158 ( V_450 ) ;
V_452 -> V_459 = F_5 ( V_379 -> V_34 ) ;
V_452 -> type = V_470 ;
V_452 -> V_461 . V_471 . error = error ;
V_452 -> V_461 . V_471 . V_385 = V_379 -> V_385 ;
V_452 -> V_461 . V_471 . V_382 = F_74 ( V_379 ) ;
F_150 ( V_442 , V_463 , V_456 ) ;
F_156 ( V_413 , V_379 , L_48 ,
error ) ;
}
void F_160 ( struct V_378 * V_379 ,
enum V_472 V_181 )
{
struct V_449 * V_450 ;
struct V_441 * V_442 ;
struct V_451 * V_452 ;
struct V_3 * V_4 ;
int V_454 = F_153 ( sizeof( * V_452 ) ) ;
V_4 = F_149 ( V_379 -> V_34 ) ;
if ( ! V_4 )
return;
V_442 = F_154 ( V_454 , V_456 ) ;
if ( ! V_442 ) {
F_156 ( V_18 , V_379 , L_46
L_49 , V_181 ) ;
return;
}
V_450 = F_157 ( V_442 , 0 , 0 , 0 , ( V_454 - sizeof( * V_450 ) ) , 0 ) ;
V_452 = F_158 ( V_450 ) ;
V_452 -> V_459 = F_5 ( V_379 -> V_34 ) ;
V_452 -> type = V_473 ;
V_452 -> V_461 . V_474 . V_181 = V_181 ;
V_452 -> V_461 . V_474 . V_385 = V_379 -> V_385 ;
V_452 -> V_461 . V_474 . V_382 = F_74 ( V_379 ) ;
F_150 ( V_442 , V_463 , V_456 ) ;
F_156 ( V_413 , V_379 , L_50 ,
V_181 ) ;
}
void F_161 ( T_5 V_194 , struct V_8 * V_34 ,
enum V_475 V_476 , T_5 V_448 ,
T_9 * V_12 )
{
struct V_449 * V_450 ;
struct V_441 * V_442 ;
struct V_451 * V_452 ;
int V_454 = F_153 ( sizeof( * V_452 ) + V_448 ) ;
V_442 = F_154 ( V_454 , V_477 ) ;
if ( ! V_442 ) {
F_13 ( V_18 L_51 ,
V_194 , V_476 ) ;
return;
}
V_450 = F_157 ( V_442 , 0 , 0 , 0 , ( V_454 - sizeof( * V_450 ) ) , 0 ) ;
V_452 = F_158 ( V_450 ) ;
V_452 -> V_459 = F_5 ( V_34 ) ;
V_452 -> type = V_478 ;
V_452 -> V_461 . V_479 . V_194 = V_194 ;
V_452 -> V_461 . V_479 . V_476 = V_476 ;
V_452 -> V_461 . V_479 . V_448 = V_448 ;
if ( V_448 )
memcpy ( ( char * ) V_452 + sizeof( * V_452 ) , V_12 , V_448 ) ;
F_150 ( V_442 , V_463 , V_477 ) ;
}
void F_162 ( T_5 V_194 , struct V_8 * V_34 ,
T_5 V_480 , T_5 V_481 , T_5 V_448 ,
T_9 * V_12 )
{
struct V_449 * V_450 ;
struct V_441 * V_442 ;
struct V_451 * V_452 ;
int V_454 = F_153 ( sizeof( * V_452 ) + V_448 ) ;
V_442 = F_154 ( V_454 , V_477 ) ;
if ( ! V_442 ) {
F_13 ( V_18 L_52 ) ;
return;
}
V_450 = F_157 ( V_442 , 0 , 0 , 0 , ( V_454 - sizeof( * V_450 ) ) , 0 ) ;
V_452 = F_158 ( V_450 ) ;
V_452 -> V_459 = F_5 ( V_34 ) ;
V_452 -> type = V_482 ;
V_452 -> V_461 . V_483 . V_194 = V_194 ;
V_452 -> V_461 . V_483 . V_480 = V_480 ;
V_452 -> V_461 . V_483 . V_481 = V_481 ;
V_452 -> V_461 . V_483 . V_448 = V_448 ;
memcpy ( ( char * ) V_452 + sizeof( * V_452 ) , V_12 , V_448 ) ;
F_150 ( V_442 , V_463 , V_477 ) ;
}
static int
F_163 ( T_5 V_443 , int V_484 , int type , int V_485 , int V_486 ,
void * V_487 , int V_488 )
{
struct V_441 * V_442 ;
struct V_449 * V_450 ;
int V_454 = F_153 ( V_488 ) ;
int V_383 = V_486 ? V_489 : 0 ;
int V_33 = V_485 ? V_490 : type ;
V_442 = F_154 ( V_454 , V_456 ) ;
if ( ! V_442 ) {
F_13 ( V_18 L_53 ) ;
return - V_458 ;
}
V_450 = F_157 ( V_442 , 0 , 0 , V_33 , ( V_454 - sizeof( * V_450 ) ) , 0 ) ;
V_450 -> V_491 = V_383 ;
memcpy ( F_158 ( V_450 ) , V_487 , V_488 ) ;
return F_150 ( V_442 , V_443 , V_456 ) ;
}
static int
F_164 ( struct V_8 * V_34 , struct V_449 * V_450 )
{
struct V_451 * V_452 = F_158 ( V_450 ) ;
struct V_492 * V_493 ;
struct V_441 * V_494 ;
struct V_378 * V_379 ;
struct V_449 * V_495 ;
struct V_451 * V_496 ;
struct V_3 * V_4 ;
int V_454 = F_153 ( sizeof( * V_452 ) +
sizeof( struct V_492 ) +
sizeof( struct V_497 ) *
V_498 ) ;
int V_15 = 0 ;
V_4 = F_149 ( V_34 ) ;
if ( ! V_4 )
return - V_455 ;
V_379 = F_80 ( V_452 -> V_499 . V_500 . V_382 , V_452 -> V_499 . V_500 . V_385 ) ;
if ( ! V_379 )
return - V_501 ;
do {
int V_502 ;
V_494 = F_154 ( V_454 , V_456 ) ;
if ( ! V_494 ) {
F_156 ( V_18 , V_379 , L_54
L_55 ) ;
return - V_458 ;
}
V_495 = F_157 ( V_494 , 0 , 0 , 0 ,
( V_454 - sizeof( * V_495 ) ) , 0 ) ;
V_496 = F_158 ( V_495 ) ;
memset ( V_496 , 0 , sizeof( * V_496 ) ) ;
V_496 -> V_459 = F_5 ( V_379 -> V_34 ) ;
V_496 -> type = V_450 -> V_503 ;
V_496 -> V_499 . V_500 . V_385 =
V_452 -> V_499 . V_500 . V_385 ;
V_496 -> V_499 . V_500 . V_382 =
V_452 -> V_499 . V_500 . V_382 ;
V_493 = (struct V_492 * )
( ( char * ) V_496 + sizeof( * V_496 ) ) ;
memset ( V_493 , 0 , sizeof( * V_493 ) ) ;
V_34 -> V_500 ( V_379 , V_493 ) ;
V_502 = F_153 ( sizeof( struct V_451 ) +
sizeof( struct V_492 ) +
sizeof( struct V_497 ) *
V_493 -> V_504 ) ;
V_502 -= sizeof( * V_495 ) ;
V_502 = F_165 ( V_502 ) ;
F_166 ( V_494 , F_167 ( V_502 ) ) ;
V_495 -> V_505 = V_502 ;
V_15 = F_150 ( V_494 , V_463 ,
V_456 ) ;
} while ( V_15 < 0 && V_15 != - V_506 );
return V_15 ;
}
int F_121 ( struct V_380 * V_388 ,
enum V_507 V_508 )
{
struct V_3 * V_4 ;
struct V_188 * V_189 ;
struct V_451 * V_452 ;
struct V_441 * V_442 ;
struct V_449 * V_450 ;
int V_509 , V_454 = F_153 ( sizeof( * V_452 ) ) ;
V_4 = F_149 ( V_388 -> V_34 ) ;
if ( ! V_4 )
return - V_455 ;
V_189 = F_85 ( V_388 ) ;
V_442 = F_154 ( V_454 , V_19 ) ;
if ( ! V_442 ) {
F_105 ( V_18 , V_388 ,
L_56
L_57 , V_508 ) ;
return - V_458 ;
}
V_450 = F_157 ( V_442 , 0 , 0 , 0 , ( V_454 - sizeof( * V_450 ) ) , 0 ) ;
V_452 = F_158 ( V_450 ) ;
V_452 -> V_459 = F_5 ( V_388 -> V_34 ) ;
V_452 -> type = V_508 ;
switch ( V_508 ) {
case V_433 :
V_452 -> V_461 . V_510 . V_194 = V_189 -> V_194 ;
V_452 -> V_461 . V_510 . V_382 = V_388 -> V_382 ;
break;
case V_432 :
V_452 -> V_461 . V_511 . V_194 = V_189 -> V_194 ;
V_452 -> V_461 . V_511 . V_382 = V_388 -> V_382 ;
break;
case V_425 :
V_452 -> V_461 . V_512 . V_194 = V_189 -> V_194 ;
V_452 -> V_461 . V_512 . V_382 = V_388 -> V_382 ;
break;
default:
F_105 ( V_18 , V_388 , L_58
L_59 , V_508 ) ;
F_168 ( V_442 ) ;
return - V_455 ;
}
V_509 = F_150 ( V_442 , V_463 , V_19 ) ;
if ( V_509 == - V_359 )
F_105 ( V_18 , V_388 ,
L_56
L_60 ,
V_508 ) ;
F_87 ( V_388 , L_61 ,
V_508 , V_509 ) ;
return V_509 ;
}
static int
F_169 ( struct V_3 * V_4 , struct V_9 * V_10 ,
struct V_451 * V_452 , T_10 V_481 ,
T_5 V_513 , T_8 V_514 ,
T_8 V_515 )
{
struct V_8 * V_34 = V_4 -> V_8 ;
struct V_380 * V_388 ;
struct V_188 * V_189 ;
V_388 = V_34 -> V_516 ( V_10 , V_514 , V_515 ,
V_513 ) ;
if ( ! V_388 )
return - V_458 ;
V_388 -> V_426 = V_481 ;
V_189 = F_85 ( V_388 ) ;
V_452 -> V_461 . V_511 . V_194 = V_189 -> V_194 ;
V_452 -> V_461 . V_511 . V_382 = V_388 -> V_382 ;
F_87 ( V_388 ,
L_62 ) ;
return 0 ;
}
static int
F_170 ( struct V_8 * V_34 , struct V_451 * V_452 )
{
struct V_378 * V_379 ;
struct V_380 * V_388 ;
V_388 = F_76 ( V_452 -> V_499 . V_517 . V_382 ) ;
if ( ! V_388 ) {
F_13 ( V_18 L_63 ,
V_452 -> V_499 . V_517 . V_382 ) ;
return - V_455 ;
}
V_379 = V_34 -> V_518 ( V_388 , V_452 -> V_499 . V_517 . V_385 ) ;
if ( ! V_379 ) {
F_105 ( V_18 , V_388 ,
L_64 ) ;
return - V_458 ;
}
V_452 -> V_461 . V_519 . V_382 = V_388 -> V_382 ;
V_452 -> V_461 . V_519 . V_385 = V_379 -> V_385 ;
F_139 ( V_379 , L_65 ) ;
return 0 ;
}
static int
F_171 ( struct V_8 * V_34 , struct V_451 * V_452 )
{
struct V_378 * V_379 ;
V_379 = F_80 ( V_452 -> V_499 . V_520 . V_382 , V_452 -> V_499 . V_520 . V_385 ) ;
if ( ! V_379 )
return - V_455 ;
F_139 ( V_379 , L_66 ) ;
if ( V_34 -> V_521 )
V_34 -> V_521 ( V_379 ) ;
return 0 ;
}
static int
F_172 ( struct V_8 * V_34 , struct V_451 * V_452 )
{
char * V_12 = ( char * ) V_452 + sizeof( * V_452 ) ;
struct V_378 * V_379 ;
struct V_380 * V_388 ;
int V_15 = 0 , V_183 = 0 ;
V_388 = F_76 ( V_452 -> V_499 . V_522 . V_382 ) ;
V_379 = F_80 ( V_452 -> V_499 . V_522 . V_382 , V_452 -> V_499 . V_522 . V_385 ) ;
if ( ! V_379 || ! V_388 )
return - V_455 ;
switch ( V_452 -> V_499 . V_522 . V_35 ) {
case V_523 :
sscanf ( V_12 , L_67 , & V_183 ) ;
if ( ! V_388 -> V_427 )
V_388 -> V_414 = V_183 ;
break;
default:
V_15 = V_34 -> V_522 ( V_379 , V_452 -> V_499 . V_522 . V_35 ,
V_12 , V_452 -> V_499 . V_522 . V_454 ) ;
}
return V_15 ;
}
static int F_173 ( struct V_8 * V_34 ,
struct V_451 * V_452 , int V_524 )
{
struct V_9 * V_10 ;
struct V_525 * V_526 ;
struct V_188 * V_189 = NULL ;
int V_527 , V_15 = 0 ;
if ( ! V_34 -> V_528 )
return - V_455 ;
if ( V_524 == V_529 ) {
V_189 = F_174 ( V_452 -> V_499 . V_530 . V_194 ) ;
if ( ! V_189 ) {
F_13 ( V_18 L_68
L_69 ,
V_452 -> V_499 . V_530 . V_194 ) ;
return - V_531 ;
}
V_527 = V_452 -> V_499 . V_530 . V_527 ;
} else
V_527 = V_452 -> V_499 . V_528 . V_527 ;
V_526 = (struct V_525 * ) ( ( char * ) V_452 + sizeof( * V_452 ) ) ;
V_10 = V_34 -> V_528 ( V_189 , V_526 , V_527 ) ;
if ( F_63 ( V_10 ) ) {
V_15 = F_65 ( V_10 ) ;
goto V_532;
}
V_452 -> V_461 . V_533 . V_26 = V_10 -> V_11 ;
V_532:
if ( V_189 )
F_86 ( V_189 ) ;
return V_15 ;
}
static int F_175 ( struct V_8 * V_34 ,
T_3 V_534 )
{
struct V_378 * V_379 ;
struct V_9 * V_10 ;
if ( ! V_34 -> V_535 )
return - V_455 ;
V_10 = F_21 ( V_534 ) ;
if ( ! V_10 )
return - V_455 ;
V_379 = V_10 -> V_379 ;
if ( V_379 ) {
F_94 ( & V_379 -> V_434 ) ;
V_379 -> V_10 = NULL ;
F_96 ( & V_379 -> V_434 ) ;
}
V_34 -> V_535 ( V_10 ) ;
return 0 ;
}
static int
F_176 ( struct V_8 * V_34 ,
struct V_451 * V_452 , int V_524 )
{
struct V_9 * V_10 ;
int V_509 = 0 ;
switch ( V_524 ) {
case V_529 :
case V_536 :
V_509 = F_173 ( V_34 , V_452 , V_524 ) ;
break;
case V_537 :
if ( ! V_34 -> V_538 )
return - V_455 ;
V_10 = F_21 ( V_452 -> V_499 . V_538 . V_534 ) ;
if ( ! V_10 )
return - V_455 ;
V_452 -> V_461 . V_539 = V_34 -> V_538 ( V_10 ,
V_452 -> V_499 . V_538 . V_540 ) ;
break;
case V_541 :
V_509 = F_175 ( V_34 ,
V_452 -> V_499 . V_535 . V_534 ) ;
break;
}
return V_509 ;
}
static int
F_177 ( struct V_8 * V_34 ,
struct V_451 * V_452 )
{
struct V_188 * V_189 ;
struct V_525 * V_526 ;
int V_15 ;
if ( ! V_34 -> V_542 )
return - V_455 ;
V_189 = F_174 ( V_452 -> V_499 . V_542 . V_194 ) ;
if ( ! V_189 ) {
F_13 ( V_18 L_70 ,
V_452 -> V_499 . V_542 . V_194 ) ;
return - V_531 ;
}
V_526 = (struct V_525 * ) ( ( char * ) V_452 + sizeof( * V_452 ) ) ;
V_15 = V_34 -> V_542 ( V_189 , V_452 -> V_499 . V_542 . type ,
V_452 -> V_499 . V_542 . V_543 , V_526 ) ;
F_86 ( V_189 ) ;
return V_15 ;
}
static int
F_178 ( struct V_8 * V_34 ,
struct V_451 * V_452 )
{
char * V_12 = ( char * ) V_452 + sizeof( * V_452 ) ;
struct V_188 * V_189 ;
int V_15 ;
if ( ! V_34 -> V_544 )
return - V_545 ;
V_189 = F_174 ( V_452 -> V_499 . V_544 . V_194 ) ;
if ( ! V_189 ) {
F_13 ( V_18 L_71 ,
V_452 -> V_499 . V_544 . V_194 ) ;
return - V_531 ;
}
V_15 = V_34 -> V_544 ( V_189 , V_452 -> V_499 . V_544 . V_35 ,
V_12 , V_452 -> V_499 . V_544 . V_454 ) ;
F_86 ( V_189 ) ;
return V_15 ;
}
static int
F_179 ( struct V_8 * V_34 , struct V_451 * V_452 )
{
struct V_188 * V_189 ;
struct V_546 * V_547 ;
int V_15 ;
if ( ! V_34 -> V_548 )
return - V_545 ;
V_189 = F_174 ( V_452 -> V_499 . V_548 . V_194 ) ;
if ( ! V_189 ) {
F_13 ( V_18 L_72 ,
V_452 -> V_499 . V_548 . V_194 ) ;
return - V_531 ;
}
V_547 = (struct V_546 * ) ( ( char * ) V_452 + sizeof( * V_452 ) ) ;
V_15 = V_34 -> V_548 ( V_189 , V_547 ) ;
F_86 ( V_189 ) ;
return V_15 ;
}
static int
F_180 ( struct V_8 * V_34 ,
struct V_451 * V_452 , T_5 V_454 )
{
char * V_12 = ( char * ) V_452 + sizeof( * V_452 ) ;
struct V_188 * V_189 ;
int V_15 ;
if ( ! V_34 -> V_549 )
return - V_545 ;
V_189 = F_174 ( V_452 -> V_499 . V_550 . V_194 ) ;
if ( ! V_189 ) {
F_13 ( V_18 L_73 ,
V_452 -> V_499 . V_550 . V_194 ) ;
return - V_531 ;
}
V_15 = V_34 -> V_549 ( V_189 , V_12 , V_454 ) ;
F_86 ( V_189 ) ;
return V_15 ;
}
static int
F_181 ( struct V_8 * V_34 , struct V_451 * V_452 )
{
struct V_188 * V_189 ;
struct V_525 * V_526 ;
int V_15 ;
if ( ! V_34 -> V_551 )
return - V_545 ;
V_189 = F_174 ( V_452 -> V_499 . V_552 . V_194 ) ;
if ( ! V_189 ) {
F_13 ( V_18 L_74 ,
V_452 -> V_499 . V_552 . V_194 ) ;
return - V_531 ;
}
V_526 = (struct V_525 * ) ( ( char * ) V_452 + sizeof( * V_452 ) ) ;
V_15 = V_34 -> V_551 ( V_189 , V_452 -> V_499 . V_552 . V_190 ,
V_452 -> V_499 . V_552 . V_103 ,
V_452 -> V_499 . V_552 . V_553 ,
V_452 -> V_499 . V_552 . V_481 ,
V_526 ) ;
F_86 ( V_189 ) ;
return V_15 ;
}
static int
F_182 ( struct V_8 * V_34 , struct V_449 * V_450 )
{
struct V_451 * V_452 = F_158 ( V_450 ) ;
struct V_188 * V_189 = NULL ;
struct V_554 * V_555 ;
struct V_3 * V_4 ;
struct V_441 * V_556 ;
struct V_449 * V_557 ;
struct V_451 * V_558 ;
T_5 V_559 ;
int V_454 , V_15 = 0 ;
char * V_7 ;
if ( ! V_34 -> V_560 )
return - V_455 ;
V_4 = F_149 ( V_34 ) ;
if ( ! V_4 )
return - V_455 ;
V_559 = ( V_452 -> V_499 . V_560 . V_561 * sizeof( * V_555 ) ) ;
V_454 = F_153 ( sizeof( * V_452 ) + V_559 ) ;
V_189 = F_174 ( V_452 -> V_499 . V_560 . V_194 ) ;
if ( ! V_189 ) {
F_13 ( V_18 L_75 ,
V_562 , V_452 -> V_499 . V_560 . V_194 ) ;
return - V_531 ;
}
do {
int V_502 ;
V_556 = F_154 ( V_454 , V_19 ) ;
if ( ! V_556 ) {
F_13 ( V_18 L_76 ) ;
V_15 = - V_458 ;
goto V_563;
}
V_557 = F_157 ( V_556 , 0 , 0 , 0 ,
( V_454 - sizeof( * V_557 ) ) , 0 ) ;
V_558 = F_158 ( V_557 ) ;
memset ( V_558 , 0 , sizeof( * V_558 ) ) ;
V_558 -> V_459 = F_5 ( V_34 ) ;
V_558 -> type = V_450 -> V_503 ;
V_558 -> V_499 . V_560 . V_194 = V_452 -> V_499 . V_560 . V_194 ;
V_558 -> V_499 . V_560 . V_564 = V_452 -> V_499 . V_560 . V_564 ;
V_558 -> V_499 . V_560 . V_561 = V_452 -> V_499 . V_560 . V_561 ;
V_7 = ( char * ) V_558 + sizeof( * V_558 ) ;
memset ( V_7 , 0 , V_559 ) ;
V_15 = V_34 -> V_560 ( V_189 , V_452 -> V_499 . V_560 . V_564 ,
& V_558 -> V_499 . V_560 . V_561 , V_7 ) ;
V_502 = F_153 ( sizeof( * V_452 ) + V_559 ) ;
F_166 ( V_556 , F_167 ( V_502 ) ) ;
V_557 -> V_505 = V_502 ;
V_15 = F_150 ( V_556 , V_463 ,
V_19 ) ;
} while ( V_15 < 0 && V_15 != - V_506 );
V_563:
F_86 ( V_189 ) ;
return V_15 ;
}
static int F_183 ( struct V_8 * V_34 ,
struct V_451 * V_452 , T_5 V_454 )
{
char * V_12 = ( char * ) V_452 + sizeof( * V_452 ) ;
struct V_188 * V_189 ;
int V_15 = 0 ;
if ( ! V_34 -> V_565 )
return - V_545 ;
V_189 = F_174 ( V_452 -> V_499 . V_548 . V_194 ) ;
if ( ! V_189 ) {
F_53 ( L_77 ,
V_562 , V_452 -> V_499 . V_548 . V_194 ) ;
return - V_531 ;
}
V_15 = V_34 -> V_565 ( V_189 , V_12 , V_454 ) ;
F_86 ( V_189 ) ;
return V_15 ;
}
static int F_184 ( struct V_8 * V_34 ,
struct V_451 * V_452 )
{
struct V_188 * V_189 ;
int V_15 = 0 ;
if ( ! V_34 -> V_566 )
return - V_545 ;
V_189 = F_174 ( V_452 -> V_499 . V_566 . V_194 ) ;
if ( ! V_189 ) {
F_13 ( V_18 L_77 ,
V_562 , V_452 -> V_499 . V_566 . V_194 ) ;
return - V_531 ;
}
V_15 = V_34 -> V_566 ( V_189 , V_452 -> V_499 . V_566 . V_564 ) ;
F_86 ( V_189 ) ;
return V_15 ;
}
char * F_185 ( int V_567 )
{
int V_32 ;
char * V_181 = L_78 ;
for ( V_32 = 0 ; V_32 < F_28 ( V_568 ) ; V_32 ++ ) {
if ( V_568 [ V_32 ] . V_183 & V_567 ) {
V_181 = V_568 [ V_32 ] . V_184 ;
break;
}
}
return V_181 ;
}
static int F_186 ( struct V_8 * V_34 ,
struct V_451 * V_452 , T_5 V_454 )
{
char * V_12 = ( char * ) V_452 + sizeof( * V_452 ) ;
struct V_188 * V_189 ;
struct V_198 * V_199 ;
struct V_270 * V_271 ;
struct V_1 * V_2 ;
T_5 V_339 ;
int V_15 = 0 ;
if ( ! V_34 -> V_569 ) {
V_15 = - V_545 ;
goto V_570;
}
V_189 = F_174 ( V_452 -> V_499 . V_571 . V_194 ) ;
if ( ! V_189 ) {
F_53 ( L_77 ,
V_562 , V_452 -> V_499 . V_571 . V_194 ) ;
V_15 = - V_531 ;
goto V_572;
}
V_339 = V_452 -> V_499 . V_571 . V_573 ;
V_199 = F_45 ( V_189 , V_339 ) ;
if ( ! V_199 ) {
F_53 ( L_79 ,
V_562 , V_339 , V_452 -> V_499 . V_571 . V_194 ) ;
V_15 = - V_531 ;
goto V_572;
}
V_2 = F_49 ( V_199 ) ;
if ( ! V_2 ) {
V_15 = - V_531 ;
goto V_574;
}
V_271 = F_37 ( V_2 ) ;
V_15 = V_34 -> V_569 ( V_199 , V_271 , V_12 , V_454 ) ;
F_12 ( V_2 ) ;
V_574:
F_12 ( & V_199 -> V_2 ) ;
V_572:
F_86 ( V_189 ) ;
V_570:
return V_15 ;
}
static int F_187 ( struct V_8 * V_34 ,
struct V_451 * V_452 , T_5 V_454 )
{
char * V_12 = ( char * ) V_452 + sizeof( * V_452 ) ;
struct V_188 * V_189 ;
int V_331 ;
int V_15 = 0 ;
if ( ! V_34 -> V_575 ) {
V_15 = - V_545 ;
goto V_576;
}
V_189 = F_174 ( V_452 -> V_499 . V_575 . V_194 ) ;
if ( ! V_189 ) {
F_53 ( L_77 ,
V_562 , V_452 -> V_499 . V_575 . V_194 ) ;
V_15 = - V_531 ;
goto V_572;
}
V_331 = V_34 -> V_575 ( V_189 , V_12 , V_454 ) ;
if ( V_331 >= 0 )
V_452 -> V_461 . V_577 . V_573 = V_331 ;
else
V_15 = - V_578 ;
V_572:
F_86 ( V_189 ) ;
V_576:
return V_15 ;
}
static int F_188 ( struct V_8 * V_34 ,
struct V_451 * V_452 )
{
struct V_188 * V_189 ;
struct V_198 * V_199 ;
T_5 V_339 ;
int V_15 = 0 ;
if ( ! V_34 -> V_579 ) {
V_15 = - V_545 ;
goto V_580;
}
V_189 = F_174 ( V_452 -> V_499 . V_579 . V_194 ) ;
if ( ! V_189 ) {
F_53 ( L_77 ,
V_562 , V_452 -> V_499 . V_579 . V_194 ) ;
V_15 = - V_531 ;
goto V_572;
}
V_339 = V_452 -> V_499 . V_579 . V_573 ;
V_199 = F_45 ( V_189 , V_339 ) ;
if ( ! V_199 ) {
F_53 ( L_79 ,
V_562 , V_339 , V_452 -> V_499 . V_579 . V_194 ) ;
V_15 = - V_531 ;
goto V_572;
}
V_15 = V_34 -> V_579 ( V_199 ) ;
F_12 ( & V_199 -> V_2 ) ;
V_572:
F_86 ( V_189 ) ;
V_580:
return V_15 ;
}
static int F_189 ( struct V_8 * V_34 ,
struct V_451 * V_452 )
{
struct V_188 * V_189 ;
struct V_198 * V_199 ;
struct V_270 * V_271 ;
struct V_1 * V_2 ;
T_5 V_339 ;
int V_15 = 0 ;
if ( ! V_34 -> V_581 ) {
V_15 = - V_545 ;
goto V_582;
}
V_189 = F_174 ( V_452 -> V_499 . V_581 . V_194 ) ;
if ( ! V_189 ) {
F_53 ( L_77 ,
V_562 , V_452 -> V_499 . V_581 . V_194 ) ;
V_15 = - V_531 ;
goto V_572;
}
V_339 = V_452 -> V_499 . V_581 . V_573 ;
V_199 = F_45 ( V_189 , V_339 ) ;
if ( ! V_199 ) {
F_53 ( L_79 ,
V_562 , V_339 , V_452 -> V_499 . V_581 . V_194 ) ;
V_15 = - V_531 ;
goto V_572;
}
V_2 = F_49 ( V_199 ) ;
if ( ! V_2 ) {
V_15 = - V_531 ;
goto V_574;
}
V_271 = F_37 ( V_2 ) ;
V_15 = V_34 -> V_581 ( V_199 , V_271 ) ;
F_12 ( V_2 ) ;
V_574:
F_12 ( & V_199 -> V_2 ) ;
V_572:
F_86 ( V_189 ) ;
V_582:
return V_15 ;
}
static int F_190 ( struct V_8 * V_34 ,
struct V_451 * V_452 )
{
struct V_188 * V_189 ;
struct V_198 * V_199 ;
struct V_270 * V_271 ;
struct V_1 * V_2 ;
T_5 V_339 ;
int V_15 = 0 ;
if ( ! V_34 -> V_583 ) {
V_15 = - V_545 ;
goto V_584;
}
V_189 = F_174 ( V_452 -> V_499 . V_583 . V_194 ) ;
if ( ! V_189 ) {
F_53 ( L_77 ,
V_562 , V_452 -> V_499 . V_583 . V_194 ) ;
V_15 = - V_531 ;
goto V_572;
}
V_339 = V_452 -> V_499 . V_583 . V_573 ;
V_199 = F_45 ( V_189 , V_339 ) ;
if ( ! V_199 ) {
F_53 ( L_79 ,
V_562 , V_339 , V_452 -> V_499 . V_583 . V_194 ) ;
V_15 = - V_531 ;
goto V_572;
}
V_2 = F_49 ( V_199 ) ;
if ( ! V_2 ) {
V_15 = - V_531 ;
goto V_574;
}
V_271 = F_37 ( V_2 ) ;
V_15 = V_34 -> V_583 ( V_199 , V_271 ) ;
F_12 ( V_2 ) ;
V_574:
F_12 ( & V_199 -> V_2 ) ;
V_572:
F_86 ( V_189 ) ;
V_584:
return V_15 ;
}
static int F_191 ( struct V_8 * V_34 ,
struct V_451 * V_452 )
{
struct V_188 * V_189 ;
struct V_380 * V_388 ;
int V_15 = 0 ;
if ( ! V_34 -> V_585 ) {
V_15 = - V_545 ;
goto V_586;
}
V_189 = F_174 ( V_452 -> V_499 . V_585 . V_194 ) ;
if ( ! V_189 ) {
F_53 ( L_77 ,
V_562 , V_452 -> V_499 . V_583 . V_194 ) ;
V_15 = - V_531 ;
goto V_572;
}
V_388 = F_76 ( V_452 -> V_499 . V_585 . V_382 ) ;
if ( ! V_388 ) {
F_53 ( L_80 ,
V_562 , V_452 -> V_499 . V_585 . V_382 ) ;
V_15 = - V_455 ;
goto V_572;
}
V_15 = V_34 -> V_585 ( V_388 ) ;
V_572:
F_86 ( V_189 ) ;
V_586:
return V_15 ;
}
static int
F_192 ( struct V_8 * V_34 , struct V_449 * V_450 )
{
struct V_451 * V_452 = F_158 ( V_450 ) ;
struct V_188 * V_189 = NULL ;
struct V_3 * V_4 ;
struct V_441 * V_587 ;
struct V_449 * V_588 ;
struct V_451 * V_589 ;
int V_590 = 0 ;
int V_454 , V_15 = 0 ;
char * V_7 ;
if ( ! V_34 -> V_591 )
return - V_545 ;
V_4 = F_149 ( V_34 ) ;
if ( ! V_4 )
return - V_455 ;
V_590 = sizeof( struct V_592 ) ;
V_454 = F_153 ( sizeof( * V_452 ) + V_590 ) ;
V_189 = F_174 ( V_452 -> V_499 . V_591 . V_194 ) ;
if ( ! V_189 ) {
F_53 ( L_81 ,
V_562 , V_452 -> V_499 . V_591 . V_194 ) ;
return - V_531 ;
}
do {
int V_502 ;
V_587 = F_154 ( V_454 , V_19 ) ;
if ( ! V_587 ) {
F_53 ( L_82 ) ;
V_15 = - V_458 ;
goto V_593;
}
V_588 = F_157 ( V_587 , 0 , 0 , 0 ,
( V_454 - sizeof( * V_588 ) ) , 0 ) ;
V_589 = F_158 ( V_588 ) ;
memset ( V_589 , 0 , sizeof( * V_589 ) ) ;
V_589 -> V_459 = F_5 ( V_34 ) ;
V_589 -> type = V_450 -> V_503 ;
V_589 -> V_499 . V_591 . V_194 =
V_452 -> V_499 . V_591 . V_194 ;
V_7 = ( char * ) V_589 + sizeof( * V_589 ) ;
memset ( V_7 , 0 , V_590 ) ;
V_15 = V_34 -> V_591 ( V_189 , V_7 , V_590 ) ;
if ( V_15 ) {
F_168 ( V_587 ) ;
goto V_593;
}
V_502 = F_153 ( sizeof( * V_452 ) + V_590 ) ;
F_166 ( V_587 , F_167 ( V_502 ) ) ;
V_588 -> V_505 = V_502 ;
V_15 = F_150 ( V_587 , V_463 ,
V_19 ) ;
} while ( V_15 < 0 && V_15 != - V_506 );
V_593:
F_86 ( V_189 ) ;
return V_15 ;
}
static int
F_193 ( struct V_441 * V_442 , struct V_449 * V_450 , T_5 * V_443 )
{
int V_15 = 0 ;
struct V_451 * V_452 = F_158 ( V_450 ) ;
struct V_8 * V_34 = NULL ;
struct V_3 * V_4 ;
struct V_380 * V_388 ;
struct V_378 * V_379 ;
struct V_9 * V_10 = NULL ;
if ( V_450 -> V_503 == V_594 )
* V_443 = V_468 ;
else
* V_443 = V_463 ;
V_4 = F_149 ( F_194 ( V_452 -> V_459 ) ) ;
if ( ! V_4 )
return - V_455 ;
V_34 = V_4 -> V_8 ;
if ( ! F_195 ( V_34 -> V_595 ) )
return - V_455 ;
switch ( V_450 -> V_503 ) {
case V_596 :
V_15 = F_169 ( V_4 , V_10 , V_452 ,
F_196 ( V_442 ) . V_597 ,
V_452 -> V_499 . V_598 . V_513 ,
V_452 -> V_499 . V_598 . V_514 ,
V_452 -> V_499 . V_598 . V_515 ) ;
break;
case V_599 :
V_10 = F_21 ( V_452 -> V_499 . V_600 . V_534 ) ;
if ( ! V_10 ) {
V_15 = - V_455 ;
break;
}
V_15 = F_169 ( V_4 , V_10 , V_452 ,
F_196 ( V_442 ) . V_597 ,
V_452 -> V_499 . V_600 . V_513 ,
V_452 -> V_499 . V_600 . V_514 ,
V_452 -> V_499 . V_600 . V_515 ) ;
break;
case V_601 :
V_388 = F_76 ( V_452 -> V_499 . V_510 . V_382 ) ;
if ( V_388 )
V_34 -> V_602 ( V_388 ) ;
else
V_15 = - V_455 ;
break;
case V_603 :
V_388 = F_76 ( V_452 -> V_499 . V_510 . V_382 ) ;
if ( V_388 )
F_109 ( F_85 ( V_388 ) ,
& V_388 -> V_422 ) ;
else
V_15 = - V_455 ;
break;
case V_604 :
V_15 = F_170 ( V_34 , V_452 ) ;
break;
case V_605 :
V_15 = F_171 ( V_34 , V_452 ) ;
break;
case V_606 :
V_388 = F_76 ( V_452 -> V_499 . V_607 . V_382 ) ;
V_379 = F_80 ( V_452 -> V_499 . V_607 . V_382 , V_452 -> V_499 . V_607 . V_385 ) ;
if ( V_379 && V_379 -> V_10 )
F_175 ( V_34 , V_379 -> V_10 -> V_11 ) ;
if ( ! V_388 || ! V_379 ) {
V_15 = - V_455 ;
break;
}
V_452 -> V_461 . V_539 = V_34 -> V_608 ( V_388 , V_379 ,
V_452 -> V_499 . V_607 . V_609 ,
V_452 -> V_499 . V_607 . V_610 ) ;
if ( V_452 -> V_461 . V_539 || ! V_34 -> V_528 )
break;
V_10 = F_21 ( V_452 -> V_499 . V_607 . V_609 ) ;
if ( V_10 ) {
V_10 -> V_379 = V_379 ;
F_94 ( & V_379 -> V_434 ) ;
V_379 -> V_10 = V_10 ;
F_96 ( & V_379 -> V_434 ) ;
} else
F_156 ( V_18 , V_379 ,
L_83
L_84 ) ;
break;
case V_611 :
V_15 = F_172 ( V_34 , V_452 ) ;
break;
case V_612 :
V_379 = F_80 ( V_452 -> V_499 . V_613 . V_382 , V_452 -> V_499 . V_613 . V_385 ) ;
if ( V_379 )
V_452 -> V_461 . V_539 = V_34 -> V_613 ( V_379 ) ;
else
V_15 = - V_455 ;
break;
case V_614 :
V_379 = F_80 ( V_452 -> V_499 . V_615 . V_382 , V_452 -> V_499 . V_615 . V_385 ) ;
if ( V_379 )
V_34 -> V_615 ( V_379 , V_452 -> V_499 . V_615 . V_616 ) ;
else
V_15 = - V_455 ;
break;
case V_617 :
V_379 = F_80 ( V_452 -> V_499 . V_618 . V_382 , V_452 -> V_499 . V_618 . V_385 ) ;
if ( V_379 )
V_452 -> V_461 . V_539 = V_34 -> V_618 ( V_379 ,
(struct V_446 * ) ( ( char * ) V_452 + sizeof( * V_452 ) ) ,
( char * ) V_452 + sizeof( * V_452 ) + V_452 -> V_499 . V_618 . V_619 ,
V_452 -> V_499 . V_618 . V_448 ) ;
else
V_15 = - V_455 ;
break;
case V_620 :
V_15 = F_164 ( V_34 , V_450 ) ;
break;
case V_536 :
case V_537 :
case V_541 :
case V_529 :
V_15 = F_176 ( V_34 , V_452 , V_450 -> V_503 ) ;
break;
case V_621 :
V_15 = F_177 ( V_34 , V_452 ) ;
break;
case V_622 :
V_15 = F_178 ( V_34 , V_452 ) ;
break;
case V_594 :
V_15 = F_179 ( V_34 , V_452 ) ;
break;
case V_623 :
V_15 = F_180 ( V_34 , V_452 ,
F_197 ( V_450 , sizeof( * V_452 ) ) ) ;
break;
case V_624 :
V_15 = F_181 ( V_34 , V_452 ) ;
break;
case V_625 :
V_15 = F_182 ( V_34 , V_450 ) ;
break;
case V_626 :
V_15 = F_184 ( V_34 , V_452 ) ;
break;
case V_627 :
V_15 = F_186 ( V_34 , V_452 ,
F_197 ( V_450 ,
sizeof( * V_452 ) ) ) ;
break;
case V_628 :
V_15 = F_187 ( V_34 , V_452 ,
F_197 ( V_450 , sizeof( * V_452 ) ) ) ;
break;
case V_629 :
V_15 = F_188 ( V_34 , V_452 ) ;
break;
case V_630 :
V_15 = F_189 ( V_34 , V_452 ) ;
break;
case V_631 :
V_15 = F_190 ( V_34 , V_452 ) ;
break;
case V_632 :
V_15 = F_191 ( V_34 , V_452 ) ;
break;
case V_633 :
V_15 = F_183 ( V_34 , V_452 ,
F_197 ( V_450 , sizeof( * V_452 ) ) ) ;
break;
case V_634 :
V_15 = F_192 ( V_34 , V_450 ) ;
break;
default:
V_15 = - V_545 ;
break;
}
F_198 ( V_34 -> V_595 ) ;
return V_15 ;
}
static void
F_199 ( struct V_441 * V_442 )
{
F_94 ( & V_635 ) ;
while ( V_442 -> V_454 >= V_636 ) {
int V_15 ;
T_5 V_637 ;
struct V_449 * V_450 ;
struct V_451 * V_452 ;
T_5 V_443 ;
V_450 = F_200 ( V_442 ) ;
if ( V_450 -> V_505 < sizeof( * V_450 ) + sizeof( * V_452 ) ||
V_442 -> V_454 < V_450 -> V_505 ) {
break;
}
V_452 = F_158 ( V_450 ) ;
V_637 = F_167 ( V_450 -> V_505 ) ;
if ( V_637 > V_442 -> V_454 )
V_637 = V_442 -> V_454 ;
V_15 = F_193 ( V_442 , V_450 , & V_443 ) ;
if ( V_15 ) {
V_452 -> type = V_638 ;
V_452 -> V_639 = V_15 ;
}
do {
if ( V_452 -> type == V_620 && ! V_15 )
break;
if ( V_452 -> type == V_625 && ! V_15 )
break;
V_15 = F_163 ( V_443 , V_450 -> V_640 ,
V_450 -> V_503 , 0 , 0 , V_452 , sizeof( * V_452 ) ) ;
} while ( V_15 < 0 && V_15 != - V_506 && V_15 != - V_359 );
F_201 ( V_442 , V_637 ) ;
}
F_96 ( & V_635 ) ;
}
static T_4 F_202 ( struct V_30 * V_22 ,
struct V_31 * V_6 , int V_32 )
{
struct V_1 * V_374 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_378 * V_379 = F_203 ( V_374 ) ;
struct V_8 * V_33 = V_379 -> V_34 ;
int V_35 ;
if ( V_6 == & V_641 . V_6 )
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
else if ( V_6 == & V_699 . V_6 )
V_35 = V_700 ;
else {
F_26 ( 1 , L_85 ) ;
return 0 ;
}
return V_33 -> V_178 ( V_701 , V_35 ) ;
}
static T_1
F_204 ( struct V_1 * V_2 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_380 * V_388 = F_75 ( V_2 -> V_29 ) ;
return sprintf ( V_7 , L_86 , F_81 ( V_388 -> V_181 ) ) ;
}
static T_1
F_205 ( struct V_1 * V_2 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_380 * V_388 = F_75 ( V_2 -> V_29 ) ;
return sprintf ( V_7 , L_87 , V_388 -> V_426 ) ;
}
static T_1
F_206 ( struct V_1 * V_2 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_380 * V_388 = F_75 ( V_2 -> V_29 ) ;
return sprintf ( V_7 , L_87 , V_388 -> V_332 ) ;
}
static T_4 F_207 ( struct V_30 * V_22 ,
struct V_31 * V_6 , int V_32 )
{
struct V_1 * V_374 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_380 * V_388 = F_208 ( V_374 ) ;
struct V_8 * V_33 = V_388 -> V_34 ;
int V_35 ;
if ( V_6 == & V_702 . V_6 )
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
V_35 = V_781 ;
else if ( V_6 == & V_782 . V_6 )
return V_783 | V_784 ;
else if ( V_6 == & V_785 . V_6 )
return V_783 ;
else if ( V_6 == & V_786 . V_6 )
return V_783 ;
else if ( V_6 == & V_787 . V_6 )
return V_783 ;
else {
F_26 ( 1 , L_88 ) ;
return 0 ;
}
return V_33 -> V_178 ( V_701 , V_35 ) ;
}
static T_4 F_209 ( struct V_30 * V_22 ,
struct V_31 * V_6 , int V_32 )
{
struct V_1 * V_374 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_188 * V_189 = F_210 ( V_374 ) ;
struct V_3 * V_4 = F_58 ( V_189 -> V_347 ) ;
int V_35 ;
if ( V_6 == & V_788 . V_6 )
V_35 = V_789 ;
else if ( V_6 == & V_790 . V_6 )
V_35 = V_791 ;
else if ( V_6 == & V_792 . V_6 )
V_35 = V_793 ;
else if ( V_6 == & V_794 . V_6 )
V_35 = V_795 ;
else if ( V_6 == & V_796 . V_6 )
V_35 = V_797 ;
else if ( V_6 == & V_798 . V_6 )
V_35 = V_799 ;
else {
F_26 ( 1 , L_89 ) ;
return 0 ;
}
return V_4 -> V_8 -> V_178 ( V_800 , V_35 ) ;
}
char * F_211 ( struct V_188 * V_189 )
{
int V_32 ;
char * V_801 = L_78 ;
struct V_365 * V_366 = V_189 -> V_375 ;
T_5 V_802 = V_366 -> V_802 ;
for ( V_32 = 0 ; V_32 < F_28 ( V_803 ) ; V_32 ++ ) {
if ( V_803 [ V_32 ] . V_183 & V_802 ) {
V_801 = V_803 [ V_32 ] . V_184 ;
break;
}
}
return V_801 ;
}
char * F_212 ( struct V_188 * V_189 )
{
int V_32 ;
char * V_181 = L_78 ;
struct V_365 * V_366 = V_189 -> V_375 ;
T_5 V_180 = V_366 -> V_180 ;
for ( V_32 = 0 ; V_32 < F_28 ( V_804 ) ; V_32 ++ ) {
if ( V_804 [ V_32 ] . V_183 & V_180 ) {
V_181 = V_804 [ V_32 ] . V_184 ;
break;
}
}
return V_181 ;
}
static int F_213 ( struct V_805 * V_806 ,
struct V_1 * V_2 )
{
struct V_380 * V_388 ;
struct V_188 * V_189 ;
struct V_3 * V_4 ;
if ( ! F_88 ( V_2 ) )
return 0 ;
V_388 = F_75 ( V_2 ) ;
V_189 = F_85 ( V_388 ) ;
if ( ! V_189 -> V_347 )
return 0 ;
V_4 = F_58 ( V_189 -> V_347 ) ;
if ( V_4 -> V_807 . V_808 . V_20 != & V_809 . V_20 )
return 0 ;
return & V_4 -> V_807 . V_808 == V_806 ;
}
static int F_214 ( struct V_805 * V_806 ,
struct V_1 * V_2 )
{
struct V_380 * V_388 ;
struct V_378 * V_379 ;
struct V_188 * V_189 ;
struct V_3 * V_4 ;
if ( ! F_140 ( V_2 ) )
return 0 ;
V_379 = F_138 ( V_2 ) ;
V_388 = F_75 ( V_379 -> V_2 . V_29 ) ;
V_189 = F_85 ( V_388 ) ;
if ( ! V_189 -> V_347 )
return 0 ;
V_4 = F_58 ( V_189 -> V_347 ) ;
if ( V_4 -> V_810 . V_808 . V_20 != & V_811 . V_20 )
return 0 ;
return & V_4 -> V_810 . V_808 == V_806 ;
}
static int F_215 ( struct V_805 * V_806 ,
struct V_1 * V_2 )
{
struct V_188 * V_189 ;
struct V_3 * V_4 ;
if ( ! F_216 ( V_2 ) )
return 0 ;
V_189 = F_68 ( V_2 ) ;
if ( ! V_189 -> V_347 ||
V_189 -> V_347 -> V_812 . V_808 . V_20 != & V_813 . V_20 )
return 0 ;
V_4 = F_58 ( V_189 -> V_347 ) ;
return & V_4 -> V_33 . V_812 . V_808 == V_806 ;
}
struct V_814 *
F_217 ( struct V_8 * V_439 )
{
struct V_3 * V_4 ;
unsigned long V_383 ;
int V_15 ;
F_59 ( ! V_439 ) ;
V_4 = F_149 ( V_439 ) ;
if ( V_4 )
return NULL ;
V_4 = F_14 ( sizeof( * V_4 ) , V_19 ) ;
if ( ! V_4 )
return NULL ;
F_124 ( & V_4 -> V_815 ) ;
V_4 -> V_8 = V_439 ;
V_4 -> V_33 . V_816 = F_97 ;
V_4 -> V_33 . V_817 = 1 ;
V_4 -> V_2 . V_20 = & V_818 ;
F_15 ( & V_4 -> V_2 , L_90 , V_439 -> V_184 ) ;
V_15 = F_16 ( & V_4 -> V_2 ) ;
if ( V_15 )
goto V_819;
V_15 = F_17 ( & V_4 -> V_2 . V_22 , & V_820 ) ;
if ( V_15 )
goto V_24;
V_4 -> V_33 . V_812 . V_808 . V_20 = & V_813 . V_20 ;
V_4 -> V_33 . V_812 . V_808 . V_821 = F_215 ;
V_4 -> V_33 . V_812 . V_808 . V_822 = & V_823 ;
V_4 -> V_33 . V_824 = sizeof( struct V_365 ) ;
F_218 ( & V_4 -> V_33 . V_812 ) ;
V_4 -> V_810 . V_808 . V_20 = & V_811 . V_20 ;
V_4 -> V_810 . V_808 . V_821 = F_214 ;
V_4 -> V_810 . V_808 . V_822 = & V_825 ;
F_218 ( & V_4 -> V_810 ) ;
V_4 -> V_807 . V_808 . V_20 = & V_809 . V_20 ;
V_4 -> V_807 . V_808 . V_821 = F_213 ;
V_4 -> V_807 . V_808 . V_822 = & V_826 ;
F_218 ( & V_4 -> V_807 ) ;
F_77 ( & V_440 , V_383 ) ;
F_134 ( & V_4 -> V_815 , & V_827 ) ;
F_79 ( & V_440 , V_383 ) ;
F_13 ( V_828 L_91 , V_439 -> V_184 ) ;
return & V_4 -> V_33 ;
V_24:
F_18 ( & V_4 -> V_2 ) ;
return NULL ;
V_819:
F_3 ( V_4 ) ;
return NULL ;
}
int F_219 ( struct V_8 * V_439 )
{
struct V_3 * V_4 ;
unsigned long V_383 ;
F_59 ( ! V_439 ) ;
F_94 ( & V_635 ) ;
V_4 = F_149 ( V_439 ) ;
F_59 ( ! V_4 ) ;
F_77 ( & V_440 , V_383 ) ;
F_144 ( & V_4 -> V_815 ) ;
F_79 ( & V_440 , V_383 ) ;
F_220 ( & V_4 -> V_810 ) ;
F_220 ( & V_4 -> V_807 ) ;
F_220 ( & V_4 -> V_33 . V_812 ) ;
F_20 ( & V_4 -> V_2 . V_22 , & V_820 ) ;
F_18 ( & V_4 -> V_2 ) ;
F_96 ( & V_635 ) ;
return 0 ;
}
static T_11 int F_221 ( void )
{
int V_15 ;
struct V_829 V_830 = {
. V_831 = 1 ,
. V_832 = F_199 ,
} ;
F_13 ( V_413 L_92 ,
V_833 ) ;
F_69 ( & V_429 , 0 ) ;
V_15 = F_222 ( & V_818 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_222 ( & V_17 ) ;
if ( V_15 )
goto V_834;
V_15 = F_222 ( & V_192 ) ;
if ( V_15 )
goto V_835;
V_15 = F_223 ( & V_813 ) ;
if ( V_15 )
goto V_836;
V_15 = F_223 ( & V_811 ) ;
if ( V_15 )
goto V_837;
V_15 = F_223 ( & V_809 ) ;
if ( V_15 )
goto V_838;
V_15 = F_224 ( & V_330 ) ;
if ( V_15 )
goto V_839;
V_445 = F_225 ( & V_840 , V_841 , & V_830 ) ;
if ( ! V_445 ) {
V_15 = - V_842 ;
goto V_843;
}
V_419 = F_226 ( L_93 ) ;
if ( ! V_419 ) {
V_15 = - V_458 ;
goto V_844;
}
return 0 ;
V_844:
F_227 ( V_445 ) ;
V_843:
F_228 ( & V_330 ) ;
V_839:
F_229 ( & V_809 ) ;
V_838:
F_229 ( & V_811 ) ;
V_837:
F_229 ( & V_813 ) ;
V_836:
F_230 ( & V_192 ) ;
V_835:
F_230 ( & V_17 ) ;
V_834:
F_230 ( & V_818 ) ;
return V_15 ;
}
static void T_12 F_231 ( void )
{
F_232 ( V_419 ) ;
F_227 ( V_445 ) ;
F_228 ( & V_330 ) ;
F_229 ( & V_811 ) ;
F_229 ( & V_809 ) ;
F_229 ( & V_813 ) ;
F_230 ( & V_17 ) ;
F_230 ( & V_192 ) ;
F_230 ( & V_818 ) ;
}
