static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_1 ( F_4 ( V_6 ) ) ;
}
static bool
F_5 ( struct V_2 * V_3 , enum V_7 * V_7 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_1 V_12 = F_7 ( V_13 ) ;
if ( ! ( V_12 & V_14 ) )
return false ;
* V_7 = F_8 ( V_12 ) ;
return true ;
}
static void
F_9 ( struct V_2 * V_3 ,
struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
F_10 ( V_11 ,
F_11 ( V_3 -> V_4 . V_19 ) -> V_7 ) ;
F_12 ( V_13 , F_7 ( V_13 ) | V_14 ) ;
}
static void
F_13 ( struct V_2 * V_3 ,
struct V_15 * V_20 ,
struct V_17 * V_21 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
F_12 ( V_13 , F_7 ( V_13 ) & ~ V_14 ) ;
}
static const struct V_22 *
F_14 ( const char * V_23 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < F_15 ( V_25 ) ; V_24 ++ ) {
const struct V_22 * V_22 = & V_25 [ V_24 ] ;
if ( ! strcmp ( V_23 , V_22 -> V_26 ) )
return V_22 ;
}
return NULL ;
}
static const struct V_22 *
F_16 ( struct V_1 * V_1 )
{
return F_14 ( V_1 -> V_23 ) ;
}
static enum V_27
F_17 ( struct V_5 * V_6 ,
struct V_28 * V_29 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
const struct V_22 * V_22 = F_16 ( V_1 ) ;
int V_30 = F_6 ( V_6 -> V_9 ) -> V_31 ;
if ( V_29 -> clock > V_30 )
return V_32 ;
if ( V_22 && abs ( V_22 -> V_33 - F_18 ( V_29 ) * 1000 )
< 1000 )
return V_34 ;
return V_35 ;
}
static void
F_19 ( struct V_2 * V_3 ,
struct V_15 * V_16 )
{
V_16 -> V_4 . V_36 . V_37 = V_16 -> V_38 ;
}
static bool
F_20 ( struct V_2 * V_3 ,
struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
const struct V_22 * V_22 = F_16 ( V_1 ) ;
if ( ! V_22 )
return false ;
V_16 -> V_4 . V_36 . V_37 = V_22 -> clock ;
F_21 ( L_1 ) ;
V_16 -> V_39 = 8 * 3 ;
V_16 -> V_4 . V_36 . V_40 = 0 ;
return true ;
}
static void
F_22 ( struct V_10 * V_11 ,
const struct V_22 * V_22 ,
bool V_41 )
{
T_1 V_42 , V_43 , V_44 ;
T_1 V_45 , V_46 , V_47 , V_48 , V_49 , V_50 , V_51 ;
V_42 = ( V_22 -> V_52 << V_53 ) |
( V_22 -> V_54 << V_55 ) ;
V_43 = ( V_22 -> V_56 << 16 ) |
( V_22 -> V_57 << V_58 ) ;
if ( V_41 )
V_43 |= V_59 ;
V_44 = ( V_22 -> V_60 << V_61 ) |
( V_22 -> V_62 << V_63 ) ;
V_45 = ( V_22 -> V_64 << V_65 ) |
( V_22 -> V_66 << V_67 ) |
( V_22 -> V_68 << V_69 ) ;
V_46 = ( V_22 -> V_70 << V_71 ) |
( V_22 -> V_72 << V_73 ) |
( V_22 -> V_74 << V_75 ) ;
V_47 = ( V_22 -> V_76 << V_77 ) |
( V_22 -> V_78 << V_79 ) |
( V_22 -> V_80 << V_81 ) ;
if ( V_22 -> V_82 )
V_47 |= V_83 ;
V_48 = ( V_22 -> V_84 << V_85 ) |
( V_22 -> V_86 << V_87 ) ;
V_49 = ( V_22 -> V_88 << V_89 ) |
( V_22 -> V_90 << V_91 ) ;
V_50 = ( V_22 -> V_92 << V_93 ) |
( V_22 -> V_94 << V_95 ) ;
V_51 = ( V_22 -> V_96 << V_97 ) |
( V_22 -> V_98 << V_99 ) ;
F_12 ( V_100 , V_42 ) ;
F_12 ( V_101 , V_43 ) ;
F_12 ( V_102 , V_44 ) ;
F_12 ( V_103 , V_45 ) ;
F_12 ( V_104 , V_46 ) ;
F_12 ( V_105 , V_47 ) ;
F_12 ( V_106 , V_48 ) ;
F_12 ( V_107 , V_49 ) ;
F_12 ( V_108 , V_50 ) ;
F_12 ( V_109 , V_51 ) ;
}
static void F_23 ( struct V_10 * V_11 ,
const struct V_110 * V_110 )
{
if ( ! V_110 )
return;
F_12 ( V_111 , ( V_110 -> V_112 << 16 ) |
V_110 -> V_113 ) ;
F_12 ( V_114 , ( V_110 -> V_115 << 16 ) |
V_110 -> V_116 ) ;
F_12 ( V_117 , ( V_110 -> V_118 << 16 ) |
V_110 -> V_119 ) ;
F_12 ( V_120 , ( V_110 -> V_121 << 16 ) |
V_110 -> V_122 ) ;
F_12 ( V_123 , ( V_110 -> V_124 << 16 ) |
V_110 -> V_125 ) ;
F_12 ( V_126 , ( V_110 -> V_127 << 16 ) |
V_110 -> V_128 ) ;
}
static void F_24 ( struct V_2 * V_3 ,
struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_10 * V_11 = F_6 ( V_3 -> V_4 . V_9 ) ;
struct V_129 * V_129 = F_11 ( V_3 -> V_4 . V_19 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
const struct V_22 * V_22 = F_16 ( V_1 ) ;
T_1 V_130 ;
T_1 V_131 , V_132 , V_133 ;
int V_24 , V_134 ;
const struct V_135 * V_135 ;
const struct V_110 * V_110 ;
bool V_41 ;
int V_136 = 0x0 , V_137 = 0x0 ;
unsigned int V_138 , V_139 ;
if ( ! V_22 )
return;
V_130 = F_7 ( V_13 ) ;
V_130 &= V_140 ;
switch ( V_1 -> type ) {
default:
case V_141 :
case V_142 :
V_130 |= V_143 ;
V_135 = V_22 -> V_144 ;
V_110 = V_22 -> V_145 ;
V_41 = V_22 -> V_41 ;
break;
case V_146 :
V_130 |= V_147 ;
V_135 = & V_148 ;
if ( V_22 -> V_41 )
V_110 = & V_149 ;
else
V_110 = & V_150 ;
V_41 = false ;
break;
case V_151 :
V_130 |= V_152 ;
V_135 = V_22 -> V_153 ;
V_110 = V_22 -> V_154 ;
V_41 = V_22 -> V_41 ;
break;
}
if ( V_129 -> V_7 == 1 )
V_130 |= V_155 ;
V_130 |= V_22 -> V_156 ;
if ( V_22 -> V_157 )
V_130 |= V_158 ;
if ( V_22 -> V_159 )
V_130 |= V_160 ;
if ( V_22 -> V_161 )
V_130 |= V_162 ;
V_131 = 0 ;
if ( V_22 -> V_163 )
V_131 |= V_164 ;
if ( V_22 -> V_165 )
V_131 |= V_166 ;
if ( V_22 -> V_167 )
V_131 |= V_168 ;
V_131 |= V_22 -> V_169 ;
if ( V_135 )
V_131 |= V_135 -> V_170 << V_171 ;
V_131 |= V_22 -> V_163 << V_172 ;
V_132 = V_22 -> V_173 << V_174 |
V_22 -> V_165 << V_175 ;
V_133 = V_22 -> V_176 << V_177 |
V_22 -> V_167 << V_178 ;
if ( F_25 ( V_11 ) )
V_130 |= V_179 | V_180 ;
F_22 ( V_11 , V_22 , V_41 ) ;
F_12 ( V_181 , V_131 ) ;
F_12 ( V_182 , V_132 ) ;
F_12 ( V_183 , V_133 ) ;
F_23 ( V_11 , V_110 ) ;
if ( F_26 ( V_11 ) >= 4 )
F_12 ( V_184 , 0x00404000 ) ;
else
F_12 ( V_184 , 0x00606000 ) ;
if ( V_135 )
F_12 ( V_185 ,
( ( V_135 -> V_186 << V_187 ) |
( V_135 -> V_188 << V_189 ) ) ) ;
F_27 ( V_11 , V_129 -> V_7 ) ;
F_12 ( V_190 , V_191 ) ;
V_138 = V_22 -> V_60 - V_22 -> V_62 ;
if ( V_22 -> V_157 )
V_139 = V_22 -> V_64 + 1 ;
else
V_139 = 2 * V_22 -> V_64 + 1 ;
V_136 += V_1 -> V_192 [ V_193 ] ;
V_137 += V_1 -> V_192 [ V_194 ] ;
V_138 -= ( V_1 -> V_192 [ V_193 ] +
V_1 -> V_192 [ V_195 ] ) ;
V_139 -= ( V_1 -> V_192 [ V_194 ] +
V_1 -> V_192 [ V_196 ] ) ;
F_12 ( V_197 , ( V_136 << 16 ) | V_137 ) ;
F_12 ( V_198 , ( V_138 << 16 ) | V_139 ) ;
V_134 = 0 ;
for ( V_24 = 0 ; V_24 < 60 ; V_24 ++ )
F_12 ( F_28 ( V_24 ) , V_22 -> V_199 [ V_134 ++ ] ) ;
for ( V_24 = 0 ; V_24 < 60 ; V_24 ++ )
F_12 ( F_29 ( V_24 ) , V_22 -> V_199 [ V_134 ++ ] ) ;
for ( V_24 = 0 ; V_24 < 43 ; V_24 ++ )
F_12 ( F_30 ( V_24 ) , V_22 -> V_199 [ V_134 ++ ] ) ;
for ( V_24 = 0 ; V_24 < 43 ; V_24 ++ )
F_12 ( F_31 ( V_24 ) , V_22 -> V_199 [ V_134 ++ ] ) ;
F_12 ( V_200 , F_7 ( V_200 ) & V_201 ) ;
F_12 ( V_13 , V_130 ) ;
}
static int
F_32 ( struct V_1 * V_1 ,
struct V_5 * V_6 )
{
struct V_202 * V_19 = V_6 -> V_203 -> V_19 ;
struct V_129 * V_129 = F_11 ( V_19 ) ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_1 V_130 , V_204 ;
T_1 V_205 , V_206 ;
int type ;
if ( V_6 -> V_207 & V_208 ) {
F_33 ( & V_11 -> V_209 ) ;
F_34 ( V_11 , 0 ,
V_210 |
V_211 ) ;
F_35 ( & V_11 -> V_209 ) ;
}
V_206 = V_205 = F_7 ( V_200 ) ;
V_204 = V_130 = F_7 ( V_13 ) ;
V_130 &= ~ ( V_14 | V_212 ) ;
V_130 |= V_213 ;
if ( V_129 -> V_7 == 1 )
V_130 |= V_155 ;
else
V_130 &= ~ V_155 ;
V_205 &= ~ ( V_214 | V_215 | V_216 | V_217 ) ;
V_205 |= ( V_218 |
V_219 |
V_220 |
V_221 |
V_222 |
V_223 |
V_224 |
V_225 ) ;
if ( F_36 ( V_11 ) )
V_205 &= ~ ( V_218 | V_219 |
V_220 | V_221 ) ;
F_12 ( V_13 , V_130 ) ;
F_12 ( V_200 , V_205 ) ;
F_37 ( V_200 ) ;
F_10 ( V_11 , V_129 -> V_7 ) ;
type = - 1 ;
V_205 = F_7 ( V_200 ) ;
F_21 ( L_2 , V_130 , V_205 ) ;
if ( ( V_205 & V_214 ) == ( V_226 | V_227 ) ) {
F_21 ( L_3 ) ;
type = V_142 ;
} else if ( ( V_205 & ( V_228 | V_226 ) ) == V_228 ) {
F_21 ( L_4 ) ;
type = V_151 ;
} else if ( ( V_205 & V_214 ) == 0 ) {
F_21 ( L_5 ) ;
type = V_146 ;
} else {
F_21 ( L_6 ) ;
type = - 1 ;
}
F_12 ( V_200 , V_206 & ~ V_218 ) ;
F_12 ( V_13 , V_204 ) ;
F_37 ( V_13 ) ;
F_10 ( V_11 , V_129 -> V_7 ) ;
if ( V_6 -> V_207 & V_208 ) {
F_33 ( & V_11 -> V_209 ) ;
F_38 ( V_11 , 0 ,
V_210 |
V_211 ) ;
F_35 ( & V_11 -> V_209 ) ;
}
return type ;
}
static void F_39 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
const struct V_22 * V_22 = F_16 ( V_1 ) ;
int V_24 ;
if ( ( V_1 -> type == V_146 ) ==
V_22 -> V_229 )
return;
for ( V_24 = 0 ; V_24 < F_15 ( V_25 ) ; V_24 ++ ) {
V_22 = V_25 + V_24 ;
if ( ( V_1 -> type == V_146 ) ==
V_22 -> V_229 )
break;
}
V_1 -> V_23 = V_22 -> V_26 ;
F_40 ( & V_6 -> V_4 ,
V_6 -> V_9 -> V_230 . V_231 , V_24 ) ;
}
static enum V_232
F_41 ( struct V_5 * V_6 , bool V_233 )
{
struct V_28 V_29 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
enum V_232 V_234 ;
int type ;
F_21 ( L_7 ,
V_6 -> V_4 . V_235 , V_6 -> V_26 ,
V_233 ) ;
V_29 = V_236 [ 0 ] ;
if ( V_233 ) {
struct V_237 V_12 ;
struct V_238 V_239 ;
F_42 ( & V_239 , 0 ) ;
if ( F_43 ( V_6 , & V_29 , & V_12 , & V_239 ) ) {
type = F_32 ( V_1 , V_6 ) ;
F_44 ( V_6 , & V_12 , & V_239 ) ;
V_234 = type < 0 ?
V_240 :
V_241 ;
} else
V_234 = V_242 ;
F_45 ( & V_239 ) ;
F_46 ( & V_239 ) ;
} else
return V_6 -> V_234 ;
if ( V_234 != V_241 )
return V_234 ;
V_1 -> type = type ;
F_39 ( V_6 ) ;
return V_241 ;
}
static void
F_47 ( struct V_5 * V_6 ,
struct V_28 * V_243 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
const struct V_22 * V_22 = F_16 ( V_1 ) ;
if ( V_22 -> V_64 < 480 && V_243 -> V_244 == 480 )
V_243 -> type |= V_245 ;
else if ( V_22 -> V_64 > 480 ) {
if ( V_22 -> V_157 == true && V_22 -> V_64 < 720 ) {
if ( V_243 -> V_244 == 720 )
V_243 -> type |= V_245 ;
} else if ( V_243 -> V_244 == 1080 )
V_243 -> type |= V_245 ;
}
}
static int
F_48 ( struct V_5 * V_6 )
{
struct V_28 * V_243 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
const struct V_22 * V_22 = F_16 ( V_1 ) ;
int V_134 , V_246 = 0 ;
T_2 V_12 ;
for ( V_134 = 0 ; V_134 < F_15 ( V_247 ) ;
V_134 ++ ) {
const struct V_248 * V_249 = & V_247 [ V_134 ] ;
unsigned int V_250 = V_249 -> V_251 ;
unsigned int V_252 = V_249 -> V_253 ;
if ( V_22 -> V_254 && V_249 -> V_251 > V_22 -> V_254 )
continue;
if ( V_249 -> V_251 > 1024 && ( ! V_22 -> V_157
&& ! V_22 -> V_229 ) )
continue;
V_243 = F_49 ( V_6 -> V_9 ) ;
if ( ! V_243 )
continue;
strncpy ( V_243 -> V_26 , V_249 -> V_26 , V_255 ) ;
V_243 -> V_26 [ V_255 - 1 ] = '\0' ;
V_243 -> V_256 = V_250 ;
V_243 -> V_257 = V_250 + 1 ;
V_243 -> V_52 = V_250 + 64 ;
if ( V_243 -> V_52 <= V_243 -> V_257 )
V_243 -> V_52 = V_243 -> V_257 + 1 ;
V_243 -> V_54 = V_250 + 96 ;
V_243 -> V_244 = V_252 ;
V_243 -> V_258 = V_252 + 1 ;
V_243 -> V_259 = V_252 + 32 ;
if ( V_243 -> V_259 <= V_243 -> V_258 )
V_243 -> V_259 = V_243 -> V_258 + 1 ;
V_243 -> V_260 = V_252 + 33 ;
V_12 = ( T_2 ) V_22 -> V_33 * V_243 -> V_260 ;
V_12 *= V_243 -> V_54 ;
V_12 = F_50 ( V_12 , 1000000 ) ;
V_243 -> clock = ( int ) V_12 ;
V_243 -> type = V_261 ;
F_47 ( V_6 , V_243 ) ;
F_51 ( V_6 , V_243 ) ;
V_246 ++ ;
}
return V_246 ;
}
static void
F_52 ( struct V_5 * V_6 )
{
F_53 ( V_6 ) ;
F_54 ( V_6 ) ;
}
static int
F_55 ( struct V_5 * V_6 , struct V_262 * V_263 ,
T_3 V_264 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_202 * V_19 = V_1 -> V_4 . V_4 . V_19 ;
int V_265 = 0 ;
bool V_266 = false ;
V_265 = F_40 ( & V_6 -> V_4 , V_263 , V_264 ) ;
if ( V_265 < 0 )
goto V_267;
if ( V_263 == V_9 -> V_230 . V_268 &&
V_1 -> V_192 [ V_193 ] != V_264 ) {
V_1 -> V_192 [ V_193 ] = V_264 ;
V_266 = true ;
} else if ( V_263 == V_9 -> V_230 . V_269 &&
V_1 -> V_192 [ V_195 ] != V_264 ) {
V_1 -> V_192 [ V_195 ] = V_264 ;
V_266 = true ;
} else if ( V_263 == V_9 -> V_230 . V_270 &&
V_1 -> V_192 [ V_194 ] != V_264 ) {
V_1 -> V_192 [ V_194 ] = V_264 ;
V_266 = true ;
} else if ( V_263 == V_9 -> V_230 . V_271 &&
V_1 -> V_192 [ V_196 ] != V_264 ) {
V_1 -> V_192 [ V_196 ] = V_264 ;
V_266 = true ;
} else if ( V_263 == V_9 -> V_230 . V_231 ) {
if ( V_264 >= F_15 ( V_25 ) ) {
V_265 = - V_272 ;
goto V_267;
}
if ( ! strcmp ( V_1 -> V_23 , V_25 [ V_264 ] . V_26 ) )
goto V_267;
V_1 -> V_23 = V_25 [ V_264 ] . V_26 ;
V_266 = true ;
} else {
V_265 = - V_272 ;
goto V_267;
}
if ( V_266 && V_19 )
F_56 ( V_19 ) ;
V_267:
return V_265 ;
}
void
F_57 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_5 * V_6 ;
struct V_1 * V_1 ;
struct V_2 * V_2 ;
struct V_273 * V_273 ;
T_1 V_274 , V_275 , V_206 ;
const char * V_276 [ F_15 ( V_25 ) ] ;
int V_24 , V_277 = 0 ;
if ( ( F_7 ( V_13 ) & V_278 ) == V_279 )
return;
if ( ! F_58 ( V_11 ) ) {
F_21 ( L_8 ) ;
return;
}
V_206 = F_7 ( V_200 ) ;
F_12 ( V_200 , V_206 | V_218 ) ;
V_274 = F_7 ( V_200 ) ;
F_12 ( V_200 , V_206 & ~ V_218 ) ;
V_275 = F_7 ( V_200 ) ;
F_12 ( V_200 , V_206 ) ;
if ( ( V_274 & V_218 ) == 0 ||
( V_275 & V_218 ) != 0 )
return;
V_1 = F_59 ( sizeof( * V_1 ) , V_280 ) ;
if ( ! V_1 ) {
return;
}
V_273 = F_60 () ;
if ( ! V_273 ) {
F_54 ( V_1 ) ;
return;
}
V_2 = & V_1 -> V_4 ;
V_6 = & V_273 -> V_4 ;
V_273 -> V_207 = V_281 ;
F_61 ( V_9 , V_6 , & V_282 ,
V_151 ) ;
F_62 ( V_9 , & V_2 -> V_4 , & V_283 ,
V_284 , L_9 ) ;
V_2 -> V_285 = F_20 ;
V_2 -> V_286 = F_19 ;
V_2 -> V_287 = F_24 ;
V_2 -> V_288 = F_9 ;
V_2 -> V_289 = F_13 ;
V_2 -> V_290 = F_5 ;
V_273 -> V_290 = V_291 ;
F_63 ( V_273 , V_2 ) ;
V_2 -> type = V_292 ;
V_2 -> V_293 = V_294 ;
V_2 -> V_295 = ( 1 << 0 ) | ( 1 << 1 ) ;
V_2 -> V_296 = 0 ;
V_2 -> V_4 . V_297 = ( ( 1 << 0 ) | ( 1 << 1 ) ) ;
V_1 -> type = V_141 ;
V_1 -> V_192 [ V_193 ] = 54 ;
V_1 -> V_192 [ V_194 ] = 36 ;
V_1 -> V_192 [ V_195 ] = 46 ;
V_1 -> V_192 [ V_196 ] = 37 ;
V_1 -> V_23 = V_25 [ V_277 ] . V_26 ;
F_64 ( V_6 , & V_298 ) ;
V_6 -> V_299 = false ;
V_6 -> V_300 = false ;
for ( V_24 = 0 ; V_24 < F_15 ( V_25 ) ; V_24 ++ )
V_276 [ V_24 ] = V_25 [ V_24 ] . V_26 ;
F_65 ( V_9 ,
F_15 ( V_25 ) ,
V_276 ) ;
F_66 ( & V_6 -> V_4 , V_9 -> V_230 . V_231 ,
V_277 ) ;
F_66 ( & V_6 -> V_4 ,
V_9 -> V_230 . V_268 ,
V_1 -> V_192 [ V_193 ] ) ;
F_66 ( & V_6 -> V_4 ,
V_9 -> V_230 . V_270 ,
V_1 -> V_192 [ V_194 ] ) ;
F_66 ( & V_6 -> V_4 ,
V_9 -> V_230 . V_269 ,
V_1 -> V_192 [ V_195 ] ) ;
F_66 ( & V_6 -> V_4 ,
V_9 -> V_230 . V_271 ,
V_1 -> V_192 [ V_196 ] ) ;
}
