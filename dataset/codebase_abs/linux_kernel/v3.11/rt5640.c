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
struct V_1 * V_2 = V_128 -> V_2 ;
struct V_132 * V_133 = F_7 ( V_2 ) ;
int div [] = { 2 , 3 , 4 , 6 , 8 , 12 } ;
int V_134 = - V_135 , V_7 ;
int V_136 , V_137 , V_138 , V_139 ;
V_136 = V_133 -> V_140 ;
V_137 = 3000000 * 12 ;
for ( V_7 = 0 ; V_7 < F_4 ( div ) ; V_7 ++ ) {
V_138 = div [ V_7 ] * 3000000 ;
if ( V_136 > V_138 )
continue;
V_139 = V_138 - V_136 ;
if ( V_139 < V_137 ) {
V_137 = V_139 ;
V_134 = V_7 ;
}
}
if ( V_134 < 0 )
F_8 ( V_2 -> V_5 , L_1 ) ;
else
F_9 ( V_2 , V_78 , V_141 ,
V_134 << V_142 ) ;
return V_134 ;
}
static int F_10 ( struct V_127 * V_143 ,
struct V_127 * V_144 )
{
unsigned int V_145 ;
V_145 = F_11 ( V_143 -> V_2 , V_79 ) ;
V_145 &= V_146 ;
if ( V_145 == V_147 || V_145 == V_148 )
return 1 ;
else
return 0 ;
}
static int F_12 ( struct V_127 * V_128 ,
struct V_129 * V_130 , int V_131 )
{
struct V_1 * V_2 = V_128 -> V_2 ;
struct V_132 * V_133 = F_7 ( V_2 ) ;
switch ( V_131 ) {
case V_149 :
F_13 ( V_133 -> V_150 , V_68 ,
0x0001 , 0x0001 ) ;
F_13 ( V_133 -> V_150 , V_151 + 0x1c ,
0xf000 , 0xf000 ) ;
break;
case V_152 :
F_13 ( V_133 -> V_150 , V_151 + 0x1c ,
0xf000 , 0x0000 ) ;
F_13 ( V_133 -> V_150 , V_68 ,
0x0001 , 0x0000 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_14 ( struct V_127 * V_128 ,
struct V_129 * V_130 , int V_131 )
{
struct V_1 * V_2 = V_128 -> V_2 ;
switch ( V_131 ) {
case V_153 :
F_9 ( V_2 , V_105 ,
V_154 | V_155 ,
V_156 | V_157 ) ;
F_9 ( V_2 , V_78 ,
V_158 | V_159 |
V_160 ,
V_161 | V_162 |
V_163 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_15 ( struct V_127 * V_128 ,
struct V_129 * V_130 , int V_131 )
{
struct V_1 * V_2 = V_128 -> V_2 ;
switch ( V_131 ) {
case V_153 :
F_9 ( V_2 , V_105 ,
V_154 | V_164 ,
V_156 | V_165 ) ;
F_9 ( V_2 , V_78 ,
V_166 | V_167 |
V_168 ,
V_169 | V_170 |
V_171 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_172 )
{
int V_173 = 0 , V_145 ;
if ( V_2 == NULL )
return - V_135 ;
V_145 = F_11 ( V_2 , V_74 ) ;
V_145 = ( V_145 & V_174 ) >> V_175 ;
switch ( V_172 ) {
case V_176 :
switch ( V_145 ) {
case V_177 :
case V_178 :
V_173 |= V_179 ;
break;
case V_180 :
V_173 |= V_179 ;
case V_181 :
case V_182 :
V_173 |= V_183 ;
break;
}
break;
case V_184 :
switch ( V_145 ) {
case V_185 :
case V_182 :
V_173 |= V_179 ;
break;
case V_186 :
V_173 |= V_179 ;
case V_177 :
case V_187 :
V_173 |= V_183 ;
break;
}
break;
default:
V_173 = - V_135 ;
break;
}
return V_173 ;
}
static int F_17 ( int V_188 , int V_136 )
{
int V_7 , V_189 [] = { 1 , 2 , 3 , 4 , 6 , 8 , 12 , 16 } ;
if ( V_188 <= 0 || V_136 <= 0 )
return - V_135 ;
V_136 = V_136 << 8 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_189 ) ; V_7 ++ )
if ( V_188 == V_136 * V_189 [ V_7 ] )
return V_7 ;
return - V_135 ;
}
static int F_18 ( struct V_190 * V_191 ,
struct V_192 * V_193 , struct V_194 * V_195 )
{
struct V_196 * V_197 = V_191 -> V_198 ;
struct V_1 * V_2 = V_197 -> V_2 ;
struct V_132 * V_133 = F_7 ( V_2 ) ;
unsigned int V_199 = 0 , V_200 , V_201 , V_202 ;
int V_203 , V_204 , V_205 ;
V_133 -> V_206 [ V_195 -> V_207 ] = F_19 ( V_193 ) ;
V_203 = F_17 ( V_133 -> V_140 , V_133 -> V_206 [ V_195 -> V_207 ] ) ;
if ( V_203 < 0 ) {
F_8 ( V_2 -> V_5 , L_2 ) ;
return - V_135 ;
}
V_205 = F_20 ( V_193 ) ;
if ( V_205 < 0 ) {
F_8 ( V_2 -> V_5 , L_3 , V_205 ) ;
return V_205 ;
}
if ( V_205 > 32 )
V_204 = 1 ;
else
V_204 = 0 ;
V_133 -> V_208 [ V_195 -> V_207 ] = V_133 -> V_206 [ V_195 -> V_207 ] * ( 32 << V_204 ) ;
F_21 ( V_195 -> V_5 , L_4 ,
V_133 -> V_208 [ V_195 -> V_207 ] , V_133 -> V_206 [ V_195 -> V_207 ] ) ;
F_21 ( V_195 -> V_5 , L_5 ,
V_204 , V_203 , V_195 -> V_207 ) ;
switch ( F_22 ( V_193 ) ) {
case V_209 :
break;
case V_210 :
V_199 |= V_211 ;
break;
case V_212 :
V_199 |= V_213 ;
break;
case V_214 :
V_199 |= V_215 ;
break;
default:
return - V_135 ;
}
V_202 = F_16 ( V_2 , V_195 -> V_207 ) ;
if ( V_202 < 0 ) {
F_8 ( V_2 -> V_5 , L_6 , V_202 ) ;
return - V_135 ;
}
if ( V_202 & V_179 ) {
V_201 = V_216 | V_217 ;
V_200 = V_204 << V_218 |
V_203 << V_219 ;
F_9 ( V_2 , V_74 ,
V_220 , V_199 ) ;
F_9 ( V_2 , V_76 , V_201 , V_200 ) ;
}
if ( V_202 & V_183 ) {
V_201 = V_221 | V_222 ;
V_200 = V_204 << V_223 |
V_203 << V_224 ;
F_9 ( V_2 , V_75 ,
V_220 , V_199 ) ;
F_9 ( V_2 , V_76 , V_201 , V_200 ) ;
}
return 0 ;
}
static int F_23 ( struct V_194 * V_195 , unsigned int V_225 )
{
struct V_1 * V_2 = V_195 -> V_2 ;
struct V_132 * V_133 = F_7 ( V_2 ) ;
unsigned int V_226 = 0 , V_202 ;
switch ( V_225 & V_227 ) {
case V_228 :
V_133 -> V_229 [ V_195 -> V_207 ] = 1 ;
break;
case V_230 :
V_226 |= V_231 ;
V_133 -> V_229 [ V_195 -> V_207 ] = 0 ;
break;
default:
return - V_135 ;
}
switch ( V_225 & V_232 ) {
case V_233 :
break;
case V_234 :
V_226 |= V_235 ;
break;
default:
return - V_135 ;
}
switch ( V_225 & V_236 ) {
case V_237 :
break;
case V_238 :
V_226 |= V_239 ;
break;
case V_240 :
V_226 |= V_241 ;
break;
case V_242 :
V_226 |= V_243 ;
break;
default:
return - V_135 ;
}
V_202 = F_16 ( V_2 , V_195 -> V_207 ) ;
if ( V_202 < 0 ) {
F_8 ( V_2 -> V_5 , L_6 , V_202 ) ;
return - V_135 ;
}
if ( V_202 & V_179 ) {
F_9 ( V_2 , V_74 ,
V_244 | V_245 |
V_246 , V_226 ) ;
}
if ( V_202 & V_183 ) {
F_9 ( V_2 , V_75 ,
V_244 | V_245 |
V_246 , V_226 ) ;
}
return 0 ;
}
static int F_24 ( struct V_194 * V_195 ,
int V_247 , unsigned int V_248 , int V_249 )
{
struct V_1 * V_2 = V_195 -> V_2 ;
struct V_132 * V_133 = F_7 ( V_2 ) ;
unsigned int V_226 = 0 ;
if ( V_248 == V_133 -> V_140 && V_247 == V_133 -> V_250 )
return 0 ;
switch ( V_247 ) {
case V_251 :
V_226 |= V_252 ;
break;
case V_253 :
V_226 |= V_147 ;
break;
case V_254 :
V_226 |= V_148 ;
break;
case V_255 :
V_226 |= V_256 ;
break;
default:
F_8 ( V_2 -> V_5 , L_7 , V_247 ) ;
return - V_135 ;
}
F_9 ( V_2 , V_79 ,
V_146 , V_226 ) ;
V_133 -> V_140 = V_248 ;
V_133 -> V_250 = V_247 ;
F_21 ( V_195 -> V_5 , L_8 , V_248 , V_247 ) ;
return 0 ;
}
static int F_25 ( const unsigned int V_257 ,
const unsigned int V_258 , struct V_259 * V_260 )
{
int V_261 = V_262 , V_263 = V_264 ;
int V_265 = 0 , V_266 = 0 , V_137 , V_267 , V_268 , V_269 , V_270 ;
int V_271 = abs ( V_258 - V_257 ) ;
bool V_272 = false ;
if ( V_273 < V_257 || V_274 > V_257 )
return - V_135 ;
for ( V_267 = 0 ; V_267 <= V_261 ; V_267 ++ ) {
V_269 = ( V_257 >> 1 ) + ( V_257 >> 2 ) * V_267 ;
if ( V_269 < 0 )
continue;
if ( V_269 == V_258 ) {
V_272 = true ;
V_265 = V_267 ;
goto V_275;
}
for ( V_268 = 0 ; V_268 <= V_263 ; V_268 ++ ) {
V_270 = V_269 / ( V_268 + 2 ) ;
V_137 = abs ( V_270 - V_258 ) ;
if ( V_137 < V_271 ) {
V_265 = V_267 ;
V_266 = V_268 ;
if ( V_137 == 0 )
goto V_275;
V_271 = V_137 ;
}
}
}
F_26 ( L_9 ) ;
V_275:
V_260 -> V_276 = V_272 ;
V_260 -> V_277 = V_266 ;
V_260 -> V_278 = V_265 ;
V_260 -> V_279 = 2 ;
return 0 ;
}
static int F_27 ( struct V_194 * V_195 , int V_280 , int V_143 ,
unsigned int V_257 , unsigned int V_258 )
{
struct V_1 * V_2 = V_195 -> V_2 ;
struct V_132 * V_133 = F_7 ( V_2 ) ;
struct V_259 * V_260 = & V_133 -> V_260 ;
int V_173 , V_202 ;
if ( V_143 == V_133 -> V_281 && V_257 == V_133 -> V_282 &&
V_258 == V_133 -> V_283 )
return 0 ;
if ( ! V_257 || ! V_258 ) {
F_21 ( V_2 -> V_5 , L_10 ) ;
V_133 -> V_282 = 0 ;
V_133 -> V_283 = 0 ;
F_9 ( V_2 , V_79 ,
V_146 , V_252 ) ;
return 0 ;
}
switch ( V_143 ) {
case V_284 :
F_9 ( V_2 , V_79 ,
V_285 , V_286 ) ;
break;
case V_287 :
case V_288 :
V_202 = F_16 ( V_2 , V_195 -> V_207 ) ;
if ( V_202 < 0 ) {
F_8 ( V_2 -> V_5 ,
L_6 , V_202 ) ;
return - V_135 ;
}
if ( V_202 & V_179 ) {
F_9 ( V_2 , V_79 ,
V_285 , V_289 ) ;
}
if ( V_202 & V_183 ) {
F_9 ( V_2 , V_79 ,
V_285 , V_290 ) ;
}
break;
default:
F_8 ( V_2 -> V_5 , L_11 , V_143 ) ;
return - V_135 ;
}
V_173 = F_25 ( V_257 , V_258 , V_260 ) ;
if ( V_173 < 0 ) {
F_8 ( V_2 -> V_5 , L_12 , V_257 ) ;
return V_173 ;
}
F_21 ( V_2 -> V_5 , L_13 , V_260 -> V_276 ,
( V_260 -> V_276 ? 0 : V_260 -> V_277 ) , V_260 -> V_278 ) ;
F_2 ( V_2 , V_80 ,
V_260 -> V_278 << V_291 | V_260 -> V_279 ) ;
F_2 ( V_2 , V_81 ,
( V_260 -> V_276 ? 0 : V_260 -> V_277 ) << V_292 |
V_260 -> V_276 << V_293 ) ;
V_133 -> V_282 = V_257 ;
V_133 -> V_283 = V_258 ;
V_133 -> V_281 = V_143 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
enum V_294 V_295 )
{
struct V_132 * V_133 = F_7 ( V_2 ) ;
switch ( V_295 ) {
case V_296 :
if ( V_297 == V_2 -> V_298 . V_299 ) {
F_29 ( V_133 -> V_150 , false ) ;
F_9 ( V_2 , V_70 ,
V_300 | V_301 |
V_302 | V_303 ,
V_300 | V_301 |
V_302 | V_303 ) ;
F_30 ( 10 ) ;
F_9 ( V_2 , V_70 ,
V_304 | V_305 ,
V_304 | V_305 ) ;
F_31 ( V_133 -> V_150 ) ;
F_9 ( V_2 , V_124 ,
0x0301 , 0x0301 ) ;
F_9 ( V_2 , V_89 ,
0x001d , 0x0019 ) ;
F_9 ( V_2 , V_90 ,
0x2000 , 0x2000 ) ;
F_9 ( V_2 , V_94 ,
0x0030 , 0x0030 ) ;
}
break;
case V_297 :
F_2 ( V_2 , V_89 , 0x0004 ) ;
F_2 ( V_2 , V_90 , 0x1100 ) ;
F_9 ( V_2 , V_124 , 0x1 , 0 ) ;
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
V_2 -> V_298 . V_299 = V_295 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_132 * V_133 = F_7 ( V_2 ) ;
int V_173 ;
V_133 -> V_2 = V_2 ;
V_2 -> V_306 = V_133 -> V_150 ;
V_173 = F_33 ( V_2 , 8 , 16 , V_307 ) ;
if ( V_173 != 0 ) {
F_8 ( V_2 -> V_5 , L_14 , V_173 ) ;
return V_173 ;
}
V_2 -> V_298 . V_308 = 1 ;
F_28 ( V_2 , V_297 ) ;
F_9 ( V_2 , V_124 , 0x0301 , 0x0301 ) ;
F_9 ( V_2 , V_89 , 0x001d , 0x0019 ) ;
F_9 ( V_2 , V_90 , 0x2000 , 0x2000 ) ;
F_9 ( V_2 , V_94 , 0x0030 , 0x0030 ) ;
F_9 ( V_2 , V_48 , 0xfc00 , 0x0c00 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_132 * V_133 = F_7 ( V_2 ) ;
F_28 ( V_2 , V_297 ) ;
F_1 ( V_2 ) ;
F_29 ( V_133 -> V_150 , true ) ;
F_36 ( V_133 -> V_150 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
F_28 ( V_2 , V_296 ) ;
return 0 ;
}
static int F_38 ( struct V_132 * V_133 , struct V_309 * V_310 )
{
V_133 -> V_311 . V_312 = F_39 ( V_310 ,
L_15 ) ;
V_133 -> V_311 . V_313 = F_39 ( V_310 ,
L_16 ) ;
V_133 -> V_311 . V_314 = F_40 ( V_310 ,
L_17 , 0 ) ;
if ( ! F_41 ( V_133 -> V_311 . V_314 ) &&
( V_133 -> V_311 . V_314 != - V_315 ) )
return V_133 -> V_311 . V_314 ;
return 0 ;
}
static int F_42 ( struct V_316 * V_317 ,
const struct V_318 * V_207 )
{
struct V_319 * V_311 = F_43 ( & V_317 -> V_5 ) ;
struct V_132 * V_133 ;
int V_173 ;
unsigned int V_145 ;
V_133 = F_44 ( & V_317 -> V_5 ,
sizeof( struct V_132 ) ,
V_320 ) ;
if ( NULL == V_133 )
return - V_321 ;
F_45 ( V_317 , V_133 ) ;
if ( V_311 ) {
V_133 -> V_311 = * V_311 ;
if ( ! V_133 -> V_311 . V_314 )
V_133 -> V_311 . V_314 = - V_135 ;
} else if ( V_317 -> V_5 . V_322 ) {
V_173 = F_38 ( V_133 , V_317 -> V_5 . V_322 ) ;
if ( V_173 )
return V_173 ;
} else
V_133 -> V_311 . V_314 = - V_135 ;
V_133 -> V_150 = F_46 ( V_317 , & V_323 ) ;
if ( F_47 ( V_133 -> V_150 ) ) {
V_173 = F_48 ( V_133 -> V_150 ) ;
F_8 ( & V_317 -> V_5 , L_18 ,
V_173 ) ;
return V_173 ;
}
if ( F_41 ( V_133 -> V_311 . V_314 ) ) {
V_173 = F_49 ( & V_317 -> V_5 , V_133 -> V_311 . V_314 ,
V_324 ,
L_19 ) ;
if ( V_173 < 0 ) {
F_8 ( & V_317 -> V_5 , L_20 ,
V_133 -> V_311 . V_314 , V_173 ) ;
return V_173 ;
}
F_50 ( 400 ) ;
}
F_51 ( V_133 -> V_150 , V_27 , & V_145 ) ;
if ( ( V_145 != V_325 ) ) {
F_8 ( & V_317 -> V_5 ,
L_21 , V_145 ) ;
return - V_326 ;
}
F_52 ( V_133 -> V_150 , V_3 , 0 ) ;
V_173 = F_53 ( V_133 -> V_150 , V_327 ,
F_4 ( V_327 ) ) ;
if ( V_173 != 0 )
F_54 ( & V_317 -> V_5 , L_22 , V_173 ) ;
if ( V_133 -> V_311 . V_312 )
F_13 ( V_133 -> V_150 , V_32 ,
V_328 , V_328 ) ;
if ( V_133 -> V_311 . V_313 )
F_13 ( V_133 -> V_150 , V_33 ,
V_329 , V_329 ) ;
V_173 = F_55 ( & V_317 -> V_5 , & V_330 ,
V_331 , F_4 ( V_331 ) ) ;
if ( V_173 < 0 )
goto V_332;
return 0 ;
V_332:
return V_173 ;
}
static int F_56 ( struct V_316 * V_317 )
{
F_57 ( & V_317 -> V_5 ) ;
return 0 ;
}
