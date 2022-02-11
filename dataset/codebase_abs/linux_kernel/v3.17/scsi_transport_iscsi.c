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
}
if ( V_11 == V_16 ) {
F_12 ( V_18 L_2 ,
V_16 - 1 ) ;
return NULL ;
}
V_10 = F_13 ( sizeof( * V_10 ) + V_14 , V_19 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_11 = V_11 ;
V_10 -> V_2 . V_20 = & V_17 ;
F_14 ( & V_10 -> V_2 , L_3 , ( unsigned long long ) V_11 ) ;
V_15 = F_15 ( & V_10 -> V_2 ) ;
if ( V_15 )
goto V_21;
V_15 = F_16 ( & V_10 -> V_2 . V_22 , & V_23 ) ;
if ( V_15 )
goto V_24;
if ( V_14 )
V_10 -> V_25 = & V_10 [ 1 ] ;
return V_10 ;
V_24:
F_17 ( & V_10 -> V_2 ) ;
return NULL ;
V_21:
F_3 ( V_10 ) ;
return NULL ;
}
void F_18 ( struct V_9 * V_10 )
{
F_19 ( & V_10 -> V_2 . V_22 , & V_23 ) ;
F_17 ( & V_10 -> V_2 ) ;
}
struct V_9 * F_20 ( T_3 V_26 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
V_2 = F_11 ( & V_17 , NULL , & V_26 ,
F_9 ) ;
if ( ! V_2 )
return NULL ;
V_10 = F_7 ( V_2 ) ;
F_21 ( V_2 ) ;
return V_10 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = F_23 ( V_2 ) ;
struct V_1 * V_29 = V_28 -> V_2 . V_29 ;
F_3 ( V_28 ) ;
F_21 ( V_29 ) ;
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
V_28 = F_13 ( sizeof( * V_28 ) + V_14 , V_19 ) ;
if ( ! V_28 )
return NULL ;
V_28 -> V_34 = V_34 ;
V_28 -> V_103 = V_103 ;
V_28 -> V_190 = V_190 ;
V_28 -> V_2 . V_191 = F_22 ;
V_28 -> V_2 . V_20 = & V_192 ;
V_28 -> V_2 . V_29 = F_31 ( & V_189 -> V_193 ) ;
if ( V_103 == V_104 )
F_14 ( & V_28 -> V_2 , L_5 , V_189 -> V_194 ,
V_190 ) ;
else
F_14 ( & V_28 -> V_2 , L_6 , V_189 -> V_194 ,
V_190 ) ;
V_15 = F_15 ( & V_28 -> V_2 ) ;
if ( V_15 )
goto V_195;
V_15 = F_16 ( & V_28 -> V_2 . V_22 , & V_196 ) ;
if ( V_15 )
goto V_197;
if ( V_14 )
V_28 -> V_25 = & V_28 [ 1 ] ;
return V_28 ;
V_197:
F_17 ( & V_28 -> V_2 ) ;
return NULL ;
V_195:
F_21 ( V_28 -> V_2 . V_29 ) ;
F_3 ( V_28 ) ;
return NULL ;
}
void F_32 ( struct V_27 * V_28 )
{
F_19 ( & V_28 -> V_2 . V_22 , & V_196 ) ;
F_17 ( & V_28 -> V_2 ) ;
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
V_199 = F_13 ( sizeof( * V_199 ) + V_14 , V_19 ) ;
if ( ! V_199 )
return NULL ;
V_199 -> V_34 = V_34 ;
V_199 -> V_332 = V_331 ;
V_199 -> V_2 . type = & V_333 ;
V_199 -> V_2 . V_329 = & V_330 ;
V_199 -> V_2 . V_29 = & V_189 -> V_193 ;
F_14 ( & V_199 -> V_2 , L_9 ,
V_189 -> V_194 , V_331 ) ;
V_15 = F_15 ( & V_199 -> V_2 ) ;
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
V_271 = F_13 ( sizeof( * V_271 ) + V_14 , V_19 ) ;
if ( ! V_271 )
return NULL ;
V_271 -> V_34 = V_34 ;
V_271 -> V_2 . type = & V_335 ;
V_271 -> V_2 . V_329 = & V_330 ;
V_271 -> V_2 . V_29 = & V_199 -> V_2 ;
F_14 ( & V_271 -> V_2 , L_10 ,
V_189 -> V_194 , V_199 -> V_332 ) ;
V_15 = F_15 ( & V_271 -> V_2 ) ;
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
F_17 ( & V_271 -> V_2 ) ;
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
F_17 ( & V_199 -> V_2 ) ;
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
V_390 = F_13 ( sizeof( * V_390 ) + V_14 ,
V_19 ) ;
if ( ! V_390 )
return NULL ;
V_390 -> V_34 = V_34 ;
V_390 -> V_425 = - 1 ;
V_390 -> V_413 = 120 ;
V_390 -> V_181 = V_395 ;
F_121 ( & V_390 -> V_411 , F_102 ) ;
F_122 ( & V_390 -> V_426 ) ;
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
V_390 -> V_384 = F_128 ( 1 , & V_427 ) ;
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
F_14 ( & V_390 -> V_2 , L_29 , V_390 -> V_384 ) ;
V_15 = F_130 ( & V_390 -> V_2 ) ;
if ( V_15 ) {
F_103 ( V_18 , V_390 ,
L_30 ) ;
goto V_428;
}
F_131 ( & V_390 -> V_2 ) ;
F_75 ( & V_386 , V_385 ) ;
F_132 ( & V_390 -> V_426 , & V_429 ) ;
F_77 ( & V_386 , V_385 ) ;
F_119 ( V_390 , V_430 ) ;
F_85 ( V_390 , L_31 ) ;
return 0 ;
V_428:
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
F_21 ( V_29 ) ;
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
F_142 ( & V_390 -> V_426 ) ;
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
F_119 ( V_390 , V_431 ) ;
F_21 ( & V_390 -> V_2 ) ;
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
V_381 = F_13 ( sizeof( * V_381 ) + V_14 , V_19 ) ;
if ( ! V_381 )
return NULL ;
if ( V_14 )
V_381 -> V_25 = & V_381 [ 1 ] ;
F_69 ( & V_381 -> V_432 ) ;
F_122 ( & V_381 -> V_433 ) ;
V_381 -> V_34 = V_34 ;
V_381 -> V_387 = V_387 ;
if ( ! F_31 ( & V_390 -> V_2 ) )
goto V_434;
F_14 ( & V_381 -> V_2 , L_39 , V_390 -> V_384 , V_387 ) ;
V_381 -> V_2 . V_29 = & V_390 -> V_2 ;
V_381 -> V_2 . V_191 = F_135 ;
V_15 = F_15 ( & V_381 -> V_2 ) ;
if ( V_15 ) {
F_103 ( V_18 , V_390 , L_40
L_41 ) ;
goto V_435;
}
F_131 ( & V_381 -> V_2 ) ;
F_75 ( & V_388 , V_385 ) ;
F_132 ( & V_381 -> V_433 , & V_436 ) ;
F_77 ( & V_388 , V_385 ) ;
F_137 ( V_381 , L_42 ) ;
return V_381 ;
V_435:
F_21 ( & V_390 -> V_2 ) ;
V_434:
F_3 ( V_381 ) ;
return NULL ;
}
int F_140 ( struct V_380 * V_381 )
{
unsigned long V_385 ;
F_75 ( & V_388 , V_385 ) ;
F_142 ( & V_381 -> V_433 ) ;
F_77 ( & V_388 , V_385 ) ;
F_144 ( & V_381 -> V_2 ) ;
F_137 ( V_381 , L_43 ) ;
F_17 ( & V_381 -> V_2 ) ;
return 0 ;
}
static struct V_3 *
F_148 ( struct V_8 * V_437 )
{
struct V_3 * V_4 ;
unsigned long V_385 ;
F_75 ( & V_438 , V_385 ) ;
F_76 (priv, &iscsi_transports, list) {
if ( V_437 == V_4 -> V_8 ) {
F_77 ( & V_438 , V_385 ) ;
return V_4 ;
}
}
F_77 ( & V_438 , V_385 ) ;
return NULL ;
}
static int
F_149 ( struct V_439 * V_440 , T_5 V_441 , T_7 V_442 )
{
return F_150 ( V_443 , V_440 , 0 , V_441 , V_442 ) ;
}
int F_151 ( struct V_380 * V_381 , struct V_444 * V_445 ,
char * V_12 , T_5 V_446 )
{
struct V_447 * V_448 ;
struct V_439 * V_440 ;
struct V_449 * V_450 ;
char * V_451 ;
struct V_3 * V_4 ;
int V_452 = F_152 ( sizeof( * V_450 ) + sizeof( struct V_444 ) +
V_446 ) ;
V_4 = F_148 ( V_381 -> V_34 ) ;
if ( ! V_4 )
return - V_453 ;
V_440 = F_153 ( V_452 , V_454 ) ;
if ( ! V_440 ) {
F_154 ( V_381 , V_455 ) ;
F_155 ( V_18 , V_381 , L_44
L_45 ) ;
return - V_372 ;
}
V_448 = F_156 ( V_440 , 0 , 0 , 0 , ( V_452 - sizeof( * V_448 ) ) , 0 ) ;
V_450 = F_157 ( V_448 ) ;
memset ( V_450 , 0 , sizeof( * V_450 ) ) ;
V_450 -> V_456 = F_5 ( V_381 -> V_34 ) ;
V_450 -> type = V_457 ;
V_450 -> V_458 . V_459 . V_387 = V_381 -> V_387 ;
V_450 -> V_458 . V_459 . V_384 = F_72 ( V_381 ) ;
V_451 = ( char * ) V_450 + sizeof( * V_450 ) ;
memcpy ( V_451 , V_445 , sizeof( struct V_444 ) ) ;
memcpy ( V_451 + sizeof( struct V_444 ) , V_12 , V_446 ) ;
return F_149 ( V_440 , V_460 , V_454 ) ;
}
int F_158 ( struct V_188 * V_189 ,
struct V_8 * V_34 , T_5 type ,
char * V_12 , T_8 V_446 )
{
struct V_447 * V_448 ;
struct V_439 * V_440 ;
struct V_449 * V_450 ;
int V_452 = F_152 ( sizeof( * V_450 ) + V_446 ) ;
V_440 = F_153 ( V_452 , V_454 ) ;
if ( ! V_440 ) {
F_12 ( V_18 L_46 ) ;
return - V_372 ;
}
V_448 = F_156 ( V_440 , 0 , 0 , 0 , ( V_452 - sizeof( * V_448 ) ) , 0 ) ;
V_450 = F_157 ( V_448 ) ;
memset ( V_450 , 0 , sizeof( * V_450 ) ) ;
V_450 -> type = type ;
V_450 -> V_456 = F_5 ( V_34 ) ;
switch ( type ) {
case V_461 :
V_450 -> V_458 . V_462 . V_194 = V_189 -> V_194 ;
break;
case V_463 :
V_450 -> V_458 . V_464 . V_194 = V_189 -> V_194 ;
break;
}
memcpy ( ( char * ) V_450 + sizeof( * V_450 ) , V_12 , V_446 ) ;
return F_149 ( V_440 , V_465 , V_454 ) ;
}
void F_154 ( struct V_380 * V_381 , enum V_466 error )
{
struct V_447 * V_448 ;
struct V_439 * V_440 ;
struct V_449 * V_450 ;
struct V_3 * V_4 ;
int V_452 = F_152 ( sizeof( * V_450 ) ) ;
V_4 = F_148 ( V_381 -> V_34 ) ;
if ( ! V_4 )
return;
V_440 = F_153 ( V_452 , V_454 ) ;
if ( ! V_440 ) {
F_155 ( V_18 , V_381 , L_47
L_48 , error ) ;
return;
}
V_448 = F_156 ( V_440 , 0 , 0 , 0 , ( V_452 - sizeof( * V_448 ) ) , 0 ) ;
V_450 = F_157 ( V_448 ) ;
V_450 -> V_456 = F_5 ( V_381 -> V_34 ) ;
V_450 -> type = V_467 ;
V_450 -> V_458 . V_468 . error = error ;
V_450 -> V_458 . V_468 . V_387 = V_381 -> V_387 ;
V_450 -> V_458 . V_468 . V_384 = F_72 ( V_381 ) ;
F_149 ( V_440 , V_460 , V_454 ) ;
F_155 ( V_412 , V_381 , L_49 ,
error ) ;
}
void F_159 ( struct V_380 * V_381 ,
enum V_469 V_181 )
{
struct V_447 * V_448 ;
struct V_439 * V_440 ;
struct V_449 * V_450 ;
struct V_3 * V_4 ;
int V_452 = F_152 ( sizeof( * V_450 ) ) ;
V_4 = F_148 ( V_381 -> V_34 ) ;
if ( ! V_4 )
return;
V_440 = F_153 ( V_452 , V_454 ) ;
if ( ! V_440 ) {
F_155 ( V_18 , V_381 , L_47
L_50 , V_181 ) ;
return;
}
V_448 = F_156 ( V_440 , 0 , 0 , 0 , ( V_452 - sizeof( * V_448 ) ) , 0 ) ;
V_450 = F_157 ( V_448 ) ;
V_450 -> V_456 = F_5 ( V_381 -> V_34 ) ;
V_450 -> type = V_470 ;
V_450 -> V_458 . V_471 . V_181 = V_181 ;
V_450 -> V_458 . V_471 . V_387 = V_381 -> V_387 ;
V_450 -> V_458 . V_471 . V_384 = F_72 ( V_381 ) ;
F_149 ( V_440 , V_460 , V_454 ) ;
F_155 ( V_412 , V_381 , L_51 ,
V_181 ) ;
}
void F_160 ( T_5 V_194 , struct V_8 * V_34 ,
enum V_472 V_473 , T_5 V_446 ,
T_9 * V_12 )
{
struct V_447 * V_448 ;
struct V_439 * V_440 ;
struct V_449 * V_450 ;
int V_452 = F_152 ( sizeof( * V_450 ) + V_446 ) ;
V_440 = F_153 ( V_452 , V_474 ) ;
if ( ! V_440 ) {
F_12 ( V_18 L_52 ,
V_194 , V_473 ) ;
return;
}
V_448 = F_156 ( V_440 , 0 , 0 , 0 , ( V_452 - sizeof( * V_448 ) ) , 0 ) ;
V_450 = F_157 ( V_448 ) ;
V_450 -> V_456 = F_5 ( V_34 ) ;
V_450 -> type = V_475 ;
V_450 -> V_458 . V_476 . V_194 = V_194 ;
V_450 -> V_458 . V_476 . V_473 = V_473 ;
V_450 -> V_458 . V_476 . V_446 = V_446 ;
if ( V_446 )
memcpy ( ( char * ) V_450 + sizeof( * V_450 ) , V_12 , V_446 ) ;
F_149 ( V_440 , V_460 , V_474 ) ;
}
void F_161 ( T_5 V_194 , struct V_8 * V_34 ,
T_5 V_477 , T_5 V_478 , T_5 V_446 ,
T_9 * V_12 )
{
struct V_447 * V_448 ;
struct V_439 * V_440 ;
struct V_449 * V_450 ;
int V_452 = F_152 ( sizeof( * V_450 ) + V_446 ) ;
V_440 = F_153 ( V_452 , V_474 ) ;
if ( ! V_440 ) {
F_12 ( V_18 L_53 ) ;
return;
}
V_448 = F_156 ( V_440 , 0 , 0 , 0 , ( V_452 - sizeof( * V_448 ) ) , 0 ) ;
V_450 = F_157 ( V_448 ) ;
V_450 -> V_456 = F_5 ( V_34 ) ;
V_450 -> type = V_479 ;
V_450 -> V_458 . V_480 . V_194 = V_194 ;
V_450 -> V_458 . V_480 . V_477 = V_477 ;
V_450 -> V_458 . V_480 . V_478 = V_478 ;
V_450 -> V_458 . V_480 . V_446 = V_446 ;
memcpy ( ( char * ) V_450 + sizeof( * V_450 ) , V_12 , V_446 ) ;
F_149 ( V_440 , V_460 , V_474 ) ;
}
static int
F_162 ( T_5 V_441 , int V_481 , int type , int V_482 , int V_483 ,
void * V_484 , int V_485 )
{
struct V_439 * V_440 ;
struct V_447 * V_448 ;
int V_452 = F_152 ( V_485 ) ;
int V_385 = V_483 ? V_486 : 0 ;
int V_33 = V_482 ? V_487 : type ;
V_440 = F_153 ( V_452 , V_454 ) ;
if ( ! V_440 ) {
F_12 ( V_18 L_54 ) ;
return - V_372 ;
}
V_448 = F_156 ( V_440 , 0 , 0 , V_33 , ( V_452 - sizeof( * V_448 ) ) , 0 ) ;
V_448 -> V_488 = V_385 ;
memcpy ( F_157 ( V_448 ) , V_484 , V_485 ) ;
return F_149 ( V_440 , V_441 , V_454 ) ;
}
static int
F_163 ( struct V_8 * V_34 , struct V_447 * V_448 )
{
struct V_449 * V_450 = F_157 ( V_448 ) ;
struct V_489 * V_490 ;
struct V_439 * V_491 ;
struct V_380 * V_381 ;
struct V_447 * V_492 ;
struct V_449 * V_493 ;
struct V_3 * V_4 ;
int V_452 = F_152 ( sizeof( * V_450 ) +
sizeof( struct V_489 ) +
sizeof( struct V_494 ) *
V_495 ) ;
int V_15 = 0 ;
V_4 = F_148 ( V_34 ) ;
if ( ! V_4 )
return - V_453 ;
V_381 = F_78 ( V_450 -> V_496 . V_497 . V_384 , V_450 -> V_496 . V_497 . V_387 ) ;
if ( ! V_381 )
return - V_498 ;
do {
int V_499 ;
V_491 = F_153 ( V_452 , V_454 ) ;
if ( ! V_491 ) {
F_155 ( V_18 , V_381 , L_55
L_56 ) ;
return - V_372 ;
}
V_492 = F_156 ( V_491 , 0 , 0 , 0 ,
( V_452 - sizeof( * V_492 ) ) , 0 ) ;
V_493 = F_157 ( V_492 ) ;
memset ( V_493 , 0 , sizeof( * V_493 ) ) ;
V_493 -> V_456 = F_5 ( V_381 -> V_34 ) ;
V_493 -> type = V_448 -> V_500 ;
V_493 -> V_496 . V_497 . V_387 =
V_450 -> V_496 . V_497 . V_387 ;
V_493 -> V_496 . V_497 . V_384 =
V_450 -> V_496 . V_497 . V_384 ;
V_490 = (struct V_489 * )
( ( char * ) V_493 + sizeof( * V_493 ) ) ;
memset ( V_490 , 0 , sizeof( * V_490 ) ) ;
V_34 -> V_497 ( V_381 , V_490 ) ;
V_499 = F_152 ( sizeof( struct V_449 ) +
sizeof( struct V_489 ) +
sizeof( struct V_494 ) *
V_490 -> V_501 ) ;
V_499 -= sizeof( * V_492 ) ;
V_499 = F_164 ( V_499 ) ;
F_165 ( V_491 , F_166 ( V_499 ) ) ;
V_492 -> V_502 = V_499 ;
V_15 = F_149 ( V_491 , V_460 ,
V_454 ) ;
} while ( V_15 < 0 && V_15 != - V_503 );
return V_15 ;
}
int F_119 ( struct V_382 * V_390 ,
enum V_504 V_505 )
{
struct V_3 * V_4 ;
struct V_188 * V_189 ;
struct V_449 * V_450 ;
struct V_439 * V_440 ;
struct V_447 * V_448 ;
int V_506 , V_452 = F_152 ( sizeof( * V_450 ) ) ;
V_4 = F_148 ( V_390 -> V_34 ) ;
if ( ! V_4 )
return - V_453 ;
V_189 = F_83 ( V_390 ) ;
V_440 = F_153 ( V_452 , V_19 ) ;
if ( ! V_440 ) {
F_103 ( V_18 , V_390 ,
L_57
L_58 , V_505 ) ;
return - V_372 ;
}
V_448 = F_156 ( V_440 , 0 , 0 , 0 , ( V_452 - sizeof( * V_448 ) ) , 0 ) ;
V_450 = F_157 ( V_448 ) ;
V_450 -> V_456 = F_5 ( V_390 -> V_34 ) ;
V_450 -> type = V_505 ;
switch ( V_505 ) {
case V_431 :
V_450 -> V_458 . V_507 . V_194 = V_189 -> V_194 ;
V_450 -> V_458 . V_507 . V_384 = V_390 -> V_384 ;
break;
case V_430 :
V_450 -> V_458 . V_508 . V_194 = V_189 -> V_194 ;
V_450 -> V_458 . V_508 . V_384 = V_390 -> V_384 ;
break;
case V_424 :
V_450 -> V_458 . V_509 . V_194 = V_189 -> V_194 ;
V_450 -> V_458 . V_509 . V_384 = V_390 -> V_384 ;
break;
default:
F_103 ( V_18 , V_390 , L_59
L_60 , V_505 ) ;
F_167 ( V_440 ) ;
return - V_453 ;
}
V_506 = F_149 ( V_440 , V_460 , V_19 ) ;
if ( V_506 == - V_359 )
F_103 ( V_18 , V_390 ,
L_57
L_61 ,
V_505 ) ;
F_85 ( V_390 , L_62 ,
V_505 , V_506 ) ;
return V_506 ;
}
static int
F_168 ( struct V_3 * V_4 , struct V_9 * V_10 ,
struct V_449 * V_450 , T_10 V_478 ,
T_5 V_510 , T_8 V_511 ,
T_8 V_512 )
{
struct V_8 * V_34 = V_4 -> V_8 ;
struct V_382 * V_390 ;
struct V_188 * V_189 ;
V_390 = V_34 -> V_513 ( V_10 , V_511 , V_512 ,
V_510 ) ;
if ( ! V_390 )
return - V_372 ;
V_390 -> V_425 = V_478 ;
V_189 = F_83 ( V_390 ) ;
V_450 -> V_458 . V_508 . V_194 = V_189 -> V_194 ;
V_450 -> V_458 . V_508 . V_384 = V_390 -> V_384 ;
F_85 ( V_390 ,
L_63 ) ;
return 0 ;
}
static int
F_169 ( struct V_8 * V_34 , struct V_449 * V_450 )
{
struct V_380 * V_381 ;
struct V_382 * V_390 ;
V_390 = F_74 ( V_450 -> V_496 . V_514 . V_384 ) ;
if ( ! V_390 ) {
F_12 ( V_18 L_64 ,
V_450 -> V_496 . V_514 . V_384 ) ;
return - V_453 ;
}
V_381 = V_34 -> V_515 ( V_390 , V_450 -> V_496 . V_514 . V_387 ) ;
if ( ! V_381 ) {
F_103 ( V_18 , V_390 ,
L_65 ) ;
return - V_372 ;
}
V_450 -> V_458 . V_516 . V_384 = V_390 -> V_384 ;
V_450 -> V_458 . V_516 . V_387 = V_381 -> V_387 ;
F_137 ( V_381 , L_66 ) ;
return 0 ;
}
static int
F_170 ( struct V_8 * V_34 , struct V_449 * V_450 )
{
struct V_380 * V_381 ;
V_381 = F_78 ( V_450 -> V_496 . V_517 . V_384 , V_450 -> V_496 . V_517 . V_387 ) ;
if ( ! V_381 )
return - V_453 ;
F_137 ( V_381 , L_67 ) ;
if ( V_34 -> V_518 )
V_34 -> V_518 ( V_381 ) ;
return 0 ;
}
static int
F_171 ( struct V_8 * V_34 , struct V_449 * V_450 )
{
char * V_12 = ( char * ) V_450 + sizeof( * V_450 ) ;
struct V_380 * V_381 ;
struct V_382 * V_390 ;
int V_15 = 0 , V_183 = 0 ;
V_390 = F_74 ( V_450 -> V_496 . V_519 . V_384 ) ;
V_381 = F_78 ( V_450 -> V_496 . V_519 . V_384 , V_450 -> V_496 . V_519 . V_387 ) ;
if ( ! V_381 || ! V_390 )
return - V_453 ;
switch ( V_450 -> V_496 . V_519 . V_35 ) {
case V_520 :
sscanf ( V_12 , L_68 , & V_183 ) ;
V_390 -> V_413 = V_183 ;
break;
default:
V_15 = V_34 -> V_519 ( V_381 , V_450 -> V_496 . V_519 . V_35 ,
V_12 , V_450 -> V_496 . V_519 . V_452 ) ;
}
return V_15 ;
}
static int F_172 ( struct V_8 * V_34 ,
struct V_449 * V_450 , int V_521 )
{
struct V_9 * V_10 ;
struct V_522 * V_523 ;
struct V_188 * V_189 = NULL ;
int V_524 , V_15 = 0 ;
if ( ! V_34 -> V_525 )
return - V_453 ;
if ( V_521 == V_526 ) {
V_189 = F_173 ( V_450 -> V_496 . V_527 . V_194 ) ;
if ( ! V_189 ) {
F_12 ( V_18 L_69
L_70 ,
V_450 -> V_496 . V_527 . V_194 ) ;
return - V_528 ;
}
V_524 = V_450 -> V_496 . V_527 . V_524 ;
} else
V_524 = V_450 -> V_496 . V_525 . V_524 ;
V_523 = (struct V_522 * ) ( ( char * ) V_450 + sizeof( * V_450 ) ) ;
V_10 = V_34 -> V_525 ( V_189 , V_523 , V_524 ) ;
if ( F_174 ( V_10 ) ) {
V_15 = F_175 ( V_10 ) ;
goto V_529;
}
V_450 -> V_458 . V_530 . V_26 = V_10 -> V_11 ;
V_529:
if ( V_189 )
F_84 ( V_189 ) ;
return V_15 ;
}
static int F_176 ( struct V_8 * V_34 ,
T_3 V_531 )
{
struct V_380 * V_381 ;
struct V_9 * V_10 ;
if ( ! V_34 -> V_532 )
return - V_453 ;
V_10 = F_20 ( V_531 ) ;
if ( ! V_10 )
return - V_453 ;
V_381 = V_10 -> V_381 ;
if ( V_381 ) {
F_92 ( & V_381 -> V_432 ) ;
V_381 -> V_10 = NULL ;
F_94 ( & V_381 -> V_432 ) ;
}
V_34 -> V_532 ( V_10 ) ;
return 0 ;
}
static int
F_177 ( struct V_8 * V_34 ,
struct V_449 * V_450 , int V_521 )
{
struct V_9 * V_10 ;
int V_506 = 0 ;
switch ( V_521 ) {
case V_526 :
case V_533 :
V_506 = F_172 ( V_34 , V_450 , V_521 ) ;
break;
case V_534 :
if ( ! V_34 -> V_535 )
return - V_453 ;
V_10 = F_20 ( V_450 -> V_496 . V_535 . V_531 ) ;
if ( ! V_10 )
return - V_453 ;
V_450 -> V_458 . V_536 = V_34 -> V_535 ( V_10 ,
V_450 -> V_496 . V_535 . V_537 ) ;
break;
case V_538 :
V_506 = F_176 ( V_34 ,
V_450 -> V_496 . V_532 . V_531 ) ;
break;
}
return V_506 ;
}
static int
F_178 ( struct V_8 * V_34 ,
struct V_449 * V_450 )
{
struct V_188 * V_189 ;
struct V_522 * V_523 ;
int V_15 ;
if ( ! V_34 -> V_539 )
return - V_453 ;
V_189 = F_173 ( V_450 -> V_496 . V_539 . V_194 ) ;
if ( ! V_189 ) {
F_12 ( V_18 L_71 ,
V_450 -> V_496 . V_539 . V_194 ) ;
return - V_528 ;
}
V_523 = (struct V_522 * ) ( ( char * ) V_450 + sizeof( * V_450 ) ) ;
V_15 = V_34 -> V_539 ( V_189 , V_450 -> V_496 . V_539 . type ,
V_450 -> V_496 . V_539 . V_540 , V_523 ) ;
F_84 ( V_189 ) ;
return V_15 ;
}
static int
F_179 ( struct V_8 * V_34 ,
struct V_449 * V_450 )
{
char * V_12 = ( char * ) V_450 + sizeof( * V_450 ) ;
struct V_188 * V_189 ;
int V_15 ;
if ( ! V_34 -> V_541 )
return - V_542 ;
V_189 = F_173 ( V_450 -> V_496 . V_541 . V_194 ) ;
if ( ! V_189 ) {
F_12 ( V_18 L_72 ,
V_450 -> V_496 . V_541 . V_194 ) ;
return - V_528 ;
}
V_15 = V_34 -> V_541 ( V_189 , V_450 -> V_496 . V_541 . V_35 ,
V_12 , V_450 -> V_496 . V_541 . V_452 ) ;
F_84 ( V_189 ) ;
return V_15 ;
}
static int
F_180 ( struct V_8 * V_34 , struct V_449 * V_450 )
{
struct V_188 * V_189 ;
struct V_543 * V_544 ;
int V_15 ;
if ( ! V_34 -> V_545 )
return - V_542 ;
V_189 = F_173 ( V_450 -> V_496 . V_545 . V_194 ) ;
if ( ! V_189 ) {
F_12 ( V_18 L_73 ,
V_450 -> V_496 . V_545 . V_194 ) ;
return - V_528 ;
}
V_544 = (struct V_543 * ) ( ( char * ) V_450 + sizeof( * V_450 ) ) ;
V_15 = V_34 -> V_545 ( V_189 , V_544 ) ;
F_84 ( V_189 ) ;
return V_15 ;
}
static int
F_181 ( struct V_8 * V_34 ,
struct V_449 * V_450 , T_5 V_452 )
{
char * V_12 = ( char * ) V_450 + sizeof( * V_450 ) ;
struct V_188 * V_189 ;
int V_15 ;
if ( ! V_34 -> V_546 )
return - V_542 ;
V_189 = F_173 ( V_450 -> V_496 . V_547 . V_194 ) ;
if ( ! V_189 ) {
F_12 ( V_18 L_74 ,
V_450 -> V_496 . V_547 . V_194 ) ;
return - V_528 ;
}
V_15 = V_34 -> V_546 ( V_189 , V_12 , V_452 ) ;
F_84 ( V_189 ) ;
return V_15 ;
}
static int
F_182 ( struct V_8 * V_34 , struct V_449 * V_450 )
{
struct V_188 * V_189 ;
struct V_522 * V_523 ;
int V_15 ;
if ( ! V_34 -> V_548 )
return - V_542 ;
V_189 = F_173 ( V_450 -> V_496 . V_549 . V_194 ) ;
if ( ! V_189 ) {
F_12 ( V_18 L_75 ,
V_450 -> V_496 . V_549 . V_194 ) ;
return - V_528 ;
}
V_523 = (struct V_522 * ) ( ( char * ) V_450 + sizeof( * V_450 ) ) ;
V_15 = V_34 -> V_548 ( V_189 , V_450 -> V_496 . V_549 . V_190 ,
V_450 -> V_496 . V_549 . V_103 ,
V_450 -> V_496 . V_549 . V_550 ,
V_450 -> V_496 . V_549 . V_478 ,
V_523 ) ;
F_84 ( V_189 ) ;
return V_15 ;
}
static int
F_183 ( struct V_8 * V_34 , struct V_447 * V_448 )
{
struct V_449 * V_450 = F_157 ( V_448 ) ;
struct V_188 * V_189 = NULL ;
struct V_551 * V_552 ;
struct V_3 * V_4 ;
struct V_439 * V_553 ;
struct V_447 * V_554 ;
struct V_449 * V_555 ;
T_5 V_556 ;
int V_452 , V_15 = 0 ;
char * V_7 ;
if ( ! V_34 -> V_557 )
return - V_453 ;
V_4 = F_148 ( V_34 ) ;
if ( ! V_4 )
return - V_453 ;
V_556 = ( V_450 -> V_496 . V_557 . V_558 * sizeof( * V_552 ) ) ;
V_452 = F_152 ( sizeof( * V_450 ) + V_556 ) ;
V_189 = F_173 ( V_450 -> V_496 . V_557 . V_194 ) ;
if ( ! V_189 ) {
F_12 ( V_18 L_76 ,
V_559 , V_450 -> V_496 . V_557 . V_194 ) ;
return - V_528 ;
}
do {
int V_499 ;
V_553 = F_153 ( V_452 , V_19 ) ;
if ( ! V_553 ) {
F_12 ( V_18 L_77 ) ;
V_15 = - V_372 ;
goto V_560;
}
V_554 = F_156 ( V_553 , 0 , 0 , 0 ,
( V_452 - sizeof( * V_554 ) ) , 0 ) ;
V_555 = F_157 ( V_554 ) ;
memset ( V_555 , 0 , sizeof( * V_555 ) ) ;
V_555 -> V_456 = F_5 ( V_34 ) ;
V_555 -> type = V_448 -> V_500 ;
V_555 -> V_496 . V_557 . V_194 = V_450 -> V_496 . V_557 . V_194 ;
V_555 -> V_496 . V_557 . V_561 = V_450 -> V_496 . V_557 . V_561 ;
V_555 -> V_496 . V_557 . V_558 = V_450 -> V_496 . V_557 . V_558 ;
V_7 = ( char * ) V_555 + sizeof( * V_555 ) ;
memset ( V_7 , 0 , V_556 ) ;
V_15 = V_34 -> V_557 ( V_189 , V_450 -> V_496 . V_557 . V_561 ,
& V_555 -> V_496 . V_557 . V_558 , V_7 ) ;
V_499 = F_152 ( sizeof( * V_450 ) + V_556 ) ;
F_165 ( V_553 , F_166 ( V_499 ) ) ;
V_554 -> V_502 = V_499 ;
V_15 = F_149 ( V_553 , V_460 ,
V_19 ) ;
} while ( V_15 < 0 && V_15 != - V_503 );
V_560:
F_84 ( V_189 ) ;
return V_15 ;
}
static int F_184 ( struct V_8 * V_34 ,
struct V_449 * V_450 , T_5 V_452 )
{
char * V_12 = ( char * ) V_450 + sizeof( * V_450 ) ;
struct V_188 * V_189 ;
int V_15 = 0 ;
if ( ! V_34 -> V_562 )
return - V_542 ;
V_189 = F_173 ( V_450 -> V_496 . V_545 . V_194 ) ;
if ( ! V_189 ) {
F_53 ( L_78 ,
V_559 , V_450 -> V_496 . V_545 . V_194 ) ;
return - V_528 ;
}
V_15 = V_34 -> V_562 ( V_189 , V_12 , V_452 ) ;
F_84 ( V_189 ) ;
return V_15 ;
}
static int F_185 ( struct V_8 * V_34 ,
struct V_449 * V_450 )
{
struct V_188 * V_189 ;
int V_15 = 0 ;
if ( ! V_34 -> V_563 )
return - V_542 ;
V_189 = F_173 ( V_450 -> V_496 . V_563 . V_194 ) ;
if ( ! V_189 ) {
F_12 ( V_18 L_78 ,
V_559 , V_450 -> V_496 . V_563 . V_194 ) ;
return - V_528 ;
}
V_15 = V_34 -> V_563 ( V_189 , V_450 -> V_496 . V_563 . V_561 ) ;
F_84 ( V_189 ) ;
return V_15 ;
}
char * F_186 ( int V_564 )
{
int V_32 ;
char * V_181 = L_79 ;
for ( V_32 = 0 ; V_32 < F_28 ( V_565 ) ; V_32 ++ ) {
if ( V_565 [ V_32 ] . V_183 & V_564 ) {
V_181 = V_565 [ V_32 ] . V_184 ;
break;
}
}
return V_181 ;
}
static int F_187 ( struct V_8 * V_34 ,
struct V_449 * V_450 , T_5 V_452 )
{
char * V_12 = ( char * ) V_450 + sizeof( * V_450 ) ;
struct V_188 * V_189 ;
struct V_198 * V_199 ;
struct V_270 * V_271 ;
struct V_1 * V_2 ;
T_5 V_339 ;
int V_15 = 0 ;
if ( ! V_34 -> V_566 ) {
V_15 = - V_542 ;
goto V_567;
}
V_189 = F_173 ( V_450 -> V_496 . V_568 . V_194 ) ;
if ( ! V_189 ) {
F_53 ( L_78 ,
V_559 , V_450 -> V_496 . V_568 . V_194 ) ;
V_15 = - V_528 ;
goto V_569;
}
V_339 = V_450 -> V_496 . V_568 . V_570 ;
V_199 = F_45 ( V_189 , V_339 ) ;
if ( ! V_199 ) {
F_53 ( L_80 ,
V_559 , V_339 , V_450 -> V_496 . V_568 . V_194 ) ;
V_15 = - V_528 ;
goto V_569;
}
V_2 = F_49 ( V_199 ) ;
if ( ! V_2 ) {
V_15 = - V_528 ;
goto V_571;
}
V_271 = F_37 ( V_2 ) ;
V_15 = V_34 -> V_566 ( V_199 , V_271 , V_12 , V_452 ) ;
F_21 ( V_2 ) ;
V_571:
F_21 ( & V_199 -> V_2 ) ;
V_569:
F_84 ( V_189 ) ;
V_567:
return V_15 ;
}
static int F_188 ( struct V_8 * V_34 ,
struct V_449 * V_450 , T_5 V_452 )
{
char * V_12 = ( char * ) V_450 + sizeof( * V_450 ) ;
struct V_188 * V_189 ;
int V_331 ;
int V_15 = 0 ;
if ( ! V_34 -> V_572 ) {
V_15 = - V_542 ;
goto V_573;
}
V_189 = F_173 ( V_450 -> V_496 . V_572 . V_194 ) ;
if ( ! V_189 ) {
F_53 ( L_78 ,
V_559 , V_450 -> V_496 . V_572 . V_194 ) ;
V_15 = - V_528 ;
goto V_569;
}
V_331 = V_34 -> V_572 ( V_189 , V_12 , V_452 ) ;
if ( V_331 >= 0 )
V_450 -> V_458 . V_574 . V_570 = V_331 ;
else
V_15 = - V_575 ;
V_569:
F_84 ( V_189 ) ;
V_573:
return V_15 ;
}
static int F_189 ( struct V_8 * V_34 ,
struct V_449 * V_450 )
{
struct V_188 * V_189 ;
struct V_198 * V_199 ;
T_5 V_339 ;
int V_15 = 0 ;
if ( ! V_34 -> V_576 ) {
V_15 = - V_542 ;
goto V_577;
}
V_189 = F_173 ( V_450 -> V_496 . V_576 . V_194 ) ;
if ( ! V_189 ) {
F_53 ( L_78 ,
V_559 , V_450 -> V_496 . V_576 . V_194 ) ;
V_15 = - V_528 ;
goto V_569;
}
V_339 = V_450 -> V_496 . V_576 . V_570 ;
V_199 = F_45 ( V_189 , V_339 ) ;
if ( ! V_199 ) {
F_53 ( L_80 ,
V_559 , V_339 , V_450 -> V_496 . V_576 . V_194 ) ;
V_15 = - V_528 ;
goto V_569;
}
V_15 = V_34 -> V_576 ( V_199 ) ;
F_21 ( & V_199 -> V_2 ) ;
V_569:
F_84 ( V_189 ) ;
V_577:
return V_15 ;
}
static int F_190 ( struct V_8 * V_34 ,
struct V_449 * V_450 )
{
struct V_188 * V_189 ;
struct V_198 * V_199 ;
struct V_270 * V_271 ;
struct V_1 * V_2 ;
T_5 V_339 ;
int V_15 = 0 ;
if ( ! V_34 -> V_578 ) {
V_15 = - V_542 ;
goto V_579;
}
V_189 = F_173 ( V_450 -> V_496 . V_578 . V_194 ) ;
if ( ! V_189 ) {
F_53 ( L_78 ,
V_559 , V_450 -> V_496 . V_578 . V_194 ) ;
V_15 = - V_528 ;
goto V_569;
}
V_339 = V_450 -> V_496 . V_578 . V_570 ;
V_199 = F_45 ( V_189 , V_339 ) ;
if ( ! V_199 ) {
F_53 ( L_80 ,
V_559 , V_339 , V_450 -> V_496 . V_578 . V_194 ) ;
V_15 = - V_528 ;
goto V_569;
}
V_2 = F_49 ( V_199 ) ;
if ( ! V_2 ) {
V_15 = - V_528 ;
goto V_571;
}
V_271 = F_37 ( V_2 ) ;
V_15 = V_34 -> V_578 ( V_199 , V_271 ) ;
F_21 ( V_2 ) ;
V_571:
F_21 ( & V_199 -> V_2 ) ;
V_569:
F_84 ( V_189 ) ;
V_579:
return V_15 ;
}
static int F_191 ( struct V_8 * V_34 ,
struct V_449 * V_450 )
{
struct V_188 * V_189 ;
struct V_198 * V_199 ;
struct V_270 * V_271 ;
struct V_1 * V_2 ;
T_5 V_339 ;
int V_15 = 0 ;
if ( ! V_34 -> V_580 ) {
V_15 = - V_542 ;
goto V_581;
}
V_189 = F_173 ( V_450 -> V_496 . V_580 . V_194 ) ;
if ( ! V_189 ) {
F_53 ( L_78 ,
V_559 , V_450 -> V_496 . V_580 . V_194 ) ;
V_15 = - V_528 ;
goto V_569;
}
V_339 = V_450 -> V_496 . V_580 . V_570 ;
V_199 = F_45 ( V_189 , V_339 ) ;
if ( ! V_199 ) {
F_53 ( L_80 ,
V_559 , V_339 , V_450 -> V_496 . V_580 . V_194 ) ;
V_15 = - V_528 ;
goto V_569;
}
V_2 = F_49 ( V_199 ) ;
if ( ! V_2 ) {
V_15 = - V_528 ;
goto V_571;
}
V_271 = F_37 ( V_2 ) ;
V_15 = V_34 -> V_580 ( V_199 , V_271 ) ;
F_21 ( V_2 ) ;
V_571:
F_21 ( & V_199 -> V_2 ) ;
V_569:
F_84 ( V_189 ) ;
V_581:
return V_15 ;
}
static int F_192 ( struct V_8 * V_34 ,
struct V_449 * V_450 )
{
struct V_188 * V_189 ;
struct V_382 * V_390 ;
int V_15 = 0 ;
if ( ! V_34 -> V_582 ) {
V_15 = - V_542 ;
goto V_583;
}
V_189 = F_173 ( V_450 -> V_496 . V_582 . V_194 ) ;
if ( ! V_189 ) {
F_53 ( L_78 ,
V_559 , V_450 -> V_496 . V_580 . V_194 ) ;
V_15 = - V_528 ;
goto V_569;
}
V_390 = F_74 ( V_450 -> V_496 . V_582 . V_384 ) ;
if ( ! V_390 ) {
F_53 ( L_81 ,
V_559 , V_450 -> V_496 . V_582 . V_384 ) ;
V_15 = - V_453 ;
goto V_569;
}
V_15 = V_34 -> V_582 ( V_390 ) ;
V_569:
F_84 ( V_189 ) ;
V_583:
return V_15 ;
}
static int
F_193 ( struct V_8 * V_34 , struct V_447 * V_448 )
{
struct V_449 * V_450 = F_157 ( V_448 ) ;
struct V_188 * V_189 = NULL ;
struct V_3 * V_4 ;
struct V_439 * V_584 ;
struct V_447 * V_585 ;
struct V_449 * V_586 ;
int V_587 = 0 ;
int V_452 , V_15 = 0 ;
char * V_7 ;
if ( ! V_34 -> V_588 )
return - V_542 ;
V_4 = F_148 ( V_34 ) ;
if ( ! V_4 )
return - V_453 ;
V_587 = sizeof( struct V_589 ) ;
V_452 = F_152 ( sizeof( * V_450 ) + V_587 ) ;
V_189 = F_173 ( V_450 -> V_496 . V_588 . V_194 ) ;
if ( ! V_189 ) {
F_53 ( L_76 ,
V_559 , V_450 -> V_496 . V_588 . V_194 ) ;
return - V_528 ;
}
do {
int V_499 ;
V_584 = F_153 ( V_452 , V_19 ) ;
if ( ! V_584 ) {
F_53 ( L_82 ) ;
V_15 = - V_372 ;
goto V_590;
}
V_585 = F_156 ( V_584 , 0 , 0 , 0 ,
( V_452 - sizeof( * V_585 ) ) , 0 ) ;
V_586 = F_157 ( V_585 ) ;
memset ( V_586 , 0 , sizeof( * V_586 ) ) ;
V_586 -> V_456 = F_5 ( V_34 ) ;
V_586 -> type = V_448 -> V_500 ;
V_586 -> V_496 . V_588 . V_194 =
V_450 -> V_496 . V_588 . V_194 ;
V_7 = ( char * ) V_586 + sizeof( * V_586 ) ;
memset ( V_7 , 0 , V_587 ) ;
V_15 = V_34 -> V_588 ( V_189 , V_7 , V_587 ) ;
if ( V_15 ) {
F_167 ( V_584 ) ;
goto V_590;
}
V_499 = F_152 ( sizeof( * V_450 ) + V_587 ) ;
F_165 ( V_584 , F_166 ( V_499 ) ) ;
V_585 -> V_502 = V_499 ;
V_15 = F_149 ( V_584 , V_460 ,
V_19 ) ;
} while ( V_15 < 0 && V_15 != - V_503 );
V_590:
F_84 ( V_189 ) ;
return V_15 ;
}
static int
F_194 ( struct V_439 * V_440 , struct V_447 * V_448 , T_5 * V_441 )
{
int V_15 = 0 ;
struct V_449 * V_450 = F_157 ( V_448 ) ;
struct V_8 * V_34 = NULL ;
struct V_3 * V_4 ;
struct V_382 * V_390 ;
struct V_380 * V_381 ;
struct V_9 * V_10 = NULL ;
if ( V_448 -> V_500 == V_591 )
* V_441 = V_465 ;
else
* V_441 = V_460 ;
V_4 = F_148 ( F_195 ( V_450 -> V_456 ) ) ;
if ( ! V_4 )
return - V_453 ;
V_34 = V_4 -> V_8 ;
if ( ! F_196 ( V_34 -> V_592 ) )
return - V_453 ;
switch ( V_448 -> V_500 ) {
case V_593 :
V_15 = F_168 ( V_4 , V_10 , V_450 ,
F_197 ( V_440 ) . V_594 ,
V_450 -> V_496 . V_595 . V_510 ,
V_450 -> V_496 . V_595 . V_511 ,
V_450 -> V_496 . V_595 . V_512 ) ;
break;
case V_596 :
V_10 = F_20 ( V_450 -> V_496 . V_597 . V_531 ) ;
if ( ! V_10 ) {
V_15 = - V_453 ;
break;
}
V_15 = F_168 ( V_4 , V_10 , V_450 ,
F_197 ( V_440 ) . V_594 ,
V_450 -> V_496 . V_597 . V_510 ,
V_450 -> V_496 . V_597 . V_511 ,
V_450 -> V_496 . V_597 . V_512 ) ;
break;
case V_598 :
V_390 = F_74 ( V_450 -> V_496 . V_507 . V_384 ) ;
if ( V_390 )
V_34 -> V_599 ( V_390 ) ;
else
V_15 = - V_453 ;
break;
case V_600 :
V_390 = F_74 ( V_450 -> V_496 . V_507 . V_384 ) ;
if ( V_390 )
F_107 ( F_83 ( V_390 ) ,
& V_390 -> V_421 ) ;
else
V_15 = - V_453 ;
break;
case V_601 :
V_15 = F_169 ( V_34 , V_450 ) ;
break;
case V_602 :
V_15 = F_170 ( V_34 , V_450 ) ;
break;
case V_603 :
V_390 = F_74 ( V_450 -> V_496 . V_604 . V_384 ) ;
V_381 = F_78 ( V_450 -> V_496 . V_604 . V_384 , V_450 -> V_496 . V_604 . V_387 ) ;
if ( V_381 && V_381 -> V_10 )
F_176 ( V_34 , V_381 -> V_10 -> V_11 ) ;
if ( ! V_390 || ! V_381 ) {
V_15 = - V_453 ;
break;
}
V_450 -> V_458 . V_536 = V_34 -> V_605 ( V_390 , V_381 ,
V_450 -> V_496 . V_604 . V_606 ,
V_450 -> V_496 . V_604 . V_607 ) ;
if ( V_450 -> V_458 . V_536 || ! V_34 -> V_525 )
break;
V_10 = F_20 ( V_450 -> V_496 . V_604 . V_606 ) ;
if ( V_10 ) {
V_10 -> V_381 = V_381 ;
F_92 ( & V_381 -> V_432 ) ;
V_381 -> V_10 = V_10 ;
F_94 ( & V_381 -> V_432 ) ;
} else
F_155 ( V_18 , V_381 ,
L_83
L_84 ) ;
break;
case V_608 :
V_15 = F_171 ( V_34 , V_450 ) ;
break;
case V_609 :
V_381 = F_78 ( V_450 -> V_496 . V_610 . V_384 , V_450 -> V_496 . V_610 . V_387 ) ;
if ( V_381 )
V_450 -> V_458 . V_536 = V_34 -> V_610 ( V_381 ) ;
else
V_15 = - V_453 ;
break;
case V_611 :
V_381 = F_78 ( V_450 -> V_496 . V_612 . V_384 , V_450 -> V_496 . V_612 . V_387 ) ;
if ( V_381 )
V_34 -> V_612 ( V_381 , V_450 -> V_496 . V_612 . V_613 ) ;
else
V_15 = - V_453 ;
break;
case V_614 :
V_381 = F_78 ( V_450 -> V_496 . V_615 . V_384 , V_450 -> V_496 . V_615 . V_387 ) ;
if ( V_381 )
V_450 -> V_458 . V_536 = V_34 -> V_615 ( V_381 ,
(struct V_444 * ) ( ( char * ) V_450 + sizeof( * V_450 ) ) ,
( char * ) V_450 + sizeof( * V_450 ) + V_450 -> V_496 . V_615 . V_616 ,
V_450 -> V_496 . V_615 . V_446 ) ;
else
V_15 = - V_453 ;
break;
case V_617 :
V_15 = F_163 ( V_34 , V_448 ) ;
break;
case V_533 :
case V_534 :
case V_538 :
case V_526 :
V_15 = F_177 ( V_34 , V_450 , V_448 -> V_500 ) ;
break;
case V_618 :
V_15 = F_178 ( V_34 , V_450 ) ;
break;
case V_619 :
V_15 = F_179 ( V_34 , V_450 ) ;
break;
case V_591 :
V_15 = F_180 ( V_34 , V_450 ) ;
break;
case V_620 :
V_15 = F_181 ( V_34 , V_450 ,
F_198 ( V_448 , sizeof( * V_450 ) ) ) ;
break;
case V_621 :
V_15 = F_182 ( V_34 , V_450 ) ;
break;
case V_622 :
V_15 = F_183 ( V_34 , V_448 ) ;
break;
case V_623 :
V_15 = F_185 ( V_34 , V_450 ) ;
break;
case V_624 :
V_15 = F_187 ( V_34 , V_450 ,
F_198 ( V_448 ,
sizeof( * V_450 ) ) ) ;
break;
case V_625 :
V_15 = F_188 ( V_34 , V_450 ,
F_198 ( V_448 , sizeof( * V_450 ) ) ) ;
break;
case V_626 :
V_15 = F_189 ( V_34 , V_450 ) ;
break;
case V_627 :
V_15 = F_190 ( V_34 , V_450 ) ;
break;
case V_628 :
V_15 = F_191 ( V_34 , V_450 ) ;
break;
case V_629 :
V_15 = F_192 ( V_34 , V_450 ) ;
break;
case V_630 :
V_15 = F_184 ( V_34 , V_450 ,
F_198 ( V_448 , sizeof( * V_450 ) ) ) ;
break;
case V_631 :
V_15 = F_193 ( V_34 , V_448 ) ;
break;
default:
V_15 = - V_542 ;
break;
}
F_199 ( V_34 -> V_592 ) ;
return V_15 ;
}
static void
F_200 ( struct V_439 * V_440 )
{
F_92 ( & V_632 ) ;
while ( V_440 -> V_452 >= V_633 ) {
int V_15 ;
T_5 V_634 ;
struct V_447 * V_448 ;
struct V_449 * V_450 ;
T_5 V_441 ;
V_448 = F_201 ( V_440 ) ;
if ( V_448 -> V_502 < sizeof( * V_448 ) ||
V_440 -> V_452 < V_448 -> V_502 ) {
break;
}
V_450 = F_157 ( V_448 ) ;
V_634 = F_166 ( V_448 -> V_502 ) ;
if ( V_634 > V_440 -> V_452 )
V_634 = V_440 -> V_452 ;
V_15 = F_194 ( V_440 , V_448 , & V_441 ) ;
if ( V_15 ) {
V_450 -> type = V_635 ;
V_450 -> V_636 = V_15 ;
}
do {
if ( V_450 -> type == V_617 && ! V_15 )
break;
if ( V_450 -> type == V_622 && ! V_15 )
break;
V_15 = F_162 ( V_441 , V_448 -> V_637 ,
V_448 -> V_500 , 0 , 0 , V_450 , sizeof( * V_450 ) ) ;
} while ( V_15 < 0 && V_15 != - V_503 && V_15 != - V_359 );
F_202 ( V_440 , V_634 ) ;
}
F_94 ( & V_632 ) ;
}
static T_4 F_203 ( struct V_30 * V_22 ,
struct V_31 * V_6 , int V_32 )
{
struct V_1 * V_376 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_380 * V_381 = F_204 ( V_376 ) ;
struct V_8 * V_33 = V_381 -> V_34 ;
int V_35 ;
if ( V_6 == & V_638 . V_6 )
V_35 = V_639 ;
else if ( V_6 == & V_640 . V_6 )
V_35 = V_641 ;
else if ( V_6 == & V_642 . V_6 )
V_35 = V_643 ;
else if ( V_6 == & V_644 . V_6 )
V_35 = V_645 ;
else if ( V_6 == & V_646 . V_6 )
V_35 = V_647 ;
else if ( V_6 == & V_648 . V_6 )
V_35 = V_649 ;
else if ( V_6 == & V_650 . V_6 )
V_35 = V_651 ;
else if ( V_6 == & V_652 . V_6 )
V_35 = V_653 ;
else if ( V_6 == & V_654 . V_6 )
V_35 = V_655 ;
else if ( V_6 == & V_656 . V_6 )
V_35 = V_657 ;
else if ( V_6 == & V_658 . V_6 )
V_35 = V_659 ;
else if ( V_6 == & V_660 . V_6 )
V_35 = V_661 ;
else if ( V_6 == & V_662 . V_6 )
V_35 = V_663 ;
else if ( V_6 == & V_664 . V_6 )
V_35 = V_665 ;
else if ( V_6 == & V_666 . V_6 )
V_35 = V_667 ;
else if ( V_6 == & V_668 . V_6 )
V_35 = V_669 ;
else if ( V_6 == & V_670 . V_6 )
V_35 = V_671 ;
else if ( V_6 == & V_672 . V_6 )
V_35 = V_673 ;
else if ( V_6 == & V_674 . V_6 )
V_35 = V_675 ;
else if ( V_6 == & V_676 . V_6 )
V_35 = V_677 ;
else if ( V_6 == & V_678 . V_6 )
V_35 = V_679 ;
else if ( V_6 == & V_680 . V_6 )
V_35 = V_681 ;
else if ( V_6 == & V_682 . V_6 )
V_35 = V_683 ;
else if ( V_6 == & V_684 . V_6 )
V_35 = V_685 ;
else if ( V_6 == & V_686 . V_6 )
V_35 = V_687 ;
else if ( V_6 == & V_688 . V_6 )
V_35 = V_689 ;
else if ( V_6 == & V_690 . V_6 )
V_35 = V_691 ;
else if ( V_6 == & V_692 . V_6 )
V_35 = V_693 ;
else if ( V_6 == & V_694 . V_6 )
V_35 = V_695 ;
else if ( V_6 == & V_696 . V_6 )
V_35 = V_697 ;
else {
F_26 ( 1 , L_85 ) ;
return 0 ;
}
return V_33 -> V_178 ( V_698 , V_35 ) ;
}
static T_1
F_205 ( struct V_1 * V_2 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_382 * V_390 = F_73 ( V_2 -> V_29 ) ;
return sprintf ( V_7 , L_86 , F_79 ( V_390 -> V_181 ) ) ;
}
static T_1
F_206 ( struct V_1 * V_2 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_382 * V_390 = F_73 ( V_2 -> V_29 ) ;
return sprintf ( V_7 , L_87 , V_390 -> V_425 ) ;
}
static T_1
F_207 ( struct V_1 * V_2 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_382 * V_390 = F_73 ( V_2 -> V_29 ) ;
return sprintf ( V_7 , L_87 , V_390 -> V_332 ) ;
}
static T_4 F_208 ( struct V_30 * V_22 ,
struct V_31 * V_6 , int V_32 )
{
struct V_1 * V_376 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_382 * V_390 = F_209 ( V_376 ) ;
struct V_8 * V_33 = V_390 -> V_34 ;
int V_35 ;
if ( V_6 == & V_699 . V_6 )
V_35 = V_700 ;
else if ( V_6 == & V_701 . V_6 )
V_35 = V_702 ;
else if ( V_6 == & V_703 . V_6 )
V_35 = V_704 ;
else if ( V_6 == & V_705 . V_6 )
V_35 = V_706 ;
else if ( V_6 == & V_707 . V_6 )
V_35 = V_708 ;
else if ( V_6 == & V_709 . V_6 )
V_35 = V_710 ;
else if ( V_6 == & V_711 . V_6 )
V_35 = V_712 ;
else if ( V_6 == & V_713 . V_6 )
V_35 = V_714 ;
else if ( V_6 == & V_715 . V_6 )
V_35 = V_716 ;
else if ( V_6 == & V_717 . V_6 )
V_35 = V_718 ;
else if ( V_6 == & V_719 . V_6 )
V_35 = V_720 ;
else if ( V_6 == & V_721 . V_6 )
V_35 = V_722 ;
else if ( V_6 == & V_723 . V_6 )
V_35 = V_724 ;
else if ( V_6 == & V_725 . V_6 )
V_35 = V_726 ;
else if ( V_6 == & V_727 . V_6 )
V_35 = V_728 ;
else if ( V_6 == & V_729 . V_6 )
V_35 = V_730 ;
else if ( V_6 == & V_731 . V_6 )
V_35 = V_732 ;
else if ( V_6 == & V_733 . V_6 )
V_35 = V_734 ;
else if ( V_6 == & V_735 . V_6 )
V_35 = V_736 ;
else if ( V_6 == & V_737 . V_6 )
V_35 = V_738 ;
else if ( V_6 == & V_739 . V_6 )
V_35 = V_740 ;
else if ( V_6 == & V_741 . V_6 )
V_35 = V_742 ;
else if ( V_6 == & V_743 . V_6 )
V_35 = V_744 ;
else if ( V_6 == & V_745 . V_6 )
V_35 = V_746 ;
else if ( V_6 == & V_747 . V_6 )
V_35 = V_748 ;
else if ( V_6 == & V_749 . V_6 )
V_35 = V_750 ;
else if ( V_6 == & V_751 . V_6 )
V_35 = V_752 ;
else if ( V_6 == & V_753 . V_6 )
V_35 = V_754 ;
else if ( V_6 == & V_755 . V_6 )
V_35 = V_756 ;
else if ( V_6 == & V_757 . V_6 )
V_35 = V_758 ;
else if ( V_6 == & V_759 . V_6 )
V_35 = V_760 ;
else if ( V_6 == & V_761 . V_6 )
V_35 = V_762 ;
else if ( V_6 == & V_763 . V_6 )
V_35 = V_764 ;
else if ( V_6 == & V_765 . V_6 )
V_35 = V_766 ;
else if ( V_6 == & V_767 . V_6 )
V_35 = V_768 ;
else if ( V_6 == & V_769 . V_6 )
V_35 = V_770 ;
else if ( V_6 == & V_771 . V_6 )
V_35 = V_772 ;
else if ( V_6 == & V_773 . V_6 )
V_35 = V_774 ;
else if ( V_6 == & V_775 . V_6 )
V_35 = V_776 ;
else if ( V_6 == & V_777 . V_6 )
V_35 = V_778 ;
else if ( V_6 == & V_779 . V_6 )
return V_780 | V_781 ;
else if ( V_6 == & V_782 . V_6 )
return V_780 ;
else if ( V_6 == & V_783 . V_6 )
return V_780 ;
else if ( V_6 == & V_784 . V_6 )
return V_780 ;
else {
F_26 ( 1 , L_88 ) ;
return 0 ;
}
return V_33 -> V_178 ( V_698 , V_35 ) ;
}
static T_4 F_210 ( struct V_30 * V_22 ,
struct V_31 * V_6 , int V_32 )
{
struct V_1 * V_376 = F_25 ( V_22 , struct V_1 , V_22 ) ;
struct V_188 * V_189 = F_211 ( V_376 ) ;
struct V_3 * V_4 = F_58 ( V_189 -> V_347 ) ;
int V_35 ;
if ( V_6 == & V_785 . V_6 )
V_35 = V_786 ;
else if ( V_6 == & V_787 . V_6 )
V_35 = V_788 ;
else if ( V_6 == & V_789 . V_6 )
V_35 = V_790 ;
else if ( V_6 == & V_791 . V_6 )
V_35 = V_792 ;
else if ( V_6 == & V_793 . V_6 )
V_35 = V_794 ;
else if ( V_6 == & V_795 . V_6 )
V_35 = V_796 ;
else {
F_26 ( 1 , L_89 ) ;
return 0 ;
}
return V_4 -> V_8 -> V_178 ( V_797 , V_35 ) ;
}
char * F_212 ( struct V_188 * V_189 )
{
int V_32 ;
char * V_798 = L_79 ;
struct V_365 * V_366 = V_189 -> V_377 ;
T_5 V_799 = V_366 -> V_799 ;
for ( V_32 = 0 ; V_32 < F_28 ( V_800 ) ; V_32 ++ ) {
if ( V_800 [ V_32 ] . V_183 & V_799 ) {
V_798 = V_800 [ V_32 ] . V_184 ;
break;
}
}
return V_798 ;
}
char * F_213 ( struct V_188 * V_189 )
{
int V_32 ;
char * V_181 = L_79 ;
struct V_365 * V_366 = V_189 -> V_377 ;
T_5 V_180 = V_366 -> V_180 ;
for ( V_32 = 0 ; V_32 < F_28 ( V_801 ) ; V_32 ++ ) {
if ( V_801 [ V_32 ] . V_183 & V_180 ) {
V_181 = V_801 [ V_32 ] . V_184 ;
break;
}
}
return V_181 ;
}
static int F_214 ( struct V_802 * V_803 ,
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
if ( V_4 -> V_804 . V_805 . V_20 != & V_806 . V_20 )
return 0 ;
return & V_4 -> V_804 . V_805 == V_803 ;
}
static int F_215 ( struct V_802 * V_803 ,
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
if ( V_4 -> V_807 . V_805 . V_20 != & V_808 . V_20 )
return 0 ;
return & V_4 -> V_807 . V_805 == V_803 ;
}
static int F_216 ( struct V_802 * V_803 ,
struct V_1 * V_2 )
{
struct V_188 * V_189 ;
struct V_3 * V_4 ;
if ( ! F_217 ( V_2 ) )
return 0 ;
V_189 = F_67 ( V_2 ) ;
if ( ! V_189 -> V_347 ||
V_189 -> V_347 -> V_809 . V_805 . V_20 != & V_810 . V_20 )
return 0 ;
V_4 = F_58 ( V_189 -> V_347 ) ;
return & V_4 -> V_33 . V_809 . V_805 == V_803 ;
}
struct V_811 *
F_218 ( struct V_8 * V_437 )
{
struct V_3 * V_4 ;
unsigned long V_385 ;
int V_15 ;
F_59 ( ! V_437 ) ;
V_4 = F_148 ( V_437 ) ;
if ( V_4 )
return NULL ;
V_4 = F_13 ( sizeof( * V_4 ) , V_19 ) ;
if ( ! V_4 )
return NULL ;
F_122 ( & V_4 -> V_812 ) ;
V_4 -> V_8 = V_437 ;
V_4 -> V_33 . V_813 = F_95 ;
V_4 -> V_33 . V_814 = 1 ;
V_4 -> V_2 . V_20 = & V_815 ;
F_14 ( & V_4 -> V_2 , L_90 , V_437 -> V_184 ) ;
V_15 = F_15 ( & V_4 -> V_2 ) ;
if ( V_15 )
goto V_816;
V_15 = F_16 ( & V_4 -> V_2 . V_22 , & V_817 ) ;
if ( V_15 )
goto V_24;
V_4 -> V_33 . V_809 . V_805 . V_20 = & V_810 . V_20 ;
V_4 -> V_33 . V_809 . V_805 . V_818 = F_216 ;
V_4 -> V_33 . V_809 . V_805 . V_819 = & V_820 ;
V_4 -> V_33 . V_821 = sizeof( struct V_365 ) ;
F_219 ( & V_4 -> V_33 . V_809 ) ;
V_4 -> V_807 . V_805 . V_20 = & V_808 . V_20 ;
V_4 -> V_807 . V_805 . V_818 = F_215 ;
V_4 -> V_807 . V_805 . V_819 = & V_822 ;
F_219 ( & V_4 -> V_807 ) ;
V_4 -> V_804 . V_805 . V_20 = & V_806 . V_20 ;
V_4 -> V_804 . V_805 . V_818 = F_214 ;
V_4 -> V_804 . V_805 . V_819 = & V_823 ;
F_219 ( & V_4 -> V_804 ) ;
F_75 ( & V_438 , V_385 ) ;
F_132 ( & V_4 -> V_812 , & V_824 ) ;
F_77 ( & V_438 , V_385 ) ;
F_12 ( V_825 L_91 , V_437 -> V_184 ) ;
return & V_4 -> V_33 ;
V_24:
F_17 ( & V_4 -> V_2 ) ;
return NULL ;
V_816:
F_3 ( V_4 ) ;
return NULL ;
}
int F_220 ( struct V_8 * V_437 )
{
struct V_3 * V_4 ;
unsigned long V_385 ;
F_59 ( ! V_437 ) ;
F_92 ( & V_632 ) ;
V_4 = F_148 ( V_437 ) ;
F_59 ( ! V_4 ) ;
F_75 ( & V_438 , V_385 ) ;
F_142 ( & V_4 -> V_812 ) ;
F_77 ( & V_438 , V_385 ) ;
F_221 ( & V_4 -> V_807 ) ;
F_221 ( & V_4 -> V_804 ) ;
F_221 ( & V_4 -> V_33 . V_809 ) ;
F_19 ( & V_4 -> V_2 . V_22 , & V_817 ) ;
F_17 ( & V_4 -> V_2 ) ;
F_94 ( & V_632 ) ;
return 0 ;
}
static T_11 int F_222 ( void )
{
int V_15 ;
struct V_826 V_827 = {
. V_828 = 1 ,
. V_829 = F_200 ,
} ;
F_12 ( V_412 L_92 ,
V_830 ) ;
F_68 ( & V_427 , 0 ) ;
V_15 = F_223 ( & V_815 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_223 ( & V_17 ) ;
if ( V_15 )
goto V_831;
V_15 = F_223 ( & V_192 ) ;
if ( V_15 )
goto V_832;
V_15 = F_224 ( & V_810 ) ;
if ( V_15 )
goto V_833;
V_15 = F_224 ( & V_808 ) ;
if ( V_15 )
goto V_834;
V_15 = F_224 ( & V_806 ) ;
if ( V_15 )
goto V_835;
V_15 = F_225 ( & V_330 ) ;
if ( V_15 )
goto V_836;
V_443 = F_226 ( & V_837 , V_838 , & V_827 ) ;
if ( ! V_443 ) {
V_15 = - V_839 ;
goto V_840;
}
V_418 = F_227 ( L_93 ) ;
if ( ! V_418 ) {
V_15 = - V_372 ;
goto V_841;
}
return 0 ;
V_841:
F_228 ( V_443 ) ;
V_840:
F_229 ( & V_330 ) ;
V_836:
F_230 ( & V_806 ) ;
V_835:
F_230 ( & V_808 ) ;
V_834:
F_230 ( & V_810 ) ;
V_833:
F_231 ( & V_192 ) ;
V_832:
F_231 ( & V_17 ) ;
V_831:
F_231 ( & V_815 ) ;
return V_15 ;
}
static void T_12 F_232 ( void )
{
F_233 ( V_418 ) ;
F_228 ( V_443 ) ;
F_229 ( & V_330 ) ;
F_230 ( & V_808 ) ;
F_230 ( & V_806 ) ;
F_230 ( & V_810 ) ;
F_231 ( & V_17 ) ;
F_231 ( & V_192 ) ;
F_231 ( & V_815 ) ;
}
