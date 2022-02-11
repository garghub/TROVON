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
int V_192 , V_193 ;
V_193 = V_157 -> V_194 / F_23 ( V_157 -> V_195 ,
V_84 , V_196 ) ;
V_192 = F_24 ( V_193 ) ;
if ( V_192 < 0 )
F_18 ( V_151 -> V_2 , L_5 ) ;
else
F_9 ( V_151 , V_86 ,
V_197 , V_192 << V_198 ) ;
return V_192 ;
}
static int F_25 ( struct V_187 * V_199 ,
struct V_187 * V_200 )
{
struct V_150 * V_151 = F_22 ( V_199 -> V_155 ) ;
struct V_156 * V_157 = F_6 ( V_151 ) ;
if ( V_157 -> V_201 == V_202 )
return 1 ;
else
return 0 ;
}
static int F_26 ( struct V_187 * V_199 ,
struct V_187 * V_200 )
{
struct V_150 * V_151 = F_22 ( V_199 -> V_155 ) ;
unsigned int V_3 , V_203 , V_153 ;
switch ( V_199 -> V_203 ) {
case 0 :
V_3 = V_97 ;
V_203 = 0 ;
break;
case 1 :
V_3 = V_97 ;
V_203 = 4 ;
break;
case 2 :
V_3 = V_15 ;
V_203 = 12 ;
break;
case 3 :
V_3 = V_96 ;
V_203 = 0 ;
break;
case 8 :
V_3 = V_96 ;
V_203 = 4 ;
break;
case 9 :
V_3 = V_96 ;
V_203 = 8 ;
break;
case 10 :
V_3 = V_96 ;
V_203 = 12 ;
break;
default:
return 0 ;
}
V_153 = ( F_12 ( V_151 , V_3 ) >> V_203 ) & 0xf ;
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
static int F_27 ( struct V_187 * V_199 ,
struct V_187 * V_200 )
{
struct V_150 * V_151 = F_22 ( V_199 -> V_155 ) ;
struct V_156 * V_157 = F_6 ( V_151 ) ;
if ( V_157 -> V_194 > V_157 -> V_204 [ V_205 ] * 384 )
return 1 ;
return 0 ;
}
int F_28 ( struct V_150 * V_151 ,
unsigned int V_206 , unsigned int V_207 )
{
unsigned int V_208 = 0 , V_209 = 0 ;
unsigned int V_210 = 0 , V_211 = 0 ;
if ( V_207 > V_212 )
return - V_213 ;
if ( V_206 & V_214 ) {
V_208 |= V_215 ;
V_209 = ( V_209 & ~ V_215 )
| ( V_207 << V_216 ) ;
}
if ( V_206 & V_217 ) {
V_208 |= V_218 ;
V_209 = ( V_209 & ~ V_218 )
| ( V_207 << V_219 ) ;
}
if ( V_206 & V_220 ) {
V_208 |= V_221 ;
V_209 = ( V_209 & ~ V_221 )
| ( V_207 << V_222 ) ;
}
if ( V_206 & V_223 ) {
V_208 |= V_224 ;
V_209 = ( V_209 & ~ V_224 )
| ( V_207 << V_225 ) ;
}
if ( V_206 & V_226 ) {
V_210 |= V_227 ;
V_211 = ( V_211 & ~ V_227 )
| ( V_207 << V_228 ) ;
}
if ( V_206 & V_229 ) {
V_210 |= V_230 ;
V_211 = ( V_211 & ~ V_230 )
| ( V_207 << V_231 ) ;
}
if ( V_206 & V_232 ) {
V_210 |= V_233 ;
V_211 = ( V_211 & ~ V_233 )
| ( V_207 << V_234 ) ;
}
if ( V_206 & V_235 ) {
V_210 |= V_236 ;
V_211 = ( V_211 & ~ V_236 )
| ( V_207 << V_237 ) ;
}
if ( V_208 )
F_9 ( V_151 , V_96 ,
V_208 , V_209 ) ;
if ( V_210 )
F_9 ( V_151 , V_97 ,
V_210 , V_211 ) ;
return 0 ;
}
static int F_29 ( struct V_187 * V_188 ,
struct V_189 * V_190 , int V_191 )
{
struct V_150 * V_151 = F_22 ( V_188 -> V_155 ) ;
struct V_156 * V_157 = F_6 ( V_151 ) ;
switch ( V_191 ) {
case V_238 :
F_30 ( V_157 -> V_195 , V_110 ,
V_239 , V_240 ) ;
F_30 ( V_157 -> V_195 , V_148 ,
0x0400 , 0x0400 ) ;
F_30 ( V_157 -> V_195 , V_75 ,
V_241 | V_242 |
V_243 , V_241 |
V_242 | V_243 ) ;
F_31 ( V_157 -> V_195 , V_108 , 0x3100 ) ;
F_31 ( V_157 -> V_195 , V_107 , 0x8009 ) ;
F_31 ( V_157 -> V_195 , V_244 +
V_245 , 0x9f00 ) ;
F_32 ( 20 ) ;
F_31 ( V_157 -> V_195 , V_107 , 0x8019 ) ;
break;
case V_246 :
F_31 ( V_157 -> V_195 , V_107 , 0x0004 ) ;
F_11 ( 30 ) ;
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
struct V_156 * V_157 = F_6 ( V_151 ) ;
switch ( V_191 ) {
case V_238 :
F_31 ( V_157 -> V_195 , V_244 +
V_247 , 0xb400 ) ;
F_31 ( V_157 -> V_195 , V_109 , 0x0772 ) ;
F_31 ( V_157 -> V_195 , V_107 , 0x805d ) ;
F_31 ( V_157 -> V_195 , V_107 , 0x831d ) ;
F_30 ( V_157 -> V_195 , V_148 ,
0x0300 , 0x0300 ) ;
F_30 ( V_157 -> V_195 , V_36 ,
V_248 | V_249 , 0 ) ;
F_11 ( 80 ) ;
F_31 ( V_157 -> V_195 , V_107 , 0x8019 ) ;
break;
case V_246 :
F_31 ( V_157 -> V_195 , V_244 +
V_247 , 0xb400 ) ;
F_31 ( V_157 -> V_195 , V_109 , 0x0772 ) ;
F_31 ( V_157 -> V_195 , V_107 , 0x803d ) ;
F_32 ( 10 ) ;
F_31 ( V_157 -> V_195 , V_107 , 0x831d ) ;
F_32 ( 10 ) ;
F_30 ( V_157 -> V_195 , V_36 ,
V_248 | V_249 ,
V_248 | V_249 ) ;
F_11 ( 20 ) ;
F_30 ( V_157 -> V_195 ,
V_148 , 0x0300 , 0x0 ) ;
F_31 ( V_157 -> V_195 , V_107 , 0x8019 ) ;
F_31 ( V_157 -> V_195 , V_109 , 0x0707 ) ;
F_31 ( V_157 -> V_195 , V_244 +
V_247 , 0xfc00 ) ;
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
case V_238 :
F_9 ( V_151 , V_76 ,
V_250 , V_250 ) ;
break;
case V_246 :
F_9 ( V_151 , V_76 ,
V_250 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_35 ( struct V_187 * V_188 ,
struct V_189 * V_190 , int V_191 )
{
struct V_150 * V_151 = F_22 ( V_188 -> V_155 ) ;
switch ( V_191 ) {
case V_238 :
F_9 ( V_151 , V_76 ,
V_251 , V_251 ) ;
break;
case V_246 :
F_9 ( V_151 , V_76 ,
V_251 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_36 ( struct V_252 * V_253 ,
struct V_254 * V_255 , struct V_256 * V_257 )
{
struct V_150 * V_151 = V_257 -> V_151 ;
struct V_156 * V_157 = F_6 ( V_151 ) ;
unsigned int V_258 = 0 , V_259 , V_260 ;
int V_261 , V_262 , V_263 ;
V_157 -> V_204 [ V_257 -> V_264 ] = F_37 ( V_255 ) ;
V_261 = F_38 ( V_157 -> V_194 , V_157 -> V_204 [ V_257 -> V_264 ] ) ;
if ( V_261 < 0 ) {
F_18 ( V_151 -> V_2 , L_6 ,
V_157 -> V_204 [ V_257 -> V_264 ] , V_257 -> V_264 ) ;
return - V_213 ;
}
V_263 = F_39 ( V_255 ) ;
if ( V_263 < 0 ) {
F_18 ( V_151 -> V_2 , L_7 , V_263 ) ;
return - V_213 ;
}
V_262 = V_263 > 32 ;
V_157 -> V_265 [ V_257 -> V_264 ] = V_157 -> V_204 [ V_257 -> V_264 ] * ( 32 << V_262 ) ;
F_40 ( V_257 -> V_2 , L_8 ,
V_157 -> V_265 [ V_257 -> V_264 ] , V_157 -> V_204 [ V_257 -> V_264 ] ) ;
F_40 ( V_257 -> V_2 , L_9 ,
V_262 , V_261 , V_257 -> V_264 ) ;
switch ( F_41 ( V_255 ) ) {
case 16 :
break;
case 20 :
V_258 |= V_266 ;
break;
case 24 :
V_258 |= V_267 ;
break;
case 8 :
V_258 |= V_268 ;
break;
default:
return - V_213 ;
}
switch ( V_257 -> V_264 ) {
case V_205 :
V_260 = V_269 | V_270 ;
V_259 = V_262 << V_271 |
V_261 << V_196 ;
F_9 ( V_151 , V_81 ,
V_272 , V_258 ) ;
F_9 ( V_151 , V_84 , V_260 , V_259 ) ;
break;
case V_273 :
V_260 = V_274 | V_275 ;
V_259 = V_262 << V_276 |
V_261 << V_277 ;
F_9 ( V_151 , V_82 ,
V_272 , V_258 ) ;
F_9 ( V_151 , V_84 , V_260 , V_259 ) ;
break;
default:
F_18 ( V_151 -> V_2 , L_10 , V_257 -> V_264 ) ;
return - V_213 ;
}
return 0 ;
}
static int F_42 ( struct V_256 * V_257 , unsigned int V_278 )
{
struct V_150 * V_151 = V_257 -> V_151 ;
struct V_156 * V_157 = F_6 ( V_151 ) ;
unsigned int V_279 = 0 ;
switch ( V_278 & V_280 ) {
case V_281 :
V_157 -> V_282 [ V_257 -> V_264 ] = 1 ;
break;
case V_283 :
V_279 |= V_284 ;
V_157 -> V_282 [ V_257 -> V_264 ] = 0 ;
break;
default:
return - V_213 ;
}
switch ( V_278 & V_285 ) {
case V_286 :
break;
case V_287 :
V_279 |= V_288 ;
break;
default:
return - V_213 ;
}
switch ( V_278 & V_289 ) {
case V_290 :
break;
case V_291 :
V_279 |= V_292 ;
break;
case V_293 :
V_279 |= V_294 ;
break;
case V_295 :
V_279 |= V_296 ;
break;
default:
return - V_213 ;
}
switch ( V_257 -> V_264 ) {
case V_205 :
F_9 ( V_151 , V_81 ,
V_297 | V_298 |
V_299 , V_279 ) ;
break;
case V_273 :
F_9 ( V_151 , V_82 ,
V_297 | V_298 |
V_299 , V_279 ) ;
break;
default:
F_18 ( V_151 -> V_2 , L_10 , V_257 -> V_264 ) ;
return - V_213 ;
}
return 0 ;
}
static int F_43 ( struct V_256 * V_257 ,
int V_300 , unsigned int V_301 , int V_302 )
{
struct V_150 * V_151 = V_257 -> V_151 ;
struct V_156 * V_157 = F_6 ( V_151 ) ;
unsigned int V_279 = 0 ;
switch ( V_300 ) {
case V_303 :
V_279 |= V_304 ;
break;
case V_202 :
V_279 |= V_305 ;
break;
case V_306 :
V_279 |= V_307 ;
break;
default:
F_18 ( V_151 -> V_2 , L_11 , V_300 ) ;
return - V_213 ;
}
F_9 ( V_151 , V_92 ,
V_308 , V_279 ) ;
V_157 -> V_194 = V_301 ;
if ( V_300 != V_306 )
V_157 -> V_201 = V_300 ;
F_40 ( V_257 -> V_2 , L_12 , V_301 , V_300 ) ;
return 0 ;
}
static int F_44 ( struct V_256 * V_257 , int V_309 , int V_199 ,
unsigned int V_310 , unsigned int V_311 )
{
struct V_150 * V_151 = V_257 -> V_151 ;
struct V_156 * V_157 = F_6 ( V_151 ) ;
struct V_312 V_313 ;
int V_182 ;
if ( V_199 == V_157 -> V_314 && V_310 == V_157 -> V_315 &&
V_311 == V_157 -> V_316 )
return 0 ;
if ( ! V_310 || ! V_311 ) {
F_40 ( V_151 -> V_2 , L_13 ) ;
V_157 -> V_315 = 0 ;
V_157 -> V_316 = 0 ;
F_9 ( V_151 , V_92 ,
V_308 , V_304 ) ;
return 0 ;
}
switch ( V_199 ) {
case V_317 :
F_9 ( V_151 , V_92 ,
V_318 , V_319 ) ;
break;
case V_320 :
case V_321 :
case V_322 :
case V_323 :
switch ( V_257 -> V_264 ) {
case V_205 :
F_9 ( V_151 , V_92 ,
V_318 , V_324 ) ;
break;
case V_273 :
F_9 ( V_151 , V_92 ,
V_318 , V_325 ) ;
break;
default:
F_18 ( V_151 -> V_2 , L_10 , V_257 -> V_264 ) ;
return - V_213 ;
}
break;
default:
F_18 ( V_151 -> V_2 , L_14 , V_199 ) ;
return - V_213 ;
}
V_182 = F_45 ( V_310 , V_311 , & V_313 ) ;
if ( V_182 < 0 ) {
F_18 ( V_151 -> V_2 , L_15 , V_310 ) ;
return V_182 ;
}
F_40 ( V_151 -> V_2 , L_16 ,
V_313 . V_326 , ( V_313 . V_326 ? 0 : V_313 . V_327 ) ,
V_313 . V_328 , V_313 . V_329 ) ;
F_10 ( V_151 , V_93 ,
V_313 . V_328 << V_330 | V_313 . V_329 ) ;
F_10 ( V_151 , V_94 ,
( V_313 . V_326 ? 0 : V_313 . V_327 ) << V_331 |
V_313 . V_326 << V_332 ) ;
V_157 -> V_315 = V_310 ;
V_157 -> V_316 = V_311 ;
V_157 -> V_314 = V_199 ;
return 0 ;
}
static int F_46 ( struct V_256 * V_257 , unsigned int V_333 ,
unsigned int V_334 , int V_335 , int V_336 )
{
struct V_150 * V_151 = V_257 -> V_151 ;
unsigned int V_153 = 0 ;
if ( V_334 || V_333 )
V_153 |= ( 1 << 14 ) ;
switch ( V_335 ) {
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
return - V_213 ;
}
switch ( V_336 ) {
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
return - V_213 ;
}
F_9 ( V_151 , V_88 , 0x7c00 , V_153 ) ;
return 0 ;
}
static int F_47 ( struct V_150 * V_151 ,
enum V_337 V_338 )
{
struct V_156 * V_157 = F_6 ( V_151 ) ;
switch ( V_338 ) {
case V_339 :
if ( V_340 == F_48 ( V_151 ) ) {
F_9 ( V_151 , V_75 ,
V_341 | V_342 |
V_343 | V_344 ,
V_341 | V_342 |
V_343 | V_344 ) ;
F_32 ( 10 ) ;
F_9 ( V_151 , V_75 ,
V_242 | V_243 ,
V_242 | V_243 ) ;
F_9 ( V_151 , V_110 ,
V_345 | V_346 ,
V_347 | V_348 ) ;
F_9 ( V_151 , V_147 , 0x1 , 0x1 ) ;
F_9 ( V_151 , V_75 ,
V_349 , 0x5 ) ;
}
break;
case V_340 :
F_9 ( V_151 , V_75 ,
V_341 | V_344 |
V_242 | V_243 , 0 ) ;
F_9 ( V_151 , V_75 ,
V_349 , 0x3 ) ;
break;
case V_350 :
if ( V_157 -> V_176 . V_177 )
F_9 ( V_151 , V_75 ,
V_341 | V_342 |
V_343 | V_344 |
V_242 | V_243 ,
V_342 | V_343 ) ;
else
F_9 ( V_151 , V_75 ,
V_341 | V_342 |
V_343 | V_344 |
V_242 | V_243 , 0 ) ;
F_9 ( V_151 , V_147 , 0x1 , 0x0 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_49 ( struct V_150 * V_151 )
{
struct V_154 * V_155 = F_5 ( V_151 ) ;
struct V_156 * V_157 = F_6 ( V_151 ) ;
switch ( F_12 ( V_151 , V_10 ) & V_351 ) {
case V_352 :
case V_353 :
F_50 ( V_155 ,
V_354 ,
F_2 ( V_354 ) ) ;
F_51 ( V_155 ,
V_355 ,
F_2 ( V_355 ) ) ;
break;
case V_356 :
F_50 ( V_155 ,
V_357 ,
F_2 ( V_357 ) ) ;
F_51 ( V_155 ,
V_358 ,
F_2 ( V_358 ) ) ;
break;
default:
F_18 ( V_151 -> V_2 ,
L_17 ) ;
return - V_359 ;
}
V_157 -> V_151 = V_151 ;
return 0 ;
}
static int F_52 ( struct V_150 * V_151 )
{
struct V_156 * V_157 = F_6 ( V_151 ) ;
F_31 ( V_157 -> V_195 , V_10 , 0 ) ;
F_53 ( V_157 -> V_173 , 1 , & V_157 -> V_171 ) ;
return 0 ;
}
static int F_54 ( struct V_150 * V_151 )
{
struct V_156 * V_157 = F_6 ( V_151 ) ;
F_55 ( V_157 -> V_195 , true ) ;
F_56 ( V_157 -> V_195 ) ;
return 0 ;
}
static int F_57 ( struct V_150 * V_151 )
{
struct V_156 * V_157 = F_6 ( V_151 ) ;
F_55 ( V_157 -> V_195 , false ) ;
F_58 ( V_157 -> V_195 ) ;
return 0 ;
}
static int F_59 ( struct V_360 * V_361 ,
const struct V_362 * V_264 )
{
struct V_363 * V_176 = F_60 ( & V_361 -> V_2 ) ;
struct V_156 * V_157 ;
int V_182 ;
unsigned int V_153 ;
V_157 = F_61 ( & V_361 -> V_2 ,
sizeof( struct V_156 ) ,
V_364 ) ;
if ( NULL == V_157 )
return - V_365 ;
F_62 ( V_361 , V_157 ) ;
if ( V_176 )
V_157 -> V_176 = * V_176 ;
if ( F_63 ( V_366 ) ) {
V_157 -> V_176 . V_367 = true ;
V_157 -> V_176 . V_368 = V_369 ;
V_157 -> V_176 . V_370 = true ;
V_157 -> V_176 . V_177 = 1 ;
}
V_157 -> V_195 = F_64 ( V_361 , & V_371 ) ;
if ( F_65 ( V_157 -> V_195 ) ) {
V_182 = F_66 ( V_157 -> V_195 ) ;
F_18 ( & V_361 -> V_2 , L_18 ,
V_182 ) ;
return V_182 ;
}
F_67 ( V_157 -> V_195 , V_35 , & V_153 ) ;
if ( V_153 != V_372 ) {
F_18 ( & V_361 -> V_2 ,
L_19 , V_153 ) ;
return - V_359 ;
}
F_31 ( V_157 -> V_195 , V_10 , 0 ) ;
F_30 ( V_157 -> V_195 , V_75 ,
V_373 | V_374 |
V_344 , V_344 ) ;
F_11 ( 100 ) ;
F_31 ( V_157 -> V_195 , V_10 , 0 ) ;
F_67 ( V_157 -> V_195 , V_33 , & V_153 ) ;
if ( V_153 >= 4 )
F_31 ( V_157 -> V_195 , V_126 , 0x0980 ) ;
else
F_31 ( V_157 -> V_195 , V_126 , 0x0d00 ) ;
V_182 = F_68 ( V_157 -> V_195 , V_375 ,
F_2 ( V_375 ) ) ;
if ( V_182 != 0 )
F_69 ( & V_361 -> V_2 , L_20 , V_182 ) ;
F_30 ( V_157 -> V_195 , V_147 ,
V_376 , V_376 ) ;
if ( V_157 -> V_176 . V_377 )
F_30 ( V_157 -> V_195 , V_38 ,
V_378 , V_378 ) ;
if ( V_157 -> V_176 . V_370 ) {
F_31 ( V_157 -> V_195 , V_27 , 0x0000 ) ;
F_31 ( V_157 -> V_195 , V_137 , 0x0010 ) ;
F_31 ( V_157 -> V_195 , V_138 , 0x0014 ) ;
F_30 ( V_157 -> V_195 , V_124 ,
V_160 , V_161 ) ;
F_30 ( V_157 -> V_195 , V_125 ,
V_379 , V_380 ) ;
}
if ( V_157 -> V_176 . V_177 ) {
F_30 ( V_157 -> V_195 , V_92 ,
V_308 , V_307 ) ;
V_157 -> V_194 = 0 ;
V_157 -> V_201 = V_306 ;
F_30 ( V_157 -> V_195 , V_75 ,
V_342 , V_342 ) ;
F_30 ( V_157 -> V_195 , V_76 ,
V_381 , V_381 ) ;
F_30 ( V_157 -> V_195 , V_123 ,
V_382 , V_383 ) ;
F_30 ( V_157 -> V_195 , V_145 ,
V_384 |
V_385 ,
V_386 | V_387 ) ;
switch ( V_157 -> V_176 . V_177 ) {
case 1 :
F_30 ( V_157 -> V_195 , V_19 ,
V_388 ,
V_389 ) ;
break;
case 2 :
F_30 ( V_157 -> V_195 , V_19 ,
V_388 ,
V_390 ) ;
break;
case 3 :
F_30 ( V_157 -> V_195 , V_19 ,
V_388 ,
V_391 ) ;
break;
default:
break;
}
}
if ( V_157 -> V_176 . V_367 ) {
F_30 ( V_157 -> V_195 , V_124 ,
V_392 ,
V_393 ) ;
switch ( V_157 -> V_176 . V_368 ) {
case V_369 :
F_30 ( V_157 -> V_195 , V_86 ,
V_394 ,
V_395 ) ;
break;
case V_396 :
F_30 ( V_157 -> V_195 , V_86 ,
V_394 ,
V_397 ) ;
F_30 ( V_157 -> V_195 , V_124 ,
V_398 ,
V_399 ) ;
break;
case V_400 :
F_30 ( V_157 -> V_195 , V_86 ,
V_394 ,
V_401 ) ;
F_30 ( V_157 -> V_195 , V_124 ,
V_402 ,
V_403 ) ;
break;
default:
break;
}
switch ( V_157 -> V_176 . V_404 ) {
case V_405 :
F_30 ( V_157 -> V_195 , V_86 ,
V_406 ,
V_407 ) ;
break;
case V_408 :
F_30 ( V_157 -> V_195 , V_86 ,
V_406 ,
V_409 ) ;
F_30 ( V_157 -> V_195 , V_124 ,
V_410 ,
V_411 ) ;
break;
default:
break;
}
switch ( V_157 -> V_176 . V_412 ) {
case V_413 :
F_30 ( V_157 -> V_195 , V_87 ,
V_414 ,
V_415 ) ;
F_30 ( V_157 -> V_195 , V_124 ,
V_416 ,
V_417 ) ;
break;
case V_418 :
case V_419 :
F_18 ( & V_361 -> V_2 ,
L_21 ) ;
break;
default:
break;
}
}
F_70 ( & V_361 -> V_2 ) ;
F_71 ( & V_361 -> V_2 ) ;
V_182 = F_72 ( & V_361 -> V_2 , & V_420 ,
V_421 , F_2 ( V_421 ) ) ;
if ( V_182 < 0 )
goto V_422;
F_73 ( & V_361 -> V_2 ) ;
return 0 ;
V_422:
F_74 ( & V_361 -> V_2 ) ;
return V_182 ;
}
static int F_75 ( struct V_360 * V_361 )
{
F_74 ( & V_361 -> V_2 ) ;
F_76 ( & V_361 -> V_2 ) ;
return 0 ;
}
