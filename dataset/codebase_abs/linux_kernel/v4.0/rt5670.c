static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
if ( ( V_3 >= V_5 [ V_4 ] . V_6 &&
V_3 <= V_5 [ V_4 ] . V_6 +
V_5 [ V_4 ] . V_7 ) ||
( V_3 >= V_5 [ V_4 ] . V_8 &&
V_3 <= V_5 [ V_4 ] . V_9 ) ) {
return true ;
}
}
switch ( V_3 ) {
case V_10 :
case V_11 :
case V_12 :
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
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
return true ;
default:
return false ;
}
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
if ( ( V_3 >= V_5 [ V_4 ] . V_6 &&
V_3 <= V_5 [ V_4 ] . V_6 +
V_5 [ V_4 ] . V_7 ) ||
( V_3 >= V_5 [ V_4 ] . V_8 &&
V_3 <= V_5 [ V_4 ] . V_9 ) ) {
return true ;
}
}
switch ( V_3 ) {
case V_10 :
case V_36 :
case V_37 :
case V_16 :
case V_17 :
case V_18 :
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
case V_11 :
case V_60 :
case V_61 :
case V_12 :
case V_62 :
case V_63 :
case V_13 :
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
case V_14 :
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
case V_15 :
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
case V_19 :
case V_20 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_21 :
case V_22 :
case V_116 :
case V_23 :
case V_117 :
case V_118 :
case V_119 :
case V_24 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_25 :
case V_26 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_27 :
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
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_148 :
case V_149 :
case V_33 :
case V_34 :
case V_35 :
return true ;
default:
return false ;
}
}
static int F_4 ( struct V_150 * V_151 ,
struct V_152 * V_153 , int V_154 )
{
struct V_155 * V_156 = F_5 ( V_151 -> V_157 ) ;
struct V_158 * V_159 = F_6 ( V_156 ) ;
int V_160 = - V_161 ;
V_160 = F_7 ( V_159 -> V_162 ) ;
if ( V_160 < 0 )
F_8 ( V_156 -> V_2 , L_1 ) ;
else
F_9 ( V_156 , V_86 ,
V_163 , V_160 << V_164 ) ;
return V_160 ;
}
static int F_10 ( struct V_150 * V_165 ,
struct V_150 * V_166 )
{
struct V_155 * V_156 = F_5 ( V_165 -> V_157 ) ;
unsigned int V_167 ;
V_167 = F_11 ( V_156 , V_92 ) ;
V_167 &= V_168 ;
if ( V_167 == V_169 )
return 1 ;
else
return 0 ;
}
static int F_12 ( struct V_150 * V_165 ,
struct V_150 * V_166 )
{
struct V_155 * V_156 = F_5 ( V_165 -> V_157 ) ;
unsigned int V_3 , V_170 , V_167 ;
switch ( V_165 -> V_170 ) {
case 0 :
V_3 = V_97 ;
V_170 = 0 ;
break;
case 1 :
V_3 = V_97 ;
V_170 = 4 ;
break;
case 2 :
V_3 = V_15 ;
V_170 = 12 ;
break;
case 3 :
V_3 = V_96 ;
V_170 = 0 ;
break;
case 8 :
V_3 = V_96 ;
V_170 = 4 ;
break;
case 9 :
V_3 = V_96 ;
V_170 = 8 ;
break;
case 10 :
V_3 = V_96 ;
V_170 = 12 ;
break;
default:
return 0 ;
}
V_167 = ( F_11 ( V_156 , V_3 ) >> V_170 ) & 0xf ;
switch ( V_167 ) {
case 1 :
case 2 :
case 3 :
case 4 :
return 1 ;
default:
return 0 ;
}
}
static int F_13 ( struct V_150 * V_165 ,
struct V_150 * V_166 )
{
struct V_155 * V_156 = F_5 ( V_165 -> V_157 ) ;
struct V_158 * V_159 = F_6 ( V_156 ) ;
if ( V_159 -> V_162 > V_159 -> V_171 [ V_172 ] * 384 )
return 1 ;
return 0 ;
}
int F_14 ( struct V_155 * V_156 ,
unsigned int V_173 , unsigned int V_174 )
{
unsigned int V_175 = 0 , V_176 = 0 ;
unsigned int V_177 = 0 , V_178 = 0 ;
if ( V_174 > V_179 )
return - V_161 ;
if ( V_173 & V_180 ) {
V_175 |= V_181 ;
V_176 = ( V_176 & ~ V_181 )
| ( V_174 << V_182 ) ;
}
if ( V_173 & V_183 ) {
V_175 |= V_184 ;
V_176 = ( V_176 & ~ V_184 )
| ( V_174 << V_185 ) ;
}
if ( V_173 & V_186 ) {
V_175 |= V_187 ;
V_176 = ( V_176 & ~ V_187 )
| ( V_174 << V_188 ) ;
}
if ( V_173 & V_189 ) {
V_175 |= V_190 ;
V_176 = ( V_176 & ~ V_190 )
| ( V_174 << V_191 ) ;
}
if ( V_173 & V_192 ) {
V_177 |= V_193 ;
V_178 = ( V_178 & ~ V_193 )
| ( V_174 << V_194 ) ;
}
if ( V_173 & V_195 ) {
V_177 |= V_196 ;
V_178 = ( V_178 & ~ V_196 )
| ( V_174 << V_197 ) ;
}
if ( V_173 & V_198 ) {
V_177 |= V_199 ;
V_178 = ( V_178 & ~ V_199 )
| ( V_174 << V_200 ) ;
}
if ( V_173 & V_201 ) {
V_177 |= V_202 ;
V_178 = ( V_178 & ~ V_202 )
| ( V_174 << V_203 ) ;
}
if ( V_175 )
F_9 ( V_156 , V_96 ,
V_175 , V_176 ) ;
if ( V_177 )
F_9 ( V_156 , V_97 ,
V_177 , V_178 ) ;
return 0 ;
}
static int F_15 ( struct V_150 * V_151 ,
struct V_152 * V_153 , int V_154 )
{
struct V_155 * V_156 = F_5 ( V_151 -> V_157 ) ;
struct V_158 * V_159 = F_6 ( V_156 ) ;
switch ( V_154 ) {
case V_204 :
F_16 ( V_159 -> V_205 , V_110 ,
V_206 , V_207 ) ;
F_16 ( V_159 -> V_205 , V_148 ,
0x0400 , 0x0400 ) ;
F_16 ( V_159 -> V_205 , V_75 ,
V_208 | V_209 |
V_210 , V_208 |
V_209 | V_210 ) ;
F_17 ( V_159 -> V_205 , V_108 , 0x3100 ) ;
F_17 ( V_159 -> V_205 , V_107 , 0x8009 ) ;
F_17 ( V_159 -> V_205 , V_211 +
V_212 , 0x9f00 ) ;
F_18 ( 20 ) ;
F_17 ( V_159 -> V_205 , V_107 , 0x8019 ) ;
break;
case V_213 :
F_17 ( V_159 -> V_205 , V_107 , 0x0004 ) ;
F_19 ( 30 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_20 ( struct V_150 * V_151 ,
struct V_152 * V_153 , int V_154 )
{
struct V_155 * V_156 = F_5 ( V_151 -> V_157 ) ;
struct V_158 * V_159 = F_6 ( V_156 ) ;
switch ( V_154 ) {
case V_204 :
F_17 ( V_159 -> V_205 , V_211 +
V_214 , 0xb400 ) ;
F_17 ( V_159 -> V_205 , V_109 , 0x0772 ) ;
F_17 ( V_159 -> V_205 , V_107 , 0x805d ) ;
F_17 ( V_159 -> V_205 , V_107 , 0x831d ) ;
F_16 ( V_159 -> V_205 , V_148 ,
0x0300 , 0x0300 ) ;
F_16 ( V_159 -> V_205 , V_36 ,
V_215 | V_216 , 0 ) ;
F_19 ( 80 ) ;
F_17 ( V_159 -> V_205 , V_107 , 0x8019 ) ;
break;
case V_213 :
F_17 ( V_159 -> V_205 , V_211 +
V_214 , 0xb400 ) ;
F_17 ( V_159 -> V_205 , V_109 , 0x0772 ) ;
F_17 ( V_159 -> V_205 , V_107 , 0x803d ) ;
F_18 ( 10 ) ;
F_17 ( V_159 -> V_205 , V_107 , 0x831d ) ;
F_18 ( 10 ) ;
F_16 ( V_159 -> V_205 , V_36 ,
V_215 | V_216 ,
V_215 | V_216 ) ;
F_19 ( 20 ) ;
F_16 ( V_159 -> V_205 ,
V_148 , 0x0300 , 0x0 ) ;
F_17 ( V_159 -> V_205 , V_107 , 0x8019 ) ;
F_17 ( V_159 -> V_205 , V_109 , 0x0707 ) ;
F_17 ( V_159 -> V_205 , V_211 +
V_214 , 0xfc00 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_21 ( struct V_150 * V_151 ,
struct V_152 * V_153 , int V_154 )
{
struct V_155 * V_156 = F_5 ( V_151 -> V_157 ) ;
switch ( V_154 ) {
case V_204 :
F_9 ( V_156 , V_76 ,
V_217 , V_217 ) ;
break;
case V_213 :
F_9 ( V_156 , V_76 ,
V_217 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_22 ( struct V_150 * V_151 ,
struct V_152 * V_153 , int V_154 )
{
struct V_155 * V_156 = F_5 ( V_151 -> V_157 ) ;
switch ( V_154 ) {
case V_204 :
F_9 ( V_156 , V_76 ,
V_218 , V_218 ) ;
break;
case V_213 :
F_9 ( V_156 , V_76 ,
V_218 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_23 ( struct V_219 * V_220 ,
struct V_221 * V_222 , struct V_223 * V_224 )
{
struct V_155 * V_156 = V_224 -> V_156 ;
struct V_158 * V_159 = F_6 ( V_156 ) ;
unsigned int V_225 = 0 , V_226 , V_227 ;
int V_228 , V_229 , V_230 ;
V_159 -> V_171 [ V_224 -> V_231 ] = F_24 ( V_222 ) ;
V_228 = F_25 ( V_159 -> V_162 , V_159 -> V_171 [ V_224 -> V_231 ] ) ;
if ( V_228 < 0 ) {
F_8 ( V_156 -> V_2 , L_2 ,
V_159 -> V_171 [ V_224 -> V_231 ] , V_224 -> V_231 ) ;
return - V_161 ;
}
V_230 = F_26 ( V_222 ) ;
if ( V_230 < 0 ) {
F_8 ( V_156 -> V_2 , L_3 , V_230 ) ;
return - V_161 ;
}
V_229 = V_230 > 32 ;
V_159 -> V_232 [ V_224 -> V_231 ] = V_159 -> V_171 [ V_224 -> V_231 ] * ( 32 << V_229 ) ;
F_27 ( V_224 -> V_2 , L_4 ,
V_159 -> V_232 [ V_224 -> V_231 ] , V_159 -> V_171 [ V_224 -> V_231 ] ) ;
F_27 ( V_224 -> V_2 , L_5 ,
V_229 , V_228 , V_224 -> V_231 ) ;
switch ( F_28 ( V_222 ) ) {
case 16 :
break;
case 20 :
V_225 |= V_233 ;
break;
case 24 :
V_225 |= V_234 ;
break;
case 8 :
V_225 |= V_235 ;
break;
default:
return - V_161 ;
}
switch ( V_224 -> V_231 ) {
case V_172 :
V_227 = V_236 | V_237 ;
V_226 = V_229 << V_238 |
V_228 << V_239 ;
F_9 ( V_156 , V_81 ,
V_240 , V_225 ) ;
F_9 ( V_156 , V_84 , V_227 , V_226 ) ;
break;
case V_241 :
V_227 = V_242 | V_243 ;
V_226 = V_229 << V_244 |
V_228 << V_245 ;
F_9 ( V_156 , V_82 ,
V_240 , V_225 ) ;
F_9 ( V_156 , V_84 , V_227 , V_226 ) ;
break;
default:
F_8 ( V_156 -> V_2 , L_6 , V_224 -> V_231 ) ;
return - V_161 ;
}
return 0 ;
}
static int F_29 ( struct V_223 * V_224 , unsigned int V_246 )
{
struct V_155 * V_156 = V_224 -> V_156 ;
struct V_158 * V_159 = F_6 ( V_156 ) ;
unsigned int V_247 = 0 ;
switch ( V_246 & V_248 ) {
case V_249 :
V_159 -> V_250 [ V_224 -> V_231 ] = 1 ;
break;
case V_251 :
V_247 |= V_252 ;
V_159 -> V_250 [ V_224 -> V_231 ] = 0 ;
break;
default:
return - V_161 ;
}
switch ( V_246 & V_253 ) {
case V_254 :
break;
case V_255 :
V_247 |= V_256 ;
break;
default:
return - V_161 ;
}
switch ( V_246 & V_257 ) {
case V_258 :
break;
case V_259 :
V_247 |= V_260 ;
break;
case V_261 :
V_247 |= V_262 ;
break;
case V_263 :
V_247 |= V_264 ;
break;
default:
return - V_161 ;
}
switch ( V_224 -> V_231 ) {
case V_172 :
F_9 ( V_156 , V_81 ,
V_265 | V_266 |
V_267 , V_247 ) ;
break;
case V_241 :
F_9 ( V_156 , V_82 ,
V_265 | V_266 |
V_267 , V_247 ) ;
break;
default:
F_8 ( V_156 -> V_2 , L_6 , V_224 -> V_231 ) ;
return - V_161 ;
}
return 0 ;
}
static int F_30 ( struct V_223 * V_224 ,
int V_268 , unsigned int V_269 , int V_270 )
{
struct V_155 * V_156 = V_224 -> V_156 ;
struct V_158 * V_159 = F_6 ( V_156 ) ;
unsigned int V_247 = 0 ;
if ( V_269 == V_159 -> V_162 && V_268 == V_159 -> V_271 )
return 0 ;
if ( V_159 -> V_272 . V_273 ) {
if ( V_268 == V_274 )
F_31 ( & V_156 -> V_157 , L_7 ) ;
else
F_32 ( & V_156 -> V_157 , L_7 ) ;
F_33 ( & V_156 -> V_157 ) ;
}
switch ( V_268 ) {
case V_275 :
V_247 |= V_276 ;
break;
case V_274 :
V_247 |= V_169 ;
break;
case V_277 :
V_247 |= V_278 ;
break;
default:
F_8 ( V_156 -> V_2 , L_8 , V_268 ) ;
return - V_161 ;
}
F_9 ( V_156 , V_92 ,
V_168 , V_247 ) ;
V_159 -> V_162 = V_269 ;
V_159 -> V_271 = V_268 ;
F_27 ( V_224 -> V_2 , L_9 , V_269 , V_268 ) ;
return 0 ;
}
static int F_34 ( struct V_223 * V_224 , int V_279 , int V_165 ,
unsigned int V_280 , unsigned int V_281 )
{
struct V_155 * V_156 = V_224 -> V_156 ;
struct V_158 * V_159 = F_6 ( V_156 ) ;
struct V_282 V_283 ;
int V_284 ;
if ( V_165 == V_159 -> V_285 && V_280 == V_159 -> V_286 &&
V_281 == V_159 -> V_287 )
return 0 ;
if ( ! V_280 || ! V_281 ) {
F_27 ( V_156 -> V_2 , L_10 ) ;
V_159 -> V_286 = 0 ;
V_159 -> V_287 = 0 ;
F_9 ( V_156 , V_92 ,
V_168 , V_276 ) ;
return 0 ;
}
switch ( V_165 ) {
case V_288 :
F_9 ( V_156 , V_92 ,
V_289 , V_290 ) ;
break;
case V_291 :
case V_292 :
case V_293 :
case V_294 :
switch ( V_224 -> V_231 ) {
case V_172 :
F_9 ( V_156 , V_92 ,
V_289 , V_295 ) ;
break;
case V_241 :
F_9 ( V_156 , V_92 ,
V_289 , V_296 ) ;
break;
default:
F_8 ( V_156 -> V_2 , L_6 , V_224 -> V_231 ) ;
return - V_161 ;
}
break;
default:
F_8 ( V_156 -> V_2 , L_11 , V_165 ) ;
return - V_161 ;
}
V_284 = F_35 ( V_280 , V_281 , & V_283 ) ;
if ( V_284 < 0 ) {
F_8 ( V_156 -> V_2 , L_12 , V_280 ) ;
return V_284 ;
}
F_27 ( V_156 -> V_2 , L_13 ,
V_283 . V_297 , ( V_283 . V_297 ? 0 : V_283 . V_298 ) ,
V_283 . V_299 , V_283 . V_300 ) ;
F_36 ( V_156 , V_93 ,
V_283 . V_299 << V_301 | V_283 . V_300 ) ;
F_36 ( V_156 , V_94 ,
( V_283 . V_297 ? 0 : V_283 . V_298 ) << V_302 |
V_283 . V_297 << V_303 ) ;
V_159 -> V_286 = V_280 ;
V_159 -> V_287 = V_281 ;
V_159 -> V_285 = V_165 ;
return 0 ;
}
static int F_37 ( struct V_223 * V_224 , unsigned int V_304 ,
unsigned int V_305 , int V_306 , int V_307 )
{
struct V_155 * V_156 = V_224 -> V_156 ;
unsigned int V_167 = 0 ;
if ( V_305 || V_304 )
V_167 |= ( 1 << 14 ) ;
switch ( V_306 ) {
case 4 :
V_167 |= ( 1 << 12 ) ;
break;
case 6 :
V_167 |= ( 2 << 12 ) ;
break;
case 8 :
V_167 |= ( 3 << 12 ) ;
break;
case 2 :
break;
default:
return - V_161 ;
}
switch ( V_307 ) {
case 20 :
V_167 |= ( 1 << 10 ) ;
break;
case 24 :
V_167 |= ( 2 << 10 ) ;
break;
case 32 :
V_167 |= ( 3 << 10 ) ;
break;
case 16 :
break;
default:
return - V_161 ;
}
F_9 ( V_156 , V_88 , 0x7c00 , V_167 ) ;
return 0 ;
}
static int F_38 ( struct V_155 * V_156 ,
enum V_308 V_309 )
{
struct V_158 * V_159 = F_6 ( V_156 ) ;
switch ( V_309 ) {
case V_310 :
if ( V_311 == V_156 -> V_157 . V_312 ) {
F_9 ( V_156 , V_75 ,
V_313 | V_314 |
V_315 | V_316 ,
V_313 | V_314 |
V_315 | V_316 ) ;
F_18 ( 10 ) ;
F_9 ( V_156 , V_75 ,
V_209 | V_210 ,
V_209 | V_210 ) ;
F_9 ( V_156 , V_110 ,
V_317 | V_318 ,
V_319 | V_320 ) ;
F_9 ( V_156 , V_147 , 0x1 , 0x1 ) ;
F_9 ( V_156 , V_75 ,
V_321 , 0x3 ) ;
}
break;
case V_311 :
F_9 ( V_156 , V_75 ,
V_313 | V_316 |
V_209 | V_210 , 0 ) ;
F_9 ( V_156 , V_75 ,
V_321 , 0x1 ) ;
break;
case V_322 :
if ( V_159 -> V_272 . V_273 )
F_9 ( V_156 , V_75 ,
V_313 | V_314 |
V_315 | V_316 |
V_209 | V_210 ,
V_314 | V_315 ) ;
else
F_9 ( V_156 , V_75 ,
V_313 | V_314 |
V_315 | V_316 |
V_209 | V_210 , 0 ) ;
F_9 ( V_156 , V_147 , 0x1 , 0x0 ) ;
break;
default:
break;
}
V_156 -> V_157 . V_312 = V_309 ;
return 0 ;
}
static int F_39 ( struct V_155 * V_156 )
{
struct V_158 * V_159 = F_6 ( V_156 ) ;
switch ( F_11 ( V_156 , V_10 ) & V_323 ) {
case V_324 :
case V_325 :
F_40 ( & V_156 -> V_157 ,
V_326 ,
F_2 ( V_326 ) ) ;
F_41 ( & V_156 -> V_157 ,
V_327 ,
F_2 ( V_327 ) ) ;
break;
case V_328 :
F_40 ( & V_156 -> V_157 ,
V_329 ,
F_2 ( V_329 ) ) ;
F_41 ( & V_156 -> V_157 ,
V_330 ,
F_2 ( V_330 ) ) ;
break;
default:
F_8 ( V_156 -> V_2 ,
L_14 ) ;
return - V_331 ;
}
V_159 -> V_156 = V_156 ;
return 0 ;
}
static int F_42 ( struct V_155 * V_156 )
{
struct V_158 * V_159 = F_6 ( V_156 ) ;
F_17 ( V_159 -> V_205 , V_10 , 0 ) ;
return 0 ;
}
static int F_43 ( struct V_155 * V_156 )
{
struct V_158 * V_159 = F_6 ( V_156 ) ;
F_44 ( V_159 -> V_205 , true ) ;
F_45 ( V_159 -> V_205 ) ;
return 0 ;
}
static int F_46 ( struct V_155 * V_156 )
{
struct V_158 * V_159 = F_6 ( V_156 ) ;
F_44 ( V_159 -> V_205 , false ) ;
F_47 ( V_159 -> V_205 ) ;
return 0 ;
}
static int F_48 ( struct V_332 * V_333 ,
const struct V_334 * V_231 )
{
struct V_335 * V_272 = F_49 ( & V_333 -> V_2 ) ;
struct V_158 * V_159 ;
int V_284 ;
unsigned int V_167 ;
V_159 = F_50 ( & V_333 -> V_2 ,
sizeof( struct V_158 ) ,
V_336 ) ;
if ( NULL == V_159 )
return - V_337 ;
F_51 ( V_333 , V_159 ) ;
if ( V_272 )
V_159 -> V_272 = * V_272 ;
if ( F_52 ( V_338 ) ) {
V_159 -> V_272 . V_339 = true ;
V_159 -> V_272 . V_340 = V_341 ;
V_159 -> V_272 . V_273 = 1 ;
}
V_159 -> V_205 = F_53 ( V_333 , & V_342 ) ;
if ( F_54 ( V_159 -> V_205 ) ) {
V_284 = F_55 ( V_159 -> V_205 ) ;
F_8 ( & V_333 -> V_2 , L_15 ,
V_284 ) ;
return V_284 ;
}
F_56 ( V_159 -> V_205 , V_35 , & V_167 ) ;
if ( V_167 != V_343 ) {
F_8 ( & V_333 -> V_2 ,
L_16 , V_167 ) ;
return - V_331 ;
}
F_17 ( V_159 -> V_205 , V_10 , 0 ) ;
F_16 ( V_159 -> V_205 , V_75 ,
V_344 | V_345 |
V_316 , V_316 ) ;
F_19 ( 100 ) ;
F_17 ( V_159 -> V_205 , V_10 , 0 ) ;
F_56 ( V_159 -> V_205 , V_33 , & V_167 ) ;
if ( V_167 >= 4 )
F_17 ( V_159 -> V_205 , V_126 , 0x0980 ) ;
else
F_17 ( V_159 -> V_205 , V_126 , 0x0d00 ) ;
V_284 = F_57 ( V_159 -> V_205 , V_346 ,
F_2 ( V_346 ) ) ;
if ( V_284 != 0 )
F_58 ( & V_333 -> V_2 , L_17 , V_284 ) ;
if ( V_159 -> V_272 . V_347 )
F_16 ( V_159 -> V_205 , V_38 ,
V_348 , V_348 ) ;
if ( V_333 -> V_349 ) {
F_16 ( V_159 -> V_205 , V_124 ,
V_350 , V_351 ) ;
F_16 ( V_159 -> V_205 , V_125 ,
V_352 , V_353 ) ;
}
if ( V_159 -> V_272 . V_273 ) {
F_16 ( V_159 -> V_205 , V_92 ,
V_168 , V_278 ) ;
V_159 -> V_162 = 0 ;
V_159 -> V_271 = V_277 ;
F_16 ( V_159 -> V_205 , V_75 ,
V_314 , V_314 ) ;
F_16 ( V_159 -> V_205 , V_76 ,
V_354 , V_354 ) ;
F_16 ( V_159 -> V_205 , V_123 ,
V_355 , V_356 ) ;
F_16 ( V_159 -> V_205 , V_145 ,
V_357 |
V_358 ,
V_359 | V_360 ) ;
switch ( V_159 -> V_272 . V_273 ) {
case 1 :
F_16 ( V_159 -> V_205 , V_19 ,
V_361 ,
V_362 ) ;
break;
case 2 :
F_16 ( V_159 -> V_205 , V_19 ,
V_361 ,
V_363 ) ;
break;
case 3 :
F_16 ( V_159 -> V_205 , V_19 ,
V_361 ,
V_364 ) ;
break;
default:
break;
}
}
if ( V_159 -> V_272 . V_339 ) {
F_16 ( V_159 -> V_205 , V_124 ,
V_365 ,
V_366 ) ;
switch ( V_159 -> V_272 . V_340 ) {
case V_341 :
F_16 ( V_159 -> V_205 , V_86 ,
V_367 ,
V_368 ) ;
break;
case V_369 :
F_16 ( V_159 -> V_205 , V_86 ,
V_367 ,
V_370 ) ;
F_16 ( V_159 -> V_205 , V_124 ,
V_371 ,
V_372 ) ;
break;
case V_373 :
F_16 ( V_159 -> V_205 , V_86 ,
V_367 ,
V_374 ) ;
F_16 ( V_159 -> V_205 , V_124 ,
V_375 ,
V_376 ) ;
break;
default:
break;
}
switch ( V_159 -> V_272 . V_377 ) {
case V_378 :
F_16 ( V_159 -> V_205 , V_86 ,
V_379 ,
V_380 ) ;
break;
case V_381 :
F_16 ( V_159 -> V_205 , V_86 ,
V_379 ,
V_382 ) ;
F_16 ( V_159 -> V_205 , V_124 ,
V_383 ,
V_384 ) ;
break;
default:
break;
}
switch ( V_159 -> V_272 . V_385 ) {
case V_386 :
F_16 ( V_159 -> V_205 , V_87 ,
V_387 ,
V_388 ) ;
F_16 ( V_159 -> V_205 , V_124 ,
V_389 ,
V_390 ) ;
break;
case V_391 :
case V_392 :
F_8 ( & V_333 -> V_2 ,
L_18 ) ;
break;
default:
break;
}
}
F_59 ( & V_333 -> V_2 ) ;
F_60 ( & V_333 -> V_2 ) ;
V_284 = F_61 ( & V_333 -> V_2 , & V_393 ,
V_394 , F_2 ( V_394 ) ) ;
if ( V_284 < 0 )
goto V_395;
F_62 ( & V_333 -> V_2 ) ;
return 0 ;
V_395:
F_63 ( & V_333 -> V_2 ) ;
return V_284 ;
}
static int F_64 ( struct V_332 * V_333 )
{
F_63 ( & V_333 -> V_2 ) ;
F_65 ( & V_333 -> V_2 ) ;
return 0 ;
}
