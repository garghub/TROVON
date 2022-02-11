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
static void F_15 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = F_8 ( V_2 ) ;
F_16 ( V_134 -> V_138 , V_147 +
V_148 , 0x0700 , 0x0200 ) ;
F_16 ( V_134 -> V_138 , V_90 ,
V_149 , V_150 ) ;
F_16 ( V_134 -> V_138 , V_89 ,
V_151 | V_152 | V_153 ,
V_154 | V_155 | V_156 ) ;
F_17 ( V_134 -> V_138 , V_147 + V_157 ,
0x9f00 ) ;
F_16 ( V_134 -> V_138 , V_70 ,
V_158 | V_159 , 0 ) ;
F_16 ( V_134 -> V_138 , V_70 ,
V_160 ,
V_160 ) ;
F_18 ( 10000 , 15000 ) ;
F_16 ( V_134 -> V_138 , V_70 ,
V_158 | V_159 ,
V_158 | V_159 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = F_8 ( V_2 ) ;
F_16 ( V_134 -> V_138 , V_90 ,
V_149 | V_161 ,
V_162 | V_163 ) ;
F_16 ( V_134 -> V_138 , V_92 ,
V_164 , V_165 ) ;
F_16 ( V_134 -> V_138 , V_91 ,
V_166 | V_167 | V_168 ,
( V_169 << V_170 ) |
( V_171 << V_172 ) |
( V_169 << V_173 ) ) ;
F_17 ( V_134 -> V_138 , V_147 +
V_174 , 0x1c00 ) ;
F_16 ( V_134 -> V_138 , V_89 ,
V_151 | V_152 ,
V_175 | V_176 ) ;
F_16 ( V_134 -> V_138 , V_147 +
V_148 , 0x0700 , 0x0400 ) ;
}
static int F_20 ( struct V_127 * V_128 ,
struct V_129 * V_130 , int V_131 )
{
struct V_1 * V_2 = F_7 ( V_128 -> V_132 ) ;
struct V_133 * V_134 = F_8 ( V_2 ) ;
switch ( V_131 ) {
case V_177 :
F_19 ( V_2 ) ;
V_134 -> V_178 = 0 ;
break;
case V_179 :
V_134 -> V_178 = 1 ;
F_18 ( 70000 , 75000 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_21 ( struct V_127 * V_128 ,
struct V_129 * V_130 , int V_131 )
{
struct V_1 * V_2 = F_7 ( V_128 -> V_132 ) ;
switch ( V_131 ) {
case V_177 :
F_15 ( V_2 ) ;
F_12 ( V_2 , V_70 ,
V_180 , V_180 ) ;
F_12 ( V_2 , V_30 ,
V_181 | V_182 , 0 ) ;
break;
case V_179 :
F_12 ( V_2 , V_30 ,
V_181 | V_182 ,
V_181 | V_182 ) ;
F_12 ( V_2 , V_70 ,
V_180 , 0 ) ;
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
case V_177 :
F_15 ( V_2 ) ;
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
struct V_133 * V_134 = F_8 ( V_2 ) ;
switch ( V_131 ) {
case V_177 :
if ( ! V_134 -> V_178 )
F_18 ( 80000 , 85000 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , int V_183 )
{
int V_184 = 0 , V_144 ;
if ( V_2 == NULL )
return - V_185 ;
V_144 = F_14 ( V_2 , V_74 ) ;
V_144 = ( V_144 & V_186 ) >> V_187 ;
switch ( V_183 ) {
case V_188 :
switch ( V_144 ) {
case V_189 :
case V_190 :
V_184 |= V_191 ;
break;
case V_192 :
V_184 |= V_191 ;
case V_193 :
case V_194 :
V_184 |= V_195 ;
break;
}
break;
case V_196 :
switch ( V_144 ) {
case V_197 :
case V_194 :
V_184 |= V_191 ;
break;
case V_198 :
V_184 |= V_191 ;
case V_189 :
case V_199 :
V_184 |= V_195 ;
break;
}
break;
default:
V_184 = - V_185 ;
break;
}
return V_184 ;
}
static int F_25 ( struct V_200 * V_201 ,
struct V_202 * V_203 , struct V_204 * V_205 )
{
struct V_1 * V_2 = V_205 -> V_2 ;
struct V_133 * V_134 = F_8 ( V_2 ) ;
unsigned int V_206 = 0 , V_207 , V_208 ;
int V_209 , V_210 , V_211 , V_212 ;
V_134 -> V_213 [ V_205 -> V_214 ] = F_26 ( V_203 ) ;
V_210 = F_27 ( V_134 -> V_137 , V_134 -> V_213 [ V_205 -> V_214 ] ) ;
if ( V_210 < 0 ) {
F_11 ( V_2 -> V_5 , L_2 ,
V_134 -> V_213 [ V_205 -> V_214 ] , V_205 -> V_214 ) ;
return - V_185 ;
}
V_212 = F_28 ( V_203 ) ;
if ( V_212 < 0 ) {
F_11 ( V_2 -> V_5 , L_3 , V_212 ) ;
return V_212 ;
}
if ( V_212 > 32 )
V_211 = 1 ;
else
V_211 = 0 ;
V_134 -> V_215 [ V_205 -> V_214 ] = V_134 -> V_213 [ V_205 -> V_214 ] * ( 32 << V_211 ) ;
F_29 ( V_205 -> V_5 , L_4 ,
V_134 -> V_215 [ V_205 -> V_214 ] , V_134 -> V_213 [ V_205 -> V_214 ] ) ;
F_29 ( V_205 -> V_5 , L_5 ,
V_211 , V_210 , V_205 -> V_214 ) ;
switch ( F_30 ( V_203 ) ) {
case 16 :
break;
case 20 :
V_206 |= V_216 ;
break;
case 24 :
V_206 |= V_217 ;
break;
case 8 :
V_206 |= V_218 ;
break;
default:
return - V_185 ;
}
V_209 = F_24 ( V_2 , V_205 -> V_214 ) ;
if ( V_209 < 0 ) {
F_11 ( V_2 -> V_5 , L_6 , V_209 ) ;
return - V_185 ;
}
if ( V_209 & V_191 ) {
V_208 = V_219 | V_220 ;
V_207 = V_211 << V_221 |
V_210 << V_139 ;
F_12 ( V_2 , V_74 ,
V_222 , V_206 ) ;
F_12 ( V_2 , V_76 , V_208 , V_207 ) ;
}
if ( V_209 & V_195 ) {
V_208 = V_223 | V_224 ;
V_207 = V_211 << V_225 |
V_210 << V_226 ;
F_12 ( V_2 , V_75 ,
V_222 , V_206 ) ;
F_12 ( V_2 , V_76 , V_208 , V_207 ) ;
}
return 0 ;
}
static int F_31 ( struct V_204 * V_205 , unsigned int V_227 )
{
struct V_1 * V_2 = V_205 -> V_2 ;
struct V_133 * V_134 = F_8 ( V_2 ) ;
unsigned int V_228 = 0 ;
int V_209 ;
switch ( V_227 & V_229 ) {
case V_230 :
V_134 -> V_231 [ V_205 -> V_214 ] = 1 ;
break;
case V_232 :
V_228 |= V_233 ;
V_134 -> V_231 [ V_205 -> V_214 ] = 0 ;
break;
default:
return - V_185 ;
}
switch ( V_227 & V_234 ) {
case V_235 :
break;
case V_236 :
V_228 |= V_237 ;
break;
default:
return - V_185 ;
}
switch ( V_227 & V_238 ) {
case V_239 :
break;
case V_240 :
V_228 |= V_241 ;
break;
case V_242 :
V_228 |= V_243 ;
break;
case V_244 :
V_228 |= V_245 ;
break;
default:
return - V_185 ;
}
V_209 = F_24 ( V_2 , V_205 -> V_214 ) ;
if ( V_209 < 0 ) {
F_11 ( V_2 -> V_5 , L_6 , V_209 ) ;
return - V_185 ;
}
if ( V_209 & V_191 ) {
F_12 ( V_2 , V_74 ,
V_246 | V_247 |
V_248 , V_228 ) ;
}
if ( V_209 & V_195 ) {
F_12 ( V_2 , V_75 ,
V_246 | V_247 |
V_248 , V_228 ) ;
}
return 0 ;
}
static int F_32 ( struct V_204 * V_205 ,
int V_249 , unsigned int V_250 , int V_251 )
{
struct V_1 * V_2 = V_205 -> V_2 ;
struct V_133 * V_134 = F_8 ( V_2 ) ;
unsigned int V_228 = 0 ;
if ( V_250 == V_134 -> V_137 && V_249 == V_134 -> V_252 )
return 0 ;
switch ( V_249 ) {
case V_253 :
V_228 |= V_254 ;
break;
case V_255 :
V_228 |= V_146 ;
break;
default:
F_11 ( V_2 -> V_5 , L_7 , V_249 ) ;
return - V_185 ;
}
F_12 ( V_2 , V_79 ,
V_145 , V_228 ) ;
V_134 -> V_137 = V_250 ;
V_134 -> V_252 = V_249 ;
F_29 ( V_205 -> V_5 , L_8 , V_250 , V_249 ) ;
return 0 ;
}
static int F_33 ( struct V_204 * V_205 , int V_256 , int V_142 ,
unsigned int V_257 , unsigned int V_258 )
{
struct V_1 * V_2 = V_205 -> V_2 ;
struct V_133 * V_134 = F_8 ( V_2 ) ;
struct V_259 V_260 ;
int V_184 , V_209 ;
if ( V_142 == V_134 -> V_261 && V_257 == V_134 -> V_262 &&
V_258 == V_134 -> V_263 )
return 0 ;
if ( ! V_257 || ! V_258 ) {
F_29 ( V_2 -> V_5 , L_9 ) ;
V_134 -> V_262 = 0 ;
V_134 -> V_263 = 0 ;
F_12 ( V_2 , V_79 ,
V_145 , V_254 ) ;
return 0 ;
}
switch ( V_142 ) {
case V_264 :
F_12 ( V_2 , V_79 ,
V_265 , V_266 ) ;
break;
case V_267 :
case V_268 :
V_209 = F_24 ( V_2 , V_205 -> V_214 ) ;
if ( V_209 < 0 ) {
F_11 ( V_2 -> V_5 ,
L_6 , V_209 ) ;
return - V_185 ;
}
if ( V_209 & V_191 ) {
F_12 ( V_2 , V_79 ,
V_265 , V_269 ) ;
}
if ( V_209 & V_195 ) {
F_12 ( V_2 , V_79 ,
V_265 , V_270 ) ;
}
break;
default:
F_11 ( V_2 -> V_5 , L_10 , V_142 ) ;
return - V_185 ;
}
V_184 = F_34 ( V_257 , V_258 , & V_260 ) ;
if ( V_184 < 0 ) {
F_11 ( V_2 -> V_5 , L_11 , V_257 ) ;
return V_184 ;
}
F_29 ( V_2 -> V_5 , L_12 ,
V_260 . V_271 , ( V_260 . V_271 ? 0 : V_260 . V_272 ) ,
V_260 . V_273 , V_260 . V_274 ) ;
F_2 ( V_2 , V_80 ,
V_260 . V_273 << V_275 | V_260 . V_274 ) ;
F_2 ( V_2 , V_81 ,
( V_260 . V_271 ? 0 : V_260 . V_272 ) << V_276 |
V_260 . V_271 << V_277 ) ;
V_134 -> V_262 = V_257 ;
V_134 -> V_263 = V_258 ;
V_134 -> V_261 = V_142 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
enum V_278 V_279 )
{
switch ( V_279 ) {
case V_280 :
if ( V_281 == F_36 ( V_2 ) ) {
F_12 ( V_2 , V_70 ,
V_282 | V_283 |
V_284 | V_285 ,
V_282 | V_283 |
V_284 | V_285 ) ;
F_18 ( 10000 , 15000 ) ;
F_12 ( V_2 , V_70 ,
V_158 | V_159 ,
V_158 | V_159 ) ;
F_12 ( V_2 , V_124 ,
0x0301 , 0x0301 ) ;
F_12 ( V_2 , V_94 ,
0x0030 , 0x0030 ) ;
}
break;
case V_281 :
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
int F_37 ( struct V_1 * V_2 ,
bool V_286 , bool V_287 )
{
struct V_133 * V_134 = F_8 ( V_2 ) ;
F_16 ( V_134 -> V_138 , V_105 ,
V_288 , V_289 ) ;
if ( V_286 ) {
F_16 ( V_134 -> V_138 , V_78 ,
V_290 , V_291 ) ;
F_16 ( V_134 -> V_138 , V_105 ,
V_292 , V_293 ) ;
}
if ( V_287 ) {
F_16 ( V_134 -> V_138 , V_78 ,
V_294 , V_295 ) ;
F_16 ( V_134 -> V_138 , V_105 ,
V_296 , V_297 ) ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_298 * V_132 = F_39 ( V_2 ) ;
struct V_133 * V_134 = F_8 ( V_2 ) ;
V_134 -> V_2 = V_2 ;
F_40 ( V_2 , V_281 ) ;
F_12 ( V_2 , V_124 , 0x0301 , 0x0301 ) ;
F_12 ( V_2 , V_94 , 0x0030 , 0x0030 ) ;
F_12 ( V_2 , V_48 , 0xfc00 , 0x0c00 ) ;
switch ( F_14 ( V_2 , V_3 ) & V_299 ) {
case V_300 :
case V_301 :
F_41 ( V_2 ,
V_302 ,
F_4 ( V_302 ) ) ;
F_42 ( V_132 ,
V_303 ,
F_4 ( V_303 ) ) ;
F_43 ( V_132 ,
V_304 ,
F_4 ( V_304 ) ) ;
break;
case V_305 :
F_42 ( V_132 ,
V_306 ,
F_4 ( V_306 ) ) ;
F_43 ( V_132 ,
V_307 ,
F_4 ( V_307 ) ) ;
break;
default:
F_11 ( V_2 -> V_5 ,
L_13 ) ;
return - V_308 ;
}
if ( V_134 -> V_309 . V_310 )
F_37 ( V_2 , V_134 -> V_309 . V_286 ,
V_134 -> V_309 . V_287 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = F_8 ( V_2 ) ;
F_40 ( V_2 , V_281 ) ;
F_1 ( V_2 ) ;
F_46 ( V_134 -> V_138 , true ) ;
F_47 ( V_134 -> V_138 ) ;
if ( F_48 ( V_134 -> V_309 . V_311 ) )
F_49 ( V_134 -> V_309 . V_311 , 0 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = F_8 ( V_2 ) ;
if ( F_48 ( V_134 -> V_309 . V_311 ) ) {
F_49 ( V_134 -> V_309 . V_311 , 1 ) ;
F_51 ( 400 ) ;
}
F_46 ( V_134 -> V_138 , false ) ;
F_52 ( V_134 -> V_138 ) ;
return 0 ;
}
static int F_53 ( struct V_133 * V_134 , struct V_312 * V_313 )
{
V_134 -> V_309 . V_314 = F_54 ( V_313 ,
L_14 ) ;
V_134 -> V_309 . V_315 = F_54 ( V_313 ,
L_15 ) ;
V_134 -> V_309 . V_311 = F_55 ( V_313 ,
L_16 , 0 ) ;
if ( ! F_48 ( V_134 -> V_309 . V_311 ) &&
( V_134 -> V_309 . V_311 != - V_316 ) )
return V_134 -> V_309 . V_311 ;
return 0 ;
}
static int F_56 ( struct V_317 * V_318 ,
const struct V_319 * V_214 )
{
struct V_320 * V_309 = F_57 ( & V_318 -> V_5 ) ;
struct V_133 * V_134 ;
int V_184 ;
unsigned int V_144 ;
V_134 = F_58 ( & V_318 -> V_5 ,
sizeof( struct V_133 ) ,
V_321 ) ;
if ( NULL == V_134 )
return - V_322 ;
F_59 ( V_318 , V_134 ) ;
if ( V_309 ) {
V_134 -> V_309 = * V_309 ;
if ( ! V_134 -> V_309 . V_311 )
V_134 -> V_309 . V_311 = - V_185 ;
} else if ( V_318 -> V_5 . V_323 ) {
V_184 = F_53 ( V_134 , V_318 -> V_5 . V_323 ) ;
if ( V_184 )
return V_184 ;
} else
V_134 -> V_309 . V_311 = - V_185 ;
V_134 -> V_138 = F_60 ( V_318 , & V_324 ) ;
if ( F_61 ( V_134 -> V_138 ) ) {
V_184 = F_62 ( V_134 -> V_138 ) ;
F_11 ( & V_318 -> V_5 , L_17 ,
V_184 ) ;
return V_184 ;
}
if ( F_48 ( V_134 -> V_309 . V_311 ) ) {
V_184 = F_63 ( & V_318 -> V_5 , V_134 -> V_309 . V_311 ,
V_325 ,
L_18 ) ;
if ( V_184 < 0 ) {
F_11 ( & V_318 -> V_5 , L_19 ,
V_134 -> V_309 . V_311 , V_184 ) ;
return V_184 ;
}
F_51 ( 400 ) ;
}
F_64 ( V_134 -> V_138 , V_27 , & V_144 ) ;
if ( V_144 != V_326 ) {
F_11 ( & V_318 -> V_5 ,
L_20 , V_144 ) ;
return - V_308 ;
}
F_17 ( V_134 -> V_138 , V_3 , 0 ) ;
V_184 = F_65 ( V_134 -> V_138 , V_327 ,
F_4 ( V_327 ) ) ;
if ( V_184 != 0 )
F_66 ( & V_318 -> V_5 , L_21 , V_184 ) ;
if ( V_134 -> V_309 . V_314 )
F_16 ( V_134 -> V_138 , V_32 ,
V_328 , V_328 ) ;
if ( V_134 -> V_309 . V_315 )
F_16 ( V_134 -> V_138 , V_33 ,
V_329 , V_329 ) ;
V_134 -> V_178 = 1 ;
return F_67 ( & V_318 -> V_5 , & V_330 ,
V_331 , F_4 ( V_331 ) ) ;
}
static int F_68 ( struct V_317 * V_318 )
{
F_69 ( & V_318 -> V_5 ) ;
return 0 ;
}
