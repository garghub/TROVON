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
static int F_4 ( struct V_150 * V_151 , int V_152 )
{
int V_153 ;
struct V_154 * V_155 = F_5 ( V_151 ) ;
if ( V_152 ) {
F_6 ( & V_151 -> V_156 ,
L_1 ) ;
F_7 ( & V_151 -> V_156 ) ;
F_8 ( V_151 , V_149 , 0x4 , 0x0 ) ;
F_8 ( V_151 , V_17 ,
V_157 | V_158 ,
V_158 ) ;
F_9 ( V_151 , V_125 , 0x0004 ) ;
F_8 ( V_151 , V_124 ,
V_159 , V_160 ) ;
F_8 ( V_151 , V_16 ,
V_161 , V_161 ) ;
F_9 ( V_151 , V_145 , 0x00f0 ) ;
F_8 ( V_151 , V_17 ,
V_158 , V_158 ) ;
F_8 ( V_151 , V_17 ,
V_158 , 0 ) ;
F_10 ( 300 ) ;
V_153 = F_11 ( V_151 , V_18 ) & 0x7 ;
if ( V_153 == 0x1 || V_153 == 0x2 ) {
V_155 -> V_162 = V_163 ;
F_8 ( V_151 , V_26 , 0x8 , 0x8 ) ;
F_8 ( V_151 , V_27 , 0x40 , 0x40 ) ;
F_11 ( V_151 , V_27 ) ;
} else {
F_8 ( V_151 , V_149 , 0x4 , 0x4 ) ;
V_155 -> V_162 = V_164 ;
F_12 ( & V_151 -> V_156 , L_1 ) ;
F_7 ( & V_151 -> V_156 ) ;
}
} else {
F_8 ( V_151 , V_26 , 0x8 , 0x0 ) ;
F_8 ( V_151 , V_149 , 0x4 , 0x4 ) ;
V_155 -> V_162 = 0 ;
F_12 ( & V_151 -> V_156 , L_1 ) ;
F_7 ( & V_151 -> V_156 ) ;
}
return V_155 -> V_162 ;
}
void F_13 ( struct V_150 * V_151 )
{
struct V_154 * V_155 = F_5 ( V_151 ) ;
V_155 -> V_165 = V_155 -> V_162 ;
F_4 ( V_151 , 0 ) ;
}
void F_14 ( struct V_150 * V_151 )
{
struct V_154 * V_155 = F_5 ( V_151 ) ;
if ( V_155 -> V_165 )
F_4 ( V_151 , 1 ) ;
}
static int F_15 ( struct V_150 * V_151 )
{
int V_166 , V_153 ;
V_153 = F_11 ( V_151 , V_27 ) ;
V_166 = V_153 & 0xff80 ;
F_9 ( V_151 , V_27 , V_153 ) ;
if ( V_166 != 0 ) {
F_10 ( 20 ) ;
V_153 = F_11 ( V_151 , V_27 ) ;
F_9 ( V_151 , V_27 , V_153 ) ;
}
return V_166 ;
}
static int F_16 ( void * V_167 )
{
struct V_154 * V_155 = (struct V_154 * ) V_167 ;
struct V_168 * V_169 = & V_155 -> V_170 ;
struct V_171 * V_172 = V_155 -> V_172 ;
int V_153 , V_166 , V_173 = V_172 -> V_174 ;
if ( V_155 -> V_175 . V_176 == 1 )
V_153 = F_11 ( V_155 -> V_151 , V_19 ) & 0x0070 ;
else
V_153 = F_11 ( V_155 -> V_151 , V_19 ) & 0x0020 ;
switch ( V_153 ) {
case 0x30 :
case 0x0 :
if ( V_155 -> V_162 == 0 ) {
V_173 = F_4 ( V_155 -> V_151 , 1 ) ;
V_169 -> V_177 = 25 ;
break;
}
V_166 = 0 ;
if ( F_11 ( V_155 -> V_151 , V_26 ) & 0x4 ) {
V_173 = V_163 ;
V_166 = F_15 ( V_155 -> V_151 ) ;
switch ( V_166 ) {
case 0x2000 :
V_173 |= V_178 ;
break;
case 0x0400 :
V_173 |= V_179 ;
break;
case 0x0080 :
V_173 |= V_180 ;
break;
default:
F_17 ( V_155 -> V_151 -> V_2 ,
L_2 ,
V_166 ) ;
break;
}
}
if ( V_166 == 0 )
V_173 = V_155 -> V_162 ;
break;
case 0x70 :
case 0x10 :
case 0x20 :
V_173 = 0 ;
F_8 ( V_155 -> V_151 , V_26 , 0x1 , 0x0 ) ;
F_4 ( V_155 -> V_151 , 0 ) ;
V_169 -> V_177 = 150 ;
break;
default:
break;
}
return V_173 ;
}
int F_18 ( struct V_150 * V_151 ,
struct V_171 * V_172 )
{
struct V_154 * V_155 = F_5 ( V_151 ) ;
int V_181 ;
V_155 -> V_172 = V_172 ;
V_155 -> V_170 . V_182 = V_151 -> V_2 ;
V_155 -> V_170 . V_183 = L_3 ;
V_155 -> V_170 . V_173 = V_163 |
V_179 | V_178 | V_180 ;
V_155 -> V_170 . V_177 = 150 ;
V_155 -> V_170 . V_184 = true ;
V_155 -> V_170 . V_167 = (struct V_154 * ) V_155 ;
V_155 -> V_170 . V_185 = F_16 ;
V_181 = F_19 ( V_155 -> V_172 , 1 ,
& V_155 -> V_170 ) ;
if ( V_181 ) {
F_17 ( V_151 -> V_2 , L_4 ) ;
return V_181 ;
}
return 0 ;
}
static int F_20 ( struct V_186 * V_187 ,
struct V_188 * V_189 , int V_190 )
{
struct V_150 * V_151 = F_21 ( V_187 -> V_156 ) ;
struct V_154 * V_155 = F_5 ( V_151 ) ;
int V_191 = - V_192 ;
V_191 = F_22 ( V_155 -> V_193 ) ;
if ( V_191 < 0 )
F_17 ( V_151 -> V_2 , L_5 ) ;
else
F_8 ( V_151 , V_86 ,
V_194 , V_191 << V_195 ) ;
return V_191 ;
}
static int F_23 ( struct V_186 * V_196 ,
struct V_186 * V_197 )
{
struct V_150 * V_151 = F_21 ( V_196 -> V_156 ) ;
struct V_154 * V_155 = F_5 ( V_151 ) ;
if ( V_155 -> V_198 == V_199 )
return 1 ;
else
return 0 ;
}
static int F_24 ( struct V_186 * V_196 ,
struct V_186 * V_197 )
{
struct V_150 * V_151 = F_21 ( V_196 -> V_156 ) ;
unsigned int V_3 , V_200 , V_153 ;
switch ( V_196 -> V_200 ) {
case 0 :
V_3 = V_97 ;
V_200 = 0 ;
break;
case 1 :
V_3 = V_97 ;
V_200 = 4 ;
break;
case 2 :
V_3 = V_15 ;
V_200 = 12 ;
break;
case 3 :
V_3 = V_96 ;
V_200 = 0 ;
break;
case 8 :
V_3 = V_96 ;
V_200 = 4 ;
break;
case 9 :
V_3 = V_96 ;
V_200 = 8 ;
break;
case 10 :
V_3 = V_96 ;
V_200 = 12 ;
break;
default:
return 0 ;
}
V_153 = ( F_11 ( V_151 , V_3 ) >> V_200 ) & 0xf ;
switch ( V_153 ) {
case 1 :
case 2 :
case 3 :
case 4 :
return 1 ;
default:
return 0 ;
}
}
static int F_25 ( struct V_186 * V_196 ,
struct V_186 * V_197 )
{
struct V_150 * V_151 = F_21 ( V_196 -> V_156 ) ;
struct V_154 * V_155 = F_5 ( V_151 ) ;
if ( V_155 -> V_193 > V_155 -> V_201 [ V_202 ] * 384 )
return 1 ;
return 0 ;
}
int F_26 ( struct V_150 * V_151 ,
unsigned int V_203 , unsigned int V_204 )
{
unsigned int V_205 = 0 , V_206 = 0 ;
unsigned int V_207 = 0 , V_208 = 0 ;
if ( V_204 > V_209 )
return - V_192 ;
if ( V_203 & V_210 ) {
V_205 |= V_211 ;
V_206 = ( V_206 & ~ V_211 )
| ( V_204 << V_212 ) ;
}
if ( V_203 & V_213 ) {
V_205 |= V_214 ;
V_206 = ( V_206 & ~ V_214 )
| ( V_204 << V_215 ) ;
}
if ( V_203 & V_216 ) {
V_205 |= V_217 ;
V_206 = ( V_206 & ~ V_217 )
| ( V_204 << V_218 ) ;
}
if ( V_203 & V_219 ) {
V_205 |= V_220 ;
V_206 = ( V_206 & ~ V_220 )
| ( V_204 << V_221 ) ;
}
if ( V_203 & V_222 ) {
V_207 |= V_223 ;
V_208 = ( V_208 & ~ V_223 )
| ( V_204 << V_224 ) ;
}
if ( V_203 & V_225 ) {
V_207 |= V_226 ;
V_208 = ( V_208 & ~ V_226 )
| ( V_204 << V_227 ) ;
}
if ( V_203 & V_228 ) {
V_207 |= V_229 ;
V_208 = ( V_208 & ~ V_229 )
| ( V_204 << V_230 ) ;
}
if ( V_203 & V_231 ) {
V_207 |= V_232 ;
V_208 = ( V_208 & ~ V_232 )
| ( V_204 << V_233 ) ;
}
if ( V_205 )
F_8 ( V_151 , V_96 ,
V_205 , V_206 ) ;
if ( V_207 )
F_8 ( V_151 , V_97 ,
V_207 , V_208 ) ;
return 0 ;
}
static int F_27 ( struct V_186 * V_187 ,
struct V_188 * V_189 , int V_190 )
{
struct V_150 * V_151 = F_21 ( V_187 -> V_156 ) ;
struct V_154 * V_155 = F_5 ( V_151 ) ;
switch ( V_190 ) {
case V_234 :
F_28 ( V_155 -> V_235 , V_110 ,
V_236 , V_237 ) ;
F_28 ( V_155 -> V_235 , V_148 ,
0x0400 , 0x0400 ) ;
F_28 ( V_155 -> V_235 , V_75 ,
V_238 | V_239 |
V_240 , V_238 |
V_239 | V_240 ) ;
F_29 ( V_155 -> V_235 , V_108 , 0x3100 ) ;
F_29 ( V_155 -> V_235 , V_107 , 0x8009 ) ;
F_29 ( V_155 -> V_235 , V_241 +
V_242 , 0x9f00 ) ;
F_30 ( 20 ) ;
F_29 ( V_155 -> V_235 , V_107 , 0x8019 ) ;
break;
case V_243 :
F_29 ( V_155 -> V_235 , V_107 , 0x0004 ) ;
F_10 ( 30 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_31 ( struct V_186 * V_187 ,
struct V_188 * V_189 , int V_190 )
{
struct V_150 * V_151 = F_21 ( V_187 -> V_156 ) ;
struct V_154 * V_155 = F_5 ( V_151 ) ;
switch ( V_190 ) {
case V_234 :
F_29 ( V_155 -> V_235 , V_241 +
V_244 , 0xb400 ) ;
F_29 ( V_155 -> V_235 , V_109 , 0x0772 ) ;
F_29 ( V_155 -> V_235 , V_107 , 0x805d ) ;
F_29 ( V_155 -> V_235 , V_107 , 0x831d ) ;
F_28 ( V_155 -> V_235 , V_148 ,
0x0300 , 0x0300 ) ;
F_28 ( V_155 -> V_235 , V_36 ,
V_245 | V_246 , 0 ) ;
F_10 ( 80 ) ;
F_29 ( V_155 -> V_235 , V_107 , 0x8019 ) ;
break;
case V_243 :
F_29 ( V_155 -> V_235 , V_241 +
V_244 , 0xb400 ) ;
F_29 ( V_155 -> V_235 , V_109 , 0x0772 ) ;
F_29 ( V_155 -> V_235 , V_107 , 0x803d ) ;
F_30 ( 10 ) ;
F_29 ( V_155 -> V_235 , V_107 , 0x831d ) ;
F_30 ( 10 ) ;
F_28 ( V_155 -> V_235 , V_36 ,
V_245 | V_246 ,
V_245 | V_246 ) ;
F_10 ( 20 ) ;
F_28 ( V_155 -> V_235 ,
V_148 , 0x0300 , 0x0 ) ;
F_29 ( V_155 -> V_235 , V_107 , 0x8019 ) ;
F_29 ( V_155 -> V_235 , V_109 , 0x0707 ) ;
F_29 ( V_155 -> V_235 , V_241 +
V_244 , 0xfc00 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_32 ( struct V_186 * V_187 ,
struct V_188 * V_189 , int V_190 )
{
struct V_150 * V_151 = F_21 ( V_187 -> V_156 ) ;
switch ( V_190 ) {
case V_234 :
F_8 ( V_151 , V_76 ,
V_247 , V_247 ) ;
break;
case V_243 :
F_8 ( V_151 , V_76 ,
V_247 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_33 ( struct V_186 * V_187 ,
struct V_188 * V_189 , int V_190 )
{
struct V_150 * V_151 = F_21 ( V_187 -> V_156 ) ;
switch ( V_190 ) {
case V_234 :
F_8 ( V_151 , V_76 ,
V_248 , V_248 ) ;
break;
case V_243 :
F_8 ( V_151 , V_76 ,
V_248 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_34 ( struct V_249 * V_250 ,
struct V_251 * V_252 , struct V_253 * V_254 )
{
struct V_150 * V_151 = V_254 -> V_151 ;
struct V_154 * V_155 = F_5 ( V_151 ) ;
unsigned int V_255 = 0 , V_256 , V_257 ;
int V_258 , V_259 , V_260 ;
V_155 -> V_201 [ V_254 -> V_261 ] = F_35 ( V_252 ) ;
V_258 = F_36 ( V_155 -> V_193 , V_155 -> V_201 [ V_254 -> V_261 ] ) ;
if ( V_258 < 0 ) {
F_17 ( V_151 -> V_2 , L_6 ,
V_155 -> V_201 [ V_254 -> V_261 ] , V_254 -> V_261 ) ;
return - V_192 ;
}
V_260 = F_37 ( V_252 ) ;
if ( V_260 < 0 ) {
F_17 ( V_151 -> V_2 , L_7 , V_260 ) ;
return - V_192 ;
}
V_259 = V_260 > 32 ;
V_155 -> V_262 [ V_254 -> V_261 ] = V_155 -> V_201 [ V_254 -> V_261 ] * ( 32 << V_259 ) ;
F_38 ( V_254 -> V_2 , L_8 ,
V_155 -> V_262 [ V_254 -> V_261 ] , V_155 -> V_201 [ V_254 -> V_261 ] ) ;
F_38 ( V_254 -> V_2 , L_9 ,
V_259 , V_258 , V_254 -> V_261 ) ;
switch ( F_39 ( V_252 ) ) {
case 16 :
break;
case 20 :
V_255 |= V_263 ;
break;
case 24 :
V_255 |= V_264 ;
break;
case 8 :
V_255 |= V_265 ;
break;
default:
return - V_192 ;
}
switch ( V_254 -> V_261 ) {
case V_202 :
V_257 = V_266 | V_267 ;
V_256 = V_259 << V_268 |
V_258 << V_269 ;
F_8 ( V_151 , V_81 ,
V_270 , V_255 ) ;
F_8 ( V_151 , V_84 , V_257 , V_256 ) ;
break;
case V_271 :
V_257 = V_272 | V_273 ;
V_256 = V_259 << V_274 |
V_258 << V_275 ;
F_8 ( V_151 , V_82 ,
V_270 , V_255 ) ;
F_8 ( V_151 , V_84 , V_257 , V_256 ) ;
break;
default:
F_17 ( V_151 -> V_2 , L_10 , V_254 -> V_261 ) ;
return - V_192 ;
}
return 0 ;
}
static int F_40 ( struct V_253 * V_254 , unsigned int V_276 )
{
struct V_150 * V_151 = V_254 -> V_151 ;
struct V_154 * V_155 = F_5 ( V_151 ) ;
unsigned int V_277 = 0 ;
switch ( V_276 & V_278 ) {
case V_279 :
V_155 -> V_280 [ V_254 -> V_261 ] = 1 ;
break;
case V_281 :
V_277 |= V_282 ;
V_155 -> V_280 [ V_254 -> V_261 ] = 0 ;
break;
default:
return - V_192 ;
}
switch ( V_276 & V_283 ) {
case V_284 :
break;
case V_285 :
V_277 |= V_286 ;
break;
default:
return - V_192 ;
}
switch ( V_276 & V_287 ) {
case V_288 :
break;
case V_289 :
V_277 |= V_290 ;
break;
case V_291 :
V_277 |= V_292 ;
break;
case V_293 :
V_277 |= V_294 ;
break;
default:
return - V_192 ;
}
switch ( V_254 -> V_261 ) {
case V_202 :
F_8 ( V_151 , V_81 ,
V_295 | V_296 |
V_297 , V_277 ) ;
break;
case V_271 :
F_8 ( V_151 , V_82 ,
V_295 | V_296 |
V_297 , V_277 ) ;
break;
default:
F_17 ( V_151 -> V_2 , L_10 , V_254 -> V_261 ) ;
return - V_192 ;
}
return 0 ;
}
static int F_41 ( struct V_253 * V_254 ,
int V_298 , unsigned int V_299 , int V_300 )
{
struct V_150 * V_151 = V_254 -> V_151 ;
struct V_154 * V_155 = F_5 ( V_151 ) ;
unsigned int V_277 = 0 ;
switch ( V_298 ) {
case V_301 :
V_277 |= V_302 ;
break;
case V_199 :
V_277 |= V_303 ;
break;
case V_304 :
V_277 |= V_305 ;
break;
default:
F_17 ( V_151 -> V_2 , L_11 , V_298 ) ;
return - V_192 ;
}
F_8 ( V_151 , V_92 ,
V_306 , V_277 ) ;
V_155 -> V_193 = V_299 ;
if ( V_298 != V_304 )
V_155 -> V_198 = V_298 ;
F_38 ( V_254 -> V_2 , L_12 , V_299 , V_298 ) ;
return 0 ;
}
static int F_42 ( struct V_253 * V_254 , int V_307 , int V_196 ,
unsigned int V_308 , unsigned int V_309 )
{
struct V_150 * V_151 = V_254 -> V_151 ;
struct V_154 * V_155 = F_5 ( V_151 ) ;
struct V_310 V_311 ;
int V_181 ;
if ( V_196 == V_155 -> V_312 && V_308 == V_155 -> V_313 &&
V_309 == V_155 -> V_314 )
return 0 ;
if ( ! V_308 || ! V_309 ) {
F_38 ( V_151 -> V_2 , L_13 ) ;
V_155 -> V_313 = 0 ;
V_155 -> V_314 = 0 ;
F_8 ( V_151 , V_92 ,
V_306 , V_302 ) ;
return 0 ;
}
switch ( V_196 ) {
case V_315 :
F_8 ( V_151 , V_92 ,
V_316 , V_317 ) ;
break;
case V_318 :
case V_319 :
case V_320 :
case V_321 :
switch ( V_254 -> V_261 ) {
case V_202 :
F_8 ( V_151 , V_92 ,
V_316 , V_322 ) ;
break;
case V_271 :
F_8 ( V_151 , V_92 ,
V_316 , V_323 ) ;
break;
default:
F_17 ( V_151 -> V_2 , L_10 , V_254 -> V_261 ) ;
return - V_192 ;
}
break;
default:
F_17 ( V_151 -> V_2 , L_14 , V_196 ) ;
return - V_192 ;
}
V_181 = F_43 ( V_308 , V_309 , & V_311 ) ;
if ( V_181 < 0 ) {
F_17 ( V_151 -> V_2 , L_15 , V_308 ) ;
return V_181 ;
}
F_38 ( V_151 -> V_2 , L_16 ,
V_311 . V_324 , ( V_311 . V_324 ? 0 : V_311 . V_325 ) ,
V_311 . V_326 , V_311 . V_327 ) ;
F_9 ( V_151 , V_93 ,
V_311 . V_326 << V_328 | V_311 . V_327 ) ;
F_9 ( V_151 , V_94 ,
( V_311 . V_324 ? 0 : V_311 . V_325 ) << V_329 |
V_311 . V_324 << V_330 ) ;
V_155 -> V_313 = V_308 ;
V_155 -> V_314 = V_309 ;
V_155 -> V_312 = V_196 ;
return 0 ;
}
static int F_44 ( struct V_253 * V_254 , unsigned int V_331 ,
unsigned int V_332 , int V_333 , int V_334 )
{
struct V_150 * V_151 = V_254 -> V_151 ;
unsigned int V_153 = 0 ;
if ( V_332 || V_331 )
V_153 |= ( 1 << 14 ) ;
switch ( V_333 ) {
case 4 :
V_153 |= ( 1 << 12 ) ;
break;
case 6 :
V_153 |= ( 2 << 12 ) ;
break;
case 8 :
V_153 |= ( 3 << 12 ) ;
break;
case 2 :
break;
default:
return - V_192 ;
}
switch ( V_334 ) {
case 20 :
V_153 |= ( 1 << 10 ) ;
break;
case 24 :
V_153 |= ( 2 << 10 ) ;
break;
case 32 :
V_153 |= ( 3 << 10 ) ;
break;
case 16 :
break;
default:
return - V_192 ;
}
F_8 ( V_151 , V_88 , 0x7c00 , V_153 ) ;
return 0 ;
}
static int F_45 ( struct V_150 * V_151 ,
enum V_335 V_336 )
{
struct V_154 * V_155 = F_5 ( V_151 ) ;
switch ( V_336 ) {
case V_337 :
if ( V_338 == V_151 -> V_156 . V_339 ) {
F_8 ( V_151 , V_75 ,
V_340 | V_341 |
V_342 | V_343 ,
V_340 | V_341 |
V_342 | V_343 ) ;
F_30 ( 10 ) ;
F_8 ( V_151 , V_75 ,
V_239 | V_240 ,
V_239 | V_240 ) ;
F_8 ( V_151 , V_110 ,
V_344 | V_345 ,
V_346 | V_347 ) ;
F_8 ( V_151 , V_147 , 0x1 , 0x1 ) ;
F_8 ( V_151 , V_75 ,
V_348 , 0x3 ) ;
}
break;
case V_338 :
F_8 ( V_151 , V_75 ,
V_340 | V_343 |
V_239 | V_240 , 0 ) ;
F_8 ( V_151 , V_75 ,
V_348 , 0x1 ) ;
break;
case V_349 :
if ( V_155 -> V_175 . V_176 )
F_8 ( V_151 , V_75 ,
V_340 | V_341 |
V_342 | V_343 |
V_239 | V_240 ,
V_341 | V_342 ) ;
else
F_8 ( V_151 , V_75 ,
V_340 | V_341 |
V_342 | V_343 |
V_239 | V_240 , 0 ) ;
F_8 ( V_151 , V_147 , 0x1 , 0x0 ) ;
break;
default:
break;
}
V_151 -> V_156 . V_339 = V_336 ;
return 0 ;
}
static int F_46 ( struct V_150 * V_151 )
{
struct V_154 * V_155 = F_5 ( V_151 ) ;
switch ( F_11 ( V_151 , V_10 ) & V_350 ) {
case V_351 :
case V_352 :
F_47 ( & V_151 -> V_156 ,
V_353 ,
F_2 ( V_353 ) ) ;
F_48 ( & V_151 -> V_156 ,
V_354 ,
F_2 ( V_354 ) ) ;
break;
case V_355 :
F_47 ( & V_151 -> V_156 ,
V_356 ,
F_2 ( V_356 ) ) ;
F_48 ( & V_151 -> V_156 ,
V_357 ,
F_2 ( V_357 ) ) ;
break;
default:
F_17 ( V_151 -> V_2 ,
L_17 ) ;
return - V_358 ;
}
V_155 -> V_151 = V_151 ;
return 0 ;
}
static int F_49 ( struct V_150 * V_151 )
{
struct V_154 * V_155 = F_5 ( V_151 ) ;
F_29 ( V_155 -> V_235 , V_10 , 0 ) ;
F_50 ( V_155 -> V_172 , 1 , & V_155 -> V_170 ) ;
return 0 ;
}
static int F_51 ( struct V_150 * V_151 )
{
struct V_154 * V_155 = F_5 ( V_151 ) ;
F_52 ( V_155 -> V_235 , true ) ;
F_53 ( V_155 -> V_235 ) ;
return 0 ;
}
static int F_54 ( struct V_150 * V_151 )
{
struct V_154 * V_155 = F_5 ( V_151 ) ;
F_52 ( V_155 -> V_235 , false ) ;
F_55 ( V_155 -> V_235 ) ;
return 0 ;
}
static int F_56 ( struct V_359 * V_360 ,
const struct V_361 * V_261 )
{
struct V_362 * V_175 = F_57 ( & V_360 -> V_2 ) ;
struct V_154 * V_155 ;
int V_181 ;
unsigned int V_153 ;
V_155 = F_58 ( & V_360 -> V_2 ,
sizeof( struct V_154 ) ,
V_363 ) ;
if ( NULL == V_155 )
return - V_364 ;
F_59 ( V_360 , V_155 ) ;
if ( V_175 )
V_155 -> V_175 = * V_175 ;
if ( F_60 ( V_365 ) ) {
V_155 -> V_175 . V_366 = true ;
V_155 -> V_175 . V_367 = V_368 ;
V_155 -> V_175 . V_369 = true ;
V_155 -> V_175 . V_176 = 1 ;
}
V_155 -> V_235 = F_61 ( V_360 , & V_370 ) ;
if ( F_62 ( V_155 -> V_235 ) ) {
V_181 = F_63 ( V_155 -> V_235 ) ;
F_17 ( & V_360 -> V_2 , L_18 ,
V_181 ) ;
return V_181 ;
}
F_64 ( V_155 -> V_235 , V_35 , & V_153 ) ;
if ( V_153 != V_371 ) {
F_17 ( & V_360 -> V_2 ,
L_19 , V_153 ) ;
return - V_358 ;
}
F_29 ( V_155 -> V_235 , V_10 , 0 ) ;
F_28 ( V_155 -> V_235 , V_75 ,
V_372 | V_373 |
V_343 , V_343 ) ;
F_10 ( 100 ) ;
F_29 ( V_155 -> V_235 , V_10 , 0 ) ;
F_64 ( V_155 -> V_235 , V_33 , & V_153 ) ;
if ( V_153 >= 4 )
F_29 ( V_155 -> V_235 , V_126 , 0x0980 ) ;
else
F_29 ( V_155 -> V_235 , V_126 , 0x0d00 ) ;
V_181 = F_65 ( V_155 -> V_235 , V_374 ,
F_2 ( V_374 ) ) ;
if ( V_181 != 0 )
F_66 ( & V_360 -> V_2 , L_20 , V_181 ) ;
if ( V_155 -> V_175 . V_375 )
F_28 ( V_155 -> V_235 , V_38 ,
V_376 , V_376 ) ;
if ( V_155 -> V_175 . V_369 ) {
F_29 ( V_155 -> V_235 , V_27 , 0x0000 ) ;
F_29 ( V_155 -> V_235 , V_137 , 0x0010 ) ;
F_29 ( V_155 -> V_235 , V_138 , 0x0014 ) ;
F_28 ( V_155 -> V_235 , V_124 ,
V_159 , V_160 ) ;
F_28 ( V_155 -> V_235 , V_125 ,
V_377 , V_378 ) ;
F_28 ( V_155 -> V_235 , V_147 , 0x8 , 0x8 ) ;
}
if ( V_155 -> V_175 . V_176 ) {
F_28 ( V_155 -> V_235 , V_92 ,
V_306 , V_305 ) ;
V_155 -> V_193 = 0 ;
V_155 -> V_198 = V_304 ;
F_28 ( V_155 -> V_235 , V_75 ,
V_341 , V_341 ) ;
F_28 ( V_155 -> V_235 , V_76 ,
V_379 , V_379 ) ;
F_28 ( V_155 -> V_235 , V_123 ,
V_380 , V_381 ) ;
F_28 ( V_155 -> V_235 , V_145 ,
V_382 |
V_383 ,
V_384 | V_385 ) ;
switch ( V_155 -> V_175 . V_176 ) {
case 1 :
F_28 ( V_155 -> V_235 , V_19 ,
V_386 ,
V_387 ) ;
break;
case 2 :
F_28 ( V_155 -> V_235 , V_19 ,
V_386 ,
V_388 ) ;
break;
case 3 :
F_28 ( V_155 -> V_235 , V_19 ,
V_386 ,
V_389 ) ;
break;
default:
break;
}
}
if ( V_155 -> V_175 . V_366 ) {
F_28 ( V_155 -> V_235 , V_124 ,
V_390 ,
V_391 ) ;
switch ( V_155 -> V_175 . V_367 ) {
case V_368 :
F_28 ( V_155 -> V_235 , V_86 ,
V_392 ,
V_393 ) ;
break;
case V_394 :
F_28 ( V_155 -> V_235 , V_86 ,
V_392 ,
V_395 ) ;
F_28 ( V_155 -> V_235 , V_124 ,
V_396 ,
V_397 ) ;
break;
case V_398 :
F_28 ( V_155 -> V_235 , V_86 ,
V_392 ,
V_399 ) ;
F_28 ( V_155 -> V_235 , V_124 ,
V_400 ,
V_401 ) ;
break;
default:
break;
}
switch ( V_155 -> V_175 . V_402 ) {
case V_403 :
F_28 ( V_155 -> V_235 , V_86 ,
V_404 ,
V_405 ) ;
break;
case V_406 :
F_28 ( V_155 -> V_235 , V_86 ,
V_404 ,
V_407 ) ;
F_28 ( V_155 -> V_235 , V_124 ,
V_408 ,
V_409 ) ;
break;
default:
break;
}
switch ( V_155 -> V_175 . V_410 ) {
case V_411 :
F_28 ( V_155 -> V_235 , V_87 ,
V_412 ,
V_413 ) ;
F_28 ( V_155 -> V_235 , V_124 ,
V_414 ,
V_415 ) ;
break;
case V_416 :
case V_417 :
F_17 ( & V_360 -> V_2 ,
L_21 ) ;
break;
default:
break;
}
}
F_67 ( & V_360 -> V_2 ) ;
F_68 ( & V_360 -> V_2 ) ;
V_181 = F_69 ( & V_360 -> V_2 , & V_418 ,
V_419 , F_2 ( V_419 ) ) ;
if ( V_181 < 0 )
goto V_420;
F_70 ( & V_360 -> V_2 ) ;
return 0 ;
V_420:
F_71 ( & V_360 -> V_2 ) ;
return V_181 ;
}
static int F_72 ( struct V_359 * V_360 )
{
F_71 ( & V_360 -> V_2 ) ;
F_73 ( & V_360 -> V_2 ) ;
return 0 ;
}
