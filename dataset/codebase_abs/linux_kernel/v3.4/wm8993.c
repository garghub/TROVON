static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
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
case V_5 :
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
case V_6 :
case V_82 :
case V_83 :
case V_7 :
case V_8 :
case V_9 :
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
case V_112 :
case V_113 :
return true ;
default:
return false ;
}
}
static int F_3 ( struct V_114 * V_115 , unsigned int V_116 ,
unsigned int V_117 )
{
T_1 V_118 ;
unsigned int V_119 , V_120 , V_121 , V_122 ;
unsigned int div ;
int V_123 ;
div = 1 ;
V_115 -> V_124 = 0 ;
while ( ( V_116 / div ) > 13500000 ) {
div *= 2 ;
V_115 -> V_124 ++ ;
if ( div > 8 ) {
F_4 ( L_1 ,
V_116 ) ;
return - V_125 ;
}
}
F_5 ( L_2 , V_116 , V_117 ) ;
V_116 /= div ;
div = 0 ;
V_122 = V_117 * 2 ;
while ( V_122 < 90000000 ) {
div ++ ;
V_122 *= 2 ;
if ( div > 7 ) {
F_4 ( L_3 ,
V_117 ) ;
return - V_125 ;
}
}
V_115 -> V_126 = div ;
F_5 ( L_4 , V_122 ) ;
for ( V_123 = 0 ; V_123 < F_6 ( V_127 ) ; V_123 ++ ) {
if ( V_127 [ V_123 ] . V_128 <= V_116 && V_116 <= V_127 [ V_123 ] . V_129 ) {
V_115 -> V_130 = V_127 [ V_123 ] . V_130 ;
V_122 /= V_127 [ V_123 ] . V_131 ;
break;
}
}
if ( V_123 == F_6 ( V_127 ) ) {
F_4 ( L_5 , V_116 ) ;
return - V_125 ;
}
V_120 = V_122 / V_116 ;
V_115 -> V_132 = V_120 ;
V_121 = V_122 % V_116 ;
F_5 ( L_6 , V_121 ) ;
V_118 = V_133 * ( long long ) V_121 ;
F_7 ( V_118 , V_116 ) ;
V_119 = V_118 & 0xFFFFFFFF ;
if ( ( V_119 % 10 ) >= 5 )
V_119 += 5 ;
V_115 -> V_134 = V_119 / 10 ;
F_5 ( L_7 ,
V_115 -> V_132 , V_115 -> V_134 ,
V_115 -> V_130 , V_115 -> V_126 ,
V_115 -> V_124 ) ;
return 0 ;
}
static int F_8 ( struct V_135 * V_136 , int V_137 , int V_138 ,
unsigned int V_116 , unsigned int V_117 )
{
struct V_139 * V_140 = F_9 ( V_136 ) ;
struct V_141 * V_142 = F_10 ( V_136 -> V_2 ) ;
T_2 V_143 , V_144 , V_145 ;
struct V_114 V_115 ;
unsigned int V_146 ;
int V_147 ;
if ( V_116 == V_140 -> V_148 && V_117 == V_140 -> V_149 )
return 0 ;
if ( V_117 == 0 ) {
F_11 ( V_136 -> V_2 , L_8 ) ;
V_140 -> V_148 = 0 ;
V_140 -> V_149 = 0 ;
V_143 = F_12 ( V_136 , V_65 ) ;
V_143 &= ~ V_150 ;
F_13 ( V_136 , V_65 , V_143 ) ;
return 0 ;
}
V_147 = F_3 ( & V_115 , V_116 , V_117 ) ;
if ( V_147 != 0 )
return V_147 ;
V_145 = F_12 ( V_136 , V_69 ) ;
V_145 &= ~ V_151 ;
switch ( V_137 ) {
case V_152 :
break;
case V_153 :
V_145 |= 1 ;
break;
case V_154 :
V_145 |= 2 ;
break;
default:
F_14 ( V_136 -> V_2 , L_9 , V_137 ) ;
return - V_125 ;
}
V_143 = F_12 ( V_136 , V_65 ) ;
V_143 &= ~ V_150 ;
F_13 ( V_136 , V_65 , V_143 ) ;
if ( V_115 . V_134 )
V_143 |= V_155 ;
else
V_143 &= ~ V_155 ;
F_13 ( V_136 , V_65 , V_143 ) ;
F_13 ( V_136 , V_66 ,
( V_115 . V_126 << V_156 ) |
( V_115 . V_130 << V_157 ) ) ;
F_13 ( V_136 , V_67 , V_115 . V_134 ) ;
V_144 = F_12 ( V_136 , V_68 ) ;
V_144 &= ~ V_158 ;
V_144 |= V_115 . V_132 << V_159 ;
F_13 ( V_136 , V_68 , V_144 ) ;
V_145 &= ~ V_160 ;
V_145 |= V_115 . V_124 << V_161 ;
F_13 ( V_136 , V_69 , V_145 ) ;
if ( V_142 -> V_162 )
V_146 = F_15 ( 20 ) ;
else if ( V_116 < 1000000 )
V_146 = F_15 ( 3 ) ;
else
V_146 = F_15 ( 1 ) ;
F_16 ( & V_140 -> V_163 ) ;
F_13 ( V_136 , V_65 , V_143 | V_150 ) ;
V_146 = F_17 ( & V_140 -> V_163 , V_146 ) ;
if ( V_142 -> V_162 && ! V_146 )
F_18 ( V_136 -> V_2 , L_10 ) ;
F_11 ( V_136 -> V_2 , L_11 , V_116 , V_117 ) ;
V_140 -> V_148 = V_116 ;
V_140 -> V_149 = V_117 ;
V_140 -> V_164 = V_138 ;
return 0 ;
}
static int F_19 ( struct V_165 * V_166 , int V_137 , int V_138 ,
unsigned int V_116 , unsigned int V_117 )
{
return F_8 ( V_166 -> V_136 , V_137 , V_138 , V_116 , V_117 ) ;
}
static int F_20 ( struct V_135 * V_136 )
{
struct V_139 * V_140 = F_9 ( V_136 ) ;
unsigned int V_3 ;
switch ( V_140 -> V_167 ) {
case V_168 :
F_11 ( V_136 -> V_2 , L_12 , V_140 -> V_169 ) ;
V_3 = F_12 ( V_136 , V_16 ) ;
V_3 &= ~ ( V_170 | V_171 ) ;
if ( V_140 -> V_169 > 13500000 ) {
V_3 |= V_170 ;
V_140 -> V_172 = V_140 -> V_169 / 2 ;
} else {
V_3 &= ~ V_170 ;
V_140 -> V_172 = V_140 -> V_169 ;
}
F_13 ( V_136 , V_16 , V_3 ) ;
break;
case V_173 :
F_11 ( V_136 -> V_2 , L_13 ,
V_140 -> V_149 ) ;
V_3 = F_12 ( V_136 , V_16 ) ;
V_3 |= V_171 ;
if ( V_140 -> V_149 > 13500000 ) {
V_3 |= V_170 ;
V_140 -> V_172 = V_140 -> V_149 / 2 ;
} else {
V_3 &= ~ V_170 ;
V_140 -> V_172 = V_140 -> V_149 ;
}
F_13 ( V_136 , V_16 , V_3 ) ;
break;
default:
F_14 ( V_136 -> V_2 , L_14 ) ;
return - V_125 ;
}
F_11 ( V_136 -> V_2 , L_15 , V_140 -> V_172 ) ;
return 0 ;
}
static int F_21 ( struct V_174 * V_175 ,
struct V_176 * V_177 , int V_178 )
{
struct V_135 * V_136 = V_175 -> V_136 ;
switch ( V_178 ) {
case V_179 :
return F_20 ( V_136 ) ;
case V_180 :
break;
}
return 0 ;
}
static int F_22 ( struct V_176 * V_177 ,
struct V_181 * V_182 )
{
struct V_183 * V_184 = F_23 ( V_177 ) ;
struct V_174 * V_185 = V_184 -> V_186 [ 0 ] ;
struct V_135 * V_136 = V_185 -> V_136 ;
struct V_139 * V_140 = F_9 ( V_136 ) ;
int V_147 ;
if ( V_182 -> V_187 . integer . V_187 [ 0 ] == 0 ) {
if ( V_140 -> V_188 == 0 ) {
F_11 ( V_136 -> V_2 , L_16 ) ;
F_24 ( V_136 , V_81 ,
V_189 |
V_190 ,
0 ) ;
}
V_140 -> V_188 ++ ;
V_140 -> V_191 . V_192 = true ;
}
V_147 = F_25 ( V_177 , V_182 ) ;
if ( V_182 -> V_187 . integer . V_187 [ 0 ] == 1 ) {
if ( V_140 -> V_188 == 1 ) {
F_11 ( V_136 -> V_2 , L_17 ) ;
F_24 ( V_136 , V_81 ,
V_189 |
V_190 ,
V_189 |
V_190 ) ;
}
V_140 -> V_188 -- ;
V_140 -> V_191 . V_192 = false ;
}
F_11 ( V_136 -> V_2 , L_18 ,
V_140 -> V_188 ) ;
return V_147 ;
}
static int F_26 ( struct V_135 * V_136 ,
enum V_193 V_194 )
{
struct V_139 * V_140 = F_9 ( V_136 ) ;
int V_147 ;
F_27 ( V_136 , V_194 ) ;
switch ( V_194 ) {
case V_195 :
case V_196 :
F_24 ( V_136 , V_10 ,
V_197 , 0x2 ) ;
F_24 ( V_136 , V_11 ,
V_198 , V_198 ) ;
break;
case V_199 :
if ( V_136 -> V_200 . V_201 == V_202 ) {
V_147 = F_28 ( F_6 ( V_140 -> V_203 ) ,
V_140 -> V_203 ) ;
if ( V_147 != 0 )
return V_147 ;
F_29 ( V_140 -> V_204 , false ) ;
F_30 ( V_140 -> V_204 ) ;
F_31 ( V_136 ) ;
F_24 ( V_136 , V_63 ,
V_205 |
V_206 |
V_207 |
V_208 ,
V_205 |
V_206 |
V_207 |
V_208 ) ;
if ( ! V_140 -> V_209 . V_210 ||
! V_140 -> V_209 . V_211 )
F_24 ( V_136 , V_62 ,
V_212 ,
V_212 ) ;
F_24 ( V_136 , V_10 ,
V_197 |
V_213 ,
V_213 | 0x2 ) ;
F_32 ( 32 ) ;
F_24 ( V_136 , V_63 ,
V_208 |
V_205 , 0 ) ;
}
F_24 ( V_136 , V_10 ,
V_197 , 0x4 ) ;
F_24 ( V_136 , V_11 ,
V_198 , 0 ) ;
break;
case V_202 :
F_24 ( V_136 , V_62 ,
V_212 , 0 ) ;
F_24 ( V_136 , V_10 ,
V_197 | V_213 ,
0 ) ;
F_24 ( V_136 , V_63 ,
V_205 |
V_206 |
V_207 |
V_208 , 0 ) ;
F_29 ( V_140 -> V_204 , true ) ;
F_33 ( V_140 -> V_204 ) ;
F_34 ( F_6 ( V_140 -> V_203 ) ,
V_140 -> V_203 ) ;
break;
}
V_136 -> V_200 . V_201 = V_194 ;
return 0 ;
}
static int F_35 ( struct V_165 * V_214 ,
int V_215 , unsigned int V_216 , int V_217 )
{
struct V_135 * V_136 = V_214 -> V_136 ;
struct V_139 * V_140 = F_9 ( V_136 ) ;
switch ( V_215 ) {
case V_168 :
V_140 -> V_169 = V_216 ;
case V_173 :
V_140 -> V_167 = V_215 ;
break;
default:
return - V_125 ;
}
return 0 ;
}
static int F_36 ( struct V_165 * V_166 ,
unsigned int V_218 )
{
struct V_135 * V_136 = V_166 -> V_136 ;
struct V_139 * V_140 = F_9 ( V_136 ) ;
unsigned int V_219 = F_12 ( V_136 , V_13 ) ;
unsigned int V_220 = F_12 ( V_136 , V_18 ) ;
V_219 &= ~ ( V_221 | V_222 |
V_223 | V_224 ) ;
V_220 &= ~ V_225 ;
switch ( V_218 & V_226 ) {
case V_227 :
V_140 -> V_228 = 0 ;
break;
case V_229 :
V_220 |= V_225 ;
V_140 -> V_228 = 1 ;
break;
case V_230 :
V_219 |= V_221 ;
V_140 -> V_228 = 1 ;
break;
case V_231 :
V_219 |= V_221 ;
V_220 |= V_225 ;
V_140 -> V_228 = 1 ;
break;
default:
return - V_125 ;
}
switch ( V_218 & V_232 ) {
case V_233 :
V_219 |= V_223 ;
case V_234 :
V_219 |= 0x18 ;
break;
case V_235 :
V_219 |= 0x10 ;
break;
case V_236 :
break;
case V_237 :
V_219 |= 0x8 ;
break;
default:
return - V_125 ;
}
switch ( V_218 & V_232 ) {
case V_234 :
case V_233 :
switch ( V_218 & V_238 ) {
case V_239 :
break;
case V_240 :
V_219 |= V_222 ;
break;
default:
return - V_125 ;
}
break;
case V_235 :
case V_236 :
case V_237 :
switch ( V_218 & V_238 ) {
case V_239 :
break;
case V_241 :
V_219 |= V_222 | V_223 ;
break;
case V_240 :
V_219 |= V_222 ;
break;
case V_242 :
V_219 |= V_223 ;
break;
default:
return - V_125 ;
}
break;
default:
return - V_125 ;
}
F_13 ( V_136 , V_13 , V_219 ) ;
F_13 ( V_136 , V_18 , V_220 ) ;
return 0 ;
}
static int F_37 ( struct V_243 * V_244 ,
struct V_245 * V_246 ,
struct V_165 * V_166 )
{
struct V_135 * V_136 = V_166 -> V_136 ;
struct V_139 * V_140 = F_9 ( V_136 ) ;
int V_147 , V_123 , V_247 , V_248 , V_249 ;
unsigned int V_250 , V_251 , V_219 , V_220 ;
V_250 = F_12 ( V_136 , V_15 ) ;
V_250 &= ~ V_252 ;
V_251 = F_12 ( V_136 , V_70 ) ;
V_251 &= ~ ( V_253 | V_254 ) ;
V_219 = F_12 ( V_136 , V_13 ) ;
V_219 &= ~ V_255 ;
V_220 = F_12 ( V_136 , V_18 ) ;
V_220 &= ~ V_256 ;
V_140 -> V_257 = F_38 ( V_246 ) ;
V_140 -> V_258 = 2 * V_140 -> V_257 ;
if ( V_140 -> V_259 ) {
F_11 ( V_136 -> V_2 , L_19 ,
V_140 -> V_259 , V_140 -> V_260 ) ;
V_140 -> V_258 *= V_140 -> V_260 * V_140 -> V_259 ;
} else {
switch ( F_39 ( V_246 ) ) {
case V_261 :
V_140 -> V_258 *= 16 ;
break;
case V_262 :
V_140 -> V_258 *= 20 ;
V_219 |= 0x8 ;
break;
case V_263 :
V_140 -> V_258 *= 24 ;
V_219 |= 0x10 ;
break;
case V_264 :
V_140 -> V_258 *= 32 ;
V_219 |= 0x18 ;
break;
default:
return - V_125 ;
}
}
F_11 ( V_136 -> V_2 , L_20 , V_140 -> V_258 ) ;
V_147 = F_20 ( V_136 ) ;
if ( V_147 != 0 )
return V_147 ;
V_247 = 0 ;
V_248 = abs ( ( V_140 -> V_172 / V_265 [ 0 ] . V_131 )
- V_140 -> V_257 ) ;
for ( V_123 = 1 ; V_123 < F_6 ( V_265 ) ; V_123 ++ ) {
V_249 = abs ( ( V_140 -> V_172 /
V_265 [ V_123 ] . V_131 ) - V_140 -> V_257 ) ;
if ( V_249 < V_248 ) {
V_247 = V_123 ;
V_248 = V_249 ;
}
}
F_11 ( V_136 -> V_2 , L_21 ,
V_265 [ V_247 ] . V_131 ) ;
V_251 |= ( V_265 [ V_247 ] . V_266
<< V_267 ) ;
V_247 = 0 ;
V_248 = abs ( V_140 -> V_257 - V_268 [ 0 ] . V_269 ) ;
for ( V_123 = 1 ; V_123 < F_6 ( V_268 ) ; V_123 ++ ) {
V_249 = abs ( V_140 -> V_257 - V_268 [ V_123 ] . V_269 ) ;
if ( V_249 < V_248 ) {
V_247 = V_123 ;
V_248 = V_249 ;
}
}
F_11 ( V_136 -> V_2 , L_22 ,
V_268 [ V_247 ] . V_269 ) ;
V_251 |= ( V_268 [ V_247 ] . V_270
<< V_271 ) ;
V_247 = 0 ;
V_248 = V_272 ;
for ( V_123 = 0 ; V_123 < F_6 ( V_273 ) ; V_123 ++ ) {
V_249 = ( ( V_140 -> V_172 * 10 ) / V_273 [ V_123 ] . div )
- V_140 -> V_258 ;
if ( V_249 < 0 )
break;
if ( V_249 < V_248 ) {
V_247 = V_123 ;
V_248 = V_249 ;
}
}
V_140 -> V_258 = ( V_140 -> V_172 * 10 ) / V_273 [ V_247 ] . div ;
F_11 ( V_136 -> V_2 , L_23 ,
V_273 [ V_247 ] . div , V_140 -> V_258 ) ;
V_250 |= V_273 [ V_247 ] . V_274 << V_275 ;
F_11 ( V_136 -> V_2 , L_24 , V_140 -> V_258 / V_140 -> V_257 ) ;
V_220 |= V_140 -> V_258 / V_140 -> V_257 ;
F_13 ( V_136 , V_15 , V_250 ) ;
F_13 ( V_136 , V_70 , V_251 ) ;
F_13 ( V_136 , V_13 , V_219 ) ;
F_13 ( V_136 , V_18 , V_220 ) ;
if ( V_140 -> V_209 . V_276 ) {
T_2 V_277 = F_12 ( V_136 , V_85 ) ;
struct V_278 * V_279 ;
V_247 = 0 ;
V_248 = abs ( V_140 -> V_209 . V_280 [ 0 ] . V_269
- V_140 -> V_257 ) ;
for ( V_123 = 0 ; V_123 < V_140 -> V_209 . V_276 ; V_123 ++ ) {
V_249 = abs ( V_140 -> V_209 . V_280 [ V_123 ] . V_269
- V_140 -> V_257 ) ;
if ( V_249 < V_248 ) {
V_248 = V_249 ;
V_247 = V_123 ;
}
}
V_279 = & V_140 -> V_209 . V_280 [ V_247 ] ;
F_11 ( V_136 -> V_2 , L_25 ,
V_279 -> V_281 , V_279 -> V_269 ) ;
F_24 ( V_136 , V_85 , V_282 , 0 ) ;
for ( V_123 = 1 ; V_123 < F_6 ( V_279 -> V_283 ) ; V_123 ++ )
F_13 ( V_136 , V_85 + V_123 , V_279 -> V_283 [ V_123 ] ) ;
F_24 ( V_136 , V_85 , V_282 , V_277 ) ;
}
return 0 ;
}
static int F_40 ( struct V_165 * V_214 , int V_284 )
{
struct V_135 * V_136 = V_214 -> V_136 ;
unsigned int V_3 ;
V_3 = F_12 ( V_136 , V_19 ) ;
if ( V_284 )
V_3 |= V_285 ;
else
V_3 &= ~ V_285 ;
F_13 ( V_136 , V_19 , V_3 ) ;
return 0 ;
}
static int F_41 ( struct V_165 * V_166 , unsigned int V_286 ,
unsigned int V_287 , int V_288 , int V_289 )
{
struct V_135 * V_136 = V_166 -> V_136 ;
struct V_139 * V_140 = F_9 ( V_136 ) ;
int V_219 = 0 ;
int V_290 = 0 ;
if ( V_288 == 0 ) {
V_140 -> V_259 = 0 ;
goto V_291;
}
V_219 |= V_292 ;
V_290 |= V_293 ;
switch ( V_287 ) {
case 3 :
break;
case 0xc :
V_219 |= V_294 ;
break;
default:
return - V_125 ;
}
switch ( V_286 ) {
case 3 :
break;
case 0xc :
V_290 |= V_295 ;
break;
default:
return - V_125 ;
}
V_291:
V_140 -> V_260 = V_289 ;
V_140 -> V_259 = V_288 / 2 ;
F_24 ( V_136 , V_13 ,
V_292 | V_294 , V_219 ) ;
F_24 ( V_136 , V_14 ,
V_293 | V_295 , V_290 ) ;
return 0 ;
}
static T_3 F_42 ( int V_162 , void * V_296 )
{
struct V_139 * V_140 = V_296 ;
int V_297 , V_298 , V_147 ;
V_147 = F_43 ( V_140 -> V_204 , V_5 , & V_298 ) ;
if ( V_147 != 0 ) {
F_14 ( V_140 -> V_2 , L_26 ,
V_147 ) ;
return V_299 ;
}
V_147 = F_43 ( V_140 -> V_204 , V_28 , & V_297 ) ;
if ( V_147 != 0 ) {
F_14 ( V_140 -> V_2 , L_27 ,
V_147 ) ;
return V_299 ;
}
V_298 &= ~ ( V_297 | V_300 ) ;
if ( ! V_298 )
return V_299 ;
if ( V_298 & V_301 )
F_44 ( V_140 -> V_2 , L_28 ) ;
if ( V_298 & V_302 ) {
F_11 ( V_140 -> V_2 , L_29 ) ;
F_45 ( & V_140 -> V_163 ) ;
}
V_147 = F_46 ( V_140 -> V_204 , V_5 , V_298 ) ;
if ( V_147 != 0 )
F_14 ( V_140 -> V_2 , L_30 , V_147 ) ;
return V_303 ;
}
static int F_47 ( struct V_135 * V_136 )
{
struct V_139 * V_140 = F_9 ( V_136 ) ;
struct V_304 * V_200 = & V_136 -> V_200 ;
int V_147 ;
V_140 -> V_191 . V_305 = 1 ;
V_140 -> V_191 . V_306 = - 2 ;
V_140 -> V_191 . V_307 = - 2 ;
V_140 -> V_191 . V_308 = 1 ;
V_136 -> V_309 = V_140 -> V_204 ;
V_147 = F_48 ( V_136 , 8 , 16 , V_310 ) ;
if ( V_147 != 0 ) {
F_14 ( V_136 -> V_2 , L_31 , V_147 ) ;
return V_147 ;
}
V_140 -> V_188 = 2 ;
F_24 ( V_136 , V_21 ,
V_311 , V_311 ) ;
F_24 ( V_136 , V_25 ,
V_312 , V_312 ) ;
F_24 ( V_136 , V_84 ,
V_313 , 0 ) ;
F_24 ( V_136 , V_71 , V_314 , 0 ) ;
F_49 ( V_136 , V_140 -> V_209 . V_210 ,
V_140 -> V_209 . V_211 ,
V_140 -> V_209 . V_315 ,
V_140 -> V_209 . V_316 ,
V_140 -> V_209 . V_317 ,
V_140 -> V_209 . V_318 ,
V_140 -> V_209 . V_319 ,
V_140 -> V_209 . V_320 ) ;
V_147 = F_26 ( V_136 , V_199 ) ;
if ( V_147 != 0 )
return V_147 ;
F_50 ( V_136 , V_321 ,
F_6 ( V_321 ) ) ;
if ( V_140 -> V_209 . V_276 != 0 ) {
F_11 ( V_136 -> V_2 , L_32 ) ;
} else {
F_11 ( V_136 -> V_2 , L_33 ) ;
F_50 ( V_136 , V_322 ,
F_6 ( V_322 ) ) ;
}
F_51 ( V_200 , V_323 ,
F_6 ( V_323 ) ) ;
F_52 ( V_136 ) ;
F_53 ( V_200 , V_324 , F_6 ( V_324 ) ) ;
F_54 ( V_136 , V_140 -> V_209 . V_210 ,
V_140 -> V_209 . V_211 ) ;
if ( V_140 -> V_209 . V_210 && V_140 -> V_209 . V_211 )
V_136 -> V_200 . V_325 = 1 ;
return 0 ;
}
static int F_55 ( struct V_135 * V_136 )
{
struct V_139 * V_140 = F_9 ( V_136 ) ;
F_26 ( V_136 , V_202 ) ;
F_56 ( F_6 ( V_140 -> V_203 ) , V_140 -> V_203 ) ;
return 0 ;
}
static int F_57 ( struct V_135 * V_136 )
{
struct V_139 * V_140 = F_9 ( V_136 ) ;
int V_149 = V_140 -> V_149 ;
int V_148 = V_140 -> V_148 ;
int V_147 ;
V_147 = F_8 ( V_136 , 0 , 0 , 0 , 0 ) ;
if ( V_147 != 0 ) {
F_14 ( V_136 -> V_2 , L_34 ) ;
return V_147 ;
}
V_140 -> V_149 = V_149 ;
V_140 -> V_148 = V_148 ;
F_26 ( V_136 , V_202 ) ;
return 0 ;
}
static int F_58 ( struct V_135 * V_136 )
{
struct V_139 * V_140 = F_9 ( V_136 ) ;
int V_147 ;
F_26 ( V_136 , V_199 ) ;
if ( V_140 -> V_149 ) {
int V_149 = V_140 -> V_149 ;
int V_148 = V_140 -> V_148 ;
V_140 -> V_148 = 0 ;
V_140 -> V_149 = 0 ;
V_147 = F_8 ( V_136 , 0 , V_140 -> V_164 ,
V_148 , V_149 ) ;
if ( V_147 != 0 )
F_14 ( V_136 -> V_2 , L_35 ) ;
}
return 0 ;
}
static T_4 int F_59 ( struct V_141 * V_142 ,
const struct V_326 * V_327 )
{
struct V_139 * V_140 ;
unsigned int V_3 ;
int V_147 , V_123 ;
V_140 = F_60 ( & V_142 -> V_2 , sizeof( struct V_139 ) ,
V_328 ) ;
if ( V_140 == NULL )
return - V_329 ;
V_140 -> V_2 = & V_142 -> V_2 ;
F_61 ( & V_140 -> V_163 ) ;
V_140 -> V_204 = F_62 ( V_142 , & V_330 ) ;
if ( F_63 ( V_140 -> V_204 ) ) {
V_147 = F_64 ( V_140 -> V_204 ) ;
F_14 ( & V_142 -> V_2 , L_36 , V_147 ) ;
return V_147 ;
}
F_65 ( V_142 , V_140 ) ;
for ( V_123 = 0 ; V_123 < F_6 ( V_140 -> V_203 ) ; V_123 ++ )
V_140 -> V_203 [ V_123 ] . V_331 = V_332 [ V_123 ] ;
V_147 = F_66 ( & V_142 -> V_2 , F_6 ( V_140 -> V_203 ) ,
V_140 -> V_203 ) ;
if ( V_147 != 0 ) {
F_14 ( & V_142 -> V_2 , L_37 , V_147 ) ;
goto V_333;
}
V_147 = F_28 ( F_6 ( V_140 -> V_203 ) ,
V_140 -> V_203 ) ;
if ( V_147 != 0 ) {
F_14 ( & V_142 -> V_2 , L_38 , V_147 ) ;
goto V_334;
}
V_147 = F_43 ( V_140 -> V_204 , V_4 , & V_3 ) ;
if ( V_147 != 0 ) {
F_14 ( & V_142 -> V_2 , L_39 , V_147 ) ;
goto V_335;
}
if ( V_3 != 0x8993 ) {
F_14 ( & V_142 -> V_2 , L_40 , V_3 ) ;
V_147 = - V_125 ;
goto V_335;
}
V_147 = F_46 ( V_140 -> V_204 , V_4 , 0xffff ) ;
if ( V_147 != 0 )
goto V_335;
V_147 = F_67 ( V_140 -> V_204 , V_336 ,
F_6 ( V_336 ) ) ;
if ( V_147 != 0 )
F_18 ( V_140 -> V_2 , L_41 ,
V_147 ) ;
if ( V_142 -> V_162 ) {
V_147 = F_68 ( V_140 -> V_204 , V_26 ,
V_337 |
V_338 , 7 ) ;
if ( V_147 != 0 )
goto V_335;
V_147 = F_69 ( V_142 -> V_162 , NULL , F_42 ,
V_339 | V_340 ,
L_42 , V_140 ) ;
if ( V_147 != 0 )
goto V_335;
}
F_34 ( F_6 ( V_140 -> V_203 ) , V_140 -> V_203 ) ;
F_29 ( V_140 -> V_204 , true ) ;
V_147 = F_70 ( & V_142 -> V_2 ,
& V_341 , & V_342 , 1 ) ;
if ( V_147 != 0 ) {
F_14 ( & V_142 -> V_2 , L_43 , V_147 ) ;
goto V_343;
}
return 0 ;
V_343:
if ( V_142 -> V_162 )
F_71 ( V_142 -> V_162 , V_140 ) ;
V_335:
F_34 ( F_6 ( V_140 -> V_203 ) , V_140 -> V_203 ) ;
V_334:
F_56 ( F_6 ( V_140 -> V_203 ) , V_140 -> V_203 ) ;
V_333:
F_72 ( V_140 -> V_204 ) ;
return V_147 ;
}
static T_5 int F_73 ( struct V_141 * V_142 )
{
struct V_139 * V_140 = F_74 ( V_142 ) ;
F_75 ( & V_142 -> V_2 ) ;
if ( V_142 -> V_162 )
F_71 ( V_142 -> V_162 , V_140 ) ;
F_72 ( V_140 -> V_204 ) ;
F_34 ( F_6 ( V_140 -> V_203 ) , V_140 -> V_203 ) ;
F_56 ( F_6 ( V_140 -> V_203 ) , V_140 -> V_203 ) ;
return 0 ;
}
