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
int V_135 = - V_136 ;
V_135 = F_9 ( V_134 -> V_137 ) ;
if ( V_135 < 0 )
F_10 ( V_2 -> V_5 , L_1 ) ;
else
F_11 ( V_2 , V_78 , V_138 ,
V_135 << V_139 ) ;
return V_135 ;
}
static int F_12 ( struct V_127 * V_140 ,
struct V_127 * V_141 )
{
struct V_1 * V_2 = F_7 ( V_140 -> V_132 ) ;
unsigned int V_142 ;
V_142 = F_13 ( V_2 , V_79 ) ;
V_142 &= V_143 ;
if ( V_142 == V_144 )
return 1 ;
else
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = F_8 ( V_2 ) ;
F_15 ( V_134 -> V_145 , V_146 +
V_147 , 0x0700 , 0x0200 ) ;
F_15 ( V_134 -> V_145 , V_90 ,
V_148 , V_149 ) ;
F_15 ( V_134 -> V_145 , V_89 ,
V_150 | V_151 | V_152 ,
V_153 | V_154 | V_155 ) ;
F_16 ( V_134 -> V_145 , V_146 + V_156 ,
0x9f00 ) ;
F_15 ( V_134 -> V_145 , V_70 ,
V_157 | V_158 , 0 ) ;
F_15 ( V_134 -> V_145 , V_70 ,
V_159 ,
V_159 ) ;
F_17 ( 10000 , 15000 ) ;
F_15 ( V_134 -> V_145 , V_70 ,
V_157 | V_158 ,
V_157 | V_158 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = F_8 ( V_2 ) ;
F_15 ( V_134 -> V_145 , V_90 ,
V_148 | V_160 ,
V_161 | V_162 ) ;
F_15 ( V_134 -> V_145 , V_92 ,
V_163 , V_164 ) ;
F_15 ( V_134 -> V_145 , V_91 ,
V_165 | V_166 | V_167 ,
( V_168 << V_169 ) |
( V_170 << V_171 ) |
( V_168 << V_172 ) ) ;
F_16 ( V_134 -> V_145 , V_146 +
V_173 , 0x1c00 ) ;
F_15 ( V_134 -> V_145 , V_89 ,
V_150 | V_151 ,
V_174 | V_175 ) ;
F_15 ( V_134 -> V_145 , V_146 +
V_147 , 0x0700 , 0x0400 ) ;
}
static int F_19 ( struct V_127 * V_128 ,
struct V_129 * V_130 , int V_131 )
{
struct V_1 * V_2 = F_7 ( V_128 -> V_132 ) ;
struct V_133 * V_134 = F_8 ( V_2 ) ;
switch ( V_131 ) {
case V_176 :
F_18 ( V_2 ) ;
V_134 -> V_177 = 0 ;
break;
case V_178 :
V_134 -> V_177 = 1 ;
F_17 ( 70000 , 75000 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_20 ( struct V_127 * V_128 ,
struct V_129 * V_130 , int V_131 )
{
struct V_1 * V_2 = F_7 ( V_128 -> V_132 ) ;
switch ( V_131 ) {
case V_176 :
F_14 ( V_2 ) ;
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
struct V_133 * V_134 = F_8 ( V_2 ) ;
switch ( V_131 ) {
case V_176 :
if ( ! V_134 -> V_177 )
F_17 ( 80000 , 85000 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , int V_179 )
{
int V_180 = 0 , V_142 ;
if ( V_2 == NULL )
return - V_136 ;
V_142 = F_13 ( V_2 , V_74 ) ;
V_142 = ( V_142 & V_181 ) >> V_182 ;
switch ( V_179 ) {
case V_183 :
switch ( V_142 ) {
case V_184 :
case V_185 :
V_180 |= V_186 ;
break;
case V_187 :
V_180 |= V_186 ;
case V_188 :
case V_189 :
V_180 |= V_190 ;
break;
}
break;
case V_191 :
switch ( V_142 ) {
case V_192 :
case V_189 :
V_180 |= V_186 ;
break;
case V_193 :
V_180 |= V_186 ;
case V_184 :
case V_194 :
V_180 |= V_190 ;
break;
}
break;
default:
V_180 = - V_136 ;
break;
}
return V_180 ;
}
static int F_23 ( struct V_195 * V_196 ,
struct V_197 * V_198 , struct V_199 * V_200 )
{
struct V_1 * V_2 = V_200 -> V_2 ;
struct V_133 * V_134 = F_8 ( V_2 ) ;
unsigned int V_201 = 0 , V_202 , V_203 ;
int V_204 , V_205 , V_206 , V_207 ;
V_134 -> V_208 [ V_200 -> V_209 ] = F_24 ( V_198 ) ;
V_205 = F_25 ( V_134 -> V_137 , V_134 -> V_208 [ V_200 -> V_209 ] ) ;
if ( V_205 < 0 ) {
F_10 ( V_2 -> V_5 , L_2 ,
V_134 -> V_208 [ V_200 -> V_209 ] , V_200 -> V_209 ) ;
return - V_136 ;
}
V_207 = F_26 ( V_198 ) ;
if ( V_207 < 0 ) {
F_10 ( V_2 -> V_5 , L_3 , V_207 ) ;
return V_207 ;
}
if ( V_207 > 32 )
V_206 = 1 ;
else
V_206 = 0 ;
V_134 -> V_210 [ V_200 -> V_209 ] = V_134 -> V_208 [ V_200 -> V_209 ] * ( 32 << V_206 ) ;
F_27 ( V_200 -> V_5 , L_4 ,
V_134 -> V_210 [ V_200 -> V_209 ] , V_134 -> V_208 [ V_200 -> V_209 ] ) ;
F_27 ( V_200 -> V_5 , L_5 ,
V_206 , V_205 , V_200 -> V_209 ) ;
switch ( F_28 ( V_198 ) ) {
case 16 :
break;
case 20 :
V_201 |= V_211 ;
break;
case 24 :
V_201 |= V_212 ;
break;
case 8 :
V_201 |= V_213 ;
break;
default:
return - V_136 ;
}
V_204 = F_22 ( V_2 , V_200 -> V_209 ) ;
if ( V_204 < 0 ) {
F_10 ( V_2 -> V_5 , L_6 , V_204 ) ;
return - V_136 ;
}
if ( V_204 & V_186 ) {
V_203 = V_214 | V_215 ;
V_202 = V_206 << V_216 |
V_205 << V_217 ;
F_11 ( V_2 , V_74 ,
V_218 , V_201 ) ;
F_11 ( V_2 , V_76 , V_203 , V_202 ) ;
}
if ( V_204 & V_190 ) {
V_203 = V_219 | V_220 ;
V_202 = V_206 << V_221 |
V_205 << V_222 ;
F_11 ( V_2 , V_75 ,
V_218 , V_201 ) ;
F_11 ( V_2 , V_76 , V_203 , V_202 ) ;
}
return 0 ;
}
static int F_29 ( struct V_199 * V_200 , unsigned int V_223 )
{
struct V_1 * V_2 = V_200 -> V_2 ;
struct V_133 * V_134 = F_8 ( V_2 ) ;
unsigned int V_224 = 0 ;
int V_204 ;
switch ( V_223 & V_225 ) {
case V_226 :
V_134 -> V_227 [ V_200 -> V_209 ] = 1 ;
break;
case V_228 :
V_224 |= V_229 ;
V_134 -> V_227 [ V_200 -> V_209 ] = 0 ;
break;
default:
return - V_136 ;
}
switch ( V_223 & V_230 ) {
case V_231 :
break;
case V_232 :
V_224 |= V_233 ;
break;
default:
return - V_136 ;
}
switch ( V_223 & V_234 ) {
case V_235 :
break;
case V_236 :
V_224 |= V_237 ;
break;
case V_238 :
V_224 |= V_239 ;
break;
case V_240 :
V_224 |= V_241 ;
break;
default:
return - V_136 ;
}
V_204 = F_22 ( V_2 , V_200 -> V_209 ) ;
if ( V_204 < 0 ) {
F_10 ( V_2 -> V_5 , L_6 , V_204 ) ;
return - V_136 ;
}
if ( V_204 & V_186 ) {
F_11 ( V_2 , V_74 ,
V_242 | V_243 |
V_244 , V_224 ) ;
}
if ( V_204 & V_190 ) {
F_11 ( V_2 , V_75 ,
V_242 | V_243 |
V_244 , V_224 ) ;
}
return 0 ;
}
static int F_30 ( struct V_199 * V_200 ,
int V_245 , unsigned int V_246 , int V_247 )
{
struct V_1 * V_2 = V_200 -> V_2 ;
struct V_133 * V_134 = F_8 ( V_2 ) ;
unsigned int V_224 = 0 ;
if ( V_246 == V_134 -> V_137 && V_245 == V_134 -> V_248 )
return 0 ;
switch ( V_245 ) {
case V_249 :
V_224 |= V_250 ;
break;
case V_251 :
V_224 |= V_144 ;
break;
default:
F_10 ( V_2 -> V_5 , L_7 , V_245 ) ;
return - V_136 ;
}
F_11 ( V_2 , V_79 ,
V_143 , V_224 ) ;
V_134 -> V_137 = V_246 ;
V_134 -> V_248 = V_245 ;
F_27 ( V_200 -> V_5 , L_8 , V_246 , V_245 ) ;
return 0 ;
}
static int F_31 ( struct V_199 * V_200 , int V_252 , int V_140 ,
unsigned int V_253 , unsigned int V_254 )
{
struct V_1 * V_2 = V_200 -> V_2 ;
struct V_133 * V_134 = F_8 ( V_2 ) ;
struct V_255 V_256 ;
int V_180 , V_204 ;
if ( V_140 == V_134 -> V_257 && V_253 == V_134 -> V_258 &&
V_254 == V_134 -> V_259 )
return 0 ;
if ( ! V_253 || ! V_254 ) {
F_27 ( V_2 -> V_5 , L_9 ) ;
V_134 -> V_258 = 0 ;
V_134 -> V_259 = 0 ;
F_11 ( V_2 , V_79 ,
V_143 , V_250 ) ;
return 0 ;
}
switch ( V_140 ) {
case V_260 :
F_11 ( V_2 , V_79 ,
V_261 , V_262 ) ;
break;
case V_263 :
case V_264 :
V_204 = F_22 ( V_2 , V_200 -> V_209 ) ;
if ( V_204 < 0 ) {
F_10 ( V_2 -> V_5 ,
L_6 , V_204 ) ;
return - V_136 ;
}
if ( V_204 & V_186 ) {
F_11 ( V_2 , V_79 ,
V_261 , V_265 ) ;
}
if ( V_204 & V_190 ) {
F_11 ( V_2 , V_79 ,
V_261 , V_266 ) ;
}
break;
default:
F_10 ( V_2 -> V_5 , L_10 , V_140 ) ;
return - V_136 ;
}
V_180 = F_32 ( V_253 , V_254 , & V_256 ) ;
if ( V_180 < 0 ) {
F_10 ( V_2 -> V_5 , L_11 , V_253 ) ;
return V_180 ;
}
F_27 ( V_2 -> V_5 , L_12 ,
V_256 . V_267 , ( V_256 . V_267 ? 0 : V_256 . V_268 ) ,
V_256 . V_269 , V_256 . V_270 ) ;
F_2 ( V_2 , V_80 ,
V_256 . V_269 << V_271 | V_256 . V_270 ) ;
F_2 ( V_2 , V_81 ,
( V_256 . V_267 ? 0 : V_256 . V_268 ) << V_272 |
V_256 . V_267 << V_273 ) ;
V_134 -> V_258 = V_253 ;
V_134 -> V_259 = V_254 ;
V_134 -> V_257 = V_140 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
enum V_274 V_275 )
{
switch ( V_275 ) {
case V_276 :
if ( V_277 == V_2 -> V_132 . V_278 ) {
F_11 ( V_2 , V_70 ,
V_279 | V_280 |
V_281 | V_282 ,
V_279 | V_280 |
V_281 | V_282 ) ;
F_17 ( 10000 , 15000 ) ;
F_11 ( V_2 , V_70 ,
V_157 | V_158 ,
V_157 | V_158 ) ;
F_11 ( V_2 , V_124 ,
0x0301 , 0x0301 ) ;
F_11 ( V_2 , V_94 ,
0x0030 , 0x0030 ) ;
}
break;
case V_277 :
F_2 ( V_2 , V_89 , 0x0004 ) ;
F_2 ( V_2 , V_90 , 0x1100 ) ;
F_11 ( V_2 , V_124 , 0x1 , 0 ) ;
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
V_2 -> V_132 . V_278 = V_275 ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 ,
bool V_283 , bool V_284 )
{
struct V_133 * V_134 = F_8 ( V_2 ) ;
F_15 ( V_134 -> V_145 , V_105 ,
V_285 , V_286 ) ;
if ( V_283 ) {
F_15 ( V_134 -> V_145 , V_78 ,
V_287 , V_288 ) ;
F_15 ( V_134 -> V_145 , V_105 ,
V_289 , V_290 ) ;
}
if ( V_284 ) {
F_15 ( V_134 -> V_145 , V_78 ,
V_291 , V_292 ) ;
F_15 ( V_134 -> V_145 , V_105 ,
V_293 , V_294 ) ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = F_8 ( V_2 ) ;
V_134 -> V_2 = V_2 ;
F_33 ( V_2 , V_277 ) ;
F_11 ( V_2 , V_124 , 0x0301 , 0x0301 ) ;
F_11 ( V_2 , V_94 , 0x0030 , 0x0030 ) ;
F_11 ( V_2 , V_48 , 0xfc00 , 0x0c00 ) ;
switch ( F_13 ( V_2 , V_3 ) & V_295 ) {
case V_296 :
case V_297 :
F_36 ( V_2 ,
V_298 ,
F_4 ( V_298 ) ) ;
F_37 ( & V_2 -> V_132 ,
V_299 ,
F_4 ( V_299 ) ) ;
F_38 ( & V_2 -> V_132 ,
V_300 ,
F_4 ( V_300 ) ) ;
break;
case V_301 :
F_37 ( & V_2 -> V_132 ,
V_302 ,
F_4 ( V_302 ) ) ;
F_38 ( & V_2 -> V_132 ,
V_303 ,
F_4 ( V_303 ) ) ;
break;
default:
F_10 ( V_2 -> V_5 ,
L_13 ) ;
return - V_304 ;
}
if ( V_134 -> V_305 . V_306 )
F_34 ( V_2 , V_134 -> V_305 . V_283 ,
V_134 -> V_305 . V_284 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = F_8 ( V_2 ) ;
F_33 ( V_2 , V_277 ) ;
F_1 ( V_2 ) ;
F_41 ( V_134 -> V_145 , true ) ;
F_42 ( V_134 -> V_145 ) ;
if ( F_43 ( V_134 -> V_305 . V_307 ) )
F_44 ( V_134 -> V_305 . V_307 , 0 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = F_8 ( V_2 ) ;
if ( F_43 ( V_134 -> V_305 . V_307 ) ) {
F_44 ( V_134 -> V_305 . V_307 , 1 ) ;
F_46 ( 400 ) ;
}
F_41 ( V_134 -> V_145 , false ) ;
F_47 ( V_134 -> V_145 ) ;
return 0 ;
}
static int F_48 ( struct V_133 * V_134 , struct V_308 * V_309 )
{
V_134 -> V_305 . V_310 = F_49 ( V_309 ,
L_14 ) ;
V_134 -> V_305 . V_311 = F_49 ( V_309 ,
L_15 ) ;
V_134 -> V_305 . V_307 = F_50 ( V_309 ,
L_16 , 0 ) ;
if ( ! F_43 ( V_134 -> V_305 . V_307 ) &&
( V_134 -> V_305 . V_307 != - V_312 ) )
return V_134 -> V_305 . V_307 ;
return 0 ;
}
static int F_51 ( struct V_313 * V_314 ,
const struct V_315 * V_209 )
{
struct V_316 * V_305 = F_52 ( & V_314 -> V_5 ) ;
struct V_133 * V_134 ;
int V_180 ;
unsigned int V_142 ;
V_134 = F_53 ( & V_314 -> V_5 ,
sizeof( struct V_133 ) ,
V_317 ) ;
if ( NULL == V_134 )
return - V_318 ;
F_54 ( V_314 , V_134 ) ;
if ( V_305 ) {
V_134 -> V_305 = * V_305 ;
if ( ! V_134 -> V_305 . V_307 )
V_134 -> V_305 . V_307 = - V_136 ;
} else if ( V_314 -> V_5 . V_319 ) {
V_180 = F_48 ( V_134 , V_314 -> V_5 . V_319 ) ;
if ( V_180 )
return V_180 ;
} else
V_134 -> V_305 . V_307 = - V_136 ;
V_134 -> V_145 = F_55 ( V_314 , & V_320 ) ;
if ( F_56 ( V_134 -> V_145 ) ) {
V_180 = F_57 ( V_134 -> V_145 ) ;
F_10 ( & V_314 -> V_5 , L_17 ,
V_180 ) ;
return V_180 ;
}
if ( F_43 ( V_134 -> V_305 . V_307 ) ) {
V_180 = F_58 ( & V_314 -> V_5 , V_134 -> V_305 . V_307 ,
V_321 ,
L_18 ) ;
if ( V_180 < 0 ) {
F_10 ( & V_314 -> V_5 , L_19 ,
V_134 -> V_305 . V_307 , V_180 ) ;
return V_180 ;
}
F_46 ( 400 ) ;
}
F_59 ( V_134 -> V_145 , V_27 , & V_142 ) ;
if ( V_142 != V_322 ) {
F_10 ( & V_314 -> V_5 ,
L_20 , V_142 ) ;
return - V_304 ;
}
F_16 ( V_134 -> V_145 , V_3 , 0 ) ;
V_180 = F_60 ( V_134 -> V_145 , V_323 ,
F_4 ( V_323 ) ) ;
if ( V_180 != 0 )
F_61 ( & V_314 -> V_5 , L_21 , V_180 ) ;
if ( V_134 -> V_305 . V_310 )
F_15 ( V_134 -> V_145 , V_32 ,
V_324 , V_324 ) ;
if ( V_134 -> V_305 . V_311 )
F_15 ( V_134 -> V_145 , V_33 ,
V_325 , V_325 ) ;
V_134 -> V_177 = 1 ;
return F_62 ( & V_314 -> V_5 , & V_326 ,
V_327 , F_4 ( V_327 ) ) ;
}
static int F_63 ( struct V_313 * V_314 )
{
F_64 ( & V_314 -> V_5 ) ;
return 0 ;
}
