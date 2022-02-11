static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_4 ) ;
}
static struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( F_4 ( V_6 ) ,
struct V_1 ,
V_4 ) ;
}
static void
F_5 ( struct V_2 * V_3 , int V_7 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
switch ( V_7 ) {
case V_13 :
F_6 ( V_14 , F_7 ( V_14 ) | V_15 ) ;
break;
case V_16 :
case V_17 :
case V_18 :
F_6 ( V_14 , F_7 ( V_14 ) & ~ V_15 ) ;
break;
}
}
static const struct V_19 *
F_8 ( const char * V_20 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < sizeof( V_22 ) / sizeof( V_22 [ 0 ] ) ; V_21 ++ ) {
const struct V_19 * V_19 = & V_22 [ V_21 ] ;
if ( ! strcmp ( V_20 , V_19 -> V_23 ) )
return V_19 ;
}
return NULL ;
}
static const struct V_19 *
F_9 ( struct V_1 * V_1 )
{
return F_8 ( V_1 -> V_20 ) ;
}
static enum V_24
F_10 ( struct V_5 * V_6 ,
struct V_25 * V_7 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
const struct V_19 * V_19 = F_9 ( V_1 ) ;
if ( V_19 && abs ( V_19 -> V_26 - F_11 ( V_7 ) * 1000 )
< 1000 )
return V_27 ;
return V_28 ;
}
static bool
F_12 ( struct V_2 * V_3 , struct V_25 * V_7 ,
struct V_25 * V_29 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_30 * V_31 = & V_9 -> V_32 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
const struct V_19 * V_19 = F_9 ( V_1 ) ;
struct V_2 * V_33 ;
if ( ! V_19 )
return false ;
F_13 (other_encoder, &drm_config->encoder_list, head) {
if ( V_33 != V_3 &&
V_33 -> V_34 == V_3 -> V_34 )
return false ;
}
V_29 -> clock = V_19 -> clock ;
return true ;
}
static void
F_14 ( struct V_2 * V_3 , struct V_25 * V_7 ,
struct V_25 * V_29 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_35 * V_34 = V_3 -> V_34 ;
struct V_36 * V_36 = F_15 ( V_34 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
const struct V_19 * V_19 = F_9 ( V_1 ) ;
T_1 V_37 ;
T_1 V_38 , V_39 , V_40 ;
T_1 V_41 , V_42 , V_43 , V_44 , V_45 , V_46 , V_47 ;
T_1 V_48 , V_49 , V_50 ;
int V_21 , V_51 ;
const struct V_52 * V_52 ;
const struct V_53 * V_53 ;
bool V_54 ;
int V_55 = V_36 -> V_55 ;
if ( ! V_19 )
return;
V_37 = F_7 ( V_14 ) ;
V_37 &= V_56 ;
switch ( V_1 -> type ) {
default:
case V_57 :
case V_58 :
V_37 |= V_59 ;
V_52 = V_19 -> V_60 ;
V_53 = V_19 -> V_61 ;
V_54 = V_19 -> V_54 ;
break;
case V_62 :
V_37 |= V_63 ;
V_52 = & V_64 ;
if ( V_19 -> V_54 )
V_53 = & V_65 ;
else
V_53 = & V_66 ;
V_54 = false ;
break;
case V_67 :
V_37 |= V_68 ;
V_52 = V_19 -> V_69 ;
V_53 = V_19 -> V_70 ;
V_54 = V_19 -> V_54 ;
break;
}
V_38 = ( V_19 -> V_71 << V_72 ) |
( V_19 -> V_73 << V_74 ) ;
V_39 = ( V_19 -> V_75 << 16 ) |
( V_19 -> V_76 << V_77 ) ;
if ( V_54 )
V_39 |= V_78 ;
V_40 = ( V_19 -> V_79 << V_80 ) |
( V_19 -> V_81 << V_82 ) ;
V_41 = ( V_19 -> V_83 << V_84 ) |
( V_19 -> V_85 << V_86 ) |
( V_19 -> V_87 << V_88 ) ;
V_42 = ( V_19 -> V_89 << V_90 ) |
( V_19 -> V_91 << V_92 ) |
( V_19 -> V_93 << V_94 ) ;
V_43 = ( V_19 -> V_95 << V_96 ) |
( V_19 -> V_97 << V_98 ) |
( V_19 -> V_99 << V_100 ) ;
if ( V_19 -> V_101 )
V_43 |= V_102 ;
V_44 = ( V_19 -> V_103 << V_104 ) |
( V_19 -> V_105 << V_106 ) ;
V_45 = ( V_19 -> V_107 << V_108 ) |
( V_19 -> V_109 << V_110 ) ;
V_46 = ( V_19 -> V_111 << V_112 ) |
( V_19 -> V_113 << V_114 ) ;
V_47 = ( V_19 -> V_115 << V_116 ) |
( V_19 -> V_117 << V_118 ) ;
if ( V_36 -> V_55 == 1 )
V_37 |= V_119 ;
V_37 |= V_19 -> V_120 ;
if ( V_19 -> V_121 )
V_37 |= V_122 ;
if ( V_19 -> V_123 )
V_37 |= V_124 ;
if ( V_19 -> V_125 )
V_37 |= V_126 ;
V_48 = 0 ;
if ( V_19 -> V_127 )
V_48 |= V_128 ;
if ( V_19 -> V_129 )
V_48 |= V_130 ;
if ( V_19 -> V_131 )
V_48 |= V_132 ;
V_48 |= V_19 -> V_133 ;
if ( V_52 )
V_48 |= V_52 -> V_134 << V_135 ;
V_48 |= V_19 -> V_127 << V_136 ;
V_49 = V_19 -> V_137 << V_138 |
V_19 -> V_129 << V_139 ;
V_50 = V_19 -> V_140 << V_141 |
V_19 -> V_131 << V_142 ;
if ( V_9 -> V_143 < 0x2772 )
V_37 |= V_144 | V_145 ;
F_6 ( V_146 , V_38 ) ;
F_6 ( V_147 , V_39 ) ;
F_6 ( V_148 , V_40 ) ;
F_6 ( V_149 , V_41 ) ;
F_6 ( V_150 , V_42 ) ;
F_6 ( V_151 , V_43 ) ;
F_6 ( V_152 , V_44 ) ;
F_6 ( V_153 , V_45 ) ;
F_6 ( V_154 , V_46 ) ;
F_6 ( V_155 , V_47 ) ;
F_6 ( V_156 , V_48 ) ;
F_6 ( V_157 , V_49 ) ;
F_6 ( V_158 , V_50 ) ;
if ( V_53 ) {
F_6 ( V_159 , ( V_53 -> V_160 << 16 ) |
V_53 -> V_161 ) ;
F_6 ( V_162 , ( V_53 -> V_163 << 16 ) |
V_53 -> V_164 ) ;
F_6 ( V_165 , ( V_53 -> V_166 << 16 ) |
V_53 -> V_167 ) ;
F_6 ( V_168 , ( V_53 -> V_169 << 16 ) |
V_53 -> V_170 ) ;
F_6 ( V_171 , ( V_53 -> V_172 << 16 ) |
V_53 -> V_173 ) ;
F_6 ( V_174 , ( V_53 -> V_175 << 16 ) |
V_53 -> V_176 ) ;
}
if ( F_16 ( V_9 ) -> V_177 >= 4 )
F_6 ( V_178 , 0x00404000 ) ;
else
F_6 ( V_178 , 0x00606000 ) ;
if ( V_52 )
F_6 ( V_179 ,
( ( V_52 -> V_180 << V_181 ) |
( V_52 -> V_182 << V_183 ) ) ) ;
{
int V_184 = F_17 ( V_55 ) ;
int V_185 = F_18 ( V_36 -> V_186 ) ;
int V_187 = F_7 ( V_184 ) ;
int V_188 = F_7 ( V_185 ) ;
int V_189 = F_19 ( V_36 -> V_186 ) ;
int V_190 = 0x0 , V_191 = 0x0 ;
unsigned int V_192 , V_193 ;
F_6 ( V_185 , V_188 & ~ V_194 ) ;
F_6 ( V_189 , F_7 ( V_189 ) ) ;
if ( F_20 ( V_9 ) )
F_21 ( V_9 , V_36 -> V_55 ) ;
F_6 ( V_184 , V_187 & ~ V_195 ) ;
F_22 ( V_9 , V_36 -> V_55 ) ;
F_6 ( V_196 , V_197 ) ;
V_192 = V_19 -> V_79 - V_19 -> V_81 ;
if ( V_19 -> V_121 )
V_193 = V_19 -> V_83 + 1 ;
else
V_193 = 2 * V_19 -> V_83 + 1 ;
V_190 += V_1 -> V_198 [ V_199 ] ;
V_191 += V_1 -> V_198 [ V_200 ] ;
V_192 -= ( V_1 -> V_198 [ V_199 ] +
V_1 -> V_198 [ V_201 ] ) ;
V_193 -= ( V_1 -> V_198 [ V_200 ] +
V_1 -> V_198 [ V_202 ] ) ;
F_6 ( V_203 , ( V_190 << 16 ) | V_191 ) ;
F_6 ( V_204 , ( V_192 << 16 ) | V_193 ) ;
F_6 ( V_184 , V_187 ) ;
F_6 ( V_185 , V_188 ) ;
F_6 ( V_189 , F_7 ( V_189 ) ) ;
}
V_51 = 0 ;
for ( V_21 = 0 ; V_21 < 60 ; V_21 ++ )
F_6 ( V_205 + ( V_21 << 2 ) , V_19 -> V_206 [ V_51 ++ ] ) ;
for ( V_21 = 0 ; V_21 < 60 ; V_21 ++ )
F_6 ( V_207 + ( V_21 << 2 ) , V_19 -> V_206 [ V_51 ++ ] ) ;
for ( V_21 = 0 ; V_21 < 43 ; V_21 ++ )
F_6 ( V_208 + ( V_21 << 2 ) , V_19 -> V_206 [ V_51 ++ ] ) ;
for ( V_21 = 0 ; V_21 < 43 ; V_21 ++ )
F_6 ( V_209 + ( V_21 << 2 ) , V_19 -> V_206 [ V_51 ++ ] ) ;
F_6 ( V_210 , F_7 ( V_210 ) & V_211 ) ;
F_6 ( V_14 , V_37 ) ;
}
static int
F_23 ( struct V_1 * V_1 ,
struct V_5 * V_6 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_35 * V_34 = V_3 -> V_34 ;
struct V_36 * V_36 = F_15 ( V_34 ) ;
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
unsigned long V_212 ;
T_1 V_37 , V_213 ;
T_1 V_214 , V_215 ;
int type ;
if ( V_6 -> V_216 & V_217 ) {
F_24 ( & V_11 -> V_218 , V_212 ) ;
F_25 ( V_11 , 0 ,
V_219 |
V_220 ) ;
F_26 ( & V_11 -> V_218 , V_212 ) ;
}
V_215 = V_214 = F_7 ( V_210 ) ;
V_213 = V_37 = F_7 ( V_14 ) ;
V_37 &= ~ ( V_15 | V_221 ) ;
V_37 |= V_222 ;
if ( V_36 -> V_55 == 1 )
V_37 |= V_119 ;
else
V_37 &= ~ V_119 ;
V_214 &= ~ ( V_223 | V_224 | V_225 | V_226 ) ;
V_214 |= ( V_227 |
V_228 |
V_229 |
V_230 |
V_231 |
V_232 |
V_233 |
V_234 ) ;
F_6 ( V_14 , V_37 ) ;
F_6 ( V_210 , V_214 ) ;
F_27 ( V_210 ) ;
F_21 ( V_1 -> V_4 . V_4 . V_9 ,
F_15 ( V_1 -> V_4 . V_4 . V_34 ) -> V_55 ) ;
type = - 1 ;
V_214 = F_7 ( V_210 ) ;
F_28 ( L_1 , V_37 , V_214 ) ;
if ( ( V_214 & V_223 ) == ( V_235 | V_236 ) ) {
F_28 ( L_2 ) ;
type = V_58 ;
} else if ( ( V_214 & ( V_237 | V_235 ) ) == V_237 ) {
F_28 ( L_3 ) ;
type = V_67 ;
} else if ( ( V_214 & V_223 ) == 0 ) {
F_28 ( L_4 ) ;
type = V_62 ;
} else {
F_28 ( L_5 ) ;
type = - 1 ;
}
F_6 ( V_210 , V_215 & ~ V_227 ) ;
F_6 ( V_14 , V_213 ) ;
if ( V_6 -> V_216 & V_217 ) {
F_24 ( & V_11 -> V_218 , V_212 ) ;
F_29 ( V_11 , 0 ,
V_219 |
V_220 ) ;
F_26 ( & V_11 -> V_218 , V_212 ) ;
}
return type ;
}
static void F_30 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
const struct V_19 * V_19 = F_9 ( V_1 ) ;
int V_21 ;
if ( ( V_1 -> type == V_62 ) ==
V_19 -> V_238 )
return;
for ( V_21 = 0 ; V_21 < sizeof( V_22 ) / sizeof( * V_22 ) ; V_21 ++ ) {
V_19 = V_22 + V_21 ;
if ( ( V_1 -> type == V_62 ) ==
V_19 -> V_238 )
break;
}
V_1 -> V_20 = V_19 -> V_23 ;
F_31 ( V_6 ,
V_6 -> V_9 -> V_32 . V_239 , V_21 ) ;
}
static enum V_240
F_32 ( struct V_5 * V_6 , bool V_241 )
{
struct V_25 V_7 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
int type ;
V_7 = V_242 [ 0 ] ;
F_33 ( & V_7 , V_243 ) ;
if ( V_1 -> V_4 . V_4 . V_34 && V_1 -> V_4 . V_4 . V_34 -> V_244 ) {
type = F_23 ( V_1 , V_6 ) ;
} else if ( V_241 ) {
struct V_245 V_246 ;
if ( F_34 ( & V_1 -> V_4 , V_6 ,
& V_7 , & V_246 ) ) {
type = F_23 ( V_1 , V_6 ) ;
F_35 ( & V_1 -> V_4 ,
V_6 ,
& V_246 ) ;
} else
return V_247 ;
} else
return V_6 -> V_248 ;
if ( type < 0 )
return V_249 ;
V_1 -> type = type ;
F_30 ( V_6 ) ;
return V_250 ;
}
static void
F_36 ( struct V_5 * V_6 ,
struct V_25 * V_251 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
const struct V_19 * V_19 = F_9 ( V_1 ) ;
if ( V_19 -> V_83 < 480 && V_251 -> V_252 == 480 )
V_251 -> type |= V_253 ;
else if ( V_19 -> V_83 > 480 ) {
if ( V_19 -> V_121 == true && V_19 -> V_83 < 720 ) {
if ( V_251 -> V_252 == 720 )
V_251 -> type |= V_253 ;
} else if ( V_251 -> V_252 == 1080 )
V_251 -> type |= V_253 ;
}
}
static int
F_37 ( struct V_5 * V_6 )
{
struct V_25 * V_251 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
const struct V_19 * V_19 = F_9 ( V_1 ) ;
int V_51 , V_254 = 0 ;
T_2 V_246 ;
for ( V_51 = 0 ; V_51 < F_38 ( V_255 ) ;
V_51 ++ ) {
const struct V_256 * V_257 = & V_255 [ V_51 ] ;
unsigned int V_258 = V_257 -> V_259 ;
unsigned int V_260 = V_257 -> V_261 ;
if ( V_19 -> V_262 && V_257 -> V_259 > V_19 -> V_262 )
continue;
if ( V_257 -> V_259 > 1024 && ( ! V_19 -> V_121
&& ! V_19 -> V_238 ) )
continue;
V_251 = F_39 ( V_6 -> V_9 ) ;
if ( ! V_251 )
continue;
strncpy ( V_251 -> V_23 , V_257 -> V_23 , V_263 ) ;
V_251 -> V_264 = V_258 ;
V_251 -> V_265 = V_258 + 1 ;
V_251 -> V_71 = V_258 + 64 ;
if ( V_251 -> V_71 <= V_251 -> V_265 )
V_251 -> V_71 = V_251 -> V_265 + 1 ;
V_251 -> V_73 = V_258 + 96 ;
V_251 -> V_252 = V_260 ;
V_251 -> V_266 = V_260 + 1 ;
V_251 -> V_267 = V_260 + 32 ;
if ( V_251 -> V_267 <= V_251 -> V_266 )
V_251 -> V_267 = V_251 -> V_266 + 1 ;
V_251 -> V_268 = V_260 + 33 ;
V_246 = ( T_2 ) V_19 -> V_26 * V_251 -> V_268 ;
V_246 *= V_251 -> V_73 ;
V_246 = F_40 ( V_246 , 1000000 ) ;
V_251 -> clock = ( int ) V_246 ;
V_251 -> type = V_269 ;
F_36 ( V_6 , V_251 ) ;
F_41 ( V_6 , V_251 ) ;
V_254 ++ ;
}
return V_254 ;
}
static void
F_42 ( struct V_5 * V_6 )
{
F_43 ( V_6 ) ;
F_44 ( V_6 ) ;
F_45 ( V_6 ) ;
}
static int
F_46 ( struct V_5 * V_6 , struct V_270 * V_271 ,
T_3 V_272 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_35 * V_34 = V_1 -> V_4 . V_4 . V_34 ;
int V_273 = 0 ;
bool V_274 = false ;
V_273 = F_31 ( V_6 , V_271 , V_272 ) ;
if ( V_273 < 0 )
goto V_275;
if ( V_271 == V_9 -> V_32 . V_276 &&
V_1 -> V_198 [ V_199 ] != V_272 ) {
V_1 -> V_198 [ V_199 ] = V_272 ;
V_274 = true ;
} else if ( V_271 == V_9 -> V_32 . V_277 &&
V_1 -> V_198 [ V_201 ] != V_272 ) {
V_1 -> V_198 [ V_201 ] = V_272 ;
V_274 = true ;
} else if ( V_271 == V_9 -> V_32 . V_278 &&
V_1 -> V_198 [ V_200 ] != V_272 ) {
V_1 -> V_198 [ V_200 ] = V_272 ;
V_274 = true ;
} else if ( V_271 == V_9 -> V_32 . V_279 &&
V_1 -> V_198 [ V_202 ] != V_272 ) {
V_1 -> V_198 [ V_202 ] = V_272 ;
V_274 = true ;
} else if ( V_271 == V_9 -> V_32 . V_239 ) {
if ( V_272 >= F_38 ( V_22 ) ) {
V_273 = - V_280 ;
goto V_275;
}
if ( ! strcmp ( V_1 -> V_20 , V_22 [ V_272 ] . V_23 ) )
goto V_275;
V_1 -> V_20 = V_22 [ V_272 ] . V_23 ;
V_274 = true ;
} else {
V_273 = - V_280 ;
goto V_275;
}
if ( V_274 && V_34 )
F_47 ( V_34 , & V_34 -> V_7 , V_34 -> V_281 ,
V_34 -> V_282 , V_34 -> V_283 ) ;
V_275:
return V_273 ;
}
static int F_48 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_284 * V_285 ;
int V_21 , V_273 ;
if ( ! V_11 -> V_286 )
return 1 ;
V_273 = 0 ;
for ( V_21 = 0 ; V_21 < V_11 -> V_286 ; V_21 ++ ) {
V_285 = V_11 -> V_287 + V_21 ;
if ( V_285 -> V_288 != V_289 &&
V_285 -> V_288 != V_290 )
continue;
if ( V_285 -> V_291 ) {
V_273 = 1 ;
break;
}
}
return V_273 ;
}
void
F_49 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_5 * V_6 ;
struct V_1 * V_1 ;
struct V_292 * V_292 ;
struct V_293 * V_293 ;
T_1 V_294 , V_295 , V_215 ;
char * V_296 [ F_38 ( V_22 ) ] ;
int V_21 , V_297 = 0 ;
if ( ( F_7 ( V_14 ) & V_298 ) == V_299 )
return;
if ( ! F_48 ( V_9 ) ) {
F_28 ( L_6 ) ;
return;
}
if ( ! V_11 -> V_300 )
return;
V_215 = F_7 ( V_210 ) ;
F_6 ( V_210 , V_215 | V_227 ) ;
V_294 = F_7 ( V_210 ) ;
F_6 ( V_210 , V_215 & ~ V_227 ) ;
V_295 = F_7 ( V_210 ) ;
F_6 ( V_210 , V_215 ) ;
if ( ( V_294 & V_227 ) == 0 ||
( V_295 & V_227 ) != 0 )
return;
V_1 = F_50 ( sizeof( struct V_1 ) , V_301 ) ;
if ( ! V_1 ) {
return;
}
V_293 = F_50 ( sizeof( struct V_293 ) , V_301 ) ;
if ( ! V_293 ) {
F_45 ( V_1 ) ;
return;
}
V_292 = & V_1 -> V_4 ;
V_6 = & V_293 -> V_4 ;
V_6 -> V_216 = V_302 ;
F_51 ( V_9 , V_6 , & V_303 ,
V_67 ) ;
F_52 ( V_9 , & V_292 -> V_4 , & V_304 ,
V_305 ) ;
F_53 ( V_293 , V_292 ) ;
V_292 -> type = V_306 ;
V_292 -> V_307 = ( 1 << 0 ) | ( 1 << 1 ) ;
V_292 -> V_308 = ( 1 << V_309 ) ;
V_292 -> V_4 . V_310 = ( ( 1 << 0 ) | ( 1 << 1 ) ) ;
V_292 -> V_4 . V_311 = ( 1 << V_306 ) ;
V_1 -> type = V_57 ;
V_1 -> V_198 [ V_199 ] = 54 ;
V_1 -> V_198 [ V_200 ] = 36 ;
V_1 -> V_198 [ V_201 ] = 46 ;
V_1 -> V_198 [ V_202 ] = 37 ;
V_1 -> V_20 = V_22 [ V_297 ] . V_23 ;
F_54 ( & V_292 -> V_4 , & V_312 ) ;
F_55 ( V_6 , & V_313 ) ;
V_6 -> V_314 = false ;
V_6 -> V_315 = false ;
for ( V_21 = 0 ; V_21 < F_38 ( V_22 ) ; V_21 ++ )
V_296 [ V_21 ] = ( char * ) V_22 [ V_21 ] . V_23 ;
F_56 ( V_9 ,
F_38 ( V_22 ) ,
V_296 ) ;
F_57 ( V_6 , V_9 -> V_32 . V_239 ,
V_297 ) ;
F_57 ( V_6 ,
V_9 -> V_32 . V_276 ,
V_1 -> V_198 [ V_199 ] ) ;
F_57 ( V_6 ,
V_9 -> V_32 . V_278 ,
V_1 -> V_198 [ V_200 ] ) ;
F_57 ( V_6 ,
V_9 -> V_32 . V_277 ,
V_1 -> V_198 [ V_201 ] ) ;
F_57 ( V_6 ,
V_9 -> V_32 . V_279 ,
V_1 -> V_198 [ V_202 ] ) ;
F_58 ( V_6 ) ;
}
