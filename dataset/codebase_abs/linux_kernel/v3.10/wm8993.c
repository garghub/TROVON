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
static int F_22 ( struct V_135 * V_136 ,
enum V_181 V_182 )
{
struct V_139 * V_140 = F_9 ( V_136 ) ;
int V_147 ;
F_23 ( V_136 , V_182 ) ;
switch ( V_182 ) {
case V_183 :
case V_184 :
F_24 ( V_136 , V_10 ,
V_185 , 0x2 ) ;
F_24 ( V_136 , V_11 ,
V_186 , V_186 ) ;
break;
case V_187 :
if ( V_136 -> V_188 . V_189 == V_190 ) {
V_147 = F_25 ( F_6 ( V_140 -> V_191 ) ,
V_140 -> V_191 ) ;
if ( V_147 != 0 )
return V_147 ;
F_26 ( V_140 -> V_192 , false ) ;
F_27 ( V_140 -> V_192 ) ;
F_28 ( V_136 ) ;
F_24 ( V_136 , V_63 ,
V_193 |
V_194 |
V_195 |
V_196 ,
V_193 |
V_194 |
V_195 |
V_196 ) ;
if ( ! V_140 -> V_197 . V_198 ||
! V_140 -> V_197 . V_199 )
F_24 ( V_136 , V_62 ,
V_200 ,
V_200 ) ;
F_24 ( V_136 , V_10 ,
V_185 |
V_201 ,
V_201 | 0x2 ) ;
F_29 ( 32 ) ;
F_24 ( V_136 , V_63 ,
V_196 |
V_193 , 0 ) ;
}
F_24 ( V_136 , V_10 ,
V_185 , 0x4 ) ;
F_24 ( V_136 , V_11 ,
V_186 , 0 ) ;
break;
case V_190 :
F_24 ( V_136 , V_62 ,
V_200 , 0 ) ;
F_24 ( V_136 , V_10 ,
V_185 | V_201 ,
0 ) ;
F_24 ( V_136 , V_63 ,
V_193 |
V_194 |
V_195 |
V_196 , 0 ) ;
F_26 ( V_140 -> V_192 , true ) ;
F_30 ( V_140 -> V_192 ) ;
F_31 ( F_6 ( V_140 -> V_191 ) ,
V_140 -> V_191 ) ;
break;
}
V_136 -> V_188 . V_189 = V_182 ;
return 0 ;
}
static int F_32 ( struct V_165 * V_202 ,
int V_203 , unsigned int V_204 , int V_205 )
{
struct V_135 * V_136 = V_202 -> V_136 ;
struct V_139 * V_140 = F_9 ( V_136 ) ;
switch ( V_203 ) {
case V_168 :
V_140 -> V_169 = V_204 ;
case V_173 :
V_140 -> V_167 = V_203 ;
break;
default:
return - V_125 ;
}
return 0 ;
}
static int F_33 ( struct V_165 * V_166 ,
unsigned int V_206 )
{
struct V_135 * V_136 = V_166 -> V_136 ;
struct V_139 * V_140 = F_9 ( V_136 ) ;
unsigned int V_207 = F_12 ( V_136 , V_13 ) ;
unsigned int V_208 = F_12 ( V_136 , V_18 ) ;
V_207 &= ~ ( V_209 | V_210 |
V_211 | V_212 ) ;
V_208 &= ~ V_213 ;
switch ( V_206 & V_214 ) {
case V_215 :
V_140 -> V_216 = 0 ;
break;
case V_217 :
V_208 |= V_213 ;
V_140 -> V_216 = 1 ;
break;
case V_218 :
V_207 |= V_209 ;
V_140 -> V_216 = 1 ;
break;
case V_219 :
V_207 |= V_209 ;
V_208 |= V_213 ;
V_140 -> V_216 = 1 ;
break;
default:
return - V_125 ;
}
switch ( V_206 & V_220 ) {
case V_221 :
V_207 |= V_211 ;
case V_222 :
V_207 |= 0x18 ;
break;
case V_223 :
V_207 |= 0x10 ;
break;
case V_224 :
break;
case V_225 :
V_207 |= 0x8 ;
break;
default:
return - V_125 ;
}
switch ( V_206 & V_220 ) {
case V_222 :
case V_221 :
switch ( V_206 & V_226 ) {
case V_227 :
break;
case V_228 :
V_207 |= V_210 ;
break;
default:
return - V_125 ;
}
break;
case V_223 :
case V_224 :
case V_225 :
switch ( V_206 & V_226 ) {
case V_227 :
break;
case V_229 :
V_207 |= V_210 | V_211 ;
break;
case V_228 :
V_207 |= V_210 ;
break;
case V_230 :
V_207 |= V_211 ;
break;
default:
return - V_125 ;
}
break;
default:
return - V_125 ;
}
F_13 ( V_136 , V_13 , V_207 ) ;
F_13 ( V_136 , V_18 , V_208 ) ;
return 0 ;
}
static int F_34 ( struct V_231 * V_232 ,
struct V_233 * V_234 ,
struct V_165 * V_166 )
{
struct V_135 * V_136 = V_166 -> V_136 ;
struct V_139 * V_140 = F_9 ( V_136 ) ;
int V_147 , V_123 , V_235 , V_236 , V_237 ;
unsigned int V_238 , V_239 , V_207 , V_208 ;
V_238 = F_12 ( V_136 , V_15 ) ;
V_238 &= ~ V_240 ;
V_239 = F_12 ( V_136 , V_70 ) ;
V_239 &= ~ ( V_241 | V_242 ) ;
V_207 = F_12 ( V_136 , V_13 ) ;
V_207 &= ~ V_243 ;
V_208 = F_12 ( V_136 , V_18 ) ;
V_208 &= ~ V_244 ;
V_140 -> V_245 = F_35 ( V_234 ) ;
V_140 -> V_246 = 2 * V_140 -> V_245 ;
if ( V_140 -> V_247 ) {
F_11 ( V_136 -> V_2 , L_16 ,
V_140 -> V_247 , V_140 -> V_248 ) ;
V_140 -> V_246 *= V_140 -> V_248 * V_140 -> V_247 ;
} else {
switch ( F_36 ( V_234 ) ) {
case V_249 :
V_140 -> V_246 *= 16 ;
break;
case V_250 :
V_140 -> V_246 *= 20 ;
V_207 |= 0x8 ;
break;
case V_251 :
V_140 -> V_246 *= 24 ;
V_207 |= 0x10 ;
break;
case V_252 :
V_140 -> V_246 *= 32 ;
V_207 |= 0x18 ;
break;
default:
return - V_125 ;
}
}
F_11 ( V_136 -> V_2 , L_17 , V_140 -> V_246 ) ;
V_147 = F_20 ( V_136 ) ;
if ( V_147 != 0 )
return V_147 ;
V_235 = 0 ;
V_236 = abs ( ( V_140 -> V_172 / V_253 [ 0 ] . V_131 )
- V_140 -> V_245 ) ;
for ( V_123 = 1 ; V_123 < F_6 ( V_253 ) ; V_123 ++ ) {
V_237 = abs ( ( V_140 -> V_172 /
V_253 [ V_123 ] . V_131 ) - V_140 -> V_245 ) ;
if ( V_237 < V_236 ) {
V_235 = V_123 ;
V_236 = V_237 ;
}
}
F_11 ( V_136 -> V_2 , L_18 ,
V_253 [ V_235 ] . V_131 ) ;
V_239 |= ( V_253 [ V_235 ] . V_254
<< V_255 ) ;
V_235 = 0 ;
V_236 = abs ( V_140 -> V_245 - V_256 [ 0 ] . V_257 ) ;
for ( V_123 = 1 ; V_123 < F_6 ( V_256 ) ; V_123 ++ ) {
V_237 = abs ( V_140 -> V_245 - V_256 [ V_123 ] . V_257 ) ;
if ( V_237 < V_236 ) {
V_235 = V_123 ;
V_236 = V_237 ;
}
}
F_11 ( V_136 -> V_2 , L_19 ,
V_256 [ V_235 ] . V_257 ) ;
V_239 |= ( V_256 [ V_235 ] . V_258
<< V_259 ) ;
V_235 = 0 ;
V_236 = V_260 ;
for ( V_123 = 0 ; V_123 < F_6 ( V_261 ) ; V_123 ++ ) {
V_237 = ( ( V_140 -> V_172 * 10 ) / V_261 [ V_123 ] . div )
- V_140 -> V_246 ;
if ( V_237 < 0 )
break;
if ( V_237 < V_236 ) {
V_235 = V_123 ;
V_236 = V_237 ;
}
}
V_140 -> V_246 = ( V_140 -> V_172 * 10 ) / V_261 [ V_235 ] . div ;
F_11 ( V_136 -> V_2 , L_20 ,
V_261 [ V_235 ] . div , V_140 -> V_246 ) ;
V_238 |= V_261 [ V_235 ] . V_262 << V_263 ;
F_11 ( V_136 -> V_2 , L_21 , V_140 -> V_246 / V_140 -> V_245 ) ;
V_208 |= V_140 -> V_246 / V_140 -> V_245 ;
F_13 ( V_136 , V_15 , V_238 ) ;
F_13 ( V_136 , V_70 , V_239 ) ;
F_13 ( V_136 , V_13 , V_207 ) ;
F_13 ( V_136 , V_18 , V_208 ) ;
if ( V_140 -> V_197 . V_264 ) {
T_2 V_265 = F_12 ( V_136 , V_85 ) ;
struct V_266 * V_267 ;
V_235 = 0 ;
V_236 = abs ( V_140 -> V_197 . V_268 [ 0 ] . V_257
- V_140 -> V_245 ) ;
for ( V_123 = 0 ; V_123 < V_140 -> V_197 . V_264 ; V_123 ++ ) {
V_237 = abs ( V_140 -> V_197 . V_268 [ V_123 ] . V_257
- V_140 -> V_245 ) ;
if ( V_237 < V_236 ) {
V_236 = V_237 ;
V_235 = V_123 ;
}
}
V_267 = & V_140 -> V_197 . V_268 [ V_235 ] ;
F_11 ( V_136 -> V_2 , L_22 ,
V_267 -> V_269 , V_267 -> V_257 ) ;
F_24 ( V_136 , V_85 , V_270 , 0 ) ;
for ( V_123 = 1 ; V_123 < F_6 ( V_267 -> V_271 ) ; V_123 ++ )
F_13 ( V_136 , V_85 + V_123 , V_267 -> V_271 [ V_123 ] ) ;
F_24 ( V_136 , V_85 , V_270 , V_265 ) ;
}
return 0 ;
}
static int F_37 ( struct V_165 * V_202 , int V_272 )
{
struct V_135 * V_136 = V_202 -> V_136 ;
unsigned int V_3 ;
V_3 = F_12 ( V_136 , V_19 ) ;
if ( V_272 )
V_3 |= V_273 ;
else
V_3 &= ~ V_273 ;
F_13 ( V_136 , V_19 , V_3 ) ;
return 0 ;
}
static int F_38 ( struct V_165 * V_166 , unsigned int V_274 ,
unsigned int V_275 , int V_276 , int V_277 )
{
struct V_135 * V_136 = V_166 -> V_136 ;
struct V_139 * V_140 = F_9 ( V_136 ) ;
int V_207 = 0 ;
int V_278 = 0 ;
if ( V_276 == 0 ) {
V_140 -> V_247 = 0 ;
goto V_279;
}
V_207 |= V_280 ;
V_278 |= V_281 ;
switch ( V_275 ) {
case 3 :
break;
case 0xc :
V_207 |= V_282 ;
break;
default:
return - V_125 ;
}
switch ( V_274 ) {
case 3 :
break;
case 0xc :
V_278 |= V_283 ;
break;
default:
return - V_125 ;
}
V_279:
V_140 -> V_248 = V_277 ;
V_140 -> V_247 = V_276 / 2 ;
F_24 ( V_136 , V_13 ,
V_280 | V_282 , V_207 ) ;
F_24 ( V_136 , V_14 ,
V_281 | V_283 , V_278 ) ;
return 0 ;
}
static T_3 F_39 ( int V_162 , void * V_284 )
{
struct V_139 * V_140 = V_284 ;
int V_285 , V_286 , V_147 ;
V_147 = F_40 ( V_140 -> V_192 , V_5 , & V_286 ) ;
if ( V_147 != 0 ) {
F_14 ( V_140 -> V_2 , L_23 ,
V_147 ) ;
return V_287 ;
}
V_147 = F_40 ( V_140 -> V_192 , V_28 , & V_285 ) ;
if ( V_147 != 0 ) {
F_14 ( V_140 -> V_2 , L_24 ,
V_147 ) ;
return V_287 ;
}
V_286 &= ~ ( V_285 | V_288 ) ;
if ( ! V_286 )
return V_287 ;
if ( V_286 & V_289 )
F_41 ( V_140 -> V_2 , L_25 ) ;
if ( V_286 & V_290 ) {
F_11 ( V_140 -> V_2 , L_26 ) ;
F_42 ( & V_140 -> V_163 ) ;
}
V_147 = F_43 ( V_140 -> V_192 , V_5 , V_286 ) ;
if ( V_147 != 0 )
F_14 ( V_140 -> V_2 , L_27 , V_147 ) ;
return V_291 ;
}
static int F_44 ( struct V_135 * V_136 )
{
struct V_139 * V_140 = F_9 ( V_136 ) ;
struct V_292 * V_188 = & V_136 -> V_188 ;
int V_147 ;
V_140 -> V_293 . V_294 = 1 ;
V_140 -> V_293 . V_295 = - 2 ;
V_140 -> V_293 . V_296 = - 2 ;
V_140 -> V_293 . V_297 = 1 ;
V_136 -> V_298 = V_140 -> V_192 ;
V_147 = F_45 ( V_136 , 8 , 16 , V_299 ) ;
if ( V_147 != 0 ) {
F_14 ( V_136 -> V_2 , L_28 , V_147 ) ;
return V_147 ;
}
F_24 ( V_136 , V_21 ,
V_300 , V_300 ) ;
F_24 ( V_136 , V_25 ,
V_301 , V_301 ) ;
F_24 ( V_136 , V_84 ,
V_302 , 0 ) ;
F_24 ( V_136 , V_71 , V_303 , 0 ) ;
F_46 ( V_136 , V_140 -> V_197 . V_198 ,
V_140 -> V_197 . V_199 ,
V_140 -> V_197 . V_304 ,
V_140 -> V_197 . V_305 ,
V_140 -> V_197 . V_306 ,
V_140 -> V_197 . V_307 ,
V_140 -> V_197 . V_308 ,
V_140 -> V_197 . V_309 ,
V_140 -> V_197 . V_310 ,
V_140 -> V_197 . V_311 ) ;
V_147 = F_22 ( V_136 , V_187 ) ;
if ( V_147 != 0 )
return V_147 ;
F_47 ( V_136 , V_312 ,
F_6 ( V_312 ) ) ;
if ( V_140 -> V_197 . V_264 != 0 ) {
F_11 ( V_136 -> V_2 , L_29 ) ;
} else {
F_11 ( V_136 -> V_2 , L_30 ) ;
F_47 ( V_136 , V_313 ,
F_6 ( V_313 ) ) ;
}
F_48 ( V_188 , V_314 ,
F_6 ( V_314 ) ) ;
F_49 ( V_136 ) ;
F_50 ( V_188 , V_315 , F_6 ( V_315 ) ) ;
F_51 ( V_136 , V_140 -> V_197 . V_198 ,
V_140 -> V_197 . V_199 ) ;
if ( V_140 -> V_197 . V_198 && V_140 -> V_197 . V_199 )
V_136 -> V_188 . V_316 = 1 ;
return 0 ;
}
static int F_52 ( struct V_135 * V_136 )
{
struct V_139 * V_140 = F_9 ( V_136 ) ;
F_22 ( V_136 , V_190 ) ;
F_53 ( F_6 ( V_140 -> V_191 ) , V_140 -> V_191 ) ;
return 0 ;
}
static int F_54 ( struct V_135 * V_136 )
{
struct V_139 * V_140 = F_9 ( V_136 ) ;
int V_149 = V_140 -> V_149 ;
int V_148 = V_140 -> V_148 ;
int V_147 ;
V_147 = F_8 ( V_136 , 0 , 0 , 0 , 0 ) ;
if ( V_147 != 0 ) {
F_14 ( V_136 -> V_2 , L_31 ) ;
return V_147 ;
}
V_140 -> V_149 = V_149 ;
V_140 -> V_148 = V_148 ;
F_22 ( V_136 , V_190 ) ;
return 0 ;
}
static int F_55 ( struct V_135 * V_136 )
{
struct V_139 * V_140 = F_9 ( V_136 ) ;
int V_147 ;
F_22 ( V_136 , V_187 ) ;
if ( V_140 -> V_149 ) {
int V_149 = V_140 -> V_149 ;
int V_148 = V_140 -> V_148 ;
V_140 -> V_148 = 0 ;
V_140 -> V_149 = 0 ;
V_147 = F_8 ( V_136 , 0 , V_140 -> V_164 ,
V_148 , V_149 ) ;
if ( V_147 != 0 )
F_14 ( V_136 -> V_2 , L_32 ) ;
}
return 0 ;
}
static int F_56 ( struct V_141 * V_142 ,
const struct V_317 * V_318 )
{
struct V_139 * V_140 ;
unsigned int V_3 ;
int V_147 , V_123 ;
V_140 = F_57 ( & V_142 -> V_2 , sizeof( struct V_139 ) ,
V_319 ) ;
if ( V_140 == NULL )
return - V_320 ;
V_140 -> V_2 = & V_142 -> V_2 ;
F_58 ( & V_140 -> V_163 ) ;
V_140 -> V_192 = F_59 ( V_142 , & V_321 ) ;
if ( F_60 ( V_140 -> V_192 ) ) {
V_147 = F_61 ( V_140 -> V_192 ) ;
F_14 ( & V_142 -> V_2 , L_33 , V_147 ) ;
return V_147 ;
}
F_62 ( V_142 , V_140 ) ;
for ( V_123 = 0 ; V_123 < F_6 ( V_140 -> V_191 ) ; V_123 ++ )
V_140 -> V_191 [ V_123 ] . V_322 = V_323 [ V_123 ] ;
V_147 = F_63 ( & V_142 -> V_2 , F_6 ( V_140 -> V_191 ) ,
V_140 -> V_191 ) ;
if ( V_147 != 0 ) {
F_14 ( & V_142 -> V_2 , L_34 , V_147 ) ;
return V_147 ;
}
V_147 = F_25 ( F_6 ( V_140 -> V_191 ) ,
V_140 -> V_191 ) ;
if ( V_147 != 0 ) {
F_14 ( & V_142 -> V_2 , L_35 , V_147 ) ;
return V_147 ;
}
V_147 = F_40 ( V_140 -> V_192 , V_4 , & V_3 ) ;
if ( V_147 != 0 ) {
F_14 ( & V_142 -> V_2 , L_36 , V_147 ) ;
goto V_324;
}
if ( V_3 != 0x8993 ) {
F_14 ( & V_142 -> V_2 , L_37 , V_3 ) ;
V_147 = - V_125 ;
goto V_324;
}
V_147 = F_43 ( V_140 -> V_192 , V_4 , 0xffff ) ;
if ( V_147 != 0 )
goto V_324;
V_147 = F_64 ( V_140 -> V_192 , V_325 ,
F_6 ( V_325 ) ) ;
if ( V_147 != 0 )
F_18 ( V_140 -> V_2 , L_38 ,
V_147 ) ;
if ( V_142 -> V_162 ) {
V_147 = F_65 ( V_140 -> V_192 , V_26 ,
V_326 |
V_327 , 7 ) ;
if ( V_147 != 0 )
goto V_324;
V_147 = F_66 ( V_142 -> V_162 , NULL , F_39 ,
V_328 | V_329 ,
L_39 , V_140 ) ;
if ( V_147 != 0 )
goto V_324;
}
F_31 ( F_6 ( V_140 -> V_191 ) , V_140 -> V_191 ) ;
F_26 ( V_140 -> V_192 , true ) ;
V_147 = F_67 ( & V_142 -> V_2 ,
& V_330 , & V_331 , 1 ) ;
if ( V_147 != 0 ) {
F_14 ( & V_142 -> V_2 , L_40 , V_147 ) ;
goto V_332;
}
return 0 ;
V_332:
if ( V_142 -> V_162 )
F_68 ( V_142 -> V_162 , V_140 ) ;
V_324:
F_31 ( F_6 ( V_140 -> V_191 ) , V_140 -> V_191 ) ;
return V_147 ;
}
static int F_69 ( struct V_141 * V_142 )
{
struct V_139 * V_140 = F_70 ( V_142 ) ;
F_71 ( & V_142 -> V_2 ) ;
if ( V_142 -> V_162 )
F_68 ( V_142 -> V_162 , V_140 ) ;
F_31 ( F_6 ( V_140 -> V_191 ) , V_140 -> V_191 ) ;
return 0 ;
}
