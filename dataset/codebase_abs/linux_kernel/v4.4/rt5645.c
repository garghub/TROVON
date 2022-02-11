static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 , 0 ) ;
}
static bool F_3 ( struct V_4 * V_5 , unsigned int V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_8 ) ; V_7 ++ ) {
if ( V_6 >= V_8 [ V_7 ] . V_9 &&
V_6 <= V_8 [ V_7 ] . V_10 ) {
return true ;
}
}
switch ( V_6 ) {
case V_3 :
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
return true ;
default:
return false ;
}
}
static bool F_5 ( struct V_4 * V_5 , unsigned int V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_8 ) ; V_7 ++ ) {
if ( V_6 >= V_8 [ V_7 ] . V_9 &&
V_6 <= V_8 [ V_7 ] . V_10 ) {
return true ;
}
}
switch ( V_6 ) {
case V_3 :
case V_27 :
case V_28 :
case V_29 :
case V_12 :
case V_13 :
case V_14 :
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
case V_86 :
case V_11 :
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
case V_15 :
case V_109 :
case V_110 :
case V_16 :
case V_111 :
case V_17 :
case V_112 :
case V_18 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_19 :
case V_20 :
case V_21 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_22 :
case V_130 :
case V_131 :
case V_23 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
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
case V_24 :
case V_25 :
case V_26 :
return true ;
default:
return false ;
}
}
static int F_6 ( struct V_147 * V_148 ,
struct V_149 * V_150 )
{
V_150 -> type = V_151 ;
V_150 -> V_152 = V_153 * sizeof( struct V_154 ) ;
return 0 ;
}
static int F_7 ( struct V_147 * V_148 ,
struct V_155 * V_156 )
{
struct V_157 * V_158 = F_8 ( V_148 ) ;
struct V_159 * V_160 = F_9 ( V_158 ) ;
struct V_154 * V_161 =
(struct V_154 * ) V_156 -> V_162 . V_163 . V_164 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_153 ; V_7 ++ ) {
V_161 [ V_7 ] . V_6 = F_10 ( V_160 -> V_161 [ V_7 ] . V_6 ) ;
V_161 [ V_7 ] . V_165 = F_10 ( V_160 -> V_161 [ V_7 ] . V_165 ) ;
}
return 0 ;
}
static bool F_11 ( unsigned short V_6 )
{
if ( ( V_6 >= 0x1a4 && V_6 <= 0x1cd ) | ( V_6 >= 0x1e5 && V_6 <= 0x1f8 ) |
( V_6 == V_112 ) )
return true ;
return false ;
}
static int F_12 ( struct V_147 * V_148 ,
struct V_155 * V_156 )
{
struct V_157 * V_158 = F_8 ( V_148 ) ;
struct V_159 * V_160 = F_9 ( V_158 ) ;
struct V_154 * V_161 =
(struct V_154 * ) V_156 -> V_162 . V_163 . V_164 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_153 ; V_7 ++ ) {
V_161 [ V_7 ] . V_6 = F_13 ( V_161 [ V_7 ] . V_6 ) ;
V_161 [ V_7 ] . V_165 = F_13 ( V_161 [ V_7 ] . V_165 ) ;
}
for ( V_7 = V_153 - 1 ; V_7 >= 0 ; V_7 -- ) {
if ( V_161 [ V_7 ] . V_6 == 0 )
continue;
else if ( V_161 [ V_7 ] . V_6 != V_112 )
return 0 ;
else
break;
}
for ( V_7 = 0 ; V_7 < V_153 ; V_7 ++ ) {
if ( ! F_11 ( V_161 [ V_7 ] . V_6 ) &&
V_161 [ V_7 ] . V_6 != 0 )
return 0 ;
else if ( V_161 [ V_7 ] . V_6 == 0 )
break;
}
memcpy ( V_160 -> V_161 , V_161 ,
V_153 * sizeof( struct V_154 ) ) ;
return 0 ;
}
static int F_14 ( struct V_147 * V_148 ,
struct V_155 * V_156 )
{
struct V_157 * V_158 = F_8 ( V_148 ) ;
struct V_159 * V_160 = F_9 ( V_158 ) ;
int V_166 ;
F_15 ( & V_160 -> V_167 ) ;
F_16 ( V_160 -> V_168 , V_108 ,
V_169 , V_170 ) ;
V_166 = F_17 ( V_148 , V_156 ) ;
F_18 ( V_171 , & V_160 -> V_167 ,
F_19 ( 200 ) ) ;
return V_166 ;
}
static int F_20 ( struct V_172 * V_173 ,
struct V_147 * V_148 , int V_174 )
{
struct V_1 * V_2 = F_21 ( V_173 -> V_175 ) ;
struct V_159 * V_160 = F_22 ( V_2 ) ;
int V_176 , V_177 ;
V_177 = V_160 -> V_178 / F_23 ( V_160 -> V_168 ,
V_89 , V_179 ) ;
V_176 = F_24 ( V_177 ) ;
if ( V_176 < 0 )
F_25 ( V_2 -> V_5 , L_1 ) ;
else
F_26 ( V_2 , V_91 ,
V_180 , V_176 << V_181 ) ;
return V_176 ;
}
static int F_27 ( struct V_172 * V_182 ,
struct V_172 * V_183 )
{
struct V_1 * V_2 = F_21 ( V_182 -> V_175 ) ;
unsigned int V_165 ;
V_165 = F_28 ( V_2 , V_97 ) ;
V_165 &= V_184 ;
if ( V_165 == V_185 )
return 1 ;
else
return 0 ;
}
static int F_29 ( struct V_172 * V_182 ,
struct V_172 * V_183 )
{
struct V_1 * V_2 = F_21 ( V_182 -> V_175 ) ;
unsigned int V_6 , V_186 , V_165 ;
switch ( V_182 -> V_186 ) {
case 0 :
V_6 = V_102 ;
V_186 = 0 ;
break;
case 1 :
V_6 = V_102 ;
V_186 = 4 ;
break;
case 3 :
V_6 = V_101 ;
V_186 = 0 ;
break;
case 8 :
V_6 = V_101 ;
V_186 = 4 ;
break;
case 9 :
V_6 = V_101 ;
V_186 = 8 ;
break;
case 10 :
V_6 = V_101 ;
V_186 = 12 ;
break;
default:
return 0 ;
}
V_165 = ( F_28 ( V_2 , V_6 ) >> V_186 ) & 0xf ;
switch ( V_165 ) {
case 1 :
case 2 :
case 3 :
case 4 :
return 1 ;
default:
return 0 ;
}
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_159 * V_160 = F_22 ( V_2 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_153 ; V_7 ++ ) {
if ( F_11 ( V_160 -> V_161 [ V_7 ] . V_6 ) )
F_31 ( V_160 -> V_168 , V_160 -> V_161 [ V_7 ] . V_6 ,
V_160 -> V_161 [ V_7 ] . V_165 ) ;
else
break;
}
return 0 ;
}
int F_32 ( struct V_1 * V_2 ,
unsigned int V_187 , unsigned int V_188 )
{
unsigned int V_189 = 0 ;
unsigned int V_190 = 0 ;
unsigned int V_191 = 0 ;
unsigned int V_192 = 0 ;
switch ( V_188 ) {
case V_193 :
case V_194 :
case V_195 :
case V_196 :
break;
default:
return - V_197 ;
}
if ( V_187 & V_198 ) {
V_189 |= V_199 ;
V_190 = ( V_190 & ~ V_199 )
| ( V_188 << V_200 ) ;
}
if ( V_187 & V_201 ) {
V_189 |= V_202 ;
V_190 = ( V_190 & ~ V_202 )
| ( V_188 << V_203 ) ;
}
if ( V_187 & V_204 ) {
V_189 |= V_205 ;
V_190 = ( V_190 & ~ V_205 )
| ( V_188 << V_206 ) ;
}
if ( V_187 & V_207 ) {
V_189 |= V_208 ;
V_190 = ( V_190 & ~ V_208 )
| ( V_188 << V_209 ) ;
}
if ( V_187 & V_210 ) {
V_191 |= V_211 ;
V_192 = ( V_192 & ~ V_211 )
| ( V_188 << V_212 ) ;
}
if ( V_187 & V_213 ) {
V_191 |= V_214 ;
V_192 = ( V_192 & ~ V_214 )
| ( V_188 << V_215 ) ;
}
if ( V_189 )
F_26 ( V_2 , V_101 ,
V_189 , V_190 ) ;
if ( V_191 )
F_26 ( V_2 , V_102 ,
V_191 , V_192 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 , int V_216 )
{
static int V_217 ;
struct V_159 * V_160 = F_22 ( V_2 ) ;
if ( V_216 ) {
if ( V_217 <= 0 ) {
if ( V_160 -> V_218 == V_219 ) {
F_2 ( V_2 , V_105 , 0x3100 ) ;
F_2 ( V_2 , V_107 ,
0x0e06 ) ;
F_2 ( V_2 , V_104 , 0x000d ) ;
F_31 ( V_160 -> V_168 , V_220 +
V_221 , 0x9f01 ) ;
F_34 ( 20 ) ;
F_26 ( V_2 , V_104 ,
V_222 , V_223 ) ;
F_31 ( V_160 -> V_168 , V_220 +
0x3e , 0x7400 ) ;
F_2 ( V_2 , V_106 , 0x0737 ) ;
F_31 ( V_160 -> V_168 , V_220 +
V_224 , 0xfc00 ) ;
F_2 ( V_2 , V_105 , 0x1140 ) ;
F_34 ( 70 ) ;
V_160 -> V_225 = true ;
} else {
F_26 ( V_2 , V_105 ,
V_226 , V_227 ) ;
F_2 ( V_2 , V_104 , 0x000d ) ;
F_31 ( V_160 -> V_168 , V_220 +
V_221 , 0x9f01 ) ;
F_35 ( 150 ) ;
F_26 ( V_2 , V_82 ,
V_228 | V_229 , 0 ) ;
F_26 ( V_2 , V_85 ,
V_230 | V_231 ,
V_230 | V_231 ) ;
F_26 ( V_2 , V_82 ,
V_232 | V_233 |
V_234 ,
V_232 | V_233 |
V_234 ) ;
F_35 ( 5 ) ;
F_26 ( V_2 , V_82 ,
V_228 | V_229 ,
V_228 | V_229 ) ;
F_26 ( V_2 , V_104 ,
V_222 | V_235 ,
V_223 | V_236 ) ;
F_31 ( V_160 -> V_168 , V_220 +
0x14 , 0x1aaa ) ;
F_31 ( V_160 -> V_168 , V_220 +
0x24 , 0x0430 ) ;
}
}
V_217 ++ ;
} else {
V_217 -- ;
if ( V_217 <= 0 ) {
if ( V_160 -> V_218 == V_219 ) {
F_31 ( V_160 -> V_168 , V_220 +
0x3e , 0x7400 ) ;
F_2 ( V_2 , V_106 , 0x0737 ) ;
F_31 ( V_160 -> V_168 , V_220 +
V_224 , 0xfc00 ) ;
F_2 ( V_2 , V_105 , 0x1140 ) ;
F_34 ( 100 ) ;
F_2 ( V_2 , V_104 , 0x0001 ) ;
} else {
F_26 ( V_2 , V_104 ,
V_235 |
V_237 |
V_238 ,
V_239 |
V_240 |
V_241 ) ;
F_2 ( V_2 , V_104 , 0x0000 ) ;
F_26 ( V_2 , V_82 ,
V_232 | V_233 |
V_234 , 0 ) ;
F_26 ( V_2 , V_105 ,
V_226 , 0 ) ;
}
}
}
}
static int F_36 ( struct V_172 * V_173 ,
struct V_147 * V_148 , int V_174 )
{
struct V_1 * V_2 = F_21 ( V_173 -> V_175 ) ;
struct V_159 * V_160 = F_22 ( V_2 ) ;
switch ( V_174 ) {
case V_242 :
F_33 ( V_2 , 1 ) ;
if ( V_160 -> V_218 == V_243 ) {
F_26 ( V_2 , V_106 ,
V_244 | V_245 |
V_246 ,
( V_247 << V_248 ) |
( V_249 << V_250 ) |
( V_247 << V_251 ) ) ;
F_31 ( V_160 -> V_168 , V_220 +
V_224 , 0xfc00 ) ;
F_26 ( V_2 , V_104 ,
V_252 , V_253 ) ;
F_26 ( V_2 , V_104 ,
V_254 , V_255 ) ;
F_26 ( V_2 , V_104 ,
V_254 | V_237 |
V_238 , V_256 |
V_257 | V_258 ) ;
F_34 ( 40 ) ;
F_26 ( V_2 , V_104 ,
V_235 | V_237 |
V_238 , V_239 |
V_240 | V_241 ) ;
}
break;
case V_259 :
if ( V_160 -> V_218 == V_243 ) {
F_26 ( V_2 , V_106 ,
V_244 | V_245 |
V_246 ,
( V_260 << V_248 ) |
( V_249 << V_250 ) |
( V_260 << V_251 ) ) ;
F_31 ( V_160 -> V_168 , V_220 +
V_224 , 0xfc00 ) ;
F_26 ( V_2 , V_104 ,
V_235 , V_236 ) ;
F_26 ( V_2 , V_104 ,
V_261 , V_262 ) ;
F_26 ( V_2 , V_104 ,
V_261 | V_237 |
V_238 , V_263 |
V_257 | V_258 ) ;
F_34 ( 30 ) ;
}
F_33 ( V_2 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_37 ( struct V_172 * V_173 ,
struct V_147 * V_148 , int V_174 )
{
struct V_1 * V_2 = F_21 ( V_173 -> V_175 ) ;
switch ( V_174 ) {
case V_242 :
F_30 ( V_2 ) ;
F_26 ( V_2 , V_80 ,
V_264 | V_265 |
V_266 ,
V_264 | V_265 |
V_266 ) ;
F_26 ( V_2 , V_146 ,
V_267 , V_268 ) ;
break;
case V_259 :
F_26 ( V_2 , V_146 ,
V_267 , V_269 ) ;
F_2 ( V_2 , V_112 , 0 ) ;
F_26 ( V_2 , V_80 ,
V_264 | V_265 |
V_266 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_38 ( struct V_172 * V_173 ,
struct V_147 * V_148 , int V_174 )
{
struct V_1 * V_2 = F_21 ( V_173 -> V_175 ) ;
switch ( V_174 ) {
case V_242 :
F_33 ( V_2 , 1 ) ;
F_26 ( V_2 , V_82 ,
V_270 , V_270 ) ;
F_26 ( V_2 , V_29 ,
V_271 | V_272 , 0 ) ;
break;
case V_259 :
F_26 ( V_2 , V_29 ,
V_271 | V_272 ,
V_271 | V_272 ) ;
F_26 ( V_2 , V_82 ,
V_270 , 0 ) ;
F_33 ( V_2 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_39 ( struct V_172 * V_173 ,
struct V_147 * V_148 , int V_174 )
{
struct V_1 * V_2 = F_21 ( V_173 -> V_175 ) ;
switch ( V_174 ) {
case V_242 :
F_26 ( V_2 , V_83 ,
V_273 , V_273 ) ;
break;
case V_259 :
F_26 ( V_2 , V_83 ,
V_273 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_40 ( struct V_172 * V_173 ,
struct V_147 * V_274 , int V_174 )
{
struct V_1 * V_2 = F_21 ( V_173 -> V_175 ) ;
struct V_159 * V_160 = F_22 ( V_2 ) ;
switch ( V_174 ) {
case V_242 :
if ( V_160 -> V_225 ) {
F_34 ( 100 ) ;
V_160 -> V_225 = false ;
}
break;
default:
return 0 ;
}
return 0 ;
}
static int F_41 ( struct V_275 * V_276 ,
struct V_277 * V_278 , struct V_279 * V_280 )
{
struct V_1 * V_2 = V_280 -> V_2 ;
struct V_159 * V_160 = F_22 ( V_2 ) ;
unsigned int V_281 = 0 , V_282 , V_283 , V_284 ;
int V_285 , V_286 , V_287 ;
V_160 -> V_288 [ V_280 -> V_289 ] = F_42 ( V_278 ) ;
V_285 = F_43 ( V_160 -> V_178 , V_160 -> V_288 [ V_280 -> V_289 ] ) ;
if ( V_285 < 0 ) {
F_25 ( V_2 -> V_5 , L_2 ) ;
return - V_197 ;
}
V_287 = F_44 ( V_278 ) ;
if ( V_287 < 0 ) {
F_25 ( V_2 -> V_5 , L_3 , V_287 ) ;
return - V_197 ;
}
switch ( V_160 -> V_218 ) {
case V_219 :
V_284 = 4 ;
break;
default:
V_284 = 2 ;
break;
}
V_286 = V_287 > 32 ;
V_160 -> V_290 [ V_280 -> V_289 ] = V_160 -> V_288 [ V_280 -> V_289 ] * ( 32 << V_286 ) ;
F_45 ( V_280 -> V_5 , L_4 ,
V_160 -> V_290 [ V_280 -> V_289 ] , V_160 -> V_288 [ V_280 -> V_289 ] ) ;
F_45 ( V_280 -> V_5 , L_5 ,
V_286 , V_285 , V_280 -> V_289 ) ;
switch ( F_46 ( V_278 ) ) {
case 16 :
break;
case 20 :
V_281 = 0x1 ;
break;
case 24 :
V_281 = 0x2 ;
break;
case 8 :
V_281 = 0x3 ;
break;
default:
return - V_197 ;
}
switch ( V_280 -> V_289 ) {
case V_291 :
V_283 = V_292 ;
V_282 = V_285 << V_179 ;
F_26 ( V_2 , V_87 ,
( 0x3 << V_284 ) , ( V_281 << V_284 ) ) ;
F_26 ( V_2 , V_89 , V_283 , V_282 ) ;
break;
case V_293 :
V_283 = V_294 | V_295 ;
V_282 = V_286 << V_296 |
V_285 << V_297 ;
F_26 ( V_2 , V_88 ,
( 0x3 << V_284 ) , ( V_281 << V_284 ) ) ;
F_26 ( V_2 , V_89 , V_283 , V_282 ) ;
break;
default:
F_25 ( V_2 -> V_5 , L_6 , V_280 -> V_289 ) ;
return - V_197 ;
}
return 0 ;
}
static int F_47 ( struct V_279 * V_280 , unsigned int V_298 )
{
struct V_1 * V_2 = V_280 -> V_2 ;
struct V_159 * V_160 = F_22 ( V_2 ) ;
unsigned int V_299 = 0 , V_300 ;
switch ( V_160 -> V_218 ) {
case V_219 :
V_300 = 8 ;
break;
default:
V_300 = 7 ;
break;
}
switch ( V_298 & V_301 ) {
case V_302 :
V_160 -> V_303 [ V_280 -> V_289 ] = 1 ;
break;
case V_304 :
V_299 |= V_305 ;
V_160 -> V_303 [ V_280 -> V_289 ] = 0 ;
break;
default:
return - V_197 ;
}
switch ( V_298 & V_306 ) {
case V_307 :
break;
case V_308 :
V_299 |= ( 1 << V_300 ) ;
break;
default:
return - V_197 ;
}
switch ( V_298 & V_309 ) {
case V_310 :
break;
case V_311 :
V_299 |= V_312 ;
break;
case V_313 :
V_299 |= V_314 ;
break;
case V_315 :
V_299 |= V_316 ;
break;
default:
return - V_197 ;
}
switch ( V_280 -> V_289 ) {
case V_291 :
F_26 ( V_2 , V_87 ,
V_317 | ( 1 << V_300 ) |
V_318 , V_299 ) ;
break;
case V_293 :
F_26 ( V_2 , V_88 ,
V_317 | ( 1 << V_300 ) |
V_318 , V_299 ) ;
break;
default:
F_25 ( V_2 -> V_5 , L_6 , V_280 -> V_289 ) ;
return - V_197 ;
}
return 0 ;
}
static int F_48 ( struct V_279 * V_280 ,
int V_319 , unsigned int V_320 , int V_321 )
{
struct V_1 * V_2 = V_280 -> V_2 ;
struct V_159 * V_160 = F_22 ( V_2 ) ;
unsigned int V_299 = 0 ;
if ( V_320 == V_160 -> V_178 && V_319 == V_160 -> V_322 )
return 0 ;
switch ( V_319 ) {
case V_323 :
V_299 |= V_324 ;
break;
case V_325 :
V_299 |= V_185 ;
break;
case V_326 :
V_299 |= V_327 ;
break;
default:
F_25 ( V_2 -> V_5 , L_7 , V_319 ) ;
return - V_197 ;
}
F_26 ( V_2 , V_97 ,
V_184 , V_299 ) ;
V_160 -> V_178 = V_320 ;
V_160 -> V_322 = V_319 ;
F_45 ( V_280 -> V_5 , L_8 , V_320 , V_319 ) ;
return 0 ;
}
static int F_49 ( struct V_279 * V_280 , int V_328 , int V_182 ,
unsigned int V_329 , unsigned int V_330 )
{
struct V_1 * V_2 = V_280 -> V_2 ;
struct V_159 * V_160 = F_22 ( V_2 ) ;
struct V_331 V_332 ;
int V_166 ;
if ( V_182 == V_160 -> V_333 && V_329 == V_160 -> V_334 &&
V_330 == V_160 -> V_335 )
return 0 ;
if ( ! V_329 || ! V_330 ) {
F_45 ( V_2 -> V_5 , L_9 ) ;
V_160 -> V_334 = 0 ;
V_160 -> V_335 = 0 ;
F_26 ( V_2 , V_97 ,
V_184 , V_324 ) ;
return 0 ;
}
switch ( V_182 ) {
case V_336 :
F_26 ( V_2 , V_97 ,
V_337 , V_338 ) ;
break;
case V_339 :
case V_340 :
switch ( V_280 -> V_289 ) {
case V_291 :
F_26 ( V_2 , V_97 ,
V_337 , V_341 ) ;
break;
case V_293 :
F_26 ( V_2 , V_97 ,
V_337 , V_342 ) ;
break;
default:
F_25 ( V_2 -> V_5 , L_6 , V_280 -> V_289 ) ;
return - V_197 ;
}
break;
default:
F_25 ( V_2 -> V_5 , L_10 , V_182 ) ;
return - V_197 ;
}
V_166 = F_50 ( V_329 , V_330 , & V_332 ) ;
if ( V_166 < 0 ) {
F_25 ( V_2 -> V_5 , L_11 , V_329 ) ;
return V_166 ;
}
F_45 ( V_2 -> V_5 , L_12 ,
V_332 . V_343 , ( V_332 . V_343 ? 0 : V_332 . V_344 ) ,
V_332 . V_345 , V_332 . V_346 ) ;
F_2 ( V_2 , V_98 ,
V_332 . V_345 << V_347 | V_332 . V_346 ) ;
F_2 ( V_2 , V_99 ,
( V_332 . V_343 ? 0 : V_332 . V_344 ) << V_348 |
V_332 . V_343 << V_349 ) ;
V_160 -> V_334 = V_329 ;
V_160 -> V_335 = V_330 ;
V_160 -> V_333 = V_182 ;
return 0 ;
}
static int F_51 ( struct V_279 * V_280 , unsigned int V_350 ,
unsigned int V_351 , int V_352 , int V_353 )
{
struct V_1 * V_2 = V_280 -> V_2 ;
struct V_159 * V_160 = F_22 ( V_2 ) ;
unsigned int V_354 , V_355 , V_356 , V_357 , V_358 ;
unsigned int V_359 , V_165 = 0 ;
switch ( V_160 -> V_218 ) {
case V_219 :
V_358 = 15 ;
V_354 = 10 ;
V_355 = 8 ;
V_356 = 6 ;
V_357 = 4 ;
V_359 = 0x8ff0 ;
break;
default:
V_358 = 14 ;
V_354 = V_355 = 12 ;
V_356 = V_357 = 10 ;
V_359 = 0x7c00 ;
break;
}
if ( V_351 || V_350 ) {
V_165 |= ( 1 << V_358 ) ;
if ( V_160 -> V_218 == V_243 )
F_26 ( V_2 , V_122 ,
V_360 , V_361 ) ;
}
switch ( V_352 ) {
case 4 :
V_165 |= ( 1 << V_354 ) | ( 1 << V_355 ) ;
break;
case 6 :
V_165 |= ( 2 << V_354 ) | ( 2 << V_355 ) ;
break;
case 8 :
V_165 |= ( 3 << V_354 ) | ( 3 << V_355 ) ;
break;
case 2 :
default:
break;
}
switch ( V_353 ) {
case 20 :
V_165 |= ( 1 << V_356 ) | ( 1 << V_357 ) ;
break;
case 24 :
V_165 |= ( 2 << V_356 ) | ( 2 << V_357 ) ;
break;
case 32 :
V_165 |= ( 3 << V_356 ) | ( 3 << V_357 ) ;
break;
case 16 :
default:
break;
}
F_26 ( V_2 , V_93 , V_359 , V_165 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
enum V_362 V_363 )
{
struct V_159 * V_160 = F_22 ( V_2 ) ;
switch ( V_363 ) {
case V_364 :
if ( V_365 == F_53 ( V_2 ) ) {
F_26 ( V_2 , V_82 ,
V_366 | V_367 |
V_368 | V_369 ,
V_366 | V_367 |
V_368 | V_369 ) ;
F_35 ( 10 ) ;
F_26 ( V_2 , V_82 ,
V_228 | V_229 ,
V_228 | V_229 ) ;
F_26 ( V_2 , V_144 ,
V_370 , V_370 ) ;
}
break;
case V_365 :
F_26 ( V_2 , V_82 ,
V_366 | V_367 |
V_368 | V_369 ,
V_366 | V_367 |
V_368 | V_369 ) ;
F_26 ( V_2 , V_82 ,
V_228 | V_229 ,
V_228 | V_229 ) ;
if ( V_160 -> V_371 &&
F_53 ( V_2 ) == V_372 )
F_18 ( V_171 ,
& V_160 -> V_373 , F_19 ( 0 ) ) ;
break;
case V_372 :
F_2 ( V_2 , V_105 , 0x1100 ) ;
if ( ! V_160 -> V_371 )
F_26 ( V_2 , V_144 ,
V_370 , 0 ) ;
F_26 ( V_2 , V_82 ,
V_366 | V_367 |
V_368 | V_369 |
V_228 | V_229 , 0x0 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_54 ( struct V_1 * V_2 ,
bool V_374 )
{
struct V_375 * V_175 = F_55 ( V_2 ) ;
if ( V_374 ) {
F_56 ( V_175 , L_13 ) ;
F_56 ( V_175 , L_14 ) ;
F_57 ( V_175 ) ;
F_26 ( V_2 ,
V_21 , 0x8 , 0x8 ) ;
F_26 ( V_2 ,
V_132 , 0x8000 , 0x8000 ) ;
F_28 ( V_2 , V_23 ) ;
F_58 ( L_15 , V_376 , V_23 ,
F_28 ( V_2 , V_23 ) ) ;
} else {
F_26 ( V_2 , V_132 , 0x8000 , 0x0 ) ;
F_26 ( V_2 , V_21 , 0x8 , 0x0 ) ;
F_59 ( V_175 , L_13 ) ;
F_59 ( V_175 , L_14 ) ;
F_57 ( V_175 ) ;
}
}
static int F_60 ( struct V_1 * V_2 , int V_377 )
{
struct V_375 * V_175 = F_55 ( V_2 ) ;
struct V_159 * V_160 = F_22 ( V_2 ) ;
unsigned int V_165 ;
if ( V_377 ) {
F_31 ( V_160 -> V_168 , V_107 , 0x0006 ) ;
F_56 ( V_175 , L_16 ) ;
F_56 ( V_175 , L_17 ) ;
F_57 ( V_175 ) ;
if ( ! V_175 -> V_378 -> V_379 ) {
F_16 ( V_160 -> V_168 , V_82 ,
V_367 | V_369 ,
V_367 | V_369 ) ;
F_16 ( V_160 -> V_168 , V_84 ,
V_380 , V_380 ) ;
F_16 ( V_160 -> V_168 , V_85 ,
V_381 , V_381 ) ;
}
F_31 ( V_160 -> V_168 , V_142 , 0x00f0 ) ;
F_16 ( V_160 -> V_168 , V_13 ,
V_382 , V_382 ) ;
F_16 ( V_160 -> V_168 , V_12 ,
V_383 , V_383 ) ;
F_34 ( 100 ) ;
F_16 ( V_160 -> V_168 , V_13 ,
V_382 , 0 ) ;
F_34 ( 600 ) ;
F_61 ( V_160 -> V_168 , V_14 , & V_165 ) ;
V_165 &= 0x7 ;
F_45 ( V_2 -> V_5 , L_18 , V_165 ) ;
if ( V_165 == 1 || V_165 == 2 ) {
V_160 -> V_384 = V_385 ;
if ( V_160 -> V_371 ) {
F_54 ( V_2 , true ) ;
}
} else {
F_59 ( V_175 , L_17 ) ;
F_57 ( V_175 ) ;
V_160 -> V_384 = V_386 ;
}
if ( V_160 -> V_387 . V_388 )
F_16 ( V_160 -> V_168 , V_19 ,
V_389 , V_390 ) ;
} else {
V_160 -> V_384 = 0 ;
F_16 ( V_160 -> V_168 , V_28 ,
V_271 | V_272 ,
V_271 | V_272 ) ;
F_16 ( V_160 -> V_168 , V_13 ,
V_382 , V_382 ) ;
F_16 ( V_160 -> V_168 , V_12 ,
V_383 , 0 ) ;
if ( V_160 -> V_371 )
F_54 ( V_2 , false ) ;
if ( V_160 -> V_387 . V_391 == 0 )
F_59 ( V_175 , L_16 ) ;
F_59 ( V_175 , L_17 ) ;
F_57 ( V_175 ) ;
if ( V_160 -> V_387 . V_388 )
F_16 ( V_160 -> V_168 , V_19 ,
V_389 , V_392 ) ;
}
return V_160 -> V_384 ;
}
static int F_62 ( struct V_1 * V_2 )
{
int V_393 , V_165 ;
V_165 = F_28 ( V_2 , V_23 ) ;
F_58 ( L_19 , V_165 ) ;
V_393 = V_165 & 0xfff0 ;
F_2 ( V_2 , V_23 , V_165 ) ;
return V_393 ;
}
int F_63 ( struct V_1 * V_2 ,
struct V_394 * V_395 , struct V_394 * V_396 ,
struct V_394 * V_397 )
{
struct V_159 * V_160 = F_22 ( V_2 ) ;
V_160 -> V_395 = V_395 ;
V_160 -> V_396 = V_396 ;
V_160 -> V_397 = V_397 ;
if ( V_160 -> V_397 && V_160 -> V_218 == V_219 ) {
V_160 -> V_371 = true ;
F_16 ( V_160 -> V_168 , V_119 ,
V_398 , V_398 ) ;
F_16 ( V_160 -> V_168 , V_144 ,
V_370 , V_370 ) ;
}
F_64 ( 0 , V_160 ) ;
return 0 ;
}
static void F_65 ( struct V_399 * V_400 )
{
struct V_159 * V_160 =
F_66 ( V_400 , struct V_159 , V_373 . V_400 ) ;
int V_165 , V_393 , V_401 = 0 , V_402 = 0 ;
if ( ! V_160 -> V_2 )
return;
switch ( V_160 -> V_387 . V_391 ) {
case 0 :
if ( V_160 -> V_403 ) {
V_401 = F_67 ( V_160 -> V_403 ) ;
F_45 ( V_160 -> V_2 -> V_5 , L_20 ,
V_401 ) ;
V_402 = F_60 ( V_160 -> V_2 , V_401 ) ;
}
F_68 ( V_160 -> V_395 ,
V_402 , V_386 ) ;
F_68 ( V_160 -> V_396 ,
V_402 , V_404 ) ;
return;
case 1 :
V_165 = F_28 ( V_160 -> V_2 , V_15 ) & 0x0070 ;
break;
default:
V_165 = F_28 ( V_160 -> V_2 , V_15 ) & 0x0020 ;
break;
}
switch ( V_165 ) {
case 0x30 :
case 0x0 :
if ( V_160 -> V_384 == 0 ) {
V_402 = F_60 ( V_160 -> V_2 , 1 ) ;
break;
}
V_393 = 0 ;
if ( F_28 ( V_160 -> V_2 , V_21 ) & 0x4 ) {
V_402 = V_385 ;
V_393 = F_62 ( V_160 -> V_2 ) ;
switch ( V_393 ) {
case 0x8000 :
case 0x4000 :
case 0x2000 :
V_402 |= V_405 ;
break;
case 0x1000 :
case 0x0800 :
case 0x0400 :
V_402 |= V_406 ;
break;
case 0x0200 :
case 0x0100 :
case 0x0080 :
V_402 |= V_407 ;
break;
case 0x0040 :
case 0x0020 :
case 0x0010 :
V_402 |= V_408 ;
break;
case 0x0000 :
break;
default:
F_25 ( V_160 -> V_2 -> V_5 ,
L_21 ,
V_393 ) ;
break;
}
}
if ( V_393 == 0 )
V_402 = V_160 -> V_384 ;
break;
case 0x70 :
case 0x10 :
case 0x20 :
V_402 = 0 ;
F_26 ( V_160 -> V_2 ,
V_21 , 0x1 , 0x0 ) ;
F_60 ( V_160 -> V_2 , 0 ) ;
break;
default:
break;
}
F_68 ( V_160 -> V_395 , V_402 , V_386 ) ;
F_68 ( V_160 -> V_396 , V_402 , V_404 ) ;
if ( V_160 -> V_371 )
F_68 ( V_160 -> V_397 ,
V_402 , V_405 | V_406 |
V_407 | V_408 ) ;
}
static void F_69 ( struct V_399 * V_400 )
{
struct V_159 * V_160 =
F_66 ( V_400 , struct V_159 , V_167 . V_400 ) ;
F_16 ( V_160 -> V_168 , V_108 ,
V_169 , V_409 ) ;
}
static T_1 F_64 ( int V_410 , void * V_164 )
{
struct V_159 * V_160 = V_164 ;
F_18 ( V_171 ,
& V_160 -> V_373 , F_19 ( 250 ) ) ;
return V_411 ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_375 * V_175 = F_55 ( V_2 ) ;
struct V_159 * V_160 = F_22 ( V_2 ) ;
V_160 -> V_2 = V_2 ;
switch ( V_160 -> V_218 ) {
case V_243 :
F_71 ( V_175 ,
V_412 ,
F_4 ( V_412 ) ) ;
F_72 ( V_175 ,
V_413 ,
F_4 ( V_413 ) ) ;
break;
case V_219 :
F_71 ( V_175 ,
V_414 ,
F_4 ( V_414 ) ) ;
F_72 ( V_175 ,
V_415 ,
F_4 ( V_415 ) ) ;
break;
}
F_73 ( V_2 , V_372 ) ;
if ( V_160 -> V_387 . V_391 ) {
F_56 ( V_175 , L_22 ) ;
F_56 ( V_175 , L_16 ) ;
F_57 ( V_175 ) ;
}
V_160 -> V_161 = F_74 ( V_2 -> V_5 ,
V_153 * sizeof( struct V_154 ) , V_416 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_159 * V_160 = F_22 ( V_2 ) ;
F_77 ( V_160 -> V_168 , true ) ;
F_78 ( V_160 -> V_168 ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_159 * V_160 = F_22 ( V_2 ) ;
F_77 ( V_160 -> V_168 , false ) ;
F_80 ( V_160 -> V_168 ) ;
return 0 ;
}
static int F_81 ( const struct V_417 * V_289 )
{
V_418 = & V_419 ;
return 1 ;
}
static int F_82 ( const struct V_417 * V_289 )
{
V_418 = & V_420 ;
return 1 ;
}
static int F_83 ( struct V_159 * V_160 , struct V_4 * V_5 )
{
V_160 -> V_387 . V_421 = F_84 ( V_5 ,
L_23 ) ;
F_85 ( V_5 ,
L_24 , & V_160 -> V_387 . V_422 ) ;
F_85 ( V_5 ,
L_25 , & V_160 -> V_387 . V_423 ) ;
F_85 ( V_5 ,
L_26 , & V_160 -> V_387 . V_391 ) ;
return 0 ;
}
static int F_86 ( struct V_424 * V_425 ,
const struct V_426 * V_289 )
{
struct V_427 * V_387 = F_87 ( & V_425 -> V_5 ) ;
struct V_159 * V_160 ;
int V_166 , V_7 ;
unsigned int V_165 ;
V_160 = F_74 ( & V_425 -> V_5 , sizeof( struct V_159 ) ,
V_416 ) ;
if ( V_160 == NULL )
return - V_428 ;
V_160 -> V_425 = V_425 ;
F_88 ( V_425 , V_160 ) ;
if ( V_387 )
V_160 -> V_387 = * V_387 ;
else if ( F_89 ( V_429 ) ||
F_89 ( V_430 ) )
V_160 -> V_387 = * V_418 ;
else
F_83 ( V_160 , & V_425 -> V_5 ) ;
V_160 -> V_403 = F_90 ( & V_425 -> V_5 , L_27 ,
V_431 ) ;
if ( F_91 ( V_160 -> V_403 ) ) {
F_25 ( & V_425 -> V_5 , L_28 ) ;
return F_92 ( V_160 -> V_403 ) ;
}
V_160 -> V_168 = F_93 ( V_425 , & V_432 ) ;
if ( F_91 ( V_160 -> V_168 ) ) {
V_166 = F_92 ( V_160 -> V_168 ) ;
F_25 ( & V_425 -> V_5 , L_29 ,
V_166 ) ;
return V_166 ;
}
for ( V_7 = 0 ; V_7 < F_4 ( V_160 -> V_433 ) ; V_7 ++ )
V_160 -> V_433 [ V_7 ] . V_434 = V_435 [ V_7 ] ;
V_166 = F_94 ( & V_425 -> V_5 ,
F_4 ( V_160 -> V_433 ) ,
V_160 -> V_433 ) ;
if ( V_166 ) {
F_25 ( & V_425 -> V_5 , L_30 , V_166 ) ;
return V_166 ;
}
V_166 = F_95 ( F_4 ( V_160 -> V_433 ) ,
V_160 -> V_433 ) ;
if ( V_166 ) {
F_25 ( & V_425 -> V_5 , L_31 , V_166 ) ;
return V_166 ;
}
F_61 ( V_160 -> V_168 , V_26 , & V_165 ) ;
switch ( V_165 ) {
case V_436 :
V_160 -> V_218 = V_243 ;
break;
case V_437 :
V_160 -> V_218 = V_219 ;
break;
default:
F_25 ( & V_425 -> V_5 ,
L_32 ,
V_165 ) ;
V_166 = - V_438 ;
goto V_439;
}
F_31 ( V_160 -> V_168 , V_3 , 0 ) ;
V_166 = F_96 ( V_160 -> V_168 , V_440 ,
F_4 ( V_440 ) ) ;
if ( V_166 != 0 )
F_97 ( & V_425 -> V_5 , L_33 , V_166 ) ;
if ( V_160 -> V_218 == V_219 ) {
V_166 = F_96 ( V_160 -> V_168 , V_441 ,
F_4 ( V_441 ) ) ;
if ( V_166 != 0 )
F_97 ( & V_425 -> V_5 , L_34 ,
V_166 ) ;
}
if ( V_160 -> V_387 . V_421 )
F_16 ( V_160 -> V_168 , V_30 ,
V_442 , V_442 ) ;
if ( V_160 -> V_387 . V_422 || V_160 -> V_387 . V_423 ) {
F_16 ( V_160 -> V_168 , V_119 ,
V_443 , V_444 ) ;
}
switch ( V_160 -> V_387 . V_422 ) {
case V_445 :
F_16 ( V_160 -> V_168 , V_91 ,
V_446 , V_447 ) ;
break;
case V_448 :
F_16 ( V_160 -> V_168 , V_119 ,
V_449 , V_450 ) ;
F_16 ( V_160 -> V_168 , V_91 ,
V_446 , V_451 ) ;
F_16 ( V_160 -> V_168 , V_119 ,
V_452 , V_453 ) ;
break;
case V_454 :
F_16 ( V_160 -> V_168 , V_91 ,
V_446 , V_455 ) ;
F_16 ( V_160 -> V_168 , V_119 ,
V_456 ,
V_457 ) ;
break;
default:
break;
}
switch ( V_160 -> V_387 . V_423 ) {
case V_458 :
F_16 ( V_160 -> V_168 , V_91 ,
V_459 , V_460 ) ;
break;
case V_461 :
F_16 ( V_160 -> V_168 , V_91 ,
V_459 , V_462 ) ;
F_16 ( V_160 -> V_168 , V_119 ,
V_463 , V_464 ) ;
break;
case V_465 :
F_16 ( V_160 -> V_168 , V_91 ,
V_459 , V_466 ) ;
F_16 ( V_160 -> V_168 , V_119 ,
V_467 ,
V_468 ) ;
break;
case V_469 :
F_16 ( V_160 -> V_168 , V_91 ,
V_459 , V_470 ) ;
F_16 ( V_160 -> V_168 , V_119 ,
V_471 ,
V_472 ) ;
break;
default:
break;
}
if ( V_160 -> V_387 . V_391 ) {
F_16 ( V_160 -> V_168 , V_146 ,
V_473 ,
V_473 ) ;
F_16 ( V_160 -> V_168 , V_108 ,
V_474 , V_474 ) ;
F_16 ( V_160 -> V_168 , V_19 ,
V_475 , V_475 ) ;
F_16 ( V_160 -> V_168 , V_146 ,
V_476 , V_476 ) ;
F_16 ( V_160 -> V_168 , V_58 ,
V_477 , V_477 ) ;
F_16 ( V_160 -> V_168 , V_108 ,
V_478 , V_478 ) ;
F_16 ( V_160 -> V_168 , V_119 ,
V_398 , V_398 ) ;
switch ( V_160 -> V_387 . V_391 ) {
case 1 :
F_16 ( V_160 -> V_168 , V_15 ,
V_479 ,
V_480 ) ;
break;
case 2 :
F_16 ( V_160 -> V_168 , V_15 ,
V_479 ,
V_481 ) ;
break;
case 3 :
F_16 ( V_160 -> V_168 , V_15 ,
V_479 ,
V_482 ) ;
break;
default:
break;
}
}
F_98 ( & V_160 -> V_373 , F_65 ) ;
F_98 ( & V_160 -> V_167 , F_69 ) ;
if ( V_160 -> V_425 -> V_410 ) {
V_166 = F_99 ( V_160 -> V_425 -> V_410 , NULL , F_64 ,
V_483 | V_484
| V_485 , L_35 , V_160 ) ;
if ( V_166 ) {
F_25 ( & V_425 -> V_5 , L_36 , V_166 ) ;
goto V_439;
}
}
V_166 = F_100 ( & V_425 -> V_5 , & V_486 ,
V_487 , F_4 ( V_487 ) ) ;
if ( V_166 )
goto V_488;
return 0 ;
V_488:
if ( V_160 -> V_425 -> V_410 )
F_101 ( V_160 -> V_425 -> V_410 , V_160 ) ;
V_439:
F_102 ( F_4 ( V_160 -> V_433 ) , V_160 -> V_433 ) ;
return V_166 ;
}
static int F_103 ( struct V_424 * V_425 )
{
struct V_159 * V_160 = F_104 ( V_425 ) ;
if ( V_425 -> V_410 )
F_101 ( V_425 -> V_410 , V_160 ) ;
F_15 ( & V_160 -> V_373 ) ;
F_15 ( & V_160 -> V_167 ) ;
F_105 ( & V_425 -> V_5 ) ;
F_102 ( F_4 ( V_160 -> V_433 ) , V_160 -> V_433 ) ;
return 0 ;
}
static void F_106 ( struct V_424 * V_425 )
{
struct V_159 * V_160 = F_104 ( V_425 ) ;
F_16 ( V_160 -> V_168 , V_146 ,
V_489 , V_489 ) ;
F_16 ( V_160 -> V_168 , V_13 , V_382 ,
V_382 ) ;
F_16 ( V_160 -> V_168 , V_12 , V_383 ,
0 ) ;
F_34 ( 20 ) ;
F_31 ( V_160 -> V_168 , V_3 , 0 ) ;
}
