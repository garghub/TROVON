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
struct V_156 * V_157 = F_6 ( V_151 ) ;
if ( V_152 ) {
F_7 ( V_155 , L_1 ) ;
F_8 ( V_155 ) ;
F_9 ( V_151 , V_149 , 0x4 , 0x0 ) ;
F_9 ( V_151 , V_17 ,
V_158 | V_159 ,
V_159 ) ;
F_10 ( V_151 , V_125 , 0x0004 ) ;
F_9 ( V_151 , V_124 ,
V_160 , V_161 ) ;
F_9 ( V_151 , V_16 ,
V_162 , V_162 ) ;
F_10 ( V_151 , V_145 , 0x00f0 ) ;
F_9 ( V_151 , V_17 ,
V_159 , V_159 ) ;
F_9 ( V_151 , V_17 ,
V_159 , 0 ) ;
F_11 ( 300 ) ;
V_153 = F_12 ( V_151 , V_18 ) & 0x7 ;
if ( V_153 == 0x1 || V_153 == 0x2 ) {
V_157 -> V_163 = V_164 ;
F_9 ( V_151 , V_26 , 0x8 , 0x8 ) ;
F_9 ( V_151 , V_27 , 0x40 , 0x40 ) ;
F_12 ( V_151 , V_27 ) ;
} else {
F_9 ( V_151 , V_149 , 0x4 , 0x4 ) ;
V_157 -> V_163 = V_165 ;
F_13 ( V_155 , L_1 ) ;
F_8 ( V_155 ) ;
}
} else {
F_9 ( V_151 , V_26 , 0x8 , 0x0 ) ;
F_9 ( V_151 , V_149 , 0x4 , 0x4 ) ;
V_157 -> V_163 = 0 ;
F_13 ( V_155 , L_1 ) ;
F_8 ( V_155 ) ;
}
return V_157 -> V_163 ;
}
void F_14 ( struct V_150 * V_151 )
{
struct V_156 * V_157 = F_6 ( V_151 ) ;
V_157 -> V_166 = V_157 -> V_163 ;
F_4 ( V_151 , 0 ) ;
}
void F_15 ( struct V_150 * V_151 )
{
struct V_156 * V_157 = F_6 ( V_151 ) ;
if ( V_157 -> V_166 )
F_4 ( V_151 , 1 ) ;
}
static int F_16 ( struct V_150 * V_151 )
{
int V_167 , V_153 ;
V_153 = F_12 ( V_151 , V_27 ) ;
V_167 = V_153 & 0xff80 ;
F_10 ( V_151 , V_27 , V_153 ) ;
if ( V_167 != 0 ) {
F_11 ( 20 ) ;
V_153 = F_12 ( V_151 , V_27 ) ;
F_10 ( V_151 , V_27 , V_153 ) ;
}
return V_167 ;
}
static int F_17 ( void * V_168 )
{
struct V_156 * V_157 = (struct V_156 * ) V_168 ;
struct V_169 * V_170 = & V_157 -> V_171 ;
struct V_172 * V_173 = V_157 -> V_173 ;
int V_153 , V_167 , V_174 = V_173 -> V_175 ;
if ( V_157 -> V_176 . V_177 == 1 )
V_153 = F_12 ( V_157 -> V_151 , V_19 ) & 0x0070 ;
else
V_153 = F_12 ( V_157 -> V_151 , V_19 ) & 0x0020 ;
switch ( V_153 ) {
case 0x30 :
case 0x0 :
if ( V_157 -> V_163 == 0 ) {
V_174 = F_4 ( V_157 -> V_151 , 1 ) ;
V_170 -> V_178 = 25 ;
break;
}
V_167 = 0 ;
if ( F_12 ( V_157 -> V_151 , V_26 ) & 0x4 ) {
V_174 = V_164 ;
V_167 = F_16 ( V_157 -> V_151 ) ;
switch ( V_167 ) {
case 0x2000 :
V_174 |= V_179 ;
break;
case 0x0400 :
V_174 |= V_180 ;
break;
case 0x0080 :
V_174 |= V_181 ;
break;
default:
F_18 ( V_157 -> V_151 -> V_2 ,
L_2 ,
V_167 ) ;
break;
}
}
if ( V_167 == 0 )
V_174 = V_157 -> V_163 ;
break;
case 0x70 :
case 0x10 :
case 0x20 :
V_174 = 0 ;
F_9 ( V_157 -> V_151 , V_26 , 0x1 , 0x0 ) ;
F_4 ( V_157 -> V_151 , 0 ) ;
V_170 -> V_178 = 150 ;
break;
default:
break;
}
return V_174 ;
}
int F_19 ( struct V_150 * V_151 ,
struct V_172 * V_173 )
{
struct V_156 * V_157 = F_6 ( V_151 ) ;
int V_182 ;
V_157 -> V_173 = V_173 ;
V_157 -> V_171 . V_183 = V_151 -> V_2 ;
V_157 -> V_171 . V_184 = L_3 ;
V_157 -> V_171 . V_174 = V_164 |
V_180 | V_179 | V_181 ;
V_157 -> V_171 . V_178 = 150 ;
V_157 -> V_171 . V_185 = true ;
V_157 -> V_171 . V_168 = (struct V_156 * ) V_157 ;
V_157 -> V_171 . V_186 = F_17 ;
V_182 = F_20 ( V_157 -> V_173 , 1 ,
& V_157 -> V_171 ) ;
if ( V_182 ) {
F_18 ( V_151 -> V_2 , L_4 ) ;
return V_182 ;
}
return 0 ;
}
static int F_21 ( struct V_187 * V_188 ,
struct V_189 * V_190 , int V_191 )
{
struct V_150 * V_151 = F_22 ( V_188 -> V_155 ) ;
struct V_156 * V_157 = F_6 ( V_151 ) ;
int V_192 = - V_193 ;
V_192 = F_23 ( V_157 -> V_194 ) ;
if ( V_192 < 0 )
F_18 ( V_151 -> V_2 , L_5 ) ;
else
F_9 ( V_151 , V_86 ,
V_195 , V_192 << V_196 ) ;
return V_192 ;
}
static int F_24 ( struct V_187 * V_197 ,
struct V_187 * V_198 )
{
struct V_150 * V_151 = F_22 ( V_197 -> V_155 ) ;
struct V_156 * V_157 = F_6 ( V_151 ) ;
if ( V_157 -> V_199 == V_200 )
return 1 ;
else
return 0 ;
}
static int F_25 ( struct V_187 * V_197 ,
struct V_187 * V_198 )
{
struct V_150 * V_151 = F_22 ( V_197 -> V_155 ) ;
unsigned int V_3 , V_201 , V_153 ;
switch ( V_197 -> V_201 ) {
case 0 :
V_3 = V_97 ;
V_201 = 0 ;
break;
case 1 :
V_3 = V_97 ;
V_201 = 4 ;
break;
case 2 :
V_3 = V_15 ;
V_201 = 12 ;
break;
case 3 :
V_3 = V_96 ;
V_201 = 0 ;
break;
case 8 :
V_3 = V_96 ;
V_201 = 4 ;
break;
case 9 :
V_3 = V_96 ;
V_201 = 8 ;
break;
case 10 :
V_3 = V_96 ;
V_201 = 12 ;
break;
default:
return 0 ;
}
V_153 = ( F_12 ( V_151 , V_3 ) >> V_201 ) & 0xf ;
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
static int F_26 ( struct V_187 * V_197 ,
struct V_187 * V_198 )
{
struct V_150 * V_151 = F_22 ( V_197 -> V_155 ) ;
struct V_156 * V_157 = F_6 ( V_151 ) ;
if ( V_157 -> V_194 > V_157 -> V_202 [ V_203 ] * 384 )
return 1 ;
return 0 ;
}
int F_27 ( struct V_150 * V_151 ,
unsigned int V_204 , unsigned int V_205 )
{
unsigned int V_206 = 0 , V_207 = 0 ;
unsigned int V_208 = 0 , V_209 = 0 ;
if ( V_205 > V_210 )
return - V_193 ;
if ( V_204 & V_211 ) {
V_206 |= V_212 ;
V_207 = ( V_207 & ~ V_212 )
| ( V_205 << V_213 ) ;
}
if ( V_204 & V_214 ) {
V_206 |= V_215 ;
V_207 = ( V_207 & ~ V_215 )
| ( V_205 << V_216 ) ;
}
if ( V_204 & V_217 ) {
V_206 |= V_218 ;
V_207 = ( V_207 & ~ V_218 )
| ( V_205 << V_219 ) ;
}
if ( V_204 & V_220 ) {
V_206 |= V_221 ;
V_207 = ( V_207 & ~ V_221 )
| ( V_205 << V_222 ) ;
}
if ( V_204 & V_223 ) {
V_208 |= V_224 ;
V_209 = ( V_209 & ~ V_224 )
| ( V_205 << V_225 ) ;
}
if ( V_204 & V_226 ) {
V_208 |= V_227 ;
V_209 = ( V_209 & ~ V_227 )
| ( V_205 << V_228 ) ;
}
if ( V_204 & V_229 ) {
V_208 |= V_230 ;
V_209 = ( V_209 & ~ V_230 )
| ( V_205 << V_231 ) ;
}
if ( V_204 & V_232 ) {
V_208 |= V_233 ;
V_209 = ( V_209 & ~ V_233 )
| ( V_205 << V_234 ) ;
}
if ( V_206 )
F_9 ( V_151 , V_96 ,
V_206 , V_207 ) ;
if ( V_208 )
F_9 ( V_151 , V_97 ,
V_208 , V_209 ) ;
return 0 ;
}
static int F_28 ( struct V_187 * V_188 ,
struct V_189 * V_190 , int V_191 )
{
struct V_150 * V_151 = F_22 ( V_188 -> V_155 ) ;
struct V_156 * V_157 = F_6 ( V_151 ) ;
switch ( V_191 ) {
case V_235 :
F_29 ( V_157 -> V_236 , V_110 ,
V_237 , V_238 ) ;
F_29 ( V_157 -> V_236 , V_148 ,
0x0400 , 0x0400 ) ;
F_29 ( V_157 -> V_236 , V_75 ,
V_239 | V_240 |
V_241 , V_239 |
V_240 | V_241 ) ;
F_30 ( V_157 -> V_236 , V_108 , 0x3100 ) ;
F_30 ( V_157 -> V_236 , V_107 , 0x8009 ) ;
F_30 ( V_157 -> V_236 , V_242 +
V_243 , 0x9f00 ) ;
F_31 ( 20 ) ;
F_30 ( V_157 -> V_236 , V_107 , 0x8019 ) ;
break;
case V_244 :
F_30 ( V_157 -> V_236 , V_107 , 0x0004 ) ;
F_11 ( 30 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_32 ( struct V_187 * V_188 ,
struct V_189 * V_190 , int V_191 )
{
struct V_150 * V_151 = F_22 ( V_188 -> V_155 ) ;
struct V_156 * V_157 = F_6 ( V_151 ) ;
switch ( V_191 ) {
case V_235 :
F_30 ( V_157 -> V_236 , V_242 +
V_245 , 0xb400 ) ;
F_30 ( V_157 -> V_236 , V_109 , 0x0772 ) ;
F_30 ( V_157 -> V_236 , V_107 , 0x805d ) ;
F_30 ( V_157 -> V_236 , V_107 , 0x831d ) ;
F_29 ( V_157 -> V_236 , V_148 ,
0x0300 , 0x0300 ) ;
F_29 ( V_157 -> V_236 , V_36 ,
V_246 | V_247 , 0 ) ;
F_11 ( 80 ) ;
F_30 ( V_157 -> V_236 , V_107 , 0x8019 ) ;
break;
case V_244 :
F_30 ( V_157 -> V_236 , V_242 +
V_245 , 0xb400 ) ;
F_30 ( V_157 -> V_236 , V_109 , 0x0772 ) ;
F_30 ( V_157 -> V_236 , V_107 , 0x803d ) ;
F_31 ( 10 ) ;
F_30 ( V_157 -> V_236 , V_107 , 0x831d ) ;
F_31 ( 10 ) ;
F_29 ( V_157 -> V_236 , V_36 ,
V_246 | V_247 ,
V_246 | V_247 ) ;
F_11 ( 20 ) ;
F_29 ( V_157 -> V_236 ,
V_148 , 0x0300 , 0x0 ) ;
F_30 ( V_157 -> V_236 , V_107 , 0x8019 ) ;
F_30 ( V_157 -> V_236 , V_109 , 0x0707 ) ;
F_30 ( V_157 -> V_236 , V_242 +
V_245 , 0xfc00 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_33 ( struct V_187 * V_188 ,
struct V_189 * V_190 , int V_191 )
{
struct V_150 * V_151 = F_22 ( V_188 -> V_155 ) ;
switch ( V_191 ) {
case V_235 :
F_9 ( V_151 , V_76 ,
V_248 , V_248 ) ;
break;
case V_244 :
F_9 ( V_151 , V_76 ,
V_248 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_34 ( struct V_187 * V_188 ,
struct V_189 * V_190 , int V_191 )
{
struct V_150 * V_151 = F_22 ( V_188 -> V_155 ) ;
switch ( V_191 ) {
case V_235 :
F_9 ( V_151 , V_76 ,
V_249 , V_249 ) ;
break;
case V_244 :
F_9 ( V_151 , V_76 ,
V_249 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_35 ( struct V_250 * V_251 ,
struct V_252 * V_253 , struct V_254 * V_255 )
{
struct V_150 * V_151 = V_255 -> V_151 ;
struct V_156 * V_157 = F_6 ( V_151 ) ;
unsigned int V_256 = 0 , V_257 , V_258 ;
int V_259 , V_260 , V_261 ;
V_157 -> V_202 [ V_255 -> V_262 ] = F_36 ( V_253 ) ;
V_259 = F_37 ( V_157 -> V_194 , V_157 -> V_202 [ V_255 -> V_262 ] ) ;
if ( V_259 < 0 ) {
F_18 ( V_151 -> V_2 , L_6 ,
V_157 -> V_202 [ V_255 -> V_262 ] , V_255 -> V_262 ) ;
return - V_193 ;
}
V_261 = F_38 ( V_253 ) ;
if ( V_261 < 0 ) {
F_18 ( V_151 -> V_2 , L_7 , V_261 ) ;
return - V_193 ;
}
V_260 = V_261 > 32 ;
V_157 -> V_263 [ V_255 -> V_262 ] = V_157 -> V_202 [ V_255 -> V_262 ] * ( 32 << V_260 ) ;
F_39 ( V_255 -> V_2 , L_8 ,
V_157 -> V_263 [ V_255 -> V_262 ] , V_157 -> V_202 [ V_255 -> V_262 ] ) ;
F_39 ( V_255 -> V_2 , L_9 ,
V_260 , V_259 , V_255 -> V_262 ) ;
switch ( F_40 ( V_253 ) ) {
case 16 :
break;
case 20 :
V_256 |= V_264 ;
break;
case 24 :
V_256 |= V_265 ;
break;
case 8 :
V_256 |= V_266 ;
break;
default:
return - V_193 ;
}
switch ( V_255 -> V_262 ) {
case V_203 :
V_258 = V_267 | V_268 ;
V_257 = V_260 << V_269 |
V_259 << V_270 ;
F_9 ( V_151 , V_81 ,
V_271 , V_256 ) ;
F_9 ( V_151 , V_84 , V_258 , V_257 ) ;
break;
case V_272 :
V_258 = V_273 | V_274 ;
V_257 = V_260 << V_275 |
V_259 << V_276 ;
F_9 ( V_151 , V_82 ,
V_271 , V_256 ) ;
F_9 ( V_151 , V_84 , V_258 , V_257 ) ;
break;
default:
F_18 ( V_151 -> V_2 , L_10 , V_255 -> V_262 ) ;
return - V_193 ;
}
return 0 ;
}
static int F_41 ( struct V_254 * V_255 , unsigned int V_277 )
{
struct V_150 * V_151 = V_255 -> V_151 ;
struct V_156 * V_157 = F_6 ( V_151 ) ;
unsigned int V_278 = 0 ;
switch ( V_277 & V_279 ) {
case V_280 :
V_157 -> V_281 [ V_255 -> V_262 ] = 1 ;
break;
case V_282 :
V_278 |= V_283 ;
V_157 -> V_281 [ V_255 -> V_262 ] = 0 ;
break;
default:
return - V_193 ;
}
switch ( V_277 & V_284 ) {
case V_285 :
break;
case V_286 :
V_278 |= V_287 ;
break;
default:
return - V_193 ;
}
switch ( V_277 & V_288 ) {
case V_289 :
break;
case V_290 :
V_278 |= V_291 ;
break;
case V_292 :
V_278 |= V_293 ;
break;
case V_294 :
V_278 |= V_295 ;
break;
default:
return - V_193 ;
}
switch ( V_255 -> V_262 ) {
case V_203 :
F_9 ( V_151 , V_81 ,
V_296 | V_297 |
V_298 , V_278 ) ;
break;
case V_272 :
F_9 ( V_151 , V_82 ,
V_296 | V_297 |
V_298 , V_278 ) ;
break;
default:
F_18 ( V_151 -> V_2 , L_10 , V_255 -> V_262 ) ;
return - V_193 ;
}
return 0 ;
}
static int F_42 ( struct V_254 * V_255 ,
int V_299 , unsigned int V_300 , int V_301 )
{
struct V_150 * V_151 = V_255 -> V_151 ;
struct V_156 * V_157 = F_6 ( V_151 ) ;
unsigned int V_278 = 0 ;
switch ( V_299 ) {
case V_302 :
V_278 |= V_303 ;
break;
case V_200 :
V_278 |= V_304 ;
break;
case V_305 :
V_278 |= V_306 ;
break;
default:
F_18 ( V_151 -> V_2 , L_11 , V_299 ) ;
return - V_193 ;
}
F_9 ( V_151 , V_92 ,
V_307 , V_278 ) ;
V_157 -> V_194 = V_300 ;
if ( V_299 != V_305 )
V_157 -> V_199 = V_299 ;
F_39 ( V_255 -> V_2 , L_12 , V_300 , V_299 ) ;
return 0 ;
}
static int F_43 ( struct V_254 * V_255 , int V_308 , int V_197 ,
unsigned int V_309 , unsigned int V_310 )
{
struct V_150 * V_151 = V_255 -> V_151 ;
struct V_156 * V_157 = F_6 ( V_151 ) ;
struct V_311 V_312 ;
int V_182 ;
if ( V_197 == V_157 -> V_313 && V_309 == V_157 -> V_314 &&
V_310 == V_157 -> V_315 )
return 0 ;
if ( ! V_309 || ! V_310 ) {
F_39 ( V_151 -> V_2 , L_13 ) ;
V_157 -> V_314 = 0 ;
V_157 -> V_315 = 0 ;
F_9 ( V_151 , V_92 ,
V_307 , V_303 ) ;
return 0 ;
}
switch ( V_197 ) {
case V_316 :
F_9 ( V_151 , V_92 ,
V_317 , V_318 ) ;
break;
case V_319 :
case V_320 :
case V_321 :
case V_322 :
switch ( V_255 -> V_262 ) {
case V_203 :
F_9 ( V_151 , V_92 ,
V_317 , V_323 ) ;
break;
case V_272 :
F_9 ( V_151 , V_92 ,
V_317 , V_324 ) ;
break;
default:
F_18 ( V_151 -> V_2 , L_10 , V_255 -> V_262 ) ;
return - V_193 ;
}
break;
default:
F_18 ( V_151 -> V_2 , L_14 , V_197 ) ;
return - V_193 ;
}
V_182 = F_44 ( V_309 , V_310 , & V_312 ) ;
if ( V_182 < 0 ) {
F_18 ( V_151 -> V_2 , L_15 , V_309 ) ;
return V_182 ;
}
F_39 ( V_151 -> V_2 , L_16 ,
V_312 . V_325 , ( V_312 . V_325 ? 0 : V_312 . V_326 ) ,
V_312 . V_327 , V_312 . V_328 ) ;
F_10 ( V_151 , V_93 ,
V_312 . V_327 << V_329 | V_312 . V_328 ) ;
F_10 ( V_151 , V_94 ,
( V_312 . V_325 ? 0 : V_312 . V_326 ) << V_330 |
V_312 . V_325 << V_331 ) ;
V_157 -> V_314 = V_309 ;
V_157 -> V_315 = V_310 ;
V_157 -> V_313 = V_197 ;
return 0 ;
}
static int F_45 ( struct V_254 * V_255 , unsigned int V_332 ,
unsigned int V_333 , int V_334 , int V_335 )
{
struct V_150 * V_151 = V_255 -> V_151 ;
unsigned int V_153 = 0 ;
if ( V_333 || V_332 )
V_153 |= ( 1 << 14 ) ;
switch ( V_334 ) {
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
return - V_193 ;
}
switch ( V_335 ) {
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
return - V_193 ;
}
F_9 ( V_151 , V_88 , 0x7c00 , V_153 ) ;
return 0 ;
}
static int F_46 ( struct V_150 * V_151 ,
enum V_336 V_337 )
{
struct V_156 * V_157 = F_6 ( V_151 ) ;
switch ( V_337 ) {
case V_338 :
if ( V_339 == F_47 ( V_151 ) ) {
F_9 ( V_151 , V_75 ,
V_340 | V_341 |
V_342 | V_343 ,
V_340 | V_341 |
V_342 | V_343 ) ;
F_31 ( 10 ) ;
F_9 ( V_151 , V_75 ,
V_240 | V_241 ,
V_240 | V_241 ) ;
F_9 ( V_151 , V_110 ,
V_344 | V_345 ,
V_346 | V_347 ) ;
F_9 ( V_151 , V_147 , 0x1 , 0x1 ) ;
F_9 ( V_151 , V_75 ,
V_348 , 0x3 ) ;
}
break;
case V_339 :
F_9 ( V_151 , V_75 ,
V_340 | V_343 |
V_240 | V_241 , 0 ) ;
F_9 ( V_151 , V_75 ,
V_348 , 0x1 ) ;
break;
case V_349 :
if ( V_157 -> V_176 . V_177 )
F_9 ( V_151 , V_75 ,
V_340 | V_341 |
V_342 | V_343 |
V_240 | V_241 ,
V_341 | V_342 ) ;
else
F_9 ( V_151 , V_75 ,
V_340 | V_341 |
V_342 | V_343 |
V_240 | V_241 , 0 ) ;
F_9 ( V_151 , V_147 , 0x1 , 0x0 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_48 ( struct V_150 * V_151 )
{
struct V_154 * V_155 = F_5 ( V_151 ) ;
struct V_156 * V_157 = F_6 ( V_151 ) ;
switch ( F_12 ( V_151 , V_10 ) & V_350 ) {
case V_351 :
case V_352 :
F_49 ( V_155 ,
V_353 ,
F_2 ( V_353 ) ) ;
F_50 ( V_155 ,
V_354 ,
F_2 ( V_354 ) ) ;
break;
case V_355 :
F_49 ( V_155 ,
V_356 ,
F_2 ( V_356 ) ) ;
F_50 ( V_155 ,
V_357 ,
F_2 ( V_357 ) ) ;
break;
default:
F_18 ( V_151 -> V_2 ,
L_17 ) ;
return - V_358 ;
}
V_157 -> V_151 = V_151 ;
return 0 ;
}
static int F_51 ( struct V_150 * V_151 )
{
struct V_156 * V_157 = F_6 ( V_151 ) ;
F_30 ( V_157 -> V_236 , V_10 , 0 ) ;
F_52 ( V_157 -> V_173 , 1 , & V_157 -> V_171 ) ;
return 0 ;
}
static int F_53 ( struct V_150 * V_151 )
{
struct V_156 * V_157 = F_6 ( V_151 ) ;
F_54 ( V_157 -> V_236 , true ) ;
F_55 ( V_157 -> V_236 ) ;
return 0 ;
}
static int F_56 ( struct V_150 * V_151 )
{
struct V_156 * V_157 = F_6 ( V_151 ) ;
F_54 ( V_157 -> V_236 , false ) ;
F_57 ( V_157 -> V_236 ) ;
return 0 ;
}
static int F_58 ( struct V_359 * V_360 ,
const struct V_361 * V_262 )
{
struct V_362 * V_176 = F_59 ( & V_360 -> V_2 ) ;
struct V_156 * V_157 ;
int V_182 ;
unsigned int V_153 ;
V_157 = F_60 ( & V_360 -> V_2 ,
sizeof( struct V_156 ) ,
V_363 ) ;
if ( NULL == V_157 )
return - V_364 ;
F_61 ( V_360 , V_157 ) ;
if ( V_176 )
V_157 -> V_176 = * V_176 ;
if ( F_62 ( V_365 ) ) {
V_157 -> V_176 . V_366 = true ;
V_157 -> V_176 . V_367 = V_368 ;
V_157 -> V_176 . V_369 = true ;
V_157 -> V_176 . V_177 = 1 ;
}
V_157 -> V_236 = F_63 ( V_360 , & V_370 ) ;
if ( F_64 ( V_157 -> V_236 ) ) {
V_182 = F_65 ( V_157 -> V_236 ) ;
F_18 ( & V_360 -> V_2 , L_18 ,
V_182 ) ;
return V_182 ;
}
F_66 ( V_157 -> V_236 , V_35 , & V_153 ) ;
if ( V_153 != V_371 ) {
F_18 ( & V_360 -> V_2 ,
L_19 , V_153 ) ;
return - V_358 ;
}
F_30 ( V_157 -> V_236 , V_10 , 0 ) ;
F_29 ( V_157 -> V_236 , V_75 ,
V_372 | V_373 |
V_343 , V_343 ) ;
F_11 ( 100 ) ;
F_30 ( V_157 -> V_236 , V_10 , 0 ) ;
F_66 ( V_157 -> V_236 , V_33 , & V_153 ) ;
if ( V_153 >= 4 )
F_30 ( V_157 -> V_236 , V_126 , 0x0980 ) ;
else
F_30 ( V_157 -> V_236 , V_126 , 0x0d00 ) ;
V_182 = F_67 ( V_157 -> V_236 , V_374 ,
F_2 ( V_374 ) ) ;
if ( V_182 != 0 )
F_68 ( & V_360 -> V_2 , L_20 , V_182 ) ;
if ( V_157 -> V_176 . V_375 )
F_29 ( V_157 -> V_236 , V_38 ,
V_376 , V_376 ) ;
if ( V_157 -> V_176 . V_369 ) {
F_30 ( V_157 -> V_236 , V_27 , 0x0000 ) ;
F_30 ( V_157 -> V_236 , V_137 , 0x0010 ) ;
F_30 ( V_157 -> V_236 , V_138 , 0x0014 ) ;
F_29 ( V_157 -> V_236 , V_124 ,
V_160 , V_161 ) ;
F_29 ( V_157 -> V_236 , V_125 ,
V_377 , V_378 ) ;
F_29 ( V_157 -> V_236 , V_147 , 0x8 , 0x8 ) ;
}
if ( V_157 -> V_176 . V_177 ) {
F_29 ( V_157 -> V_236 , V_92 ,
V_307 , V_306 ) ;
V_157 -> V_194 = 0 ;
V_157 -> V_199 = V_305 ;
F_29 ( V_157 -> V_236 , V_75 ,
V_341 , V_341 ) ;
F_29 ( V_157 -> V_236 , V_76 ,
V_379 , V_379 ) ;
F_29 ( V_157 -> V_236 , V_123 ,
V_380 , V_381 ) ;
F_29 ( V_157 -> V_236 , V_145 ,
V_382 |
V_383 ,
V_384 | V_385 ) ;
switch ( V_157 -> V_176 . V_177 ) {
case 1 :
F_29 ( V_157 -> V_236 , V_19 ,
V_386 ,
V_387 ) ;
break;
case 2 :
F_29 ( V_157 -> V_236 , V_19 ,
V_386 ,
V_388 ) ;
break;
case 3 :
F_29 ( V_157 -> V_236 , V_19 ,
V_386 ,
V_389 ) ;
break;
default:
break;
}
}
if ( V_157 -> V_176 . V_366 ) {
F_29 ( V_157 -> V_236 , V_124 ,
V_390 ,
V_391 ) ;
switch ( V_157 -> V_176 . V_367 ) {
case V_368 :
F_29 ( V_157 -> V_236 , V_86 ,
V_392 ,
V_393 ) ;
break;
case V_394 :
F_29 ( V_157 -> V_236 , V_86 ,
V_392 ,
V_395 ) ;
F_29 ( V_157 -> V_236 , V_124 ,
V_396 ,
V_397 ) ;
break;
case V_398 :
F_29 ( V_157 -> V_236 , V_86 ,
V_392 ,
V_399 ) ;
F_29 ( V_157 -> V_236 , V_124 ,
V_400 ,
V_401 ) ;
break;
default:
break;
}
switch ( V_157 -> V_176 . V_402 ) {
case V_403 :
F_29 ( V_157 -> V_236 , V_86 ,
V_404 ,
V_405 ) ;
break;
case V_406 :
F_29 ( V_157 -> V_236 , V_86 ,
V_404 ,
V_407 ) ;
F_29 ( V_157 -> V_236 , V_124 ,
V_408 ,
V_409 ) ;
break;
default:
break;
}
switch ( V_157 -> V_176 . V_410 ) {
case V_411 :
F_29 ( V_157 -> V_236 , V_87 ,
V_412 ,
V_413 ) ;
F_29 ( V_157 -> V_236 , V_124 ,
V_414 ,
V_415 ) ;
break;
case V_416 :
case V_417 :
F_18 ( & V_360 -> V_2 ,
L_21 ) ;
break;
default:
break;
}
}
F_69 ( & V_360 -> V_2 ) ;
F_70 ( & V_360 -> V_2 ) ;
V_182 = F_71 ( & V_360 -> V_2 , & V_418 ,
V_419 , F_2 ( V_419 ) ) ;
if ( V_182 < 0 )
goto V_420;
F_72 ( & V_360 -> V_2 ) ;
return 0 ;
V_420:
F_73 ( & V_360 -> V_2 ) ;
return V_182 ;
}
static int F_74 ( struct V_359 * V_360 )
{
F_73 ( & V_360 -> V_2 ) ;
F_75 ( & V_360 -> V_2 ) ;
return 0 ;
}
